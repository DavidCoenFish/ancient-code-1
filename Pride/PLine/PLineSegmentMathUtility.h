//file: Pride/PLine/PLineSegmentMathUtility.h
#ifndef _P_LINE_SEGMENT_MATH_UTILITY_H_
#define _P_LINE_SEGMENT_MATH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLineSegment;
	typedef PLineSegment< Hubris::HREAL, 2 >PLineSegmentR2;
	typedef PLineSegment< Hubris::HREAL, 3 >PLineSegmentR3;
};

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// template method overload declarations
	/*
		avoid min, max, lerps unless implemented on unit sphere, uses a unit vector, do not allow to touch 0,0,0
	*/
	//template const Pride::PLineSegmentR2 HMathUtility::Absolute( const Pride::PLineSegmentR2& in_src );
	//template const Pride::PLineSegmentR3 HMathUtility::Absolute( const Pride::PLineSegmentR3& in_src );

	//template const HBOOL HMathUtility::Valid( const Pride::PLineSegmentR2& in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PLineSegmentR3& in_src );

	//template const HBOOL HMathUtility::ValidNot( const Pride::PLineSegmentR2& in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PLineSegmentR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PLineSegmentR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PLineSegmentR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PLineSegmentR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PLineSegmentR3& in_src );

	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PLineSegmentR2& in_lhs, const Pride::PLineSegmentR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PLineSegmentR3& in_lhs, const Pride::PLineSegmentR3& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PLineSegmentR2& in_lhs, const Pride::PLineSegmentR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PLineSegmentR3& in_lhs, const Pride::PLineSegmentR3& in_rhs );

};

#endif // _P_LINE_SEGMENT_MATH_UTILITY_H_