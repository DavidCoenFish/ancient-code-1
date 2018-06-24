//file: Sloth/SComponent/SComponentSpriteFixedFontData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentSpriteFixedFontData.h"

#include "Sloth/SComponent/SComponentSprite.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// static local mathods
/**/
static HVOID LocalCharacterTransformGet(
	HMatrixR4& out_matrix,
	const HVectorS2& in_cursor,
	const HVectorR2& in_origin,
	const HREAL in_characterWidth,
	const HREAL in_characterHeight
	)
{
	out_matrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
	const HVectorR3 offset = HMatrixConstructor::HVectorR3Construct( 
		in_origin[ 0 ] + ( in_cursor[ 0 ] * in_characterWidth ), 
		in_origin[ 1 ] - ( in_cursor[ 1 ] * in_characterHeight ), 
		0.0F 
		);
	HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_matrix, offset );
	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SComponentSpriteFixedFontData::SComponentSpriteFixedFontData( const SComponentSpriteFixedFontData& in_src )
: m_leftToRight( HTRUE )
, m_origin()
, m_string()
, m_arraySpriteInstanceIndex()
{
	( *this ) = in_src;
	return;
}

/**/
SComponentSpriteFixedFontData::SComponentSpriteFixedFontData(
	const Hubris::HBOOL in_leftToRight,
	const Hubris::HVectorS2& in_origin
	)
: m_leftToRight( in_leftToRight )
, m_origin( in_origin )
, m_string()
, m_arraySpriteInstanceIndex()
{
	return;
}

/**/
SComponentSpriteFixedFontData::SComponentSpriteFixedFontData()
: m_leftToRight( HTRUE )
, m_origin()
, m_string()
, m_arraySpriteInstanceIndex()
{
	return;
}

/**/
SComponentSpriteFixedFontData::~SComponentSpriteFixedFontData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const SComponentSpriteFixedFontData& SComponentSpriteFixedFontData::operator=( const SComponentSpriteFixedFontData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_leftToRight = in_rhs.m_leftToRight;
		m_origin = in_rhs.m_origin;
		m_string = in_rhs.m_string;
		m_arraySpriteInstanceIndex = in_rhs.m_arraySpriteInstanceIndex;
	}
	return( *this );
}

/**/
const Hubris::HBOOL SComponentSpriteFixedFontData::operator==( const SComponentSpriteFixedFontData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_leftToRight == in_rhs.m_leftToRight );
		match &= ( m_origin == in_rhs.m_origin );
		match &= ( m_string == in_rhs.m_string );
		match &= ( m_arraySpriteInstanceIndex == in_rhs.m_arraySpriteInstanceIndex );
	}

	return match;
}

/**/
const Hubris::HBOOL SComponentSpriteFixedFontData::operator!=( const SComponentSpriteFixedFontData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentSpriteFixedFontData::TextSet(
	SComponentSprite& in_out_spriteManager,
	const TTreeSintSint& in_mapCharacterSpriteIndex,
	const Hubris::HString& in_text,
	const Hubris::HVectorR2& in_origin,
	const Hubris::HREAL in_characterWidth,
	const Hubris::HREAL in_characterHeight
	)
{
	HMatrixR4 matrix;

	TArraySint arrayOldSpriteInstanceIndex( m_arraySpriteInstanceIndex );
	m_arraySpriteInstanceIndex.SizeSet( in_text.SizeGet() );

	//populate new
	for( HSINT index = 0; index < in_text.SizeGet(); ++index )
	{
		const HSINT newCharacter = in_text[ index ];
		HSINT oldCharacter = HCOMMON_INVALID_INDEX;
		if( index < m_string.SizeGet() )
		{
			oldCharacter = m_string[ index ];
		}
		
		if( newCharacter == oldCharacter )
		{
			//match, save and keep going
			m_arraySpriteInstanceIndex[ index ] = arrayOldSpriteInstanceIndex[ index ];
			continue;
		}
		else if( index < m_string.SizeGet() )
		{
			//not a match, remove old sprite... better to not remove old but don't have a blank space sprite
			const HSINT spriteInstanceIndex = arrayOldSpriteInstanceIndex[ index ];
			if( HCOMMON_INVALID_INDEX != spriteInstanceIndex )
			{
				in_out_spriteManager.SpriteInstanceRemove( spriteInstanceIndex );
			}
		}

		//create new sprite
		const TTreeSintSint::TIterator iterator = in_mapCharacterSpriteIndex.Find( newCharacter );
		if( iterator == in_mapCharacterSpriteIndex.End() )
		{
			//no sprite found for character, continue
			m_arraySpriteInstanceIndex[ index ] = HCOMMON_INVALID_INDEX;
			continue;
		}

		HVectorS2 offset( m_origin );
		if( HTRUE == m_leftToRight )
		{
			offset += HMatrixConstructor::HVectorS2Construct( index, 0 );
		}
		else
		{
			offset -= HMatrixConstructor::HVectorS2Construct( index, 0 );
		}

		LocalCharacterTransformGet(
			matrix,
			offset,
			in_origin,
			in_characterWidth,
			in_characterHeight
			);

		const HSINT spriteInstanceIndex = in_out_spriteManager.SpriteInstanceCreate( 
			( *iterator ),
			matrix
			);
	
		m_arraySpriteInstanceIndex[ index ] = spriteInstanceIndex;
	}

	//use old text as data signature
	m_string = in_text;

	//trim old sprites
	for( HSINT index = m_arraySpriteInstanceIndex.SizeGet(); index < arrayOldSpriteInstanceIndex.SizeGet(); ++index )
	{
		const HSINT spriteInstanceIndex = arrayOldSpriteInstanceIndex[ index ];
		if( HCOMMON_INVALID_INDEX == spriteInstanceIndex )
		{
			continue;
		}
		in_out_spriteManager.SpriteInstanceRemove( spriteInstanceIndex );
	}

	return;
}

/**/
Hubris::HVOID SComponentSpriteFixedFontData::TextClear(
	SComponentSprite& in_out_spriteManager
	)
{
	HCOMMON_FOR_EACH_CONST( spriteInstanceIndex, m_arraySpriteInstanceIndex, TArraySint )
	{
		if( HCOMMON_INVALID_INDEX == spriteInstanceIndex )
		{
			continue;
		}
		in_out_spriteManager.SpriteInstanceRemove( spriteInstanceIndex );
	}
	m_arraySpriteInstanceIndex.Clear();
	m_string.Clear();

	return;
}

/**/
