//file: Vanity/VComponentVisual/VComponentVisualDataBase.h
#ifndef _V_COMPONENT_VISUAL_ITEM_DATA_BASE_H_
#define _V_COMPONENT_VISUAL_ITEM_DATA_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Envy/EMemento/EMemento_Export.h >
#include "Vanity/VAsset/VAsset_Export.h"

namespace Sloth
{
	class SInterfaceRender;
	class SLight;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;
	class VSceneApplicationInterface;
	class VScene;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentVisualDataBase : public Hubris::HSmartPointerObjectBase< VComponentVisualDataBase >
	{
		HTYPE_RUN_TIME_TYPE_INFO_BASE( VComponentVisualDataBase );
		EMEMENTO_FACTORY_HEADER_PURE( VComponentVisualDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< Sloth::SLight >TArrayLight;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualDataBase();
		virtual ~VComponentVisualDataBase();

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface
			)=0;
		virtual Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface
			)=0;

		//currently 0 for normal (no blending with screen) or 1 for alpha (blend with screen), 
		virtual const Hubris::HSINT RenderLayerGet()const=0; 

		//pass base object data members might be bad, could pass base item of VScene and item index
		virtual Hubris::HVOID Render( 
			const TItemId in_itemId,
			const Hubris::HSINT in_renderIndex,
			VScene& in_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface
			)=0;
		//virtual Hubris::HVOID AnimationUpdateSubMatrix(
		//	const Hubris::HSINT in_boneIndex, 
		//	const Hubris::HMatrixR4& in_matrix 
		//	)=0;

		///////////////////////////////////////////////////////
		// public members
	public:
		Hubris::HVOID AlphaOverrideSet(
			const Hubris::HSINT in_alphaOverrideFrameId,
			Hubris::HREAL in_alphaOverride
			);

		///////////////////////////////////////////////////////
		// protected accessors
	protected:
		const Hubris::HSINT AlphaOverrideFrameIdGet()const{ return m_alphaOverrideFrameId; }
		const Hubris::HREAL AlphaOverrideGet()const{ return m_alphaOverride; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_alphaOverrideFrameId;
		Hubris::HREAL m_alphaOverride;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ITEM_DATA_BASE_H_