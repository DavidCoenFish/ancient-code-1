//file: Envy/EStateMachine/EStateMachineStateChannelBase.h
#ifndef _E_STATE_MACHINE_STATE_CHANNEL_BASE_H_
#define _E_STATE_MACHINE_STATE_CHANNEL_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include< Hubris/HSmartPointer/HSmartPointer_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	class EStateMachineDataExchange;
	class EStateMachineChannel;

	/////////////////////////////////////////////////////////////////
	// class
	/*
		state base, define state interface 
	*/
	class EStateMachineStateChannelBase : public Hubris::HSmartPointerObjectBase< EStateMachineStateChannelBase >
	{
		/////////////////////////////////////////////////////////////////
		// RTTI
	public:
		//HTYPE_RUN_TIME_TYPE_INFO_BASE

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStateMachineStateChannelBase();
		virtual ~EStateMachineStateChannelBase();

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DeleteThis();

		//make a clone of this object
		EStateMachineStateChannelBase* Clone()const;
		//return true if the input is equivalent
		const Hubris::HBOOL Compair( const EStateMachineStateChannelBase& in_rhs )const;

		//contract with state machine to respond to events
		Hubris::HVOID SubmitEvent( 
			EStateMachineDataExchange& in_out_dataExchange, 
			EStateMachineChannel& in_out_stateEngine,
			const Hubris::HString& in_stateName, 
			const Hubris::HString& in_eventName
			);

		/////////////////////////////////////////////////////////////////
		// define interface
	private:
		virtual EStateMachineStateChannelBase* OnClone()const=0;
		virtual const Hubris::HBOOL OnCompair( const EStateMachineStateChannelBase& in_rhs )const=0;
		virtual Hubris::HVOID OnSubmitEvent( 
			EStateMachineDataExchange& in_out_dataExchange, 
			EStateMachineChannel& in_out_stateEngine,
			const Hubris::HString& in_stateName, 
			const Hubris::HString& in_eventName
			)=0;

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		const EStateMachineStateChannelBase& operator=( const EStateMachineStateChannelBase& in_rhs );
		EStateMachineStateChannelBase( const EStateMachineStateChannelBase& in_src );

	};

	/**/
};

#endif // _E_STATE_MACHINE_STATE_CHANNEL_BASE_H_