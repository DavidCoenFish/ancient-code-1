//file: Envy/EMemento/EMementoPointerDataOwner.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoPointerDataOwner.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//creation
/**/
EMementoPointerDataOwner::EMementoPointerDataOwner( const EMementoPointerDataOwner& in_src )
: m_id( HCOMMON_INVALID_INDEX )
, m_factoryName( HNULL )
, m_isReferenced( HFALSE )
{
	( *this ) = in_src;
	return;
}

/**/
EMementoPointerDataOwner::EMementoPointerDataOwner(
	const Hubris::HSINT in_id,
	const Hubris::HString& in_factoryName,
	const Hubris::HBOOL in_isReferenced
	)
: m_id( in_id )
, m_factoryName( in_factoryName )
, m_isReferenced( in_isReferenced )
{
	return;
}

/**/
EMementoPointerDataOwner::EMementoPointerDataOwner()
: m_id( HCOMMON_INVALID_INDEX )
, m_factoryName( HNULL )
, m_isReferenced( HFALSE )
{
	return;
}

/**/
EMementoPointerDataOwner::~EMementoPointerDataOwner()
{
	return;
}

//////////////////////////////////////////////
//operator
/**/
const EMementoPointerDataOwner& EMementoPointerDataOwner::operator=( const EMementoPointerDataOwner& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_id = in_rhs.m_id;
		m_factoryName = in_rhs.m_factoryName;
		m_isReferenced = in_rhs.m_isReferenced;
	}

	return( *this );
}

/**/
const Hubris::HBOOL EMementoPointerDataOwner::operator==( const EMementoPointerDataOwner& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_id == in_rhs.m_id );
		match &= ( m_factoryName == in_rhs.m_factoryName );
		match &= ( m_isReferenced == in_rhs.m_isReferenced );
	}

	return match;
}

/**/
const Hubris::HBOOL EMementoPointerDataOwner::operator!=( const EMementoPointerDataOwner& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
