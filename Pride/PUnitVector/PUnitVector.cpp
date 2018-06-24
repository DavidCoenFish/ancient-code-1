//file: Pride/PUnitVector/PUnitVector.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PUnitVector/PUnitVector.h"

#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PUnitVector< HREAL, 2 >;
template class Pride::PUnitVector< HREAL, 3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PUnitVector< IN_TYPE, IN_COUNT >::PUnitVector( const PUnitVector& in_src )
: m_unitVector()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PUnitVector< IN_TYPE, IN_COUNT >::PUnitVector(
	const TVector& in_vector
	)
: m_unitVector()
{
	VectorSet( in_vector );

	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PUnitVector< IN_TYPE, IN_COUNT >::PUnitVector()
: m_unitVector()
{
	m_unitVector[ 0 ] = HVariablesMath::UnitGet< IN_TYPE >();
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PUnitVector< IN_TYPE, IN_COUNT >::~PUnitVector()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const PUnitVector< IN_TYPE, IN_COUNT >& PUnitVector< IN_TYPE, IN_COUNT >::operator=( const PUnitVector& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_unitVector = in_rhs.m_unitVector;
		//m_valid = in_rhs.m_valid;
	}
	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PUnitVector< IN_TYPE, IN_COUNT >::operator==( const PUnitVector& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_unitVector == in_rhs.m_unitVector );
		//match &= ( m_valid == in_rhs.m_valid );
	}
	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PUnitVector< IN_TYPE, IN_COUNT >::operator!=( const PUnitVector& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HREAL PUnitVector< IN_TYPE, IN_COUNT >::operator[]( Hubris::HSINT in_index )const
{
	return( m_unitVector[ in_index ] );
}


///////////////////////////////////////////////////////
// public accessors
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
HVOID PUnitVector< IN_TYPE, IN_COUNT >::VectorSet( const TVector& in_unitVector )
{
	m_unitVector = HMatrixUtility::Normalise( in_unitVector );

	HCOMMON_ASSERT( HTRUE == HMathUtility::EpsilonZeroNot( m_unitVector ), "invalid result, zero vector" );

	return;
}

/**/
