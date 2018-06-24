//file: Envy/EStateMachine/EStateMachine.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStateMachine/EStateMachine.h"
#include "Envy/EStateMachine/EStateMachineTemplate.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// local var
/**/
static const HCHAR* const s_eventNameActivate = "ON_ACTIVATE";
static const HCHAR* const s_eventNameDeactivate = "ON_DEACTIVATE";

/////////////////////////////////////////////////////////////////
// creation
Envy::EStateMachine::EStateMachine( const EStateMachine& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, TStateMachine, in_src.ImplementationGet() );
	return;
}

/**/
Envy::EStateMachine::EStateMachine() 
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, TStateMachine );

	return;
}

/**/
Envy::EStateMachine::~EStateMachine()
{
	HCOMMON_DELETE( m_pImplementation, EStateMachineImplementation );

	return;
}

/////////////////////////////////////////////////////////////////
// operators
/**/
const EStateMachine& Envy::EStateMachine::operator=( const EStateMachine& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();

	return( *this );
}

/**/
const HBOOL Envy::EStateMachine::operator==( const EStateMachine& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
const HBOOL Envy::EStateMachine::operator!=( const EStateMachine& in_rhs )const
{
	return( !operator==( in_rhs ) );
}

/////////////////////////////////////////////////////////////////
// public methods
const Hubris::HBOOL Envy::EStateMachine::StateTest( 
	const Hubris::HString& in_stateName
	)
{
	return ImplementationGet().StateTest(
		in_stateName
		);
}

/**/
Hubris::HVOID Envy::EStateMachine::StateAdd( 
	const Hubris::HString& in_stateName, 
	const EStateMachineStateBase& in_state 
	)
{
	ImplementationGet().StateAdd(
		in_stateName,
		in_state
		);

	return;
}

/**/
Hubris::HVOID Envy::EStateMachine::StateRemove( 
	const Hubris::HString& in_stateName
	)
{
	ImplementationGet().StateRemove(
		in_stateName
		);

	return;
}

/**/
Hubris::HVOID Envy::EStateMachine::StateActiveSet( 
	const Hubris::HString& in_stateName, 
	const Hubris::HBOOL in_active, 
	EStateMachineDataExchange& in_dataExchange 
	)
{
	ImplementationGet().StateActiveSet(
		in_stateName,
		in_active,
		in_dataExchange,
		( *this )
		);

	return;
}

/**/
const Hubris::HBOOL Envy::EStateMachine::StateActiveGet( 
	const Hubris::HString& in_stateName 
	)const
{
	return ImplementationGet().StateActiveGet(
		in_stateName
		);
}

/**/
Hubris::HVOID Envy::EStateMachine::StateDeactiveAll( 
	EStateMachineDataExchange& in_dataExchange 
	)
{
	ImplementationGet().StateDeactiveAll(
		in_dataExchange,
		( *this )
		);

	return;
}

/**/
Hubris::HVOID Envy::EStateMachine::SubmitEvent( 
	const Hubris::HString& in_eventName, 
	EStateMachineDataExchange& in_dataExchange 
	)
{
	ImplementationGet().SubmitEvent(
		in_eventName, 
		in_dataExchange,
		*this 
		);

	return;
}

/**/
const Hubris::HVOID Envy::EStateMachine::StateNameGather( TArrayString& out_arrayStateName )const
{
	ImplementationGet().StateNameGather(
		out_arrayStateName
		);

	return;
}

/**/
const Hubris::HVOID Envy::EStateMachine::StateActiveNameGather( TArrayString& out_arrayStateActiveName )const
{
	ImplementationGet().StateActiveNameGather(
		out_arrayStateActiveName
		);

	return;
}

/////////////////////////////////////////////////////////////////
// public static accessors
/**/
const Hubris::HCHAR* const Envy::EStateMachine::EventNameActivateGet()
{
	return s_eventNameActivate;
}

/**/
const Hubris::HCHAR* const Envy::EStateMachine::EventNameDeactivateGet()
{
	return s_eventNameDeactivate;
}

/////////////////////////////////////////////////////////////////
// private accessor
/**/
const Envy::EStateMachine::TStateMachine& Envy::EStateMachine::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
Envy::EStateMachine::TStateMachine& Envy::EStateMachine::ImplementationGet()
{	
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
