//file: Pride/PPlane/PPlane.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PPlane/PPlane.h"

#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PPlane< HREAL, 2 >;
template class Pride::PPlane< HREAL, 3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PPlane< IN_TYPE, IN_COUNT >::PPlane( const PPlane& in_src )
: m_distance( HVariablesMath::ZeroGet< IN_TYPE >() )
, m_direction()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PPlane< IN_TYPE, IN_COUNT >::PPlane(
	const IN_TYPE in_distance,
	const TUnitVector& in_direction
	)
: m_distance( in_distance )
, m_direction( in_direction )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PPlane< IN_TYPE, IN_COUNT >::PPlane()
: m_distance( HVariablesMath::ZeroGet< IN_TYPE >() )
, m_direction()
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PPlane< IN_TYPE, IN_COUNT >::~PPlane()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const PPlane< IN_TYPE, IN_COUNT >& PPlane< IN_TYPE, IN_COUNT >::operator=( const PPlane& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_distance = in_rhs.m_distance;
		m_direction = in_rhs.m_direction;
	}
	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PPlane< IN_TYPE, IN_COUNT >::operator==( const PPlane& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_distance == in_rhs.m_distance );
		match &= ( m_direction == in_rhs.m_direction );
	}
	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PPlane< IN_TYPE, IN_COUNT >::operator!=( const PPlane& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
