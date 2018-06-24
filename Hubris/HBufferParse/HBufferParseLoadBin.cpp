//file: Hubris/HBufferParse/HBufferParseLoadBin.h

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseLoadBin.h"

#include "Hubris/HBufferParse/HBufferParseBinType.h"
#include "Hubris/HBufferParse/HBufferParseVariant.h"
#include "Hubris/HBufferParse/HBufferParseLoadVisitorInterface.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HCommon/HCommon_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HMatrix/HMatrix_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HTrait/HTrait_Export.h"
#include "Hubris/HVariables/HVariables_Export.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// typedef
typedef HContainerArray< HSINT >TIntArray;

typedef HContainerArray< HU8 >TU8Array;
typedef HContainerArray< HS8 >TS8Array;
typedef HContainerArray< HU16 >TU16Array;
typedef HContainerArray< HS16 >TS16Array;
typedef HContainerArray< HU32 >TU32Array;
typedef HContainerArray< HS32 >TS32Array;
typedef HContainerArray< HR32 >TR32Array;
typedef HContainerArray< HR64 >TR64Array;
typedef HContainerArray< HBOOL >TBoolArray;
typedef HContainerArray< HCHAR >TCharArray;
typedef HContainerArray< HString >TArrayString;

///////////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalSkipTest(
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth 
	)
{
	if( HCOMMON_INVALID_INDEX != in_out_skipToDepth )
	{
		if( in_out_depth <= in_out_skipToDepth )
		{
			in_out_skipToDepth = HCOMMON_INVALID_INDEX;
		}
	}

	if( HCOMMON_INVALID_INDEX != in_out_skipToDepth )
	{
		return HTRUE;
	}

	return HFALSE;
}

/**/
static HSINT LocalStringSizeGet( const HBufferParseBinType::TControlValues::TEnum in_type, const HBuffer& in_buffer, const HSINT in_offset, HU32& out_size, const HBufferParseBinType::TControlValues::TEnum in_sizeU8, const HBufferParseBinType::TControlValues::TEnum in_sizeU16, const HBufferParseBinType::TControlValues::TEnum in_sizeU32 )
{
	HSINT returnOffset( in_offset );

	if( in_sizeU8 == in_type )
	{
		HU8 size = 0;
		HTraitBufferOutGet( size, returnOffset, in_buffer );
		out_size = size;
	}
	else if( in_sizeU16 == in_type )
	{
		HU16 size = 0;
		HTraitBufferOutGet( size, returnOffset, in_buffer );
		out_size = size;
	}
	else if( in_sizeU32 == in_type )
	{
		HU32 size = 0;
		HTraitBufferOutGet( size, returnOffset, in_buffer );
		out_size = size;
	}
	else
	{
		HCOMMON_ASSERT_ALWAYS( "invalid type" );
	}
	
	return returnOffset;
}

/**/
static HSINT LocalLoadString( const HBuffer& in_buffer, const HSINT in_offset, const HU32 in_size, HString& out_value )
{
	HSINT returnOffset( in_offset );

	if( 0 != in_size )
	{
		const HSINT byteSize = in_size * sizeof( HCHAR );
		HBuffer data;
		data.SizeSet( in_size );
		HBufferUtility::DataGet( in_buffer, data.RawGet(), returnOffset, byteSize );
		out_value.SizeSet( in_size );
		out_value.DataSet( ( const HCHAR* const )( data.RawGet() ), byteSize, 0 );

		returnOffset += ( byteSize );
	}
	else
	{
		out_value.Clear();
	}

	return returnOffset;
}

