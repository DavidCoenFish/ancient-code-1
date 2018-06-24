//file: Envy/EStateMachine/EStateMachineTemplate.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStateMachine/EStateMachineTemplate.h"

#include "Envy/EStateMachine/EStateMachine.h"
#include "Envy/EStateMachine/EStateMachineChannel.h"
#include "Envy/EStateMachine/EStateMachineStateBase.h"
#include "Envy/EStateMachine/EStateMachineStateChannelBase.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// typedefs
/**/

/////////////////////////////////////////////////////////////////
// local free functions

////////////////////////////////////////////////////
// template definitions
/**/
template class Envy::EStateMachineTemplate< EStateMachineStateBase, EStateMachine >;
template class Envy::EStateMachineTemplate< EStateMachineStateChannelBase, EStateMachineChannel >;

/////////////////////////////////////////////////////////////////
// creation
/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::EStateMachineTemplate( const EStateMachineTemplate& in_src )
: m_treeStateNameState()
, m_treeActiveStateNameState()
{
	( *this ) = in_src;

	return;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::EStateMachineTemplate() 
: m_treeStateNameState()
, m_treeActiveStateNameState()
{
	return;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::~EStateMachineTemplate()
{
	return;
}

/////////////////////////////////////////////////////////////////
// operators
/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
const EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >& Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::operator=( const EStateMachineTemplate& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_treeStateNameState.Clear();
		m_treeActiveStateNameState.Clear();

		for( TTreeStringState::TIterator iterator = in_rhs.m_treeStateNameState.Begin(); iterator != in_rhs.m_treeStateNameState.End(); ++iterator )
		{
			const HString& stateName = iterator.KeyGet();
			TStateBasePointer state = ( *iterator )->Clone();

			m_treeStateNameState.Insert( stateName, state );

			if( in_rhs.m_treeActiveStateNameState.Find( stateName ) != in_rhs.m_treeActiveStateNameState.End() )
			{
				m_treeActiveStateNameState.Insert( stateName, state );
			}
		}
	}

	return( *this );
}

/*
	detect if data values are the same
*/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
const Hubris::HBOOL Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::operator==( const EStateMachineTemplate& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_treeStateNameState.SizeGet() == in_rhs.m_treeStateNameState.SizeGet() );
		match &= ( m_treeActiveStateNameState.SizeGet() == in_rhs.m_treeActiveStateNameState.SizeGet() );

		//are the same states active
		if( HTRUE == match )
		{
			TTreeStringState::TIterator rhsIterator = in_rhs.m_treeActiveStateNameState.Begin();
			for( TTreeStringState::TIterator lhsIterator = m_treeActiveStateNameState.Begin(); lhsIterator != m_treeActiveStateNameState.End(); ++lhsIterator, ++rhsIterator )
			{
				match &= ( lhsIterator.KeyGet() == rhsIterator.KeyGet() );
				if( HFALSE == match )
				{
					break;
				}
			}
		}

		//are the states the same
		if( HTRUE == match )
		{
			TTreeStringState::TIterator rhsIterator = in_rhs.m_treeStateNameState.Begin();
			for( TTreeStringState::TIterator lhsIterator = m_treeStateNameState.Begin(); lhsIterator != m_treeStateNameState.End(); ++lhsIterator, ++rhsIterator )
			{
				match &= ( lhsIterator.KeyGet() == rhsIterator.KeyGet() );
				match &= ( ( *lhsIterator )->Compair( *( *rhsIterator ) ) );
				if( HFALSE == match )
				{
					break;
				}
			}
		}

	}

	return match;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
