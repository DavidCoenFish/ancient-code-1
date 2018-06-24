//file: Vanity/VComponentSoundReceiver/VComponentSoundReceiverInterfaceObject.h
#ifndef _V_COMPONENT_SOUND_RECIEVER_INTERFACE_OBJECT_H_
#define _V_COMPONENT_SOUND_RECIEVER_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VComponentSoundReceiver;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentSoundReceiverInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< Pride::PUnitVectorR3, Pride::PColourRealRgb >TPairDirectionColour;
		typedef Hubris::HContainerArray< TPairDirectionColour >TArrayPairDirectionColour;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentSoundReceiverInterfaceObject(
			VComponentSoundReceiver& in_componentLight,
			VScene& in_scene
			);
		~VComponentSoundReceiverInterfaceObject();

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentSoundReceiverInterfaceObject( const VComponentSoundReceiverInterfaceObject& in_src );
		const VComponentSoundReceiverInterfaceObject& operator=( const VComponentSoundReceiverInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentSoundReceiver& m_componentLight;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_SOUND_RECIEVER_INTERFACE_OBJECT_H_