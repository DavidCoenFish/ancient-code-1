//file: Vanity/VComponentCollision/VComponentCollision.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollision.h"

#include "Vanity/VComponentCollision/VComponentCollisionDataBase.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataBound.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataHull.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataSphere.h"


#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollision::VComponentCollision()
: m_arrayPointerData()
{
	return;
}

/**/
VComponentCollision::~VComponentCollision()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentCollision::OnAddItem(
	const Hubris::HSINT in_itemIndex
	)
{
	if( m_arrayPointerData.SizeGet() <= in_itemIndex )
	{
		m_arrayPointerData.SizeResize( in_itemIndex + 1 );
	}

	return;
}

/**/
HVOID VComponentCollision::OnRemoveItem(
	const Hubris::HSINT in_itemIndex
	)
{
	m_arrayPointerData[ in_itemIndex ] = HNULL;

	return;
}

/**/
Hubris::HVOID VComponentCollision::CollisionBoundCreate(
	const TItemId in_itemId,
	const Pride::PBoundsR3& in_bound
	)
{
	VComponentCollisionDataBound* pBound = HNULL;
	HCOMMON_NEW(
		pBound,
		VComponentCollisionDataBound
		);

	if( HNULL != pBound )
	{
		pBound->BoundSet( in_bound );
	}

	m_arrayPointerData[ in_itemId ] = pBound;

	return;
}

/**/
Hubris::HVOID VComponentCollision::CollisionSphereCreate(
	const TItemId in_itemId
	)
{
	VComponentCollisionDataSphere* pSphere = HNULL;
	HCOMMON_NEW(
		pSphere,
		VComponentCollisionDataSphere
		);

	m_arrayPointerData[ in_itemId ] = pSphere;

	return;
}

/**/
Hubris::HVOID VComponentCollision::CollisionConvexHullCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	VComponentCollisionDataHull* pConvexHull = HNULL;
	HCOMMON_NEW(
		pConvexHull,
		VComponentCollisionDataHull
		);

	if( HNULL != pConvexHull )
	{
		pConvexHull->FilePathSet( in_assetPath );
	}

	m_arrayPointerData[ in_itemId ] = pConvexHull;

	return;
}

/**/
Hubris::HVOID VComponentCollision::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->Load( in_sceneApplicationInterface );

	return;
}

/**/
Hubris::HVOID VComponentCollision::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->UnLoad( in_sceneApplicationInterface );

	return;
}

/**/
Hubris::HVOID VComponentCollision::CollideRay(
	VComponentCollisionResultBase& out_collisionData,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_maximumLineLength,
	const Hubris::HREAL in_rayThickness,
	const VScene& in_scene,
	const TItemId in_itemId
	)const
{
	const TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->CollideRay( 
		out_collisionData,
		in_line,
		in_maximumLineLength,
		in_rayThickness,
		in_scene,
		in_itemId
		);

	return;
}

/**/
Hubris::HVOID VComponentCollision::Render(
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HSINT in_renderIndex,
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->Render( 
		in_scene,
		in_sceneApplicationInterface,
		in_renderIndex,
		in_itemId
		);

	return;
}

/**/