//file: Envy/ETestbed/ETestbedStateMachineSimple.cpp

#include "Envy/ETestbed/ETestbedStateMachineSimple.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Envy;
using namespace Hubris;

//////////////////////////////////////////////////
// typedef
/**/
class CState;
class CDataExchange;
typedef EStateMachineSimple< CState, CDataExchange >TStateMachine;

//////////////////////////////////////////////////
// local class
/**/
class CState
{
public:
	CState( const CState& in_src )
	: m_num( 0 )
	{
		( *this ) = in_src;
		return;
	}
	CState( const HSINT in_num = HCOMMON_INVALID_INDEX )
	: m_num( in_num )
	{
		return;
	}
	~CState()
	{
		return;
	}
	const CState& operator=( const CState& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_num = in_rhs.m_num;
		}

		return( *this );
	}
	const HBOOL operator==( const CState& in_rhs )const
	{
		HBOOL match = HTRUE;
		if( this != ( &in_rhs ) )
		{
			match &= ( m_num == in_rhs.m_num );
		}

		return match;
	}
	const HBOOL operator!=( const CState& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	HVOID SubmitEvent(
		CDataExchange& HCOMMON_UNUSED_VAR( in_dataExchange ),
		TStateMachine& HCOMMON_UNUSED_VAR( in_stateMachine ),
		const HString& HCOMMON_UNUSED_VAR( in_stateName ),
		const HString& HCOMMON_UNUSED_VAR( in_eventName )
		)
	{
		return;
	}
public:
	HSINT m_num;
};

class CDataExchange
{
public:
	CDataExchange(	
		HBOOL& in_success
		)
	: m_success( in_success )
	{
		return;
	}
	~CDataExchange()
	{
		return;
	}
private:
	CDataExchange( const CDataExchange& in_src );
	const CDataExchange& operator=( const CDataExchange& in_rhs );
public:
	HBOOL& m_success;
};

namespace Envy
{
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const CState& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, CState& out_data );
};

//CState
Hubris::HVOID Envy::EMementoTraitCollect< CState >( EMementoCollect& in_out_mementoCollect, const CState& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_num", in_data.m_num );
	return;
}
Hubris::HVOID Envy::EMementoTraitAssign< CState >( const EMementoAssign& in_out_mementoAssign, CState& out_data )
{
	in_out_mementoAssign.MemberGet( "m_num", out_data.m_num );
	return;
}

//////////////////////////////////////////////////
// local free functions
/**/
static const Hubris::HBOOL TestbedStateMachineSimpleObject()
{
	HBOOL success = HTRUE;

	CDataExchange dataExchange( success );
	TStateMachine stateMachine;
	stateMachine.StateAdd( "foo", CState( 0 ) );
	stateMachine.StateAdd( "bar", CState( 1 ) );
	stateMachine.StateAdd( "moo", CState( 2 ) );
	stateMachine.StateAdd( "zoo", CState( 3 ) );
	stateMachine.StateActiveSet(
		"moo",
		HTRUE,
		dataExchange
		);
	{
		const TStateMachine stateMachine0( stateMachine );
		const TStateMachine stateMachine1 = stateMachine;
		const TStateMachine stateMachine2;

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

	ETESTBED_VALIDATE_STATUS( "EStateMachineObject", success );

	return success;
}

/**/
static const Hubris::HBOOL TestbedStateMachineSimpleMemento()
{
	HBOOL success = HTRUE;

	CDataExchange dataExchange( success );
	TStateMachine stateMachine;
	stateMachine.StateAdd( "foo", CState( 0 ) );
	stateMachine.StateAdd( "bar", CState( 1 ) );
	stateMachine.StateAdd( "moo", CState( 2 ) );
	stateMachine.StateAdd( "zoo", CState( 3 ) );
	stateMachine.StateActiveSet(
		"moo",
		HTRUE,
		dataExchange
		);

	EMemento memento;

	{
		EMementoCollect mememntoCollect( memento );
		mememntoCollect.MemberAdd( "stateMachine", stateMachine );
	}

	{
		TStateMachine stateMachine0;
		EMementoAssign mememntoAssign( memento );
		mememntoAssign.MemberGet( "stateMachine", stateMachine0 );

		success &= ( stateMachine == stateMachine0 );
	}

	ETESTBED_VALIDATE_STATUS( "EStateMachineMemento", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedStateMachineSimple()
{
	HBOOL success = HTRUE;

	success &= TestbedStateMachineSimpleObject();
	success &= TestbedStateMachineSimpleMemento();


	ETESTBED_VALIDATE_START( "TestbedStateMachineSimple" );

	return success;
}

/**/