//file: Pride/PTestbed/PTestbedConvexHull.cpp

#include "Pride/PTestbed/PTestbedConvexHull.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< PConvexHull >TArrayHull;
typedef Hubris::HContainerArray< PTriangle >TArrayTriangle;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector2D;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedConvexHull()
{
	HBOOL success = HTRUE;

	//PConvexHull( const PConvexHull& in_src );
	//PConvexHull();
	//~PConvexHull();
	//const PConvexHull& operator=( const PConvexHull& in_rhs );
	//Hubris::HBOOL operator==( const PConvexHull& in_rhs )const;
	//Hubris::HBOOL operator!=( const PConvexHull& in_rhs )const;
	{
		PConvexHull hull0;
		hull0.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) ) );

		const PConvexHull hull1( hull0 );
		const PConvexHull hull2 = hull0;
		const PConvexHull hull3;

		success &= ( hull0 == hull1 );
		success &= ( hull1 == hull0 );

		success &= ( hull0 == hull2 );
		success &= ( hull2 == hull0 );

		success &= ( hull0 != hull3 );
		success &= ( hull3 != hull0 );

		success &= !( hull0 != hull2 );
		success &= !( hull2 != hull0 );

		success &= !( hull0 == hull3 );
		success &= !( hull3 == hull0 );

	}

	//HVOID PlaneAdd( const PPlaneR3& in_plane );
	//const Hubris::HSINT PlaneCountGet()const;
	//const PPlaneR3& PlaneGet( const Hubris::HSINT in_index )const;
	//HVOID PlaneSet( const Hubris::HSINT in_index, const PPlaneR3& in_plane );
	//HVOID PlaneRemove( const Hubris::HSINT in_index );
	{
		PConvexHull hull0;
		PPlaneR3 plane0( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) );
		PPlaneR3 plane1( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) );
		PPlaneR3 plane2( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) );
		PPlaneR3 plane3( 20.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisX() ) );
		PPlaneR3 plane4( 20.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisY() ) );
		PPlaneR3 plane5( 20.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisZ() ) );
		hull0.PlaneAdd( plane0 );
		hull0.PlaneAdd( plane1 );
		hull0.PlaneAdd( plane2 );
		hull0.PlaneAdd( plane3 );
		hull0.PlaneAdd( plane4 );
		hull0.PlaneAdd( plane5 );

		success &= ( 6 == hull0.PlaneCountGet() );
		success &= ( plane0 == hull0.PlaneGet( 0 ) );
		success &= ( plane1 == hull0.PlaneGet( 1 ) );
		success &= ( plane2 == hull0.PlaneGet( 2 ) );
		success &= ( plane3 == hull0.PlaneGet( 3 ) );
		success &= ( plane4 == hull0.PlaneGet( 4 ) );
		success &= ( plane5 == hull0.PlaneGet( 5 ) );

		hull0.PlaneRemove( 2 );

		success &= ( 5 == hull0.PlaneCountGet() );
		success &= ( plane0 == hull0.PlaneGet( 0 ) );
		success &= ( plane1 == hull0.PlaneGet( 1 ) );
		success &= ( plane3 == hull0.PlaneGet( 2 ) );
		success &= ( plane4 == hull0.PlaneGet( 3 ) );
		success &= ( plane5 == hull0.PlaneGet( 4 ) );

		hull0.PlaneSet( 2, plane2 );
		success &= ( plane2 == hull0.PlaneGet( 2 ) );
	}

	PTESTBED_VALIDATE_STATUS( "PConvexHull", success );

	return success;
}

/**/
static const HBOOL LocalTestbedConvexHullUtility()
{
	HBOOL success = HTRUE;

	PConvexHull hull0;
	hull0.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) ) );
	hull0.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) ) );
	hull0.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) ) );
	hull0.PlaneAdd( PPlaneR3( 20.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisX() ) ) );
	hull0.PlaneAdd( PPlaneR3( 20.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisY() ) ) );
	hull0.PlaneAdd( PPlaneR3( 20.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisZ() ) ) );

	PConvexHull hull1;
	hull1.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) ) );
	hull1.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) ) );
	hull1.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) ) );

	PConvexHull hull2;
	hull2.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) ) );
	hull2.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) ) );
	hull2.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) ) );
	hull2.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisX() ) ) );
	hull2.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisY() ) ) );
	hull2.PlaneAdd( PPlaneR3( 0.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) ) );

	PConvexHull hull3;
	hull3.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisX() ) ) );
	hull3.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisY() ) ) );
	hull3.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ) ) );
	hull3.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisX() ) ) );
	hull3.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( -HMatrixConstructor::HVectorR3AxisY() ) ) );
	hull3.PlaneAdd( PPlaneR3( 10.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct( 0.01F, 0.0F, -0.99F ) ) ) );


	//PConvexHullUtility
	//HVOID PlaneUnusedGet( PConvexHull& in_out_convexHull, TArraySint& out_arrayIndex );
	//static HVOID PlaneClean( PConvexHull& in_out_convexHull );
	//static const Hubris::HBOOL EnclosedTest( PConvexHull& in_out_convexHull );
	{
		success &= ( HTRUE == PConvexHullUtility::EnclosedTest( hull0 ) );
		success &= ( HFALSE == PConvexHullUtility::EnclosedTest( hull1 ) );
		success &= ( HFALSE == PConvexHullUtility::EnclosedTest( hull2 ) );
		success &= ( HTRUE == PConvexHullUtility::EnclosedTest( hull3 ) );
	}

	//static HVOID BoundsGet( PBoundsR3& out_bounds, PConvexHull& in_out_convexHull );

	//static const Hubris::HREAL VolumeApproxGet( PConvexHull& in_out_convexHull );
	//static const Hubris::HREAL VolumeGet( PConvexHull& in_out_convexHull );


	PTESTBED_VALIDATE_STATUS( "PConvexHullUtility", success );

	return success;
}
		
///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedConvexHull()
{
	PTESTBED_VALIDATE_START( "TestbedConvexHull" );
	HBOOL success = HTRUE;

	success &= LocalTestbedConvexHull();
	success &= LocalTestbedConvexHullUtility();

	return success;
}

/**/