//file: Pride/PTestbed/PTestbedConvexHullGenerate.cpp

#include "Pride/PTestbed/PTestbedConvexHullGenerate.h"

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
static const HBOOL LocalTestbedConvexHullGenerateUtility()
{
	HBOOL success = HTRUE;

	//struct PConvexHullGenerateUtility
	//static HVOID GenerateHulls( 
	//	TArrayHull& out_arrayHull, 
	//	PMesh& in_mesh,
	//	const Hubris::HSINT in_maxHullCount = Hubris::HVariablesMathSINT::s_max,
	//	const Hubris::HREAL in_depth = Hubris::HVariablesMath::UnitGet< HREAL >(),
	//	const Hubris::HREAL in_widthPad = Hubris::HVariablesMathREAL::s_zero,
	//	PInterfaceProgress* const in_pProgress = HNULL
	//	);
	{
		TArrayHull arrayHull0;
		PMesh mesh0;
		TArrayVector arrayVertex0;
		TArraySint arrayTriangleVertexIndex0;
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F,  1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F,  1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  1.0F,  1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F, -1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F, -1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F, -1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  1.0F, -1.0F ) );

		arrayTriangleVertexIndex0.Insert( 0 ); arrayTriangleVertexIndex0.Insert( 1 ); arrayTriangleVertexIndex0.Insert( 2 );
		arrayTriangleVertexIndex0.Insert( 0 ); arrayTriangleVertexIndex0.Insert( 2 ); arrayTriangleVertexIndex0.Insert( 3 );

		arrayTriangleVertexIndex0.Insert( 0 ); arrayTriangleVertexIndex0.Insert( 4 ); arrayTriangleVertexIndex0.Insert( 5 );
		arrayTriangleVertexIndex0.Insert( 0 ); arrayTriangleVertexIndex0.Insert( 5 ); arrayTriangleVertexIndex0.Insert( 1 );

		arrayTriangleVertexIndex0.Insert( 1 ); arrayTriangleVertexIndex0.Insert( 5 ); arrayTriangleVertexIndex0.Insert( 6 );
		arrayTriangleVertexIndex0.Insert( 1 ); arrayTriangleVertexIndex0.Insert( 6 ); arrayTriangleVertexIndex0.Insert( 2 );

		arrayTriangleVertexIndex0.Insert( 2 ); arrayTriangleVertexIndex0.Insert( 6 ); arrayTriangleVertexIndex0.Insert( 7 );
		arrayTriangleVertexIndex0.Insert( 2 ); arrayTriangleVertexIndex0.Insert( 7 ); arrayTriangleVertexIndex0.Insert( 3 );

		arrayTriangleVertexIndex0.Insert( 3 ); arrayTriangleVertexIndex0.Insert( 7 ); arrayTriangleVertexIndex0.Insert( 4 );
		arrayTriangleVertexIndex0.Insert( 3 ); arrayTriangleVertexIndex0.Insert( 4 ); arrayTriangleVertexIndex0.Insert( 0 );

		arrayTriangleVertexIndex0.Insert( 4 ); arrayTriangleVertexIndex0.Insert( 7 ); arrayTriangleVertexIndex0.Insert( 6 );
		arrayTriangleVertexIndex0.Insert( 4 ); arrayTriangleVertexIndex0.Insert( 6 ); arrayTriangleVertexIndex0.Insert( 5 );

		mesh0.DataSet( arrayVertex0, arrayTriangleVertexIndex0 );

		PConvexHullGenerateUtility::GenerateHulls(
			arrayHull0,
			mesh0
			);

		success &= ( 1 == arrayHull0.SizeGet() );
		if( HTRUE == success )
		{
			PConvexHull& hull0 = arrayHull0[ 0 ];
			success &= ( 6 == hull0.PlaneCountGet() );
			success &= ( HTRUE == PConvexHullUtility::EnclosedTest( hull0 ) );
		}

	}
	TArrayHull arrayHull9;
	{
		PMesh mesh0;
		TArrayVector arrayVertex0;
		TArraySint arrayTriangleVertexIndex0;
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F,  0.0F,  0.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F, -1.0F,  0.0F ) );

		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  0.0F,  1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F,  1.0F ) );

		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  2.0F,  0.0F,  0.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  2.0F, -1.0F,  0.0F ) );

		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  3.0F,  0.0F,  1.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  3.0F, -1.0F,  1.0F ) );

		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  3.5F,  0.0F,  0.5F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  3.5F, -1.0F,  0.5F ) );

		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  4.0F,  0.0F,  0.0F ) );
		arrayVertex0.Insert( HMatrixConstructor::HVectorR3Construct(  4.0F, -1.0F,  0.0F ) );

		arrayTriangleVertexIndex0.Insert( 0 ); arrayTriangleVertexIndex0.Insert( 2 ); arrayTriangleVertexIndex0.Insert( 3 );
		arrayTriangleVertexIndex0.Insert( 0 ); arrayTriangleVertexIndex0.Insert( 3 ); arrayTriangleVertexIndex0.Insert( 1 );

		arrayTriangleVertexIndex0.Insert( 2 ); arrayTriangleVertexIndex0.Insert( 4 ); arrayTriangleVertexIndex0.Insert( 5 );
		arrayTriangleVertexIndex0.Insert( 2 ); arrayTriangleVertexIndex0.Insert( 5 ); arrayTriangleVertexIndex0.Insert( 3 );

		arrayTriangleVertexIndex0.Insert( 4 ); arrayTriangleVertexIndex0.Insert( 6 ); arrayTriangleVertexIndex0.Insert( 7 );
		arrayTriangleVertexIndex0.Insert( 4 ); arrayTriangleVertexIndex0.Insert( 7 ); arrayTriangleVertexIndex0.Insert( 5 );

		arrayTriangleVertexIndex0.Insert( 6 ); arrayTriangleVertexIndex0.Insert( 8 ); arrayTriangleVertexIndex0.Insert( 9 );
		arrayTriangleVertexIndex0.Insert( 6 ); arrayTriangleVertexIndex0.Insert( 9 ); arrayTriangleVertexIndex0.Insert( 7 );

		arrayTriangleVertexIndex0.Insert( 8 ); arrayTriangleVertexIndex0.Insert( 10 ); arrayTriangleVertexIndex0.Insert( 11 );
		arrayTriangleVertexIndex0.Insert( 8 ); arrayTriangleVertexIndex0.Insert( 11 ); arrayTriangleVertexIndex0.Insert( 9 );

		mesh0.DataSet( arrayVertex0, arrayTriangleVertexIndex0 );

		PConvexHullGenerateUtility::GenerateHulls(
			arrayHull9,
			mesh0
			);

		success &= ( 2 == arrayHull9.SizeGet() );
		if( HTRUE == success )
		{
			success &= ( 5 == arrayHull9[ 0 ].PlaneCountGet() );
			success &= ( HTRUE == PConvexHullUtility::EnclosedTest( arrayHull9[ 0 ] ) );
			success &= ( 5 == arrayHull9[ 1 ].PlaneCountGet() );
			success &= ( HTRUE == PConvexHullUtility::EnclosedTest( arrayHull9[ 1 ] ) );
		}
	}

	//static const Hubris::HBOOL CreateHullFromPointCloud( 
	//	PConvexHull& out_convexHull,
	//	const TArrayVector& in_pointCloud,
	//	PInterfaceProgress* const in_pProgress = HNULL
	//	);
	{
		PConvexHull hull0;
		TArrayVector pointCloud0;
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F, -1.0F, -1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F,  1.0F, -1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  0.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  0.0F,  1.0F ) );
		success &= PConvexHullGenerateUtility::CreateHullFromPointCloud(
			hull0,
			pointCloud0
			);

		success &= ( HTRUE == PConvexHullUtility::EnclosedTest( hull0 ) );
		success &= ( 4 == hull0.PlaneCountGet() );

		//internal and on surface extra points
		PConvexHull hull1;
		TArrayVector pointCloud1( pointCloud0 );
		pointCloud1.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F, 0.0F, 0.0F ) );
		pointCloud1.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F, 0.0F, -1.0F ) );
		success &= PConvexHullGenerateUtility::CreateHullFromPointCloud(
			hull1,
			pointCloud1
			);

		//order is not ensured
		//success &= ( hull1 == hull0 );
		success &= ( HTRUE == PConvexHullUtility::EnclosedTest( hull1 ) );
		success &= ( 4 == hull1.PlaneCountGet() );
	}
	{
		PConvexHull hull0;
		TArrayVector pointCloud0;
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F, -1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F, -1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  1.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  1.0F, -1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F, -1.0F ) );

		//extra points
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F,  0.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F,  1.0F,  0.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  0.0F,  0.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F,  0.0F, -1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F, -1.0F,  0.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  0.0F,  0.0F ) );

		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F,  1.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  0.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  0.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  0.0F,  1.0F, -1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F,  0.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  0.0F,  1.0F ) );

		success &= PConvexHullGenerateUtility::CreateHullFromPointCloud(
			hull0,
			pointCloud0
			);
		success &= ( HTRUE == PConvexHullUtility::EnclosedTest( hull0 ) );
		success &= ( 6 == hull0.PlaneCountGet() );
	}
	//static const Hubris::HBOOL CreateProfileFromPointCloud2D( 
	//	TArraySint& out_arrayIndex,
	//	const TArrayVector2D& in_pointCloud,
	//	PInterfaceProgress* const in_pProgress = HNULL
	//	);
	{
		TArrayVector2D pointCloud0;
		pointCloud0.Insert( HMatrixConstructor::HVectorR2Construct(  0.0F,  0.0F ) );//0
		pointCloud0.Insert( HMatrixConstructor::HVectorR2Construct( -1.0F,  1.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR2Construct( -2.0F,  2.0F ) );//2
		pointCloud0.Insert( HMatrixConstructor::HVectorR2Construct(  0.0F,  2.0F ) );
		pointCloud0.Insert( HMatrixConstructor::HVectorR2Construct(  2.0F,  3.0F ) );//4
		pointCloud0.Insert( HMatrixConstructor::HVectorR2Construct(  2.0F,  0.0F ) );//5
		pointCloud0.Insert( HMatrixConstructor::HVectorR2Construct(  1.0F,  1.0F ) );

		TArraySint arrayIndex0;
		success &= PConvexHullGenerateUtility::CreateProfileFromPointCloud2D(
			arrayIndex0,
			pointCloud0
			);

		success &= ( 4 == arrayIndex0.SizeGet() );
	}

	//given a array of hulls, reduce the hull count to maxHulls
	//static HVOID ReduceHullCount( 
	//	TArrayHull& in_out_arrayHull, 
	//	const Hubris::HSINT in_maxHullCount = Hubris::HVariablesMathSINT::s_max,
	//	PInterfaceProgress* const in_pProgress = HNULL
	//	);
	{
		PConvexHullGenerateUtility::ReduceHullCount( 
			arrayHull9,
			1
			);
		success &= ( 1 == arrayHull9.SizeGet() );
	}

	//static HVOID ReducePlaneCount(
	//	PConvexHull& in_out_hull,
	//	const Hubris::HSINT in_maxPlaneCount = Hubris::HVariablesMathSINT::s_max,
	//	PInterfaceProgress* const in_pProgress = HNULL
	//	);
	if( HTRUE == success )
	{
		PConvexHullGenerateUtility::ReducePlaneCount( 
			arrayHull9[ 0 ],
			5
			);
		success &= ( 5 == arrayHull9[ 0 ].PlaneCountGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PConvexHullGenerateUtility", success );

	return success;
}

/**
static const HBOOL LocalTestbedConvexHullGeneratePointCloudUtility()
{
	HBOOL success = HTRUE;

	//struct PConvexHullGeneratePointCloudUtility
	//static const Hubris::HBOOL SeedPointsSelect( 
	//	Hubris::HSINT& out_indexOne,
	//	Hubris::HSINT& out_indexTwo,
	//	Hubris::HSINT& out_indexThree,
	//	const TArrayVector& in_pointCloud
	//	);
	//static const Hubris::HBOOL LookForPointOutsidePlane( 
	//	Hubris::HSINT& out_outsidePointIndex,
	//	const Hubris::HSINT in_indexOne,
	//	const Hubris::HSINT in_indexTwo,
	//	const Hubris::HSINT in_indexThree,
	//	const TArrayVector& in_pointCloud
	//	);
	//static const Hubris::HBOOL GrowPlane( 
	//	Hubris::HSINT& out_indexOne,
	//	Hubris::HSINT& out_indexTwo,
	//	Hubris::HSINT& out_indexThree,
	//	const Hubris::HSINT in_indexOne,
	//	const Hubris::HSINT in_indexTwo,
	//	const Hubris::HSINT in_indexThree,
	//	const Hubris::HSINT in_newPoint,
	//	const TArrayVector& in_pointCloud
	//	);
	//static const Hubris::HBOOL FindNextCandidate( 
	//	Hubris::HSINT& out_newCandiadte,
	//	const Hubris::HSINT in_indexOne,
	//	const Hubris::HSINT in_indexTwo,
	//	const TArrayVector& in_pointCloud, 
	//	const PPlaneR3& in_plane 
	//	);
	//static const HVOID ProjectOntoPlane( 
	//	TArrayVector2D& out_arrayPoints2D,
	//	const TArrayVector& in_pointCloud, 
	//	const PPlaneR3& in_plane 
	//	);
	//static const Hubris::HBOOL GenerateProfile2D( 
	//	TArraySint& out_arrayIndexEdgeLoop,
	//	const TArrayVector2D& in_pointCloud
	//	);
	{
		TArrayVector2D pointCloud;
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( -1.0F, -1.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( -1.5F, -0.5F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( -0.5F, 0.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, 1.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, 1.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, -1.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, -0.5F ) );

		TArraySint edgeLoopIndex;
		PConvexHullGeneratePointCloudUtility::GenerateProfile2D( 
			edgeLoopIndex,
			pointCloud
			);

		success &= ( 5 == edgeLoopIndex.SizeGet() );
	}
	{
		TArrayVector2D pointCloud;
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, -1.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, -1.5F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 0.5F, -0.5F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( -0.5F, -0.5F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( -0.5F, 0.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, 0.5F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, 1.5F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, 0.0F ) );
		pointCloud.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F ) );

		TArraySint edgeLoopIndex;
		PConvexHullGeneratePointCloudUtility::GenerateProfile2D( 
			edgeLoopIndex,
			pointCloud
			);

		success &= ( 5 == edgeLoopIndex.SizeGet() );
	}

	//static const Hubris::HBOOL SeedPointsSelect2D( 
	//	Hubris::HSINT& out_indexOne,
	//	Hubris::HSINT& out_indexTwo,
	//	const TArrayVector2D& in_pointCloud
	//	);
	//static const Hubris::HBOOL FindNextCandidate2D( 
	//	Hubris::HSINT& out_newCandiadte,
	//	const Hubris::HSINT in_indexOne,
	//	const Hubris::HSINT in_indexTwo,
	//	const TArrayVector2D& in_pointCloud
	//	);


	PTESTBED_VALIDATE_STATUS( "PConvexHullGeneratePointCloudUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedConvexHullGenerate()
{
	PTESTBED_VALIDATE_START( "TestbedConvexHullGenerate" );
	HBOOL success = HTRUE;

	success &= LocalTestbedConvexHullGenerateUtility();
	//success &= LocalTestbedConvexHullGeneratePointCloudUtility();


	return success;
}

/**/