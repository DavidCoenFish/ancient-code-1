//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceLine.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceLine.h"

#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceData.h"

#include "Pride/PLine/PLine_Export.h"
#include "Pride/PPlane/PPlane_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceData >TArrayData;

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityPlaneReduceLine::PConvexHullGenerateUtilityPlaneReduceLine( const PConvexHullGenerateUtilityPlaneReduceLine& in_src )
: m_lineSegment()
, m_planeIndexOne( HCOMMON_INVALID_INDEX )
, m_planeIndexTwo( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullGenerateUtilityPlaneReduceLine::PConvexHullGenerateUtilityPlaneReduceLine(
	PLineR3& in_line,
	const Hubris::HSINT in_planeIndexOne,
	const Hubris::HSINT in_planeIndexTwo
	)
: m_lineSegment( in_line )
, m_planeIndexOne( in_planeIndexOne )
, m_planeIndexTwo( in_planeIndexTwo )
{
	return;
}

/**/
PConvexHullGenerateUtilityPlaneReduceLine::PConvexHullGenerateUtilityPlaneReduceLine()
: m_lineSegment()
, m_planeIndexOne( HCOMMON_INVALID_INDEX )
, m_planeIndexTwo( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
PConvexHullGenerateUtilityPlaneReduceLine::~PConvexHullGenerateUtilityPlaneReduceLine()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilityPlaneReduceLine& PConvexHullGenerateUtilityPlaneReduceLine::operator=( const PConvexHullGenerateUtilityPlaneReduceLine& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_lineSegment = in_rhs.m_lineSegment;
		m_planeIndexOne = in_rhs.m_planeIndexOne;
		m_planeIndexTwo = in_rhs.m_planeIndexTwo;
	}
	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityPlaneReduceLine::operator==( const PConvexHullGenerateUtilityPlaneReduceLine& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_lineSegment == in_rhs.m_lineSegment );
		match &= ( m_planeIndexOne == in_rhs.m_planeIndexOne );
		match &= ( m_planeIndexTwo == in_rhs.m_planeIndexTwo );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityPlaneReduceLine::operator!=( const PConvexHullGenerateUtilityPlaneReduceLine& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL PConvexHullGenerateUtilityPlaneReduceLine::TrimSegmentAgainstPlanes(
	const TArrayData& in_arrayData
	)
{
	m_lineSegment.BoundsLowerValidClear();
	m_lineSegment.BoundsLowerValidClear();

	//plane must be in use 
	for( HSINT index = 0; index < in_arrayData.SizeGet(); ++index )
	{
		const PConvexHullGenerateUtilityPlaneReduceData& data = in_arrayData[ index ];

		if( HFALSE == data.PlaneInUseGet() )
		{
			continue;
		}

		if( ( m_planeIndexOne == index ) ||
			( m_planeIndexTwo == index ) )
		{
			continue;
		}

		if( HFALSE == PLineSegmentUtility::TrimLineSegment( m_lineSegment, data.PlaneGet() ) )
		{
			//deal with lin parrallel to plane case
			const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( data.PlaneGet(), m_lineSegment.LineGet().OriginGet() );
			if( 0.00001F < distance )
			{
				//line is parrallel and outside plane
				return HFALSE;
			}
		}

		//bail on zero length line
		if( ( HTRUE == m_lineSegment.BoundsLowerValidGet() ) &&
			( HTRUE == m_lineSegment.BoundsUpperValidGet() ) )
		{
			if( m_lineSegment.BoundsUpperGet() < m_lineSegment.BoundsLowerGet() )
			{
				return HFALSE;
			}
		}
	}

	return HTRUE;
}

/**/
