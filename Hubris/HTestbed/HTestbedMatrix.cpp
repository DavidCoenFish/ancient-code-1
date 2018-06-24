//file: Hubris/HTestbed/HTestbedMatrix.cpp

#include "Hubris/HTestbed/HTestbedMatrix.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonMemory.h"
#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixConstructor.h"
#include "Hubris/HMatrix/HMatrixMathUtility.h"
#include "Hubris/HMatrix/HMatrixOperator.h"
#include "Hubris/HMatrix/HMatrixTrait.h"
#include "Hubris/HMatrix/HMatrixUtility.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HVariables/HVariablesMath.h"


//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedMatrix()
{
	HBOOL success = HTRUE;

	const HREAL data0[] = { 3.0F, 2.0F, -5.3F, 7.8F };
	const HREAL data1[] = { 1.0F, 1.0F, 1.0F, 1.0F };

	//HMatrix( const TMatrix& in_src );
	//HMatrix( const IN_TYPE* const in_data );
	//explicit HMatrix( const IN_TYPE in_default = 0 );
	//~HMatrix();
	//const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator=( const TMatrix& in_src );
	//const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator=( const IN_TYPE in_value );
	{
		const HMatrixR2 matrix0( data0 );
		const HMatrixR2 matrix1( data1 );
		const HMatrixR2 matrix2( 1.0F );
		const HMatrixR2 matrix3( matrix0 );
		const HMatrixR2 matrix4 = matrix0;
		const HMatrixR2 matrix5;

		success &= ( matrix0 == matrix3 );
		success &= ( matrix3 == matrix0 );
		success &= ( matrix0 == matrix4 );
		success &= ( matrix4 == matrix0 );
		success &= ( matrix0 != matrix5 );
		success &= ( matrix5 != matrix0 );
		success &= !( matrix0 != matrix4 );
		success &= !( matrix4 != matrix0 );
		success &= !( matrix0 == matrix5 );
		success &= !( matrix5 == matrix0 );

		success &= ( matrix1 == matrix2 );
		success &= ( matrix2 == matrix1 );
	}
	//const IN_TYPE* const DataGet()const;
	//HVOID DataSet( const IN_TYPE* const in_data );
	//HVOID DataSet( const IN_TYPE in_data );
	{
		const HMatrixR2 matrix0( data0 );
		success &= ( 0 == HCommonMemory::MemoryCompair( &data0[ 0 ], matrix0.DataGet(), sizeof( data0 ) ) );
		HMatrixR2 matrix1;
		matrix1.DataSet( data0 );
		success &= ( 0 == HCommonMemory::MemoryCompair( &data0[ 0 ], matrix1.DataGet(), sizeof( data0 ) ) );
	}
	//const IN_TYPE operator[]( HSINT in_index )const;
	//IN_TYPE& operator[]( HSINT in_index );
	//static HSINT IndexGet( const HSINT in_x, const HSINT in_y );
	{
		const HMatrixR2 matrix0( data0 );
		success &= ( 3.0F == matrix0[ 0 ] );
		success &= ( 2.0F == matrix0[ 1 ] );
		success &= ( -5.3F == matrix0[ 2 ] );
		success &= ( 7.8F == matrix0[ 3 ] );

		HMatrixR2 matrix1( data0 );
		matrix1[ 2 ] = 7.1F;
		success &= ( 7.1F == matrix1[ 2 ] );

		success &= ( 0 == HMatrixR2::IndexGet( 0, 0 ) );
		success &= ( 1 == HMatrixR2::IndexGet( 1, 0 ) );
		success &= ( 2 == HMatrixR2::IndexGet( 0, 1 ) );
		success &= ( 3 == HMatrixR2::IndexGet( 1, 1 ) );

		success &= ( 0 == HVectorR3::IndexGet( 0, 0 ) );
		success &= ( 1 == HVectorR3::IndexGet( 1, 0 ) );
		success &= ( 2 == HVectorR3::IndexGet( 2, 0 ) );
		success &= ( 6 == HMatrixR4::IndexGet( 2, 1 ) );
		success &= ( 10 == HMatrixR4::IndexGet( 2, 2 ) );
		success &= ( 14 == HMatrixR4::IndexGet( 2, 3 ) );
	}

	HTESTBED_VALIDATE_STATUS( "HMatrix", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMatrixConstructor()
{
	HBOOL success = HTRUE;

	//static HVectorS2 HVectorS2Construct( const HSINT in_x, const HSINT in_y );
	{
		HSINT dataS2[] = { 45, -108 };
		success &= ( HVectorS2( dataS2 ) == HMatrixConstructor::HVectorS2Construct( 45, -108 ) );
		success &= ( HVectorS2( dataS2 ) != HMatrixConstructor::HVectorS2Construct( 45, 105 ) );
	}

	//static HVectorS3 HVectorS3Construct( const HSINT in_x, const HSINT in_y, const HSINT in_z );
	{
		HSINT dataS3[] = { 45, -108, 459 };
		success &= ( HVectorS3( dataS3 ) == HMatrixConstructor::HVectorS3Construct( 45, -108, 459 ) );
		success &= ( HVectorS3( dataS3 ) != HMatrixConstructor::HVectorS3Construct( 45, 105, 0 ) );
	}

	//static HVectorR2 HVectorR2Construct( const HREAL in_x, const HREAL in_y );
	{
		HREAL dataR2[] = { 8.5F, 7.3F };
		success &= ( HVectorR2( dataR2 ) == HMatrixConstructor::HVectorR2Construct( 8.5F, 7.3F ) );
		success &= ( HVectorR2( dataR2 ) != HMatrixConstructor::HVectorR2Construct( 2.3F, 7.3F ) );
	}

	//static HVectorR3 HVectorR3Construct( const HREAL in_x, const HREAL in_y, const HREAL in_z );
	{
		const HREAL dataR3[] = { 8.5F, 7.3F, 4.9F };
		success &= ( HVectorR3( dataR3 ) == HMatrixConstructor::HVectorR3Construct( 8.5F, 7.3F, 4.9F ) );
		success &= ( HVectorR3( dataR3 ) != HMatrixConstructor::HVectorR3Construct( 2.3F, 7.3F, 4.9F ) );
	}

	//static HVectorR4 HVectorR4Construct( const HREAL in_x, const HREAL in_y, const HREAL in_z, const HREAL in_w );
	{
		const HREAL dataR4[] = { 8.5F, 7.3F, 4.9F, -8.6F };
		success &= ( HVectorR4( dataR4 ) == HMatrixConstructor::HVectorR4Construct( 8.5F, 7.3F, 4.9F, -8.6F ) );
		success &= ( HVectorR4( dataR4 ) != HMatrixConstructor::HVectorR4Construct( 2.3F, 7.3F, 4.9F, -8.6F ) );
	}

	//static HMatrixR4 HMatrixR4ConstructAxisAngle( const HVectorR3& in_axis, const HREAL in_angleRad );
	{
		const HMatrixR4 matrix0 = HMatrixConstructor::HMatrixR4ConstructAxisAngle( 
			HMatrixConstructor::HVectorR3AxisZ(),
			0.0F
			);
		success &= ( matrix0 == HMatrixUtility::IdentityGet< HMatrixR4 >() );

		const HREAL dataR4[] = { 
			0.70710677F, 0.70710677F, 0.0F, 0.0F,
			-0.70710677F, 0.70710677F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			0.0F, 0.0F, 0.0F, 1.0F,
		
		};
		const HMatrixR4 matrix1 = HMatrixConstructor::HMatrixR4ConstructAxisAngle( 
			HMatrixConstructor::HVectorR3AxisZ(),
			HVariablesMath::PiHalfGet< HREAL >() * 0.5F
			);

		success &= ( matrix1 == HMatrixR4( dataR4 ) );
	}

	//static HMatrixR4 HMatrixR4ConstructAtUp( const HVectorR3& in_targetAt, const HVectorR3& in_targetUp, const HVectorR3& in_baseAt, const HVectorR3& in_baseUp );
	{
		const HMatrixR4 matrix0 = HMatrixConstructor::HMatrixR4ConstructAtUp( 
			HMatrixConstructor::HVectorR3AxisY(),
			HMatrixConstructor::HVectorR3AxisZ()
			);
		success &= ( matrix0 == HMatrixUtility::IdentityGet< HMatrixR4 >() );

		HREAL dataR4[] = { 
			0.0F, 1.0F, 0.0F, 0.0F,
			-1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			0.0F, 0.0F, 0.0F, 1.0F,
		
		};
		const HMatrixR4 matrix1 = HMatrixConstructor::HMatrixR4ConstructAtUp( 
			-HMatrixConstructor::HVectorR3AxisX(),
			HMatrixConstructor::HVectorR3AxisZ()
			);
		success &= ( matrix1 == HMatrixR4( dataR4 ) );
	}

	//static HMatrixR4 HMatrixR4ConstructLookAt( const HVectorR3& in_pos, const HVectorR3& in_target, const HVectorR3& in_up );
	{
		const HMatrixR4 matrix0 = HMatrixConstructor::HMatrixR4ConstructLookAt( 
			HTraitEmpty< HVectorR3 >::EmptyGet(),
			HMatrixConstructor::HVectorR3AxisY(),
			HMatrixConstructor::HVectorR3AxisZ()
			);
		success &= ( matrix0 == HMatrixUtility::IdentityGet< HMatrixR4 >() );

		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		HREAL data1[] = { 5.0F, 3.0F, 4.0F };
		HREAL dataR4[] = { 
			0.0F, -1.0F, 0.0F, 0.0F,
			1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			2.0F, 3.0F, 4.0F, 1.0F,
		};

		const HMatrixR4 matrix1 = HMatrixConstructor::HMatrixR4ConstructLookAt( 
			HVectorR3( data0 ),
			HVectorR3( data1 ),
			HMatrixConstructor::HVectorR3AxisZ()
			);
		success &= ( matrix1 == HMatrixR4( dataR4 ) );
	}

	//static const HVectorR3& HVectorR3AxisX();
	{
		HREAL dataR3[] = { 1.0F, 0.0F, 0.0F };
		success &= ( HVectorR3( dataR3 ) == HMatrixConstructor::HVectorR3AxisX() );
	}

	//static const HVectorR3& HVectorR3AxisY();
	{
		HREAL dataR3[] = { 0.0F, 1.0F, 0.0F };
		success &= ( HVectorR3( dataR3 ) == HMatrixConstructor::HVectorR3AxisY() );
	}

	//static const HVectorR3& HVectorR3AxisZ();
	{
		HREAL dataR3[] = {  0.0F, 0.0F, 1.0F };
		success &= ( HVectorR3( dataR3 ) == HMatrixConstructor::HVectorR3AxisZ() );
	}

	HTESTBED_VALIDATE_STATUS( "HMatrixConstructor", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMatrixMathUtility()
{
	HBOOL success = HTRUE;

	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		HREAL data1[] = { 3.5F, 2.5F, 1.5F };
		HREAL data2[] = { 3.5F, 2.5F, 3.0F };
		const HVectorR3 vector0 = HMathUtility::Maximum( HVectorR3( data0 ), HVectorR3( data1 ) );

		success &= ( HVectorR3( data2 ) == vector0 );
	}

	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		HREAL data1[] = { 3.5F, 2.5F, 1.5F };
		HREAL data2[] = { 1.0F, 2.0F, 1.5F };
		const HVectorR3 vector0 = HMathUtility::Minimum( HVectorR3( data0 ), HVectorR3( data1 ) );

		success &= ( HVectorR3( data2 ) == vector0 );
	}

	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Absolute( const IN_TYPE& in_src )
	{
		HREAL data0[] = { -1.0F, 2.0F, -3.0F };
		HREAL data1[] = { 1.0F, 2.0F, 3.0F };
		const HVectorR3 vector0 = HMathUtility::Absolute( HVectorR3( data0 ) );

		success &= ( HVectorR3( data1 ) == vector0 );
	}

	//const IN_TYPE Hubris::HMathUtility< IN_TYPE >::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio )
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		HREAL data1[] = { 2.0F, 2.5F, 1.0F };
		HREAL data2[] = { 1.2F, 2.1F, 2.6F };
		const HVectorR3 vector0 = HMathUtility::Lerp( HVectorR3( data0 ), HVectorR3( data1 ), 0.2F );

		success &= ( HVectorR3( data2 ) == vector0 );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::Valid( const IN_TYPE& in_src )
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		success &= HMathUtility::Valid( HVectorR3( data0 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::ValidNot( const IN_TYPE& in_src )
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		success &= !HMathUtility::ValidNot( HVectorR3( data0 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonZero( const IN_TYPE & in_src )
	{
		HREAL data0[] = { 0.0F, 0.0F, 0.0F };
		HREAL data1[] = { 0.0F, 0.000000001F, -0.000000001F };
		HREAL data2[] = { 0.0F, 0.000000001F, 5.0F };
		success &= HMathUtility::EpsilonZero( HVectorR3( data0 ) );
		success &= HMathUtility::EpsilonZero( HVectorR3( data1 ) );
		success &= !HMathUtility::EpsilonZero( HVectorR3( data2 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonZeroNot( const IN_TYPE & in_src )
	{
		HREAL data0[] = { 0.0F, 0.0F, 0.0F };
		HREAL data1[] = { 0.0F, 0.000000001F, -0.000000001F };
		HREAL data2[] = { 0.0F, 0.000000001F, 5.0F };
		success &= !HMathUtility::EpsilonZeroNot( HVectorR3( data0 ) );
		success &= !HMathUtility::EpsilonZeroNot( HVectorR3( data1 ) );
		success &= HMathUtility::EpsilonZeroNot( HVectorR3( data2 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE & in_rhs )
	{
		HREAL data0[] = { 1.0F, 2.0F, 0.0F };
		HREAL data1[] = { 1.0F, 2.000000001F, -0.000000001F };
		HREAL data2[] = { 1.0F, 2.000000001F, 5.0F };
		success &= HMathUtility::EpsilonEqual( HVectorR3( data0 ), HVectorR3( data1 ) );
		success &= HMathUtility::EpsilonEqual( HVectorR3( data1 ), HVectorR3( data0 ) );
		success &= !HMathUtility::EpsilonEqual( HVectorR3( data0 ), HVectorR3( data2 ) );
	}

	//HBOOL Hubris::HMathUtility< IN_TYPE >::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE & in_rhs )
	{
		HREAL data0[] = { 1.0F, 2.0F, 0.0F };
		HREAL data1[] = { 1.0F, 2.000000001F, -0.000000001F };
		HREAL data2[] = { 1.0F, 2.000000001F, 5.0F };
		success &= !HMathUtility::EpsilonEqualNot( HVectorR3( data0 ), HVectorR3( data1 ) );
		success &= !HMathUtility::EpsilonEqualNot( HVectorR3( data1 ), HVectorR3( data0 ) );
		success &= HMathUtility::EpsilonEqualNot( HVectorR3( data0 ), HVectorR3( data2 ) );
	}

	HTESTBED_VALIDATE_STATUS( "HMatrixMathUtility", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMatrixOperator()
{
	HBOOL success = HTRUE;

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator == ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator == ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator == ( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 1.0F, 2.0F, 0.0F };
		HREAL data1[] = { 1.0F, 2.0F, 3.0F };
		HREAL data2[] = { 2.5F, 2.5F, 2.5F };

		success &= ( HVectorR3( data0 ) == HVectorR3( data0 ) );
		success &= !( HVectorR3( data0 ) == HVectorR3( data1 ) );
		success &= ( HVectorR3( data2 ) == 2.5F );
		success &= ( 2.5F == HVectorR3( data2 ) );
		success &= !( HVectorR3( data2 ) == 3.5F );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator != ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator != ( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator != ( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 1.0F, 2.0F, 0.0F };
		HREAL data1[] = { 1.0F, 2.0F, 3.0F };
		HREAL data2[] = { 2.5F, 2.5F, 2.5F };

		success &= !( HVectorR3( data0 ) != HVectorR3( data0 ) );
		success &= ( HVectorR3( data0 ) != HVectorR3( data1 ) );
		success &= !( HVectorR3( data2 ) != 2.5F );
		success &= !( 2.5F != HVectorR3( data2 ) );
		success &= ( HVectorR3( data2 ) != 3.5F );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator +( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator +( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator +( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		HREAL data1[] = { 2.0F, 3.0F, 4.0F };
		HREAL data2[] = { 2.0F, 4.0F, 6.0F };

		success &= ( ( HVectorR3( data0 ) + HVectorR3( data0 ) ) == HVectorR3( data2 ) );
		success &= ( ( HVectorR3( data0 ) + 1.0F ) == HVectorR3( data1 ) );
		success &= ( ( 1.0F + HVectorR3( data0 ) ) == HVectorR3( data1 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator +=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator +=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		HREAL data1[] = { 2.0F, 3.0F, 4.0F };
		HREAL data2[] = { 2.0F, 4.0F, 6.0F };

		HVectorR3 vector0( data0 );
		HVectorR3 vector1( data0 );

		vector0 += vector0;
		vector1 += 1.0F;
		success &= ( vector0 == HVectorR3( data2 ) );
		success &= ( vector1 == HVectorR3( data1 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		HREAL data1[] = { 0.0F, 1.0F, 2.0F };
		HREAL data2[] = { 0.0F, 0.0F, 0.0F };
		HREAL data3[] = { 0.0F, -1.0F, -2.0F };

		success &= ( ( HVectorR3( data0 ) - HVectorR3( data0 ) ) == HVectorR3( data2 ) );
		success &= ( ( HVectorR3( data0 ) - 1.0F ) == HVectorR3( data1 ) );
		success &= ( ( 1.0F - HVectorR3( data0 ) ) == HVectorR3( data3 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator -( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs );
	{
		HREAL data0[] = { 1.0F, -2.0F, 3.0F };
		HREAL data1[] = { -1.0F, 2.0F, -3.0F };

		success &= ( HVectorR3( data0 ) == ( -HVectorR3( data1 ) ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator -=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator -=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	{
		HREAL data0[] = { 1.0F, 2.0F, 3.0F };
		HREAL data1[] = { 0.0F, 1.0F, 2.0F };

		HVectorR3 vector0( data0 );
		HVectorR3 vector1( data0 );

		vector0 -= vector0;
		vector1 -= 1.0F;
		success &= ( vector0 == HVectorR3() );
		success &= ( vector1 == HVectorR3( data1 ) );
	}
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator *( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator *( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 1.0F, 1.5F, 2.0F };
		HREAL data1[] = { 2.0F, 3.0F, 4.0F };

		success &= ( ( 2.0F * HVectorR3( data0 ) ) == HVectorR3( data1 ) );
		success &= ( ( HVectorR3( data0 ) * 2.0F ) == HVectorR3( data1 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator *=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	{
		HREAL data0[] = { 1.0F, 1.5F, 2.0F };
		HREAL data1[] = { 2.0F, 3.0F, 4.0F };
		HVectorR3 vector0( data0 );
		vector0 *= 2.0F;

		success &= ( vector0 == HVectorR3( data1 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator /( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > operator /( const IN_TYPE& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		HREAL data1[] = { 1.0F, 1.5F, 2.0F };
		HREAL data2[] = { 0.5F, 0.3333333333333333333F, 0.25F };

		success &= ( ( HVectorR3( data0 ) / 2.0F ) == HVectorR3( data1 ) );
		success &= ( ( 1.0F / HVectorR3( data0 ) ) == HVectorR3( data2 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator /=( HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const IN_TYPE& in_rhs );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		HREAL data1[] = { 1.0F, 1.5F, 2.0F };
		HVectorR3 vector0( data0 );
		vector0 /= 2.0F;

		success &= ( vector0 == HVectorR3( data1 ) );
	}

	// return type doesn't specialise, so template for a_a * a_1 and a_a * b_1 and a_a * a_a
	//internal still uses a_c = a_b * b_c
	//template< typename IN_TYPE, HSINT IN_A, HSINT IN_B, HSINT IN_C >const HMatrix< IN_TYPE, IN_B, IN_C > operator *( const HMatrix< IN_TYPE, IN_A, IN_A >& in_lhs, const HMatrix< IN_TYPE, IN_B, IN_C >& in_rhs );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F, 5.0F };
		HREAL data1[] = { -3.0F, 2.0F, 4.0F, 5.0F };

		HVectorR4 vector0 = HVectorR4( data0 )* HMatrixUtility::IdentityGet< HMatrixR4 >();

		success &= ( vector0 == HVectorR4( data0 ) );

		const HMatrixR4 matrix1 = HMatrixConstructor::HMatrixR4ConstructAtUp( 
			-HMatrixConstructor::HVectorR3AxisX(),
			HMatrixConstructor::HVectorR3AxisZ()
			);

		HVectorR4 vector1 = HVectorR4( data0 ) * matrix1;

		success &= ( vector1 == HVectorR4( data1 ) );
	}

	//template< typename IN_TYPE, HSINT IN_A >const HMatrix< IN_TYPE, IN_A, IN_A >& operator *=( HMatrix< IN_TYPE, IN_A, IN_A >& in_lhs, const HMatrix< IN_TYPE, IN_A, IN_A >& in_rhs );
	{
		const HMatrixR4 matrix1 = HMatrixConstructor::HMatrixR4ConstructAtUp( 
			-HMatrixConstructor::HVectorR3AxisX(),
			HMatrixConstructor::HVectorR3AxisZ()
			);

		HMatrixR4 matrix2( matrix1 );
		matrix2	*= HMatrixUtility::IdentityGet< HMatrixR4 >();

		success &= ( matrix1 == matrix2 );

		HMatrixR4 matrix3( matrix1 );
		matrix3 *= matrix1;

		HREAL data1[] = { 
			-1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, -1.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			0.0F, 0.0F, 0.0F, 1.0F,
		};	
	
		success &= ( matrix3 == HMatrixR4( data1 ) );
	}

	//// return true if each members safifies condition
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator<( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		HREAL data1[] = { 1.0F, 1.5F, 2.0F };
		HREAL data2[] = { 2.0F, 3.0F, 3.0F };

		success &= ( HVectorR3( data1 ) < HVectorR3( data0 ) );
		success &= ( HVectorR3( data2 ) < HVectorR3( data0 ) );
		success &= !( HVectorR3( data0 ) < HVectorR3( data2 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator<=( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		HREAL data1[] = { 1.0F, 1.5F, 2.0F };
		HREAL data2[] = { 2.0F, 3.0F, 3.0F };

		success &= ( HVectorR3( data0 ) <= HVectorR3( data0 ) );
		success &= ( HVectorR3( data1 ) <= HVectorR3( data0 ) );
		success &= ( HVectorR3( data2 ) <= HVectorR3( data0 ) );
		success &= !( HVectorR3( data0 ) <= HVectorR3( data2 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator>( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		HREAL data1[] = { 1.0F, 1.5F, 2.0F };
		HREAL data2[] = { 2.0F, 3.0F, 5.0F };

		success &= !( HVectorR3( data1 ) > HVectorR3( data0 ) );
		success &= ( HVectorR3( data2 ) > HVectorR3( data0 ) );
	}

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >HBOOL operator>=( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		HREAL data1[] = { 1.0F, 1.5F, 2.0F };
		HREAL data2[] = { 1.0F, 1.5F, 5.0F };

		success &= ( HVectorR3( data0 ) >= HVectorR3( data0 ) );
		success &= !( HVectorR3( data1 ) >= HVectorR3( data0 ) );
		success &= ( HVectorR3( data2 ) >= HVectorR3( data1 ) );
	}

	HTESTBED_VALIDATE_STATUS( "HMatrixOperator", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMatrixTrait()
{
	HBOOL success = HTRUE;

	//name
	{
		success &= ( HString( "HMatrixR4" ) == HTraitName< HMatrixR4 >::NameGet() );
		success &= ( HString( "HVectorR3" ) == HTraitName< HVectorR3 >::NameGet() );
	}

	//empty
	{
		success &= ( HMatrixR4() == HTraitEmpty< HMatrixR4 >::EmptyGet() );
		success &= ( HVectorR3() == HTraitEmpty< HVectorR3 >::EmptyGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HMatrixTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedMatrixUtility()
{
	HBOOL success = HTRUE;

	//template const HVectorR2 HMatrixUtilityCross( const HVectorR2& in_lhs );
	{
		HREAL data0[] = { 1.0F, 0.5F };
		HREAL data1[] = { -0.5F, 1.0F };
		success &= ( HMathUtility::EpsilonEqual( HVectorR2( data1 ), HMatrixUtility::CrossProduct( HVectorR2( data0 ) ) ) );
	}
	//template const HVectorR3 HMatrixUtilityCross( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
	{
		HREAL data0[] = { 1.0F, 0.0F, 0.0F };
		HREAL data1[] = { 0.0F, 1.0F, 0.0F };
		HREAL data2[] = { 0.0F, 0.0F, 1.0F };
		success &= ( HMathUtility::EpsilonEqual( HVectorR3( data2 ), HMatrixUtility::CrossProduct( HVectorR3( data0 ), HVectorR3( data1 ) ) ) );
	}
	//template const HREAL HMatrixUtilityDot( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	{
		HREAL data0[] = { 3.0F, 2.0F };
		HREAL data1[] = { 3.0F, 2.0F };
		success &= ( HMathUtility::EpsilonEqual( 13.0F, HMatrixUtility::DotProduct( HVectorR2( data0 ), HVectorR2( data1 ) ) ) );
	}

	//template const HREAL HMatrixUtilityDot( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
	{
		HREAL data0[] = { 3.0F, 2.0F, 1.0F };
		HREAL data1[] = { 3.0F, 2.0F, 2.0F };
		success &= ( HMathUtility::EpsilonEqual( 15.0F, HMatrixUtility::DotProduct( HVectorR3( data0 ), HVectorR3( data1 ) ) ) );
	}

	//template const HVectorR2 HMatrixUtility::Reflect( const HVectorR2& in_unitMirror, const HVectorR2& in_vector );
	{
		HREAL data0[] = { 0.0F, 1.0F };
		HREAL data1[] = { 1.0F, 2.0F };
		HREAL data2[] = { -1.0F, 2.0F };
		success &= ( HMathUtility::EpsilonEqual( HVectorR2( data2 ), HMatrixUtility::Reflect( HVectorR2( data0 ), HVectorR2( data1 ) ) ) );
	}

	//template const HVectorR3 HMatrixUtility::Reflect( const HVectorR3& in_unitMirror, const HVectorR3& in_vector );
	{
		HREAL data0[] = { 0.0F, 0.0F, 1.0F };
		HREAL data1[] = { 1.0F, 2.0F, 3.0F };
		HREAL data2[] = { -1.0F, -2.0F, 3.0F };
		success &= ( HMathUtility::EpsilonEqual( HVectorR3( data2 ), HMatrixUtility::Reflect( HVectorR3( data0 ), HVectorR3( data1 ) ) ) );
	}

	//static IN_TYPE MemberSum( const TMatrix& in_src );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		success &= ( 9.0F == HMatrixUtility::MemberSum( HVectorR3( data0 ) ) );
	}

	//static IN_TYPE MemberProduct( const TMatrix& in_src );
	{
		HREAL data0[] = { 2.0F, 3.0F, 4.0F };
		success &= ( 24.0F == HMatrixUtility::MemberProduct( HVectorR3( data0 ) ) );
	}

	//static IN_TYPE Normalise( TMatrix& in_out_src );
	{
		HREAL data0[] = { 2.0F, 2.0F, 0.0F };
		HREAL data1[] = { 0.7071067811865F, 0.7071067811865F, 0.0F };
	
		HVectorR3 vector0 = HMatrixUtility::Normalise( HVectorR3( data0 ) );

		success &= ( HVectorR3( data1 ) == vector0 );
	}
	//static IN_TYPE Length( const TMatrix& in_vector ); 
	{
		HREAL data0[] = { 0.7071067811865F, 0.7071067811865F, 0.0F };
		HREAL data1[] = { 0.0F, 1.0F, 0.0F };
		HREAL data2[] = { 2.0F, 2.0F, -2.0F };

		success &= ( HMathUtility::EpsilonEqual( 1.0F, HMatrixUtility::Length( HVectorR3( data0 ) ) ) );
		success &= ( HMathUtility::EpsilonEqual( 1.0F, HMatrixUtility::Length( HVectorR3( data1 ) ) ) );
		success &= ( HMathUtility::EpsilonEqual( 3.46410161513775F, HMatrixUtility::Length( HVectorR3( data2 ) ) ) );
	}

	//static IN_TYPE LengthSquared( const TMatrix& in_vector ); 
	{
		HREAL data0[] = { 0.7071067811865F, 0.7071067811865F, 0.0F };
		HREAL data1[] = { 0.0F, 1.0F, 0.0F };
		HREAL data2[] = { 2.0F, 2.0F, -2.0F };

		success &= ( HMathUtility::EpsilonEqual( 1.0F, HMatrixUtility::LengthSquared( HVectorR3( data0 ) ) ) );
		success &= ( HMathUtility::EpsilonEqual( 1.0F, HMatrixUtility::LengthSquared( HVectorR3( data1 ) ) ) );
		success &= ( HMathUtility::EpsilonEqual( 12.0F, HMatrixUtility::LengthSquared( HVectorR3( data2 ) ) ) );
	}

	//HMatrixUtility
	//static IN_TYPE Determinant( const TMatrix& in_src ); 
	{
		HREAL data0[] = {
			1.0F, 2.0F, 3.0F,
			3.0F, 3.0F, 1.0F,
			2.0F, 1.0F, 3.0F
		};

		success &= ( HMathUtility::EpsilonEqual( -15.0F, HMatrixUtility::Determinant( HMatrixR3( data0 ) ) ) );
	}

	//static TMatrix Transpose( const TMatrix& in_src );
	{
		HREAL data0[] = {
			1.0F, -2.0F, -0.5F,
			0.5F, 0.5F, -1.0F,
			2.0F, 1.0F, 0.5F
		};

		HREAL data1[] = {
			1.0F, 0.5F, 2.0F,
			-2.0F, 0.5F, 1.0F,
			-0.5F, -1.0F, 0.5F
		};

		success &= ( HMatrixR3( data1 ) == HMatrixUtility::Transpose( HMatrixR3( data0 ) ) );
	}

	//static TMatrix Inverse( const TMatrix& in_src );
	{
		HREAL data0[] = {
			1.0F, 0.0F, 0.0F,
			0.0F, 1.0F, 2.0F,
			1.0F, 1.0F, 1.0F
		};

		HREAL data1[] = {
			1.0F, 0.0F, 0.0F,
			-2.0F, -1.0F, 2.0F,
			1.0F, 1.0F, -1.0F
		};

		const HMatrixR3 matrix1 = HMatrixUtility::Inverse( HMatrixR3( data0 ) );

		success &= ( HMatrixR3( data1 ) == matrix1 );

		const HMatrixR3 matrix2 = HMatrixR3( data0 ) * HMatrixR3( data1 );
		success &= ( HMathUtility::EpsilonEqual( matrix2, HMatrixUtility::IdentityGet< HMatrixR3 >() ) );
	}

	//static const TMatrix& Identity();
	{
		HREAL data0[] = {
			1.0F, 0.0F, 0.0F,
			0.0F, 1.0F, 0.0F,
			0.0F, 0.0F, 1.0F
		};

		success &= ( HMatrixR3( data0 ) == HMatrixUtility::IdentityGet< HMatrixR3 >() );
	}

	//static HVectorR3 TranslateGet( const HMatrixR4& in_matrix );
	{
		HREAL data1[] = { 
			1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 1.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			3.0F, 5.0F, 7.0F, 1.0F,
		};	

		HREAL data2[] = { 3.0F, 5.0F, 7.0F };

		const HVectorR3 vector0 = HMatrixUtility::TranslateGet< HMatrixR4, HVectorR3 >( HMatrixR4( data1 ) );
		success &= ( vector0 == HVectorR3( data2 ) );
	}

	//static HVOID TranslateSet( HMatrixR4& out_matrix, const HVectorR3& in_translate );
	{
		HREAL data0[] = { 
			1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 1.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			0.0F, 0.0F, 0.0F, 1.0F,
		};	

		HREAL data1[] = { 
			1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 1.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			3.0F, 5.0F, 7.0F, 1.0F,
		};	

		HREAL data2[] = { 3.0F, 5.0F, 7.0F };

		HMatrixR4 matrix0( data0 );

		HMatrixUtility::TranslateSet( matrix0, HVectorR3( data2 ) );
		success &= ( matrix0 == HMatrixR4( data1 ) );
	}

	//static HVectorR3 VectorProduct( const HMatrixR4& in_lhs, const HVectorR3& in_rhs );
	{
		HREAL data1[] = { 
			0.0F, 1.0F, 0.0F, 0.0F,
			1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			3.0F, 5.0F, 7.0F, 1.0F,
		};	

		HREAL data2[] = { 3.0F, 5.0F, 7.0F };
		HREAL data3[] = { 8.0F, 8.0F, 14.0F };
		const HVectorR3 vector0 = HMatrixUtility::VectorProduct( HMatrixR4( data1 ), HVectorR3( data2 ) );

		success &= ( vector0 == HVectorR3( data3 ) );
	}

	//static HVectorR3 VectorProductNoTranslate( const HMatrixR4& in_lhs, const HVectorR3& in_rhs );
	{
		HREAL data1[] = { 
			0.0F, 1.0F, 0.0F, 0.0F,
			1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			3.0F, 5.0F, 7.0F, 1.0F,
		};	

		HREAL data2[] = { 3.0F, 5.0F, 7.0F };
		HREAL data3[] = { 5.0F, 3.0F, 7.0F };
		const HVectorR3 vector0 = HMatrixUtility::VectorProductNoTranslate( HMatrixR4( data1 ), HVectorR3( data2 ) );

		success &= ( vector0 == HVectorR3( data3 ) );
	}

	//static HVOID Decompose( 
	//	TMatrix& out_matrixRotate,
	//	TMatrix& out_matrixScale,
	//	TMatrix& out_matrixTranslate,
	//	const TMatrix& in_matrix
	//	);
	{
		const HREAL data0[] = { 
			0.0F, 0.5F, 0.5F, 0.0F,
			-0.5F, 0.5F, 0.0F, 0.0F,
			0.0F, -0.5F, 0.5F, 0.0F,
			3.0F, 5.0F, 7.0F, 1.0F,
		};	

		const HMatrixR4 matrix0( data0 );
		HMatrixR4 matrix1;
		HMatrixR4 matrix2;
		HMatrixR4 matrix3;

		HMatrixUtility::Decompose( 
			matrix1,
			matrix2,
			matrix3,
			matrix0
			);

		const HMatrixR4 matrix4 = matrix1 * matrix2 * matrix3;

		success &= ( HTRUE == HMathUtility::EpsilonEqual( matrix4, matrix0 ) );
	}

	HTESTBED_VALIDATE_STATUS( "HMatrixUtility", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedMatrix()
{
	HTESTBED_VALIDATE_START( "TestbedMatrix" );
	HBOOL success = HTRUE;

	success &= LocalTestbedMatrix();
	success &= LocalTestbedMatrixConstructor();
	success &= LocalTestbedMatrixMathUtility();
	success &= LocalTestbedMatrixOperator();
	success &= LocalTestbedMatrixTrait();
	success &= LocalTestbedMatrixUtility();

	return success;
}

/**/