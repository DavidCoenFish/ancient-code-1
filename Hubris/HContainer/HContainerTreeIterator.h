//file: Hubris/HContainer/HContainerTreeIterator.h
#ifndef _H_CONTAINER_TREE_ITERATOR_H_
#define _H_CONTAINER_TREE_ITERATOR_H_

/**/
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonType.h"
#include< map >
/**/
namespace Hubris
{
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> class HContainerTree;

	//it is not nice to lie about the constness of owner (overloaded constructor)
	// but this and mutable members where concessions to make a const iterator function
	// a const iterator can still read and increment
	// a non const iterator can write value as well
	//
	//cache node the iterator points at, as dont want to retreive it by index (tree traversal)
	// after finding in tree (tree traversal)
	//
	template<typename IN_KEY, typename IN_DATA, typename IN_SORT >class HContainerTreeIterator
	{
		friend HContainerTree< IN_KEY, IN_DATA, IN_SORT >;

		////////////////////////////////////////////////////
		// typedef
	private:
		typedef typename std::map< IN_KEY, IN_DATA, IN_SORT >TImplementationMap;
		typedef typename TImplementationMap::iterator TImplementationIterator;

		////////////////////////////////////////////////////
		// creation
	private:
		HContainerTreeIterator( const TImplementationIterator& in_iterator );
	public:
		HContainerTreeIterator( const HContainerTreeIterator& in_src );
		~HContainerTreeIterator();

		////////////////////////////////////////////////////
		// public methods
	public:
		const IN_DATA& DataGet() const;
		IN_DATA& DataGet();

		const IN_DATA& operator *() const;
		IN_DATA& operator *();
	
		const IN_DATA* operator ->() const;
		IN_DATA* operator ->();

		const IN_KEY& KeyGet() const;

		//preincrement the iterator
		const HContainerTreeIterator& operator ++()const;
		//postincrement the iterator
		const HContainerTreeIterator operator ++(HS32)const;
		//predecrement the iterator
		const HContainerTreeIterator& operator --()const;
		//postdecrement the iterator
		const HContainerTreeIterator operator --(HS32)const;
	
		const HContainerTreeIterator& operator +=(const HS32 in_offset)const;
		const HContainerTreeIterator operator +(const HS32 in_offset)const;
	
		const HContainerTreeIterator& operator -=(const HS32 in_offset)const;
		const HContainerTreeIterator operator -(const HS32 in_offset)const;
	
		HS32 operator -(const HContainerTreeIterator & in_rhs)const;
	
		const HContainerTreeIterator& operator =(const HContainerTreeIterator & in_rhs);

		HBOOL operator ==( const HContainerTreeIterator& in_rhs )const;
		HBOOL operator !=( const HContainerTreeIterator& in_rhs )const;

		////////////////////////////////////////////////////
		// private accessor
	private:
		TImplementationIterator& ImplementationGet()const{ return m_iterator; }

		////////////////////////////////////////////////////
		// private members
	private:
		mutable TImplementationIterator m_iterator;

	};

	////////////////////////////////////////////////////
	// creation
	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::HContainerTreeIterator( const HContainerTreeIterator& in_src )
	: m_iterator( in_src.m_iterator )
	{
		return;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::HContainerTreeIterator( const TImplementationIterator& in_iterator )
	: m_iterator( in_iterator )
	{
		return;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::~HContainerTreeIterator()
	{
		return;
	}

	////////////////////////////////////////////////////
	// public methods
	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const IN_DATA& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::DataGet()const
	{
		return( *m_iterator ).second;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	IN_DATA& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::DataGet()
	{
		return( *m_iterator ).second;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const IN_DATA& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator *()const
	{
		return( *m_iterator ).second;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	IN_DATA& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator *()
	{
		return( *m_iterator ).second;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const IN_DATA* HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator ->()const
	{
		return( &( *m_iterator ).second );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	IN_DATA* HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator ->()
	{
		return( &( *m_iterator ).second );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const IN_KEY& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::KeyGet()const
	{
		return( *m_iterator ).first;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator ++()const
	{
		++m_iterator;
		return( *this );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT> HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator ++(HS32)const
	{
		HContainerTreeIterator returnIterator( m_iterator );
		++m_iterator;
		return returnIterator;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator --()const
	{
		--m_iterator;
		return( *this );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT> HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator --(HS32)const
	{
		HContainerTreeIterator returnIterator( m_iterator );
		--m_iterator;
		return returnIterator;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator +=(const HS32 in_offset)const
	{
		//m_iterator += in_offset;
		for( HSINT index = 0; index < in_offset; ++index )
		{
			++m_iterator;
		}
		return( *this );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT> HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator +(const HS32 in_offset)const
	{
		HContainerTreeIterator returnIterator( m_iterator );
		returnIterator += in_offset;
		return returnIterator;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator -=(const HS32 in_offset)const
	{
		for( HSINT index = 0; index < in_offset; ++index )
		{
			--m_iterator;
		}
		return( *this );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT> HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator -(const HS32 in_offset)const
	{
		HContainerTreeIterator returnIterator( m_iterator );
		returnIterator -= in_offset;
		return returnIterator;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	HS32 HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator -(const HContainerTreeIterator & in_rhs)const
	{
		return( m_iterator - in_rhs.m_iterator );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	const HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>& HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator =(const HContainerTreeIterator & in_rhs)
	{
		if( ( *this ) != in_rhs ) 
		{
			m_iterator = in_rhs.m_iterator;
		}
		return( *this );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	HBOOL HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator ==( const HContainerTreeIterator& in_rhs )const
	{
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match &= ( m_iterator == in_rhs.m_iterator );
		}

		return match;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT> 
	HBOOL HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>::operator !=( const HContainerTreeIterator& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	/**/

};

/**/
#endif// _H_CONTAINER_TREE_ITERATOR_H_
