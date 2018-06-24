//file: Vanity/VScene/VSceneUtilityHelperRender.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneUtilityHelperRender.h"

#include "Vanity/VScene/VScene.h"
#include "Vanity/VScene/VSceneApplicationInterface.h"
#include "Vanity/VScene/VSceneUtility.h"

#include "Vanity/VComponentVisual/VComponentVisual_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< SLight >TArrayLight;

///////////////////////////////////////////////////////
// creation
/**/
VSceneUtilityHelperRender::VSceneUtilityHelperRender( 
	VScene& in_out_scene,
	const HSINT in_renderIndex,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
: m_scene( in_out_scene )
, m_renderIndex( in_renderIndex )
, m_sceneApplicationInterface( in_sceneApplicationInterface )
, m_pendingArrayId()
{
	return;
}

/**/
VSceneUtilityHelperRender::~VSceneUtilityHelperRender()
{
	PostVisitor();
	return;
}
///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HBOOL VSceneUtilityHelperRender::VisitorSorted( Hubris::HSINT in_itemId )
{
	const HSINT renderLayer = m_scene.InterfaceObjectVisualGet().RenderLayerGet( in_itemId );
	if( HCOMMON_INVALID_INDEX == renderLayer )
	{
		return HTRUE;
	}

	if( 0 == renderLayer )
	{
		RenderItemId( in_itemId );
		return HTRUE;
	}

	if( m_pendingArrayId.SizeGet() < renderLayer )
	{
		m_pendingArrayId.SizeResize( renderLayer );
	}

	HContainerUtility::PushBack( m_pendingArrayId[ renderLayer - 1 ], in_itemId );

	return HTRUE;
}

/**/
Hubris::HVOID VSceneUtilityHelperRender::PostVisitor()
{
	HCOMMON_FOR_EACH_CONST( arrayId, m_pendingArrayId, TArrayArraySint )
	{
		for( const TArraySint::TIterator iterator = arrayId.Begin(); iterator != arrayId.End(); ++iterator )
		{
			RenderItemId( *iterator );
		}
	}

	m_pendingArrayId.Clear();
	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID VSceneUtilityHelperRender::RenderItemId( const Hubris::HSINT in_itemId )
{
	TArrayLight arrayLight;
	Pride::PColourRealRgb globalAmbient;
	VSceneUtility::GatherLightsOnObject(
		m_scene,
		in_itemId,
		arrayLight,
		globalAmbient
		);

	SInterfaceRender& interfaceRender = *( m_sceneApplicationInterface.RenderInterfaceGet( m_renderIndex ) );
	interfaceRender.LightSet(
		arrayLight,
		globalAmbient
		);

	m_scene.InterfaceObjectVisualGet().Render(
		in_itemId,
		m_renderIndex,
		m_sceneApplicationInterface
		);

	return;
}

/**/