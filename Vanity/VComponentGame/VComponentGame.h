//file: Vanity/VComponentGame/VComponentGame.h
#ifndef _V_COMPONENT_GAME_H_
#define _V_COMPONENT_GAME_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentGame/VComponentGameDataBase.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentGame;
};

namespace Envy
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//VComponentGame
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentGame& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentGame& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	struct VComponentGameRenderParam;
	class VComponentGameCamera;
	class VInterfaceRenderTarget;
	class VImageHDR;
	class VComponentGameItemData;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentGame
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VComponentGame >( Envy::EMementoCollect& in_out_mementoCollect, const VComponentGame& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VComponentGame >( const Envy::EMementoAssign& in_out_mementoAssign, VComponentGame& out_data );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentGameItemData >TArrayItemData;
		typedef Hubris::HSINT TItemId;

		//facory method for creation of game objects
		typedef VComponentGameDataBase* const (*FGameObjectCreate)(
			const Envy::EMementoAssign& in_data,
			Vanity::VScene& in_out_scene,
			const TItemId in_itemId
			);

		//presume VComponentGameEditFormat is not needed for creation, just for edit
		typedef Hubris::HContainerTree< Hubris::HString, FGameObjectCreate >TTreeStringGameObjectCreate;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentGame();
		~VComponentGame();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentGame( const VComponentGame& in_src );
		const VComponentGame& operator=( const VComponentGame& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const Hubris::HSINT in_itemIndex 
			);

		Hubris::HVOID OnRemoveItem(
			const Hubris::HSINT in_itemIndex 
			);

		Hubris::HVOID ItemDataSet(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_dataPath
			);

		Hubris::HVOID Load(
			VSceneApplicationInterface& in_out_sceneApplicationInterface,
			const TItemId in_itemId
			);
		Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_out_sceneApplicationInterface,
			const TItemId in_itemId
			);
		Hubris::HVOID GameObjectCreate(
			VScene& in_out_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);
		Hubris::HVOID GameObjectRelease(
			VScene& in_out_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);

		Hubris::HVOID Phase(
			VScene& in_out_scene,
			const TItemId in_itemId,
			const Hubris::HSINT in_phaseIndex,
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		VComponentGameDataBase* const FactoryGameObjectCreate(
			const Hubris::HString& in_gameObjectTypeName,
			const Envy::EMemento& in_data,
			Vanity::VScene& in_out_scene,
			const TItemId in_itemId
			)const;

		Hubris::HVOID FactoryGameObjectCreateRegister( 
			const Hubris::HString& in_gameObjectTypeName,
			const FGameObjectCreate in_fGameObjectCreate
			);

		///////////////////////////////////////////////////////
		// private methods
	private:
		const VComponentGameItemData& ItemDataGet( const TItemId in_itemId )const;
		VComponentGameItemData& ItemDataGet( const TItemId in_itemId );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HVOID PhaseCountSet( const Hubris::HSINT in_phaseCount ){ m_phaseCount = in_phaseCount; return; }
		const Hubris::HSINT PhaseCountGet()const{ return m_phaseCount; }

		const TArrayItemData& ArrayItemDataGet()const{ return m_arrayItemData; }
		TArrayItemData& ArrayItemDataGet(){ return m_arrayItemData; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TTreeStringGameObjectCreate m_treeNameCreator;
		TArrayItemData m_arrayItemData;
		Hubris::HSINT m_phaseCount;

	};

	/**/
	
};

#endif // _V_COMPONENT_GAME_H_