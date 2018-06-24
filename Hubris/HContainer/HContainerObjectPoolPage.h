//file: Hubris/HContainer/HContainerObjectPoolPage.h
#ifndef _H_CONTAINER_OBJECT_POOL_PAGE_H_
#define _H_CONTAINER_OBJECT_POOL_PAGE_H_

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonLowestBit.h"

namespace Hubris
{
	template <typename IN_CLASS> class HContainerObjectPoolPage
	{
		/////////////////////////////////////////////////////////////////
		// creation
	public:
		HContainerObjectPoolPage( HContainerObjectPoolPage *& in_next );
		~HContainerObjectPoolPage();

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		//get an item, else Create a new page and ask for an item from it
		IN_CLASS* ItemCreate( HContainerObjectPoolPage*& in_prevNext );
		//mark item as free if it is in our address page, else pass on the free, if the entire page is free-ed, delete page
		HBOOL ItemRelease( const IN_CLASS * const in_item, HContainerObjectPoolPage *& in_prevNext );
		//! get the index of a item
		HSINT ItemIndexGet( const IN_CLASS& in_item, HSINT& in_out_index )const;
		//! get the item at an index
		const IN_CLASS* ItemGet( HSINT& in_out_index )const;
		IN_CLASS* ItemGet( HSINT& in_out_index );

		//release all used items, call clear on next page
		HVOID Clear();

		/////////////////////////////////////////////////////////////////
		// private methods
	private:
		//release the item at index
		HVOID Release( const HS32 in_index );

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		HContainerObjectPoolPage( const HContainerObjectPoolPage & in_src );
		const HContainerObjectPoolPage& operator =( const HContainerObjectPoolPage & in_src );

		/////////////////////////////////////////////////////////////////
		// private Members
	private:
		static const HU32 s_flagDefault = 0xFFFFFFFF;
		static const HS32 s_bitCount = 32; 

		HContainerObjectPoolPage* m_next;
		IN_CLASS m_data[ s_bitCount ]; //thinking about making this an array
		HU32 m_flag;

	};

	/**/
	template< typename IN_CLASS > 
	HContainerObjectPoolPage< IN_CLASS >::HContainerObjectPoolPage( HContainerObjectPoolPage*& in_next ) 
	: m_next( in_next )
	, m_flag( s_flagDefault )
	{
		in_next = this;
		return;
	}

	/**/
	template< typename IN_CLASS > 
	HContainerObjectPoolPage< IN_CLASS >::~HContainerObjectPoolPage()
	{
		if( HNULL != m_next) 
		{
			HCOMMON_DELETE( m_next, HContainerObjectPoolPage );
		}

		return;
	}

	/*get an item, else Create a new page and ask for an item from it */
	template< typename IN_CLASS > 
	IN_CLASS* HContainerObjectPoolPage< IN_CLASS >::ItemCreate( HContainerObjectPoolPage*& in_prevNext )
	{
		HS32 lowestBit = HCOMMON_LOWEST_BIT32( m_flag );

		if( HCOMMON_INVALID_INDEX == lowestBit ) // no items left unused on this page, make new page
		{
			HContainerObjectPoolPage* newPage = HNULL;
			HCOMMON_NEW_PARAM( newPage, HContainerObjectPoolPage, in_prevNext );

			if( HNULL != newPage )
			{
				return newPage->ItemCreate( m_next );
			}
		}
		else
		{
			m_flag &= ( ~( HCOMMON_INDEX_TO_FLAG( lowestBit ) ) );
			m_data[ lowestBit ] = IN_CLASS(); //HTraitEmpty< IN_CLASS >::EmptyGet();
			return &m_data[ lowestBit ];
		}

		return HNULL;
	}

	/* mark item as free if it is in our address page, else pass on the free, if the entire page is free-ed, delete page */
	template< typename IN_CLASS > 
	HBOOL HContainerObjectPoolPage< IN_CLASS >::ItemRelease( const IN_CLASS* const in_item, HContainerObjectPoolPage*& in_prevNext )
	{
		const HS32 index = ( const HS32 )( in_item - ( &m_data[ 0 ] ) );
		//could item be in this pages array
		if( ( 0 <= index ) && ( index < s_bitCount ) )
		{
			Release( index );

			if( s_flagDefault == m_flag ) // all items released
			{
				in_prevNext = m_next;
				m_next = HNULL;
				delete this;
			}

			return HTRUE;
		}
		else if( HNULL != m_next )
		{
			return m_next->ItemRelease( in_item, m_next );
		}

		return HFALSE;
	}

