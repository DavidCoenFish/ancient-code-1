//file: Pride/PLight/PLightOperator.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLight/PLightOperator.h"

#include "Pride/PLight/PLight.h"
#include "Pride/PColour/PColour_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/////////////////////////////////////////////////////////////////
// static local methods
/**/
template< typename IN_TYPE >
static const Hubris::HBOOL LocalCmp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	if( in_lhs.ActiveGet() != in_rhs.ActiveGet() )
	{
		return( in_lhs.ActiveGet() < in_rhs.ActiveGet() );
	}
	if( in_lhs.TypeGet() != in_rhs.TypeGet() )
	{
		return( in_lhs.TypeGet() < in_rhs.TypeGet() );
	}
	if( in_lhs.StrengthGet() != in_rhs.StrengthGet() )
	{
		return( in_lhs.StrengthGet() < in_rhs.StrengthGet() );
	}
	if( in_lhs.RadiusGet() != in_rhs.RadiusGet() )
	{
		return( in_lhs.RadiusGet() < in_rhs.RadiusGet() );
	}
	if( in_lhs.AmbientGet() != in_rhs.AmbientGet() )
	{
		return( in_lhs.AmbientGet() < in_rhs.AmbientGet() );
	}
	if( in_lhs.DiffuseGet() != in_rhs.DiffuseGet() )
	{
		return( in_lhs.DiffuseGet() < in_rhs.DiffuseGet() );
	}
	if( in_lhs.SpecularGet() != in_rhs.SpecularGet() )
	{
		return( in_lhs.SpecularGet() < in_rhs.SpecularGet() );
	}
	if( in_lhs.ExponentGet() != in_rhs.ExponentGet() )
	{
		return( in_lhs.ExponentGet() < in_rhs.ExponentGet() );
	}
	if( in_lhs.SpotAngleGet() != in_rhs.SpotAngleGet() )
	{
		return( in_lhs.SpotAngleGet() < in_rhs.SpotAngleGet() );
	}
	if( in_lhs.SpotExponentGet() != in_rhs.SpotExponentGet() )
	{
		return( in_lhs.SpotExponentGet() < in_rhs.SpotExponentGet() );
	}
	if( in_lhs.ShadowFlagGet() != in_rhs.ShadowFlagGet() )
	{
		return( in_lhs.ShadowFlagGet() < in_rhs.ShadowFlagGet() );
	}
	if( in_lhs.ShadowQualityGet() != in_rhs.ShadowQualityGet() )
	{
		return( in_lhs.ShadowQualityGet() < in_rhs.ShadowQualityGet() );
	}

	return HFALSE;
}

/////////////////////////////////////////////////////////////////
// global operators
/**/
const Hubris::HBOOL Pride::operator<( const PLightMono& in_lhs, const PLightMono& in_rhs )
{
	return( LocalCmp( in_lhs, in_rhs ) );
}

/**/
const Hubris::HBOOL Pride::operator<( const PLightRgb& in_lhs, const PLightRgb& in_rhs )
{
	return( LocalCmp( in_lhs, in_rhs ) );
}

/**/
const Hubris::HBOOL Pride::operator<( const PLightRgba& in_lhs, const PLightRgba& in_rhs )
{
	return( LocalCmp( in_lhs, in_rhs ) );
}

/**/
const Hubris::HBOOL Pride::operator<( const PLightRealMono& in_lhs, const PLightRealMono& in_rhs )
{
	return( LocalCmp( in_lhs, in_rhs ) );
}

/**/
const Hubris::HBOOL Pride::operator<( const PLightRealRgb& in_lhs, const PLightRealRgb& in_rhs )
{
	return( LocalCmp( in_lhs, in_rhs ) );
}

/**/
const Hubris::HBOOL Pride::operator<( const PLightRealRgba& in_lhs, const PLightRealRgba& in_rhs )
{
	return( LocalCmp( in_lhs, in_rhs ) );
}

/**/
