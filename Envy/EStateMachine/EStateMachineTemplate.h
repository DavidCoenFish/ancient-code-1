//file: Envy/EStateMachine/EStateMachineTemplate.h
#ifndef _E_STATE_MACHINE_TEMPLATE_H_
#define _E_STATE_MACHINE_TEMPLATE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EStateMachineDataExchange;

	/////////////////////////////////////////////////////////////////
	// class
	/*
		generic state machine
		events can be submited to the active states
		states call activate/ deactivate events on themselves on activation/ deactivation
	*/
	template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE > class EStateMachineTemplate
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HSmartPointer< IN_STATE_BASE >TStateBasePointer;
		typedef Hubris::HContainerTree< Hubris::HString, TStateBasePointer >TTreeStringState;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStateMachineTemplate( const EStateMachineTemplate& in_src );
		EStateMachineTemplate();
		~EStateMachineTemplate();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EStateMachineTemplate& operator=( const EStateMachineTemplate& in_rhs );
		const Hubris::HBOOL operator==( const EStateMachineTemplate& in_rhs )const;
		const Hubris::HBOOL operator!=( const EStateMachineTemplate& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL StateTest( 
			const Hubris::HString& in_stateName
			);

		Hubris::HVOID StateAdd( 
			const Hubris::HString& in_stateName, 
			const IN_STATE_BASE& in_state 
			);

		Hubris::HVOID StateRemove( 
			const Hubris::HString& in_stateName
			);

		const Hubris::HBOOL StateActiveGet( 
			const Hubris::HString& in_stateName 
			)const;


		const Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		const Hubris::HVOID StateActiveNameGather( TArrayString& out_arrayStateActiveName )const;

		Hubris::HVOID StateActiveSet( 
			const Hubris::HString& in_stateName, 
			const Hubris::HBOOL in_active, 
			EStateMachineDataExchange& in_dataExchange,
			IN_STATE_MACHINE_INTERFACE& in_stateMachine
			);

		Hubris::HVOID StateDeactiveAll( 
			EStateMachineDataExchange& in_dataExchange,
			IN_STATE_MACHINE_INTERFACE& in_stateMachine
			);

		Hubris::HVOID SubmitEvent( 
			const Hubris::HString& in_eventName, 
			EStateMachineDataExchange& in_dataExchange, 
			IN_STATE_MACHINE_INTERFACE& in_stateMachine
			);

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		TTreeStringState m_treeStateNameState;
		TTreeStringState m_treeActiveStateNameState;

	};

	/**/
};

#endif // _E_STATE_MACHINE_TEMPLATE_H_
