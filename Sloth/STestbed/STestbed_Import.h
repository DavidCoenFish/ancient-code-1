//file: Sloth/STestbed/STestbed_Import.h
#ifndef _S_TESTBED_IMPORT_H_
#define _S_TESTBED_IMPORT_H_

#include< Hubris/Hubris_Export.h >
#include< Sloth/Sloth_Export.h >
#include< stdio.h >

#define STESTBED_VALIDATE_START( COMPONENT_NAME ) printf( "%s\n", COMPONENT_NAME )
#define STESTBED_VALIDATE_STATUS( MESSAGE, STATUS ) if( HFALSE == STATUS ) printf( " <FAILED> %s\n", MESSAGE )

#endif // _S_TESTBED_IMPORT_H_