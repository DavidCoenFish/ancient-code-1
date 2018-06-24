//file: Sloth/SComponent/SComponentSpriteFixedFontData.h
#ifndef _S_COMPONENT_SPRITE_FIXED_FONT_DATA_H_
#define _S_COMPONENT_SPRITE_FIXED_FONT_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	class PGeometry;
};

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SComponentSprite;

	///////////////////////////////////////////////////////
	// class
	/*
		doh, sprite manager could have been better name 
	*/
	class SComponentSpriteFixedFontData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HSINT >TTreeSintSint;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentSpriteFixedFontData( const SComponentSpriteFixedFontData& in_src );
		SComponentSpriteFixedFontData(
			const Hubris::HBOOL in_leftToRight,
			const Hubris::HVectorS2& in_origin
			);
		SComponentSpriteFixedFontData();
		~SComponentSpriteFixedFontData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const SComponentSpriteFixedFontData& operator=( const SComponentSpriteFixedFontData& in_rhs );
		const Hubris::HBOOL operator==( const SComponentSpriteFixedFontData& in_rhs )const;
		const Hubris::HBOOL operator!=( const SComponentSpriteFixedFontData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID TextSet(
			SComponentSprite& in_out_spriteManager,
			const TTreeSintSint& in_mapCharacterSpriteIndex,
			const Hubris::HString& in_text,
			const Hubris::HVectorR2& in_origin,
			const Hubris::HREAL in_characterWidth,
			const Hubris::HREAL in_characterHeight
			);

		Hubris::HVOID TextClear(
			SComponentSprite& in_out_spriteManager
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HBOOL m_leftToRight;
		Hubris::HVectorS2 m_origin;
		Hubris::HString m_string;
		TArraySint m_arraySpriteInstanceIndex;

	};

	/**/
	
};

#endif // _S_COMPONENT_SPRITE_FIXED_FONT_DATA_H_