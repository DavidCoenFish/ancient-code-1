//file: Vanity/VComponentDynamic/VComponentDynamicInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentDynamic/VComponentDynamicInterfaceObject.h"

#include "Vanity/VComponentDynamic/VComponentDynamic.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentDynamicInterfaceObject::VComponentDynamicInterfaceObject(
	VComponentDynamic& in_componentDynamic,
	VScene& in_scene
	)
: m_componentDynamic( in_componentDynamic )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentDynamicInterfaceObject::~VComponentDynamicInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentDynamicInterfaceObject::StartNewFrame()
{
	m_componentDynamic.StartNewFrame();
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::DefaultParamSet(
	const VComponentDynamicComponentParam& in_param
	)
{
	m_componentDynamic.DefaultParamSet(
		in_param
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemParamGet(
	const TItemId in_itemId,
	VComponentDynamicComponentParam& out_param,
	Hubris::HREAL& out_invertMass //zero if item doesn't move
	)
{
	m_componentDynamic.ItemParamGet(
		in_itemId,
		out_param,
		out_invertMass
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemParamSet(
	const TItemId in_itemId,
	const VComponentDynamicComponentParam& in_param,
	const Hubris::HREAL in_invertMass //zero if item doesn't move
	)
{
	m_componentDynamic.ItemParamSet(
		in_itemId,
		in_param,
		in_invertMass
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::CreateDynamicStatic(
	const TItemId in_itemId,
	const VComponentDynamicComponentParam& in_param
	)
{
	m_componentDynamic.CreateDynamicStatic( 
		in_itemId,
		in_param
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::CreateDynamicSimple(
	const TItemId in_itemId,
	const VComponentDynamicComponentParam& in_param,
	const Hubris::HREAL in_massInvert
	)
{
	m_componentDynamic.CreateDynamicSimple( 
		in_itemId,
		in_param,
		in_massInvert
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemApplyTranslateForce(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_force
	)
{
	m_componentDynamic.ItemApplyTranslateForce( 
		in_itemId,
		in_force
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemApplyTranslateForce(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_force,
	const Hubris::HVectorR3& in_position
	)
{
	m_componentDynamic.ItemApplyTranslateForce( 
		in_itemId,
		in_force,
		in_position
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemApplyRotateForce(
	const TItemId in_itemId,
	const Pride::PUnitVectorR3& in_axis,
	const Hubris::HREAL in_magnitude
	)
{
	m_componentDynamic.ItemApplyRotateForce( 
		in_itemId,
		in_axis,
		in_magnitude
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemTranslateTeleport(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_newPosition
	)
{
	m_componentDynamic.ItemTranslateTeleport( 
		in_itemId,
		in_newPosition
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemTranslateSweep(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_newPosition
	)
{
	m_componentDynamic.ItemTranslateSweep( 
		in_itemId,
		in_newPosition
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ResolveMovement(
	const Sloth::SComponentDelta& in_delta
	)
{
	m_componentDynamic.ResolveMovement( 
		in_delta,
		m_scene
		);
	return;
}

/**/
Hubris::HVOID VComponentDynamicInterfaceObject::ItemDataGet(
	const TItemId in_itemId,
	TArrayContactData* const out_pArrayContactData,
	Hubris::HVectorR3* const out_pVelocity,
	Pride::PUnitVectorR3* const out_pRotationAxis,
	Hubris::HREAL* const out_pRotationMagnitude
	)const
{
	m_componentDynamic.ItemDataGet( 
		in_itemId,
		out_pArrayContactData,
		out_pVelocity,
		out_pRotationAxis,
		out_pRotationMagnitude
		);
	return;
}

/**/
