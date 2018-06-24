//file: Hubris/HMath/HMathRandomObject.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMath/HMathRandomObject.h"

#include "Hubris/HMath/HMathRandomObjectImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

////////////////////////////////////////////////////
// creation
/**/
HMathRandomObject::HMathRandomObject( const HMathRandomObject& in_src )
: m_pImplementaion( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementaion, HMathRandomObjectImplementation, in_src.ImplementationGet() );
	return;
}

/**/
HMathRandomObject::HMathRandomObject( const HSINT in_seed )
: m_pImplementaion( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementaion, HMathRandomObjectImplementation, in_seed );
	return;
}

/**/
HMathRandomObject::HMathRandomObject()
: m_pImplementaion( HNULL )
{
	HCOMMON_NEW( m_pImplementaion, HMathRandomObjectImplementation );
	return;
}

/**/
HMathRandomObject::~HMathRandomObject()
{
	HCOMMON_DELETE( m_pImplementaion, HMathRandomObjectImplementation ); 
	return;
}

////////////////////////////////////////////////////
// operators, for the rest, see HMatrixOperator
/**/
const HMathRandomObject& HMathRandomObject::operator=( const HMathRandomObject& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
const HBOOL HMathRandomObject::operator==( const HMathRandomObject& in_rhs )const
{
	const HBOOL match = ( ImplementationGet() == in_rhs.ImplementationGet() );
	return match;
}

/**/
const HBOOL HMathRandomObject::operator!=( const HMathRandomObject& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID HMathRandomObject::RandomSeedSet( const Hubris::HSINT in_seed )
{
	ImplementationGet().RandomSeedSet( in_seed );
	return;
}

/**/
const Hubris::HREAL HMathRandomObject::RandomRangeOneValueGet() //return a value [0 ... 1.0 } 
{
	const HREAL value = ImplementationGet().RandomRangeOneValueGet();
	return value;
}

/**/
const Hubris::HREAL HMathRandomObject::RandomValueGet( const Hubris::HREAL in_range )
{
	const HREAL value = ImplementationGet().RandomValueGet( in_range );
	return value;
}

/**/
const Hubris::HSINT HMathRandomObject::RandomValueIntGet()
{
	const HSINT value = ImplementationGet().RandomValueIntGet();
	return value;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const HMathRandomObjectImplementation& HMathRandomObject::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementaion, "invalid member" );
	return( *m_pImplementaion );
}

/**/
HMathRandomObjectImplementation& HMathRandomObject::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementaion, "invalid member" );
	return( *m_pImplementaion );
}

/**/

