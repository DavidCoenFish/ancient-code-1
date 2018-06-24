//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtility.h"

#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataTriangle.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduce.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduce.h"

#include "Pride/PConvexHull/PConvexHull.h"
#include "Pride/PConvexHull/PConvexHullUtility.h"
#include "Pride/PInterface/PInterface_Export.h"
#include "Pride/PLine/PLineSegment.h"
#include "Pride/PLine/PLineSegmentUtility.h"
#include "Pride/PMesh/PMesh_Export.h"
#include "Pride/PBounds/PBounds_Export.h"
#include "Pride/PPlane/PPlane_Export.h"
#include "Pride/PPointCloud/PPointCloud_Export.h"
#include "Pride/PSphere/PSphere_Export.h"

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
typedef Hubris::HContainerPair< Hubris::HVectorR2, Hubris::HVectorR2 >TPairVectorR2VectorR2;
typedef Hubris::HContainerArray< TPairVectorR2VectorR2 >TArrayPairVectorR2VectorR2;
typedef Hubris::HContainerArray< PPlaneR3 >TArrayPlane;
typedef Hubris::HContainerArray< PConvexHull >TArrayHull;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVectorR2;
typedef Hubris::HContainerArray< Hubris::HBOOL >TArrayBool;
typedef Hubris::HContainerArray< PPlaneR2 >TArrayPlaneR2;

typedef Hubris::HContainerArray< PSphereR3 >TArraySphere;
typedef Hubris::HContainerArray< TArraySint >TArrayArraySint;

static const HSINT s_pointCloudSizeLimit = 128;

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalReducePointCloud( 
	TArrayVector& out_cleanPointCloud,
	const TArrayVector& in_pointCloud,
	const HREAL in_pointCloudMergePercentage
	)
{
	PPointCloudR3 pointCloud;
	pointCloud.ArrayPointMerge( in_pointCloud, PPointCloudR3::ThreasholdCreate( in_pointCloud, in_pointCloudMergePercentage ) );
	out_cleanPointCloud = pointCloud.ArrayPointsGet();

	//TArraySint arrayMergeCount;
	//out_cleanPointCloud.Clear();

	//PBoundsR3 bounds;
	//HCOMMON_FOR_EACH_CONST( point, in_pointCloud, TArrayVector )
	//{
	//	bounds.InsertPoint( point );
	//}

	//const HVectorR3 delta = ( bounds.VectorMaximumGet() - bounds.VectorMinimumGet() ) * in_pointCloudMergePercentage;
	//HCOMMON_FOR_EACH_CONST( point, in_pointCloud, TArrayVector )
	//{
	//	HBOOL add = HTRUE;
	//	for( HSINT index = 0; index < out_cleanPointCloud.SizeGet(); ++index )
	//	{
	//		const HVectorR3 offset = HMathUtility::Absolute( point - out_cleanPointCloud[ index ] );
	//		if( offset <= delta )
	//		{
	//			add = HFALSE;
	//			//merge point
	//			HVectorR3& cleanPoint = out_cleanPointCloud[ index ];
	//			HSINT& size = arrayMergeCount[ index ]; 
	//			size += 1;
	//			cleanPoint = ( ( cleanPoint * ( HREAL )( size ) ) + point ) * ( 1.0F / ( HREAL )( size + 1 ) );
	//			break;
	//		}
	//	}
	//	if( HFALSE == add )
	//	{
	//		continue;
	//	}

	//	out_cleanPointCloud.Insert( point );
	//	arrayMergeCount.Insert( 0 );
	//}

	return;
}

/**/
static Hubris::HVOID LocalAddUniquePlane( 
	TArrayPlane& in_out_arrayPlane,
	const PPlaneR3& in_plane 
	)
{
	for( HSINT index = 0; index < in_out_arrayPlane.SizeGet(); ++index )
	{
		if( HTRUE == PPlaneUtility::EqualDelta( in_plane, in_out_arrayPlane[ index ], 0.001F, 0.01F ) )
		{
			return;
		}
	}

	in_out_arrayPlane.Insert( in_plane );

	return;
}

