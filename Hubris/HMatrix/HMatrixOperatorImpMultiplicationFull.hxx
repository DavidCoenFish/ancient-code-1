//file: Hubris/HMatrix/HMatrixOperatorImpMultiplicationFull.hxx

/**/
//template< typename IN_TYPE, HSINT IN_M, HSINT IN_N, HSINT IN_P >
template<>
const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_P, HMATRIX_OPERATOR_N > Hubris::operator *( const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_M, HMATRIX_OPERATOR_N >& in_lhs, const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_P, HMATRIX_OPERATOR_M >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMATRIX_OPERATOR_P * HMATRIX_OPERATOR_N ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::MatrixMul( in_lhs.DataGet(), in_rhs.DataGet(), HMATRIX_OPERATOR_M, HMATRIX_OPERATOR_N, HMATRIX_OPERATOR_P, data );

	return HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_P, HMATRIX_OPERATOR_N >( data );
}

/**/
