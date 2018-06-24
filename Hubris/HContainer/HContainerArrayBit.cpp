//file: Hubris/HContainer/HContainerArrayBit.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HContainer/HContainerArrayBit.h"

#include "Hubris/HCommon/HCommonDefine.h"

/////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/////////////////////////////////////////////////////////
// creation
/**/
Hubris::HContainerArrayBit::HContainerArrayBit( const TIteratorConst& in_insertStart, const TIteratorConst& in_insertEnd )
: m_data( in_insertStart, in_insertEnd )
{
	return;
}

/**/
Hubris::HContainerArrayBit::HContainerArrayBit( const HContainerArrayBit& in_src )
: m_data()
{
	( *this ) = in_src;
	return;
}

/**/
Hubris::HContainerArrayBit::HContainerArrayBit()
: m_data()
{
	return;
}
/**/
Hubris::HContainerArrayBit::~HContainerArrayBit()
{
	return;
}

/////////////////////////////////////////////////////////
// operators, see HContainerArrayOperators for more
/**/
Hubris::HContainerArrayBit& Hubris::HContainerArrayBit::operator =( const HContainerArrayBit& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**/
HBOOL Hubris::HContainerArrayBit::operator ==( const HContainerArrayBit& in_rhs ) const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_data == in_rhs.m_data );
	}

	return match;
}

/**/
HBOOL Hubris::HContainerArrayBit::operator !=( const HContainerArrayBit& in_rhs ) const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
const Hubris::HContainerArrayBit::TTypeConst Hubris::HContainerArrayBit::operator[]( const HSINT in_index ) const
{
	return m_data[ in_index ];
}

/**/
Hubris::HContainerArrayBit::TType Hubris::HContainerArrayBit::operator[]( const HSINT in_index )
{
	return m_data[ in_index ];
}

/////////////////////////////////////////////////////////
// accessors
/**/
HSINT Hubris::HContainerArrayBit::SizeGet()const
{
	return HSINT( m_data.size() );
}

/**/
HSINT Hubris::HContainerArrayBit::SizeSet( const HSINT in_size )
{
	m_data.clear();
	m_data.resize( in_size );
	return SizeGet();
}

/**/
HSINT Hubris::HContainerArrayBit::SizeResize( const HSINT in_size )
{
	m_data.resize( in_size );
	return SizeGet();
}
/**/
HVOID Hubris::HContainerArrayBit::Clear()
{
	m_data.clear();
	m_data.resize( 0 );
	return;
}

/**/
Hubris::HContainerArrayBit::TIteratorConst Hubris::HContainerArrayBit::Begin() const
{
	return m_data.begin();
}

/**/
Hubris::HContainerArrayBit::TIterator Hubris::HContainerArrayBit::Begin()
{
	return m_data.begin();
}

/**/
Hubris::HContainerArrayBit::TIteratorConst Hubris::HContainerArrayBit::End() const
{
	return m_data.end();
}

/**/
Hubris::HContainerArrayBit::TIterator Hubris::HContainerArrayBit::End()
{
	return m_data.end();
}

/////////////////////////////////////////////////////////
// public methods
/**/
HVOID Hubris::HContainerArrayBit::Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where )
{
	m_data.insert( in_where, in_insertStart, in_insertEnd );
	return;
}

/**/
HVOID Hubris::HContainerArrayBit::Insert( const HBOOL in_data, const TIterator& in_where )
{
	m_data.insert( in_where, in_data );
	return;
}

/**/
HVOID Hubris::HContainerArrayBit::Insert( const HBOOL in_data )
{
	m_data.push_back( in_data );
	return;
}

/**/
HVOID Hubris::HContainerArrayBit::Remove( const TIterator& in_start, const TIterator& in_end )
{
	m_data.erase( in_start, in_end );
	return;
}

/**/
Hubris::HContainerArrayBit::TIterator Hubris::HContainerArrayBit::Remove( const TIterator& in_where )
{
	return m_data.erase( in_where );
}

/**/

