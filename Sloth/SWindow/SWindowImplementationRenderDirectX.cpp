//file: Sloth/SWindow/SWindowImplementationRenderDirectX.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowImplementationRenderDirectX.h"

#include "Sloth/SWindow/SWindowParamDirectX.h"

#include "Sloth/SInterface/SInterface_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowImplementationRenderDirectX::SWindowImplementationRenderDirectX()
: SWindowImplementationRender()
{
	return;
}

/**/
SWindowImplementationRenderDirectX::~SWindowImplementationRenderDirectX()
{
	return;
}

///////////////////////////////////////////////////////
// implement SWindowImplementationBase
/**/
Hubris::HVOID SWindowImplementationRenderDirectX::OnClose(
	HWND in_hWnd 
	)
{
	in_hWnd;
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderDirectX::OnCreate( 
	HWND in_hWnd 
	)
{
	in_hWnd;
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderDirectX::OnPaint( 
	HWND in_hWnd 
	)
{
	in_hWnd;
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderDirectX::OnSize( 
	HWND in_hWnd,
	const Hubris::HSINT in_width,
	const Hubris::HSINT in_height
	)
{
	in_hWnd;
	in_width;
	in_height;
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderDirectX::OnDestroy(
	HWND in_hWnd 			
	)
{
	in_hWnd;
	return;
}

///////////////////////////////////////////////////////
// implement SWindowImplementationRender
/**/
SInterfaceRender* const SWindowImplementationRenderDirectX::RenderInterfaceCreate()
{
	SInterfaceRender* pInterface = HNULL;
	HCOMMON_NEW_PARAM(
		pInterface,
		SInterfaceRender,
		( *this )
		);

	return( pInterface );
}
