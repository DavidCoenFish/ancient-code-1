//file: Pride/PImage/PImageBitmap.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PImage/PImageBitmap.h"

#include "Pride/PImage/PImage.h"
#include "Pride/PImage/PImageConvertor.h"

#include "Pride/PColour/PColour_Export.h"

#include <WINDOWS.H>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// typedef
/**/
////////////////////////////////////////////////
// local static functions
/**/
static const HSINT LocalWidthGet( 
	const Hubris::HSINT in_width, 
	const Hubris::HSINT in_bitsPerPixel	
	)
{
	//pad the line width to word boundaries
	const HSINT temp = HMathUtility::Pad( in_width * in_bitsPerPixel, HSINT( sizeof( DWORD ) * 8 ) );
	const HSINT width = temp / in_bitsPerPixel;

	return width; 
}

/**/
static Hubris::HVOID* LocalCreateBitmap( 
	const PImageRgba& in_image,
	const Hubris::HSINT in_planes, 
	const Hubris::HSINT in_bitsPerPixel	
	)
{
	HBITMAP bitmap = NULL;

	const HVectorS2& size = in_image.SizeGet();

	if( ( 4 == in_planes ) && ( 8 == in_bitsPerPixel ) )
	{
		bitmap = CreateBitmap( size[ 0 ], size[ 1 ], in_planes, in_bitsPerPixel, in_image.RawGet() );
	}
	else
	{
		const HSINT padWidth = LocalWidthGet( size[ 0 ], in_bitsPerPixel );
		const HSINT length = ( padWidth * size[ 1 ] ) * in_planes;
		HContainerArrayBit arrayBit;
		arrayBit.SizeSet( length );

		HSINT traceBase = 0;
		HVectorS2 pos;
		for( pos[ 1 ] = 0; pos[ 1 ] < size[ 1 ]; ++( pos[ 1 ] ) )
		{
			HSINT trace = traceBase;
			for( pos[ 0 ] = 0; pos[ 0 ] < size[ 0 ]; ++( pos[ 0 ] ) )
			{
				for( HSINT indexPlane = 0; indexPlane < in_planes; ++indexPlane )
				{
					const HU8 value = in_image.ColourGet( pos ).DataGet()[ indexPlane ];
					for( HSINT indexBit = 0; indexBit < in_bitsPerPixel; ++indexBit )
					{
						arrayBit[ trace ] = ( 0 != ( value & ( 1 << indexBit ) ) );
						trace += 1;
					}
				}
			}

			traceBase += padWidth;
		}

		bitmap = CreateBitmap( size[ 0 ], size[ 1 ], in_planes, in_bitsPerPixel, arrayBit.RawGet() );
	}

	return bitmap;
}

////////////////////////////////////////////////
// creation
/**/
PImageBitmap::PImageBitmap(
	const PImageRgba& in_image,
	const Hubris::HSINT in_planes, 
	const Hubris::HSINT in_bitsPerPixel
	)
: m_bitmap( NULL )
{
	m_bitmap = LocalCreateBitmap( in_image, in_planes, in_bitsPerPixel );

	return;
}

/**/
PImageBitmap::~PImageBitmap()
{
	if( NULL != m_bitmap )
	{
		DeleteObject( ( HBITMAP )m_bitmap );
		m_bitmap = INVALID_HANDLE_VALUE;
	}

	return;
}

/**/