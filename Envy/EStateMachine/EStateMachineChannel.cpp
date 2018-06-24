//file: Envy/EStateMachine/EStateMachineChannel.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStateMachine/EStateMachineChannel.h"

#include "Envy/EStateMachine/EStateMachine.h"
#include "Envy/EStateMachine/EStateMachineChannelImplementation.h"

/**/
using namespace Envy;
using namespace Hubris;

/////////////////////////////////////////////////////////////////
// local var
/**/
static const HCHAR* const s_channelDefaultName( "DEFAULT" );

/////////////////////////////////////////////////////////////////
// creation
Envy::EStateMachineChannel::EStateMachineChannel( const EStateMachineChannel& in_src ) 
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, EStateMachineChannelImplementation, in_src.ImplementationGet() );
	return;
}

/**/
Envy::EStateMachineChannel::EStateMachineChannel()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, EStateMachineChannelImplementation );
	return;
}

/**/
Envy::EStateMachineChannel::~EStateMachineChannel()
{
	HCOMMON_DELETE( m_pImplementation, EStateMachineChannelImplementation );
	return;
}

/////////////////////////////////////////////////////////////////
// operators
/**/
const EStateMachineChannel& Envy::EStateMachineChannel::operator=( const EStateMachineChannel& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
const Hubris::HBOOL Envy::EStateMachineChannel::operator==( const EStateMachineChannel& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
const Hubris::HBOOL Envy::EStateMachineChannel::operator!=( const EStateMachineChannel& in_rhs )const
{
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL Envy::EStateMachineChannel::StateTest( 
	const Hubris::HString& in_stateName
	)
{
	return ImplementationGet().StateTest(
		in_stateName 
		);
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::StateAdd( 
	const Hubris::HString& in_stateName, 
	const EStateMachineStateChannelBase& in_state 
	)
{
	ImplementationGet().StateAdd(
		in_stateName,
		in_state
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::StateRemove( 
	const Hubris::HString& in_stateName
	)
{
	ImplementationGet().StateRemove(
		in_stateName 
		);
	return;
}

/**/
const Hubris::HBOOL Envy::EStateMachineChannel::ChannelTest( 
	const Hubris::HString& in_channelName
	)
{
	const HBOOL result = ImplementationGet().ChannelTest(
		in_channelName 
		);
	return result;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::ChannelAdd( 
	const Hubris::HString& in_channelName 
	)
{
	ImplementationGet().ChannelAdd(
		in_channelName 
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::ChannelRemove( 
	const Hubris::HString& in_channelName
	)
{
	ImplementationGet().ChannelRemove(
		in_channelName 
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::ChannelStateActivePush( 
	const Hubris::HString& in_stateName, 
	const Hubris::HString& in_channelName, 
	EStateMachineDataExchange& in_dataExchange 
	)
{
	ImplementationGet().ChannelStateActivePush(
		in_stateName,
		in_channelName,
		in_dataExchange,
		( *this )
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::ChannelStateActivePop( 
	const Hubris::HString& in_channelName, 
	EStateMachineDataExchange& in_dataExchange 
	)
{
	ImplementationGet().ChannelStateActivePop(
		in_channelName,
		in_dataExchange,
		( *this )
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::ChannelStateActiveClear( 
	const Hubris::HString& in_channelName, 
	EStateMachineDataExchange& in_dataExchange 
	)
{
	ImplementationGet().ChannelStateActiveClear(
		in_channelName,
		in_dataExchange,
		( *this )
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::SubmitEvent( 
	const Hubris::HString& in_eventName, 
	EStateMachineDataExchange& in_dataExchange 
	)
{
	ImplementationGet().SubmitEvent(
		in_eventName,
		in_dataExchange,
		( *this )
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::StateNameGather( TArrayString& out_arrayStateName )const
{
	ImplementationGet().StateNameGather(
		out_arrayStateName 
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::ChannelNameGather( TArrayString& out_arrayChannelName )const
{
	ImplementationGet().ChannelNameGather(
		out_arrayChannelName 
		);
	return;
}

/**/
Hubris::HVOID Envy::EStateMachineChannel::ChannelStateStackGather(
	TArrayString& out_arrayChannelStateNameStack, 
	const Hubris::HString& in_channelName, 
	const Hubris::HSINT in_maxStateReturnCount	
	)const
{
	ImplementationGet().ChannelStateStackGather(
		out_arrayChannelStateNameStack,
		in_channelName,
		in_maxStateReturnCount
		);
	return;
}

/////////////////////////////////////////////////////////////////
// public static accessor
const Hubris::HCHAR* const Envy::EStateMachineChannel::ChannelDefaultNameGet()
{
	return s_channelDefaultName;
}

/**/
const Hubris::HCHAR* const Envy::EStateMachineChannel::EventNameActivateGet()
{
	return EStateMachine::EventNameActivateGet();
}

/**/
const Hubris::HCHAR* const Envy::EStateMachineChannel::EventNameDeactivateGet()
{
	return EStateMachine::EventNameDeactivateGet();
}

/////////////////////////////////////////////////////////////////
// private accessors
/**/
const EStateMachineChannelImplementation& Envy::EStateMachineChannel::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
EStateMachineChannelImplementation& Envy::EStateMachineChannel::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/