//file: Vanity/VComponentSoundReceiver/VComponentSoundReceiver.h
#ifndef _V_COMPONENT_SOUND_RECIEVER_H_
#define _V_COMPONENT_SOUND_RECIEVER_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	struct VComponentSoundReceiverRenderParam;
	class VComponentSoundReceiverCamera;
	class VInterfaceRenderTarget;
	class VImageHDR;
	class VComponentSoundReceiverItemData;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentSoundReceiver
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentSoundReceiverItemData >TArrayItemData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentSoundReceiver();
		~VComponentSoundReceiver();


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
		VComponentSoundReceiver( const VComponentSoundReceiver& in_src );
		const VComponentSoundReceiver& operator=( const VComponentSoundReceiver& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayItemData m_arrayItemData;

	};

	/**/
	
};

#endif // _V_COMPONENT_SOUND_RECIEVER_H_