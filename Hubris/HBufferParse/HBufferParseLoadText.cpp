//file: Hubris/HBufferParse/HBufferParseLoadText.h

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseLoadText.h"

#include "Hubris/HBufferParse/HBufferParseLoadVisitorInterface.h"
#include "Hubris/HBufferParse/HBufferParseTextVariables.h"
#include "Hubris/HBufferParse/HBufferParseVariant.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HCommon/HCommon_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HMatrix/HMatrix_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HTinyXml/HTinyXml_Export.h"
#include "Hubris/HType/HType_Export.h"
#include "Hubris/HTrait/HTrait_Export.h"
#include "Hubris/HVariables/HVariables_Export.h"
#include "Hubris/HVariant/HVariant_Export.h"

#include< tinyxml.h >

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerPair< HCHAR, HString >TPairCharacterString;
typedef HContainerArray< TPairCharacterString >TArrayPairCharacterString;


//////////////////////////////////////////
// Local free functions
/**
static HVOID LocalDealStringArray( TArrayString& out_arrayString, const HString in_data )
{
	const TArrayPairCharacterString& defaultEscape = HStringUtility::DefaultEscapeCharArrayGet();

	//here the deal, we have n escaped string seperated by a comma then a space
	// lets ignore everything but the string quote
	HBOOL insideString = HFALSE;
	HString currentString;
	for( HSINT index = 0; index < in_data.SizeGet(); ++index )
	{
		const HCHAR value = in_data[ index ];
		if( value == HVariablesString::QuoteGet() )
		{
			if( HTRUE == insideString )
			{
				HContainerUtility::PushBack( out_arrayString, currentString );
				currentString = HNULL;
			}

			insideString ^= HTRUE;
			continue;
		}

		if( HFALSE == insideString )
		{
			continue;
		}
	
		HSINT length = 0;
		if( HTRUE == HStringUtility::FindLongestMatchEscape( in_data, index, currentString, length, defaultEscape ) )
		{
			index += ( length - 1 );
		}
		else
		{
			currentString += value;
		}
	}

	return;
}

/**
template< typename IN_TYPE >
static HVOID LocalDealString( const HString& in_data, IN_TYPE& out_value );

template<>
static HVOID LocalDealString( const HString& in_data, TArrayString& out_arrayString )
{
	const TArrayPairCharacterString& defaultEscape = HStringUtility::DefaultEscapeCharArrayGet();

	//here the deal, we have n escaped string seperated by a comma then a space
	// lets ignore everything but the string quote
	HBOOL insideString = HFALSE;
	HString currentString;
	for( HSINT index = 0; index < in_data.SizeGet(); ++index )
	{
		const HCHAR value = in_data[ index ];
		if( value == HVariablesString::QuoteGet() )
		{
			if( HTRUE == insideString )
			{
				HContainerUtility::PushBack( out_arrayString, currentString );
				currentString = HNULL;
			}

			insideString ^= HTRUE;
			continue;
		}

		if( HFALSE == insideString )
		{
			continue;
		}
	
		HSINT length = 0;
		if( HTRUE == HStringUtility::FindLongestMatchEscape( in_data, index, currentString, length, defaultEscape ) )
		{
			index += ( length - 1 );
		}
		else
		{
			currentString += value;
		}
	}

	return;
}

template< typename IN_TYPE >
static HVOID LocalDealString( const HString& in_data, IN_TYPE& out_value )
{
	HTraitStringOut( out_value, in_data );
	return;
}

/**/
template< HSINT IN_INDEX >
static HVOID LocalTypeValueGet( 
	HBufferParseVariant& out_value,
	const HString& in_data
	)
{
	typedef HTypeListUtilIndexType< HBufferParseVariant::TTypeList, IN_INDEX >::Type TType;

	TType localValue;
	HTraitStringOut( localValue, in_data );
	//LocalDealString( in_data, localValue );
	out_value = localValue;

	return;
}

