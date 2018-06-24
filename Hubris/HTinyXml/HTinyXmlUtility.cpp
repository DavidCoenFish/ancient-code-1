//file: Hubris/HTinyXml/HTinyXmlUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HTinyXml/HTinyXmlUtility.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HTrait/HTrait_Export.h"

#include< tinyxml.h >

/*
xml print code has been sourced from tinyxml

www.sourceforge.net/projects/tinyxml
Original code (2.0 and earlier )copyright (c) 2000-2002 Lee Thomason (www.grinninglizard.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

/////////////////////////////////////////////////////////////////
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
static const HCHAR* const s_textEndOfLine = "\n";
static const HCHAR* const s_textTab = "\t";

static const HCHAR s_arrayXmlReservedChar[] = {
	'<',
	'>',
	'&',
	'#',
	'\'',
	'\"',
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
	25,
	26,
	27,
	28,
	29,
	30,
	31
};

static const HSINT s_arrayXmlReservedCharCount = HCOMMON_ARRAY_SIZE( s_arrayXmlReservedChar );

///////////////////////////////////////////////////////////
// local static methods
/**/
const TArrayPairCharacterString& LocalEscapeDataGet()
{
	static TArrayPairCharacterString s_data;
	if( 0 == s_data.SizeGet() )
	{
		for( HSINT index = 0; index < s_arrayXmlReservedCharCount; ++index )
		{
			TPairCharacterString data;
			data.m_first = s_arrayXmlReservedChar[ index ];
			data.m_second = "&#x" + HStringUtility::PadLeft( HTraitStringInHex( HU8( s_arrayXmlReservedChar[ index ] ) ), 2, '0' ) + ";";

			s_data.Insert( data );
			//TPairCharacterString( s_arrayXmlReservedChar[ index ], "&#x" + HStringUtility::PadLeft( s_arrayXmlReservedChar[ index ], 2, '0' ) + ";" ) );
		}
	}

	return s_data;
}

/**/
static HVOID LocalElementPrint( 
	HBuffer& in_out_buffer,
	const TiXmlElement& in_data,
	const HSINT in_depth
	);
static HVOID LocalDocumentPrint(
	HBuffer& in_out_buffer,
	const TiXmlDocument& in_data,
	const HSINT in_depth
	);
static HVOID LocalAttributePrint(
	HBuffer& in_out_buffer,
	const TiXmlAttribute& in_data
	);
static HVOID LocalCommentPrint(
	HBuffer& in_out_buffer,
	const TiXmlComment& in_data,
	const HSINT in_depth
	);
static HVOID LocalTextPrint(
	HBuffer& in_out_buffer,
	const TiXmlText& in_data
	);
static HVOID LocalDeclarationPrint(
	HBuffer& in_out_buffer,
	const TiXmlDeclaration& in_data,
	const HSINT in_depth
	);
static HVOID LocalUnknownPrint(
	HBuffer& in_out_buffer,
	const TiXmlUnknown& in_data,
	const HSINT in_depth
	);

/**/
static HVOID LocalPrintNode(
	HBuffer& in_out_buffer,
	const TiXmlNode& in_node,
	const HSINT in_depth
	)
{
	//attempt upcast
	const TiXmlDocument* pDocument = in_node.ToDocument();
	const TiXmlElement* pElement = in_node.ToElement();
	const TiXmlComment* pComment = in_node.ToComment();
	const TiXmlUnknown* pUnknown = in_node.ToUnknown() ;
	const TiXmlText* pText = in_node.ToText();
	const TiXmlDeclaration* pDeclaration = in_node.ToDeclaration();
	if( HNULL != pDocument )
	{
		LocalDocumentPrint(
			in_out_buffer,
			*pDocument,
			in_depth
			);
	}
	if( HNULL != pElement )
	{
		LocalElementPrint(
			in_out_buffer,
			*pElement,
			in_depth
			);
	}
	if( HNULL != pComment )
	{
		LocalCommentPrint(
			in_out_buffer,
			*pComment,
			in_depth
			);
	}
	if( HNULL != pUnknown )
	{
		LocalUnknownPrint(
			in_out_buffer,
			*pUnknown,
			in_depth
			);
	}
	if( HNULL != pText )
	{
		LocalTextPrint(
			in_out_buffer,
			*pText
			);
	}
	if( HNULL != pDeclaration )
	{
		LocalDeclarationPrint(
			in_out_buffer,
			*pDeclaration,
			in_depth
			);
	}

	HBufferUtility::TextAppend( in_out_buffer, s_textEndOfLine );
	return;
}

