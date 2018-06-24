//file: Pride/PTriangle/PTriangle.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PTriangle/PTriangle.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PTriangle::PTriangle( const PTriangle& in_src )
: m_pointOne()
, m_pointTwo()
, m_pointThree()
{
	( *this ) = in_src;
	return;
}

/**/
PTriangle::PTriangle(
	const Hubris::HVectorR3& in_pointOne,
	const Hubris::HVectorR3& in_pointTwo,
	const Hubris::HVectorR3& in_pointThree
	)
: m_pointOne( in_pointOne )
, m_pointTwo( in_pointTwo )
, m_pointThree( in_pointThree )
{
	return;
}

/**/
PTriangle::PTriangle()
: m_pointOne()
, m_pointTwo()
, m_pointThree()
{
	return;
}

/**/
PTriangle::~PTriangle()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PTriangle& PTriangle::operator=( const PTriangle& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_pointOne = in_rhs.m_pointOne;
		m_pointTwo = in_rhs.m_pointTwo;
		m_pointThree = in_rhs.m_pointThree;
	}
	return( *this );
}

/**/
Hubris::HBOOL PTriangle::operator==( const PTriangle& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_pointOne == in_rhs.m_pointOne );
		match &= ( m_pointTwo == in_rhs.m_pointTwo );
		match &= ( m_pointThree == in_rhs.m_pointThree );
	}
	return match;
}

/**/
Hubris::HBOOL PTriangle::operator!=( const PTriangle& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
