//file: Sloth/SWindow/SWindowParamDirectX.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowParamDirectX.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowParamDirectX::SWindowParamDirectX(
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
SWindowParamDirectX::~SWindowParamDirectX()
{
	return;
}

///////////////////////////////////////////////////////
// public static accessors
/**/
const Hubris::HU32 SWindowParamDirectX::ClassStyleDefaultGet()
{
	return( SWindowParam::ClassStyleDefaultGet() );
}

/**/
const Hubris::HU32 SWindowParamDirectX::WindowStyleDefaultGet()
{
	return( SWindowParam::WindowStyleDefaultGet() );
}
/**/
