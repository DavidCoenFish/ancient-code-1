//file: Hubris/HSmartPointer/HSmartPointer.h
#ifndef _H_SMART_POINTER_H_
#define _H_SMART_POINTER_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

namespace Hubris
{

	//////////////////////////////////////////////////////
	// class
	/*
		in_type is under contract to have a member HSmartPointerReferenceCount m_referenceCount;
		or to derive from HSmartPointerObjectBase

		if the smart pointer has ownership of the object (destorys it ), should it also Create it?
		if we Create it, hide the pointer assignment members? no, would like to keep construction params avaliable
	*/
	template< typename IN_TYPE >class HSmartPointer
	{

		//////////////////////////////////////////////////////
		// creation
	public:
		HSmartPointer( const HSmartPointer& in_data );
		//construct a smart pointer that holds in_data, in_data referene count is incremented
		HSmartPointer( IN_TYPE* const in_data );
		HSmartPointer( const HS32 in_null );
		HSmartPointer();

		~HSmartPointer();

		//////////////////////////////////////////////////////
		// operator
	public:
		const IN_TYPE& operator *()const;
		IN_TYPE& operator *();

		const IN_TYPE* operator ->()const;
		IN_TYPE* operator ->();

		const IN_TYPE* RawGet()const;
		IN_TYPE* RawGet();
 
		const HSmartPointer& operator =( const HSmartPointer& in_rhs );
		const HSmartPointer& operator =( IN_TYPE* in_rhs );
		const HSmartPointer& operator =( const HS32 in_rhs );

		//see smart pointer operators for operators

		//////////////////////////////////////////////////////
		// public methods
	public:
		// Create a new object for the smart pointer
		HVOID Create();
		// Create a new object for the smart pointer which is a COPY of in_src
		HVOID CreateCopy( const IN_TYPE& in_src );
		// set this pointer to HNULL, destoy object if last reference
		HVOID Destroy();

		//////////////////////////////////////////////////////
		// private methods
	private:
		HVOID IncrementReferenceCount();
		HVOID DecrementReferenceCount();

		//////////////////////////////////////////////////////
		// private members
	private:
		IN_TYPE* m_data;

	};

	/**/
	template< typename IN_TYPE > 
	HSmartPointer< IN_TYPE >::HSmartPointer( const HSmartPointer< IN_TYPE >& in_data )
	: m_data( HNULL )
	{
		( *this ) = in_data;
		return;
	}

	/**/
	template< typename IN_TYPE > 
	HSmartPointer< IN_TYPE >::HSmartPointer( IN_TYPE* const in_data )
	: m_data( HNULL )
	{
		( *this ) = in_data;
		return;
	}

	/**/
	template< typename IN_TYPE > 
	HSmartPointer< IN_TYPE >::HSmartPointer( const HS32 in_null )
	: m_data( HNULL )
	{
		HCOMMON_ASSERT( HNULL == in_null, "non null in null constructor" );
		return;
	}

	/**/
	template< typename IN_TYPE > 
	HSmartPointer< IN_TYPE >::HSmartPointer()
	: m_data( HNULL )
	{
		return;
	}

	/**/
	template< typename IN_TYPE > 
	HSmartPointer< IN_TYPE >::~HSmartPointer()
	{
		DecrementReferenceCount();

		return;
	}

	/**/
	template< typename IN_TYPE > 
	const IN_TYPE& HSmartPointer< IN_TYPE >::operator*()const
	{
		HCOMMON_ASSERT( HNULL != m_data, "dereference null smart pointer" );

		return( *m_data );
	}

	/**/
	template< typename IN_TYPE > 
	IN_TYPE& HSmartPointer< IN_TYPE >::operator*()
	{
		HCOMMON_ASSERT( HNULL != m_data, "dereference null smart pointer" );

		return( *m_data );
	}

	/**/
	template< typename IN_TYPE > 
	const IN_TYPE* HSmartPointer< IN_TYPE >::operator ->()const
	{
		HCOMMON_ASSERT( HNULL != m_data, "dereference null smart pointer" );

		return m_data;
	}

