//file: Pride/PSphere/PSphereUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PSphere/PSphereUtility.h"

#include "Pride/PSphere/PSphere.h"
#include "Pride/PSphere/PSphereListReduce.h"

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
typedef Hubris::HContainerPair< PSphereR3, TArraySint >TPairSphereArraySint;
typedef Hubris::HContainerArray< TPairSphereArraySint >TArrayPairSphereArraySint;

///////////////////////////////////////////////////////
// static public methods
/**/
const PSphereR3 PSphereUtility::SphereTranslate( 
	const PSphereR3& in_sphere,
	const Hubris::HMatrixR4& in_matrix
	)
{
	const PSphereR3 returnSphere( 
		( in_sphere.RadiusGet() * HMatrixUtility::RotationLengthGet( in_matrix ) ),
		HMatrixUtility::VectorProduct< HMatrixR4, HVectorR3 >( in_matrix, in_sphere.CenterGet() )
		);

	return returnSphere;
}

/*
http://local.wasp.uwa.edu.au/~pbourke/geometry/spherefrom4/
Given 4 points in 3 dimensional space [ (x1,y1,z1) (x2,y2,z2) (x3,y3,z3) (x4,y4,z4) ]the equation of the sphere with those points on the surface is found by solving the following determinant. 

x2 + y2 + z2	x	y	z	1 
x12 + y12 + z12 x1	y1	z1	1 
x22 + y22 + z22 x2	y2	z2	1 
x32 + y32 + z32 x3	y3	z3	1 
x42 + y42 + z42 x4	y4	z4	1 
  = 0 

x0 = 0.5 M12 / M11 
y0 = - 0.5 M13 / M11 
z0 = 0.5 M14 / M11 
r2 = x02 + y02 + z02 - M15 / M11 
 Note that these can't be solved for M11 equal to zero. This corresponds to no quadratic terms (x2, y2, z2) in which case we aren't dealing with a sphere and the points are either coplanar or three are colinear. 
*/
const Hubris::HBOOL PSphereUtility::SphereFromPoints(
	Pride::PSphereR3& out_sphere,
	const Hubris::HVectorR3 in_pointOne,
	const Hubris::HVectorR3 in_pointTwo,
	const Hubris::HVectorR3 in_pointThree,
	const Hubris::HVectorR3 in_pointFour
	)
{
	HMatrixR5 matrix;
	matrix[ HMatrixR5::IndexGet( 0, 1 ) ] = HMatrixUtility::DotProduct( in_pointOne, in_pointOne );
	matrix[ HMatrixR5::IndexGet( 1, 1 ) ] = in_pointOne[ 0 ];
	matrix[ HMatrixR5::IndexGet( 1, 1 ) ] = in_pointOne[ 1 ];
	matrix[ HMatrixR5::IndexGet( 1, 1 ) ] = in_pointOne[ 2 ];
	matrix[ HMatrixR5::IndexGet( 4, 1 ) ] = HVariablesMath::UnitGet< HREAL >();

	matrix[ HMatrixR5::IndexGet( 0, 2 ) ] = HMatrixUtility::DotProduct( in_pointTwo, in_pointTwo );
	matrix[ HMatrixR5::IndexGet( 1, 2 ) ] = in_pointTwo[ 0 ];
	matrix[ HMatrixR5::IndexGet( 1, 2 ) ] = in_pointTwo[ 1 ];
	matrix[ HMatrixR5::IndexGet( 1, 2 ) ] = in_pointTwo[ 2 ];
	matrix[ HMatrixR5::IndexGet( 4, 2 ) ] = HVariablesMath::UnitGet< HREAL >();

	matrix[ HMatrixR5::IndexGet( 0, 3 ) ] = HMatrixUtility::DotProduct( in_pointThree, in_pointThree );
	matrix[ HMatrixR5::IndexGet( 1, 3 ) ] = in_pointThree[ 0 ];
	matrix[ HMatrixR5::IndexGet( 1, 3 ) ] = in_pointThree[ 1 ];
	matrix[ HMatrixR5::IndexGet( 1, 3 ) ] = in_pointThree[ 2 ];
	matrix[ HMatrixR5::IndexGet( 4, 3 ) ] = HVariablesMath::UnitGet< HREAL >();

	matrix[ HMatrixR5::IndexGet( 0, 4 ) ] = HMatrixUtility::DotProduct( in_pointFour, in_pointFour );
	matrix[ HMatrixR5::IndexGet( 1, 4 ) ] = in_pointFour[ 0 ];
	matrix[ HMatrixR5::IndexGet( 1, 4 ) ] = in_pointFour[ 1 ];
	matrix[ HMatrixR5::IndexGet( 1, 4 ) ] = in_pointFour[ 2 ];
	matrix[ HMatrixR5::IndexGet( 4, 4 ) ] = HVariablesMath::UnitGet< HREAL >();

	const HREAL determinantM11 = HMatrixUtility::Determinant( 
		HMatrixUtility::MinorMatrixGet< HMatrixR5, HMatrixR4 >( matrix, 0, 0 ) 
		);

	if( HTRUE == HMathUtility::EpsilonZero( determinantM11 ) )
	{
		return HFALSE;
	}

	const HREAL invertDeterminantM11 = HVariablesMath::UnitGet< HREAL >() / determinantM11;

	HVectorR3 origin;

	origin[ 0 ] = HMatrixUtility::Determinant( HMatrixUtility::MinorMatrixGet< HMatrixR5, HMatrixR4 >( matrix, 1, 0 ) ) * invertDeterminantM11;
	origin[ 1 ] = HMatrixUtility::Determinant( HMatrixUtility::MinorMatrixGet< HMatrixR5, HMatrixR4 >( matrix, 2, 0 ) ) * invertDeterminantM11;
	origin[ 2 ] = HMatrixUtility::Determinant( HMatrixUtility::MinorMatrixGet< HMatrixR5, HMatrixR4 >( matrix, 3, 0 ) ) * invertDeterminantM11;

	const HREAL radiusSquared = HMatrixUtility::DotProduct( origin, origin ) - ( HMatrixUtility::Determinant( HMatrixUtility::MinorMatrixGet< HMatrixR5, HMatrixR4 >( matrix, 3, 0 ) ) * invertDeterminantM11 );

	if( radiusSquared < 0.0F )
	{
		return HFALSE;
	}

	const HREAL radius = HMath::SquareRoot< HREAL >( radiusSquared );

	out_sphere.CenterSet( origin );
	out_sphere.RadiusSet( radius );

	return HTRUE;
}

