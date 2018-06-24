//file: Hubris/HMath/HMathUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMath/HMathUtility.h"

#include "Hubris/HVariables/HVariablesMath.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >static const IN_TYPE Clamp( const IN_TYPE& in_value, const IN_TYPE& in_minimum, const IN_TYPE& in_maximum );
*/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::Clamp( const IN_TYPE& in_value, const IN_TYPE& in_minimum, const IN_TYPE& in_maximum )
{
	if( in_value < in_minimum )
	{
		return in_minimum;
	}
	else if( in_maximum < in_value )
	{
		return in_maximum;
	}

	return in_value;
}

template const HU8 Hubris::HMathUtility::Clamp< HU8 >( const HU8& in_value, const HU8& in_minimum, const HU8& in_maximum );
template const HSINT Hubris::HMathUtility::Clamp< HSINT >( const HSINT& in_value, const HSINT& in_minimum, const HSINT& in_maximum );
template const HREAL Hubris::HMathUtility::Clamp< HREAL >( const HREAL& in_value, const HREAL& in_minimum, const HREAL& in_maximum );

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	if( in_lhs <= in_rhs )
	{
		return in_rhs;
	}
	return in_lhs;
}

template const HU8 Hubris::HMathUtility::Maximum< HU8 >( const HU8& in_lhs, const HU8& in_rhs );
template const HSINT Hubris::HMathUtility::Maximum< HSINT >( const HSINT& in_lhs, const HSINT& in_rhs );
template const HREAL Hubris::HMathUtility::Maximum< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs );

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	if( in_lhs <= in_rhs )
	{
		return in_lhs;
	}
	return in_rhs;
}

template const HU8 Hubris::HMathUtility::Minimum< HU8 >( const HU8& in_lhs, const HU8& in_rhs );
template const HSINT Hubris::HMathUtility::Minimum< HSINT >( const HSINT& in_lhs, const HSINT& in_rhs );
template const HREAL Hubris::HMathUtility::Minimum< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs );

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::Absolute( const IN_TYPE& in_src )
{
	if( 0 <= in_src ) 
	{
		return in_src;
	}
	return( -in_src );
}

template const HU8 Hubris::HMathUtility::Absolute< HU8 >( const HU8& in_src );
template const HSINT Hubris::HMathUtility::Absolute< HSINT >( const HSINT& in_src );
template const HREAL Hubris::HMathUtility::Absolute< HREAL >( const HREAL& in_src );

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio )
{
	return static_cast< IN_TYPE >( in_lhs + ( ( in_rhs - in_lhs ) * in_ratio ) );
}

template const HU8 Hubris::HMathUtility::Lerp< HU8 >( const HU8& in_lhs, const HU8& in_rhs, const HREAL in_ratio );
template const HSINT Hubris::HMathUtility::Lerp< HSINT >( const HSINT& in_lhs, const HSINT& in_rhs, const HREAL in_ratio );
template const HREAL Hubris::HMathUtility::Lerp< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs, const HREAL in_ratio );

/**/
Hubris::HVOID Hubris::HMathUtility::SplineHermiteBiasGet(
	const HREAL in_ratio,
	HREAL& out_bias0, // * in_lhs
	HREAL& out_bias1, // * in_rhs
	HREAL& out_bias2, // * in_lhsTangent
	HREAL& out_bias3  // * in_rhsTangent
	)
{
	const HREAL ratioSquared = in_ratio * in_ratio;
	const HREAL ratioCubed = ratioSquared * in_ratio;
	out_bias0 = ( ratioCubed + ratioCubed ) - ( 3.0F * ratioSquared ) + 1.0F;
	out_bias1 = ( - ratioCubed - ratioCubed ) + ( 3.0F * ratioSquared );
	out_bias2 = ratioCubed - ( ratioSquared + ratioSquared ) + in_ratio;
	out_bias3 = ratioCubed - ratioSquared;
	return;
}

/**/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::SplineHermite(
	const HREAL in_ratio,
	const IN_TYPE& in_lhs, 
	const IN_TYPE& in_rhs, 
	const IN_TYPE& in_lhsTangent, 
	const IN_TYPE& in_rhsTangent
	)
{
	HREAL hermite0;
	HREAL hermite1;
	HREAL hermite2;
	HREAL hermite3;

	SplineHermiteBiasGet(
		in_ratio,
		hermite0,
		hermite1,
		hermite2,
		hermite3
		);

	const IN_TYPE returnValue = static_cast< IN_TYPE >( 
		( hermite0 * in_lhs ) + 
		( hermite1 * in_rhs ) + 
		( hermite2 * in_lhsTangent ) +
		( hermite3 * in_rhsTangent ) 
		);

	return returnValue;
}

template const HU8 Hubris::HMathUtility::SplineHermite< HU8 >( const HREAL in_ratio, const HU8& in_lhs, const HU8& in_rhs, const HU8& in_lhsTangent, const HU8& in_rhsTangent );
template const HSINT Hubris::HMathUtility::SplineHermite< HSINT >( const HREAL in_ratio, const HSINT& in_lhs, const HSINT& in_rhs, const HSINT& in_lhsTangent, const HSINT& in_rhsTangent );
template const HREAL Hubris::HMathUtility::SplineHermite< HREAL >( const HREAL in_ratio, const HREAL& in_lhs, const HREAL& in_rhs, const HREAL& in_lhsTangent, const HREAL& in_rhsTangent );

/**/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::SplineTangentGet(
	const IN_TYPE& in_lhs, 
	const IN_TYPE& in_rhs, 
	const HREAL in_bias
	)
{
	return static_cast< IN_TYPE >( ( in_rhs - in_lhs ) * in_bias );
}

