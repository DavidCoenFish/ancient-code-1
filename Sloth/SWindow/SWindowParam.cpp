//file: Sloth/SWindow/SWindowParam.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowParam.h"

#include <WINDOWS.H>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowParam::SWindowParam(
	const Hubris::HString& in_className,
	const Hubris::HString& in_windowTitle,
	const Hubris::HBOOL in_showWindow,
	const Hubris::HU32 in_classStyle,
	const Hubris::HU32 in_windowStyle,
	const Hubris::HVectorS2& in_windowOrigin,
	const Hubris::HVectorS2& in_windowDimention,
	//SInput* const in_pInput,
	SCursor* const in_pCursor,
	SIcon* const in_pIcon,
	SMenu* const in_pMenu,
	const HWND in_parentHWnd
	)
: m_className( in_className )
, m_windowTitle( in_windowTitle )
, m_showWindow( in_showWindow )
, m_classStyle( in_classStyle )
, m_windowStyle( in_windowStyle )
, m_windowOrigin( in_windowOrigin )
, m_windowDimention( in_windowDimention )
//, m_pInput( in_pInput )
, m_pCursor( in_pCursor )
, m_pIcon( in_pIcon )
, m_pMenu( in_pMenu )
, m_parentHWnd( in_parentHWnd )
{
	return;
}

/**/
SWindowParam::~SWindowParam()
{
	return;
}

///////////////////////////////////////////////////////
// public static accessors
/**/
const Hubris::HU32 SWindowParam::ClassStyleDefaultGet()
{
	return 0; //( CS_HREDRAW | CS_VREDRAW ); //| CS_BYTEALIGNCLIENT | CS_BYTEALIGNWINDOW );
}

const Hubris::HU32 SWindowParam::WindowStyleDefaultGet()
{
	return( WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN );
}

/**/