/**/
static HVOID LocalDepthPrint(
	HBuffer& in_out_buffer,
	const HSINT in_depth
	)
{
	for( HSINT index = 0; index < in_depth; index++ )
	{
		HBufferUtility::TextAppend( in_out_buffer, s_textTab );
	}

	return;
}

/**/
static const HBOOL LocalIsEscapeString( 
	HString& in_out_outPutString, 
	const HString& in_inputString, 
	HSINT& in_out_index
	)
{
	const HString testString = HStringUtility::SubString( in_inputString, in_out_index, 3 );
	if( testString == "&#x" )
	{
		in_out_outPutString += "&#x";
		in_out_index += 3;

		//keep going to end or ';'
		while( in_out_index < in_inputString.SizeGet() )
		{
			const HCHAR value = in_inputString[ in_out_index ];
			in_out_index += 1;
			in_out_outPutString += value;
			if( value == ';' )
			{
				break;
			}
		}

		return HTRUE;
	}

	return HFALSE;
}

/**/
static const HBOOL LocalEscapeChar( 
	HString& in_out_outPutString, 
	const HString& in_inputString, 
	HSINT& in_out_index, 
	const TArrayPairCharacterString& in_escapeData 
	)
{
	const HCHAR value = in_inputString[ in_out_index ];
	HCOMMON_FOR_EACH_CONST( pair, in_escapeData, TArrayPairCharacterString )
	{
		if( value == pair.m_first )
		{
			in_out_outPutString += pair.m_second;
			in_out_index += 1;
			return HTRUE;
		}
	}

	return HFALSE;
}

/**/
static const HString LocalXmlEncodeString( 
	const HString& in_string
	)
{
	HString returnString;

	const TArrayPairCharacterString& escapeData = LocalEscapeDataGet();

	HSINT index = 0;
	while( index < in_string.SizeGet() )
	{
		const HCHAR c = in_string[ index ];

		//if we find an escaped string, skip it
		if( HTRUE == LocalIsEscapeString( returnString, in_string, index ) )
		{
			//NOP
		}
		//if we find a char to escape, escape it
		else if( HTRUE == LocalEscapeChar( returnString, in_string, index, escapeData ) )
		{
			//NOP
		}
		//else add char
		else
		{
			returnString += c;
			index += 1;
		}

	}

	return returnString;
}

/**/
static HVOID LocalElementPrint( 
	HBuffer& in_out_buffer,
	const TiXmlElement& in_data,
	const HSINT in_depth
	)
{
	LocalDepthPrint( in_out_buffer, in_depth );

	HBufferUtility::TextAppend( in_out_buffer, HString( "<" ) + in_data.Value() );

	for( const TiXmlAttribute* attrib = in_data.FirstAttribute(); HNULL != attrib; attrib = attrib->Next() )
	{
		LocalAttributePrint(
			in_out_buffer,
			*attrib
			);
	}

	// There are 3 different formatting approaches:
	// 1) An element without children is printed as a <foo /> node
	// 2) An element with only a text child is printed as <foo> text </foo>
	// 3) An element with children is printed on multiple lines.
	const TiXmlNode* pChild = in_data.FirstChild();
	if( HNULL == pChild )
	{
		HBufferUtility::TextAppend( in_out_buffer, "/>" );
	}
	else if( ( HNULL == pChild->NextSibling() ) &&
		( HNULL != pChild->ToText() ) )
	{
		HBufferUtility::TextAppend( in_out_buffer, ">" );
		LocalTextPrint( in_out_buffer, *( pChild->ToText() ) );
		HBufferUtility::TextAppend( in_out_buffer, HString( "</" ) + in_data.Value() + ">" );
	}
	else
	{
		HBufferUtility::TextAppend( in_out_buffer, ">" );
		HBufferUtility::TextAppend( in_out_buffer, s_textEndOfLine );

		while( HNULL != pChild )
		{
			LocalPrintNode( in_out_buffer, *pChild, in_depth + 1 );
			pChild = pChild->NextSibling();
		}

		LocalDepthPrint( in_out_buffer, in_depth );
		HBufferUtility::TextAppend( in_out_buffer, HString( "</" ) + in_data.Value() + ">" );
	}

	return;
}

