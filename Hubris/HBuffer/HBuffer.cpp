//file: Hubris/HBuffer/HBuffer.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBuffer/HBuffer.h"

#include "Hubris/HBuffer/HBufferOperators.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonMemory.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HBuffer::HBuffer( const HBuffer & in_src )
: m_data( HNULL )
, m_size( 0 )
{
	( *this ) = in_src;
	return;
}

/**/
Hubris::HBuffer::HBuffer( const HVOID* const in_src, const HSINT in_size ) :
	m_data( HNULL ),
	m_size( 0 )
{
	SizeSet( in_size );
	DataSet( in_src, in_size, 0 );

	return;
}

/**/
Hubris::HBuffer::HBuffer() :
	m_data( HNULL ),
	m_size( 0 )
{
	return;
}

/**/
Hubris::HBuffer::~HBuffer()
{
	SizeSet( 0 );

	return;
}

//////////////////////////////////////////
// operators
/**/
const HBuffer & Hubris::HBuffer::operator =( const HBuffer & in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		SizeSet( in_rhs.SizeGet() );
		DataSet( in_rhs.RawGet(), in_rhs.SizeGet(), 0 );
	}

	return ( *this );
}

/**/
const HBOOL Hubris::HBuffer::operator ==( const HBuffer & in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_size == in_rhs.m_size );
		if( HTRUE == match )
		{
			match &= ( 0 == HCommonMemory::MemoryCompair( m_data, in_rhs.m_data, m_size ) );
		}
	}

	return match;
}

/**/
const HBOOL Hubris::HBuffer::operator !=( const HBuffer & in_rhs )const
{
	return( !( operator ==( in_rhs ) ) );
}

//////////////////////////////////////////
// accessor
/**/
HVOID Hubris::HBuffer::DataSet( const HVOID* const in_src, const HSINT in_size, const HSINT in_offset )
{
	if( 0 == in_size )
	{
		return;
	}

	HCOMMON_ASSERT( HNULL != in_src, "invalid param" );
	HCOMMON_ASSERT( HNULL != m_data, "invalid member" );
	HCOMMON_ASSERT( 0 < in_size, "invalid param" );
	HCOMMON_ASSERT( 0 <= in_offset, "invalid param" );
	HCOMMON_ASSERT( in_size + in_offset <= m_size, "invalid param" );

	HCommonMemory::MemoryCopy( ( ( HU8* )m_data ) + in_offset, in_src, in_size );

	return;
}

/**/
HVOID Hubris::HBuffer::DataGet( HVOID* const in_dest, const HSINT in_size, const HSINT in_offset ) const 
{
	if( 0 == in_size )
	{
		return;
	}

	HCOMMON_ASSERT( HNULL != in_dest, "invalid param" );
	HCOMMON_ASSERT( HNULL != m_data, "invalid member" );
	HCOMMON_ASSERT( 0 < in_size, "invalid param" );
	HCOMMON_ASSERT( 0 <= in_offset, "invalid param" );
	HCOMMON_ASSERT( in_size + in_offset <= m_size, "invalid member" );

	HCommonMemory::MemoryCopy( in_dest, ( ( HU8* )m_data ) + in_offset, in_size );

	return;
}

/**/
HVOID Hubris::HBuffer::SizeSet( const HSINT in_size )
{
	if( in_size == m_size )
	{
		return;
	}

	if( HNULL != m_data )
	{
		HCommonMemory::Free( m_data );
		m_data = HNULL;
	}

	if( 0 < in_size )
	{
		m_data = HCommonMemory::Malloc( in_size );
	}

	if( HNULL != m_data )
	{
		m_size = in_size;
	}
	else
	{
		m_size = 0;
	}

	return;
}

/**/
HVOID Hubris::HBuffer::SizeResize( const HSINT in_size )
{
	if( in_size != m_size )
	{
		if( ( HNULL == m_data ) && ( 0 < in_size ) )
		{
			m_data = HCommonMemory::Malloc( in_size );
		}
		else if( 0 < in_size )
		{
			m_data = HCommonMemory::Realloc( m_data, in_size );
		}
		else
		{
			HCommonMemory::Free( m_data );
			m_data = HNULL;
		}

		if( HNULL != m_data )
		{
			m_size = in_size;
		}
		else
		{
			m_size = 0;
		}
	}

	return;
}

/**/
HVOID Hubris::HBuffer::Clear()
{
	SizeSet( 0 );
	return;
}

/**/