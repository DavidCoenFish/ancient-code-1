//file: Envy/EMemento/EMementoPointerData.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoPointerData.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//creation
/**/
EMementoPointerData::EMementoPointerData( const EMementoPointerData& in_src )
: m_id( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
EMementoPointerData::EMementoPointerData( const Hubris::HSINT in_id )
: m_id( in_id )
{
	return;
}

/**/
EMementoPointerData::EMementoPointerData()
: m_id( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
EMementoPointerData::~EMementoPointerData()
{
	return;
}

//////////////////////////////////////////////
//operator
/**/
const EMementoPointerData& EMementoPointerData::operator=( const EMementoPointerData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_id = in_rhs.m_id;
	}

	return( *this );
}

/**/
const Hubris::HBOOL EMementoPointerData::operator==( const EMementoPointerData& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_id == in_rhs.m_id );
	}

	return match;
}

/**/
const Hubris::HBOOL EMementoPointerData::operator!=( const EMementoPointerData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
