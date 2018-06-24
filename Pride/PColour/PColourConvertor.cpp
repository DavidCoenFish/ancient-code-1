//file: Pride/PColour/PColourConvertor.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PColour/PColourConvertor.h"
#include "Pride/PColour/PColour.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// public static methods
/**/
const PColourRgba PColourConvertor::U32ToRgba( const Hubris::HU32 in_value )
{
	PColourRgba returnValue;

	returnValue.RedSet( ( ( HU8* ) &in_value )[ 2 ] );
	returnValue.GreenSet( ( ( HU8* ) &in_value )[ 1 ] );
	returnValue.BlueSet( ( ( HU8* ) &in_value )[ 0 ] );
	returnValue.OpacitySet( ( ( HU8* ) &in_value )[ 3 ] );

	return returnValue;
}

/**/
const Hubris::HU32 PColourConvertor::RgbaToU32( const PColourRgba& in_rgba )
{
	Hubris::HU32 returnValue;

	( ( HU8* ) &returnValue )[ 2 ] = in_rgba.RedGet();
	( ( HU8* ) &returnValue )[ 1 ] = in_rgba.GreenGet();
	( ( HU8* ) &returnValue )[ 0 ] = in_rgba.BlueGet();
	( ( HU8* ) &returnValue )[ 3 ] = in_rgba.OpacityGet();

	return returnValue;
}

/**/
const PColourRgba PColourConvertor::RgbaToRgba( const PColourRealRgba& in_rgba )
{
	PColourRgba returnValue;

	returnValue.RedSet( RealToValue( in_rgba.RedGet() ) );
	returnValue.GreenSet( RealToValue( in_rgba.GreenGet() ) );
	returnValue.BlueSet( RealToValue( in_rgba.BlueGet() ) );
	returnValue.OpacitySet( RealToValue( in_rgba.OpacityGet() ) );

	return returnValue;
}

/**/
const PColourRealRgba PColourConvertor::RgbaToRgba( const PColourRgba& in_rgba )
{
	PColourRealRgba returnValue;

	returnValue.RedSet( ValueToReal( in_rgba.RedGet() ) );
	returnValue.GreenSet( ValueToReal( in_rgba.GreenGet() ) );
	returnValue.BlueSet( ValueToReal( in_rgba.BlueGet() ) );
	returnValue.OpacitySet( ValueToReal( in_rgba.OpacityGet() ) );

	return returnValue;
}

/**/
const PColourRgb PColourConvertor::RgbToRgb( const PColourRealRgb& in_rgba )
{
	PColourRgb returnValue;

	returnValue.RedSet( RealToValue( in_rgba.RedGet() ) );
	returnValue.GreenSet( RealToValue( in_rgba.GreenGet() ) );
	returnValue.BlueSet( RealToValue( in_rgba.BlueGet() ) );
	returnValue.OpacitySet( RealToValue( in_rgba.OpacityGet() ) );

	return returnValue;
}

/**/
const PColourRealRgb PColourConvertor::RgbToRgb( const PColourRgb& in_rgba )
{
	PColourRealRgb returnValue;

	returnValue.RedSet( ValueToReal( in_rgba.RedGet() ) );
	returnValue.GreenSet( ValueToReal( in_rgba.GreenGet() ) );
	returnValue.BlueSet( ValueToReal( in_rgba.BlueGet() ) );

	return returnValue;
}

/**/
const PColourRealRgb PColourConvertor::RgbaToRgb( const PColourRealRgba& in_rgba )
{
	PColourRealRgb returnValue;

	returnValue.RedSet( in_rgba.RedGet() * in_rgba.OpacityGet() );
	returnValue.GreenSet( in_rgba.GreenGet() * in_rgba.OpacityGet() );
	returnValue.BlueSet( in_rgba.BlueGet() * in_rgba.OpacityGet() );

	return returnValue;
}

/**/
const PColourRealRgba PColourConvertor::RgbToRgba( const PColourRealRgb& in_rgb, const Hubris::HREAL in_opacity )
{
	PColourRealRgba returnValue;

	returnValue.RedSet( in_rgb.RedGet() );
	returnValue.GreenSet( in_rgb.GreenGet() );
	returnValue.BlueSet( in_rgb.BlueGet() );
	returnValue.OpacitySet( in_opacity );

	return returnValue;
}

/**/
const PColourRealMono PColourConvertor::RgbaToMono( const PColourRealRgba& in_rgba )
{
	PColourRealMono returnValue;

	returnValue.MonoSet( ( in_rgba.RedGet() + in_rgba.GreenGet() + in_rgba.BlueGet() ) * in_rgba.OpacityGet() * 0.3333333333F );

	return returnValue;
}

