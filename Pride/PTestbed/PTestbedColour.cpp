//file: Pride/PTestbed/PTestbedColour.cpp

#include "Pride/PTestbed/PTestbedColour.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedColour()
{
	HBOOL success = HTRUE;

	//PColour( const PColour& in_src );
	//PColour( const TVector& in_data );
	//PColour( 
	//	const IN_TYPE in_red,
	//	const IN_TYPE in_green,
	//	const IN_TYPE in_blue,
	//	const IN_TYPE in_opacity
	//	);
	//PColour( 
	//	const IN_TYPE in_red,
	//	const IN_TYPE in_green,
	//	const IN_TYPE in_blue
	//	);
	//PColour( const IN_TYPE in_mono = Hubris::HVariablesMath< IN_TYPE >::s_zero );
	//~PColour();
	//const PColour& operator=( const PColour& in_rhs );
	//Hubris::HBOOL operator==( const PColour& in_rhs )const;
	//Hubris::HBOOL operator!=( const PColour& in_rhs )const;
	{
		PColourRgba colour0( 120, 20, 50, 200 );
		PColourRgba colour1( colour0 );
		PColourRgba colour2 = colour0;
		PColourRgba colour3( 120, 20, 50 );
		PColourRgba colour4( 10 );
		PColourRgba colour5;
		PColourRgb colour6( 120, 20, 50 );

		success &= ( colour0 == colour1 );
		success &= ( colour1 == colour0 );

		success &= ( colour0 == colour2 );
		success &= ( colour2 == colour0 );

		success &= ( colour0 != colour3 );
		success &= ( colour3 != colour0 );

		success &= !( colour0 != colour2 );
		success &= !( colour2 != colour0 );

		success &= !( colour0 == colour3 );
		success &= !( colour3 == colour0 );

		success &= ( colour3 == PColourRgba( 120, 20, 50, 0 ) );
		success &= ( colour4 == PColourRgba( 10, 10, 10, 10 ) );
		success &= ( colour5 == PColourRgba( 0, 0, 0, 0 ) );

		success &= ( colour6 == PColourRgb( 120, 20, 50 ) );
	}

	//IN_TYPE MonoGet()const;
	//void MonoSet( const IN_TYPE in_mono );
	{
		PColourRgba colour0( 10 );
		PColourMono colour1( 20 );

		success &= ( 10 == colour0.MonoGet() );
		colour0.MonoSet( 200 );
		success &= ( 200 == colour0.MonoGet() );
		success &= ( colour0 == PColourRgba( 200, 200, 200, 200 ) );

		success &= ( 20 == colour1.MonoGet() );
		colour1.MonoSet( 130 );
		success &= ( 130 == colour1.MonoGet() );
		success &= ( colour1 == PColourMono( 130 ) );
	}

	//IN_TYPE RedGet()const;
	//void RedSet( const IN_TYPE in_red );
	//IN_TYPE GreenGet()const;
	//void GreenSet( const IN_TYPE in_green );
	//IN_TYPE BlueGet()const;
	//void BlueSet( const IN_TYPE in_blue );
	//IN_TYPE OpacityGet()const;
	//void OpacitySet( const IN_TYPE in_opacity );
	{
		PColourRgba colour0( 10, 50, 200, 60 );

		success &= ( 10 == colour0.RedGet() );
		colour0.RedSet( 15 );
		success &= ( 15 == colour0.RedGet() );
		success &= ( colour0 == PColourRgba( 15, 50, 200, 60 ) );

		success &= ( 50 == colour0.GreenGet() );
		colour0.GreenSet( 55 );
		success &= ( 55 == colour0.GreenGet() );
		success &= ( colour0 == PColourRgba( 15, 55, 200, 60 ) );

		success &= ( 200 == colour0.BlueGet() );
		colour0.BlueSet( 205 );
		success &= ( 205 == colour0.BlueGet() );
		success &= ( colour0 == PColourRgba( 15, 55, 205, 60 ) );

		success &= ( 60 == colour0.OpacityGet() );
		colour0.OpacitySet( 65 );
		success &= ( 65 == colour0.OpacityGet() );
		success &= ( colour0 == PColourRgba( 15, 55, 205, 65 ) );
	}

	//const TVector& DataGet()const{ return m_data; }
	//void DataSet( const TVector& in_data ){ m_data = in_data; return; }
	{
		PColourRgba colour0( 10, 50, 200, 60 );
		HVectorU4 data0 = colour0.DataGet();

		PColourRgba colour1;
		colour1.DataSet( data0 );

		success &= ( colour0 == colour1 );
		success &= ( data0 == colour1.DataGet() );

		success &= ( colour0 != PColourRgba() );
	}


	PTESTBED_VALIDATE_STATUS( "PColour", success );

	return success;
}

