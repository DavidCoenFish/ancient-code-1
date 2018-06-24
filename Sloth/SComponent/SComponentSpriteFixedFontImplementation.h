//file: Sloth/SComponent/SComponentSpriteFixedFontImplementation.h
#ifndef _S_COMPONENT_SPRITE_FIXED_FONT_IMPLEMENTATION_H_
#define _S_COMPONENT_SPRITE_FIXED_FONT_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SComponent/SComponentSpriteFixedFontData.h"
#include< Envy/EResourceIdManager/EResourceIdManager.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		doh, sprite manager could have been better name 
	*/
	class SComponentSpriteFixedFontImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HSINT >TPairSintSint;
		typedef Hubris::HContainerArray< TPairSintSint >TArrayPairSintSint;
		typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HSINT >TTreeSintSint;
		typedef Hubris::HContainerArray< SComponentSpriteFixedFontData >TArrayData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentSpriteFixedFontImplementation(
			const TArrayPairSintSint& in_arrayCharacterValueSpriteIndex,
			const Hubris::HVectorR2& in_origin,
			const Hubris::HREAL in_characterWidth,
			const Hubris::HREAL in_characterHeight
			);
		~SComponentSpriteFixedFontImplementation();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentSpriteFixedFontImplementation( const SComponentSpriteFixedFontImplementation& in_src );
		const SComponentSpriteFixedFontImplementation& operator=( const SComponentSpriteFixedFontImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT TextAdd( 
			SComponentSprite& in_out_spriteManager,
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_cursor,
			const Hubris::HBOOL m_leftToRight = HTRUE
			);

		Hubris::HVOID TextChange( 
			SComponentSprite& in_out_spriteManager,
			const Hubris::HSINT in_textIndex,
			const Hubris::HString& in_text
			);
		Hubris::HVOID TextRemove( 
			SComponentSprite& in_out_spriteManager,
			const Hubris::HSINT in_textIndex
			);
		Hubris::HVOID TextRemoveAll(
			SComponentSprite& in_out_spriteManager			
			);	

		///////////////////////////////////////////////////////
		// private members
	private:
		TTreeSintSint m_mapCaracterSprite;
		const Hubris::HVectorR2 m_origin;
		const Hubris::HREAL m_characterWidth;
		const Hubris::HREAL m_characterHeight;
		TArrayData m_arrayData;
		Envy::EResourceIdManager m_arrayDataResourceIdManager;

	};

	/**/
	
};

#endif // _S_COMPONENT_SPRITE_FIXED_FONT_IMPLEMENTATION_H_