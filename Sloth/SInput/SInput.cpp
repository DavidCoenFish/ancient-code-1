//file: Sloth/SInput/SInput.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SInput/SInput.h"

#include "Sloth/SInput/SInputImplementation.h"
#include "Sloth/SInput/SInputKeyboard.h"
#include "Sloth/SInput/SInputMouse.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SInput::SInput( 
	const SInputParam& in_param
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM(
		m_pImplementation,
		SInputImplementation,
		in_param
		);

	return;
}

/**/
SInput::~SInput()
{
	HCOMMON_DELETE(
		m_pImplementation,
		SInputImplementation
		);

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT SInput::ButtonStateGet(
	const Hubris::HSINT in_deviceIndex,
	const Hubris::HSINT in_inputIndex
	)const
{
	const Hubris::HSINT result = ImplementationGet().ButtonStateGet(
		in_deviceIndex,
		in_inputIndex
		);
	return result;
}

/**/
const Hubris::HREAL SInput::InputAmountGet(
	const Hubris::HSINT in_deviceIndex,
	const Hubris::HSINT in_inputIndex
	)const
{
	const Hubris::HREAL result = ImplementationGet().InputAmountGet(
		in_deviceIndex,
		in_inputIndex
		);
	return result;
}

/**/
const Hubris::HREAL SInput::InputDeltaGet(
	const Hubris::HSINT in_deviceIndex,
	const Hubris::HSINT in_inputIndex
	)const
{
	const Hubris::HREAL result = ImplementationGet().InputDeltaGet(
		in_deviceIndex,
		in_inputIndex
		);
	return result;
}

/**/
Hubris::HVOID SInput::UpdatePreProcessMessages()
{
	ImplementationGet().UpdatePreProcessMessages();
	return;
}
/**/
Hubris::HVOID SInput::ProcessMessages(
	HWND in_hWnd,
	const Hubris::HU32 in_uMessage,
	const Hubris::HU32 in_wParam,
	const Hubris::HU32 in_lParam			
	)
{
	ImplementationGet().ProcessMessages(
		in_hWnd,
		in_uMessage,
		in_wParam,
		in_lParam
		);
	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT SInput::DeviceIndexKeyboardGet()
{
	return( SInputImplementation::DeviceIndexKeyboardGet() );
}

/**/
const Hubris::HSINT SInput::DeviceIndexMouseGet()
{
	return( SInputImplementation::DeviceIndexMouseGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexMouseLeftGet()
{
	return( SInputMouse::InputIndexMouseLeftGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexMouseMiddleGet()
{
	return( SInputMouse::InputIndexMouseMiddleGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexMouseRightGet()
{
	return( SInputMouse::InputIndexMouseRightGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexMouseHorizontalGet()
{
	return( SInputMouse::InputIndexMouseHorizontalGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexMouseVerticalGet()
{
	return( SInputMouse::InputIndexMouseVerticalGet() );
}

/**/
const Hubris::HSINT SInput::ButtonStateNoneGet()
{
	return( SInputItemData::ButtonStateNoneGet() );
}

/**/
const Hubris::HSINT SInput::ButtonStateUpGet()
{
	return( SInputItemData::ButtonStateUpGet() );
}

/**/
const Hubris::HSINT SInput::ButtonStateDownGet()
{
	return( SInputItemData::ButtonStateDownGet() );
}

/**/
const Hubris::HSINT SInput::ButtonStateChangedToUpGet()
{
	return( SInputItemData::ButtonStateChangedToUpGet() );
}

/**/
const Hubris::HSINT SInput::ButtonStateChangedToDownGet()
{
	return( SInputItemData::ButtonStateChangedToDownGet() );
}

/**/
const Hubris::HSINT SInput::ButtonStateModifierGet()
{
	return( SInputItemData::ButtonStateModifierGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardEscapeGet() 
{
	return( SInputKeyboard::InputIndexKeyboardEscapeGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardShiftGet()  
{
	return( SInputKeyboard::InputIndexKeyboardShiftGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardControlGet()
{
	return( SInputKeyboard::InputIndexKeyboardControlGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardMenuGet()   
{
	return( SInputKeyboard::InputIndexKeyboardMenuGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardCapitalGet()
{
	return( SInputKeyboard::InputIndexKeyboardCapitalGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardReturnGet() 
{
	return( SInputKeyboard::InputIndexKeyboardReturnGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardSpaceGet()  
{
	return( SInputKeyboard::InputIndexKeyboardSpaceGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardLeftGet()   
{
	return( SInputKeyboard::InputIndexKeyboardLeftGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardUpGet()     
{
	return( SInputKeyboard::InputIndexKeyboardUpGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardRightGet()  
{
	return( SInputKeyboard::InputIndexKeyboardRightGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardDownGet()   
{
	return( SInputKeyboard::InputIndexKeyboardDownGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad0Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad0Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad1Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad1Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad2Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad2Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad3Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad3Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad4Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad4Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad5Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad5Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad6Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad6Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad7Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad7Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad8Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad8Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardNumPad9Get()
{
	return( SInputKeyboard::InputIndexKeyboardNumPad9Get() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardMultiply()
{
	return( SInputKeyboard::InputIndexKeyboardMultiply() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardAddGet()    
{
	return( SInputKeyboard::InputIndexKeyboardAddGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardSeparator()
{
	return( SInputKeyboard::InputIndexKeyboardSeparator() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardSubtract()
{
	return( SInputKeyboard::InputIndexKeyboardSubtract() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardDecimalGet()
{
	return( SInputKeyboard::InputIndexKeyboardDecimalGet() );
}

/**/
const Hubris::HSINT SInput::InputIndexKeyboardDivideGet() 
{
	return( SInputKeyboard::InputIndexKeyboardDivideGet() );
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SInputImplementation& SInput::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
SInputImplementation& SInput::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