	/**/
	template< typename IN_TYPE > 
	IN_TYPE* HSmartPointer< IN_TYPE >::operator ->()
	{
		HCOMMON_ASSERT( HNULL != m_data, "dereference null smart pointer" );

		return m_data;
	}

	/**/
	template< typename IN_TYPE > 
	const IN_TYPE* HSmartPointer< IN_TYPE >::RawGet()const
	{
		return m_data;
	}

	/**/
	template< typename IN_TYPE > 
	IN_TYPE* HSmartPointer< IN_TYPE >::RawGet()
	{
		return m_data;
	}

	/**/
	template< typename IN_TYPE > 
	const HSmartPointer< IN_TYPE >& HSmartPointer<IN_TYPE>::operator =( const HSmartPointer< IN_TYPE >& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			DecrementReferenceCount();
			m_data = in_rhs.m_data;
			IncrementReferenceCount();
		}

		return( *this );
	}

	/**/
	template< typename IN_TYPE > 
	const HSmartPointer< IN_TYPE >& HSmartPointer<IN_TYPE>::operator =( IN_TYPE* in_rhs )
	{
		if( m_data != in_rhs )
		{
			DecrementReferenceCount();
			m_data = in_rhs;
			IncrementReferenceCount();
		}

		return( *this );
	}

	/**/
	template< typename IN_TYPE > 
	const HSmartPointer< IN_TYPE >& HSmartPointer<IN_TYPE>::operator =( const HS32 in_rhs )
	{
		HCOMMON_ASSERT( HNULL == in_rhs, "HNULL assignment with non null" );

		if( HNULL != m_data )
		{
			DecrementReferenceCount();
			m_data = HNULL;
		}

		return( *this );
	}

	//////////////////////////////////////////////////////
	// public methods
	/**/
	template< typename IN_TYPE > 
	HVOID HSmartPointer< IN_TYPE >::Create()
	{
		//assign ourselves to HNULL
		( *this ) = HNULL;

		//create new reference
		IN_TYPE* pNewObject = HNULL;

		HCOMMON_NEW( pNewObject, IN_TYPE );

		( *this ) = pNewObject;

		return;
	}

	/**/
	template< typename IN_TYPE > 
	HVOID HSmartPointer< IN_TYPE >::CreateCopy( const IN_TYPE& in_src )
	{
		//assign ourselves to HNULL
		( *this ) = HNULL;

		//create new reference
		IN_TYPE* pNewObject = HNULL;

		HCOMMON_NEW_PARAM( pNewObject, IN_TYPE, in_src );

		( *this ) = pNewObject;

		return;
	}

	/**/
	template< typename IN_TYPE > 
	HVOID HSmartPointer< IN_TYPE >::Destroy()
	{
		//assign ourselves to HNULL
		( *this ) = HNULL;

		////Destroy if we are the only owner
		//DecrementReferenceCount();
		//if( HNULL != m_data )
		//{
		//	//not the only owner, restore count
		//	IncrementReferenceCount();
		//}

		return;
	}

	//////////////////////////////////////////////////////
	// private methods

	/**/
	template< typename IN_TYPE > 
	HVOID HSmartPointer< IN_TYPE >::IncrementReferenceCount()
	{
		if( HNULL != m_data )
		{
			m_data->RefereceCountGet().Increment();
		}

		return;
	}

	/**/
	template< typename IN_TYPE > 
	HVOID HSmartPointer< IN_TYPE >::DecrementReferenceCount()
	{
		if( HNULL != m_data )
		{
			m_data->RefereceCountGet().Decrement();
			if( true == m_data->RefereceCountGet().ZeroReferenceTest() )
			{
				//TODO: swap over to deleteThis?, don't know what memory context created the smart pointer -david
				HCOMMON_DELETE( m_data, IN_TYPE );
			}
		}

		return;
	}

	/**/
};

#endif // _H_SMART_POINTER_H_