//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceData.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceData.h"

#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtility.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceLine.h"

#include "Pride/PIntersection/PIntersection_Export.h"
#include "Pride/PLine/PLine_Export.h"
#include "Pride/PPlane/PPlane_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMath/HMath_Export.h >
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
typedef Hubris::HContainerArray< HVectorR2 >TArrayVector2D;
typedef Hubris::HContainerArray< HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< PPlaneR3 >TArrayPlane;
typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceData >TArrayData;
typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceLine >TArrayLine;

///////////////////////////////////////////////////////
// static local methods
/**/
static HBOOL LocalPlaneAreaGet(
	HREAL& out_faceArea,
	const TArrayLine& in_arrayLine,
	const TArraySint& in_arrayLineIndex,
	const PPlaneR3& in_plane
	) 
{
	TArrayVector arrayPoints3d;
	HCOMMON_FOR_EACH_CONST( index, in_arrayLineIndex, TArraySint )
	{
		const PConvexHullGenerateUtilityPlaneReduceLine& line = in_arrayLine[ index ];

		HBOOL lowValid = HTRUE;
		HVectorR3 lowPoint;
		HBOOL highValid = HTRUE;
		HVectorR3 highPoint;

		PLineSegmentUtility::LineSegmentToPoints( lowPoint, lowValid, highPoint, highValid, line.LineSegmentGet() );

		if( ( HFALSE == lowValid ) ||
			( HFALSE == highValid ) )
		{
			return HFALSE;
		}

		arrayPoints3d.Insert( lowPoint );
		arrayPoints3d.Insert( highPoint );
	}

	TArrayVector2D arrayPoints2d;
	PPlaneUtility::ProjectOntoPlane(
		arrayPoints2d,
		arrayPoints3d,
		in_plane
		);

	TArraySint arrayIndex;

	if( HFALSE == PConvexHullGenerateUtility::CreateProfileFromPointCloud2D( 
		arrayIndex,
		arrayPoints2d ) )
	{
		return HFALSE;
	}

	TArrayVector2D edgeLoop;
	HCOMMON_FOR_EACH_CONST( index, arrayIndex, TArraySint )
	{
		HContainerUtility::PushBack( edgeLoop, arrayPoints2d[ index ] );
	}

	out_faceArea = HMathArea::AreaClosedLoop( edgeLoop );

	return HTRUE;
}

/**/
static const HBOOL LocalMaxHeightGet(
	HREAL& out_height,
	const TArrayPlane& in_arrayPlane,
	const PPlaneR3& in_plane
	)
{
	HBOOL found = HFALSE;
	out_height = 0.0F; //doh, arbitary large nb, can't use ::s_max as still used in calc
	const PPlaneR3 flipBase = PPlaneUtility::PlaneFlip( in_plane );

	//make a line between each plane and trim line
	for( HSINT indexOne = 0; indexOne < in_arrayPlane.SizeGet(); ++indexOne )
	{
		for( HSINT indexTwo = indexOne + 1; indexTwo < in_arrayPlane.SizeGet(); ++indexTwo )
		{
			PLineR3 intersectionLine;
			if( HFALSE == PIntersectionUtility::PlanePlaneIntersect( 
				intersectionLine, 
				in_arrayPlane[ indexOne ], 
				in_arrayPlane[ indexTwo ]
				) )
			{
				//fail case of line intersection is planes parrallel, if we hit that, we could have zero height
				//return HVariablesMath::ZeroGet< HREAL >();
				//not all planes need to intersect
				continue;
			}

			PLineSegmentR3 lineSegment( intersectionLine );
			for( HSINT indexThree = 0; indexThree < in_arrayPlane.SizeGet(); ++indexThree )
			{
				if( ( indexThree == indexOne ) ||
					( indexThree == indexTwo ) )
				{
					continue;
				}

				PLineSegmentUtility::TrimLineSegment( lineSegment, in_arrayPlane[ indexThree ] );
			}

			PLineSegmentUtility::TrimLineSegment( lineSegment, flipBase );

			if( ( HFALSE == lineSegment.BoundsLowerValidGet() ) ||
				( HFALSE == lineSegment.BoundsUpperValidGet() ) )
			{
				//change to continue rather than return false, unbound segements are possible
				continue;
			}

			// attempt at catching SMALL hieght that may not pass following upper < lower
			if( HMathUtility::Absolute( lineSegment.BoundsUpperGet() - lineSegment.BoundsLowerGet() ) < 0.001F )
			{
				out_height = 0.00001F;
				return HTRUE;
			}

			if( lineSegment.BoundsUpperGet() < lineSegment.BoundsLowerGet() )
			{
				continue;
			}

			HVectorR3 lowPoint;
			HBOOL lowPointValid = HTRUE;
			HVectorR3 highPoint;
			HBOOL highPointValid = HTRUE;
			PLineSegmentUtility::LineSegmentToPoints(
				lowPoint,
				lowPointValid,
				highPoint,
				highPointValid,
				lineSegment
				);

			const HREAL testDistanceLow = PPlaneUtility::DistanceFromPlaneGet( in_plane, lowPoint );
			const HREAL testDistanceHigh = PPlaneUtility::DistanceFromPlaneGet( in_plane, highPoint );

			out_height = HMathUtility::Maximum( out_height, testDistanceLow );
			out_height = HMathUtility::Maximum( out_height, testDistanceHigh );
			found = HTRUE;
		}
	}

	return found;
}

