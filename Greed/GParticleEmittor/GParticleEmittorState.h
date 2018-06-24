//file: Greed/GParticleEmittor/GParticleEmittorState.h
#ifndef _G_PARTICLE_EMITTOR_STATE_H_
#define _G_PARTICLE_EMITTOR_STATE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Envy
{
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >class EStateMachineSimple;
};

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GParticleEmittorStateDataExchange;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class GParticleEmittorState //use state machine? make memento difficult : public Envy::EStateMachineStateBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HSmartPointer< Vanity::VAnimationReference >TAnimationPointer;
		typedef Envy::EStateMachineSimple< GParticleEmittorState, GParticleEmittorStateDataExchange >TStateMachine;

		///////////////////////////////////////////////////////
		// creation
	public:
		GParticleEmittorState( const GParticleEmittorState& in_src );
		GParticleEmittorState();
		~GParticleEmittorState();

		///////////////////////////////////////////////////////
		// operator
	public:
		const GParticleEmittorState& operator=( const GParticleEmittorState& in_rhs );
		const Hubris::HBOOL operator==( const GParticleEmittorState& in_rhs )const;
		const Hubris::HBOOL operator!=( const GParticleEmittorState& in_rhs )const;

		///////////////////////////////////////////////////////
		// implement EStateMachineSimple contract~ friend the state machine or just make method public
	public:
		Hubris::HVOID SubmitEvent(
			GParticleEmittorStateDataExchange& in_out_dataExchange,
			TStateMachine& in_out_stateMachine,
			const Hubris::HString& in_stateName,
			const Hubris::HString& in_eventName
			);

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID OnEventTick(
			GParticleEmittorStateDataExchange& in_out_dataExchange
			);

		Hubris::HVOID OnEventEmit(
			GParticleEmittorStateDataExchange& in_out_dataExchange
			);

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const Hubris::HBOOL AnimationTest()const;
		//set if we have animation
		Hubris::HVOID AnimationSet( const Hubris::HBOOL in_hasAnimation );
		const Vanity::VAnimation& AnimationGet()const;
		Vanity::VAnimation& AnimationGet();

		const Hubris::HREAL DurationGet()const{ return m_duration; }
		Hubris::HVOID DurationSet( const Hubris::HREAL in_duration ){ m_duration = in_duration; return; }

		const TArraySint& ArrayTypeIndexGet()const{ return m_arrayTypeIndex; }
		TArraySint& ArrayTypeIndexGet(){ return m_arrayTypeIndex; }

		const TArrayString& ArrayNextStateGet()const{ return m_arrayNextState; }
		TArrayString& ArrayNextStateGet(){ return m_arrayNextState; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HREAL m_duration; //inf if duration is negative;
		TArraySint m_arrayTypeIndex;
		TArrayString m_arrayNextState; //on finishing this state, the array of states to activate next

		Hubris::HREAL m_currentTime;

		//animation data state data
		TAnimationPointer m_pAnimation;
	};

	/**/
	
};

#endif // _G_PARTICLE_EMITTOR_STATE_H_