//file: Hubris/HMath/HMath.h
#ifndef _H_MATH_H_
#define _H_MATH_H_

#include "Hubris/HCommon/HCommonType.h"

/* 
	general math functions
	intended as collection of math functions
	since matrix supports HS32, so do we, even though a few var dont make that much sence

	the 'util' function expected to be performable on any 'math' type are over in HMathUtility
	const variables are in HVariablesMath
*/
namespace Hubris
{
	/**/
	struct HMath
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HMath();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		template< typename IN_TYPE >static const IN_TYPE SquareRoot( const IN_TYPE& in_value );
		template< typename IN_TYPE >static const IN_TYPE Square( const IN_TYPE& in_value );
		template< typename IN_TYPE >static const IN_TYPE Power( const IN_TYPE& in_value, const IN_TYPE& in_power );
		template< typename IN_TYPE >static const IN_TYPE Invert( const IN_TYPE& in_value );
		template< typename IN_TYPE >static const IN_TYPE CopySign( const IN_TYPE& in_value, const IN_TYPE& in_signSoure );
		template< typename IN_TYPE >static HVOID SinCos( const IN_TYPE& in_rad, IN_TYPE& out_sin, IN_TYPE& out_cos );
		template< typename IN_TYPE >static const IN_TYPE Sin( const IN_TYPE& in_rad );
		template< typename IN_TYPE >static const IN_TYPE Cos( const IN_TYPE& in_rad );
		template< typename IN_TYPE >static const IN_TYPE Tan( const IN_TYPE& in_rad );
		template< typename IN_TYPE >static const IN_TYPE SinArc( const IN_TYPE& in_ratio );
		template< typename IN_TYPE >static const IN_TYPE CosArc( const IN_TYPE& in_ratio );
		template< typename IN_TYPE >static const IN_TYPE TanArc( const IN_TYPE& in_ratio );
		template< typename IN_TYPE >static const IN_TYPE DegToRadian( const IN_TYPE& in_deg );
		template< typename IN_TYPE >static const IN_TYPE RadianToDeg( const IN_TYPE& in_rad );

	};

	//template<>const HREAL HMath::SquareRoot( const HREAL& in_value );
	//template<>const HREAL HMath::Square( const HREAL& in_value );
	//template<>const HREAL HMath::Power( const HREAL& in_value, const HREAL& in_power );
	//template<>const HREAL HMath::Invert( const HREAL& in_value );
	//template<>const HSINT HMath::CopySign( const HSINT& in_value, const HSINT& in_signSoure );
	//template<>const HREAL HMath::CopySign( const HREAL& in_value, const HREAL& in_signSoure );
	//template<>HVOID HMath::SinCos( const HREAL& in_rad, HREAL& out_sin, HREAL& out_cos );
	//template<>const HREAL HMath::Sin( const HREAL& in_rad );
	//template<>const HREAL HMath::Cos( const HREAL& in_rad );
	//template<>const HREAL HMath::Tan( const HREAL& in_rad );
	//template<>const HREAL HMath::SinArc( const HREAL& in_ratio );
	//template<>const HREAL HMath::CosArc( const HREAL& in_ratio );
	//template<>const HREAL HMath::TanArc( const HREAL& in_ratio );
	//template<>const HREAL HMath::DegToRadian( const HREAL& in_deg );
	//template<>const HREAL HMath::RadianToDeg( const HREAL& in_rad );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::SquareRoot( const IN_TYPE& in_value );

	//template const HSINT HMath::SquareRoot( const HSINT& in_value );
	//template const HREAL HMath::SquareRoot( const HREAL& in_value );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::Square( const IN_TYPE& in_value );

	//template const HSINT HMath::Square( const HSINT& in_value );
	//template const HREAL HMath::Square( const HREAL& in_value );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::Power( const IN_TYPE& in_value, const IN_TYPE& in_power );

	//template const HREAL HMath::Power( const HREAL& in_value, const HREAL& in_power );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::Invert( const IN_TYPE& in_value );

	//template const HREAL HMath::Invert( const HREAL& in_value );

	///* return a value the same sign as the source */
	//template< typename IN_TYPE >const IN_TYPE HMath::CopySign( const IN_TYPE& in_value, const IN_TYPE& in_signSoure );

	//template const HSINT HMath::CopySign( const HSINT& in_value, const HSINT& in_signSoure  );
	//template const HREAL HMath::CopySign( const HREAL& in_value, const HREAL& in_signSoure );

	///**/
	//template< typename IN_TYPE >HVOID HMath::SinCos( const IN_TYPE& in_rad, IN_TYPE& out_sin, IN_TYPE& out_cos );

	//template HVOID HMath::SinCos( const HREAL& in_rad, HREAL& out_sin, HREAL& out_cos );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::Sin( const IN_TYPE& in_rad );

	//template const HREAL HMath::Sin( const HREAL& in_rad );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::Cos( const IN_TYPE& in_rad );

	//template const HREAL HMath::Cos( const HREAL& in_rad );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::Tan( const IN_TYPE& in_rad );

	//template const HREAL HMath::Tan( const HREAL& in_rad );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::SinArc( const IN_TYPE& in_ratio );

	//template const HREAL HMath::SinArc( const HREAL& in_ratio );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::CosArc( const IN_TYPE& in_ratio );

	//template const HREAL HMath::CosArc( const HREAL& in_ratio );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::TanArc( const IN_TYPE& in_ratio );

	//template const HREAL HMath::TanArc( const HREAL& in_ratio );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::DegToRadian( const IN_TYPE& in_deg );

	//template const HREAL HMath::DegToRadian( const HREAL& in_deg );

	///**/
	//template< typename IN_TYPE >const IN_TYPE HMath::RadianToDeg( const IN_TYPE& in_rad );

	//template const HREAL HMath::RadianToDeg( const HREAL& in_rad );

	/**/
};

#endif // _H_MATH_H_