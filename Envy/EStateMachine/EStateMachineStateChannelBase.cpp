//file: Envy/EStateMachine/EStateMachineStateChannelBase.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStateMachine/EStateMachineStateChannelBase.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;


//HTYPE_RUN_TIME_TYPE_INFO_IMPLEMENTATION_BASE( Envy, EStateBase );

/////////////////////////////////////////////////////////////////
// creation
/**/
EStateMachineStateChannelBase::EStateMachineStateChannelBase()
{
	return;
}

/**/
EStateMachineStateChannelBase::~EStateMachineStateChannelBase()
{
	return;
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID EStateMachineStateChannelBase::DeleteThis()
{
	HCOMMON_DELETE_THIS( this, EStateMachineStateChannelBase );
	return;
}

/**/
EStateMachineStateChannelBase* EStateMachineStateChannelBase::Clone()const
{
	return( OnClone() );
}

/**/
const Hubris::HBOOL EStateMachineStateChannelBase::Compair( const EStateMachineStateChannelBase& in_rhs )const
{
	return( OnCompair( in_rhs ) );
}

/**/
Hubris::HVOID EStateMachineStateChannelBase::SubmitEvent( 
	EStateMachineDataExchange& in_out_dataExchange, 
	EStateMachineChannel& in_out_stateEngine,
	const Hubris::HString& in_stateName, 
	const Hubris::HString& in_eventName
	)
{
	OnSubmitEvent(
		in_out_dataExchange, 
		in_out_stateEngine,
		in_stateName, 
		in_eventName
		);
	return;
}

/**/