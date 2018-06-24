//file: Vanity/VComponentCollision/VComponentCollisionDataHull.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataHull.h"

#include "Vanity/VComponentCollision/VComponentCollisionTrait.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultBase.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/SInterface/SInterface_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentCollisionDataHull, VComponentCollisionDataBase );

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VComponentCollisionHullData >TArrayData;

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionDataHull::VComponentCollisionDataHull()
: m_filePath()
, m_pAsset()
, m_arrayTriangle()
{
	return;
}

/**/
VComponentCollisionDataHull::~VComponentCollisionDataHull()
{
	return;
}

///////////////////////////////////////////////////////
// implement VComponentCollisionDataBase
/**/
Hubris::HVOID VComponentCollisionDataHull::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pAsset = in_sceneApplicationInterface.AssetManagerGet().AssetRequest< VComponentCollisionAssetHull >( 
		in_sceneApplicationInterface,
		m_filePath 
		);
	return;
}

/**/
Hubris::HVOID VComponentCollisionDataHull::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pAsset = HNULL;
	in_sceneApplicationInterface.AssetManagerGet().AssetReleaseUnused();
	return;
}

/**/
Hubris::HVOID VComponentCollisionDataHull::CollideRay(
	VComponentCollisionResultBase& out_collisionData,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_maximumLineLength,
	const Hubris::HREAL HCOMMON_UNUSED_VAR( in_rayThickness ),
	const VScene& in_scene,
	const TItemId in_itemId
	)const
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	HMatrixR4 itemMatrix;
	HMatrixR4 itemMatrixInvert;

	VSceneUtility::ItemMatrixGet( 
		itemMatrix,
		itemMatrixInvert,
		in_scene,
		in_itemId
		);

	m_pAsset->ConvexHullGet().CollideRay(
		out_collisionData,
		in_line,
		in_maximumLineLength,
		itemMatrix,
		itemMatrixInvert
		);

	return;
}

/**/
Hubris::HVOID VComponentCollisionDataHull::Render(
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HSINT in_renderIndex,
	const TItemId in_itemId
	)
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	SInterfaceRender* pInterfaceRender = in_sceneApplicationInterface.RenderInterfaceGet( in_renderIndex );
	if( HNULL == pInterfaceRender )
	{
		return;
	}

	VSceneUtility::RenderItemMatrixSet( 
		in_itemId,
		in_scene,
		*pInterfaceRender
		);

	if( 0 == m_arrayTriangle.SizeGet() )
	{
		PConvexHull convexHull;
		const VComponentCollisionHull& hull = m_pAsset->ConvexHullGet();
		HCOMMON_FOR_EACH_CONST( data, hull.ArrayDataGet(), TArrayData )
		{
			convexHull.PlaneAdd( data.PlaneGet() );
		}

		PConvexHullUtility::ConvertToTriangles(
			m_arrayTriangle, 
			convexHull
			);
	}

	pInterfaceRender->DrawTriangle( m_arrayTriangle );

	return;
}

/**/