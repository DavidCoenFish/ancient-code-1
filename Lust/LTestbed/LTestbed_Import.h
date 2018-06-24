//file: Lust/LTestbed/LTestbed_Import.h
#ifndef _L_TESTBED_IMPORT_H_
#define _L_TESTBED_IMPORT_H_

#include< Hubris/Hubris_Export.h >
#include< Pride/Pride_Export.h >
#include< Lust/Lust_Export.h >
#include< stdio.h>

#define LTESTBED_VALIDATE_START( COMPONENT_NAME ) printf( "%s\n", COMPONENT_NAME )
#define LTESTBED_VALIDATE_STATUS( MESSAGE, STATUS ) if( HFALSE == STATUS ) printf( " <FAILED> %s\n", MESSAGE )

#endif // _L_TESTBED_IMPORT_H_