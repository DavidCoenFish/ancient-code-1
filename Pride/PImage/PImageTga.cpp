//file: Pride/PImage/PImageTga.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PImage/PImageTga.h"

#include "Pride/PImage/PImage.h"
#include "Pride/PImage/PImageConvertor.h"

#include "Pride/PColour/PColour_Export.h"

#include< Hubris/HBuffer/HBuffer_Export.h >
#include< Hubris/HFileSystem/HFileSystem_Export.h >
#include< Hubris/HTrait/HTrait_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// local variables
static const HCHAR* const s_tgaComment = "coen_tga_2007";
static const HCHAR* const s_tgaExtention = "TGA";
struct TBitsPerPixel
{
	enum TEnum
	{
		TMono = 8,
		TRgb = 24,
		TRgba = 32,
	};
};
struct TFlag
{
	enum TEnum
	{
		TNone = 0,
		TFlipHorizontal = 0x10,
		TFlipVertical = 0x20,
	};
};
struct TTgaEncodeing
{
	enum TEnum
	{
		TNone = 0,
		TRawIndex = 1,		//  1 = Raw indexed image
		TRawRGB = 2,		//  2 = Raw RGB
		TRawGreyScale = 3,	//  3 = Raw greyscale
		TRLEIndex = 9,		//  9 = RLE indexed
		TRLERGB = 10,		// 10 = RLE RGB
		TRLEGreyscale = 11,	// 11 = RLE greyscale
							// 32 & 33 Other compression, indexed
	};
};

///////////////////////////////////////////////////////
// static public methods
/**/
static HSINT LocalHeaderRead( const HBuffer& in_file, HS32& out_width, HS32& out_height, HS32& out_bitPerPixel, TFlag::TEnum& out_flag, TTgaEncodeing::TEnum& out_encoding )
{
	out_width = 0;
	out_height = 0;
	out_bitPerPixel = 0;
	out_flag = TFlag::TNone;

	if( in_file.SizeGet() < 18 )
	{
		//file seems too small
		return 0;
	}

	HSINT cursor = 0;
	HU8 idLength = 0;
	HTraitBufferOutGet( idLength, cursor, in_file );

	HU8 colourType = 0;
	HTraitBufferOutGet( colourType, cursor, in_file );

	if( 1 == colourType )
	{
		//not dealing with pal
		return 0;
	}

	HU8 imageType = 0;
	HTraitBufferOutGet( imageType, cursor, in_file );
	out_encoding = ( TTgaEncodeing::TEnum )imageType;

	HU16 width = 0;
	HU16 height = 0;
	HU8 bitPerPixel = 0;
	HU8 flag = 0;
	cursor = 12;
	HTraitBufferOutGet( width, cursor, in_file );
	HTraitBufferOutGet( height, cursor, in_file );
	HTraitBufferOutGet( bitPerPixel, cursor, in_file );
	HTraitBufferOutGet( flag, cursor, in_file );

	out_width = width;
	out_height = height;
	out_bitPerPixel = bitPerPixel;
	out_flag = ( TFlag::TEnum ) flag;

	return( 18 + idLength );
}

/**/
static void LocalHeaderWrite( HBuffer& out_file, const HS32 in_width, const HS32 in_height, const HS32 in_bitPerPixel )
{
	const HU8 length = ( HU8 )( HStringUtility::Length( s_tgaComment ) + 1 );
	HTraitBufferInAppend( out_file, length ); //start by writing the size of the comment
	HTraitBufferInAppend< HU8 >( out_file, 0 );
	if( 8 == in_bitPerPixel )					//2: 1 is has a colourMap, 2 is truecolour, 3 = greyscale
	{
		HTraitBufferInAppend< HU8 >( out_file, 3 );
	}
	else
	{
		HTraitBufferInAppend< HU8 >( out_file, 2 );
	}
	HTraitBufferInAppend< HU8 >( out_file, 0);				//3:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//4:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//5:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//6:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//7:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//8:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//9:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//10:
	HTraitBufferInAppend< HU8 >( out_file, 0);				//11:
	HTraitBufferInAppend( out_file, (HU16)in_width );		//12:
	HTraitBufferInAppend( out_file, (HU16)in_height );	//14:
	HTraitBufferInAppend( out_file, HU8( in_bitPerPixel ) );	//16:
	HTraitBufferInAppend( out_file, HU8( TFlag::TFlipVertical ) );	//17: dir flag, 

	HBufferUtility::DataAppend( out_file, s_tgaComment, length * sizeof( HCHAR ) );

	return;
}

