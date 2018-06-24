//file: Hubris/HContainer/HContainerArrayIterator.h
#ifndef _H_CONTAINER_ARRAY_ITERATOR_H_
#define _H_CONTAINER_ARRAY_ITERATOR_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"

/*
contain dynamic array of items, oblige items to be assignable
*/
namespace Hubris
{
	template <typename IN_TYPE> class HContainerArray;

	//it is not nice to lie about the constness of owner ( overloaded constructor )
	// but this and mutable members where concessions to make a const iterator function
	// a const iterator can still read and increment
	// a non const iterator can write value as well

	//try to treat as ifit was just a pointer
	template <typename IN_TYPE> class HContainerArrayIterator
	{
		////////////////////////////////////////
		// typedef
	private:
		typedef HContainerArray< IN_TYPE >TContainerArray;
		//typedef std::vector< IN_TYPE >TImplementationVector;
		//typedef typename std::vector< IN_TYPE >::iterator TImplementationIterator;

		////////////////////////////////////////
		// creation
	public:
		HContainerArrayIterator( TContainerArray& in_owner, const Hubris::HSINT in_index );
		HContainerArrayIterator( const HContainerArrayIterator& in_src );
		~HContainerArrayIterator();

		////////////////////////////////////////
		// operator
	public:
		const IN_TYPE& operator*()const;
		IN_TYPE& operator*();

		const IN_TYPE* operator->()const;
		IN_TYPE* operator->();

		//preincrement the iterator
		const HContainerArrayIterator &operator++()const;
		//postincrement the iterator
		const HContainerArrayIterator operator++( HS32 )const;
		//predecrement the iterator
		const HContainerArrayIterator &operator--()const;
		//postdecrement the iterator
		const HContainerArrayIterator operator--( HS32 )const;

		const HContainerArrayIterator &operator+=( const HS32 in_offset )const;
		const HContainerArrayIterator operator+( const HS32 in_offset )const;

		const HContainerArrayIterator &operator-=( const HS32 in_offset )const;
		const HContainerArrayIterator operator-( const HS32 in_offset )const;

		HS32 operator-( const HContainerArrayIterator & in_rhs )const;
		
		const HContainerArrayIterator& operator=( const HContainerArrayIterator & in_rhs )const;

		HBOOL operator==( const HContainerArrayIterator & in_rhs )const;
		HBOOL operator!=( const HContainerArrayIterator & in_rhs )const;
		HBOOL operator<( const HContainerArrayIterator & in_rhs )const;

		const Hubris::HSINT IndexGet()const{ return m_index; }
		////////////////////////////////////////
		// private member
	private:
		TContainerArray& m_owner;
		mutable Hubris::HSINT m_index;
		
		//mutable TImplementationIterator m_iterator;

	};

	////////////////////////////////////////
	// creation
	/**/
	template <typename IN_TYPE> 
	HContainerArrayIterator< IN_TYPE >::HContainerArrayIterator( TContainerArray& in_owner, const Hubris::HSINT in_index )
	: m_owner( in_owner )
	, m_index( in_index )
	{
		return;
	}

	/**/
	template <typename IN_TYPE>
	HContainerArrayIterator< IN_TYPE >::HContainerArrayIterator( const HContainerArrayIterator& in_src )
	: m_owner( ( TContainerArray& )in_src.m_owner )
	, m_index( in_src.m_index )
	{
		return;
	}

	/**/
	template <typename IN_TYPE> 
	HContainerArrayIterator< IN_TYPE >::~HContainerArrayIterator()
	{
		return;
	}

	////////////////////////////////////////
	// operator
	/**/
	template <typename IN_TYPE> 
	const IN_TYPE& HContainerArrayIterator< IN_TYPE >::operator*()const
	{
		return m_owner[ m_index ];
	}

	/**/
	template <typename IN_TYPE> 
	IN_TYPE& HContainerArrayIterator< IN_TYPE >::operator*()
	{
		return m_owner[ m_index ];
	}

	/**/
	template <typename IN_TYPE> 
	const IN_TYPE* HContainerArrayIterator< IN_TYPE >::operator->()const
	{
		return &( m_owner[ m_index ] );
	}

	/**/
	template <typename IN_TYPE> 
	IN_TYPE* HContainerArrayIterator< IN_TYPE >::operator->()
	{
		return &( m_owner[ m_index ] );
	}

	//preincrement the iterator
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE >& HContainerArrayIterator< IN_TYPE >::operator++()const
	{
		++m_index;
		return( *this );
	}

	//postincrement the iterator
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE > HContainerArrayIterator< IN_TYPE >::operator++( HS32 )const
	{
		HContainerArrayIterator returnIterator( *this );
		++m_index;
		return returnIterator;
	}

	//predecrement the iterator
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE >& HContainerArrayIterator< IN_TYPE >::operator--()const
	{
		--m_index;
		return( *this );
	}

	//postdecrement the iterator
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE > HContainerArrayIterator< IN_TYPE >::operator--( HS32 )const
	{
		HContainerArrayIterator returnIterator( m_iterator );
		--m_index;
		return returnIterator;
	}

	/**/
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE >& HContainerArrayIterator< IN_TYPE >::operator+=( const HS32 in_offset )const
	{
		m_index += in_offset;
		return( *this );
	}

	/**/
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE > HContainerArrayIterator< IN_TYPE >::operator+( const HS32 in_offset )const
	{
		HContainerArrayIterator returnIterator( m_owner, m_index + in_offset );
		return returnIterator;
	}

	/**/
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE >& HContainerArrayIterator< IN_TYPE >::operator-=( const HS32 in_offset )const
	{
		m_index -= in_offset;
		return( *this );
	}

	/**/
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE > HContainerArrayIterator< IN_TYPE >::operator-( const HS32 in_offset )const
	{
		HContainerArrayIterator returnIterator( m_owner, m_index - in_offset );
		return returnIterator;
	}

	/**/
	template <typename IN_TYPE> 
	HS32 HContainerArrayIterator< IN_TYPE >::operator-( const HContainerArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no operators between array iterators" );
		return m_index - in_rhs.m_index;
	}
	
	/**/
	template <typename IN_TYPE> 
	const HContainerArrayIterator< IN_TYPE >& HContainerArrayIterator< IN_TYPE >::operator=( const HContainerArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no assignmnet between array iterators" );
		if( ( *this ) != in_rhs ) 
		{
			m_index = in_rhs.m_index;
		}
		return( *this );
	}

	/**/
	template <typename IN_TYPE> 
	HBOOL HContainerArrayIterator< IN_TYPE >::operator==( const HContainerArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no cmp between array iterators" );
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match &= ( m_index == in_rhs.m_index );
		}

		return match;
	}

	/**/
	template <typename IN_TYPE> 
	HBOOL HContainerArrayIterator< IN_TYPE >::operator!=( const HContainerArrayIterator & in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	/**/
	template <typename IN_TYPE> 
	HBOOL HContainerArrayIterator< IN_TYPE >::operator<( const HContainerArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no cmp between array iterators" );
		return( m_index < in_rhs.m_index );
	}

	/**/
};

/**/
#endif// _H_CONTAINER_ARRAY_ITERATOR_H_
