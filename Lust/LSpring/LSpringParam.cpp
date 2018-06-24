//file: Lust/LSpring/LSpringParam.cpp

#include "Lust/LustPreCompileHeader.h"
#include "Lust/LSpring/LSpringParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Lust;

///////////////////////////////////////////////////////
// creation
/**/
Lust::LSpringParam::LSpringParam( const LSpringParam& in_src )
: m_springConstant( 0.0F )
, m_springDamppenConstant( 0.0F )
, m_springMaximumDistance( 0.0F )
{
	( *this ) = in_src;
	return;
}

/**/
Lust::LSpringParam::LSpringParam(
	const Hubris::HREAL in_springConstant,
	const Hubris::HREAL in_springDamppenConstant,
	const Hubris::HREAL in_springMaximumDistance
	)
: m_springConstant( in_springConstant )
, m_springDamppenConstant( in_springDamppenConstant )
, m_springMaximumDistance( in_springMaximumDistance )
{
	return;
}

/**/
Lust::LSpringParam::LSpringParam()
: m_springConstant( 0.0F )
, m_springDamppenConstant( 0.0F )
, m_springMaximumDistance( 0.0F )
{
	return;
}

/**/
Lust::LSpringParam::~LSpringParam()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const LSpringParam& Lust::LSpringParam::operator=( const LSpringParam& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_springConstant = in_rhs.m_springConstant;
		m_springDamppenConstant = in_rhs.m_springDamppenConstant;
		m_springMaximumDistance = in_rhs.m_springMaximumDistance;
	}
	return( *this );
}

/**/
const Hubris::HBOOL Lust::LSpringParam::operator==( const LSpringParam& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_springConstant == in_rhs.m_springConstant );
		match &= ( m_springDamppenConstant == in_rhs.m_springDamppenConstant );
		match &= ( m_springMaximumDistance == in_rhs.m_springMaximumDistance );
	}
	return match;
}

/**/
const Hubris::HBOOL Lust::LSpringParam::operator!=( const LSpringParam& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/