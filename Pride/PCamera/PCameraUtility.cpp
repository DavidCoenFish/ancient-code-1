//file: Pride/PCamera/PCameraUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PCamera/PCameraUtility.h"

#include "Pride/PCamera/PCamera.h"

#include "Pride/PConvexHull/PConvexHull_Export.h"
#include "Pride/PPlane/PPlane_Export.h"
#include "Pride/PSphere/PSphere_Export.h"
#include "Pride/PTriangle/PTriangle_Export.h"
#include "Pride/PUnitVector/PUnitVector_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// static local functions
/**/
static const HVOID LocalGenerateConvexHullOrthogonal(
	PConvexHull& out_convexHull,
	const PCamera& in_camera
	)
{
	out_convexHull.Clear();
	out_convexHull.PlaneAdd( PPlaneR3(
		-( in_camera.NearGet() ),
		PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		( in_camera.FarGet() ),
		PUnitVectorR3( -( HMatrixConstructor::HVectorR3AxisZ() ) )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		-( in_camera.LeftGet() ),
		PUnitVectorR3( -( HMatrixConstructor::HVectorR3AxisX() ) )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		( in_camera.RightGet() ),
		PUnitVectorR3( ( HMatrixConstructor::HVectorR3AxisX() ) )
		) );

	out_convexHull.PlaneAdd( PPlaneR3(
		-( in_camera.TopGet() ),
		PUnitVectorR3( ( HMatrixConstructor::HVectorR3AxisY() ) )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		( in_camera.BottomGet() ),
		PUnitVectorR3( -( HMatrixConstructor::HVectorR3AxisY() ) )
		) );

	return;
}

/**/
static const HVOID LocalGenerateConvexHullPerspective(
	PConvexHull& out_convexHull,
	const PCamera& in_camera
	)
{
	out_convexHull.Clear();
	out_convexHull.PlaneAdd( PPlaneR3(
		-in_camera.NearGet(),
		PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		in_camera.FarGet(),
		PUnitVectorR3( -( HMatrixConstructor::HVectorR3AxisZ() ) )
		) );

	PUnitVectorR3 normal;
	PTriangleUtility::TriangleNormalGet( normal, PTriangle( 
		HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 0.0F ),
		HMatrixConstructor::HVectorR3Construct( in_camera.RightGet(), in_camera.BottomGet(), -( in_camera.NearGet() ) ),
		HMatrixConstructor::HVectorR3Construct( in_camera.RightGet(), in_camera.TopGet(), -( in_camera.NearGet() ) )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		0.0F,
		normal
		) );

	PTriangleUtility::TriangleNormalGet( normal, PTriangle( 
		HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 0.0F ),
		HMatrixConstructor::HVectorR3Construct( in_camera.RightGet(), in_camera.TopGet(), -( in_camera.NearGet() ) ),
		HMatrixConstructor::HVectorR3Construct( in_camera.LeftGet(), in_camera.TopGet(), -( in_camera.NearGet() ) )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		0.0F,
		normal
		) );

	PTriangleUtility::TriangleNormalGet( normal, PTriangle( 
		HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 0.0F ),
		HMatrixConstructor::HVectorR3Construct( in_camera.LeftGet(), in_camera.TopGet(), -( in_camera.NearGet() ) ),
		HMatrixConstructor::HVectorR3Construct( in_camera.LeftGet(), in_camera.BottomGet(), -( in_camera.NearGet() ) )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		0.0F,
		normal
		) );

	PTriangleUtility::TriangleNormalGet( normal, PTriangle( 
		HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 0.0F ),
		HMatrixConstructor::HVectorR3Construct( in_camera.LeftGet(), in_camera.BottomGet(), -( in_camera.NearGet() ) ),
		HMatrixConstructor::HVectorR3Construct( in_camera.RightGet(), in_camera.BottomGet(), -( in_camera.NearGet() ) )
		) );
	out_convexHull.PlaneAdd( PPlaneR3(
		0.0F,
		normal
		) );

	return;
}

