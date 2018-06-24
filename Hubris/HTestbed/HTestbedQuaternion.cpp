//file: Hubris/HTestbed/HTestbedQuaternion.cpp

#include "Hubris/HTestbed/HTestbedQuaternion.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"

#include "Hubris/HMatrix/HMatrix_Export.h"
#include "Hubris/HQuaternion/HQuaternion_Export.h"
#include "Hubris/HString/HString_Export.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedQuaternion()
{
	HBOOL success = HTRUE;

	//HQuaternion( const HQuaternion& in_src );
	//HQuaternion( const IN_TYPE in_w, const IN_TYPE in_x, const IN_TYPE in_y, const IN_TYPE in_z );
	//HQuaternion();
	//~HQuaternion();
	//const HQuaternion& operator=( const HQuaternion& in_rhs );
	//HBOOL operator==( const HQuaternion& in_rhs )const;
	//HBOOL operator!=( const HQuaternion& in_rhs )const;
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 0.3F, 0.25F );
		HQuaternionREAL quat1( quat0 );
		HQuaternionREAL quat2 = quat0;
		HQuaternionREAL quat3;

		success &= ( quat0 == quat1 );
		success &= ( quat1 == quat0 );

		success &= ( quat0 == quat2 );
		success &= ( quat2 == quat0 );

		success &= !( quat0 != quat2 );
		success &= !( quat2 != quat0 );

		success &= ( quat0 != quat3 );
		success &= ( quat3 != quat0 );

		success &= !( quat0 == quat3 );
		success &= !( quat3 == quat0 );
	}

	//void WSet( const IN_TYPE in_w );
	//const IN_TYPE WGet()const;
	//void XSet( const IN_TYPE in_x );
	//const IN_TYPE XGet()const;
	//void YSet( const IN_TYPE in_y );
	//const IN_TYPE YGet()const;
	//void ZSet( const IN_TYPE in_z );
	//const IN_TYPE ZGet()const;
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 0.3F, 0.25F );
		quat0.WSet( 0.6F );
		quat0.XSet( 1.1F );
		quat0.YSet( 0.4F );
		quat0.ZSet( 0.35F );

		const HQuaternionREAL quat1( quat0 );

		success &= ( 0.6F == quat1.WGet() );
		success &= ( 1.1F == quat1.XGet() );
		success &= ( 0.4F == quat1.YGet() );
		success &= ( 0.35F == quat1.ZGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HQuaternion", success );

	return success;
}

