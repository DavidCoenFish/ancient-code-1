//file: Pride/PConvexHull/PConvexHullUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHull/PConvexHullUtility.h"

#include "Pride/PConvexHull/PConvexHull.h"
#include "Pride/PConvexHull/PConvexHullEdge.h"
#include "Pride/PConvexHull/PConvexHullImplementation.h"

#include "Pride/PBounds/PBounds_Export.h"
#include "Pride/PTriangle/PTriangle_Export.h"
#include "Pride/PMesh/PMesh_Export.h"
#include "Pride/PPlane/PPlane_Export.h"
#include "Pride/PPointCloud/PPointCloud_Export.h"
#include "Pride/PSphere/PSphere_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< HBOOL >TArrayBool;
typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
typedef Hubris::HContainerPair< HSINT, HSINT >TPairSint;
typedef Hubris::HContainerTree< TPairSint, HSINT >TTreePairSint;

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalAddVector( 
	TArrayReal& out_arrayReal,
	const Hubris::HVectorR3& in_vector
	)
{
	HContainerUtility::PushBack( out_arrayReal, in_vector[ 0 ] );
	HContainerUtility::PushBack( out_arrayReal, in_vector[ 1 ] );
	HContainerUtility::PushBack( out_arrayReal, in_vector[ 2 ] );

	return;
}

///////////////////////////////////////////////////////
// public static methods
/**/
HVOID PConvexHullUtility::HullClean( PConvexHull& in_out_convexHull )
{
	PConvexHull newHull;
	HSINT planeCount = in_out_convexHull.PlaneCountGet();
	for( HSINT index = 0; index < planeCount; ++index )
	{
		if( HFALSE == in_out_convexHull.ImplementationGet().RefreashEdgeGet().PlaneUseQuery( index ) )
		{
			continue;
		}

		newHull.PlaneAdd( in_out_convexHull.PlaneGet( index ) );
	}

	in_out_convexHull = newHull;

	return;
}

/**/
const Hubris::HBOOL PConvexHullUtility::EnclosedTest( PConvexHull& in_out_convexHull )
{
	return in_out_convexHull.ImplementationGet().RefreashEdgeGet().EnclosedGet();
}

/**/
const PBoundsR3 PConvexHullUtility::BoundsGet( PConvexHull& in_out_convexHull )
{
	PBoundsR3 bounds;

	//HCOMMON_ASSERT( HTRUE == EnclosedTest( in_out_convexHull ), "hull must be closed for get bounds, call EnclosedTest() on hull first" );

	const TArrayVector& pointCloud = in_out_convexHull.PointCloudGet();

	HCOMMON_FOR_EACH_CONST( point, pointCloud, TArrayVector )
	{
		bounds.InsertPoint( point );
	}

	return bounds;
}

