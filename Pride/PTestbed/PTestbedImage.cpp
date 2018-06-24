//file: Pride/PTestbed/PTestbedImage.cpp

#include "Pride/PTestbed/PTestbedImage.h"

//#include <WINDOWS.H>

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
/**/
static const PImageMono LocalImageCreateMono()
{
	const HVectorS2 vector0 = PImageMono::IndexCreate( 16, 8 );
	PImageMono image0( vector0 );
	for( HSINT indexHeight = 0; indexHeight < 8; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < 16; ++indexWidth )
		{
			image0.ColourSet
			( 
				PImageMono::IndexCreate( indexWidth, indexHeight ),
				PColourMono( HU8( ( ( indexHeight * 8 ) + indexWidth ) & 0xFF ) )
			);
		}
	}

	return image0;
}

/**/
static const PImageRgb LocalImageCreateRgb()
{
	const HVectorS2 vector0 = PImageMono::IndexCreate( 16, 8 );
	PImageRgb image0( vector0 );
	for( HSINT indexHeight = 0; indexHeight < 8; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < 16; ++indexWidth )
		{
			image0.ColourSet
			( 
				PImageRgb::IndexCreate( indexWidth, indexHeight ),
				PColourRgb( 
					HU8( ( ( indexHeight * 8 ) + indexWidth ) & 0xFF ),
					150,
					200
				)
			);
		}
	}

	return image0;
}

/**/
static const PImageRgba LocalImageCreateRgba()
{
	const HVectorS2 vector0 = PImageMono::IndexCreate( 16, 8 );
	PImageRgba image0( vector0 );
	for( HSINT indexHeight = 0; indexHeight < 8; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < 16; ++indexWidth )
		{
			image0.ColourSet
			( 
				PImageRgba::IndexCreate( indexWidth, indexHeight ),
				PColourRgba( 
					HU8( ( ( indexHeight * 8 ) + indexWidth ) & 0xFF ),
					10,
					150,
					200
				)
			);
		}
	}

	return image0;
}

