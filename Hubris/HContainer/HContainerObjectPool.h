//file: Hubris/HContainer/HContainerObjectPool.h
#ifndef _H_CONTAINER_OBJECT_POOL_H_
#define _H_CONTAINER_OBJECT_POOL_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HContainer/HContainerObjectPoolPage.h"

namespace Hubris
{
	/**/
	template< typename IN_CLASS >class HContainerObjectPool
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HContainerObjectPoolPage< IN_CLASS > TPage;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		HContainerObjectPool();
		~HContainerObjectPool();

		/////////////////////////////////////////////////////////////////
		// accessors
	public:
		// request an item, 
		IN_CLASS& ItemCreate();
		// release item, item gets marked as unused
		HVOID ItemRelease( const IN_CLASS& in_item );

		HSINT SizeGet()const{ return m_count; }

		// get the index of a item
		HSINT ItemIndexGet( const IN_CLASS& in_item )const;
		// get the item at an index, CAN BE HNULL
		const IN_CLASS& ItemGet( const HSINT in_index )const;
		IN_CLASS& ItemGet( const HSINT in_index );

		//! set all usages to zero, can also free memory
		HVOID Clear( const HBOOL in_freeMemory = HTRUE );

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		HContainerObjectPool( const HContainerObjectPool& in_src );
		const HContainerObjectPool& operator =( const HContainerObjectPool & in_src );

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		TPage* m_firstPage;
		HSINT m_count;

	};

	/**/
	template< typename IN_CLASS > 
	HContainerObjectPool< IN_CLASS >::HContainerObjectPool() 
	: m_firstPage( HNULL )
	, m_count( 0 )
	{
		return;
	}

	/**/
	template< typename IN_CLASS > 
	HContainerObjectPool< IN_CLASS >::~HContainerObjectPool()
	{
		if( HNULL != m_firstPage )
		{
			HCOMMON_DELETE( m_firstPage, TPage );			
		}

		return;
	}

	/**/
	template< typename IN_CLASS >
	IN_CLASS& HContainerObjectPool< IN_CLASS >::ItemCreate()
	{
		m_count += 1;
		IN_CLASS* returnValue = HNULL;

		if( HNULL == m_firstPage )
		{
			TPage* newPage = HNULL;
			HCOMMON_NEW_PARAM( newPage, TPage, m_firstPage );
		}
		
		if( HNULL != m_firstPage )
		{
			returnValue = m_firstPage->ItemCreate( m_firstPage );
		}

		return( *returnValue );
	}

	/**/
	template< typename IN_CLASS > 
	HVOID HContainerObjectPool< IN_CLASS >::ItemRelease( const IN_CLASS& in_item )
	{	
		HBOOL removed = HFALSE;
		if( HNULL != m_firstPage )
		{
			removed = m_firstPage->ItemRelease( &in_item, m_firstPage );
		}

		m_count -= 1;
		HCOMMON_ASSERT( HTRUE == removed, "attempt removal of item which was not found" );

		return;
	}

	/**/
	template< typename IN_CLASS > 
	HSINT HContainerObjectPool< IN_CLASS >::ItemIndexGet( const IN_CLASS& in_item )const
	{
		HSINT index = HCOMMON_INVALID_INDEX;
		if( HNULL != m_firstPage )
		{
			HSINT trace = 0;
			index = m_firstPage->ItemIndexGet( in_item, trace );
		}

		return index;
	}

	/**/
	template< typename IN_CLASS > 
	const IN_CLASS& HContainerObjectPool< IN_CLASS >::ItemGet( const HSINT in_index )const
	{
		const IN_CLASS* returnValue = HNULL;

		if( HNULL != m_firstPage )
		{
			HSINT trace( in_index );
			returnValue = m_firstPage->ItemGet( trace );
		}

		HCOMMON_ASSERT( HNULL != returnValue, "item not found" );

		return( *returnValue );
	}

	/**/
	template< typename IN_CLASS > 
	IN_CLASS& HContainerObjectPool< IN_CLASS >::ItemGet( const HSINT in_index )
	{
		IN_CLASS* returnValue = HNULL;

		if( HNULL != m_firstPage )
		{
			HSINT trace( in_index );
			returnValue = m_firstPage->ItemGet( trace );
		}

		HCOMMON_ASSERT( HNULL != returnValue, "item not found" );

		return( *returnValue );
	}

	/**/
	template< typename IN_CLASS > 
	HVOID HContainerObjectPool< IN_CLASS >::Clear( const HBOOL in_freeMemory )
	{
		if( HNULL != m_firstPage )
		{
			m_count = 0;
			m_firstPage->Clear();

			if( true == in_freeMemory )
			{
				HCOMMON_DELETE( m_firstPage, TPage );
			}
		}

		return;
	}

	/**/

};

#endif// _H_CONTAINER_OBJECT_POOL_H_
