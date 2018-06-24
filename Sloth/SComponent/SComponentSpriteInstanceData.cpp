//file: Sloth/SComponent/SComponentSpriteInstanceData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentSpriteInstanceData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentSpriteInstanceData::SComponentSpriteInstanceData( const SComponentSpriteInstanceData& in_src )
: m_spriteIndex( HCOMMON_INVALID_INDEX )
//, m_sortHint( 0 )
, m_alphaOverride( 1.0F )
, m_matrix()
, m_visible( HFALSE )
{
	( *this ) = in_src;
	return;
}

/**/
SComponentSpriteInstanceData::SComponentSpriteInstanceData(
	const Hubris::HSINT in_spriteIndex,
	//const Hubris::HSINT in_sortHint,
	const Hubris::HREAL in_alphaOverride,
	const Hubris::HMatrixR4& in_matrix,
	const Hubris::HBOOL in_visible
	)
: m_spriteIndex( in_spriteIndex )
//, m_sortHint( in_sortHint )
, m_alphaOverride( in_alphaOverride )
, m_matrix( in_matrix )
, m_visible( in_visible )
{
	return;
}

/**/
SComponentSpriteInstanceData::SComponentSpriteInstanceData()
: m_spriteIndex( HCOMMON_INVALID_INDEX )
//, m_sortHint( 0 )
, m_alphaOverride( 1.0F )
, m_matrix()
, m_visible( HFALSE )
{
	return;
}

/**/
SComponentSpriteInstanceData::~SComponentSpriteInstanceData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const SComponentSpriteInstanceData& SComponentSpriteInstanceData::operator=( const SComponentSpriteInstanceData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_spriteIndex = in_rhs.m_spriteIndex;
		//m_sortHint = in_rhs.m_sortHint;
		m_alphaOverride = in_rhs.m_alphaOverride;
		m_matrix = in_rhs.m_matrix;
		m_visible = in_rhs.m_visible;
	}

	return( *this );
}

/**/
const Hubris::HBOOL SComponentSpriteInstanceData::operator==( const SComponentSpriteInstanceData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_spriteIndex == in_rhs.m_spriteIndex );
		//match &= ( m_sortHint == in_rhs.m_sortHint );
		match &= ( m_alphaOverride == in_rhs.m_alphaOverride );
		match &= ( m_matrix == in_rhs.m_matrix );
		match &= ( m_visible == in_rhs.m_visible );
	}

	return match;
}

/**/
const Hubris::HBOOL SComponentSpriteInstanceData::operator!=( const SComponentSpriteInstanceData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}
/**/
