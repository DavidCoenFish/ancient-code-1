//file: Vanity/VComponentVisual/VComponentVisual.h
#ifndef _V_COMPONENT_VISUAL_H_
#define _V_COMPONENT_VISUAL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentVisual/VComponentVisualDataBase.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInterfaceRender;
	class SLight;
	class SMaterial;
	class SComponentDelta;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentVisual;
};

namespace Envy
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//VComponentVisual
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisual& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisual& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	struct VComponentVisualRenderParam;
	class VComponentVisualCamera;
	class VInterfaceRenderTarget;
	class VImageHDR;
	class VComponentVisualItemData;
	class VComponentVisualAssetParticleData;
	class VComponentVisualAssetHierarchyBoneData;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentVisual
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VComponentVisual >( Envy::EMementoCollect& in_out_mementoCollect, const VComponentVisual& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VComponentVisual >( const Envy::EMementoAssign& in_out_mementoAssign, VComponentVisual& out_data );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VComponentVisualDataBase >TPointerData;
		typedef Hubris::HContainerArray< TPointerData >TArrayPointerData;
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< Sloth::SLight >TArrayLight;
		typedef Hubris::HContainerArray< VComponentVisualAssetParticleData >TArrayParticleData;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;
		typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisual();
		~VComponentVisual();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentVisual( const VComponentVisual& in_src );
		const VComponentVisual& operator=( const VComponentVisual& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const Hubris::HSINT in_itemIndex 
			);

		Hubris::HVOID OnRemoveItem(
			const Hubris::HSINT in_itemIndex 
			);

		//create a visual simple for the item
		Hubris::HVOID VisualSimpleCreate(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_assetPath
			);

		Hubris::HVOID VisualParticleCreate(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_assetPath
			);

		Hubris::HVOID VisualHierarchyCreate(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_assetPath
			);

		Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);
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
			VScene& in_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface //holds render interface, frame id
			);

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
		TArrayPointerData m_arrayPointerData;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_H_