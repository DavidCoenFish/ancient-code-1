//file: Vanity/VComponentGame/VComponentGameInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentGame/VComponentGameInterfaceObject.h"

#include "Vanity/VComponentGame/VComponentGame.h"
#include "Vanity/VComponentGame/VComponentGameDataAsset.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentGameInterfaceObject::VComponentGameInterfaceObject(
	VComponentGame& in_componentGame,
	VScene& in_scene
	)
: m_componentGame( in_componentGame )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentGameInterfaceObject::~VComponentGameInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentGameInterfaceObject::GameObjectAssetCreate(
	const Hubris::HFileSystemPath& in_assetPath,
	const Hubris::HString& in_gameObjectTypeName,
	const Envy::EMemento& in_data
	)
{
	VComponentGameDataAsset::CreateAsset(
		in_assetPath,
		in_gameObjectTypeName,
		in_data
		);
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentGameInterfaceObject::ItemDataSet(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_dataPath
	)
{
	m_componentGame.ItemDataSet(
		in_itemId,
		in_dataPath
		);
	return;
}

/**/
Hubris::HVOID VComponentGameInterfaceObject::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	m_componentGame.Load(
		in_sceneApplicationInterface,
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentGameInterfaceObject::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	m_componentGame.UnLoad(
		in_sceneApplicationInterface,
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentGameInterfaceObject::GameObjectCreate(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	m_componentGame.GameObjectCreate(
		m_scene,
		in_sceneApplicationInterface,
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentGameInterfaceObject::GameObjectRelease(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	m_componentGame.GameObjectRelease(
		m_scene,
		in_sceneApplicationInterface,
		in_itemId
		);
}

/**/
Hubris::HVOID VComponentGameInterfaceObject::Phase(
	VScene& in_out_scene,
	const TItemId in_itemId,
	const Hubris::HSINT in_phaseIndex,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_componentGame.Phase(
		in_out_scene,
		in_itemId,
		in_phaseIndex,
		in_sceneApplicationInterface
		);

	return;
}

/**/
Hubris::HVOID VComponentGameInterfaceObject::FactoryGameObjectCreateRegister( 
	const Hubris::HString& in_gameObjectTypeName,
	const FGameObjectCreate in_fGameObjectCreate
	)
{
	m_componentGame.FactoryGameObjectCreateRegister(
		in_gameObjectTypeName,
		in_fGameObjectCreate
		);
	return;
}

/**/
///////////////////////////////////////////////////////
// public accessors
/**/
Hubris::HVOID VComponentGameInterfaceObject::PhaseCountSet( const Hubris::HSINT in_phaseCount )
{
	m_componentGame.PhaseCountSet( in_phaseCount );
	return;
}

/**/
const Hubris::HSINT VComponentGameInterfaceObject::PhaseCountGet()const
{
	return m_componentGame.PhaseCountGet();
}

/**/
