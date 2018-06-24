//file: Hubris/HMatrix/HMatrixOperatorImpStandard.hxx

/**/
template<> 
HBOOL Hubris::operator == ( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataCmp( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize );
};

/**/
template<>
HBOOL Hubris::operator == ( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	return HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataCmp( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize );
}

/**/
template<>
HBOOL Hubris::operator == ( const HMATRIX_OPERATOR_TYPE& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataCmp( in_rhs.DataGet(), in_lhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize );
}

/**/
template<>
HBOOL Hubris::operator != ( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return !( in_lhs == in_rhs );
}

/**/
template<>
HBOOL Hubris::operator != ( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	return !( in_lhs == in_rhs );
}

/**/
template<>
HBOOL Hubris::operator != ( const HMATRIX_OPERATOR_TYPE& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return !( in_lhs == in_rhs );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator +( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataAdd( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator +( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataAdd( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator +( const HMATRIX_OPERATOR_TYPE& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataAdd( in_rhs.DataGet(), in_lhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM >& Hubris::operator +=( HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataAdd( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	in_lhs.DataSet( data );

	return in_lhs;
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM >& Hubris::operator +=( HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataAdd( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	in_lhs.DataSet( data );

	return in_lhs;
}

template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator -( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataSub( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator -( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataSub( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator -( const HMATRIX_OPERATOR_TYPE& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataSub( in_lhs, in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator -( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataNeg( in_lhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM >& Hubris::operator -=( HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataSub( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	in_lhs.DataSet( data );

	return in_lhs;
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM >& Hubris::operator -=( HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataSub( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	in_lhs.DataSet( data );

	return in_lhs;
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator *( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataMul( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator *( const HMATRIX_OPERATOR_TYPE& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataMul( in_lhs, in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM >& Hubris::operator *=( HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataMul( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	in_lhs.DataSet( data );

	return in_lhs;
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator /( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataDiv( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM > Hubris::operator /( const HMATRIX_OPERATOR_TYPE& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataDiv( in_lhs, in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	return HMatrix< HMATRIX_OPERATOR_PARAM >( data );
}

/**/
template<>
const HMatrix< HMATRIX_OPERATOR_PARAM >& Hubris::operator /=( HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMATRIX_OPERATOR_TYPE& in_rhs )
{
	HMATRIX_OPERATOR_TYPE data[ HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize ];

	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataDiv( in_lhs.DataGet(), in_rhs, HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize, data );

	in_lhs.DataSet( data );

	return in_lhs;
}

/*	return true if each members safifies condition */
template<>
HBOOL Hubris::operator < ( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::LessThan( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize );
}
template<>
HBOOL Hubris::operator <=( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::LessThanEqual( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize );
}
template<>
HBOOL Hubris::operator >( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return( !( operator <=( in_lhs, in_rhs ) ) );
	//return HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::GreaterThan( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize );
}
template<>
HBOOL Hubris::operator >=( const HMatrix< HMATRIX_OPERATOR_PARAM >& in_lhs, const HMatrix< HMATRIX_OPERATOR_PARAM >& in_rhs )
{
	return( !( operator <( in_lhs, in_rhs ) ) );
	//return HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::GreaterThanEqual( in_lhs.DataGet(), in_rhs.DataGet(), HMatrix< HMATRIX_OPERATOR_PARAM >::TVar::TSize );
}

////template< typename IN_TYPE, HSINT IN_M, HSINT IN_N, HSINT IN_P >
//template<>
//const HMatrix< HMATRIX_OPERATOR_TYPE, IN_M, IN_P > operator *( const HMatrix< HMATRIX_OPERATOR_TYPE, IN_M, IN_N >& in_lhs, const HMatrix< HMATRIX_OPERATOR_TYPE, IN_N, IN_P >& in_rhs )
//{
//	HMATRIX_OPERATOR_TYPE data[ HMATRIX_OPERATOR_WIDTH ];
//
//	HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::MatrixMul( in_lhs.DataGet(), in_rhs.DataGet(), HMATRIX_OPERATOR_WIDTH, 1, HMATRIX_OPERATOR_WIDTH, data );
//
//	return HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, 1 >( data );
//}
//
////template< typename IN_TYPE, HSINT IN_M, HSINT IN_N >
//template<>
//const HMatrix< IN_TYPE, IN_M, IN_N > operator *=( const HMatrix< IN_TYPE, IN_M, IN_N >& in_lhs, const HMatrix< IN_TYPE, IN_N, IN_N >& in_rhs )
//{
//}


/**
//vector multiplication ie. 4_1 = 4_4 x 4_1
#if( HMATRIX_OPERATOR_WIDTH == HMATRIX_OPERATOR_HEIGHT )
	template<>
	const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, 1 > Hubris::operator *( const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >& in_lhs, const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, 1 >& in_rhs )
	{
		HMATRIX_OPERATOR_TYPE data[ HMATRIX_OPERATOR_WIDTH ];

		HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::MatrixMul( in_lhs.DataGet(), in_rhs.DataGet(), HMATRIX_OPERATOR_WIDTH, 1, HMATRIX_OPERATOR_WIDTH, data );

		return HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, 1 >( data );
	}
#endif

//upcast vector multiplication ie. 3_1 = 4_4 x 3_1
#if( ( HMATRIX_OPERATOR_WIDTH == HMATRIX_OPERATOR_HEIGHT )&& ( 1 < HMATRIX_OPERATOR_WIDTH ) )
	template<>
	const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH - 1, 1 > Hubris::operator *( const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >& in_lhs, const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH - 1, 1 >& in_rhs )
	{
		HMATRIX_OPERATOR_TYPE data[ HMATRIX_OPERATOR_WIDTH ];

		HMATRIX_OPERATOR_TYPE rhsUpcast[ HMATRIX_OPERATOR_WIDTH ];
		HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::DataSet( rhsUpcast, in_rhs.DataGet(), HMATRIX_OPERATOR_WIDTH - 1 );
		rhsUpcast[ HMATRIX_OPERATOR_WIDTH - 1 ] = HVariablesMath< HMATRIX_OPERATOR_TYPE >::s_unit;
		
		HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::MatrixMul( in_lhs.DataGet(), rhsUpcast, HMATRIX_OPERATOR_WIDTH, 1, HMATRIX_OPERATOR_WIDTH, data );

		return HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH - 1, 1 >( data );
	}
#endif

//square matrix multiplication ie. 4_4 = 4_4 x 4_4
#if( ( HMATRIX_OPERATOR_WIDTH == HMATRIX_OPERATOR_HEIGHT ) && ( 1 != HMATRIX_OPERATOR_WIDTH ) )
	template<>
	const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH > Hubris::operator *( const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >& in_lhs, const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >& in_rhs )
	{
		HMATRIX_OPERATOR_TYPE data[ HMATRIX_OPERATOR_WIDTH * HMATRIX_OPERATOR_WIDTH ];

		HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::MatrixMul( in_lhs.DataGet(), in_rhs.DataGet(), HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH, data );

		return HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >( data );
	}
#endif

#if( HMATRIX_OPERATOR_WIDTH == HMATRIX_OPERATOR_HEIGHT )
	template<>
	const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >& Hubris::operator *=( HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >& in_lhs, const HMatrix< HMATRIX_OPERATOR_TYPE, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH >& in_rhs )
	{
		HMATRIX_OPERATOR_TYPE data[ HMATRIX_OPERATOR_WIDTH * HMATRIX_OPERATOR_WIDTH ];

		HMatrixImplementation< HMATRIX_OPERATOR_TYPE >::MatrixMul( in_lhs.DataGet(), in_rhs.DataGet(), HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH, HMATRIX_OPERATOR_WIDTH, data );

		in_lhs.DataSet( data );

		return in_lhs;
	}

#endif

/**/
