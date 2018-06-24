//file: Vanity/VComponentCollision/VComponentCollisionResultHull.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultHull.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionResultHull::VComponentCollisionResultHull(
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_distance,
	const Hubris::HVectorR3& in_normal	
	)
: m_line( in_line )
, m_distance( in_distance )
, m_normal( in_normal )
, m_position()
, m_positionValid( HFALSE )
{
	return;
}

/**/
VComponentCollisionResultHull::~VComponentCollisionResultHull()
{
	return;
}

///////////////////////////////////////////////////////
// public methods, contract with VComponentCollisionResultBase
/**/
const Hubris::HREAL VComponentCollisionResultHull::DistanceSquaredGet()
{
	return( m_distance * m_distance );
}

/**/
const Hubris::HREAL VComponentCollisionResultHull::DistanceGet()
{
	return( m_distance );
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultHull::ContactPositionGet()
{
	if( HFALSE == m_positionValid )
	{
		m_positionValid = HTRUE;
		m_position = PLineUtility::LinePointGet(
			m_line,
			m_distance
			);
	}
	return m_position;
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultHull::ContactNormalGet()
{
	return m_normal;
}

/**/
