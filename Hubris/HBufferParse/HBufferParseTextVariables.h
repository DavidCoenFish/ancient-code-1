//file: Hubris/HBufferParse/HBufferParseTextVariables.h
#ifndef _H_BUFFER_PARSE_TEXT_VARIABLES_H_
#define _H_BUFFER_PARSE_TEXT_VARIABLES_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	////////////////////////////////////////////////////
	// forward declaration
	/**/
	class HString;
	template< typename IN_TYPE >class HContainerArray;
	template< typename IN_FIRST, typename IN_SECOND >class HContainerPair;

	////////////////////////////////////////////////////
	// struct
	/**/
	struct HBufferParseTextVariables
	{
		////////////////////////////////////////////////////
		// typedef
	private:
		typedef HContainerPair< HCHAR, HString >TPairCharacterString;
		typedef HContainerArray< TPairCharacterString >TArrayPairCharacterString;

		////////////////////////////////////////////////////
		// disabled
	private:
		~HBufferParseTextVariables();

		////////////////////////////////////////////////////
		// public static methods
	public:
		static const HCHAR* const NameGetDocumentRoot();
		static const HCHAR* const NameGetDefaultBlock();
		static const HCHAR* const NameGetAttributeType();

		//static const TArrayPairCharacterString& EscapeDataGet();

	};

	/**/
};

#endif// _H_BUFFER_PARSE_TEXT_VARIABLES_H_
