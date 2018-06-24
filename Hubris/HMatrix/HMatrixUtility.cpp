//file: Hubris/HMatrix/HMatrixUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixUtility.h"

#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixConstructor.h"
#include "Hubris/HMatrix/HMatrixOperator.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HMath/HMath.h"
#include "Hubris/HMath/HMathUtility.h"
#include "Hubris/HVariables/HVariablesMath.h"
#include "Hubris/HQuaternion/HQuaternion_Export.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// static local methods
/**/
template< typename IN_TYPE, HSINT IN_WIDTH >const IN_TYPE LocalDeterminant( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src );

template<>const HREAL LocalDeterminant( const HMatrix< HREAL, 2, 2 >& in_src )
{
	return( ( in_src[ 0 ] * in_src[ 3 ] ) - ( in_src[ 1 ] * in_src[ 2 ] ) );
}

template<>const HSINT LocalDeterminant( const HMatrix< HSINT, 2, 2 >& in_src )
{
	return( ( in_src[ 0 ] * in_src[ 3 ] ) - ( in_src[ 1 ] * in_src[ 2 ] ) );
}

template< typename IN_TYPE, HSINT IN_WIDTH >const IN_TYPE LocalDeterminant( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src )
{
	IN_TYPE determinamt = HVariablesMath::ZeroGet< IN_TYPE >();
	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;

	for( HSINT x = 0; x < IN_WIDTH; ++x )
	{
		const TSubMatrix subMatrix = HMatrixUtility::MinorMatrixGet< HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >, TSubMatrix >( in_src, x, 0 );
		const IN_TYPE value = ( in_src[ x ] * LocalDeterminant< IN_TYPE, IN_WIDTH - 1 >( subMatrix ) );;

		if( x & 1 )
		{
			determinamt -= value;
		}
		else
		{
			determinamt += value;
		}
	}

	return determinamt;
}

/**/
template< typename IN_TYPE >
static const IN_TYPE LocalIdentity()
{
	IN_TYPE returnMatrix;

	HCOMMON_ASSERT_STATIC( IN_TYPE::TVar::TWidth == IN_TYPE::TVar::THeight, width_and_height_must_match );

	for( HSINT y = 0; y < IN_TYPE::TVar::THeight; ++y )
	{
		for( HSINT x = 0; x < IN_TYPE::TVar::TWidth; ++x )
		{
			const HSINT index = IN_TYPE::IndexGet( x, y );
			if( x == y )
			{
				returnMatrix[ index ] = HVariablesMath::UnitGet< IN_TYPE::TType >(); 
			}
			else
			{
				returnMatrix[ index ] = HVariablesMath::ZeroGet< IN_TYPE::TType >();
			}
		}
	}

	return returnMatrix;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH >static HVOID LocalInverse( HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& out_value, const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src );

template<>HVOID LocalInverse( HMatrixR2& out_value, const HMatrixR2& in_src )
{
	const HREAL determinant = HMatrixUtility::Determinant( in_src );

	for( HSINT x = 0; x < 2; ++x )
	{
		for( HSINT y = 0; y < 2; ++y )
		{
			const HREAL subDeterminant = in_src[ HMatrixR2::IndexGet( x, y ) ];
			if( ( x + y ) & 1 )
			{
				out_value[ HMatrixR2::IndexGet( y, x ) ] = -( subDeterminant / determinant );
			}
			else
			{
				out_value[ HMatrixR2::IndexGet( y, x ) ] = ( subDeterminant / determinant );
			}
		}
	}

	return;
}

template< typename IN_TYPE, HSINT IN_WIDTH >
HVOID LocalInverse( HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& out_value, const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src )
{
	typedef HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH>TMatrix;
	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
	const IN_TYPE determinant = HMatrixUtility::Determinant( in_src );
	if( HMathUtility::EpsilonZero( determinant ) )
	{
		out_value = HMatrixUtility::IdentityGet< TMatrix >();
		return;
	}
	const IN_TYPE invertedDeterminant = HVariablesMath::UnitGet< IN_TYPE >() / determinant;

	for( HSINT x = 0; x < IN_WIDTH; ++x )
	{
		for( HSINT y = 0; y < IN_WIDTH; ++y )
		{
			const TSubMatrix subMatrix = HMatrixUtility::MinorMatrixGet< TMatrix, TSubMatrix >( in_src, x, y );
			const IN_TYPE subDeterminant = HMatrixUtility::Determinant( subMatrix );
			if( ( x + y ) & 1 )
			{
				out_value[ TMatrix::IndexGet( y, x ) ] = -( subDeterminant * invertedDeterminant );
			}
			else
			{
				out_value[ TMatrix::IndexGet( y, x ) ] = ( subDeterminant * invertedDeterminant );
			}
		}
	}

	return;
}

/**
template< typename IN_TYPE, HSINT IN_SIZE > 
typename const HMatrix< IN_TYPE, IN_SIZE - 1, 1 > LocalTranslateGet( 
	const HMatrix< IN_TYPE, IN_SIZE, IN_SIZE >& in_src 
	)
{
	HREAL data[ IN_SIZE - 1 ];

	for( HSINT index = 0; index < IN_SIZE - 1; ++index )
	{
		data[ index ] = in_src[ HMatrix< IN_TYPE, IN_SIZE, IN_SIZE >::IndexGet( index, IN_SIZE - 1 ) ]; 
	}

	return HMatrix< IN_TYPE, IN_SIZE - 1, 1 >( data );
}

/**
template< typename IN_TYPE, HSINT IN_SIZE > 
HVOID LocalTranslateSet( 
	HMatrix< IN_TYPE, IN_SIZE, IN_SIZE >& out_matrix, 
	const HMatrix< IN_TYPE, IN_SIZE - 1, 1 >& in_translate 
	)
{
	for( HSINT index = 0; index < IN_SIZE - 1; ++index )
	{
		out_matrix[ HMatrix< IN_TYPE, IN_SIZE, IN_SIZE >::IndexGet( index, IN_SIZE - 1 ) ] = in_translate[ index ];
	}

	return;
}

///////////////////////////////////////////////////
// static public methods
///**/
template< typename IN_TYPE > 
const HSINT Hubris::HMatrixUtility::AxisFindLargest( const IN_TYPE& in_vector )
{
	IN_TYPE::TType maxValue = HVariablesMath::MinimumGet< IN_TYPE::TType >();
	HSINT maxIndex = HCOMMON_INVALID_INDEX;

	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		const IN_TYPE::TType testValue = in_vector[ index ];
		if( maxValue < testValue )
		{
			maxValue = testValue;
			maxIndex = index;
		}
	}

	return maxIndex;
}

