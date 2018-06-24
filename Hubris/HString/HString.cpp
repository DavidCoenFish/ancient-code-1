//file: Hubris/HString/HString.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HString/HString.h"

#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringUtility.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonDefine.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// static local var

///////////////////////////////////////////////////////////
// creation

/**/
Hubris::HString::HString( const HString& in_src )
: m_data()
{
	(*this) = in_src;

	return;
}

/**/
Hubris::HString::HString( const HCHAR* const in_src )
: m_data()
{
	(*this) = in_src;
	return;
}

/**/
Hubris::HString::HString( const HCHAR in_src )
: m_data()
{
	(*this) = in_src;
	return;
}

/**/
Hubris::HString::HString( const HSINT in_src )
: m_data()
{
	(*this) = in_src;
	return;
}

/**/
Hubris::HString::HString()
: m_data()
{
	SizeSet( 0 );
	return;
}

/**/
Hubris::HString::~HString()
{
	return;
}

//////////////////////////////////////////
// operators, for other operators, see HStringOperators
/**/
const HString& Hubris::HString::operator =( const HString& in_rhs )
{
	if( (*this) != in_rhs )
	{
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**/
const HString& Hubris::HString::operator =( const HCHAR* const in_rhs )
{
	if( (*this) != in_rhs )
	{
		if( HNULL == in_rhs )
		{
			m_data.clear();
		}
		else
		{
			m_data = in_rhs;
		}
	}

	return( *this );
}

/**/
const HString& Hubris::HString::operator =( const HCHAR in_rhs )
{
	if( (*this) != in_rhs )
	{
		m_data = in_rhs;
	}

	return( *this );
}

/**/
const HString& Hubris::HString::operator =( const HSINT in_rhs )
{
	HCOMMON_ASSERT( 0 == in_rhs, "HSINT string assignment for HNULL only" );

	if( (*this) != in_rhs )
	{
		m_data.clear();
	}

	return( *this );
}

/**/
const HCHAR Hubris::HString::operator[]( const HSINT in_index ) const
{
	return m_data[ in_index ];
}

/**/
HCHAR& Hubris::HString::operator[]( const HSINT in_index )
{
	return m_data[ in_index ];
}

/**/

//////////////////////////////////////////
// accessor

/**/
const HCHAR* const Hubris::HString::RawGet() const
{
	return m_data.c_str();
}

/**/
HSINT Hubris::HString::SizeGet() const
{
	return m_data.length();
}

#include <string>
/**/
HSINT Hubris::HString::SizeSet( const HSINT in_size )
{ 
	m_data.clear();
	return SizeResize( in_size );
}

/**/
HSINT Hubris::HString::SizeResize( const HSINT in_size )
{
	m_data.resize( in_size );
	return SizeGet();
}

//////////////////////////////////////////
// public methods
/**/
HVOID Hubris::HString::Clear()
{
	m_data.clear();

	return;
}

/**/
HVOID Hubris::HString::DataSet( const HCHAR* const in_data, const HSINT in_size, const HSINT in_offset )
{
	//m_data.replace( in_offset, in_size, in_data );
	for( HSINT index = 0; index < in_size; ++index )
	{
		m_data[ in_offset + index ] = in_data[ index ];
	}

	return;
}

/**/
