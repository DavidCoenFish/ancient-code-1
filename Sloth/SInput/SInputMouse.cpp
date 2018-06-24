//file: Sloth/SInput/SInputMouse.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SInput/SInputMouse.h"

#include< windows.h >
#include< windowsx.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
struct TInputIndex
{
	enum TEnum
	{
		TMouseLeft = 0,
		TMouseMiddle,
		TMouseRight,
		TMouseHorizontal,
		TMouseVertical,

		TCount
	};
};

///////////////////////////////////////////////////////
// static local methods
/**/
static HVOID LocalMouseMove(
	SInputItemData& in_out_itemDataHorizontal,
	SInputItemData& in_out_itemDataVertical,
	HWND in_hWnd,
	const Hubris::HU32 in_lParam			
	)
{
	RECT rect;
	memset( &rect, 0, sizeof( RECT ) );
	if( 0 == GetWindowRect( in_hWnd, &rect ) )
	{
		return;
	}
	const HSINT width = rect.right - rect.left;
	const HSINT height = rect.bottom - rect.top;

	const HSINT xPos = GET_X_LPARAM( in_lParam ); 
	const HSINT yPos = GET_Y_LPARAM( in_lParam ); 

	if( 0 != width )
	{
		const HREAL ratio = ( ( HREAL )( xPos ) ) / ( ( HREAL )( width ) );
		in_out_itemDataHorizontal.ValueSet( ratio );
	}

	if( 0 != height )
	{
		const HREAL ratio = ( ( HREAL )( yPos ) ) / ( ( HREAL )( height ) );
		in_out_itemDataVertical.ValueSet( ratio );
	}

	return;
}

/**/
static HVOID LocalCaseButtonDown(
	SInputItemData& in_out_itemData,
	const Hubris::HU32 in_wParam,
	HWND in_hWnd
	)
{
	SetCapture( in_hWnd );

	HSINT newFlag = SInputItemData::ButtonStateNoneGet();
	const HSINT flag = in_out_itemData.FlagGet();
	if( 0 == ( SInputItemData::ButtonStateDownGet() & flag ) )
	{
		newFlag |= SInputItemData::ButtonStateChangedToDownGet();
	}

	newFlag |= SInputItemData::ButtonStateDownGet();

	if( in_wParam & MK_SHIFT )
	{
		newFlag |= SInputItemData::ButtonStateModifierGet();
	}

	in_out_itemData.FlagSet( newFlag );
	in_out_itemData.ValueSet( HVariablesMath::UnitGet< HREAL >() );

	return;
}

/**/
static HVOID LocalCaseButtonUp(
	SInputItemData& in_out_itemData,
	const Hubris::HU32 in_wParam
	)
{
	ReleaseCapture();

	HSINT newFlag = SInputItemData::ButtonStateNoneGet();
	const HSINT flag = in_out_itemData.FlagGet();
	if( 0 == ( SInputItemData::ButtonStateUpGet() & flag ) )
	{
		newFlag |= SInputItemData::ButtonStateChangedToUpGet();
	}

	newFlag |= SInputItemData::ButtonStateUpGet();

	if( in_wParam & MK_SHIFT )
	{
		newFlag |= SInputItemData::ButtonStateModifierGet();
	}

	in_out_itemData.FlagSet( newFlag );
	in_out_itemData.ValueSet( HVariablesMath::ZeroGet< HREAL >() );

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SInputMouse::SInputMouse()
: m_arrayItemData()
{
	m_arrayItemData.SizeSet( TInputIndex::TCount );
	return;
}

/**/
SInputMouse::~SInputMouse()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT SInputMouse::ButtonStateGet(
	const Hubris::HSINT in_inputIndex
	)const
{
	return( m_arrayItemData[ in_inputIndex ].FlagGet() );
}

/**/
const Hubris::HREAL SInputMouse::InputAmountGet(
	const Hubris::HSINT in_inputIndex
	)const
{
	return( m_arrayItemData[ in_inputIndex ].ValueGet() );
}

/**/
const Hubris::HREAL SInputMouse::InputDeltaGet(
	const Hubris::HSINT in_inputIndex
	)const
{
	const SInputItemData& itemData = m_arrayItemData[ in_inputIndex ];
	const HREAL delta = itemData.ValueGet() - itemData.PreviousValueGet();
	return delta;
}

/**/
Hubris::HVOID SInputMouse::UpdatePreProcessMessages()
{
	HCOMMON_FOR_EACH( input, m_arrayItemData, TArrayItemData )
	{
		input.Update();
	}

	return;
}

/**/
Hubris::HVOID SInputMouse::ProcessMessages(
	HWND in_hWnd,
	const Hubris::HU32 in_uMessage,
	const Hubris::HU32 in_wParam,
	const Hubris::HU32 in_lParam			
	)
{
	switch( in_uMessage )
	{
	default:
		{
			break;
		}
	case WM_MOUSEMOVE:
		{
			LocalMouseMove(
				m_arrayItemData[ TInputIndex::TMouseHorizontal ],
				m_arrayItemData[ TInputIndex::TMouseVertical ],
				( ::HWND )in_hWnd,
				in_lParam
				);
			break;
		}
	case WM_LBUTTONDOWN:
		{
			LocalCaseButtonDown(
				m_arrayItemData[ TInputIndex::TMouseLeft ],
				in_wParam,
				( ::HWND )in_hWnd
				);
			break;
		}
	case WM_LBUTTONUP:
		{
			LocalCaseButtonUp(
				m_arrayItemData[ TInputIndex::TMouseLeft ],
				in_wParam
				);
			break;
		}
	case WM_MBUTTONDOWN:
		{
			LocalCaseButtonDown(
				m_arrayItemData[ TInputIndex::TMouseMiddle ],
				in_wParam,
				( ::HWND )in_hWnd
				);
			break;
		}
	case WM_MBUTTONUP:
		{
			LocalCaseButtonUp(
				m_arrayItemData[ TInputIndex::TMouseMiddle ],
				in_wParam
				);
			break;
		}
	case WM_RBUTTONDOWN:
		{
			LocalCaseButtonDown(
				m_arrayItemData[ TInputIndex::TMouseRight ],
				in_wParam,
				( ::HWND )in_hWnd
				);
			break;
		}
	case WM_RBUTTONUP:
		{
			LocalCaseButtonUp(
				m_arrayItemData[ TInputIndex::TMouseRight ],
				in_wParam
				);
			break;
		}
	}

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HSINT SInputMouse::InputIndexMouseLeftGet()
{
	return( TInputIndex::TMouseLeft );
}

/**/
const Hubris::HSINT SInputMouse::InputIndexMouseMiddleGet()
{
	return( TInputIndex::TMouseMiddle );
}

/**/
const Hubris::HSINT SInputMouse::InputIndexMouseRightGet()
{
	return( TInputIndex::TMouseRight );
}

/**/
const Hubris::HSINT SInputMouse::InputIndexMouseHorizontalGet()
{
	return( TInputIndex::TMouseHorizontal );
}

/**/
const Hubris::HSINT SInputMouse::InputIndexMouseVerticalGet()
{
	return( TInputIndex::TMouseVertical );
}

/**/
