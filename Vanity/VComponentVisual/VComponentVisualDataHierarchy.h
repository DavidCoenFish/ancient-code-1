//file: Vanity/VComponentVisual/VComponentVisualDataHierarchy.h
#ifndef _V_COMPONENT_VISUAL_DATA_HIERARCHY_H_
#define _V_COMPONENT_VISUAL_DATA_HIERARCHY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentVisual/VComponentVisualDataBase.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchy.h"
#include "Vanity/VComponentVisual/VComponentVisualDataHierarchyGeometryData.h"

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Sloth
{
	class SInterfaceRender;
	class SLight;
};
namespace Vanity
{
	class VScene;
	class VSceneApplicationInterface;
	class VComponentVisualDataHierarchyMatrixCache;
};

///////////////////////////////////////////////////////
// class
/*
	resource and data for a visual representation of a Hierarchy, the geometry and the bone hierarchy
	bit weird putting dynamic bone data in here when animation are not allowed, so don't put in dynamic bone data at this stage, treat it as animation
	//lift up to game object or client side
*/
namespace Vanity
{
	class VComponentVisualDataHierarchy : public VComponentVisualDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentVisualDataHierarchy, VComponentVisualDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentVisualDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VComponentVisualAssetHierarchy >TPointerAsset;
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HVOID* TObjectHandle;
		typedef Hubris::HContainerArray< Sloth::SLight >TArrayLight;

		typedef Hubris::HContainerArray< VComponentVisualDataHierarchyGeometryData >TArrayGeometryData;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;
		typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
		typedef Hubris::HSmartPointer< VComponentVisualComponentRenderResource >TPointerRenderResource;
		typedef Hubris::HContainerArray< TPointerRenderResource >TArrayPointerRenderResource;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualDataHierarchy();
		virtual ~VComponentVisualDataHierarchy();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualDataHierarchy( const VComponentVisualDataHierarchy& in_src );
		const VComponentVisualDataHierarchy& operator=( const VComponentVisualDataHierarchy& in_rhs );

		///////////////////////////////////////////////////////
		// implement VComponentVisualDataBase
	public:
		virtual Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface
			);
		virtual Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		virtual const Hubris::HSINT RenderLayerGet()const; 

		//pass base object data members might be bad, could pass base item of VScene and item index
		virtual Hubris::HVOID Render( 
			const TItemId in_itemId,
			const Hubris::HSINT in_renderIndex,
			VScene& in_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		//get animation interface? array bone data, array bone matrix
		Hubris::HVOID AquireAnimationData(
			const TArrayBoneData*& out_pArrayBoneData,
			TArrayMatrix*& out_pArrayMatrix
			);

		//update geometry data for skinning, bounce vertex
		Hubris::HVOID GeometryUpdate(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Sloth::SComponentDelta& in_delta
			);

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const Hubris::HFileSystemPath& FilePathGet()const{ return m_filePath; }
		Hubris::HFileSystemPath& FilePathGet(){ return m_filePath; }

		///////////////////////////////////////////////////////
		// private acessors
	private:
		const VComponentVisualDataHierarchyMatrixCache& MatrixCacheGet()const; 
		VComponentVisualDataHierarchyMatrixCache& MatrixCacheGet(); 

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HFileSystemPath m_filePath;
		TPointerAsset m_pAsset;

		TArrayGeometryData m_arrayGeometryData;
		TArrayMatrix m_arrayBoneAnimationMatrix;
		//array bool visible geometry

		//render resource for dynamic geometry of the asset, ie, the dynamic geometry
		TArrayPointerRenderResource m_arrayPointerRenderResource;

		VComponentVisualDataHierarchyMatrixCache* m_pMatrixCache;
	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_DATA_HIERARCHY_H_