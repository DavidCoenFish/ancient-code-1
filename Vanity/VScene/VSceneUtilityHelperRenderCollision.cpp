//file: Vanity/VScene/VSceneUtilityHelperRenderCollision.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneUtilityHelperRenderCollision.h"

#include "Vanity/VScene/VScene.h"
#include "Vanity/VScene/VSceneUtility.h"

#include "Vanity/VComponentCollision/VComponentCollision_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VSceneUtilityHelperRenderCollision::VSceneUtilityHelperRenderCollision( 
	VScene& in_out_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const HSINT in_renderIndex
	)
: m_scene( in_out_scene )
, m_sceneApplicationInterface( in_sceneApplicationInterface )
, m_renderIndex( in_renderIndex )
{
	return;
}

/**/
VSceneUtilityHelperRenderCollision::~VSceneUtilityHelperRenderCollision()
{
	return;
}
///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HBOOL VSceneUtilityHelperRenderCollision::VisitorSorted( Hubris::HSINT in_itemId )
{
	m_scene.InterfaceObjectCollisionGet().Render(
		m_sceneApplicationInterface,
		m_renderIndex,
		in_itemId
		);

	return HTRUE;
}

/**/