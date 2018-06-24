//file: Pride/PLine/PLineSegmentUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLine/PLineSegmentUtility.h"

#include "Pride/PLine/PLineSegment.h"
#include "Pride/PLine/PLineUtility.h"

#include "Pride/PIntersection/PIntersection_Export.h"
#include "Pride/PUnitVector/PUnitVector_Export.h"
#include "Pride/PPlane/PPlane_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HBOOL PLineSegmentUtility::TrimLineSegment( PLineSegmentR2& in_out_lineSegment, const PPlaneR2& in_plane )
{
	HREAL ratioOnLine;
	const HVectorR2 intersectPoint;
	if( HFALSE == PIntersectionUtility::PlaneLineIntersect( 
			ratioOnLine, 
			in_plane,
			in_out_lineSegment.LineGet()
			) )
	{
		return HFALSE;
	}

	const HREAL dotResult = HMatrixUtility::DotProduct( in_out_lineSegment.LineGet().DirectionGet().VectorGet(), in_plane.DirectionGet().VectorGet() );
	if( 0 <= dotResult )
	{
		if( ( HFALSE == in_out_lineSegment.BoundsUpperValidGet() ) || 
			( ratioOnLine < in_out_lineSegment.BoundsUpperGet() ) )
		{
			in_out_lineSegment.BoundsUpperSet( ratioOnLine );
		}
	}
	else
	{
		if( ( HFALSE == in_out_lineSegment.BoundsLowerValidGet() ) || 
			( in_out_lineSegment.BoundsLowerGet() < ratioOnLine ) )
		{
			in_out_lineSegment.BoundsLowerSet( ratioOnLine );
		}
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL PLineSegmentUtility::TrimLineSegment( PLineSegmentR3& in_out_lineSegment, const PPlaneR3& in_plane )
{
	HREAL ratioOnLine;
	const HVectorR3 intersectPoint;
	if( HFALSE == PIntersectionUtility::PlaneLineIntersect( 
			ratioOnLine, 
			in_plane,
			in_out_lineSegment.LineGet()
			) )
	{
		return HFALSE;
	}

	const HREAL dotResult = HMatrixUtility::DotProduct( in_out_lineSegment.LineGet().DirectionGet().VectorGet(), in_plane.DirectionGet().VectorGet() );
	if( 0 <= dotResult )
	{
		if( ( HFALSE == in_out_lineSegment.BoundsUpperValidGet() ) || 
			( ratioOnLine < in_out_lineSegment.BoundsUpperGet() ) )
		{
			in_out_lineSegment.BoundsUpperSet( ratioOnLine );
		}
	}
	else
	{
		if( ( HFALSE == in_out_lineSegment.BoundsLowerValidGet() ) || 
			( in_out_lineSegment.BoundsLowerGet() < ratioOnLine ) )
		{
			in_out_lineSegment.BoundsLowerSet( ratioOnLine );
		}
	}

	return HTRUE;
}

/**/
HVOID PLineSegmentUtility::LineSegmentToPoints(
	Hubris::HVectorR2& out_lowPoint,
	Hubris::HBOOL& out_lowPointValid,
	Hubris::HVectorR2& out_highPoint,
	Hubris::HBOOL& out_highPointValid,
	const PLineSegmentR2& in_lineSegment
	)
{
	out_lowPointValid = in_lineSegment.BoundsLowerValidGet();
	if( HTRUE == out_lowPointValid )
	{
		out_lowPoint = PLineUtility::LinePointGet( in_lineSegment.LineGet(), in_lineSegment.BoundsLowerGet() );
	}

	out_highPointValid = in_lineSegment.BoundsUpperValidGet();
	if( HTRUE == out_highPointValid )
	{
		out_highPoint = PLineUtility::LinePointGet( in_lineSegment.LineGet(), in_lineSegment.BoundsUpperGet() );
	}

	return;
}

/**/
HVOID PLineSegmentUtility::LineSegmentToPoints(
	Hubris::HVectorR3& out_lowPoint,
	Hubris::HBOOL& out_lowPointValid,
	Hubris::HVectorR3& out_highPoint,
	Hubris::HBOOL& out_highPointValid,
	const PLineSegmentR3& in_lineSegment
	)
{
	out_lowPointValid = in_lineSegment.BoundsLowerValidGet();
	if( HTRUE == out_lowPointValid )
	{
		out_lowPoint = PLineUtility::LinePointGet( in_lineSegment.LineGet(), in_lineSegment.BoundsLowerGet() );
	}

	out_highPointValid = in_lineSegment.BoundsUpperValidGet();
	if( HTRUE == out_highPointValid )
	{
		out_highPoint = PLineUtility::LinePointGet( in_lineSegment.LineGet(), in_lineSegment.BoundsUpperGet() );
	}

	return;
}

/**/
const Hubris::HBOOL PLineSegmentUtility::LineSegmentFromPoints(
	PLineSegmentR3& out_lineSegment,
	const Hubris::HVectorR3& in_lowPoint,
	const Hubris::HVectorR3& in_highPoint
	)
{
	HVectorR3 normal = ( in_highPoint - in_lowPoint );
	const HREAL length = HMatrixUtility::Length( normal );
	if( HMathUtility::EpsilonZero( length ) )
	{
		return HFALSE;
	}

	normal *= ( 1.0F / length );

	out_lineSegment = PLineSegmentR3( PLineR3( in_lowPoint, PUnitVectorR3( normal ) ) );
	out_lineSegment.BoundsLowerSet( 0.0F );
	out_lineSegment.BoundsUpperSet( length );

	return HTRUE;
}

/**/
