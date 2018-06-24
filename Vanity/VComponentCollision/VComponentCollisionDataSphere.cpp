//file: Vanity/VComponentCollision/VComponentCollisionDataSphere.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataSphere.h"

#include "Vanity/VComponentCollision/VComponentCollisionTrait.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultBase.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultSphere.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/SInterface/SInterface_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentCollisionDataSphere, VComponentCollisionDataBase );

///////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionDataSphere::VComponentCollisionDataSphere()
{
	return;
}

/**/
VComponentCollisionDataSphere::~VComponentCollisionDataSphere()
{
	return;
}

///////////////////////////////////////////////////////
// implement VComponentCollisionDataBase
/**/
Hubris::HVOID VComponentCollisionDataSphere::Load(
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface )
	)
{
	return;
}

/**/
Hubris::HVOID VComponentCollisionDataSphere::UnLoad(
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface )
	)
{
	return;
}

/**/
Hubris::HVOID VComponentCollisionDataSphere::CollideRay(
	VComponentCollisionResultBase& out_collisionData,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_maximumLineLength,
	const Hubris::HREAL HCOMMON_UNUSED_VAR( in_rayThickness ),
	const VScene& in_scene,
	const TItemId in_itemId
	)const
{
	PSphereR3 sphere;
	in_scene.ItemDataGet( in_itemId, HNULL, &sphere );

	const HREAL tempDistance = HMatrixUtility::DotProduct( in_line.DirectionGet().VectorGet(), sphere.CenterGet() - in_line.OriginGet() );
	//elevate sphere radius check?
	//if( in_maximumLineLength < ( tempDistance - sphere->RadiusGet() ) )
	//{
	//	return;
	//}

	const HVectorR3 tempPoint = in_line.OriginGet() + ( tempDistance * in_line.DirectionGet().VectorGet() );
	const HREAL pointDistanceSquared = HMatrixUtility::LengthSquared( tempPoint - sphere.CenterGet() );
	const HREAL radiusSquared = HMath::Square( sphere.RadiusGet() );

	//test is distance to perpendicular point on line is greater than sphere radius, and if so, bail
	if( ( radiusSquared < pointDistanceSquared ) &&
		( HMathUtility::EpsilonEqualNot( pointDistanceSquared, radiusSquared ) ) )
	{
		return;
	}

	//we have a potential collision
	const HREAL distance = tempDistance - ( HMath::SquareRoot( HMath::Square( sphere.RadiusGet() ) + pointDistanceSquared ) );

	//test distance against line max
	if( distance < in_maximumLineLength )
		//( HMathUtility::EpsilonEqualNot( distance, in_maximumLineLength ) ) )
	{
		return;
	}

	VComponentCollisionResultSphere* pResult = HNULL;
	HCOMMON_NEW_PARAM_3(
		pResult,
		VComponentCollisionResultSphere,
		distance,
		in_line,
		sphere
		);

	out_collisionData.PointerSetSphere( pResult );

	return;
}

/**/
Hubris::HVOID VComponentCollisionDataSphere::Render(
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

	const HREAL radius = in_scene.ItemSphereGet( in_itemId ).RadiusGet();
	pInterfaceRender->DrawSphere( radius );

	return;
}

/**/
