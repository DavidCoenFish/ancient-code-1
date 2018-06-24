//file: Vanity/VComponentGame/VComponentGameItemData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentGame/VComponentGameItemData.h"

#include "Vanity/VComponentGame/VComponentGame.h"

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
VComponentGameItemData::VComponentGameItemData( const VComponentGameItemData& in_src )
: m_dataPath()
, m_pointerDataAsset()
, m_pointerData()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentGameItemData::VComponentGameItemData()
: m_dataPath()
, m_pointerDataAsset()
, m_pointerData()
{
	return;
}

/**/
VComponentGameItemData::~VComponentGameItemData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VComponentGameItemData& VComponentGameItemData::operator=( const VComponentGameItemData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_dataPath = in_rhs.m_dataPath;
		m_pointerDataAsset = in_rhs.m_pointerDataAsset;
		m_pointerData = in_rhs.m_pointerData;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VComponentGameItemData::operator==( const VComponentGameItemData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_dataPath == in_rhs.m_dataPath );
		match &= ( m_pointerDataAsset == in_rhs.m_pointerDataAsset );
		match &= ( m_pointerData == in_rhs.m_pointerData );
	}
	return match;
}

/**/
const Hubris::HBOOL VComponentGameItemData::operator!=( const VComponentGameItemData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public method
/**/
Hubris::HVOID VComponentGameItemData::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pointerDataAsset = in_sceneApplicationInterface.AssetManagerGet().AssetRequest< VComponentGameDataAsset >( 
		in_sceneApplicationInterface,
		m_dataPath 
		);
	return;
}

/**/
Hubris::HVOID VComponentGameItemData::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pointerDataAsset = HNULL;
	in_sceneApplicationInterface.AssetManagerGet().AssetReleaseUnused();
	return;
}

/**/
Hubris::HVOID VComponentGameItemData::GameObjectCreate(
	VScene& in_out_scene,
	const VComponentGame& in_componentGame, //factory
	const TItemId in_itemId
	)
{
	if( HNULL == m_pointerDataAsset )
	{
		return;
	}

	m_pointerData = in_componentGame.FactoryGameObjectCreate(
		m_pointerDataAsset->GameObjectTypeNameGet(),
		m_pointerDataAsset->DataGet(),
		in_out_scene,
		in_itemId
		);

	return;
}

/**/
Hubris::HVOID VComponentGameItemData::GameObjectRelease(
	VSceneApplicationInterface& in_out_sceneApplicationInterface,
	const TItemId
	)
{
	m_pointerData = HNULL;
	in_out_sceneApplicationInterface.AssetManagerGet().AssetReleaseUnused();

	return;
}

/**/
Hubris::HVOID VComponentGameItemData::Phase(
	VScene& in_out_scene,
	const TItemId in_itemId,
	const Hubris::HSINT in_phaseIndex,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	if( HNULL == m_pointerData )
	{
		return;
	}

	m_pointerData->Phase( 
		in_out_scene, 
		in_itemId,
		in_phaseIndex,
		in_sceneApplicationInterface
		);

	return;
}

/**/
