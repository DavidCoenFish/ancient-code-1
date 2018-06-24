//file: Vanity/VScene/VSceneUtilityHelperCollision.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneUtilityHelperCollision.h"

#include "Vanity/VScene/VScene.h"

#include "Vanity/VComponentCollision/VComponentCollision_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VSceneUtilityHelperCollision::VSceneUtilityHelperCollision(
	VScene& in_scene,
	VComponentCollisionResultBase& in_out_collisionResult,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL m_maximumDistance,
	const Hubris::HREAL in_rayThickness
	)
: m_scene( in_scene )
, m_collisionResult( in_out_collisionResult )
, m_line( in_line )
, m_maximumDistance( m_maximumDistance )
, m_rayThickness( in_rayThickness )
{
	return;
}

/**/
VSceneUtilityHelperCollision::~VSceneUtilityHelperCollision()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HBOOL VSceneUtilityHelperCollision::VisitorSorted( Hubris::HSINT in_itemId, HREAL in_nodeDistance )
{
	if( m_maximumDistance < in_nodeDistance )
	{
		return HFALSE;
	}

	VComponentCollisionResultBase collisionData;
	m_scene.InterfaceObjectCollisionGet().CollideRay(
		collisionData,
		m_line,
		m_maximumDistance,
		m_rayThickness,
		in_itemId
		);

	if( HFALSE == collisionData.ValidGet() )
	{
		return HTRUE;
	}

	const HREAL distance = collisionData.DistanceGet();
	if( distance < ( -HVariablesMath::EpsilonGet< HREAL >() ) )
	{
		return HTRUE;
	}
	if( distance < m_maximumDistance )
	{
		m_collisionResult = collisionData;
		m_maximumDistance = distance;
	}

	return HTRUE;
}

/**/

