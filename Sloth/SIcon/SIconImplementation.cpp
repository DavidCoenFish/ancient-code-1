//file: Sloth/SIcon/SIconImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SIcon/SIconImplementation.h"

#include "Sloth/SIcon/SIconParam.h"

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
static HICON LocalSplitImage(
	const PImageRgba& in_source,
	const HVectorS2& in_maxSize
	)
{
	PImageRgba imageMask;
	PImageRgba image;

	if( in_maxSize < in_source.SizeGet() )
	{
		PImageUtilityRgba::CropImage( image, in_source, in_maxSize );
	}
	else
	{
		image = in_source;
	}


	PImageMono alphaImage;
	PImageConvertor::RgbaAlphaToMono( alphaImage, image );
	PImageConvertor::MonoToRgba( imageMask, alphaImage );

	ICONINFO iconInfo;
	SecureZeroMemory( &iconInfo, sizeof( ICONINFO ) );
	iconInfo.fIcon = TRUE;

	PImageBitmap maskImageBitmap( imageMask, 1, 1 ); 
	PImageBitmap imageBitmap( image, 4, 8 ); 

	iconInfo.hbmMask = ::HBITMAP( maskImageBitmap.BitmapGet() );
	iconInfo.hbmColor = ::HBITMAP( imageBitmap.BitmapGet() );

	return CreateIconIndirect( &iconInfo );
}

///////////////////////////////////////////////////////
// creation
/**/
SIconImplementation::SIconImplementation( 
	const SIconParam& in_param
	)
: m_iconLarge( HNULL )
, m_iconSmall( HNULL )
{
	HVectorS2 maxLargeSize;
	maxLargeSize[ 0 ] = GetSystemMetrics( SM_CXICON );
	maxLargeSize[ 1 ] = GetSystemMetrics( SM_CYICON );

	m_iconLarge = LocalSplitImage(
		in_param.ImageLargeGet(),
		maxLargeSize
		);

	HVectorS2 maxSmallSize;
	maxSmallSize[ 0 ] = 16;
	maxSmallSize[ 1 ] = 16;

	m_iconSmall = LocalSplitImage(
		in_param.ImageSmallGet(),
		maxSmallSize
		);

	return;
}

/**/
SIconImplementation::~SIconImplementation()
{
	DestroyIcon( ::HICON( m_iconLarge ) );
	DestroyIcon( ::HICON( m_iconSmall ) );

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
SIconImplementation::HICON SIconImplementation::IconLargeGet()
{
	return m_iconLarge;
}

/**/
SIconImplementation::HICON SIconImplementation::IconSmallGet()
{
	return m_iconSmall;
}

/**/
