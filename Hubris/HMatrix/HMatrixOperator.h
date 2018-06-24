//file: Hubris/HMatrix/HMatrixOperator.h
#ifndef _H_MATRIX_OPERATOR_H_
#define _H_MATRIX_OPERATOR_H_

#include "Hubris/HCommon/HCommonType.h"

//specialised operators for HMatrix
namespace Hubris
{
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >class HMatrix;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator == ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator == ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator == ( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator != ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator != ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator != ( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator +( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator +( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator +( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator +=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator +=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator -=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator -=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator *( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator *( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator *=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator /( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator /( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator /=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );

	// return type doesn't specialise, so template for a_a * a_1 and a_a * b_1 and a_a * a_a
	//internal still uses ( a_c = a_b * b_c ) -> b_c = a_a * b_c
	//template< typename IN_TYPE, HSINT IN_A, HSINT IN_B, HSINT IN_C >const HMatrix< IN_TYPE, IN_B, IN_C > operator *( const HMatrix< IN_TYPE, IN_A, IN_A >& in_lhs, const HMatrix< IN_TYPE, IN_B, IN_C >& in_rhs );
	//template< typename IN_TYPE, HSINT IN_A >const HMatrix< IN_TYPE, IN_A, IN_A >& operator *=( HMatrix< IN_TYPE, IN_A, IN_A >& in_lhs, const HMatrix< IN_TYPE, IN_A, IN_A >& in_rhs );

	/*
		tradtionally math has matrix multiplication AxB effectivly apply transform B then A, with y,x being order of matrix axis specification. so we are flipping
		Matrix[ x, y ] with x being coloumn, y being row
		lhs[ m x n ] * rhs[ p x m ] = result[ p x n ]

		result[ i, j ] = sum( r = 1 to n ) Lhs[ i,r ] * Rhs[ r, j ] =  ( Lhs[ i, 1 ] * Rhs[ 1, j ] ) + ( Lhs[ i, 2 ] * Rhs[ 2, j ] ) + ... + ( Lhs[ i, n ] * Rhs[ n, j ] ) 

	*/
	template< typename IN_TYPE, HSINT IN_M, HSINT IN_N, HSINT IN_P >const HMatrix< IN_TYPE, IN_P, IN_N > operator *( const HMatrix< IN_TYPE, IN_M, IN_N >& in_lhs, const HMatrix< IN_TYPE, IN_P, IN_M >& in_rhs );
	template< typename IN_TYPE, HSINT IN_M, HSINT IN_N >const HMatrix< IN_TYPE, IN_M, IN_N >& operator *=( HMatrix< IN_TYPE, IN_M, IN_N >& in_lhs, const HMatrix< IN_TYPE, IN_M, IN_M >& in_rhs );

	// return true if members in series are lhs less than rhs
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator<( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator<=( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	// return true if members in series are lhs greater than rhs
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator>( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator>=( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

};


#endif // _H_MATRIX_OPERATOR_H_