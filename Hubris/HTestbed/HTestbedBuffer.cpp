//file: Hubris/HTestbed/HTestbedBuffer.cpp

#include "Hubris/HTestbed/HTestbedBuffer.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonMemory.h"
#include "Hubris/HBuffer/HBuffer.h"
#include "Hubris/HBuffer/HBufferOperators.h"
#include "Hubris/HBuffer/HBufferTrait.h"
#include "Hubris/HBuffer/HBufferUtility.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedBuffer()
{
	HBOOL success = HTRUE;

	const HU8 data[] = { 10, 37, 255, 0, 1, 4, 7 };
	const HSINT dataSize = HCOMMON_ARRAY_SIZE( data );

	//HBuffer( const HBuffer& in_src );
	//HBuffer( const HVOID* const in_src, const HSINT in_size );
	//HBuffer();
	//~HBuffer();
	//const HBuffer& operator =( const HBuffer& in_rhs );
	{
		const HBuffer buffer0( data, dataSize );
		const HBuffer buffer1( buffer0 );
		const HBuffer buffer2 = buffer0;
		const HBuffer buffer3;

		success &= ( buffer0 == buffer1 );
		success &= ( buffer1 == buffer0 );

		success &= ( buffer0 == buffer2 );
		success &= ( buffer2 == buffer0 );

		success &= !( buffer0 == buffer3 );
		success &= !( buffer3 == buffer0 );

		success &= !( buffer0 != buffer2 );
		success &= !( buffer2 != buffer0 );

		success &= ( buffer0 != buffer3 );
		success &= ( buffer3 != buffer0 );
	}

	//const HVOID* const RawGet() const { return m_data; }
	//HVOID* RawGet() { return m_data; }
	//HVOID DataSet( const HVOID* const in_src, const HSINT in_size, const HSINT in_offset );
	//HVOID DataGet( HVOID* const in_dest, const HSINT in_size, const HSINT in_offset ) const;
	//HSINT SizeGet() const { return m_size; }
	//HVOID SizeSet( const HSINT in_size );
	//HVOID SizeResize( const HSINT in_size );
	{
		HBuffer buffer0;
		success &= ( 0 == buffer0.SizeGet() );
		buffer0.SizeSet( dataSize );
		success &= ( dataSize == buffer0.SizeGet() );
		buffer0.DataSet( data, dataSize, 0 );

		const HBuffer buffer1( data, dataSize );
		success &= ( buffer0 == buffer1 );
		success &= ( buffer1 == buffer0 );

		success &= ( 0 == HCommonMemory::MemoryCompair( buffer0.RawGet(), buffer1.RawGet(), dataSize ) );
		HU8 data2[ 100 ];
		buffer0.DataGet( data2, dataSize, 0 );
		success &= ( 0 == HCommonMemory::MemoryCompair( data2, data, dataSize ) );

		buffer0.SizeResize( dataSize + dataSize );

		buffer0.DataSet( data, dataSize, dataSize );
		buffer0.DataGet( data2, dataSize, dataSize );
		success &= ( 0 == HCommonMemory::MemoryCompair( data2, data, dataSize ) );

		buffer0.SizeResize( dataSize );

		success &= ( buffer0 == buffer1 );
		success &= ( buffer1 == buffer0 );
	}

	HTESTBED_VALIDATE_STATUS( "HBuffer", success );
	return success;
}

