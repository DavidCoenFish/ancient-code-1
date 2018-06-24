//file: Vanity/VComponentSoundEmitter/VComponentSoundEmitterItemData.h
#ifndef _V_COMPONENT_SOUND_EMITTER_ITEM_DATA_H_
#define _V_COMPONENT_SOUND_EMITTER_ITEM_DATA_H_

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
	class VComponentSoundEmitterItemData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentSoundEmitterItemData( const VComponentSoundEmitterItemData& in_src );
		VComponentSoundEmitterItemData();
		~VComponentSoundEmitterItemData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VComponentSoundEmitterItemData& operator=( const VComponentSoundEmitterItemData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentSoundEmitterItemData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentSoundEmitterItemData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private members
	private:
		//Hubris::HFileSystem m_soundResource; ? resourceId?


	};

	/**/
	
};

#endif // _V_COMPONENT_SOUND_EMITTER_H_