//file: Hubris/HTrait/HTraitStringIn.h
#ifndef _H_TRAIT_STRING_IN_H_
#define _H_TRAIT_STRING_IN_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	/////////////////////////////////////////////////////////////////
	// forward definitions
	/**/
	class HString;

	template< typename IN_TYPE >HString HTraitStringIn( const IN_TYPE& in_data );
	template< typename IN_TYPE >HString HTraitStringInHex( const IN_TYPE& in_data );

	///////////////////////////////////////////////////////////
	// declarations
	/*
		turn something into a string
	*/
	template HString HTraitStringIn( const HU8& in_data );
	template HString HTraitStringIn( const HS8& in_data );
	template HString HTraitStringIn( const HU16& in_data );
	template HString HTraitStringIn( const HS16& in_data );
	template HString HTraitStringIn( const HU32& in_data );
	template HString HTraitStringIn( const HS32& in_data );
	template HString HTraitStringIn( const HR32& in_data );
	template HString HTraitStringIn( const HR64& in_data );
	template HString HTraitStringIn( const HBOOL& in_data );
	template HString HTraitStringIn( const HCHAR& in_data );
	template HString HTraitStringIn( const HString& in_data );

	//template HString HTraitStringIn( const HVectorS2& in_data );
	//template HString HTraitStringIn( const HVectorS3& in_data );
	//template HString HTraitStringIn( const HVectorS4& in_data );
	//template HString HTraitStringIn( const HMatrixS2& in_data );
	//template HString HTraitStringIn( const HMatrixS3& in_data );
	//template HString HTraitStringIn( const HMatrixS4& in_data );

	//template HString HTraitStringIn( const HVectorR2& in_data );
	//template HString HTraitStringIn( const HVectorR3& in_data );
	//template HString HTraitStringIn( const HVectorR4& in_data );
	//template HString HTraitStringIn( const HMatrixR2& in_data );
	//template HString HTraitStringIn( const HMatrixR3& in_data );
	//template HString HTraitStringIn( const HMatrixR4& in_data );

	//return a hexidecimal string (without 0x prepend)
	template HString HTraitStringInHex( const HU8& in_data );
	/**/
};

#endif // _H_TRAIT_STRING_IN_H_

