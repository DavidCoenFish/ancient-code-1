//file: Pride/PIntersection/PIntersectionUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PIntersection/PIntersectionUtility.h"

#include "Pride/PConvexHull/PConvexHull_Export.h"
#include "Pride/PBounds/PBounds_Export.h"
#include "Pride/PLine/PLine_Export.h"
#include "Pride/PPlane/PPlane_Export.h"
#include "Pride/PSphere/PSphere_Export.h"
#include "Pride/PUnitVector/PUnitVector_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMath/HMath_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >
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

///////////////////////////////////////////////////////
// local static methods
/**/
static const HBOOL LocalPointInsideHull(
	PConvexHull& in_out_hull,
	const Hubris::HVectorR3& in_point,
	const HREAL in_delta
	)
{
	//if point outside any plane, return HFALSE
	for( HSINT index = 0; index < in_out_hull.PlaneCountGet(); ++index )
	{
		const PPlaneR3& plane = in_out_hull.PlaneGet( index );
		const HREAL distance = PPlaneUtility::DistanceFromPlaneGet( plane, in_point );
		if( in_delta < distance )
		{
			return HFALSE;
		}
	}

	//point is only inside if hull has planes
	return( 0 < in_out_hull.PlaneCountGet() );
}

/**/
static const HBOOL LocalPointInsideHullBounds(
	const PBoundsR3& in_bounds,
	PConvexHull& in_out_hull,
	const Hubris::HVectorR3& in_point,
	const HREAL in_delta
	)
{
	if( HFALSE == PBoundsUtility::PointInsideTest(  //PIntersectionUtility::PointInsideBounds(
		in_bounds,
		in_point
		) )
	{
		return HFALSE;
	}

	return LocalPointInsideHull(
		in_out_hull,
		in_point,
		in_delta
		);
}

///////////////////////////////////////////////////////
// public static methods

/*
	http://www.siggraph.org/education/materials/HyperGraph/raytrace/rtinter1.htm

A = Xd^2 + Yd^2 + Zd^2
B = 2 * (Xd * (X0 - Xc) + Yd * (Y0 - Yc) + Zd * (Z0 - Zc))
C = (X0 - Xc)^2 + (Y0 - Yc)^2 + (Z0 - Zc)^2 - Sr^2
t0, t1 = (- B + (B^2 - 4*C)^1/2) / 2 where t0 is for (-) and t1 is for (+)

*/
const Hubris::HBOOL PIntersectionUtility::LineSphereIntersect( 
	const PSphereR3& in_sphere,
	const PLineR3& in_line,
	Hubris::HREAL* const out_pRatioOnLineNear, 
	Hubris::HREAL* const out_pRatioOnLineFar
	)
{
	const HVectorR3 offset = in_sphere.CenterGet() - in_line.OriginGet();
	const HREAL dotDist = -( HMatrixUtility::DotProduct( offset, in_line.DirectionGet().VectorGet() ) );
	const HREAL varB = ( 2.0F * dotDist );
	const HREAL varC = HMatrixUtility::LengthSquared( offset ) - ( in_sphere.RadiusGet() * in_sphere.RadiusGet() );

	const HREAL discriminant = ( ( varB * varB ) - ( 4.0F * varC ) );

	if( discriminant < 0.0F )
	{
		return HFALSE;
	}

	if( ( HNULL != out_pRatioOnLineNear ) ||
		( HNULL != out_pRatioOnLineFar ) )
	{
		const HREAL temp = HMath::SquareRoot< HREAL >( discriminant );
		const HREAL tempOne = ( -varB + temp ) * 0.5F;
		const HREAL tempTwo = ( -varB - temp ) * 0.5F;

		if( HNULL != out_pRatioOnLineNear )
		{
			( *out_pRatioOnLineNear ) = HMathUtility::Minimum( tempOne, tempTwo );
		}

		if( HNULL != out_pRatioOnLineFar )
		{
			( *out_pRatioOnLineFar ) = HMathUtility::Maximum( tempOne, tempTwo );
		}
	}

	return HTRUE;
}