/**/
static const HSINT LocalNameGet(
	HString& out_name,
	const HSINT& in_offset,
	const HBuffer& in_buffer,
	HBufferParseLoadVisitorInterface& out_visitor
	)
{
	HSINT returnOffset( in_offset );
	HU8 value = 0;
	HTraitBufferOutGet( value, returnOffset, in_buffer );
	const HBufferParseBinType::TControlValues::TEnum control( (HBufferParseBinType::TControlValues::TEnum) value );

	switch( control )
	{
	default:
		{
			returnOffset = in_offset; 
			out_visitor.ErrorSet( "missing name", returnOffset );
			break;
		}
	case HBufferParseBinType::TControlValues::TTokenNone:
		{
			out_name = HNULL;
			break;
		}
	case HBufferParseBinType::TControlValues::TTokenSizeU8:
	case HBufferParseBinType::TControlValues::TTokenSizeU16:
	case HBufferParseBinType::TControlValues::TTokenSizeU32:
		{
			HU32 size = 0;
			returnOffset = LocalStringSizeGet( control, in_buffer, returnOffset, size, HBufferParseBinType::TControlValues::TTokenSizeU8, HBufferParseBinType::TControlValues::TTokenSizeU16, HBufferParseBinType::TControlValues::TTokenSizeU32 );
			returnOffset = LocalLoadString( in_buffer, returnOffset, size, out_name );
			break;
		}
	}

	return returnOffset;
}

/**/
static const HSINT LocalBlockStart(  
	const HSINT in_offset,
	const HBuffer& in_buffer,
	HBufferParseLoadVisitorInterface& out_visitor, 
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth 
	)
{
	HSINT returnOffset( in_offset );
	in_out_depth += 1;

	HString name;
	returnOffset = LocalNameGet(
		name,
		returnOffset,
		in_buffer,
		out_visitor
		);

	if( HTRUE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		return returnOffset;
	}

	out_visitor.FoundBlockStart( name, in_offset );

	return returnOffset;
}

/**/
static HVOID LocalBlockEnd(
	const HSINT in_offset, 
	HBufferParseLoadVisitorInterface& out_visitor, 
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth 
	)
{
	in_out_depth -= 1;

	if( HTRUE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		return;
	}

	out_visitor.FoundBlockEnd( in_offset );

	return;
}

/**/
template< typename IN_TYPE >
static HSINT LocalDealValue( 
	const HBuffer& in_buffer, 
	const HSINT in_offset, 
	HBufferParseLoadVisitorInterface& out_visitor,
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth,
	const HString& in_valueName
	)
{
	HSINT returnOffset( in_offset );

	IN_TYPE value;
	HTraitBufferOutGet( value, returnOffset, in_buffer );

	if( HFALSE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		out_visitor.FoundValue( in_valueName, HBufferParseVariant( value ), returnOffset );
	}
	
	return returnOffset;
}

/**/
static HSINT LocalDealValueHString( 
	const HBufferParseBinType::TControlValues::TEnum in_type, 
	const HBuffer& in_buffer, 
	const HSINT in_offset, 
	HBufferParseLoadVisitorInterface& out_visitor,
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth,
	const HString& in_valueName
	)
{
	HSINT returnOffset( in_offset );

	HU32 size = 0;
	returnOffset = LocalStringSizeGet( in_type, in_buffer, returnOffset, size, HBufferParseBinType::TControlValues::TValueHStringSizeU8, HBufferParseBinType::TControlValues::TValueHStringSizeU16, HBufferParseBinType::TControlValues::TValueHStringSizeU32 );

	HString value;
	returnOffset = LocalLoadString( in_buffer, returnOffset, size, value );

	if( HFALSE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		out_visitor.FoundValue( in_valueName, HBufferParseVariant( value ), returnOffset );
	}

	return returnOffset;
}

/**/
template< typename IN_TYPE >
static HSINT LocalDealValueArray( 
	const HBufferParseBinType::TControlValues::TEnum in_type, 
	const HBuffer& in_buffer, 
	const HSINT in_offset, 
	HBufferParseLoadVisitorInterface& out_visitor,
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth,
	const HString& in_valueName
	)
{
	HSINT returnOffset( in_offset );

	typedef HContainerArray< IN_TYPE >TArray;
	TArray valueArray;
	HU32 count = 0;
	returnOffset = LocalStringSizeGet
	( 
		in_type, 
		in_buffer, 
		returnOffset, 
		count, 
		HBufferParseBinType::TypeGetSmall< TArray >(),
		HBufferParseBinType::TypeGetMedium< TArray >(),
		HBufferParseBinType::TypeGetLarge< TArray >()
	);

	for( HU32 index = 0; index < count; ++index )
	{
		IN_TYPE value;
		HTraitBufferOutGet( value, returnOffset, in_buffer );
		valueArray.Insert( value );
	}

	if( HFALSE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		out_visitor.FoundValue( in_valueName, HBufferParseVariant( valueArray ), returnOffset );
	}
	
	return returnOffset;
}

