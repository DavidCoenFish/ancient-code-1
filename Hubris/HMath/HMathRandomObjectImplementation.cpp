//file: Hubris/HMath/HMathRandomObjectImplementation.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMath/HMathRandomObjectImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

////////////////////////////////////////////////////
// local static variables
/*
implementation from Numerical recipes in c, second edition (rand2)
*/
static const HSINT s_im1 = 2147483563;
static const HSINT s_im2 = 2147483399;
static const HR64 s_am = ( 1.0 / s_im1 );
static const HSINT s_imm1 = ( s_im1 - 1 );
static const HSINT s_ia1 = 40014;
static const HSINT s_ia2 = 40692;
static const HSINT s_iq1 = 53668;
static const HSINT s_iq2 = 52774;
static const HSINT s_ir1 = 12211;
static const HSINT s_ir2 = 3791;
static const HR64 s_ndix = ( 1 + s_imm1 / HMathRandomObjectImplementation::TVar::TNTAB );
static const HR64 s_eps = 1.2e-7;
static const HR64 s_rnmx = ( 1.0 - s_eps );

////////////////////////////////////////////////////
// creation
/**/
static HSINT LocalRandValue( const HSINT in_idum, const HSINT in_ia, const HSINT in_iq, const HSINT in_ir, const HSINT in_im  )
{
	const HSINT k = in_idum / in_iq;
	HSINT returnIdum = in_ia * ( in_idum - k * in_iq ) - k * in_ir;
	if( returnIdum < 0 )
	{
		returnIdum += in_im;
	}

	return returnIdum; 
}

////////////////////////////////////////////////////
// creation
/**/
HMathRandomObjectImplementation::HMathRandomObjectImplementation( const HMathRandomObjectImplementation& in_src )
: m_idum( 0 )
, m_idum2( 0 )
, m_iy( 0 )
, m_staticArrayIv()
{
	m_staticArrayIv.SizeResize( TVar::TNTAB );
	( *this ) = in_src;
	return;
}

/**/
HMathRandomObjectImplementation::HMathRandomObjectImplementation( const HSINT in_seed )
: m_idum( 0 )
, m_idum2( 0 )
, m_iy( 0 )
, m_staticArrayIv()
{
	m_staticArrayIv.SizeResize( TVar::TNTAB );
	RandomSeedSet( in_seed );
	return;
}

/**/
HMathRandomObjectImplementation::HMathRandomObjectImplementation()
: m_idum( 0 )
, m_idum2( 0 )
, m_iy( 0 )
, m_staticArrayIv()
{
	m_staticArrayIv.SizeResize( TVar::TNTAB );
	Initialise();
	return;
}

/**/
HMathRandomObjectImplementation::~HMathRandomObjectImplementation()
{
	return;
}

////////////////////////////////////////////////////
// operators
/**/
const HMathRandomObjectImplementation& HMathRandomObjectImplementation::operator=( const HMathRandomObjectImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_idum = in_rhs.m_idum;
		m_idum2 = in_rhs.m_idum2;
		m_iy = in_rhs.m_iy;
		m_staticArrayIv = in_rhs.m_staticArrayIv;
	}

	return( *this );
}

/**/
const HBOOL HMathRandomObjectImplementation::operator==( const HMathRandomObjectImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_idum == in_rhs.m_idum );
		match &= ( m_idum2 == in_rhs.m_idum2 );
		match &= ( m_iy == in_rhs.m_iy );
		match &= ( m_staticArrayIv == in_rhs.m_staticArrayIv );
	}

	return match;
}

/**/
const HBOOL HMathRandomObjectImplementation::operator!=( const HMathRandomObjectImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID HMathRandomObjectImplementation::RandomSeedSet( const Hubris::HSINT in_seed )
{
	m_idum = in_seed;
	Initialise();
	return;
}

/**/
const Hubris::HREAL HMathRandomObjectImplementation::RandomRangeOneValueGet() //return a value [0 ... 1.0 } 
{
	const HREAL value = GenerateReal();
	return value;
}

/**/
const Hubris::HREAL HMathRandomObjectImplementation::RandomValueGet( const Hubris::HREAL in_range )
{
	const HREAL value = GenerateReal() * in_range;
	return value;
}

/**/
const Hubris::HSINT HMathRandomObjectImplementation::RandomValueIntGet()
{
	Generate();
	return m_iy;
}

/////////////////////////////////////////////////////////////////
// private methods
/**/
HVOID HMathRandomObjectImplementation::Initialise()
{
	if( 0 == m_idum )
	{
		m_idum = 1;
	}
	else if( m_idum < 0 )
	{
		m_idum = -m_idum;
	}

	m_idum2 = m_idum;
	for( HSINT j = TVar::TNTAB + 7; j >= 0; j-- )
	{
		m_idum = LocalRandValue( m_idum, s_ia1, s_iq1, s_ir1, s_im1 );

		if( j < TVar::TNTAB )
		{
			m_staticArrayIv[ j ] = m_idum;
		}
	}

	m_iy = m_staticArrayIv[ 0 ];

	return;
}

/**/
HVOID HMathRandomObjectImplementation::Generate()
{
	m_idum = LocalRandValue( m_idum, s_ia1, s_iq1, s_ir1, s_im1 );
	m_idum2 = LocalRandValue( m_idum2, s_ia2, s_iq2, s_ir2, s_im2 );

	const HSINT j = HSINT( m_iy / s_ndix );
	m_iy = m_staticArrayIv[ j ] - m_idum2;
	m_staticArrayIv[ j ] = m_idum;
	if( m_iy < 1 )
	{
		m_iy += s_imm1;
	}

	return;
}

/**/
const HREAL HMathRandomObjectImplementation::GenerateReal()
{
	//could call RandomValueIntGet() but lets not invoke public interface in private methods..
	Generate();

	const HR64 temp = s_am * m_iy;
	if( s_rnmx < temp )
	{
		return HREAL( s_rnmx );
	}

	return HREAL( temp );
}

/**/