/**/
static const HBOOL LocalTestbedColourConvertor()
{
	HBOOL success = HTRUE;

	//PColourConvertor
	//static const PColourRgba U32ToRgba( const Hubris::HU32 in_value );
	//static const Hubris::HU32 RgbaToU32( const PColourRgba& in_rgba );
	{
		const PColourRgba colour0( 5, 10, 215, 220 );
		const HU32 value0 = PColourConvertor::RgbaToU32( colour0 );
		const PColourRgba colour1 = PColourConvertor::U32ToRgba( value0 );

		success &= ( colour0 == colour1 );
	}

	//static const PColourRgba RgbaToRgba( const PColourRealRgba& in_rgba );
	//static const PColourRealRgba RgbaToRgba( const PColourRgba& in_rgba );
	{
		const PColourRgba colour0( 5, 10, 215, 220 );
		const PColourRealRgba colour1 = PColourConvertor::RgbaToRgba( colour0 );
		const PColourRgba colour2 = PColourConvertor::RgbaToRgba( colour1 );

		success &= ( colour0 == colour2 );
	}

	//static const PColourRealRgb RgbaToRgb( const PColourRealRgba& in_rgba );
	//static const PColourRealRgba RgbToRgba( const PColourRealRgb& in_rgb, const Hubris::HREAL in_opacity = Hubris::HVariablesMath::UnitGet< HREAL >() );
	//static const PColourRealMono RgbaToMono( const PColourRealRgba& in_rgba );
	//static const PColourRealRgba MonoToRgba( const PColourRealMono& in_mono, const Hubris::HREAL in_opacity = Hubris::HVariablesMath::UnitGet< HREAL >() );
	//static const PColourRealMono RgbToMono( const PColourRealRgb& in_rgb );
	//static const PColourRealRgb MonoToRgb( const PColourRealMono& in_mono );
	{
		const PColourRealRgba colour0( -1.5F, 0.9F, 0.8F, 1.0F ); 
		const PColourRealRgba colour1( -1.5F, 0.9F, 0.8F, 0.5F ); 
		const PColourRealRgb colour3 = PColourConvertor::RgbaToRgb( colour0 );
		const PColourRealRgb colour4 = PColourConvertor::RgbaToRgb( colour1 );
		const PColourRealMono colour5 = PColourConvertor::RgbaToMono( colour0 );
		const PColourRealMono colour6 = PColourConvertor::RgbaToMono( colour1 );

		const PColourRealRgba colour7 = PColourConvertor::RgbToRgba( colour3 );
		const PColourRealRgba colour8 = PColourConvertor::RgbToRgba( colour4 );
		const PColourRealRgba colour9 = PColourConvertor::MonoToRgba( colour5 );
		const PColourRealRgba colour10 = PColourConvertor::MonoToRgba( colour6 );

		const PColourRealRgb colour11 = PColourConvertor::MonoToRgb( colour5 );
		const PColourRealRgb colour12 = PColourConvertor::MonoToRgb( colour6 );
		const PColourRealMono colour13 = PColourConvertor::RgbToMono( colour11 );
		const PColourRealMono colour14 = PColourConvertor::RgbToMono( colour12 );

		success &= ( colour7 == PColourRealRgba( -1.5F, 0.9F, 0.8F, 1.0F ) );
		success &= ( colour8 == PColourRealRgba( -0.75F, 0.45F, 0.4F, 1.0F ) );

		success &= ( colour9 == PColourRealRgba( 0.066666663F, 0.066666663F, 0.066666663F, 1.0F ) );
		success &= ( colour10 == PColourRealRgba( 0.033333333F, 0.033333333F, 0.033333333F, 1.0F ) );

		success &= ( colour5 == colour13 );
		success &= ( colour6 == colour14 );
	}


	//static const PColourRgb RgbaToRgb( const PColourRgba& in_rgba );
	//static const PColourRgba RgbToRgba( const PColourRgb& in_rgb, const Hubris::HU8 in_opacity = 255 );
	//static const PColourMono RgbaToMono( const PColourRgba& in_rgba );
	//static const PColourRgba MonoToRgba( const PColourMono& in_mono, const Hubris::HU8 in_opacity = 255 );
	//static const PColourMono RgbToMono( const PColourRgb& in_rgb );
	//static const PColourRgb MonoToRgb( const PColourMono& in_mono );
	{
		const PColourRgba colour0( 64, 128, 207, 255 ); 
		const PColourRgba colour1( 64, 128, 207, 128 ); 
		const PColourRgb colour3 = PColourConvertor::RgbaToRgb( colour0 );
		const PColourRgb colour4 = PColourConvertor::RgbaToRgb( colour1 );
		const PColourMono colour5 = PColourConvertor::RgbaToMono( colour0 );
		const PColourMono colour6 = PColourConvertor::RgbaToMono( colour1 );

		const PColourRgba colour7 = PColourConvertor::RgbToRgba( colour3 );
		const PColourRgba colour8 = PColourConvertor::RgbToRgba( colour4 );
		const PColourRgba colour9 = PColourConvertor::MonoToRgba( colour5 );
		const PColourRgba colour10 = PColourConvertor::MonoToRgba( colour6 );

		const PColourRgb colour11 = PColourConvertor::MonoToRgb( colour5 );
		const PColourRgb colour12 = PColourConvertor::MonoToRgb( colour6 );
		const PColourMono colour13 = PColourConvertor::RgbToMono( colour11 );
		const PColourMono colour14 = PColourConvertor::RgbToMono( colour12 );

		success &= ( colour7 == PColourRgba( 64, 128, 207, 255 ) );
		success &= ( colour8 == PColourRgba( 32, 64, 104, 255 ) );

		success &= ( colour9 == PColourRgba( 133, 133, 133, 255 ) );
		success &= ( colour10 == PColourRgba( 67, 67, 67, 255 ) );

		success &= ( colour5 == colour13 );
		success &= ( colour6 == colour14 );
	}

	//static Hubris::HREAL ValueToReal( const Hubris::HU8 in_value );
	//static Hubris::HU8 RealToValue( const Hubris::HREAL in_value );
	{
		const HU8 value0 = 0;
		const HU8 value1 = 168;
		const HU8 value2 = 255;

		const HREAL value3 = PColourConvertor::ValueToReal( value0 );
		const HREAL value4 = PColourConvertor::ValueToReal( value1 );
		const HREAL value5 = PColourConvertor::ValueToReal( value2 );

		const HU8 value6 = PColourConvertor::RealToValue( value3 );
		const HU8 value7 = PColourConvertor::RealToValue( value4 );
		const HU8 value8 = PColourConvertor::RealToValue( value5 );

		success &= ( value0 == value6 );
		success &= ( value1 == value7 );
		success &= ( value2 == value8 );
	}

	PTESTBED_VALIDATE_STATUS( "PColourConvertor", success );

	return success;
}

