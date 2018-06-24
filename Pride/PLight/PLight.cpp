//file: Pride/PLight/PLight.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLight/PLight.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TLightType
{
	enum TEnum
	{
		TAmbient = 0,
		TPoint,
		TDirect,
		TSpot,

		TCount
	};
};
struct TShadowFlag
{
	enum TEnum
	{
		TNone = 0,
		TMap,

		TCount
	};
};
struct TShadowQuality
{
	enum TEnum
	{
		TLow = 0,
		TMedium,
		THigh,

		TCount
	};
};

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PLight< HU8, 4 >;
template class Pride::PLight< HU8, 3 >;
template class Pride::PLight< HU8, 1 >;

template class Pride::PLight< HREAL, 4 >;
template class Pride::PLight< HREAL, 3 >;
template class Pride::PLight< HREAL, 1 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::PLight( const PLight& in_src )
: m_active( HFALSE )
, m_type( HCOMMON_INVALID_INDEX )
, m_strength( HVariablesMath::ZeroGet< HREAL >() )
, m_radius( HVariablesMath::ZeroGet< HREAL >() )
, m_ambient()
, m_diffuse()
, m_specular()
, m_exponent( HVariablesMath::ZeroGet< HREAL >() )
, m_spotAngle( HVariablesMath::ZeroGet< HREAL >() )
, m_spotExponent( HVariablesMath::ZeroGet< HREAL >() )
, m_shadowFlag( HCOMMON_INVALID_INDEX )
, m_shadowQuality( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::PLight(
	const Hubris::HBOOL in_active,
	const Hubris::HSINT in_type,
	const Hubris::HREAL in_strength,
	const Hubris::HREAL in_radius,
	const TColour& in_ambient,
	const TColour& in_diffuse,
	const TColour& in_specular,
	const Hubris::HREAL in_exponent,
	const Hubris::HREAL in_spotAngle,
	const Hubris::HREAL in_spotExponent,
	const Hubris::HSINT in_shadowFlag,
	const Hubris::HSINT in_shadowQuality
	)
: m_active( in_active )
, m_type( in_type )
, m_strength( in_strength )
, m_radius( in_radius )
, m_ambient( in_ambient )
, m_diffuse( in_diffuse )
, m_specular( in_specular )
, m_exponent( in_exponent )
, m_spotAngle( in_spotAngle )
, m_spotExponent( in_spotExponent )
, m_shadowFlag( in_shadowFlag )
, m_shadowQuality( in_shadowQuality )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::PLight()
: m_active( HFALSE )
, m_type( HCOMMON_INVALID_INDEX )
, m_strength( HVariablesMath::ZeroGet< HREAL >() )
, m_radius( HVariablesMath::ZeroGet< HREAL >() )
, m_ambient()
, m_diffuse()
, m_specular()
, m_exponent( HVariablesMath::ZeroGet< HREAL >() )
, m_spotAngle( HVariablesMath::ZeroGet< HREAL >() )
, m_spotExponent( HVariablesMath::ZeroGet< HREAL >() )
, m_shadowFlag( HCOMMON_INVALID_INDEX )
, m_shadowQuality( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::~PLight()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const PLight< IN_TYPE, IN_CHANNEL_COUNT >& Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::operator=( const PLight< IN_TYPE, IN_CHANNEL_COUNT >& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_active = in_rhs.m_active;
		m_type = in_rhs.m_type;
		m_strength = in_rhs.m_strength;
		m_radius = in_rhs.m_radius;
		m_ambient = in_rhs.m_ambient;
		m_diffuse = in_rhs.m_diffuse;
		m_specular = in_rhs.m_specular;
		m_exponent = in_rhs.m_exponent;
		m_spotAngle = in_rhs.m_spotAngle;
		m_spotExponent = in_rhs.m_spotExponent;
		m_shadowFlag = in_rhs.m_shadowFlag;
		m_shadowQuality = in_rhs.m_shadowQuality;
	}

	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HBOOL Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::operator==( const PLight< IN_TYPE, IN_CHANNEL_COUNT >& in_rhs )const
{
	HBOOL match = HFALSE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_active == in_rhs.m_active );
		match &= ( m_type == in_rhs.m_type );
		match &= ( m_strength == in_rhs.m_strength );
		match &= ( m_radius == in_rhs.m_radius );
		match &= ( m_ambient == in_rhs.m_ambient );
		match &= ( m_diffuse == in_rhs.m_diffuse );
		match &= ( m_specular == in_rhs.m_specular );
		match &= ( m_exponent == in_rhs.m_exponent );
		match &= ( m_spotAngle == in_rhs.m_spotAngle );
		match &= ( m_spotExponent == in_rhs.m_spotExponent );
		match &= ( m_shadowFlag == in_rhs.m_shadowFlag );
		match &= ( m_shadowQuality == in_rhs.m_shadowQuality );
	}

	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HBOOL Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::operator!=( const PLight< IN_TYPE, IN_CHANNEL_COUNT >& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// static public accessors
/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::TypeAmbientGet()
{
	return( TLightType::TAmbient );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::TypePointGet()
{
	return( TLightType::TPoint );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::TypeDirectGet()
{
	return( TLightType::TDirect );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::TypeSpotGet()
{
	return( TLightType::TSpot );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::ShadowFlagNoneGet()
{
	return( TShadowFlag::TNone );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::ShadowFlagMapGet()
{
	return( TShadowFlag::TMap );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::ShadowQualityLowGet()
{
	return( TShadowQuality::TLow );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::ShadowQualityMediumGet()
{
	return( TShadowQuality::TMedium );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
const Hubris::HSINT Pride::PLight< IN_TYPE, IN_CHANNEL_COUNT >::ShadowQualityHighGet()
{
	return( TShadowQuality::THigh );
}

/**/

