//file: Vanity/VComponentLightEmitter/VComponentLightEmitterTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitterTrait.h"

#include "Vanity/VComponentLightEmitter/VComponentLightEmitter.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitterItemData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< HSINT, VComponentLightEmitterItemData >TPairSintEmitterData;
typedef Hubris::HContainerArray< TPairSintEmitterData >TArrayPairSintEmitterData;

///////////////////////////////////////////////////////////
// VComponentLightEmitter
/**/
HVOID Envy::EMementoTraitCollect< VComponentLightEmitter >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightEmitter& in_data )
{
	TArrayPairSintEmitterData arrayLights;
	const HSINT lightCount = in_data.m_arrayItemData.SizeGet();
	const VComponentLightEmitterItemData defaultItemData;
	for( HSINT index = 0; index < lightCount; ++index )
	{
		if( in_data.m_arrayItemData[ index ] == defaultItemData )
		{
			continue;
		}

		arrayLights.Insert( TPairSintEmitterData( index, in_data.m_arrayItemData[ index ] ) );
	}

	in_out_mementoCollect.MemberAdd( "lightCount", lightCount );
	in_out_mementoCollect.MemberAdd( "itemData", arrayLights );
	in_out_mementoCollect.MemberAdd( "m_colourAmbient", in_data.m_colourAmbient );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentLightEmitter >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightEmitter& out_data )
{
	TArrayPairSintEmitterData arrayLights;
	HSINT lightCount = 0;

	in_out_mementoAssign.MemberGet( "lightCount", lightCount );
	in_out_mementoAssign.MemberGet( "itemData", arrayLights );
	in_out_mementoAssign.MemberGet( "m_colourAmbient", out_data.m_colourAmbient );

	out_data.m_arrayItemData.SizeSet( lightCount );
	HCOMMON_FOR_EACH_CONST( pair, arrayLights, TArrayPairSintEmitterData )
	{
		out_data.m_arrayItemData[ pair.m_first ] = pair.m_second;
	}

	return;
}

///////////////////////////////////////////////////////////
// VComponentLightEmitterItemData
/**/
HVOID Envy::EMementoTraitCollect< VComponentLightEmitterItemData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightEmitterItemData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_mode", in_data.ModeGet() );
	in_out_mementoCollect.MemberAdd( "m_diffuse", in_data.DiffuseGet() );
	in_out_mementoCollect.MemberAdd( "m_falloffExponent", in_data.FalloffExponentGet() );
	in_out_mementoCollect.MemberAdd( "m_radius", in_data.RadiusGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentLightEmitterItemData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightEmitterItemData& out_data )
{
	HSINT mode = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_mode", mode );
	out_data.ModeSet( mode );

	PColourRealRgb diffuse;
	in_out_mementoAssign.MemberGet( "m_diffuse", diffuse );
	out_data.DiffuseSet( diffuse );

	HREAL falloffExponent = 0.0F;
	in_out_mementoAssign.MemberGet( "m_falloffExponent", falloffExponent );
	out_data.FalloffExponentSet( falloffExponent );

	HREAL radius = 0.0F;
	in_out_mementoAssign.MemberGet( "m_radius", radius );
	out_data.RadiusSet( radius );

	return;
}

/**/