const Hubris::HBOOL Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::operator!=( const EStateMachineTemplate& in_rhs )const
{
	return( !operator==( in_rhs ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
const Hubris::HBOOL Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateTest( 
	const Hubris::HString& in_stateName
	)
{
	return( m_treeStateNameState.Find( in_stateName ) != m_treeStateNameState.End() );
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Hubris::HVOID Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateAdd( 
	const Hubris::HString& in_stateName, 
	const IN_STATE_BASE& in_state  
	)
{
	HCOMMON_ASSERT( HFALSE == StateTest( in_stateName ), "duplicate state names" );

	m_treeStateNameState.Insert( in_stateName, in_state.Clone() );

	return;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Hubris::HVOID Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateRemove( 
	const Hubris::HString& in_stateName
	)
{
	HCOMMON_ASSERT( m_treeActiveStateNameState.Find( in_stateName ) == m_treeActiveStateNameState.End(), "removal of active state" );

	TTreeStringState::TIterator iterator = m_treeStateNameState.Find( in_stateName );
	HCOMMON_ASSERT( iterator != m_treeStateNameState.End(), "state not found" );

	m_treeStateNameState.Remove( iterator );

	return;
}


/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
const Hubris::HBOOL Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateActiveGet( 
	const Hubris::HString& in_stateName 
	)const
{
	return( m_treeActiveStateNameState.Find( in_stateName ) != m_treeActiveStateNameState.End() );
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Hubris::HVOID Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateDeactiveAll( 
	EStateMachineDataExchange& in_dataExchange,
	IN_STATE_MACHINE_INTERFACE& in_stateMachine
	)
{
	while( 0 < m_treeActiveStateNameState.SizeGet() )
	{
		TTreeStringState::TIterator iterator = m_treeActiveStateNameState.Begin();
		const HString stateName = iterator.KeyGet();
		TStateBasePointer state = ( *iterator );
		m_treeActiveStateNameState.Remove( iterator );

		state->SubmitEvent(
			in_dataExchange,
			in_stateMachine,
			stateName, 
			Envy::EStateMachine::EventNameDeactivateGet()
			);
	}

	return;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
const Hubris::HVOID Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateNameGather( TArrayString& out_arrayStateName )const
{
	for( const TTreeStringState::TIterator iterator = m_treeStateNameState.Begin(); iterator != m_treeStateNameState.End(); ++iterator )
	{
		HContainerUtility::PushBack( out_arrayStateName, iterator.KeyGet() );
	}
	return;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
const Hubris::HVOID Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateActiveNameGather( TArrayString& out_arrayStateActiveName )const
{
	for( const TTreeStringState::TIterator iterator = m_treeActiveStateNameState.Begin(); iterator != m_treeActiveStateNameState.End(); ++iterator )
	{
		HContainerUtility::PushBack( out_arrayStateActiveName, iterator.KeyGet() );
	}
	return;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Hubris::HVOID Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::StateActiveSet( 
	const Hubris::HString& in_stateName, 
	const Hubris::HBOOL in_active, 
	EStateMachineDataExchange& in_dataExchange,
	IN_STATE_MACHINE_INTERFACE& in_stateMachine
	)
{
	//test if already active/ deactive ( NOP )
	TTreeStringState::TIterator activeIterator = m_treeActiveStateNameState.Find( in_stateName );
	if( ( HTRUE == in_active ) &&
		( activeIterator != m_treeActiveStateNameState.End() ) )
	{
		return;
	}
	else if( ( HTRUE == in_active ) &&
		( activeIterator != m_treeActiveStateNameState.End() ) )
	{
		return;
	}

	//Activate/ deactivate the state
	TTreeStringState::TIterator iterator = m_treeStateNameState.Find( in_stateName );
	HCOMMON_ASSERT( iterator != m_treeStateNameState.End(), "state not found" );

	//put state on active tree
	if( HTRUE == in_active )
	{
		m_treeActiveStateNameState.Insert( in_stateName, ( *iterator ) );
	}
	else
	{
		HCOMMON_ASSERT( activeIterator != m_treeActiveStateNameState.End(), "deactivating state not found on active state list" );
		m_treeActiveStateNameState.Remove( activeIterator );
	}

	//submit event
	if( HTRUE == in_active )
	{
		( *iterator )->SubmitEvent(
			in_dataExchange,
			in_stateMachine,
			in_stateName,
			Envy::EStateMachine::EventNameActivateGet()
			);
	}
	else
	{
		( *iterator )->SubmitEvent(
			in_dataExchange,
			in_stateMachine,
			in_stateName,
			Envy::EStateMachine::EventNameDeactivateGet()
			);
	}

	return;
}

/**/
template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE >
Hubris::HVOID Envy::EStateMachineTemplate< IN_STATE_BASE, IN_STATE_MACHINE_INTERFACE >::SubmitEvent( 
	const Hubris::HString& in_eventName, 
	EStateMachineDataExchange& in_dataExchange, 
	IN_STATE_MACHINE_INTERFACE& in_stateMachine
	)
{
	TTreeStringState localActiveState( m_treeActiveStateNameState );
	for( TTreeStringState::TIterator iterator = localActiveState.Begin(); iterator != localActiveState.End(); ++iterator )
	{
		( *iterator )->SubmitEvent(
			in_dataExchange,
			in_stateMachine,
			iterator.KeyGet(),
			in_eventName
			);
	}

	return;
}

/**/
