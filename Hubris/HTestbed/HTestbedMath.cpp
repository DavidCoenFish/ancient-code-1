//file: Hubris/HTestbed/HTestbedMath.cpp

#include "Hubris/HTestbed/HTestbedMath.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HMath/HMath.h"
#include "Hubris/HMath/HMathArea.h"
#include "Hubris/HMath/HMathRandom.h"
#include "Hubris/HMath/HMathRandomObject.h"
#include "Hubris/HMath/HMathUtility.h"
#include "Hubris/HMath/HMathVolume.h"
#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixConstructor.h"
#include "Hubris/HVariables/HVariablesMath.h"

#include "Hubris/HFileSystem/HFileSystem_Export.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HVectorR2 >TArrayVectorR2;
typedef HContainerArray< HVectorR3 >TArrayVectorR3;

//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedMath()
{
	HBOOL success = HTRUE;

	//const HREAL HMath::SquareRoot( const HREAL& in_value );
	{
		success &= HMathUtility::EpsilonEqual( 2.0F, HMath::SquareRoot( 4.0F ) );
	}
	//const HREAL HMath::Square( const HREAL& in_value );
	{
		success &= HMathUtility::EpsilonEqual( 4.0F, HMath::Square( 2.0F ) );
	}
	//const HREAL HMath::Power( const HREAL& in_value, const HREAL& in_power );
	{
		success &= HMathUtility::EpsilonEqual( 5.1961524227066318805823390245176F, HMath::Power( 3.0F, 1.5F ) );
	}

	//const HREAL HMath::Invert( const HREAL& in_value );
	{
		success &= HMathUtility::EpsilonEqual( 0.5F, HMath::Invert( 2.0F ) );
	}

	//const HSINT HMath::CopySign( const HSINT& in_value, const HSINT& in_signSoure );
	//const HREAL HMath::CopySign( const HREAL& in_value, const HREAL& in_signSoure );
	{
		success &= HMathUtility::EpsilonEqual( 3, HMath::CopySign( 3, 1 ) );
		success &= HMathUtility::EpsilonEqual( -3, HMath::CopySign( 3, -2 ) );
		success &= HMathUtility::EpsilonEqual( 3, HMath::CopySign( -3, 1 ) );
		success &= HMathUtility::EpsilonEqual( -3, HMath::CopySign( -3, -2 ) );

		success &= HMathUtility::EpsilonEqual( 3.0F, HMath::CopySign( 3.0F, 1.0F ) );
		success &= HMathUtility::EpsilonEqual( -3.0F, HMath::CopySign( 3.0F, -2.0F ) );
		success &= HMathUtility::EpsilonEqual( 3.0F, HMath::CopySign( -3.0F, 1.0F ) );
		success &= HMathUtility::EpsilonEqual( -3.0F, HMath::CopySign( -3.0F, -2.0F ) );
	}

	//HVOID HMath::SinCos( const HREAL& in_rad, HREAL& out_sin, HREAL& out_cos );
	{
		HREAL sinValue0;
		HREAL cosValue0;
		HMath::SinCos( HVariablesMath::PiGet< HREAL >() / 4.0F, sinValue0, cosValue0 );
		success &= HMathUtility::EpsilonEqual( 0.70710678118654752440084436210485F, sinValue0 );
		success &= HMathUtility::EpsilonEqual( 0.70710678118654752440084436210485F, cosValue0 );

		HREAL sinValue1;
		HREAL cosValue1;
		HMath::SinCos( HVariablesMath::PiGet< HREAL >() / 2.0F, sinValue1, cosValue1 );
		success &= HMathUtility::EpsilonEqual( 1.0F, sinValue1 );
		success &= HMathUtility::EpsilonEqual( 0.0F, cosValue1 );
	}

	//const HREAL HMath::Sin( const HREAL& in_rad );
	{
		success &= HMathUtility::EpsilonEqual( 0.70710678118654752440084436210485F, HMath::Sin( HVariablesMath::PiGet< HREAL >() / 4.0F ) );
		success &= HMathUtility::EpsilonEqual( 1.0F, HMath::Sin( HVariablesMath::PiGet< HREAL >() / 2.0F ) );
	}

	//const HREAL HMath::Cos( const HREAL& in_rad );
	{
		success &= HMathUtility::EpsilonEqual( 0.70710678118654752440084436210485F, HMath::Cos( HVariablesMath::PiGet< HREAL >() / 4.0F ) );
		success &= HMathUtility::EpsilonEqual( 0.0F, HMath::Cos( HVariablesMath::PiGet< HREAL >() / 2.0F ) );
	}

	//const HREAL HMath::Tan( const HREAL& in_rad );
	{
		success &= HMathUtility::EpsilonEqual( 1.0F, HMath::Tan( HVariablesMath::PiGet< HREAL >() / 4.0F ) );
		success &= HMathUtility::EpsilonEqual( 1.7320508075688772935274463415059F, HMath::Tan( HVariablesMath::PiGet< HREAL >() / 3.0F ) );
	}

	//const HREAL HMath::SinArc( const HREAL& in_ratio );
	{
		success &= HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() / 4.0F, HMath::SinArc( 0.70710678118654752440084436210485F ) );
		success &= HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() / 2.0F, HMath::SinArc( 1.0F ) );
	}

	//const HREAL HMath::CosArc( const HREAL& in_ratio );
	{
		success &= HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() / 4.0F, HMath::CosArc( 0.70710678118654752440084436210485F ) );
		success &= HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() / 2.0F, HMath::CosArc( 0.0F ) );
	}

	//const HREAL HMath::TanArc( const HREAL& in_ratio );
	{
		success &= HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() / 4.0F, HMath::TanArc( 1.0F ) );
		success &= HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() / 3.0F, HMath::TanArc( 1.7320508075688772935274463415059F ) );
	}

	//const HREAL HMath::DegToRadian( const HREAL& in_deg );
	//const HREAL HMath::RadianToDeg( const HREAL& in_rad );

	HTESTBED_VALIDATE_STATUS( "HMath", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMathArea()
{
	HBOOL success = HTRUE;

	{
		TArrayVectorR2 arrayLoop;
		arrayLoop.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, 1.0F ) );
		arrayLoop.Insert( HMatrixConstructor::HVectorR2Construct( 2.0F, 1.0F ) );
		arrayLoop.Insert( HMatrixConstructor::HVectorR2Construct( 2.0F, 2.0F ) );
		arrayLoop.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, 3.0F ) );
		arrayLoop.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, 3.0F ) );
		arrayLoop.Insert( HMatrixConstructor::HVectorR2Construct( 0.0F, 2.0F ) );
		arrayLoop.Insert( HMatrixConstructor::HVectorR2Construct( 1.0F, 2.0F ) );

		success &= HMathUtility::EpsilonEqual< HREAL >( 2.5F, HMathArea::AreaClosedLoop( arrayLoop ) );
	}

	HTESTBED_VALIDATE_STATUS( "HMathArea", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMathRandom()
{
	HBOOL success = HTRUE;

	// HMathRandomObject
	{
		const HMathRandomObject randObject0( 3 );
		const HMathRandomObject randObject1( randObject0 );
		const HMathRandomObject randObject2 = randObject0;
		const HMathRandomObject randObject3;

		success &= ( randObject0 == randObject1 );
		success &= ( randObject1 == randObject0 );

		success &= ( randObject0 == randObject2 );
		success &= ( randObject2 == randObject0 );

		success &= !( randObject0 == randObject3 );
		success &= !( randObject3 == randObject0 );

		success &= !( randObject0 != randObject2 );
		success &= !( randObject2 != randObject0 );

		success &= ( randObject0 != randObject3 );
		success &= ( randObject3 != randObject0 );
	}

	{
		HFileSystem fileSystem;
		const HFileSystemTime systemTime = fileSystem.CurrentTimeGet();

		HMathRandomObject randObject0( systemTime.SeedGet() );
		HMathRandomObject randObject1( systemTime.SeedGet() );

		success &= ( randObject0 == randObject1 );

		HREAL sum = 0.0F;
		for( HSINT index = 0; index < 1000; ++index )
		{
			const HREAL value0 = randObject0.RandomRangeOneValueGet();
			const HREAL value1 = randObject1.RandomRangeOneValueGet();

			success &= ( value0 == value1 );

			sum += value0;
		}

		//printf( " %f\n", sum );
	}

	//for( HSINT index = 0; index < 60; ++index )
	//{
	//	printf( " %f\t%f\t%f\t%f\t%f\n", HMathRandom::RandomRangeOneValueGet(), HMathRandom::RandomRangeOneValueGet(), HMathRandom::RandomRangeOneValueGet(), HMathRandom::RandomRangeOneValueGet(), HMathRandom::RandomRangeOneValueGet() );
	//}

	HTESTBED_VALIDATE_STATUS( "HMathRandom", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMathUtility()
{
	HBOOL success = HTRUE;

	//template< typename IN_TYPE >static const IN_TYPE Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	{
		success &= ( 2.0F == HMathUtility::Maximum( 0.5F, 2.0F ) );
		success &= ( 2.0F == HMathUtility::Maximum( 2.0F, 0.5F ) );
		success &= ( -0.5F == HMathUtility::Maximum( -2.0F, -0.5F ) );
		success &= ( -0.5F == HMathUtility::Maximum( -0.5F, -2.0F ) );
		success &= ( 2 == HMathUtility::Maximum( 2, 1 ) );
		success &= ( 2 == HMathUtility::Maximum( 1, 2 ) );
		success &= ( -1 == HMathUtility::Maximum( -1, -2 ) );
		success &= ( -1 == HMathUtility::Maximum( -2, -1 ) );
	}

	//template< typename IN_TYPE >static const IN_TYPE Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	{
		success &= ( 0.5F == HMathUtility::Minimum( 0.5F, 2.0F ) );
		success &= ( 0.5F == HMathUtility::Minimum( 2.0F, 0.5F ) );
		success &= ( -2.0F == HMathUtility::Minimum( -2.0F, -0.5F ) );
		success &= ( -2.0F == HMathUtility::Minimum( -0.5F, -2.0F ) );
		success &= ( 1 == HMathUtility::Minimum( 2, 1 ) );
		success &= ( 1 == HMathUtility::Minimum( 1, 2 ) );
		success &= ( -2 == HMathUtility::Minimum( -1, -2 ) );
		success &= ( -2 == HMathUtility::Minimum( -2, -1 ) );
	}

	//template< typename IN_TYPE >static const IN_TYPE Absolute( const IN_TYPE& in_src );
	{
		success &= ( 2.0F == HMathUtility::Absolute( -2.0F ) );
		success &= ( 2.0F == HMathUtility::Absolute( 2.0F ) );
		success &= ( 2 == HMathUtility::Absolute( -2 ) );
		success &= ( 2 == HMathUtility::Absolute( 2 ) );
	}
	//template< typename IN_TYPE >static const IN_TYPE Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
	{
		success &= ( HTRUE == HMathUtility::EpsilonEqual( 2.0F, HMathUtility::Lerp( 1.0F, 4.0F, 1.0F / 3.0F ) ) );
	}
	//template< typename IN_TYPE >static const HBOOL Valid( const IN_TYPE& in_src );
	{
		success &= ( HTRUE == HMathUtility::Valid( 5.756F ) );	
	}
	//template< typename IN_TYPE >static const HBOOL ValidNot( const IN_TYPE& in_src );
	//template< typename IN_TYPE >static const HBOOL EpsilonZero( const IN_TYPE& in_src );
	{
		success &= ( HTRUE == HMathUtility::EpsilonZero( 0.0000000000000000000000001F ) );
	}
	//template< typename IN_TYPE >static const HBOOL EpsilonZeroNot( const IN_TYPE& in_src );
	{
		success &= ( HTRUE == HMathUtility::EpsilonZeroNot( 0.5F ) );
	}
	//template< typename IN_TYPE >static const HBOOL EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	{
		success &= ( HTRUE == HMathUtility::EpsilonEqual( 5.0F, 5.000000000000000000000001F ) );
	}
	//template< typename IN_TYPE >static const HBOOL EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	{
		success &= ( HTRUE == HMathUtility::EpsilonEqualNot( 5.0F, 5.5F ) );
	}
	////increment value so that remainder after division is zero (increaces, unlike % mod )
	//template< typename IN_TYPE >static const IN_TYPE Pad( const IN_TYPE& in_value, const IN_TYPE& in_pad );
	{
		success &= ( HTRUE == HMathUtility::EpsilonEqual( 8, HMathUtility::Pad( 5, 4 ) ) );
		success &= ( HTRUE == HMathUtility::EpsilonEqual( 8, HMathUtility::Pad( 6, 4 ) ) );
		success &= ( HTRUE == HMathUtility::EpsilonEqual( 8, HMathUtility::Pad( 7, 4 ) ) );
		success &= ( HTRUE == HMathUtility::EpsilonEqual( 8, HMathUtility::Pad( 8, 4 ) ) );
	}

	HTESTBED_VALIDATE_STATUS( "HMathUtility", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMathVolume()
{
	HBOOL success = HTRUE;

	//HMathVolume
	//template< typename IN_TYPE >static const IN_TYPE VolumeSphere( const IN_TYPE& in_radius );
	{
		success &= ( HTRUE == HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() * 4.0F / 3.0F, HMathVolume::VolumeSphere( 1.0F ) ) );		
		success &= ( HTRUE == HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() * 32.0F / 3.0F, HMathVolume::VolumeSphere( 2.0F ) ) );		
	}

	//template< typename IN_TYPE >static const IN_TYPE VolumeSphereIntersection( const IN_TYPE& in_radiusOne, const IN_TYPE& in_radiusTwo, const IN_TYPE& in_distance );
	{
		success &= ( HTRUE == HMathUtility::EpsilonEqual( HVariablesMath::PiGet< HREAL >() * 4.0F / 3.0F, HMathVolume::VolumeSphereIntersection( 1.0F, 3.0F, 2.0F ) ) );		
		success &= ( HTRUE == HMathUtility::EpsilonEqual( 2.0943952F, HMathVolume::VolumeSphereIntersection( 1.5F, 1.5F, 2.0F ) ) );		
	}

	//static const HREAL VolumeClosedMesh( const TArrayVectorR3& in_arrayTriangleTriplets );
	{
		TArrayVectorR3 arrayClosedMesh;
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, 0.0F, 0.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, -2.0F, -2.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( 0.0F, -2.0F, 0.0F ) );

		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( 0.0F, -2.0F, 0.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, -2.0F, -2.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, -2.0F, 0.0F ) );

		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, -2.0F, 0.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, -2.0F, -2.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, 0.0F, 0.0F ) );

		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( 0.0F, -2.0F, 0.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, -2.0F, -2.0F ) );
		arrayClosedMesh.Insert( HMatrixConstructor::HVectorR3Construct( -2.0F, 0.0F, 0.0F ) );

		success &= ( HTRUE == HMathUtility::EpsilonEqual( 2.6666667F, HMathVolume::VolumeClosedMesh( arrayClosedMesh ) ) );		
	}


	HTESTBED_VALIDATE_STATUS( "HMathVolume", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedMath()
{
	HTESTBED_VALIDATE_START( "TestbedMath" );
	HBOOL success = HTRUE;

	success &= LocalTestbedMath();
	success &= LocalTestbedMathArea();
	success &= LocalTestbedMathRandom();
	success &= LocalTestbedMathUtility();
	success &= LocalTestbedMathVolume();

	return success;
}