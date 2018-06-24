//file: Pride/PPlane/PPlaneUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PPlane/PPlaneUtility.h"

#include "Pride/PPlane/PPlane.h"

#include "Pride/PSphere/PSphere_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HBOOL PPlaneUtility::ConstructPlane( 
	PPlaneR2& out_plane, 
	const Hubris::HVectorR2& in_pointOne,
	const Hubris::HVectorR2& in_pointTwo
	)
{
	out_plane = PPlaneR2();

	const HVectorR2 cross = HMatrixUtility::Normalise( in_pointTwo - in_pointOne );
	if( HTRUE == HMathUtility::EpsilonZero( cross ) )
	{
		return HFALSE;
	}
	const HVectorR2 normal = HMatrixConstructor::HVectorR2Construct( -( cross[ 1 ] ), cross[ 0 ] );
	out_plane.DirectionSet( PUnitVectorR2( normal ) );
	out_plane.DistanceSet( HMatrixUtility::DotProduct( normal, in_pointOne ) );

	return HTRUE;
}

/**/
const Hubris::HBOOL PPlaneUtility::ConstructPlane( 
	PPlaneR3& out_plane, 
	const Hubris::HVectorR3& in_pointOne,
	const Hubris::HVectorR3& in_pointTwo,
	const Hubris::HVectorR3& in_pointThree
	)
{
	out_plane = PPlaneR3();

	HVectorR3 normal = HMatrixUtility::CrossProduct( in_pointTwo - in_pointOne, in_pointOne - in_pointThree );
	normal = HMatrixUtility::Normalise( normal );

	if( HTRUE == HMathUtility::EpsilonZero( normal ) )
	{
		return HFALSE;
	}

	out_plane.DirectionSet( PUnitVectorR3( normal ) );
	out_plane.DistanceSet( HMatrixUtility::DotProduct( normal, in_pointOne ) );

	return HTRUE;
}

/**/
const PPlaneR3 PPlaneUtility::TranslatePlane( 
	const PPlaneR3& in_plane, 
	const Hubris::HMatrixR4& in_transform
	)
{
	const HVectorR3 origin = ( in_plane.DistanceGet() * in_plane.DirectionGet().VectorGet() );
	const HVectorR3 newOrigin = ( HMatrixUtility::VectorProduct( in_transform, origin ) );
	const HVectorR3 newDirection = ( HMatrixUtility::VectorProductNoTranslate( in_transform, in_plane.DirectionGet().VectorGet() ) );

	if( HMathUtility::EpsilonZero( newDirection ) )
	{
		return in_plane;
	}

	const PUnitVectorR3 newUnitDirection( newDirection );

	const PPlaneR3 plane(
		HMatrixUtility::DotProduct( newUnitDirection.VectorGet(), newOrigin ),
		newUnitDirection
		);
	return plane;
}

/**/
const PPlaneR2 PPlaneUtility::PlaneFlip( const PPlaneR2& in_plane )
{
	const PPlaneR2 plane(
		-( in_plane.DistanceGet() ),
		PUnitVectorR2( -( in_plane.DirectionGet().VectorGet() ) )
		);
	return plane;
}
const PPlaneR3 PPlaneUtility::PlaneFlip( const PPlaneR3& in_plane )
{
	const PPlaneR3 plane(
		-( in_plane.DistanceGet() ),
		PUnitVectorR3( -( in_plane.DirectionGet().VectorGet() ) )
		);
	return plane;
}

/**/
const Hubris::HREAL PPlaneUtility::DistanceFromPlaneGet( const PPlaneR2& in_plane, const Hubris::HVectorR2& in_point )
{
	return( HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), in_point ) - in_plane.DistanceGet() );
}
const Hubris::HREAL PPlaneUtility::DistanceFromPlaneGet( const PPlaneR3& in_plane, const Hubris::HVectorR3& in_point )
{
	return( HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), in_point ) - in_plane.DistanceGet() );
}

/**/
const Hubris::HBOOL PPlaneUtility::DirectionParallelToPlaneTest( 
	const PPlaneR2& in_plane, 
	const PUnitVectorR2& in_direction, 
	const Hubris::HREAL in_delta
	)
{
	return( HMathUtility::Absolute( HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), in_direction.VectorGet() ) ) <= in_delta );
}

/**/
const Hubris::HBOOL PPlaneUtility::DirectionParallelToPlaneTest( 
	const PPlaneR3& in_plane, 
	const PUnitVectorR3& in_direction, 
	const Hubris::HREAL in_delta
	)
{
	return( HMathUtility::Absolute( HMatrixUtility::DotProduct( in_plane.DirectionGet().VectorGet(), in_direction.VectorGet() ) ) <= in_delta );
}