/**/
static const HBOOL LocalTestbedBufferOperators()
{
	HBOOL success = HTRUE;

	const HU8 data0[] = { 10, 37, 255, 0, 1, 4, 7 };
	const HSINT dataSize0 = HCOMMON_ARRAY_SIZE( data0 );
	const HU8 data1[] = { 10, 37, 255, 8, 1, 4, 7 };
	const HSINT dataSize1 = HCOMMON_ARRAY_SIZE( data1 );
	const HU8 data2[] = { 10, 37, 255, 0, 1, 4, 7, 10, 37, 255, 8, 1, 4, 7 };
	const HSINT dataSize2 = HCOMMON_ARRAY_SIZE( data2 );

	//const HBuffer operator +( const HBuffer& in_lhs, const HBuffer& in_rhs );
	//const HBuffer& operator +=( HBuffer& in_lhs, const HBuffer& in_rhs );
	{
		const HBuffer buffer0( data0, dataSize0 );
		const HBuffer buffer1( data1, dataSize1 );
		const HBuffer buffer2( data2, dataSize2 );
		const HBuffer buffer3 = buffer0 + buffer1;
		HBuffer buffer4;
		buffer4 += buffer0;
		buffer4 += buffer1;

		success &= ( buffer3 == buffer2 );
		success &= ( buffer4 == buffer2 );
	}


	//const HBOOL operator <( const HBuffer& in_lhs, const HBuffer& in_rhs );
	{
		const HBuffer buffer0( data0, dataSize0 );
		const HBuffer buffer1( data1, dataSize1 );
		const HBuffer buffer2( data2, dataSize2 );
		const HBuffer buffer3;

		success &= !( buffer3 < buffer3 );
		success &= ( buffer0 < buffer1 );
		success &= !( buffer1 < buffer0 );
		success &= ( buffer0 < buffer2 );
		success &= !( buffer2 < buffer0 );
	}

	HTESTBED_VALIDATE_STATUS( "HBufferOperators", success );
	return success;
}
/**/
static const HBOOL LocalTestbedBufferTrait()
{
	HBOOL success = HTRUE;
	const HU8 data[] = { 10, 37, 255, 0, 1, 4, 7 };
	const HSINT dataSize = HCOMMON_ARRAY_SIZE( data );

	//HTraitEmpty
	{
		const HBuffer buffer0( data, dataSize );

		success &= ( HBuffer() == HTraitEmpty< HBuffer >::EmptyGet() );
		success &= ( buffer0 != HTraitEmpty< HBuffer >::EmptyGet() );
	}

	//HTraitName
	{
		success &= ( HString( "HBuffer" ) == HTraitName< HBuffer >::NameGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HBufferTrait", success );
	return success;
}
/**/
static const HBOOL LocalTestbedBufferUtility()
{
	HBOOL success = HTRUE;

	const HU8 data0[] = { 10, 37, 255, 0, 1, 4, 7 };
	const HSINT dataSize0 = HCOMMON_ARRAY_SIZE( data0 );
	const HU8 data1[] = { 10, 37, 255, 0, 1, 4, 7, 10, 37, 255, 0, 1, 4, 7 };
	const HSINT dataSize1 = HCOMMON_ARRAY_SIZE( data1 );
	const HU8 data2[] = { 0, 0, 0, 0, 0, 0, 0, 10, 37, 255, 0, 1, 4, 7 };
	const HSINT dataSize2 = HCOMMON_ARRAY_SIZE( data2 );

	//HBufferUtility
	//static HVOID StringFromBuffer( HString& out_string, const HBuffer& in_buffer );
	//static HVOID BufferFromString( HBuffer& out_buffer, const HString& in_string );
	{
		const HBuffer buffer0( data0, dataSize0 );
		HString string0;
		HBufferUtility::StringFromBuffer( string0, buffer0 );
		HBuffer buffer1;
		HBufferUtility::BufferFromString( buffer1, string0 );
		HString string1;
		HBufferUtility::StringFromBuffer( string1, buffer1 );

		success &= ( buffer0 == buffer1 );
		success &= ( string0 == string1 );
	}

	//static HVOID DataAppend( HBuffer& in_buffer, const HVOID* const in_data, const HSINT in_size );
	{
		const HBuffer buffer0( data0, dataSize0 );
		const HBuffer buffer1( data1, dataSize1 );
		HBuffer buffer2;
		HBufferUtility::DataAppend( buffer2, data0, dataSize0 );
		success &= ( buffer0 == buffer2 );

		HBufferUtility::DataAppend( buffer2, data0, dataSize0 );
		success &= ( buffer1 == buffer2 );
	}
	//static HVOID DataSet( HBuffer& in_buffer, const HVOID* const in_data, const HSINT in_offset, const HSINT in_size );
	{
		HBuffer buffer0;
		const HBuffer buffer1( data2, dataSize2 );

		buffer0.SizeSet( dataSize1 );
		HBufferUtility::DataSet( buffer0, data2, 0, dataSize0 );
		HBufferUtility::DataSet( buffer0, data0, dataSize0, dataSize0 );

		success &= ( buffer0 == buffer1 );
	}
	//static HVOID DataGet( const HBuffer& in_buffer, HVOID* const out_data, const HSINT in_offset, const HSINT in_size );
	{
		const HBuffer buffer0( data2, dataSize2 );
		HU8 data[ 100 ];

		HBufferUtility::DataGet( buffer0, data, dataSize0, dataSize0 );

		success &= ( 0 == HCommonMemory::MemoryCompair( data, data0, dataSize0 ) );
	}
	//static HVOID DataPad( HBuffer& in_out_buffer, const HSINT in_byteBoundary, const HU8 in_padValue = 0 );
	{
		const HU8 dataPad0[] = { 1, 2, 3, 4 };
		const HSINT dataPadSize0 = HCOMMON_ARRAY_SIZE( dataPad0 );
		const HU8 dataPad1[] = { 1, 2, 3, 4 };
		const HSINT dataPadSize1 = HCOMMON_ARRAY_SIZE( dataPad1 );
		const HU8 dataPad2[] = { 1, 2, 3, 4, 5 };
		const HSINT dataPadSize2 = HCOMMON_ARRAY_SIZE( dataPad2 );
		const HU8 dataPad3[] = { 1, 2, 3, 4, 5, 0, 0, 0 };
		const HSINT dataPadSize3 = HCOMMON_ARRAY_SIZE( dataPad3 );
		const HU8 dataPad4[] = { 1, 2, 3, 4, 5, 6 };
		const HSINT dataPadSize4 = HCOMMON_ARRAY_SIZE( dataPad4 );
		const HU8 dataPad5[] = { 1, 2, 3, 4, 5, 6, 0, 0 };
		const HSINT dataPadSize5 = HCOMMON_ARRAY_SIZE( dataPad5 );
		const HU8 dataPad6[] = { 1, 2, 3, 4, 5, 6, 7 };
		const HSINT dataPadSize6 = HCOMMON_ARRAY_SIZE( dataPad6 );
		const HU8 dataPad7[] = { 1, 2, 3, 4, 5, 6, 7, 0 };
		const HSINT dataPadSize7 = HCOMMON_ARRAY_SIZE( dataPad7 );

		HBuffer buffer0( dataPad0, dataPadSize0 );
		const HBuffer buffer1( dataPad1, dataPadSize1 );
		HBuffer buffer2( dataPad2, dataPadSize2 );
		const HBuffer buffer3( dataPad3, dataPadSize3 );
		HBuffer buffer4( dataPad4, dataPadSize4 );
		const HBuffer buffer5( dataPad5, dataPadSize5 );
		HBuffer buffer6( dataPad6, dataPadSize6 );
		const HBuffer buffer7( dataPad7, dataPadSize7 );

		HBufferUtility::DataPad( buffer0, 4 );
		HBufferUtility::DataPad( buffer2, 4 );
		HBufferUtility::DataPad( buffer4, 4 );
		HBufferUtility::DataPad( buffer6, 4 );
		
		success &= ( buffer0 == buffer1 );
		success &= ( buffer2 == buffer3 );
		success &= ( buffer4 == buffer5 );
		success &= ( buffer6 == buffer7 );
	}

	HTESTBED_VALIDATE_STATUS( "HBufferUtility", success );
	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedBuffer()
{
	HTESTBED_VALIDATE_START( "TestbedBuffer" );
	HBOOL success = HTRUE;

	success &= LocalTestbedBuffer();
	success &= LocalTestbedBufferOperators();
	success &= LocalTestbedBufferTrait();
	success &= LocalTestbedBufferUtility();

	return success;
}

/**/