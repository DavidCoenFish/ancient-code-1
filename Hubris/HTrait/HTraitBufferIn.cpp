//file: Hubris/HTrait/HTraitBufferIn.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HTrait/HTraitBufferIn.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HString/HString_Export.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/////////////////////////////////////////////////////////////////
//typedef
typedef HS32 TStringLengthType;  //WARNING, match HTraitBufferOut.cpp
typedef HS32 TArrayLengthType;   //WARNING, match HTraitBufferOut.cpp

/////////////////////////////////////////////////////////////////
// static local methods
/**/
template< typename IN_TYPE >
static HVOID LocalBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< IN_TYPE >& in_value )
{
	const HSINT offset = in_out_buffer.SizeGet();
	const HSINT newSize = offset + sizeof( TArrayLengthType ) + ( in_value.SizeGet() * sizeof( IN_TYPE ) );
	in_out_buffer.SizeResize( newSize );

	HTraitBufferInReplace( in_out_buffer, in_value, offset );

	return;
}

/**/
template< typename IN_TYPE >
static HSINT LocalBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< IN_TYPE >& in_value, const HSINT in_offset )
{
	const TArrayLengthType length = ( TArrayLengthType )in_value.SizeGet();
	HSINT returnOffset( in_offset );

	returnOffset = HTraitBufferInReplace( in_out_buffer, length, returnOffset );
	formtypeAVI( HSINT index = 0; index < length; ++index )
	{
		returnOffset = HTraitBufferInReplace( in_out_buffer, in_value[ index ], returnOffset );
	}

	return returnOffset;
}


/////////////////////////////////////////////////////////////////
// HTraitBufferInAppend Declare the function template
/**/
template< typename IN_TYPE >
HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const IN_TYPE& in_value )
{
	const HSINT offset = in_out_buffer.SizeGet();
	in_out_buffer.SizeResize( offset + sizeof( IN_TYPE ) );	
	HTraitBufferInReplace( in_out_buffer, in_value, offset );
	return;
}

//Then forcibly instantiate it with a desired type
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HU8& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HS8& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HU16& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HS16& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HU32& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HS32& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HR32& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HR64& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HBOOL& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HCHAR& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HString& in_value );

template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HU8 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HS8 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HU16 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HS16 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HU32 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HS32 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HR32 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HR64 >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HBOOL >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HCHAR >& in_value );
template HVOID Hubris::HTraitBufferInAppend( HBuffer& in_out_buffer, const HContainerArray< HString >& in_value );

//specialise instantiation
HVOID Hubris::HTraitBufferInAppend< HString >( HBuffer& in_out_buffer, const HString& in_value )
{
	const HSINT offset = in_out_buffer.SizeGet();
	const HSINT newSize = offset + sizeof( TStringLengthType ) + ( in_value.SizeGet() * sizeof( HCHAR ) );
	in_out_buffer.SizeResize( newSize );

	HTraitBufferInReplace( in_out_buffer, in_value, offset );

	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HU8 > >( HBuffer& in_out_buffer, const HContainerArray< HU8 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HS8 > >( HBuffer& in_out_buffer, const HContainerArray< HS8 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HU16 > >( HBuffer& in_out_buffer, const HContainerArray< HU16 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HS16 > >( HBuffer& in_out_buffer, const HContainerArray< HS16 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HU32 > >( HBuffer& in_out_buffer, const HContainerArray< HU32 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HS32 > >( HBuffer& in_out_buffer, const HContainerArray< HS32 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HR32 > >( HBuffer& in_out_buffer, const HContainerArray< HR32 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HR64 > >( HBuffer& in_out_buffer, const HContainerArray< HR64 >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HBOOL > >( HBuffer& in_out_buffer, const HContainerArray< HBOOL >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HCHAR > >( HBuffer& in_out_buffer, const HContainerArray< HCHAR >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}
HVOID Hubris::HTraitBufferInAppend< HContainerArray< HString > >( HBuffer& in_out_buffer, const HContainerArray< HString >& in_value )
{
	LocalBufferInAppend( in_out_buffer, in_value );
	return;
}

/////////////////////////////////////////////////////////////////
// HTraitBufferInReplace Declare the function template
/**/
template< typename IN_TYPE >
HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const IN_TYPE& in_value, const HSINT in_offset )
{
	in_out_buffer.DataSet( &in_value, sizeof( IN_TYPE ), in_offset );
	return in_offset + sizeof( IN_TYPE );
}

//Then forcibly instantiate it with a desired type
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HU8& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HS8& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HU16& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HS16& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HU32& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HS32& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HR32& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HR64& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HBOOL& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HCHAR& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HString& in_value, const HSINT in_offset );

template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HU8 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HS8 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HU16 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HS16 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HU32 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HS32 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HR32 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HR64 >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HBOOL >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HCHAR >& in_value, const HSINT in_offset );
template HSINT Hubris::HTraitBufferInReplace( HBuffer& in_out_buffer, const HContainerArray< HString >& in_value, const HSINT in_offset );

//specialise instantiation
HSINT Hubris::HTraitBufferInReplace< HString >( HBuffer& in_out_buffer, const HString& in_value, const HSINT in_offset )
{
	const TStringLengthType length = ( TStringLengthType )in_value.SizeGet();
	HSINT returnOffset( in_offset );

	returnOffset = HTraitBufferInReplace( in_out_buffer, length, returnOffset );
	if( 0 != length )
	{
		const HSINT size = length * sizeof( HCHAR );
		HBufferUtility::DataSet( in_out_buffer, in_value.RawGet(), returnOffset, size );
		returnOffset += size;
	}

	return returnOffset;
}

/**/