/**/
const PSphereR3 PSphereUtility::SphereMerge(
	const PSphereR3& in_lhs,
	const PSphereR3& in_rhs
	)
{
	const HVectorR3 offset = in_lhs.CenterGet() - in_rhs.CenterGet();
	const HREAL distance = HMatrixUtility::Length( offset );

	//deal with sphere inside
	// presume distance == zero dealt with by following
	if( distance + in_lhs.RadiusGet() <= in_rhs.RadiusGet() )
	{
		return in_rhs;
	}
	if( distance + in_rhs.RadiusGet() <= in_lhs.RadiusGet() )
	{
		return in_lhs;
	}

	//reduandant, but just to be sure
	if( HTRUE == HMathUtility::EpsilonZero( distance ) )
	{
		if( in_lhs.RadiusGet() <= in_rhs.RadiusGet() )
		{
			return in_rhs;
		}
		return in_lhs;
	}

	const HREAL newRadius = ( ( distance + in_lhs.RadiusGet() + in_rhs.RadiusGet() ) * 0.5F );
	const HVectorR3 normal = offset / distance;

	//get a point on lhs in line with center lhs& rhs, then go back by new radius
	const HVectorR3 newCenter = ( in_lhs.CenterGet() + ( in_lhs.RadiusGet() - newRadius ) * normal );

	return PSphereR3( 
		newRadius,
		newCenter
		);
}

/**/
const PSphereR3 PSphereUtility::SphereMerge(
	const TArraySphere& in_arraySphere
	)
{
	if( in_arraySphere.SizeGet() <= 0 )
	{
		//or assert?
		return PSphereR3();
	}

	if( 1 == in_arraySphere.SizeGet() )
	{
		return in_arraySphere[ 0 ];
	}

	//find the best pair, the 

	HSINT bestOne = HCOMMON_INVALID_INDEX;
	HSINT bestTwo = HCOMMON_INVALID_INDEX;
	HREAL bestDistance = HVariablesMath::MinimumGet< HREAL >();
	for( HSINT indexOne = 0; indexOne < in_arraySphere.SizeGet(); ++indexOne )
	{
		for( HSINT indexTwo = indexOne + 1; indexTwo < in_arraySphere.SizeGet(); ++indexTwo )
		{
			const PSphereR3& sphereOne = in_arraySphere[ indexOne ];
			const PSphereR3& sphereTwo = in_arraySphere[ indexTwo ];

			//approx, for exact you need length, not length squared
			const HREAL testDistance = HMatrixUtility::LengthSquared( sphereOne.CenterGet() - sphereTwo.CenterGet() ) +
				( sphereOne.RadiusGet() + sphereOne.RadiusGet() ) +
				( sphereTwo.RadiusGet() + sphereTwo.RadiusGet() );

			if( bestDistance < testDistance )
			{
				bestDistance = testDistance;
				bestOne = indexOne;
				bestTwo = indexTwo;
			}
		}
	}

	PSphereR3 sphere = SphereMerge( in_arraySphere[ bestOne ], in_arraySphere[ bestTwo ] );

	for( HSINT index = 0; index <  in_arraySphere.SizeGet(); ++index )
	{
		if( ( index == bestOne ) ||
			( index == bestTwo ) )
		{
			continue;
		}

		sphere = SphereMerge( in_arraySphere[ index ], sphere );
	}

	return sphere;
}


