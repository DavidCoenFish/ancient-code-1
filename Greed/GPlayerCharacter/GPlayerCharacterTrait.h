//file: Greed/GPlayerCharacter/GPlayerCharacterTrait.h
#ifndef _G_PLAYER_CHARACTER_TRAIT_H_
#define _G_PLAYER_CHARACTER_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GPlayerCharacter;

};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//GPlayerCharacter
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Greed::GPlayerCharacter& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Greed::GPlayerCharacter& out_data );

};

#endif // _G_PLAYER_CHARACTER_TRAIT_H_