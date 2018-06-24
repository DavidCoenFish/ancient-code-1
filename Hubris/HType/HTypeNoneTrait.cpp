//file: Hubris/HType/HTypeNoneTrait.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HType/HTypeNoneTrait.h"

#include "Hubris/HType/HTypeNone.h"

#include "Hubris/HCommon/HCommon_Export.h"
#include "Hubris/HString/HString_Export.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
HTYPE_NAME_IMPLEMENTATION( HTypeNone );

/**/
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HTypeNone );

/**/
HString Hubris::HTraitStringIn< HTypeNone >( const HTypeNone& )
{
	//HCOMMON_ASSERT_ALWAYS("why are you trying to print a None class, guess you can do this, NULL variant..." );
	return HNULL;
}

/**/
HVOID Hubris::HTraitStringOut< HTypeNone >( HTypeNone&, const HString& )
{
	//HCOMMON_ASSERT_ALWAYS("why are you trying to scan a None class, guess you can do this, NULL variant..." );
	return;
}

/**/