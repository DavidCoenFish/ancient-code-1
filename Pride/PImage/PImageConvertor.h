//file: Pride/PImage/PImageConvertor.h
#ifndef _P_IMAGE_CONVERTOR_H_
#define _P_IMAGE_CONVERTOR_H_

#include< Hubris/HCommon/HCommon_Export.h >

/////////////////////////////////////////////////////////////////
// forward declarations
/**/
struct tagBITMAPINFO;
typedef tagBITMAPINFO BITMAPINFO;

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PImage;
	typedef PImage< Hubris::HU8, 1 >PImageMono;
	typedef PImage< Hubris::HU8, 3 >PImageRgb;
	typedef PImage< Hubris::HU8, 4 >PImageRgba;

	typedef PImage< Hubris::HREAL, 1 >PImageRealMono;
	typedef PImage< Hubris::HREAL, 3 >PImageRealRgb;
	typedef PImage< Hubris::HREAL, 4 >PImageRealRgba;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PImageConvertor
	{
		///////////////////////////////////////////////////////
		// public static methods
	public:
		static void RgbToRgba( PImageRgba& out_rgba, const PImageRgb& in_rgb, const Hubris::HU8 in_opacity = 255 );
		static void MonoToRgba( PImageRgba& out_rgba, const PImageMono& in_mono, const Hubris::HU8 in_opacity = 255 );

		static void RgbaAlphaToMono( PImageMono& out_mono, const PImageRgba& in_rgba );

		static void BitmapToRgba( PImageRgba& out_rgba, const BITMAPINFO* const in_bitmapInfo );

		static void RealRgbToRgba( PImageRgba& out_rgba, const PImageRealRgb& in_realRgb );
		static void RealRgbaToRgba( PImageRgba& out_rgba, const PImageRealRgba& in_realRgba );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PImageConvertor();

	};
	/**/
	
};

#endif // _P_IMAGE_CONVERTOR_H_