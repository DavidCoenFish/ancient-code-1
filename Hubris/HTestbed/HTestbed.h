//file: Hubris/HTestbed/HTestbed.h
#ifndef _H_TESTBED_H_
#define _H_TESTBED_H_

#include "Hubris/HCommon/HCommonType.h"

#include <stdio.h>

#define HTESTBED_VALIDATE_START( COMPONENT_NAME ) printf( "  %s\n", COMPONENT_NAME )
#define HTESTBED_VALIDATE_STATUS( MESSAGE, STATUS ) if( HFALSE == STATUS ) printf( "   <FAILED> %s\n", MESSAGE )

#endif // _H_TESTBED_H_