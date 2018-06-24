//file: Hubris/HMatrix/HMatrixImplementation.h
#ifndef _H_MATRIX_IMPLEMENTATION_H_
#define _H_MATRIX_IMPLEMENTATION_H_

#include "Hubris/HCommon/HCommonType.h"

// implement so of the required operations of a matrix
namespace Hubris
{
	template< typename IN_TYPE > class HMatrixImplementation
	{
	public:
		static HBOOL DataCmp( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count );
		static HBOOL DataCmp( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count );

		static HVOID DataDot( const IN_TYPE * in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE& out_data );

		static HVOID DataMul( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data );
		static HVOID DataMul( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data );
		static HVOID DataMul( const IN_TYPE& in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data );

		static HVOID DataAdd( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data );
		static HVOID DataAdd( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data );

		static HVOID DataSub( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data );
		static HVOID DataSub( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data );
		static HVOID DataSub( const IN_TYPE& in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data );

		// negate all the values in the array
		static HVOID DataNeg( const IN_TYPE * const in_lhs, const HSINT in_count, IN_TYPE * const out_data );

		static HVOID DataDiv( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data );
		static HVOID DataDiv( const IN_TYPE * const in_lhs, const IN_TYPE& in_rhs, const HSINT in_count, IN_TYPE * const out_data );
		static HVOID DataDiv( const IN_TYPE& in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count, IN_TYPE * const out_data );

		//! set the lhs to the value from rhs
		static HVOID DataSet( IN_TYPE * const in_out_lhs, const IN_TYPE * const in_rhs, const HSINT in_count );
		static HVOID DataSet( IN_TYPE * const in_out_lhs, const IN_TYPE& in_rhs, const HSINT in_count );

		// < m, n > * < n, p > = < m, p >
		static HVOID MatrixMul( const IN_TYPE* const in_lhs, const IN_TYPE* const in_rhs, const HSINT in_m, const HSINT in_n, const HSINT in_p, IN_TYPE* const out_data );

		static HBOOL LessThan( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count );
		static HBOOL LessThanEqual( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count );
		static HBOOL GreaterThan( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count );
		static HBOOL GreaterThanEqual( const IN_TYPE * const in_lhs, const IN_TYPE * const in_rhs, const HSINT in_count );

	private:
		//unimplemented privated destructor, method class
		~HMatrixImplementation();
	};
};

#endif // _H_MATRIX_IMPLEMENTATION_H_