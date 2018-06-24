//file: Pride/PConvexHull/PConvexHullEdgeData.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHull/PConvexHullEdgeData.h"

#include "Pride/PLine/PLine_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullEdgeData::PConvexHullEdgeData( const PConvexHullEdgeData& in_src )
: m_lineSegment()
, m_planeIndexOne( HCOMMON_INVALID_INDEX )
, m_planeIndexTwo( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullEdgeData::PConvexHullEdgeData( 
	const PLineSegmentR3& m_lineSegment, 
	const Hubris::HSINT in_indexOne, 
	const Hubris::HSINT in_indexTwo 
	)
: m_lineSegment( m_lineSegment )
, m_planeIndexOne( in_indexOne )
, m_planeIndexTwo( in_indexTwo )
{
	return;
}

/**/
PConvexHullEdgeData::PConvexHullEdgeData()
: m_lineSegment()
, m_planeIndexOne( HCOMMON_INVALID_INDEX )
, m_planeIndexTwo( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
PConvexHullEdgeData::~PConvexHullEdgeData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullEdgeData& PConvexHullEdgeData::operator=( const PConvexHullEdgeData& in_rhs )
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
Hubris::HBOOL PConvexHullEdgeData::operator==( const PConvexHullEdgeData& in_rhs )const
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
Hubris::HBOOL PConvexHullEdgeData::operator!=( const PConvexHullEdgeData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/