/**/
static HBOOL LocalNoPointsOutside(
	const PPlaneR3& in_plane, 
	const TArrayVector::TIterator& in_pointCloudFirst,
	const TArrayVector::TIterator& in_pointCloudLast,
	const TArrayVector::TIterator& in_iteratorOne,
	const TArrayVector::TIterator& in_iteratorTwo,
	const TArrayVector::TIterator& in_iteratorThree
	)
{
	for( const TArrayVector::TIterator trace = in_pointCloudFirst; trace != in_pointCloudLast; ++trace )
	{
		if( ( trace == in_iteratorOne ) || 
			( trace == in_iteratorTwo ) ||
			( trace == in_iteratorThree ) )
		{
			continue;
		}

		const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( 
			in_plane, 
			*trace 
			);

		if( 0.001F < distance )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
static Hubris::HVOID LocalSubmitPlane(
	TArrayPlane& in_out_arrayPlane,
	const TArrayVector::TIterator& in_pointCloudFirst,
	const TArrayVector::TIterator& in_pointCloudLast,
	const TArrayVector::TIterator& in_iteratorOne,
	const TArrayVector::TIterator& in_iteratorTwo,
	const TArrayVector::TIterator& in_iteratorThree
	)
{
	//attempt create plane
	PPlaneR3 plane;
	if( HFALSE == PPlaneUtility::ConstructPlane(
		plane,
		( *in_iteratorOne ),
		( *in_iteratorTwo ),
		( *in_iteratorThree )
		) )
	{
		return;
	}

	if( HTRUE == LocalNoPointsOutside(
		plane, 
		in_pointCloudFirst,
		in_pointCloudLast,
		in_iteratorOne,
		in_iteratorTwo,
		in_iteratorThree
		) )
	{
		LocalAddUniquePlane( 
			in_out_arrayPlane,
			plane 
			);
		return;
	}

	plane = PPlaneUtility::PlaneFlip( plane );

	if( HTRUE == LocalNoPointsOutside(
		plane, 
		in_pointCloudFirst,
		in_pointCloudLast,
		in_iteratorOne,
		in_iteratorTwo,
		in_iteratorThree
		) )
	{
		LocalAddUniquePlane( 
			in_out_arrayPlane,
			plane 
			);
		return;
	}

	return;
}

/**/
static Hubris::HVOID LocalGatherPointsOnPlaneSurface(
	TArrayVector& out_usedPoints,
	const TArrayPlane& in_planeArray,
	const TArrayVector::TIterator& in_pointCloudFirst,
	const TArrayVector::TIterator& in_pointCloudLast
	)
{
	//if point is not inside every plane (ie, it is on the surface) then add
	for( const TArrayVector::TIterator trace = in_pointCloudFirst; trace != in_pointCloudLast; ++trace )
	{
		HBOOL addPoint = HFALSE;
		HCOMMON_FOR_EACH_CONST( plane, in_planeArray, TArrayPlane )
		{
			const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( 
				plane,
				( *trace )
				);

			if( -0.001 < distance )
			{
				addPoint = HTRUE;
				break;
			}
		}

		if( HTRUE == addPoint )
		{
			out_usedPoints.Insert( *trace );
		}
	}

	return;
}

/**/
static Hubris::HVOID LocalCreateArrayUsedPointsFromPointCloud(
	TArrayPlane& out_planeArray,
	TArrayVector& out_usedPoints,
	const TArrayVector::TIterator& in_pointCloudFirst,
	const TArrayVector::TIterator& in_pointCloudLast
	)
{
	out_planeArray.Clear();
	out_usedPoints.Clear();

	//make a plane for each triplate of points once
	for( const TArrayVector::TIterator iteratorOne = in_pointCloudFirst; iteratorOne < in_pointCloudLast; ++iteratorOne )
	{
		for( const TArrayVector::TIterator iteratorTwo = iteratorOne + 1; iteratorTwo < in_pointCloudLast; ++iteratorTwo )
		{
			for( const TArrayVector::TIterator iteratorThree = iteratorTwo + 1; iteratorThree < in_pointCloudLast; ++iteratorThree )
			{
				LocalSubmitPlane(
					out_planeArray,
					in_pointCloudFirst,
					in_pointCloudLast,
					iteratorOne,
					iteratorTwo,
					iteratorThree
					);
			}
		}
	}

	LocalGatherPointsOnPlaneSurface(
		out_usedPoints,
		out_planeArray,
		in_pointCloudFirst,
		in_pointCloudLast
		);

	return;
}

/**/
static Hubris::HVOID LocalMakePlaneArrayFromPointCloud(
	TArrayPlane& out_planeArray,
	TArrayVector& out_usedPoints,
	const TArrayVector::TIterator& in_pointCloudFirst,
	const TArrayVector::TIterator& in_pointCloudLast,
	PInterfaceProgress* const in_pProgress
	)
{
	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "Make planes for point cloud: " + 
			HTraitStringIn( in_pointCloudFirst.IndexGet() ) +
			" to " +
			HTraitStringIn( in_pointCloudLast.IndexGet() )
			);
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return;
		}
	}

	TArrayVector localPointCloud;

	const HSINT length = in_pointCloudLast - in_pointCloudFirst;
	if( s_pointCloudSizeLimit < length )
	{
		const HSINT half = length >> 1;
		TArrayPlane localPlaneArray;
		TArrayVector localUsedPoints0;

		LocalMakePlaneArrayFromPointCloud(
			localPlaneArray,
			localPointCloud,
			in_pointCloudFirst, 
			in_pointCloudFirst + half,
			in_pProgress
			);

		if( HNULL != in_pProgress )
		{
			if( HTRUE == in_pProgress->CancelGet() )
			{
				return;
			}
		}

		LocalMakePlaneArrayFromPointCloud(
			localPlaneArray,
			localUsedPoints0,
			in_pointCloudFirst + half, 
			in_pointCloudLast,
			in_pProgress
			);

		if( HNULL != in_pProgress )
		{
			if( HTRUE == in_pProgress->CancelGet() )
			{
				return;
			}
		}

		localPointCloud.Insert( localUsedPoints0.Begin(), localUsedPoints0.End() );		
	}
	else
	{
		localPointCloud.Insert( in_pointCloudFirst, in_pointCloudLast );
	}

	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "get used vertex planes: " + 
			HTraitStringIn( out_planeArray.SizeGet() ) +
			" point cloud: " +
			HTraitStringIn( localPointCloud.SizeGet() )
			);
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return;
		}
	}

	LocalCreateArrayUsedPointsFromPointCloud(
		out_planeArray,
		out_usedPoints,
		localPointCloud.Begin(),
		localPointCloud.End()
		);

	return;
}

