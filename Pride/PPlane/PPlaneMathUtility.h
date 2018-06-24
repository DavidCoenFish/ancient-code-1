//file: Pride/PPlane/PPlaneMathUtility.h
#ifndef _P_PLANE_MATH_UTILITY_H_
#define _P_PLANE_MATH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;
};

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// template method overload declarations
	/*
		avoid min, max, lerps unless implemented on unit sphere for unit vector, do not allow to touch 0,0,0
	*/
	//template const Pride::PPlaneR2 HMathUtility::Absolute( const Pride::PPlaneR2& in_src );
	//template const Pride::PPlaneR3 HMathUtility::Absolute( const Pride::PPlaneR3& in_src );

	//template const HBOOL HMathUtility::Valid( const Pride::PPlaneR2& in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PPlaneR3& in_src );

	//template const HBOOL HMathUtility::ValidNot( const Pride::PPlaneR2& in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PPlaneR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PPlaneR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PPlaneR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PPlaneR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PPlaneR3& in_src );

	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PPlaneR2& in_lhs, const Pride::PPlaneR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PPlaneR3& in_lhs, const Pride::PPlaneR3& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PPlaneR2& in_lhs, const Pride::PPlaneR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PPlaneR3& in_lhs, const Pride::PPlaneR3& in_rhs );

};
#endif // _P_PLANE_MATH_UTILITY_H_