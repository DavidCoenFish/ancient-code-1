//file: Pride/PPlane/PPlaneMathUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PPlane/PPlaneMathUtility.h"

#include "Pride/PPlane/PPlane.h"

#include "Pride/PPlane/PPlane_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PPlane Hubris::HMathUtility::Maximum< PPlane >( const PPlane& in_lhs, const PPlane& in_rhs )
{
	PPlane value;

	value.DistanceSet( HMathUtility::Maximum( in_lhs.DistanceGet(), in_lhs.DistanceGet() ) );
	value.DirectionSet( HMathUtility::Maximum( in_lhs.DirectionGet(), in_lhs.DirectionGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PPlane Hubris::HMathUtility::Minimum< PPlane >( const PPlane& in_lhs, const PPlane& in_rhs )
{
	PPlane value;

	value.DistanceSet( HMathUtility::Minimum( in_lhs.DistanceGet(), in_lhs.DistanceGet() ) );
	value.DirectionSet( HMathUtility::Minimum( in_lhs.DirectionGet(), in_lhs.DirectionGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template<>
const PPlaneR2 Hubris::HMathUtility::Absolute< PPlaneR2 >( const PPlaneR2& in_src )
{
	PPlaneR2 value;

	value.DistanceSet( HMathUtility::Absolute( in_src.DistanceGet() ) );
	value.DirectionSet( HMathUtility::Absolute( in_src.DirectionGet() ) );

	return value;
}
template<>
const PPlaneR3 Hubris::HMathUtility::Absolute< PPlaneR3 >( const PPlaneR3& in_src )
{
	PPlaneR3 value;

	value.DistanceSet( HMathUtility::Absolute( in_src.DistanceGet() ) );
	value.DirectionSet( HMathUtility::Absolute( in_src.DirectionGet() ) );

	return value;
}
/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*
const PPlane Hubris::HMathUtility::Lerp< PPlane >( const PPlane& in_lhs, const PPlane& in_rhs, const HREAL in_ratio )
{
	PPlane value;

	value.DistanceSet( HMathUtility::Lerp( in_lhs.DistanceGet(), in_lhs.DistanceGet(), in_ratio ) );
	value.DirectionSet( HMathUtility::Lerp( in_lhs.DirectionGet(), in_lhs.DirectionGet(), in_ratio ) );

	return value;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::Valid< PPlaneR2 >( const PPlaneR2& in_src )
{
	return( ( HMathUtility::Valid( in_src.DistanceGet() ) ) && ( HMathUtility::Valid( in_src.DirectionGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PPlaneR3 >( const PPlaneR3& in_src )
{
	return( ( HMathUtility::Valid( in_src.DistanceGet() ) ) && ( HMathUtility::Valid( in_src.DirectionGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PPlaneR2 >( const PPlaneR2& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PPlaneR3 >( const PPlaneR3& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PPlaneR2 >( const PPlaneR2& in_src )
{
	return( ( HMathUtility::EpsilonZero( in_src.DistanceGet() ) ) && ( HMathUtility::EpsilonZero( in_src.DirectionGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PPlaneR3 >( const PPlaneR3& in_src )
{
	return( ( HMathUtility::EpsilonZero( in_src.DistanceGet() ) ) && ( HMathUtility::EpsilonZero( in_src.DirectionGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PPlaneR2 >( const PPlaneR2& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PPlaneR3 >( const PPlaneR3& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PPlaneR2 >( const PPlaneR2& in_lhs, const PPlaneR2& in_rhs )
{
	return( ( HMathUtility::EpsilonEqual( in_lhs.DistanceGet(), in_rhs.DistanceGet() ) ) && ( HMathUtility::EpsilonEqual( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PPlaneR3 >( const PPlaneR3& in_lhs, const PPlaneR3& in_rhs )
{
	return( ( HMathUtility::EpsilonEqual( in_lhs.DistanceGet(), in_rhs.DistanceGet() ) ) && ( HMathUtility::EpsilonEqual( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PPlaneR2 >( const PPlaneR2& in_lhs, const PPlaneR2& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PPlaneR3 >( const PPlaneR3& in_lhs, const PPlaneR3& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}

/**/