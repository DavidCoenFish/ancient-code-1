//file: Hubris/HContainer/HContainerPairTrait.h
#ifndef _H_CONTAINER_PAIR_TRAIT_H_
#define _H_CONTAINER_PAIR_TRAIT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

namespace Hubris
{
	/////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_FIRST, typename IN_SECOND > class HContainerPair;
	template< typename IN_TYPE >struct HTraitName;

	/////////////////////////////////////////////////////////
	// type name HContainer Pair
	/**/
	template< typename IN_FIRST, typename IN_SECOND >										
	struct HTraitName< HContainerPair< IN_FIRST, IN_SECOND > >					
	{
		static const HString NameGet();
	private:			
		~HTraitName();								
	};	

	template< typename IN_FIRST, typename IN_SECOND >										
	const HString HTraitName< HContainerPair< IN_FIRST, IN_SECOND > >::NameGet(){ return( HString( "HPair" ) + "_" + HTraitName< IN_FIRST >::NameGet() + "_" + HTraitName< IN_SECOND >::NameGet() ); }

	/**/
};

#endif// _H_CONTAINER_PAIR_TRAIT_H_