/**/
const Hubris::HBOOL PPlaneUtility::EqualDelta( 
	const PPlaneR2& in_planeLhs, 
	const PPlaneR2& in_planeRhs, 
	const Hubris::HREAL in_deltaDirection,
	const Hubris::HREAL in_deltaDistance
	)
{
	HBOOL match = HTRUE;

	if( ( &in_planeLhs ) != ( &in_planeRhs ) )
	{
		match &= ( HMathUtility::Absolute( in_planeLhs.DistanceGet() - in_planeRhs.DistanceGet() ) <= ( in_deltaDistance ) );
		match &= ( 1.0F - HMatrixUtility::DotProduct( in_planeLhs.DirectionGet().VectorGet(), in_planeRhs.DirectionGet().VectorGet() ) <= in_deltaDirection );
		//match &= ( HMathUtility::Absolute( in_planeLhs.DirectionGet().VectorGet() - in_planeRhs.DirectionGet().VectorGet() ) <= HVectorR2( in_deltaDirection ) );
	}

	return match;
}
const Hubris::HBOOL PPlaneUtility::EqualDelta( 
	const PPlaneR3& in_planeLhs, 
	const PPlaneR3& in_planeRhs, 
	const Hubris::HREAL in_deltaDirection,
	const Hubris::HREAL in_deltaDistance
	)
{
	HBOOL match = HTRUE;

	if( ( &in_planeLhs ) != ( &in_planeRhs ) )
	{
		match &= ( HMathUtility::Absolute( in_planeLhs.DistanceGet() - in_planeRhs.DistanceGet() ) <= ( in_deltaDistance ) );
		match &= ( 1.0F - HMatrixUtility::DotProduct( in_planeLhs.DirectionGet().VectorGet(), in_planeRhs.DirectionGet().VectorGet() ) <= in_deltaDirection );
		//match &= ( HMathUtility::Absolute( in_planeLhs.DirectionGet().VectorGet() - in_planeRhs.DirectionGet().VectorGet() ) <= HVectorR3( in_deltaDirection ) );
	}

	return match;
}

/**/
HVOID PPlaneUtility::ProjectOntoPlane( 
	TArrayVector2D& out_arrayPoints2D,
	const TArrayVector& in_pointCloud, 
	const PPlaneR3& in_plane 
	)
{
	out_arrayPoints2D.Clear();
	const HVectorR3 cross = HMatrixUtility::CrossVector( in_plane.DirectionGet().VectorGet() );
	const HVectorR3 up = HMatrixUtility::CrossProduct( in_plane.DirectionGet().VectorGet(), cross );

	const HSINT count = in_pointCloud.SizeGet();
	out_arrayPoints2D.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		const HVectorR3& point = in_pointCloud[ index ];
		out_arrayPoints2D[ index ] = HMatrixConstructor::HVectorR2Construct(
			HMatrixUtility::DotProduct( cross, point ),
			HMatrixUtility::DotProduct( up, point )
			);
	}

	return;
}

/**/
const Hubris::HBOOL PPlaneUtility::SphereTouchPlane( 
	const PPlaneR3& in_plane,
	const PSphereR3& in_sphere
	)
{
	const HREAL distance = DistanceFromPlaneGet( in_plane, in_sphere.CenterGet() ) - HMathUtility::Absolute( in_sphere.RadiusGet() );
	const HBOOL insideTouching = ( ( distance < 0.0F ) ||
		( HTRUE == HMathUtility::EpsilonZero( distance ) ) );
	return insideTouching;
}

/**/
const Hubris::HBOOL PPlaneUtility::SphereInsidePlane( 
	const PPlaneR3& in_plane,
	const PSphereR3& in_sphere
	)
{
	const HREAL distance = DistanceFromPlaneGet( in_plane, in_sphere.CenterGet() ) + HMathUtility::Absolute( in_sphere.RadiusGet() );
	const HBOOL insideTouching = ( ( distance < 0.0F ) ||
		( HTRUE == HMathUtility::EpsilonZero( distance ) ) );
	return insideTouching;
}

/**/
const Hubris::HBOOL PPlaneUtility::PointInsidePlane(
	const PPlaneR3& in_plane,
	const Hubris::HVectorR3& in_point
	)
{
	const HREAL distance = DistanceFromPlaneGet( in_plane, in_point );
	const HBOOL insideTouching = ( ( distance < 0.0F ) ||
		( HTRUE == HMathUtility::EpsilonZero( distance ) ) );
	return insideTouching;
}

/**/