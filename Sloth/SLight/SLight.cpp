//file: Sloth/SLight/SLight.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SLight/SLight.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
struct TMode
{
	enum TEnum
	{
		TPoint = 0,
		TDirect,
		TSpot,

		TCount
	};
};

///////////////////////////////////////////////////////
// creation
/**/
SLight::SLight( const SLight& in_src )
: m_mode( TMode::TCount )
, m_diffuse()
, m_falloffExponent( 1.0F )
, m_radius( 0.0F )
, m_position()
, m_direction()
{
	( *this ) = in_src;
	return;
}

/**/
SLight::SLight(
	const Hubris::HSINT in_mode,
	const Pride::PColourRealRgb& in_diffuse,
	const Hubris::HVectorR3& in_position,
	const Hubris::HREAL in_radius,
	const Hubris::HREAL in_falloffExponent
	)
: m_mode( in_mode )
, m_diffuse( in_diffuse )
, m_falloffExponent( in_falloffExponent )
, m_radius( in_radius )
, m_position( in_position )
, m_direction()
{
	return;
}

/**/
SLight::SLight()
: m_mode( TMode::TCount )
, m_diffuse()
, m_falloffExponent( 1.0F )
, m_radius( 0.0F )
, m_position()
, m_direction()
{
	return;
}

/**/
SLight::~SLight()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const SLight& SLight::operator=( const SLight& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_mode = in_rhs.m_mode;
		m_diffuse = in_rhs.m_diffuse;
		m_falloffExponent = in_rhs.m_falloffExponent;
		m_radius = in_rhs.m_radius;
		m_position = in_rhs.m_position;
		m_direction = in_rhs.m_direction;
	}

	return( *this );
}

/**/
const Hubris::HBOOL SLight::operator==( const SLight& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_mode == in_rhs.m_mode );
		match &= ( m_diffuse == in_rhs.m_diffuse );
		match &= ( m_falloffExponent == in_rhs.m_falloffExponent );
		match &= ( m_radius == in_rhs.m_radius );
		match &= ( m_position == in_rhs.m_position );
		match &= ( m_direction == in_rhs.m_direction );
	}

	return( match );
}
/**/
const Hubris::HBOOL SLight::operator!=( const SLight& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL SLight::DirectionValidTest()const
{
	switch( m_mode )
	{
	default:
		{
			break;
		}
	case TMode::TDirect:
	case TMode::TSpot:
		{
			return HTRUE;
		}
	}

	return HTRUE;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT SLight::ModePointGet()
{
	return( TMode::TPoint );
}

/**/
const Hubris::HSINT SLight::ModeDirectGet()
{
	return( TMode::TDirect );
}

/**/
const Hubris::HSINT SLight::ModeSpotGet()
{
	return( TMode::TSpot );
}

/**/
