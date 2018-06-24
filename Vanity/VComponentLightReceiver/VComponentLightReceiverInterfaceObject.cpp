//file: Vanity/VComponentLightReceiver/VComponentLightReceiverInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightReceiver/VComponentLightReceiverInterfaceObject.h"

#include "Vanity/VComponentLightReceiver/VComponentLightReceiver.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentLightReceiverInterfaceObject::VComponentLightReceiverInterfaceObject(
	VComponentLightReceiver& in_componentLight,
	VScene& in_scene
	)
: m_componentLight( in_componentLight )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentLightReceiverInterfaceObject::~VComponentLightReceiverInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentLightReceiverInterfaceObject::DynamicLightAdd(
	const TItemId in_itemId,
	const TItemId in_lightItemId,
	const Hubris::HSINT in_frameId
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentLightReceiverGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentLight.DynamicLightAdd(
		in_itemId,
		in_lightItemId,
		in_frameId
		);

	return;
}

/**/
Hubris::HVOID VComponentLightReceiverInterfaceObject::ArrayLightIdGather(
	const TItemId in_itemId,
	TArrayItemId& out_arrayLightsId
	)const
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentLightReceiverGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentLight.ArrayLightIdGather(
		in_itemId,
		out_arrayLightsId
		);

	return;
}

/**/
Hubris::HVOID VComponentLightReceiverInterfaceObject::ArrayLightIdStaticSet(
	const TItemId in_itemId,
	const TArrayItemId& in_arrayLightIdStatic
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentLightReceiverGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentLight.ArrayLightIdStaticSet(
		in_itemId,
		in_arrayLightIdStatic
		);

	return;
}

/**/