template const HU8 Hubris::HMathUtility::SplineTangentGet< HU8 >( const HU8& in_lhs, const HU8& in_rhs, const HREAL in_bias );
template const HSINT Hubris::HMathUtility::SplineTangentGet< HSINT >( const HSINT& in_lhs, const HSINT& in_rhs, const HREAL in_bias );
template const HREAL Hubris::HMathUtility::SplineTangentGet< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs, const HREAL in_bias );

/**/
template< typename IN_TYPE >
static const IN_TYPE Hubris::HMathUtility::SplineCatmullRom(
	const HREAL in_ratio,
	const IN_TYPE& in_point0, 
	const IN_TYPE& in_point1, 
	const IN_TYPE& in_point2, 
	const IN_TYPE& in_point3
	)
{
	const IN_TYPE lhsTangent = SplineTangentGet( in_point0, in_point2 );
	const IN_TYPE rhsTangent = SplineTangentGet( in_point1, in_point3 );

	const IN_TYPE returnValue = SplineHermite( in_ratio, in_point1, in_point2, lhsTangent, rhsTangent );
	return returnValue;
}

template const HU8 Hubris::HMathUtility::SplineCatmullRom< HU8 >( const HREAL in_ratio, const HU8& in_point0, const HU8& in_point1, const HU8& in_point2, const HU8& in_point3 );
template const HSINT Hubris::HMathUtility::SplineCatmullRom< HSINT >( const HREAL in_ratio, const HSINT& in_point0, const HSINT& in_point1, const HSINT& in_point2, const HSINT& in_point3 );
template const HREAL Hubris::HMathUtility::SplineCatmullRom< HREAL >( const HREAL in_ratio, const HREAL& in_point0, const HREAL& in_point1, const HREAL& in_point2, const HREAL& in_point3 );
 
/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*/
template< typename IN_TYPE >
static const HBOOL Hubris::HMathUtility::Valid( const IN_TYPE& in_src )
{
	//assume that if number line complete, nb is ok and not a NAN or inf
	return ( ( in_src < 0 ) || ( 0 <= in_src ) );
}

template const HBOOL Hubris::HMathUtility::Valid< HU8 >( const HU8& in_src );
template const HBOOL Hubris::HMathUtility::Valid< HSINT >( const HSINT& in_src );
template const HBOOL Hubris::HMathUtility::Valid< HREAL >( const HREAL& in_src );

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*/
template< typename IN_TYPE >
static const HBOOL Hubris::HMathUtility::ValidNot( const IN_TYPE& in_src )
{
	//assume that if number line complete, nb is ok and not a NAN or inf
	return( !( Valid( in_src ) ) );
}

template const HBOOL Hubris::HMathUtility::ValidNot< HU8 >( const HU8& in_src );
template const HBOOL Hubris::HMathUtility::ValidNot< HSINT >( const HSINT& in_src );
template const HBOOL Hubris::HMathUtility::ValidNot< HREAL >( const HREAL& in_src );

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMathUtility::EpsilonZero( const IN_TYPE& in_src )
{
	//<= aim for number line complete with EpsilonZeroNot, and allow int to pass int zero Epsilon
	return( Absolute( in_src ) <= HVariablesMath::EpsilonGet< IN_TYPE >() );
}

template const HBOOL HMathUtility::EpsilonZero< HU8 >( const HU8& in_src );
template const HBOOL HMathUtility::EpsilonZero< HSINT >( const HSINT& in_src );
template const HBOOL HMathUtility::EpsilonZero< HREAL >( const HREAL& in_src );

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src )
{
	//not just calling !EpsilonZero as want to exclude NAN and inf
	return( HVariablesMath::EpsilonGet< IN_TYPE >() < Absolute( in_src ) );
}

template const HBOOL HMathUtility::EpsilonZeroNot< HU8 >( const HU8& in_src );
template const HBOOL HMathUtility::EpsilonZeroNot< HSINT >( const HSINT& in_src );
template const HBOOL HMathUtility::EpsilonZeroNot< HREAL >( const HREAL& in_src );

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	return( EpsilonZero( in_lhs - in_rhs ) );
}

template const HBOOL HMathUtility::EpsilonEqual< HU8 >( const HU8& in_lhs, const HU8& in_rhs );
template const HBOOL HMathUtility::EpsilonEqual< HSINT >( const HSINT& in_lhs, const HSINT& in_rhs );
template const HBOOL HMathUtility::EpsilonEqual< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs );

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	return( EpsilonZeroNot( in_lhs - in_rhs ) );
}

template const HBOOL HMathUtility::EpsilonEqualNot< HU8 >( const HU8& in_lhs, const HU8& in_rhs );
template const HBOOL HMathUtility::EpsilonEqualNot< HSINT >( const HSINT& in_lhs, const HSINT& in_rhs );
template const HBOOL HMathUtility::EpsilonEqualNot< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs );

/*
template< typename IN_TYPE >const IN_TYPE HMathUtility::Pad( const IN_TYPE& in_value, const IN_TYPE& in_pad );
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMathUtility::Pad( const IN_TYPE& in_value, const IN_TYPE& in_pad )
{
	const IN_TYPE over = in_value % in_pad;
	if( 0 != over )
	{
		return( in_value + ( in_pad - over ) );
	}
	return in_value;
}

template const HU8 HMathUtility::Pad< HU8 >( const HU8& in_value, const HU8& in_pad );
template const HSINT HMathUtility::Pad< HSINT >( const HSINT& in_value, const HSINT& in_pad );

/**/
