//file: Pride/PTestbed/PTestbed_Import.h
#ifndef _P_TESTBED_IMPORT_E_
#define _P_TESTBED_IMPORT_E_

#include< Hubris/Hubris_Export.h >
#include< Envy/Envy_Export.h >
#include< Pride/Pride_Export.h >

#include <stdio.h>

#define PTESTBED_VALIDATE_START( COMPONENT_NAME ) printf( "  %s\n", COMPONENT_NAME )
#define PTESTBED_VALIDATE_STATUS( MESSAGE, STATUS ) if( HFALSE == STATUS ) printf( "    <FAILED> %s\n", MESSAGE )

#endif // _P_TESTBED_IMPORT_E_