/**/
static HVOID LocalValueGet( 
	HBufferParseVariant& out_value,
	const HString& in_type, 
	const HString& in_data 
	)
{
	const HSINT index = HVariantUtility::TypeIndexFromName< HBufferParseVariant >( in_type );

	switch( index )
	{
	default:
		{
			break;
		}
	case  0:{ LocalTypeValueGet<  0 >( out_value, in_data ); break; }
	case  1:{ LocalTypeValueGet<  1 >( out_value, in_data ); break; }
	case  2:{ LocalTypeValueGet<  2 >( out_value, in_data ); break; }
	case  3:{ LocalTypeValueGet<  3 >( out_value, in_data ); break; }
	case  4:{ LocalTypeValueGet<  4 >( out_value, in_data ); break; }
	case  5:{ LocalTypeValueGet<  5 >( out_value, in_data ); break; }
	case  6:{ LocalTypeValueGet<  6 >( out_value, in_data ); break; }
	case  7:{ LocalTypeValueGet<  7 >( out_value, in_data ); break; }
	case  8:{ LocalTypeValueGet<  8 >( out_value, in_data ); break; }
	case  9:{ LocalTypeValueGet<  9 >( out_value, in_data ); break; }
	case 10:{ LocalTypeValueGet< 10 >( out_value, in_data ); break; }
	case 11:{ LocalTypeValueGet< 11 >( out_value, in_data ); break; }
	case 12:{ LocalTypeValueGet< 12 >( out_value, in_data ); break; }
	case 13:{ LocalTypeValueGet< 13 >( out_value, in_data ); break; }
	case 14:{ LocalTypeValueGet< 14 >( out_value, in_data ); break; }
	case 15:{ LocalTypeValueGet< 15 >( out_value, in_data ); break; }
	case 16:{ LocalTypeValueGet< 16 >( out_value, in_data ); break; }
	case 17:{ LocalTypeValueGet< 17 >( out_value, in_data ); break; }
	case 18:{ LocalTypeValueGet< 18 >( out_value, in_data ); break; }
	case 19:{ LocalTypeValueGet< 19 >( out_value, in_data ); break; }
	case 20:{ LocalTypeValueGet< 20 >( out_value, in_data ); break; }
	case 21:{ LocalTypeValueGet< 21 >( out_value, in_data ); break; }
	case 22:{ LocalTypeValueGet< 22 >( out_value, in_data ); break; }
	case 23:{ LocalTypeValueGet< 23 >( out_value, in_data ); break; }
	case 24:{ LocalTypeValueGet< 24 >( out_value, in_data ); break; }
	case 25:{ LocalTypeValueGet< 25 >( out_value, in_data ); break; }
	case 26:{ LocalTypeValueGet< 26 >( out_value, in_data ); break; }
	case 27:{ LocalTypeValueGet< 27 >( out_value, in_data ); break; }
	case 28:{ LocalTypeValueGet< 28 >( out_value, in_data ); break; }
	case 29:{ LocalTypeValueGet< 29 >( out_value, in_data ); break; }
	case 30:{ LocalTypeValueGet< 30 >( out_value, in_data ); break; }
	case 31:{ LocalTypeValueGet< 31 >( out_value, in_data ); break; }
	case 32:{ LocalTypeValueGet< 32 >( out_value, in_data ); break; }
	case 33:{ LocalTypeValueGet< 33 >( out_value, in_data ); break; }
	case 34:{ LocalTypeValueGet< 34 >( out_value, in_data ); break; }
	case 35:{ LocalTypeValueGet< 35 >( out_value, in_data ); break; }
	case 36:{ LocalTypeValueGet< 36 >( out_value, in_data ); break; }
	case 37:{ LocalTypeValueGet< 37 >( out_value, in_data ); break; }
	case 38:{ LocalTypeValueGet< 38 >( out_value, in_data ); break; }
	case 39:{ LocalTypeValueGet< 39 >( out_value, in_data ); break; }
	case 40:{ LocalTypeValueGet< 40 >( out_value, in_data ); break; }
	case 41:{ LocalTypeValueGet< 41 >( out_value, in_data ); break; }
	case 42:{ LocalTypeValueGet< 42 >( out_value, in_data ); break; }
	case 43:{ LocalTypeValueGet< 43 >( out_value, in_data ); break; }
	case 44:{ LocalTypeValueGet< 44 >( out_value, in_data ); break; }
	case 45:{ LocalTypeValueGet< 45 >( out_value, in_data ); break; }
	case 46:{ LocalTypeValueGet< 46 >( out_value, in_data ); break; }
	case 47:{ LocalTypeValueGet< 47 >( out_value, in_data ); break; }
	case 48:{ LocalTypeValueGet< 48 >( out_value, in_data ); break; }
	case 49:{ LocalTypeValueGet< 49 >( out_value, in_data ); break; }
	case 50:{ LocalTypeValueGet< 50 >( out_value, in_data ); break; }
	case 51:{ LocalTypeValueGet< 51 >( out_value, in_data ); break; }
	case 52:{ LocalTypeValueGet< 52 >( out_value, in_data ); break; }
	case 53:{ LocalTypeValueGet< 53 >( out_value, in_data ); break; }
	case 54:{ LocalTypeValueGet< 54 >( out_value, in_data ); break; }
	case 55:{ LocalTypeValueGet< 55 >( out_value, in_data ); break; }
	case 56:{ LocalTypeValueGet< 56 >( out_value, in_data ); break; }
	case 57:{ LocalTypeValueGet< 57 >( out_value, in_data ); break; }
	case 58:{ LocalTypeValueGet< 58 >( out_value, in_data ); break; }
	case 59:{ LocalTypeValueGet< 59 >( out_value, in_data ); break; }
	}

	return;
}

