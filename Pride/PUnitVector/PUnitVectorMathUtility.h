//file: Pride/PUnitVector/PUnitVectorMathUtility.h
#ifndef _P_UNIT_VECTOR_MATH_UTILITY_H_
#define _P_UNIT_VECTOR_MATH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PUnitVector;
	typedef PUnitVector< Hubris::HREAL, 2 >PUnitVectorR2;
	typedef PUnitVector< Hubris::HREAL, 3 >PUnitVectorR3;

};

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// template method overload declarations
	/*
		avoid min, max, lerps unless implemented on unit sphere, this is a unit vector, do not allow to touch 0,0,0
	*/
	//template const Pride::PUnitVectorR2 HMathUtility::Absolute( const Pride::PUnitVectorR2& in_src );
	//template const Pride::PUnitVectorR3 HMathUtility::Absolute( const Pride::PUnitVectorR3& in_src );

	//template const HBOOL HMathUtility::Valid( const Pride::PUnitVectorR2& in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PUnitVectorR3& in_src );

	//template const HBOOL HMathUtility::ValidNot( const Pride::PUnitVectorR2& in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PUnitVectorR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PUnitVectorR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PUnitVectorR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PUnitVectorR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PUnitVectorR3& in_src );

	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PUnitVectorR2& in_lhs, const Pride::PUnitVectorR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PUnitVectorR3& in_lhs, const Pride::PUnitVectorR3& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PUnitVectorR2& in_lhs, const Pride::PUnitVectorR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PUnitVectorR3& in_lhs, const Pride::PUnitVectorR3& in_rhs );

};

#endif // _P_UNIT_VECTOR_MATH_UTILITY_H_