/**/
static HBOOL LocalHullForTriangle(
	PConvexHull& in_convexHull,
	PMesh& in_mesh,
	const HREAL in_depth,
	const HSINT in_index,
	PInterfaceProgress* const in_pProgress = HNULL
	)
{
	HVectorR3 pointOne;
	HVectorR3 pointTwo;
	HVectorR3 pointThree;
	in_mesh.TriangleVertexGet(
		in_index,
		pointOne,
		pointTwo,
		pointThree
		);

	PPlaneR3 plane;
	if( HFALSE == PPlaneUtility::ConstructPlane( 
		plane,
		pointOne,
		pointTwo,
		pointThree
		) )
	{
		return HFALSE;
	}

	const HREAL localDepth = HMathUtility::Maximum( 1.0F, in_depth );
	const HVectorR3 offset = plane.DirectionGet().VectorGet() * localDepth;

	TArrayVector pointCloud;
	pointCloud.Insert( pointOne );
	pointCloud.Insert( pointTwo );
	pointCloud.Insert( pointThree );
	pointCloud.Insert( pointOne - offset );
	pointCloud.Insert( pointTwo - offset );
	pointCloud.Insert( pointThree - offset );

	if( HFALSE == PConvexHullGenerateUtility::CreateHullFromPointCloud(
		in_convexHull,
		pointCloud,
		in_pProgress
		) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/

static Hubris::HVOID LocalAddUniquePlane( 
	TArrayPlaneR2& in_out_arrayPlane,
	const PPlaneR2& in_plane 
	)
{
	for( HSINT index = 0; index < in_out_arrayPlane.SizeGet(); ++index )
	{
		if( HTRUE == PPlaneUtility::EqualDelta( in_plane, in_out_arrayPlane[ index ], 0.0001F, 0.001F ) )
		{
			return;
		}
	}

	in_out_arrayPlane.Insert( in_plane );

	return;
}

/**
static HBOOL LocalNoPointsOutside(
	const PPlaneR3& in_plane, 
	const TArrayVector& in_pointCloud,
	const HSINT in_ignorePointIndexOne,
	const HSINT in_ignorePointIndexTwo,
	const HSINT in_ignorePointIndexThree
	)
{
	//HCOMMON_FOR_EACH_CONST( point, in_pointCloud, TArrayVector )
	for( HSINT index = 0; index < in_pointCloud.SizeGet(); ++index )
	{
		if( ( index == in_ignorePointIndexOne ) || 
			( index == in_ignorePointIndexTwo ) ||
			( index == in_ignorePointIndexThree ) )
		{
			continue;
		}

		const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( in_plane, in_pointCloud[ index ] );
		if( 0.001F < distance )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}
/**/
static HBOOL LocalNoPointsOutside(
	const PPlaneR2& in_plane, 
	const TArrayVectorR2& in_pointCloud,
	const HSINT in_ignorePointIndexOne,
	const HSINT in_ignorePointIndexTwo
	)
{
	//HCOMMON_FOR_EACH_CONST( point, in_pointCloud, TArrayVectorR2 )
	for( HSINT index = 0; index < in_pointCloud.SizeGet(); ++index )
	{
		if( ( index == in_ignorePointIndexOne ) || 
			( index == in_ignorePointIndexTwo ) )
		{
			continue;
		}

		const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( in_plane, in_pointCloud[ index ] );
		if( 0.001F < distance )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**
static Hubris::HVOID LocalSubmitPlane(
	TArrayPlane& in_out_arrayPlane,
	const TArrayVector& in_pointCloud,
	const HSINT in_indexOne,
	const HSINT in_indexTwo,
	const HSINT in_indexThree
	)
{
	//attempt create plane
	PPlaneR3 plane;
	if( HFALSE == PPlaneUtility::ConstructPlane(
		plane,
		in_pointCloud[ in_indexOne ],
		in_pointCloud[ in_indexTwo ],
		in_pointCloud[ in_indexThree ]
	) )
	{
		return;
	}

	if( HTRUE == LocalNoPointsOutside(
		plane, 
		in_pointCloud,
		in_indexOne,
		in_indexTwo,
		in_indexThree
		) )
	{
		LocalAddUniquePlane( 
			in_out_arrayPlane,
			plane 
			);
		return;
	}

	plane = PPlaneUtility::PlaneFlip( plane );

	if( HTRUE == LocalNoPointsOutside(
		plane, 
		in_pointCloud,
		in_indexOne,
		in_indexTwo,
		in_indexThree
		) )
	{
		LocalAddUniquePlane( 
			in_out_arrayPlane,
			plane 
			);
		return;
	}

	return;
}

/**/
static Hubris::HVOID LocalSubmitPlane(
	TArrayPlaneR2& in_out_arrayPlanes,
	const TArrayVectorR2& in_pointCloud,
	const HSINT in_indexOne,
	const HSINT in_indexTwo
	)
{
	//attempt to create plane
	PPlaneR2 plane;
	if( HFALSE == PPlaneUtility::ConstructPlane(
		plane,
		in_pointCloud[ in_indexOne ],
		in_pointCloud[ in_indexTwo ]
	) )
	{
		return;
	}

	if( HTRUE == LocalNoPointsOutside(
		plane, 
		in_pointCloud,
		in_indexOne,
		in_indexTwo
		) )
	{
		LocalAddUniquePlane( 
			in_out_arrayPlanes,
			plane 
			);
		return;
	}

	plane = PPlaneUtility::PlaneFlip( plane );

	if( HTRUE == LocalNoPointsOutside(
		plane, 
		in_pointCloud,
		in_indexOne,
		in_indexTwo
		) )
	{
		LocalAddUniquePlane( 
			in_out_arrayPlanes,
			plane 
			);
		return;
	}

	return;
}

/**/
static Hubris::HVOID LocalGatherEdgeSegments( 
	TArrayPairVectorR2VectorR2& out_arraySegment,
	const TArrayPlaneR2& in_arrayPlanes
	)
{
	for( HSINT index = 0; index < in_arrayPlanes.SizeGet(); ++index )
	{
		const PPlaneR2 plane = in_arrayPlanes[ index ];
		const HVectorR2 origin = ( plane.DistanceGet() * plane.DirectionGet().VectorGet() );
		const HVectorR2 direction = plane.DirectionGet().VectorGet();
		PLineSegmentR2 line( PLineR2( origin, PUnitVectorR2( HMatrixConstructor::HVectorR2Construct( direction[ 1 ], -( direction[ 0 ] ) ) ) ) );

		for( HSINT subIndex = 0; subIndex < in_arrayPlanes.SizeGet(); ++subIndex )
		{
			if( index == subIndex )
			{
				continue;
			}

			PLineSegmentUtility::TrimLineSegment( line, in_arrayPlanes[ subIndex ] );
		}

		if( ( HFALSE == line.BoundsLowerValidGet() ) ||
			( HFALSE == line.BoundsUpperValidGet() ) )
		{
			continue;
		}

		if( line.BoundsUpperGet() <= line.BoundsLowerGet() )
		{
			continue;
		}

		HBOOL lowerValid;
		HVectorR2 lower;
		HBOOL upperValid;
		HVectorR2 upper;
		PLineSegmentUtility::LineSegmentToPoints( 
			lower,
			lowerValid,
			upper,
			upperValid,
			line
			);

		if( HMathUtility::EpsilonEqual( lower, upper ) )
		{
			continue;
		}

		out_arraySegment.Insert( TPairVectorR2VectorR2(
			lower, upper 
			) );
	}

	return;
}

/**/
static Hubris::HVOID LocalSortEdgeSegments( 
	TArrayVectorR2& out_arrayPointsSorted,
	const TArrayPairVectorR2VectorR2& in_arraySegment
	)
{
	out_arrayPointsSorted.Clear();

	if( 0 == in_arraySegment.SizeGet() )
	{
		return;
	}

	HVectorR2 seedPoint = in_arraySegment[ 0 ].m_second;

	//go through the segment pairs, and find closest pair linking (current.second to next.first)
	do
	{
		//if seed point is not unique, bail
		if( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( out_arrayPointsSorted, seedPoint ) )
		{
			break;
		}
		HContainerUtility::PushBack( out_arrayPointsSorted, seedPoint );

		HREAL smallestDistance = HVariablesMath::MaximumGet< HREAL >();
		HSINT bestIndex = HCOMMON_INVALID_INDEX;
		for( HSINT index = 0; index < in_arraySegment.SizeGet(); ++index )
		{
			const HREAL testDistance = HMatrixUtility::LengthSquared( seedPoint - in_arraySegment[ index ].m_first );
			if( testDistance < smallestDistance )
			{
				smallestDistance = testDistance;
				bestIndex = index;
			}
		}

		if( HCOMMON_INVALID_INDEX == bestIndex )
		{
			break;
		}

		seedPoint = in_arraySegment[ bestIndex ].m_second;
	}
	while( 0 != out_arrayPointsSorted.SizeGet() );

	return;
}

/**/
static Hubris::HVOID LocalClosestIndexGet(
	TArraySint& out_arrayIndex,
	const TArrayVectorR2& in_arrayPointsSorted,
	const TArrayVectorR2& in_arrayPointCloud
	)
{
	out_arrayIndex.Clear();
	for( HSINT index = 0; index < in_arrayPointsSorted.SizeGet(); ++index )
	{
		HREAL smallestDistance = HVariablesMath::MaximumGet< HREAL >();
		HSINT bestIndex = HCOMMON_INVALID_INDEX;
		for( HSINT subIndex = 0; subIndex < in_arrayPointCloud.SizeGet(); ++subIndex )
		{
			const HREAL testDistance = HMatrixUtility::LengthSquared( in_arrayPointsSorted[ index ] - in_arrayPointCloud[ subIndex ] );
			if( testDistance < smallestDistance )
			{
				smallestDistance = testDistance;
				bestIndex = subIndex;
			}
		}

		if( HCOMMON_INVALID_INDEX == bestIndex )
		{
			continue;
		}

		if( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( out_arrayIndex, bestIndex ) )
		{
			break;
		}
		HContainerUtility::PushBack( out_arrayIndex, bestIndex );

	}
	return;
}

/**/
static Hubris::HVOID LocalExtractIndexArrayFromPlanes(
	TArraySint& out_arrayIndex,
	const TArrayPlaneR2& in_arrayPlanes,
	const TArrayVectorR2& in_pointCloud
	)
{
	out_arrayIndex.Clear();

	TArrayPairVectorR2VectorR2 arraySegment;
	LocalGatherEdgeSegments( 
		arraySegment,
		in_arrayPlanes
		);

	TArrayVectorR2 arrayPointsSorted;
	LocalSortEdgeSegments( 
		arrayPointsSorted,
		arraySegment
		);

	LocalClosestIndexGet(
		out_arrayIndex,
		arrayPointsSorted,
		in_pointCloud
		);

	return;
}

///////////////////////////////////////////////////////
// public static methods
/**/
HVOID PConvexHullGenerateUtility::GenerateHulls( 
		TArrayHull& out_arrayHull, 
		PMesh& in_mesh,
		const Hubris::HREAL in_depth,
		PInterfaceProgress* const in_pProgress
	)
{
	out_arrayHull.Clear();

	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "GenerateHulls" );
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return;
		}
	}

	const HSINT triangleCount = in_mesh.TriangleCountGet();
	TArrayBool arrayFaceUsage;
	arrayFaceUsage.SizeSet( triangleCount );
	for( HSINT index = 0; index < triangleCount; ++index )
	{
		arrayFaceUsage[ index ] = HFALSE;
	}

	//first pass, try to flow over triangles
	HSINT trace = 0;
	while( trace < triangleCount )
	{
		if( HTRUE == arrayFaceUsage[ trace ] )
		{
			trace += 1;
			continue;
		}

		PConvexHullGenerateUtilityDataTriangle dataTriangle;
		if( HFALSE == dataTriangle.Create(
			arrayFaceUsage,
			in_mesh,
			in_depth,
			trace
			) )
		{
			trace += 1;
			continue;
		}

		out_arrayHull.SizeResize( out_arrayHull.SizeGet() + 1 );
		if( HFALSE == CreateHullFromPointCloud(
			HContainerUtility::Back( out_arrayHull ),
			dataTriangle.PointCloudGet(),
			in_pProgress
			) )
		{
			HContainerUtility::PopBack( out_arrayHull );
		}

		if( HNULL != in_pProgress )
		{
			in_pProgress->ProgressSet( "GenerateHulls", HREAL( trace ) / HREAL( triangleCount ) );
			if( HTRUE == in_pProgress->CancelGet() )
			{
				break;
			}
		}
	}

	//second pass, get triangles we missed above
	for( HSINT index = 0; index < triangleCount; ++index )
	{
		if( HTRUE == arrayFaceUsage[ index ] )
		{
			continue;
		}

		//an unused face
		out_arrayHull.SizeResize( out_arrayHull.SizeGet() + 1 );
		if( HFALSE == LocalHullForTriangle(
			HContainerUtility::Back( out_arrayHull ),
			in_mesh,
			in_depth,
			index,
			in_pProgress
			) )
		{
			HContainerUtility::PopBack( out_arrayHull );
		}
	}

	return;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtility::CreateHullFromPointCloud( 
	PConvexHull& out_convexHull,
	const TArrayVector& in_pointCloud,
	PInterfaceProgress* const in_pProgress,
	const Hubris::HREAL in_pointCloudMergePercentage
	)
{
	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "CreateHullFromPointCloud" );
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return HFALSE;
		}
	}

	out_convexHull.Clear();

	//clean the input, attempt to remove co-incident data
	TArrayVector cleanPointCloud;
	LocalReducePointCloud( 
		cleanPointCloud,
		in_pointCloud,
		in_pointCloudMergePercentage
		);

	if( HNULL != in_pProgress )
	{
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return HFALSE;
		}
	}

	TArrayPlane planeArray;
	TArrayVector usedPoints;
	LocalMakePlaneArrayFromPointCloud(
		planeArray,
		usedPoints,
		cleanPointCloud.Begin(),
		cleanPointCloud.End(),
		in_pProgress
		);

	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "Hull Data Set planes:" +
			HTraitStringIn( planeArray.SizeGet() )
			);
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return HFALSE;
		}
	}

	out_convexHull.DataSet(
		planeArray
		);

	out_convexHull.PlaneRemoveUnused();

	return( 0 < out_convexHull.PlaneCountGet() );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtility::CreateProfileFromPointCloud2D( 
	TArraySint& out_arrayIndex,
	const TArrayVector2D& in_pointCloud,
	PInterfaceProgress* const in_pProgress
	)
{
	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "CreateHullFromPointCloud2D" );
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return HFALSE;
		}
	}

	TArrayPlaneR2 arrayPlanes;

	//make a plane for each dueo of points once
	for( HSINT indexOne = 0; indexOne < in_pointCloud.SizeGet(); ++indexOne )
	{
		for( HSINT indexTwo = indexOne + 1; indexTwo < in_pointCloud.SizeGet(); ++indexTwo )
		{
			LocalSubmitPlane(
				arrayPlanes,
				in_pointCloud,
				indexOne,
				indexTwo
				);
		}
	}

	LocalExtractIndexArrayFromPlanes(
		out_arrayIndex,
		arrayPlanes,
		in_pointCloud
		);

	return( 0 != arrayPlanes.SizeGet() );
}


