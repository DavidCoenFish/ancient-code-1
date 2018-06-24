//file: Hubris/HContainer/HContainerArrayBool.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HContainer/HContainerArrayBool.h"

#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HContainer/HContainerArrayIterator.h"

#include "Hubris/HCommon/HCommonForEach.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
Hubris::HContainerArray< Hubris::HBOOL >::HContainerArray( const TIterator& in_insertStart, const TIterator& in_insertEnd ) 
: m_data()
{
	Insert( in_insertStart, in_insertEnd, End() );

	return;
}

/**/
HContainerArray< Hubris::HBOOL >::HContainerArray( const HContainerArray< Hubris::HBOOL >& in_src )
: m_data()
{
	( *this ) = in_src;

	return;
}

/**/
HContainerArray< Hubris::HBOOL >::HContainerArray()
: m_data()
{
	return;
}

/**/
HContainerArray< Hubris::HBOOL >::~HContainerArray()
{
	m_data.clear();
	return;
}

/**/
HContainerArray< Hubris::HBOOL >& HContainerArray< Hubris::HBOOL >::operator =( const HContainerArray< Hubris::HBOOL >& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**/
HBOOL HContainerArray< Hubris::HBOOL >::operator ==( const HContainerArray< Hubris::HBOOL >& in_rhs ) const
{		
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match = match && ( m_data == in_rhs.m_data );
	}

	return match;
}

/**/
HBOOL HContainerArray< Hubris::HBOOL >::operator !=( const HContainerArray< Hubris::HBOOL >& in_rhs )const
{		
	return!( operator==( in_rhs ) );
}

/**/
const Hubris::HBOOL& HContainerArray< Hubris::HBOOL >::operator[]( const HSINT in_index )const
{
	return (const HBOOL&)( *( HBOOL * )( &m_data[ in_index ] ) );
}

/**/
Hubris::HBOOL& HContainerArray< Hubris::HBOOL >::operator[]( const HSINT in_index )
{
	return (HBOOL&) m_data[ in_index ];
}

///////////////////////////////////////////////////////////
// accessors
/**/
HSINT HContainerArray< Hubris::HBOOL >::SizeGet()const
{
	return m_data.size();
}

/**/
HSINT HContainerArray< Hubris::HBOOL >::SizeSet( const HSINT in_size )
{
	Clear();
	SizeResize( in_size );
	return SizeGet();
}

/**/
HSINT HContainerArray< Hubris::HBOOL >::SizeResize( const HSINT in_size )
{
	m_data.resize( in_size );
	return SizeGet();
}

/**/
HVOID HContainerArray< Hubris::HBOOL >::Clear()
{
	m_data.clear();
	return;
}

/**/
const HContainerArray< Hubris::HBOOL >::TIterator HContainerArray< Hubris::HBOOL >::Begin() const
{
	//this is the cost of not having iter and const_iter, weak obligation to return const iterator not to change container
	//return TIterator( ( ( HContainerArray< Hubris::HBOOL >& ) *this ).m_data.begin() );
	return TIterator( ( TContainer& )( *this ), 0 );
}

/**/
HContainerArray< Hubris::HBOOL >::TIterator HContainerArray< Hubris::HBOOL >::Begin()
{
	//return TIterator( m_data.begin() );
	return TIterator( ( *this ), 0 );
}

/**/
const HContainerArray< Hubris::HBOOL >::TIterator HContainerArray< Hubris::HBOOL >::End() const
{
	//return TIterator( ( ( HContainerArray< Hubris::HBOOL >& ) *this ).m_data.end() );
	return TIterator( ( TContainer& )( *this ), SizeGet() );
}

/**/
HContainerArray< Hubris::HBOOL >::TIterator HContainerArray< Hubris::HBOOL >::End()
{
	//return TIterator( m_data.end() );
	return TIterator( *this, SizeGet() );
}

/**/
HVOID HContainerArray< Hubris::HBOOL >::Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where )
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
		HCOMMON_FOR_EACH_RANGE_CONST( data, HContainerArray< Hubris::HBOOL >, in_insertStart, in_insertEnd )
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

	HCOMMON_FOR_EACH_RANGE_CONST( data, HContainerArray< Hubris::HBOOL >, in_insertStart, in_insertEnd )
	{
		m_data[ trace + insertSpace ] = m_data[ trace ];
		m_data[ trace ] = data;
		++trace;
	}

	return;
}

/**/
HVOID HContainerArray< Hubris::HBOOL >::Insert( const TType& in_data, const TIterator& in_where )
{
	if( ( 0 == SizeGet() ) || ( in_where == End() ) )
	{
		Insert( in_data );
	}
	else
	{
		SizeResize( SizeGet() + 1 );
		TIterator trace = End() - 1;
		{
			TIterator oldTrace( trace );
			--trace;
			( *oldTrace ) = ( *trace );
		}
		while( ( trace != in_where ) && ( trace != Begin() ) )

		( *trace ) = in_data;
	}

	return;
}

/**/
HVOID HContainerArray< Hubris::HBOOL >::Insert( const TType& in_data )
{
	m_data.push_back( in_data );

	return;
}

/**/
HVOID HContainerArray< Hubris::HBOOL >::Remove( const TIterator& in_start, const TIterator& in_end )
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
HContainerArray< Hubris::HBOOL >::TIterator HContainerArray< Hubris::HBOOL >::Remove( const TIterator& in_where )
{
	Remove( in_where, in_where + 1 );

	return( in_where - 1 );
}

/**/

