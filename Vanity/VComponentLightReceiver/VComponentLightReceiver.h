//file: Vanity/VComponentLightReceiver/VComponentLightReceiver.h
#ifndef _V_COMPONENT_LIGHT_RECIEVER_H_
#define _V_COMPONENT_LIGHT_RECIEVER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentLightReceiver/VComponentLightReceiverItemData.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentLightReceiver;

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
	// specialise memento functions for hubris classes
	/**/

	//VScene
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightReceiver& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightReceiver& out_data );
};


namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentLightReceiver
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VComponentLightReceiver >( Envy::EMementoCollect& in_out_mementoCollect, const VComponentLightReceiver& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VComponentLightReceiver >( const Envy::EMementoAssign& in_out_mementoAssign, VComponentLightReceiver& out_data );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< VComponentLightReceiverItemData >TArrayItemData;
		typedef Hubris::HContainerArray< TItemId >TArrayItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentLightReceiver();
		~VComponentLightReceiver();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentLightReceiver( const VComponentLightReceiver& in_src );
		const VComponentLightReceiver& operator=( const VComponentLightReceiver& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const TItemId in_itemId 
			);

		Hubris::HVOID OnRemoveItem(
			const TItemId in_itemId 
			);

		/*
			policy, assert if in_itemId doesn't have a component of this type
		*/
		Hubris::HVOID DynamicLightAdd(
			const TItemId in_itemId,
			const TItemId in_lightItemId,
			const Hubris::HSINT in_frameId
			);

		//gather both static and dynaminc light ids
		Hubris::HVOID ArrayLightIdGather(
			const TItemId in_itemId,
			TArrayItemId& out_arrayLightsId
			)const;

		Hubris::HVOID ArrayLightIdStaticSet(
			const TItemId in_itemId,
			const TArrayItemId& in_arrayLightIdStatic
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayItemData m_arrayItemData;

	};

	/**/
	
};

#endif // _V_COMPONENT_LIGHT_RECIEVER_H_