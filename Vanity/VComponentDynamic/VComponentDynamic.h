//file: Vanity/VComponentDynamic/VComponentDynamic.h
#ifndef _V_COMPONENT_DYNAMIC_H_
#define _V_COMPONENT_DYNAMIC_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VComponentDynamic/VComponentDynamicDataBase.h"
#include "Vanity/VComponentDynamic/VComponentDynamicComponentParam.h"

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
	struct VComponentDynamicRenderParam;
	class VComponentDynamicCamera;
	class VInterfaceRenderTarget;
	class VImageHDR;
	class VComponentDynamicItemData;

	///////////////////////////////////////////////////////
	// class
	/*
		is the dynamic component responcible for just resolving movement (but then wat happens after collision)
		or does it collect forces on objects they apply

		DynamicStatic
			a fake dynamic object, no movement but can have different to default param (elastic dampen)
	*/
	class VComponentDynamic
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HSmartPointer< VComponentDynamicDataBase >TPointerData;
		typedef Hubris::HContainerArray< TPointerData >TArrayPointerData;
		typedef Hubris::HContainerArray< VComponentDynamicContactData >TArrayContactData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentDynamic();
		~VComponentDynamic();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentDynamic( const VComponentDynamic& in_src );
		const VComponentDynamic& operator=( const VComponentDynamic& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const Hubris::HSINT in_itemIndex 
			);

		Hubris::HVOID OnRemoveItem(
			const Hubris::HSINT in_itemIndex 
			);

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
			const Sloth::SComponentDelta& in_delta,
			VScene& in_scene
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
		// public accessors
	public:
		const TArrayPointerData& ArrayPointerDataGet()const{ return m_arrayData; }
		TArrayPointerData& ArrayPointerDataGet(){ return m_arrayData; }

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const VComponentDynamicDataBase* const DataBaseGet(
			const TItemId in_itemId
			)const; 
		VComponentDynamicDataBase* const DataBaseGet(
			const TItemId in_itemId
			); 

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayPointerData m_arrayData;
		VComponentDynamicComponentParam m_componentParam;

		//going to need a component to deal with movement of dynamic objects could intersect other dynamic objects moving
		//VComponentDynamic m_pComponentDynamicMovementOverlap;
		//then deal with movement of each remaining dynamic object over the static world

	};

	/**/
	
};

#endif // _V_COMPONENT_DYNAMIC_H_