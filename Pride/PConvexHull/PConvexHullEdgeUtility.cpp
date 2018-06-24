//file: Pride/PConvexHull/PConvexHullEdgeUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHull/PConvexHullEdgeUtility.h"

#include "Pride/PConvexHull/PConvexHullEdgeData.h"

#include "Pride/PConvexHullGenerate/PConvexHullGenerate_Export.h"
#include "Pride/PIntersection/PIntersection_Export.h"
#include "Pride/PPointCloud/PPointCloud_Export.h"
#include "Pride/PBounds/PBounds_Export.h"
#include "Pride/PLine/PLine_Export.h"
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
typedef Hubris::HContainerArray< PPlaneR3 >TArrayPlane;
typedef Hubris::HContainerArray< PConvexHullEdgeData >TArrayData;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerPair< Hubris::HVectorR3, Hubris::HVectorR3 >TPairVectorVector;
typedef Hubris::HContainerArray< TPairVectorVector >TArrayPairVectorVector;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVectorR2;


///////////////////////////////////////////////////////
// local static methods
/*
	return false if a line segment is on a test plane
*/
static const Hubris::HBOOL LocalTrimLine( PLineSegmentR3& in_out_lineSegment, const TArrayPlane& in_arrayPlane, const Hubris::HSINT in_indexOne, const Hubris::HSINT in_indexTwo )
{
	const HSINT planeCount = in_arrayPlane.SizeGet();
	for( HSINT index = 0; index < planeCount; ++index )
	{
		if( ( in_indexOne == index ) || ( in_indexTwo == index ) )
		{
			continue;
		}

		const PPlaneR3& plane = in_arrayPlane[ index ];

		if( HTRUE == PPlaneUtility::DirectionParallelToPlaneTest( plane, in_out_lineSegment.LineGet().DirectionGet() ) )
		{
			//hoy, if line is on or past plane, then entire line is invalid
			const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( plane, in_out_lineSegment.LineGet().OriginGet() );
			if( 0.00001F < distance )
			{
				return HFALSE;
			}

			continue;
		}

		PLineSegmentUtility::TrimLineSegment( in_out_lineSegment, plane );
	}

	//if we have bounds, but negative length or point, we bail
	// either end open is allowed, unbound plane?
	if( ( HTRUE == in_out_lineSegment.BoundsLowerValidGet() ) && ( HTRUE == in_out_lineSegment.BoundsUpperValidGet() ) )
	{
		const HREAL lowBound = in_out_lineSegment.BoundsLowerGet();
		const HREAL highBound = in_out_lineSegment.BoundsUpperGet();
		if( ( HTRUE == HMathUtility::EpsilonEqual( lowBound, highBound ) ) || 
			( highBound < lowBound ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
static Hubris::HVOID LocalExtractClosedLoop( TArrayVector& out_arrayVector, const TArrayPairVectorVector& in_arraySegments)
{
	if( in_arraySegments.SizeGet() <= 0 )
	{
		return;
	}

	TArrayPairVectorVector localArraySegments( in_arraySegments );
	HVectorR3 seedVector;

	{
		TPairVectorVector pairVectors = HContainerUtility::Back( localArraySegments );
		//seedVector = pairVectors.m_second;
		seedVector = pairVectors.m_first;

		//we dont add the first vector as is get added again latter
		HContainerUtility::PushBack( out_arrayVector, seedVector );

		HContainerUtility::PopBack( localArraySegments );
	}

	while( 0 != localArraySegments.SizeGet() )
	{
		HSINT bestMatchIndex = HCOMMON_INVALID_INDEX;
		HREAL bestDistanceSquared = HVariablesMath::MaximumGet< HREAL >();
		HVectorR3 nextSeed;

		for( HSINT index = 0; index < localArraySegments.SizeGet(); ++index )
		{
			const TPairVectorVector& pairSegment = localArraySegments[ index ];
			const HREAL testDistance = HMatrixUtility::LengthSquared( seedVector - pairSegment.m_second );
			if( testDistance < bestDistanceSquared )
			{
				bestMatchIndex = index;
				bestDistanceSquared = testDistance;
				nextSeed = pairSegment.m_first;
			}
		}

		HCOMMON_ASSERT( HCOMMON_INVALID_INDEX != bestMatchIndex, "invalid state" );
		localArraySegments.Remove( localArraySegments.Begin() + bestMatchIndex );
		seedVector = nextSeed;
		HContainerUtility::PushBack( out_arrayVector, seedVector );
	}

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
HVOID PConvexHullEdgeUtility::EdgeDataCreate( TArrayData& out_arrayEdgeData, const TArrayPlane& in_arrayPlane )
{
	out_arrayEdgeData.Clear();

	const HSINT planeCount = in_arrayPlane.SizeGet();
	for( HSINT outterIndex = 0; outterIndex < planeCount; ++outterIndex )
	{
		const PPlaneR3& outterPlane = in_arrayPlane[ outterIndex ];

		for( HSINT innerIndex = outterIndex + 1; innerIndex < planeCount; ++innerIndex )
		{
			if( outterIndex == innerIndex )
			{
				continue;
			}

			const PPlaneR3& innerPlane = in_arrayPlane[ innerIndex ];

			PLineR3 intersectionLine;
			if( HFALSE == PIntersectionUtility::PlanePlaneIntersect( intersectionLine, outterPlane, innerPlane ) )
			{
				continue;
			}

			PLineSegmentR3 lineSegment( intersectionLine );

			if( HFALSE == LocalTrimLine( lineSegment, in_arrayPlane, innerIndex, outterIndex ) )
			{
				continue;
			}

			out_arrayEdgeData.Insert( 
				PConvexHullEdgeData(
					lineSegment, 
					outterIndex,
					innerIndex
					)
				);
		}

	}

	return;
}

/**/
const Hubris::HBOOL PConvexHullEdgeUtility::EnclosedTest( const TArrayData& in_arrayEdgeData )
{
	//only enclosed if we have data
	HBOOL enclosed = HFALSE;

	HCOMMON_FOR_EACH_CONST( data, in_arrayEdgeData, TArrayData )
	{
		const PLineSegmentR3& lineSegment = data.LineSegmentGet();
		if( ( HTRUE == lineSegment.BoundsLowerValidGet() ) && 
			( HTRUE == lineSegment.BoundsUpperValidGet() ) )
		{
			enclosed = HTRUE;
		}
		else
		{
			return HFALSE;
		}
	}

	return enclosed;
}

/**/
HVOID PConvexHullEdgeUtility::PlaneLoopGather( 
	TArrayVector& out_arrayVector, 
	Hubris::HBOOL& out_closed,
	const TArrayData& in_arrayEdgeData, 
	const Hubris::HSINT in_planeIndex
	)
{
	TArrayPairVectorVector arraySegments;
	out_closed = HTRUE;
	out_arrayVector.Clear();

	//HBOOL clockwise = HFALSE;
	HCOMMON_FOR_EACH_CONST( data, in_arrayEdgeData, TArrayData )
	{
		if( ( in_planeIndex != data.PlaneIndexOneGet() ) && ( in_planeIndex != data.PlaneIndexTwoGet() ) )
		{
			continue;
		}

		const PLineSegmentR3& lineSegment = data.LineSegmentGet();

		HVectorR3 pointOne;
		HBOOL pointOneValid;
		HVectorR3 pointTwo;
		HBOOL pointTwoValid;
		PLineSegmentUtility::LineSegmentToPoints( pointOne, pointOneValid, pointTwo, pointTwoValid, lineSegment );

		if( ( HFALSE == pointOneValid ) || 
			( HFALSE == pointTwoValid ) )
		{
			out_closed = HFALSE;
			continue;
		}

		TPairVectorVector pairData;
		if( in_planeIndex == data.PlaneIndexOneGet() )
		{
			pairData.m_first = pointTwo;
			pairData.m_second = pointOne;
		}
		else
		{
			pairData.m_first = pointOne;
			pairData.m_second = pointTwo;
		}

		HContainerUtility::PushBack( arraySegments, pairData );
	}

	LocalExtractClosedLoop( out_arrayVector, arraySegments );

	return;
}

/**/
HVOID PConvexHullEdgeUtility::PlaneArrayIndexTouchingGet(
	TArraySint& out_arrayIndexTouching,
	const TArrayData& in_arrayEdgeData, 
	const Hubris::HSINT in_planeIndex
	)
{
	out_arrayIndexTouching.Clear();
	HCOMMON_FOR_EACH_CONST( data, in_arrayEdgeData, TArrayData )
	{
		if( ( in_planeIndex != data.PlaneIndexOneGet() ) && ( in_planeIndex != data.PlaneIndexTwoGet() ) )
		{
			continue;
		}

		const PLineSegmentR3& lineSegment = data.LineSegmentGet();
		if( ( HFALSE == lineSegment.BoundsUpperValidGet() ) ||
			( HFALSE == lineSegment.BoundsLowerValidGet() ) )
		{
			continue;
		}

		if( data.PlaneIndexOneGet() != in_planeIndex )
		{
			HContainerUtility::PushBack( out_arrayIndexTouching, data.PlaneIndexOneGet() );
		}
		else
		{
			HContainerUtility::PushBack( out_arrayIndexTouching, data.PlaneIndexTwoGet() );
		}

	}
	return;
}

/**/
HVOID PConvexHullEdgeUtility::VertexGather( const TArrayData& in_arrayEdgeData, TArrayVector& out_arrayVector, const Hubris::HREAL in_threashold )
{
	out_arrayVector.Clear();
	PBoundsR3 bounds;

	HCOMMON_FOR_EACH_CONST( data, in_arrayEdgeData, TArrayData )
	{
		const PLineSegmentR3& lineSegment = data.LineSegmentGet();

		HVectorR3 pointOne;
		HBOOL pointOneValid;
		HVectorR3 pointTwo;
		HBOOL pointTwoValid;
		PLineSegmentUtility::LineSegmentToPoints( pointOne, pointOneValid, pointTwo, pointTwoValid, lineSegment );

		if( HTRUE == pointOneValid )
		{
			out_arrayVector.Insert( pointOne );
			bounds.InsertPoint( pointOne );
		}
		if( HTRUE == pointTwoValid )
		{
			out_arrayVector.Insert( pointTwo );
			bounds.InsertPoint( pointTwo );
		}
	}

	if( HFALSE == bounds.ValidGet() )
	{
		return;
	}

	PPointCloudR3 pointCloud;

	pointCloud.ArrayPointMerge( out_arrayVector, PPointCloudR3::ThreasholdCreate( out_arrayVector, in_threashold ) );

	out_arrayVector = pointCloud.ArrayPointsGet();

	return;
}

/**/