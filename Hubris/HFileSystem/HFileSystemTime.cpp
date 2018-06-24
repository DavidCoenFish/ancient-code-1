//file: Hubris/HFileSystem/HFileSystemTime.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HFileSystem/HFileSystemTime.h"

#include "Hubris/HFileSystem/HFileSystemTimeImplementPc.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HFileSystemTime::HFileSystemTime( const HFileSystemTime& in_src ) 
: m_pImplement( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplement, TImplementation, in_src.ImplementGet() );
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return;
}

/**/
Hubris::HFileSystemTime::HFileSystemTime()
: m_pImplement( HNULL )
{
	HCOMMON_NEW( m_pImplement, TImplementation );
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return;
}

/**/
Hubris::HFileSystemTime::~HFileSystemTime()
{	
	HCOMMON_DELETE( m_pImplement, TImplementation );

	return;
}

///////////////////////////////////////////////////////////
// operators
const HFileSystemTime& Hubris::HFileSystemTime::operator=( const HFileSystemTime& in_rhs )
{
	ImplementGet() = in_rhs.ImplementGet();

	return( *this );
}

/**/
HBOOL Hubris::HFileSystemTime::operator==( const HFileSystemTime& in_rhs ) const
{
	return( ImplementGet() == in_rhs.ImplementGet() );
}

/**/
HBOOL Hubris::HFileSystemTime::operator!=( const HFileSystemTime& in_rhs ) const
{
	return( ImplementGet() != in_rhs.ImplementGet() );
}

/**/
HBOOL Hubris::HFileSystemTime::operator<( const HFileSystemTime& in_rhs )const
{
	return( ImplementGet() < in_rhs.ImplementGet() );
}

/**/
HBOOL Hubris::HFileSystemTime::operator<=( const HFileSystemTime& in_rhs )const
{
	return( ImplementGet() <= in_rhs.ImplementGet() );
}

/**/
HBOOL Hubris::HFileSystemTime::operator>( const HFileSystemTime& in_rhs )const
{
	return( ImplementGet() > in_rhs.ImplementGet() );
}

/**/
HBOOL Hubris::HFileSystemTime::operator>=( const HFileSystemTime& in_rhs )const
{
	return( ImplementGet() >= in_rhs.ImplementGet() );
}

///////////////////////////////////////////////////////////
// public methods
/**/
const HString Hubris::HFileSystemTime::StringISO8601Get()const
{
	HString returnString;
	ImplementGet().StringISO8601Get( returnString );
	return returnString;
}

/**/
HVOID Hubris::HFileSystemTime::StringISO8601Set( const HString& in_string )
{
	ImplementGet().StringISO8601Set( in_string );
	return;	
}

/**/
const HSINT Hubris::HFileSystemTime::SeedGet()const
{
	const HSINT seed = ImplementGet().SeedGet();
	return seed;
}


///////////////////////////////////////////////////////////
// private accessors
/**/
const Hubris::HFileSystemTime::TImplementation& Hubris::HFileSystemTime::ImplementGet()const
{	
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return( *m_pImplement );
}

/**/
Hubris::HFileSystemTime::TImplementation& Hubris::HFileSystemTime::ImplementGet()
{	
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return( *m_pImplement );
}

/**/
