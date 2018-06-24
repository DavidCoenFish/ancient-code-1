//file: Vanity/VComponentVisual/VComponentVisualDataSimple.h
#ifndef _V_COMPONENT_VISUAL_DATA_SIMPLE_H_
#define _V_COMPONENT_VISUAL_DATA_SIMPLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentVisual/VComponentVisualDataBase.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetSimple.h"

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
	class VScene;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentVisualDataSimple : public VComponentVisualDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentVisualDataSimple, VComponentVisualDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentVisualDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VComponentVisualAssetSimple >TPointerAsset;
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HVOID* TObjectHandle;
		typedef Hubris::HContainerArray< Sloth::SLight >TArrayLight;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualDataSimple();
		virtual ~VComponentVisualDataSimple();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualDataSimple( const VComponentVisualDataSimple& in_src );
		const VComponentVisualDataSimple& operator=( const VComponentVisualDataSimple& in_rhs );

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
		//virtual Hubris::HVOID AnimationUpdateSubMatrix(
		//	const Hubris::HSINT in_boneIndex, 
		//	const Hubris::HMatrixR4& in_matrix 
		//	);

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const Hubris::HFileSystemPath& FilePathGet()const{ return m_filePath; }
		Hubris::HVOID FilePathSet( const Hubris::HFileSystemPath& in_filePath ){ m_filePath = in_filePath; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HFileSystemPath m_filePath;
		TPointerAsset m_pAsset;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_DATA_SIMPLE_H_