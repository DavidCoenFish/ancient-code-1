//file: Vanity/VComponentSoundEmitter/VComponentSoundEmitter.h
#ifndef _V_COMPONENT_SOUND_EMITTER_H_
#define _V_COMPONENT_SOUND_EMITTER_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	struct VComponentSoundEmitterRenderParam;
	class VComponentSoundEmitterCamera;
	class VInterfaceRenderTarget;
	class VImageHDR;
	class VComponentSoundEmitterItemData;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentSoundEmitter
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentSoundEmitterItemData >TArrayItemData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentSoundEmitter();
		~VComponentSoundEmitter();

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const Hubris::HSINT in_itemIndex 
			);

		Hubris::HVOID OnRemoveItem(
			const Hubris::HSINT in_itemIndex 
			);

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentSoundEmitter( const VComponentSoundEmitter& in_src );
		const VComponentSoundEmitter& operator=( const VComponentSoundEmitter& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayItemData m_arrayItemData;

	};

	/**/
	
};

#endif // _V_COMPONENT_SOUND_EMITTER_H_