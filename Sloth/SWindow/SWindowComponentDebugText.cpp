//file: Sloth/SWindow/SWindowComponentDebugText.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowComponentDebugText.h"

#include< windows.h > 

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// static local functions
/**/
static const HVectorS2 LocalTextMetricGet( ::HDC in_memoryDeviceContext )
{
	TEXTMETRIC textMetric;
	SecureZeroMemory( &textMetric, sizeof( textMetric ) );

	GetTextMetrics( ( HDC )in_memoryDeviceContext, &textMetric );

	return HMatrixConstructor::HVectorS2Construct( textMetric.tmMaxCharWidth, textMetric.tmHeight );
}

/**/
static HVOID LocalTextPut( 
	HDC in_memoryDeviceContext,
	HWND in_hWnd,
	const Hubris::HVectorS2& in_textMetric,
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_location,
	const Pride::PColourRgb& in_foregroundColour,
	const Pride::PColourRgb& in_backgroundColour
	)
{
	HVectorS2 textOrigin( in_location );
	textOrigin[ 0 ] *= in_textMetric[ 0 ];
	textOrigin[ 1 ] *= in_textMetric[ 1 ];

	SetTextColor( in_memoryDeviceContext, RGB( in_foregroundColour.RedGet(), in_foregroundColour.GreenGet(), in_foregroundColour.BlueGet() ) );
	SetBkColor( in_memoryDeviceContext, RGB( in_backgroundColour.RedGet(), in_backgroundColour.GreenGet(), in_backgroundColour.BlueGet() ) );

	BOOL result = 0;
	result = TextOut(
		in_memoryDeviceContext, 
		textOrigin[ 0 ], 
		textOrigin[ 1 ], 
		in_text.RawGet(), 
		in_text.SizeGet()
	);

	SIZE writenSize;

	GetTextExtentPoint32( 
		in_memoryDeviceContext, 
		in_text.RawGet(),
		in_text.SizeGet(), 
		&writenSize
	); 

	RECT redrawArea;
	redrawArea.left = textOrigin[ 0 ];
	redrawArea.top = textOrigin[ 1 ];
	redrawArea.right = redrawArea.left + writenSize.cx;
	redrawArea.bottom = redrawArea.top + writenSize.cy;

	InvalidateRect(
		in_hWnd,
		&redrawArea,
		FALSE
	);

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SWindowComponentDebugText::SWindowComponentDebugText()
: m_arrayData()
{
	return;
}

/**/
SWindowComponentDebugText::~SWindowComponentDebugText()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SWindowComponentDebugText::TextAdd(
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_location,
	const Pride::PColourRgb& in_foregroundColour,
	const Pride::PColourRgb& in_backgroundColour
	)
{
	m_arrayData.Insert(
		SWindowComponentDebugTextData(
			in_text,
			in_location,
			in_foregroundColour,
			in_backgroundColour
			)
		);
			
	return;
}

/**/
Hubris::HVOID SWindowComponentDebugText::TextClear()
{
	m_arrayData.Clear();
	return;
}

/**/
Hubris::HVOID SWindowComponentDebugText::TextDraw(
	HWND in_hwnd
	)
{
	if( m_arrayData.SizeGet() <= 0 )
	{
		return;
	}

	//GdiFlush();

	PAINTSTRUCT paintStruct;
	SecureZeroMemory( &paintStruct, sizeof( paintStruct ) );

	HDC deviceContext = BeginPaint( ( ::HWND )in_hwnd, &paintStruct );

	const COLORREF oldTextColor = GetTextColor( deviceContext ); 
	const COLORREF oldBkColor = GetBkColor( deviceContext ); 

	const HVectorS2 textMetric = LocalTextMetricGet( deviceContext );

	HCOMMON_FOR_EACH( data, m_arrayData, TArrayData )
	{
		LocalTextPut( 
			deviceContext,
			( ::HWND )in_hwnd,
			textMetric,
			data.TextGet(),
			data.LocationGet(),
			data.ForegroundColourGet(),
			data.BackgroundColourGet()
			);
	}

	SetTextColor( deviceContext, oldTextColor );
	SetBkColor( deviceContext, oldBkColor );

	EndPaint( ( ::HWND )in_hwnd, &paintStruct );

	//GdiFlush();

	return;
}

/**/
