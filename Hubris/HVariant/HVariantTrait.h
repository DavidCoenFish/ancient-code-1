//file: Hubris/HVariant/HVariantTrait.h
#ifndef _H_VARIANT_TRAIT_H_
#define _H_VARIANT_TRAIT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HTrait/HTraitName.h"
#include "Hubris/HType/HTypeListTrait.h"

/**/
namespace Hubris
{
	template< class IN_TYPE_LIST >class HVariantImplementation;

	/**/
	/////////////////////////////////////////////////////////
	// type name variant

	/**/
	template< typename IN_TYPE_LIST >										
	struct HTraitName< HVariantImplementation< IN_TYPE_LIST > >					
	{
		static const HString NameGet();
	private:			
		~HTraitName();								
	};	

	/**/
	template< typename IN_TYPE_LIST >										
	const HString HTraitName< HVariantImplementation< IN_TYPE_LIST > >::NameGet(){ return HString( "HVariant_" + HTraitName< IN_TYPE_LIST >::NameGet() ); }

	/**/

};

#endif // _H_VARIANT_TRAIT_H_