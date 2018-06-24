//file: Envy/EStateMachine/EStateMachineStateBase.h
#ifndef _E_STATE_MACHINE_STATE_BASE_H_
#define _E_STATE_MACHINE_STATE_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HTypeRunTimeInfo.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	class EStateMachineDataExchange;
	class EStateMachine;

	/////////////////////////////////////////////////////////////////
	// class
	/*
		state base, define state interface 
	*/
	class EStateMachineStateBase : public Hubris::HSmartPointerObjectBase< EStateMachineStateBase >
	{
		/////////////////////////////////////////////////////////////////
		// RTTI
	public:
		HTYPE_RUN_TIME_TYPE_INFO_BASE( EStateMachineStateBase );

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStateMachineStateBase();
		virtual ~EStateMachineStateBase();

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DeleteThis();

		//make a clone of this object
		EStateMachineStateBase* const Clone()const;
		//return true if the input is equivalent
		const Hubris::HBOOL Compair( const EStateMachineStateBase& in_rhs )const;

		//contract with state machine to respond to events
		Hubris::HVOID SubmitEvent( 
			EStateMachineDataExchange& in_out_dataExchange, 
			EStateMachine& in_out_stateEngine,
			const Hubris::HString& in_stateName, 
			const Hubris::HString& in_eventName
			);
		//contract with state machine to respond to events
		//Hubris::HVOID SubmitEvent( 
		//	const Hubris::HString& in_eventName, 
		//	EStateMachine& in_stateEngine
		//	);

		/////////////////////////////////////////////////////////////////
		// define interface
	private:
		virtual Envy::EStateMachineStateBase* const OnClone()const=0;
		virtual const Hubris::HBOOL OnCompair( const EStateMachineStateBase& in_rhs )const=0;
		virtual Hubris::HVOID OnSubmitEvent( 
			EStateMachineDataExchange& in_out_dataExchange, 
			EStateMachine& in_out_stateEngine,
			const Hubris::HString& in_stateName, 
			const Hubris::HString& in_eventName
			)=0;
		//virtual Hubris::HVOID OnSubmitEvent( 
		//	const Hubris::HString& in_eventName, 
		//	EStateMachine& in_stateEngine
		//	)=0;

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		const EStateMachineStateBase& operator=( const EStateMachineStateBase& in_rhs );
		EStateMachineStateBase( const EStateMachineStateBase& in_src );

	};

	/**/
};

#endif // _E_STATE_MACHINE_STATE_BASE_H_