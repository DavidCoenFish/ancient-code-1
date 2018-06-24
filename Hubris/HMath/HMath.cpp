//file: Hubris/HMath/HMath.cpp

#include "Hubris/HubrisPreCompileHeader.h"

#include "Hubris/HMath/HMath.h"
#include "Hubris/HMath/HMathUtility.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HVariables/HVariablesMath.h"

#include <cmath>

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////////
// static public methods
/**/
template<>
const HREAL Hubris::HMath::SquareRoot< HREAL >( const HREAL& in_value )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_value ), "invalid param" );
	HCOMMON_ASSERT( 0 <= in_value, "invalid param" );

	return sqrt( in_value );
}

/**/
template<>
const HREAL Hubris::HMath::Square< HREAL >( const HREAL& in_value )
{
	//HCOMMON_ASSERT( HTRUE == HMathUtility::Valid( in_value ), "invalid param" );

	const HREAL returnValue = in_value * in_value;

	//HCOMMON_ASSERT( HTRUE == HMathUtility::Valid( returnValue ), "invalid param" );

	return returnValue;
}

/**/
template<>
const HREAL Hubris::HMath::Power< HREAL >( const HREAL& in_value, const HREAL& in_power )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_value ), "invalid param" );
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_power ), "invalid param" );
	//HCOMMON_ASSERT( !( ( true == HMathUtility::EpsilonZero( in_value ) ) && ( 0 <= in_power ) ), "invalid param" );

	HCOMMON_ASSERT( ( 0 < in_value ) || ( 0 <= in_power ), "invalid param" );

	HREAL returnValue = pow( in_value, in_power );

	HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}

/**/
template<>
const HREAL Hubris::HMath::Invert< HREAL >( const HREAL& in_value )
{
	HCOMMON_ASSERT( false == HMathUtility::EpsilonZero( in_value ), "invalid param" );

	const HREAL returnValue = HVariablesMath::UnitGet< HREAL >() / in_value;

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}

/**/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMath::CopySign(  const IN_TYPE& in_value, const IN_TYPE& in_signSoure )
{
	IN_TYPE result = HMathUtility::Absolute( in_value );

	if( in_signSoure < HVariablesMath::ZeroGet< IN_TYPE >() )
	{
		result = -result;
	}

	return result;
}

template const HSINT Hubris::HMath::CopySign< HSINT >( const HSINT& in_value, const HSINT& in_signSoure );
template const HREAL Hubris::HMath::CopySign< HREAL >( const HREAL& in_value, const HREAL& in_signSoure );

/**/
template< typename IN_TYPE >
HVOID Hubris::HMath::SinCos(  const IN_TYPE& in_rad, IN_TYPE& out_sin, IN_TYPE& out_cos )
{
	out_sin = Sin( in_rad );
	out_cos = Cos( in_rad );

	return;
}

template HVOID Hubris::HMath::SinCos< HREAL >( const HREAL& in_rad, HREAL& out_sin, HREAL& out_cos );

/**/
template< typename IN_TYPE >
const IN_TYPE Hubris::HMath::Sin( const IN_TYPE& in_rad )
{
	const IN_TYPE returnValue = sin( in_rad );
	return returnValue;
}

template const HREAL Hubris::HMath::Sin< HREAL >( const HREAL& in_rad );

/**/
template<>
const HREAL Hubris::HMath::Cos< HREAL >( const HREAL& in_rad )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_rad ), "invalid param" );

	const HREAL returnValue = cos( in_rad );

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}

/**/
template<>
const HREAL Hubris::HMath::Tan< HREAL >( const HREAL& in_rad )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_rad ), "invalid param" );

	const HREAL returnValue = tan( in_rad );

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}

/**/
template<> 
const HREAL Hubris::HMath::SinArc< HREAL >( const HREAL& in_ratio )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_ratio ), "invalid param" );

	const HREAL returnValue = asin( in_ratio );

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}
/**/
template<> 
const HREAL Hubris::HMath::CosArc< HREAL >( const HREAL& in_ratio )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_ratio ), "invalid param" );

	const HREAL returnValue = acos( in_ratio );

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}
/**/
template<> 
const HREAL Hubris::HMath::TanArc< HREAL >( const HREAL& in_ratio )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_ratio ), "invalid param" );

	const HREAL returnValue = atan( in_ratio );

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}

/**/
template<>
const HREAL Hubris::HMath::DegToRadian< HREAL >( const HREAL& in_deg )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_deg ), "invalid param" );

	const HREAL returnValue = in_deg * HVariablesMath::DegToRadGet< HREAL >();

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}

/**/
template<> 
const HREAL Hubris::HMath::RadianToDeg< HREAL >( const HREAL& in_rad )
{
	//HCOMMON_ASSERT( true == HMathUtility::Valid( in_rad ), "invalid param" );

	const HREAL returnValue = in_rad * HVariablesMath::RadToDegGet< HREAL >();

	//HCOMMON_ASSERT( true == HMathUtility::Valid( returnValue ), "invalid return" );

	return returnValue;
}

/**/
