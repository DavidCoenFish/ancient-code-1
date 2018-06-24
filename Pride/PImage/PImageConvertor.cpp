//file: Pride/PImage/PImageConvertor.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PImage/PImageConvertor.h"

#include "Pride/PImage/PImage.h"

#include "Pride/PColour/PColour_Export.h"

#include <WINDOWS.H>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// public static methods
/**/
PColourRgba LocalGetPixel( const BITMAPINFO* const in_pBitmapInfo, const HSINT in_indexX, const HSINT in_indexY )
{
	PColourRgba	returnColour;
	if( NULL == in_pBitmapInfo )
	{
		return returnColour;
	}

	HU32 colour = 0;
	HSINT y = in_indexY;
	if (0 < in_pBitmapInfo->bmiHeader.biHeight) // flip if height is negative
	{
		y = ( in_pBitmapInfo->bmiHeader.biHeight - 1 ) - in_indexY;
	}

	//nb: 0 == in_pBitmapInfo->bmiHeader.biBitCount for compressed

	HSINT lineBitWidth = in_pBitmapInfo->bmiHeader.biWidth * in_pBitmapInfo->bmiHeader.biBitCount;
	if( 0 != ( lineBitWidth & 0x1F ) )
	{
		lineBitWidth += ( ( ~lineBitWidth ) & 0x1F ); //dword align
	}

	HSINT pixelBitOffset = ( lineBitWidth * y ) +  ( in_indexX * in_pBitmapInfo->bmiHeader.biBitCount );


	HSINT* pColourMap = ( HSINT* )( ( (char*)in_pBitmapInfo ) + in_pBitmapInfo->bmiHeader.biSize );
	char * data = NULL;
	if( 0 == in_pBitmapInfo->bmiHeader.biClrUsed )
	{
		data = ( ( ( char* ) in_pBitmapInfo ) + in_pBitmapInfo->bmiHeader.biSize + ( 4 * ( 1 << in_pBitmapInfo->bmiHeader.biBitCount ) ) );
	}
	else
	{
		data = ( ( ( char* ) in_pBitmapInfo ) + in_pBitmapInfo->bmiHeader.biSize + ( 4 * in_pBitmapInfo->bmiHeader.biClrUsed ) );
	}

	HSINT value = 0;
	HSINT byteOffset = pixelBitOffset >> 3;
	HSINT bitOffset = pixelBitOffset & 0x07;
	((char *)&value)[0] = data[byteOffset + 0]; 
	((char *)&value)[1] = data[byteOffset + 1]; 
	((char *)&value)[2] = data[byteOffset + 2]; 
	((char *)&value)[3] = data[byteOffset + 3]; 

	switch( in_pBitmapInfo->bmiHeader.biBitCount )
	{
	default:
		{
			break;
		}
	case 1:
		{
			value >>= bitOffset;
			colour = pColourMap[value & 0x01];
			break;
		}
	case 2:
		{
			value >>= bitOffset;
			colour = pColourMap[value & 0x02];
			break;
		}
	case 4:
		{
			value >>= bitOffset;
			colour = pColourMap[value & 0x04];
			break;
		}
	case 8:
		{
			value >>= bitOffset;
			colour = pColourMap[value & 0x08];
			break;
		}
	case 16:
		{
			//todo: need defice caps or something to find out if 5-5-5 or 5-6-5 rgb
			//atlest make something
			value &= 0x00FFFF;
			( ( HU8* )&colour )[ 0 ] = ( HU8 )( ( value & 0x1F ) << 3 );
			( ( HU8* )&colour )[ 1 ] = ( HU8 )( ( ( value>>5 ) & 0x1F ) << 3 );
			( ( HU8* )&colour )[ 2 ] = ( HU8 )( ( ( value>>10 ) & 0x1F ) << 3 );
			break;
		}
	case 24:
		{
			colour = ( value & 0x00FFFFFF );
			break;
		}
	case 32:
		{
			colour = value;
			break;
		}
	}

	returnColour = PColourConvertor::U32ToRgba( colour );

	return returnColour;
}


///////////////////////////////////////////////////////
// public static methods
/**/
void PImageConvertor::RgbToRgba( PImageRgba& out_rgba, const PImageRgb& in_rgb, const HU8 in_opacity )
{
	const HVectorS2 size = in_rgb.SizeGet();
	out_rgba.SizeSet( size );
	for( HSINT height = 0; height < size[ 1 ]; ++height )
	{
		for( HSINT width = 0; width < size[ 0 ]; ++width )
		{
			const HVectorS2 index = HMatrixConstructor::HVectorS2Construct( width, height );
			const PColourRgb src = in_rgb.ColourGet( index );
			const PColourRgba dest = PColourConvertor::RgbToRgba( src, in_opacity );
			out_rgba.ColourSet( index, dest );
		}
	}

	return;
}

