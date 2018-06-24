//file: Hubris/HBufferParse/HBufferParseSaveText.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseSaveText.h"

#include "Hubris/HBufferParse/HBufferParseTextVariables.h"
#include "Hubris/HBufferParse/HBufferParseUtilityPrivate.h"
#include "Hubris/HBufferParse/HBufferParseVariant.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HMatrix/HMatrix_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HTinyXml/HTinyXml_Export.h"
#include "Hubris/HTrait/HTrait_Export.h"
#include "Hubris/HType/HType_Export.h"
#include "Hubris/HVariables/HVariables_Export.h"

#include< tinyxml.h >

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HString >TArrayString;
typedef HContainerPair< HCHAR, HString >TPairCharacterString;
typedef HContainerArray< TPairCharacterString >TArrayPairCharacterString;

///////////////////////////////////////////////////////////
// local static variables
/**/
static const HCHAR* const s_textDeclarationVersion = "1.0";
static const HCHAR* const s_textDeclarationEncoding = "utf-8"; //single byte encoding of text
static const HCHAR* const s_textDeclarationStandalone = "yes";

///////////////////////////////////////////////////////////
// local static methods
/**/
const TArrayString LocalStackStringGet( 
	const TiXmlElement* const in_pElement 
	)
{
	TArrayString returnArrayString;
	const TiXmlNode* pTrace = in_pElement;
	while( HNULL != pTrace )
	{
		HContainerUtility::PushBack( returnArrayString, pTrace->Value() );
		pTrace = pTrace->Parent();
	}

	return returnArrayString;
}

/*
static const HString LocalDealStringArray( 
	const TArrayString in_arrayString 
	)
{
	HString returnString;

	HBOOL first = HTRUE;
	HCOMMON_FOR_EACH_CONST( string, in_arrayString, TArrayString )
	{
		if( HFALSE == first )
		{
			returnString += HVariablesString::CommaGet();
			returnString += HVariablesString::SpaceGet();
		}
		first = HFALSE;

		returnString += ( "\"" + HTraitStringIn( string ) + "\"" );
	}

	return returnString;
}

/**
template< typename IN_TYPE >
static const HString LocalDealString( const IN_TYPE& in_src );

template<>
static const HString LocalDealString< TArrayString >( const TArrayString& in_arrayString )
{
	HString returnString;

	HBOOL first = HTRUE;
	HCOMMON_FOR_EACH_CONST( string, in_arrayString, TArrayString )
	{
		if( HFALSE == first )
		{
			returnString += HVariablesString::CommaGet();
			returnString += HVariablesString::SpaceGet();
		}
		first = HFALSE;

		returnString += ( "\"" + HTraitStringIn( string ) + "\"" );
	}

	return returnString;
}

template< typename IN_TYPE >
static const HString LocalDealString( const IN_TYPE& in_src )
{
	return( HTraitStringIn( in_src ) );
}

/**/
template< HSINT IN_INDEX >
static HVOID LocalVariantValuePut( 
	HBufferParseSaveText& in_out_saveText, 
	const HString& in_name,
	const HBufferParseVariant& in_value 
	)
{	
	typedef HTypeListUtilIndexType< HBufferParseVariant::TTypeList, IN_INDEX >::Type TType;

	//const HString stringData = LocalDealString< TType >( in_value.ValueGet< TType >() );
	const HString stringData = HTraitStringIn( in_value.ValueGet< TType >() );

	in_out_saveText.ValueStringPut(
		in_name,
		HTraitName< TType >::NameGet(),
		stringData
		);

	return;
}

///////////////////////////////////////////////////////////
// creation
/**/
HBufferParseSaveText::HBufferParseSaveText( const HBufferParseSaveText& in_src )
: m_pDocument( HNULL )
, m_pCurrentElement( HNULL )
{
	( *this ) = in_src;
	return;
}

/**/
HBufferParseSaveText::HBufferParseSaveText()
: m_pDocument( HNULL )
, m_pCurrentElement( HNULL )
{
	HCOMMON_NEW( m_pDocument, TiXmlDocument );

	m_pDocument->InsertEndChild( 
		TiXmlDeclaration( 
		s_textDeclarationVersion, 
		s_textDeclarationEncoding, 
		s_textDeclarationStandalone 
		) );

	m_pCurrentElement = m_pDocument->InsertEndChild( 
		TiXmlElement( HBufferParseTextVariables::NameGetDocumentRoot() )
		)->ToElement();

	return;
}

/**/
HBufferParseSaveText::~HBufferParseSaveText()
{
	HCOMMON_DELETE( m_pDocument, TiXmlDocument );
	m_pCurrentElement = HNULL;
	return;
}

