//file: Vanity/VComponentLightReceiver/VComponentLightReceiverItemData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightReceiver/VComponentLightReceiverItemData.h"

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
VComponentLightReceiverItemData::VComponentLightReceiverItemData( const VComponentLightReceiverItemData& in_src )
: m_arrayLightIdStatic() 
, m_frameId( HCOMMON_INVALID_INDEX )
, m_arrayLightIdDynamic()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentLightReceiverItemData::VComponentLightReceiverItemData()
: m_arrayLightIdStatic() 
, m_frameId( HCOMMON_INVALID_INDEX )
, m_arrayLightIdDynamic()
{
	return;
}

/**/
VComponentLightReceiverItemData::~VComponentLightReceiverItemData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VComponentLightReceiverItemData& VComponentLightReceiverItemData::operator=( const VComponentLightReceiverItemData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayLightIdStatic = in_rhs.m_arrayLightIdStatic;
		m_frameId = in_rhs.m_frameId;
		m_arrayLightIdDynamic = in_rhs.m_arrayLightIdDynamic;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentLightReceiverItemData::operator==( const VComponentLightReceiverItemData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayLightIdStatic == in_rhs.m_arrayLightIdStatic );
		match &= ( m_frameId == in_rhs.m_frameId );
		match &= ( m_arrayLightIdDynamic == in_rhs.m_arrayLightIdDynamic );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentLightReceiverItemData::operator!=( const VComponentLightReceiverItemData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentLightReceiverItemData::DynamicLightAdd(
	const TItemId in_lightItemId,
	const Hubris::HSINT in_frameId
	)
{
	if( in_frameId != m_frameId )
	{
		m_frameId = in_frameId;
		m_arrayLightIdDynamic.Clear();
	}
	m_arrayLightIdDynamic.Insert( in_lightItemId );

	return;
}

/**/
Hubris::HVOID VComponentLightReceiverItemData::ArrayLightIdGather(
	TArrayItemId& out_arrayLightsId
	)const
{
	out_arrayLightsId = m_arrayLightIdStatic;
	out_arrayLightsId.Insert( m_arrayLightIdDynamic.Begin(), m_arrayLightIdDynamic.End(), out_arrayLightsId.End() );

	return;
}

/**/
Hubris::HVOID VComponentLightReceiverItemData::ArrayLightIdStaticSet(
	const TArrayItemId& in_arrayLightIdStatic
	)
{
	m_arrayLightIdStatic = in_arrayLightIdStatic;
	return;
}

/**/