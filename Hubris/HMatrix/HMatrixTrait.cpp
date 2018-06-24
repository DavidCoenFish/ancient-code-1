//file: Hubris/HMatrix/HMatrixTrait.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixTrait.h"

#include "Hubris/HMatrix/HMatrix.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringUtility.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HVariables/HVariablesString.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
typedef HContainerArray< HString >TArrayString;

///////////////////////////////////////////////////////////
// name
/**/
#define HMATRIX_TRAIT_NAME_IMPLEMENTATION( IN_TYPE )			\
	const HCHAR* const Hubris::HTraitName< IN_TYPE >::NameGet(){ return HCOMMON_TOKEN( IN_TYPE ); }								

/**/
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HVectorS2 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HVectorS3 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HVectorS4 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HMatrixS2 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HMatrixS3 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HMatrixS4 );

/**/
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HVectorR2 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HVectorR3 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HVectorR4 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HMatrixR2 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HMatrixR3 );
HMATRIX_TRAIT_NAME_IMPLEMENTATION( HMatrixR4 );

#undef HMATRIX_TRAIT_NAME_IMPLEMENTATION
/**/

///////////////////////////////////////////////////////////
// empty
/**/
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HVectorS2 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HVectorS3 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HVectorS4 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HMatrixS2 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HMatrixS3 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HMatrixS4 );

/**/
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HVectorR2 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HVectorR3 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HVectorR4 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HMatrixR2 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HMatrixR3 );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( HMatrixR4 );
/**/

/**/
template< typename IN_TYPE >
static HString LocalPrintArray( const IN_TYPE* const in_pData, const HSINT in_count )
{
	HString returnString;
	for( HSINT index = 0; index < in_count; ++index )
	{
		if( 0 != index )
		{
			returnString += HVariablesString::SpaceGet();
		}

		returnString += HTraitStringIn< IN_TYPE >( in_pData[ index ] );
	}

	return returnString;
}

/**/
template< typename IN_TYPE >
static HVOID LocalArrayRead( IN_TYPE* const out_pData, const HSINT in_count, const HString& in_string )
{
	TArrayString arrayString;
	HStringUtility::Split( in_string, HVariablesString::SpaceGet(), arrayString );

	for( HSINT index = 0; index < in_count; ++index )
	{
		IN_TYPE value = HTraitEmpty< IN_TYPE >::EmptyGet();

		if( index < arrayString.SizeGet() )
		{
			HTraitStringOut< IN_TYPE >( value, arrayString[ index ] );
		}

		out_pData[ index ] = value;
	}

	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalBufferAppend( 
	HBuffer& out_buffer,
	const IN_TYPE* const in_pData, 
	const HSINT in_count 
	)
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		HTraitBufferInAppend( 
			out_buffer,
			in_pData[ index ]
			);
	}

	return;
}

/**/
template< typename IN_TYPE >
static const HSINT LocalBufferReplace( 
	HBuffer& out_buffer,
	const IN_TYPE* const in_pData, 
	const HSINT in_count,
	const HSINT in_offset
	)
{
	HSINT offset( in_offset );
	for( HSINT index = 0; index < in_count; ++index )
	{
		offset = HTraitBufferInReplace( 
			out_buffer,
			in_pData[ index ],
			offset
			);
	}

	return offset;
}


/**/
template< typename IN_TYPE >
static HVOID LocalBufferRead( 
	IN_TYPE* const out_pData, 
	HSINT& in_out_offset,
	const HSINT in_count,
	const HBuffer& in_buffer
	)
{
	for( HSINT index = 0; index < in_count; ++index )
	{
		IN_TYPE value;
		HTraitBufferOutGet( 
			value,
			in_out_offset,
			in_buffer
			);
		out_pData[ index ] = value;
	}

	return;
}

