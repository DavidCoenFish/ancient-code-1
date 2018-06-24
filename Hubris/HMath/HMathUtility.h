//file: Hubris/HMath/HMathUtility.h
#ifndef _H_MATH_UTILITY_H_
#define _H_MATH_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"

/* 
	utility math functions

	classes inteded to be used as math values should specilise
	HMin, HMax, Absolute, HValid, HNotValid, HLerp, HEpsilonEqual, HEpsilonNotEqual, HEpsilonZero, HEpsilonNotZero

	here they are specilised for HSINT, HREAL

	nb. interface: since this is to be intended to be extended from complex types, pass by reference rather than value
		ie. IN_TYPE might be vertex containing ( pos, normal, colour, uv etc )
		but return by value

	changed to global functions to allow selective specialisation


NOTE: 3dsmax TCB, tangents for hermite spline 

          (1-t)*(1-c)*(1+b)
TS    =   -----------------  * ( P   -  P    )
  i              2                i      i-1

          (1-t)*(1+c)*(1-b)
      +   -----------------  * ( P   -  P    )
                 2                i+1    i

The "outgoing" Tangent equation:

          (1-t)*(1+c)*(1+b)
TD    =   -----------------  * ( P   -  P    )
  i              2                i      i-1

          (1-t)*(1-c)*(1-b)
      +   -----------------  * ( P   -  P    )
                 2                i+1    i

    |  P(i)    |
C = |  P(i+1)  |
    |  TD(i)   |
    |  TS(i+1) |
*/
namespace Hubris
{
	struct HMathUtility
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HMathUtility();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		template< typename IN_TYPE >static const IN_TYPE Clamp( const IN_TYPE& in_value, const IN_TYPE& in_minimum, const IN_TYPE& in_maximum );
		template< typename IN_TYPE >static const IN_TYPE Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
		template< typename IN_TYPE >static const IN_TYPE Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
		template< typename IN_TYPE >static const IN_TYPE Absolute( const IN_TYPE& in_src );
		template< typename IN_TYPE >static const IN_TYPE Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );

		static Hubris::HVOID SplineHermiteBiasGet(
			const HREAL in_ratio,
			HREAL& out_bias0, // * in_lhs
			HREAL& out_bias1, // * in_rhs
			HREAL& out_bias2, // * in_lhsTangent
			HREAL& out_bias3  // * in_rhsTangent
			);
		template< typename IN_TYPE >static const IN_TYPE SplineHermite(
			const HREAL in_ratio,
			const IN_TYPE& in_lhs, 
			const IN_TYPE& in_rhs, 
			const IN_TYPE& in_lhsTangent, 
			const IN_TYPE& in_rhsTangent
			);
		//Ti = a * ( Pi+1 - Pi-1 ), 
		//a == 0.5 for Catmull-Rom splines (bias)
		template< typename IN_TYPE >static const IN_TYPE SplineTangentGet(
			const IN_TYPE& in_lhs, 
			const IN_TYPE& in_rhs, 
			const HREAL in_bias = 0.5F
			);
		//plot curve between point1 & point2
		template< typename IN_TYPE >static const IN_TYPE SplineCatmullRom(
			const HREAL in_ratio,
			const IN_TYPE& in_point0, 
			const IN_TYPE& in_point1, 
			const IN_TYPE& in_point2, 
			const IN_TYPE& in_point3
			);

		template< typename IN_TYPE >static const HBOOL Valid( const IN_TYPE& in_src );
		template< typename IN_TYPE >static const HBOOL ValidNot( const IN_TYPE& in_src );
		template< typename IN_TYPE >static const HBOOL EpsilonZero( const IN_TYPE& in_src );
		template< typename IN_TYPE >static const HBOOL EpsilonZeroNot( const IN_TYPE& in_src );
		template< typename IN_TYPE >static const HBOOL EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
		template< typename IN_TYPE >static const HBOOL EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
		//increment value so that remainder after division is zero (increaces, unlike % mod )
		template< typename IN_TYPE >static const IN_TYPE Pad( const IN_TYPE& in_value, const IN_TYPE& in_pad );
	};

	/*
		by all rights you should be able to forward declare template specialisation, 
		however MSVC7 gives a internal compiler error if you do this, disabled for now
	*/

	//template< typename IN_TYPE >static const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

	//template<>const HU8 HMathUtility::Maximum( const HU8& in_lhs, const HU8& in_rhs );
	//template<>const HSINT HMathUtility::Maximum( const HSINT& in_lhs, const HSINT& in_rhs );
	//template<>const HREAL HMathUtility::Maximum( const HREAL& in_lhs, const HREAL& in_rhs );

	/////**/
	////template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

	//template<>const HU8 HMathUtility::Minimum( const HU8& in_lhs, const HU8& in_rhs );
	//template<>const HSINT HMathUtility::Minimum( const HSINT& in_lhs, const HSINT& in_rhs );
	//template<>const HREAL HMathUtility::Minimum( const HREAL& in_lhs, const HREAL& in_rhs );

	/////**/
	////template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );

	//template<>const HU8 HMathUtility::Absolute( const HU8& in_src );
	//template<>const HSINT HMathUtility::Absolute( const HSINT& in_src );
	//template<>const HREAL HMathUtility::Absolute( const HREAL& in_src );

	/////**/
	////template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );

	//template<>const HU8 HMathUtility::Lerp( const HU8& in_lhs, const HU8& in_rhs, const HREAL in_ratio );
	//template<>const HSINT HMathUtility::Lerp( const HSINT& in_lhs, const HSINT& in_rhs, const HREAL in_ratio );
	//template<>const HREAL HMathUtility::Lerp( const HREAL& in_lhs, const HREAL& in_rhs, const HREAL in_ratio );

	/////**/
	////template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );

	//template<>const HBOOL HMathUtility::Valid( const HU8& in_src );
	//template<>const HBOOL HMathUtility::Valid( const HSINT& in_src );
	//template<>const HBOOL HMathUtility::Valid( const HREAL& in_src );

	/////**/
	////template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );

	//template<>const HBOOL HMathUtility::ValidNot( const HU8& in_src );
	//template<>const HBOOL HMathUtility::ValidNot( const HSINT& in_src );
	//template<>const HBOOL HMathUtility::ValidNot( const HREAL& in_src );

	/////**/
	////template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );

	//template<>const HBOOL HMathUtility::EpsilonZero( const HU8& in_src );
	//template<>const HBOOL HMathUtility::EpsilonZero( const HSINT& in_src );
	//template<>const HBOOL HMathUtility::EpsilonZero( const HREAL& in_src );

	/////**/
	////template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );

	//template<>const HBOOL HMathUtility::EpsilonZeroNot( const HU8& in_src );
	//template<>const HBOOL HMathUtility::EpsilonZeroNot( const HSINT& in_src );
	//template<>const HBOOL HMathUtility::EpsilonZeroNot( const HREAL& in_src );

	///**/
	//template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqual( const HU8& in_lhs, const HU8& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const HSINT& in_lhs, const HSINT& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const HREAL& in_lhs, const HREAL& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqual< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs );
	
	//template<>const HBOOL HMathUtility::EpsilonEqual( const HU8& in_lhs, const HU8& in_rhs );
	//template<>const HBOOL HMathUtility::EpsilonEqual( const HSINT& in_lhs, const HSINT& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual< HREAL >( const HREAL& in_lhs, const HREAL& in_rhs );

	///**/
	//template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

	//template<>const HBOOL HMathUtility::EpsilonEqualNot( const HU8& in_lhs, const HU8& in_rhs );
	//template<>const HBOOL HMathUtility::EpsilonEqualNot( const HSINT& in_lhs, const HSINT& in_rhs );
	//template<>const HBOOL HMathUtility::EpsilonEqualNot( const HREAL& in_lhs, const HREAL& in_rhs );

	/////**/
	////template< typename IN_TYPE >const IN_TYPE HMathUtility::Pad( const IN_TYPE& in_value, const IN_TYPE& in_pad );

	//template<>const HU8 HMathUtility::Pad( const HU8& in_value, const HU8& in_pad );
	//template<>const HSINT HMathUtility::Pad( const HSINT& in_value, const HSINT& in_pad );
	//template<>const HREAL HMathUtility::Pad( const HREAL& in_value, const HREAL& in_pad );

};

#endif // _H_MATH_UTILITY_H_