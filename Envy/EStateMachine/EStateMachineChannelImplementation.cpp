//file: Envy/EStateMachine/EStateMachineChannelImplementation.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStateMachine/EStateMachineChannelImplementation.h"

#include "Envy/EStateMachine/EStateMachineChannel.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// typedefs
/**/

/////////////////////////////////////////////////////////////////
// static local methods

/////////////////////////////////////////////////////////////////
// creation
/**/
Envy::EStateMachineChannelImplementation::EStateMachineChannelImplementation( const EStateMachineChannelImplementation& in_src )
: m_stateMachine()
, m_treeChannelNameStateNameStack()
{
	( *this ) = in_src;
	return;
}

/**/
Envy::EStateMachineChannelImplementation::EStateMachineChannelImplementation()
: m_stateMachine()
, m_treeChannelNameStateNameStack()
{
	return;
}

/**/
Envy::EStateMachineChannelImplementation::~EStateMachineChannelImplementation()
{
	return;
}

/////////////////////////////////////////////////////////////////
// operators
/**/
const EStateMachineChannelImplementation& Envy::EStateMachineChannelImplementation::operator=( const EStateMachineChannelImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_stateMachine = in_rhs.m_stateMachine;
		m_treeChannelNameStateNameStack = in_rhs.m_treeChannelNameStateNameStack;
	}

	return( *this );
}

/**/
const Hubris::HBOOL Envy::EStateMachineChannelImplementation::operator==( const EStateMachineChannelImplementation& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_treeChannelNameStateNameStack == in_rhs.m_treeChannelNameStateNameStack );
		match &= ( m_stateMachine == in_rhs.m_stateMachine );
	}

	return match;
}

