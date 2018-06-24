//file: Pride/PLine/PLineMathUtility.h
#ifndef _P_LINE_MATH_UTILITY_H_
#define _P_LINE_MATH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLine;
	typedef PLine< Hubris::HREAL, 2 >PLineR2;
	typedef PLine< Hubris::HREAL, 3 >PLineR3;
};

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// template method overload declarations
	/*
		avoid min, max, lerps unless implemented on unit sphere, uses a unit vector, do not allow to touch 0,0,0
	*/
	//template const Pride::PLineR2 HMathUtility::Absolute( const Pride::PLineR2& in_src );
	//template const Pride::PLineR3 HMathUtility::Absolute( const Pride::PLineR3& in_src );

	//template const HBOOL HMathUtility::Valid( const Pride::PLineR2& in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PLineR3& in_src );

	//template const HBOOL HMathUtility::ValidNot( const Pride::PLineR2& in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PLineR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PLineR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PLineR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PLineR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PLineR3& in_src );

	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PLineR2& in_lhs, const Pride::PLineR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PLineR3& in_lhs, const Pride::PLineR3& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PLineR2& in_lhs, const Pride::PLineR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PLineR3& in_lhs, const Pride::PLineR3& in_rhs );

};

#endif // _P_LINE_MATH_UTILITY_H_