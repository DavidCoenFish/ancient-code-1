//file: Hubris/HBufferParse/HBufferParseSaveBin.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseSaveBin.h"

#include "Hubris/HBufferParse/HBufferParseBinType.h"
#include "Hubris/HBufferParse/HBufferParseVariant.h"
#include "Hubris/HBufferParse/HBufferParseUtilityPrivate.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HCommon/HCommon_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HMatrix/HMatrix_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HTrait/HTrait_Export.h"
#include "Hubris/HType/HType_Export.h"


///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HU8 >TArrayU8;
typedef HContainerArray< HS8 >TArrayS8;
typedef HContainerArray< HU16 >TArrayU16;
typedef HContainerArray< HS16 >TArrayS16;
typedef HContainerArray< HU32 >TArrayU32;
typedef HContainerArray< HS32 >TArrayS32;
typedef HContainerArray< HR32 >TArrayR32;
typedef HContainerArray< HR64 >TArrayR64;
typedef HContainerArray< HBOOL >TArrayHBOOL;
typedef HContainerArray< HCHAR >TArrayHCHAR;
typedef HContainerArray< HString >TArrayHString;

typedef HContainerArray< HVectorS2 >TArrayHVectorS2;
typedef HContainerArray< HVectorS3 >TArrayHVectorS3;
typedef HContainerArray< HVectorS4 >TArrayHVectorS4;
typedef HContainerArray< HMatrixS2 >TArrayHMatrixS2;
typedef HContainerArray< HMatrixS3 >TArrayHMatrixS3;
typedef HContainerArray< HMatrixS4 >TArrayHMatrixS4;

typedef HContainerArray< HVectorR2 >TArrayHVectorR2;
typedef HContainerArray< HVectorR3 >TArrayHVectorR3;
typedef HContainerArray< HVectorR4 >TArrayHVectorR4;
typedef HContainerArray< HMatrixR2 >TArrayHMatrixR2;
typedef HContainerArray< HMatrixR3 >TArrayHMatrixR3;
typedef HContainerArray< HMatrixR4 >TArrayHMatrixR4;

///////////////////////////////////////////////////////////
// local free functions
/**/
static HVOID LocalBufferSizeAdd( HBuffer& in_buffer, const HSINT in_count, const HBufferParseBinType::TControlValues::TEnum in_sizeU8, const HBufferParseBinType::TControlValues::TEnum in_sizeU16, const HBufferParseBinType::TControlValues::TEnum in_sizeU32 )
{
	if( in_count <= 255 )
	{
		HTraitBufferInAppend( in_buffer, HU8( in_sizeU8 ) );
		HU8 value( HU8( in_count & 0xFF ) );
		HTraitBufferInAppend( in_buffer, value );
	}
	else if( in_count <= 65535 )
	{
		HTraitBufferInAppend( in_buffer, HU8( in_sizeU16 ) );
		HU16 value( HU16( in_count & 0xFFFF ) );
		HTraitBufferInAppend( in_buffer, value );
	}
	else
	{
		HTraitBufferInAppend( in_buffer, HU8( in_sizeU32 ) );
		HU32 value( in_count );
		HTraitBufferInAppend( in_buffer, value );
	}

	return;
}