/**/
static const HSINT LocalTgaBitPerPixelCountGet( const HBuffer& in_file )
{
	HSINT width = 0;
	HSINT height = 0;
	HSINT bitPerPixel = 0;
	TFlag::TEnum flag = TFlag::TNone;
	TTgaEncodeing::TEnum encoding = TTgaEncodeing::TNone;

	LocalHeaderRead( in_file, width, height, bitPerPixel, flag, encoding );

	return bitPerPixel;
}

/**/
static HVectorS2 LocalImageIndexGet( const HSINT in_indexWidth, const HSINT in_indexHeight, const HSINT in_width, const HSINT in_height, const TFlag::TEnum in_flag )
{
	HSINT x = in_indexWidth;
	HSINT y = in_indexHeight;

	if( in_flag & TFlag::TFlipHorizontal )
	{
		x = ( in_width - 1 - in_indexWidth );
	}

	if( 0 == ( in_flag & TFlag::TFlipVertical ) )
	{
		y = ( in_height - 1 - in_indexHeight );
	}

	return HMatrixConstructor::HVectorS2Construct( x, y );
}

/**/
template< HSINT IN_BYTE_PER_PIXEL >
static Hubris::HVOID LocalTgaPixelGet(
	Pride::PColour< HU8, IN_BYTE_PER_PIXEL >& out_colour,
	const Hubris::HBuffer& in_file,
	Hubris::HSINT& in_out_cursor
	)
{
	if( in_file.SizeGet() < in_out_cursor + IN_BYTE_PER_PIXEL )
	{
		return;
	}
	Pride::PColour< HU8, IN_BYTE_PER_PIXEL >::TVector data;
	for( HSINT index = 0; index < IN_BYTE_PER_PIXEL; ++index )
	{
		HU8 value = 0;
		HTraitBufferOutGet( value, in_out_cursor, in_file );
		data[ index ] = value;
	}

	out_colour.DataSet( data );
	return;
}

/**/
template< HSINT IN_BYTE_PER_PIXEL >
static Hubris::HVOID LocalLoadRLE(
	Pride::PImage< HU8, IN_BYTE_PER_PIXEL >& out_image,
	const HBuffer& in_file,
	const Hubris::HSINT in_cursor, 
	const Hubris::HSINT in_width, 
	const Hubris::HSINT in_height, 
	const TFlag::TEnum in_flag
	)
{
	HSINT cursor = in_cursor;
	Pride::PImage< HU8, IN_BYTE_PER_PIXEL >::TColour colour;
	HSINT pixelRLECount = 0;
	HBOOL isRaw = HFALSE;
	for( HSINT indexHeight = 0; indexHeight < in_height; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < in_width; ++indexWidth )
		{
			if( pixelRLECount == 0 )
			{
				if( in_file.SizeGet() < cursor + 1 )
				{
					return;
				}
				HU8 value = 0;
				HTraitBufferOutGet( value, cursor, in_file );
				isRaw = ( 0 == ( value & 0x80 ) );
				if( isRaw )
				{
					pixelRLECount = ( value + 1 );
				}
				else
				{
					pixelRLECount = ( value - 127 );
					LocalTgaPixelGet(
						colour,
						in_file,
						cursor
						);
				}
			}

			if( pixelRLECount <= 0 )
			{
				return;
			}

			if( HTRUE == isRaw )
			{
				LocalTgaPixelGet(
					colour,
					in_file,
					cursor
					);
			}

			const HVectorS2 imageIndex = LocalImageIndexGet( indexWidth, indexHeight, in_width, in_height, in_flag );
			out_image.ColourSet( imageIndex, colour );
			pixelRLECount -= 1;
		}
	}

	return;
}

/**/
template< HSINT IN_BYTE_PER_PIXEL >
static Hubris::HVOID LocalLoadRaw(
	Pride::PImage< HU8, IN_BYTE_PER_PIXEL >& out_image,
	const HBuffer& in_file,
	const Hubris::HSINT in_cursor, 
	const Hubris::HSINT in_width, 
	const Hubris::HSINT in_height, 
	const TFlag::TEnum in_flag
	)
{
	HSINT cursor = in_cursor;
	Pride::PImage< HU8, IN_BYTE_PER_PIXEL >::TColour colour;
	out_image.SizeSet( HMatrixConstructor::HVectorS2Construct( in_width, in_height ) );
	for( HSINT indexHeight = 0; indexHeight < in_height; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < in_width; ++indexWidth )
		{
			LocalTgaPixelGet(
				colour,
				in_file,
				cursor
				);

			const HVectorS2 imageIndex = LocalImageIndexGet( indexWidth, indexHeight, in_width, in_height, in_flag );
			out_image.ColourSet( imageIndex, colour );
		}
	}

	return;
}