/**/
static HVOID LocalDocumentPrint(
	HBuffer& in_out_buffer,
	const TiXmlDocument& in_data,
	const HSINT in_depth
	)
{
	for( const TiXmlNode* pNode = in_data.FirstChild(); HNULL != pNode; pNode = pNode->NextSibling() )
	{
		LocalPrintNode(
			in_out_buffer,
			*pNode,
			in_depth
			);
	}

	return;
}

/**/
static HVOID LocalAttributePrint(
	HBuffer& in_out_buffer,
	const TiXmlAttribute& in_data
	)
{
	const HString name = LocalXmlEncodeString( in_data.Name() );
	HString value = LocalXmlEncodeString( in_data.Value() );

	if( HCOMMON_INVALID_INDEX == HStringUtility::FindFirst( value, '\"' ) )
	{
		value = '\"' + value + '\"';
	}
	else
	{
		value = '\'' + value + '\'';
	}

	HBufferUtility::TextAppend(
		in_out_buffer,
		" " + name + "=" + value
		);

	return;
}

/**/
static HVOID LocalCommentPrint(
	HBuffer& in_out_buffer,
	const TiXmlComment& in_data,
	const HSINT in_depth
	)
{
	LocalDepthPrint(
		in_out_buffer,
		in_depth
		);
	HBufferUtility::TextAppend(
		in_out_buffer,
		HString( "<!--" ) + in_data.Value() + "-->"
		);
	return;
}

/**/
static HVOID LocalTextPrint(
	HBuffer& in_out_buffer,
	const TiXmlText& in_data
	)
{
	const HString encodedString = LocalXmlEncodeString( in_data.Value() );
	HBufferUtility::TextAppend(
		in_out_buffer,
		encodedString
		);
}

/**/
static HVOID LocalDeclarationPrint(
	HBuffer& in_out_buffer,
	const TiXmlDeclaration& in_data,
	const HSINT
	)
{
	HBufferUtility::TextAppend( in_out_buffer, "<?xml " );

	const HString version = in_data.Version();
	const HString encoding = in_data.Encoding();
	const HString standalone = in_data.Standalone();

	if ( HNULL != version )
	{
		HBufferUtility::TextAppend( in_out_buffer, "version=\"" + version + "\" " );
	}

	if ( HNULL != encoding )
	{
		HBufferUtility::TextAppend( in_out_buffer, "encoding=\"" + encoding + "\" " );
	}

	if ( HNULL != standalone )
	{
		HBufferUtility::TextAppend( in_out_buffer, "standalone=\"" + standalone + "\" " );
	}

	HBufferUtility::TextAppend( in_out_buffer, "?>" );

	return;
}

/**/
static HVOID LocalUnknownPrint(
	HBuffer& in_out_buffer,
	const TiXmlUnknown& in_data,
	const HSINT in_depth
	)
{
	LocalDepthPrint(
		in_out_buffer,
		in_depth
		);
	HBufferUtility::TextAppend(
		in_out_buffer,
		HString( "<" ) + in_data.Value() + ">"
		);
	return;
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
const HBOOL HTinyXmlUtility::TinyXmlFromBuffer( TiXmlDocument& out_tinyXml, const HBuffer& in_buffer )
{
	out_tinyXml.Parse( ( const HCHAR* const )in_buffer.RawGet() );
	return HTRUE;
}

/**/
const HBOOL HTinyXmlUtility::TinyXmlToBuffer( HBuffer& out_buffer, TiXmlDocument& in_tinyXml )
{
	LocalPrintNode(
		out_buffer,
		in_tinyXml,
		0
		);

	return HTRUE;
}

/**/