/**/
const Hubris::HBOOL Envy::EStateMachineChannelImplementation::operator!=( const EStateMachineChannelImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL Envy::EStateMachineChannelImplementation::StateTest( 
	const Hubris::HString& in_stateName
	)
{
	return( m_stateMachine.StateTest( in_stateName ) );
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::StateAdd( 
	const Hubris::HString& in_stateName, 
	const EStateMachineStateChannelBase& in_state
	)
{
	m_stateMachine.StateAdd( 
		in_stateName,
		in_state 
		);

	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::StateRemove( 
	const Hubris::HString& in_stateName
	)
{
	m_stateMachine.StateRemove( 
		in_stateName
		);

	return;
}

/**/
const Hubris::HBOOL Envy::EStateMachineChannelImplementation::ChannelTest( 
	const Hubris::HString& in_channelName
	)
{
	return( m_treeChannelNameStateNameStack.Find( in_channelName ) != m_treeChannelNameStateNameStack.End() );
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::ChannelAdd( 
	const Hubris::HString& in_channelName 
	)
{
	HCOMMON_ASSERT( HFALSE == ChannelTest( in_channelName ), "duplicate channel names" );
	m_treeChannelNameStateNameStack.Insert( in_channelName, TArrayString() );
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::ChannelRemove( 
	const Hubris::HString& in_channelName
	)
{
	TTreeStringArrayString::TIterator channelIterator = m_treeChannelNameStateNameStack.Find( in_channelName );
	if( channelIterator == m_treeChannelNameStateNameStack.End() )
	{
		return;
	}

	const TArrayString& stateStack = ( *channelIterator );
	HCOMMON_ASSERT( 0 == stateStack.SizeGet(), "deactivation of channel with active states" );
	m_treeChannelNameStateNameStack.Remove( channelIterator );

	return;
}
/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::ChannelStateActivePush( 
	const Hubris::HString& in_stateName, 
	const Hubris::HString& in_channelName, 
	EStateMachineDataExchange& in_dataExchange,
	EStateMachineChannel& in_stateMachine
	)
{
	TTreeStringArrayString::TIterator channelIterator = m_treeChannelNameStateNameStack.Find( in_channelName );
	if( channelIterator == m_treeChannelNameStateNameStack.End() )
	{
		HCOMMON_ASSERT_ALWAYS( "channel not found" );
		return;
	}
	if( HFALSE == m_stateMachine.StateTest( in_stateName ) )
	{
		HCOMMON_ASSERT_ALWAYS( "state not found" );
		return;
	}

	TArrayString& stateStack = ( *channelIterator );
	if( 0 < stateStack.SizeGet() )
	{
		m_stateMachine.StateActiveSet(
			HContainerUtility::Back( stateStack ),
			HFALSE,
			in_dataExchange,
			in_stateMachine
			);
	}

	HContainerUtility::PushBack( stateStack, in_stateName ), 

	m_stateMachine.StateActiveSet(
		in_stateName,
		HTRUE,
		in_dataExchange,
		in_stateMachine
		);

	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::ChannelStateActivePop( 
	const Hubris::HString& in_channelName, 
	EStateMachineDataExchange& in_dataExchange,
	EStateMachineChannel& in_stateMachine
	)
{
	TTreeStringArrayString::TIterator channelIterator = m_treeChannelNameStateNameStack.Find( in_channelName );
	if( channelIterator == m_treeChannelNameStateNameStack.End() )
	{
		HCOMMON_ASSERT_ALWAYS( "channel not found" );
		return;
	}

	TArrayString& stateStack = ( *channelIterator );
	if( 0 < stateStack.SizeGet() )
	{
		m_stateMachine.StateActiveSet(
			HContainerUtility::Back( stateStack ),
			HFALSE, 
			in_dataExchange,
			in_stateMachine
			);
	}

	HContainerUtility::PopBack( stateStack );

	if( 0 < stateStack.SizeGet() )
	{
		m_stateMachine.StateActiveSet(
			HContainerUtility::Back( stateStack ),
			HTRUE, 
			in_dataExchange,
			in_stateMachine
			);
	}

	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::ChannelStateActiveClear( 
	const Hubris::HString& in_channelName, 
	EStateMachineDataExchange& in_dataExchange,
	EStateMachineChannel& in_stateMachine
	)
{
	TTreeStringArrayString::TIterator channelIterator = m_treeChannelNameStateNameStack.Find( in_channelName );
	if( channelIterator == m_treeChannelNameStateNameStack.End() )
	{
		HCOMMON_ASSERT_ALWAYS( "channel not found" );
		return;
	}

	TArrayString& stateStack = ( *channelIterator );
	if( 0 < stateStack.SizeGet() )
	{
		m_stateMachine.StateActiveSet(
			HContainerUtility::Back( stateStack ),
			HFALSE, 
			in_dataExchange,
			in_stateMachine
			);
	}

	stateStack.Clear();

	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::SubmitEvent( 
	const Hubris::HString& in_eventName, 
	EStateMachineDataExchange& in_dataExchange,
	EStateMachineChannel& in_stateMachine
	)
{
	m_stateMachine.SubmitEvent(
		in_eventName,
		in_dataExchange,
		in_stateMachine
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::StateNameGather( TArrayString& out_arrayStateName )const
{
	m_stateMachine.StateNameGather(
		out_arrayStateName
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::ChannelNameGather( TArrayString& out_arrayChannelName )const
{
	for( const TTreeStringArrayString::TIterator iterator = m_treeChannelNameStateNameStack.Begin(); iterator != m_treeChannelNameStateNameStack.End(); ++iterator )
	{
		HContainerUtility::PushBack( out_arrayChannelName, iterator.KeyGet() );
	}
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannelImplementation::ChannelStateStackGather( 
	TArrayString& out_arrayChannelStateNameStack, 
	const Hubris::HString& in_channelName, 
	const Hubris::HSINT in_maxStateReturnCount 
	)const
{
	out_arrayChannelStateNameStack.Clear();
	TTreeStringArrayString::TIterator channelIterator = m_treeChannelNameStateNameStack.Find( in_channelName );
	if( channelIterator == m_treeChannelNameStateNameStack.End() )
	{
		HCOMMON_ASSERT_ALWAYS( "channel not found" );
		return;
	}

	TArrayString& stateStack = ( *channelIterator );
	for( HSINT index = 0; index < stateStack.SizeGet(); ++index )
	{
		if( in_maxStateReturnCount <= index )
		{
			break;
		}

		HContainerUtility::PushBack( out_arrayChannelStateNameStack, stateStack[ stateStack.SizeGet() - ( index + 1 ) ] );
	}

	return;
}

/**/