/*
	http://www.softsurfer.com/Archive/algorithm_0104/algorithm_0104B.htm#Intersection%20of%202%20Planes
*/
const Hubris::HBOOL PIntersectionUtility::PlaneLineIntersect( 
	Hubris::HREAL& out_ratioOnLine, 
	const PPlaneR2& in_plane,
	const PLineR2& in_line
	)
{
	const HREAL dom = HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), in_line.DirectionGet().VectorGet() );
	const HREAL num = -HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), ( in_line.OriginGet() - ( in_plane.DirectionGet().VectorGet() * in_plane.DistanceGet() ) ) );

	//parallel case
	if( HTRUE == HMathUtility::EpsilonZero( dom ) )
	{
		//if num == 0, segment was on plane
		return HFALSE;
	}

	out_ratioOnLine = num / dom;

	return HTRUE;
}

const Hubris::HBOOL PIntersectionUtility::PlaneLineIntersect( 
	Hubris::HREAL& out_ratioOnLine, 
	const PPlaneR3& in_plane,
	const PLineR3& in_line
	)
{
	const HREAL dom = HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), in_line.DirectionGet().VectorGet() );
	const HREAL num = -HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), ( in_line.OriginGet() - ( in_plane.DirectionGet().VectorGet() * in_plane.DistanceGet() ) ) );

	//parallel case
	if( HTRUE == HMathUtility::EpsilonZero( dom ) )
	{
		//if num == 0, segment was on plane
		return HFALSE;
	}

	out_ratioOnLine = num / dom;

	return HTRUE;
}

/*
	http://www.softsurfer.com/Archive/algorithm_0104/algorithm_0104B.htm#Intersection%20of%202%20Planes
*/
const Hubris::HBOOL PIntersectionUtility::PlanePlaneIntersect( 
	PLineR3& out_line, 
	const PPlaneR3& in_planeOne,
	const PPlaneR3& in_planeTwo
	)
{
	HVectorR3 lineDirection = HMatrixUtility::CrossProduct( in_planeOne.DirectionGet().VectorGet(), in_planeTwo.DirectionGet().VectorGet() );
	//mul result by 0.0001 as several operation build on these number and had a -e005 vector expolode 
	if( HTRUE == HMathUtility::EpsilonZero( lineDirection * 0.0001F ) )
	{
		return HFALSE;
	}

	const HSINT index0 = HMatrixUtility::AxisFindLargest< HVectorR3 >( HMathUtility::Absolute( lineDirection ) );
	const HSINT index1 = ( index0 + 1 ) % 3;
	const HSINT index2 = ( index0 + 2 ) % 3;

	HVectorR3 lineOrigin;

	lineOrigin[ index0 ] = HVariablesMath::ZeroGet< HREAL >();
	lineOrigin[ index1 ] = ( ( in_planeOne.DistanceGet() * in_planeTwo.DirectionGet()[ index2 ] ) - ( in_planeTwo.DistanceGet() * in_planeOne.DirectionGet()[ index2 ] ) ) / lineDirection[ index0 ];
	lineOrigin[ index2 ] = ( ( in_planeTwo.DistanceGet() * in_planeOne.DirectionGet()[ index1 ] ) - ( in_planeOne.DistanceGet() * in_planeTwo.DirectionGet()[ index1 ] ) ) / lineDirection[ index0 ];

	out_line = PLineR3( lineOrigin, PUnitVectorR3( lineDirection ) );

	return HTRUE;
}

