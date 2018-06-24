//file: Hubris/HBufferParse/HBufferParseVariant.h
#ifndef _H_BUFFER_PARSE_VARIANT_H_
#define _H_BUFFER_PARSE_VARIANT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HType/HTypeList.h"
#include "Hubris/HVariant/HVariant.h"

namespace Hubris
{
	///////////////////////////////////////////////////
	// pre defines
	/**/
	template< typename IN_TYPE >class HContainerArray;

	class HString;

	///////////////////////////////////////////////////
	// typedefs
	/*
		have some thoughts to do away with this, but makes it difficult to get values out on load if just templated 

		//let us not nativly support arrays in parse
		// or, just support base types, and arrays of base types, vector is not a base type...

		ok, support base types ONLY, no arrays, no vectors. they can be constructed out of multiple items of the base types...
	*/
	typedef HTYPE_LIST_21( 
		HBOOL,
		HU8, 
		HS8, 
		HU16,
		HS16,
		HU32,
		HS32,
		HR32,
		HR64,
		HCHAR,

		HString,

		HContainerArray< HBOOL >,
		HContainerArray< HU8 >,
		HContainerArray< HS8 >,
		HContainerArray< HU16 >,
		HContainerArray< HS16 >,
		HContainerArray< HU32 >,
		HContainerArray< HS32 >,
		HContainerArray< HR32 >,
		HContainerArray< HR64 >,
		HContainerArray< HCHAR >

		// bring back string when we can safely save out a string array as text
		//HContainerArray< HString >

	) HBufferParseVariantTypeList;

	/**/
	HVARIANT_DEFINITION( HBufferParseVariant, HBufferParseVariantTypeList );

	/**/
};

#endif// _H_BUFFER_PARSE_VARIANT_H_