/**
HSINT LocalDealValueArrayHString8( 
	const HBufferParseBinType::TControlValues::TEnum in_type, 
	const HBuffer& in_buffer, 
	const HSINT in_offset, 
	HBufferParseLoadVisitorInterface& out_visitor,
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth,
	const HString& in_valueName
	)
{
	HSINT returnOffset( in_offset );

	TArrayString valueArray;
	HU32 count = 0;
	returnOffset = LocalStringSizeGet( in_type, in_buffer, returnOffset, count, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU8, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU8, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU8 );

	for( HU32 index = 0; index < count; ++index )
	{
		HU8 size = 0;
		HString value;
		HTraitBufferOutGet( size, returnOffset, in_buffer );

		returnOffset = LocalLoadString( in_buffer, returnOffset, size, value );
		valueArray.Insert( value );
	}

	if( HFALSE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		out_visitor.FoundValue( in_valueName, HBufferParseVariant( valueArray ), returnOffset );
	}
	
	return returnOffset;
}

/**
HSINT LocalDealValueArrayHString16( 
	const HBufferParseBinType::TControlValues::TEnum in_type, 
	const HBuffer& in_buffer, 
	const HSINT in_offset, 
	HBufferParseLoadVisitorInterface& out_visitor,
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth,
	const HString& in_valueName
	)
{
	HSINT returnOffset( in_offset );

	TArrayString valueArray;
	HU32 count = 0;
	returnOffset = LocalStringSizeGet( in_type, in_buffer, returnOffset, count, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU16, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU16, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU16 );

	for( HU32 index = 0; index < count; ++index )
	{
		HU16 size = 0;
		HString value;
		HTraitBufferOutGet( size, returnOffset, in_buffer );

		returnOffset = LocalLoadString( in_buffer, returnOffset, size, value );
		valueArray.Insert( value );
	}

	if( HFALSE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		out_visitor.FoundValue( in_valueName, HBufferParseVariant( valueArray ), returnOffset );
	}
	
	return returnOffset;
}

/**
HSINT LocalDealValueArrayHString32( 
	const HBufferParseBinType::TControlValues::TEnum in_type, 
	const HBuffer& in_buffer, 
	const HSINT in_offset, 
	HBufferParseLoadVisitorInterface& out_visitor,
	HSINT& in_out_depth, 
	HSINT& in_out_skipToDepth,
	const HString& in_valueName
	)
{
	HSINT returnOffset( in_offset );

	TArrayString valueArray;
	HU32 count = 0;
	returnOffset = LocalStringSizeGet( in_type, in_buffer, returnOffset, count, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU32, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU32, HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU32 );

	for( HU32 index = 0; index < count; ++index )
	{
		HU32 size = 0;
		HString value;
		HTraitBufferOutGet( size, returnOffset, in_buffer );

		returnOffset = LocalLoadString( in_buffer, returnOffset, size, value );
		valueArray.Insert( value );
	}

	if( HFALSE == LocalSkipTest( in_out_depth, in_out_skipToDepth ) )
	{
		out_visitor.FoundValue( in_valueName, HBufferParseVariant( valueArray ), returnOffset  );
	}
	
	return returnOffset;
}

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HBufferParseLoadBin::HBufferParseLoadBin( const HBuffer& in_srcBuffer, const HSINT in_cursorStart )
: m_buffer( in_srcBuffer )
, m_cursorStart( in_cursorStart )
{
	return;
}

/**/
Hubris::HBufferParseLoadBin::~HBufferParseLoadBin()
{	
	return;
}

