//file: Envy/EStateMachine/EStateMachineChannelImplementation.h
#ifndef _E_STATE_MACHINE_CHANNEL_IMPLEMENTAION_H_
#define _E_STATE_MACHINE_CHANNEL_IMPLEMENTAION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

#include "Envy/EStateMachine/EStateMachineChannel.h"
#include "Envy/EStateMachine/EStateMachineStateChannelBase.h"
#include "Envy/EStateMachine/EStateMachineTemplate.h"

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	class EStateMachineChannel;
	//template< typename IN_STATE_BASE, typename IN_STATE_MACHINE_INTERFACE > class EStateMachineTemplate;

	/////////////////////////////////////////////////////////////////
	// class

	/*
		generic state machine
		events can be submited to the active states
		states call activate/ deactivate events on themselves on activation/ deactivation
	*/
	class EStateMachineChannelImplementation
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HContainerTree< Hubris::HString, TArrayString >TTreeStringArrayString;
		typedef EStateMachineTemplate< EStateMachineStateChannelBase, EStateMachineChannel >TStateMachine;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStateMachineChannelImplementation( const EStateMachineChannelImplementation& in_src );
		EStateMachineChannelImplementation();
		~EStateMachineChannelImplementation();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EStateMachineChannelImplementation& operator=( const EStateMachineChannelImplementation& in_rhs );
		const Hubris::HBOOL operator==( const EStateMachineChannelImplementation& in_rhs )const;
		const Hubris::HBOOL operator!=( const EStateMachineChannelImplementation& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL StateTest( 
			const Hubris::HString& in_stateName
			);

		Hubris::HVOID StateAdd( 
			const Hubris::HString& in_stateName, 
			const EStateMachineStateChannelBase& in_state 
			);
		Hubris::HVOID StateRemove( 
			const Hubris::HString& in_stateName
			);

		const Hubris::HBOOL ChannelTest( 
			const Hubris::HString& in_channelName
			);

		Hubris::HVOID ChannelAdd( 
			const Hubris::HString& in_channelName 
			);
		Hubris::HVOID ChannelRemove( 
			const Hubris::HString& in_channelName
			);

		Hubris::HVOID ChannelStateActivePush( 
			const Hubris::HString& in_stateName, 
			const Hubris::HString& in_channelName, 
			EStateMachineDataExchange& in_dataExchange,
			EStateMachineChannel& in_stateMachine
			);
		Hubris::HVOID ChannelStateActivePop( 
			const Hubris::HString& in_channelName, 
			EStateMachineDataExchange& in_dataExchange,
			EStateMachineChannel& in_stateMachine
			);
		Hubris::HVOID ChannelStateActiveClear( 
			const Hubris::HString& in_channelName, 
			EStateMachineDataExchange& in_dataExchange,
			EStateMachineChannel& in_stateMachine
			);

		Hubris::HVOID SubmitEvent( 
			const Hubris::HString& in_eventName, 
			EStateMachineDataExchange& in_dataExchange,
			EStateMachineChannel& in_stateMachine
			);

		Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		Hubris::HVOID ChannelNameGather( TArrayString& out_arrayChannelName )const;
		Hubris::HVOID ChannelStateStackGather( 
			TArrayString& out_arrayChannelStateNameStack, 
			const Hubris::HString& in_channelName, 
			const Hubris::HSINT in_maxStateReturnCount 
			)const;

		/////////////////////////////////////////////////////////////////
		// private methods
	private: 

		/////////////////////////////////////////////////////////////////
		// private accessors
	private:

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		//EStateMachineImplementation m_stateMachine;
		TStateMachine m_stateMachine;
		TTreeStringArrayString m_treeChannelNameStateNameStack;

	};

	/**/
};

#endif // _E_STATE_MACHINE_CHANNEL_IMPLEMENTAION_H_