/**/
static const HBOOL LocalTestbedQuaternionMathUtility()
{
	HBOOL success = HTRUE;

	//HMathUtility
	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 1.5F, 2.0F );
		HQuaternionREAL quat1( 2.5F, 1.5F, 1.0F, 0.5F );
		HQuaternionREAL quat2( 2.5F, 1.5F, 1.5F, 2.0F );

		success &= ( quat2 == HMathUtility::Maximum( quat0, quat1 ) );
		success &= ( quat2 == HMathUtility::Maximum( quat1, quat0 ) );
	}

	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 1.5F, 2.0F );
		HQuaternionREAL quat1( 2.5F, 1.5F, 1.0F, 0.5F );
		HQuaternionREAL quat2( 0.5F, 1.0F, 1.0F, 0.5F );

		success &= ( quat2 == HMathUtility::Minimum( quat0, quat1 ) );
		success &= ( quat2 == HMathUtility::Minimum( quat1, quat0 ) );
	}

	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Absolute( const IN_TYPE& in_src )
	{
		HQuaternionREAL quat0( 0.5F, -1.0F, 1.5F, -2.0F );
		HQuaternionREAL quat1( 0.5F, 1.0F, 1.5F, 2.0F );

		success &= ( quat1== HMathUtility::Absolute( quat0 ) );
	}

	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio )
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 1.5F, 2.0F );
		HQuaternionREAL quat1( 2.5F, 1.5F, 1.0F, 0.0F );
		HQuaternionREAL quat2( 1.0F, 1.125F, 1.375F, 1.5F );

		success &= ( quat2 == HMathUtility::Lerp( quat0, quat1, 0.25F ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::Valid( const IN_TYPE& in_src )
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 1.5F, 2.0F );

		success &= ( HMathUtility::Valid( quat0 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::ValidNot( const IN_TYPE& in_src )
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 1.5F, 2.0F );
		success &= !( HMathUtility::ValidNot( quat0 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonZero( const IN_TYPE & in_src )
	{
		HQuaternionREAL quat0( 0.0F, 0.0F, 0.0F, 0.0F );
		HQuaternionREAL quat1( 0.000000001F, 0.000000001F, -0.000000001F, -0.000000001F );
		HQuaternionREAL quat2( 0.0F, 1.0F, 0.0F, 0.0F );

		success &= ( HMathUtility::EpsilonZero( quat0 ) );
		success &= ( HMathUtility::EpsilonZero( quat1 ) );
		success &= !( HMathUtility::EpsilonZero( quat2 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonZeroNot( const IN_TYPE & in_src )
	{
		HQuaternionREAL quat0( 0.0F, 0.0F, 0.0F, 0.0F );
		HQuaternionREAL quat1( 0.000000001F, 0.000000001F, -0.000000001F, -0.000000001F );
		HQuaternionREAL quat2( 0.0F, 1.0F, 0.0F, 0.0F );

		success &= !( HMathUtility::EpsilonZeroNot( quat0 ) );
		success &= !( HMathUtility::EpsilonZeroNot( quat1 ) );
		success &= ( HMathUtility::EpsilonZeroNot( quat2 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE & in_rhs )
	{
		HQuaternionREAL quat0( 1.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat1( 1.000000001F, 2.000000001F, 3.000000001F, 4.000000001F );
		HQuaternionREAL quat2( 1.0F, 1.0F, 0.0F, 0.0F );

		success &= ( HMathUtility::EpsilonEqual( quat0, quat1 ) );
		success &= !( HMathUtility::EpsilonEqual( quat0, quat2 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE & in_rhs )
	{
		HQuaternionREAL quat0( 1.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat1( 1.000000001F, 2.000000001F, 3.000000001F, 4.000000001F );
		HQuaternionREAL quat2( 1.0F, 1.0F, 0.0F, 0.0F );

		success &= !( HMathUtility::EpsilonEqualNot( quat0, quat1 ) );
		success &= ( HMathUtility::EpsilonEqualNot( quat0, quat2 ) );
	}


	HTESTBED_VALIDATE_STATUS( "HQuaternionMathUtility", success );

	return success;
}

/**/
static const HBOOL LocalTestbedQuaternionOperator()
{
	HBOOL success = HTRUE;

	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator +( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator +( const HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator +( const IN_TYPE in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 0.3F, 1.25F );
		HQuaternionREAL quat1( 0.3F, 0.8F, 1.2F, -0.3F );
		HQuaternionREAL quat3( 0.8F, 1.8F, 1.5F, 0.95F );
		HQuaternionREAL quat4( 1.5F, 1.0F, 0.3F, 1.25F );
		const HQuaternionREAL quat2 = quat0 + quat1;

		success &= ( quat3 == quat2 );
		success &= ( quat3 == quat2 );
		success &= ( quat4 == ( quat0 + 1.0F ) );
		success &= ( quat4 == ( 1.0F + quat0 ) );
	}

	//template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator +=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator +=( HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 0.3F, 1.25F );
		HQuaternionREAL quat1( 0.3F, 0.8F, 1.2F, -0.3F );
		HQuaternionREAL quat3( 0.8F, 1.8F, 1.5F, 0.95F );
		HQuaternionREAL quat4( 1.5F, 1.0F, 0.3F, 1.25F );

		HQuaternionREAL quat5( quat0 );
		quat5 += quat1;

		success &= ( quat5 == quat3 );

		HQuaternionREAL quat6( quat0 );
		quat6 += 1.0F;

		success &= ( quat6 == quat4 );
	}

	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const IN_TYPE in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	{
		HQuaternionREAL quat0( 1.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat1( 2.0F, 2.5F, 3.0F, 3.5F );
		HQuaternionREAL quat2( -1.0F, -0.5F, 0.0F, 0.5F );
		HQuaternionREAL quat3( 0.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat4( 0.0F, -2.0F, -3.0F, -4.0F );

		success &= ( quat2 == ( quat0 - quat1 ) );
		success &= ( quat3 == ( quat0 - 1.0F ) );
		success &= ( quat4 == ( 1.0F - quat0 ) );
	}

	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const HQuaternion< IN_TYPE >& in_src );
	{
		HQuaternionREAL quat0( 0.5F, 1.0F, 0.3F, 0.25F );
		HQuaternionREAL quat1( -0.5F, -1.0F, -0.3F, -0.25F );

		success &= ( quat0 == ( -quat1 ) );
	}

	//template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator -=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator -=( HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );
	{
		HQuaternionREAL quat0( 1.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat1( 2.0F, 2.5F, 3.0F, 3.5F );
		HQuaternionREAL quat2( -1.0F, -0.5F, 0.0F, 0.5F );
		HQuaternionREAL quat3( 0.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat4( 1.0F, 2.0F, 3.0F, 4.0F );

		quat0 -= quat1;
		success &= ( quat2 == quat0 );
		quat4 -= 1.0F;
		success &= ( quat4 == quat3 );
	}

	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator *( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator *=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	{
		HQuaternionREAL quat0( 1.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat1( 2.0F, 2.5F, 3.0F, 3.5F );
		HQuaternionREAL quat3( -26.0F, 5.0F, 12.0F, 10.0F );

		success &= ( quat3 == ( quat0 * quat1 ) );
		quat0 *= quat1;
		success &= ( quat3 == quat0 );
	}

	//template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator /( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	//template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator /=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	{
		HQuaternionREAL quat0( 1.0F, 2.0F, 3.0F, 4.0F );
		HQuaternionREAL quat1( 2.0F, 2.5F, 3.0F, 3.5F );
		HQuaternionREAL quat3( 0.95238101F, 0.0F, 0.19047621F, 0.095238104F );

		success &= ( quat3 == ( quat0 / quat1 ) );
		quat0 /= quat1;
		success &= ( quat3 == quat0 );
	}

	HTESTBED_VALIDATE_STATUS( "HQuaternionOperator", success );

	return success;
}

/**/
static const HBOOL LocalTestbedQuaternionTrait()
{
	HBOOL success = HTRUE;

	//name
	{
		success &= ( HString( "HQuaternionREAL" ) == HTraitName< HQuaternionREAL >::NameGet() );
	}

	//empty
	{
		success &= ( HQuaternionREAL() == HTraitEmpty< HQuaternionREAL >::EmptyGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HQuaternionTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedQuaternionUtility()
{
	HBOOL success = HTRUE;

	//HQuaternionUtility
	//static HVOID Normalise( TQuaternion& in_out_src );
	{
		HQuaternionREAL quat0( 2.0F, 0.0F, 2.0F, 0.0F );
		HQuaternionREAL quat1( 0.70710678F, 0.0F, 0.70710678F, 0.0F );
		HQuaternionREAL quat2( 1.0F, 1.0F, 1.0F, 1.0F );
		HQuaternionREAL quat3( 0.5F, 0.5F, 0.5F, 0.5F );

		success &= ( quat1 == HQuaternionUtility::Normalise( quat0 ) );
		success &= ( quat3 == HQuaternionUtility::Normalise( quat2 ) );
	}

	//static const IN_TYPE LengthSquared( const TQuaternion& in_src );
	{
		HQuaternionREAL quat0( 2.0F, 0.0F, 2.0F, 0.0F );
		HQuaternionREAL quat1( 0.70710678F, 0.0F, 0.70710678F, 0.0F );

		success &= ( 8.0F == HQuaternionUtility::LengthSquared( quat0 ) );
		success &= ( HMathUtility::EpsilonEqual( 1.0F, HQuaternionUtility::LengthSquared( quat1 ) ) );
	}

	//static const IN_TYPE Length( const TQuaternion& in_src );
	{
		HQuaternionREAL quat0( 2.0F, 0.0F, 2.0F, 0.0F );
		HQuaternionREAL quat1( 0.70710678F, 0.0F, 0.70710678F, 0.0F );

		success &= ( HMathUtility::EpsilonEqual( 2.82842712474619F, HQuaternionUtility::Length( quat0 ) ) );
		success &= ( HMathUtility::EpsilonEqual( 1.0F, HQuaternionUtility::LengthSquared( quat1 ) ) );
	}

	//static const TQuaternion Conjugate( const TQuaternion& in_src );
	{
		HQuaternionREAL quat0( 2.0F, 0.0F, 2.0F, 0.0F );
		HQuaternionREAL quat1( 2.0F, 0.0F, -2.0F, 0.0F );
		HQuaternionREAL quat2( 2.0F, 3.0F, 4.0F, 5.0F );
		HQuaternionREAL quat3( 2.0F, -3.0F, -4.0F, -5.0F );

		success &= ( quat1 == HQuaternionUtility::Conjugate( quat0 ) );
		success &= ( quat3 == HQuaternionUtility::Conjugate( quat2 ) );
	}

	//static const TQuaternion Inverse( const TQuaternion& in_src );
	{
		HQuaternionREAL quat0( 2.0F, 0.0F, 2.0F, 0.0F );
		HQuaternionREAL quat1( 0.25F, 0.0F, -0.25F, 0.0F );
		HQuaternionREAL quat2( 2.0F, 3.0F, 4.0F, 5.0F );
		HQuaternionREAL quat3( 0.037037037F, -0.055555556F, -0.074074075F, -0.092592597F );

		const HQuaternionREAL quat4 = HQuaternionUtility::Inverse( quat0 );
		const HQuaternionREAL quat5 = HQuaternionUtility::Inverse( quat2 );

		success &= ( quat1 == quat4 );
		success &= ( quat3 == quat5 );
	}

	//static const HMatrix< IN_TYPE, 4, 4> ConvertToMatrix( const TQuaternion& in_src );
	{
		HQuaternionREAL quat0( 0.70710678F, 0.0F, 0.70710678F, 0.0F );
		const HMatrixR4 matrix1 = HQuaternionUtility::ConvertToMatrix4( quat0 );
		HREAL data0[] = {
			0.0F, 0.0F, 1.0F, 0.0F,
			0.0F, 1.0F, 0.0F, 0.0F,
			-1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 0.0F, 1.0F,
		};

		success &= ( HMathUtility::EpsilonEqual( matrix1, HMatrixR4( data0 ) ) );

		HQuaternionREAL quat1( 1.0F, 0.0F, 0.0F, 0.0F );
		const HMatrixR4 matrix2 = HQuaternionUtility::ConvertToMatrix4( quat1 );

		success &= ( HMathUtility::EpsilonEqual( matrix2, HMatrixUtility::IdentityGet< HMatrixR4 >() ) );
	}

	//static const TQuaternion ConvertFromMatrix( const HMatrix< IN_TYPE, 4, 4>& in_src );
	{
		HQuaternionREAL quat0( 0.70710678F, 0.0F, 0.70710678F, 0.0F );
		HREAL data0[] = {
			0.0F, 0.0F, 1.0F, 0.0F,
			0.0F, 1.0F, 0.0F, 0.0F,
			-1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 0.0F, 1.0F,
		};
		const HQuaternionREAL quat1 = HQuaternionUtility::ConvertFromMatrix4( HMatrixR4( data0 ) );

		success &= ( HMathUtility::EpsilonEqual( quat0, quat1 ) );

		HQuaternionREAL quat2( 1.0F, 0.0F, 0.0F, 0.0F );
		const HQuaternionREAL quat3 = HQuaternionUtility::ConvertFromMatrix4( HMatrixUtility::IdentityGet< HMatrixR4 >() );

		success &= ( HMathUtility::EpsilonEqual( quat2, quat3 ) );
	}

	//const typename HQuaternionUtility< IN_TYPE >::TQuaternion Hubris::HQuaternionUtility< IN_TYPE >::BetweenVectors( const TVector& in_src, const TVector& in_dest )
	{
		const HVectorR3 vector0 = HMatrixConstructor::HVectorR3Construct( 1.0F, 1.0F, 0.0F );
		const HVectorR3 vector1 = HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0, 1.0F );

		const HVectorR3 vector2 = HMatrixUtility::Normalise( vector0 );
		const HVectorR3 vector3 = HMatrixUtility::Normalise( vector1 );

		const HQuaternionREAL quat0 = HQuaternionUtility::BetweenVectors( vector0, vector1 );
		const HQuaternionREAL quat1 = HQuaternionUtility::BetweenVectors( vector2, vector3 );

		success &= ( HMathUtility::EpsilonEqual( quat0, quat1 ) );

		const HVectorR3 vector4 = HQuaternionUtility::MultiplyVector( quat0, vector2 );

		success = ( HMathUtility::Absolute( vector1 - vector4 ) < HVectorR3( 0.00001F ) );
		//success &= ( HMathUtility::EpsilonEqual( vector1, vector4 ) );
	}

	HTESTBED_VALIDATE_STATUS( "HQuaternionUtility", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedQuaternion()
{
	HTESTBED_VALIDATE_START( "TestbedQuaternion" );
	HBOOL success = HTRUE;

	success &= LocalTestbedQuaternion();
	success &= LocalTestbedQuaternionMathUtility();
	success &= LocalTestbedQuaternionOperator();
	success &= LocalTestbedQuaternionTrait();
	success &= LocalTestbedQuaternionUtility();

	return success;
}

/**/
