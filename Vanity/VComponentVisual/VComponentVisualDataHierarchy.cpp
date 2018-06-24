//file: Vanity/VComponentVisual/VComponentVisualDataHierarchy.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualDataHierarchy.h"

#include "Vanity/VComponentVisual/VComponentVisualDataHierarchyMatrixCache.h"
#include "Vanity/VComponentVisual/VComponentVisualTrait.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentVisualDataHierarchy, VComponentVisualDataBase );

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualDataHierarchy::VComponentVisualDataHierarchy()
: m_filePath()
, m_pAsset()
, m_arrayGeometryData()
, m_arrayBoneAnimationMatrix()
, m_pMatrixCache()
{
	return;
}

/**/
VComponentVisualDataHierarchy::~VComponentVisualDataHierarchy()
{
	HCOMMON_DELETE( m_pMatrixCache, VComponentVisualDataHierarchyMatrixCache );
	return;
}

///////////////////////////////////////////////////////
// implement VComponentVisualDataBase
/**/
Hubris::HVOID VComponentVisualDataHierarchy::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pAsset = in_sceneApplicationInterface.AssetManagerGet().AssetRequest< VComponentVisualAssetHierarchy >(
		in_sceneApplicationInterface,
		m_filePath 
		);

	m_arrayPointerRenderResource.Clear();
	m_arrayGeometryData.Clear();

	if( HNULL == m_pAsset )
	{
		return;
	}

	m_pAsset->DynamicRenderDataAquire(
		in_sceneApplicationInterface,
		m_arrayPointerRenderResource,
		m_arrayGeometryData
		);

	const HSINT boneCount = m_pAsset->ArrayBoneDataGet().SizeGet();
	m_arrayBoneAnimationMatrix.SizeSet( boneCount );
	for( HSINT index = 0; index < boneCount; ++index )
	{
		m_arrayBoneAnimationMatrix[ index ] = HMatrixUtility::IdentityGet< HMatrixR4 >();
	}

	HCOMMON_NEW_PARAM( m_pMatrixCache, VComponentVisualDataHierarchyMatrixCache, boneCount );

	return;
}

/**/
Hubris::HVOID VComponentVisualDataHierarchy::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_arrayPointerRenderResource.Clear();
	m_arrayGeometryData.Clear();
	m_pAsset = HNULL;
	in_sceneApplicationInterface.AssetManagerGet().AssetReleaseUnused();
	HCOMMON_DELETE( m_pMatrixCache, VComponentVisualDataHierarchyMatrixCache );

	return;
}

/**/
const Hubris::HSINT VComponentVisualDataHierarchy::RenderLayerGet()const
{
	if( HNULL == m_pAsset )
	{
		return HCOMMON_INVALID_INDEX;
	}

	const HSINT renderLayer = m_pAsset->RenderLayerGet();
	return renderLayer;
}

/**/
Hubris::HVOID VComponentVisualDataHierarchy::Render( 
	const TItemId in_itemId,
	const Hubris::HSINT in_renderIndex,
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	SInterfaceRender* pRender = in_sceneApplicationInterface.RenderInterfaceGet( in_renderIndex );
	if( HNULL == pRender )
	{
		return;
	}

	HREAL alphaOverride = 1.0F;
	if( AlphaOverrideFrameIdGet() == in_scene.FrameIDGet() )
	{
		alphaOverride = AlphaOverrideGet();
	}

	HMatrixR4 matrix;
	VSceneUtility::ItemMatrixGet( matrix, in_scene, in_itemId );

	m_pAsset->Render(
		*pRender,
		in_renderIndex,
		matrix,
		alphaOverride,
		MatrixCacheGet().ArrayBoneMatrixAnimatedGet( m_arrayBoneAnimationMatrix, m_pAsset->ArrayBoneDataGet() ),
		m_arrayPointerRenderResource
		);

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentVisualDataHierarchy::AquireAnimationData(
	const TArrayBoneData*& out_pArrayBoneData,
	TArrayMatrix*& out_pArrayMatrix
	)
{
	if( HNULL != m_pAsset )
	{
		out_pArrayBoneData = &( m_pAsset->ArrayBoneDataGet() );
	}

	out_pArrayMatrix = &m_arrayBoneAnimationMatrix;
	return;
}

/**/
Hubris::HVOID VComponentVisualDataHierarchy::GeometryUpdate(
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface ),
	const Sloth::SComponentDelta& in_delta
	)
{
	//update the geometry of each skinned object
	if( HNULL == m_pAsset )
	{
		return;
	}

	VComponentVisualDataHierarchyMatrixCache& matrixCache = MatrixCacheGet();
	matrixCache.OnNewFrame();

	HCOMMON_FOR_EACH( geometryData, m_arrayGeometryData, TArrayGeometryData )
	{
		const HSINT geometryIndex = geometryData.GeometryIndexGet();
		geometryData.Update(
			m_arrayPointerRenderResource[ geometryIndex ],
			m_pAsset->ArrayGeometryDataGet()[ geometryIndex ].GeometryGet(),
			in_delta,
			MatrixCacheGet(),
			m_arrayBoneAnimationMatrix,
			m_pAsset->ArrayBoneDataGet(),
			m_pAsset->ArrayInvertSkinningGet()
			);
	}

	return;
}

///////////////////////////////////////////////////////
// private acessors
/**/
const VComponentVisualDataHierarchyMatrixCache& VComponentVisualDataHierarchy::MatrixCacheGet()const
{
	HCOMMON_ASSERT( HNULL == m_pMatrixCache, "invalid member" );
	return( *m_pMatrixCache );
}

/**/
VComponentVisualDataHierarchyMatrixCache& VComponentVisualDataHierarchy::MatrixCacheGet()
{
	HCOMMON_ASSERT( HNULL == m_pMatrixCache, "invalid member" );
	return( *m_pMatrixCache );
}

/**/
