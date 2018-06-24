//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataTriangle.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataTriangle.h"

#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtility.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataVertexPool.h"

#include "Pride/PConvexHull/PConvexHull_Export.h"
#include "Pride/PIntersection/PIntersection_Export.h"
#include "Pride/PMesh/PMesh_Export.h"
#include "Pride/PPlane/PPlane_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< Hubris::HBOOL >TArrayBool;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector2D;
typedef Hubris::HContainerArray< Pride::PPlaneR3 >TArrayPlane;
typedef Hubris::HContainerTree< HSINT, HSINT >TTreeIntInt;

///////////////////////////////////////////////////////
// local static variables
/**/
static const HREAL s_encloseHullDotLimit = -0.2F;

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalCollectUsedVertex( 
	TArrayVector& in_out_arrayPoints,
	const TArraySint& in_arrayTriangleIndex,
	const PMesh& in_mesh
	)
{
	PConvexHullGenerateUtilityDataVertexPool vertexPool( in_mesh.ArrayVertexGet(), in_out_arrayPoints );

	HCOMMON_FOR_EACH_CONST( triangleIndex, in_arrayTriangleIndex, TArraySint )
	{
		HSINT arrayVertexIndex[ 3 ];
		in_mesh.TriangleIndexGet( 
			triangleIndex, 
			arrayVertexIndex[ 0 ],
			arrayVertexIndex[ 1 ],
			arrayVertexIndex[ 2 ]
		);

		vertexPool.RequestVertex( arrayVertexIndex[ 0 ] );
		vertexPool.RequestVertex( arrayVertexIndex[ 1 ] );
		vertexPool.RequestVertex( arrayVertexIndex[ 2 ] );
	}

	return;
}

