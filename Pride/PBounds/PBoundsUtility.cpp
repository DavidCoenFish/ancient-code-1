//file: Pride/PBounds/PBoundsUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PBounds/PBoundsUtility.h"

#include "Pride/PBounds/PBounds.h"

#include "Pride/PLine/PLine_Export.h"
#include "Pride/PPlane/PPlane_Export.h"

#include "Pride/PIntersection/PIntersection_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HBOOL PBoundsUtility::IntersectLine( 
	const PBoundsR3& in_bounds,
	const PLineR3& in_line,
	Hubris::HREAL* const out_pRatioOnLineNear, 
	Hubris::HVectorR3* const our_pSurfaceNormalNear
	)
{
	HBOOL negative = HFALSE;
	const HSINT startAxis = HMatrixUtility::AxisFindLargestAbsoluteSigned( in_line.DirectionGet().VectorGet(), negative );

	for( HSINT index = 0; index < 3; ++index )
	{
		const HSINT axis = ( startAxis + index ) % 3;
		negative = ( in_line.DirectionGet().VectorGet()[ axis ] < 0.0F );
		//make a plane
		PPlaneR3 plane;
		HVectorR3 normal;
		if( HTRUE == negative )
		{
			normal[ axis ] = 1.0F;
			plane.DistanceSet( in_bounds.VectorMaximumGet()[ axis ] );
		}
		else
		{
			normal[ axis ] = -1.0F;
			plane.DistanceSet( in_bounds.VectorMinimumGet()[ axis ] );
		}
		plane.DirectionSet( PUnitVectorR3( normal ) );

		//intersect with plane
		HREAL ratioOnLine = 0.0F;
		if( HFALSE == PIntersectionUtility::PlaneLineIntersect( 
			ratioOnLine, 
			plane, 
			in_line ) )
		{
			continue;
		}

		const HVectorR3 position = PLineUtility::LinePointGet( 
			in_line, 
			ratioOnLine
			);

		if( HFALSE == PBoundsUtility::PointInsideTest(
			in_bounds,
			position
			) )
		{
			continue;
		}

		if( HNULL != out_pRatioOnLineNear )
		{
			( *out_pRatioOnLineNear ) = ratioOnLine;
		}

		if( HNULL != our_pSurfaceNormalNear )
		{
			( *our_pSurfaceNormalNear ) = normal;
		}

		return HTRUE;
	}

	return HFALSE;
}

/**/
const Hubris::HBOOL PBoundsUtility::PointInsideTest(
	const PBoundsR3& in_bounds,
	const Hubris::HVectorR3& in_point
	)
{
	if( HFALSE == in_bounds.ValidGet() )
	{
		return HFALSE;
	}

	const HVectorR3& minimumBound = in_bounds.VectorMinimumGet();
	const HVectorR3& maximumBound = in_bounds.VectorMaximumGet();

	for( HSINT index = 0; index < 3; ++index )
	{
		const HREAL testValue = in_point[ index ];
		if( ( testValue < minimumBound[ index ] ) ||
			( maximumBound[ index ] < testValue ) )
		{
			//point is outside bounds
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