///////////////////////////////////////////////////////////
// operators
/**/
const HBufferParseSaveText& HBufferParseSaveText::operator=( const HBufferParseSaveText& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		HCOMMON_DELETE( m_pDocument, TiXmlDocument );
		HCOMMON_ASSERT( HNULL != in_rhs.m_pDocument, "invlaid input" );

		HCOMMON_NEW_PARAM( m_pDocument, TiXmlDocument, ( *in_rhs.m_pDocument ) );

		m_pCurrentElement = HNULL;
		if( HNULL != in_rhs.m_pCurrentElement )
		{
			const TArrayString stackString = LocalStackStringGet( in_rhs.m_pCurrentElement );

			TiXmlHandle handel( m_pDocument );
			TiXmlHandle trace( handel );
			HCOMMON_FOR_EACH_CONST( name, stackString, TArrayString )
			{
				trace = trace.FirstChild( name.RawGet() );
			}

			m_pCurrentElement = trace.Element();
		}
	}

	return( *this );
}

/**/
const HBOOL HBufferParseSaveText::operator==( const HBufferParseSaveText& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		const TArrayString stackStringLhs = LocalStackStringGet( m_pCurrentElement );
		const TArrayString stackStringRhs = LocalStackStringGet( in_rhs.m_pCurrentElement );
		match &= ( stackStringLhs == stackStringRhs );
		match &= ( BufferGet() == in_rhs.BufferGet() );
	}

	return match;
}

