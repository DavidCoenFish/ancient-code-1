//file: Pride/PColour/PColourMathUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PColour/PColourMathUtility.h"

#include "Pride/PColour/PColour.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/

///////////////////////////////////////////////////////
// public static methods
/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const Pride::PColourMono     Hubris::HMathUtility::Maximum< PColourMono     >( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs )
{
	Pride::PColourMono value;
	value.DataSet( HMathUtility::Maximum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRgb      Hubris::HMathUtility::Maximum< PColourRgb      >( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs )
{
	Pride::PColourRgb value;
	value.DataSet( HMathUtility::Maximum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRgba     Hubris::HMathUtility::Maximum< PColourRgba     >( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs )
{
	Pride::PColourRgba value;
	value.DataSet( HMathUtility::Maximum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealMono Hubris::HMathUtility::Maximum< PColourRealMono >( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs )
{
	Pride::PColourRealMono value;
	value.DataSet( HMathUtility::Maximum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealRgb  Hubris::HMathUtility::Maximum< PColourRealRgb  >( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs )
{
	Pride::PColourRealRgb value;
	value.DataSet( HMathUtility::Maximum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealRgba Hubris::HMathUtility::Maximum< PColourRealRgba >( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs )
{
	Pride::PColourRealRgba value;
	value.DataSet( HMathUtility::Maximum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const Pride::PColourMono     Hubris::HMathUtility::Minimum< PColourMono     >( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs )
{
	PColourMono value;
	value.DataSet( HMathUtility::Minimum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRgb      Hubris::HMathUtility::Minimum< PColourRgb      >( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs )
{
	PColourRgb value;
	value.DataSet( HMathUtility::Minimum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRgba     Hubris::HMathUtility::Minimum< PColourRgba     >( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs )
{
	PColourRgba value;
	value.DataSet( HMathUtility::Minimum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealMono Hubris::HMathUtility::Minimum< PColourRealMono >( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs )
{
	PColourRealMono value;
	value.DataSet( HMathUtility::Minimum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealRgb  Hubris::HMathUtility::Minimum< PColourRealRgb  >( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs )
{
	PColourRealRgb value;
	value.DataSet( HMathUtility::Minimum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealRgba Hubris::HMathUtility::Minimum< PColourRealRgba >( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs )
{
	PColourRealRgba value;
	value.DataSet( HMathUtility::Minimum( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template<>
const Pride::PColourMono     Hubris::HMathUtility::Absolute< PColourMono     >( const Pride::PColourMono&     in_src )
{
	PColourMono value;
	value.DataSet( HMathUtility::Absolute( in_src.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRgb      Hubris::HMathUtility::Absolute< PColourRgb      >( const Pride::PColourRgb&      in_src )
{
	PColourRgb value;
	value.DataSet( HMathUtility::Absolute( in_src.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRgba     Hubris::HMathUtility::Absolute< PColourRgba     >( const Pride::PColourRgba&     in_src )
{
	PColourRgba value;
	value.DataSet( HMathUtility::Absolute( in_src.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealMono Hubris::HMathUtility::Absolute< PColourRealMono >( const Pride::PColourRealMono& in_src )
{
	PColourRealMono value;
	value.DataSet( HMathUtility::Absolute( in_src.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealRgb  Hubris::HMathUtility::Absolute< PColourRealRgb  >( const Pride::PColourRealRgb&  in_src )
{
	PColourRealRgb value;
	value.DataSet( HMathUtility::Absolute( in_src.DataGet() ) );
	return value;
}
template<>
const Pride::PColourRealRgba Hubris::HMathUtility::Absolute< PColourRealRgba >( const Pride::PColourRealRgba& in_src )
{
	PColourRealRgba value;
	value.DataSet( HMathUtility::Absolute( in_src.DataGet() ) );
	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*/
template<>
const Pride::PColourMono     Hubris::HMathUtility::Lerp< PColourMono     >( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs, const HREAL in_ratio )
{
	PColourMono value;
	value.DataSet( HMathUtility::Lerp( in_lhs.DataGet(), in_rhs.DataGet(), in_ratio ) );
	return value;
}
template<>
const Pride::PColourRgb      Hubris::HMathUtility::Lerp< PColourRgb      >( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs, const HREAL in_ratio )
{
	PColourRgb value;
	value.DataSet( HMathUtility::Lerp( in_lhs.DataGet(), in_rhs.DataGet(), in_ratio ) );
	return value;
}
template<>
const Pride::PColourRgba     Hubris::HMathUtility::Lerp< PColourRgba     >( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs, const HREAL in_ratio )
{
	PColourRgba value;
	value.DataSet( HMathUtility::Lerp( in_lhs.DataGet(), in_rhs.DataGet(), in_ratio ) );
	return value;
}
template<>
const Pride::PColourRealMono Hubris::HMathUtility::Lerp< PColourRealMono >( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs, const HREAL in_ratio )
{
	PColourRealMono value;
	value.DataSet( HMathUtility::Lerp( in_lhs.DataGet(), in_rhs.DataGet(), in_ratio ) );
	return value;
}
template<>
const Pride::PColourRealRgb  Hubris::HMathUtility::Lerp< PColourRealRgb  >( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs, const HREAL in_ratio )
{
	PColourRealRgb value;
	value.DataSet( HMathUtility::Lerp( in_lhs.DataGet(), in_rhs.DataGet(), in_ratio ) );
	return value;
}
template<>
const Pride::PColourRealRgba Hubris::HMathUtility::Lerp< PColourRealRgba >( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs, const HREAL in_ratio )
{
	PColourRealRgba value;
	value.DataSet( HMathUtility::Lerp( in_lhs.DataGet(), in_rhs.DataGet(), in_ratio ) );
	return value;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::Valid< PColourMono     >( const Pride::PColourMono&     in_src )
{
	return( HMathUtility::Valid( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PColourRgb      >( const Pride::PColourRgb&      in_src )
{
	return( HMathUtility::Valid( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PColourRgba     >( const Pride::PColourRgba&     in_src )
{
	return( HMathUtility::Valid( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PColourRealMono >( const Pride::PColourRealMono& in_src )
{
	return( HMathUtility::Valid( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PColourRealRgb  >( const Pride::PColourRealRgb&  in_src )
{
	return( HMathUtility::Valid( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PColourRealRgba >( const Pride::PColourRealRgba& in_src )
{
	return( HMathUtility::Valid( in_src.DataGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PColourMono     >( const Pride::PColourMono&     in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PColourRgb      >( const Pride::PColourRgb&      in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PColourRgba     >( const Pride::PColourRgba&     in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PColourRealMono >( const Pride::PColourRealMono& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PColourRealRgb  >( const Pride::PColourRealRgb&  in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PColourRealRgba >( const Pride::PColourRealRgba& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PColourMono     >( const Pride::PColourMono&     in_src )
{
	return( HMathUtility::EpsilonZero( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PColourRgb      >( const Pride::PColourRgb&      in_src )
{
	return( HMathUtility::EpsilonZero( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PColourRgba     >( const Pride::PColourRgba&     in_src )
{
	return( HMathUtility::EpsilonZero( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PColourRealMono >( const Pride::PColourRealMono& in_src )
{
	return( HMathUtility::EpsilonZero( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PColourRealRgb  >( const Pride::PColourRealRgb&  in_src )
{
	return( HMathUtility::EpsilonZero( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PColourRealRgba >( const Pride::PColourRealRgba& in_src )
{
	return( HMathUtility::EpsilonZero( in_src.DataGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PColourMono     >( const Pride::PColourMono&     in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PColourRgb      >( const Pride::PColourRgb&      in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PColourRgba     >( const Pride::PColourRgba&     in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PColourRealMono >( const Pride::PColourRealMono& in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PColourRealRgb  >( const Pride::PColourRealRgb&  in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PColourRealRgba >( const Pride::PColourRealRgba& in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.DataGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PColourMono     >( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PColourRgb      >( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PColourRgba     >( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PColourRealMono >( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PColourRealRgb  >( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PColourRealRgba >( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.DataGet(), in_rhs.DataGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PColourMono     >( const Pride::PColourMono&     in_lhs, const Pride::PColourMono&     in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PColourRgb      >( const Pride::PColourRgb&      in_lhs, const Pride::PColourRgb&      in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PColourRgba     >( const Pride::PColourRgba&     in_lhs, const Pride::PColourRgba&     in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PColourRealMono >( const Pride::PColourRealMono& in_lhs, const Pride::PColourRealMono& in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PColourRealRgb  >( const Pride::PColourRealRgb&  in_lhs, const Pride::PColourRealRgb&  in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.DataGet(), in_rhs.DataGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PColourRealRgba >( const Pride::PColourRealRgba& in_lhs, const Pride::PColourRealRgba& in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.DataGet(), in_rhs.DataGet() ) );
}

/**/










