//file: Pride/PLine/PLine.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLine/PLine.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PLine< HREAL, 2 >;
template class Pride::PLine< HREAL, 3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLine< IN_TYPE, IN_COUNT >::PLine( const PLine& in_src )
: m_origin()
, m_direction()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLine< IN_TYPE, IN_COUNT >::PLine(
	const TVector& in_origin,
	const TUnitVector& in_direction
	)
: m_origin( in_origin )
, m_direction( in_direction )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLine< IN_TYPE, IN_COUNT >::PLine()
: m_origin()
, m_direction()
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLine< IN_TYPE, IN_COUNT >::~PLine()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const PLine< IN_TYPE, IN_COUNT >& PLine< IN_TYPE, IN_COUNT >::operator=( const PLine& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_origin = in_rhs.m_origin;
		m_direction = in_rhs.m_direction;
	}

	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PLine< IN_TYPE, IN_COUNT >::operator==( const PLine& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_origin == in_rhs.m_origin );
		match &= ( m_direction == in_rhs.m_direction );
	}

	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PLine< IN_TYPE, IN_COUNT >::operator!=( const PLine& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
