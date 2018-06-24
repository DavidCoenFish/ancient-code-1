//file: Sloth/SComponent/SComponentSpriteFixedFont.h
#ifndef _S_COMPONENT_SPRITE_FIXED_FONT_H_
#define _S_COMPONENT_SPRITE_FIXED_FONT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SComponentSprite;
	class SComponentSpriteFixedFontImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentSpriteFixedFont
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HSINT >TPairSintSint;
		typedef Hubris::HContainerArray< TPairSintSint >TArrayPairSintSint;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentSpriteFixedFont(
			const TArrayPairSintSint& in_arrayCharacterValueSpriteIndex,
			const Hubris::HVectorR2& in_origin,
			const Hubris::HREAL in_characterWidth,
			const Hubris::HREAL in_characterHeight
			//todo. also take matrix to put text into 3d space?
			);
		~SComponentSpriteFixedFont();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentSpriteFixedFont( const SComponentSpriteFixedFont& in_src );
		const SComponentSpriteFixedFont& operator=( const SComponentSpriteFixedFont& in_rhs );

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
		// private accessors
	private:
		const SComponentSpriteFixedFontImplementation& ImplementationGet()const;
		SComponentSpriteFixedFontImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SComponentSpriteFixedFontImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_COMPONENT_SPRITE_FIXED_FONT_H_