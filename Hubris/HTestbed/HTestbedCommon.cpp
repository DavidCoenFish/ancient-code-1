//file: Hubris/HTestbed/HTestbedCommon.cpp

#include "Hubris/HTestbed/HTestbedCommon.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonBitCount.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonForEach.h"
#include "Hubris/HCommon/HCommonLowestBit.h"
#include "Hubris/HCommon/HCommonMemory.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HContainer/HContainerUtility.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
typedef HContainerArray< HSINT >TArraySint;

//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedCommonAssert()
{
	HBOOL success = HTRUE;

	HBOOL lTrue = HTRUE;
	HBOOL lFalse = HFALSE;

	HCOMMON_ASSERT( lTrue == !lFalse, "check condition" );
	HCOMMON_ASSERT( lTrue == lTrue, "check condition" );
	HCOMMON_ASSERT( lFalse == lFalse, "check condition" );

	//HCOMMON_ASSERT( lTrue == lFalse, "check assert" );
	//HCOMMON_ASSERT_CASE( 0 );
	//HCOMMON_ASSERT_ALWAYS( "check assert always" );

	HTESTBED_VALIDATE_STATUS( "HCommonAssert", success );

	return success;
}

/**/
static const HBOOL LocalTestbedCommonBitCount()
{
	HBOOL success = HTRUE;

	success &= ( 0 == HCOMMON_BIT_COUNT( 0 ) );
	success &= ( 1 == HCOMMON_BIT_COUNT( 1 ) );
	success &= ( 1 == HCOMMON_BIT_COUNT( 2 ) );
	success &= ( 2 == HCOMMON_BIT_COUNT( 3 ) );
	success &= ( 1 == HCOMMON_BIT_COUNT( 4 ) );
	success &= ( 2 == HCOMMON_BIT_COUNT( 5 ) );
	success &= ( 2 == HCOMMON_BIT_COUNT( 6 ) );
	success &= ( 3 == HCOMMON_BIT_COUNT( 7 ) );
	success &= ( 1 == HCOMMON_BIT_COUNT( 8 ) );
	success &= ( 32 == HCOMMON_BIT_COUNT( -1 ) );

	HTESTBED_VALIDATE_STATUS( "HCommonBitCount", success );

	return success;
}

/**/
static const HBOOL LocalTestbedCommonDefine()
{
	HBOOL success = HTRUE;

	{
		HU8 data[ 10 ] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
		success &= ( 10 == HCOMMON_ARRAY_SIZE( data ) );
	}
	for( HS32 index = 0; index < 32; ++index )
	{
		const HS32 flag = 1 << index;
		success = success && ( flag == HCOMMON_INDEX_TO_FLAG( index ) );
	}
	{
		success &= ( HString( "HBOOL" ) == HCOMMON_TOKEN( HBOOL ) );
		success &= ( HString( "HBOOLHSINT" ) == HCOMMON_TOKEN_TOKEN( HBOOL, HSINT ) );
		success &= ( HString( "HBOOLHSINTHREAL" ) == HCOMMON_TOKEN_TOKEN_TOKEN( HBOOL, HSINT, HREAL ) );
	}
	{
		HSINT value0 = 0;
		HSINT value1 = 0;
		HSINT value2 = 3;
		success &= ( HTRUE == ( value0 == value1 ) );
		success &= ( HTRUE == ( value0 != value2 ) );
		success &= ( HFALSE == ( value0 != value1 ) );
		success &= ( HFALSE == ( value0 == value2 ) );
	}

	HTESTBED_VALIDATE_STATUS( "HCommonDefine", success );

	return success;
}

/**/
static const HBOOL LocalTestbedCommonForEach()
{
	HBOOL success = HTRUE;

	{
		TArraySint arraySint0;
		HContainerUtility::PushBack( arraySint0, 0 );
		HContainerUtility::PushBack( arraySint0, 1 );
		HContainerUtility::PushBack( arraySint0, 2 );
		HContainerUtility::PushBack( arraySint0, 3 );
		HContainerUtility::PushBack( arraySint0, 4 );
		HContainerUtility::PushBack( arraySint0, 5 );
		HSINT trace = 0;
		HCOMMON_FOR_EACH( value, arraySint0, TArraySint )
		{
			success &= ( value == trace );
			trace += 1;
		}
	}

	HTESTBED_VALIDATE_STATUS( "HCommonForEach", success );

	return success;
}

/**/
static const HBOOL LocalTestbedCommonLowestBit()
{
	HBOOL success = HTRUE;

	success = success && ( HCOMMON_INVALID_INDEX == HCOMMON_LOWEST_BIT32( 0 ) );

	for( HS32 index = 0; index < 32; ++index )
	{
		const HS32 flag = 1 << index;
		success = success && ( index == HCOMMON_LOWEST_BIT32( flag ) );
	}

	HTESTBED_VALIDATE_STATUS( "HCommonLowestBit", success );

	return success;
}

/**/
static const HBOOL LocalTestbedCommonMemory()
{
	HBOOL success = HTRUE;

	{
		HU8* someMemory = HCOMMON_MALLOC( HU8, 10 );
		success = success && ( NULL != someMemory );

		someMemory = HCOMMON_REALLOC( someMemory, HU8, 100 );
		success = success && ( NULL != someMemory );

		HCOMMON_FREE( someMemory );
		success = success && ( NULL == someMemory );
	}

	{
		HCHAR data[] = { 'a', 'b', 'c' };
		HCHAR data_dest[3];

		Hubris::HCommonMemory::MemoryCopy( data_dest, data, 3 );
		
		success = success && ( 0 == Hubris::HCommonMemory::MemoryCompair( data_dest, data, 3 ) );
	}


	HTESTBED_VALIDATE_STATUS( "HCommonMemory", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedCommon()
{
	HTESTBED_VALIDATE_START( "TestbedCommon" );
	HBOOL success = HTRUE;

	success &= LocalTestbedCommonAssert();
	success &= LocalTestbedCommonBitCount();
	success &= LocalTestbedCommonBitCount();
	success &= LocalTestbedCommonDefine();
	success &= LocalTestbedCommonForEach();
	success &= LocalTestbedCommonLowestBit();
	success &= LocalTestbedCommonMemory();

	return success;
}

/**/