/**/
HVOID PConvexHullUtility::ConvertToMesh(
	PMesh& out_mesh,
	Hubris::HBOOL& out_open,
	Hubris::HBOOL& out_messy, //triangle normals not matching plane, or open edges
	TArrayTriangleData& out_triangleData,
	TArraySint& out_arrayUnusedPlaneIndex,
	PConvexHull& in_out_convexHull,
	const Hubris::HREAL in_pointMergeThreasholdPercentage
	)
{
	out_mesh = PMesh();
	out_open = HFALSE;
	out_messy = HFALSE;
	out_triangleData.Clear();
	out_arrayUnusedPlaneIndex.Clear();

	const HVectorR3 threashold = PPointCloudR3::ThreasholdCreate( BoundsGet( in_out_convexHull ), in_pointMergeThreasholdPercentage );
	TArraySint arrayTriangleVertexIndex;
	TArrayBool arrayTriangleEdgeVisiblity;
	PPointCloudR3 pointCloud;

	const HSINT planeCount = in_out_convexHull.PlaneCountGet();
	for( HSINT planeIndex = 0; planeIndex < planeCount; ++planeIndex )
	{
		const PPlaneR3& plane = in_out_convexHull.PlaneGet( planeIndex );
		//get the vertex edge loop
		TArrayVector arrayEdgeLoopVertex;
		HBOOL closed = HTRUE;

		in_out_convexHull.ImplementationGet().PlaneLoopGather(
			arrayEdgeLoopVertex,
			closed,
			planeIndex
			);
		out_open |= ( HFALSE == closed );

		TArraySint arrayEdgeVertexIndex;
		HCOMMON_FOR_EACH_CONST( point, arrayEdgeLoopVertex, TArrayVector )
		{
			const HSINT edgeLoopVertexIndex = pointCloud.PointMerge( point, threashold );
			HContainerUtility::UniqueAdd( arrayEdgeVertexIndex, edgeLoopVertexIndex );
		}

		TTreePairSint treeEdges;

		const TArrayVector& arrayPointCloudVertex = pointCloud.ArrayPointsGet();
		TArrayVector arrayCleanEdgeLoopVertex;
		HCOMMON_FOR_EACH_CONST( index, arrayEdgeVertexIndex, TArraySint )
		{
			HContainerUtility::PushBack( arrayCleanEdgeLoopVertex, arrayPointCloudVertex[ index ] );
		}

		TArraySint arrayTriangleVertexIndexTriplets;
		PTriangleUtility::CapEdgeLoop( 
			arrayTriangleVertexIndexTriplets, //size%3
			arrayCleanEdgeLoopVertex
			);

		HSINT planeTriangleCount = 0;
		for( HSINT triangleIndex = 0; triangleIndex < arrayTriangleVertexIndexTriplets.SizeGet(); triangleIndex += 3 )
		{
			HContainerUtility::PushBack( arrayTriangleVertexIndex, arrayEdgeVertexIndex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 0 ] ] );
			HContainerUtility::PushBack( arrayTriangleVertexIndex, arrayEdgeVertexIndex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 1 ] ] );
			HContainerUtility::PushBack( arrayTriangleVertexIndex, arrayEdgeVertexIndex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 2 ] ] );

			const HSINT edgeLoopSize = arrayCleanEdgeLoopVertex.SizeGet();
			const HBOOL edgeVertexOneTwo = ( ( arrayTriangleVertexIndexTriplets[ triangleIndex + 0 ] + 1 ) % edgeLoopSize == arrayTriangleVertexIndexTriplets[ triangleIndex + 1 ] );
			const HBOOL edgeVertexTwoThree = ( ( arrayTriangleVertexIndexTriplets[ triangleIndex + 1 ] + 1 ) % edgeLoopSize == arrayTriangleVertexIndexTriplets[ triangleIndex + 2 ] );
			const HBOOL edgeVertexThreeOne = ( ( arrayTriangleVertexIndexTriplets[ triangleIndex + 2 ] + 1 ) % edgeLoopSize == arrayTriangleVertexIndexTriplets[ triangleIndex + 0 ] );
			HContainerUtility::PushBack( arrayTriangleEdgeVisiblity, edgeVertexOneTwo );
			HContainerUtility::PushBack( arrayTriangleEdgeVisiblity, edgeVertexTwoThree );
			HContainerUtility::PushBack( arrayTriangleEdgeVisiblity, edgeVertexThreeOne );

			TTriangleData triangleData;
			triangleData.m_planeIndex = planeIndex;

			triangleData.m_messy = HTRUE;
			PUnitVectorR3 triangleNormal;
			if( HTRUE == PTriangleUtility::TriangleNormalGet( 
				triangleNormal, 
				PTriangle( 
					arrayCleanEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 0 ] ],
					arrayCleanEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 1 ] ],
					arrayCleanEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 2 ] ]
				) ) )
			{
				const HREAL dot = 1.0F - HMatrixUtility::DotProduct( -( triangleNormal.VectorGet() ), plane.DirectionGet().VectorGet() );
				triangleData.m_messy = ( ( 0.01F < HMathUtility::Absolute( dot ) ) || 
					( closed == HFALSE ) );
			};

			HContainerUtility::PushBack( out_triangleData, triangleData );

			planeTriangleCount += 1;
		}

		if( 0 == planeTriangleCount )
		{
			out_arrayUnusedPlaneIndex.Insert( planeIndex );
		}
	}

	out_mesh = PMesh( pointCloud.ArrayPointsGet(), arrayTriangleVertexIndex );

	for( HSINT index = 0; index < out_triangleData.SizeGet(); ++index )
	{
		out_mesh.TriangleEdgeFlagSet(
			index,
			arrayTriangleEdgeVisiblity[ ( index * 3 ) + 0 ],
			arrayTriangleEdgeVisiblity[ ( index * 3 ) + 1 ],
			arrayTriangleEdgeVisiblity[ ( index * 3 ) + 2 ]
		);

		TTriangleData& triangleData = out_triangleData[ index ];
		//mark triangle as dirty if there is an open edge
		for( HSINT edgeIndex = 0; edgeIndex < 3; ++edgeIndex )
		{
			const HSINT triangleTouching = out_mesh.TriangleEdgeTouchesGet(
				index,
				edgeIndex
				);
			if( HCOMMON_INVALID_INDEX == triangleTouching )
			{
				triangleData.m_messy = HTRUE;
			}
		}
	}

	//make sure each fase marked as messy gets all faces of palne to be marked as messy
	TArraySint arrayMessyPlaneIndex;
	HCOMMON_FOR_EACH_CONST( data, out_triangleData, TArrayTriangleData )
	{
		if( HTRUE == data.m_messy )
		{
			HContainerUtility::UniqueAdd( arrayMessyPlaneIndex, data.m_planeIndex );
		}
	}

	HCOMMON_FOR_EACH( data, out_triangleData, TArrayTriangleData )
	{
		if( HCOMMON_INVALID_INDEX == HContainerUtility::IndexOf( arrayMessyPlaneIndex, data.m_planeIndex ) )
		{
			continue;
		}

		data.m_messy = HTRUE;
	}

	return;
}

