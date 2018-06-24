//file: Hubris/HBufferParse/HBufferParseTextVariables.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseTextVariables.h"

#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HTrait/HTrait_Export.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// local static variables
/**/
static const HCHAR* const s_nameDocumentRoot = "DOCUMENT_ROOT";
static const HCHAR* const s_nameDefaultBlock = "HBPTV_BLOCK";
static const HCHAR* const s_nameAttributeType = "TYPE";

////////////////////////////////////////////////////
// public static methods
/**/
const HCHAR* const HBufferParseTextVariables::NameGetDocumentRoot()
{
	return s_nameDocumentRoot;
}

/**/
const HCHAR* const HBufferParseTextVariables::NameGetDefaultBlock()
{
	return s_nameDefaultBlock;
}

/**/
const HCHAR* const HBufferParseTextVariables::NameGetAttributeType()
{
	return s_nameAttributeType;
}

/*
const HBufferParseTextVariables::TArrayPairCharacterString& HBufferParseTextVariables::EscapeDataGet()
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
