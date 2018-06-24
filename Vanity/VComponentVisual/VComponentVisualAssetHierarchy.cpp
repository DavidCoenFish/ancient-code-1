//file: Vanity/VComponentVisual/VComponentVisualAssetHierarchy.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchy.h"

#include "Vanity/VComponentVisual/VComponentVisualDataHierarchyGeometryData.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HVOID* TObjectHandle;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
typedef Hubris::HContainerArray< VComponentVisualDataHierarchyGeometryData >TArrayDataGeometryData;
typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalInvertSkinningMatrixPrepair(
	TArrayMatrix& out_arrayInvertSkinningMatrix,
	TArrayMatrix& out_arrayHierarchyMatrix,
	const TArrayBoneData& in_arrayBoneData,
	const Hubris::HSINT in_index = 0
	)
{
	if( in_arrayBoneData.SizeGet() <= in_index )
	{
		return;
	}

	const VComponentVisualAssetHierarchyBoneData& boneData = in_arrayBoneData[ in_index ];
	const HSINT parentIndex = boneData.ParentBoneIndexGet();
	if( HCOMMON_INVALID_INDEX != parentIndex )
	{
		out_arrayHierarchyMatrix[ in_index ] = out_arrayHierarchyMatrix[ parentIndex ] * boneData.RelativeToParentMatrixGet();
	}
	else
	{
		out_arrayHierarchyMatrix[ in_index ] = boneData.RelativeToParentMatrixGet();
	}

	out_arrayInvertSkinningMatrix[ in_index ] = HMatrixUtility::Inverse( out_arrayHierarchyMatrix[ in_index ] );

	//recurse
	LocalInvertSkinningMatrixPrepair(
		out_arrayInvertSkinningMatrix,
		out_arrayHierarchyMatrix,
		in_arrayBoneData,
		in_index + 1
		);

	return;
}

