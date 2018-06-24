//file: Hubris/HMatrix/HMatrixImplementation.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixImplementation.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HVariables/HVariablesMath.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
template< typename IN_TYPE >
HBOOL Hubris::HMatrixImplementation< IN_TYPE >::DataCmp( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count )
{
	HBOOL match = true;
	for( HSINT index = 0; index < in_count; ++index )
	{
		//change epsilon cmp to be in HMathUtility< IN_TYPE >::Epsilon*, not intrinsic to matrix type
		//if( false == HMathUtility::EpsilonEqual( in_lhs[ index ], in_rhs[ index ] ) )
		if( false == ( in_lhs[ index ] == in_rhs[ index ] ) )
		{
			match = false;
			break;
		}
	}

	return match;
}

/**/
template< typename IN_TYPE >
HBOOL Hubris::HMatrixImplementation< IN_TYPE >::DataCmp( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count )
{
	HBOOL match = true;
	for( HSINT index = 0; index < in_count; ++index )
	{
		//change epsilon cmp to be in HMathUtility< IN_TYPE >::Epsilon*, not intrinsic to matrix type
		//if( false == HMathUtility::EpsilonEqual( in_lhs[ index ], in_rhs ) )
		if( false == ( in_lhs[ index ] == in_rhs ) )
		{
			match = false;
			break;
		}
	}

	return match;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataDot( const IN_TYPE * in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE& out_data )
{
	out_data = HVariablesMath::ZeroGet< IN_TYPE >();

	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data += ( in_lhs[ index ] * in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataMul( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] * in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataMul( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] * in_rhs );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataMul( const IN_TYPE& in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs * in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataAdd( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] + in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataAdd( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] + in_rhs );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataSub( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] - in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataSub( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] - in_rhs );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataSub( const IN_TYPE& in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs - in_rhs[ index ] );
	}

	return;
}

/* negate all the values in the array */
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataNeg( const IN_TYPE * const in_lhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = -( in_lhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataDiv( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] / in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataDiv( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs[ index ] / in_rhs );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataDiv( const IN_TYPE& in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		out_data[ index ] = ( in_lhs / in_rhs[ index ] );
	}

	return;
}

/**/
template< typename IN_TYPE >
//! set the lhs to the value from rhs
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataSet( IN_TYPE * const in_out_lhs, const IN_TYPE * const in_rhs, const HSINT in_count )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		in_out_lhs[ index ] = in_rhs[ index ];
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::DataSet( IN_TYPE * const in_out_lhs, const IN_TYPE& in_rhs, const HSINT in_count )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		in_out_lhs[ index ] =in_rhs;
	}

	return;
}

/* < W, IN_OTHER > = < W, H > * < H, IN_OTHER > *
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::MatrixMul( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_width, const HSINT in_height, const HSINT in_other, IN_TYPE * const out_data )
{
	HSINT indexData = 0;
	for( HSINT indexHeight = 0; indexHeight < in_height; ++indexHeight )
	{
		for( HSINT indexWidth = 0; indexWidth < in_width; ++indexWidth )
		{
			IN_TYPE value = HVariablesMath::ZeroGet< IN_TYPE >();
			HSINT dataIndexLhs = indexWidth;
			HSINT dataIndexRhs = ( indexHeight * in_other );
			for( HSINT indexOther = 0; indexOther < in_other; ++indexOther )
			{
				value += ( in_lhs[ dataIndexLhs ] * in_rhs[ dataIndexRhs ] );
				dataIndexLhs += in_width;
				dataIndexRhs += 1;
			}

			out_data[ indexData ] = value;
			indexData += 1;
		}
	}

	return;
}

*
	< m, n > * < p, m > = < p, n >
*/
template< typename IN_TYPE >
HVOID Hubris::HMatrixImplementation< IN_TYPE >::MatrixMul( const IN_TYPE* const in_lhs, const IN_TYPE* const in_rhs, const HSINT in_m, const HSINT in_n, const HSINT in_p, IN_TYPE* const out_data )
{
	HSINT trace = 0;
	IN_TYPE value;

	for( HSINT indexN = 0; indexN < in_n; ++indexN )
	{
		for( HSINT indexP = 0; indexP < in_p; ++indexP )
		{
			//for( r = 0 to m ) sum A[n, r] * B[r, p]
			value = HVariablesMath::ZeroGet< IN_TYPE >();
			for( HSINT indexM = 0; indexM < in_m; ++indexM )
			{
				//[ indexM, indexP ] * [ indexP, indexM ]
				value += ( in_lhs[ ( indexN * in_m ) + indexM ] ) * ( in_rhs[ ( indexM * in_p ) + indexP ] );
			}

			out_data[ trace ] = value;
			trace += 1;
		}
	}

	return;
}

/* return true if all members smaller */
template< typename IN_TYPE >
HBOOL Hubris::HMatrixImplementation< IN_TYPE >::LessThan( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		if( in_lhs[ index ] == in_rhs[ index ] )
		{
			continue;
		}

		return( in_lhs[ index ] < in_rhs[ index ] );
	}

	return HFALSE;
}

/**/
template< typename IN_TYPE >
HBOOL Hubris::HMatrixImplementation< IN_TYPE >::LessThanEqual( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		if( in_lhs[ index ] == in_rhs[ index ] )
		{
			continue;
		}

		return( in_lhs[ index ] < in_rhs[ index ] );
	}

	return HTRUE;
}

/**/
template< typename IN_TYPE >
HBOOL Hubris::HMatrixImplementation< IN_TYPE >::GreaterThan( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		if( in_lhs[ index ] == in_rhs[ index ] )
		{
			continue;
		}

		return( in_rhs[ index ] < in_lhs[ index ] );
	}

	return HFALSE;
}

/**/
template< typename IN_TYPE >
HBOOL Hubris::HMatrixImplementation< IN_TYPE >::GreaterThanEqual( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count )
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		if( in_lhs[ index ] == in_rhs[ index ] )
		{
			continue;
		}

		return( in_rhs[ index ] < in_lhs[ index ] );
	}

	return HTRUE;
}

/**/
template class Hubris::HMatrixImplementation< HU8 >;
template class Hubris::HMatrixImplementation< HSINT >;
template class Hubris::HMatrixImplementation< HREAL >;


/**/