/**/
const HBOOL HBufferParseSaveText::operator!=( const HBufferParseSaveText& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

//////////////////////////////////////////
// public methods
/**/
HVOID HBufferParseSaveText::BlockStart( 
	const HString& in_name //name must not have spaces, can be HNULL
	)
{
	HCOMMON_ASSERT( HNULL != m_pCurrentElement, "invalid state" );
	const HString localName = NameValidate( in_name );
	m_pCurrentElement = m_pCurrentElement->InsertEndChild(
		TiXmlElement( localName.RawGet() )
		)->ToElement();

	return;
}
/**/
HVOID HBufferParseSaveText::BlockEnd()
{
	HCOMMON_ASSERT( HNULL != m_pCurrentElement, "invalid state" );
	m_pCurrentElement = m_pCurrentElement->Parent()->ToElement();

	return;
}

/**/
HVOID HBufferParseSaveText::ValuePut( 
	const HString& in_name,
	const HBufferParseVariant& in_value 
	)
{
	const HSINT type = in_value.TypeIndexGet();
	switch( type )
	{
	default:
		{
			HCOMMON_ASSERT_CASE( type );
			break;
		}
	case  0: { LocalVariantValuePut<  0 >( *this, in_name, in_value ); break; }
	case  1: { LocalVariantValuePut<  1 >( *this, in_name, in_value ); break; }
	case  2: { LocalVariantValuePut<  2 >( *this, in_name, in_value ); break; }
	case  3: { LocalVariantValuePut<  3 >( *this, in_name, in_value ); break; }
	case  4: { LocalVariantValuePut<  4 >( *this, in_name, in_value ); break; }
	case  5: { LocalVariantValuePut<  5 >( *this, in_name, in_value ); break; }
	case  6: { LocalVariantValuePut<  6 >( *this, in_name, in_value ); break; }
	case  7: { LocalVariantValuePut<  7 >( *this, in_name, in_value ); break; }
	case  8: { LocalVariantValuePut<  8 >( *this, in_name, in_value ); break; }
	case  9: { LocalVariantValuePut<  9 >( *this, in_name, in_value ); break; }
	case 10: { LocalVariantValuePut< 10 >( *this, in_name, in_value ); break; }
	case 11: { LocalVariantValuePut< 11 >( *this, in_name, in_value ); break; }
	case 12: { LocalVariantValuePut< 12 >( *this, in_name, in_value ); break; }
	case 13: { LocalVariantValuePut< 13 >( *this, in_name, in_value ); break; }
	case 14: { LocalVariantValuePut< 14 >( *this, in_name, in_value ); break; }
	case 15: { LocalVariantValuePut< 15 >( *this, in_name, in_value ); break; }
	case 16: { LocalVariantValuePut< 16 >( *this, in_name, in_value ); break; }
	case 17: { LocalVariantValuePut< 17 >( *this, in_name, in_value ); break; }
	case 18: { LocalVariantValuePut< 18 >( *this, in_name, in_value ); break; }
	case 19: { LocalVariantValuePut< 19 >( *this, in_name, in_value ); break; }
	case 20: { LocalVariantValuePut< 20 >( *this, in_name, in_value ); break; }
	case 21: { LocalVariantValuePut< 21 >( *this, in_name, in_value ); break; }
	case 22: { LocalVariantValuePut< 22 >( *this, in_name, in_value ); break; }
	case 23: { LocalVariantValuePut< 23 >( *this, in_name, in_value ); break; }
	case 24: { LocalVariantValuePut< 24 >( *this, in_name, in_value ); break; }
	case 25: { LocalVariantValuePut< 25 >( *this, in_name, in_value ); break; }
	case 26: { LocalVariantValuePut< 26 >( *this, in_name, in_value ); break; }
	case 27: { LocalVariantValuePut< 27 >( *this, in_name, in_value ); break; }
	case 28: { LocalVariantValuePut< 28 >( *this, in_name, in_value ); break; }
	case 29: { LocalVariantValuePut< 29 >( *this, in_name, in_value ); break; }
	case 30: { LocalVariantValuePut< 30 >( *this, in_name, in_value ); break; }
	case 31: { LocalVariantValuePut< 31 >( *this, in_name, in_value ); break; }
	case 32: { LocalVariantValuePut< 32 >( *this, in_name, in_value ); break; }
	case 33: { LocalVariantValuePut< 33 >( *this, in_name, in_value ); break; }
	case 34: { LocalVariantValuePut< 34 >( *this, in_name, in_value ); break; }
	case 35: { LocalVariantValuePut< 35 >( *this, in_name, in_value ); break; }
	case 36: { LocalVariantValuePut< 36 >( *this, in_name, in_value ); break; }
	case 37: { LocalVariantValuePut< 37 >( *this, in_name, in_value ); break; }
	case 38: { LocalVariantValuePut< 38 >( *this, in_name, in_value ); break; }
	case 39: { LocalVariantValuePut< 39 >( *this, in_name, in_value ); break; }
	case 40: { LocalVariantValuePut< 40 >( *this, in_name, in_value ); break; }
	case 41: { LocalVariantValuePut< 41 >( *this, in_name, in_value ); break; }
	case 42: { LocalVariantValuePut< 42 >( *this, in_name, in_value ); break; }
	case 43: { LocalVariantValuePut< 43 >( *this, in_name, in_value ); break; }
	case 44: { LocalVariantValuePut< 44 >( *this, in_name, in_value ); break; }
	case 45: { LocalVariantValuePut< 45 >( *this, in_name, in_value ); break; }
	case 46: { LocalVariantValuePut< 46 >( *this, in_name, in_value ); break; }
	case 47: { LocalVariantValuePut< 47 >( *this, in_name, in_value ); break; }
	case 48: { LocalVariantValuePut< 48 >( *this, in_name, in_value ); break; }
	case 49: { LocalVariantValuePut< 49 >( *this, in_name, in_value ); break; }
	case 50: { LocalVariantValuePut< 50 >( *this, in_name, in_value ); break; }
	case 51: { LocalVariantValuePut< 51 >( *this, in_name, in_value ); break; }
	case 52: { LocalVariantValuePut< 52 >( *this, in_name, in_value ); break; }
	case 53: { LocalVariantValuePut< 53 >( *this, in_name, in_value ); break; }
	case 54: { LocalVariantValuePut< 54 >( *this, in_name, in_value ); break; }
	case 55: { LocalVariantValuePut< 55 >( *this, in_name, in_value ); break; }
	case 56: { LocalVariantValuePut< 56 >( *this, in_name, in_value ); break; }
	case 57: { LocalVariantValuePut< 57 >( *this, in_name, in_value ); break; }
	case 58: { LocalVariantValuePut< 58 >( *this, in_name, in_value ); break; }
	case 59: { LocalVariantValuePut< 59 >( *this, in_name, in_value ); break; }
	}

}

/**/
HVOID HBufferParseSaveText::CommentPut( 
	const HString& in_comment 
	)
{
	HCOMMON_ASSERT( HNULL != m_pCurrentElement, "invalid state" );

	TiXmlComment comment;
	comment.SetValue( in_comment.RawGet() );

	m_pCurrentElement->InsertEndChild(
		comment
		);

	return;
}

/**/
HVOID HBufferParseSaveText::ValueStringPut(
	const HString& in_name, //name must not have spaces
	const HString& in_typeName,
	const HString& in_stringValue
	)
{
	BlockStart( in_name );
	HCOMMON_ASSERT( HNULL != m_pCurrentElement, "invalid state" );

	m_pCurrentElement->SetAttribute( 
		HBufferParseTextVariables::NameGetAttributeType(),
		in_typeName.RawGet()
		);

	m_pCurrentElement->InsertEndChild(
		TiXmlText( in_stringValue.RawGet() )
		);

	BlockEnd();
}

//////////////////////////////////////////
// static private methods
/**/
const HString HBufferParseSaveText::NameValidate( 
	const HString& in_name 
	)
{
	if( HNULL == in_name )
	{
		return HBufferParseTextVariables::NameGetDefaultBlock();
	}

	HCOMMON_ASSERT( HCOMMON_INVALID_INDEX == HStringUtility::FindFirst( in_name, HVariablesString::SpaceGet() ), "invalid char in name" );

	return in_name;
}

///////////////////////////////////////////////////////////
// accessors
/**/
const HBuffer& HBufferParseSaveText::BufferGet()const
{
	m_buffer.Clear();
	if( HNULL != m_pDocument )
	{
		HTinyXmlUtility::TinyXmlToBuffer(
			m_buffer, 
			*m_pDocument 
			);
	}

	return m_buffer;
}

/**/

