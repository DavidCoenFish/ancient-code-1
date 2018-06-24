//file: Vanity/VComponentLightReceiver/VComponentLightReceiverItemData.h
#ifndef _V_COMPONENT_LIGHT_RECIEVER_ITEM_DATA_H_
#define _V_COMPONENT_LIGHT_RECIEVER_ITEM_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
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
	// specialise memento functions for hubris classes
	/**/

	//VScene
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightReceiverItemData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightReceiverItemData& out_data );
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
	class VComponentLightReceiverItemData
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VComponentLightReceiverItemData >( Envy::EMementoCollect& in_out_mementoCollect, const VComponentLightReceiverItemData& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VComponentLightReceiverItemData >( const Envy::EMementoAssign& in_out_mementoAssign, VComponentLightReceiverItemData& out_data );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< TItemId >TArrayItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentLightReceiverItemData( const VComponentLightReceiverItemData& in_src );
		VComponentLightReceiverItemData();
		~VComponentLightReceiverItemData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VComponentLightReceiverItemData& operator=( const VComponentLightReceiverItemData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentLightReceiverItemData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentLightReceiverItemData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DynamicLightAdd(
			const TItemId in_lightItemId,
			const Hubris::HSINT in_frameId
			);

		//gather both static and dynaminc light ids
		Hubris::HVOID ArrayLightIdGather(
			TArrayItemId& out_arrayLightsId
			)const;

		Hubris::HVOID ArrayLightIdStaticSet(
			const TArrayItemId& in_arrayLightIdStatic
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		//the array of lights that are not moving which touch this object (empty if this object moves)
		TArrayItemId m_arrayLightIdStatic; 

		//the array of dynamic lights touching this object this frame
		Hubris::HSINT m_frameId;
		TArrayItemId m_arrayLightIdDynamic; 

	};

	/**/
	
};

#endif // _V_COMPONENT_LIGHT_RECIEVER_H_