/**/
HVOID PSphereUtility::SphereListReduce(
	TArrayArraySint& out_mergeList,
	const TArraySphere& in_arraySphere,
	const Hubris::HSINT in_maxCount
	)
{
	TArrayPairSphereArraySint sphereList;
	sphereList.SizeSet( in_arraySphere.SizeGet() );
	for( HSINT index = 0; index < in_arraySphere.SizeGet(); ++index )
	{
		sphereList[ index ].m_first = in_arraySphere[ index ];
		sphereList[ index ].m_second.Insert( index );
	}

	PSphereListReduce::Reduce(
		sphereList,
		in_maxCount
		);

	out_mergeList.SizeSet( sphereList.SizeGet() );
	for( HSINT index = 0; index < sphereList.SizeGet(); ++index )
	{
		out_mergeList[ index ] = sphereList[ index ].m_second;
	}

	return;
}

/**/
const Hubris::HBOOL PSphereUtility::SphereEqualOrInside(
	const PSphereR3& in_sphereMaster,
	const PSphereR3& in_sphereEqualInsideTest
	)
{
	const HREAL masterValue = HMath::Square( in_sphereMaster.RadiusGet() - in_sphereEqualInsideTest.RadiusGet() );
	const HREAL testValue = ( HMatrixUtility::LengthSquared( in_sphereMaster.CenterGet() - in_sphereEqualInsideTest.CenterGet() ) );

	return( ( testValue < masterValue ) ||
		( HMathUtility::EpsilonEqual( testValue, masterValue ) ) );
}

/**/
const Hubris::HBOOL PSphereUtility::SphereTouching(
	const PSphereR3& in_sphereLhs,
	const PSphereR3& in_sphereRhs
	)
{
	const HREAL offsetSquared = ( HMatrixUtility::LengthSquared( in_sphereLhs.CenterGet() - in_sphereRhs.CenterGet() ) );
	const HREAL radiusSumSquared = HMath::Square( in_sphereLhs.RadiusGet() + in_sphereRhs.RadiusGet() );

	const HBOOL touching = ( offsetSquared <= radiusSumSquared );

	return touching;
}

/**/
HVOID PSphereUtility::SphereTouchingTest(
	Hubris::HBOOL& out_sphereInside,
	Hubris::HBOOL& out_sphereTouching,
	const PSphereR3& in_sphereMaster,
	const PSphereR3& in_sphereInsideTouchingTest
	)
{
	out_sphereInside = HFALSE;
	out_sphereTouching = HFALSE;

	const HREAL offsetSquared = ( HMatrixUtility::LengthSquared( in_sphereMaster.CenterGet() - in_sphereInsideTouchingTest.CenterGet() ) );

	//if (radiusone - radius2)^2 < offset_length_squared, inside
	const HREAL insideTest = HMath::Square( in_sphereMaster.RadiusGet() - in_sphereInsideTouchingTest.RadiusGet() );
	if( insideTest < offsetSquared )
	{
		out_sphereInside = HTRUE;
		out_sphereTouching = HTRUE;
		return;
	}

	//if (radiusone + radius2)^2 < offset_length_squared, touching
	const HREAL touchingTest = HMath::Square( in_sphereMaster.RadiusGet() + in_sphereInsideTouchingTest.RadiusGet() );
	if( offsetSquared < touchingTest )
	{
		out_sphereTouching = HTRUE;
		return;
	}

	return;
}

/**/
const Hubris::HBOOL PSphereUtility::PointInsideInclusive( 
	const PSphereR3& in_sphere,
	const Hubris::HVectorR3& in_point
	)
{
	const HVectorR3 offset = in_point - in_sphere.CenterGet();
	const HREAL distanceSquared = HMatrixUtility::LengthSquared( offset );
	const HREAL radiusSquared = in_sphere.RadiusGet() * in_sphere.RadiusGet();

	const HBOOL result = ( ( distanceSquared < radiusSquared ) ||
		( HTRUE == HMathUtility::EpsilonEqual( distanceSquared, radiusSquared ) ) );

	return result;
}

/**/
