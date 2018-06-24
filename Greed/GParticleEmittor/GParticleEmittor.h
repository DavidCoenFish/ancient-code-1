//file: Greed/GParticleEmittor/GParticleEmittor.h
#ifndef _G_PARTICLE_EMITTOR_H_
#define _G_PARTICLE_EMITTOR_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Vanity/VComponentGame/VComponentGame_Export.h >
#include< Envy/EResourceIdManager/EResourceIdManager_Export.h >
#include< Envy/EStateMachineSimple/EStateMachineSimple_Export.h >
#include "Greed/GParticleEmittor/GParticleEmittorStateDataExchange.h"
#include "Greed/GParticleEmittor/GParticleEmittorState.h"
#include "Greed/GParticleEmittor/GParticleEmittorType.h"
#include "Greed/GParticleEmittor/GParticleEmittorData.h"

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GComponentTranslation;
	class GComponentRotation;
	class GComponentAnimation;

	///////////////////////////////////////////////////////
	// class
	/*
		rem to register factory with Greed::GUtility::RegisterGameObjectFactory
	*/
	class GParticleEmittor : public Vanity::VComponentGameDataBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerPair< Pride::PUnitVectorR3, Hubris::HREAL >TPairUnitVectorReal;
		typedef Hubris::HContainerArray< TPairUnitVectorReal >TArrayPairUnitVectorReal;

		typedef Hubris::HContainerArray< GParticleEmittorType >TArrayType;
		typedef Hubris::HContainerArray< GParticleEmittorData >TArrayData;

		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		typedef Envy::EStateMachineSimple< GParticleEmittorState, GParticleEmittorStateDataExchange >TStateMachine;

		///////////////////////////////////////////////////////
		// creation
	public:
		GParticleEmittor();
		virtual ~GParticleEmittor();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GParticleEmittor( const GParticleEmittor& in_src );
		const GParticleEmittor& operator=( const GParticleEmittor& in_rhs );

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
			const GParticleEmittor& in_gameObject
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
		//interface for GComponentAnimationVisitor
		Hubris::HVOID AnimationValueSet(
			Vanity::VScene& in_out_scene,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_animatedValue
			);
		Hubris::HVOID AnimationValueSet(
			Vanity::VScene& in_out_scene,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HREAL in_animatedValue
			);
		Hubris::HVOID AnimationValueSet(
			Vanity::VScene& in_out_scene,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR2& in_animatedValue
			);
		Hubris::HVOID AnimationValueSet(
			Vanity::VScene& in_out_scene,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR3& in_animatedValue
			);
		Hubris::HVOID AnimationValueSet(
			Vanity::VScene& in_out_scene,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR4& in_animatedValue
			);

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

		static const Hubris::HCHAR* StateSubmitEventNameGetTick();
		static const Hubris::HCHAR* StateSubmitEventNameGetEmit();
		//static const Hubris::HCHAR* StateSubmitEventNameGetTick();

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const TStateMachine& StateMachineGet()const{ return m_stateMachine; }
		TStateMachine& StateMachineGet(){ return m_stateMachine; }

		const TArrayString& ArrayPendingStateNameGet()const{ return m_arrayPendingStateName; }
		TArrayString& ArrayPendingStateNameGet(){ return m_arrayPendingStateName; }

		const TArrayPairUnitVectorReal& EmittorShapeGet()const{ return m_emittorShape; }
		TArrayPairUnitVectorReal& EmittorShapeGet(){ return m_emittorShape; }

		const TArrayType& ArrayTypeGet()const{ return m_arrayType; }
		TArrayType& ArrayTypeGet(){ return m_arrayType; }

		const TArrayData& ArrayDataGet()const{ return m_arrayData; }
		TArrayData& ArrayDataGet(){ return m_arrayData; }

		const Envy::EResourceIdManager& ActiveDataGet()const{ return m_activeData; }
		Envy::EResourceIdManager& ActiveDataGet(){ return m_activeData; }

		const Hubris::HSINT MaximumParticleCountGet()const;
		Hubris::HVOID MaximumParticleCountSet( const Hubris::HSINT in_maximumParticleCount );

		///////////////////////////////////////////////////////
		// private members
	private:
		TStateMachine m_stateMachine;
		TArrayString m_arrayPendingStateName; //on construction of game object, the array of states to activate

		TArrayPairUnitVectorReal m_emittorShape;

		TArrayType m_arrayType;

		//m_arrayData.SizeGet() is maximum particle count (not all may be active)
		TArrayData m_arrayData;
		Envy::EResourceIdManager m_activeData;

		// moved to be part of m_pComponentAnimation children
		//GComponentTranslation* m_pComponentTranslation;
		//GComponentRotation* m_pComponentRotation;

		GComponentAnimation* m_pComponentAnimation;

	};

	/**/
	
};

#endif // _G_PARTICLE_EMITTOR_H_