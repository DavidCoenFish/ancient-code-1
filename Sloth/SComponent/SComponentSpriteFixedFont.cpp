//file: Sloth/SComponent/SComponentSpriteFixedFont.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentSpriteFixedFont.h"

#include "Sloth/SComponent/SComponentSpriteFixedFontImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentSpriteFixedFont::SComponentSpriteFixedFont(
	const TArrayPairSintSint& in_arrayCharacterValueSpriteIndex,
	const Hubris::HVectorR2& in_origin,
	const Hubris::HREAL in_characterWidth,
	const Hubris::HREAL in_characterHeight
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM_4(
		m_pImplementation,
		SComponentSpriteFixedFontImplementation,
		in_arrayCharacterValueSpriteIndex,
		in_origin,
		in_characterWidth,
		in_characterHeight
		);

	return;
}

/**/
SComponentSpriteFixedFont::~SComponentSpriteFixedFont()
{
	HCOMMON_DELETE( m_pImplementation, SComponentSpriteFixedFontImplementation );
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT SComponentSpriteFixedFont::TextAdd( 
	SComponentSprite& in_out_spriteManager,
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_cursor,
	const Hubris::HBOOL m_leftToRight
	)
{
	const HSINT index = ImplementationGet().TextAdd(
		in_out_spriteManager,
		in_text,
		in_cursor,
		m_leftToRight
		);
	return index;
}

/**/
Hubris::HVOID SComponentSpriteFixedFont::TextChange( 
	SComponentSprite& in_out_spriteManager,
	const Hubris::HSINT in_textIndex,
	const Hubris::HString& in_text
	)
{
	ImplementationGet().TextChange(
		in_out_spriteManager,
		in_textIndex,
		in_text
		);
	return;
}

/**/
Hubris::HVOID SComponentSpriteFixedFont::TextRemove( 
	SComponentSprite& in_out_spriteManager,
	const Hubris::HSINT in_textIndex
	)
{
	ImplementationGet().TextRemove(
		in_out_spriteManager,
		in_textIndex
		);
	return;
}

/**/
Hubris::HVOID SComponentSpriteFixedFont::TextRemoveAll(
	SComponentSprite& in_out_spriteManager			
	)
{
	ImplementationGet().TextRemoveAll(
		in_out_spriteManager
		);
	return;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SComponentSpriteFixedFontImplementation& SComponentSpriteFixedFont::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
SComponentSpriteFixedFontImplementation& SComponentSpriteFixedFont::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
