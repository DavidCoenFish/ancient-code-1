//file: Vanity/VComponentSoundReceiver/VComponentSoundReceiverInterfaceObject.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentSoundReceiver/VComponentSoundReceiverInterfaceObject.h"

#include "Vanity/VComponentSoundReceiver/VComponentSoundReceiver.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentSoundReceiverInterfaceObject::VComponentSoundReceiverInterfaceObject(
	VComponentSoundReceiver& in_componentLight,
	VScene& in_scene
	)
: m_componentLight( in_componentLight )
, m_scene( in_scene )
{
	return;
}

/**/
VComponentSoundReceiverInterfaceObject::~VComponentSoundReceiverInterfaceObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