/**/
static const HBOOL LocalTestbedColourTrait()
{
	HBOOL success = HTRUE;

	//HTRAIT_EMPTY_HEADER( Pride::PColourMono );
	//HTRAIT_EMPTY_HEADER( Pride::PColourRgb );
	//HTRAIT_EMPTY_HEADER( Pride::PColourRgba );
	{
		success &= ( HTraitEmpty< PColourMono >::EmptyGet() == PColourMono() );
		success &= ( HTraitEmpty< PColourRgb >::EmptyGet() == PColourRgb() );
		success &= ( HTraitEmpty< PColourRgba >::EmptyGet() == PColourRgba() );
	}

	//HString HTraitStringIn( const Pride::PColourRgb& in_data );
	//Pride::PColourRgb HTraitStringOut( const HString& in_data );
	{
		const PColourRgb colour0( 5, 255, 127 );
		HString string0 = HTraitStringIn( colour0 );
		PColourRgb colour1;
		HTraitStringOut< PColourRgb >( colour1, string0 );

		success &= ( colour0 == colour1 );
	}
	{
		const PColourRgba colour0( 5, 255, 127, 3 );
		HString string0 = HTraitStringIn( colour0 );
		PColourRgba colour1;
		HTraitStringOut( colour1, string0 );

		success &= ( colour0 == colour1 );
	}

	PTESTBED_VALIDATE_STATUS( "PColourTrait", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedColour()
{
	PTESTBED_VALIDATE_START( "TestbedColour" );
	HBOOL success = HTRUE;

	success &= LocalTestbedColour();
	success &= LocalTestbedColourConvertor();
	success &= LocalTestbedColourTrait();

	return success;
}

/**/