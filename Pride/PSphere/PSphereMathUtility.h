//file: Pride/PSphere/PSphereMathUtility.h
#ifndef _P_SPHERE_MATH_UTILITY_H_
#define _P_SPHERE_MATH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;
};

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// template method overload declarations
	/*
		avoid min, max, lerps unless implemented on unit sphere for unit vector, do not allow to touch 0,0,0
	*/
	//template const Pride::PSphereR2 HMathUtility::Absolute( const Pride::PSphereR2& in_src );
	//template const Pride::PSphereR3 HMathUtility::Absolute( const Pride::PSphereR3& in_src );

	//template const HBOOL HMathUtility::Valid( const Pride::PSphereR2& in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PSphereR3& in_src );

	//template const HBOOL HMathUtility::ValidNot( const Pride::PSphereR2& in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PSphereR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PSphereR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PSphereR3& in_src );

	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PSphereR2& in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PSphereR3& in_src );

	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PSphereR2& in_lhs, const Pride::PSphereR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PSphereR3& in_lhs, const Pride::PSphereR3& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PSphereR2& in_lhs, const Pride::PSphereR2& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PSphereR3& in_lhs, const Pride::PSphereR3& in_rhs );

};
#endif // _P_SPHERE_MATH_UTILITY_H_