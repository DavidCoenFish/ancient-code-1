//file: Vanity/VComponentLightEmitter/VComponentLightEmitterTrait.h
#ifndef _V_COMPONENT_LIGHT_EMITTER_TRAIT_H_
#define _V_COMPONENT_LIGHT_EMITTER_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentLightEmitter;
	class VComponentLightEmitterItemData;

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

	//VComponentLightEmitter
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightEmitter& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightEmitter& out_data );

	//VComponentLightEmitterItemData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightEmitterItemData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightEmitterItemData& out_data );

};

#endif // _V_COMPONENT_LIGHT_EMITTER_TRAIT_H_