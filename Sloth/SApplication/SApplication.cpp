//file: Sloth/SApplication/SApplication.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SApplication/SApplication.h"

#include "Sloth/SCursor/SCursor_Export.h"
#include "Sloth/SIcon/SIcon_Export.h"
#include "Sloth/SWindow/SWindow_Export.h"

#include <WINDOWS.H>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/*
int WinMain(
	HINSTANCE in_hInstance,
    HINSTANCE in_hPrevInstance,
    LPSTR in_lpCmdLine,
    int in_nCmdShow
)
{
	SApplication application( in_hInstance, in_lpCmdLine, in_nCmdShow );

	IN_TASK_OBJECT.Run( application );

	return 0;
}

*/

///////////////////////////////////////////////////////
// creation
Sloth::SApplication::SApplication( 
	HINSTANCE in_hInstance,
	const Hubris::HString& in_commandLine,
	int in_nCmdShow			
	)
	: m_hinstance( in_hInstance )
	, m_commandLine( in_commandLine )
	, m_commandShow( in_nCmdShow )	
{
	return;
}

/**/
Sloth::SApplication::~SApplication()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
//SMenu* const Sloth::SApplication::MenuRequest()
//HVOID Sloth::SApplication::MenuRelease( SMenu*& in_out_pMenu )

SCursor* const Sloth::SApplication::CursorRequest( const SCursorParam& in_cursorParam )
{
	SCursor* pCursor = HNULL;
	HCOMMON_NEW_PARAM(
		pCursor,
		SCursor,
		in_cursorParam
		);

	return pCursor;
}

HVOID Sloth::SApplication::CursorRelease( SCursor*& in_out_pCursor )
{
	HCOMMON_DELETE( in_out_pCursor, SCursor );

	return;
}

/**/
SIcon* const Sloth::SApplication::IconRequest( const SIconParam& in_iconParam )
{
	SIcon* pIcon = HNULL;
	HCOMMON_NEW_PARAM(
		pIcon,
		SIcon,
		in_iconParam
		);

	return pIcon;
}

/**/
HVOID Sloth::SApplication::IconRelease( SIcon*& in_out_pIcon )
{
	HCOMMON_DELETE( in_out_pIcon, SIcon );

	return;
}

/**/
SWindowImage* const Sloth::SApplication::WindowImageRequest( const SWindowParam& in_windowParam )
{
	SWindowImage* pWindow = HNULL;
	HCOMMON_NEW_PARAM_2(
		pWindow,
		SWindowImage,
		m_hinstance,
		in_windowParam
		);

	return pWindow;
}

/**/
Hubris::HVOID Sloth::SApplication::WindowImageRelease( SWindowImage*& in_out_pWindowImage )
{
	HCOMMON_DELETE( 
		in_out_pWindowImage, 
		SWindow 
		);
	return;
}

/**/
SWindowRender* const Sloth::SApplication::WindowRenderRequest( const SWindowParamDirectX& in_windowParamDirectX )
{
	SWindowRender* pWindow = HNULL;
	HCOMMON_NEW_PARAM_2(
		pWindow,
		SWindowRender,
		m_hinstance,
		in_windowParamDirectX
		);

	return pWindow;
}

/**/
SWindowRender* const Sloth::SApplication::WindowRenderRequest( const SWindowParamOpenGl& in_windowParamOpenGl )
{
	SWindowRender* pWindow = HNULL;
	HCOMMON_NEW_PARAM_2(
		pWindow,
		SWindowRender,
		m_hinstance,
		in_windowParamOpenGl
		);

	return pWindow;
}

/**/
Hubris::HVOID Sloth::SApplication::WindowRenderRelease( SWindowRender*& in_out_pWindowRender )
{
	HCOMMON_DELETE( 
		in_out_pWindowRender, 
		SWindowRender 
		);
	return;
}

/**/

//SConsole* const Sloth::SApplication::ConsoleRequest()
//HVOID Sloth::SApplication::ConsoleRelease( SConsole*& in_out_pConsole )

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetHide()const
{
	return( SW_HIDE == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetMaximize()const
{
	return( SW_MAXIMIZE == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetMinimize()const
{
	return( SW_MINIMIZE == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetRestore()const
{
	return( SW_RESTORE == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetShow()const
{
	return( SW_SHOW == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetShowMaximized()const
{
	return( SW_SHOWMAXIMIZED == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetShowMinimized()const
{
	return( SW_SHOWMINIMIZED == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetShowMinNoActive()const
{
	return( SW_SHOWMINNOACTIVE == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetShowNA()const
{
	return( SW_SHOWNA == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetShowNoActivate()const
{
	return( SW_SHOWNOACTIVATE == m_commandShow );
}

/**/
const Hubris::HBOOL Sloth::SApplication::CommandShowGetShowNormal()const
{
	return( SW_SHOWNORMAL == m_commandShow );
}

/**/