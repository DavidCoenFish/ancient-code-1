//file: Pride/PColour/PColourConvertor.h
#ifndef _P_COLOUR_CONVERTOR_H_
#define _P_COLOUR_CONVERTOR_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 1 >PColourMono;
	typedef PColour< Hubris::HU8, 3 >PColourRgb;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;

	typedef PColour< Hubris::HREAL, 1 >PColourRealMono;
	typedef PColour< Hubris::HREAL, 3 >PColourRealRgb;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PColourConvertor
	{
		///////////////////////////////////////////////////////
		// public static methods
		/*
			policy, when converting from a format with alpha to a format without alpha,
			alpha is burnt into the colour (ie colour * opacity )
		*/
	public:
		//HU8 rgba to HSINT
		static const PColourRgba U32ToRgba( const Hubris::HU32 in_value );
		static const Hubris::HU32 RgbaToU32( const PColourRgba& in_rgba );

		//HU8 and REAL conversion
		static const PColourRgba RgbaToRgba( const PColourRealRgba& in_rgba );
		static const PColourRealRgba RgbaToRgba( const PColourRgba& in_rgba );

		//HU8 and REAL conversion
		static const PColourRgb RgbToRgb( const PColourRealRgb& in_rgba );
		static const PColourRealRgb RgbToRgb( const PColourRgb& in_rgba );

		//Between REAL rgba, rgb, mono
		static const PColourRealRgb RgbaToRgb( const PColourRealRgba& in_rgba );
		static const PColourRealRgba RgbToRgba( const PColourRealRgb& in_rgb, const Hubris::HREAL in_opacity = 1.0F /* Hubris::HVariablesMath::UnitGet< HREAL >() */ );

		static const PColourRealMono RgbaToMono( const PColourRealRgba& in_rgba );
		static const PColourRealRgba MonoToRgba( const PColourRealMono& in_mono, const Hubris::HREAL in_opacity = 1.0F /* Hubris::HVariablesMath::UnitGet< HREAL >() */ );

		static const PColourRealMono RgbToMono( const PColourRealRgb& in_rgb );
		static const PColourRealRgb MonoToRgb( const PColourRealMono& in_mono );

		//Between HU8 rgba, rgb, mono
		static const PColourRgb RgbaToRgb( const PColourRgba& in_rgba );
		static const PColourRgba RgbToRgba( const PColourRgb& in_rgb, const Hubris::HU8 in_opacity = 255 );

		static const PColourMono RgbaToMono( const PColourRgba& in_rgba );
		static const PColourRgba MonoToRgba( const PColourMono& in_mono, const Hubris::HU8 in_opacity = 255 );

		static const PColourMono RgbToMono( const PColourRgb& in_rgb );
		static const PColourRgb MonoToRgb( const PColourMono& in_mono );

		//expose HU8 and REAL conversion
		static Hubris::HREAL ValueToReal( const Hubris::HU8 in_value );
		static Hubris::HU8 RealToValue( const Hubris::HREAL in_value );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PColourConvertor();

	};

	/**/
};

#endif // _P_COLOUR_CONVERTOR_H_