	/**/
	template< typename IN_CLASS > 
	HSINT HContainerObjectPoolPage< IN_CLASS >::ItemIndexGet( const IN_CLASS& in_item, HSINT& in_out_trace )const
	{
		HSINT returnValue = HCOMMON_INVALID_INDEX;
		if( HNULL != m_next )
		{
			returnValue = m_next->ItemIndexGet( in_item, in_out_trace ); 
			if( HCOMMON_INVALID_INDEX != returnValue )
			{
				return returnValue;
			}
		}

		for( HSINT index = 0; index < s_bitCount; ++index )
		{
			//check use flag in use
			if( 0 != ( m_flag & HCOMMON_INDEX_TO_FLAG( index ) ) )
			{
				continue;
			}
			else if( &in_item == &m_data[ index ] )
			{
				returnValue = in_out_trace;
				break;
			}

			in_out_trace += 1;
		}

		return returnValue;
	}

	/**/
	template< typename IN_CLASS > 
	const IN_CLASS* HContainerObjectPoolPage< IN_CLASS >::ItemGet( HSINT& in_out_trace  )const
	{
		const IN_CLASS* returnValue = HNULL;
		if( HNULL != m_next )
		{
			returnValue = m_next->ItemGet( in_out_trace ); 
			if( HNULL != returnValue )
			{
				return returnValue;
			}
		}

		for( HSINT index = 0; index < s_bitCount; ++index )
		{
			//check item in use
			if( 0 != ( m_flag & HCOMMON_INDEX_TO_FLAG( index ) ) )
			{
				continue;
			}
			else if( 0 == in_out_trace )
			{
				returnValue = &m_data[ index ];
				break;
			}

			in_out_trace -= 1;
		}

		return returnValue;
	}

	/**/
	template< typename IN_CLASS > 
	IN_CLASS* HContainerObjectPoolPage< IN_CLASS >::ItemGet( HSINT& in_out_trace  )
	{
		IN_CLASS* returnValue = HNULL;
		if( HNULL != m_next )
		{
			returnValue = m_next->ItemGet( in_out_trace ); 
			if( HNULL != returnValue )
			{
				return returnValue;
			}
		}

		for( HSINT index = 0; index < s_bitCount; ++index )
		{
			if( 0 != ( m_flag & HCOMMON_INDEX_TO_FLAG( index ) ) )
			{
				continue;
			}
			else if( 0 == in_out_trace )
			{
				returnValue = &m_data[ index ];
				break;
			}

			in_out_trace -= 1;
		}

		return returnValue;
	}

	/**/
	template< typename IN_CLASS > 
	HVOID HContainerObjectPoolPage< IN_CLASS >::Clear()
	{
		if( s_flagDefault != m_flag )
		{
			for( HS32 index = 0; index < s_bitCount; ++index )
			{
				if( 0 == ( m_flag & HCOMMON_INDEX_TO_FLAG( index )  ) )
				{
					m_data[ index ] = HTraitEmpty< IN_CLASS >::EmptyGet();
				}
			}

			m_flag = s_flagDefault;
		}

		if( HNULL != m_next )
		{
			m_next->Clear();
		}

		return;
	}

	/* release the item at index */
	template< typename IN_CLASS > 
	HVOID HContainerObjectPoolPage< IN_CLASS >::Release( const HS32 in_index )
	{
		//private function, no range check
		//TODO: if IN_CLASS has unimplemented assignment operator we have a problem
		//m_data[ in_index ] = HTraitEmpty< IN_CLASS >::EMPTY;
		m_flag |= HCOMMON_INDEX_TO_FLAG( in_index ) ;

		return;
	}

	/**/

};




#endif// _H_CONTAINER_OBJECT_POOL_PAGE_H_
