//file: Vanity/VScene/VScene.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VScene.h"

#include "Vanity/VScene/VSceneImplementation.h"

#include "Vanity/VComponentCollision/VComponentCollision_Export.h"
#include "Vanity/VComponentDynamic/VComponentDynamic_Export.h"
#include "Vanity/VComponentForce/VComponentForce_Export.h"
#include "Vanity/VComponentGame/VComponentGame_Export.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitter_Export.h"
#include "Vanity/VComponentLightReceiver/VComponentLightReceiver_Export.h"
#include "Vanity/VComponentSoundEmitter/VComponentSoundEmitter_Export.h"
#include "Vanity/VComponentSoundReceiver/VComponentSoundReceiver_Export.h"
#include "Vanity/VComponentVisual/VComponentVisual_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VScene::VScene( const Hubris::HSINT in_objectFlag )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM(
		m_pImplementation, 
		VSceneImplementation,
		in_objectFlag
		);
}

/**/
VScene::VScene()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW(
		m_pImplementation, 
		VSceneImplementation
		);

	return;
}

/**/
VScene::~VScene()
{
	HCOMMON_DELETE( m_pImplementation, VSceneImplementation );
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const VScene::TItemId VScene::ItemAdd(
	const Hubris::HSINT in_componentFlag, //which components see this object on queries, assert valid
	const Pride::PSphereR3& in_sphere,
	const Hubris::HQuaternionREAL* const in_pRotation
	)
{
	return ImplementationGet().ItemAdd(
		in_componentFlag,
		in_sphere,
		in_pRotation
		);
}

/**/
HVOID VScene::ItemRemove(
	const TItemId in_itemId
	)
{
	ImplementationGet().ItemRemove(
		in_itemId
		);

	return;
}

/**/
HVOID VScene::ItemPositionChange( 
	const TItemId in_itemId, 
	const Pride::PSphereR3& in_sphere
	)
{
	ImplementationGet().ItemPositionChange(
		in_itemId,
		in_sphere
		);

	return;
}

/**/
HVOID VScene::ItemRotateChange( 
	const TItemId in_itemId, 
	const Hubris::HQuaternionREAL& in_rotation
	)
{
	ImplementationGet().ItemRotateChange(
		in_itemId,
		in_rotation
		);

	return;
}

/**/
HVOID VScene::ItemDataGet(
	const TItemId in_itemId,
	Hubris::HSINT* out_pComponentFlag,
	Pride::PSphereR3* out_pSphere,
	const VSceneItemComponentRotation** out_pRotationComponent
	)const
{
	ImplementationGet().ItemDataGet(
		in_itemId,
		out_pComponentFlag,
		out_pSphere,
		out_pRotationComponent
		);

	return;
}

/**/
const Hubris::HSINT VScene::ItemObjectFlagGet(
	const TItemId in_itemId
	)const
{
	return ImplementationGet().ItemObjectFlagGet(
		in_itemId
		);
}

/**/
const Pride::PSphereR3& VScene::ItemSphereGet(
	const TItemId in_itemId
	)const
{
	return ImplementationGet().ItemSphereGet(
		in_itemId
		);
}

/**/
const Hubris::HBOOL VScene::ItemRotationTest(
	const TItemId in_itemId
	)const
{
	return ImplementationGet().ItemRotationTest(
		in_itemId
		);
}

/**/
const VSceneItemComponentRotation& VScene::ItemComponentRotationGet(
	const TItemId in_itemId
	)const
{
	return ImplementationGet().ItemComponentRotationGet(
		in_itemId
		);
}

/**/
Hubris::HVOID VScene::ItemNameSet(
	const TItemId in_itemId,
	const Hubris::HString& in_itemName
	)
{
	ImplementationGet().ItemNameSet(
		in_itemId,
		in_itemName
		);
	return;
}

/**/
const VScene::TItemId VScene::ItemNameIndexGet(
	const Hubris::HString& in_itemName
	)
{
	const TItemId itemId = ImplementationGet().ItemNameIndexGet( in_itemName );
	return itemId;
}

/**/
HVOID VScene::ItemStructureRefreash()
{
	ImplementationGet().ItemStructureRefreash();
	return;
}

/**/
HVOID VScene::SubmitVisitorUnsortedAll(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag //item must match any of the flags to be exposed to query
	)const
{
	ImplementationGet().SubmitVisitorUnsortedAll(
		out_arrayItemId,
		in_componentFlag
		);

	return;
}

/**/
HVOID VScene::SubmitVisitorUnsortedSphere(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PSphereR3& in_sphere
	)const
{
	ImplementationGet().SubmitVisitorUnsortedSphere(
		out_arrayItemId,
		in_componentFlag,
		in_sphere
		);

	return;
}

/**/
HVOID VScene::SubmitVisitorUnsortedTriangle(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PTriangle& in_triangle
	)const
{
	ImplementationGet().SubmitVisitorUnsortedTriangle(
		out_arrayItemId,
		in_componentFlag,
		in_triangle
		);

	return;
}

/**/
HVOID VScene::SubmitVisitorUnsortedSegment(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PLineR3& in_segment
	)const
{
	ImplementationGet().SubmitVisitorUnsortedSegment(
		out_arrayItemId,
		in_componentFlag,
		in_segment
		);

	return;
}

/**/
HVOID VScene::SubmitVisitorUnsortedBounds(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PBoundsR3& in_bounds
	)const
{
	ImplementationGet().SubmitVisitorUnsortedBounds(
		out_arrayItemId,
		in_componentFlag,
		in_bounds
		);

	return;
}

/**/
HVOID VScene::SubmitVisitorUnsortedConvexHull(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PConvexHull& in_convexHull
	)const
{
	ImplementationGet().SubmitVisitorUnsortedConvexHull(
		out_arrayItemId,
		in_componentFlag,
		in_convexHull
		);

	return;
}

/**/
HVOID VScene::SubmitVisitorSortedRay(
	TFunctorVisitorSorted& in_functorVisitor,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_lineMaximumLength
	)const
{
	ImplementationGet().SubmitVisitorSortedRay(
		in_functorVisitor,
		in_componentFlag,
		in_line,
		in_lineMaximumLength
		);

	return;
}

/**/
Hubris::HVOID VScene::SubmitVisitorSortedHull(
	TFunctorVisitor& in_functorVisitor,
	const Hubris::HSINT in_objectFlag,
	const Hubris::HVectorR3& in_direction,
	const Pride::PConvexHull& in_hull,
	const Pride::PSphereR3& in_sphereContainingHull
	)const
{
	ImplementationGet().SubmitVisitorSortedHull(
		in_functorVisitor,
		in_objectFlag,
		in_direction,
		in_hull,
		in_sphereContainingHull
		);

	return;
}

/**/
Hubris::HVOID VScene::NewFrame()
{
	ImplementationGet().NewFrame();
	return;
}

/**/
Hubris::HVOID VScene::SceneCameraSet(
	const Pride::PCamera& in_camera
	)
{
	ImplementationGet().SceneCameraSet(
		in_camera
		);
	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT VScene::FlagComponentCollisionGet()
{
	return( VSceneImplementation::FlagComponentCollisionGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentDynamicGet()
{
	return( VSceneImplementation::FlagComponentDynamicGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentGameGet()
{
	return( VSceneImplementation::FlagComponentGameGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentForceGet()
{
	return( VSceneImplementation::FlagComponentForceGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentLightEmitterGet()
{
	return( VSceneImplementation::FlagComponentLightEmitterGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentLightReceiverGet()
{
	return( VSceneImplementation::FlagComponentLightReceiverGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentSoundEmitterGet()
{
	return( VSceneImplementation::FlagComponentSoundEmitterGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentSoundReceiverGet()
{
	return( VSceneImplementation::FlagComponentSoundReceiverGet() );
}

/**/
const Hubris::HSINT VScene::FlagComponentVisualGet()
{
	return( VSceneImplementation::FlagComponentVisualGet() );
}

/**
const Hubris::HSINT VScene::FlagTickComponentDynamicGet()
{
	return( VSceneImplementation::FlagTickComponentDynamicGet() );
}

/**
const Hubris::HSINT VScene::FlagTickComponentGameGet()
{
	return( VSceneImplementation::FlagTickComponentGameGet() );
}

/**/
const Hubris::HSINT VScene::FlagStaticGet()
{
	return( VSceneImplementation::FlagStaticGet() );
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT VScene::ComponentFlagGet()const
{
	return( ImplementationGet().ComponentFlagGet() );
}

/**/
Hubris::HVOID VScene::ComponentFlagSet( const Hubris::HSINT in_componentFlag )
{
	ImplementationGet().ComponentFlagSet( in_componentFlag );
	return;
}

/**/
VComponentCollisionInterfaceObject VScene::InterfaceObjectCollisionGet()
{
	return VComponentCollisionInterfaceObject(
		ImplementationGet().ComponentCollisionGet(),
		( *this )
		);
}

/**/
VComponentDynamicInterfaceObject VScene::InterfaceObjectDynamicGet()
{
	return VComponentDynamicInterfaceObject(
		ImplementationGet().ComponentDynamicGet(),
		( *this )
		);
}

/**/
VComponentGameInterfaceObject VScene::InterfaceObjectGameGet()
{
	return VComponentGameInterfaceObject(
		ImplementationGet().ComponentGameGet(),
		( *this )
		);
}

/**/
VComponentForceInterfaceObject VScene::InterfaceObjectForceGet()
{
	return VComponentForceInterfaceObject(
		ImplementationGet().ComponentForceGet(),
		( *this )
		);
}

/**/
VComponentLightEmitterInterfaceObject VScene::InterfaceObjectLightEmitterGet()
{
	return VComponentLightEmitterInterfaceObject(
		ImplementationGet().ComponentLightEmitterGet(),
		( *this )
		);
}

/**/
VComponentLightReceiverInterfaceObject VScene::InterfaceObjectLightReceiverGet()
{
	return VComponentLightReceiverInterfaceObject(
		ImplementationGet().ComponentLightReceiverGet(),
		( *this )
		);
}

/**/
VComponentSoundEmitterInterfaceObject VScene::InterfaceObjectSoundEmitterGet()
{
	return VComponentSoundEmitterInterfaceObject(
		ImplementationGet().ComponentSoundEmitterGet(),
		( *this )
		);
}

/**/
VComponentSoundReceiverInterfaceObject VScene::InterfaceObjectSoundReceiverGet()
{
	return VComponentSoundReceiverInterfaceObject(
		ImplementationGet().ComponentSoundReceiverGet(),
		( *this )
		);
}

/**/
VComponentVisualInterfaceObject VScene::InterfaceObjectVisualGet()
{
	return VComponentVisualInterfaceObject(
		ImplementationGet().ComponentVisualGet(),
		( *this )
		);
}

/**/
const Hubris::HSINT VScene::FrameIDGet()const
{
	const HSINT frameID = ImplementationGet().FrameIDGet();
	return frameID;
}

/**/
const Hubris::HVectorR3& VScene::CameraVectorAtGet()const
{
	return ImplementationGet().CameraVectorAtGet();
}

/**/
const Hubris::HVectorR3& VScene::CameraVectorUpGet()const
{
	return ImplementationGet().CameraVectorUpGet();
}

/**/
const Hubris::HVectorR3& VScene::CameraVectorRightGet()const
{
	return ImplementationGet().CameraVectorRightGet();
}

///////////////////////////////////////////////////////
// private accessors
/**/
const VSceneImplementation& VScene::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
VSceneImplementation& VScene::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/