/**/
static HVOID LocalBlockStart(
	HBufferParseLoadVisitorInterface& out_visitor,
	const HString& in_name,
	const HSINT in_depth,
	HSINT& in_out_skipToDepth,
	const HSINT in_cursor
	)
{
	if( in_depth < in_out_skipToDepth )
	{
		out_visitor.FoundBlockStart( in_name, in_cursor );

		if( HTRUE == out_visitor.SkipToEndBlock() )
		{
			in_out_skipToDepth = in_depth - 1;
		}
	}

	return;
}

/**/
static HVOID LocalBlockEnd(
	HBufferParseLoadVisitorInterface& out_visitor,
	const HSINT in_depth,
	HSINT& in_out_skipToDepth,
	const HSINT in_cursor
	)
{
	if( in_depth < in_out_skipToDepth )
	{
		out_visitor.FoundBlockEnd( in_cursor );

		if( HTRUE == out_visitor.SkipToEndBlock() )
		{
			in_out_skipToDepth = in_depth - 1;
		}
	}

	return;
}

/**/
static HVOID LocalValue(
	HBufferParseLoadVisitorInterface& out_visitor,
	const HString& in_name,
	const HString& in_type,
	const HString& in_data,
	const HSINT in_depth,
	HSINT& in_out_skipToDepth,
	const HSINT in_cursor
	)
{
	HString localName( in_name );
	if( HBufferParseTextVariables::NameGetDefaultBlock() == localName )
	{
		localName = HNULL;
	}
	if( in_depth < in_out_skipToDepth )
	{
		HBufferParseVariant value;
		LocalValueGet( value, in_type, in_data );
		out_visitor.FoundValue( localName, value, in_cursor );

		if( HTRUE == out_visitor.SkipToEndBlock() )
		{
			in_out_skipToDepth = in_depth - 1;
		}
	}

	return;
}

/**/
static HVOID LocalSubmitVisitorComment(
	const TiXmlComment& in_comment,
	HBufferParseLoadVisitorInterface& out_visitor,
	const HSINT in_depth,
	HSINT& in_out_skipToDepth
	)
{
	if( in_depth < in_out_skipToDepth )
	{
		out_visitor.FoundComment( in_comment.Value(), in_comment.Row() );

		if( HTRUE == out_visitor.SkipToEndBlock() )
		{
			in_out_skipToDepth = in_depth - 1;
		}
	}

	return;
}

/**/
static HVOID LocalSubmitVisitorElement(
	const TiXmlElement& in_element,
	HBufferParseLoadVisitorInterface& out_visitor,
	const HSINT in_depth,
	HSINT& in_out_skipToDepth
	);

