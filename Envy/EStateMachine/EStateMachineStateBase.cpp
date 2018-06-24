//file: Envy/EStateMachine/EStateMachineStateBase.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStateMachine/EStateMachineStateBase.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// creation
/**/
EStateMachineStateBase::EStateMachineStateBase()
{
	return;
}

/**/
EStateMachineStateBase::~EStateMachineStateBase()
{
	return;
}

/////////////////////////////////////////////////////////////////
// public methods
Hubris::HVOID EStateMachineStateBase::DeleteThis()
{
	HCOMMON_DELETE_THIS( this, EStateMachineStateBase );
}

/**/
EStateMachineStateBase* const EStateMachineStateBase::Clone()const
{
	return OnClone();
}

/**/
const Hubris::HBOOL EStateMachineStateBase::Compair( const EStateMachineStateBase& in_rhs )const
{
	return OnCompair( in_rhs );
}

/**/
Hubris::HVOID EStateMachineStateBase::SubmitEvent( 
	EStateMachineDataExchange& in_out_dataExchange, 
	EStateMachine& in_out_stateEngine,
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

/**
Hubris::HVOID EStateMachineStateBase::SubmitEvent( 
	const Hubris::HString& in_eventName, 
	EStateMachine& in_stateEngine
	)
{
	OnSubmitEvent( 
		in_eventName,
		in_stateEngine
		);

	return;
}

/**/
