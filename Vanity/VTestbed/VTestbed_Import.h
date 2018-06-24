//file: Vanity/VTestbed/VTestbed_Import.h
#ifndef _V_TESTBED_IMPORT_H_
#define _V_TESTBED_IMPORT_H_

#include< Hubris/Hubris_Export.h >
#include< Pride/Pride_Export.h >
#include< Vanity/Vanity_Export.h >
#include< stdio.h>

#define VTESTBED_VALIDATE_START( COMPONENT_NAME ) printf( "%s\n", COMPONENT_NAME )
#define VTESTBED_VALIDATE_STATUS( MESSAGE, STATUS ) if( HFALSE == STATUS ) printf( " <FAILED> %s\n", MESSAGE )

#endif // _V_TESTBED_IMPORT_H_