//file: Hubris/HContainer/HContainerTree.h
#ifndef _H_CONTAINER_TREE_H_
#define _H_CONTAINER_TREE_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HContainer/HContainerTreeIterator.h"
#include <map>

/**/
namespace Hubris
{
	template< typename IN_TYPE >struct HContainerLess;

	template< typename IN_KEY, typename IN_DATA, typename IN_SORT = HContainerLess< IN_KEY > >class HContainerTree
	{
		///////////////////////////////////////////////////////////
		// typedefs
	public:
		typedef HContainerTreeIterator<IN_KEY, IN_DATA, IN_SORT>TIterator;
		typedef HContainerTree< IN_KEY, IN_DATA, IN_SORT >TContainer;
		typedef IN_DATA TType; // for generice contain usage by algorithm, foreach
		typedef IN_KEY TKey;
		typedef IN_SORT TSort;
	private:
		typedef std::map< IN_KEY, IN_DATA, IN_SORT >TImplementationMap;
		
		///////////////////////////////////////////////////////////
		// creation
	public:
		HContainerTree( const HContainerTree& in_src );
		HContainerTree();
		~HContainerTree();

		///////////////////////////////////////////////////////////
		// operators
	public:
		const HContainerTree & operator =( const HContainerTree& in_src );

		HBOOL operator ==( const HContainerTree& in_rhs )const;
		HBOOL operator !=( const HContainerTree& in_rhs )const;
		HBOOL operator <( const HContainerTree& in_rhs )const;

		const IN_DATA& operator [] ( const HS32 in_index )const;
		IN_DATA& operator [] ( const HS32 in_index );

		///////////////////////////////////////////////////////////
		// accessors
	public:
		HS32 SizeGet()const { return m_data.size(); }
		HVOID Clear(); // free all memory

		const TIterator Begin()const;		//return the iterator to the first data, could be not valid
		TIterator Begin();					//return the iterator to the first data, could be not valid

		const TIterator End()const;		//return the iterator after last data, not valid
		TIterator End();					//return the iterator after last data, not valid

		const TIterator Find( const IN_KEY & in_key)const;		//return the iterator found or after last data, could be not valid
		TIterator Find( const IN_KEY & in_key);					//return the iterator found or after last data, could be not valid

		//get the key that at or just under key, or Begin() if key is under start
		const TIterator FindNearest( const IN_KEY& in_key )const; 
		TIterator FindNearest( const IN_KEY& in_key ); 

		///////////////////////////////////////////////////////////
		// public methods
	public:
		//index return removed for performance
		//replaces item at key if it already exsists
		HVOID Insert( const TIterator& in_start, const TIterator& in_stop );
		HVOID Insert( const IN_KEY& in_key, const IN_DATA& in_data );

		HVOID Remove( const TIterator& in_start, const TIterator& in_stop );
		//returns the iter before the removed item, still need to increment it (ie, assumes in for loop)
		TIterator Remove( const TIterator& in_where );

		//get key
		const IN_KEY& KeyGet( const HS32 in_index )const;

		///////////////////////////////////////////////////////////
		// private members
	private:
		TImplementationMap m_data;

	};

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HContainerTree<IN_KEY, IN_DATA, IN_SORT>::HContainerTree(const HContainerTree & in_src)
	: m_data()
	{
		(*this) = in_src;
		return;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HContainerTree<IN_KEY, IN_DATA, IN_SORT>::HContainerTree()
	: m_data()
	{
		return;
	}
	
	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HContainerTree<IN_KEY, IN_DATA, IN_SORT>::~HContainerTree()
	{
		return;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HVOID HContainerTree<IN_KEY, IN_DATA, IN_SORT>::Clear()
	{
		m_data.clear();
		return;
	}

	/**/
	template< typename IN_KEY, typename IN_DATA, typename IN_SORT >
	HVOID HContainerTree< IN_KEY, IN_DATA, IN_SORT >::Insert( const IN_KEY& in_key, const IN_DATA& in_data )
	{
		TIterator iterator = Find( in_key );
		if( iterator == End() )
		{
			m_data.insert( TImplementationMap::value_type( in_key, in_data ) );
		}
		else
		{
			( *iterator ) = in_data;
		}

		return; 
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HVOID HContainerTree<IN_KEY, IN_DATA, IN_SORT>::Insert(const TIterator & in_start, const TIterator & in_stop)
	{		
		for( TIterator iter = in_start; iter != in_stop; ++iter )
		{
			Insert( iter.KeyGet(), (*iter) );
		}

		return;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	typename const HContainerTree<IN_KEY, IN_DATA, IN_SORT>::TIterator HContainerTree<IN_KEY, IN_DATA, IN_SORT>::Begin()const
	{
		return TIterator( ( ( HContainerTree<IN_KEY, IN_DATA, IN_SORT>& ) *this ).m_data.begin() );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	typename HContainerTree<IN_KEY, IN_DATA, IN_SORT>::TIterator HContainerTree<IN_KEY, IN_DATA, IN_SORT>::Begin()
	{	
		return TIterator( m_data.begin() );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	typename const HContainerTree<IN_KEY, IN_DATA, IN_SORT>::TIterator HContainerTree<IN_KEY, IN_DATA, IN_SORT>::End()const
	{	
		return TIterator( ( ( HContainerTree<IN_KEY, IN_DATA, IN_SORT>& ) *this ).m_data.end() );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	typename HContainerTree<IN_KEY, IN_DATA, IN_SORT>::TIterator HContainerTree<IN_KEY, IN_DATA, IN_SORT>::End()
	{	
		return TIterator( m_data.end() );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	typename const HContainerTree<IN_KEY, IN_DATA, IN_SORT>::TIterator HContainerTree<IN_KEY, IN_DATA, IN_SORT>::Find(const IN_KEY & in_key) const
	{	
		return TIterator( ( ( HContainerTree<IN_KEY, IN_DATA, IN_SORT>& ) *this ).m_data.find( in_key ) );
	}

	/**/
	template< typename IN_KEY, typename IN_DATA, typename IN_SORT >
	typename HContainerTree< IN_KEY, IN_DATA, IN_SORT >::TIterator HContainerTree< IN_KEY, IN_DATA, IN_SORT >::Find( const IN_KEY & in_key )
	{
		return TIterator( m_data.find( in_key ) );
	}

	/**/
	template< typename IN_KEY, typename IN_DATA, typename IN_SORT >
	const typename HContainerTree< IN_KEY, IN_DATA, IN_SORT >::TIterator HContainerTree< IN_KEY, IN_DATA, IN_SORT >::FindNearest( const IN_KEY& in_key )const
	{
		return TIterator( ( ( HContainerTree<IN_KEY, IN_DATA, IN_SORT>& ) *this ).m_data.lower_bound( in_key ) );
	}

	/**/
	template< typename IN_KEY, typename IN_DATA, typename IN_SORT >
	typename HContainerTree< IN_KEY, IN_DATA, IN_SORT >::TIterator HContainerTree< IN_KEY, IN_DATA, IN_SORT >::FindNearest( const IN_KEY& in_key )
	{
		return TIterator( m_data.lower_bound( in_key ) );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	typename HContainerTree<IN_KEY, IN_DATA, IN_SORT>::TIterator HContainerTree<IN_KEY, IN_DATA, IN_SORT>::Remove(const TIterator & in_src)
	{
		return TIterator( m_data.erase( in_src.ImplementationGet() ) );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HVOID HContainerTree<IN_KEY, IN_DATA, IN_SORT>::Remove(const TIterator & in_start, const TIterator & in_stop)
	{		
		m_data.erase( in_start.ImplementationGet(), in_stop.ImplementationGet() );
		return;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	const IN_DATA& HContainerTree<IN_KEY, IN_DATA, IN_SORT>::operator [] (const HS32 in_index) const
	{
		return( const IN_DATA& )( *( Begin() + in_index ) );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	IN_DATA& HContainerTree<IN_KEY, IN_DATA, IN_SORT>::operator [] (const HS32 in_index)
	{
		return( IN_DATA& )( *( Begin() + in_index ) );
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	const HContainerTree<IN_KEY, IN_DATA, IN_SORT> & HContainerTree<IN_KEY, IN_DATA, IN_SORT>::operator =(const HContainerTree & in_src)
	{		
		if((*this) != in_src)
		{
			Clear();

			Insert(in_src.Begin(), in_src.End());
		}

		return (*this);
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HBOOL HContainerTree<IN_KEY, IN_DATA, IN_SORT>::operator ==(const HContainerTree & in_rhs) const
	{	
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match = ( m_data == in_rhs.m_data );
		}

		return match;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HBOOL HContainerTree<IN_KEY, IN_DATA, IN_SORT>::operator !=(const HContainerTree & in_rhs) const
	{
		return !(operator ==(in_rhs));
	}
		
	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	HBOOL HContainerTree<IN_KEY, IN_DATA, IN_SORT>::operator <(const HContainerTree & in_rhs) const
	{
		HBOOL lessThan = HFALSE;
		if( this != &in_rhs )
		{
			lessThan = ( m_data < in_rhs.m_data );
		}

		return lessThan;
	}

	/**/
	template <typename IN_KEY, typename IN_DATA, typename IN_SORT>
	const IN_KEY& HContainerTree<IN_KEY, IN_DATA, IN_SORT>::KeyGet( const HS32 in_index )const
	{	
		return( Begin() + in_index ).KeyGet();	
	}

	/**/

};

#endif// _H_CONTAINER_TREE_H_
