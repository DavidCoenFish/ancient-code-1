//file: Vanity/VComponentVisual/VComponentVisualAssetHierarchy.h
#ifndef _V_COMPONENT_VISUAL_ASSET_HIERARCHY_H_
#define _V_COMPONENT_VISUAL_ASSET_HIERARCHY_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VAsset/VAsset_Export.h"
#include< Sloth/SMaterial/SMaterial_Export.h >
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneData.h"
//#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneSkinData.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyGeometryData.h"
#include "Vanity/VComponentVisual/VComponentVisualComponentRenderResource.h"

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Vanity
{
	class VComponentVisualDataHierarchyGeometryData;
	class VAssetManager;
	class VScene;
};	
namespace Sloth
{
	class SInterfaceRender;
};

///////////////////////////////////////////////////////
// class
/*
	NOTE: asset do not hold render resources for dynamic geometry, just static geometry
*/
namespace Vanity
{
	class VComponentVisualAssetHierarchy : public VAsset
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentVisualAssetHierarchy, VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentVisualDataHierarchyGeometryData >TArrayDataGeometryData;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyGeometryData >TArrayGeometryData;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;
		//typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneSkinData >TArrayBoneSkinData;
		typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
		typedef Hubris::HSmartPointer< VComponentVisualComponentRenderResource >TPointerRenderResource;
		typedef Hubris::HContainerArray< TPointerRenderResource >TArrayPointerRenderResource;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualAssetHierarchy(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HFileSystemPath& in_path			
			);
		virtual ~VComponentVisualAssetHierarchy();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualAssetHierarchy( const VAsset& in_src );
		const VComponentVisualAssetHierarchy& operator=( const VAsset& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID CreateAsset(
			const Hubris::HFileSystemPath& in_path,
			const TArrayGeometryData& in_arrayGeometryData,
			const TArrayBoneData& in_arrayBoneData,
			//const TArrayBoneSkinData& in_arrayBonsSkinData,
			const Hubris::HSINT in_renderLayer
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DynamicRenderDataAquire(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			TArrayPointerRenderResource& in_out_arrayPointerRenderResource,
			TArrayDataGeometryData& in_out_arrayGeometryData
			);

		Hubris::HVOID Render(
			Sloth::SInterfaceRender& in_out_renderInterface,
			const Hubris::HSINT in_renderIndex,
			const Hubris::HMatrixR4& in_objectMatrix,
			const Hubris::HREAL in_alphaOverride,
			const TArrayMatrix& in_arrayBoneMatrix,
			TArrayPointerRenderResource& in_arrayPointerRenderResource
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT RenderLayerGet()const{ return m_renderLayer; }
		const TArrayGeometryData& ArrayGeometryDataGet()const{ return m_arrayGeometryData; }
		const TArrayBoneData& ArrayBoneDataGet()const{ return m_arrayBoneData; }
		const TArrayMatrix& ArrayInvertSkinningGet()const{ return m_arrayInvertSkinning; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_renderLayer;
		TArrayGeometryData m_arrayGeometryData; //geometry, material, array render handle, bone index
		TArrayBoneData m_arrayBoneData;
		TArrayMatrix m_arrayInvertSkinning; // generate on load, the invert bone heirarchy matrix for skinning
		//TArrayBoneSkinData m_arrayBoneSkinData;
		//array of static geometry render resources. expect external clients of asset to hold dynamic render resources
		TArrayPointerRenderResource m_arrayStaticRenderResource;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_HIERARCHY_H_