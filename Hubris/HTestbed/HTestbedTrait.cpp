//file: Hubris/HTestbed/HTestbedTrait.cpp

#include "Hubris/HTestbed/HTestbedTrait.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HBuffer/HBuffer.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HFileSystem/HFileSystemPath.h"
#include "Hubris/HFileSystem/HFileSystemPathTrait.h"
#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixConstructor.h"
#include "Hubris/HMatrix/HMatrixOperator.h"
#include "Hubris/HMatrix/HMatrixTrait.h"
#include "Hubris/HMatrix/HMatrixUtility.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringTrait.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HTrait/HTraitBufferIn.h"
#include "Hubris/HTrait/HTraitBufferOut.h"
#include "Hubris/HTrait/HTraitEmpty.h"
#include "Hubris/HTrait/HTraitName.h"
#include "Hubris/HTrait/HTraitStringIn.h"
#include "Hubris/HTrait/HTraitStringOut.h"
#include "Hubris/HTrait/HTraitSwap.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local static functions
/**/
static const HBOOL LocalTestbedTraitBufferIn()
{
	HBOOL success = HTRUE;

	HTESTBED_VALIDATE_STATUS( "HTraitBufferIn", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTraitBufferOut()
{
	HBOOL success = HTRUE;

	{
		HBuffer buffer0;
		const HU8 value0 = 199;
		HTraitBufferInAppend( buffer0, value0 );
		HU8 value1 = 0;
		HSINT offset = 0;
		HTraitBufferOutGet( value1, offset, buffer0 );

		success &= ( value0 == value1 );

		buffer0.SizeSet( 100 );

		HTraitBufferInReplace( buffer0, value0, 50 );
		offset = 50;
		HU8 value2 = 0;
		HTraitBufferOutGet( value2, offset, buffer0 );

		success &= ( value0 == value2 );
	}

	{
		HBuffer buffer0;
		const HS8 value0 = -105;
		HTraitBufferInAppend( buffer0, value0 );
		HS8 value1 = 0;
		HSINT offset = 0;
		HTraitBufferOutGet( value1, offset, buffer0 );

		success &= ( value0 == value1 );

		buffer0.SizeSet( 100 );

		HTraitBufferInReplace( buffer0, value0, 50 );
		offset = 50;
		HS8 value2 = 0;
		HTraitBufferOutGet( value2, offset, buffer0 );

		success &= ( value0 == value2 );
	}

	{
		HBuffer buffer0;
		const HS16 value0 = -537;
		HTraitBufferInAppend( buffer0, value0 );
		HS16 value1 = 0;
		HSINT offset = 0;
		HTraitBufferOutGet( value1, offset, buffer0 );

		success &= ( value0 == value1 );

		buffer0.SizeSet( 100 );

		HTraitBufferInReplace( buffer0, value0, 50 );
		offset = 50;
		HS16 value2 = 0;
		HTraitBufferOutGet( value2, offset, buffer0 );

		success &= ( value0 == value2 );
	}
	{
		HBuffer buffer0;
		const HS32 value0 = -65539;
		HTraitBufferInAppend( buffer0, value0 );
		HS32 value1 = 0;
		HSINT offset = 0;
		HTraitBufferOutGet( value1, offset, buffer0 );

		success &= ( value0 == value1 );

		buffer0.SizeSet( 100 );

		HTraitBufferInReplace( buffer0, value0, 50 );
		offset = 50;
		HS32 value2 = 0;
		HTraitBufferOutGet( value2, offset, buffer0 );

		success &= ( value0 == value2 );
	}
	{
		HBuffer buffer0;
		const HREAL value0 = 11.39F;
		HTraitBufferInAppend( buffer0, value0 );
		HREAL value1 = 0;
		HSINT offset = 0;
		HTraitBufferOutGet( value1, offset, buffer0 );

		success &= ( value0 == value1 );

		buffer0.SizeSet( 100 );

		HTraitBufferInReplace( buffer0, value0, 50 );
		offset = 50;
		HREAL value2 = 0;
		HTraitBufferOutGet( value2, offset, buffer0 );

		success &= ( value0 == value2 );
	}

	{
		HBuffer buffer0;
		const HString value0 = "fubar hello world";
		HTraitBufferInAppend( buffer0, value0 );
		HString value1 = 0;
		HSINT offset = 0;
		HTraitBufferOutGet( value1, offset, buffer0 );

		success &= ( value0 == value1 );

		buffer0.SizeSet( 100 );

		HTraitBufferInReplace( buffer0, value0, 50 );
		offset = 50;
		HString value2 = 0;
		HTraitBufferOutGet( value2, offset, buffer0 );

		success &= ( value0 == value2 );
	}

	HTESTBED_VALIDATE_STATUS( "HTraitBufferOut", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTraitEmpty()
{
	HBOOL success = HTRUE;

	success &= ( HTraitEmpty< HU8 >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HS8 >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HU16 >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HS16 >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HU32 >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HS32 >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HR32 >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HR64 >::EmptyGet() == 0 );

	success &= ( HTraitEmpty< HCHAR >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HSINT >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HREAL >::EmptyGet() == 0 );
	success &= ( HTraitEmpty< HBOOL >::EmptyGet() == HFALSE );
	success &= ( HTraitEmpty< HString >::EmptyGet() == HString() );

	success &= ( HTraitEmpty< HVectorR2 >::EmptyGet() == HVectorR2() );
	success &= ( HTraitEmpty< HVectorR3 >::EmptyGet() == HVectorR3() );
	success &= ( HTraitEmpty< HVectorR4 >::EmptyGet() == HVectorR4() );

	success &= ( HTraitEmpty< HMatrixR2 >::EmptyGet() == HMatrixR2() );
	success &= ( HTraitEmpty< HMatrixR3 >::EmptyGet() == HMatrixR3() );
	success &= ( HTraitEmpty< HMatrixR4 >::EmptyGet() == HMatrixR4() );

	success &= ( HTraitEmpty< HFileSystemPath >::EmptyGet() == HFileSystemPath() );

	HTESTBED_VALIDATE_STATUS( "HTraitEmpty", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTraitName()
{
	HBOOL success = HTRUE;

	success &= ( HString( "HU8" ) == HTraitName< HU8 >::NameGet() );
	success &= ( HString( "HS8" ) == HTraitName< HS8 >::NameGet() );
	success &= ( HString( "HU16" ) == HTraitName< HU16 >::NameGet() );
	success &= ( HString( "HS16" ) == HTraitName< HS16 >::NameGet() );
	success &= ( HString( "HU32" ) == HTraitName< HU32 >::NameGet() );
	success &= ( HString( "HS32" ) == HTraitName< HS32 >::NameGet() );
	success &= ( HString( "HR32" ) == HTraitName< HR32 >::NameGet() );
	success &= ( HString( "HR64" ) == HTraitName< HR64 >::NameGet() );

	success &= ( HString( "HCHAR" ) == HTraitName< HCHAR >::NameGet() );
	success &= ( HString( "HBOOL" ) == HTraitName< HBOOL >::NameGet() );

	success &= ( HString( "HString" ) == HTraitName< HString >::NameGet() );

	success &= ( HString( "HVectorR2" ) == HTraitName< HVectorR2 >::NameGet() );
	success &= ( HString( "HVectorR3" ) == HTraitName< HVectorR3 >::NameGet() );
	success &= ( HString( "HVectorR4" ) == HTraitName< HVectorR4 >::NameGet() );

	success &= ( HString( "HMatrixR2" ) == HTraitName< HMatrixR2 >::NameGet() );
	success &= ( HString( "HMatrixR3" ) == HTraitName< HMatrixR3 >::NameGet() );
	success &= ( HString( "HMatrixR4" ) == HTraitName< HMatrixR4 >::NameGet() );

	HTESTBED_VALIDATE_STATUS( "HTraitName", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTraitStringIn()
{
	HBOOL success = HTRUE;

	HTESTBED_VALIDATE_STATUS( "HTraitStringIn", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTraitStringOut()
{
	HBOOL success = HTRUE;

	{
		const HU8 value0 = 199;
		const HString string0 = HTraitStringIn( value0 );
		HU8 value1 = 0; 
		HTraitStringOut< HU8 >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HS8 value0 = -119;
		const HString string0 = HTraitStringIn( value0 );
		HS8 value1 = 0;
		HTraitStringOut< HS8 >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HU16 value0 = 1026;
		const HString string0 = HTraitStringIn( value0 );
		HU16 value1 = 0;
		HTraitStringOut< HU16 >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HS16 value0 = -517;
		const HString string0 = HTraitStringIn( value0 );
		HS16 value1 = 0;
		HTraitStringOut< HS16 >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HREAL value0 = 11.7F;
		const HString string0 = HTraitStringIn( value0 );
		HREAL value1 = 0;
		HTraitStringOut< HREAL >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HBOOL value0 = HTRUE;
		const HString string0 = HTraitStringIn( value0 );
		HBOOL value1 = 0;
		HTraitStringOut< HBOOL >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HBOOL value0 = HFALSE;
		const HString string0 = HTraitStringIn( value0 );
		HBOOL value1 = 0;
		HTraitStringOut< HBOOL >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HSINT data[] = { 154632, -14935, 112654 };
		const HVectorS3 value0( data );
		const HString string0 = HTraitStringIn( value0 );
		HVectorS3 value1;
		HTraitStringOut< HVectorS3 >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HVectorR3 value0 = HMatrixConstructor::HVectorR3AxisY();
		const HString string0 = HTraitStringIn( value0 );
		HVectorR3 value1;
		HTraitStringOut< HVectorR3 >( value1, string0 );

		success &= ( value0 == value1 );
	}

	{
		const HMatrixR4 value0 = HMatrixUtility::IdentityGet< HMatrixR4 >();
		const HString string0 = HTraitStringIn( value0 );
		HMatrixR4 value1;
		HTraitStringOut< HMatrixR4 >( value1, string0 );

		success &= ( value0 == value1 );
	}

	HTESTBED_VALIDATE_STATUS( "HTraitStringOut", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTraitSwap()
{
	HBOOL success = HTRUE;

	HTESTBED_VALIDATE_STATUS( "HTraitSwap", success );

	return success;
}

//static void LocalTestbedTraitBuffer()
//{
//	HBOOL success = HTRUE;
//
//
//
//	HTESTBED_VALIDATE_STATUS( "TraitBuffer", success );
//
//	return;
//}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedTrait()
{
	HTESTBED_VALIDATE_START( "TestbedTrait" );
	HBOOL success = HTRUE;

	success &= LocalTestbedTraitBufferIn();
	success &= LocalTestbedTraitBufferOut();
	success &= LocalTestbedTraitEmpty();
	success &= LocalTestbedTraitName();
	success &= LocalTestbedTraitStringIn();
	success &= LocalTestbedTraitStringOut();
	success &= LocalTestbedTraitSwap();

	return success;
}

/**/