/**/
static HVOID LocalSphereVarOrthogonal(
	HREAL& out_varA,
	HREAL& out_varB,
	const PCamera& in_camera
	)
{
	const HREAL top = in_camera.TopGet();
	const HREAL bottom = in_camera.BottomGet();
	const HREAL left = in_camera.LeftGet();
	const HREAL right = in_camera.RightGet();

	HREAL test = ( top * top ) + ( left * left );
	out_varA = HMathUtility::Maximum( out_varA, test );

	test = ( left * left ) + ( bottom * bottom );
	out_varA = HMathUtility::Maximum( out_varA, test );

	test = ( bottom * bottom ) + ( right * right );
	out_varA = HMathUtility::Maximum( out_varA, test );

	test = ( right * right ) + ( top * top );
	out_varA = HMathUtility::Maximum( out_varA, test );
	out_varB = out_varA;

	return;
}

/**/
static HVOID LocalSphereVarPerspective(
	HREAL& out_varA,
	HREAL& out_varB,
	const PCamera& in_camera
	)
{
	LocalSphereVarOrthogonal(
		out_varA,
		out_varB,
		in_camera
		);

	const HREAL near = in_camera.NearGet();
	if( HTRUE == HMathUtility::EpsilonZeroNot( near ) )
	{
		out_varB = ( out_varA / near ) * in_camera.FarGet();
	}

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
const PConvexHull PCameraUtility::FustrumFromCamera(
	const PCamera& in_camera
	)
{
	PConvexHull convexHull;
	const HSINT type = in_camera.TypeGet();
	if( PCamera::TypeOrthogonalGet() == type )
	{
		LocalGenerateConvexHullOrthogonal(
			convexHull,
			in_camera
			);
	}
	else if( PCamera::TypePerspectiveGet() == type )
	{
		LocalGenerateConvexHullPerspective(
			convexHull,
			in_camera
			);
	}

	PConvexHullUtility::TranslateHull(
		convexHull,
		in_camera.TransformGet()
		);

	return convexHull;
}

/*
find distance to zaxis on near and far place of left/ right/ top/ bottom
then find point on z axis that is same distance between these points, and that is the sphere that fits around the fustrum
a^2 + d^2 = b^2 + e^2
c = d + e 
c is the distance btween near and far
a is distance to z axis on near plane
b is distance to z axis on far plane

e = ( a^2 - b^2 + c^2 ) / ( 2c )
*/
const PSphereR3 PCameraUtility::SphereFromCamera(
	const PCamera& in_camera
	)
{
	PSphereR3 sphere;
	HREAL varA = 0.0F;
	HREAL varB = 0.0F;
	const HREAL varC = in_camera.FarGet() - in_camera.NearGet();
	if( HTRUE == HMathUtility::EpsilonZero( varC ) )
	{
		return sphere;
	}

	const HSINT type = in_camera.TypeGet();
	if( PCamera::TypeOrthogonalGet() == type )
	{
		LocalSphereVarOrthogonal(
			varA,
			varB,
			in_camera
			);
	}
	else if( PCamera::TypePerspectiveGet() == type )
	{
		LocalSphereVarPerspective(
			varA,
			varB,
			in_camera
			);
	}


	const HREAL varE = ( ( varA * varA ) - ( varB * varB ) + ( varC * varC ) ) / ( varC + varC );
	sphere.RadiusSet( HMath::SquareRoot( ( varB * varB ) + ( varE * varE ) ) );
	const HVectorR3 center = HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, varE - ( in_camera.FarGet() ) );
	sphere.CenterSet( HMatrixUtility::VectorProduct( in_camera.TransformGet(), center ) );

	return sphere;
}

/**/
const Hubris::HVectorR3 PCameraUtility::AtFromCamera(
	const PCamera& in_camera
	)
{
	const Hubris::HVectorR3 direction = HMatrixUtility::VectorProductNoTranslate( in_camera.TransformGet(), -( HMatrixConstructor::HVectorR3AxisZ() ) );
	return direction;
}

/**/
const Hubris::HVectorR3 PCameraUtility::UpFromCamera(
	const PCamera& in_camera
	)
{
	const Hubris::HVectorR3 direction = HMatrixUtility::VectorProductNoTranslate( in_camera.TransformGet(), ( HMatrixConstructor::HVectorR3AxisY() ) );
	return direction;
}

const Hubris::HVectorR3 PCameraUtility::RightFromCamera(
	const PCamera& in_camera
	)
{
	const Hubris::HVectorR3 direction = HMatrixUtility::VectorProductNoTranslate( in_camera.TransformGet(), ( HMatrixConstructor::HVectorR3AxisX() ) );
	return direction;
}

/**/