//file: Pride/PTestbed/PTestbedMaterial.cpp

#include "Pride/PTestbed/PTestbedMaterial.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedMaterial()
{
	HBOOL success = HTRUE;

	PTESTBED_VALIDATE_STATUS( "PMaterial", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedMaterial()
{
	PTESTBED_VALIDATE_START( "TestbedMaterial" );
	HBOOL success = HTRUE;

	success &= LocalTestbedMaterial();

	return success;
}

/**/