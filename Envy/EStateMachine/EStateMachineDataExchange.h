//file: Envy/EStateMachine/EStateMachineDataExchange.h
#ifndef _E_STATE_MACHINE_DATA_EXCHANGE_H_
#define _E_STATE_MACHINE_DATA_EXCHANGE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HTypeRunTimeInfo.h >

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations

	class EStateMachineImplementation;

	/////////////////////////////////////////////////////////////////
	// class

	/*
		interface for state machine logic to access client data
	*/
	class EStateMachineDataExchange
	{
		/////////////////////////////////////////////////////////////////
		// RTTI
	public:
		HTYPE_RUN_TIME_TYPE_INFO_BASE( EStateMachineDataExchange );

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		//EStateMachineDataExchange();
	//protected:
		//~EStateMachineDataExchange();

	};

	/**/
};

#endif // _E_STATE_MACHINE_DATA_EXCHANGE_H_