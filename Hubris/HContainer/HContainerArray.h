//file: Hubris/HContainer/HContainerArray.h
#ifndef _H_CONTAINER_ARRAY_H_
#define _H_CONTAINER_ARRAY_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonForEach.h"
#include "Hubris/HContainer/HContainerArrayIterator.h"
#include "Hubris/HContainer/HContainerArrayBool.h"
#include <vector>

/*
contain dynamic array of items, oblige items to be assignable
*/
namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray
	{
		///////////////////////////////////////////////////////////
		// typedef
	public:
		typedef HContainerArrayIterator< IN_TYPE >TIterator;
		typedef HContainerArray< IN_TYPE >TContainer;
		typedef IN_TYPE TType;
	private:
		typedef std::vector< IN_TYPE >TImplementationVector;
		
		///////////////////////////////////////////////////////////
		// creation
	public:
		HContainerArray( const TIterator& in_insertStart, const TIterator& in_insertEnd );
		HContainerArray( const HContainerArray& in_src );
		HContainerArray();
		~HContainerArray();

		///////////////////////////////////////////////////////////
		// operators
	public:
		HContainerArray& operator =( const HContainerArray& in_rhs );
		const HBOOL operator ==( const HContainerArray& in_rhs ) const;
		const HBOOL operator !=( const HContainerArray& in_rhs ) const;
		const HBOOL operator <( const HContainerArray& in_rhs )const;
		HContainerArray& operator +=( const HContainerArray& in_rhs );

		const IN_TYPE& operator[]( const HSINT in_index ) const;
		IN_TYPE& operator[]( const HSINT in_index );

		///////////////////////////////////////////////////////////
		// accessors
	public:
		HSINT SizeGet()const;
		//change array size without concern of preserving contents
		HSINT SizeSet( const HSINT in_size );
		//change array size preserving contents
		HSINT SizeResize( const HSINT in_size );
		//release memory
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
		TImplementationVector m_data;

	};

	/**/
	template< typename IN_TYPE >
	HContainerArray< IN_TYPE >::HContainerArray( const TIterator& in_insertStart, const TIterator& in_insertEnd ) 
	: m_data()
	{
		Insert( in_insertStart, in_insertEnd, End() );

		return;
	}

	/**/
	template <typename IN_TYPE>
	HContainerArray<IN_TYPE>::HContainerArray( const HContainerArray& in_src )
	: m_data()
	{
		( *this ) = in_src;

		return;
	}

	/**/
	template <typename IN_TYPE>
	HContainerArray<IN_TYPE>::HContainerArray()
	: m_data()
	{
		return;
	}

	/**/
	template <typename IN_TYPE>
	HContainerArray<IN_TYPE>::~HContainerArray()
	{
		m_data.clear();
		return;
	}

	/**/
	template <typename IN_TYPE>
	HContainerArray<IN_TYPE>& HContainerArray<IN_TYPE>::operator =( const HContainerArray& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_data = in_rhs.m_data;
		}

		return( *this );
	}

	/**/
	template <typename IN_TYPE>
	const HBOOL HContainerArray<IN_TYPE>::operator ==( const HContainerArray& in_rhs ) const
	{		
		HBOOL match = HTRUE;

		if( this != &in_rhs )
		{
			match = match && ( m_data == in_rhs.m_data );
		}

		return match;
	}

	/**/
	template <typename IN_TYPE>
	const HBOOL HContainerArray<IN_TYPE>::operator !=( const HContainerArray& in_rhs )const
	{		
		return!( operator==( in_rhs ) );
	}

	/**/
	template <typename IN_TYPE>
	const HBOOL HContainerArray<IN_TYPE>::operator<( const HContainerArray& in_rhs )const
	{
		return( m_data < in_rhs.m_data );
	}

	/**/
	template <typename IN_TYPE>
	HContainerArray<IN_TYPE>& HContainerArray<IN_TYPE>::operator +=( const HContainerArray& in_rhs )
	{
		Insert( in_rhs.Begin(), in_rhs.End(), End() );
		return( *this );
	}

	/**/
	template <typename IN_TYPE>
	const IN_TYPE& HContainerArray<IN_TYPE>::operator[]( const HSINT in_index )const
	{
		return m_data[ in_index ];
	}

	/**/
	template <typename IN_TYPE>
	IN_TYPE& HContainerArray<IN_TYPE>::operator[]( const HSINT in_index )
	{
		return m_data[ in_index ];
	}

	///////////////////////////////////////////////////////////
	// accessors
	/**/
	template <typename IN_TYPE>
	HSINT HContainerArray<IN_TYPE>::SizeGet()const
	{
		return m_data.size();
	}

	/**/
	template <typename IN_TYPE>
	HSINT HContainerArray<IN_TYPE>::SizeSet( const HSINT in_size )
	{
		Clear();
		SizeResize( in_size );
		return SizeGet();
	}

	/**/
	template <typename IN_TYPE>
	HSINT HContainerArray<IN_TYPE>::SizeResize( const HSINT in_size )
	{
		m_data.resize( in_size );
		return SizeGet();
	}

	/**/
	template <typename IN_TYPE>
	HVOID HContainerArray<IN_TYPE>::Clear()
	{
		m_data.clear();
		return;
	}

	/**/
	template <typename IN_TYPE>
	const typename HContainerArray<IN_TYPE>::TIterator HContainerArray<IN_TYPE>::Begin() const
	{
		//this is the cost of not having iter and const_iter, weak obligation to return const iterator not to change container
		//return TIterator( ( ( HContainerArray<IN_TYPE>& ) *this ).m_data.begin() );
		return TIterator( ( HContainerArray<IN_TYPE>& )( *this ), 0 );
	}

	/**/
	template <typename IN_TYPE>
	typename HContainerArray<IN_TYPE>::TIterator HContainerArray<IN_TYPE>::Begin()
	{
		//return TIterator( m_data.begin() );
		return TIterator( ( *this ), 0 );
	}

	/**/
	template <typename IN_TYPE>
	const typename HContainerArray<IN_TYPE>::TIterator HContainerArray<IN_TYPE>::End() const
	{
		//return TIterator( ( ( HContainerArray<IN_TYPE>& ) *this ).m_data.end() );
		return TIterator( ( HContainerArray<IN_TYPE>& )( *this ), SizeGet() );
	}

	/**/
	template <typename IN_TYPE>
	typename HContainerArray<IN_TYPE>::TIterator HContainerArray<IN_TYPE>::End()
	{
		//return TIterator( m_data.end() );
		return TIterator( *this, SizeGet() );
	}

	/**/
	template <typename IN_TYPE>
	HVOID HContainerArray<IN_TYPE>::Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd )
	{
		Insert( in_insertStart, in_insertEnd, End() );
		return;
	}

	/**/
	template <typename IN_TYPE>
	HVOID HContainerArray<IN_TYPE>::Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where )
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
			HCOMMON_FOR_EACH_RANGE_CONST( data, HContainerArray<IN_TYPE>, in_insertStart, in_insertEnd )
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

		HCOMMON_FOR_EACH_RANGE_CONST( data, HContainerArray<IN_TYPE>, in_insertStart, in_insertEnd )
		{
			m_data[ trace + insertSpace ] = m_data[ trace ];
			m_data[ trace ] = data;
			++trace;
		}

		return;
	}

	/**/
	template <typename IN_TYPE>
	HVOID HContainerArray<IN_TYPE>::Insert( const IN_TYPE& in_data, const TIterator& in_where )
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
	template <typename IN_TYPE>
	HVOID HContainerArray<IN_TYPE>::Insert( const IN_TYPE& in_data )
	{
		m_data.push_back( in_data );

		return;
	}

	/**/
	template <typename IN_TYPE>
	HVOID HContainerArray<IN_TYPE>::Remove( const TIterator& in_start, const TIterator& in_end )
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
	template <typename IN_TYPE>
	typename HContainerArray<IN_TYPE>::TIterator HContainerArray<IN_TYPE>::Remove( const TIterator& in_where )
	{
		Remove( in_where, in_where + 1 );

		return( in_where - 1 );
	}

	/**/

};

#endif// _H_CONTAINER_H_
