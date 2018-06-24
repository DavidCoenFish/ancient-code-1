//file: Hubris/HContainer/HContainerStaticArrayIterator.h
#ifndef _H_CONTAINER_STATIC_ARRAY_ITERATOR_H_
#define _H_CONTAINER_STATIC_ARRAY_ITERATOR_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"

/*
contain dynamic array of items, oblige items to be assignable
*/
namespace Hubris
{
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > class HContainerStaticArray;

	//it is not nice to lie about the constness of owner ( overloaded constructor )
	// but this and mutable members where concessions to make a const iterator function
	// a const iterator can still read and increment
	// a non const iterator can write value as well

	//try to treat as ifit was just a pointer
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > class HContainerStaticArrayIterator
	{
		////////////////////////////////////////
		// typedef
	private:
		typedef HContainerStaticArray< IN_TYPE, IN_MAXIMUM_SIZE >TContainerArray;

		////////////////////////////////////////
		// creation
	public:
		HContainerStaticArrayIterator( TContainerArray& in_owner, const Hubris::HSINT in_index );
		HContainerStaticArrayIterator( const HContainerStaticArrayIterator& in_src );
		~HContainerStaticArrayIterator();

		////////////////////////////////////////
		// operator
	public:
		const IN_TYPE& operator*()const;
		IN_TYPE& operator*();

		const IN_TYPE* operator->()const;
		IN_TYPE* operator->();

		//preincrement the iterator
		const HContainerStaticArrayIterator &operator++()const;
		//postincrement the iterator
		const HContainerStaticArrayIterator operator++( HS32 )const;
		//predecrement the iterator
		const HContainerStaticArrayIterator &operator--()const;
		//postdecrement the iterator
		const HContainerStaticArrayIterator operator--( HS32 )const;

		const HContainerStaticArrayIterator &operator+=( const HS32 in_offset )const;
		const HContainerStaticArrayIterator operator+( const HS32 in_offset )const;

		const HContainerStaticArrayIterator &operator-=( const HS32 in_offset )const;
		const HContainerStaticArrayIterator operator-( const HS32 in_offset )const;

		HS32 operator-( const HContainerStaticArrayIterator & in_rhs )const;
		
		const HContainerStaticArrayIterator& operator=( const HContainerStaticArrayIterator & in_rhs )const;

		HBOOL operator==( const HContainerStaticArrayIterator & in_rhs )const;
		HBOOL operator!=( const HContainerStaticArrayIterator & in_rhs )const;
		HBOOL operator<( const HContainerStaticArrayIterator & in_rhs )const;

		const Hubris::HSINT IndexGet()const{ return m_index; }
		////////////////////////////////////////
		// private member
	private:
		TContainerArray& m_owner;
		mutable Hubris::HSINT m_index;

	};

	////////////////////////////////////////
	// creation
	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::HContainerStaticArrayIterator( TContainerArray& in_owner, const Hubris::HSINT in_index )
	: m_owner( in_owner )
	, m_index( in_index )
	{
		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE >
	HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::HContainerStaticArrayIterator( const HContainerStaticArrayIterator& in_src )
	: m_owner( ( TContainerArray& )in_src.m_owner )
	, m_index( in_src.m_index )
	{
		return;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::~HContainerStaticArrayIterator()
	{
		return;
	}

	////////////////////////////////////////
	// operator
	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const IN_TYPE& HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator*()const
	{
		return m_owner[ m_index ];
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	IN_TYPE& HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator*()
	{
		return m_owner[ m_index ];
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const IN_TYPE* HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator->()const
	{
		return &( m_owner[ m_index ] );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	IN_TYPE* HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator->()
	{
		return &( m_owner[ m_index ] );
	}

	//preincrement the iterator
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >& HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator++()const
	{
		++m_index;
		return( *this );
	}

	//postincrement the iterator
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE > HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator++( HS32 )const
	{
		HContainerStaticArrayIterator returnIterator( *this );
		++m_index;
		return returnIterator;
	}

	//predecrement the iterator
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >& HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator--()const
	{
		--m_index;
		return( *this );
	}

	//postdecrement the iterator
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE > HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator--( HS32 )const
	{
		HContainerStaticArrayIterator returnIterator( m_iterator );
		--m_index;
		return returnIterator;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >& HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator+=( const HS32 in_offset )const
	{
		m_index += in_offset;
		return( *this );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE > HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator+( const HS32 in_offset )const
	{
		HContainerStaticArrayIterator returnIterator( m_owner, m_index + in_offset );
		return returnIterator;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >& HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator-=( const HS32 in_offset )const
	{
		m_index -= in_offset;
		return( *this );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE > HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator-( const HS32 in_offset )const
	{
		HContainerStaticArrayIterator returnIterator( m_owner, m_index - in_offset );
		return returnIterator;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	HS32 HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator-( const HContainerStaticArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no operators between different array iterators" );
		return m_index - in_rhs.m_index;
	}
	
	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	const HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >& HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator=( const HContainerStaticArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no assignmnet between different array iterators" );
		if( ( *this ) != in_rhs ) 
		{
			m_index = in_rhs.m_index;
		}
		return( *this );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	HBOOL HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator==( const HContainerStaticArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no cmp between different array iterators" );
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match &= ( m_index == in_rhs.m_index );
		}

		return match;
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	HBOOL HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator!=( const HContainerStaticArrayIterator & in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	/**/
	template < typename IN_TYPE, HSINT IN_MAXIMUM_SIZE > 
	HBOOL HContainerStaticArrayIterator< IN_TYPE, IN_MAXIMUM_SIZE >::operator<( const HContainerStaticArrayIterator & in_rhs )const
	{
		HCOMMON_ASSERT( &m_owner == &in_rhs.m_owner, "no cmp between different array iterators" );
		return( m_index < in_rhs.m_index );
	}

	/**/
};

/**/
#endif// _H_CONTAINER_STATIC_ARRAY_ITERATOR_H_