/*
http://mathworld.wolfram.com/Plane-PlaneIntersection.html
 x=(|n_1~ n_2~ n_3~|)^(-1)[(x_1.n_1~)(n_2~ x n_3~)+(x_2.n_2~)(n_3~ x n_1~)+(x_3.n_3~)(n_1~ x n_2~)], 
*/
const Hubris::HBOOL PIntersectionUtility::PlanePlanePlaneIntersect( 
	Hubris::HVectorR3& out_point, 
	const PPlaneR3& in_planeOne,
	const PPlaneR3& in_planeTwo,
	const PPlaneR3& in_planeThree
	)
{
	const HMatrixR3 normalMatrix = HMatrixConstructor::HMatrixR3ConstructColoumn(
		in_planeOne.DirectionGet().VectorGet(),
		in_planeTwo.DirectionGet().VectorGet(),
		in_planeThree.DirectionGet().VectorGet()
		);

	const HREAL determinant = HMatrixUtility::Determinant( normalMatrix );

	if( HTRUE == HMathUtility::EpsilonZero( determinant ) )
	{
		return HFALSE;
	}

	HVectorR3 pointPlaneOne = in_planeOne.DirectionGet().VectorGet() * in_planeOne.DistanceGet();
	HVectorR3 pointPlaneTwo = in_planeTwo.DirectionGet().VectorGet() * in_planeTwo.DistanceGet();
	HVectorR3 pointPlaneThree = in_planeThree.DirectionGet().VectorGet() * in_planeThree.DistanceGet();

	out_point = (
		( HMatrixUtility::DotProduct( pointPlaneOne, in_planeOne.DirectionGet().VectorGet() ) * HMatrixUtility::CrossProduct( in_planeTwo.DirectionGet().VectorGet(), in_planeThree.DirectionGet().VectorGet() ) ) +
		( HMatrixUtility::DotProduct( pointPlaneTwo, in_planeTwo.DirectionGet().VectorGet() ) * HMatrixUtility::CrossProduct( in_planeThree.DirectionGet().VectorGet(), in_planeOne.DirectionGet().VectorGet() ) ) +
		( HMatrixUtility::DotProduct( pointPlaneThree, in_planeThree.DirectionGet().VectorGet() ) * HMatrixUtility::CrossProduct( in_planeOne.DirectionGet().VectorGet(), in_planeTwo.DirectionGet().VectorGet() ) )
		) * ( 1.0F /  determinant );

	return HTRUE;
}

/**/
const Hubris::HBOOL PIntersectionUtility::ArrayPointInsideHull(
	PConvexHull& in_out_hull,
	const TArrayVector& in_arrayVector,
	const HREAL in_delta
	)
{
	if( HTRUE == PConvexHullUtility::EnclosedTest( in_out_hull ) )
	{
		PBoundsR3 bounds = PConvexHullUtility::BoundsGet( in_out_hull );
		HCOMMON_FOR_EACH_CONST( point, in_arrayVector, TArrayVector )
		{
			if( HTRUE == LocalPointInsideHullBounds(
				bounds,
				in_out_hull,
				point,
				in_delta
				) )
			{
				return HTRUE;
			}
		}
	}
	else
	{
		HCOMMON_FOR_EACH_CONST( point, in_arrayVector, TArrayVector )
		{
			if( HTRUE == LocalPointInsideHull(
				in_out_hull,
				point,
				in_delta
				) )
			{
				return HTRUE;
			}
		}
	}

	return HFALSE;
}

/**/
const Hubris::HBOOL PIntersectionUtility::PointInsideHull(
	PConvexHull& in_out_hull,
	const Hubris::HVectorR3& in_point,
	const HREAL in_delta
	)
{
	if( HTRUE == PConvexHullUtility::EnclosedTest( in_out_hull ) )
	{
		return LocalPointInsideHullBounds(
			PConvexHullUtility::BoundsGet( in_out_hull ),
			in_out_hull,
			in_point,
			in_delta
			);
	}

	return LocalPointInsideHull(
		in_out_hull,
		in_point,
		in_delta
		);
}

/**
const Hubris::HBOOL PIntersectionUtility::PointInsideBounds(
	const PBoundsR3& in_bounds,
	const Hubris::HVectorR3& in_vector
	)
{
	//point is outside any axis, return HFALSE
	for( HSINT index = 0; index < 3; ++index )
	{
		if( ( in_vector[ index ] < in_bounds.VectorMinimumGet()[ index ] ) ||
			( in_bounds.VectorMaximumGet()[ index ] < in_vector[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
