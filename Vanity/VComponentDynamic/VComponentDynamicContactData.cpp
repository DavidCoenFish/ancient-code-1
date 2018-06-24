//file: Vanity/VComponentDynamic/VComponentDynamicContactData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentDynamic/VComponentDynamicContactData.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentDynamicContactData::VComponentDynamicContactData( const VComponentDynamicContactData& in_src )
: m_contactNormal()
, m_contactPosition()
, m_touchingObjectId( HCOMMON_INVALID_INDEX )
, m_targetCanMove( HFALSE )
{
	( *this ) = in_src;
	return;
}

/**/
VComponentDynamicContactData::VComponentDynamicContactData()
: m_contactNormal()
, m_contactPosition()
, m_touchingObjectId( HCOMMON_INVALID_INDEX )
, m_targetCanMove( HFALSE )
{
	return;
}
/**/
VComponentDynamicContactData::~VComponentDynamicContactData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentDynamicContactData& VComponentDynamicContactData::operator=( const VComponentDynamicContactData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_contactNormal = in_rhs.m_contactNormal;
		m_contactPosition = in_rhs.m_contactPosition;
		m_touchingObjectId = in_rhs.m_touchingObjectId;
		m_targetCanMove = in_rhs.m_targetCanMove;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentDynamicContactData::operator==( const VComponentDynamicContactData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_contactNormal == in_rhs.m_contactNormal );
		match &= ( m_contactPosition == in_rhs.m_contactPosition );
		match &= ( m_touchingObjectId == in_rhs.m_touchingObjectId );
		match &= ( m_targetCanMove == in_rhs.m_targetCanMove );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentDynamicContactData::operator!=( const VComponentDynamicContactData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
