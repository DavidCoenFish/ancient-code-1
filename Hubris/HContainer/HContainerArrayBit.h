//file: Hubris/HContainer/HContainerArrayBit.h
#ifndef _H_CONTAINER_ARRAY_BIT_H_
#define _H_CONTAINER_ARRAY_BIT_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	class HContainerArrayBit
	{
		/////////////////////////////////////////////////////////
		// typedef
	public:
		typedef std::vector< bool >::const_iterator TIteratorConst;
		typedef std::vector< bool >::iterator TIterator;
		typedef std::vector< bool >::const_reference TTypeConst;
		typedef std::vector< bool >::reference TType;
	private:
		class TImplementationVector : public std::vector< bool >
		{
		public:
			TImplementationVector( const TIteratorConst& in_insertStart, const TIteratorConst& in_insertEnd )
			: std::vector< bool >( in_insertStart, in_insertEnd )
			{
				return;
			}
			TImplementationVector()
			{
				return;
			}
			TImplementationVector( const TImplementationVector& in_src )
			: std::vector< bool >( in_src )
			{
				return;
			}
			const HVOID* const RawGet()const{ return( ( const HVOID* )( &( _Myvec[ 0 ] ) ) ); }
		};
		//typedef std::vector< bool >TImplementationVector;

		/////////////////////////////////////////////////////////
		// creation
	public:
		HContainerArrayBit( const TIteratorConst& in_insertStart, const TIteratorConst& in_insertEnd );
		HContainerArrayBit( const HContainerArrayBit& in_src );
		HContainerArrayBit();
		~HContainerArrayBit();

		/////////////////////////////////////////////////////////
		// operators, see HContainerArrayOperators for more
	public:
		HContainerArrayBit& operator =( const HContainerArrayBit& in_rhs );
		HBOOL operator ==( const HContainerArrayBit& in_rhs ) const;
		HBOOL operator !=( const HContainerArrayBit& in_rhs ) const;

		const TTypeConst operator[]( const HSINT in_index ) const;
		TType operator[]( const HSINT in_index );

		/////////////////////////////////////////////////////////
		// accessors
	public:
		HSINT SizeGet()const;
		HSINT SizeSet( const HSINT in_size );
		HSINT SizeResize( const HSINT in_size );
		//release memory
		HVOID Clear();

		TIteratorConst Begin() const;
		TIterator Begin();

		TIteratorConst End() const;
		TIterator End();

		/////////////////////////////////////////////////////////
		// public methods
	public:
		//for push, pop and back, see 
		//insert at 'where', contents at 'where' are pushed along, if any 
		HVOID Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where );
		HVOID Insert( const HBOOL in_data, const TIterator& in_where );
		HVOID Insert( const HBOOL in_data );

		HVOID Remove( const TIterator& in_start, const TIterator& in_end );
		TIterator Remove( const TIterator& in_where );

		const HVOID* const RawGet()const{ return( m_data.RawGet() ); }

		/////////////////////////////////////////////////////////
		// private members
	private:
		TImplementationVector m_data;

	};
};

#endif// _H_CONTAINER_ARRAY_BIT_H_