/**/
static const HBOOL LocalTestbedImage()
{
	HBOOL success = HTRUE;

	//PImage( const PImage& in_src );
	//PImage( const Hubris::HVectorS2& in_size = Hubris::HVectorS2() );
	//~PImage();
	//const PImage& operator=( const PImage& in_rhs );
	//Hubris::HBOOL operator==( const PImage& in_rhs )const;
	//Hubris::HBOOL operator!=( const PImage& in_rhs )const;
	{
		const PImageRgba image0( HMatrixConstructor::HVectorS2Construct( 16, 8 ) ); 
		const PImageRgba image1( image0 );
		const PImageRgba image2 = image0;
		const PImageRgba image3;

		success &= ( image0 == image1 );
		success &= ( image1 == image0 );

		success &= ( image0 == image2 );
		success &= ( image2 == image0 );

		success &= ( image0 != image3 );
		success &= ( image3 != image0 );

		success &= !( image0 != image2 );
		success &= !( image2 != image0 );

		success &= !( image0 == image3 );
		success &= !( image3 == image0 );
	}

	//Hubris::HBOOL IndexValid( const Hubris::HVectorS2& in_index )const;
	{
		const PImageRgba image0( HMatrixConstructor::HVectorS2Construct( 16, 8 ) ); 
		success &= ( HTRUE == image0.IndexValid( HMatrixConstructor::HVectorS2Construct( 0, 0 ) ) );
		success &= ( HTRUE == image0.IndexValid( HMatrixConstructor::HVectorS2Construct( 15, 7 ) ) );
		success &= ( HFALSE == image0.IndexValid( HMatrixConstructor::HVectorS2Construct( 16, 7 ) ) );
		success &= ( HFALSE == image0.IndexValid( HMatrixConstructor::HVectorS2Construct( 15, 8 ) ) );
		success &= ( HFALSE == image0.IndexValid( HMatrixConstructor::HVectorS2Construct( -1, -1 ) ) );
		success &= ( HFALSE == image0.IndexValid( HMatrixConstructor::HVectorS2Construct( -1, 0 ) ) );
		success &= ( HFALSE == image0.IndexValid( HMatrixConstructor::HVectorS2Construct( 0, -1 ) ) );
	}

	//void ColourGet( const Hubris::HVectorS2& in_index, TColour& out_colour )const;
	//void ColourSet( const Hubris::HVectorS2& in_index, const TColour& in_colour );
	{
		PImageRgba image0( HMatrixConstructor::HVectorS2Construct( 16, 8 ) ); 
		const PColourRgba colour0( 1, 200, 5, 128 );
		image0.ColourSet( HMatrixConstructor::HVectorS2Construct( 1, 2 ), colour0 );
		const PColourRgba colour1 = image0.ColourGet( HMatrixConstructor::HVectorS2Construct( 1, 2 ) );

		success &= ( colour0 == colour1 );
	}

	//void SizeSet( const Hubris::HVectorS2& in_size );
	//const Hubris::HVectorS2 SizeGet()const;
	{
		const HVectorS2 vector0 = HMatrixConstructor::HVectorS2Construct( 16, 8 );
		const HVectorS2 vector1 = HMatrixConstructor::HVectorS2Construct( 64, 32 );
		PImageRgba image0( vector0 );

		success &= ( vector0 == image0.SizeGet() );
		image0.SizeSet( vector1 );
		success &= ( vector1 == image0.SizeGet() );
	}

	//const void* const RawGet()const;
	{
		const PImageRgba image0( HMatrixConstructor::HVectorS2Construct( 16, 8 ) ); 
		success &= ( HNULL != image0.RawGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PImage", success );

	return success;
}

/**/
static const HBOOL LocalTestbedImageBitmap()
{
	HBOOL success = HTRUE;

	//class PImageBitmap
	//PImageBitmap( const PImageMono& in_image );
	//PImageBitmap( const PImageRgb& in_image );
	//PImageBitmap( const PImageRgba& in_image );
	//~PImageBitmap();
	//HANDLE BitmapGet()const { return m_bitmap; }
	//{
	//	const PImageMono image0( HMatrixConstructor::HVectorS2Construct( 16, 8 ) ); 
	//	PImageBitmap image1( image0 );
	//	success &= ( HNULL != image1.BitmapGet() );
	//}
	//{
	//	const PImageRgb image0( HMatrixConstructor::HVectorS2Construct( 16, 8 ) ); 
	//	PImageBitmap image1( image0 );
	//	success &= ( HNULL != image1.BitmapGet() );
	//}
	{
		const PImageRgba image0( HMatrixConstructor::HVectorS2Construct( 16, 8 ) ); 
		PImageBitmap image1( image0 );
		success &= ( HNULL != image1.BitmapGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PImageBitmap", success );

	return success;
}

/**/
static const HBOOL LocalTestbedImageConvertor()
{
	HBOOL success = HTRUE;

	//struct PImageConvertor
	//static void RgbToRgba( PImageRgba& out_rgba, const PImageRgb& in_rgb, const Hubris::HU8 in_opacity = 255 );
	{
		const HVectorS2 vector0 = HMatrixConstructor::HVectorS2Construct( 16, 8 );
		const PImageRgb image0( vector0 ); 
		PImageRgba image1;
		PImageConvertor::RgbToRgba( image1, image0 );

		success &= ( vector0 == image1.SizeGet() );
	}

	//static void MonoToRgba( PImageRgba& out_rgba, const PImageMono& in_mono, const Hubris::HU8 in_opacity = 255 );
	{
		const HVectorS2 vector0 = HMatrixConstructor::HVectorS2Construct( 16, 8 );
		const PImageMono image0( vector0 ); 
		PImageRgba image1;
		PImageConvertor::MonoToRgba( image1, image0 );

		success &= ( vector0 == image1.SizeGet() );
	}

	//static void BitmapToRgba( PImageRgba& out_rgba, const BITMAPINFO* const in_bitmapInfo );
	{
		//TODO:
		//HDC hdcScreen = CreateDC( "DISPLAY", NULL, NULL, NULL ); 
		//HDC hdcCompatible = CreateCompatibleDC( hdcScreen ); 
		//if ( SelectObject( hdcCompatible, hbmScreen ) ) 
		//{
	 //       BitBlt
		//	(
		//		hdcCompatible, 
		//		0,
		//		0, 
		//		bmp.bmWidth, 
		//		bmp.bmHeight, 
		//		hdcScreen, 
		//		0,
		//		0, 
		//		SRCCOPY
		//	);

		//	const int scanLineCopied = GetDIBits
		//	(
		//		hdcCompatible,           // handle to DC
		//		HBITMAP hbmp,      // handle to bitmap
		//		UINT uStartScan,   // first scan line to set
		//		UINT cScanLines,   // number of scan lines to copy
		//		LPVOID lpvBits,    // array for bitmap bits
		//		LPBITMAPINFO lpbi, // bitmap data buffer
		//		UINT uUsage        // RGB or palette index
		//	);
		//}

		//// Create a compatible bitmap for hdcScreen. 
		// 
		//hbmScreen = CreateCompatibleBitmap(hdcScreen, 
		//					GetDeviceCaps(hdcScreen, HORZRES), 
		//					GetDeviceCaps(hdcScreen, VERTRES)); 

		//BITMAPINFO
		////HBITMAP CreateBitmap
		////(
		////	int nWidth,         // bitmap width, in pixels
		////	int nHeight,        // bitmap height, in pixels
		////	UINT cPlanes,       // number of color planes
		////	UINT cBitsPerPel,   // number of bits to identify color
		////	CONST VOID *lpvBits // color data array
		////);
	}


	PTESTBED_VALIDATE_STATUS( "PImageConvertor", success );

	return success;
}

/**/
static const HBOOL LocalTestbedImageTga()
{
	HBOOL success = HTRUE;

	const PImageMono imageMono0 = LocalImageCreateMono();
	const PImageRgb imageRgb0 = LocalImageCreateRgb();
	const PImageRgba imageRgba0 = LocalImageCreateRgba();
	HFileSystem fileSystem;
	const HCHAR* const nameMono = "data\\out_PIMono.tga";
	const HCHAR* const nameRgb = "data\\out_PIRgb.tga";
	const HCHAR* const nameRgba = "data\\out_PIRgba.tga";
	const HCHAR* const nameDummy = "data\\out_PIDummy.tga";

	//struct PImageTga

	//static HBOOL TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageMono& in_imageMono );
	{
		success &= PImageTga::TgaSave( fileSystem, nameMono, imageMono0 );
	}

	//static HBOOL TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageRgb& in_imageRgb );
	{
		success &= PImageTga::TgaSave( fileSystem, nameRgb, imageRgb0 );
	}

	//static HBOOL TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageRgba& in_imageRgba );
	{
		success &= PImageTga::TgaSave( fileSystem, nameRgba, imageRgba0 );
	}

	//static Hubris::HBOOL TgaFormatGet( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, Hubris::HBOOL& out_isMono, Hubris::HBOOL& out_isRgb, Hubris::HBOOL& out_isRgba );
	{
		HBOOL isMono = HFALSE;
		HBOOL isRgb = HFALSE;
		HBOOL isRgba = HFALSE;
		success &= PImageTga::TgaFormatGet( fileSystem, nameMono, isMono, isRgb, isRgba );
		success &= ( HTRUE == isMono );
		success &= ( HFALSE == isRgb );
		success &= ( HFALSE == isRgba );
		success &= PImageTga::TgaFormatGet( fileSystem, nameRgb, isMono, isRgb, isRgba );
		success &= ( HFALSE == isMono );
		success &= ( HTRUE == isRgb );
		success &= ( HFALSE == isRgba );
		success &= PImageTga::TgaFormatGet( fileSystem, nameRgba, isMono, isRgb, isRgba );
		success &= ( HFALSE == isMono );
		success &= ( HFALSE == isRgb );
		success &= ( HTRUE == isRgba );
		success &= !PImageTga::TgaFormatGet( fileSystem, nameDummy, isMono, isRgb, isRgba );
		success &= ( HFALSE == isMono );
		success &= ( HFALSE == isRgb );
		success &= ( HFALSE == isRgba );
	}

	//static HBOOL TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageMono& out_imageMono );
	{
		PImageMono imageMono1;
		success &= PImageTga::TgaLoad( fileSystem, nameMono, imageMono1 );
		success &= ( imageMono0 == imageMono1 );
	}

	//static HBOOL TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgb& out_imageRgb );
	{
		PImageRgb imageRgb1;
		success &= PImageTga::TgaLoad( fileSystem, nameRgb, imageRgb1 );
		success &= ( imageRgb0 == imageRgb1 );
	}

	//static HBOOL TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgba& out_imageRgba );
	{
		PImageRgba imageRgba1;
		success &= PImageTga::TgaLoad( fileSystem, nameRgba, imageRgba1 );
		success &= ( imageRgba0 == imageRgba1 );
	}

	//static HBOOL TgaLoadGeneric( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgba& out_imageRgba );
	{
		PImageRgba imageRgba1;
		success &= PImageTga::TgaLoadGeneric( fileSystem, nameRgba, imageRgba1 );
		success &= ( imageRgba0 == imageRgba1 );

		PImageRgba imageRgba2;
		success &= PImageTga::TgaLoadGeneric( fileSystem, nameRgb, imageRgba2 );

		PImageRgba imageRgba3;
		success &= PImageTga::TgaLoadGeneric( fileSystem, nameMono, imageRgba3 );

		PImageRgba imageRgba4;
		success &= !PImageTga::TgaLoadGeneric( fileSystem, nameDummy, imageRgba4 );
	}
	//{
	//	PImageRgba imageRgba;
	//	success &= PImageTga::TgaLoadGeneric( fileSystem, "data\\rgb_raw.tga", imageRgba );
	//	success &= PImageTga::TgaSave( fileSystem, "data\\out_rgb_raw.tga", imageRgba );
	//}
	//{
	//	PImageRgba imageRgba;
	//	success &= PImageTga::TgaLoadGeneric( fileSystem, "data\\rgb_rle.tga", imageRgba );
	//	success &= PImageTga::TgaSave( fileSystem, "data\\out_rgb_rle.tga", imageRgba );
	//}
	//{
	//	PImageRgba imageRgba;
	//	success &= PImageTga::TgaLoadGeneric( fileSystem, "data\\rgba_raw.tga", imageRgba );
	//	success &= PImageTga::TgaSave( fileSystem, "data\\out_rgba_raw.tga", imageRgba );
	//}
	//{
	//	PImageRgba imageRgba;
	//	success &= PImageTga::TgaLoadGeneric( fileSystem, "data\\rgba_rle.tga", imageRgba );
	//	success &= PImageTga::TgaSave( fileSystem, "data\\out_rgba_rle.tga", imageRgba );
	//}
	//{
	//	PImageRgba imageRgba;
	//	success &= PImageTga::TgaLoadGeneric( fileSystem, "data\\grey_raw.tga", imageRgba );
	//	success &= PImageTga::TgaSave( fileSystem, "data\\out_grey_raw.tga", imageRgba );
	//}
	//{
	//	PImageRgba imageRgba;
	//	success &= PImageTga::TgaLoadGeneric( fileSystem, "data\\grey_rle.tga", imageRgba );
	//	success &= PImageTga::TgaSave( fileSystem, "data\\out_grey_rle.tga", imageRgba );
	//}


	PTESTBED_VALIDATE_STATUS( "PImageTga", success );

	return success;
}

/**/
static const HBOOL LocalTestbedImageUtility()
{
	HBOOL success = HTRUE;

	//PImageUtilityRgba;
	//static void ResizeImage( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize ); 
	{
		const HVectorS2 vector0 = HMatrixConstructor::HVectorS2Construct( 16, 8 );
		const HVectorS2 vector1 = HMatrixConstructor::HVectorS2Construct( 32, 32 );
		const PImageRgba image0( vector0 ); 
		PImageRgba image1( vector0 ); 
		PImageUtilityRgba::ResizeImage( image1, image0, vector1 );

		success &= ( vector0 == image0.SizeGet() );
		success &= ( vector1 == image1.SizeGet() );
	}

	//static void ResizeImageQuick( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize ); 
	{
		const HVectorS2 vector0 = HMatrixConstructor::HVectorS2Construct( 16, 8 );
		const HVectorS2 vector1 = HMatrixConstructor::HVectorS2Construct( 32, 32 );
		const PImageRgba image0( vector0 ); 
		PImageRgba image1( vector0 ); 
		PImageUtilityRgba::ResizeImageQuick( image1, image0, vector1 );

		success &= ( vector0 == image0.SizeGet() );
		success &= ( vector1 == image1.SizeGet() );
	}

	//static void CropImage( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize, const Hubris::HVectorS2& in_origin ); 
	{
		const HVectorS2 vector0 = HMatrixConstructor::HVectorS2Construct( 32, 32 );
		const HVectorS2 vector1 = HMatrixConstructor::HVectorS2Construct( 16, 8 );
		const PImageRgba image0( vector0 ); 
		PImageRgba image1( vector0 ); 
		PImageUtilityRgba::CropImage( image1, image0, vector1 );

		success &= ( vector0 == image0.SizeGet() );
		success &= ( vector1 == image1.SizeGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PImageUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedImage()
{
	PTESTBED_VALIDATE_START( "TestbedImage" );
	HBOOL success = HTRUE;

	success &= LocalTestbedImage();
	success &= LocalTestbedImageBitmap();
	success &= LocalTestbedImageConvertor();
	success &= LocalTestbedImageTga();
	success &= LocalTestbedImageUtility();

	return success;
}

/**/