/**/
template< HSINT IN_BYTE_PER_PIXEL >
static const Hubris::HBOOL LocalTgaLoad( 
	Pride::PImage< HU8, IN_BYTE_PER_PIXEL >& out_image,
	const HBuffer& in_buffer
	)
{
	HSINT width = 0;
	HSINT height = 0;
	HSINT bitPerPixel = 0;
	TFlag::TEnum flag = TFlag::TNone;
	TTgaEncodeing::TEnum encoding = TTgaEncodeing::TNone;
	HSINT cursor = 0;

	cursor = LocalHeaderRead( in_buffer, width, height, bitPerPixel, flag, encoding );
	if( ( 8 * IN_BYTE_PER_PIXEL ) != bitPerPixel )
	{
		return HFALSE;
	}

	out_image.SizeSet( HMatrixConstructor::HVectorS2Construct( width, height ) );

	switch( encoding )
	{
	default:
		{
			break;
		}
	case TTgaEncodeing::TRawGreyScale:
	case TTgaEncodeing::TRawRGB:
		{
			LocalLoadRaw(
				out_image,
				in_buffer,
				cursor, 
				width, 
				height, 
				flag
				);
			break;
		}
	case TTgaEncodeing::TRLEGreyscale:
	case TTgaEncodeing::TRLERGB:
		{
			LocalLoadRLE(
				out_image,
				in_buffer,
				cursor, 
				width, 
				height, 
				flag
				);
			break;
		}
	}

	return HTRUE;
}


