//file: Pride/PSphere/PSphere.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PSphere/PSphere.h"

#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PSphere< HREAL, 2 >;
template class Pride::PSphere< HREAL, 3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PSphere< IN_TYPE, IN_COUNT >::PSphere( const PSphere& in_src )
: m_radius( HVariablesMath::ZeroGet< IN_TYPE >() )
, m_center()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PSphere< IN_TYPE, IN_COUNT >::PSphere(
	const IN_TYPE in_radius,
	const TVector& in_center
	)
: m_radius( in_radius )
, m_center( in_center )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PSphere< IN_TYPE, IN_COUNT >::PSphere()
: m_radius( HVariablesMath::ZeroGet< IN_TYPE >() )
, m_center()
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PSphere< IN_TYPE, IN_COUNT >::~PSphere()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const PSphere< IN_TYPE, IN_COUNT >& PSphere< IN_TYPE, IN_COUNT >::operator=( const PSphere& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_radius = in_rhs.m_radius;
		m_center = in_rhs.m_center;
	}
	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PSphere< IN_TYPE, IN_COUNT >::operator==( const PSphere& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_radius == in_rhs.m_radius );
		match &= ( m_center == in_rhs.m_center );
	}
	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PSphere< IN_TYPE, IN_COUNT >::operator!=( const PSphere& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
