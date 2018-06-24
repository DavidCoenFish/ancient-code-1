//file: Envy/EStateMachineSimple/EStateMachineSimpleTrait.h
#ifndef _E_STATE_MACHINE_SIMPLE_TRAIT_H_
#define _E_STATE_MACHINE_SIMPLE_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/EStateMachineSimple/EStateMachineSimple.h"

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	//EStateMachineSimple
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >& in_data )
	{
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		in_out_mementoCollect.MemberAdd( "m_treeStringState", in_data.m_treeStringState );

		//WARNING, active states scribe may be problimatic, as 'set state active' would not be called on state on unscribe, 
		//but that may be fine...
		TArrayString activeStates;
		in_data.StateActiveNameGather( activeStates );
		in_out_mementoCollect.MemberAdd( "m_activeStates", activeStates );

		return;
	}
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >& out_data )
	{
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		in_out_mementoAssign.MemberGet( "m_treeStringState", out_data.m_treeStringState );

		TArrayString activeStates;
		in_out_mementoAssign.MemberGet( "m_activeStates", activeStates );
		out_data.m_treeActiveState.Clear();

		HCOMMON_FOR_EACH_CONST( name, activeStates, TArrayString )
		{
			EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::TTreeStringState::TIterator iterator = out_data.m_treeStringState.Find( name );
			if( iterator == out_data.m_treeStringState.End() )
			{
				continue;
			}

			out_data.m_treeActiveState.Insert( name, &( *iterator ) );
		}

		return;
	}

};

#endif // _E_STATE_MACHINE_SIMPLE_TRAIT_H_
