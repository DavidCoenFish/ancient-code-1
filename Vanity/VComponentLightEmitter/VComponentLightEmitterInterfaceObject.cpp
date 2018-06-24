//file: Vanity/VComponentLightEmitter/VComponentLightEmitterInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitterInterfaceObject.h"

#include "Vanity/VComponentLightEmitter/VComponentLightEmitter.h"

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
VComponentLightEmitterInterfaceObject::VComponentLightEmitterInterfaceObject(
	VComponentLightEmitter& in_componentLight,
	VScene& in_scene
	)
: m_componentLight( in_componentLight )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentLightEmitterInterfaceObject::~VComponentLightEmitterInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentLightEmitterInterfaceObject::LightGet(
	const TItemId in_itemId,
	Hubris::HSINT& out_mode,
	Pride::PColourRealRgb& out_diffuse,
	Hubris::HREAL& out_falloffExponent,
	Hubris::HREAL& out_radius
	)const
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentLightEmitterGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentLight.LightGet( 
		in_itemId,
		out_mode,
		out_diffuse,
		out_falloffExponent,
		out_radius
		);

	return;
}

/**/
Hubris::HVOID VComponentLightEmitterInterfaceObject::LightSet( 
	const TItemId in_itemId,
	const Hubris::HSINT in_mode,
	const Pride::PColourRealRgb& in_diffuse,
	const Hubris::HREAL in_falloffExponent,
	const Hubris::HREAL in_radius
	)
{
	HCOMMON_ASSERT( 0 != ( VScene::FlagComponentLightEmitterGet() & m_scene.ItemObjectFlagGet( in_itemId ) ), "invalid data access" );

	m_componentLight.LightSet( 
		in_itemId,
		in_mode,
		in_diffuse,
		in_falloffExponent,
		in_radius
		);

	return;
}

/**/
const Pride::PColourRealRgb& VComponentLightEmitterInterfaceObject::ColourAmbientGet()const
{
	return m_componentLight.ColourAmbientGet();
}

/**/
Hubris::HVOID VComponentLightEmitterInterfaceObject::ColourAmbientSet( const Pride::PColourRealRgb& in_colourAmbient )
{
	m_componentLight.ColourAmbientSet( in_colourAmbient );
	return;
}

/**/