/**/
/**/
static const HBOOL LocalMaxHeightRemovedVolume(
	HREAL& out_height,
	const HSINT in_ourIndex,
	const PPlaneR3& in_plane,
	const TArraySint& in_arrayLineIndex,
	const TArrayLine& in_arrayLine,
	const TArrayData& in_arrayData
	) 
{
	out_height = HVariablesMath::ZeroGet< HREAL >();
	TArraySint arrayTouchingPlaneIndex;
	HCOMMON_FOR_EACH_CONST( lineIndex, in_arrayLineIndex, TArraySint )
	{
		const PConvexHullGenerateUtilityPlaneReduceLine& line = in_arrayLine[ lineIndex ];
		if( in_ourIndex != line.PlaneIndexOneGet() )
		{
			arrayTouchingPlaneIndex.Insert( line.PlaneIndexOneGet() );
		}
		else if( in_ourIndex != line.PlaneIndexTwoGet() )
		{
			arrayTouchingPlaneIndex.Insert( line.PlaneIndexTwoGet() );
		}
	}

	TArrayPlane arrayPlane;
	HCOMMON_FOR_EACH_CONST( planeIndex, arrayTouchingPlaneIndex, TArraySint )
	{
		arrayPlane.Insert( in_arrayData[ planeIndex ].PlaneGet() );
	}

	//we Could constuct a hull and get the hull area at this stage, BTW, for now approximate
	//arrayPlane.Insert( PPlaneUtility::PlaneFlip( in_plane ) );

	if( HFALSE == LocalMaxHeightGet(
		out_height,
		arrayPlane,
		in_plane
		) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**
static Hubris::HVOID LocalTrimOtherPlanes(
	PLineSegmentR3& in_out_lineSegment,
	const TArrayLine& in_arrayLine,
	const TArrayData& in_arrayData,
	const Hubris::HSINT in_ourIndex,
	const TArraySint& in_arrayLineIndex
	)
{
	//go through the array of lines this plane uses
	HCOMMON_FOR_EACH_CONST( index, in_arrayLineIndex, TArraySint )
	{
		const PConvexHullGenerateUtilityPlaneReduceLine& line = in_arrayLine[ index ];
	
		HSINT otherIndex = HCOMMON_INVALID_INDEX;
		if( in_ourIndex == line.PlaneIndexOneGet() )
		{
			otherIndex = line.PlaneIndexTwoGet();
		}
		if( in_ourIndex == line.PlaneIndexTwoGet() )
		{
			otherIndex = line.PlaneIndexOneGet();
		}

		if( HCOMMON_INVALID_INDEX == otherIndex )
		{
			continue;
		}

		const PConvexHullGenerateUtilityPlaneReduceData& data = in_arrayData[ otherIndex ];

		HCOMMON_ASSERT( HTRUE == data.PlaneInUseGet(), "invalid state" );

		PLineSegmentUtility::TrimLineSegment(
			in_out_lineSegment,
			data.PlaneGet()
			);
	}

	return;
}


///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityPlaneReduceData::PConvexHullGenerateUtilityPlaneReduceData( const PConvexHullGenerateUtilityPlaneReduceData& in_src )
: m_plane()
, m_planeInUse( HTRUE )
, m_arrayLineIndex()
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullGenerateUtilityPlaneReduceData::PConvexHullGenerateUtilityPlaneReduceData(
	const PPlaneR3& in_plane
	)
: m_plane( in_plane )
, m_planeInUse( HTRUE )
, m_arrayLineIndex()
{
	return;
}

/**/
PConvexHullGenerateUtilityPlaneReduceData::PConvexHullGenerateUtilityPlaneReduceData()
: m_plane()
, m_planeInUse( HTRUE )
, m_arrayLineIndex()
{
	return;
}

/**/
PConvexHullGenerateUtilityPlaneReduceData::~PConvexHullGenerateUtilityPlaneReduceData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilityPlaneReduceData& PConvexHullGenerateUtilityPlaneReduceData::operator=( const PConvexHullGenerateUtilityPlaneReduceData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_plane = in_rhs.m_plane;
		m_planeInUse = in_rhs.m_planeInUse;
		m_arrayLineIndex = in_rhs.m_arrayLineIndex;
	}

	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityPlaneReduceData::operator==( const PConvexHullGenerateUtilityPlaneReduceData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_plane == in_rhs.m_plane );
		match &= ( m_planeInUse == in_rhs.m_planeInUse );
		match &= ( m_arrayLineIndex == in_rhs.m_arrayLineIndex );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityPlaneReduceData::operator!=( const PConvexHullGenerateUtilityPlaneReduceData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/*
	put up a line from cenerter of plane face perpendicular to plane,
	use cone volume for approx of volume gain be plane removal
*/
const Hubris::HREAL PConvexHullGenerateUtilityPlaneReduceData::CalculateRemovedVolume( 
	const TArrayLine& in_arrayLine,
	const TArrayData& in_arrayData,
	const Hubris::HSINT in_ourIndex  
	)const
{
	HREAL faceArea = HVariablesMath::ZeroGet< HREAL >();

	if( HFALSE == LocalPlaneAreaGet(
		faceArea,
		in_arrayLine,
		m_arrayLineIndex,
		m_plane
		) )
	{
		return HVariablesMath::MaximumGet< HREAL >();
	}

	//want area of plane face if enclosed
	//
	HREAL height = HVariablesMath::ZeroGet< HREAL >();
	if( HFALSE == LocalMaxHeightRemovedVolume(
		height,
		in_ourIndex,
		m_plane,
		m_arrayLineIndex,
		in_arrayLine,
		in_arrayData
		) )
	{
		return HVariablesMath::MaximumGet< HREAL >();
	}

	//get volume on trimmed line height
	const HREAL removedVolume = faceArea * height / 3.0F;

	return removedVolume;
}

/**/
HVOID PConvexHullGenerateUtilityPlaneReduceData::ArrayLineIndexClear()
{
	m_arrayLineIndex.Clear();
	return;
}

/**/
HVOID PConvexHullGenerateUtilityPlaneReduceData::ArrayLineIndexAdd( const Hubris::HSINT in_lineIndex )
{
	m_arrayLineIndex.Insert( in_lineIndex );
}

/**/