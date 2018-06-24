//file: Vanity/VComponentVisual/VComponentVisualAssetParticle.h
#ifndef _V_COMPONENT_VISUAL_ASSET_PARTICLE_H_
#define _V_COMPONENT_VISUAL_ASSET_PARTICLE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VAsset/VAsset_Export.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticleData.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticleTypeData.h"

#include< Sloth/SMaterial/SMaterial_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentVisualAssetParticle : public VAsset
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentVisualAssetParticle, VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentVisualAssetParticleTypeData >TArrayTypeData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualAssetParticle(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HFileSystemPath& in_path		
			);
		virtual ~VComponentVisualAssetParticle();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualAssetParticle( const VAsset& in_src );
		const VComponentVisualAssetParticle& operator=( const VAsset& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID CreateAsset(
			const Hubris::HFileSystemPath& in_path,
			const Sloth::SMaterialStage& in_materialStage,
			const TArrayTypeData& in_arrayTypeData,
			const Hubris::HSINT in_maxCount,
			const Hubris::HSINT in_renderLayer
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID ParticleDataSet(
			Hubris::HSINT& out_maxCount,
			TArrayTypeData*& out_pArrayParticleData
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT MaxCountGet()const{ return m_maxCount; }
		const Hubris::HSINT RenderLayerGet()const{ return m_renderLayer; }

		const Sloth::SMaterialStage& MaterialStageGet()const{ return m_materialStage; }

		const TArrayTypeData& ArrayTypeDataGet()const{ return m_arrayTypeData; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Sloth::SMaterialStage m_materialStage;
		TArrayTypeData m_arrayTypeData;
		Hubris::HSINT m_maxCount;
		Hubris::HSINT m_textureIndex;
		Hubris::HSINT m_renderLayer;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_PARTICLE_H_