//file: Hubris/HTrait/HTraitStringOut.h
#ifndef _H_TRAIT_STRING_OUT_H_
#define _H_TRAIT_STRING_OUT_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	/////////////////////////////////////////////////////////////////
	// forward definitions
	/**/
	class HString;

	/////////////////////////////////////////////////////////////////
	// namespace functions
	/*
		if these are free functions, they can be extended latter? ie, there are types i don't know about yet

		would like to be symetrical with HTraitStringIn, but can not implicitly define template on return type
		symetry more importaint than saving some typing, changed back (also take the cost of pass by value on return)
	*/

	//get IN_TYPE value out of a string
	template< typename IN_TYPE >HVOID HTraitStringOut( IN_TYPE& out_value, const HString& in_string );
	template< typename IN_TYPE >HVOID HTraitStringOutHex( IN_TYPE& out_value, const HString& in_string );

	///////////////////////////////////////////////////////////
	// declarations
	/*
		get somethings out of a string
		out value moved into param to assist overloading on type
	*/
	template HVOID HTraitStringOut( HU8& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HS8& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HU16& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HS16& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HU32& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HS32& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HR32& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HR64& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HCHAR& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HBOOL& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HString& out_value, const HString& in_data );

	template HVOID HTraitStringOutHex( HU8& out_value, const HString& in_data );

	/**/
};

#endif // _H_TRAIT_STRING_OUT_H_

