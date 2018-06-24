//file: Vanity/VComponentLightEmitter/VComponentLightEmitterItemData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitterItemData.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentLightEmitterItemData::VComponentLightEmitterItemData( const VComponentLightEmitterItemData& in_src )
: m_mode( HCOMMON_INVALID_INDEX )
, m_diffuse()
, m_falloffExponent( 0.0F )
, m_radius( 0.0F )
{
	( *this ) = in_src;
	return;
}

/**/
VComponentLightEmitterItemData::VComponentLightEmitterItemData()
: m_mode( HCOMMON_INVALID_INDEX )
, m_diffuse()
, m_falloffExponent( 0.0F )
, m_radius( 0.0F )
{
	return;
}

/**/
VComponentLightEmitterItemData::~VComponentLightEmitterItemData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VComponentLightEmitterItemData& VComponentLightEmitterItemData::operator=( const VComponentLightEmitterItemData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_mode = in_rhs.m_mode;
		m_diffuse = in_rhs.m_diffuse;
		m_falloffExponent = in_rhs.m_falloffExponent;
		m_radius = in_rhs.m_radius;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VComponentLightEmitterItemData::operator==( const VComponentLightEmitterItemData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_mode == in_rhs.m_mode );
		match &= ( m_diffuse == in_rhs.m_diffuse );
		match &= ( m_falloffExponent == in_rhs.m_falloffExponent );
		match &= ( m_radius == in_rhs.m_radius );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentLightEmitterItemData::operator!=( const VComponentLightEmitterItemData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public accessors
/**/

/**/