/**/
static HVOID LocalPutToken(
	HBuffer& in_out_buffer,
	const HString& in_name
	)
{
	if( HNULL == in_name )
	{
		HTraitBufferInAppend( in_out_buffer, HU8( HBufferParseBinType::TControlValues::TTokenNone ) );
		return;
	}
	const HSINT size = in_name.SizeGet();
	LocalBufferSizeAdd( in_out_buffer, size, HBufferParseBinType::TControlValues::TTokenSizeU8, HBufferParseBinType::TControlValues::TTokenSizeU16, HBufferParseBinType::TControlValues::TTokenSizeU32 );

	if( 0 != size )
	{
		HBufferUtility::DataAppend( in_out_buffer, in_name.RawGet(), size * sizeof( HCHAR ) );
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID VariantValuePut( HBuffer& in_out_buffer, const HContainerArray< IN_TYPE >& in_value )
{
	typedef HContainerArray< IN_TYPE >TArray;
	const HSINT size = in_value.SizeGet();
	LocalBufferSizeAdd( in_out_buffer, size, HBufferParseBinType::TypeGetSmall< TArray >(), HBufferParseBinType::TypeGetMedium< TArray >(), HBufferParseBinType::TypeGetLarge< TArray >() );

	HCOMMON_FOR_EACH_CONST( data, in_value, TArray )	
	{
		HTraitBufferInAppend( in_out_buffer, data );
	}
	return;
}

/**/
template<>
HVOID VariantValuePut( HBuffer& in_out_buffer, const TArrayHString& in_value )
{
	HSINT maxStringLength = 0;
	HCOMMON_FOR_EACH_CONST( data, in_value, TArrayHString )	
	{
		const HSINT stringLength = data.SizeGet();
		if( maxStringLength < stringLength )
		{
			maxStringLength = stringLength;
		}
	}

	if( maxStringLength < 255 )
	{
		LocalBufferSizeAdd( in_out_buffer, in_value.SizeGet(), HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU8, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU8, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU8 );
	}
	else if( maxStringLength < 65535 )
	{
		LocalBufferSizeAdd( in_out_buffer, in_value.SizeGet(), HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU16, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU16, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU16 );
	}
	else
	{
		LocalBufferSizeAdd( in_out_buffer, in_value.SizeGet(), HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU32, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU32, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU32 );
	}

	HCOMMON_FOR_EACH_CONST( string, in_value, TArrayHString )	
	{
		const HSINT stringLength = string.SizeGet();

		if( maxStringLength <= 255 )
		{
			HTraitBufferInAppend( in_out_buffer, HU8( stringLength & 0xFF ) );
		}
		else if( maxStringLength <= 65535 )
		{
			HTraitBufferInAppend( in_out_buffer, HU16( stringLength & 0xFFFF ) );
		}
		else
		{
			HTraitBufferInAppend( in_out_buffer, HU32( stringLength ) );
		}

		if( 0 != stringLength )
		{
			HBufferUtility::DataAppend( in_out_buffer, string.RawGet(), stringLength * sizeof( HCHAR ) );
		}
	}

	return;
}

/**/
template< typename IN_TYPE >
HVOID VariantValuePut( HBuffer& in_out_buffer, const IN_TYPE& in_value )
{
	HTraitBufferInAppend( in_out_buffer, HU8( HBufferParseBinType::TypeGet< IN_TYPE >() ) );
	HTraitBufferInAppend( in_out_buffer, in_value );
	return;
}

/**/
template<>
HVOID VariantValuePut( HBuffer& in_out_buffer, const HBOOL& in_value )
{
	if( HTRUE == in_value )
	{
		HTraitBufferInAppend( in_out_buffer, HU8( HBufferParseBinType::TControlValues::TValueHBOOLTrue ) );
	}
	else
	{
		HTraitBufferInAppend( in_out_buffer, HU8( HBufferParseBinType::TControlValues::TValueHBOOLFalse ) );
	}
	return;
}

/**/
template<>
HVOID VariantValuePut( HBuffer& in_out_buffer, const HString& in_value )
{
	const HSINT size = in_value.SizeGet();
	LocalBufferSizeAdd( in_out_buffer, size, HBufferParseBinType::TControlValues::TValueHStringSizeU8, HBufferParseBinType::TControlValues::TValueHStringSizeU16, HBufferParseBinType::TControlValues::TValueHStringSizeU32 );

	if( 0 != size )
	{
		HBufferUtility::DataAppend( in_out_buffer, in_value.RawGet(), size * sizeof( HCHAR ) );
	}
	return;
}

/**/
template<>
HVOID VariantValuePut( HBuffer&, const HTypeNone& )
{
	HCOMMON_ASSERT_ALWAYS( "invalid code path" );
	return;
}

/**/
template< HSINT IN_INDEX >
HVOID VariantValuePutIndex( HBuffer& in_out_buffer, const HBufferParseVariant& in_value )
{
	typedef HTypeListUtilIndexType< HBufferParseVariant::TTypeList, IN_INDEX >::Type TType;
	VariantValuePut( in_out_buffer, in_value.ValueGet< TType >() );

	return;
}

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HBufferParseSaveBin::HBufferParseSaveBin( const HBufferParseSaveBin& in_src )
: m_buffer()
{
	( *this ) = in_src;
	return;
}

/**/
Hubris::HBufferParseSaveBin::HBufferParseSaveBin()
: m_buffer()
{
	HBufferParseUtilityPrivate::IsBinSet( m_buffer );
	return;
}

/**/
Hubris::HBufferParseSaveBin::~HBufferParseSaveBin()
{
	return;
}

///////////////////////////////////////////////////////////
// operators
/**/
const HBufferParseSaveBin& Hubris::HBufferParseSaveBin::operator=( const HBufferParseSaveBin& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_buffer = in_rhs.m_buffer;
	}

	return( *this );
}

/**/
HBOOL Hubris::HBufferParseSaveBin::operator==( const HBufferParseSaveBin& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_buffer == in_rhs.m_buffer );
	}

	return match;
}

