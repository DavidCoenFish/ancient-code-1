//file: Pride/PTestbed/PTestbed.cpp

#include "Pride/PTestbed/PTestbed.h"

#include "Pride/PTestbed/PTestbedAnimation.h"
#include "Pride/PTestbed/PTestbedBounds.h"
#include "Pride/PTestbed/PTestbedColour.h"
#include "Pride/PTestbed/PTestbedConvexHull.h"
#include "Pride/PTestbed/PTestbedConvexHullGenerate.h"
#include "Pride/PTestbed/PTestbedGeometry.h"
#include "Pride/PTestbed/PTestbedImage.h"
#include "Pride/PTestbed/PTestbedIntersection.h"
#include "Pride/PTestbed/PTestbedLine.h"
#include "Pride/PTestbed/PTestbedMaterial.h"
#include "Pride/PTestbed/PTestbedMesh.h"
#include "Pride/PTestbed/PTestbedPlane.h"
#include "Pride/PTestbed/PTestbedSphere.h"
#include "Pride/PTestbed/PTestbedUnitVector.h"

using namespace Hubris;

/**/
HS32 main( HS32 in_argc, HU8 ** )
{
	HBOOL success = HTRUE;

	success &= TestbedAnimation();
	success &= TestbedBounds();
	success &= TestbedColour();
	success &= TestbedConvexHull();
	success &= TestbedConvexHullGenerate();
	success &= TestbedGeometry();
	success &= TestbedImage();
	success &= TestbedIntersection();
	success &= TestbedLine();
	success &= TestbedMaterial();
	success &= TestbedMesh();
	success &= TestbedPlane();
	success &= TestbedSphere();
	success &= TestbedUnitVector();

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