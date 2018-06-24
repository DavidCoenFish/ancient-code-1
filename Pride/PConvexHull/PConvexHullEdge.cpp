//file: Pride/PConvexHull/PConvexHullEdge.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHull/PConvexHullEdge.h"

#include "Pride/PConvexHull/PConvexHullEdgeUtility.h"
#include "Pride/PIntersection/PIntersection_Export.h"

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
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

///////////////////////////////////////////////////////
// local static methods

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullEdge::PConvexHullEdge( const PConvexHullEdge& in_src )
: m_pointCloud()
, m_arrayData()
//, m_arrayUsedPlaneIndex()
, m_enclosed( HFALSE )
, m_dirty( HTRUE )
{
	( *this ) = in_src;
	return;
}
/**/
PConvexHullEdge::PConvexHullEdge()
: m_pointCloud()
, m_arrayData()
//, m_arrayUsedPlaneIndex()
, m_enclosed( HFALSE )
, m_dirty( HTRUE )
{
	return;
}

/**/
PConvexHullEdge::~PConvexHullEdge()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullEdge& PConvexHullEdge::operator=( const PConvexHullEdge& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_pointCloud = in_rhs.m_pointCloud;
		m_arrayData = in_rhs.m_arrayData;
		m_enclosed = in_rhs.m_enclosed;
		m_dirty = in_rhs.m_dirty;
	}

	return( *this );
}

/**/
Hubris::HBOOL PConvexHullEdge::operator==( const PConvexHullEdge& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_pointCloud == in_rhs.m_pointCloud );
		match &= ( m_arrayData == in_rhs.m_arrayData );
		match &= ( m_enclosed == in_rhs.m_enclosed );
		match &= ( m_dirty == in_rhs.m_dirty );
	}

	return match;
}

/**/
Hubris::HBOOL PConvexHullEdge::operator!=( const PConvexHullEdge& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PConvexHullEdge::DataSet( 
	const TArrayPlane& in_arrayPlanes
	)
{
	( *this ) = PConvexHullEdge();
	m_dirty = HTRUE;

	Refreash( in_arrayPlanes );

	return;
}

/**/
HVOID PConvexHullEdge::Refreash( 
	const TArrayPlane& in_arrayPlanes
	)
{
	if( HTRUE == m_dirty )
	{
		m_arrayData.Clear();

		PConvexHullEdgeUtility::EdgeDataCreate( m_arrayData, in_arrayPlanes );

		m_enclosed = PConvexHullEdgeUtility::EnclosedTest( m_arrayData );

		PConvexHullEdgeUtility::VertexGather( m_arrayData, m_pointCloud, 0.001F );

		m_dirty = HFALSE;
	}

	return;
}

/**/
const Hubris::HBOOL PConvexHullEdge::PlaneUseQuery( 
	const Hubris::HSINT in_planeIndex
	)const
{
	HCOMMON_ASSERT( HFALSE == m_dirty, "invalid state" );

	HCOMMON_FOR_EACH_CONST( data, m_arrayData, TArrayData )
	{
		if( ( in_planeIndex == data.PlaneIndexOneGet() ) ||
			( in_planeIndex == data.PlaneIndexTwoGet() ) )
		{
			return HTRUE;
		}
	}

	return HFALSE;
}

/**/
HVOID PConvexHullEdge::PlaneLoopGather( 
	TArrayVector& out_arrayVector, 
	Hubris::HBOOL& out_closed, 
	const Hubris::HSINT in_planeIndex
	)const
{
	HCOMMON_ASSERT( HFALSE == m_dirty, "invalid state" );
	PConvexHullEdgeUtility::PlaneLoopGather( 
		out_arrayVector,
		out_closed,
		m_arrayData,
		in_planeIndex
		);

	return;
}

/**/
Hubris::HVOID PConvexHullEdge::PlaneArrayIndexTouchingGet(
	TArraySint& out_arrayIndexTouching,
	const Hubris::HSINT in_planeIndex
	)const
{
	HCOMMON_ASSERT( HFALSE == m_dirty, "invalid state" );
	PConvexHullEdgeUtility::PlaneArrayIndexTouchingGet( 
		out_arrayIndexTouching,
		m_arrayData,
		in_planeIndex
		);

	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HBOOL PConvexHullEdge::EnclosedGet()const
{
	HCOMMON_ASSERT( HFALSE == m_dirty, "invalid state" );
	return m_enclosed;
}

/**/
const TArrayVector& PConvexHullEdge::PointCloudGet()const
{
	HCOMMON_ASSERT( HFALSE == m_dirty, "invalid state" );
	return m_pointCloud;
}

/**/
