//file: Lust/LTestbed/LTestbed.cpp

#include "Lust/LTestbed/LTestbed.h"

#include "Lust/LTestbed/LTestbedSpring.h"

using namespace Hubris;

/**/
HS32 main( HS32 in_argc, HU8 ** )
{
	HBOOL success = HTRUE;

	success &= TestbedSpring();

	//assume default invoke has one param, gets 'wait for key'
	if( 1 == in_argc )
	{
		printf( "\n<press enter key to exit>" ); 
		HU8 c; 
		H_SCAN( "%c", &c ); 
	}

	//return 0 on no error, ie, not success
	return( !success );
}

/**/