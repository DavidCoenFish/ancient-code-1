//file: Sloth/STestbed/STestbed.cpp

#include "Sloth/STestbed/STestbed.h"

#include "Sloth/STestbed/STestbedTextureAlias.h"

///////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////////
// application inpoint
/**/
HS32 main( HS32 in_argc, HU8 ** )
{
	HBOOL success = HTRUE;

	success &= TestbedTextureAlias();

	//HFileSystem fileSystem;
	//fileSystem.FolderRemove( "data" );

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