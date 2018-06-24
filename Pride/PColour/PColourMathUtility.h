//file: Pride/PColour/PColourMathUtility.h
#ifndef _P_COLOUR_MATH_UTILITY_H_
#define _P_COLOUR_MATH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

/**/
namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 1 >PColourMono;
	typedef PColour< Hubris::HU8, 3 >PColourRgb;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 1 >PColourRealMono;
	typedef PColour< Hubris::HREAL, 3 >PColourRealRgb;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;
};

/**/
namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// template method overload declarations
	/**/
	//template const Pride::PColourMono     HMathUtility::Maximum( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs );
	//template const Pride::PColourRgb      HMathUtility::Maximum( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs );
	//template const Pride::PColourRgba     HMathUtility::Maximum( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs );
	//template const Pride::PColourRealMono HMathUtility::Maximum( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs );
	//template const Pride::PColourRealRgb  HMathUtility::Maximum( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs );
	//template const Pride::PColourRealRgba HMathUtility::Maximum( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs );

	//template const Pride::PColourMono     HMathUtility::Minimum( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs );
	//template const Pride::PColourRgb      HMathUtility::Minimum( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs );
	//template const Pride::PColourRgba     HMathUtility::Minimum( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs );
	//template const Pride::PColourRealMono HMathUtility::Minimum( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs );
	//template const Pride::PColourRealRgb  HMathUtility::Minimum( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs );
	//template const Pride::PColourRealRgba HMathUtility::Minimum( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs );

	//template const Pride::PColourMono     HMathUtility::Absolute( const Pride::PColourMono&     in_src );
	//template const Pride::PColourRgb      HMathUtility::Absolute( const Pride::PColourRgb&      in_src );
	//template const Pride::PColourRgba     HMathUtility::Absolute( const Pride::PColourRgba&     in_src );
	//template const Pride::PColourRealMono HMathUtility::Absolute( const Pride::PColourRealMono& in_src );
	//template const Pride::PColourRealRgb  HMathUtility::Absolute( const Pride::PColourRealRgb&  in_src );
	//template const Pride::PColourRealRgba HMathUtility::Absolute( const Pride::PColourRealRgba& in_src );

	//template const Pride::PColourMono     HMathUtility::Lerp( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs, const HREAL in_ratio );
	//template const Pride::PColourRgb      HMathUtility::Lerp( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs, const HREAL in_ratio );
	//template const Pride::PColourRgba     HMathUtility::Lerp( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs, const HREAL in_ratio );
	//template const Pride::PColourRealMono HMathUtility::Lerp( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs, const HREAL in_ratio );
	//template const Pride::PColourRealRgb  HMathUtility::Lerp( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs, const HREAL in_ratio );
	//template const Pride::PColourRealRgba HMathUtility::Lerp( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs, const HREAL in_ratio );

	//template const HBOOL HMathUtility::Valid( const Pride::PColourMono&     in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PColourRgb&      in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PColourRgba&     in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PColourRealMono& in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PColourRealRgb&  in_src );
	//template const HBOOL HMathUtility::Valid( const Pride::PColourRealRgba& in_src );

	//template const HBOOL HMathUtility::ValidNot( const Pride::PColourMono&     in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PColourRgb&      in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PColourRgba&     in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PColourRealMono& in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PColourRealRgb&  in_src );
	//template const HBOOL HMathUtility::ValidNot( const Pride::PColourRealRgba& in_src );

	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PColourMono&     in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PColourRgb&      in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PColourRgba&     in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PColourRealMono& in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PColourRealRgb&  in_src );
	//template const HBOOL HMathUtility::EpsilonZero( const Pride::PColourRealRgba& in_src );

	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PColourMono&     in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PColourRgb&      in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PColourRgba&     in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PColourRealMono& in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PColourRealRgb&  in_src );
	//template const HBOOL HMathUtility::EpsilonZeroNot( const Pride::PColourRealRgba& in_src );

	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqual( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs );

	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs );
	//template const HBOOL HMathUtility::EpsilonEqualNot( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs );


};

/**/
#endif // _P_COLOUR_MATH_UTILITY_H_