/**/
HVOID PConvexHullGenerateUtility::ReduceHullCount( 
	TArrayHull& in_out_arrayHull, 
	const Hubris::HSINT in_maxHullCount = Hubris::HVariablesMath::MaximumGet< Hubris::HSINT >(),
	PInterfaceProgress* const in_pProgress
	)
{
	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "ReduceHullCount" );
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return;
		}
	}

	if( in_out_arrayHull.SizeGet() <= in_maxHullCount ) 
	{
		return;
	}

	TArrayHull arrayHull; 
	TArrayHull arrayHullReduce; 

	TArrayArraySint mergeList;
	TArraySphere arraySphere;

	for( HSINT index = 0; index < in_out_arrayHull.SizeGet(); ++index )
	{
		PConvexHull& hull = in_out_arrayHull[ index ];
		hull.PlaneRemoveUnused();
		if( HFALSE == PConvexHullUtility::EnclosedTest( hull ) )
		{
			if( 0 != hull.PlaneCountGet() )
			{
				arrayHull.Insert( hull );
			}
			continue;
		}

		const PBoundsR3 bounds = PConvexHullUtility::BoundsGet( hull );
		arrayHullReduce.Insert( hull );
		arraySphere.Insert( PSphereR3( bounds.RadiusGet(), bounds.CenterGet() ) );
	}

	in_out_arrayHull = arrayHull;

	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "ReduceSphereList" );
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return;
		}
	}

	PSphereUtility::SphereListReduce(
		mergeList,
		arraySphere,
		in_maxHullCount
	);

	//HCOMMON_FOR_EACH_CONST( merge, mergeList, TArrayArraySint )
	for( HSINT outerIndex = 0; outerIndex < mergeList.SizeGet(); ++outerIndex )
	{
		const TArraySint& merge = mergeList[ outerIndex ];
		TArrayVector pointCloud;
		for( HSINT index = 0; index < merge.SizeGet(); ++index )
		{
			const TArrayVector& hullPointCloud = arrayHullReduce[ merge[ index ] ].PointCloudGet();
			pointCloud.Insert( hullPointCloud.Begin(), hullPointCloud.End() );
		}

		in_out_arrayHull.SizeResize( in_out_arrayHull.SizeGet() + 1 );
		if( HFALSE == CreateHullFromPointCloud(
			HContainerUtility::Back( in_out_arrayHull ),
			pointCloud,
			in_pProgress
			) )
		{
			HContainerUtility::PopBack( in_out_arrayHull );
		}

		if( HNULL != in_pProgress )
		{
			in_pProgress->ProgressSet( "ReduceHullCount", HREAL( outerIndex ) / HREAL( mergeList.SizeGet() ) );
			if( HTRUE == in_pProgress->CancelGet() )
			{
				break;
			}
		}
	}

	HCOMMON_FOR_EACH( hull, in_out_arrayHull, TArrayHull )
	{
		hull.PlaneRemoveUnused();
	}

	return;
}

