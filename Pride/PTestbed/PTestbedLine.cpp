//file: Pride/PTestbed/PTestbedLine.cpp

#include "Pride/PTestbed/PTestbedLine.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedLine()
{
	HBOOL success = HTRUE;

	PTESTBED_VALIDATE_STATUS( "PLineR3", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedLine()
{
	PTESTBED_VALIDATE_START( "TestbedLine" );
	HBOOL success = HTRUE;

	success &= LocalTestbedLine();

	return success;
}

/**/