//file: Pride/PTestbed/PTestbedPlane.cpp

#include "Pride/PTestbed/PTestbedPlane.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedPlane()
{
	HBOOL success = HTRUE;

	PTESTBED_VALIDATE_STATUS( "PPlaneR3", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedPlane()
{
	PTESTBED_VALIDATE_START( "TestbedPlane" );
	HBOOL success = HTRUE;

	success &= LocalTestbedPlane();

	return success;
}

/**/