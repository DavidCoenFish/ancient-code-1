//file: Vanity/VComponentVisual/VComponentVisualAssetParticleData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticleData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualAssetParticleData::VComponentVisualAssetParticleData( const VComponentVisualAssetParticleData& in_src )
: m_position()
, m_vectorUp()
, m_vectorRight()
, m_size( 0.0F )
, m_colour()
, m_typeIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
VComponentVisualAssetParticleData::VComponentVisualAssetParticleData(
	const Hubris::HVectorR3& in_position,
	const Hubris::HVectorR3& in_vectorUp,
	const Hubris::HVectorR3& in_vectorRight,
	const Hubris::HREAL in_size,
	const Pride::PColourRgba& in_colour,
	const Hubris::HSINT in_typeIndex
	)
: m_position( in_position )
, m_vectorUp( in_vectorUp )
, m_vectorRight( in_vectorRight )
, m_size( in_size )
, m_colour( in_colour )
, m_typeIndex( in_typeIndex )
{
	return;
}

/**/
VComponentVisualAssetParticleData::VComponentVisualAssetParticleData()
: m_position()
, m_vectorUp()
, m_vectorRight()
, m_size( 0.0F )
, m_colour()
, m_typeIndex( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
VComponentVisualAssetParticleData::~VComponentVisualAssetParticleData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentVisualAssetParticleData& VComponentVisualAssetParticleData::operator=( const VComponentVisualAssetParticleData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_position = in_rhs.m_position;
		m_vectorUp = in_rhs.m_vectorUp;
		m_vectorRight = in_rhs.m_vectorRight;
		m_size = in_rhs.m_size;
		m_colour = in_rhs.m_colour;
		m_typeIndex = in_rhs.m_typeIndex;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VComponentVisualAssetParticleData::operator==( const VComponentVisualAssetParticleData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_position == in_rhs.m_position );
		match &= ( m_vectorUp == in_rhs.m_vectorUp );
		match &= ( m_vectorRight == in_rhs.m_vectorRight );
		match &= ( m_size == in_rhs.m_size );
		match &= ( m_colour == in_rhs.m_colour );
		match &= ( m_typeIndex == in_rhs.m_typeIndex );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentVisualAssetParticleData::operator!=( const VComponentVisualAssetParticleData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
