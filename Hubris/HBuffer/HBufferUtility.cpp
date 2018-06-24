//file: Hubris/HBuffer/HBufferUtility.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBuffer/HBufferUtility.h"

#include "Hubris/HBuffer/HBuffer.h"

#include "Hubris/HCommon/HCommon_Export.h"
#include "Hubris/HString/HString_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/////////////////////////////////////////////////////////////////
// static public methods
/**/
HVOID Hubris::HBufferUtility::StringFromBuffer( HString& out_string, const HBuffer& in_buffer )
{
	const HSINT size = in_buffer.SizeGet() / sizeof( HCHAR );
	out_string.SizeSet( size );
	out_string.DataSet( ( const HCHAR* const )in_buffer.RawGet(), size, 0 );

	return;
}

/**/
HVOID Hubris::HBufferUtility::BufferFromString( HBuffer& out_buffer, const HString& in_string )
{
	const HSINT size = in_string.SizeGet() * sizeof( HCHAR );
	out_buffer.SizeSet( size );
	out_buffer.DataSet( in_string.RawGet(), size, 0 );

	return;
}

/**/
HVOID Hubris::HBufferUtility::DataAppend( HBuffer& in_buffer, const HVOID* const in_data, const HSINT in_size )
{
	if( 0 == in_size )
	{
		return;
	}

	const HSINT old_size = in_buffer.SizeGet();

	in_buffer.SizeResize( old_size + in_size );
	HBufferUtility::DataSet( in_buffer, in_data, old_size, in_size );

	return;
}

/**/
HVOID Hubris::HBufferUtility::DataSet( HBuffer& in_buffer, const HVOID* const in_data, const HSINT in_offset, const HSINT in_size )
{
	in_buffer.DataSet( in_data, in_size, in_offset );

	return;
}

/**/
HVOID Hubris::HBufferUtility::DataGet( const HBuffer& in_buffer, HVOID* const out_data, const HSINT in_offset, const HSINT in_size )
{
	in_buffer.DataGet( out_data, in_size, in_offset );

	return;
}

/**/
HVOID Hubris::HBufferUtility::DataPad( HBuffer& in_out_buffer, const HSINT in_byteBoundary, const HU8 in_padValue )
{
	HCOMMON_ASSERT( 0 != in_byteBoundary, "invalid param" );

	const HSINT size = in_out_buffer.SizeGet();
	const HSINT overhang = size % in_byteBoundary;

	if( 0 == overhang )
	{
		return;
	}

	for( HSINT index = overhang; index < in_byteBoundary; ++index )
	{
		HBufferUtility::DataAppend( in_out_buffer, &in_padValue, sizeof( HU8 ) );
	}

	return;
}

/**/
HVOID Hubris::HBufferUtility::TextAppend( 
	HBuffer& in_out_buffer, 
	const HString& in_text
	)
{
	HBufferUtility::DataAppend( in_out_buffer, in_text.RawGet(), in_text.SizeGet() );
	return;
}

/**/
