//file: Vanity/VComponentLightEmitter/VComponentLightEmitter.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitter.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentLightEmitter::VComponentLightEmitter()
: m_arrayItemData()
{
	return;
}

/**/
VComponentLightEmitter::~VComponentLightEmitter()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentLightEmitter::OnAddItem(
	const TItemId in_itemId 
	)
{
	if( m_arrayItemData.SizeGet() <= in_itemId )
	{
		m_arrayItemData.SizeResize( in_itemId + 1 );
	}

	return;
}

/**/
HVOID VComponentLightEmitter::OnRemoveItem(
	const TItemId HCOMMON_UNUSED_VAR( in_itemId )
	)
{
	return;
}

/**/
Hubris::HVOID VComponentLightEmitter::LightGet(
	const TItemId in_itemId,
	Hubris::HSINT& out_mode,
	Pride::PColourRealRgb& out_diffuse,
	Hubris::HREAL& out_falloffExponent,
	Hubris::HREAL& out_radius
	)const
{
	const VComponentLightEmitterItemData& lightData = m_arrayItemData[ in_itemId ];
	out_mode = lightData.ModeGet();
	out_diffuse = lightData.DiffuseGet();
	out_falloffExponent = lightData.FalloffExponentGet();
	out_radius = lightData.RadiusGet();

	return;
}

/**/
Hubris::HVOID VComponentLightEmitter::LightSet( 
	const TItemId in_itemId,
	const Hubris::HSINT in_mode,
	const Pride::PColourRealRgb& in_diffuse,
	const Hubris::HREAL in_falloffExponent,
	const Hubris::HREAL in_radius
	)
{
	VComponentLightEmitterItemData& lightData = m_arrayItemData[ in_itemId ];
	lightData.ModeSet( in_mode );
	lightData.DiffuseSet( in_diffuse );
	lightData.FalloffExponentSet( in_falloffExponent );
	lightData.RadiusSet( in_radius );

	return;
}

/**/