//file: Vanity/VComponentCollision/VComponentCollisionInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionInterfaceObject.h"

#include "Vanity/VComponentCollision/VComponentCollision.h"
#include "Vanity/VComponentCollision/VComponentCollisionAssetHull.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionInterfaceObject::VComponentCollisionInterfaceObject(
	VComponentCollision& in_componentCollision,
	VScene& in_scene
	)
: m_componentCollision( in_componentCollision )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentCollisionInterfaceObject::~VComponentCollisionInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentCollisionInterfaceObject::CollisionBoundCreate(
	const TItemId in_itemId,
	const Pride::PBoundsR3& in_bound
	)
{
	m_componentCollision.CollisionBoundCreate(
		in_itemId,
		in_bound
		);
	return;
}

/**/
Hubris::HVOID VComponentCollisionInterfaceObject::CollisionSphereCreate(
	const TItemId in_itemId
	)
{
	m_componentCollision.CollisionSphereCreate(
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentCollisionInterfaceObject::CollisionConvexHullCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	m_componentCollision.CollisionConvexHullCreate(
		in_itemId,
		in_assetPath
		);
	return;
}

/**/
Hubris::HVOID VComponentCollisionInterfaceObject::CollisionConvexHullAssetCreate(
	const Hubris::HFileSystemPath& in_assetPath,
	Pride::PConvexHull& in_convexHull
	)
{
	VComponentCollisionAssetHull::CreateAsset(
		in_assetPath,
		in_convexHull
		);
	return;
}

/**/
Hubris::HVOID VComponentCollisionInterfaceObject::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	m_componentCollision.Load(
		in_sceneApplicationInterface,
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentCollisionInterfaceObject::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	m_componentCollision.UnLoad(
		in_sceneApplicationInterface,
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentCollisionInterfaceObject::CollideRay(
	VComponentCollisionResultBase& out_collisionData,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_maximumLineLength,
	const Hubris::HREAL in_rayThickness,
	const TItemId in_itemId
	)const
{
	m_componentCollision.CollideRay(
		out_collisionData,
		in_line,
		in_maximumLineLength,
		in_rayThickness,
		m_scene,
		in_itemId
		);

	return;
}

/**/
Hubris::HVOID VComponentCollisionInterfaceObject::Render(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HSINT in_renderIndex,
	const TItemId in_itemId
	)
{
	m_componentCollision.Render(
		m_scene,
		in_sceneApplicationInterface,
		in_renderIndex,
		in_itemId
		);

	return;
}

/**/