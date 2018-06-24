//file: Envy/EStringTable/EStringTable.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStringTable/EStringTable.h"

#include "Envy/EStringTable/EStringTableImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// creation
/**/
EStringTable::EStringTable( const EStringTable& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, EStringTableImplementation, in_src.ImplementationGet() );
	return;
}

/**/
EStringTable::EStringTable()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, EStringTableImplementation );
	return;
}

/**/
EStringTable::~EStringTable()
{
	HCOMMON_DELETE( m_pImplementation, EStringTableImplementation );
	return;
}

/////////////////////////////////////////////////////////////////
// operators
/**/
const EStringTable& EStringTable::operator=( const EStringTable& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
const Hubris::HBOOL EStringTable::operator==( const EStringTable& in_rhs )const
{
	const HBOOL result = ImplementationGet() == in_rhs.ImplementationGet();
	return result;
}

/**/
const Hubris::HBOOL EStringTable::operator!=( const EStringTable& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT EStringTable::StringAdd( const Hubris::HString& in_string )
{
	const HSINT index = ImplementationGet().StringAdd( in_string );
	return index;
}

/**/
Hubris::HVOID EStringTable::StringIndexAdd( const Hubris::HString& in_string, const Hubris::HSINT in_index )
{
	ImplementationGet().StringIndexAdd( in_string, in_index );
	return;
}

/**/
const Hubris::HSINT EStringTable::StringFind( const Hubris::HString& in_string )const
{
	const HSINT index = ImplementationGet().StringFind( in_string );
	return index;
}

/**/
const Hubris::HString& EStringTable::StringGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StringGet( in_index );
}

/**/
const Hubris::HSINT EStringTable::StringCountGet()const
{
	const HSINT size = ImplementationGet().StringCountGet();
	return size;
}

/////////////////////////////////////////////////////////////////
// private accessors
/**/
const EStringTableImplementation& EStringTable::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
EStringTableImplementation& EStringTable::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
