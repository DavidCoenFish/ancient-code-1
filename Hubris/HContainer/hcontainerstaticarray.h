//file: Hubris/HContainer/HContainerStaticArray.h
#ifndef _H_CONTAINER_STATIC_ARRAY_H_
#define _H_CONTAINER_STATIC_ARRAY_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonForEach.h"
#include "Hubris/HContainer/HContainerStaticArrayIterator.h"
#include <vector>

/*
contain maximum fixed size array of items, oblige items to be assignable
*/
namespace Hubris
{
	template< typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >class HContainerStaticArray
	{
		///////////////////////////////////////////////////////////
		// typedef
	public:
		typedef HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >TIterator;
		typedef HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >TContainer;
		typedef IN_TYPE TType;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HContainerStaticArray( const TIterator& in_insertStart, const TIterator& in_insertEnd );
		HContainerStaticArray( const HContainerStaticArray& in_src );
		HContainerStaticArray();
		~HContainerStaticArray();

		///////////////////////////////////////////////////////////
		// operators
	public:
		HContainerStaticArray& operator =( const HContainerStaticArray& in_rhs );
		const HBOOL operator ==( const HContainerStaticArray& in_rhs ) const;
		const HBOOL operator !=( const HContainerStaticArray& in_rhs ) const;
		const HBOOL operator <( const HContainerStaticArray& in_rhs )const;
		HContainerStaticArray& operator +=( const HContainerStaticArray& in_rhs );

		const IN_TYPE& operator[]( const HSINT in_index ) const;
		IN_TYPE& operator[]( const HSINT in_index );

		///////////////////////////////////////////////////////////
		// accessors
	public:
		HSINT MaximumSizeGet()const;

		HSINT SizeGet()const;
		//change array size, assert if over max size
		HSINT SizeResize( const HSINT in_size );
		//set size to zero
		HVOID Clear();

		const TIterator Begin() const;
		TIterator Begin();

		const TIterator End() const;
		TIterator End();

		///////////////////////////////////////////////////////////
		// public methods
	public:
		//for push, pop and back, see HContainerUtility
		//insert at 'where', contents at 'where' are pushed along, if any 
		//HVOID Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where = ( const TIterator& )End() );
		HVOID Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where );
		HVOID Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd );
		HVOID Insert( const IN_TYPE& in_data, const TIterator& in_where );
		HVOID Insert( const IN_TYPE& in_data );

		HVOID Remove( const TIterator& in_start, const TIterator& in_end );
		TIterator Remove( const TIterator& in_where );

		const IN_TYPE* const RawGet()const{ return &m_data[ 0 ]; }

		///////////////////////////////////////////////////////////
		// private members
	private:
		IN_TYPE m_data[ IN_MAXIMUM_SIZE ];
		HSINT m_size; //range [ 0...IN_MAXIMUM_SIZE ]

	};

	/**/
	template< typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::HContainerStaticArray( const TIterator& in_insertStart, const TIterator& in_insertEnd ) 
	: m_size( 0 )
	{
		Insert( in_insertStart, in_insertEnd, End() );

		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::HContainerStaticArray( const HContainerStaticArray& in_src )
	: m_size( 0 )
	{
		( *this ) = in_src;
		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::HContainerStaticArray()
	: m_size( 0 )
	{
		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::~HContainerStaticArray()
	{
		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >& HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::operator =( const HContainerStaticArray& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_size = in_rhs.m_size;
			for( HSINT index = 0; index < m_size; ++index )
			{
				m_data[ index ] = in_rhs.m_data[ index ];
			}
		}

		return( *this );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	const HBOOL HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::operator ==( const HContainerStaticArray& in_rhs ) const
	{		
		HBOOL match = HTRUE;

		if( this != &in_rhs )
		{
			match = match && ( m_size == in_rhs.m_size );
			if( HTRUE == match )
			{
				for( HSINT index = 0; index < m_size; ++index )
				{
					match = match && ( m_data[ index ] == in_rhs.m_data[ index ] );
				}
			}
		}

		return match;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	const HBOOL HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::operator !=( const HContainerStaticArray& in_rhs )const
	{		
		return!( operator==( in_rhs ) );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	const HBOOL HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::operator<( const HContainerStaticArray& in_rhs )const
	{
		//return( m_data < in_rhs.m_data );
		if( m_size != in_rhs.m_size )
		{
			return( m_size < in_rhs.m_size );
		}
		for( HSINT index = 0; index < m_size; ++index )
		{
			if( m_data[ index ] != in_rhs.m_data[ index ] )
			{
				return( m_data[ index ] < in_rhs.in_rhs.m_data[ index ] );
			}
		}

		return HFALSE;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >& HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::operator +=( const HContainerStaticArray& in_rhs )
	{
		Insert( in_rhs.Begin(), in_rhs.End(), End() );
		return( *this );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	const IN_TYPE& HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::operator[]( const HSINT in_index )const
	{
		return m_data[ in_index ];
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	IN_TYPE& HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::operator[]( const HSINT in_index )
	{
		return m_data[ in_index ];
	}

	///////////////////////////////////////////////////////////
	// accessors
	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HSINT HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::MaximumSizeGet()const
	{
		return m_size;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HSINT HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::SizeGet()const
	{
		return m_size;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HSINT HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::SizeResize( const HSINT in_size )
	{
		HCOMMON_ASSERT( m_size < IN_MAXIMUM_SIZE, "invalid size" );
		m_size = in_size;
		return SizeGet();
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HVOID HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Clear()
	{
		m_size = 0;
		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	const typename HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::TIterator HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Begin() const
	{
		//this is the cost of not having iter and const_iter, weak obligation to return const iterator not to change container
		//return TIterator( ( ( HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >& ) *this ).m_data.begin() );
		return TIterator( ( HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >& )( *this ), 0 );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	typename HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::TIterator HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Begin()
	{
		//return TIterator( m_data.begin() );
		return TIterator( ( *this ), 0 );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	const typename HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::TIterator HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::End() const
	{
		return TIterator( ( HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >& )( *this ), SizeGet() );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	typename HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::TIterator HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::End()
	{
		//return TIterator( m_data.end() );
		return TIterator( *this, SizeGet() );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HVOID HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd )
	{
		Insert( in_insertStart, in_insertEnd, End() );
		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HVOID HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where )
	{
		const HSINT insertSpace = in_insertEnd - in_insertStart;
		if( 0 == insertSpace )
		{
			return;
		}

		if( ( 0 == SizeGet() ) || ( in_where == End() ) )
		{
			HSINT trace = SizeGet();
			SizeResize( trace + insertSpace );
			HCOMMON_FOR_EACH_RANGE_CONST( data, TContainer, in_insertStart, in_insertEnd )
			{
				m_data[ trace ] = data;
				++trace;
			}
			return;
		}

		//hmmn, if in_where is not in array this could go BOOM
		HSINT trace = in_where - Begin();
		HCOMMON_ASSERT( ( 0 <= trace ) && ( trace <= SizeGet() ), "where is out of range" );

		SizeResize( SizeGet() + insertSpace );

		HCOMMON_FOR_EACH_RANGE_CONST( data, TContainer, in_insertStart, in_insertEnd )
		{
			m_data[ trace + insertSpace ] = m_data[ trace ];
			m_data[ trace ] = data;
			++trace;
		}

		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HVOID HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Insert( const IN_TYPE& in_data, const TIterator& in_where )
	{
		if( ( 0 == SizeGet() ) || ( in_where == End() ) )
		{
			Insert( in_data );
		}
		else
		{
			SizeResize( SizeGet() + 1 );
			TIterator trace = End() - 1;
			do
			{
				TIterator oldTrace( trace );
				--trace;
				( *oldTrace ) = ( *trace );
			}
			while( ( trace != in_where ) && ( trace != Begin() ) );

			( *trace ) = in_data;
		}

		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HVOID HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Insert( const IN_TYPE& in_data )
	{
		HCOMMON_ASSERT( ( m_size ) < IN_MAXIMUM_SIZE, "attempt to insert too many items into static array" );

		m_data[ m_size ] = in_data;
		m_size += 1;

		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HVOID HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Remove( const TIterator& in_start, const TIterator& in_end )
	{
		const HSINT removeCount = in_end - in_start;
		for( TIterator iter = in_start; iter != End() - removeCount; ++iter )
		{
			( *iter ) = ( *( iter + removeCount ) );
		}

		SizeResize( SizeGet() - removeCount );

		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	typename HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::TIterator HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >::Remove( const TIterator& in_where )
	{
		Remove( in_where, in_where + 1 );

		return( in_where - 1 );
	}

	/**/

};

#endif// _H_CONTAINER_STATIC_ARRAY_H_