/*
	true: when all points inside plane
	false: if any point outside
*/
static const HBOOL LocalVertexInsidePlane( 
	const PPlaneR3& in_plane,
	const HVectorR3& in_vectorOne,
	const HVectorR3& in_vectorTwo,
	const HVectorR3& in_vectorThree
)
{
	const HREAL distanceOne = PPlaneUtility::DistanceFromPlaneGet( in_plane, in_vectorOne );
	const HREAL distanceTwo = PPlaneUtility::DistanceFromPlaneGet( in_plane, in_vectorTwo );
	const HREAL distanceThree = PPlaneUtility::DistanceFromPlaneGet( in_plane, in_vectorThree );

	if( ( 0.001F <= distanceOne ) ||
		( 0.001F <= distanceTwo ) ||
		( 0.001F <= distanceThree ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/*
	true: when all points inside plane
	false: if any point outside
*/
static const HBOOL LocalVertexInsideArrayPlane( 
	const TArrayPlane& in_arrayPlane,
	const HVectorR3& in_vectorOne,
	const HVectorR3& in_vectorTwo,
	const HVectorR3& in_vectorThree
)
{
	HCOMMON_FOR_EACH_CONST( plane, in_arrayPlane, TArrayPlane )
	{
		if( HFALSE == LocalVertexInsidePlane(
			plane,
			in_vectorOne,
			in_vectorTwo,
			in_vectorThree
			) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
static const HSINT LocalFindMatchingPlane( 
	const TArrayPlane& in_arrayPlane,
	const HVectorR3& in_vectorOne,
	const HVectorR3& in_vectorTwo,
	const HVectorR3& in_vectorThree
)
{
	for( HSINT index = 0; index < in_arrayPlane.SizeGet(); ++index )
	{
		const PPlaneR3 plane = in_arrayPlane[ index ];
		const HREAL distanceOne = HMathUtility::Absolute( PPlaneUtility::DistanceFromPlaneGet( plane, in_vectorOne ) );
		const HREAL distanceTwo = HMathUtility::Absolute( PPlaneUtility::DistanceFromPlaneGet( plane, in_vectorTwo ) );
		const HREAL distanceThree = HMathUtility::Absolute( PPlaneUtility::DistanceFromPlaneGet( plane, in_vectorThree ) );

		if( ( distanceOne <= 0.001F ) &&
			( distanceTwo <= 0.001F ) &&
			( distanceThree <= 0.001F ) )
		{
			return index;
		}
	}

	return HCOMMON_INVALID_INDEX;
}


/**/
static Hubris::HVOID LocalCalculatePlaneArray(
	TArrayPlane& out_arrayTrianglePlane,
	const TArraySint& in_arrayUsedTriangleIndex,
	PMesh& in_mesh
	)
{
	out_arrayTrianglePlane.Clear();

	HCOMMON_FOR_EACH_CONST( triangleIndex, in_arrayUsedTriangleIndex, TArraySint )
	{
		HVectorR3 testArrayVectors[ 3 ];
		in_mesh.TriangleVertexGet(
			triangleIndex,
			testArrayVectors[ 0 ],
			testArrayVectors[ 1 ],
			testArrayVectors[ 2 ]
		);

		const HSINT planeIndex = LocalFindMatchingPlane( 
			out_arrayTrianglePlane,
			testArrayVectors[ 0 ], 
			testArrayVectors[ 1 ], 
			testArrayVectors[ 2 ] 
		);

		if( HCOMMON_INVALID_INDEX != planeIndex )
		{
			continue;
		}

		PPlaneR3 plane;
		if( HTRUE == PPlaneUtility::ConstructPlane( 
			plane, 
			testArrayVectors[ 0 ],
			testArrayVectors[ 1 ],
			testArrayVectors[ 2 ]
		) )
		{
			out_arrayTrianglePlane.Insert( plane );
		}
	}

	return;
}	

/*
	return true if any triangles removed
*/
static const HBOOL LocalAddLimitPlane(
	TArraySint& in_out_arrayUsedTriangleIndex,
	TArrayPlane& in_out_arrayPlanesLimit,
	const HVectorR3& in_vectorOne,
	const HVectorR3& in_vectorTwo,
	const HVectorR3& in_vectorThree,
	PMesh& in_mesh
)
{
	//bail if we already have a matching plane
	if( HCOMMON_INVALID_INDEX != LocalFindMatchingPlane(
		in_out_arrayPlanesLimit,
		in_vectorOne,
		in_vectorTwo,
		in_vectorThree
		) )
	{
		return HFALSE;
	}

	//add limit plane
	PPlaneR3 limitPlane;
	if( HFALSE == PPlaneUtility::ConstructPlane(
		limitPlane,
		in_vectorOne,
		in_vectorTwo,
		in_vectorThree
		) )
	{
		return HFALSE;
	}

	in_out_arrayPlanesLimit.Insert( limitPlane );

	//trim the triangle list by the limit plane
	TArraySint newTriangleList;
	HBOOL removedTriangle = HFALSE;
	HCOMMON_FOR_EACH_CONST( triangleIndex, in_out_arrayUsedTriangleIndex, TArraySint )
	{
		HVectorR3 arrayVector[ 3 ];
		in_mesh.TriangleVertexGet(
			triangleIndex,
			arrayVector[ 0 ],
			arrayVector[ 1 ],
			arrayVector[ 2 ]
		);

		if( HTRUE == LocalVertexInsidePlane( 
			limitPlane,
			arrayVector[ 0 ],
			arrayVector[ 1 ],
			arrayVector[ 2 ] 
		) )
		{
			newTriangleList.Insert( triangleIndex );
		}
		else
		{
			removedTriangle = HTRUE;
		}
	}

	if( HTRUE == removedTriangle )
	{
		in_out_arrayUsedTriangleIndex = newTriangleList;
	}

	return removedTriangle;
}

/*
	return true if any point of mesh is inside a hull surrounding given triangles
*/
static const HBOOL LocalAnyOtherTriangleInsideHull(
	const TArraySint& in_arrayUsedTriangleIndex,
	const HSINT in_newTraingleIndex,
	PMesh& in_mesh
	)
{
	PConvexHull hull;

	TArraySint localArrayUsedIndex( in_arrayUsedTriangleIndex );
	localArrayUsedIndex.Insert( in_newTraingleIndex );
	TArrayVector pointCloud;
	PMeshUtility::TrianglePointCloudGet( 
		pointCloud,
		localArrayUsedIndex,
		in_mesh
		);

	PConvexHullGenerateUtility::CreateHullFromPointCloud(
		hull, 
		pointCloud 
		);

	if( HFALSE == PConvexHullUtility::EnclosedTest( hull ) )
	{
		return HFALSE;
	}

	return PIntersectionUtility::ArrayPointInsideHull(
		hull,
		in_mesh.ArrayVertexGet(),
		-0.0001F
		);
}

/**/
static const HBOOL LocalTriangleAtemptAdd(
	TArraySint& in_out_arrayUsedTriangleIndex,
	const TArrayPlane& in_arrayPlanes,
	TArrayPlane& in_out_arrayPlanesLimit,
	const TArrayBool& in_arrayFaceUsage,
	PMesh& in_mesh,
	const HSINT in_triangleIndex
	) 
{
	//straight bail case, invalid triangle or already used triangle
	if( ( HCOMMON_INVALID_INDEX == in_triangleIndex ) ||
		( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( in_out_arrayUsedTriangleIndex, in_triangleIndex ) ) )
	{
		return HFALSE;
	}

	HVectorR3 arrayVector[ 3 ];
	in_mesh.TriangleVertexGet(
		in_triangleIndex,
		arrayVector[ 0 ],
		arrayVector[ 1 ],
		arrayVector[ 2 ]
	);

	//bail if triangle to add is outside any plane, ie. fail convex
	if( HFALSE == LocalVertexInsideArrayPlane( 
		in_arrayPlanes,
		arrayVector[ 0 ],
		arrayVector[ 1 ],
		arrayVector[ 2 ]
		) )
	{
		return HFALSE;
	}

	if( HTRUE == LocalAnyOtherTriangleInsideHull(
		in_out_arrayUsedTriangleIndex,
		in_triangleIndex,
		in_mesh
		) )
	{
		return HFALSE;
	}

	//if already in use, add limit
	if( HTRUE == in_arrayFaceUsage[ in_triangleIndex ] )
	{
		return LocalAddLimitPlane(
			in_out_arrayUsedTriangleIndex,
			in_out_arrayPlanesLimit,
			arrayVector[ 0 ],
			arrayVector[ 1 ],
			arrayVector[ 2 ],
			in_mesh
		);
	}

	//add triangle
	in_out_arrayUsedTriangleIndex.Insert( in_triangleIndex );

	return HTRUE;
}

/**/
static const HBOOL LocalFlowTriangle(
	TArraySint& in_out_arrayUsedTriangleIndex,
	const TArrayPlane& in_arrayPlanes,
	TArrayPlane& in_out_arrayPlanesLimit,
	const TArrayBool& in_arrayFaceUsage,
	PMesh& in_mesh
	)
{
	HCOMMON_FOR_EACH_CONST( triangleIndex, in_out_arrayUsedTriangleIndex, TArraySint )
	{
		for( HSINT index = 0; index < 3; ++index )
		{
			const HSINT touchingTriangle = in_mesh.TriangleEdgeTouchesGet( triangleIndex, index );

			if( HTRUE == LocalTriangleAtemptAdd(
				in_out_arrayUsedTriangleIndex,
				in_arrayPlanes,
				in_out_arrayPlanesLimit,
				in_arrayFaceUsage,
				in_mesh,
				touchingTriangle
				) )
			{
				return HTRUE;
			}
		}
	}

	return HFALSE;
}

/**/
static Hubris::HVOID LocalConstructTriangleHull(
	TArraySint& out_arrayUsedTriangleIndex,
	TArrayPlane& out_arrayPlanes,
	TArrayPlane& out_arrayPlanesLimit,
	const TArrayBool& in_arrayFaceUsage,
	PMesh& in_mesh,
	const HSINT in_seedIndex
	)
{
	out_arrayUsedTriangleIndex.Clear();
	out_arrayPlanes.Clear();
	out_arrayPlanesLimit.Clear();

	//prime data
	out_arrayUsedTriangleIndex.Insert( in_seedIndex );

	HBOOL triangleListChanged = HTRUE;
	while( HTRUE == triangleListChanged )
	{
		LocalCalculatePlaneArray(
			out_arrayPlanes,
			out_arrayUsedTriangleIndex,
			in_mesh
		);

		triangleListChanged = LocalFlowTriangle(
			out_arrayUsedTriangleIndex,
			out_arrayPlanes,
			out_arrayPlanesLimit,
			in_arrayFaceUsage,
			in_mesh
			);
	}

	return;
}

/**/
static const HVectorR3 LocalAverageNormalFind( 
	const TArrayPlane& in_arrayPlane 
	)
{
	HVectorR3 normal;
	HCOMMON_FOR_EACH_CONST( plane, in_arrayPlane, TArrayPlane )
	{
		normal += plane.DirectionGet().VectorGet();
	}

	normal = HMatrixUtility::Normalise( normal );

	return normal;
}

/**/
static const HREAL LocalMinDotGet( 
	const TArrayPlane& in_arrayPlane, 
	const HVectorR3& in_averageNormal 
	)
{
	HREAL minDot = 1.0F;
	HCOMMON_FOR_EACH_CONST( plane, in_arrayPlane, TArrayPlane )
	{
		const HREAL testDot = HMatrixUtility::DotProduct( in_averageNormal, plane.DirectionGet().VectorGet() );
		if( testDot < minDot )
		{
			minDot = testDot;
		}
	}

	return minDot;
}

/**/
static const HREAL LocalPlaneDistanceGet( 
	const TArrayVector& in_arrayPoints,
	const HVectorR3& in_averageNormal,
	const HREAL in_depth 
	)
{
	HREAL minValue = HVariablesMath::MaximumGet< HREAL >();
	HCOMMON_FOR_EACH_CONST( point, in_arrayPoints, TArrayVector )
	{
		const HREAL testValue = HMatrixUtility::DotProduct( in_averageNormal, point );
		if( testValue < minValue )
		{
			minValue = testValue;
		}
	}

	return( minValue - in_depth );
}

/**/
static const Hubris::HVOID LocalAddProjectedPoints(
	TArrayVector& in_out_arrayPoints,
	const PPlaneR3& in_plane,
	const TArraySint& in_arrayIndexEdgeLoop 
	)
{
	TArrayVector newPoints;
	HCOMMON_FOR_EACH_CONST( index, in_arrayIndexEdgeLoop, TArraySint )
	{
		HVectorR3 point = in_out_arrayPoints[ index ];
		const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( in_plane, point );
		point -= ( distance * in_plane.DirectionGet().VectorGet() );
		newPoints.Insert( point );
	}

	in_out_arrayPoints.Insert( newPoints.Begin(), newPoints.End() );

	return;
}

/**/
static Hubris::HVOID LocalAddThickness(
	const TArrayPlane& in_arrayPlane,
	TArrayVector& in_out_arrayPoints,
	const Hubris::HREAL in_depth
	)
{
	//if we have thickness, project plane average profile down and add points for it
	if( HTRUE == HMathUtility::EpsilonZero( in_depth ) )
	{
		return;
	}

	//find average normal
	const HVectorR3 averageNormal = LocalAverageNormalFind( in_arrayPlane );
	if( HTRUE == HMathUtility::EpsilonZero( averageNormal ) )
	{
		return;
	}

	//get max plane dot producet with average
	const HREAL minDot = LocalMinDotGet( in_arrayPlane, averageNormal );
	//found planes are partially enclosed, bail
	if( minDot < s_encloseHullDotLimit ) 
	{
		return;
	}

	const HREAL planeDistance = LocalPlaneDistanceGet( in_out_arrayPoints, averageNormal, in_depth );

	TArraySint arrayPointIndexEdgeProfile;
	PPlaneR3 plane( planeDistance, PUnitVectorR3( averageNormal ) );

	TArrayVector2D arrayPoints2D;
	PPlaneUtility::ProjectOntoPlane( 
			arrayPoints2D,
			in_out_arrayPoints, 
			plane
			);

	TArraySint arrayIndexEdgeLoop;

	if( HFALSE == PConvexHullGenerateUtility::CreateProfileFromPointCloud2D( 
		arrayIndexEdgeLoop,
		arrayPoints2D
		) )
	{
		return;
	}

	//add the profile point projected onto the plane
	LocalAddProjectedPoints(
		in_out_arrayPoints,
		plane,
		arrayIndexEdgeLoop
		);

	return;
}

/**/
///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityDataTriangle::PConvexHullGenerateUtilityDataTriangle( const PConvexHullGenerateUtilityDataTriangle& in_src )
: m_arrayPoints()
{
	( *this ) = in_src;
	return;
}
/**/
PConvexHullGenerateUtilityDataTriangle::PConvexHullGenerateUtilityDataTriangle()
: m_arrayPoints()
{
	return;
}

/**/
PConvexHullGenerateUtilityDataTriangle::~PConvexHullGenerateUtilityDataTriangle()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilityDataTriangle& PConvexHullGenerateUtilityDataTriangle::operator=( const PConvexHullGenerateUtilityDataTriangle& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayPoints = in_rhs.m_arrayPoints;
	}

	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataTriangle::operator==( const PConvexHullGenerateUtilityDataTriangle& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayPoints == in_rhs.m_arrayPoints );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataTriangle::operator!=( const PConvexHullGenerateUtilityDataTriangle& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataTriangle::Create(
	TArrayBool& in_out_arrayFaceUsage,
	PMesh& in_mesh,
	const Hubris::HREAL in_depth,
	const Hubris::HSINT in_seedIndex
	)
{
	( *this ) = PConvexHullGenerateUtilityDataTriangle();

	TArraySint arrayUsedTriangleIndex;
	TArrayPlane arrayPlanes;
	TArrayPlane arrayPlanesLimit;

	LocalConstructTriangleHull(
		arrayUsedTriangleIndex,
		arrayPlanes,
		arrayPlanesLimit,
		in_out_arrayFaceUsage,
		in_mesh,
		in_seedIndex
		);

	LocalCollectUsedVertex( 
		m_arrayPoints,
		arrayUsedTriangleIndex,
		in_mesh
		);

	//AFTER collecting used vertex, add thickness
	LocalAddThickness(
		arrayPlanes,
		m_arrayPoints,
		in_depth
		);

	//update the face usage array
	HCOMMON_FOR_EACH_CONST( triangleIndex, arrayUsedTriangleIndex, TArraySint )
	{
		in_out_arrayFaceUsage[ triangleIndex ] = HTRUE;
	}

	//HCOMMON_ASSERT( 0 < arrayUsedTriangleIndex.SizeGet(), "failed sanity check" );
	const HBOOL ok = ( 0 < arrayUsedTriangleIndex.SizeGet() );

	return ok;
}

/**/

