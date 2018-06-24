//file: Pride/PTriangle/PTriangleMathUtility.h
#ifndef _P_TRIANGLE_MATH_UTILITY_H_
#define _P_TRIANGLE_MATH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PTriangle;
};

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// template method overload declarations
	/*
		avoid min, max, lerps unless implemented on unit sphere for unit vector, do not allow to touch 0,0,0
	*/
	//template const Pride::PTriangle HMathUtility::Maximum( const Pride::PTriangle& in_lhs, const Pride::PTriangle& in_rhs );
	//template const Pride::PTriangle HMathUtility::Minimum( const Pride::PTriangle& in_lhs, const Pride::PTriangle& in_rhs );
	//template const Pride::PTriangle HMathUtility::Absolute( const Pride::PTriangle& in_src );
	//template const Pride::PTriangle HMathUtility::Lerp( const Pride::PTriangle& in_lhs, const Pride::PTriangle& in_rhs, const HREAL in_ratio );
	//template const HBOOL HMathUtility::Valid( const Pride::PTriangle& in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PTriangle& in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PTriangle& in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PTriangle& in_src );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PTriangle& in_lhs, const Pride::PTriangle& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PTriangle& in_lhs, const Pride::PTriangle& in_rhs );

};
#endif // _P_TRIANGLE_MATH_UTILITY_H_