//////////////////////////////////////////
// HBufferParseLoad methods
/**/
HVOID Hubris::HBufferParseLoadBin::SubmitVisitor( HBufferParseLoadVisitorInterface& out_visitor )const
{
	HSINT offset( m_cursorStart );
	HSINT depth = 0;
	HSINT skipToDepth = HCOMMON_INVALID_INDEX;
	//this is a little naughty, a value name (TTokenSizeXX) precedes a value
	// if we hit a token, save it and use it for the next value's name
	// tokens are also used after block start
	HString valueName;

	while( offset < m_buffer.SizeGet() )
	{
		HU8 value = 0;
		HTraitBufferOutGet( value, offset, m_buffer );
		const HBufferParseBinType::TControlValues::TEnum control( (HBufferParseBinType::TControlValues::TEnum) value );

		switch( control )
		{
		default:
			{
				//HCOMMON_ASSERT_CASE( control );
				break;
			}
		case HBufferParseBinType::TControlValues::TBlockStart:
			{
				offset = LocalBlockStart( offset, m_buffer, out_visitor, depth, skipToDepth );
				break;
			}
		case HBufferParseBinType::TControlValues::TBlockEnd:
			{
				LocalBlockEnd( offset, out_visitor, depth, skipToDepth );
				break;
			}
		case HBufferParseBinType::TControlValues::TTokenNone:
			{
				valueName = HNULL;
				break;
			}
		case HBufferParseBinType::TControlValues::TTokenSizeU8:
		case HBufferParseBinType::TControlValues::TTokenSizeU16:
		case HBufferParseBinType::TControlValues::TTokenSizeU32:
			{
				HU32 size = 0;
				offset = LocalStringSizeGet( control, m_buffer, offset, size, HBufferParseBinType::TControlValues::TTokenSizeU8, HBufferParseBinType::TControlValues::TTokenSizeU16, HBufferParseBinType::TControlValues::TTokenSizeU32 );
				offset = LocalLoadString( m_buffer, offset, size, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueU8:
			{
				offset = LocalDealValue< HU8 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueS8:
			{
				offset = LocalDealValue< HS8 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueU16:
			{
				offset = LocalDealValue< HU16 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueS16:
			{
				offset = LocalDealValue< HS16 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueU32:
			{
				offset = LocalDealValue< HU32 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueS32:
			{
				offset = LocalDealValue< HS32 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueR32:
			{
				offset = LocalDealValue< HR32 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueR64:
			{
				offset = LocalDealValue< HR64 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueHBOOLTrue:
			{
				if( HFALSE == LocalSkipTest( depth, skipToDepth ) )
				{
					out_visitor.FoundValue( valueName, HBufferParseVariant( ( HBOOL )HTRUE ), offset );
				}
				break;
			}
		case HBufferParseBinType::TControlValues::TValueHBOOLFalse:
			{
				if( HFALSE == LocalSkipTest( depth, skipToDepth ) )
				{
					out_visitor.FoundValue( valueName, HBufferParseVariant( ( HBOOL )HFALSE ), offset );
				}
				break;
			}
		case HBufferParseBinType::TControlValues::TValueHCHAR:
			{
				offset = LocalDealValue< HCHAR >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueHStringSizeU8:
		case HBufferParseBinType::TControlValues::TValueHStringSizeU16:
		case HBufferParseBinType::TControlValues::TValueHStringSizeU32:
			{
				offset = LocalDealValueHString( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		//case HBufferParseBinType::TControlValues::TValueVectorS2:
		//	{
		//		offset = LocalDealValue< HVectorS2 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueVectorS3:
		//	{
		//		offset = LocalDealValue< HVectorS3 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueVectorS4:
		//	{
		//		offset = LocalDealValue< HVectorS4 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueMatrixS2:
		//	{
		//		offset = LocalDealValue< HMatrixS2 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueMatrixS3:
		//	{
		//		offset = LocalDealValue< HMatrixS3 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueMatrixS4:
		//	{
		//		offset = LocalDealValue< HMatrixS4 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueVectorR2:
		//	{
		//		offset = LocalDealValue< HVectorR2 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueVectorR3:
		//	{
		//		offset = LocalDealValue< HVectorR3 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueVectorR4:
		//	{
		//		offset = LocalDealValue< HVectorR4 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueMatrixR2:
		//	{
		//		offset = LocalDealValue< HMatrixR2 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueMatrixR3:
		//	{
		//		offset = LocalDealValue< HMatrixR3 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueMatrixR4:
		//	{
		//		offset = LocalDealValue< HMatrixR4 >( m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}

		case HBufferParseBinType::TControlValues::TValueArrayU8SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayU8SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayU8SizeU32:
			{
				offset = LocalDealValueArray< HU8 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayS8SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayS8SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayS8SizeU32:
			{
				offset = LocalDealValueArray< HS8 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayU16SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayU16SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayU16SizeU32:
			{
				offset = LocalDealValueArray< HU16 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayS16SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayS16SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayS16SizeU32:
			{
				offset = LocalDealValueArray< HS16 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayU32SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayU32SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayU32SizeU32:
			{
				offset = LocalDealValueArray< HU32 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayS32SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayS32SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayS32SizeU32:
			{
				offset = LocalDealValueArray< HS32 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayR32SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayR32SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayR32SizeU32:
			{
				offset = LocalDealValueArray< HR32 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayR64SizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayR64SizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayR64SizeU32:
			{
				offset = LocalDealValueArray< HR64 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayHBOOLSizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayHBOOLSizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayHBOOLSizeU32:
			{
				offset = LocalDealValueArray< HBOOL >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		case HBufferParseBinType::TControlValues::TValueArrayHCHARSizeU8:
		case HBufferParseBinType::TControlValues::TValueArrayHCHARSizeU16:
		case HBufferParseBinType::TControlValues::TValueArrayHCHARSizeU32:
			{
				offset = LocalDealValueArray< HCHAR >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
				break;
			}
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU8SizeU32:
		//	{
		//		offset = LocalDealValueArrayHString8( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU16SizeU32:
		//	{
		//		offset = LocalDealValueArrayHString16( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayHStringSizeU32SizeU32:
		//	{
		//		offset = LocalDealValueArrayHString32( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		////case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS2SizeU8:
		////case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS2SizeU16:
		////case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS2SizeU32:
		////	{
		////		offset = LocalDealValueArray< HVectorS2 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		////		break;
		////	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS3SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS3SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS3SizeU32:
		//	{
		//		offset = LocalDealValueArray< HVectorS3 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS4SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS4SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorS4SizeU32:
		//	{
		//		offset = LocalDealValueArray< HVectorS4 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS2SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS2SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS2SizeU32:
		//	{
		//		offset = LocalDealValueArray< HMatrixS2 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS3SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS3SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS3SizeU32:
		//	{
		//		offset = LocalDealValueArray< HMatrixS3 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS4SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS4SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixS4SizeU32:
		//	{
		//		offset = LocalDealValueArray< HMatrixS4 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR2SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR2SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR2SizeU32:
		//	{
		//		offset = LocalDealValueArray< HVectorR2 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR3SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR3SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR3SizeU32:
		//	{
		//		offset = LocalDealValueArray< HVectorR3 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR4SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR4SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueVectorR4SizeU32:
		//	{
		//		offset = LocalDealValueArray< HVectorR4 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR2SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR2SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR2SizeU32:
		//	{
		//		offset = LocalDealValueArray< HMatrixR2 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR3SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR3SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR3SizeU32:
		//	{
		//		offset = LocalDealValueArray< HMatrixR3 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR4SizeU8:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR4SizeU16:
		//case HBufferParseBinType::TControlValues::TValueArrayTValueMatrixR4SizeU32:
		//	{
		//		offset = LocalDealValueArray< HMatrixR4 >( control, m_buffer, offset, out_visitor, depth, skipToDepth, valueName );
		//		break;
		//	}
		}

		//does visitor want us to skip to end of block
		if( HCOMMON_INVALID_INDEX == skipToDepth )
		{
			if( HTRUE == out_visitor.SkipToEndBlock() )
			{
				skipToDepth = depth - 1;
			}
		}
	}

	return;
}

//////////////////////////////////////////
// private methods
/**/


