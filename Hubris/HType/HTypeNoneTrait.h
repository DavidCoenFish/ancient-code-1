//file: Hubris/HType/HTypeNoneTrait.h
#ifndef _H_TYPE_NONE_TRAIT_H_
#define _H_TYPE_NONE_TRAIT_H_

#include "Hubris/HTrait/HTraitEmpty.h"
#include "Hubris/HTrait/HTraitName.h"

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////
	// forward definitions
	/**/
	class HTypeNone;

	///////////////////////////////////////////////////////
	// HTraitEmpty
	/**/
	HTRAIT_EMPTY_HEADER( HTypeNone );

	///////////////////////////////////////////////////////
	// HTraitName
	/**/
	HTYPE_NAME_HEADER( HTypeNone );

	/////////////////////////////////////////////////////////////////
	// global HTraitStringIn
	/**/
	template< typename IN_TYPE >HString HTraitStringIn( const IN_TYPE& in_data );

	template HString HTraitStringIn( const HTypeNone& in_data );

	/////////////////////////////////////////////////////////////////
	// global HTraitStringOut
	/**/
	template< typename IN_TYPE >HVOID HTraitStringOut( IN_TYPE& out_value, const HString& in_string );

	template HVOID HTraitStringOut( HTypeNone& out_value, const HString& in_data );

	/**/
};

#endif // _H_TYPE_NONE_TRAIT_H_