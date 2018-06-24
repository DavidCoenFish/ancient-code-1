//file: Pride/PConvexHull/PConvexHullImplementation.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHull/PConvexHullImplementation.h"

#include "Pride/PConvexHull/PConvexHullEdge.h"

#include "Pride/PLine/PLine_Export.h"
#include "Pride/PPlane/PPlane_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullImplementation::PConvexHullImplementation( const PConvexHullImplementation& in_src )
: m_arrayPlane()
, m_pEdge( HNULL )
{
	HCOMMON_NEW( m_pEdge, PConvexHullEdge );
	( *this ) = in_src;
	return;
}
/**/
PConvexHullImplementation::PConvexHullImplementation()
: m_arrayPlane()
, m_pEdge( HNULL )
{
	HCOMMON_NEW( m_pEdge, PConvexHullEdge );
	return;
}

/**/
PConvexHullImplementation::~PConvexHullImplementation()
{
	HCOMMON_DELETE( m_pEdge, PConvexHullEdge );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullImplementation& PConvexHullImplementation::operator=( const PConvexHullImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayPlane = in_rhs.m_arrayPlane;
		EdgeGet() = in_rhs.EdgeGet();
	}

	return( *this );
}

/**/
Hubris::HBOOL PConvexHullImplementation::operator==( const PConvexHullImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayPlane == in_rhs.m_arrayPlane );
		match &= ( EdgeGet() == in_rhs.EdgeGet() );
	}

	return match;
}

/**/
Hubris::HBOOL PConvexHullImplementation::operator!=( const PConvexHullImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PConvexHullImplementation::Clear()
{
	( *this ) = PConvexHullImplementation();
	return;
}

/**/
HVOID PConvexHullImplementation::DataSet(
	const TArrayPlane& in_arrayPlanes
	)
{
	m_arrayPlane = in_arrayPlanes;
	//EdgeGet().DataSet(
	//	m_arrayPlane
	//	);
	return;
}

/**/
HVOID PConvexHullImplementation::PlaneAdd( const PPlaneR3& in_plane )
{
	EdgeGet().DirtySet();
	m_arrayPlane.Insert( in_plane );
	return;
}

/**/
const Hubris::HSINT PConvexHullImplementation::PlaneCountGet()const
{
	return m_arrayPlane.SizeGet();
}

/**/
const PPlaneR3& PConvexHullImplementation::PlaneGet( const Hubris::HSINT in_index )const
{
	return m_arrayPlane[ in_index ];
}

/**/
HVOID PConvexHullImplementation::PlaneSet( const Hubris::HSINT in_index, const PPlaneR3& in_plane )
{
	EdgeGet().DirtySet();
	m_arrayPlane[ in_index ] = in_plane;
	return;
}

/**/
HVOID PConvexHullImplementation::PlaneRemove( const Hubris::HSINT in_index )
{
	EdgeGet().DirtySet();
	m_arrayPlane.Remove( m_arrayPlane.Begin() + in_index );
	return;
}

/**/
HVOID PConvexHullImplementation::PlaneRemoveUnused()
{
	TArrayPlane arrayNewPlane;
	HBOOL change = HFALSE;

	for( HSINT index = 0; index < m_arrayPlane.SizeGet(); ++index )
	{
		if( HFALSE == RefreashEdgeGet().PlaneUseQuery( index ) )
		{
			change = HTRUE;
			continue;
		}

		arrayNewPlane.Insert( m_arrayPlane[ index ] );
	}

	if( HFALSE == change )
	{
		return;
	}

	m_arrayPlane = arrayNewPlane;

	EdgeGet().DirtySet();

	return;
}


/**/
HVOID PConvexHullImplementation::PlaneLoopGather( 
	TArrayVector& out_arrayVector, 
	Hubris::HBOOL& out_closed,
	const Hubris::HSINT in_planeIndex
	)
{
	RefreashEdgeGet().PlaneLoopGather(
		out_arrayVector, 
		out_closed,
		in_planeIndex
		);

	return;
}

/**/
const PConvexHullImplementation::TArrayVector& PConvexHullImplementation::PointCloudGet()
{
	return RefreashEdgeGet().PointCloudGet();
}

/**/
Hubris::HVOID PConvexHullImplementation::PlaneArrayIndexTouchingGet(
	TArraySint& out_arrayIndexTouching,
	const Hubris::HSINT in_planeIndex
	)
{
	RefreashEdgeGet().PlaneArrayIndexTouchingGet(
		out_arrayIndexTouching,
		in_planeIndex
		);

	return;
}

/**/
const PConvexHullEdge& PConvexHullImplementation::RefreashEdgeGet()
{
	EdgeGet().Refreash( m_arrayPlane );
	return EdgeGet();
}

///////////////////////////////////////////////////////
// private methods
/**/
const PConvexHullEdge& PConvexHullImplementation::EdgeGet()const
{
	HCOMMON_ASSERT( HNULL != m_pEdge, "invalid data" );
	return( *m_pEdge );
}

/**/
PConvexHullEdge& PConvexHullImplementation::EdgeGet()
{
	HCOMMON_ASSERT( HNULL != m_pEdge, "invalid data" );
	return( *m_pEdge );
}

/**/
