//file: Pride/PConvexHull/PConvexHull.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHull/PConvexHull.h"

#include "Pride/PConvexHull/PConvexHullImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PConvexHull::PConvexHull( const PConvexHull& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PConvexHullImplementation, in_src.ImplementationGet() );
	return;
}

/**/
PConvexHull::PConvexHull()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, PConvexHullImplementation );
	return;
}

/**/
PConvexHull::~PConvexHull()
{
	HCOMMON_DELETE( m_pImplementation, PConvexHullImplementation );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHull& PConvexHull::operator=( const PConvexHull& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
Hubris::HBOOL PConvexHull::operator==( const PConvexHull& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL PConvexHull::operator!=( const PConvexHull& in_rhs )const
{
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PConvexHull::Clear()
{
	ImplementationGet().Clear();
	return;
}

/**/
HVOID PConvexHull::DataSet(
	const TArrayPlane& in_arrayPlanes
	)
{
	ImplementationGet().DataSet( 
		in_arrayPlanes
		);
	return;
}


/**/
HVOID PConvexHull::PlaneAdd( const PPlaneR3& in_plane )
{
	ImplementationGet().PlaneAdd( in_plane );
	return;
}

/**/
const Hubris::HSINT PConvexHull::PlaneCountGet()const
{
	return ImplementationGet().PlaneCountGet();
}

/**/
const PPlaneR3& PConvexHull::PlaneGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().PlaneGet( in_index );
}

/**/
HVOID PConvexHull::PlaneSet( const Hubris::HSINT in_index, const PPlaneR3& in_plane )
{
	return ImplementationGet().PlaneSet( in_index, in_plane );
}

/**/
HVOID PConvexHull::PlaneRemove( const Hubris::HSINT in_index )
{
	ImplementationGet().PlaneRemove( in_index );
	return;
}

/**/
HVOID PConvexHull::PlaneRemoveUnused()
{
	ImplementationGet().PlaneRemoveUnused();
	return;
}

/**/
const PConvexHull::TArrayVector& PConvexHull::PointCloudGet()
{
	return ImplementationGet().PointCloudGet();
}

/**/
Hubris::HVOID PConvexHull::PlaneArrayIndexTouchingGet(
	TArraySint& out_arrayIndexTouching,
	const Hubris::HSINT in_planeIndex
	)
{
	ImplementationGet().PlaneArrayIndexTouchingGet(
		out_arrayIndexTouching,
		in_planeIndex
		);
	return;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const PConvexHullImplementation& PConvexHull::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
PConvexHullImplementation& PConvexHull::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/