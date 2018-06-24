//file: Hubris/HMatrix/HMatrixMathUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixMathUtility.h"

#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixOperator.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonDefine.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// static local methods
/**/
template< typename IN_TYPE >
static HVOID LocalClamp( IN_TYPE& in_out_value, const IN_TYPE& in_minimum, const IN_TYPE& in_maximum )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		in_out_value[ index ] = HMathUtility::Clamp( in_out_value[ index ], in_minimum[ index ], in_maximum[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalMaximum( IN_TYPE& out_value, const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		out_value[ index ] = HMathUtility::Maximum( in_lhs[ index ], in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalMinimum( IN_TYPE& out_value, const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		out_value[ index ] = HMathUtility::Minimum( in_lhs[ index ], in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalAbsolute( IN_TYPE& out_value, const IN_TYPE& in_src )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		out_value[ index ] = HMathUtility::Absolute( in_src[ index ] );
	}

	return;
}
/**/
template< typename IN_TYPE >
static HVOID LocalLerp( IN_TYPE& out_value, const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		out_value[ index ] = HMathUtility::Lerp( in_lhs[ index ], in_rhs[ index ], in_ratio );
	}

	return;
}
/**/
template< typename IN_TYPE >
static HVOID LocalSplineHermite( IN_TYPE& out_value, const HREAL in_ratio, const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const IN_TYPE& in_lhsTangent, const IN_TYPE& in_rhsTangent )
{
	HREAL hermite0;
	HREAL hermite1;
	HREAL hermite2;
	HREAL hermite3;

	HMathUtility::SplineHermiteBiasGet(
		in_ratio,
		hermite0,
		hermite1,
		hermite2,
		hermite3
		);

	out_value = ( 
		( hermite0 * in_lhs ) + 
		( hermite1 * in_rhs ) + 
		( hermite2 * in_lhsTangent ) +
		( hermite3 * in_rhsTangent ) 
		);

	return;
}
/**/
template< typename IN_TYPE >
static HVOID LocalSplineTangent( IN_TYPE& out_value, const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_bias = 0.5F )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		out_value[ index ] = HMathUtility::SplineTangentGet( in_lhs[ index ], in_rhs[ index ], in_bias );
	}

	return;
}
/**/
template< typename IN_TYPE >
static HVOID LocalSplineCatmullRom( IN_TYPE& out_value, const HREAL in_ratio, const IN_TYPE& in_point0, const IN_TYPE& in_point1, const IN_TYPE& in_point2, const IN_TYPE& in_point3 )
{
	IN_TYPE lhsTangent;
	LocalSplineTangent( lhsTangent, in_point0, in_point2 );
	IN_TYPE rhsTangent;
	LocalSplineTangent( rhsTangent, in_point1, in_point3 );

	LocalSplineHermite( out_value, in_ratio, in_point1, lhsTangent, in_point2, rhsTangent );

	return;
}
/**/
template< typename IN_TYPE >
static HBOOL LocalValid( const IN_TYPE& in_src )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		if( HFALSE == HMathUtility::Valid( in_src[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}
/**/
template< typename IN_TYPE >
static HBOOL LocalEpsilonZero( const IN_TYPE& in_src )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		if( HFALSE == HMathUtility::EpsilonZero( in_src[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}
/**/
template< typename IN_TYPE >
static HBOOL LocalEpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		if( HFALSE == HMathUtility::EpsilonEqual( in_lhs[ index ], in_rhs[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

////////////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >static const IN_TYPE Clamp( const IN_TYPE& in_value, const IN_TYPE& in_minimum, const IN_TYPE& in_maximum );
*/
template<>
const HVectorU1 Hubris::HMathUtility::Clamp< HVectorU1 >( const HVectorU1& in_value, const HVectorU1& in_minimum, const HVectorU1& in_maximum )
{
	HVectorU1 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorU2 Hubris::HMathUtility::Clamp< HVectorU2 >( const HVectorU2& in_value, const HVectorU2& in_minimum, const HVectorU2& in_maximum )
{
	HVectorU2 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorU3 Hubris::HMathUtility::Clamp< HVectorU3 >( const HVectorU3& in_value, const HVectorU3& in_minimum, const HVectorU3& in_maximum )
{
	HVectorU3 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorU4 Hubris::HMathUtility::Clamp< HVectorU4 >( const HVectorU4& in_value, const HVectorU4& in_minimum, const HVectorU4& in_maximum )
{
	HVectorU4 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixU2 Hubris::HMathUtility::Clamp< HMatrixU2 >( const HMatrixU2& in_value, const HMatrixU2& in_minimum, const HMatrixU2& in_maximum )
{
	HMatrixU2 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixU3 Hubris::HMathUtility::Clamp< HMatrixU3 >( const HMatrixU3& in_value, const HMatrixU3& in_minimum, const HMatrixU3& in_maximum )
{
	HMatrixU3 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixU4 Hubris::HMathUtility::Clamp< HMatrixU4 >( const HMatrixU4& in_value, const HMatrixU4& in_minimum, const HMatrixU4& in_maximum )
{
	HMatrixU4 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}

template<>
const HVectorS1 Hubris::HMathUtility::Clamp< HVectorS1 >( const HVectorS1& in_value, const HVectorS1& in_minimum, const HVectorS1& in_maximum )
{
	HVectorS1 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorS2 Hubris::HMathUtility::Clamp< HVectorS2 >( const HVectorS2& in_value, const HVectorS2& in_minimum, const HVectorS2& in_maximum )
{
	HVectorS2 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorS3 Hubris::HMathUtility::Clamp< HVectorS3 >( const HVectorS3& in_value, const HVectorS3& in_minimum, const HVectorS3& in_maximum )
{
	HVectorS3 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorS4 Hubris::HMathUtility::Clamp< HVectorS4 >( const HVectorS4& in_value, const HVectorS4& in_minimum, const HVectorS4& in_maximum )
{
	HVectorS4 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixS2 Hubris::HMathUtility::Clamp< HMatrixS2 >( const HMatrixS2& in_value, const HMatrixS2& in_minimum, const HMatrixS2& in_maximum )
{
	HMatrixS2 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixS3 Hubris::HMathUtility::Clamp< HMatrixS3 >( const HMatrixS3& in_value, const HMatrixS3& in_minimum, const HMatrixS3& in_maximum )
{
	HMatrixS3 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixS4 Hubris::HMathUtility::Clamp< HMatrixS4 >( const HMatrixS4& in_value, const HMatrixS4& in_minimum, const HMatrixS4& in_maximum )
{
	HMatrixS4 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}

template<>
const HVectorR1 Hubris::HMathUtility::Clamp< HVectorR1 >( const HVectorR1& in_value, const HVectorR1& in_minimum, const HVectorR1& in_maximum )
{
	HVectorR1 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorR2 Hubris::HMathUtility::Clamp< HVectorR2 >( const HVectorR2& in_value, const HVectorR2& in_minimum, const HVectorR2& in_maximum )
{
	HVectorR2 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::Clamp< HVectorR3 >( const HVectorR3& in_value, const HVectorR3& in_minimum, const HVectorR3& in_maximum )
{
	HVectorR3 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::Clamp< HVectorR4 >( const HVectorR4& in_value, const HVectorR4& in_minimum, const HVectorR4& in_maximum )
{
	HVectorR4 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixR2 Hubris::HMathUtility::Clamp< HMatrixR2 >( const HMatrixR2& in_value, const HMatrixR2& in_minimum, const HMatrixR2& in_maximum )
{
	HMatrixR2 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixR3 Hubris::HMathUtility::Clamp< HMatrixR3 >( const HMatrixR3& in_value, const HMatrixR3& in_minimum, const HMatrixR3& in_maximum )
{
	HMatrixR3 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}
template<>
const HMatrixR4 Hubris::HMathUtility::Clamp< HMatrixR4 >( const HMatrixR4& in_value, const HMatrixR4& in_minimum, const HMatrixR4& in_maximum )
{
	HMatrixR4 value( in_value );
	LocalClamp( value, in_minimum, in_maximum );
	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HVectorU1 Hubris::HMathUtility::Maximum< HVectorU1 >( const HVectorU1& in_lhs, const HVectorU1& in_rhs )
{
	HVectorU1 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorU2 Hubris::HMathUtility::Maximum< HVectorU2 >( const HVectorU2& in_lhs, const HVectorU2& in_rhs )
{
	HVectorU2 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorU3 Hubris::HMathUtility::Maximum< HVectorU3 >( const HVectorU3& in_lhs, const HVectorU3& in_rhs )
{
	HVectorU3 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorU4 Hubris::HMathUtility::Maximum< HVectorU4 >( const HVectorU4& in_lhs, const HVectorU4& in_rhs )
{
	HVectorU4 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixU2 Hubris::HMathUtility::Maximum< HMatrixU2 >( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs )
{
	HMatrixU2 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixU3 Hubris::HMathUtility::Maximum< HMatrixU3 >( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs )
{
	HMatrixU3 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixU4 Hubris::HMathUtility::Maximum< HMatrixU4 >( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs )
{
	HMatrixU4 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}

template<>
const HVectorS1 Hubris::HMathUtility::Maximum< HVectorS1 >( const HVectorS1& in_lhs, const HVectorS1& in_rhs )
{
	HVectorS1 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorS2 Hubris::HMathUtility::Maximum< HVectorS2 >( const HVectorS2& in_lhs, const HVectorS2& in_rhs )
{
	HVectorS2 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorS3 Hubris::HMathUtility::Maximum< HVectorS3 >( const HVectorS3& in_lhs, const HVectorS3& in_rhs )
{
	HVectorS3 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorS4 Hubris::HMathUtility::Maximum< HVectorS4 >( const HVectorS4& in_lhs, const HVectorS4& in_rhs )
{
	HVectorS4 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixS2 Hubris::HMathUtility::Maximum< HMatrixS2 >( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs )
{
	HMatrixS2 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixS3 Hubris::HMathUtility::Maximum< HMatrixS3 >( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs )
{
	HMatrixS3 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixS4 Hubris::HMathUtility::Maximum< HMatrixS4 >( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs )
{
	HMatrixS4 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}

template<>
const HVectorR1 Hubris::HMathUtility::Maximum< HVectorR1 >( const HVectorR1& in_lhs, const HVectorR1& in_rhs )
{
	HVectorR1 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorR2 Hubris::HMathUtility::Maximum< HVectorR2 >( const HVectorR2& in_lhs, const HVectorR2& in_rhs )
{
	HVectorR2 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::Maximum< HVectorR3 >( const HVectorR3& in_lhs, const HVectorR3& in_rhs )
{
	HVectorR3 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::Maximum< HVectorR4 >( const HVectorR4& in_lhs, const HVectorR4& in_rhs )
{
	HVectorR4 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixR2 Hubris::HMathUtility::Maximum< HMatrixR2 >( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs )
{
	HMatrixR2 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixR3 Hubris::HMathUtility::Maximum< HMatrixR3 >( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs )
{
	HMatrixR3 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixR4 Hubris::HMathUtility::Maximum< HMatrixR4 >( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs )
{
	HMatrixR4 value;
	LocalMaximum( value, in_lhs, in_rhs );
	return value;
}


/*
	Minimum
*/
template<>
const HVectorU1 Hubris::HMathUtility::Minimum< HVectorU1 >( const HVectorU1& in_lhs, const HVectorU1& in_rhs )
{
	HVectorU1 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorU2 Hubris::HMathUtility::Minimum< HVectorU2 >( const HVectorU2& in_lhs, const HVectorU2& in_rhs )
{
	HVectorU2 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorU3 Hubris::HMathUtility::Minimum< HVectorU3 >( const HVectorU3& in_lhs, const HVectorU3& in_rhs )
{
	HVectorU3 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorU4 Hubris::HMathUtility::Minimum< HVectorU4 >( const HVectorU4& in_lhs, const HVectorU4& in_rhs )
{
	HVectorU4 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixU2 Hubris::HMathUtility::Minimum< HMatrixU2 >( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs )
{
	HMatrixU2 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixU3 Hubris::HMathUtility::Minimum< HMatrixU3 >( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs )
{
	HMatrixU3 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixU4 Hubris::HMathUtility::Minimum< HMatrixU4 >( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs )
{
	HMatrixU4 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}

template<>
const HVectorS1 Hubris::HMathUtility::Minimum< HVectorS1 >( const HVectorS1& in_lhs, const HVectorS1& in_rhs )
{
	HVectorS1 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorS2 Hubris::HMathUtility::Minimum< HVectorS2 >( const HVectorS2& in_lhs, const HVectorS2& in_rhs )
{
	HVectorS2 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorS3 Hubris::HMathUtility::Minimum< HVectorS3 >( const HVectorS3& in_lhs, const HVectorS3& in_rhs )
{
	HVectorS3 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorS4 Hubris::HMathUtility::Minimum< HVectorS4 >( const HVectorS4& in_lhs, const HVectorS4& in_rhs )
{
	HVectorS4 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixS2 Hubris::HMathUtility::Minimum< HMatrixS2 >( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs )
{
	HMatrixS2 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixS3 Hubris::HMathUtility::Minimum< HMatrixS3 >( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs )
{
	HMatrixS3 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixS4 Hubris::HMathUtility::Minimum< HMatrixS4 >( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs )
{
	HMatrixS4 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}

template<>
const HVectorR1 Hubris::HMathUtility::Minimum< HVectorR1 >( const HVectorR1& in_lhs, const HVectorR1& in_rhs )
{
	HVectorR1 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorR2 Hubris::HMathUtility::Minimum< HVectorR2 >( const HVectorR2& in_lhs, const HVectorR2& in_rhs )
{
	HVectorR2 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::Minimum< HVectorR3 >( const HVectorR3& in_lhs, const HVectorR3& in_rhs )
{
	HVectorR3 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::Minimum< HVectorR4 >( const HVectorR4& in_lhs, const HVectorR4& in_rhs )
{
	HVectorR4 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixR2 Hubris::HMathUtility::Minimum< HMatrixR2 >( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs )
{
	HMatrixR2 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixR3 Hubris::HMathUtility::Minimum< HMatrixR3 >( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs )
{
	HMatrixR3 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}
template<>
const HMatrixR4 Hubris::HMathUtility::Minimum< HMatrixR4 >( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs )
{
	HMatrixR4 value;
	LocalMinimum( value, in_lhs, in_rhs );
	return value;
}

/*
	Absolute
*/
template<>
const HVectorU1 Hubris::HMathUtility::Absolute< HVectorU1 >( const HVectorU1& in_src )
{
	HVectorU1 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorU2 Hubris::HMathUtility::Absolute< HVectorU2 >( const HVectorU2& in_src )
{
	HVectorU2 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorU3 Hubris::HMathUtility::Absolute< HVectorU3 >( const HVectorU3& in_src )
{
	HVectorU3 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorU4 Hubris::HMathUtility::Absolute< HVectorU4 >( const HVectorU4& in_src )
{
	HVectorU4 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixU2 Hubris::HMathUtility::Absolute< HMatrixU2 >( const HMatrixU2& in_src )
{
	HMatrixU2 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixU3 Hubris::HMathUtility::Absolute< HMatrixU3 >( const HMatrixU3& in_src )
{
	HMatrixU3 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixU4 Hubris::HMathUtility::Absolute< HMatrixU4 >( const HMatrixU4& in_src )
{
	HMatrixU4 value;
	LocalAbsolute( value, in_src );
	return value;
}

template<>
const HVectorS1 Hubris::HMathUtility::Absolute< HVectorS1 >( const HVectorS1& in_src )
{
	HVectorS1 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorS2 Hubris::HMathUtility::Absolute< HVectorS2 >( const HVectorS2& in_src )
{
	HVectorS2 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorS3 Hubris::HMathUtility::Absolute< HVectorS3 >( const HVectorS3& in_src )
{
	HVectorS3 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorS4 Hubris::HMathUtility::Absolute< HVectorS4 >( const HVectorS4& in_src )
{
	HVectorS4 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixS2 Hubris::HMathUtility::Absolute< HMatrixS2 >( const HMatrixS2& in_src )
{
	HMatrixS2 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixS3 Hubris::HMathUtility::Absolute< HMatrixS3 >( const HMatrixS3& in_src )
{
	HMatrixS3 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixS4 Hubris::HMathUtility::Absolute< HMatrixS4 >( const HMatrixS4& in_src )
{
	HMatrixS4 value;
	LocalAbsolute( value, in_src );
	return value;
}

template<>
const HVectorR1 Hubris::HMathUtility::Absolute< HVectorR1 >( const HVectorR1& in_src )
{
	HVectorR1 value;
	LocalAbsolute( value, in_src );
	return value;
}

/**/
//template< typename IN_TYPE >
//const IN_TYPE Hubris::HMathUtility::Absolute( const IN_TYPE& in_src )
//{
//	IN_TYPE returnValue;
//	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
//	{
//		returnValue[ index ] = HMathUtility::Absolute( in_src[ index ] );
//	}
//
//	return returnValue;
//}
//template const HVectorR2 Hubris::HMathUtility::Absolute< HVectorR2 >( const HVectorR2& in_src );


//template< typename IN_TYPE >
//const HBOOL Hubris::HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
//{
//	return LocalEpsilonZero( in_lhs - in_rhs );
//}
//
//template const HBOOL HMathUtility::EpsilonEqual< HU8 >( const HU8& in_lhs, const HU8& in_rhs );
//template const HBOOL HMathUtility::EpsilonEqual< HSINT >( const HSINT& in_lhs, const HSINT& in_rhs );
//template const HBOOL HMathUtility::EpsilonEqual< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs );

//{
//	HVectorR2 value;
//	LocalAbsolute( value, in_src );
//	return value;
//}

template<>
const HVectorR2 Hubris::HMathUtility::Absolute< HVectorR2 >( const HVectorR2& in_src )
{
	HVectorR2 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::Absolute< HVectorR3 >( const HVectorR3& in_src )
{
	HVectorR3 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::Absolute< HVectorR4 >( const HVectorR4& in_src )
{
	HVectorR4 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixR2 Hubris::HMathUtility::Absolute< HMatrixR2 >( const HMatrixR2& in_src )
{
	HMatrixR2 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixR3 Hubris::HMathUtility::Absolute< HMatrixR3 >( const HMatrixR3& in_src )
{
	HMatrixR3 value;
	LocalAbsolute( value, in_src );
	return value;
}
template<>
const HMatrixR4 Hubris::HMathUtility::Absolute< HMatrixR4 >( const HMatrixR4& in_src )
{
	HMatrixR4 value;
	LocalAbsolute( value, in_src );
	return value;
}

/*
	Lerp
*/
template<>
const HVectorU1 Hubris::HMathUtility::Lerp< HVectorU1 >( const HVectorU1& in_lhs, const HVectorU1& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorU1 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorU2 Hubris::HMathUtility::Lerp< HVectorU2 >( const HVectorU2& in_lhs, const HVectorU2& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorU2 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorU3 Hubris::HMathUtility::Lerp< HVectorU3 >( const HVectorU3& in_lhs, const HVectorU3& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorU3 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorU4 Hubris::HMathUtility::Lerp< HVectorU4 >( const HVectorU4& in_lhs, const HVectorU4& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorU4 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixU2 Hubris::HMathUtility::Lerp< HMatrixU2 >( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixU2 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixU3 Hubris::HMathUtility::Lerp< HMatrixU3 >( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixU3 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixU4 Hubris::HMathUtility::Lerp< HMatrixU4 >( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixU4 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}

template<>
const HVectorS1 Hubris::HMathUtility::Lerp< HVectorS1 >( const HVectorS1& in_lhs, const HVectorS1& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorS1 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorS2 Hubris::HMathUtility::Lerp< HVectorS2 >( const HVectorS2& in_lhs, const HVectorS2& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorS2 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorS3 Hubris::HMathUtility::Lerp< HVectorS3 >( const HVectorS3& in_lhs, const HVectorS3& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorS3 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorS4 Hubris::HMathUtility::Lerp< HVectorS4 >( const HVectorS4& in_lhs, const HVectorS4& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorS4 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixS2 Hubris::HMathUtility::Lerp< HMatrixS2 >( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixS2 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixS3 Hubris::HMathUtility::Lerp< HMatrixS3 >( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixS3 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixS4 Hubris::HMathUtility::Lerp< HMatrixS4 >( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixS4 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}

template<>
const HVectorR1 Hubris::HMathUtility::Lerp< HVectorR1 >( const HVectorR1& in_lhs, const HVectorR1& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorR1 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorR2 Hubris::HMathUtility::Lerp< HVectorR2 >( const HVectorR2& in_lhs, const HVectorR2& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorR2 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::Lerp< HVectorR3 >( const HVectorR3& in_lhs, const HVectorR3& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorR3 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::Lerp< HVectorR4 >( const HVectorR4& in_lhs, const HVectorR4& in_rhs, const Hubris::HREAL in_ratio )
{
	HVectorR4 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixR2 Hubris::HMathUtility::Lerp< HMatrixR2 >( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixR2 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixR3 Hubris::HMathUtility::Lerp< HMatrixR3 >( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixR3 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}
template<>
const HMatrixR4 Hubris::HMathUtility::Lerp< HMatrixR4 >( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs, const Hubris::HREAL in_ratio )
{
	HMatrixR4 value;
	LocalLerp( value, in_lhs, in_rhs, in_ratio );
	return value;
}

/*
	SplineHermite
*/
template<>
const HVectorR2 Hubris::HMathUtility::SplineHermite< HVectorR2 >(
	const HREAL in_ratio,
	const HVectorR2& in_lhs, 
	const HVectorR2& in_rhs, 
	const HVectorR2& in_lhsTangent, 
	const HVectorR2& in_rhsTangent
	)
{
	HVectorR2 value;
	LocalSplineHermite( value, in_ratio, in_lhs, in_rhs, in_lhsTangent, in_rhsTangent );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::SplineHermite< HVectorR3 >(
	const HREAL in_ratio,
	const HVectorR3& in_lhs, 
	const HVectorR3& in_rhs, 
	const HVectorR3& in_lhsTangent, 
	const HVectorR3& in_rhsTangent
	)
{
	HVectorR3 value;
	LocalSplineHermite( value, in_ratio, in_lhs, in_rhs, in_lhsTangent, in_rhsTangent );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::SplineHermite< HVectorR4 >(
	const HREAL in_ratio,
	const HVectorR4& in_lhs, 
	const HVectorR4& in_rhs, 
	const HVectorR4& in_lhsTangent, 
	const HVectorR4& in_rhsTangent
	)
{
	HVectorR4 value;
	LocalSplineHermite( value, in_ratio, in_lhs, in_rhs, in_lhsTangent, in_rhsTangent );
	return value;
}

/*
	SplineTangentGet
*/
template<>
const HVectorR2 Hubris::HMathUtility::SplineTangentGet< HVectorR2 >(
	const HVectorR2& in_lhs, 
	const HVectorR2& in_rhs, 
	const HREAL in_bias
	)
{
	HVectorR2 value;
	LocalSplineTangent( value, in_lhs, in_rhs, in_bias );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::SplineTangentGet< HVectorR3 >(
	const HVectorR3& in_lhs, 
	const HVectorR3& in_rhs, 
	const HREAL in_bias
	)
{
	HVectorR3 value;
	LocalSplineTangent( value, in_lhs, in_rhs, in_bias );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::SplineTangentGet< HVectorR4 >(
	const HVectorR4& in_lhs, 
	const HVectorR4& in_rhs, 
	const HREAL in_bias
	)
{
	HVectorR4 value;
	LocalSplineTangent( value, in_lhs, in_rhs, in_bias );
	return value;
}

/*
	SplineCatmullRom
*/
template<>
const HVectorR2 Hubris::HMathUtility::SplineCatmullRom< HVectorR2 >(
	const HREAL in_ratio,
	const HVectorR2& in_point0, 
	const HVectorR2& in_point1, 
	const HVectorR2& in_point2, 
	const HVectorR2& in_point3
	)
{
	HVectorR2 value;
	LocalSplineCatmullRom( value, in_ratio, in_point0, in_point1, in_point2, in_point3 );
	return value;
}
template<>
const HVectorR3 Hubris::HMathUtility::SplineCatmullRom< HVectorR3 >(
	const HREAL in_ratio,
	const HVectorR3& in_point0, 
	const HVectorR3& in_point1, 
	const HVectorR3& in_point2, 
	const HVectorR3& in_point3
	)
{
	HVectorR3 value;
	LocalSplineCatmullRom( value, in_ratio, in_point0, in_point1, in_point2, in_point3 );
	return value;
}
template<>
const HVectorR4 Hubris::HMathUtility::SplineCatmullRom< HVectorR4 >(
	const HREAL in_ratio,
	const HVectorR4& in_point0, 
	const HVectorR4& in_point1, 
	const HVectorR4& in_point2, 
	const HVectorR4& in_point3
	)
{
	HVectorR4 value;
	LocalSplineCatmullRom( value, in_ratio, in_point0, in_point1, in_point2, in_point3 );
	return value;
}

/*
	Valid
*/
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorU1 >( const HVectorU1& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorU2 >( const HVectorU2& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorU3 >( const HVectorU3& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorU4 >( const HVectorU4& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixU2 >( const HMatrixU2& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixU3 >( const HMatrixU3& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixU4 >( const HMatrixU4& in_src )
{
	return LocalValid(  in_src );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorS1 >( const HVectorS1& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorS2 >( const HVectorS2& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorS3 >( const HVectorS3& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorS4 >( const HVectorS4& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixS2 >( const HMatrixS2& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixS3 >( const HMatrixS3& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixS4 >( const HMatrixS4& in_src )
{
	return LocalValid(  in_src );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorR1 >( const HVectorR1& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorR2 >( const HVectorR2& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorR3 >( const HVectorR3& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HVectorR4 >( const HVectorR4& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixR2 >( const HMatrixR2& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixR3 >( const HMatrixR3& in_src )
{
	return LocalValid(  in_src );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::Valid< HMatrixR4 >( const HMatrixR4& in_src )
{
	return LocalValid(  in_src );
}

/*
	ValidNot
*/
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorU1 >( const HVectorU1& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorU2 >( const HVectorU2& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorU3 >( const HVectorU3& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorU4 >( const HVectorU4& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixU2 >( const HMatrixU2& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixU3 >( const HMatrixU3& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixU4 >( const HMatrixU4& in_src )
{
	return( !LocalValid( in_src ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorS1 >( const HVectorS1& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorS2 >( const HVectorS2& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorS3 >( const HVectorS3& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorS4 >( const HVectorS4& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixS2 >( const HMatrixS2& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixS3 >( const HMatrixS3& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixS4 >( const HMatrixS4& in_src )
{
	return( !LocalValid( in_src ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorR1 >( const HVectorR1& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorR2 >( const HVectorR2& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorR3 >( const HVectorR3& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HVectorR4 >( const HVectorR4& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixR2 >( const HMatrixR2& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixR3 >( const HMatrixR3& in_src )
{
	return( !LocalValid( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::ValidNot< HMatrixR4 >( const HMatrixR4& in_src )
{
	return( !LocalValid( in_src ) );
}

/*
	EpsilonZero
*/
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorU1 >( const HVectorU1& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorU2 >( const HVectorU2& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorU3 >( const HVectorU3& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorU4 >( const HVectorU4& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixU2 >( const HMatrixU2& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixU3 >( const HMatrixU3& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixU4 >( const HMatrixU4& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorS1 >( const HVectorS1& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorS2 >( const HVectorS2& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorS3 >( const HVectorS3& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorS4 >( const HVectorS4& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixS2 >( const HMatrixS2& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixS3 >( const HMatrixS3& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixS4 >( const HMatrixS4& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorR1 >( const HVectorR1& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorR2 >( const HVectorR2& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorR3 >( const HVectorR3& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HVectorR4 >( const HVectorR4& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixR2 >( const HMatrixR2& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixR3 >( const HMatrixR3& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZero< HMatrixR4 >( const HMatrixR4& in_src )
{
	return( LocalEpsilonZero( in_src ) );
}

/*
	EpsilonZeroNot
*/
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorU1 >( const HVectorU1& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorU2 >( const HVectorU2& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorU3 >( const HVectorU3& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorU4 >( const HVectorU4& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixU2 >( const HMatrixU2& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixU3 >( const HMatrixU3& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixU4 >( const HMatrixU4& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorS1 >( const HVectorS1& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorS2 >( const HVectorS2& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorS3 >( const HVectorS3& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorS4 >( const HVectorS4& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixS2 >( const HMatrixS2& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixS3 >( const HMatrixS3& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixS4 >( const HMatrixS4& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorR1 >( const HVectorR1& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorR2 >( const HVectorR2& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorR3 >( const HVectorR3& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HVectorR4 >( const HVectorR4& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixR2 >( const HMatrixR2& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixR3 >( const HMatrixR3& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonZeroNot< HMatrixR4 >( const HMatrixR4& in_src )
{
	return( !LocalEpsilonZero( in_src ) );
}

/*
	EpsilonEqual
*/
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorU1 >( const HVectorU1& in_lhs, const HVectorU1& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorU2 >( const HVectorU2& in_lhs, const HVectorU2& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorU3 >( const HVectorU3& in_lhs, const HVectorU3& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorU4 >( const HVectorU4& in_lhs, const HVectorU4& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixU2 >( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixU3 >( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixU4 >( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorS1 >( const HVectorS1& in_lhs, const HVectorS1& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorS2 >( const HVectorS2& in_lhs, const HVectorS2& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorS3 >( const HVectorS3& in_lhs, const HVectorS3& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorS4 >( const HVectorS4& in_lhs, const HVectorS4& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixS2 >( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixS3 >( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixS4 >( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorR1 >( const HVectorR1& in_lhs, const HVectorR1& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorR2 >( const HVectorR2& in_lhs, const HVectorR2& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorR3 >( const HVectorR3& in_lhs, const HVectorR3& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HVectorR4 >( const HVectorR4& in_lhs, const HVectorR4& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixR2 >( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixR3 >( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqual< HMatrixR4 >( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs )
{
	return( LocalEpsilonEqual( in_lhs, in_rhs ) );
}

/*
	EpsilonEqualNot
*/
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorU1 >( const HVectorU1& in_lhs, const HVectorU1& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorU2 >( const HVectorU2& in_lhs, const HVectorU2& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorU3 >( const HVectorU3& in_lhs, const HVectorU3& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorU4 >( const HVectorU4& in_lhs, const HVectorU4& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixU2 >( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixU3 >( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixU4 >( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorS1 >( const HVectorS1& in_lhs, const HVectorS1& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorS2 >( const HVectorS2& in_lhs, const HVectorS2& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorS3 >( const HVectorS3& in_lhs, const HVectorS3& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorS4 >( const HVectorS4& in_lhs, const HVectorS4& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixS2 >( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixS3 >( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixS4 >( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}

template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorR1 >( const HVectorR1& in_lhs, const HVectorR1& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorR2 >( const HVectorR2& in_lhs, const HVectorR2& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorR3 >( const HVectorR3& in_lhs, const HVectorR3& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HVectorR4 >( const HVectorR4& in_lhs, const HVectorR4& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixR2 >( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixR3 >( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const Hubris::HBOOL Hubris::HMathUtility::EpsilonEqualNot< HMatrixR4 >( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs )
{
	return( !LocalEpsilonEqual( in_lhs, in_rhs ) );
}

/**/
