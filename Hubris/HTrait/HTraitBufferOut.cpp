//file: Hubris/HTrait/HTraitBufferOut.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HTrait/HTraitBufferOut.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HString/HString_Export.h"

/////////////////////////////////////////////////////////////////
//using
/**/
using namespace Hubris;

/////////////////////////////////////////////////////////////////
//typedef
/**/
typedef HS32 TStringLengthType;  //WARNING, match HTraitBufferIn.cpp
typedef HS32 TArrayLengthType;   //WARNING, match HTraitBufferIn.cpp

/////////////////////////////////////////////////////////////////
// static local methods
/**/
template< typename IN_TYPE >
static HVOID LocalBufferOutGet( HContainerArray< IN_TYPE >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	TArrayLengthType arrayLength = 0;
	HTraitBufferOutGet( arrayLength, in_out_offset, in_buffer );

	out_value.SizeSet( arrayLength );
	for( HSINT index = 0; index < arrayLength; ++index )
	{
		HTraitBufferOutGet< IN_TYPE >( out_value[ index ], in_out_offset, in_buffer );
	}

	return;
}

/////////////////////////////////////////////////////////////////
// HTraitBufferInAppend Declare the function template
/**/
template< typename IN_TYPE >
HVOID Hubris::HTraitBufferOutGet( IN_TYPE& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	in_buffer.DataGet( &out_value, sizeof( IN_TYPE ), in_out_offset );
	in_out_offset += sizeof( IN_TYPE );
	return;
}

//Then forcibly instantiate it with a desired type
template HVOID Hubris::HTraitBufferOutGet( HU8& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HS8& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HU16& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HS16& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HU32& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HS32& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HR32& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HR64& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HCHAR& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HBOOL& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HString& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HU8 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HS8 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HU16 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HS16 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HU32 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HS32 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HR32 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HR64 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HCHAR >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HBOOL >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
template HVOID Hubris::HTraitBufferOutGet( HContainerArray< HString >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

//specialise instantiation
HVOID Hubris::HTraitBufferOutGet< HString >( HString& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	TStringLengthType stringLength = 0;
	HTraitBufferOutGet( stringLength, in_out_offset, in_buffer );

	out_value.SizeSet( stringLength );
	out_value.DataSet( ( ( const HCHAR* )in_buffer.RawGet() ) + in_out_offset , stringLength, 0 );
	in_out_offset += stringLength;

	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HU8 > >( HContainerArray< HU8 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HS8 > >( HContainerArray< HS8 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HU16 > >( HContainerArray< HU16 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HS16 > >( HContainerArray< HS16 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HU32 > >( HContainerArray< HU32 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HS32 > >( HContainerArray< HS32 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HR32 > >( HContainerArray< HR32 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HR64 > >( HContainerArray< HR64 >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HCHAR > >( HContainerArray< HCHAR >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HBOOL > >( HContainerArray< HBOOL >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}
HVOID Hubris::HTraitBufferOutGet< HContainerArray< HString > >( HContainerArray< HString >& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	LocalBufferOutGet( out_value, in_out_offset, in_buffer );
	return;
}

/**/