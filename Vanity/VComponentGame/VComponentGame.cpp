//file: Vanity/VComponentGame/VComponentGame.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentGame/VComponentGame.h"

#include "Vanity/VComponentGame/VComponentGameItemData.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Envy;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentGame::VComponentGame()
: m_treeNameCreator()
, m_arrayItemData()
, m_phaseCount( 0 )
{
	return;
}

/**/
VComponentGame::~VComponentGame()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentGame::OnAddItem(
	const Hubris::HSINT in_itemIndex
	)
{
	if( m_arrayItemData.SizeGet() <= in_itemIndex )
	{
		m_arrayItemData.SizeResize( in_itemIndex + 1 );
	}

	return;
}

/**/
HVOID VComponentGame::OnRemoveItem(
	const Hubris::HSINT in_itemIndex
	)
{
	ItemDataGet( in_itemIndex ) = VComponentGameItemData();

	return;
}

/**/
Hubris::HVOID VComponentGame::ItemDataSet(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_dataPath
	)
{
	ItemDataGet( in_itemId ).DataPathGet() = in_dataPath;
	return;
}

/**/
Hubris::HVOID VComponentGame::Load(
	VSceneApplicationInterface& in_out_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	ItemDataGet( in_itemId ).Load( in_out_sceneApplicationInterface );
	return;
}

/**/
Hubris::HVOID VComponentGame::UnLoad(
	VSceneApplicationInterface& in_out_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	ItemDataGet( in_itemId ).UnLoad( in_out_sceneApplicationInterface );
	return;
}

/**/
Hubris::HVOID VComponentGame::GameObjectCreate(
	VScene& in_out_scene,
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface ),
	const TItemId in_itemId
	)
{
	ItemDataGet( in_itemId ).GameObjectCreate(
		in_out_scene,
		*this,
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentGame::GameObjectRelease(
	VScene& HCOMMON_UNUSED_VAR( in_out_scene ),
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	ItemDataGet( in_itemId ).GameObjectRelease(
		in_sceneApplicationInterface,
		in_itemId
		);
	return;
}

/**/
Hubris::HVOID VComponentGame::Phase(
	VScene& in_out_scene,
	const TItemId in_itemId,
	const Hubris::HSINT in_phaseIndex,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{	
	ItemDataGet( in_itemId ).Phase(
		in_out_scene,
		in_itemId,
		in_phaseIndex,
		in_sceneApplicationInterface
		);

	return;
}

/**/
VComponentGameDataBase* const VComponentGame::FactoryGameObjectCreate(
	const Hubris::HString& in_gameObjectTypeName,
	const Envy::EMemento& in_data,
	Vanity::VScene& in_out_scene,
	const TItemId in_itemId
	)const
{
	const TTreeStringGameObjectCreate::TIterator iterator = m_treeNameCreator.Find( in_gameObjectTypeName );
	if( iterator == m_treeNameCreator.End() )
	{
		return HNULL;
	}

	EMementoAssign mementoAssign( in_data );
	VComponentGameDataBase* const pGameObjectBase = ( ( *iterator )( 
		EMementoAssign( in_data ), 
		in_out_scene,
		in_itemId
		) );

	return pGameObjectBase;
}

/**/
Hubris::HVOID VComponentGame::FactoryGameObjectCreateRegister( 
	const Hubris::HString& in_gameObjectTypeName,
	const FGameObjectCreate in_fGameObjectCreate
	)
{
	m_treeNameCreator.Insert( in_gameObjectTypeName, in_fGameObjectCreate );
	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
const VComponentGameItemData& VComponentGame::ItemDataGet( const TItemId in_itemId )const
{
	HCOMMON_ASSERT( ( 0 <= in_itemId ) && ( in_itemId < m_arrayItemData.SizeGet() ), "invalid param" );
	return m_arrayItemData[ in_itemId ];
}

/**/
VComponentGameItemData& VComponentGame::ItemDataGet( const TItemId in_itemId )
{
	HCOMMON_ASSERT( ( 0 <= in_itemId ) && ( in_itemId < m_arrayItemData.SizeGet() ), "invalid param" );
	return m_arrayItemData[ in_itemId ];
}

/**/