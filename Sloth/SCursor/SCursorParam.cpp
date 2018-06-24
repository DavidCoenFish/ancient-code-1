//file: Sloth/SCursor/SCursorParam.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SCursor/SCursorParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SCursorParam::SCursorParam(
	const Pride::PImageRgba& in_image,
	const Hubris::HVectorS2& in_hotspot
	)
	: m_image( in_image )
	, m_hotspot( in_hotspot )

{
	return;
}

/**/
SCursorParam::~SCursorParam()
{
	return;
}

/**/
