//file: Hubris/HMatrix/HMatrixUtility4.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixUtility4.h"

#include "Hubris/HMatrix/HMatrixOperator.h"
#include "Hubris/HMatrix/HMatrixConstructor.h"
#include "Hubris/HMatrix/HMatrixUtilitySquare.h"

//////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////////
//// template definitions
///**/
//template struct Hubris::HMatrixUtility4< HREAL, 4 >;
//
////////////////////////////////////////////////////////////////
//// public static functions
///**/
//template< typename IN_TYPE, HSINT IN_SIZE > 
//typename const Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::TVector Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::TranslateGet( const TMatrix& in_src )
//{
//	HREAL data[ IN_SIZE - 1 ];
//
//	for( HSINT index = 0; index < IN_SIZE - 1; ++index )
//	{
//		data[ index ] = in_src[ HMatrixR4::IndexGet( index, 3 ) ]; 
//	}
//
//	return TVector( data );
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_SIZE > 
//HVOID Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::TranslateSet( TMatrix& out_matrix, const TVector& in_translate )
//{
//	for( HSINT index = 0; index < IN_SIZE - 1; ++index )
//	{
//		out_matrix[ HMatrixR4::IndexGet( index, IN_SIZE - 1 ) ] = in_translate[ index ];
//	}
//
//	return;
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_SIZE > 
//typename const Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::TVector Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::VectorProduct( const TMatrix& in_lhs, const TVector& in_rhs )
//{
//	TUpcastVector vector;
//	for( HSINT index = 0; index < IN_SIZE - 1; ++index )
//	{
//		vector[ HMatrixR4::IndexGet( index, 0 ) ] = in_rhs[ index ];
//	}
//
//	vector[ HMatrixR4::IndexGet( IN_SIZE - 1, 0 ) ] = HVariablesMathREAL::s_unit;
//
//	const HVectorR4 result = vector * in_lhs;
//	return HVectorR3( result.DataGet() );
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_SIZE > 
//typename const Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::TVector Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::VectorProductNoTranslate( const TMatrix& in_lhs, const TVector& in_rhs )
//{
//	IN_TYPE data[ IN_SIZE - 1 ];
//	for( HSINT index = 0; index < IN_SIZE - 1; ++index )
//	{
//		IN_TYPE temp = HVariablesMath::ZeroGet< IN_TYPE >();
//
//		for( HSINT subIndex = 0; subIndex < IN_SIZE - 1; ++subIndex )
//		{
//			temp += ( in_rhs[ subIndex ] * in_lhs[  HMatrixR4::IndexGet( index, subIndex ) ] );
//		}
//
//		data[ index ] = temp;
//	}
//
//	return TVector( data );
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_SIZE > 
//typename HVOID Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::Decompose( 
//	TMatrix& out_matrixRotate,
//	TMatrix& out_matrixScale,
//	TMatrix& out_matrixTranslate,
//	const TMatrix& in_matrix
//	)
//{
//	out_matrixRotate = in_matrix;
//	out_matrixTranslate = HMatrixUtility::Identity< HMatrixR4 >();
//	out_matrixScale = HMatrixUtility::Identity< HMatrixR4 >();
//
//	const HREAL scale = HMatrixUtilitySquareR4::RotationLengthSquaredGet( in_matrix );
//	HMatrixUtilitySquareR4::RotationLengthSquaredSet( out_matrixScale, scale );
//	HMatrixUtilitySquareR4::RotationLengthSquaredSet( out_matrixRotate, 3.0F );
//
//	TranslateSet( out_matrixRotate, HVectorR3() );
//	TranslateSet( out_matrixTranslate, TranslateGet( in_matrix ) );
//
//
//	return;
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_SIZE > 
//typename const Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::TMatrix Hubris::HMatrixUtility4< IN_TYPE, IN_SIZE >::Compose( 
//	const TMatrix& in_matrixRotate,
//	const TMatrix& in_matrixScale,
//	const TMatrix& in_matrixTranslate
//	)
//{
//	return in_matrixRotate * in_matrixScale * in_matrixTranslate;
//}
//
/**/