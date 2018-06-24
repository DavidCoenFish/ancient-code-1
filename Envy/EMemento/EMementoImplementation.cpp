//file: Envy/EMemento/EMementoImplementation.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//creation
/**/
EMementoImplementation::EMementoImplementation( const EMementoImplementation& in_src )
: m_dataStore()
{
	( *this ) = in_src;
	return;
}

/**/
EMementoImplementation::EMementoImplementation()
: m_dataStore()
{
	return;
}

/**/
EMementoImplementation::~EMementoImplementation()
{
	return;
}

//////////////////////////////////////////////
//operators
/**/
const EMementoImplementation& EMementoImplementation::operator=( const EMementoImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_dataStore = in_rhs.m_dataStore;
	}

	return( *this );
}

/**/
Hubris::HBOOL EMementoImplementation::operator==( const EMementoImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_dataStore == in_rhs.m_dataStore );
	}

	return match;
}

/**/
Hubris::HBOOL EMementoImplementation::operator!=( const EMementoImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}


//////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT EMementoImplementation::NullPointerIdGet()
{
	return HCOMMON_INVALID_INDEX;
}

/**/
