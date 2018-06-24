//file: Vanity/VComponentForce/VComponentForceInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentForce/VComponentForceInterfaceObject.h"

#include "Vanity/VComponentForce/VComponentForce.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentForceInterfaceObject::VComponentForceInterfaceObject(
	VComponentForce& in_componentForce,
	VScene& in_scene
	)
: m_componentForce( in_componentForce )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentForceInterfaceObject::~VComponentForceInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentForceInterfaceObject::ForceBoundCreate(
	const TItemId in_itemId,
	const Hubris::HSINT in_forceFlag,
	const Hubris::HSINT in_boundFlag,
	const Pride::PBoundsR3& in_bounds,
	const Hubris::HVectorR3& in_vector
	)
{
	m_componentForce.ForceBoundCreate(
		in_itemId,
		in_forceFlag,
		in_boundFlag,
		in_bounds,
		in_vector
		);
	return;
}

/**/
Hubris::HVOID VComponentForceInterfaceObject::ForceSphereCreate(
	const TItemId in_itemId,
	const Hubris::HSINT in_forceFlag,
	const Hubris::HSINT in_sphereFlag,
	const Hubris::HVectorR3& in_vector,
	const Hubris::HREAL in_magnitude
	)
{
	m_componentForce.ForceSphereCreate(
		in_itemId,
		in_forceFlag,
		in_sphereFlag,
		in_vector,
		in_magnitude
		);
	return;
}

/**/
Hubris::HVOID VComponentForceInterfaceObject::SampleForce(
	Hubris::HVectorR3& in_out_forceSum,
	//Pride::PAxisAngle* const in_out_pRotation,
	const VComponentForceSampleParam& in_param,
	VScene& in_scene,
	const TItemId in_itemId
	)const
{
	m_componentForce.SampleForce(
		in_out_forceSum,
		in_param,
		in_scene,
		in_itemId
		);
	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HVectorR3& VComponentForceInterfaceObject::GravitationalAccellerationGet()const
{
	return m_componentForce.GravitationalAccellerationGet();
}

/**/
Hubris::HVectorR3& VComponentForceInterfaceObject::GravitationalAccellerationGet()
{
	return m_componentForce.GravitationalAccellerationGet();
}

/**/
