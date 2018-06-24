//file: Sloth/SComponent/SComponentSpriteFixedFontImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentSpriteFixedFontImplementation.h"

#include "Sloth/SComponent/SComponentSpriteImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentSpriteFixedFontImplementation::SComponentSpriteFixedFontImplementation(
	const TArrayPairSintSint& in_arrayCharacterValueSpriteIndex,
	const Hubris::HVectorR2& in_origin,
	const Hubris::HREAL in_characterWidth,
	const Hubris::HREAL in_characterHeight
	)
: m_mapCaracterSprite()
, m_origin( in_origin )
, m_characterWidth( in_characterWidth )
, m_characterHeight( in_characterHeight )
, m_arrayData()
, m_arrayDataResourceIdManager()
{
	HCOMMON_FOR_EACH_CONST( pair, in_arrayCharacterValueSpriteIndex, TArrayPairSintSint )
	{
		m_mapCaracterSprite.Insert( pair.m_first, pair.m_second );
	}
	return;
}

/**/
SComponentSpriteFixedFontImplementation::~SComponentSpriteFixedFontImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT SComponentSpriteFixedFontImplementation::TextAdd( 
	SComponentSprite& in_out_spriteManager,
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_cursor,
	const Hubris::HBOOL m_leftToRight
	)
{
	const HSINT index = m_arrayDataResourceIdManager.ResourceIdAcquire();

	if( m_arrayData.SizeGet() <= index )
	{
		m_arrayData.SizeResize( index + 1 );
	}

	m_arrayData[ index ] = SComponentSpriteFixedFontData( m_leftToRight, in_cursor );

	m_arrayData[ index ].TextSet( 
		in_out_spriteManager,
		m_mapCaracterSprite,
		in_text,
		m_origin,
		m_characterWidth,
		m_characterHeight
		);

	return index;
}

/**/
Hubris::HVOID SComponentSpriteFixedFontImplementation::TextChange( 
	SComponentSprite& in_out_spriteManager,
	const Hubris::HSINT in_textIndex,
	const Hubris::HString& in_text
	)
{
	m_arrayData[ in_textIndex ].TextSet(
		in_out_spriteManager,
		m_mapCaracterSprite,
		in_text,
		m_origin,
		m_characterWidth,
		m_characterHeight
		);

	return;
}

/**/
Hubris::HVOID SComponentSpriteFixedFontImplementation::TextRemove( 
	SComponentSprite& in_out_spriteManager,
	const Hubris::HSINT in_textIndex
	)
{
	m_arrayData[ in_textIndex ].TextClear( in_out_spriteManager );
	m_arrayDataResourceIdManager.ResourceIdRelease( in_textIndex );
	return;
}

/**/
Hubris::HVOID SComponentSpriteFixedFontImplementation::TextRemoveAll(
	SComponentSprite& in_out_spriteManager			
	)
{
	HCOMMON_FOR_EACH( data, m_arrayData, TArrayData )
	{
		data.TextClear( in_out_spriteManager );
	}

	m_arrayData.Clear();
	m_arrayDataResourceIdManager.Clear();

	return;
}

/**/
