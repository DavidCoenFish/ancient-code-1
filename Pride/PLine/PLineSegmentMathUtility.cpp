//file: Pride/PLine/PLineSegmentMathUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLine/PLineSegmentMathUtility.h"

#include "Pride/PLine/PLineSegment.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/

///////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PLineSegment Hubris::HMathUtility::Maximum< PLineSegment >( const PLineSegment& in_lhs, const PLineSegment& in_rhs )
{
	PLineSegment value;

	value.OriginSet( HMathUtility::Maximum( in_lhs.OriginGet(), in_rhs.OriginGet() ) );
	value.DirectionSet( HMathUtility::Maximum( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PLineSegment Hubris::HMathUtility::Minimum< PLineSegment >( const PLineSegment& in_lhs, const PLineSegment& in_rhs )
{
	PLineSegment value;

	value.OriginSet( HMathUtility::Minimum( in_lhs.OriginGet(), in_rhs.OriginGet() ) );
	value.DirectionSet( HMathUtility::Minimum( in_lhs.DirectionGet(), in_rhs.DirectionGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template<>
const PLineSegmentR2 Hubris::HMathUtility::Absolute< PLineSegmentR2 >( const PLineSegmentR2& in_src )
{
	PLineSegmentR2 value( in_src );

	value.LineSet( HMathUtility::Absolute( in_src.LineGet() ) );

	return value;
}
template<>
const PLineSegmentR3 Hubris::HMathUtility::Absolute< PLineSegmentR3 >( const PLineSegmentR3& in_src )
{
	PLineSegmentR3 value( in_src );

	value.LineSet( HMathUtility::Absolute( in_src.LineGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*
const PLineSegment Hubris::HMathUtility::Lerp< PLineSegment >( const PLineSegment& in_lhs, const PLineSegment& in_rhs, const HREAL in_ratio )
{
	PLineSegment value;

	value.OriginSet( HMathUtility::Lerp( in_lhs.OriginGet(), in_rhs.OriginGet(), in_ratio ) );
	value.DirectionSet( HMathUtility::Lerp( in_lhs.DirectionGet(), in_rhs.DirectionGet(), in_ratio ) );

	return value;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*
const HBOOL Hubris::HMathUtility::Valid< PLineSegment >( const PLineSegment& in_src )
{
	return( ( HMathUtility::Valid( in_src.OriginGet() ) ) && ( HMathUtility::Valid( in_src.DirectionGet() ) ) )
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*
const HBOOL Hubris::HMathUtility::ValidNot< PLineSegment >( const PLineSegment& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*
const HBOOL Hubris::HMathUtility::EpsilonZero< PLineSegment >( const PLineSegment& in_src )
{
	return( ( HMathUtility::EpsilonZero( in_src.OriginGet() ) ) && ( HMathUtility::EpsilonZero( in_src.DirectionGet() ) ) )
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PLineSegment >( const PLineSegment& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PLineSegmentR2 >( const PLineSegmentR2& in_lhs, const PLineSegmentR2& in_rhs )
{
	if( HFALSE == HMathUtility::EpsilonEqual( in_lhs.LineGet(), in_rhs.LineGet() ) )
	{
		return HFALSE;
	}
	if( in_lhs.BoundsUpperValidGet() != in_rhs.BoundsUpperValidGet() )
	{
		return HFALSE;
	}
	if( HTRUE == in_lhs.BoundsUpperValidGet() )
	{
		if( HFALSE == HMathUtility::EpsilonEqual( in_lhs.BoundsUpperGet(), in_rhs.BoundsUpperGet() ) )
		{
			return HFALSE;
		}
	}

	if( in_lhs.BoundsLowerValidGet() != in_rhs.BoundsLowerValidGet() )
	{
		return HFALSE;
	}
	if( HTRUE == in_lhs.BoundsLowerValidGet() )
	{
		if( HFALSE == HMathUtility::EpsilonEqual( in_lhs.BoundsLowerGet(), in_rhs.BoundsLowerGet() ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PLineSegmentR3 >( const PLineSegmentR3& in_lhs, const PLineSegmentR3& in_rhs )
{
	if( HFALSE == HMathUtility::EpsilonEqual( in_lhs.LineGet(), in_rhs.LineGet() ) )
	{
		return HFALSE;
	}
	if( in_lhs.BoundsUpperValidGet() != in_rhs.BoundsUpperValidGet() )
	{
		return HFALSE;
	}
	if( HTRUE == in_lhs.BoundsUpperValidGet() )
	{
		if( HFALSE == HMathUtility::EpsilonEqual( in_lhs.BoundsUpperGet(), in_rhs.BoundsUpperGet() ) )
		{
			return HFALSE;
		}
	}

	if( in_lhs.BoundsLowerValidGet() != in_rhs.BoundsLowerValidGet() )
	{
		return HFALSE;
	}
	if( HTRUE == in_lhs.BoundsLowerValidGet() )
	{
		if( HFALSE == HMathUtility::EpsilonEqual( in_lhs.BoundsLowerGet(), in_rhs.BoundsLowerGet() ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PLineSegmentR2 >( const PLineSegmentR2& in_lhs, const PLineSegmentR2& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PLineSegmentR3 >( const PLineSegmentR3& in_lhs, const PLineSegmentR3& in_rhs )
{
	return( !HMathUtility::EpsilonEqual( in_lhs, in_rhs ) );
}

/**/