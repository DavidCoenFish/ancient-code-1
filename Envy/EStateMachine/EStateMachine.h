//file: Envy/EStateMachine/EStateMachine.h
#ifndef _E_STATE_MACHINE_H_
#define _E_STATE_MACHINE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	class HString;
	template< typename IN_TYPE >class HContainerArray;
};

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE > class EStateMachineTemplate;
	class EStateMachineStateBase;
	class EStateMachineDataExchange;

	/////////////////////////////////////////////////////////////////
	// class
	/*
		basic state machines, activate and deactivate states
		'submit events' are sent to the active events
	*/
	class EStateMachine
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef EStateMachineTemplate< EStateMachineStateBase, EStateMachine >TStateMachine;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStateMachine( const EStateMachine& in_stateMachine );
		EStateMachine();
		~EStateMachine();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EStateMachine& operator=( const EStateMachine& in_rhs );
		const Hubris::HBOOL operator==( const EStateMachine& in_rhs )const;
		const Hubris::HBOOL operator!=( const EStateMachine& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		//return true if there is a state of given name in state machine
		const Hubris::HBOOL StateTest( 
			const Hubris::HString& in_stateName
			);

		//assert on duplicate name
		Hubris::HVOID StateAdd( 
			const Hubris::HString& in_stateName, 
			const EStateMachineStateBase& in_state 
			);

		//ASSERT on state not found, WARNING, state is not deactivated if it is active
		Hubris::HVOID StateRemove( 
			const Hubris::HString& in_stateName
			);

		//set state active or not, NOP on state already being active/ deactive, ASSERT on state not found
		Hubris::HVOID StateActiveSet( 
			const Hubris::HString& in_stateName, 
			const Hubris::HBOOL in_active, 
			EStateMachineDataExchange& in_dataExchange 
			);

		//return true if named state is active, ASSERT on state not found
		const Hubris::HBOOL StateActiveGet( 
			const Hubris::HString& in_stateName 
			)const;

		//deactivate all active states
		Hubris::HVOID StateDeactiveAll( 
			EStateMachineDataExchange& in_dataExchange 
			);

		//submit event to all active states
		Hubris::HVOID SubmitEvent( 
			const Hubris::HString& in_eventName, 
			EStateMachineDataExchange& in_dataExchange
			);

		//gather the array of state names
		const Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		//gather then array of active state names
		const Hubris::HVOID StateActiveNameGather( TArrayString& out_arrayStateActiveName )const;

		//return HNULL if not found
		// try to make it so client doesn't NEED to look at states
		// or do it by 'submit event'...
		//const EStateMachineStateBase* const StateGet( const Hubris::HString& in_name )const;
		//EStateMachineStateBase* const StateGet( const Hubris::HString& in_name );

		/////////////////////////////////////////////////////////////////
		// public static accessors
	public:
		static const Hubris::HCHAR* const EventNameActivateGet();
		static const Hubris::HCHAR* const EventNameDeactivateGet();

		/////////////////////////////////////////////////////////////////
		// private accessors
	private:
		const TStateMachine& ImplementationGet()const;
		TStateMachine& ImplementationGet();

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		TStateMachine* m_pImplementation;

	};

	/**/
};

#endif // _E_STATE_MACHINE_H_
