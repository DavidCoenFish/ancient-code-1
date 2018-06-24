//file: Vanity/VComponentCollision/VComponentCollisionDataBound.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataBound.h"

#include "Vanity/VComponentCollision/VComponentCollisionTrait.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultBase.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/SInterface/SInterface_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentCollisionDataBound, VComponentCollisionDataBase );

///////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionDataBound::VComponentCollisionDataBound()
{
	return;
}

/**/
VComponentCollisionDataBound::~VComponentCollisionDataBound()
{
	return;
}
///////////////////////////////////////////////////////
// implement VComponentCollisionDataBase
/**/
Hubris::HVOID VComponentCollisionDataBound::Load(
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface )
	)
{
	return;
}

/**/
Hubris::HVOID VComponentCollisionDataBound::UnLoad(
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface )
	)
{
	return;
}

/**/
Hubris::HVOID VComponentCollisionDataBound::CollideRay(
	VComponentCollisionResultBase& out_collisionData,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_maximumLineLength,
	const Hubris::HREAL HCOMMON_UNUSED_VAR( in_rayThickness ),
	const VScene& in_scene,
	const TItemId in_itemId
	)const
{
	HMatrixR4 itemMatrix;
	HMatrixR4 itemMatrixInvert;

	VSceneUtility::ItemMatrixGet( 
		itemMatrix,
		itemMatrixInvert,
		in_scene,
		in_itemId
		);

	//put the line into local space
	PLineR3 localLine = PLineUtility::LineTransform( in_line, itemMatrixInvert );

	HREAL ratioOnLine = 0.0F;
	HVectorR3 normal;
	if( HFALSE == PBoundsUtility::IntersectLine(
		m_bound,
		localLine,
		&ratioOnLine,
		&normal
		) )
	{
		return;
	}

	//if( ratioOnLine < in_maximumLineLength )
	//bail if past maximum or after start of line
	if( ( in_maximumLineLength < ratioOnLine ) ||
		( ratioOnLine < 0.0F ) ) //check epsilon?
	{
		return;
	}

	VComponentCollisionResultBound* pResult = HNULL;
	HCOMMON_NEW_PARAM_3(
		pResult,
		VComponentCollisionResultBound,
		ratioOnLine,
		in_line,
		HMatrixUtility::VectorProductNoTranslate( itemMatrix, normal )
		);

	out_collisionData.PointerSetBound( pResult );

	return;
}

/**/
Hubris::HVOID VComponentCollisionDataBound::Render(
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HSINT in_renderIndex,
	const TItemId in_itemId
	)
{
	SInterfaceRender* pInterfaceRender = in_sceneApplicationInterface.RenderInterfaceGet( in_renderIndex );
	if( HNULL == pInterfaceRender )
	{
		return;
	}

	VSceneUtility::RenderItemMatrixSet(
		in_itemId,
		in_scene,
		*pInterfaceRender
		);

	pInterfaceRender->DrawBox( m_bound );

	return;
}

/**/