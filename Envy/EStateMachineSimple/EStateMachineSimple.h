//file: Envy/EStateMachineSimple/EStateMachineSimple.h
#ifndef _E_STATE_MACHINE_SIMPLE_H_
#define _E_STATE_MACHINE_SIMPLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

namespace Envy
{
	const Hubris::HCHAR* const EStateMachineSimpleEventNameGetActivate();
	const Hubris::HCHAR* const EStateMachineSimpleEventNameGetDeactivate();

	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EMementoCollect;
	class EMementoAssign;
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >class EStateMachineSimple;

	template< typename IN_STATE, typename IN_DATA_EXCHANGE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >& in_data );
	template< typename IN_STATE, typename IN_DATA_EXCHANGE  >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >& out_data );

	/////////////////////////////////////////////////////////////////
	// class
	/*
		templated state machine for a single type of state

		state obliged to satify contract methods
			HVOID SubmitEvent(
				IN_DATA_EXCHANGE& in_out_dataExchange,
				EStateMachineSimple& in_out_stateMachine,
				const HString& in_stateName,
				const HString& in_eventName,
				);


		IN_DATA_EXCHANGE is in client domain, so no reason for it not to have a reference to the state machine and allow state active changes during event
		...so protect state active list during event submition
	*/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	class EStateMachineSimple
	{
		//memento
		typedef EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >TSelf;
		friend Hubris::HVOID EMementoTraitCollect< IN_STATE, IN_DATA_EXCHANGE >( Envy::EMementoCollect& in_out_mementoCollect, const TSelf& in_data );
		friend Hubris::HVOID EMementoTraitAssign< IN_STATE, IN_DATA_EXCHANGE >( const Envy::EMementoAssign& in_out_mementoAssign, TSelf& out_data );

		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerTree< Hubris::HString, IN_STATE >TTreeStringState;
		typedef Hubris::HContainerTree< Hubris::HString, IN_STATE* >TTreeStringStatePointer;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStateMachineSimple( const EStateMachineSimple& in_src );
		EStateMachineSimple();
		~EStateMachineSimple();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EStateMachineSimple& operator=( const EStateMachineSimple& in_rhs );
		const Hubris::HBOOL operator==( const EStateMachineSimple& in_rhs )const;
		const Hubris::HBOOL operator!=( const EStateMachineSimple& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		//return true if there is a state of given name in state machine
		const Hubris::HBOOL StateTest( 
			const Hubris::HString& in_stateName
			);

		//replace state on duplicate name
		Hubris::HVOID StateAdd( 
			const Hubris::HString& in_stateName, 
			const IN_STATE& in_state 
			);

		//can remove active state but not a good idea
		Hubris::HVOID StateRemove( 
			const Hubris::HString& in_stateName
			);

		//set state active or not, NOP on state already being active/ deactive
		Hubris::HVOID StateActiveSet( 
			const Hubris::HString& in_stateName, 
			const Hubris::HBOOL in_active, 
			IN_DATA_EXCHANGE& in_dataExchange 
			);

		//return true if named state is active, ASSERT on state not found
		const Hubris::HBOOL StateActiveGet( 
			const Hubris::HString& in_stateName 
			)const;

		//deactivate all active states
		Hubris::HVOID StateDeactiveAll( 
			IN_DATA_EXCHANGE& in_dataExchange 
			);

		//submit event to all active states
		Hubris::HVOID SubmitEvent( 
			const Hubris::HString& in_eventName, 
			IN_DATA_EXCHANGE& in_dataExchange
			);

		//return HNULL string if state not found, find state name
		const Hubris::HString StateNameGet(
			const IN_STATE* const in_pState
			)const;

		//gather the array of state names
		const Hubris::HVOID StateNameGather( TArrayString& out_arrayStateName )const;
		//gather then array of active state names
		const Hubris::HVOID StateActiveNameGather( TArrayString& out_arrayStateActiveName )const;

		//return HNULL if not found
		// try to make it so client doesn't NEED to look at states
		// or do it by 'submit event'...
		//const IN_STATE* const StateGet( const Hubris::HString& in_name )const;
		//IN_STATE* const StateGet( const Hubris::HString& in_name );

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		TTreeStringState m_treeStringState;
		TTreeStringStatePointer m_treeActiveState;

	};

	/**/
	/////////////////////////////////////////////////////////////////
	// creation
	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::EStateMachineSimple( const EStateMachineSimple& in_src )
	: m_treeStringState()
	, m_treeActiveState()
	{
		( *this ) = in_src;
		return;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::EStateMachineSimple()
	: m_treeStringState()
	, m_treeActiveState()
	{
		return;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::~EStateMachineSimple()
	{
		return;
	}

	/////////////////////////////////////////////////////////////////
	// operators
	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >& EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::operator=( const EStateMachineSimple& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_treeStringState = in_rhs.m_treeStringState;

			m_treeActiveState.Clear();
			for( const TTreeStringStatePointer::TIterator iterator = in_rhs.m_treeActiveState.Begin(); iterator != in_rhs.m_treeActiveState.End(); ++iterator )
			{
				TTreeStringState::TIterator foundIterator = m_treeStringState.Find( iterator.KeyGet() );
				if( foundIterator != m_treeStringState.End() )
				{
					//m_treeActiveState.Insert( HString( iterator.KeyGet() ), ( IN_STATE* )( &( *foundIterator ) ) );
					m_treeActiveState.Insert( iterator.KeyGet(), &( *foundIterator ) );
				}
			}
		}

		return( *this );
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const Hubris::HBOOL EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::operator==( const EStateMachineSimple& in_rhs )const
	{
		Hubris::HBOOL match = HTRUE;
		if( this != ( &in_rhs ) )
		{
			match &= ( m_treeStringState == in_rhs.m_treeStringState );
			match &= ( m_treeActiveState.SizeGet() == in_rhs.m_treeActiveState.SizeGet() );
			if( HTRUE == match )
			{
				const TTreeStringStatePointer::TIterator iteratorLhs = m_treeActiveState.Begin();
				for( const TTreeStringStatePointer::TIterator iteratorRhs = in_rhs.m_treeActiveState.Begin(); iteratorRhs != in_rhs.m_treeActiveState.End(); ++iteratorRhs )
				{
					match &= ( iteratorLhs.KeyGet() == iteratorRhs.KeyGet() );
					if( HFALSE == match )
					{
						break;
					}

					++iteratorLhs;
				}
			}
		}

		return match;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const Hubris::HBOOL EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::operator!=( const EStateMachineSimple& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	/////////////////////////////////////////////////////////////////
	// public methods
	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const Hubris::HBOOL EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateTest( 
		const Hubris::HString& in_stateName
		)
	{
		return( m_treeStringState.Find( in_stateName ) != m_treeStringState.End() );
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	Hubris::HVOID EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateAdd( 
		const Hubris::HString& in_stateName, 
		const IN_STATE& in_state 
		)
	{
		m_treeStringState.Insert( in_stateName, in_state );

		return;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	Hubris::HVOID EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateRemove( 
		const Hubris::HString& in_stateName
		)
	{
		TTreeStringState::TIterator iterator = m_treeStringState.Find( in_stateName );
		if( iterator != m_treeStringState.End() )
		{
			m_treeStringState.Remove( iterator ); 
		}

		return;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	Hubris::HVOID EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateActiveSet( 
		const Hubris::HString& in_stateName, 
		const Hubris::HBOOL in_active, 
		IN_DATA_EXCHANGE& in_dataExchange 
		)
	{
		TTreeStringState::TIterator iterator = m_treeStringState.Find( in_stateName );
		if( iterator == m_treeStringState.End() )
		{
			//state not found
			return;
		}

		TTreeStringStatePointer::TIterator iteratorActiveFound = m_treeActiveState.Find( in_stateName );

		if( HTRUE == in_active )
		{
			if( iteratorActiveFound != m_treeActiveState.End() )
			{
				//already active
				return;
			}

			m_treeActiveState.Insert( in_stateName, &( *iterator ) );

				//IN_DATA_EXCHANGE& in_out_dataExchange,
				//EStateMachineSimple& in_out_stateMachine,
				//const HString& in_stateName,
				//const HString& in_eventName,
			( *iterator ).SubmitEvent(
				in_dataExchange,
				( *this ),
				in_stateName,
				EStateMachineSimpleEventNameGetActivate()
				);
		}
		else
		{
			if( iteratorActiveFound == m_treeActiveState.End() )
			{
				//already deactvated or not found
				return;
			}

			m_treeActiveState.Remove( iteratorActiveFound );

			( *iterator ).SubmitEvent(
				in_dataExchange,
				( *this ),
				in_stateName,
				EStateMachineSimpleEventNameGetDeactivate()
				);
		}

		return;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const Hubris::HBOOL EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateActiveGet( 
		const Hubris::HString& in_stateName 
		)const
	{
		return( m_treeActiveState.Find( in_stateName ) != m_treeActiveState.End() );
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	Hubris::HVOID EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateDeactiveAll( 
		IN_DATA_EXCHANGE& in_dataExchange 
		)
	{
		TArrayString localArrayNameActive;
		StateActiveNameGather( localArrayNameActive );

		HCOMMON_FOR_EACH_CONST( stateName, localArrayNameActive, TArrayString )
		{
			StateActiveSet(
				stateName,
				HFALSE,
				in_dataExchange
				);
		}

		return;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	Hubris::HVOID EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::SubmitEvent( 
		const Hubris::HString& in_eventName, 
		IN_DATA_EXCHANGE& in_dataExchange
		)
	{
		TArrayString localArrayNameActive;
		StateActiveNameGather( localArrayNameActive );

		HCOMMON_FOR_EACH_CONST( stateName, localArrayNameActive, TArrayString )
		{
			TTreeStringStatePointer::TIterator iteratorActiveFound = m_treeActiveState.Find( stateName );
			if( iteratorActiveFound == m_treeActiveState.End() )
			{
				continue;
			}

			( *iteratorActiveFound )->SubmitEvent(
				in_dataExchange,
				( *this ),
				stateName,
				in_eventName
				);
		}
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const Hubris::HString EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateNameGet(
		const IN_STATE* const in_pState
		)const
	{
		for( const TTreeStringState::TIterator iterator = m_treeStringState.Begin(); iterator != m_treeStringState.End(); ++iterator )
		{
			if( in_pState != &( *iterator ) )
			{
				continue;
			}

			return iterator.KeyGet();
		}

		return HNULL;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const Hubris::HVOID EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateNameGather( TArrayString& out_arrayStateName )const
	{
		for( const TTreeStringState::TIterator iterator = m_treeStringState.Begin(); iterator != m_treeStringState.End(); ++iterator )
		{
			out_arrayStateName.Insert( iterator.KeyGet() );
		}

		return;
	}

	/**/
	template< typename IN_STATE, typename IN_DATA_EXCHANGE >
	const Hubris::HVOID EStateMachineSimple< IN_STATE, IN_DATA_EXCHANGE >::StateActiveNameGather( TArrayString& out_arrayStateActiveName )const
	{
		for( const TTreeStringStatePointer::TIterator iterator = m_treeActiveState.Begin(); iterator != m_treeActiveState.End(); ++iterator )
		{
			out_arrayStateActiveName.Insert( iterator.KeyGet() );
		}

		return;
	}


};

#endif // _E_STATE_MACHINE_SIMPLE_H_
