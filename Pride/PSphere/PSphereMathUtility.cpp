//file: Pride/PSphere/PSphereMathUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PSphere/PSphereMathUtility.h"

#include "Pride/PSphere/PSphere.h"

#include "Pride/PSphere/PSphere_Export.h"

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
const PSphere Hubris::HMathUtility::Maximum< PSphere >( const PSphere& in_lhs, const PSphere& in_rhs )
{
	PSphere value;

	value.RadiusSet( HMathUtility::Maximum( in_lhs.RadiusGet(), in_lhs.RadiusGet() ) );
	value.CenterSet( HMathUtility::Maximum( in_lhs.CenterGet(), in_lhs.CenterGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PSphere Hubris::HMathUtility::Minimum< PSphere >( const PSphere& in_lhs, const PSphere& in_rhs )
{
	PSphere value;

	value.RadiusSet( HMathUtility::Minimum( in_lhs.RadiusGet(), in_lhs.RadiusGet() ) );
	value.CenterSet( HMathUtility::Minimum( in_lhs.CenterGet(), in_lhs.CenterGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template<>
const PSphereR2 Hubris::HMathUtility::Absolute< PSphereR2 >( const PSphereR2& in_src )
{
	PSphereR2 value;

	value.RadiusSet( HMathUtility::Absolute( in_src.RadiusGet() ) );
	value.CenterSet( HMathUtility::Absolute( in_src.CenterGet() ) );

	return value;
}
template<>
const PSphereR3 Hubris::HMathUtility::Absolute< PSphereR3 >( const PSphereR3& in_src )
{
	PSphereR3 value;

	value.RadiusSet( HMathUtility::Absolute( in_src.RadiusGet() ) );
	value.CenterSet( HMathUtility::Absolute( in_src.CenterGet() ) );

	return value;
}
/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*
const PSphere Hubris::HMathUtility::Lerp< PSphere >( const PSphere& in_lhs, const PSphere& in_rhs, const HREAL in_ratio )
{
	PSphere value;

	value.RadiusSet( HMathUtility::Lerp( in_lhs.RadiusGet(), in_lhs.RadiusGet(), in_ratio ) );
	value.CenterSet( HMathUtility::Lerp( in_lhs.CenterGet(), in_lhs.CenterGet(), in_ratio ) );

	return value;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::Valid< PSphereR2 >( const PSphereR2& in_src )
{
	return( ( HMathUtility::Valid( in_src.RadiusGet() ) ) && ( HMathUtility::Valid( in_src.CenterGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PSphereR3 >( const PSphereR3& in_src )
{
	return( ( HMathUtility::Valid( in_src.RadiusGet() ) ) && ( HMathUtility::Valid( in_src.CenterGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PSphereR2 >( const PSphereR2& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PSphereR3 >( const PSphereR3& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PSphereR2 >( const PSphereR2& in_src )
{
	return( ( HMathUtility::EpsilonZero( in_src.RadiusGet() ) ) && ( HMathUtility::EpsilonZero( in_src.CenterGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PSphereR3 >( const PSphereR3& in_src )
{
	return( ( HMathUtility::EpsilonZero( in_src.RadiusGet() ) ) && ( HMathUtility::EpsilonZero( in_src.CenterGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PSphereR2 >( const PSphereR2& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PSphereR3 >( const PSphereR3& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PSphereR2 >( const PSphereR2& in_lhs, const PSphereR2& in_rhs )
{
	return( ( HMathUtility::EpsilonEqual( in_lhs.RadiusGet(), in_rhs.RadiusGet() ) ) && ( HMathUtility::EpsilonEqual( in_lhs.CenterGet(), in_rhs.CenterGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PSphereR3 >( const PSphereR3& in_lhs, const PSphereR3& in_rhs )
{
	return( ( HMathUtility::EpsilonEqual( in_lhs.RadiusGet(), in_rhs.RadiusGet() ) ) && ( HMathUtility::EpsilonEqual( in_lhs.CenterGet(), in_rhs.CenterGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PSphereR2 >( const PSphereR2& in_lhs, const PSphereR2& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PSphereR3 >( const PSphereR3& in_lhs, const PSphereR3& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}

/**/