/**/
const PColourRealRgba PColourConvertor::MonoToRgba( const PColourRealMono& in_mono, const Hubris::HREAL in_opacity )
{
	PColourRealRgba returnValue;

	returnValue.RedSet( in_mono.MonoGet() );
	returnValue.GreenSet( in_mono.MonoGet() );
	returnValue.BlueSet( in_mono.MonoGet() );
	returnValue.OpacitySet( in_opacity );

	return returnValue;
}

/**/
const PColourRealMono PColourConvertor::RgbToMono( const PColourRealRgb& in_rgb )
{
	PColourRealMono returnValue;

	returnValue.MonoSet( ( in_rgb.RedGet() + in_rgb.GreenGet() + in_rgb.BlueGet() ) * 0.3333333333F );

	return returnValue;
}

/**/
const PColourRealRgb PColourConvertor::MonoToRgb( const PColourRealMono& in_mono )
{
	PColourRealRgb returnValue;

	returnValue.RedSet( in_mono.MonoGet() );
	returnValue.GreenSet( in_mono.MonoGet() );
	returnValue.BlueSet( in_mono.MonoGet() );

	return returnValue;
}

/**/
const PColourRgb PColourConvertor::RgbaToRgb( const PColourRgba& in_rgba )
{
	PColourRgb returnValue;
	const HREAL mul = ValueToReal( in_rgba.OpacityGet() );

	returnValue.RedSet( RealToValue( ValueToReal( in_rgba.RedGet() ) * mul ) );
	returnValue.GreenSet( RealToValue( ValueToReal( in_rgba.GreenGet() ) * mul ) );
	returnValue.BlueSet( RealToValue( ValueToReal( in_rgba.BlueGet() ) * mul ) );

	return returnValue;
}

/**/
const PColourRgba PColourConvertor::RgbToRgba( const PColourRgb& in_rgb, const Hubris::HU8 in_opacity )
{
	PColourRgba returnValue;

	returnValue.RedSet( in_rgb.RedGet() );
	returnValue.GreenSet( in_rgb.GreenGet() );
	returnValue.BlueSet( in_rgb.BlueGet() );
	returnValue.OpacitySet( in_opacity );

	return returnValue;
}

/**/
const PColourMono PColourConvertor::RgbaToMono( const PColourRgba& in_rgba )
{
	PColourMono returnValue;
	const HREAL mul = ValueToReal( in_rgba.OpacityGet() );
	const HU8 value = RealToValue( ( ValueToReal( in_rgba.RedGet() ) + ValueToReal( in_rgba.GreenGet() ) + ValueToReal( in_rgba.BlueGet() ) ) * 0.333333F * mul );

	returnValue.MonoSet( value );

	return returnValue;
}

/**/
const PColourRgba PColourConvertor::MonoToRgba( const PColourMono& in_mono, const Hubris::HU8 in_opacity )
{
	PColourRgba returnValue;

	returnValue.RedSet( in_mono.MonoGet() );
	returnValue.GreenSet( in_mono.MonoGet() );
	returnValue.BlueSet( in_mono.MonoGet() );
	returnValue.OpacitySet( in_opacity );

	return returnValue;
}

/**/
const PColourMono PColourConvertor::RgbToMono( const PColourRgb& in_rgb )
{
	PColourMono returnValue;
	const HU8 value = RealToValue( ( ValueToReal( in_rgb.RedGet() ) + ValueToReal( in_rgb.GreenGet() ) + ValueToReal( in_rgb.BlueGet() ) ) * 0.333333F );

	returnValue.MonoSet( value );

	return returnValue;
}

/**/
const PColourRgb PColourConvertor::MonoToRgb( const PColourMono& in_mono )
{
	PColourRgb returnValue;

	returnValue.RedSet( in_mono.MonoGet() );
	returnValue.GreenSet( in_mono.MonoGet() );
	returnValue.BlueSet( in_mono.MonoGet() );

	return returnValue;
}

/**/
Hubris::HREAL PColourConvertor::ValueToReal( const Hubris::HU8 in_value )
{
	return( static_cast< HREAL >( in_value ) * 0.003921568627450980392156862745098F );
}

/**/
Hubris::HU8 PColourConvertor::RealToValue( const Hubris::HREAL in_value )
{
	HSINT intValue = static_cast< HSINT >( ( in_value * 255.0F ) + 0.5F );
	intValue = HMathUtility::Maximum( 0, intValue );
	intValue = HMathUtility::Minimum( 255, intValue );
	return static_cast< HU8 >( intValue );
}

/**/