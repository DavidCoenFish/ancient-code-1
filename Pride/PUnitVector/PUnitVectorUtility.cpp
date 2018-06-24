//file: Pride/PUnitVector/PUnitVectorUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PUnitVector/PUnitVectorUtility.h"

#include "Pride/PUnitVector/PUnitVector.h"

#include< Hubris/HMath/HMath_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HBOOL PUnitVectorUtility::UnitVectorConstruct(
	PUnitVectorR2& out_unitVector,
	const Hubris::HVectorR2& in_vector, 
	Hubris::HREAL* const out_pLength
	)
{
	const HREAL length = HMatrixUtility::Length( in_vector );
	if( HNULL != out_pLength )
	{
		( *out_pLength) = length;
	}
	if( HTRUE == HMathUtility::EpsilonZero( length ) )
	{
		return HFALSE;
	}

	out_unitVector.VectorSet( in_vector * ( 1.0F / length ) );

	return HTRUE;
}

/**/
const Hubris::HBOOL PUnitVectorUtility::UnitVectorConstruct(
	PUnitVectorR3& out_unitVector,
	const Hubris::HVectorR3& in_vector, 
	Hubris::HREAL* const out_pLength
	)
{
	const HREAL length = HMatrixUtility::Length( in_vector );
	if( HNULL != out_pLength )
	{
		( *out_pLength) = length;
	}
	if( HTRUE == HMathUtility::EpsilonZero( length ) )
	{
		return HFALSE;
	}

	out_unitVector.VectorSet( in_vector * ( 1.0F / length ) );

	return HTRUE;
}

/**/
HVOID PUnitVectorUtility::UnitVectorFromPolar( 
	PUnitVectorR3& out_unitVector,
	const Hubris::HREAL in_latitude, //-180 ... 180 deg
	const Hubris::HREAL in_longitude //-90 ... 90 deg
	)
{
	HREAL localLatitude( in_latitude );
	while( localLatitude < -180.0F )
	{
		localLatitude += 360.0F;
	}
	while( 180.0F < localLatitude )
	{
		localLatitude -= 360.0F;
	}

	// y uses same sign as in_latitude
	const HREAL tempZ = HMath::Cos( ( 90.0F - in_longitude ) * HVariablesMath::DegToRadGet< HREAL >() );
	HREAL tempValueZ = 1.0F - ( tempZ * tempZ );
	if( 0.0F < tempValueZ )
	{
		tempValueZ = HMath::SquareRoot< HREAL >( tempValueZ );
	}

	const HREAL tempX = ( HMath::Cos< HREAL >( localLatitude * HVariablesMath::DegToRadGet< HREAL >() ) * tempValueZ );

	HREAL tempY = HVariablesMath::ZeroGet< HREAL >();
	const HREAL tempValue = 1.0F - ( ( tempX * tempX ) + ( tempZ * tempZ ) );
	if( 0.0F < tempValue )
	{
		tempY = HMath::SquareRoot< HREAL >( tempValue );
	}

	tempY = HMath::CopySign< HREAL >( tempY, localLatitude );

	out_unitVector.VectorSet( HMatrixConstructor::HVectorR3Construct( tempX, tempY, tempZ ) );
	
	return;
}

/**/
HVOID PUnitVectorUtility::PolarFromUnitVector(
	Hubris::HREAL& out_latitude, //-180 ... 180 deg
	Hubris::HREAL& out_longitude, //-90 ... 90 deg
	const PUnitVectorR3& in_unitVector
	)
{
	out_latitude = HVariablesMath::ZeroGet< HREAL >();
	HVectorR3 localVector( in_unitVector.VectorGet() );

	// -90 ... 90
	out_longitude = 90.0F - ( HMath::CosArc< HREAL >( localVector[ 2 ] ) * HVariablesMath::RadToDegGet< HREAL >() );

	localVector[ 2 ] = HVariablesMath::ZeroGet< HREAL >();
	localVector = HMatrixUtility::Normalise( localVector );

	//0 ... 180
	out_latitude = HMath::CosArc< HREAL >( localVector [ 0 ] ) * HVariablesMath::RadToDegGet< HREAL >();
	//-180 ... 180
	out_latitude = HMath::CopySign< HREAL >( out_latitude, localVector [ 1 ] );

	return;
}

/**/