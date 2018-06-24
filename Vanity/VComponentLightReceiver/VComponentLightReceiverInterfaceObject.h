//file: Vanity/VComponentLightReceiver/VComponentLightReceiverInterfaceObject.h
#ifndef _V_COMPONENT_LIGHT_RECIEVER_INTERFACE_OBJECT_H_
#define _V_COMPONENT_LIGHT_RECIEVER_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VComponentLightReceiver;

	///////////////////////////////////////////////////////
	// class
	/*
		this is a helper class to interface with the data inside a VScene component
	*/
	class VComponentLightReceiverInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< TItemId >TArrayItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentLightReceiverInterfaceObject(
			VComponentLightReceiver& in_componentLight,
			VScene& in_scene
			);
		~VComponentLightReceiverInterfaceObject();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentLightReceiverInterfaceObject( const VComponentLightReceiverInterfaceObject& in_src );
		const VComponentLightReceiverInterfaceObject& operator=( const VComponentLightReceiverInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
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
		VComponentLightReceiver& m_componentLight;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_LIGHT_RECIEVER_INTERFACE_OBJECT_H_