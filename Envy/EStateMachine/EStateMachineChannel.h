//file: Envy/EStateMachine/EStateMachineChannel.h
#ifndef _E_STATE_MACHINE_CHANNEL_H_
#define _E_STATE_MACHINE_CHANNEL_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	class HString;
	template< typename IN_TYPE >class HContainerArray;
};

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations

	class EStateMachineDataExchange;
	class EStateMachineChannelImplementation;
	class EStateMachineStateChannelBase;

	/////////////////////////////////////////////////////////////////
	// class
	/*
		a state machine with channels
		each channel has a last in first out stack of active states
	*/
	class EStateMachineChannel
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStateMachineChannel( const EStateMachineChannel& in_src );
		EStateMachineChannel();
		~EStateMachineChannel();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EStateMachineChannel& operator=( const EStateMachineChannel& in_rhs );
		const Hubris::HBOOL operator==( const EStateMachineChannel& in_rhs )const;
		const Hubris::HBOOL operator!=( const EStateMachineChannel& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		//return true if there is a state of given name in state machine
		const Hubris::HBOOL StateTest( 
			const Hubris::HString& in_stateName
			);

		//assert on duplicate name, assert on state being HNULL
		Hubris::HVOID StateAdd( 
			const Hubris::HString& in_stateName, 
			const EStateMachineStateChannelBase& in_state 
			);
		//assert on state not found
		Hubris::HVOID StateRemove( 
			const Hubris::HString& in_stateName
			);

		//return true if there is a state of given name in state machine
		const Hubris::HBOOL ChannelTest( 
			const Hubris::HString& in_channelName
			);

		//assert on duplicate name
		Hubris::HVOID ChannelAdd( 
			const Hubris::HString& in_channelName 
			);
		//assert on channel not found, NOP to states on channel, ie, doesn't deactivate active state on channel
		Hubris::HVOID ChannelRemove( 
			const Hubris::HString& in_channelName
			);

		//assert on channel not found, assert if state not found
		Hubris::HVOID ChannelStateActivePush( 
			const Hubris::HString& in_stateName, 
			const Hubris::HString& in_channelName, 
			EStateMachineDataExchange& in_dataExchange 
			);
		Hubris::HVOID ChannelStateActivePop( 
			const Hubris::HString& in_channelName, 
			EStateMachineDataExchange& in_dataExchange 
			);
		Hubris::HVOID ChannelStateActiveClear( 
			const Hubris::HString& in_channelName, 
			EStateMachineDataExchange& in_dataExchange 
			);

		//submits event to ALL active states
		Hubris::HVOID SubmitEvent( 
			const Hubris::HString& in_eventName, 
			EStateMachineDataExchange& in_dataExchange 
			);

		//gather the array of state names
		Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		//gather then array of active state names
		Hubris::HVOID ChannelNameGather( TArrayString& out_arrayChannelName )const;
		//gather then array of active state names( active state first on array)
		Hubris::HVOID ChannelStateStackGather( 
			TArrayString& out_arrayChannelStateNameStack, 
			const Hubris::HString& in_channelName, 
			const Hubris::HSINT in_maxStateReturnCount = 1 
			)const;

		/////////////////////////////////////////////////////////////////
		// public static accessor
	public:
		static const Hubris::HCHAR* const ChannelDefaultNameGet();

		static const Hubris::HCHAR* const EventNameActivateGet();
		static const Hubris::HCHAR* const EventNameDeactivateGet();

		/////////////////////////////////////////////////////////////////
		// private accessors
	private:
		const EStateMachineChannelImplementation& ImplementationGet()const;
		EStateMachineChannelImplementation& ImplementationGet();

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		EStateMachineChannelImplementation* m_pImplementation;

	};

	/**/
};

#endif // _E_STATE_MACHINE_CHANNEL_H_
