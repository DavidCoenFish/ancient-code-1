//file: Vanity/VComponentVisual/VComponentVisualDataParticle.h
#ifndef _V_COMPONENT_VISUAL_DATA_PARTICLE_H_
#define _V_COMPONENT_VISUAL_DATA_PARTICLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentVisual/VComponentVisualDataBase.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticle.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticleData.h"
#include "Vanity/VComponentVisual/VComponentVisualComponentRenderResource.h"

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
	class VComponentVisualDataParticle : public VComponentVisualDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentVisualDataParticle, VComponentVisualDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentVisualDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VComponentVisualAssetParticle >TPointerAsset;
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HVOID* TObjectHandle;
		typedef Hubris::HContainerArray< TObjectHandle >TArrayObjectHandle;
		typedef Hubris::HContainerArray< VComponentVisualAssetParticleData >TArrayParticleData;
		typedef Hubris::HSmartPointer< VComponentVisualComponentRenderResource >TPointerRenderResource;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualDataParticle();
		virtual ~VComponentVisualDataParticle();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualDataParticle( const VComponentVisualDataParticle& in_src );
		const VComponentVisualDataParticle& operator=( const VComponentVisualDataParticle& in_rhs );

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
		Hubris::HVOID ParticleDataLock(
			Hubris::HSINT& out_maxCount,
			TArrayParticleData*& out_pArrayParticleData
			);
		Hubris::HVOID ParticleDataUnlock();

		///////////////////////////////////////////////////////
		// private methods
	public:
		Hubris::HVOID ParticDataToGeometry(
			const Pride::PGeometryTypeSignature& in_typeSignature
			);

		//Hubris::HVOID RenderDataAcquire(
		//	Sloth::SInterfaceRender& in_out_interfaceRender,
		//	const Hubris::HSINT in_renderIndex
		//	);
		//Hubris::HVOID RenderDataRelease(
		//	Sloth::SInterfaceRender& in_out_interfaceRender,
		//	const Hubris::HSINT in_renderIndex
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
		TArrayParticleData m_arrayData;
		TPointerRenderResource m_pRenderResource;

		Hubris::HSINT m_dataIndexVertex;
		Hubris::HSINT m_dataIndexColour;
		Hubris::HSINT m_dataIndexUv;
		Hubris::HSINT m_topologyVertexIndex;
		Hubris::HSINT m_topologyIndexTriangle;

		Pride::PGeometry m_geometry;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_DATA_PARTICLE_H_