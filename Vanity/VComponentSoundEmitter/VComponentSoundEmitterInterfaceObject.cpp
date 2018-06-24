//file: Vanity/VComponentSoundEmitter/VComponentSoundEmitterInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentSoundEmitter/VComponentSoundEmitterInterfaceObject.h"

#include "Vanity/VComponentSoundEmitter/VComponentSoundEmitter.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentSoundEmitterInterfaceObject::VComponentSoundEmitterInterfaceObject(
	VComponentSoundEmitter& in_componentLight,
	VScene& in_scene
	)
: m_componentLight( in_componentLight )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentSoundEmitterInterfaceObject::~VComponentSoundEmitterInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