///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HBOOL Pride::PImageTga::TgaFormatGet( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, HBOOL& out_isMono, HBOOL& out_isRgb, HBOOL& out_isRgba )
{
	out_isMono = HFALSE;
	out_isRgb = HFALSE;
	out_isRgba = HFALSE;

	HBuffer file;
	if( HFALSE == in_fileSystem.FileLoad( in_path, file ) )
	{
		return HFALSE;
	}

	if( HFALSE == BufferTgaFormatGet( file, out_isMono, out_isRgb, out_isRgba ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageMono& out_imageMono )
{
	HBuffer file;
	if( HFALSE == in_fileSystem.FileLoad( in_path, file ) )
	{
		return HFALSE;
	}

	if( HFALSE == BufferTgaLoad( file, out_imageMono ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgb& out_imageRgb )
{
	HBuffer file;
	if( HFALSE == in_fileSystem.FileLoad( in_path, file ) )
	{
		return HFALSE;
	}

	if( HFALSE == BufferTgaLoad( file, out_imageRgb ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgba& out_imageRgba )
{
	HBuffer file;
	if( HFALSE == in_fileSystem.FileLoad( in_path, file ) )
	{
		return HFALSE;
	}

	if( HFALSE == BufferTgaLoad( file, out_imageRgba ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::TgaLoadGeneric( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgba& out_imageRgba )
{
	HBuffer file;
	if( HFALSE == in_fileSystem.FileLoad( in_path, file ) )
	{
		return HFALSE;
	}

	HBOOL isMono = HFALSE;
	HBOOL isRgb = HFALSE;
	HBOOL isRgba = HFALSE;
	if( HFALSE == BufferTgaFormatGet( file, isMono, isRgb, isRgba ) )
	{
		return HFALSE;
	}

	HBOOL success = HFALSE;
	if( HTRUE == isMono )
	{
		PImageMono imageMono;
		success = BufferTgaLoad( file, imageMono );
		PImageConvertor::MonoToRgba( out_imageRgba, imageMono );
	}
	else if( HTRUE == isRgb )
	{
		PImageRgb imageRgb;
		success = BufferTgaLoad( file, imageRgb );
		PImageConvertor::RgbToRgba( out_imageRgba, imageRgb );
	}
	else if( HTRUE == isRgba )
	{
		success = BufferTgaLoad( file, out_imageRgba );
	}

	return success;
}

/**/
const Hubris::HBOOL Pride::PImageTga::TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageMono& in_imageMono )
{
	HBuffer file;

	if( HFALSE == BufferTgaSave( file, in_imageMono ) )
	{
		return HFALSE;
	}

	if( HFALSE == in_fileSystem.FileSave( in_path, file ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageRgb& in_imageRgb )
{
	HBuffer file;

	if( HFALSE == BufferTgaSave( file, in_imageRgb ) )
	{
		return HFALSE;
	}

	if( HFALSE == in_fileSystem.FileSave( in_path, file ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageRgba& in_imageRgba )
{
	HBuffer file;

	if( HFALSE == BufferTgaSave( file, in_imageRgba ) )
	{
		return HFALSE;
	}

	if( HFALSE == in_fileSystem.FileSave( in_path, file ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::BufferTgaFormatGet( const Hubris::HBuffer& in_buffer, Hubris::HBOOL& out_isMono, Hubris::HBOOL& out_isRgb, Hubris::HBOOL& out_isRgba )
{
	out_isMono = HFALSE;
	out_isRgb = HFALSE;
	out_isRgba = HFALSE;

	switch( LocalTgaBitPerPixelCountGet( in_buffer ) )
	{
	default:
		{
			return HFALSE;
		}
	case TBitsPerPixel::TMono:
		{
			out_isMono = HTRUE;
			break;
		}
	case TBitsPerPixel::TRgb:
		{
			out_isRgb = HTRUE;
			break;
		}
	case TBitsPerPixel::TRgba:
		{
			out_isRgba = HTRUE;
			break;
		}
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::BufferTgaLoad( const Hubris::HBuffer& in_buffer, PImageMono& out_imageMono )
{
	if( HFALSE == LocalTgaLoad(
		out_imageMono,
		in_buffer
		) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::BufferTgaLoad( const Hubris::HBuffer& in_buffer, PImageRgb& out_imageRgb )
{
	if( HFALSE == LocalTgaLoad(
		out_imageRgb,
		in_buffer
		) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::BufferTgaLoad( const Hubris::HBuffer& in_buffer, PImageRgba& out_imageRgba )
{
	if( HFALSE == LocalTgaLoad(
		out_imageRgba,
		in_buffer
		) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::BufferTgaSave( Hubris::HBuffer& out_buffer, const PImageMono& in_imageMono )
{
	const HVectorS2 size = in_imageMono.SizeGet();
	LocalHeaderWrite( out_buffer, size[ 0 ], size[ 1 ], TBitsPerPixel::TMono );

	for( HSINT indexHeight = 0; indexHeight < size[ 1 ]; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < size[ 0 ]; ++indexWidth )
		{
			const PImageMono::TColour colour = in_imageMono.ColourGet( HMatrixConstructor::HVectorS2Construct( indexWidth, indexHeight ) );
			HTraitBufferInAppend( out_buffer, colour.MonoGet() );
		}
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::BufferTgaSave( Hubris::HBuffer& out_buffer, const PImageRgb& in_imageRgb )
{
	const HVectorS2 size = in_imageRgb.SizeGet();
	LocalHeaderWrite( out_buffer, size[ 0 ], size[ 1 ], TBitsPerPixel::TRgb );

	for( HSINT indexHeight = 0; indexHeight < size[ 1 ]; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < size[ 0 ]; ++indexWidth )
		{
			const PImageRgb::TColour colour = in_imageRgb.ColourGet( HMatrixConstructor::HVectorS2Construct( indexWidth, indexHeight ) );
			HTraitBufferInAppend( out_buffer, colour.BlueGet() );
			HTraitBufferInAppend( out_buffer, colour.GreenGet() );
			HTraitBufferInAppend( out_buffer, colour.RedGet() );
		}
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL Pride::PImageTga::BufferTgaSave( Hubris::HBuffer& out_buffer, const PImageRgba& in_imageRgba )
{
	const HVectorS2 size = in_imageRgba.SizeGet();
	LocalHeaderWrite( out_buffer, size[ 0 ], size[ 1 ], TBitsPerPixel::TRgba );

	for( HSINT indexHeight = 0; indexHeight < size[ 1 ]; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < size[ 0 ]; ++indexWidth )
		{
			const PImageRgba::TColour colour = in_imageRgba.ColourGet( HMatrixConstructor::HVectorS2Construct( indexWidth, indexHeight ) );
			HTraitBufferInAppend( out_buffer, colour.BlueGet() );
			HTraitBufferInAppend( out_buffer, colour.GreenGet() );
			HTraitBufferInAppend( out_buffer, colour.RedGet() );
			HTraitBufferInAppend( out_buffer, colour.OpacityGet() );
		}
	}

	return HTRUE;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HCHAR* const Pride::PImageTga::TgaExtentionGet()
{
	return( s_tgaExtention );
}

/**/