/**/
HBOOL Hubris::HBufferParseSaveBin::operator!=( const HBufferParseSaveBin& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

//////////////////////////////////////////
// HBufferParseSave methods
/**/
HVOID Hubris::HBufferParseSaveBin::BlockStart( 
	const HString& in_name //name must not have spaces, can be HNULL
	)
{
	HTraitBufferInAppend( m_buffer, HU8( HBufferParseBinType::TControlValues::TBlockStart ) );
	LocalPutToken( m_buffer, in_name );

	return;
}

/**/
HVOID Hubris::HBufferParseSaveBin::BlockEnd()
{
	HTraitBufferInAppend( m_buffer, HU8( HBufferParseBinType::TControlValues::TBlockEnd ) );
	return;
}

/**/
HVOID Hubris::HBufferParseSaveBin::ValuePut( 
	const HString& in_name,
	const HBufferParseVariant& in_value 
	)
{
	LocalPutToken( m_buffer, in_name );

	const HSINT type = in_value.TypeIndexGet();
	switch( type )
	{
	default:
		{
			HCOMMON_ASSERT_CASE( type );
			break;
		}
	case  0: { VariantValuePutIndex<  0 >( m_buffer, in_value ); break; }
	case  1: { VariantValuePutIndex<  1 >( m_buffer, in_value ); break; }
	case  2: { VariantValuePutIndex<  2 >( m_buffer, in_value ); break; }
	case  3: { VariantValuePutIndex<  3 >( m_buffer, in_value ); break; }
	case  4: { VariantValuePutIndex<  4 >( m_buffer, in_value ); break; }
	case  5: { VariantValuePutIndex<  5 >( m_buffer, in_value ); break; }
	case  6: { VariantValuePutIndex<  6 >( m_buffer, in_value ); break; }
	case  7: { VariantValuePutIndex<  7 >( m_buffer, in_value ); break; }
	case  8: { VariantValuePutIndex<  8 >( m_buffer, in_value ); break; }
	case  9: { VariantValuePutIndex<  9 >( m_buffer, in_value ); break; }
	case 10: { VariantValuePutIndex< 10 >( m_buffer, in_value ); break; }
	case 11: { VariantValuePutIndex< 11 >( m_buffer, in_value ); break; }
	case 12: { VariantValuePutIndex< 12 >( m_buffer, in_value ); break; }
	case 13: { VariantValuePutIndex< 13 >( m_buffer, in_value ); break; }
	case 14: { VariantValuePutIndex< 14 >( m_buffer, in_value ); break; }
	case 15: { VariantValuePutIndex< 15 >( m_buffer, in_value ); break; }
	case 16: { VariantValuePutIndex< 16 >( m_buffer, in_value ); break; }
	case 17: { VariantValuePutIndex< 17 >( m_buffer, in_value ); break; }
	case 18: { VariantValuePutIndex< 18 >( m_buffer, in_value ); break; }
	case 19: { VariantValuePutIndex< 19 >( m_buffer, in_value ); break; }
	case 20: { VariantValuePutIndex< 20 >( m_buffer, in_value ); break; }
	case 21: { VariantValuePutIndex< 21 >( m_buffer, in_value ); break; }
	case 22: { VariantValuePutIndex< 22 >( m_buffer, in_value ); break; }
	case 23: { VariantValuePutIndex< 23 >( m_buffer, in_value ); break; }
	case 24: { VariantValuePutIndex< 24 >( m_buffer, in_value ); break; }
	case 25: { VariantValuePutIndex< 25 >( m_buffer, in_value ); break; }
	case 26: { VariantValuePutIndex< 26 >( m_buffer, in_value ); break; }
	case 27: { VariantValuePutIndex< 27 >( m_buffer, in_value ); break; }
	case 28: { VariantValuePutIndex< 28 >( m_buffer, in_value ); break; }
	case 29: { VariantValuePutIndex< 29 >( m_buffer, in_value ); break; }
	case 30: { VariantValuePutIndex< 30 >( m_buffer, in_value ); break; }
	case 31: { VariantValuePutIndex< 31 >( m_buffer, in_value ); break; }
	case 32: { VariantValuePutIndex< 32 >( m_buffer, in_value ); break; }
	case 33: { VariantValuePutIndex< 33 >( m_buffer, in_value ); break; }
	case 34: { VariantValuePutIndex< 34 >( m_buffer, in_value ); break; }
	case 35: { VariantValuePutIndex< 35 >( m_buffer, in_value ); break; }
	case 36: { VariantValuePutIndex< 36 >( m_buffer, in_value ); break; }
	case 37: { VariantValuePutIndex< 37 >( m_buffer, in_value ); break; }
	case 38: { VariantValuePutIndex< 38 >( m_buffer, in_value ); break; }
	case 39: { VariantValuePutIndex< 39 >( m_buffer, in_value ); break; }
	case 40: { VariantValuePutIndex< 40 >( m_buffer, in_value ); break; }
	case 41: { VariantValuePutIndex< 41 >( m_buffer, in_value ); break; }
	case 42: { VariantValuePutIndex< 42 >( m_buffer, in_value ); break; }
	case 43: { VariantValuePutIndex< 43 >( m_buffer, in_value ); break; }
	case 44: { VariantValuePutIndex< 44 >( m_buffer, in_value ); break; }
	case 45: { VariantValuePutIndex< 45 >( m_buffer, in_value ); break; }
	case 46: { VariantValuePutIndex< 46 >( m_buffer, in_value ); break; }
	case 47: { VariantValuePutIndex< 47 >( m_buffer, in_value ); break; }
	case 48: { VariantValuePutIndex< 48 >( m_buffer, in_value ); break; }
	case 49: { VariantValuePutIndex< 49 >( m_buffer, in_value ); break; }
	case 50: { VariantValuePutIndex< 50 >( m_buffer, in_value ); break; }
	case 51: { VariantValuePutIndex< 51 >( m_buffer, in_value ); break; }
	case 52: { VariantValuePutIndex< 52 >( m_buffer, in_value ); break; }
	case 53: { VariantValuePutIndex< 53 >( m_buffer, in_value ); break; }
	case 54: { VariantValuePutIndex< 54 >( m_buffer, in_value ); break; }
	case 55: { VariantValuePutIndex< 55 >( m_buffer, in_value ); break; }
	case 56: { VariantValuePutIndex< 56 >( m_buffer, in_value ); break; }
	case 57: { VariantValuePutIndex< 57 >( m_buffer, in_value ); break; }
	case 58: { VariantValuePutIndex< 58 >( m_buffer, in_value ); break; }
	case 59: { VariantValuePutIndex< 59 >( m_buffer, in_value ); break; }
	}

	return;
}

/**/
HVOID Hubris::HBufferParseSaveBin::CommentPut( 
	const HString& HCOMMON_UNUSED_VAR( in_comment )
	)
{
	return;
}

///**/
//HVOID Hubris::HBufferParseSaveBin::BlockStart()
//{
//	HTraitBufferInAppend( m_buffer, HU8( HBufferParseBinType::TControlValues::TBlockStart ) );
//	//HContainerUtility::PushBack( m_bufferStack, HBuffer() );
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSaveBin::BlockEnd()
//{
//	HTraitBufferInAppend( m_buffer, HU8( HBufferParseBinType::TControlValues::TBlockEnd ) );
//
//	//HCOMMON_ASSERT( 0 != m_bufferStack.SizeGet(), "end without start" );
//	
//	//HBuffer& activeBuffer = m_buffer;
//	//HBuffer& parentBuffer = parentBufferGet();
//	//const HSINT size = activeBuffer.SizeGet();
//
//	//LocalBufferSizeAdd( parentBuffer, size, HBufferParseBinType::TControlValues::TBlockStartSizeU8, HBufferParseBinType::TControlValues::TBlockStartSizeU16, HBufferParseBinType::TControlValues::TBlockStartSizeU32 );
//	//HBufferUtility::DataAppend( parentBuffer, activeBuffer.RawGet(), size );
//
//	//HContainerUtility::PopBack( ( m_bufferStack ) );
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSaveBin::TokenPut( const HString& in_token )
//{
//	const HSINT size = in_token.SizeGet();
//	LocalBufferSizeAdd( m_buffer, size, HBufferParseBinType::TControlValues::TTokenSizeU8, HBufferParseBinType::TControlValues::TTokenSizeU16, HBufferParseBinType::TControlValues::TTokenSizeU32 );
//
//	if( 0 != size )
//	{
//		HBufferUtility::DataAppend( m_buffer, in_token.RawGet(), size * sizeof( HCHAR ) );
//	}
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSaveBin::ValuePut( const HBufferParseVariant& in_value )
//{	
//	const HSINT type = in_value.TypeIndexGet();
//	switch( type )
//	{
//	default:
//		{
//			HCOMMON_ASSERT_CASE( type );
//			break;
//		}
//	case  0: { VariantValuePutIndex<  0 >( m_buffer, in_value ); break; }
//	case  1: { VariantValuePutIndex<  1 >( m_buffer, in_value ); break; }
//	case  2: { VariantValuePutIndex<  2 >( m_buffer, in_value ); break; }
//	case  3: { VariantValuePutIndex<  3 >( m_buffer, in_value ); break; }
//	case  4: { VariantValuePutIndex<  4 >( m_buffer, in_value ); break; }
//	case  5: { VariantValuePutIndex<  5 >( m_buffer, in_value ); break; }
//	case  6: { VariantValuePutIndex<  6 >( m_buffer, in_value ); break; }
//	case  7: { VariantValuePutIndex<  7 >( m_buffer, in_value ); break; }
//	case  8: { VariantValuePutIndex<  8 >( m_buffer, in_value ); break; }
//	case  9: { VariantValuePutIndex<  9 >( m_buffer, in_value ); break; }
//	case 10: { VariantValuePutIndex< 10 >( m_buffer, in_value ); break; }
//	case 11: { VariantValuePutIndex< 11 >( m_buffer, in_value ); break; }
//	case 12: { VariantValuePutIndex< 12 >( m_buffer, in_value ); break; }
//	case 13: { VariantValuePutIndex< 13 >( m_buffer, in_value ); break; }
//	case 14: { VariantValuePutIndex< 14 >( m_buffer, in_value ); break; }
//	case 15: { VariantValuePutIndex< 15 >( m_buffer, in_value ); break; }
//	case 16: { VariantValuePutIndex< 16 >( m_buffer, in_value ); break; }
//	case 17: { VariantValuePutIndex< 17 >( m_buffer, in_value ); break; }
//	case 18: { VariantValuePutIndex< 18 >( m_buffer, in_value ); break; }
//	case 19: { VariantValuePutIndex< 19 >( m_buffer, in_value ); break; }
//	case 20: { VariantValuePutIndex< 20 >( m_buffer, in_value ); break; }
//	case 21: { VariantValuePutIndex< 21 >( m_buffer, in_value ); break; }
//	case 22: { VariantValuePutIndex< 22 >( m_buffer, in_value ); break; }
//	case 23: { VariantValuePutIndex< 23 >( m_buffer, in_value ); break; }
//	case 24: { VariantValuePutIndex< 24 >( m_buffer, in_value ); break; }
//	case 25: { VariantValuePutIndex< 25 >( m_buffer, in_value ); break; }
//	case 26: { VariantValuePutIndex< 26 >( m_buffer, in_value ); break; }
//	case 27: { VariantValuePutIndex< 27 >( m_buffer, in_value ); break; }
//	case 28: { VariantValuePutIndex< 28 >( m_buffer, in_value ); break; }
//	case 29: { VariantValuePutIndex< 29 >( m_buffer, in_value ); break; }
//	case 30: { VariantValuePutIndex< 30 >( m_buffer, in_value ); break; }
//	case 31: { VariantValuePutIndex< 31 >( m_buffer, in_value ); break; }
//	case 32: { VariantValuePutIndex< 32 >( m_buffer, in_value ); break; }
//	case 33: { VariantValuePutIndex< 33 >( m_buffer, in_value ); break; }
//	case 34: { VariantValuePutIndex< 34 >( m_buffer, in_value ); break; }
//	case 35: { VariantValuePutIndex< 35 >( m_buffer, in_value ); break; }
//	case 36: { VariantValuePutIndex< 36 >( m_buffer, in_value ); break; }
//	case 37: { VariantValuePutIndex< 37 >( m_buffer, in_value ); break; }
//	case 38: { VariantValuePutIndex< 38 >( m_buffer, in_value ); break; }
//	case 39: { VariantValuePutIndex< 39 >( m_buffer, in_value ); break; }
//	case 40: { VariantValuePutIndex< 40 >( m_buffer, in_value ); break; }
//	case 41: { VariantValuePutIndex< 41 >( m_buffer, in_value ); break; }
//	case 42: { VariantValuePutIndex< 42 >( m_buffer, in_value ); break; }
//	case 43: { VariantValuePutIndex< 43 >( m_buffer, in_value ); break; }
//	case 44: { VariantValuePutIndex< 44 >( m_buffer, in_value ); break; }
//	case 45: { VariantValuePutIndex< 45 >( m_buffer, in_value ); break; }
//	case 46: { VariantValuePutIndex< 46 >( m_buffer, in_value ); break; }
//	case 47: { VariantValuePutIndex< 47 >( m_buffer, in_value ); break; }
//	case 48: { VariantValuePutIndex< 48 >( m_buffer, in_value ); break; }
//	case 49: { VariantValuePutIndex< 49 >( m_buffer, in_value ); break; }
//	case 50: { VariantValuePutIndex< 50 >( m_buffer, in_value ); break; }
//	case 51: { VariantValuePutIndex< 51 >( m_buffer, in_value ); break; }
//	case 52: { VariantValuePutIndex< 52 >( m_buffer, in_value ); break; }
//	case 53: { VariantValuePutIndex< 53 >( m_buffer, in_value ); break; }
//	case 54: { VariantValuePutIndex< 54 >( m_buffer, in_value ); break; }
//	case 55: { VariantValuePutIndex< 55 >( m_buffer, in_value ); break; }
//	case 56: { VariantValuePutIndex< 56 >( m_buffer, in_value ); break; }
//	case 57: { VariantValuePutIndex< 57 >( m_buffer, in_value ); break; }
//	case 58: { VariantValuePutIndex< 58 >( m_buffer, in_value ); break; }
//	case 59: { VariantValuePutIndex< 59 >( m_buffer, in_value ); break; }
//	}
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSaveBin::CommentPut( const HString& )
//{
//	//NOP
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSaveBin::EndOfLinePut()
//{
//	//NOP
//	return;
//}

///////////////////////////////////////////////////////////
// private methods
/**
HBuffer& Hubris::HBufferParseSaveBin::m_buffer
{
	if( 0 != m_bufferStack.SizeGet() )
	{
		return HContainerUtility::Back( m_bufferStack );
	}

	return m_buffer;
}

/**
HBuffer& Hubris::HBufferParseSaveBin::parentBufferGet()
{
	if( 1 < m_bufferStack.SizeGet() )
	{
		return m_bufferStack[ m_bufferStack.SizeGet() - 2 ];
	}

	return m_buffer;
}

/**/