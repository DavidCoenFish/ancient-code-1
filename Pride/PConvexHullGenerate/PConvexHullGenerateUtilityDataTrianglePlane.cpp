//file: PConvexHullGenerate/PConvexHullGenerateUtilityDataTrianglePlane.cpp

#include "PridePreCompileHeader.h"
#include "PConvexHullGenerate/PConvexHullGenerateUtilityDataTrianglePlane.h"

#include "PMesh/PMesh_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< PConvexHullGenerateUtilityDataTrianglePlane >TArrayPlane;

///////////////////////////////////////////////////////
// local static methods
/**/
static HBOOL LocalBoundPlanesGet(
	PPlaneR3& out_planeHigh,
	PPlaneR3& out_planeLow,
	const PPlaneR3& in_plane,
	const HSINT in_triangleIndex,
	const PMesh& in_mesh,
	const HSINT in_touchingIndex
	) 
{
	//const TArrayVector& pointCloud = in_mesh.ArrayVertexGet();
	HVectorR3 arrayVertex[ 3 ];
	in_mesh.TriangleVertexGet(
		in_triangleIndex,
		arrayVertex[ 0 ],
		arrayVertex[ 1 ],
		arrayVertex[ 2 ]
		);


	const HVectorR3& otherPoint = arrayVertex[ ( in_touchingIndex + 2 ) % 3 ];

	//high case
	const HVectorR3 highNormal = HMatrixUtilityR3::Normalise( HMatrixUtilityR3::CrossProduct(
		otherPoint - arrayVertex[ in_touchingIndex ],
		in_plane.DirectionGet().VectorGet()
		) );
	if( HTRUE == HMathUtilityEpsilonZero( highNormal ) )
	{
		return HFALSE;
	}
	out_planeHigh.DirectionSet( PUnitVectorR3( highNormal ) );
	out_planeHigh.DistanceSet( HMatrixUtilityR3::DotProduct( highNormal, otherPoint ) );

	//low case
	const HVectorR3 lowNormal = HMatrixUtilityR3::Normalise( HMatrixUtilityR3::CrossProduct(
		arrayVertex[ ( in_touchingIndex + 1 ) % 3 ] - otherPoint,
		in_plane.DirectionGet().VectorGet()
		) );
	if( HTRUE == HMathUtilityEpsilonZero( lowNormal ) )
	{
		return HFALSE;
	}

	out_planeLow.DirectionSet( PUnitVectorR3( lowNormal ) );
	out_planeLow.DistanceSet( HMatrixUtilityR3::DotProduct( lowNormal, otherPoint ) );

	return HTRUE;
}

/*
	return false if any point is outside planes
*/
static HBOOL LocalTestTriangle( 
	const Hubris::HSINT in_triangleIndex,
	PMesh& in_mesh,
	const TArrayPlane& in_arrayPlane
	)
{
	HVectorR3 points[ 3 ];
	in_mesh.TriangleVertexGet(
		in_triangleIndex,
		points[ 0 ],
		points[ 1 ],
		points[ 2 ]
		);
	HCOMMON_FOR_EACH_CONST( plane, in_arrayPlane, TArrayPlane )
	{
		for( HSINT index = 0; index < 3; ++index )
		{
			const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( plane.PlaneGet(), points[ index ] );
			if( 0.0001F < distance )
			{
				return HFALSE;
			}
		}
	}

	return HTRUE;
}

/**/
static HBOOL LocalCheckTriangleProfile(
	const HSINT in_triangleIndex,
	const TArraySint& in_arrayTranglesIndex,
	PMesh& in_mesh,
	const PPlaneR3& in_plane
	)
{
	HSINT arrayVertexIndex[ 3 ];
	in_mesh.TriangleIndexGet( 
		in_triangleIndex,
		arrayVertexIndex[ 0 ],
		arrayVertexIndex[ 1 ],
		arrayVertexIndex[ 2 ]
		);

	//find which edge the target edge touches on
	HSINT touchingIndex = HCOMMON_INVALID_INDEX;
	for( HSINT index = 0; index < 3; ++index )
	{
		const HSINT testTouch = in_mesh.TriangleEdgeTouchesGet( in_triangleIndex, index );
		if( HCOMMON_INVALID_INDEX == testTouch )
		{
			continue;
		}
		if( HCOMMON_INVALID_INDEX != HContainerUtility< TArraySint >::IndexOf( in_arrayTranglesIndex, testTouch ) )
		{
			touchingIndex = index;
		}
	}

	//first face on plane? huh, non touching, but still valid
	if( HCOMMON_INVALID_INDEX == touchingIndex )
	{
		return HTRUE;
	}

	// touchingIndex is edge we touch on, 
	//so arrayVertexIndex[ ( touchingIndex + 1 ) % 3 ]
	//and arrayVertexIndex[ touchingIndex ]
	// are the vertex index to check current triangles agains
	PPlaneR3 planeHigh;
	PPlaneR3 planeLow;
	if( HFALSE == LocalBoundPlanesGet(
		planeHigh,
		planeLow,
		in_plane,
		in_triangleIndex,
		in_mesh,
		touchingIndex
		) )
	{
		return HFALSE;
	}

	//every point of used triangles must not be outside bounds planes
	HVectorR3 testPoints[ 3 ];
	HCOMMON_FOR_EACH_CONST( usedTriangleIndex, in_arrayTranglesIndex, TArraySint )
	{
		in_mesh.TriangleVertexGet(
			usedTriangleIndex,
			testPoints[ 0 ],
			testPoints[ 1 ],
			testPoints[ 2 ]
			);

		for( HSINT index = 0; index < 3; ++index )
		{
			const HREAL distanceHigh = PPlaneUtility::DistanceFromPlaneGet( planeHigh, testPoints[ index ] );
			if( 0.00001F < distanceHigh )
			{
				return HFALSE;
			}
			const HREAL distanceLow = PPlaneUtility::DistanceFromPlaneGet( planeLow, testPoints[ index ] );
			if( 0.00001F < distanceLow )
			{
				return HFALSE;
			}
		}
	}

	return HTRUE;
}

