//file: Envy/ETestbed/ETestbed.cpp

#include "Envy/ETestbed/ETestbed.h"

#include "Envy/ETestbed/ETestbedCommandLine.h"
#include "Envy/ETestbed/ETestbedDataStore.h"
#include "Envy/ETestbed/ETestbedJana.h"
#include "Envy/ETestbed/ETestbedMemento.h"
#include "Envy/ETestbed/ETestbedRecursiveDataStore.h"
#include "Envy/ETestbed/ETestbedStateMachine.h"
#include "Envy/ETestbed/ETestbedTanya.h"

using namespace Hubris;
using namespace Envy;

/**/
HS32 main( HS32 in_argc, HU8 ** )
{
	HBOOL success = HTRUE;

	success &= TestbedCommandLine();
	success &= TestbedDataStore();
	success &= TestbedJana();
	success &= TestbedMemento();
	success &= TestbedRecursiveDataStore();
	success &= TestbedStateMachine();
	success &= TestbedTanya();

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