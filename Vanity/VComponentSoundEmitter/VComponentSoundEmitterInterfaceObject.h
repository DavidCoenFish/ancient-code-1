//file: Vanity/VComponentSoundEmitter/VComponentSoundEmitterInterfaceObject.h
#ifndef _V_COMPONENT_SOUND_EMITTER_INTERFACE_OBJECT_H_
#define _V_COMPONENT_SOUND_EMITTER_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VComponentSoundEmitter;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentSoundEmitterInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< Pride::PUnitVectorR3, Pride::PColourRealRgb >TPairDirectionColour;
		typedef Hubris::HContainerArray< TPairDirectionColour >TArrayPairDirectionColour;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentSoundEmitterInterfaceObject(
			VComponentSoundEmitter& in_componentLight,
			VScene& in_scene
			);
		~VComponentSoundEmitterInterfaceObject();

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentSoundEmitterInterfaceObject( const VComponentSoundEmitterInterfaceObject& in_src );
		const VComponentSoundEmitterInterfaceObject& operator=( const VComponentSoundEmitterInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentSoundEmitter& m_componentLight;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_SOUND_EMITTER_INTERFACE_OBJECT_H_