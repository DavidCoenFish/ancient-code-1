//file: Pride/PUnitVector/PUnitVectorMathUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PUnitVector/PUnitVectorMathUtility.h"

#include "Pride/PUnitVector/PUnitVector_Export.h"

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
const PUnitVector Hubris::HMathUtility::Maximum< PUnitVector >( const PUnitVector& in_lhs, const PUnitVector& in_rhs )
{
	PUnitVector value;

	value.VectorSet( HMathUtility::Maximum( in_src.VectorGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*
const PUnitVector Hubris::HMathUtility::Minimum< PUnitVector >( const PUnitVector& in_lhs, const PUnitVector& in_rhs )
{
	PUnitVector value;

	value.VectorSet( HMathUtility::Minimum( in_src.VectorGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template<>
const PUnitVectorR2 Hubris::HMathUtility::Absolute< PUnitVectorR2 >( const PUnitVectorR2& in_src )
{
	PUnitVectorR2 value;

	value.VectorSet( HMathUtility::Absolute( in_src.VectorGet() ) );

	return value;
}

template<>
const PUnitVectorR3 Hubris::HMathUtility::Absolute< PUnitVectorR3 >( const PUnitVectorR3& in_src )
{
	PUnitVectorR3 value;

	value.VectorSet( HMathUtility::Absolute( in_src.VectorGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*
const PUnitVector Hubris::HMathUtility::Lerp< PUnitVector >( const PUnitVector& in_lhs, const PUnitVector& in_rhs, const HREAL in_ratio )
{
	PUnitVector value;

	value.VectorSet( HMathUtility::Lerp( in_lhs.VectorGet(), in_rhs.VectorGet(), in_ratio ) );

	return value;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::Valid< PUnitVectorR2 >( const PUnitVectorR2& in_src )
{
	return( HMathUtility::Valid( in_src.VectorGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::Valid< PUnitVectorR3 >( const PUnitVectorR3& in_src )
{
	return( HMathUtility::Valid( in_src.VectorGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PUnitVectorR2 >( const PUnitVectorR2& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}
template<>
const HBOOL Hubris::HMathUtility::ValidNot< PUnitVectorR3 >( const PUnitVectorR3& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PUnitVectorR2 >( const PUnitVectorR2& in_src )
{
	return( HMathUtility::EpsilonZero( in_src.VectorGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< PUnitVectorR3 >( const PUnitVectorR3& in_src )
{
	return( HMathUtility::EpsilonZero( in_src.VectorGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PUnitVectorR2 >( const PUnitVectorR2& in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.VectorGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< PUnitVectorR3 >( const PUnitVectorR3& in_src )
{
	return( HMathUtility::EpsilonZeroNot( in_src.VectorGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PUnitVectorR2 >( const PUnitVectorR2& in_lhs, const PUnitVectorR2& in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.VectorGet(), in_rhs.VectorGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< PUnitVectorR3 >( const PUnitVectorR3& in_lhs, const PUnitVectorR3& in_rhs )
{
	return( HMathUtility::EpsilonEqual( in_lhs.VectorGet(), in_rhs.VectorGet() ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PUnitVectorR2 >( const PUnitVectorR2& in_lhs, const PUnitVectorR2& in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.VectorGet(), in_rhs.VectorGet() ) );
}
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< PUnitVectorR3 >( const PUnitVectorR3& in_lhs, const PUnitVectorR3& in_rhs )
{
	return( HMathUtility::EpsilonEqualNot( in_lhs.VectorGet(), in_rhs.VectorGet() ) );
}

/**/