template const HSINT Hubris::HMatrixUtility::AxisFindLargest( const HVectorS2& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindLargest( const HVectorS3& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindLargest( const HVectorS4& in_vector );

template const HSINT Hubris::HMatrixUtility::AxisFindLargest( const HVectorR2& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindLargest( const HVectorR3& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindLargest( const HVectorR4& in_vector );

/**/
template< typename IN_TYPE > 
const HSINT Hubris::HMatrixUtility::AxisFindSmallest( const IN_TYPE& in_vector )
{
	IN_TYPE::TType minValue = HVariablesMath::MaximumGet< IN_TYPE::TType >();
	HSINT minIndex = HCOMMON_INVALID_INDEX;

	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		const IN_TYPE::TType testValue = in_vector[ index ];
		if( testValue < minValue )
		{
			minValue = testValue;
			minIndex = index;
		}
	}

	return minIndex;
}

template const HSINT Hubris::HMatrixUtility::AxisFindSmallest( const HVectorS2& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindSmallest( const HVectorS3& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindSmallest( const HVectorS4& in_vector );

template const HSINT Hubris::HMatrixUtility::AxisFindSmallest( const HVectorR2& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindSmallest( const HVectorR3& in_vector );
template const HSINT Hubris::HMatrixUtility::AxisFindSmallest( const HVectorR4& in_vector );

/**/
template< typename IN_TYPE > 
const HSINT Hubris::HMatrixUtility::AxisFindLargestAbsoluteSigned( const IN_TYPE& in_vector, Hubris::HBOOL& out_negative )	
{
	IN_TYPE::TType maxValue = HVariablesMath::MinimumGet< IN_TYPE::TType >();
	HSINT bestIndex = HCOMMON_INVALID_INDEX;
	out_negative = HFALSE;

	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		const IN_TYPE::TType testValue = HMathUtility::Absolute( in_vector[ index ] );
		if( maxValue < testValue )
		{
			bestIndex = index;
			maxValue = testValue;
			out_negative = ( in_vector[ index ] < 0 );
		}
	}

	return bestIndex;
}

template const HSINT Hubris::HMatrixUtility::AxisFindLargestAbsoluteSigned( const HVectorS2& in_vector, Hubris::HBOOL& out_negative );
template const HSINT Hubris::HMatrixUtility::AxisFindLargestAbsoluteSigned( const HVectorS3& in_vector, Hubris::HBOOL& out_negative );
template const HSINT Hubris::HMatrixUtility::AxisFindLargestAbsoluteSigned( const HVectorS4& in_vector, Hubris::HBOOL& out_negative );

template const HSINT Hubris::HMatrixUtility::AxisFindLargestAbsoluteSigned( const HVectorR2& in_vector, Hubris::HBOOL& out_negative );
template const HSINT Hubris::HMatrixUtility::AxisFindLargestAbsoluteSigned( const HVectorR3& in_vector, Hubris::HBOOL& out_negative );
template const HSINT Hubris::HMatrixUtility::AxisFindLargestAbsoluteSigned( const HVectorR4& in_vector, Hubris::HBOOL& out_negative );

/**/

/*
	Compose
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::Compose( 
	const IN_TYPE& in_matrixRotate,
	const IN_TYPE& in_matrixScale,
	const IN_TYPE& in_matrixTranslate
	)
{
	return( in_matrixScale * in_matrixRotate * in_matrixTranslate );
}

template const HMatrixR4 Hubris::HMatrixUtility::Compose( const HMatrixR4& in_matrixRotate, const HMatrixR4& in_matrixScale, const HMatrixR4& in_matrixTranslate );

/*
	CrossProduct
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::CrossProduct( const IN_TYPE& in_lhs )
{
	typename const IN_TYPE::TType* const pDataLhs = in_lhs.DataGet();
	IN_TYPE::TType data[ IN_TYPE::TVar::TSize ];
	data[ 0 ] = -( pDataLhs[ 1 ] );
	data[ 1 ] = ( pDataLhs[ 0 ] );
	return( IN_TYPE( data ) );
}

template const HVectorS2 Hubris::HMatrixUtility::CrossProduct( const HVectorS2& in_lhs );
template const HVectorR2 Hubris::HMatrixUtility::CrossProduct( const HVectorR2& in_lhs );

/*
	CrossProduct
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::CrossProduct( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	typename const IN_TYPE::TType* const pDataLhs = in_lhs.DataGet();
	typename const IN_TYPE::TType* const pDataRhs = in_rhs.DataGet();
	IN_TYPE::TType data[ IN_TYPE::TVar::TSize ];
	data[ 0 ] = ( pDataLhs[ 1 ] * pDataRhs[ 2 ] ) - ( pDataLhs[ 2 ] * pDataRhs[ 1 ] );
	data[ 1 ] = ( pDataLhs[ 2 ] * pDataRhs[ 0 ] ) - ( pDataLhs[ 0 ] * pDataRhs[ 2 ] );
	data[ 2 ] = ( pDataLhs[ 0 ] * pDataRhs[ 1 ] ) - ( pDataLhs[ 1 ] * pDataRhs[ 0 ] );
	return( IN_TYPE( data ) );
}

template const HVectorS3 Hubris::HMatrixUtility::CrossProduct( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
template const HVectorR3 Hubris::HMatrixUtility::CrossProduct( const HVectorR3& in_lhs, const HVectorR3& in_rhs );


/**/
template< typename IN_TYPE > 
const IN_TYPE Hubris::HMatrixUtility::CrossVector( const IN_TYPE& in_src )
{
	//find smallest axis
	const IN_TYPE localDirection( HMathUtility::Absolute( in_src ) );
	HVectorR3 crossAxis;
	const HSINT minAxis = AxisFindSmallest( HMathUtility::Absolute( in_src ) );
	crossAxis[ minAxis ] = HVariablesMath::UnitGet< IN_TYPE::TType >();

	//cross with unit vector on smallest axis
	HVectorR3 resultCross = CrossProduct( in_src, crossAxis );

	return resultCross;
}

template const HVectorR3 Hubris::HMatrixUtility::CrossVector( const HVectorR3& in_src );

/*
	Decompose
*/
template< typename IN_TYPE >
HVOID Hubris::HMatrixUtility::Decompose( 
	IN_TYPE& out_matrixRotate,
	IN_TYPE& out_matrixScale,
	IN_TYPE& out_matrixTranslate,
	const IN_TYPE& in_matrix
	)
{
	out_matrixRotate = in_matrix;
	out_matrixTranslate = HMatrixUtility::IdentityGet< IN_TYPE >();
	out_matrixScale = HMatrixUtility::IdentityGet< IN_TYPE >();

	typename const IN_TYPE::TType scale = HMatrixUtility::RotationLengthSquaredGet( in_matrix );
	HMatrixUtility::RotationLengthSquaredSet( out_matrixScale, scale );
	HMatrixUtility::RotationLengthSquaredSet( out_matrixRotate, 3.0F );

	typedef HMatrix< IN_TYPE::TType, IN_TYPE::TVar::TWidth - 1, 1 >TSubVector;
	TranslateSet( out_matrixRotate, TSubVector() );
	TranslateSet( out_matrixTranslate, TranslateGet< IN_TYPE, TSubVector >( in_matrix ) );
	return;
}

template HVOID Hubris::HMatrixUtility::Decompose( HMatrixR4& out_matrixRotate, HMatrixR4& out_matrixScale, HMatrixR4& out_matrixTranslate, const HMatrixR4& in_matrix );

/*
	DecomposeTransform
*/
template< typename IN_MATRIX, typename IN_QUATERNION, typename IN_VECTOR, typename IN_SCALE >
HVOID Hubris::HMatrixUtility::DecomposeTransform( 
	IN_QUATERNION& out_rotate,
	IN_VECTOR& out_translate,
	IN_SCALE& out_scale,
	const IN_MATRIX& in_matrix
	)
{
	IN_MATRIX matrixRotate;
	IN_MATRIX matrixScale;
	IN_MATRIX matrixTranslate;
	Decompose( matrixRotate, matrixScale, matrixTranslate, in_matrix );

	out_rotate = HQuaternionUtility::ConvertFromMatrix4( matrixRotate );
	out_translate = HMatrixUtility::TranslateGet< IN_MATRIX, IN_VECTOR >( matrixTranslate );

	typedef HMatrix< IN_SCALE, 3, 3 >TMinorMatrix;
	const HREAL scale = HMatrixUtility::LengthSquared( HMatrixUtility::MinorMatrixGet< HMatrixR4, TMinorMatrix >( matrixScale, 3, 3 ) ) / 3.0F;
	out_scale = HMath::SquareRoot( scale );

	return;
}

template HVOID Hubris::HMatrixUtility::DecomposeTransform( 
	HQuaternionREAL& out_rotate,
	HVectorR3& out_translate,
	HREAL& out_scale,
	const HMatrixR4& in_matrix
	);

/*
	ComposeTransform
*/
template< typename IN_MATRIX, typename IN_QUATERNION, typename IN_VECTOR, typename IN_SCALE >static HVOID Hubris::HMatrixUtility::ComposeTransform( 
	IN_MATRIX& out_matrix,
	const IN_QUATERNION& in_rotate,
	const IN_VECTOR& in_translate,
	const IN_SCALE& in_scale
	)
{
	IN_MATRIX matrixRotate = IdentityGet< IN_MATRIX >();
	IN_MATRIX matrixScale = IdentityGet< IN_MATRIX >();
	IN_MATRIX matrixTranslate = IdentityGet< IN_MATRIX >();

	matrixRotate = HQuaternionUtility::ConvertToMatrix4( in_rotate );

	HMatrixUtility::TranslateSet< IN_MATRIX, IN_VECTOR >( matrixTranslate, in_translate );

	matrixScale *= in_scale;
	matrixScale[ 15 ] = 1.0F;

	out_matrix = Compose( matrixRotate, matrixScale, matrixTranslate );

	return;
}

template HVOID Hubris::HMatrixUtility::ComposeTransform( 
	HMatrixR4& out_matrix,
	const HQuaternionREAL& in_rotate,
	const HVectorR3& in_translate,
	const HREAL& in_scale
	);

/*
	Determinant
*/
template< typename IN_TYPE, HSINT IN_WIDTH >
const IN_TYPE Hubris::HMatrixUtility::Determinant( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_value )
{
	const IN_TYPE value = LocalDeterminant( in_value );
	return value;
}

template const HREAL Hubris::HMatrixUtility::Determinant( const HMatrixR2& in_value );
template const HREAL Hubris::HMatrixUtility::Determinant( const HMatrixR3& in_value );
template const HREAL Hubris::HMatrixUtility::Determinant( const HMatrixR4& in_value );

/*
	DotProduct
*/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >
const IN_TYPE Hubris::HMatrixUtility::DotProduct( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs )
{
	IN_TYPE result = HVariablesMath::ZeroGet< IN_TYPE >();
	typename const IN_TYPE* const pDataLhs = in_lhs.DataGet();
	typename const IN_TYPE* const pDataRhs = in_rhs.DataGet();
	for( HSINT index = 0; index < IN_WIDTH * IN_HEIGHT; ++index )
	{
		result += ( pDataLhs[ index ] * pDataRhs[ index ] );
	}

	return result;
}

template const HU8 Hubris::HMatrixUtility::DotProduct( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
template const HU8 Hubris::HMatrixUtility::DotProduct( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
template const HU8 Hubris::HMatrixUtility::DotProduct( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
template const HU8 Hubris::HMatrixUtility::DotProduct( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
template const HU8 Hubris::HMatrixUtility::DotProduct( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
template const HU8 Hubris::HMatrixUtility::DotProduct( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
template const HU8 Hubris::HMatrixUtility::DotProduct( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
																						   
template const HSINT Hubris::HMatrixUtility::DotProduct( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
template const HSINT Hubris::HMatrixUtility::DotProduct( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
template const HSINT Hubris::HMatrixUtility::DotProduct( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
template const HSINT Hubris::HMatrixUtility::DotProduct( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
template const HSINT Hubris::HMatrixUtility::DotProduct( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
template const HSINT Hubris::HMatrixUtility::DotProduct( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
template const HSINT Hubris::HMatrixUtility::DotProduct( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
																						   
template const HREAL Hubris::HMatrixUtility::DotProduct( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
template const HREAL Hubris::HMatrixUtility::DotProduct( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
template const HREAL Hubris::HMatrixUtility::DotProduct( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
template const HREAL Hubris::HMatrixUtility::DotProduct( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
template const HREAL Hubris::HMatrixUtility::DotProduct( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
template const HREAL Hubris::HMatrixUtility::DotProduct( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
template const HREAL Hubris::HMatrixUtility::DotProduct( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

/*
	Identity
*/	
template< typename IN_TYPE >
const IN_TYPE& Hubris::HMatrixUtility::IdentityGet()
{
	static const IN_TYPE s_identity = LocalIdentity< IN_TYPE >();
	return s_identity;
}

template const HMatrixR2& Hubris::HMatrixUtility::IdentityGet< HMatrixR2 >();
template const HMatrixR3& Hubris::HMatrixUtility::IdentityGet< HMatrixR3 >();
template const HMatrixR4& Hubris::HMatrixUtility::IdentityGet< HMatrixR4 >();

/*
	Inverse
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::Inverse( const IN_TYPE& in_value )
{
	IN_TYPE returnValue;
	LocalInverse( returnValue, in_value );
	return returnValue;
}

template const HMatrixR2 Hubris::HMatrixUtility::Inverse( const HMatrixR2& in_value );
template const HMatrixR3 Hubris::HMatrixUtility::Inverse( const HMatrixR3& in_value );
template const HMatrixR4 Hubris::HMatrixUtility::Inverse( const HMatrixR4& in_value );

/*
	Larger
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMatrixUtility::Larger( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	typename const IN_TYPE::TType* const pDataLhs = in_lhs.DataGet();
	typename const IN_TYPE::TType* const pDataRhs = in_rhs.DataGet();
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		if( !( pDataRhs[ index ] < pDataLhs[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Larger( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

/*
	LargerEqual
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMatrixUtility::LargerEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	typename const IN_TYPE::TType* const pDataLhs = in_lhs.DataGet();
	typename const IN_TYPE::TType* const pDataRhs = in_rhs.DataGet();
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		if( !( pDataRhs[ index ] <= pDataLhs[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::LargerEqual( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

/*
	Length
*/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >
const IN_TYPE Hubris::HMatrixUtility::Length( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value )
{
	IN_TYPE returnValue = LengthSquared( in_value );
	if( HMathUtility::EpsilonZeroNot( returnValue ) )
	{
		returnValue = HMath::SquareRoot( returnValue );
	}

	return returnValue;
}

template const HREAL Hubris::HMatrixUtility::Length( const HVectorR1& in_value );
template const HREAL Hubris::HMatrixUtility::Length( const HVectorR2& in_value );
template const HREAL Hubris::HMatrixUtility::Length( const HVectorR3& in_value );
template const HREAL Hubris::HMatrixUtility::Length( const HVectorR4& in_value );
template const HREAL Hubris::HMatrixUtility::Length( const HMatrixR2& in_value );
template const HREAL Hubris::HMatrixUtility::Length( const HMatrixR3& in_value );
template const HREAL Hubris::HMatrixUtility::Length( const HMatrixR4& in_value );

/*
	LengthSquared
*/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >
const IN_TYPE Hubris::HMatrixUtility::LengthSquared( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value )
{
	const IN_TYPE* const pDataValue = in_value.DataGet();
	IN_TYPE returnValue = HVariablesMath::ZeroGet< IN_TYPE >();
	for( HSINT index = 0; index < ( IN_WIDTH * IN_HEIGHT ); ++index )
	{
		const IN_TYPE value = pDataValue[ index ];
		returnValue += ( value * value );
	}

	return returnValue;
}

template const HVectorR1::TType Hubris::HMatrixUtility::LengthSquared( const HVectorR1& in_value );
template const HVectorR2::TType Hubris::HMatrixUtility::LengthSquared( const HVectorR2& in_value );
template const HVectorR3::TType Hubris::HMatrixUtility::LengthSquared( const HVectorR3& in_value );
template const HVectorR4::TType Hubris::HMatrixUtility::LengthSquared( const HVectorR4& in_value );
template const HMatrixR2::TType Hubris::HMatrixUtility::LengthSquared( const HMatrixR2& in_value );
template const HMatrixR3::TType Hubris::HMatrixUtility::LengthSquared( const HMatrixR3& in_value );
template const HMatrixR4::TType Hubris::HMatrixUtility::LengthSquared( const HMatrixR4& in_value );

/*
	MemberMultiply
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::MemberMultiply( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	const IN_TYPE::TType* const pDataValueLhs = in_lhs.DataGet();
	const IN_TYPE::TType* const pDataValueRhs = in_rhs.DataGet();
	IN_TYPE::TType resultData[ IN_TYPE::TVar::TSize ];
	for( HSINT index = 0; index < ( IN_TYPE::TVar::TSize ); ++index )
	{
		resultData[ index ] = pDataValueLhs[ index ] * pDataValueRhs[ index ];
	}

	return IN_TYPE( resultData );
}

template const HVectorU1 Hubris::HMatrixUtility::MemberMultiply( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
template const HVectorU2 Hubris::HMatrixUtility::MemberMultiply( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
template const HVectorU3 Hubris::HMatrixUtility::MemberMultiply( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
template const HVectorU4 Hubris::HMatrixUtility::MemberMultiply( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
template const HMatrixU2 Hubris::HMatrixUtility::MemberMultiply( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
template const HMatrixU3 Hubris::HMatrixUtility::MemberMultiply( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
template const HMatrixU4 Hubris::HMatrixUtility::MemberMultiply( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );

template const HVectorS1 Hubris::HMatrixUtility::MemberMultiply( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
template const HVectorS2 Hubris::HMatrixUtility::MemberMultiply( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
template const HVectorS3 Hubris::HMatrixUtility::MemberMultiply( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
template const HVectorS4 Hubris::HMatrixUtility::MemberMultiply( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
template const HMatrixS2 Hubris::HMatrixUtility::MemberMultiply( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
template const HMatrixS3 Hubris::HMatrixUtility::MemberMultiply( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
template const HMatrixS4 Hubris::HMatrixUtility::MemberMultiply( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );

template const HVectorR1 Hubris::HMatrixUtility::MemberMultiply( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
template const HVectorR2 Hubris::HMatrixUtility::MemberMultiply( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
template const HVectorR3 Hubris::HMatrixUtility::MemberMultiply( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
template const HVectorR4 Hubris::HMatrixUtility::MemberMultiply( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
template const HMatrixR2 Hubris::HMatrixUtility::MemberMultiply( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
template const HMatrixR3 Hubris::HMatrixUtility::MemberMultiply( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
template const HMatrixR4 Hubris::HMatrixUtility::MemberMultiply( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

/*
	MemberProduct
*/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >
const IN_TYPE Hubris::HMatrixUtility::MemberProduct( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value )
{
	typename const IN_TYPE* const pDataValue = in_value.DataGet();
	IN_TYPE returnValue = pDataValue[ 0 ];
	for( HSINT index = 1; index < ( IN_WIDTH * IN_HEIGHT ); ++index )
	{
		returnValue = ( IN_TYPE )( returnValue * pDataValue[ index ] );
	}

	return returnValue;
}
//
//template const HVectorU1::TType Hubris::HMatrixUtility::MemberProduct( const HVectorU1& in_value );
//template const HVectorU2::TType Hubris::HMatrixUtility::MemberProduct( const HVectorU2& in_value );
//template const HVectorU3::TType Hubris::HMatrixUtility::MemberProduct( const HVectorU3& in_value );
//template const HVectorU4::TType Hubris::HMatrixUtility::MemberProduct( const HVectorU4& in_value );
//template const HMatrixU2::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixU2& in_value );
//template const HMatrixU3::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixU3& in_value );
//template const HMatrixU4::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixU4& in_value );

template const HVectorS1::TType Hubris::HMatrixUtility::MemberProduct( const HVectorS1& in_value );
template const HVectorS2::TType Hubris::HMatrixUtility::MemberProduct( const HVectorS2& in_value );
template const HVectorS3::TType Hubris::HMatrixUtility::MemberProduct( const HVectorS3& in_value );
template const HVectorS4::TType Hubris::HMatrixUtility::MemberProduct( const HVectorS4& in_value );
template const HMatrixS2::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixS2& in_value );
template const HMatrixS3::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixS3& in_value );
template const HMatrixS4::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixS4& in_value );

template const HVectorR1::TType Hubris::HMatrixUtility::MemberProduct( const HVectorR1& in_value );
template const HVectorR2::TType Hubris::HMatrixUtility::MemberProduct( const HVectorR2& in_value );
template const HVectorR3::TType Hubris::HMatrixUtility::MemberProduct( const HVectorR3& in_value );
template const HVectorR4::TType Hubris::HMatrixUtility::MemberProduct( const HVectorR4& in_value );
template const HMatrixR2::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixR2& in_value );
template const HMatrixR3::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixR3& in_value );
template const HMatrixR4::TType Hubris::HMatrixUtility::MemberProduct( const HMatrixR4& in_value );

/*
	MemberSum
*/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >
const IN_TYPE Hubris::HMatrixUtility::MemberSum( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value )
{
	const IN_TYPE* const pDataValue = in_value.DataGet();
	IN_TYPE returnValue = HVariablesMath::ZeroGet< IN_TYPE >();
	for( HSINT index = 0; index < ( IN_WIDTH * IN_HEIGHT ); ++index )
	{
		returnValue = ( IN_TYPE )( returnValue + pDataValue[ index ] );
	}

	return returnValue;
}

template const HVectorU1::TType Hubris::HMatrixUtility::MemberSum( const HVectorU1& in_value );
template const HVectorU2::TType Hubris::HMatrixUtility::MemberSum( const HVectorU2& in_value );
template const HVectorU3::TType Hubris::HMatrixUtility::MemberSum( const HVectorU3& in_value );
template const HVectorU4::TType Hubris::HMatrixUtility::MemberSum( const HVectorU4& in_value );
template const HMatrixU2::TType Hubris::HMatrixUtility::MemberSum( const HMatrixU2& in_value );
template const HMatrixU3::TType Hubris::HMatrixUtility::MemberSum( const HMatrixU3& in_value );
template const HMatrixU4::TType Hubris::HMatrixUtility::MemberSum( const HMatrixU4& in_value );

template const HVectorS1::TType Hubris::HMatrixUtility::MemberSum( const HVectorS1& in_value );
template const HVectorS2::TType Hubris::HMatrixUtility::MemberSum( const HVectorS2& in_value );
template const HVectorS3::TType Hubris::HMatrixUtility::MemberSum( const HVectorS3& in_value );
template const HVectorS4::TType Hubris::HMatrixUtility::MemberSum( const HVectorS4& in_value );
template const HMatrixS2::TType Hubris::HMatrixUtility::MemberSum( const HMatrixS2& in_value );
template const HMatrixS3::TType Hubris::HMatrixUtility::MemberSum( const HMatrixS3& in_value );
template const HMatrixS4::TType Hubris::HMatrixUtility::MemberSum( const HMatrixS4& in_value );

template const HVectorR1::TType Hubris::HMatrixUtility::MemberSum( const HVectorR1& in_value );
template const HVectorR2::TType Hubris::HMatrixUtility::MemberSum( const HVectorR2& in_value );
template const HVectorR3::TType Hubris::HMatrixUtility::MemberSum( const HVectorR3& in_value );
template const HVectorR4::TType Hubris::HMatrixUtility::MemberSum( const HVectorR4& in_value );
template const HMatrixR2::TType Hubris::HMatrixUtility::MemberSum( const HMatrixR2& in_value );
template const HMatrixR3::TType Hubris::HMatrixUtility::MemberSum( const HMatrixR3& in_value );
template const HMatrixR4::TType Hubris::HMatrixUtility::MemberSum( const HMatrixR4& in_value );

/*
	MinorMatrixGet
*/
template< typename IN_MAJOR, typename IN_MINOR >
const IN_MINOR Hubris::HMatrixUtility::MinorMatrixGet( const IN_MAJOR& in_src, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY )
{
	HCOMMON_ASSERT_STATIC( 1 <= IN_MINOR::TVar::TWidth, input_too_small );
	HCOMMON_ASSERT_STATIC( IN_MAJOR::TVar::TWidth - 1 == IN_MINOR::TVar::TWidth, size_miss_match );
	HCOMMON_ASSERT_STATIC( IN_MAJOR::TVar::THeight - 1 == IN_MINOR::TVar::THeight, size_miss_match );


	IN_MINOR subMatrix;

	for( HSINT traceY = 0; traceY < IN_MINOR::TVar::THeight; ++traceY )
	{
		for( HSINT traceX = 0; traceX < IN_MINOR::TVar::TWidth; ++traceX )
		{
			const HSINT subMatrixIndex = IN_MINOR::IndexGet( traceX, traceY ); 
			const HSINT srcX = traceX + ( ( in_excludeIndexX <= traceX ) ? 1 : 0 );
			const HSINT srcY = traceY + ( ( in_excludeIndexY <= traceY ) ? 1 : 0 );
			const HSINT srcMatrixIndex = IN_MAJOR::IndexGet( srcX, srcY ); 

			subMatrix[ subMatrixIndex ] = in_src[ srcMatrixIndex ];
		}
	}

	return subMatrix;
}

//template const HMatrix< HSINT, 1, 1 > Hubris::HMatrixUtility::MinorMatrixGet( const HMatrix< HSINT, 2, 2 >& in_src, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
//template const HVectorS1 Hubris::HMatrixUtility::MinorMatrixGet< HSINT, 2 >( const HMatrixS2& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template const HVectorS1 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixS2& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template const HMatrixS2 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixS3& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template const HMatrixS3 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixS4& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template const HMatrixS4 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixS5& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );

template const HVectorR1 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixR2& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template const HMatrixR2 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixR3& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template const HMatrixR3 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixR4& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template const HMatrixR4 Hubris::HMatrixUtility::MinorMatrixGet( const HMatrixR5& in_value, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );


/*
	MinorMatrixSet
*/
template< typename IN_MAJOR, typename IN_MINOR >
Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( IN_MAJOR& out_major, const IN_MINOR& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY )
{
	HCOMMON_ASSERT_STATIC( 1 <= IN_MINOR::TVar::TWidth, input_too_small );
	HCOMMON_ASSERT_STATIC( IN_MAJOR::TVar::TWidth - 1 == IN_MINOR::TVar::TWidth, size_miss_match );
	HCOMMON_ASSERT_STATIC( IN_MAJOR::TVar::THeight - 1 == IN_MINOR::TVar::THeight, size_miss_match );

	IN_MINOR subMatrix;

	for( HSINT traceY = 0; traceY < IN_MINOR::TVar::THeight; ++traceY )
	{
		for( HSINT traceX = 0; traceX < IN_MINOR::TVar::TWidth; ++traceX )
		{
			const HSINT minorIndex = IN_MINOR::IndexGet( traceX, traceY ); 
			const HSINT srcX = traceX + ( ( in_excludeIndexX <= traceX ) ? 1 : 0 );
			const HSINT srcY = traceY + ( ( in_excludeIndexY <= traceY ) ? 1 : 0 );
			const HSINT majorIndex = IN_MAJOR::IndexGet( srcX, srcY ); 

			out_major[ majorIndex ] = in_minor[ minorIndex ];
		}
	}

	return;
}

template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixS2& out_major, const HVectorS1& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixS3& out_major, const HMatrixS2& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixS4& out_major, const HMatrixS3& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixS5& out_major, const HMatrixS4& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
																			  
template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixR2& out_major, const HVectorR1& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixR3& out_major, const HMatrixR2& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixR4& out_major, const HMatrixR3& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );
template Hubris::HVOID Hubris::HMatrixUtility::MinorMatrixSet( HMatrixR5& out_major, const HMatrixR4& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );


/*
	Normalise
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::Normalise( const IN_TYPE& in_value )
{
	const IN_TYPE::TType lengthSquared = LengthSquared( in_value );

	if( ( HTRUE == HMathUtility::EpsilonEqual( HVariablesMath::UnitGet< IN_TYPE::TType >(), lengthSquared ) ) ||
		( HTRUE == HMathUtility::EpsilonZero( lengthSquared ) ) )
	{
		return in_value;
	}
	IN_TYPE returnValue = in_value;
	const IN_TYPE::TType length = HMath::SquareRoot< IN_TYPE::TType >( lengthSquared );

	if( false == HMathUtility::EpsilonZero( length ) )
	{
		returnValue = ( in_value * ( HVariablesMath::UnitGet< IN_TYPE::TType >() / length ) );
	}

	return returnValue;
}

template const HVectorR1 Hubris::HMatrixUtility::Normalise( const HVectorR1& in_value );
template const HVectorR2 Hubris::HMatrixUtility::Normalise( const HVectorR2& in_value );
template const HVectorR3 Hubris::HMatrixUtility::Normalise( const HVectorR3& in_value );
template const HVectorR4 Hubris::HMatrixUtility::Normalise( const HVectorR4& in_value );
template const HMatrixR2 Hubris::HMatrixUtility::Normalise( const HMatrixR2& in_value );
template const HMatrixR3 Hubris::HMatrixUtility::Normalise( const HMatrixR3& in_value );
template const HMatrixR4 Hubris::HMatrixUtility::Normalise( const HMatrixR4& in_value );

/*
	Reflect
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::Reflect( const IN_TYPE& in_unitMirror, const IN_TYPE& in_vector )
{
	const IN_TYPE::TType dot = DotProduct( in_unitMirror, in_vector );
	//const IN_TYPE reflectPoint = ( dot + dot )* in_unitMirror;
	//const IN_TYPE result = ( reflectPoint - in_vector );
	const IN_TYPE reflectOffset = ( dot + dot )* in_unitMirror;
	const IN_TYPE result = ( in_vector - reflectOffset );
	return result;
}
														   
template const HVectorS1 Hubris::HMatrixUtility::Reflect( const HVectorS1& in_unitMirror, const HVectorS1& in_vector );
template const HVectorS2 Hubris::HMatrixUtility::Reflect( const HVectorS2& in_unitMirror, const HVectorS2& in_vector );
template const HVectorS3 Hubris::HMatrixUtility::Reflect( const HVectorS3& in_unitMirror, const HVectorS3& in_vector );
template const HVectorS4 Hubris::HMatrixUtility::Reflect( const HVectorS4& in_unitMirror, const HVectorS4& in_vector );
																				   
template const HVectorR1 Hubris::HMatrixUtility::Reflect( const HVectorR1& in_unitMirror, const HVectorR1& in_vector );
template const HVectorR2 Hubris::HMatrixUtility::Reflect( const HVectorR2& in_unitMirror, const HVectorR2& in_vector );
template const HVectorR3 Hubris::HMatrixUtility::Reflect( const HVectorR3& in_unitMirror, const HVectorR3& in_vector );
template const HVectorR4 Hubris::HMatrixUtility::Reflect( const HVectorR4& in_unitMirror, const HVectorR4& in_vector );

/*
	Mirror
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::Mirror( const IN_TYPE& in_unitMirror, const IN_TYPE& in_vector )
{
	const IN_TYPE::TType dot = DotProduct( in_unitMirror, in_vector );
	const IN_TYPE reflectOffset = ( dot + dot )* in_unitMirror;
	const IN_TYPE mirror = ( in_vector - reflectOffset );
	return mirror;
}
														   
template const HVectorS1 Hubris::HMatrixUtility::Mirror( const HVectorS1& in_unitMirror, const HVectorS1& in_vector );
template const HVectorS2 Hubris::HMatrixUtility::Mirror( const HVectorS2& in_unitMirror, const HVectorS2& in_vector );
template const HVectorS3 Hubris::HMatrixUtility::Mirror( const HVectorS3& in_unitMirror, const HVectorS3& in_vector );
template const HVectorS4 Hubris::HMatrixUtility::Mirror( const HVectorS4& in_unitMirror, const HVectorS4& in_vector );
																				   
template const HVectorR1 Hubris::HMatrixUtility::Mirror( const HVectorR1& in_unitMirror, const HVectorR1& in_vector );
template const HVectorR2 Hubris::HMatrixUtility::Mirror( const HVectorR2& in_unitMirror, const HVectorR2& in_vector );
template const HVectorR3 Hubris::HMatrixUtility::Mirror( const HVectorR3& in_unitMirror, const HVectorR3& in_vector );
template const HVectorR4 Hubris::HMatrixUtility::Mirror( const HVectorR4& in_unitMirror, const HVectorR4& in_vector );


/*
	RotationLengthSquaredGet
*/
template< typename IN_TYPE, HSINT IN_WIDTH >
typename const IN_TYPE Hubris::HMatrixUtility::RotationLengthSquaredGet( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src )
{
	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
	const TSubMatrix subMatrix = MinorMatrixGet< HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >, TSubMatrix >( in_src, IN_WIDTH - 1, IN_WIDTH - 1 );
	const IN_TYPE lengthSquared = HMatrixUtility::LengthSquared( subMatrix ); 
	return lengthSquared;
}

template const HREAL Hubris::HMatrixUtility::RotationLengthSquaredGet( const HMatrixR4& in_src );

/*
	RotationLengthSquaredSet
*/
template< typename IN_TYPE, HSINT IN_WIDTH >
HVOID Hubris::HMatrixUtility::RotationLengthSquaredSet( HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_out_src, typename const IN_TYPE in_lengthSquared )
{
	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
	const TSubMatrix subMatrix = MinorMatrixGet< HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >, TSubMatrix >( in_out_src, IN_WIDTH - 1, IN_WIDTH - 1 );
	const IN_TYPE lengthSquared = HMatrixUtility::LengthSquared( subMatrix ); 

	if( HTRUE == HMathUtility::EpsilonEqual( in_lengthSquared, lengthSquared ) )
	{	
		return;
	}

	const IN_TYPE mul = HMath::SquareRoot< IN_TYPE >( in_lengthSquared ) / HMath::SquareRoot< IN_TYPE >( lengthSquared );

	for( HSINT traceY = 0; traceY < IN_WIDTH - 1; ++traceY )
	{
		for( HSINT traceX = 0; traceX < IN_WIDTH - 1; ++traceX )
		{
			const HSINT matrixIndex = HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >::IndexGet( traceX, traceY ); 
			in_out_src[ matrixIndex ] *= mul;
		}
	}

	return;
}

template HVOID Hubris::HMatrixUtility::RotationLengthSquaredSet( HMatrixR4& in_out_src, const HREAL in_lengthSquared );

/*
	RotationLengthGet
*/
template< typename IN_TYPE, HSINT IN_WIDTH >
typename const IN_TYPE Hubris::HMatrixUtility::RotationLengthGet( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src )
{
	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
	const TSubMatrix subMatrix = MinorMatrixGet< HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >, TSubMatrix >( in_src, IN_WIDTH - 1, IN_WIDTH - 1 );
	//const IN_TYPE length = HMatrixUtility::Length( subMatrix ); 
	const IN_TYPE lengthSquared = HMatrixUtility::LengthSquared( subMatrix ); 
	const IN_TYPE length = HMath::SquareRoot< IN_TYPE >( lengthSquared / ( IN_TYPE )( IN_WIDTH - 1 ) );
	return length;
}

template const HMatrixR4::TType Hubris::HMatrixUtility::RotationLengthGet( const HMatrixR4& in_src );

/*
	RotationLengthSet
*/
template< typename IN_TYPE, HSINT IN_WIDTH >
HVOID Hubris::HMatrixUtility::RotationLengthSet( HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_out_src, const IN_TYPE in_length )
{
	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
	const TSubMatrix subMatrix = MinorMatrixGet< HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >, TSubMatrix >( in_out_src, IN_WIDTH - 1, IN_WIDTH - 1 );
	const IN_TYPE length = HMatrixUtility::Length( subMatrix ); 

	if( HTRUE == HMathUtility::EpsilonEqual( in_length, length ) )
	{	
		return;
	}
	if( HTRUE == HMathUtility::EpsilonZero( length ) )
	{
		//NOP, can not normalise zero matrix
		return;
	}

	const IN_TYPE mul = in_length / length;

	for( HSINT traceY = 0; traceY < IN_WIDTH - 1; ++traceY )
	{
		for( HSINT traceX = 0; traceX < IN_WIDTH - 1; ++traceX )
		{
			const HSINT matrixIndex = HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >::IndexGet( traceX, traceY ); 
			in_out_src[ matrixIndex ] *= mul;
		}
	}

	return;
}

template HVOID Hubris::HMatrixUtility::RotationLengthSet( HMatrixR4& in_out_src, const HREAL in_length );

/*
	Smaller
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMatrixUtility::Smaller( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	typename const IN_TYPE::TType* const pDataLhs = in_lhs.DataGet();
	typename const IN_TYPE::TType* const pDataRhs = in_rhs.DataGet();
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		if( !( pDataLhs[ index ] < pDataRhs[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::Smaller( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

/*
	SmallerEqual
*/
template< typename IN_TYPE >
const HBOOL Hubris::HMatrixUtility::SmallerEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
{
	typename const IN_TYPE::TType* const pDataLhs = in_lhs.DataGet();
	typename const IN_TYPE::TType* const pDataRhs = in_rhs.DataGet();
	for( HSINT index = 0; index < IN_TYPE::TVar::TSize; ++index )
	{
		if( !( pDataLhs[ index ] <= pDataRhs[ index ] ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
																						   
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
template const HBOOL Hubris::HMatrixUtility::SmallerEqual( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

/*
	template< typename IN_MATRIX, typename IN_TYPE >static const IN_TYPE TranslateGet( const IN_MATRIX& in_matrix );
*/
template< typename IN_MATRIX, typename IN_VECTOR >
const IN_VECTOR Hubris::HMatrixUtility::TranslateGet( const IN_MATRIX& in_value )
{
	HREAL data[ IN_VECTOR::TVar::TWidth ];

	for( HSINT index = 0; index < IN_VECTOR::TVar::TWidth; ++index )
	{
		data[ index ] = in_value[ IN_MATRIX::IndexGet( index, IN_MATRIX::TVar::THeight - 1 ) ]; 
	}

	return IN_VECTOR( data );
}

template const HVectorR3 Hubris::HMatrixUtility::TranslateGet( const HMatrixR4& in_value );

/*
	template< typename IN_MATRIX, typename IN_TYPE >static HVOID TranslateSet( IN_MATRIX& out_matrix, const IN_TYPE& in_translate );
*/
template< typename IN_MATRIX, typename IN_VECTOR >
HVOID Hubris::HMatrixUtility::TranslateSet( IN_MATRIX& out_matrix, const IN_VECTOR& in_translate )
{
	for( HSINT index = 0; index < IN_VECTOR::TVar::TWidth; ++index )
	{
		out_matrix[ IN_MATRIX::IndexGet( index, IN_MATRIX::TVar::THeight - 1 ) ] = in_translate[ index ];
	}

	return;
}

template HVOID Hubris::HMatrixUtility::TranslateSet( HMatrixR4& out_matrix, const HVectorR3& in_translate );

/*
	Transpose
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMatrixUtility::Transpose( const IN_TYPE& in_value )
{
	IN_TYPE outMatrix;

	HCOMMON_ASSERT_STATIC( IN_TYPE::TVar::TWidth == IN_TYPE::TVar::THeight, width_and_height_must_match );

	for( HSINT x = 0; x < IN_TYPE::TVar::TWidth; ++x )
	{
		for( HSINT y = 0; y < IN_TYPE::TVar::TWidth; ++y )
		{
			outMatrix[ IN_TYPE::IndexGet( y, x ) ] = in_value[ IN_TYPE::IndexGet( x, y ) ];
		}
	}

	return outMatrix;
}

template const HMatrixR2 Hubris::HMatrixUtility::Transpose( const HMatrixR2& in_value );
template const HMatrixR3 Hubris::HMatrixUtility::Transpose( const HMatrixR3& in_value );
template const HMatrixR4 Hubris::HMatrixUtility::Transpose( const HMatrixR4& in_value );


/*
	VectorProduct
*/
template< typename IN_MATRIX, typename IN_VECTOR >
const IN_VECTOR Hubris::HMatrixUtility::VectorProduct( const IN_MATRIX& in_lhs, const IN_VECTOR& in_rhs )
{
	typedef HMatrix< IN_MATRIX::TType, IN_MATRIX::TVar::TWidth, 1 >TUpcastVector;
	TUpcastVector vector;
	for( HSINT index = 0; index < IN_VECTOR::TVar::TWidth; ++index )
	{
		vector[ index ] = in_rhs[ index ];
	}

	vector[ IN_VECTOR::TVar::TWidth ] = HVariablesMath::UnitGet< IN_MATRIX::TType >();

	const TUpcastVector result = vector * in_lhs;
	return IN_VECTOR( result.DataGet() );
}

template const HVectorR3 Hubris::HMatrixUtility::VectorProduct( const HMatrixR4& in_lhs, const HVectorR3& in_rhs );

/*
	VectorProductNoTranslate
*/
template<  typename IN_MATRIX, typename IN_VECTOR  >
const IN_VECTOR Hubris::HMatrixUtility::VectorProductNoTranslate( const IN_MATRIX& in_lhs, const IN_VECTOR& in_rhs )
{
	typename IN_MATRIX::TType data[ IN_VECTOR::TVar::TWidth ];
	for( HSINT index = 0; index < IN_VECTOR::TVar::TWidth; ++index )
	{
		IN_MATRIX::TType temp = 0;

		for( HSINT subIndex = 0; subIndex < IN_MATRIX::TVar::THeight - 1; ++subIndex )
		{
			temp += ( in_rhs[ subIndex ] * in_lhs[  IN_MATRIX::IndexGet( index, subIndex ) ] );
		}

		data[ index ] = temp;
	}

	return IN_VECTOR( data );
}

template const HVectorR3 Hubris::HMatrixUtility::VectorProductNoTranslate( const HMatrixR4& in_lhs, const HVectorR3& in_rhs );

/**/