/**/
Hubris::HVOID LocalArrayDynamicIndexGet(
	TArraySint& in_out_arrayDynamicIndex,
	TArrayDataGeometryData& in_out_arrayDataGeometryData,
	const PGeometry& in_geometry,
	const Hubris::HSINT in_geometryIndex
	)
{
	in_out_arrayDynamicIndex.Clear();
	const PGeometryTypeSignature typeSignature = in_geometry.TypeSignatureGet();

	for( HSINT index = 0; index < typeSignature.TopologyStreamCountGet(); ++index )
	{
		const HSINT type = typeSignature.TopologyStreamTypeGet( index );
		if( PGeometryTypeSignature::TypeGetTopologyVertexIndex() != type )
		{
			continue;
		}

		HSINT positionDataStreamIndex = HCOMMON_INVALID_INDEX;
		HSINT normalDataStreamIndex = HCOMMON_INVALID_INDEX;
		const HBOOL hasSkinning = PGeometryUtility::SkinningDataStreamIndexGet(
			positionDataStreamIndex,
			normalDataStreamIndex,
			typeSignature,
			index
			);
		const HBOOL hasBounce = PGeometryUtility::SpringDataStreamIndexGet(
			positionDataStreamIndex,
			typeSignature,
			index
			);

		HSINT positionArraySize = 0;
		HSINT normalArraySize = 0;
		if( HCOMMON_INVALID_INDEX != positionDataStreamIndex )
		{
			HContainerUtility::UniqueAdd( in_out_arrayDynamicIndex, positionDataStreamIndex );
			positionArraySize = in_geometry.StoreDataVectorR3Get( positionDataStreamIndex ).SizeGet();
		}
		if( HCOMMON_INVALID_INDEX != normalDataStreamIndex )
		{
			HContainerUtility::UniqueAdd( in_out_arrayDynamicIndex, normalDataStreamIndex );
			normalArraySize = in_geometry.StoreDataVectorR3Get( normalDataStreamIndex ).SizeGet();
		}

		in_out_arrayDataGeometryData.Insert(
			VComponentVisualDataHierarchyGeometryData(
				typeSignature,
				in_geometryIndex,
				index,
				hasSkinning,
				positionArraySize,
				positionDataStreamIndex,
				normalArraySize,
				normalDataStreamIndex,
				hasBounce,
				positionArraySize,
				positionDataStreamIndex
				)
			);
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualAssetHierarchy::VComponentVisualAssetHierarchy(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HFileSystemPath& in_path			
	)
: m_renderLayer( HCOMMON_INVALID_INDEX )
, m_arrayGeometryData()
, m_arrayBoneData()
, m_arrayInvertSkinning()
//, m_arrayBoneSkinData()
{
	EMemento memento;

	EMementoUtility::Load(
		in_sceneApplicationInterface.FileSystemGet(),
		in_path,
		memento
		);

	EMementoAssign mementoAssign( memento );
	mementoAssign.MemberGet( "m_renderLayer", m_renderLayer );
	mementoAssign.MemberGet( "m_arrayGeometryData", m_arrayGeometryData );
	mementoAssign.MemberGet( "m_arrayBoneData", m_arrayBoneData );
	//mementoAssign.MemberGet( "m_arrayBoneSkinData", m_arrayBoneSkinData );

	HCOMMON_FOR_EACH( geometryData, m_arrayGeometryData, TArrayGeometryData )
	{
		const HSINT count = geometryData.MaterialGet().StageCountGet();
		for( HSINT index = 0; index < count; ++index )
		{
			if( HFALSE == geometryData.MaterialGet().StageMaterialGet( index ).FlagUseTextureGet() )
			{
				continue;
			}

			PImageRgba image;
			if( HTRUE == PImageTga::TgaLoadGeneric( 
					in_sceneApplicationInterface.FileSystemGet(),
					geometryData.MaterialGet().StageMaterialGet( index ).TexturePathGet(),
					image ) )
			{
				const HSINT imageId = in_sceneApplicationInterface.TextureAliasGet().TextureAdd( image );
				geometryData.MaterialGet().StageMaterialGet( index ).TextureIdSet( imageId );
			}
		}
	}

	//create render resources for static geometry
	TArrayDataGeometryData dummyArrayDataGeometryData;
	const HSINT count = m_arrayGeometryData.SizeGet();
	m_arrayStaticRenderResource.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		const VComponentVisualAssetHierarchyGeometryData& geometryData = m_arrayGeometryData[ index ];
		TArraySint arrayDynamic;

		LocalArrayDynamicIndexGet(
			arrayDynamic,
			dummyArrayDataGeometryData,
			geometryData.GeometryGet(),
			index
			);

		if( 0 != arrayDynamic.SizeGet() )
		{
			continue;
		}

		VComponentVisualComponentRenderResource* pRenderResource = HNULL;
		HCOMMON_NEW_PARAM_3(
			pRenderResource,
			VComponentVisualComponentRenderResource,
			in_sceneApplicationInterface,
			geometryData.GeometryGet(),
			arrayDynamic
			);
		m_arrayStaticRenderResource[ index ] = pRenderResource;
	}

	//prep invert skinning matrix
	const HSINT boneCount = m_arrayBoneData.SizeGet();
	TArrayMatrix arrayHierarchyMatrix;
	arrayHierarchyMatrix.SizeSet( boneCount );
	m_arrayInvertSkinning.SizeSet( boneCount );
	LocalInvertSkinningMatrixPrepair(
		m_arrayInvertSkinning,
		arrayHierarchyMatrix,
		m_arrayBoneData
		);

	return;
}

/**/
VComponentVisualAssetHierarchy::~VComponentVisualAssetHierarchy()
{
	m_arrayStaticRenderResource.Clear();
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentVisualAssetHierarchy::CreateAsset(
	const Hubris::HFileSystemPath& in_path,
	const TArrayGeometryData& in_arrayGeometryData,
	const TArrayBoneData& in_arrayBoneData,
	//const TArrayBoneSkinData& in_arrayBonsSkinData,
	const Hubris::HSINT in_renderLayer
	)
{
	HFileSystem fileSystem;
	EMemento memento;

	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "m_renderLayer", in_renderLayer );
	mementoCollect.MemberAdd( "m_arrayGeometryData", in_arrayGeometryData );
	mementoCollect.MemberAdd( "m_arrayBoneData", in_arrayBoneData );
	//mementoCollect.MemberAdd( "m_arrayBonsSkinData", in_arrayBonsSkinData );

	EMementoUtility::SaveText(
		fileSystem,
		in_path,
		memento
		);

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentVisualAssetHierarchy::DynamicRenderDataAquire(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	TArrayPointerRenderResource& in_out_arrayPointerRenderResource,
	TArrayDataGeometryData& in_out_arrayGeometryData
	)
{
	//visit each geometry asset, if it has dynamic data, create a resource for it
	const HSINT count = m_arrayGeometryData.SizeGet();
	in_out_arrayGeometryData.SizeResize( count );
	in_out_arrayPointerRenderResource.Clear();
	in_out_arrayPointerRenderResource.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		TArraySint arrayDynamic;
		VComponentVisualAssetHierarchyGeometryData& geometryData = m_arrayGeometryData[ index ];

		LocalArrayDynamicIndexGet(
			arrayDynamic,
			in_out_arrayGeometryData,
			geometryData.GeometryGet(),
			index
			);

		if( 0 == arrayDynamic.SizeGet() )
		{
			continue;
		}

		// create the render resource
		VComponentVisualComponentRenderResource* pRenderResource = HNULL;
		HCOMMON_NEW_PARAM_3(
			pRenderResource,
			VComponentVisualComponentRenderResource,
			in_sceneApplicationInterface,
			geometryData.GeometryGet(),
			TArraySint()
			);
		in_out_arrayPointerRenderResource[ index ] = pRenderResource;
	}

	return;
}

/**/
Hubris::HVOID VComponentVisualAssetHierarchy::Render(
	Sloth::SInterfaceRender& in_out_renderInterface,
	const Hubris::HSINT in_renderIndex,
	const Hubris::HMatrixR4& in_objectMatrix,
	const Hubris::HREAL in_alphaOverride,
	const TArrayMatrix& in_arrayBoneMatrix,
	TArrayPointerRenderResource& in_arrayPointerRenderResource
	)
{
	const HSINT count = m_arrayGeometryData.SizeGet();
	for( HSINT index = 0; index < count; ++index )
	{
		//do we have render resorces for object
		TPointerRenderResource& pStaticGeometry = m_arrayStaticRenderResource[ index ];
		TPointerRenderResource& pDynamicGeometry = in_arrayPointerRenderResource[ index ];
		if( ( HNULL == pStaticGeometry ) &&
			( HNULL == pDynamicGeometry ) )
		{
			continue;
		}

		const VComponentVisualAssetHierarchyGeometryData& assetGeometryData = m_arrayGeometryData[ index ];

		//for each geometry, set the parent bone matrix
		const HSINT parentBoneIndex = assetGeometryData.ParentBoneIndexGet();
		if( HCOMMON_INVALID_INDEX == parentBoneIndex )
		{
			in_out_renderInterface.ModelTransformSet( in_objectMatrix );
		}
		else
		{
			in_out_renderInterface.ModelTransformSet( in_objectMatrix * in_arrayBoneMatrix[ parentBoneIndex ] );
		}

		if( HNULL != pStaticGeometry )
		{
			pStaticGeometry->Render( 
				in_out_renderInterface,
				in_renderIndex,
				in_alphaOverride,
				assetGeometryData.MaterialGet() 
				);
		}

		if( HNULL != pDynamicGeometry )
		{
			pDynamicGeometry->Render( 
				in_out_renderInterface,
				in_renderIndex,
				in_alphaOverride,
				assetGeometryData.MaterialGet() 
				);
		}

	}

	return;
}

///////////////////////////////////////////////////////
// public methods
/**
Hubris::HVOID VComponentVisualAssetHierarchy::RenderDataAquire(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	HCOMMON_FOR_EACH( geometryData, m_arrayGeometryData, TArrayGeometryData )
	{
		geometryData.RenderDataAquire(
			in_sceneApplicationInterface
			);
	}
	return;
}

/**
Hubris::HVOID VComponentVisualAssetHierarchy::RenderDataRelease(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	HCOMMON_FOR_EACH( geometryData, m_arrayGeometryData, TArrayGeometryData )
	{
		geometryData.RenderDataRelease(
			in_sceneApplicationInterface
			);
	}
	return;
}

/**
Hubris::HVOID VComponentVisualAssetHierarchy::Render(
	Sloth::SInterfaceRender& in_out_renderInterface,
	const Hubris::HSINT in_renderIndex,
	const Hubris::HMatrixR4& in_objectMatrix,
	const Hubris::HREAL in_alphaOverride,
	const TArrayMatrix& in_arrayBoneMatrix,
	VScene& in_scene
	)
{

	HCOMMON_FOR_EACH( geometryData, m_arrayGeometryData, TArrayGeometryData )
	{
		const SMaterial& materal = geometryData.MaterialGet();
		const TObjectHandle handle = geometryData.ObjectHandleGet( in_renderIndex );

		//set up transform
		const HSINT parentBoneIndex = geometryData.ParentBoneIndexGet();
		if( HCOMMON_INVALID_INDEX == parentBoneIndex )
		{
			in_out_renderInterface.ModelTransformSet( in_objectMatrix );
		}
		else
		{
			in_out_renderInterface.ModelTransformSet( in_objectMatrix * in_arrayBoneMatrix[ parentBoneIndex ] );
		}

		//render each stage
		const HSINT count = materal.StageCountGet();
		for( HSINT index = 0; index < count; ++index )
		{
			in_out_renderInterface.MaterialSet(
				materal.StageMaterialGet( index ),
				in_alphaOverride
				);

			const HSINT textureId = materal.StageMaterialGet( index ).TextureIdGet();
			if( HCOMMON_INVALID_INDEX != textureId )
			{
				Hubris::HMatrixR4 matrix;
				in_scene.AssetManagerGet().TextureAliasGet().TextureMatrixGet( matrix, textureId );
				in_out_renderInterface.TextureTransformSet( matrix );
			}

			in_out_renderInterface.DrawGeometry( 
				handle,
				materal.StageGeometryGet( index )
				);
		}
	}
	return;
}
/**/
