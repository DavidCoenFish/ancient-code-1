//file: Pride/PLine/PLineSegment.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLine/PLineSegment.h"

#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PLineSegment< HREAL, 2 >;
template class Pride::PLineSegment< HREAL, 3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLineSegment< IN_TYPE, IN_COUNT >::PLineSegment( const PLineSegment& in_src )
: m_line()
, m_boundsUpper( HVariablesMath::ZeroGet< HREAL >() )
, m_boundsLower( HVariablesMath::ZeroGet< HREAL >() )
, m_boundsUpperValid( HFALSE )
, m_boundsLowerValid( HFALSE )
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLineSegment< IN_TYPE, IN_COUNT >::PLineSegment(
	const TLine& in_line
	)
: m_line( in_line )
, m_boundsUpper( HVariablesMath::ZeroGet< HREAL >() )
, m_boundsLower( HVariablesMath::ZeroGet< HREAL >() )
, m_boundsUpperValid( HFALSE )
, m_boundsLowerValid( HFALSE )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLineSegment< IN_TYPE, IN_COUNT >::PLineSegment()
: m_line()
, m_boundsUpper( HVariablesMath::ZeroGet< HREAL >() )
, m_boundsLower( HVariablesMath::ZeroGet< HREAL >() )
, m_boundsUpperValid( HFALSE )
, m_boundsLowerValid( HFALSE )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PLineSegment< IN_TYPE, IN_COUNT >::~PLineSegment()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const PLineSegment< IN_TYPE, IN_COUNT >& PLineSegment< IN_TYPE, IN_COUNT >::operator=( const PLineSegment& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_line = in_rhs.m_line;
		m_boundsUpper = in_rhs.m_boundsUpper;
		m_boundsLower = in_rhs.m_boundsLower;
		m_boundsUpperValid = in_rhs.m_boundsUpperValid;
		m_boundsLowerValid = in_rhs.m_boundsLowerValid;
	}

	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PLineSegment< IN_TYPE, IN_COUNT >::operator==( const PLineSegment& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_line == in_rhs.m_line );
		match &= ( m_boundsUpper == in_rhs.m_boundsUpper );
		match &= ( m_boundsLower == in_rhs.m_boundsLower );
		match &= ( m_boundsUpperValid == in_rhs.m_boundsUpperValid );
		match &= ( m_boundsLowerValid == in_rhs.m_boundsLowerValid );
	}

	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
Hubris::HBOOL PLineSegment< IN_TYPE, IN_COUNT >::operator!=( const PLineSegment& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
