//file: Vanity/VComponentDynamic/VComponentDynamicInterfaceObject.h
#ifndef _V_COMPONENT_DYNAMIC_INTERFACE_OBJECT_H_
#define _V_COMPONENT_DYNAMIC_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	class SComponentDelta;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VComponentDynamic;
	class VComponentDynamicContactData;
	class VComponentDynamicComponentParam;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentDynamicInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< VComponentDynamicContactData >TArrayContactData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentDynamicInterfaceObject(
			VComponentDynamic& in_componentLight,
			VScene& in_scene
			);
		~VComponentDynamicInterfaceObject();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentDynamicInterfaceObject( const VComponentDynamicInterfaceObject& in_src );
		const VComponentDynamicInterfaceObject& operator=( const VComponentDynamicInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID StartNewFrame();

		//set the default param for the component
		Hubris::HVOID DefaultParamSet(
			const VComponentDynamicComponentParam& in_param
			);

		//return the component defaults if item not found
		Hubris::HVOID ItemParamGet(
			const TItemId in_itemId,
			VComponentDynamicComponentParam& out_param,
			Hubris::HREAL& out_invertMass //zero if item doesn't move
			);

		Hubris::HVOID ItemParamSet(
			const TItemId in_itemId,
			const VComponentDynamicComponentParam& in_param,
			const Hubris::HREAL in_invertMass //zero if item doesn't move
			);

		//static object with non default param
		Hubris::HVOID CreateDynamicStatic(
			const TItemId in_itemId,
			const VComponentDynamicComponentParam& in_param
			);

		//object with non default friction, which can move, just use sphere around item, ignores rotation
		Hubris::HVOID CreateDynamicSimple(
			const TItemId in_itemId,
			const VComponentDynamicComponentParam& in_param,
			const Hubris::HREAL in_massInvert
			);

		Hubris::HVOID ItemApplyTranslateForce(
			const TItemId in_itemId,
			const Hubris::HVectorR3& in_force
			);
		Hubris::HVOID ItemApplyTranslateForce(
			const TItemId in_itemId,
			const Hubris::HVectorR3& in_force,
			const Hubris::HVectorR3& in_position
			);
		Hubris::HVOID ItemApplyRotateForce(
			const TItemId in_itemId,
			const Pride::PUnitVectorR3& in_axis,
			const Hubris::HREAL in_magnitude
			);

		//insert an object at location, try to move things out of way
		Hubris::HVOID ItemTranslateTeleport(
			const TItemId in_itemId,
			const Hubris::HVectorR3& in_newPosition
			);
		//sweep an object to a location, try to move things out of the way
		Hubris::HVOID ItemTranslateSweep(
			const TItemId in_itemId,
			const Hubris::HVectorR3& in_newPosition
			);

		Hubris::HVOID ResolveMovement(
			const Sloth::SComponentDelta& in_delta
			);

		//get list of objects we are touching, collision normals?
		Hubris::HVOID ItemDataGet(
			const TItemId in_itemId,
			TArrayContactData* const out_pArrayContactData = HNULL,
			Hubris::HVectorR3* const out_pVelocity = HNULL,
			Pride::PUnitVectorR3* const out_pRotationAxis = HNULL,
			Hubris::HREAL* const out_pRotationMagnitude = HNULL
			)const;

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentDynamic& m_componentDynamic;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_DYNAMIC_INTERFACE_OBJECT_H_