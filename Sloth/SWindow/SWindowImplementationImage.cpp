//file: Sloth/SWindow/SWindowImplementationImage.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowImplementationImage.h"

#include "Sloth/SWindow/SWindowImageInterface.h"

#include <WINDOWS.H>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

////////////////////////////////////////////////////////////////
// local static methods
/**/
static HVectorS2 LocalSizeGet( HWND in_hWnd )
{
	HVectorS2 size;
	RECT rect;
	SecureZeroMemory( &rect, sizeof( rect ) ); 
	GetClientRect( in_hWnd, &rect );
	size[ 0 ] = HMathUtility::Pad( HSINT( rect.right - rect.left ), HSINT( 4 ) );
	size[ 1 ] = rect.bottom - rect.top;

	return size;
}

/**/
static void LocalFillDevice( HDC in_device, const HVectorS2& in_size, const COLORREF in_color )
{
	RECT rect;
	SecureZeroMemory( &rect, sizeof( rect ) ); 
	rect.left = 0;
	rect.top = 0;
	rect.right = in_size[ 0 ];
	rect.bottom = in_size[ 1 ];

	HBRUSH hBrush = CreateSolidBrush( in_color );
	FillRect( in_device, &rect, hBrush );
	DeleteObject( hBrush );

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SWindowImplementationImage::SWindowImplementationImage()
: SWindowImplementationBase()
, m_size()
, m_bitmapIndependant( HNULL )
, m_memoryDeviceContextIndependant( HNULL )
, m_pbitmapIndependantData( HNULL )
{
	return;
}

/**/
SWindowImplementationImage::~SWindowImplementationImage()
{
	return;
}

///////////////////////////////////////////////////////
// implement SWindowImplementationBase
/**/
Hubris::HVOID SWindowImplementationImage::OnClose(
	HWND HCOMMON_UNUSED_VAR( in_hWnd )
	)
{
	return;
}

/**/
Hubris::HVOID SWindowImplementationImage::OnCreate( 
	HWND in_hWnd 
	)
{
	//create our memory device context from the window's device context
	::HDC deviceContext = GetDC( ::HWND( in_hWnd ) );

	m_memoryDeviceContextIndependant = CreateCompatibleDC( ::HDC( deviceContext ) );

	ReleaseDC( ::HWND( in_hWnd ), deviceContext );

	return;
}

/**/
Hubris::HVOID SWindowImplementationImage::OnPaint( 
	HWND in_hWnd 
	)
{
	PAINTSTRUCT paintStruct;
	SecureZeroMemory( &paintStruct, sizeof( paintStruct ) );

	::HDC deviceContext = BeginPaint( ::HWND( in_hWnd ), &paintStruct );

	BOOL result = 0;

	//blit to device
	result = BitBlt( 
		deviceContext, 
		0, 
		0, 
		m_size[ 0 ], 
		m_size[ 1 ], 
		::HDC( m_memoryDeviceContextIndependant ), 
		0, 
		0, 
		SRCCOPY 
	);

	result = EndPaint( ::HWND( in_hWnd ), &paintStruct );

	//finish any GDI paint instruction of the thread
	GdiFlush();

	return;
}

/**/
Hubris::HVOID SWindowImplementationImage::OnSize( 
	HWND in_hWnd,
	const Hubris::HSINT in_width,
	const Hubris::HSINT in_height
	)
{
	in_width;
	in_height;
	const HVectorS2 newSize = LocalSizeGet( ::HWND( in_hWnd ) );

	if( m_size == newSize )
	{
		return;
	}

	m_size = newSize;

	//delete old bitmaps
	if( HNULL != m_bitmapIndependant )
	{
		DeleteObject( ::HBITMAP( m_bitmapIndependant ) );
		m_bitmapIndependant = HNULL;
	}

	//create device independant bitmap
	BITMAPINFO bitmapInfo;
	SecureZeroMemory( &bitmapInfo, sizeof( BITMAPINFO ) ); 
	bitmapInfo.bmiHeader.biSize = sizeof( BITMAPINFO );
	bitmapInfo.bmiHeader.biWidth = m_size[ 0 ];
	bitmapInfo.bmiHeader.biHeight = -m_size[ 1 ];
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biBitCount = 32;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biSizeImage = 0;
	bitmapInfo.bmiHeader.biXPelsPerMeter = 65536;
	bitmapInfo.bmiHeader.biYPelsPerMeter = 65536;
	bitmapInfo.bmiHeader.biClrUsed = 0;
	bitmapInfo.bmiHeader.biClrImportant = 0;


	m_bitmapIndependant = CreateDIBSection( ::HDC( m_memoryDeviceContextIndependant ), &bitmapInfo, DIB_RGB_COLORS, &m_pbitmapIndependantData, NULL, 0 );
	SelectObject( ::HDC( m_memoryDeviceContextIndependant ), ::HBITMAP( m_bitmapIndependant ) );

	return;
}

/**/
Hubris::HVOID SWindowImplementationImage::OnDestroy(
	HWND HCOMMON_UNUSED_VAR( in_hWnd )
	)
{
	DeleteObject( ::HBITMAP( m_bitmapIndependant ) );
	m_bitmapIndependant = HNULL;

	DeleteDC( ::HDC( m_memoryDeviceContextIndependant ) );
	m_memoryDeviceContextIndependant = HNULL;

	return;
}

///////////////////////////////////////////////////////
// public methods, implement SWindowImplementationImage
/**/
const Hubris::HVectorS2 SWindowImplementationImage::SizeGet()const
{
	return( m_size );
}

/**/
Hubris::HVOID SWindowImplementationImage::PixelSet(
	const Hubris::HVectorS2& in_pos,
	const Pride::PColourRgba& in_colour
	)
{
	const COLORREF colour = RGB( in_colour.RedGet(), in_colour.GreenGet(), in_colour.BlueGet() );

	SetPixel( ::HDC( m_memoryDeviceContextIndependant ), in_pos[ 0 ], in_pos[ 1 ], colour );

	return;
}
/**/
Hubris::HVOID SWindowImplementationImage::ImageSet(
	const Pride::PImageRgba& in_image
	)
{
	if( HNULL == m_pbitmapIndependantData )
	{
		return;
	}

	HCOMMON_ASSERT( m_size == in_image.SizeGet(), "size missmatch" );

	const HSINT size = m_size[ 0 ] * m_size[ 1 ] * 4;

	memcpy( m_pbitmapIndependantData, in_image.RawGet(), size_t( size ) );

	return;
}
/**/
Hubris::HVOID SWindowImplementationImage::PixelWipe(
	const Pride::PColourRgba& in_colour
	)
{
	const COLORREF colour = RGB( in_colour.RedGet(), in_colour.GreenGet(), in_colour.BlueGet() );
	LocalFillDevice( ::HDC( m_memoryDeviceContextIndependant ), m_size, colour );
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
SInterfaceImage* const SWindowImplementationImage::ImageInterfaceCreate()
{
	SInterfaceImage* pInterface = HNULL;
	HCOMMON_NEW_PARAM(
		pInterface,
		SWindowImageInterface,
		( *this )
		);

	return pInterface;
}

/**/
