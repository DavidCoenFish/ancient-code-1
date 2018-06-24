//file: Hubris/HFileSystem/HFileSystemTimeImplementPc.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HFileSystem/HFileSystemTimeImplementPc.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringUtility.h"
#include "Hubris/HTrait/HTraitStringIn.h"
#include "Hubris/HTrait/HTraitStringOut.h"

#include <time.h>

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// creation
Hubris::HFileSystemTimeImplementPc::HFileSystemTimeImplementPc( const HFileSystemTimeImplementPc& in_src )
: m_time( 0 )
{	
	( *this ) = in_src;
	return;
}

/**/
Hubris::HFileSystemTimeImplementPc::HFileSystemTimeImplementPc( const time_t in_time )
: m_time( in_time )
{	
	return;
}

/**/
Hubris::HFileSystemTimeImplementPc::~HFileSystemTimeImplementPc()
{
	
	return;
}

///////////////////////////////////////////////////////////
// operators
const HFileSystemTimeImplementPc& Hubris::HFileSystemTimeImplementPc::operator=( const HFileSystemTimeImplementPc& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_time = in_rhs.m_time;
	}

	return( *this );
}

/**/
HBOOL Hubris::HFileSystemTimeImplementPc::operator==( const HFileSystemTimeImplementPc& in_rhs ) const
{	
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_time == in_rhs.m_time );
	}

	return match;
}

/**/
HBOOL Hubris::HFileSystemTimeImplementPc::operator!=( const HFileSystemTimeImplementPc& in_rhs ) const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
HBOOL Hubris::HFileSystemTimeImplementPc::operator<( const HFileSystemTimeImplementPc& in_rhs )const
{
	if( m_time != in_rhs.m_time )
	{
		return( m_time < in_rhs.m_time );
	}

	//equal case
	return HFALSE;
}

/**/
HBOOL Hubris::HFileSystemTimeImplementPc::operator<=( const HFileSystemTimeImplementPc& in_rhs )const
{
	if( m_time != in_rhs.m_time )
	{
		return( m_time < in_rhs.m_time );
	}

	//equal case
	return HTRUE;
}

/**/
HBOOL Hubris::HFileSystemTimeImplementPc::operator>( const HFileSystemTimeImplementPc& in_rhs )const
{
	if( m_time != in_rhs.m_time )
	{
		return( m_time > in_rhs.m_time );
	}

	//equal case
	return HFALSE;
}

/**/
HBOOL Hubris::HFileSystemTimeImplementPc::operator>=( const HFileSystemTimeImplementPc& in_rhs )const
{
	if( m_time != in_rhs.m_time )
	{
		return( m_time > in_rhs.m_time );
	}

	//equal case
	return HTRUE;
}

///////////////////////////////////////////////////////////
// public methods
/*

struct tm {
        int tm_sec;     // seconds after the minute - [0,59] 
        int tm_min;     // minutes after the hour - [0,59] 
        int tm_hour;    // hours since midnight - [0,23] 
        int tm_mday;    // day of the month - [1,31] 
        int tm_mon;     // months since January - [0,11] 
        int tm_year;    // years since 1900 
        int tm_wday;    // days since Sunday - [0,6] 
        int tm_yday;    // days since January 1 - [0,365] 
        int tm_isdst;   // daylight savings time flag 
        };

*/
HVOID Hubris::HFileSystemTimeImplementPc::StringISO8601Get( HString& out_string )const
{
	tm timeStructure;
	memset( &timeStructure, 0, sizeof( tm ) );

	H_LOCAL_TIME( timeStructure, m_time );

	out_string = HNULL;
	out_string += HTraitStringIn< HSINT >( 1900 + timeStructure.tm_year );
	out_string += '-';
	out_string += HStringUtility::PadLeft( HTraitStringIn< HSINT >( timeStructure.tm_mon  + 1 ), 2, '0' );
	out_string += '-';
	out_string += HStringUtility::PadLeft( HTraitStringIn< HSINT >( timeStructure.tm_mday ), 2, '0' );
	out_string += 'T';
	out_string += HStringUtility::PadLeft( HTraitStringIn< HSINT >( timeStructure.tm_hour ), 2, '0' );
	out_string += ':';
	out_string += HStringUtility::PadLeft( HTraitStringIn< HSINT >( timeStructure.tm_min ), 2, '0' );
	out_string += ':';
	out_string += HStringUtility::PadLeft( HTraitStringIn< HSINT >( timeStructure.tm_sec ), 2, '0' );
	out_string += 'Z';

	return;
}

/**/
HVOID Hubris::HFileSystemTimeImplementPc::StringISO8601Set( const HString& in_string )
{
	( *this ) = HFileSystemTimeImplementPc();

	tm timeStructure;
	memset( &timeStructure, 0, sizeof( tm ) );

	if( 20 == in_string.SizeGet() )
	{
		HTraitStringOut< HSINT >( ( HSINT& )timeStructure.tm_year, HStringUtility::SubString( in_string, 0, 4 ) );
		timeStructure.tm_year -= 1900;
		HTraitStringOut< HSINT >( ( HSINT& )timeStructure.tm_mon, HStringUtility::SubString( in_string, 5, 2 ) );
		timeStructure.tm_mon -= 1;
		HTraitStringOut< HSINT >( ( HSINT& )timeStructure.tm_mday, HStringUtility::SubString( in_string, 8, 2 ) );
		HTraitStringOut< HSINT >( ( HSINT& )timeStructure.tm_hour, HStringUtility::SubString( in_string, 11, 2 ) );
		HTraitStringOut< HSINT >( ( HSINT& )timeStructure.tm_min, HStringUtility::SubString( in_string, 14, 2 ) );
		HTraitStringOut< HSINT >( ( HSINT& )timeStructure.tm_sec, HStringUtility::SubString( in_string, 17, 2 ) );

		m_time = mktime( &timeStructure );
	}

	return;
}

/**/
const HSINT Hubris::HFileSystemTimeImplementPc::SeedGet()const
{
	return HSINT( m_time );
}

/**/
