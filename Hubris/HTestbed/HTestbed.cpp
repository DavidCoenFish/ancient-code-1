//file: Hubris/HTestbed/HTestbed.cpp

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HTestbed/HTestbedBuffer.h"
#include "Hubris/HTestbed/HTestbedBufferParse.h"
#include "Hubris/HTestbed/HTestbedCommon.h"
#include "Hubris/HTestbed/HTestbedContainer.h"
#include "Hubris/HTestbed/HTestbedFileSystem.h"
#include "Hubris/HTestbed/HTestbedFunctor.h"
#include "Hubris/HTestbed/HTestbedMath.h"
#include "Hubris/HTestbed/HTestbedMatrix.h"
#include "Hubris/HTestbed/HTestbedQuaternion.h"
#include "Hubris/HTestbed/HTestbedSmartPointer.h"
#include "Hubris/HTestbed/HTestbedString.h"
#include "Hubris/HTestbed/HTestbedTrait.h"
#include "Hubris/HTestbed/HTestbedType.h"
#include "Hubris/HTestbed/HTestbedVariant.h"

#include "Hubris/Hubris_Export.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// application inpoint
/**/
HS32 main( HS32 in_argc, HU8 ** )
{
	HBOOL success = HTRUE;

	//typedef Hubris::HContainerTree< HSINT, HSINT >TTreeSintSint;
	//TTreeSintSint tree;
	//tree.Insert( 0, 0 );

	success &= TestbedBuffer();
	success &= TestbedBufferParse();
	success &= TestbedCommon();
	success &= TestbedContainer();
	success &= TestbedFileSystem();
	success &= TestbedFunctor();
	success &= TestbedMath();
	success &= TestbedMatrix();
	success &= TestbedQuaternion();
	success &= TestbedSmartPointer();
	success &= TestbedString();
	success &= TestbedTrait();
	success &= TestbedType();
	success &= TestbedVariant();

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