/////////////////////////////////////////////////////////////////
// global HTraitStringIn
/*
	template< typename IN_TYPE >HString HTraitStringIn( const IN_TYPE& in_data );
*/
HString Hubris::HTraitStringIn< HVectorS2 >( const HVectorS2& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HVectorS2::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HVectorS3 >( const HVectorS3& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HVectorS3::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HVectorS4 >( const HVectorS4& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HVectorS4::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HMatrixS2 >( const HMatrixS2& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HMatrixS2::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HMatrixS3 >( const HMatrixS3& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HMatrixS3::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HMatrixS4 >( const HMatrixS4& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HMatrixS4::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HVectorR2 >( const HVectorR2& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HVectorR2::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HVectorR3 >( const HVectorR3& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HVectorR3::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HVectorR4 >( const HVectorR4& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HVectorR4::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HMatrixR2 >( const HMatrixR2& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HMatrixR2::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HMatrixR3 >( const HMatrixR3& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HMatrixR3::TVar::TSize );
}

/**/
HString Hubris::HTraitStringIn< HMatrixR4 >( const HMatrixR4& in_data )
{
	return LocalPrintArray( in_data.DataGet(), HMatrixR4::TVar::TSize );
}

/**/
HVOID Hubris::HTraitStringOut< HVectorS2 >( HVectorS2& out_value, const HString& in_data )
{
	HSINT data[ HVectorS2::TVar::TSize ];
	LocalArrayRead( data, HVectorS2::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HVectorS3 >( HVectorS3& out_value, const HString& in_data )
{
	HSINT data[ HVectorS3::TVar::TSize ];
	LocalArrayRead( data, HVectorS3::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HVectorS4 >( HVectorS4& out_value, const HString& in_data )
{
	HSINT data[ HVectorS4::TVar::TSize ];
	LocalArrayRead( data, HVectorS4::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HMatrixS2 >( HMatrixS2& out_value, const HString& in_data )
{
	HSINT data[ HMatrixS2::TVar::TSize ];
	LocalArrayRead( data, HMatrixS2::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HMatrixS3 >( HMatrixS3& out_value, const HString& in_data )
{
	HSINT data[ HMatrixS3::TVar::TSize ];
	LocalArrayRead( data, HMatrixS3::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HMatrixS4 >( HMatrixS4& out_value, const HString& in_data )	  
{
	HSINT data[ HMatrixS4::TVar::TSize ];
	LocalArrayRead( data, HMatrixS4::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HVectorR2 >( HVectorR2& out_value, const HString& in_data )
{
	HREAL data[ HVectorR2::TVar::TSize ];
	LocalArrayRead( data, HVectorR2::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HVectorR3 >( HVectorR3& out_value, const HString& in_data )
{
	HREAL data[ HVectorR3::TVar::TSize ];
	LocalArrayRead( data, HVectorR3::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HVectorR4 >( HVectorR4& out_value, const HString& in_data )
{
	HREAL data[ HVectorR4::TVar::TSize ];
	LocalArrayRead( data, HVectorR4::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HMatrixR2 >( HMatrixR2& out_value, const HString& in_data )
{
	HREAL data[ HMatrixR2::TVar::TSize ];
	LocalArrayRead( data, HMatrixR2::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HMatrixR3 >( HMatrixR3& out_value, const HString& in_data )
{
	HREAL data[ HMatrixR3::TVar::TSize ];
	LocalArrayRead( data, HMatrixR3::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HMatrixR4 >( HMatrixR4& out_value, const HString& in_data )
{
	HREAL data[ HMatrixR4::TVar::TSize ];
	LocalArrayRead( data, HMatrixR4::TVar::TSize, in_data );
	out_value.DataSet( data );
	return;
}

/**/
/////////////////////////////////////////////////////////////////
// global HTraitBufferInAppend
/*
	template< typename IN_TYPE >HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const IN_TYPE& in_value );
*/
HVOID Hubris::HTraitBufferInAppend< HVectorU2 >( HBuffer& in_out_buffer, const HVectorU2& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorU2::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorU3 >( HBuffer& in_out_buffer, const HVectorU3& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorU3::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorU4 >( HBuffer& in_out_buffer, const HVectorU4& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorU4::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixU2 >( HBuffer& in_out_buffer, const HMatrixU2& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixU2::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixU3 >( HBuffer& in_out_buffer, const HMatrixU3& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixU3::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixU4 >( HBuffer& in_out_buffer, const HMatrixU4& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixU4::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorS2 >( HBuffer& in_out_buffer, const HVectorS2& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorS2::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorS3 >( HBuffer& in_out_buffer, const HVectorS3& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorS3::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorS4 >( HBuffer& in_out_buffer, const HVectorS4& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorS4::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixS2 >( HBuffer& in_out_buffer, const HMatrixS2& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixS2::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixS3 >( HBuffer& in_out_buffer, const HMatrixS3& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixS3::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixS4 >( HBuffer& in_out_buffer, const HMatrixS4& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixS4::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorR2 >( HBuffer& in_out_buffer, const HVectorR2& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorR2::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorR3 >( HBuffer& in_out_buffer, const HVectorR3& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorR3::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HVectorR4 >( HBuffer& in_out_buffer, const HVectorR4& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HVectorR4::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixR2 >( HBuffer& in_out_buffer, const HMatrixR2& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixR2::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixR3 >( HBuffer& in_out_buffer, const HMatrixR3& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixR3::TVar::TSize );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< HMatrixR4 >( HBuffer& in_out_buffer, const HMatrixR4& in_value )
{
	LocalBufferAppend( in_out_buffer, in_value.DataGet(), HMatrixR4::TVar::TSize );
	return;
}

/////////////////////////////////////////////////////////////////
// global HTraitBufferInReplace
/*
	template< typename IN_TYPE >HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const IN_TYPE& in_value, const HSINT in_offset )
*/
HSINT Hubris::HTraitBufferInReplace< HVectorU2 >( HBuffer& in_out_buffer, const HVectorU2& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorU2::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorU3 >( HBuffer& in_out_buffer, const HVectorU3& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorU3::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorU4 >( HBuffer& in_out_buffer, const HVectorU4& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorU4::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixU2 >( HBuffer& in_out_buffer, const HMatrixU2& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixU2::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixU3 >( HBuffer& in_out_buffer, const HMatrixU3& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixU3::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixU4 >( HBuffer& in_out_buffer, const HMatrixU4& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixU4::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorS2 >( HBuffer& in_out_buffer, const HVectorS2& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorS2::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorS3 >( HBuffer& in_out_buffer, const HVectorS3& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorS3::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorS4 >( HBuffer& in_out_buffer, const HVectorS4& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorS4::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixS2 >( HBuffer& in_out_buffer, const HMatrixS2& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixS2::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixS3 >( HBuffer& in_out_buffer, const HMatrixS3& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixS3::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixS4 >( HBuffer& in_out_buffer, const HMatrixS4& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixS4::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorR2 >( HBuffer& in_out_buffer, const HVectorR2& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorR2::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorR3 >( HBuffer& in_out_buffer, const HVectorR3& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorR3::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HVectorR4 >( HBuffer& in_out_buffer, const HVectorR4& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HVectorR4::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixR2 >( HBuffer& in_out_buffer, const HMatrixR2& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixR2::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixR3 >( HBuffer& in_out_buffer, const HMatrixR3& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixR3::TVar::TSize, in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< HMatrixR4 >( HBuffer& in_out_buffer, const HMatrixR4& in_value, const HSINT in_offset )
{
	return LocalBufferReplace( in_out_buffer, in_value.DataGet(), HMatrixR4::TVar::TSize, in_offset );
}

/////////////////////////////////////////////////////////////////
// global HTraitBufferOutGet
/*
	template< typename IN_TYPE >HVOID HTraitBufferOutGet( IN_TYPE& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
*/
HVOID Hubris::HTraitBufferOutGet< HVectorU2 >( HVectorU2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorU2::TType data[ HVectorU2::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorU2::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorU3 >( HVectorU3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorU3::TType data[ HVectorU3::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorU3::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorU4 >( HVectorU4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorU4::TType data[ HVectorU4::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorU4::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixU2 >( HMatrixU2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixU2::TType data[ HMatrixU2::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixU2::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixU3 >( HMatrixU3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixU3::TType data[ HMatrixU3::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixU3::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixU4 >( HMatrixU4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixU4::TType data[ HMatrixU4::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixU4::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorS2 >( HVectorS2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorS2::TType data[ HVectorS2::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorS2::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorS3 >( HVectorS3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorS3::TType data[ HVectorS3::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorS3::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorS4 >( HVectorS4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorS4::TType data[ HVectorS4::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorS4::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixS2 >( HMatrixS2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixS2::TType data[ HMatrixS2::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixS2::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixS3 >( HMatrixS3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixS3::TType data[ HMatrixS3::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixS3::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixS4 >( HMatrixS4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixS4::TType data[ HMatrixS4::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixS4::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorR2 >( HVectorR2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorR2::TType data[ HVectorR2::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorR2::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorR3 >( HVectorR3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorR3::TType data[ HVectorR3::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorR3::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HVectorR4 >( HVectorR4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HVectorR4::TType data[ HVectorR4::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HVectorR4::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixR2 >( HMatrixR2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixR2::TType data[ HMatrixR2::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixR2::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixR3 >( HMatrixR3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixR3::TType data[ HMatrixR3::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixR3::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< HMatrixR4 >( HMatrixR4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	HMatrixR4::TType data[ HMatrixR4::TVar::TSize ];
	LocalBufferRead( data, in_out_offset, HMatrixR4::TVar::TSize, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/

