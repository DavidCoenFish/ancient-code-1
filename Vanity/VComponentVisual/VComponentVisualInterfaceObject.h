//file: Vanity/VComponentVisual/VComponentVisualInterfaceObject.h
#ifndef _V_COMPONENT_VISUAL_INTERFACE_OBJECT_H_
#define _V_COMPONENT_VISUAL_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Vanity
{
	class VAssetManager;
	class VScene;
	class VSceneApplicationInterface;
	class VComponentVisual;
	class VComponentVisualAssetHierarchyBoneData;
	//class VComponentVisualAssetHierarchyBoneSkinData;
	class VComponentVisualAssetHierarchyGeometryData;
	class VComponentVisualAssetParticleData;
	class VComponentVisualAssetParticleTypeData;
};
namespace Sloth
{
	class SInterfaceRender;
	class SLight;
	class SMaterial;
	class SMaterialStage;
	class SComponentDelta;
};

///////////////////////////////////////////////////////
// class
/*
	public interface to present to client of vscene
*/
namespace Vanity
{
	class VComponentVisualInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< Sloth::SLight >TArrayLight;
		typedef Hubris::HContainerArray< VComponentVisualAssetParticleData >TArrayParticleData;
		typedef Hubris::HContainerArray< VComponentVisualAssetParticleTypeData >TArrayParticleTypeData;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyGeometryData >TArrayGeometryData;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;
		//typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneSkinData >TArrayBoneSkinData;
		typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualInterfaceObject(
			VComponentVisual& in_componentVisual,
			VScene& in_scene
			);
		~VComponentVisualInterfaceObject();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentVisualInterfaceObject( const VComponentVisualInterfaceObject& in_src );
		const VComponentVisualInterfaceObject& operator=( const VComponentVisualInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//create a visual simple asset
		static Hubris::HVOID VisualAssetSimpleCreate(
			const Hubris::HFileSystemPath& in_assetPath,
			const Pride::PGeometry& in_geometry,
			const Sloth::SMaterial& in_material,
			const Hubris::HSINT in_renderLayer
			);

		static Hubris::HVOID VisualAssetParticleCreate(
			const Hubris::HFileSystemPath& in_assetPath,
			const Sloth::SMaterialStage& in_materialStage,
			const TArrayParticleTypeData& in_arrayTypeData,
			const Hubris::HSINT in_maxCount,
			const Hubris::HSINT in_renderLayer
			);

		//this is problamatic, any more param and make a param object for skin data rather than pass in 3 arrays...
		static Hubris::HVOID VisualAssetHierarchyCreate(
			const Hubris::HFileSystemPath& in_path,
			const TArrayGeometryData& in_arrayGeometryData,
			const TArrayBoneData& in_arrayBoneData,
			//const TArrayBoneSkinData& in_arrayBonsSkinData,
			const Hubris::HSINT in_renderLayer
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		// put createion data for simple visual item at itemId
		Hubris::HVOID VisualSimpleCreate(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_assetPath
			);

		// put createion data for particle visual item at itemId
		Hubris::HVOID VisualParticleCreate(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_assetPath
			);

		// put createion data for hierarchy visual item at itemId
		Hubris::HVOID VisualHierarchyCreate(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_assetPath
			);

		// load and aquire resources for item at id
		Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);

		// release resources for item at id
		Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);

		Hubris::HVOID AlphaOverrideSet(
			const Hubris::HSINT in_frameId,
			const Hubris::HREAL in_alphaOverride,
			const TItemId in_itemId
			);

		const Hubris::HSINT RenderLayerGet(
			const TItemId in_itemId
			)const;

		//pass base object data members might be bad, could pass base item of VScene and item index
		Hubris::HVOID Render( 
			const TItemId in_itemId,
			const Hubris::HSINT in_renderIndex,
			VSceneApplicationInterface& in_sceneApplicationInterface //holds render interface, frame id
			);

		//paricel update
		Hubris::HVOID ParticleDataLock(
			const TItemId in_itemId,
			Hubris::HSINT& out_maxCount,
			TArrayParticleData*& out_pArrayParticleData
			);
		Hubris::HVOID ParticleDataUnlock(
			const TItemId in_itemId
			);

		//hierarchy update
		Hubris::HVOID HierarchyAquireAnimationData(
			const TItemId in_itemId,
			const TArrayBoneData*& out_pArrayBoneData,
			TArrayMatrix*& out_pArrayMatrix
			);
		Hubris::HVOID HierarchyGeometryUpdate(
			const TItemId in_itemId,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Sloth::SComponentDelta& in_delta //need delta for bounce
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentVisual& m_componentVisual;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_INTERFACE_OBJECT_H_