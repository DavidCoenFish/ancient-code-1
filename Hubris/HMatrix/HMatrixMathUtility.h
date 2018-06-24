//file: Hubris/HMatrix/HMatrixMathUtility.h
#ifndef _H_MATRIX_MATH_UTILITY_H_
#define _H_MATRIX_MATH_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HMath/HMathUtility.h"

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// typedef
	/**/
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;

	typedef HMatrix< HU8, 1, 1 >HVectorU1;
	typedef HMatrix< HU8, 2, 1 >HVectorU2;
	typedef HMatrix< HU8, 3, 1 >HVectorU3;
	typedef HMatrix< HU8, 4, 1 >HVectorU4;
	typedef HMatrix< HU8, 2, 2 >HMatrixU2;
	typedef HMatrix< HU8, 3, 3 >HMatrixU3;
	typedef HMatrix< HU8, 4, 4 >HMatrixU4;

	typedef HMatrix< HSINT, 1, 1 >HVectorS1;
	typedef HMatrix< HSINT, 2, 1 >HVectorS2;
	typedef HMatrix< HSINT, 3, 1 >HVectorS3;
	typedef HMatrix< HSINT, 4, 1 >HVectorS4;
	typedef HMatrix< HSINT, 2, 2 >HMatrixS2;
	typedef HMatrix< HSINT, 3, 3 >HMatrixS3;
	typedef HMatrix< HSINT, 4, 4 >HMatrixS4;

	typedef HMatrix< HREAL, 1, 1 >HVectorR1;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 2, 2 >HMatrixR2;
	typedef HMatrix< HREAL, 3, 3 >HMatrixR3;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;

	//////////////////////////////////////////////////////////////
	// declare template method overloads
	/**/
	//template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const HVectorU1 HMathUtility::Maximum( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
	//template<>const HVectorU2 HMathUtility::Maximum( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
	//template<>const HVectorU3 HMathUtility::Maximum( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
	//template<>const HVectorU4 HMathUtility::Maximum( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
	//template<>const HMatrixU2 HMathUtility::Maximum( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
	//template<>const HMatrixU3 HMathUtility::Maximum( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
	//template<>const HMatrixU4 HMathUtility::Maximum( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
	//template<>const HVectorS1 HMathUtility::Maximum( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
	//template<>const HVectorS2 HMathUtility::Maximum( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
	//template<>const HVectorS3 HMathUtility::Maximum( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
	//template<>const HVectorS4 HMathUtility::Maximum( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
	//template<>const HMatrixS2 HMathUtility::Maximum( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
	//template<>const HMatrixS3 HMathUtility::Maximum( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
	//template<>const HMatrixS4 HMathUtility::Maximum( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
	//template<>const HVectorR1 HMathUtility::Maximum( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
	//template<>const HVectorR2 HMathUtility::Maximum( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HVectorR3 HMathUtility::Maximum( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
	//template<>const HVectorR4 HMathUtility::Maximum( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
	//template<>const HMatrixR2 HMathUtility::Maximum( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
	//template<>const HMatrixR3 HMathUtility::Maximum( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
	//template<>const HMatrixR4 HMathUtility::Maximum( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

	//////template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const HVectorU1 HMathUtility::Minimum( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
	//template<>const HVectorU2 HMathUtility::Minimum( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
	//template<>const HVectorU3 HMathUtility::Minimum( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
	//template<>const HVectorU4 HMathUtility::Minimum( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
	//template<>const HMatrixU2 HMathUtility::Minimum( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
	//template<>const HMatrixU3 HMathUtility::Minimum( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
	//template<>const HMatrixU4 HMathUtility::Minimum( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
	//template<>const HVectorS1 HMathUtility::Minimum( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
	//template<>const HVectorS2 HMathUtility::Minimum( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
	//template<>const HVectorS3 HMathUtility::Minimum( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
	//template<>const HVectorS4 HMathUtility::Minimum( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
	//template<>const HMatrixS2 HMathUtility::Minimum( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
	//template<>const HMatrixS3 HMathUtility::Minimum( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
	//template<>const HMatrixS4 HMathUtility::Minimum( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
	//template<>const HVectorR1 HMathUtility::Minimum( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
	//template<>const HVectorR2 HMathUtility::Minimum( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HVectorR3 HMathUtility::Minimum( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
	//template<>const HVectorR4 HMathUtility::Minimum( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
	//template<>const HMatrixR2 HMathUtility::Minimum( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
	//template<>const HMatrixR3 HMathUtility::Minimum( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
	//template<>const HMatrixR4 HMathUtility::Minimum( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

	////template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
	//template<>const HVectorU1 HMathUtility::Absolute( const HVectorU1& in_src );
	//template<>const HVectorU2 HMathUtility::Absolute( const HVectorU2& in_src );
	//template<>const HVectorU3 HMathUtility::Absolute( const HVectorU3& in_src );
	//template<>const HVectorU4 HMathUtility::Absolute( const HVectorU4& in_src );
	//template<>const HMatrixU2 HMathUtility::Absolute( const HMatrixU2& in_src );
	//template<>const HMatrixU3 HMathUtility::Absolute( const HMatrixU3& in_src );
	//template<>const HMatrixU4 HMathUtility::Absolute( const HMatrixU4& in_src );
	//template<>const HVectorS1 HMathUtility::Absolute( const HVectorS1& in_src );
	//template<>const HVectorS2 HMathUtility::Absolute( const HVectorS2& in_src );
	//template<>const HVectorS3 HMathUtility::Absolute( const HVectorS3& in_src );
	//template<>const HVectorS4 HMathUtility::Absolute( const HVectorS4& in_src );
	//template<>const HMatrixS2 HMathUtility::Absolute( const HMatrixS2& in_src );
	//template<>const HMatrixS3 HMathUtility::Absolute( const HMatrixS3& in_src );
	//template<>const HMatrixS4 HMathUtility::Absolute( const HMatrixS4& in_src );
	//template<>const HVectorR1 HMathUtility::Absolute( const HVectorR1& in_src );
	//template<>const HVectorR2 HMathUtility::Absolute( const HVectorR2& in_src );
	//template<>const HVectorR3 HMathUtility::Absolute( const HVectorR3& in_src );
	//template<>const HVectorR4 HMathUtility::Absolute( const HVectorR4& in_src );
	//template<>const HMatrixR2 HMathUtility::Absolute( const HMatrixR2& in_src );
	//template<>const HMatrixR3 HMathUtility::Absolute( const HMatrixR3& in_src );
	//template<>const HMatrixR4 HMathUtility::Absolute( const HMatrixR4& in_src );

	////template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
	//template<>const HVectorU1 HMathUtility::Lerp( const HVectorU1& in_lhs, const HVectorU1& in_rhs, const HREAL in_ratio );
	//template<>const HVectorU2 HMathUtility::Lerp( const HVectorU2& in_lhs, const HVectorU2& in_rhs, const HREAL in_ratio );
	//template<>const HVectorU3 HMathUtility::Lerp( const HVectorU3& in_lhs, const HVectorU3& in_rhs, const HREAL in_ratio );
	//template<>const HVectorU4 HMathUtility::Lerp( const HVectorU4& in_lhs, const HVectorU4& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixU2 HMathUtility::Lerp( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixU3 HMathUtility::Lerp( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixU4 HMathUtility::Lerp( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs, const HREAL in_ratio );
	//template<>const HVectorS1 HMathUtility::Lerp( const HVectorS1& in_lhs, const HVectorS1& in_rhs, const HREAL in_ratio );
	//template<>const HVectorS2 HMathUtility::Lerp( const HVectorS2& in_lhs, const HVectorS2& in_rhs, const HREAL in_ratio );
	//template<>const HVectorS3 HMathUtility::Lerp( const HVectorS3& in_lhs, const HVectorS3& in_rhs, const HREAL in_ratio );
	//template<>const HVectorS4 HMathUtility::Lerp( const HVectorS4& in_lhs, const HVectorS4& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixS2 HMathUtility::Lerp( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixS3 HMathUtility::Lerp( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixS4 HMathUtility::Lerp( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs, const HREAL in_ratio );
	//template<>const HVectorR1 HMathUtility::Lerp( const HVectorR1& in_lhs, const HVectorR1& in_rhs, const HREAL in_ratio );
	//template<>const HVectorR2 HMathUtility::Lerp( const HVectorR2& in_lhs, const HVectorR2& in_rhs, const HREAL in_ratio );
	//template<>const HVectorR3 HMathUtility::Lerp( const HVectorR3& in_lhs, const HVectorR3& in_rhs, const HREAL in_ratio );
	//template<>const HVectorR4 HMathUtility::Lerp( const HVectorR4& in_lhs, const HVectorR4& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixR2 HMathUtility::Lerp( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixR3 HMathUtility::Lerp( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs, const HREAL in_ratio );
	//template<>const HMatrixR4 HMathUtility::Lerp( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs, const HREAL in_ratio );

	//////template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorU1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorS1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorR1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HVectorR4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::Valid( const HMatrixR4& in_src );

	//////template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorU1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorS1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorR1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HVectorR4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::ValidNot( const HMatrixR4& in_src );

	//////template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorU1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorS1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorR1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HVectorR4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZero( const HMatrixR4& in_src );

	//////template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorU1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixU2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixU3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixU4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorS1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixS2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixS3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixS4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorR1& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HVectorR4& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixR2& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixR3& in_src );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonZeroNot( const HMatrixR4& in_src );

	////template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqual( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

	////template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorU4& in_lhs, const HVectorU4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixU2& in_lhs, const HMatrixU2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixU3& in_lhs, const HMatrixU3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixU4& in_lhs, const HMatrixU4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorS1& in_lhs, const HVectorS1& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorS2& in_lhs, const HVectorS2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorS3& in_lhs, const HVectorS3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorS4& in_lhs, const HVectorS4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixS2& in_lhs, const HMatrixS2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixS3& in_lhs, const HMatrixS3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixS4& in_lhs, const HMatrixS4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HVectorR4& in_lhs, const HVectorR4& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixR2& in_lhs, const HMatrixR2& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixR3& in_lhs, const HMatrixR3& in_rhs );
	//template<>const Hubris::HBOOL HMathUtility::EpsilonEqualNot( const HMatrixR4& in_lhs, const HMatrixR4& in_rhs );

};

#endif // _H_MATRIX_MATH_UTILITY_H_