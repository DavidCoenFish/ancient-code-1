//file: Sloth/SInput/SInputKeyboard.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SInput/SInputKeyboard.h"

#include< Windows.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerTree< Hubris::HSINT, SInputItemData >TTreeSintItemData;

struct TKeyCode
{
	enum TEnum
	{
		TEscape = VK_ESCAPE,
		TShift = VK_SHIFT,
		TControl = VK_CONTROL,
		TMenu = VK_MENU,
		TCapital = VK_CAPITAL,
		TReturn = VK_RETURN,
		TSpace = VK_SPACE,
		TLeft = VK_LEFT,
		TUp = VK_UP,
		TRight = VK_RIGHT,
		TDown = VK_DOWN,
		TNumPad0 = VK_NUMPAD0,
		TNumPad1 = VK_NUMPAD1,
		TNumPad2 = VK_NUMPAD2,
		TNumPad3 = VK_NUMPAD3,
		TNumPad4 = VK_NUMPAD4,
		TNumPad5 = VK_NUMPAD5,
		TNumPad6 = VK_NUMPAD6,
		TNumPad7 = VK_NUMPAD7,
		TNumPad8 = VK_NUMPAD8, 
		TNumPad9 = VK_NUMPAD9,
		TMultiply = VK_MULTIPLY,
		TAdd = VK_ADD,
		TSeparator = VK_SEPARATOR,
		TSubtract = VK_SUBTRACT, 
		TDecimal = VK_DECIMAL, 
		TDivide = VK_DIVIDE,
	};
};

///////////////////////////////////////////////////////
// static local methods
/**/
static Hubris::HVOID LocalOnKeyDown(
	TTreeSintItemData& in_out_treeInputState,
	const Hubris::HU32 in_wParam,
	const Hubris::HU32 in_lParam
	)
{
	TTreeSintItemData::TIterator iterator = in_out_treeInputState.Find( in_wParam );
	if( iterator == in_out_treeInputState.End() )
	{
		return;
	}

	HSINT newFlag = SInputItemData::ButtonStateDownGet();
	//if( ( 1 << 24 ) & in_lParam )
	//{
	//	newFlag |= SInputItemData::ButtonStateModifierGet();
	//}

	if( 0 == ( ( 1 << 30 ) & in_lParam ) )
	{
		newFlag |= SInputItemData::ButtonStateChangedToDownGet();
	}

	SInputItemData& itemData = ( *iterator );
	itemData.FlagSet( newFlag );
	itemData.ValueSet( HVariablesMath::UnitGet< HREAL >() );

	return;
}

