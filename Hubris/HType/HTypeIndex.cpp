//file: Hubris/HType/HTypeIndex.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HType/HTypeIndex.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
HSINT Hubris::HTypeIndexUniqueGet()
{
	static HSINT s_typeIndex = 0;
	const HSINT returnIndex = s_typeIndex;
	s_typeIndex += 1;
	return returnIndex;
}

/**/