/**/
static HVOID LocalSubmitVisitorNode(
	const TiXmlNode* const in_pNode,
	HBufferParseLoadVisitorInterface& out_visitor,
	const HSINT in_depth,
	HSINT& in_out_skipToDepth
	)
{
	if( HNULL == in_pNode )
	{
		return;
	}
	const TiXmlElement* pElement = in_pNode->ToElement();
	const TiXmlComment* pComment = in_pNode->ToComment();

	if( HNULL != pElement )
	{
		LocalSubmitVisitorElement(
			*pElement,
			out_visitor,
			in_depth,
			in_out_skipToDepth
			);
	}
	else if( HNULL != pComment )
	{
		LocalSubmitVisitorComment(
			*pComment,
			out_visitor,
			in_depth,
			in_out_skipToDepth
			);
	}

	return;
}

/**/
static HVOID LocalSubmitVisitorElement(
	const TiXmlElement& in_element,
	HBufferParseLoadVisitorInterface& out_visitor,
	const HSINT in_depth,
	HSINT& in_out_skipToDepth
	)
{
	const TiXmlNode* pChild = in_element.FirstChild();


	//an element is expected to be only have text child (a value)
	//else if( ( HNULL != pChild->ToText() ) &&
	//	( HNULL == pChild->NextSibling() ) )
	//if it is an empty array, then the child text could be missing, so use type attribute
	if( HNULL != in_element.Attribute( HBufferParseTextVariables::NameGetAttributeType() ) )
	{
		HString text;
		if( HNULL != pChild )
		{
			const TiXmlText* const pText = pChild->ToText();
			text = pText->Value();
		}
		LocalValue(
			out_visitor,
			in_element.Value(),
			in_element.Attribute( HBufferParseTextVariables::NameGetAttributeType() ),
			text,
			in_depth,
			in_out_skipToDepth,
			in_element.Row()
			);
	}
	//an element count 0. has no childrent, a empty block
	else if( HNULL == pChild )
	{
		LocalBlockStart(
			out_visitor,
			in_element.Value(),
			in_depth,
			in_out_skipToDepth,
			in_element.Row()
			);

		LocalBlockEnd(
			out_visitor,
			in_depth,
			in_out_skipToDepth,
			in_element.Row()
			);
	}
	//or an element could have multiple children
	else
	{
		LocalBlockStart(
			out_visitor,
			in_element.Value(),
			in_depth,
			in_out_skipToDepth,
			in_element.Row()
			);

		//iterate through the children nodes at +1 depth
		while( HNULL != pChild )
		{
			LocalSubmitVisitorNode(
				pChild,
				out_visitor,
				in_depth + 1,
				in_out_skipToDepth
				);
			pChild = pChild->NextSibling();
		}

		LocalBlockEnd(
			out_visitor,
			in_depth,
			in_out_skipToDepth,
			in_element.Row()
			);
	}

	return;
}

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HBufferParseLoadText::HBufferParseLoadText( const HBuffer& in_srcBuffer, const HSINT in_cursorStart ) :
	m_buffer( in_srcBuffer ),
	m_cursorStart( in_cursorStart )
{
	return;
}

/**/
Hubris::HBufferParseLoadText::~HBufferParseLoadText()
{
	
	return;
}

//////////////////////////////////////////
// HBufferParseLoad methods
/**/
HVOID Hubris::HBufferParseLoadText::SubmitVisitor( HBufferParseLoadVisitorInterface& out_visitor )const
{
	TiXmlDocument document;
	HTinyXmlUtility::TinyXmlFromBuffer( document, m_buffer );
	//document.Parse( ( const HCHAR* const )m_buffer.RawGet() );

	TiXmlHandle handle( &document );
	TiXmlNode* pRootChild = handle.FirstChild( HBufferParseTextVariables::NameGetDocumentRoot() ).FirstChild().Node();

	HSINT skipToDepth = HVariablesMath::MaximumGet< HSINT >();

	while( HNULL != pRootChild )
	{
		LocalSubmitVisitorNode(
			pRootChild,
			out_visitor,
			0,
			skipToDepth
			);

		pRootChild = pRootChild->NextSibling();
	}

	return;
}

/**/