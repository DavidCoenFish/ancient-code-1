//file: Vanity/VComponentGame/VComponentGameInterfaceObject.h
#ifndef _V_COMPONENT_GAME_INTERFACE_OBJECT_H_
#define _V_COMPONENT_GAME_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	class SComponentDelta;
	class SInterfaceRender;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;
	class VComponentGame;
	class VComponentGameDataBase;
	class VScene;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentGameInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerPair< Hubris::HVectorR3, Hubris::HREAL >TPairVectorReal;
		typedef Hubris::HContainerArray< TPairVectorReal >TArrayPairVectorReal;
		//facory method for creation of game objects
		typedef VComponentGameDataBase* const (*FGameObjectCreate)(
			const Envy::EMementoAssign& in_dataStore,
			Vanity::VScene& in_out_scene,
			const TItemId in_itemId
			);

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentGameInterfaceObject(
			VComponentGame& in_componentGame,
			VScene& in_scene
			);
		~VComponentGameInterfaceObject();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//create a visual simple asset
		static Hubris::HVOID GameObjectAssetCreate(
			const Hubris::HFileSystemPath& in_assetPath,
			const Hubris::HString& in_gameObjectTypeName,
			const Envy::EMemento& in_data
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID ItemDataSet(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_dataPath
			);

		Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);
		Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);
		Hubris::HVOID GameObjectCreate(
			VSceneApplicationInterface& in_sceneApplicationInterface,
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

		Hubris::HVOID FactoryGameObjectCreateRegister( 
			const Hubris::HString& in_gameObjectTypeName,
			const FGameObjectCreate in_fGameObjectCreate
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HVOID PhaseCountSet( const Hubris::HSINT in_phaseCount );
		const Hubris::HSINT PhaseCountGet()const;

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentGameInterfaceObject( const VComponentGameInterfaceObject& in_src );
		const VComponentGameInterfaceObject& operator=( const VComponentGameInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentGame& m_componentGame;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_GAME_INTERFACE_OBJECT_H_