/**/
HVOID PConvexHullGenerateUtility::ReducePlaneMerge(
	PConvexHull& in_out_hull,
	const Hubris::HREAL in_mergeDirection,
	const Hubris::HREAL in_mergeLength,
	PInterfaceProgress* const in_pProgress
	)
{
	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "ReducePlaneMerge" );
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return;
		}
	}

	PConvexHull oldHull( in_out_hull );
	in_out_hull.Clear();

	for( HSINT index = 0; index < oldHull.PlaneCountGet(); ++index )
	{
		const PPlaneR3 plane = oldHull.PlaneGet( index );
		HBOOL add = HTRUE;
		for( HSINT planeIndex = 0; planeIndex < in_out_hull.PlaneCountGet(); ++planeIndex )
		{
			if( HTRUE == PPlaneUtility::EqualDelta(
				plane,
				in_out_hull.PlaneGet( planeIndex ),
				in_mergeDirection,
				in_mergeLength
				) )
			{
				add = HFALSE;
				break;
			}
		}

		if( HTRUE == add )
		{
			in_out_hull.PlaneAdd( plane );
		}

		if( HNULL != in_pProgress )
		{
			in_pProgress->ProgressSet( "ReducePlaneMerge", HREAL( index ) / HREAL( oldHull.PlaneCountGet() ) );
			if( HTRUE == in_pProgress->CancelGet() )
			{
				break;
			}
		}
	}

	return;
}

/**/
HVOID PConvexHullGenerateUtility::ReducePlaneCount(
	PConvexHull& in_out_hull,
	const Hubris::HSINT in_maxPlaneCount = Hubris::HVariablesMath::MaximumGet< Hubris::HSINT >(),
	PInterfaceProgress* const in_pProgress
	)
{
	if( HNULL != in_pProgress )
	{
		in_pProgress->ProgressTextSet( "ReducePlaneCount" );
		if( HTRUE == in_pProgress->CancelGet() )
		{
			return;
		}
	}

	in_out_hull.PlaneRemoveUnused();

	if( in_out_hull.PlaneCountGet() <= in_maxPlaneCount ) 
	{
		return;
	}

	PConvexHullGenerateUtilityPlaneReduce reduce(
		in_out_hull,
		in_maxPlaneCount
		);

	reduce.GatherHull( in_out_hull );

	in_out_hull.PlaneRemoveUnused();

	return;
}

/**/
