//file: Pride/PTriangle/PTriangleMathUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PTriangle/PTriangleUtility.h"

#include "Pride/PTriangle/PTriangle.h"

#include "Pride/PLine/PLine_Export.h"

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
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< PTriangle >TArrayTriangle;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// static local methods
/**/
static Hubris::HVOID LocalTriangulatLoop(
	TArraySint& in_out_triangleArray,
	const TArraySint& in_arrayIndex,
	const TArrayVector& in_arrayVector
	)
{
	if( in_arrayIndex.SizeGet() < 2 )
	{
		return;
	}

	if( 3 == in_arrayIndex.SizeGet() )
	{
		HContainerUtility::PushBack( in_out_triangleArray, in_arrayIndex[ 0 ] );
		HContainerUtility::PushBack( in_out_triangleArray, in_arrayIndex[ 1 ] );
		HContainerUtility::PushBack( in_out_triangleArray, in_arrayIndex[ 2 ] );
		return;
	}

	HSINT bestOne = HCOMMON_INVALID_INDEX;
	HSINT bestTwo = HCOMMON_INVALID_INDEX;
	HREAL bestDistance = HVariablesMath::MaximumGet< HREAL >();

	for( HSINT indexOne = 0; indexOne < in_arrayIndex.SizeGet(); ++indexOne )
	{
		for( HSINT indexTwo = indexOne + 2; indexTwo < in_arrayIndex.SizeGet(); ++indexTwo )
		{
			//special case, avoid edge on 'first to last'
			if( ( 0 == indexOne ) &&
				( ( in_arrayIndex.SizeGet() - 1 ) == indexTwo ) )
			{
				continue;
			}

			const HREAL distSquare = HMatrixUtility::LengthSquared( in_arrayVector[ indexOne ] - in_arrayVector[ indexTwo ] );

			if( distSquare < bestDistance )
			{
				bestDistance = distSquare;
				bestOne = indexOne;
				bestTwo = indexTwo;
			}
		}
	}

	if( ( HCOMMON_INVALID_INDEX == bestOne ) ||
		( HCOMMON_INVALID_INDEX == bestTwo ) )
	{
		return;
	}

	//split the index array on the pair of index that have the smallest distance
	TArraySint childOne;
	TArraySint childTwo;
	for( HSINT index = 0; index < in_arrayIndex.SizeGet(); ++index )
	{
		const HSINT vertexIndex = in_arrayIndex[ index ];

		if( ( bestOne <= index ) &&
			( index <= bestTwo ) )
		{
			HContainerUtility::PushBack( childOne, vertexIndex );
		}

		if( ( index <= bestOne ) ||
			( bestTwo <= index ) )
		{
			HContainerUtility::PushBack( childTwo, vertexIndex );
		}
	}

	LocalTriangulatLoop(
		in_out_triangleArray,
		childTwo,
		in_arrayVector
		);

	LocalTriangulatLoop(
		in_out_triangleArray,
		childOne,
		in_arrayVector
		);

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HBOOL PTriangleUtility::TrianglePointValidTest( 
	const Hubris::HVectorR3& in_pointOne,
	const Hubris::HVectorR3& in_pointTwo,
	const Hubris::HVectorR3& in_pointThree
	)
{
	return( ( HMathUtility::EpsilonEqualNot( in_pointOne, in_pointTwo ) ) &&
			( HMathUtility::EpsilonEqualNot( in_pointTwo, in_pointThree ) ) &&
			( HMathUtility::EpsilonEqualNot( in_pointThree, in_pointOne ) ) );
}

/**/
const Hubris::HBOOL PTriangleUtility::TriangleNormalGet( PUnitVectorR3& out_normal, const PTriangle& in_triangle )
{
	if( HFALSE == TrianglePointValidTest( in_triangle.PointOneGet(), in_triangle.PointTwoGet(), in_triangle.PointThreeGet() ) )
	{
		return HFALSE;
	}

	HVectorR3 normal = HMatrixUtility::CrossProduct( in_triangle.PointTwoGet() - in_triangle.PointOneGet(), in_triangle.PointOneGet() - in_triangle.PointThreeGet() );
	normal = HMatrixUtility::Normalise(  normal );
	if( HTRUE == HMathUtility::EpsilonZero( normal ) )
	{
		return HFALSE;
	}

	out_normal.VectorSet( normal );

	return HTRUE;
}

/**/
HVOID PTriangleUtility::CapEdgeLoop( TArrayTriangle& out_triangleArray, const TArrayVector& in_arrayVector )
{
	out_triangleArray.Clear();
	TArraySint arrayTriangleVertexIndexTriplets;
	CapEdgeLoop(
		arrayTriangleVertexIndexTriplets,
		in_arrayVector
		);

	HCOMMON_ASSERT( 0 == ( arrayTriangleVertexIndexTriplets.SizeGet() % 3 ), "invalid size" );

	for( HSINT index = 0; index < arrayTriangleVertexIndexTriplets.SizeGet(); index += 3 )
	{
		out_triangleArray.Insert(
			PTriangle(
				in_arrayVector[ arrayTriangleVertexIndexTriplets[ index + 0 ] ],
				in_arrayVector[ arrayTriangleVertexIndexTriplets[ index + 1 ] ],
				in_arrayVector[ arrayTriangleVertexIndexTriplets[ index + 2 ] ]
		) );
	}

	return;
}

/**/
HVOID PTriangleUtility::CapEdgeLoop( 
	TArraySint& out_arrayTriangleVertexIndexTriplets, //size%3
	const TArrayVector& in_arrayVector 
	)
{
	out_arrayTriangleVertexIndexTriplets.Clear();
	TArraySint arrayIndex;
	arrayIndex.SizeSet( in_arrayVector.SizeGet() );

	for( HSINT index = 0; index < in_arrayVector.SizeGet(); ++index )
	{
		arrayIndex[ index ] = index;
	}

	LocalTriangulatLoop(
		out_arrayTriangleVertexIndexTriplets,
		arrayIndex,
		in_arrayVector
		);

	return;
}


/**/
const Hubris::HBOOL PTriangleUtility::TriangleEdgeLineSegmentsGet(
	PLineSegmentR3& out_LineOne, 
	PLineSegmentR3& out_LineTwo, 
	PLineSegmentR3& out_LineThree, 
	const PTriangle& in_triangle 
	)
{
	if( HFALSE == PLineSegmentUtility::LineSegmentFromPoints(
		out_LineOne,
		in_triangle.PointOneGet(),
		in_triangle.PointTwoGet()
		) )
	{
		return HFALSE;
	}
	if( HFALSE == PLineSegmentUtility::LineSegmentFromPoints(
		out_LineTwo,
		in_triangle.PointTwoGet(),
		in_triangle.PointThreeGet()
		) )
	{
		return HFALSE;
	}
	if( HFALSE == PLineSegmentUtility::LineSegmentFromPoints(
		out_LineThree,
		in_triangle.PointThreeGet(),
		in_triangle.PointOneGet()
		) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/*
http://www.cs.virginia.edu/~gfx/Courses/2003/ImageSynthesis/papers/Acceleration/Fast%20MinimumStorage%20RayTriangle%20Intersection.pdf

edge1 = vert1 - vert0
edge2 = vert2 - vert0
pvec = cross( dir, edge2 )
det = dot( edge1, pvec )
if( det < 0.000001 ) return 0;
tvec = orig - vect0
u = dot( tvec, pvec )
if( u < 0 || u > det ) return 0;
qvec = cross( tvec, edge1 )
v = dot( dir, qvec )
if( v < 0 || u + v > det ) return 0;
t = dot( edge1, qvec )
inv_det = 1.0 / det
t *= inv_det
u *= inv_det
v *= inv_det
return 1
*
const Hubris::HBOOL PTriangleUtility::TriangleRayIntersect(
	const PLineR3& in_line,
	const PTriangle& in_triangle,
	Hubris::HREAL* const out_pRatioOnLine,
	Hubris::HREAL* const out_pTriangleU,
	Hubris::HREAL* const out_pTriangleV
	)
{
	const HVectorR3 edge1 = in_triangle.PointTwoGet() - in_triangle.PointOneGet();
	const HVectorR3 edge2 = in_triangle.PointThreeGet() - in_triangle.PointOneGet();

	const HVectorR3 pvec = HMatrixUtility::DotProduct( in_line.DirectionGet().VectorGet(), edge1 );

	return HTRUE;
}


/**/