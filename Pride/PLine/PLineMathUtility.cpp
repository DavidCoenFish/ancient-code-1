//file: Pride/PLine/PLineMathUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLine/PLineMathUtility.h"

#include "Pride/PLine/PLine.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PLine Hubris::HMathUtility::Maximum< PLine >( const PLine& in_lhs, const PLine& in_rhs )
{
	PLine value;

	value.OriginSet( HMathUtility::Maximum( in_lhs.OriginGet(), in_rhs.OriginGet() ) );
	value.DirectionSet( HMathUtility::Maximum( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PLine Hubris::HMathUtility::Minimum< PLine >( const PLine& in_lhs, const PLine& in_rhs )
{
	PLine value;

	value.OriginSet( HMathUtility::Minimum( in_lhs.OriginGet(), in_rhs.OriginGet() ) );
	value.DirectionSet( HMathUtility::Minimum( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template<>
const PLineR2 Hubris::HMathUtility::Absolute< PLineR2 >( const PLineR2& in_src )
{
	PLineR2 value;

	value.OriginSet( HMathUtility::Absolute( in_src.OriginGet() ) );
	value.DirectionSet( HMathUtility::Absolute( in_src.DirectionGet() ) );

	return value;
}
template<>
const PLineR3 Hubris::HMathUtility::Absolute< PLineR3 >( const PLineR3& in_src )
{
	PLineR3 value;

	value.OriginSet( HMathUtility::Absolute( in_src.OriginGet() ) );
	value.DirectionSet( HMathUtility::Absolute( in_src.DirectionGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*
const PLine Hubris::HMathUtility::Lerp< PLine >( const PLine& in_lhs, const PLine& in_rhs, const HREAL in_ratio )
{
	PLine value;

	value.OriginSet( HMathUtility::Lerp( in_lhs.OriginGet(), in_rhs.OriginGet(), in_ratio ) );
	value.DirectionSet( HMathUtility::Lerp( in_lhs.DirectionGet(), in_rhs.DirectionGet(), in_ratio ) );

	return value;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::Valid< PLineR2 >( const PLineR2& in_src )
{
	return( ( HMathUtility::Valid( in_src.OriginGet() ) ) && ( HMathUtility::Valid( in_src.DirectionGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PLineR3 >( const PLineR3& in_src )
{
	return( ( HMathUtility::Valid( in_src.OriginGet() ) ) && ( HMathUtility::Valid( in_src.DirectionGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PLineR2 >( const PLineR2& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PLineR3 >( const PLineR3& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PLineR2 >( const PLineR2& in_src )
{
	return( ( HMathUtility::EpsilonZero( in_src.OriginGet() ) ) && ( HMathUtility::EpsilonZero( in_src.DirectionGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PLineR3 >( const PLineR3& in_src )
{
	return( ( HMathUtility::EpsilonZero( in_src.OriginGet() ) ) && ( HMathUtility::EpsilonZero( in_src.DirectionGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PLineR2 >( const PLineR2& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PLineR3 >( const PLineR3& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PLineR2 >( const PLineR2& in_lhs, const PLineR2& in_rhs )
{
	return( ( HMathUtility::EpsilonEqual( in_lhs.OriginGet(), in_rhs.OriginGet() ) ) && ( HMathUtility::EpsilonEqual( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PLineR3 >( const PLineR3& in_lhs, const PLineR3& in_rhs )
{
	return( ( HMathUtility::EpsilonEqual( in_lhs.OriginGet(), in_rhs.OriginGet() ) ) && ( HMathUtility::EpsilonEqual( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PLineR2 >( const PLineR2& in_lhs, const PLineR2& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PLineR3 >( const PLineR3& in_lhs, const PLineR3& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}

/**/