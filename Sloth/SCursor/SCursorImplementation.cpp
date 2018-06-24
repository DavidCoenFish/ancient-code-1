//file: Sloth/SCursor/SCursorImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SCursor/SCursorImplementation.h"

#include "Sloth/SCursor/SCursorParam.h"

#include <WINDOWS.H>

/*
HICON CreateIconIndirect(          ICONINFO piconinfo
);
hCursor

BOOL DestroyIcon(          HICON hIcon
);

GetSystemMetrics function, specifying the SM_CXCURSOR or SM_CYCURSOR value.

*/

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

////////////////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
SCursorImplementation::SCursorImplementation( 
	const SCursorParam& in_param
	)
: m_cursor( HNULL )
{
	HVectorS2 maxSize;
	maxSize[ 0 ] = GetSystemMetrics( SM_CXCURSOR );
	maxSize[ 1 ] = GetSystemMetrics( SM_CYCURSOR );

	PImageRgba resizedImage;

	if( maxSize < in_param.ImageGet().SizeGet() )
	{
		PImageUtilityRgba::CropImage( resizedImage, in_param.ImageGet(), maxSize );
	}
	else
	{
		resizedImage = in_param.ImageGet();
	}

	//
	ICONINFO iconInfo;
	SecureZeroMemory( &iconInfo, sizeof( ICONINFO ) );

	iconInfo.fIcon = FALSE;
	iconInfo.xHotspot = in_param.HotspotGet()[ 0 ];
	iconInfo.yHotspot = in_param.HotspotGet()[ 1 ];

	PImageRgba maskImage;
	{
		PImageMono alphaImage;
		PImageConvertor::RgbaAlphaToMono( alphaImage, resizedImage );
		PImageConvertor::MonoToRgba( maskImage, alphaImage );
	}

	PImageBitmap maskImageBitmap( maskImage, 1, 1 ); 
	PImageBitmap imageBitmap( resizedImage, 4, 8 ); 

	iconInfo.hbmMask = ::HBITMAP( maskImageBitmap.BitmapGet() );
	iconInfo.hbmColor = ::HBITMAP( imageBitmap.BitmapGet() );

	m_cursor = CreateIconIndirect( &iconInfo );

	return;
}

/**/
SCursorImplementation::~SCursorImplementation()
{
	DestroyIcon( ::HICON( m_cursor ) );

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
SCursorImplementation::HCURSOR SCursorImplementation::CursorGet()
{
	return m_cursor;
}

/**/
