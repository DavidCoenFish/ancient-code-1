//file: Greed/GPlayerCharacter/GPlayerCharacter.h
#ifndef _G_PLAYER_CHARACTER_H_
#define _G_PLAYER_CHARACTER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Vanity/VComponentGame/VComponentGame_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Vanity
{
	class VSceneApplicationInterface;
};
namespace Greed
{
	class GComponentTranslation;
	class GComponentRotation;
	class GComponentAnimation;
	class GComponentTilt;
};

///////////////////////////////////////////////////////
// class
/*
	rem to register factory with Greed::GUtility::RegisterGameObjectFactory
*/
namespace Greed
{
	class GPlayerCharacter : public Vanity::VComponentGameDataBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		GPlayerCharacter();
		virtual ~GPlayerCharacter();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GPlayerCharacter( const GPlayerCharacter& in_src );
		const GPlayerCharacter& operator=( const GPlayerCharacter& in_rhs );

		///////////////////////////////////////////////////////
		// static public method
	public:
		static Vanity::VComponentGameDataBase* const FactoryGameObjectCreate(
			const Envy::EMementoAssign& in_mementoAssign,
			Vanity::VScene& in_out_scene,
			const TItemId in_itemId
			);

		static Hubris::HVOID GameObjectCollect(
			Envy::EMementoCollect& in_out_mementoCollect,
			const GPlayerCharacter& in_gameObject
			);

		///////////////////////////////////////////////////////
		// implement VComponentGameDataBase
	private:
		/*
			phase 0 update animation (object movement)
			phase 1 update emit particle position and visusal
		*/
		virtual Hubris::HVOID Phase(
			Vanity::VScene& in_out_scene,
			const TItemId in_itemId,
			const Hubris::HSINT in_phaseIndex,
			Vanity::VSceneApplicationInterface& in_sceneApplicationInterface
			);

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private methods
	private:
		//update object animation (allow for object position change
		Hubris::HVOID PhaseZero(
			Vanity::VScene& in_out_scene,
			const TItemId in_itemId,
			Vanity::VSceneApplicationInterface& in_sceneApplicationInterface
			);

		//update position of each particle and the particle visuals
		Hubris::HVOID PhaseOne(
			Vanity::VScene& in_out_scene,
			const TItemId in_itemId,
			Vanity::VSceneApplicationInterface& in_sceneApplicationInterface
			);

		///////////////////////////////////////////////////////
		// static public acessors
	public:
		static const Hubris::HCHAR* FactoryNameGet();

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const GComponentTilt& ComponentTiltGet()const;
		GComponentTilt& ComponentTiltGet();

		///////////////////////////////////////////////////////
		// private acessors
	private:

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HBOOL m_playContolActive; //on tick, request input from application
		Hubris::HSINT m_inputIndex;
		//tilt component
		GComponentTilt* m_pComponentTilt;
		//visual component~ animation state machine plus
		//player input state machine


	};

	/**/
	
};

#endif // _G_PLAYER_CHARACTER_H_