/**/
Hubris::HVOID PConvexHullUtility::ConvertToTriangles(
	TArrayTriangle& out_arrayTriangles,
	PConvexHull& in_out_convexHull
	)
{
	out_arrayTriangles.Clear();

	//get a closed loop of points for each plane, if there is one, and trianglulate it
	const HSINT planeCount = in_out_convexHull.PlaneCountGet();
	for( HSINT planeIndex = 0; planeIndex < planeCount; ++planeIndex )
	{
		//get the vertex edge loop
		TArrayVector arrayEdgeLoopVertex;
		HBOOL closed = HTRUE;

		in_out_convexHull.ImplementationGet().PlaneLoopGather(
			arrayEdgeLoopVertex,
			closed,
			planeIndex
			);

		if( HFALSE == closed )
		{
			continue;
		}

		TArraySint arrayTriangleVertexIndexTriplets;
		PTriangleUtility::CapEdgeLoop( 
			arrayTriangleVertexIndexTriplets, //size%3
			arrayEdgeLoopVertex
			);

		for( HSINT triangleIndex = 0; triangleIndex < arrayTriangleVertexIndexTriplets.SizeGet(); triangleIndex += 3 )
		{
			PTriangle triangle;
			triangle.PointOneSet( arrayEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 0 ] ] );
			triangle.PointTwoSet( arrayEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 1 ] ] );
			triangle.PointThreeSet( arrayEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 2 ] ] );
			out_arrayTriangles.Insert( triangle );
		}
	}

	return;
}

/**/
Hubris::HVOID PConvexHullUtility::ConvertToTriangles(
	TArrayReal& out_arrayTriangles,
	PConvexHull& in_out_convexHull
	)
{
	out_arrayTriangles.Clear();

	//get a closed loop of points for each plane, if there is one, and trianglulate it
	const HSINT planeCount = in_out_convexHull.PlaneCountGet();
	for( HSINT planeIndex = 0; planeIndex < planeCount; ++planeIndex )
	{
		//get the vertex edge loop
		TArrayVector arrayEdgeLoopVertex;
		HBOOL closed = HTRUE;

		in_out_convexHull.ImplementationGet().PlaneLoopGather(
			arrayEdgeLoopVertex,
			closed,
			planeIndex
			);

		if( HFALSE == closed )
		{
			continue;
		}

		TArraySint arrayTriangleVertexIndexTriplets;
		PTriangleUtility::CapEdgeLoop( 
			arrayTriangleVertexIndexTriplets, //size%3
			arrayEdgeLoopVertex
			);

		for( HSINT triangleIndex = 0; triangleIndex < arrayTriangleVertexIndexTriplets.SizeGet(); triangleIndex += 3 )
		{
			LocalAddVector( out_arrayTriangles, arrayEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 0 ] ] );
			LocalAddVector( out_arrayTriangles, arrayEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 1 ] ] );
			LocalAddVector( out_arrayTriangles, arrayEdgeLoopVertex[ arrayTriangleVertexIndexTriplets[ triangleIndex + 2 ] ] );
		}
	}

	return;
}

