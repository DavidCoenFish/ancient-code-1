//file: Hubris/HType/HTypeListTrait.h
#ifndef _H_TYPE_LIST_TRAIT_H_
#define _H_TYPE_LIST_TRAIT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HTrait/HTraitName.h"

/**/
namespace Hubris
{
	template< class IN_CLASS_A, class IN_CLASS_B > class HTypeList;

	/////////////////////////////////////////////////////////
	// HTraitName
	/**/
	template< class IN_CLASS_A, class IN_CLASS_B >										
	struct HTraitName< HTypeList< IN_CLASS_A, IN_CLASS_B > >					
	{
		const static HString NameGet();
	private:			
		~HTraitName();								
	};	

	template< class IN_CLASS_A, class IN_CLASS_B >										
	const HString HTraitName< HTypeList< IN_CLASS_A, IN_CLASS_B > >::NameGet(){ return HTraitName< IN_CLASS_B >::NameGet() + HString( "_" ) + HTraitName< IN_CLASS_A >::NameGet(); }

	/**/
	template< class IN_CLASS_A >										
	struct HTraitName< HTypeList< IN_CLASS_A, HTypeNone > >					
	{
		static const HString NameGet();
	private:			
		~HTraitName();								
	};	

	template< class IN_CLASS_A >										
	const HString HTraitName< HTypeList< IN_CLASS_A, HTypeNone > >::NameGet(){ return HString( "HTypeList_" ) + HTraitName< IN_CLASS_A >::NameGet(); }

};

#endif // _H_TYPE_LIST_TYPE_TRAIT_H_