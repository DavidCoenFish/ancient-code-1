//file: Hubris/HContainer/HContainerArrayTrait.h
#ifndef _H_CONTAINER_ARRAY_TRAIT_H_
#define _H_CONTAINER_ARRAY_TRAIT_H_

#include "Hubris/HCommon/HCommonType.h"

#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

/**/
namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;
	template< typename IN_TYPE >struct HTraitName;

	/////////////////////////////////////////////////////////
	// type name HContainer Array
	/**/
	template< typename IN_TYPE >										
	struct HTraitName< HContainerArray< IN_TYPE > >					
	{
		static HString NameGet();
	private:			
		~HTraitName();								
	};	

	template< typename IN_TYPE >										
	HString HTraitName< HContainerArray< IN_TYPE > >::NameGet(){ return HString( "HArray_" ) + HTraitName< IN_TYPE >::NameGet(); }


	/////////////////////////////////////////////////////////////////
	// string in
	/**/
	/////////////////////////////////////////////////////////////////
	// global HTraitStringIn
	/**/
	template< typename IN_TYPE >
	HString HTraitStringIn( const HContainerArray< IN_TYPE >& in_data )
	{
		HString returnString;
		HBOOL first = HTRUE;
		HCOMMON_FOR_EACH_CONST( data, in_data, HContainerArray< IN_TYPE > )
		{
			if( HFALSE == first )
			{
				returnString += HVariablesString::CommaGet();
				returnString += HVariablesString::SpaceGet();
			}
			first = HFALSE;

			returnString += HTraitStringIn( data );
		}

		return returnString;
	}

	/////////////////////////////////////////////////////////////////
	// global HTraitStringOut
	/**/
	template< typename IN_TYPE >
	HVOID HTraitStringOut( HContainerArray< IN_TYPE >& out_data, const HString& in_string )
	{
		typedef HContainerArray< HString >TArrayString;
		typedef HContainerArray< IN_TYPE >::TType SUB_TYPE;
		TArrayString arrayString;
		HStringUtility::Split( in_string, HVariablesString::CommaGet(), arrayString );
		HCOMMON_FOR_EACH_CONST( string, arrayString, TArrayString )
		{
			SUB_TYPE value;
			HTraitStringOut< SUB_TYPE >( value, string );

			HContainerUtility::PushBack( out_data, value );
		}

		return;
	}

};

#endif// _H_CONTAINER_ARRAY_TRAIT_H_
