//file: Hubris/HContainer/HContainerTreeTrait.h
#ifndef _H_CONTAINER_TREE_TRAIT_H_
#define _H_CONTAINER_TREE_TRAIT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

/**/
namespace Hubris
{
	/////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_KEY, typename IN_DATA, typename IN_SORT >class HContainerTree;
	template< typename IN_TYPE >struct HTraitName;

	/////////////////////////////////////////////////////////
	// HTraitName
	/**/
	template< typename IN_KEY, typename IN_DATA, typename IN_SORT >		
	struct HTraitName< HContainerTree< IN_KEY, IN_DATA, IN_SORT > >					
	{
		static const HString NameGet();
	private:			
		~HTraitName();								
	};	

	template< typename IN_KEY, typename IN_DATA, typename IN_SORT >										
	const HString HTraitName< HContainerTree< IN_KEY, IN_DATA, IN_SORT > >::NameGet(){ return HString( "HTree_" ) + HTraitName< IN_KEY >::NameGet() + "_" + HTraitName< IN_DATA >::NameGet() + "_" + IN_SORT::NameGet(); }

};

#endif// _H_CONTAINER_TREE_TRAIT_H_
