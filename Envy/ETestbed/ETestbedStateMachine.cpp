//file: Envy/ETestbed/ETestbedStateMachine.cpp

#include "Envy/ETestbed/ETestbedStateMachine.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Envy;
using namespace Hubris;

//////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HString >TArrayString;

//////////////////////////////////////////////////
// local class
/**/
class TTextbedState : public EStateMachineStateBase
{
public:
	TTextbedState(
		HSINT& in_activateCount,
		HSINT& in_deactivateCount,
		HSINT& in_otherCount
		)
	: m_activateCount( in_activateCount )
	, m_deactivateCount( in_deactivateCount )
	, m_otherCount( in_otherCount )
	{
		return;
	}
	virtual ~TTextbedState()
	{
		return;
	}
	/////////////////////////////////////////////////////////////////
	// define interface
private:
	virtual Envy::EStateMachineStateBase* const OnClone()const
	{
		TTextbedState* pState;
		HCOMMON_NEW_PARAM_3( pState, TTextbedState, m_activateCount, m_deactivateCount, m_otherCount );
		return( pState );
	}
	virtual const Hubris::HBOOL OnCompair( const EStateMachineStateBase& in_rhs )const
	{
		TTextbedState& rhs = ( TTextbedState& )in_rhs;
		HBOOL match = HTRUE;
		if( this != ( &in_rhs ) )
		{
			match &= ( ( &m_activateCount ) == ( &rhs.m_activateCount ) );
			match &= ( ( &m_deactivateCount ) == ( &rhs.m_deactivateCount ) );
			match &= ( ( &m_otherCount ) == ( &rhs.m_otherCount ) );
		}

		return match;
	}
	virtual Hubris::HVOID OnSubmitEvent( 
		EStateMachineDataExchange& HCOMMON_UNUSED_VAR( in_out_dataExchange ),
		EStateMachine& HCOMMON_UNUSED_VAR( in_out_stateEngine ),
		const Hubris::HString& HCOMMON_UNUSED_VAR( in_stateName ), 
		const Hubris::HString& in_eventName
		)
	{
		if( in_eventName == EStateMachine::EventNameActivateGet() )
		{
			m_activateCount += 1;
		}
		else if( in_eventName == EStateMachine::EventNameDeactivateGet() )
		{
			m_deactivateCount += 1;
		}
		else
		{
			m_otherCount += 1;
		}

		return;
	}
private:
	HSINT& m_activateCount;
	HSINT& m_deactivateCount;
	HSINT& m_otherCount;
};


class TestbedStateChannel : public EStateMachineStateChannelBase
{
public:
	TestbedStateChannel(
		HSINT& in_activateCount,
		HSINT& in_deactivateCount,
		HSINT& in_otherCount
		)
	: m_activateCount( in_activateCount )
	, m_deactivateCount( in_deactivateCount )
	, m_otherCount( in_otherCount )
	{
		return;
	}
	virtual ~TestbedStateChannel()
	{
		return;
	}
	/////////////////////////////////////////////////////////////////
	// define interface
private:
	virtual EStateMachineStateChannelBase* OnClone()const
	{
		TestbedStateChannel* pState;
		HCOMMON_NEW_PARAM_3( pState, TestbedStateChannel, m_activateCount, m_deactivateCount, m_otherCount );
		return( pState );
	}
	virtual const Hubris::HBOOL OnCompair( const EStateMachineStateChannelBase& in_rhs )const
	{
		TestbedStateChannel& rhs = ( TestbedStateChannel& )in_rhs;
		HBOOL match = HTRUE;
		if( this != ( &in_rhs ) )
		{
			match &= ( ( &m_activateCount ) == ( &rhs.m_activateCount ) );
			match &= ( ( &m_deactivateCount ) == ( &rhs.m_deactivateCount ) );
			match &= ( ( &m_otherCount ) == ( &rhs.m_otherCount ) );
		}

		return match;
	}
	virtual Hubris::HVOID OnSubmitEvent( 
		EStateMachineDataExchange& HCOMMON_UNUSED_VAR( in_out_dataExchange ), 
		EStateMachineChannel& HCOMMON_UNUSED_VAR( in_out_stateEngine ),
		const Hubris::HString& HCOMMON_UNUSED_VAR( in_stateName ), 
		const Hubris::HString& in_eventName
		)
	{
		if( in_eventName == EStateMachine::EventNameActivateGet() )
		{
			m_activateCount += 1;
		}
		else if( in_eventName == EStateMachine::EventNameDeactivateGet() )
		{
			m_deactivateCount += 1;
		}
		else
		{
			m_otherCount += 1;
		}

		return;
	}
private:
	HSINT& m_activateCount;
	HSINT& m_deactivateCount;
	HSINT& m_otherCount;
};

	//////////////////////////////////////////////////
