//file: Vanity/VComponentVisual/VComponentVisualAssetParticleTypeData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticleTypeData.h"

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
VComponentVisualAssetParticleTypeData::VComponentVisualAssetParticleTypeData( const VComponentVisualAssetParticleTypeData& in_src )
: m_uvTopLeft()
, m_uvTopRight()
, m_uvBottomLeft()
, m_uvBottomRight()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentVisualAssetParticleTypeData::VComponentVisualAssetParticleTypeData(
	const Hubris::HVectorR2& in_uvTopLeft,
	const Hubris::HVectorR2& in_uvTopRight,
	const Hubris::HVectorR2& in_uvBottomLeft,
	const Hubris::HVectorR2& in_uvBottomRight
	)
: m_uvTopLeft( in_uvTopLeft )
, m_uvTopRight( in_uvTopRight )
, m_uvBottomLeft( in_uvBottomLeft )
, m_uvBottomRight( in_uvBottomRight )
{
	return;
}

/**/
VComponentVisualAssetParticleTypeData::VComponentVisualAssetParticleTypeData()
: m_uvTopLeft()
, m_uvTopRight()
, m_uvBottomLeft()
, m_uvBottomRight()
{
	return;
}

/**/
VComponentVisualAssetParticleTypeData::~VComponentVisualAssetParticleTypeData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentVisualAssetParticleTypeData& VComponentVisualAssetParticleTypeData::operator=( const VComponentVisualAssetParticleTypeData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_uvTopLeft = in_rhs.m_uvTopLeft;
		m_uvTopRight = in_rhs.m_uvTopRight;
		m_uvBottomLeft = in_rhs.m_uvBottomLeft;
		m_uvBottomRight = in_rhs.m_uvBottomRight;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VComponentVisualAssetParticleTypeData::operator==( const VComponentVisualAssetParticleTypeData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_uvTopLeft == in_rhs.m_uvTopLeft );
		match &= ( m_uvTopRight == in_rhs.m_uvTopRight );
		match &= ( m_uvBottomLeft == in_rhs.m_uvBottomLeft );
		match &= ( m_uvBottomRight == in_rhs.m_uvBottomRight );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentVisualAssetParticleTypeData::operator!=( const VComponentVisualAssetParticleTypeData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
