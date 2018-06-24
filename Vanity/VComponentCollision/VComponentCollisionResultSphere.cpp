//file: Vanity/VComponentCollision/VComponentCollisionResultSphere.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultSphere.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionResultSphere::VComponentCollisionResultSphere(
	const Hubris::HREAL in_distance,
	const Pride::PLineR3& in_line,
	const Pride::PSphereR3& in_sphere
	)
: m_distance( in_distance )
, m_line( in_line )
, m_sphere( in_sphere )
, m_position()
, m_positionValid( HFALSE )
, m_normal()
, m_normalValid( HFALSE )
{

	return;
}

/**/
VComponentCollisionResultSphere::~VComponentCollisionResultSphere()
{
	return;
}

///////////////////////////////////////////////////////
// public methods, contract with VComponentCollisionResultBase
/**/
const Hubris::HREAL VComponentCollisionResultSphere::DistanceSquaredGet()
{
	return( m_distance * m_distance );
}

/**/
const Hubris::HREAL VComponentCollisionResultSphere::DistanceGet()
{
	return m_distance;
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultSphere::ContactPositionGet()
{
	if( HFALSE == m_positionValid )
	{
		m_position = m_line.OriginGet() + ( m_line.DirectionGet().VectorGet() * m_distance );
		m_positionValid = HTRUE;
	}

	return m_position;
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultSphere::ContactNormalGet()
{
	if( HFALSE == m_normalValid )
	{
		m_normal = ( ContactPositionGet() - m_line.OriginGet() ) * ( 1.0F / m_sphere.RadiusGet() );
		m_normalValid = HTRUE;
	}

	return m_normal;
}
/**/