/**/
static HBOOL LocalTriangleAdd(
	TArraySint& in_out_arrayTranglesIndex,
	const Hubris::HSINT in_triangleIndex,
	PMesh& in_mesh,
	const TArrayPlane& in_arrayPlane
	)
{
	//check we have not violated planes
	if( HFALSE == LocalTestTriangle( 
		in_triangleIndex,
		in_mesh,
		in_arrayPlane ) )
	{
		return HFALSE;
	}

	in_out_arrayTranglesIndex.Insert( in_triangleIndex );

	return HTRUE;
}

/**/
static HVOID LocalFlowTriangle(
	TArraySint& in_out_arrayTranglesIndex,
	const Hubris::HSINT in_triangleIndex,
	PMesh& in_mesh,
	const TArrayPlane& in_arrayPlane,
	const PPlaneR3& in_plane
	)
{
	//get the array of each triangle index touching a vertex, then if triangle is in use, make sure edge touching in convex
	for( HSINT index = 0; index < 3; ++index )
	{
		const HSINT touchingTraingleIndex = in_mesh.TriangleEdgeTouchesGet( in_triangleIndex, index );
		if( HCOMMON_INVALID_INDEX == touchingTraingleIndex )
		{
			continue;
		}

		//bail if already added
		if( HCOMMON_INVALID_INDEX != HContainerUtility< TArraySint >::IndexOf( in_out_arrayTranglesIndex, touchingTraingleIndex ) )
		{
			continue;
		}

		//bail if not close enough to plane
		const HVectorR3 triangleNormal = in_mesh.TriangleNormalGet( touchingTraingleIndex );
		if( !( HMathUtilityAbsolute( triangleNormal - in_plane.DirectionGet().VectorGet() ) < HMatrixConstructor::HVectorR3Construct( 0.00001F, 0.00001F, 0.00001F ) ) )
		{
			continue;
		}

		//every triangle in use that touches this triangle must pass convex profile
		if( HFALSE == LocalCheckTriangleProfile(
			touchingTraingleIndex,
			in_out_arrayTranglesIndex,
			in_mesh,
			in_plane
			) )
		{
			continue;
		}

		//add the triangle, checks exsising planes
		if( HFALSE == LocalTriangleAdd(
			in_out_arrayTranglesIndex,						  
			touchingTraingleIndex,
			in_mesh,
			in_arrayPlane
			) )
		{
			continue;
		}

		//recurse, flowing onto added triangle
		LocalFlowTriangle(
			in_out_arrayTranglesIndex,						  
			touchingTraingleIndex,
			in_mesh,
			in_arrayPlane,
			in_plane
			);
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityDataTrianglePlane::PConvexHullGenerateUtilityDataTrianglePlane( const PConvexHullGenerateUtilityDataTrianglePlane& in_src )
: m_plane()
, m_arrayTranglesIndex()
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullGenerateUtilityDataTrianglePlane::PConvexHullGenerateUtilityDataTrianglePlane()
: m_plane()
, m_arrayTranglesIndex()
{
	return;
}

/**/
PConvexHullGenerateUtilityDataTrianglePlane::~PConvexHullGenerateUtilityDataTrianglePlane()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilityDataTrianglePlane& PConvexHullGenerateUtilityDataTrianglePlane::operator=( const PConvexHullGenerateUtilityDataTrianglePlane& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_plane = in_rhs.m_plane;
		m_arrayTranglesIndex = in_rhs.m_arrayTranglesIndex;
	}
	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataTrianglePlane::operator==( const PConvexHullGenerateUtilityDataTrianglePlane& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_plane == in_rhs.m_plane );
		match &= ( m_arrayTranglesIndex == in_rhs.m_arrayTranglesIndex );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataTrianglePlane::operator!=( const PConvexHullGenerateUtilityDataTrianglePlane& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataTrianglePlane::DataSet(
	const Hubris::HSINT in_triangleIndex,
	PMesh& in_mesh,
	const TArrayPlane& in_arrayPlane
	)
{
	( *this ) = PConvexHullGenerateUtilityDataTrianglePlane();

	HVectorR3 points[ 3 ];
	in_mesh.TriangleVertexGet( 
		in_triangleIndex, 
		points[ 0 ],
		points[ 1 ],
		points[ 2 ]
		);
	if( HFALSE == PPlaneUtility::ConstructPlane(
		m_plane,
		points[ 0 ],
		points[ 1 ],
		points[ 2 ]	
		) )
	{
		return HFALSE;
	}

	if( HFALSE == LocalTriangleAdd(
		m_arrayTranglesIndex,
		in_triangleIndex,
		in_mesh,
		in_arrayPlane
		) )
	{
		return HFALSE;
	}

	LocalFlowTriangle(
		m_arrayTranglesIndex,
		in_triangleIndex,
		in_mesh,
		in_arrayPlane,
		m_plane
		);


	return HTRUE;
}

/**/
