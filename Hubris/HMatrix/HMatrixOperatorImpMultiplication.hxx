//file: Hubris/HMatrix/HMatrixOperatorImpMultiplication.hxx

/**/
#define HMATRIX_OPERATOR_P	1

#include "Hubris/HMatrix/HMatrixOperatorImpMultiplicationFull.hxx"

#undef HMATRIX_OPERATOR_P

/**/
#define HMATRIX_OPERATOR_P	2

#include "Hubris/HMatrix/HMatrixOperatorImpMultiplicationFull.hxx"

#undef HMATRIX_OPERATOR_P

/**/
#define HMATRIX_OPERATOR_P	3

#include "Hubris/HMatrix/HMatrixOperatorImpMultiplicationFull.hxx"

#undef HMATRIX_OPERATOR_P

/**/
#define HMATRIX_OPERATOR_P	4

#include "Hubris/HMatrix/HMatrixOperatorImpMultiplicationFull.hxx"

#undef HMATRIX_OPERATOR_P

/**/
#define HMATRIX_OPERATOR_P	5

#include "Hubris/HMatrix/HMatrixOperatorImpMultiplicationFull.hxx"

#undef HMATRIX_OPERATOR_P

/**/
//template< typename IN_TYPE, HSINT IN_M, HSINT IN_N >
template<>
const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_M, HMATRIX_OPERATOR_N >& Hubris::operator *=( HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_M, HMATRIX_OPERATOR_N >& in_lhs, const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_M, HMATRIX_OPERATOR_M >& in_rhs )
{
	//in_lhs = operator*< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_M, HMATRIX_OPERATOR_N, HMATRIX_OPERATOR_M >( in_lhs, in_rhs );
	in_lhs = ( in_lhs * in_rhs );
	return in_lhs;
}

/**/
