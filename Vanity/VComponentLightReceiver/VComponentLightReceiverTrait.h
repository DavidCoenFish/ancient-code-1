//file: Vanity/VComponentLightReceiver/VComponentLightReceiverTrait.h
#ifndef _V_COMPONENT_LIGHT_RECIEVER_TRAIT_H_
#define _V_COMPONENT_LIGHT_RECIEVER_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentLightReceiver;
	class VComponentLightReceiverItemData;

};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions
	/**/

	//VComponentLightReceiver
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightReceiver& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightReceiver& out_data );

	//VComponentLightReceiverItemData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightReceiverItemData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightReceiverItemData& out_data );

};

#endif // _V_COMPONENT_LIGHT_RECIEVER_TRAIT_H_