/**/
const Hubris::HREAL PConvexHullUtility::VolumeApproxGet( PConvexHull& in_out_convexHull )
{
	PBoundsR3 bounds;
	bounds = BoundsGet( in_out_convexHull );

	HCOMMON_ASSERT( HTRUE == bounds.ValidGet(), "bounds not valid, call EnclosedTest() on hull first" );

	const HVectorR3 dim = bounds.VectorMaximumGet() - bounds.VectorMinimumGet();

	return HMatrixUtility::DotProduct( dim, dim );
}

/**
const Hubris::HREAL PConvexHullUtility::VolumeGet( PConvexHull& in_out_convexHull )

/**/
HVOID PConvexHullUtility::ScaleHull( PConvexHull& in_out_convexHull, const HREAL in_scale )
{
	for( HSINT index = 0; index < in_out_convexHull.PlaneCountGet(); ++index )
	{

		PPlaneR3 plane = in_out_convexHull.PlaneGet( index );
		plane.DistanceSet( plane.DistanceGet() * in_scale );
		in_out_convexHull.PlaneSet( index, plane );
	}

	return;
}

/**/
HVOID PConvexHullUtility::TranslateHull( PConvexHull& in_out_convexHull, const HMatrixR4& in_transform )
{
	for( HSINT index = 0; index < in_out_convexHull.PlaneCountGet(); ++index )
	{
		const PPlaneR3 plane = PPlaneUtility::TranslatePlane( in_out_convexHull.PlaneGet( index ), in_transform );
		in_out_convexHull.PlaneSet( index, plane );
	}

	return;
}

/**/
const Hubris::HBOOL PConvexHullUtility::SphereHullTouch(
	const PConvexHull& in_hull,
	const PSphereR3& in_sphereTest
	)
{
	for( HSINT index = 0; index < in_hull.PlaneCountGet(); ++index )
	{
		if( HFALSE == PPlaneUtility::SphereTouchPlane( 
			in_hull.PlaneGet( index ),
			in_sphereTest
			) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL PConvexHullUtility::SphereHullInside(
	const PConvexHull& in_hull,
	const PSphereR3& in_sphereTest
	)
{
	for( HSINT index = 0; index < in_hull.PlaneCountGet(); ++index )
	{
		if( HFALSE == PPlaneUtility::SphereInsidePlane( 
			in_hull.PlaneGet( index ),
			in_sphereTest
			) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
Hubris::HVOID PConvexHullUtility::SphereHullTest(
	Hubris::HBOOL& out_sphereInside,
	Hubris::HBOOL& out_touching,
	const PConvexHull& in_hull,
	const PSphereR3& in_sphereTest
	)
{
	out_sphereInside = HTRUE;
	out_touching = HTRUE;

	for( HSINT index = 0; index < in_hull.PlaneCountGet(); ++index )
	{
		if( HTRUE == out_sphereInside )
		{
			if( HFALSE == PPlaneUtility::SphereInsidePlane( 
				in_hull.PlaneGet( index ),
				in_sphereTest
				) )
			{
				out_sphereInside = HFALSE;
			}
			else
			{
				continue;
			}
		}
		if( HTRUE == out_touching )
		{
			if( HFALSE == PPlaneUtility::SphereTouchPlane( 
				in_hull.PlaneGet( index ),
				in_sphereTest
				) )
			{
				out_touching = HFALSE;
				return;
			}
			else
			{
				continue;
			}
		}
	}

	return;
}

/**/
