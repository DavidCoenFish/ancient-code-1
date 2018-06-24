//file: Pride/PTestbed/PTestbedIntersection.cpp

#include "Pride/PTestbed/PTestbedIntersection.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedIntersectionUtility()
{
	HBOOL success = HTRUE;

	//struct PIntersectionUtility
	//	const Hubris::HBOOL PlaneLineIntersect( 
	//		Hubris::HVectorR3& out_point, 
	//		const PPlaneR3& in_plane,
	//		const PLineR3& in_line
	//		);
	{
	}

	//	const Hubris::HBOOL PlanePlaneIntersect( 
	//		PLineR3& out_line, 
	//		const PPlaneR3& in_planeOne,
	//		const PPlaneR3& in_planeTwo
	//		);
	{
		PLineR3 line0;
		const PUnitVectorR3 unitAxizZ( HMatrixConstructor::HVectorR3AxisZ() );
		PLineR3 line1( HVectorR3(), unitAxizZ );
		PPlaneR3 plane0( 0.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) );
		PPlaneR3 plane1( 0.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) );

		success &= PIntersectionUtility::PlanePlaneIntersect( line0, plane0, plane1 );
		success &= ( line0 == line1 );
	}
	{
		PLineR3 line0;
		const PUnitVectorR3 unitAxizY( -HMatrixConstructor::HVectorR3AxisY() );
		PLineR3 line1( HMatrixConstructor::HVectorR3Construct( 1.0F, 0.0F, 1.0F  ), unitAxizY );
		PPlaneR3 plane0( 1.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) );
		PPlaneR3 plane1( 1.4142135623730950488016887242097F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct( 1.0F, 0.0F, 1.0F  ) ) );

		success &= PIntersectionUtility::PlanePlaneIntersect( line0, plane0, plane1 );
		success &= HMathUtility::EpsilonEqual( line0, line1 );

		//PUnitVectorR3 test = Hubris::HMathUtility< PUnitVectorR3 >::Maximum( PUnitVectorR3(), PUnitVectorR3() );
	}


	////return true if there is a point of intersection of three planes
	//static const Hubris::HBOOL PlanePlanePlaneIntersect( 
	//	Hubris::HVectorR3& out_point, 
	//	const PPlaneR3& in_planeOne,
	//	const PPlaneR3& in_planeTwo,
	//	const PPlaneR3& in_planeThree
	//	)
	{
		PPlaneR3 plane0( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) );
		PPlaneR3 plane1( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) );
		PPlaneR3 plane2( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) );
		HVectorR3 point0;
		success &= ( HTRUE == PIntersectionUtility::PlanePlanePlaneIntersect( 
			point0, 
			plane0,
			plane1,
			plane2
			) );

		success &= ( HTRUE == HMathUtility::EpsilonEqual( point0, HMatrixConstructor::HVectorR3Construct( 10.0F, 10.0F, 10.0F ) ) );
	}

	{
		PPlaneR3 plane0( 5.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct( 1.0, 1.0F, 0.0F ) ) );
		PPlaneR3 plane1( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) );
		PPlaneR3 plane2( 0.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) );
		HVectorR3 point0;
		success &= ( HTRUE == PIntersectionUtility::PlanePlanePlaneIntersect( 
			point0, 
			plane0,
			plane1,
			plane2
			) );

		success &= ( HTRUE == HMathUtility::EpsilonEqual( point0, HMatrixConstructor::HVectorR3Construct( -2.9289322F, 10.0F, 0.0F ) ) );
	}

	////return true if any point is inside hull
	//static const Hubris::HBOOL ArrayPointInsideHull(
	//	PConvexHull& in_out_hull,
	//	const TArrayVector& in_arrayVector
	//	);

	//static const Hubris::HBOOL PointInsideHull(
	//	PConvexHull& in_out_hull,
	//	const Hubris::HVectorR3& in_vector
	//	);
	{
		PConvexHull hull0;
		PPlaneR3 plane0( -10.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisX() ) );
		PPlaneR3 plane1( -10.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisY() ) );
		PPlaneR3 plane2( -10.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisZ() ) );
		PPlaneR3 plane3( 20.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) );
		PPlaneR3 plane4( 20.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) );
		PPlaneR3 plane5( 20.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) );
		hull0.PlaneAdd( plane0 );
		hull0.PlaneAdd( plane1 );
		hull0.PlaneAdd( plane2 );
		hull0.PlaneAdd( plane3 );
		hull0.PlaneAdd( plane4 );
		hull0.PlaneAdd( plane5 );

		success &= ( HFALSE == PIntersectionUtility::PointInsideHull(
			hull0,
			HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 15.0F )
			) );

		success &= ( HFALSE == PIntersectionUtility::PointInsideHull(
			hull0,
			HMatrixConstructor::HVectorR3Construct( 10.0F, 10.0F, 10.0F ),
			-0.001F
			) );

		success &= ( HTRUE == PIntersectionUtility::PointInsideHull(
			hull0,
			HMatrixConstructor::HVectorR3Construct( 15.0F, 15.0F, 15.0F )
			) );

		success &= ( HTRUE == PIntersectionUtility::PointInsideHull(
			hull0,
			HMatrixConstructor::HVectorR3Construct( 20.0F, 20.0F, 20.0F )
			) );

		success &= ( HFALSE == PIntersectionUtility::PointInsideHull(
			hull0,
			HMatrixConstructor::HVectorR3Construct( 15.0F, 25.0F, 15.0F )
			) );
	}

	//static const Hubris::HBOOL PointInsideBounds(
	//	const PBoundsR3& in_bounds,
	//	const Hubris::HVectorR3& in_vector
	//	);
	{
		PBoundsR3 bounds0( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, 1.0F ),
			HMatrixConstructor::HVectorR3Construct( 2.0F, 0.0F, 3.0F )
			);

		success &= ( HTRUE == PBoundsUtility::PointInsideTest(
			bounds0,
			HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 2.0F )
			) );
		success &= ( HFALSE == PBoundsUtility::PointInsideTest(
			bounds0,
			HMatrixConstructor::HVectorR3Construct( 3.0F, 0.0F, 2.0F )
			) );
		success &= ( HFALSE == PBoundsUtility::PointInsideTest(
			bounds0,
			HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 2.0F )
			) );
		success &= ( HFALSE == PBoundsUtility::PointInsideTest(
			bounds0,
			HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 0.0F )
			) );
	}

	PTESTBED_VALIDATE_STATUS( "PIntersectionUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedIntersection()
{
	PTESTBED_VALIDATE_START( "TestbedIntersection" );
	HBOOL success = HTRUE;

	success &= LocalTestbedIntersectionUtility();

	return success;
}

/**/