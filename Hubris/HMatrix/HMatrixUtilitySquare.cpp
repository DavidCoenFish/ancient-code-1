//file: Hubris/HMatrix/HMatrixUtilitySquare.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixUtilitySquare.h"

#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixUtility.h"
#include "Hubris/HMatrix/HMatrixOperator.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////////
//// template definitions
///**/
////template struct Hubris::HMatrixUtilitySquare< HSINT, 1 >;
//template struct Hubris::HMatrixUtilitySquare< HSINT, 2 >;
//template struct Hubris::HMatrixUtilitySquare< HSINT, 3 >;
//template struct Hubris::HMatrixUtilitySquare< HSINT, 4 >;
//
////template struct Hubris::HMatrixUtilitySquare< HREAL, 1 >;
//template struct Hubris::HMatrixUtilitySquare< HREAL, 2 >;
//template struct Hubris::HMatrixUtilitySquare< HREAL, 3 >;
//template struct Hubris::HMatrixUtilitySquare< HREAL, 4 >;
//template struct Hubris::HMatrixUtilitySquare< HREAL, 5 >;
//
//////////////////////////////////////////////////////////
//// local free functions
///**/
//template< typename IN_TYPE, HSINT IN_WIDTH >
//static HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 > LocalGatherSubMatrix( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY )
//{
//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
//	typedef HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >TMatrix;
//
//	TSubMatrix subMatrix;
//
//	for( HSINT traceY = 0; traceY < IN_WIDTH - 1; ++traceY )
//	{
//		for( HSINT traceX = 0; traceX < IN_WIDTH - 1; ++traceX )
//		{
//			const HSINT subMatrixIndex = TSubMatrix::IndexGet( traceX, traceY ); 
//			const HSINT srcX = traceX + ( ( in_excludeIndexX <= traceX ) ? 1 : 0 );
//			const HSINT srcY = traceY + ( ( in_excludeIndexY <= traceY ) ? 1 : 0 );
//			const HSINT srcMatrixIndex = TMatrix::IndexGet( srcX, srcY ); 
//
//			subMatrix[ subMatrixIndex ] = in_src[ srcMatrixIndex ];
//		}
//	}
//
//	return subMatrix;
//}
//
////////////////////////////////////////////////////////////////
//// public static functions
///**/
//template<>
//HREAL Hubris::HMatrixUtilitySquare< HREAL, 2 >::Determinant( const HMatrix< HREAL, 2, 2 >& in_src )
//{
//	return( ( in_src[ 0 ] * in_src[ 3 ] ) - ( in_src[ 1 ] * in_src[ 2 ] ) );
//}
//
///**/
//template<>
//HSINT Hubris::HMatrixUtilitySquare< HSINT, 2 >::Determinant( const HMatrix< HSINT, 2, 2 >& in_src )
//{
//	return( ( in_src[ 0 ] * in_src[ 3 ] ) - ( in_src[ 1 ] * in_src[ 2 ] ) );
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_WIDTH >
//IN_TYPE Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::Determinant( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src )
//{
//	IN_TYPE determinamt = HVariablesMath::ZeroGet< IN_TYPE >();
//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
//
//	for( HSINT x = 0; x < IN_WIDTH; ++x )
//	{
//		const TSubMatrix subMatrix = LocalGatherSubMatrix< IN_TYPE, IN_WIDTH >( in_src, x, 0 );
//		const IN_TYPE value = ( in_src[ x ] * HMatrixUtilitySquare< IN_TYPE, IN_WIDTH - 1 >::Determinant( subMatrix ) );;
//
//		if( x & 1 )
//		{
//			determinamt -= value;
//		}
//		else
//		{
//			determinamt += value;
//		}
//	}
//
//	return determinamt;
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_WIDTH >
//typename Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::TMatrix Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::Transpose( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src )
//{
//	TMatrix outMatrix;
//
//	for( HSINT x = 0; x < IN_WIDTH; ++x )
//	{
//		for( HSINT y = 0; y < IN_WIDTH; ++y )
//		{
//			outMatrix[ TMatrix::IndexGet( y, x ) ] = in_src[ TMatrix::IndexGet( x, y ) ];
//		}
//	}
//
//
//	return outMatrix;
//}
//
///**/
//template<>
//typename Hubris::HMatrixUtilitySquare< HREAL, 2 >::TMatrix Hubris::HMatrixUtilitySquare< HREAL, 2 >::Inverse( const HMatrix< HREAL, 2, 2 >& in_src )
//{
//	TMatrix outMatrix;
//	const HREAL determinant = Determinant( in_src );
//
//	for( HSINT x = 0; x < 2; ++x )
//	{
//		for( HSINT y = 0; y < 2; ++y )
//		{
//			const HREAL subDeterminant = in_src[ TMatrix::IndexGet( x, y ) ];
//			if( ( x + y ) & 1 )
//			{
//				outMatrix[ TMatrix::IndexGet( y, x ) ] = -( subDeterminant / determinant );
//			}
//			else
//			{
//				outMatrix[ TMatrix::IndexGet( y, x ) ] = ( subDeterminant / determinant );
//			}
//		}
//	}
//
//	return outMatrix;
//}
///**/
//template<>
//typename Hubris::HMatrixUtilitySquare< HSINT, 2 >::TMatrix Hubris::HMatrixUtilitySquare< HSINT, 2 >::Inverse( const HMatrix< HSINT, 2, 2 >& in_src )
//{
//	TMatrix outMatrix;
//	const HSINT determinant = Determinant( in_src );
//
//	for( HSINT x = 0; x < 2; ++x )
//	{
//		for( HSINT y = 0; y < 2; ++y )
//		{
//			const HSINT subDeterminant = in_src[ TMatrix::IndexGet( x, y ) ];
//			if( ( x + y ) & 1 )
//			{
//				outMatrix[ TMatrix::IndexGet( y, x ) ] = -( subDeterminant / determinant );
//			}
//			else
//			{
//				outMatrix[ TMatrix::IndexGet( y, x ) ] = ( subDeterminant / determinant );
//			}
//		}
//	}
//
//	return outMatrix;
//}
//
//
///**/
//template< typename IN_TYPE, HSINT IN_WIDTH >
//typename Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::TMatrix Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::Inverse( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src )
//{
//	TMatrix outMatrix;
//	const IN_TYPE determinant = HVariablesMath::UnitGet< IN_TYPE >() / Determinant( in_src );
//	if( HMathUtility::EpsilonZero( determinant ) )
//	{
//		return Identity();
//	}
//
//	for( HSINT x = 0; x < IN_WIDTH; ++x )
//	{
//		for( HSINT y = 0; y < IN_WIDTH; ++y )
//		{
//			const TMatrixMinor subMatrix = LocalGatherSubMatrix( in_src, x, y );
//			const IN_TYPE subDeterminant = HMatrixUtilitySquare< IN_TYPE, IN_WIDTH - 1 >::Determinant( subMatrix );
//			if( ( x + y ) & 1 )
//			{
//				outMatrix[ TMatrix::IndexGet( y, x ) ] = -( subDeterminant * determinant );
//			}
//			else
//			{
//				outMatrix[ TMatrix::IndexGet( y, x ) ] = ( subDeterminant * determinant );
//			}
//		}
//	}
//
//	return outMatrix;
//}
//
///**/
//template< typename IN_TYPE, HSINT IN_WIDTH >
//typename const Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::TMatrix& Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::Identity()
//{
//	static TMatrix s_outMatrix;
//	static HBOOL initialise = false;
//
//	if( HTRUE == initialise )
//	{
//		return s_outMatrix;
//	}
//
//	initialise = HTRUE;
//
//	HSINT index = 0;
//	for( HSINT x = 0; x < IN_WIDTH; ++x )
//	{
//		for( HSINT y = 0; y < IN_WIDTH; ++y )
//		{
//			if( x == y )
//			{
//				s_outMatrix[ index ] = HVariablesMath::UnitGet< IN_TYPE >(); 
//			}
//			else
//			{
//				s_outMatrix[ index ] = HVariablesMath::ZeroGet< IN_TYPE >();
//			}
//
//			index += 1;
//		}
//	}
//
//	return s_outMatrix;
//}
//
//
///**/
//template<>
//const HSINT Hubris::HMatrixUtilitySquare< HSINT, 2 >::RotationLengthSquaredGet( const TMatrix& in_src )
//{
//	return HMath< HSINT >::Square( in_src[ TMatrix::IndexGet( 0, 0 ) ] );
//}
//template<>
//const HREAL Hubris::HMatrixUtilitySquare< HREAL, 2 >::RotationLengthSquaredGet( const TMatrix& in_src )
//{
//	return HMath< HREAL >::Square( in_src[ TMatrix::IndexGet( 0, 0 ) ] );
//}
//
//template< typename IN_TYPE, HSINT IN_WIDTH >
//const IN_TYPE Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::RotationLengthSquaredGet( const TMatrix& in_src )
//{
//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
//	const TSubMatrix subMatrix = LocalGatherSubMatrix( in_src, IN_WIDTH - 1, IN_WIDTH - 1 );
//	const IN_TYPE lengthSquared = HMatrixUtility< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >::LengthSquared( subMatrix ); 
//	return lengthSquared;
//}
//
///**/
//template<>
//HVOID Hubris::HMatrixUtilitySquare< HSINT, 2 >::RotationLengthSquaredSet( TMatrix& in_out_src, const HSINT in_lengthSquared )
//{
//	in_out_src[ TMatrix::IndexGet( 0, 0 ) ] = HMath< HSINT >::Sqrt( in_lengthSquared );
//	return;
//}
//template<>
//HVOID Hubris::HMatrixUtilitySquare< HREAL, 2 >::RotationLengthSquaredSet( TMatrix& in_out_src, const HREAL in_lengthSquared )
//{
//	in_out_src[ TMatrix::IndexGet( 0, 0 ) ] = HMath< HREAL >::Sqrt( in_lengthSquared );
//	return;
//}
//
//template< typename IN_TYPE, HSINT IN_WIDTH >
//HVOID Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::RotationLengthSquaredSet( TMatrix& in_out_src, const IN_TYPE in_lengthSquared )
//{
//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
//	const TSubMatrix subMatrix = LocalGatherSubMatrix( in_out_src, IN_WIDTH - 1, IN_WIDTH - 1 );
//	const IN_TYPE lengthSquared = HMatrixUtility< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >::LengthSquared( subMatrix ); 
//
//	if( HTRUE == HMathUtility::EpsilonEqual( in_lengthSquared, lengthSquared ) )
//	{	
//		return;
//	}
//
//	const IN_TYPE mul = HMath::SquareRoot< IN_TYPE >( in_lengthSquared ) / HMath::SquareRoot< IN_TYPE >( lengthSquared );
//
//	for( HSINT traceY = 0; traceY < IN_WIDTH - 1; ++traceY )
//	{
//		for( HSINT traceX = 0; traceX < IN_WIDTH - 1; ++traceX )
//		{
//			const HSINT matrixIndex = TMatrix::IndexGet( traceX, traceY ); 
//			in_out_src[ matrixIndex ] *= mul;
//		}
//	}
//
//	return;
//}
//
///**/
//template<>
//const HSINT Hubris::HMatrixUtilitySquare< HSINT, 2 >::RotationLengthGet( const TMatrix& in_src )
//{
//	return( in_src[ TMatrix::IndexGet( 0, 0 ) ] );
//}
//template<>
//const HREAL Hubris::HMatrixUtilitySquare< HREAL, 2 >::RotationLengthGet( const TMatrix& in_src )
//{
//	return( in_src[ TMatrix::IndexGet( 0, 0 ) ] );
//}
//template< typename IN_TYPE, HSINT IN_WIDTH >
//const IN_TYPE Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::RotationLengthGet( const TMatrix& in_src )
//{
//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
//	const TSubMatrix subMatrix = LocalGatherSubMatrix( in_src, IN_WIDTH - 1, IN_WIDTH - 1 );
//	const IN_TYPE length = HMatrixUtility< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >::Length( subMatrix ); 
//	return length;
//}
//
///**/
//template<>
//HVOID Hubris::HMatrixUtilitySquare< HSINT, 2 >::RotationLengthSet( TMatrix& in_out_src, const HSINT in_length )
//{
//	in_out_src[ TMatrix::IndexGet( 0, 0 ) ] = in_length;
//	return;
//}
//template<>
//HVOID Hubris::HMatrixUtilitySquare< HREAL, 2 >::RotationLengthSet( TMatrix& in_out_src, const HREAL in_length )
//{
//	in_out_src[ TMatrix::IndexGet( 0, 0 ) ] = in_length;
//	return;
//}
//template< typename IN_TYPE, HSINT IN_WIDTH >
//HVOID Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::RotationLengthSet( TMatrix& in_out_src, const IN_TYPE in_length )
//{
//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TSubMatrix;
//	const TSubMatrix subMatrix = LocalGatherSubMatrix( in_out_src, IN_WIDTH - 1, IN_WIDTH - 1 );
//	const IN_TYPE length = HMatrixUtility< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >::Length( subMatrix ); 
//
//	if( HTRUE == HMathUtility::EpsilonEqual( in_length, length ) )
//	{	
//		return;
//	}
//	if( HTRUE == HMathUtility::EpsilonZero( length ) )
//	{
//		//NOP, can not normalise zero matrix
//		return;
//	}
//
//	const IN_TYPE mul = in_length / length;
//
//	for( HSINT traceY = 0; traceY < IN_WIDTH - 1; ++traceY )
//	{
//		for( HSINT traceX = 0; traceX < IN_WIDTH - 1; ++traceX )
//		{
//			const HSINT matrixIndex = TMatrix::IndexGet( traceX, traceY ); 
//			in_out_src[ matrixIndex ] *= mul;
//		}
//	}
//
//	return;
//}
//
//
//template< typename IN_TYPE, HSINT IN_WIDTH >
//const typename Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::TMatrixMinor Hubris::HMatrixUtilitySquare< IN_TYPE, IN_WIDTH >::MinorMatrixGet( 
//	const TMatrix& in_src,
//	const HSINT in_ignoreRow,
//	const HSINT in_ignoreColumn
//	)
//{
//	return LocalGatherSubMatrix( 
//		in_src,
//		in_ignoreColumn,
//		in_ignoreRow
//		);
//}
//
/**/