// local free functions
/**/
static const Hubris::HBOOL LocalTestbedStateMachine()
{
	HBOOL success = HTRUE;

	{
		//EStateMachine( const EStateMachine& in_stateMachine );
		//EStateMachine();
		//~EStateMachine();
		//const EStateMachine& operator=( const EStateMachine& in_rhs );
		//const Hubris::HBOOL operator==( const EStateMachine& in_rhs )const;
		//const Hubris::HBOOL operator!=( const EStateMachine& in_rhs )const;
		EStateMachineDataExchange dataExchange;
		EStateMachine stateMachine;
		HSINT activeCountA = 0;
		HSINT deactiveCountA = 0;
		HSINT otherCountA = 0;
		TTextbedState stateA( activeCountA, deactiveCountA, otherCountA );
		stateMachine.StateAdd( "foo", stateA );
		HSINT activeCountB = 0;
		HSINT deactiveCountB = 0;
		HSINT otherCountB = 0;
		TTextbedState stateB( activeCountB, deactiveCountB, otherCountB );
		stateMachine.StateAdd( "bar", stateB );
		stateMachine.StateActiveSet( "bar", HTRUE, dataExchange );

		const EStateMachine stateMachine0( stateMachine );
		const EStateMachine stateMachine1 = stateMachine;
		const EStateMachine stateMachine2;

		success &= ( stateMachine0 == stateMachine );
		success &= ( stateMachine == stateMachine0 );

		success &= ( stateMachine1 == stateMachine0 );
		success &= ( stateMachine0 == stateMachine1 );

		success &= ( stateMachine2 != stateMachine0 );
		success &= ( stateMachine0 != stateMachine2 );

		success &= !( stateMachine1 != stateMachine0 );
		success &= !( stateMachine0 != stateMachine1 );

		success &= !( stateMachine2 == stateMachine0 );
		success &= !( stateMachine0 == stateMachine2 );
	}
	{
		//const Hubris::HBOOL StateTest( 
		//	const Hubris::HString& in_stateName
		//	);
		//Hubris::HVOID StateAdd( 
		//	const Hubris::HString& in_stateName, 
		//	const EStateMachineStateBase& in_state 
		//	);
		//Hubris::HVOID StateRemove( 
		//	const Hubris::HString& in_stateName
		//	);
		//Hubris::HVOID StateActiveSet( 
		//	const Hubris::HString& in_stateName, 
		//	const Hubris::HBOOL in_active, 
		//	EStateMachineDataExchange& in_dataExchange 
		//	);
		//const Hubris::HBOOL StateActiveGet( 
		//	const Hubris::HString& in_stateName 
		//	)const;
		//Hubris::HVOID StateDeactiveAll( 
		//	EStateMachineDataExchange& in_dataExchange 
		//	);
		//Hubris::HVOID SubmitEvent( 
		//	const Hubris::HString& in_eventName, 
		//	EStateMachineDataExchange& in_dataExchange 
		//	);
		//const Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		//const Hubris::HVOID StateActiveNameGather( TArrayString& out_arrayStateActiveName )const;

		EStateMachineDataExchange dataExchange;
		EStateMachine stateMachine;
		HSINT activeCountA = 0;
		HSINT deactiveCountA = 0;
		HSINT otherCountA = 0;
		TTextbedState stateA( activeCountA, deactiveCountA, otherCountA );
		stateMachine.StateAdd( "foo", stateA );
		HSINT activeCountB = 0;
		HSINT deactiveCountB = 0;
		HSINT otherCountB = 0;
		TTextbedState stateB( activeCountB, deactiveCountB, otherCountB );
		stateMachine.StateAdd( "bar", stateB );
		stateMachine.StateActiveSet( "bar", HTRUE, dataExchange );

		success &= ( HTRUE == stateMachine.StateTest( "foo" ) );
		success &= ( HTRUE == stateMachine.StateTest( "bar" ) );
		success &= ( HFALSE == stateMachine.StateTest( "goo" ) );

		stateMachine.StateActiveSet( "bar", HFALSE, dataExchange );
		//stateMachine.StateActiveSet( "bar", HFALSE, dataExchange );
		stateMachine.StateActiveSet( "bar", HTRUE, dataExchange );
		//stateMachine.StateActiveSet( "bar", HTRUE, dataExchange );

		success &= ( HFALSE == stateMachine.StateActiveGet( "foo" ) );
		success &= ( HTRUE == stateMachine.StateActiveGet( "bar" ) );

		stateMachine.StateDeactiveAll( dataExchange );

		success &= ( HFALSE == stateMachine.StateActiveGet( "foo" ) );
		success &= ( HFALSE == stateMachine.StateActiveGet( "bar" ) );

		stateMachine.StateActiveSet( "foo", HTRUE, dataExchange );

		stateMachine.StateRemove( "bar" );
		stateMachine.StateAdd( "bar", stateB );

		TArrayString arrayStateName;
		TArrayString arrayActiveStateName;

		stateMachine.StateNameGather( arrayStateName );
		stateMachine.StateActiveNameGather( arrayActiveStateName );

		success &= ( 2 == arrayStateName.SizeGet() );
		success &= ( 1 == arrayActiveStateName.SizeGet() );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayStateName, "foo" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayStateName, "bar" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayActiveStateName, "foo" ) );

		stateMachine.SubmitEvent( "other", dataExchange );

		success &= ( 1 == activeCountA );
		success &= ( 0 == deactiveCountA );
		success &= ( 1 == otherCountA );
		success &= ( 2 == activeCountB );
		success &= ( 2 == deactiveCountB );
		success &= ( 0 == otherCountB );

		//const Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		//const Hubris::HVOID StateActiveNameGather( TArrayString& out_arrayStateActiveName )const;

	}

	ETESTBED_VALIDATE_STATUS( "EStateMachine", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedStateMachineChannel()
{
	HBOOL success = HTRUE;

	{
		//EStateMachineChannel( const EStateMachineChannel& in_src );
		//EStateMachineChannel();
		//~EStateMachineChannel();
		//const EStateMachineChannel& operator=( const EStateMachineChannel& in_rhs );
		//const Hubris::HBOOL operator==( const EStateMachineChannel& in_rhs )const;
		//const Hubris::HBOOL operator!=( const EStateMachineChannel& in_rhs )const;

		EStateMachineDataExchange dataExchange;
		EStateMachineChannel stateMachine;
		HSINT activeCountA = 0;
		HSINT deactiveCountA = 0;
		HSINT otherCountA = 0;
		TestbedStateChannel stateA( activeCountA, deactiveCountA, otherCountA );
		stateMachine.StateAdd( "foo", stateA );
		HSINT activeCountB = 0;
		HSINT deactiveCountB = 0;
		HSINT otherCountB = 0;
		TestbedStateChannel stateB( activeCountB, deactiveCountB, otherCountB );
		stateMachine.StateAdd( "bar", stateB );
		stateMachine.ChannelAdd( EStateMachineChannel::ChannelDefaultNameGet() );
		stateMachine.ChannelStateActivePush(
			"foo",
			EStateMachineChannel::ChannelDefaultNameGet(),
			dataExchange 
			);

		const EStateMachineChannel stateMachine0( stateMachine );
		const EStateMachineChannel stateMachine1 = stateMachine;
		const EStateMachineChannel stateMachine2;

		success &= ( stateMachine0 == stateMachine );
		success &= ( stateMachine == stateMachine0 );

		success &= ( stateMachine1 == stateMachine0 );
		success &= ( stateMachine0 == stateMachine1 );

		success &= ( stateMachine2 != stateMachine0 );
		success &= ( stateMachine0 != stateMachine2 );

		success &= !( stateMachine1 != stateMachine0 );
		success &= !( stateMachine0 != stateMachine1 );

		success &= !( stateMachine2 == stateMachine0 );
		success &= !( stateMachine0 == stateMachine2 );
	}
	{
		//const Hubris::HBOOL StateTest( 
		//	const Hubris::HString& in_stateName
		//	);

		//Hubris::HVOID StateAdd( 
		//	const Hubris::HString& in_stateName, 
		//	const EStateMachineStateChannelBase& in_state 
		//	);
		//Hubris::HVOID StateRemove( 
		//	const Hubris::HString& in_stateName
		//	);
		//const Hubris::HBOOL ChannelTest( 
		//	const Hubris::HString& in_channelName
		//	);
		//Hubris::HVOID ChannelAdd( 
		//	const Hubris::HString& in_channelName 
		//	);
		//Hubris::HVOID ChannelRemove( 
		//	const Hubris::HString& in_channelName
		//	);
		//Hubris::HVOID ChannelStateActivePush( 
		//	const Hubris::HString& in_stateName, 
		//	const Hubris::HString& in_channelName, 
		//	EStateMachineDataExchange& in_dataExchange 
		//	);
		//Hubris::HVOID ChannelStateActivePop( 
		//	const Hubris::HString& in_channelName, 
		//	EStateMachineDataExchange& in_dataExchange 
		//	);
		//Hubris::HVOID ChannelStateActiveClear( 
		//	const Hubris::HString& in_channelName, 
		//	EStateMachineDataExchange& in_dataExchange 
		//	);
		//Hubris::HVOID SubmitEvent( 
		//	const Hubris::HString& in_eventName, 
		//	EStateMachineDataExchange& in_dataExchange 
		//	);
		//Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		//Hubris::HVOID ChannelNameGather( TArrayString& out_arrayChannelName )const;
		//Hubris::HVOID ChannelStateStackGather( 
		//	TArrayString& out_arrayChannelStateNameStack, 
		//	const Hubris::HString& in_channelName, 
		//	const Hubris::HSINT in_maxStateReturnCount = 1 
		//	)const;


		EStateMachineDataExchange dataExchange;
		EStateMachineChannel stateMachine;
		HSINT activeCountA = 0;
		HSINT deactiveCountA = 0;
		HSINT otherCountA = 0;
		TestbedStateChannel stateA( activeCountA, deactiveCountA, otherCountA );
		stateMachine.StateAdd( "foo", stateA );
		HSINT activeCountB = 0;
		HSINT deactiveCountB = 0;
		HSINT otherCountB = 0;
		TestbedStateChannel stateB( activeCountB, deactiveCountB, otherCountB );
		stateMachine.StateAdd( "bar", stateB );
		HSINT activeCountC = 0;
		HSINT deactiveCountC = 0;
		HSINT otherCountC = 0;
		TestbedStateChannel stateC( activeCountC, deactiveCountC, otherCountC );
		stateMachine.StateAdd( "moo", stateC );

		stateMachine.ChannelAdd( "channel_0" );
		stateMachine.ChannelAdd( "channel_1" );

		stateMachine.ChannelStateActivePush(
			"foo",
			"channel_0",
			dataExchange 
			);
		stateMachine.ChannelStateActivePush(
			"moo",
			"channel_0",
			dataExchange 
			);
		stateMachine.ChannelStateActivePush(
			"bar",
			"channel_1",
			dataExchange 
			);
		stateMachine.ChannelStateActiveClear(
			"channel_1",
			dataExchange
			);

		success &= ( HTRUE == stateMachine.StateTest( "foo" ) );
		success &= ( HTRUE == stateMachine.StateTest( "bar" ) );
		success &= ( HTRUE == stateMachine.StateTest( "moo" ) );
		success &= ( HFALSE == stateMachine.StateTest( "goo" ) );

		success &= ( HTRUE == stateMachine.ChannelTest( "channel_0" ) );
		success &= ( HTRUE == stateMachine.ChannelTest( "channel_1" ) );
		success &= ( HFALSE == stateMachine.ChannelTest( "channel_2" ) );



		TArrayString arrayStateName;
		TArrayString arrayChannelName;
		TArrayString arrayChannelactiveStack;

		stateMachine.StateNameGather( arrayStateName );
		stateMachine.ChannelNameGather( arrayChannelName );
		stateMachine.ChannelStateStackGather(
			arrayChannelactiveStack,
			"channel_0" );

		success &= ( 1 == arrayChannelactiveStack.SizeGet() );
		success &= ( 3 == arrayStateName.SizeGet() );
		success &= ( 2 == arrayChannelName.SizeGet() );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayChannelactiveStack, "moo" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayStateName, "foo" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayStateName, "bar" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayStateName, "moo" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayChannelName, "channel_0" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayChannelName, "channel_1" ) );

		stateMachine.SubmitEvent( "other", dataExchange );

		success &= ( 1 == activeCountA );
		success &= ( 1 == deactiveCountA );
		success &= ( 0 == otherCountA );
		success &= ( 1 == activeCountB );
		success &= ( 1 == deactiveCountB );
		success &= ( 0 == otherCountB );
		success &= ( 1 == activeCountC );
		success &= ( 0 == deactiveCountC );
		success &= ( 1 == otherCountC );

		//const Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		//const Hubris::HVOID StateActiveNameGather( TArrayString& out_arrayStateActiveName )const;

	}

	ETESTBED_VALIDATE_STATUS( "EStateMachineChannel", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedStateMachine()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedStateMachine" );

	success &= LocalTestbedStateMachine();
	success &= LocalTestbedStateMachineChannel();

	return success;
}

/**/