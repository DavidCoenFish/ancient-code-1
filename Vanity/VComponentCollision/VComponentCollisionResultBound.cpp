//file: Vanity/VComponentCollision/VComponentCollisionResultBound.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultBound.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionResultBound::VComponentCollisionResultBound(
	const Hubris::HREAL in_distance,
	const Pride::PLineR3& in_line,
	const Hubris::HVectorR3& in_normal
	)
: m_distance( in_distance )
, m_line( in_line )
, m_normal( in_normal )
, m_position()
, m_positionValid( HFALSE )
{
	return;
}

/**/
VComponentCollisionResultBound::~VComponentCollisionResultBound()
{
	return;
}

///////////////////////////////////////////////////////
// public methods, contract with VComponentCollisionResultBase
/**/
const Hubris::HREAL VComponentCollisionResultBound::DistanceSquaredGet()
{
	return( m_distance * m_distance );
}

/**/
const Hubris::HREAL VComponentCollisionResultBound::DistanceGet()
{
	return m_distance;
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultBound::ContactPositionGet()
{
	if( HFALSE == m_positionValid )
	{
		m_positionValid = HTRUE;
		m_position = PLineUtility::LinePointGet( m_line, m_distance );
	}

	return m_position;
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultBound::ContactNormalGet()
{
	return m_normal;
}

/**/