/**/
void PImageConvertor::MonoToRgba( PImageRgba& out_rgba, const PImageMono& in_mono, const HU8 in_opacity )
{
	const HVectorS2 size = in_mono.SizeGet();
	out_rgba.SizeSet( size );
	for( HSINT height = 0; height < size[ 1 ]; ++height )
	{
		for( HSINT width = 0; width < size[ 0 ]; ++width )
		{
			const HVectorS2 index = HMatrixConstructor::HVectorS2Construct( width, height );
			const PColourMono src = in_mono.ColourGet( index );
			const PColourRgba dest = PColourConvertor::MonoToRgba( src, in_opacity );
			out_rgba.ColourSet( index, dest );
		}
	}

	return;
}

/**/
void PImageConvertor::RgbaAlphaToMono( PImageMono& out_mono, const PImageRgba& in_rgba )
{
	const HVectorS2 size = in_rgba.SizeGet();
	out_mono.SizeSet( size );
	HVectorS2 pos;
	for( pos[ 1 ] = 0; pos[ 1 ] < size[ 1 ]; ++( pos[ 1 ] ) )
	{
		for( pos[ 0 ] = 0; pos[ 0 ] < size[ 0 ]; ++( pos[ 0 ] ) )
		{
			const PColourRgba src = in_rgba.ColourGet( pos );
			out_mono.ColourSet( pos, PColourMono( src.OpacityGet() ) );
		}
	}

	return;
}


/**/
void PImageConvertor::BitmapToRgba( PImageRgba& out_rgba, const BITMAPINFO* const in_pBitmapInfo )
{
	if( NULL == in_pBitmapInfo )
	{
		return;
	}

	HSINT height = in_pBitmapInfo->bmiHeader.biHeight;
	if (height < 0) 
	{
		height = (-height);
	}
	const HSINT width = in_pBitmapInfo->bmiHeader.biWidth;

	out_rgba.SizeSet( HMatrixConstructor::HVectorS2Construct( width, height ) );

	for( HSINT indexY = 0; indexY < height; ++indexY )
	{
		for( HSINT indexX = 0; indexX < width; ++indexX )
		{
			const HVectorS2 pos = HMatrixConstructor::HVectorS2Construct( indexX, indexY );
			const PColourRgba colour = LocalGetPixel( in_pBitmapInfo, indexX, indexY );
			out_rgba.ColourSet( pos, colour );
		}
	}

	return;
}

/**/
void PImageConvertor::RealRgbToRgba( PImageRgba& out_rgba, const PImageRealRgb& in_realRgb )
{
	const HVectorS2 size = in_realRgb.SizeGet();
	out_rgba.SizeSet( size );
	HVectorS2 trace;
	for( trace[ 1 ] = 0; trace[ 1 ] < size[ 1 ]; ++( trace[ 1 ] ) )
	{
		for( trace[ 0 ] = 0; trace[ 0 ] < size[ 0 ]; ++( trace[ 0 ] ) )
		{
			const PColourRealRgb src = in_realRgb.ColourGet( trace );
			const PColourRealRgba srca( src.RedGet(), src.BlueGet(), src.GreenGet(), 1.0F );
			const PColourRgba dest = PColourConvertor::RgbaToRgba( srca );
			out_rgba.ColourSet( trace, dest );
		}
	}

	return;
}

/**/
void PImageConvertor::RealRgbaToRgba( PImageRgba& out_rgba, const PImageRealRgba& in_realRgba )
{
	const HVectorS2 size = in_realRgba.SizeGet();
	out_rgba.SizeSet( size );
	HVectorS2 trace;
	for( trace[ 1 ] = 0; trace[ 1 ] < size[ 1 ]; ++( trace[ 1 ] ) )
	{
		for( trace[ 0 ] = 0; trace[ 0 ] < size[ 0 ]; ++( trace[ 0 ] ) )
		{
			const PColourRealRgba src = in_realRgba.ColourGet( trace );
			const PColourRgba dest = PColourConvertor::RgbaToRgba( src );
			out_rgba.ColourSet( trace, dest );
		}
	}

	return;
}

/**/

