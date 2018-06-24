//file: Vanity/VComponentGame/VComponentGameItemData.h
#ifndef _V_COMPONENT_GAME_ITEM_DATA_H_
#define _V_COMPONENT_GAME_ITEM_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Envy/EMemento/EMemento_Export.h >
#include "Vanity/VAsset/VAsset_Export.h"
#include "Vanity/VComponentGame/VComponentGameDataAsset.h"
#include "Vanity/VComponentGame/VComponentGameDataBase.h"
#include "Vanity/VComponentGame/VComponentGameItemData.h"

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
	class VComponentGame;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentGameItemData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VComponentGameDataAsset >TPointerDataAsset;
		typedef Hubris::HSmartPointer< VComponentGameDataBase >TPointerData;
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentGameItemData( const VComponentGameItemData& in_src );
		VComponentGameItemData();
		~VComponentGameItemData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VComponentGameItemData& operator=( const VComponentGameItemData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentGameItemData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentGameItemData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public method
	public:
		Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface
			);
		Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		Hubris::HVOID GameObjectCreate(
			VScene& in_scene,
			const VComponentGame& in_componentGame, //factory
			const TItemId in_itemId
			);
		Hubris::HVOID GameObjectRelease(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);

		Hubris::HVOID Phase(
			VScene& in_out_scene,
			const TItemId in_itemId,
			const Hubris::HSINT in_phaseIndex,
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HFileSystemPath& DataPathGet()const{ return m_dataPath; }
		Hubris::HFileSystemPath& DataPathGet(){ return m_dataPath; }

		///////////////////////////////////////////////////////
		// private memebers
	private:
		Hubris::HFileSystemPath m_dataPath; //path for asset
		TPointerDataAsset m_pointerDataAsset; //reference to construction data (asset)
		TPointerData m_pointerData; //game object

	};

	/**/
	
};

#endif // _V_COMPONENT_GAME_ITEM_DATA_H_