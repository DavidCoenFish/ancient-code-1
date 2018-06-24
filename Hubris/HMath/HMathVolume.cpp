//file: Hubris/HMath/HMathVolume.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMath/HMathVolume.h"

#include "Hubris/HMath/HMathUtility.h"

#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HVariables/HVariablesMath.h"



///////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HMatrix< HREAL, 3, 1 > > TArrayVectorR3;

///////////////////////////////////////////////////
// static local methods
/**/
template< typename IN_TYPE >
static const IN_TYPE LocalVolumeSphere( const IN_TYPE& in_radius )
{
	const IN_TYPE returnValue = ( IN_TYPE )( ( 4.0F / 3.0F ) * HVariablesMath::PiGet< IN_TYPE >() * in_radius * in_radius * in_radius );
	return returnValue;
}

/*
http://mathworld.wolfram.com/Sphere-SphereIntersection.html
*/
template< typename IN_TYPE >
static const IN_TYPE LocalVolumeSphereIntersect( const IN_TYPE& in_radiusOne, const IN_TYPE& in_radiusTwo, const IN_TYPE& in_distance )
{
	//deal sphere not touching case
	if( ( in_radiusOne + in_radiusTwo ) < in_distance )
	{
		return HVariablesMath::ZeroGet< IN_TYPE >();
	}
	//deal sphere inside two
	if( ( in_distance + in_radiusOne ) < in_radiusTwo )
	{
		const IN_TYPE returnValue = LocalVolumeSphere( in_radiusTwo );
		return returnValue;
	}
	//deal sphere inside one
	if( ( in_distance + in_radiusTwo ) < in_radiusOne )
	{
		const IN_TYPE returnValue = LocalVolumeSphere( in_radiusOne );
		return returnValue;
	}
	//deal zero distance case, return volume of smaller sphere
	if( HTRUE == HMathUtility::EpsilonZero( in_distance ) )
	{
		if( in_radiusOne < in_radiusTwo )
		{
			const IN_TYPE returnValue = LocalVolumeSphere( in_radiusOne );
			return returnValue;
		}

		const IN_TYPE returnValue = LocalVolumeSphere( in_radiusTwo );
		return returnValue;
	}

	const IN_TYPE tempOne = ( in_radiusOne + in_radiusTwo - in_distance );
	const IN_TYPE tempTwo = ( ( in_distance * in_distance ) + ( 2.0F * in_distance * in_radiusTwo ) - ( 3.0F * in_radiusTwo * in_radiusTwo ) +
		( 2.0F * in_distance * in_radiusOne ) + ( 6.0F * in_radiusOne * in_radiusTwo ) - ( 3.0F * in_radiusOne * in_radiusOne ) );

	const IN_TYPE returnValue = ( IN_TYPE )( ( HVariablesMath::PiGet< IN_TYPE >() * tempOne * tempOne * tempTwo ) / ( 12.0F * in_distance ) ); 

	return returnValue;
}

///////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >const IN_TYPE HMathVolumeSphere( const IN_TYPE& in_radius );
*/
template<>
const HREAL Hubris::HMathVolume::VolumeSphere< HREAL >( const HREAL& in_radius )
{
	const HREAL returnValue = LocalVolumeSphere( in_radius );
	return returnValue;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathVolumeSphereIntersection( const IN_TYPE& in_radiusOne, const IN_TYPE& in_radiusTwo, const IN_TYPE& in_distance );
*/
template<>
const HREAL Hubris::HMathVolume::VolumeSphereIntersection< HREAL >( const HREAL& in_radiusOne, const HREAL& in_radiusTwo, const HREAL& in_distance )
{
	const HREAL returnValue = LocalVolumeSphereIntersect( in_radiusOne, in_radiusTwo, in_distance );
	return returnValue;
}

/*
http://amp.ece.cmu.edu/Publication/Cha/icip01_Cha.pdf
volume of tetrahedra with one point at origin and three arbitary points

area = 1/6(-x3y2z1 + x2y3z1 + x3y1z2 - x1y3z2 - x2y1z3 + x1y2z3 )

*/
const HREAL Hubris::HMathVolume::VolumeClosedMesh( const TArrayVectorR3& in_arrayTriangleTriplets )
{
	HREAL area = HVariablesMath::ZeroGet< HREAL >();

	if( 0 == in_arrayTriangleTriplets.SizeGet() )
	{
		return area;
	}

	for( HSINT index = 0; index < in_arrayTriangleTriplets.SizeGet(); index += 3 )
	{
		const HVectorR3& point0 = in_arrayTriangleTriplets[ index + 0 ];
		const HVectorR3& point1 = in_arrayTriangleTriplets[ index + 1 ];
		const HVectorR3& point2 = in_arrayTriangleTriplets[ index + 2 ];

		area += ( 0.166666667F * ( 
			 ( point2[ 0 ] * point1[ 1 ] * point0[ 2 ] ) + 
			-( point1[ 0 ] * point2[ 1 ] * point0[ 2 ] ) +
			-( point2[ 0 ] * point0[ 1 ] * point1[ 2 ] ) +
			 ( point0[ 0 ] * point2[ 1 ] * point1[ 2 ] ) +
			 ( point1[ 0 ] * point0[ 1 ] * point2[ 2 ] ) +
			-( point0[ 0 ] * point1[ 1 ] * point2[ 2 ] )
			 ) );
	}

	return area;
}

/**/
