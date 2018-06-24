//file: Vanity/VComponentVisual/VComponentVisualInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualInterfaceObject.h"

#include "Vanity/VComponentVisual/VComponentVisual.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchy.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetSimple.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticle.h"

#include "Vanity/VScene/VScene.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualInterfaceObject::VComponentVisualInterfaceObject(
	VComponentVisual& in_componentVisual,
	VScene& in_scene
	)
: m_componentVisual( in_componentVisual )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentVisualInterfaceObject::~VComponentVisualInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentVisualInterfaceObject::VisualAssetSimpleCreate(
	const Hubris::HFileSystemPath& in_assetPath,
	const Pride::PGeometry& in_geometry,
	const Sloth::SMaterial& in_material,
	const Hubris::HSINT in_renderLayer
	)
{
	VComponentVisualAssetSimple::CreateAsset(
		in_assetPath,
		in_geometry,
		in_material,
		in_renderLayer
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::VisualAssetParticleCreate(
	const Hubris::HFileSystemPath& in_assetPath,
	const Sloth::SMaterialStage& in_materialStage,
	const TArrayParticleTypeData& in_arrayTypeData,
	const Hubris::HSINT in_maxCount,
	const Hubris::HSINT in_renderLayer
	)
{
	VComponentVisualAssetParticle::CreateAsset(
		in_assetPath,
		in_materialStage,
		in_arrayTypeData,
		in_maxCount,
		in_renderLayer
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::VisualAssetHierarchyCreate(
	const Hubris::HFileSystemPath& in_assetPath,
	const TArrayGeometryData& in_arrayGeometryData,
	const TArrayBoneData& in_arrayBoneData,
	//const TArrayBoneSkinData& in_arrayBonsSkinData,
	const Hubris::HSINT in_renderLayer
	)
{
	VComponentVisualAssetHierarchy::CreateAsset(
		in_assetPath,
		in_arrayGeometryData,
		in_arrayBoneData,
		//in_arrayBonsSkinData,
		in_renderLayer
		);

	return;
}

/**/

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentVisualInterfaceObject::VisualSimpleCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentVisual.VisualSimpleCreate(
		in_itemId,
		in_assetPath
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::VisualParticleCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentVisual.VisualParticleCreate(
		in_itemId,
		in_assetPath
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::VisualHierarchyCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentVisual.VisualHierarchyCreate(
		in_itemId,
		in_assetPath
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.Load(
		in_sceneApplicationInterface,
		in_itemId
		);
	
	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.UnLoad(
		in_sceneApplicationInterface,
		in_itemId
		);
	
	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::AlphaOverrideSet(
	const Hubris::HSINT in_frameId,
	const Hubris::HREAL in_alphaOverride,
	const TItemId in_itemId
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.AlphaOverrideSet(
		in_frameId,
		in_alphaOverride,
		in_itemId
		);
	
	return;
}

/**/
const Hubris::HSINT VComponentVisualInterfaceObject::RenderLayerGet(
	const TItemId in_itemId
	)const
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	const HSINT renderLayer = m_componentVisual.RenderLayerGet(
		in_itemId
		);
	return renderLayer;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::Render( 
	const TItemId in_itemId,
	const Hubris::HSINT in_renderIndex,
	VSceneApplicationInterface& in_sceneApplicationInterface //holds render interface, frame id
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.Render(
		in_itemId,
		in_renderIndex,
		m_scene,
		in_sceneApplicationInterface
		);
	
	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::ParticleDataLock(
	const TItemId in_itemId,
	Hubris::HSINT& out_maxCount,
	TArrayParticleData*& out_pArrayParticleData
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.ParticleDataLock(
		in_itemId,
		out_maxCount,
		out_pArrayParticleData
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::ParticleDataUnlock(
	const TItemId in_itemId
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.ParticleDataUnlock(
		in_itemId
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::HierarchyAquireAnimationData(
	const TItemId in_itemId,
	const TArrayBoneData*& out_pArrayBoneData,
	TArrayMatrix*& out_pArrayMatrix
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.HierarchyAquireAnimationData(
		in_itemId,
		out_pArrayBoneData,
		out_pArrayMatrix
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualInterfaceObject::HierarchyGeometryUpdate(
	const TItemId in_itemId,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Sloth::SComponentDelta& in_delta
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentVisualGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );
	m_componentVisual.HierarchyGeometryUpdate(
		in_itemId,
		in_sceneApplicationInterface,
		in_delta
		);

	return;
}

/**/