/**/
static Hubris::HVOID LocalOnKeyUp(
	TTreeSintItemData& in_out_treeInputState,
	const Hubris::HU32 in_wParam,
	const Hubris::HU32 in_lParam
	)
{
	TTreeSintItemData::TIterator iterator = in_out_treeInputState.Find( in_wParam );
	if( iterator == in_out_treeInputState.End() )
	{
		return;
	}

	HSINT newFlag = SInputItemData::ButtonStateUpGet();
	//if( ( 1 << 24 ) & in_lParam )
	//{
	//	newFlag |= SInputItemData::ButtonStateModifierGet();
	//}

	if( 0 != ( ( 1 << 30 ) & in_lParam ) )
	{
		newFlag |= SInputItemData::ButtonStateChangedToUpGet();
	}

	SInputItemData& itemData = ( *iterator );
	itemData.FlagSet( newFlag );
	itemData.ValueSet( HVariablesMath::ZeroGet< HREAL >() );

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SInputKeyboard::SInputKeyboard()
: m_treeKeyState()
{
	m_treeKeyState.Insert( TKeyCode::TEscape, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TShift, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TControl, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TMenu, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TCapital, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TReturn, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TSpace, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TLeft, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TUp, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TRight, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TDown, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad0, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad1, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad2, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad3, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad4, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad5, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad6, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad7, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad8, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TNumPad9, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TMultiply, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TAdd, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TSeparator, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TSubtract, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TDecimal, SInputItemData() );
	m_treeKeyState.Insert( TKeyCode::TDivide, SInputItemData() );
	return;
}

/**/
SInputKeyboard::~SInputKeyboard()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT SInputKeyboard::ButtonStateGet(
	const Hubris::HSINT in_inputIndex
	)const
{
	const TTreeSintItemData::TIterator iterator = m_treeKeyState.Find( in_inputIndex );
	if( iterator != m_treeKeyState.End() )
	{
		return( ( *iterator ).FlagGet() );
	}
	return 0;
}

/**/
const Hubris::HREAL SInputKeyboard::InputAmountGet(
	const Hubris::HSINT in_inputIndex
	)const
{
	const TTreeSintItemData::TIterator iterator = m_treeKeyState.Find( in_inputIndex );
	if( iterator != m_treeKeyState.End() )
	{
		return( ( *iterator ).ValueGet() );
	}
	return 0;
}

/**/
const Hubris::HREAL SInputKeyboard::InputDeltaGet(
	const Hubris::HSINT in_inputIndex
	)const
{
	const TTreeSintItemData::TIterator iterator = m_treeKeyState.Find( in_inputIndex );
	if( iterator != m_treeKeyState.End() )
	{
		const SInputItemData& itemData = ( *iterator );
		const HREAL delta = itemData.ValueGet() - itemData.PreviousValueGet();
		return delta;
	}
	return 0;
}

/**/
Hubris::HVOID SInputKeyboard::UpdatePreProcessMessages()
{
	HCOMMON_FOR_EACH( itemData, m_treeKeyState, TTreeSintItemData )
	{
		itemData.Update();
	}
	return;
}

/**/
Hubris::HVOID SInputKeyboard::ProcessMessages(
	HWND HCOMMON_UNUSED_VAR( in_hWnd ),
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
    case WM_KEYDOWN: 
		{
			LocalOnKeyDown(
				m_treeKeyState,
				in_wParam, 
				in_lParam
				);
			break;
		}
	case WM_KEYUP:
		{
			LocalOnKeyUp(
				m_treeKeyState,
				in_wParam, 
				in_lParam
				);
			break;
		}
	}

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardEscapeGet() 
{
	return( TKeyCode::TEscape );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardShiftGet()  
{
	return( TKeyCode::TShift );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardControlGet()
{
	return( TKeyCode::TControl );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardMenuGet()   
{
	return( TKeyCode::TMenu );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardCapitalGet()
{
	return( TKeyCode::TCapital );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardReturnGet() 
{
	return( TKeyCode::TReturn );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardSpaceGet()  
{
	return( TKeyCode::TSpace );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardLeftGet()   
{
	return( TKeyCode::TLeft );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardUpGet()     
{
	return( TKeyCode::TUp );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardRightGet()  
{
	return( TKeyCode::TRight );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardDownGet()   
{
	return( TKeyCode::TDown );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad0Get()
{
	return( TKeyCode::TNumPad0 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad1Get()
{
	return( TKeyCode::TNumPad1 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad2Get()
{
	return( TKeyCode::TNumPad2 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad3Get()
{
	return( TKeyCode::TNumPad3 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad4Get()
{
	return( TKeyCode::TNumPad4 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad5Get()
{
	return( TKeyCode::TNumPad5 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad6Get()
{
	return( TKeyCode::TNumPad6 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad7Get()
{
	return( TKeyCode::TNumPad7 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad8Get()
{
	return( TKeyCode::TNumPad8 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardNumPad9Get()
{
	return( TKeyCode::TNumPad9 );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardMultiply()
{
	return( TKeyCode::TMultiply );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardAddGet()    
{
	return( TKeyCode::TAdd );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardSeparator()
{
	return( TKeyCode::TSeparator );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardSubtract()
{
	return( TKeyCode::TSubtract );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardDecimalGet()
{
	return( TKeyCode::TDecimal );
}

/**/
const Hubris::HSINT SInputKeyboard::InputIndexKeyboardDivideGet() 
{
	return( TKeyCode::TDivide );
}

/**/