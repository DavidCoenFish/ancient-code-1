//file: Hubris/HBufferParse/HBufferParseVariantTrait.h
#ifndef _H_BUFFER_PARSE_VARIANT_TRAIT_H_
#define _H_BUFFER_PARSE_VARIANT_TRAIT_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	class HBufferParseVariant;
	class HString;

	////////////////////////////////////////////////////////////
	// HTraitName
	/**/
	template< typename IN_TYPE >struct HTraitName;										 

	template<>
	struct HTraitName< HBufferParseVariant >
	{
		static const HString NameGet();
	};

	/**/
};

#endif// _H_BUFFER_PARSE_VARIANT_TRAIT_H_
