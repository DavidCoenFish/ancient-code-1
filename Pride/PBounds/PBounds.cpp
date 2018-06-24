//file: Pride/PBounds/PBounds.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PBounds/PBounds.h"

#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PBounds< HREAL, 1 >;
template class Pride::PBounds< HREAL, 2 >;
template class Pride::PBounds< HREAL, 3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PBounds< IN_TYPE, IN_COUNT >::PBounds( const PBounds& in_src )
: m_valid( HFALSE )
, m_min()
, m_max()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PBounds< IN_TYPE, IN_COUNT >::PBounds(
	const TVector& in_minimum,
	const TVector& in_maximum
	)
: m_valid( HTRUE )
, m_min( in_minimum )
, m_max( in_maximum )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PBounds< IN_TYPE, IN_COUNT >::PBounds()
: m_valid( HFALSE )
, m_min()
, m_max()
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PBounds< IN_TYPE, IN_COUNT >::~PBounds()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const PBounds< IN_TYPE, IN_COUNT >& PBounds< IN_TYPE, IN_COUNT >::operator=( const PBounds& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_valid = in_rhs.m_valid;
		m_min = in_rhs.m_min;
		m_max = in_rhs.m_max;
	}

	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HBOOL PBounds< IN_TYPE, IN_COUNT >::operator==( const PBounds& in_rhs )const
{		
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_valid == in_rhs.m_valid );
		match &= ( m_min == in_rhs.m_min );
		match &= ( m_max == in_rhs.m_max );
	}

	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HBOOL PBounds< IN_TYPE, IN_COUNT >::operator!=( const PBounds& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
HVOID PBounds< IN_TYPE, IN_COUNT >::InsertPoint( 
	const TVector& in_point, 
	const Hubris::HREAL in_radius
	)
{
	if( HFALSE == m_valid )
	{
		m_valid = HTRUE;
		m_min = in_point - in_radius;
		m_max = in_point + in_radius;
	}
	else
	{
		m_min = Hubris::HMathUtility::Minimum( m_min, in_point - in_radius );
		m_max = Hubris::HMathUtility::Maximum( m_max, in_point + in_radius );
	}

	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
typename const PBounds< IN_TYPE, IN_COUNT >::TVector PBounds< IN_TYPE, IN_COUNT >::CenterGet()const
{
	return ( m_max + m_min ) * Hubris::HVariablesMath::HalfGet< HREAL >();
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HREAL PBounds< IN_TYPE, IN_COUNT >::RadiusGet()const
{
	return ( Hubris::HMatrixUtility::Length( m_max - m_min ) ) * Hubris::HVariablesMath::HalfGet< HREAL >();
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HREAL PBounds< IN_TYPE, IN_COUNT >::MaxDimGet()const
{
	IN_TYPE mamximum = Hubris::HVariablesMath::MinimumGet< IN_TYPE >();
	for( Hubris::HSINT index = 0; index < IN_COUNT; ++index )
	{
		mamximum = Hubris::HMathUtility::Maximum( mamximum, m_max[ index ] - m_min[ index ] );
	}

	return mamximum;
}

/**/
