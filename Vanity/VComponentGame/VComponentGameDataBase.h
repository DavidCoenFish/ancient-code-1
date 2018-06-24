//file: Vanity/VComponentGame/VComponentGameDataBase.h
#ifndef _V_COMPONENT_GAME_DATA_BASE_H_
#define _V_COMPONENT_GAME_DATA_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Envy/EMemento/EMemento_Export.h >
#include "Vanity/VAsset/VAsset_Export.h"

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
	class VScene;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentGameDataBase : public Hubris::HSmartPointerObjectBase< VComponentGameDataBase >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentGameDataBase();
		virtual ~VComponentGameDataBase();

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID Phase(
			VScene& in_out_scene,
			const TItemId in_itemId,
			const Hubris::HSINT in_phaseIndex,
			VSceneApplicationInterface& in_sceneApplicationInterface
			)=0;

	};

	/**/
	
};

#endif // _V_COMPONENT_GAME_DATA_BASE_H_