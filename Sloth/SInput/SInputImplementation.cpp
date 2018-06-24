//file: Sloth/SInput/SInputImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SInput/SInputImplementation.h"

#include "Sloth/SInput/SInputKeyboard.h"
#include "Sloth/SInput/SInputMouse.h"
#include "Sloth/SInput/SInputParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TDevice
{
	enum TEnum
	{
		TKeyboard = 0,
		TMouse,

		TCount
	};
};

///////////////////////////////////////////////////////
// creation
/**/
SInputImplementation::SInputImplementation( 
	const SInputParam& HCOMMON_UNUSED_VAR( in_param )
	)
: m_pKeyboard( HNULL )
, m_pMouse( HNULL )
{
	HCOMMON_NEW(
		m_pKeyboard,
		SInputKeyboard
		);

	HCOMMON_NEW(
		m_pMouse,
		SInputMouse
		);

	return;
}

/**/
SInputImplementation::~SInputImplementation()
{
	HCOMMON_DELETE(
		m_pKeyboard,
		SInputKeyboard
		);

	HCOMMON_DELETE(
		m_pMouse,
		SInputMouse
		);

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT SInputImplementation::ButtonStateGet(
	const Hubris::HSINT in_deviceIndex,
	const Hubris::HSINT in_inputIndex
	)const
{
	switch( in_deviceIndex )
	{
	default:
		{
			break;
		}
	case TDevice::TKeyboard:
		{
			return( KeyboardGet().ButtonStateGet( in_inputIndex ) );
		}
	case TDevice::TMouse:
		{
			return( MouseGet().ButtonStateGet( in_inputIndex ) );
		}
	}

	return 0;
}

/**/
const Hubris::HREAL SInputImplementation::InputAmountGet(
	const Hubris::HSINT in_deviceIndex,
	const Hubris::HSINT in_inputIndex
	)const
{
	switch( in_deviceIndex )
	{
	default:
		{
			break;
		}
	case TDevice::TKeyboard:
		{
			return( KeyboardGet().InputAmountGet( in_inputIndex ) );
		}
	case TDevice::TMouse:
		{
			return( MouseGet().InputAmountGet( in_inputIndex ) );
		}
	}

	return 0;
}

/**/
const Hubris::HREAL SInputImplementation::InputDeltaGet(
	const Hubris::HSINT in_deviceIndex,
	const Hubris::HSINT in_inputIndex
	)const
{
	switch( in_deviceIndex )
	{
	default:
		{
			break;
		}
	case TDevice::TKeyboard:
		{
			return( KeyboardGet().InputDeltaGet( in_inputIndex ) );
		}
	case TDevice::TMouse:
		{
			return( MouseGet().InputDeltaGet( in_inputIndex ) );
		}
	}

	return 0;
}

/**/
Hubris::HVOID SInputImplementation::UpdatePreProcessMessages()
{
	KeyboardGet().UpdatePreProcessMessages();
	MouseGet().UpdatePreProcessMessages();

	return;
}

/**/
Hubris::HVOID SInputImplementation::ProcessMessages(
	HWND in_hWnd,
	const Hubris::HU32 in_uMessage,
	const Hubris::HU32 in_wParam,
	const Hubris::HU32 in_lParam
	)
{
	KeyboardGet().ProcessMessages( 
		in_hWnd,
		in_uMessage,
		in_wParam,
		in_lParam
		);
	MouseGet().ProcessMessages(
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
const Hubris::HSINT SInputImplementation::DeviceIndexKeyboardGet()
{
	return( TDevice::TKeyboard );
}

/**/
const Hubris::HSINT SInputImplementation::DeviceIndexMouseGet()
{
	return( TDevice::TMouse );
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SInputKeyboard& SInputImplementation::KeyboardGet()const
{
	HCOMMON_ASSERT( HNULL != m_pKeyboard, "invalid member" );
	return( *m_pKeyboard );
}

/**/
SInputKeyboard& SInputImplementation::KeyboardGet()
{
	HCOMMON_ASSERT( HNULL != m_pKeyboard, "invalid member" );
	return( *m_pKeyboard );
}

/**/
const SInputMouse& SInputImplementation::MouseGet()const
{
	HCOMMON_ASSERT( HNULL != m_pMouse, "invalid member" );
	return( *m_pMouse );
}

/**/
SInputMouse& SInputImplementation::MouseGet()
{
	HCOMMON_ASSERT( HNULL != m_pMouse, "invalid member" );
	return( *m_pMouse );
}

/**/
