//file: Hubris/HContainer/HContainerArrayBool.h
#ifndef _H_CONTAINER_ARRAY_BOOL_H_
#define _H_CONTAINER_ARRAY_BOOL_H_

#include "Hubris/HCommon/HCommonType.h"
#include <vector>

/*
	explicit specialization in the cpp file for HContainerArra< HBOOL >
*/
namespace Hubris
{
	template< typename IN_TYPE > class HContainerArray;
	template <typename IN_TYPE> class HContainerArrayIterator;

	template<> 
	class HContainerArray< HBOOL >
	{
		/////////////////////////////////////////////////////////
		// typedef
	public:
		typedef HContainerArrayIterator< Hubris::HBOOL >TIterator;
		typedef HContainerArray< Hubris::HBOOL >TContainer;
		typedef Hubris::HBOOL TType;
	private:
		typedef std::vector< Hubris::HU8 >TImplementationVector;

		/////////////////////////////////////////////////////////
		// creation
	public:
		HContainerArray( const TIterator& in_insertStart, const TIterator& in_insertEnd );
		HContainerArray( const HContainerArray< Hubris::HBOOL >& in_src );
		HContainerArray();
		~HContainerArray();

		/////////////////////////////////////////////////////////
		// operators, see HContainerArrayOperators for more
	public:
		HContainerArray& operator =( const HContainerArray< Hubris::HBOOL >& in_rhs );
		HBOOL operator ==( const HContainerArray< Hubris::HBOOL >& in_rhs ) const;
		HBOOL operator !=( const HContainerArray< Hubris::HBOOL >& in_rhs ) const;

		const TType& operator[]( const HSINT in_index ) const;
		TType& operator[]( const HSINT in_index );

		/////////////////////////////////////////////////////////
		// accessors
	public:
		HSINT SizeGet()const;
		HSINT SizeSet( const HSINT in_size );
		HSINT SizeResize( const HSINT in_size );
		//release memory
		HVOID Clear();

		const TIterator Begin() const;
		TIterator Begin();

		const TIterator End() const;
		TIterator End();

		/////////////////////////////////////////////////////////
		// public methods
	public:
		//for push, pop and back, see 
		//insert at 'where', contents at 'where' are pushed along, if any 
		HVOID Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where );
		HVOID Insert( const TType& in_data, const TIterator& in_where );
		HVOID Insert( const TType& in_data );

		HVOID Remove( const TIterator& in_start, const TIterator& in_end );
		TIterator Remove( const TIterator& in_where );

		const HVOID* const RawGet()const{ return &m_data[ 0 ]; }

		/////////////////////////////////////////////////////////
		// private members
	private:
		TImplementationVector m_data;

	};
};

#endif// _H_CONTAINER_ARRAY_BOOL_H_
