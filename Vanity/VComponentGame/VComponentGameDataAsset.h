//file: Vanity/VComponentGame/VComponentGameDataAsset.h
#ifndef _V_COMPONENT_GAME_DATA_ASSET_H_
#define _V_COMPONENT_GAME_DATA_ASSET_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Envy/EMemento/EMemento_Export.h >
#include "Vanity/VAsset/VAsset_Export.h"
#include "Vanity/VComponentGame/VComponentGameDataBase.h"

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

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentGameDataAsset : public VAsset
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentGameDataAsset, VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentGameDataAsset(
			VSceneApplicationInterface& in_out_sceneApplicationInterface,
			const Hubris::HFileSystemPath& in_path			
			);
		~VComponentGameDataAsset();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentGameDataAsset( const VComponentGameDataAsset& in_src );
		const VComponentGameDataAsset& operator=( const VComponentGameDataAsset& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID CreateAsset(
			const Hubris::HFileSystemPath& in_path,
			const Hubris::HString in_gameObjectTypeName,
			const Envy::EMemento& in_data
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HString& GameObjectTypeNameGet()const{ return m_gameObjectTypeName; }
		Hubris::HString& GameObjectTypeNameGet(){ return m_gameObjectTypeName; }

		const Envy::EMemento& DataGet()const{ return m_data; }
		Envy::EMemento& DataGet(){ return m_data; }

		///////////////////////////////////////////////////////
		// private memebers
	private:
		Hubris::HString m_gameObjectTypeName;
		Envy::EMemento m_data;
		

	};

	/**/
	
};

#endif // _V_COMPONENT_GAME_DATA_ASSET_H_