//file: Vanity/VComponentSoundReceiver/VComponentSoundReceiverItemData.h
#ifndef _V_COMPONENT_SOUND_RECIEVER_ITEM_DATA_H_
#define _V_COMPONENT_SOUND_RECIEVER_ITEM_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentSoundReceiverItemData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentSoundReceiverItemData( const VComponentSoundReceiverItemData& in_src );
		VComponentSoundReceiverItemData();
		~VComponentSoundReceiverItemData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VComponentSoundReceiverItemData& operator=( const VComponentSoundReceiverItemData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentSoundReceiverItemData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentSoundReceiverItemData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_frameId; //the frame this object has valid data for, 


	};

	/**/
	
};

#endif // _V_COMPONENT_SOUND_RECIEVER_H_