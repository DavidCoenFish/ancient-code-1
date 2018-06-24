//file: Sloth/SWindow/SWindowParamOpenGl.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowParamOpenGl.h"

#include <WINDOWS.H>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowParamOpenGl::SWindowParamOpenGl(
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
	SMenu* const in_pMenu
	)
: SWindowParam(
	in_className,
	in_windowTitle,
	in_showWindow,
	in_classStyle,
	in_windowStyle,
	in_windowOrigin,
	in_windowDimention,
	//in_pInput,
	in_pCursor,
	in_pIcon,
	in_pMenu
	)
{
	return;
}

/**/
SWindowParamOpenGl::~SWindowParamOpenGl()
{
	return;
}

///////////////////////////////////////////////////////
// public static accessors
/**/
const Hubris::HU32 SWindowParamOpenGl::ClassStyleDefaultGet()
{
	return( SWindowParam::ClassStyleDefaultGet() | CS_OWNDC );
}

/**/
const Hubris::HU32 SWindowParamOpenGl::WindowStyleDefaultGet()
{
	return( SWindowParam::WindowStyleDefaultGet() );
}
/**/
