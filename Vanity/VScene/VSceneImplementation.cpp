//file: Vanity/VScene/VSceneImplementation.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneImplementation.h"

#include "Vanity/VScene/VSceneComponentSphereTree.h"

#include "Vanity/VComponentCollision/VComponentCollision_Export.h"
#include "Vanity/VComponentDynamic/VComponentDynamic_Export.h"
#include "Vanity/VComponentGame/VComponentGame_Export.h"
#include "Vanity/VComponentForce/VComponentForce_Export.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitter_Export.h"
#include "Vanity/VComponentLightReceiver/VComponentLightReceiver_Export.h"
#include "Vanity/VComponentSoundEmitter/VComponentSoundEmitter_Export.h"
#include "Vanity/VComponentSoundReceiver/VComponentSoundReceiver_Export.h"
#include "Vanity/VComponentVisual/VComponentVisual_Export.h"

#include "Envy/Envy_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
struct TObjectId
{
	enum TEnum
	{
		TStatic = 0,

		TComponentCollision,
		TComponentDynamic,
		TComponentForce,
		TComponentGame,
		TComponentLightEmitter,
		TComponentLightReceiver,
		TComponentSoundEmitter,
		TComponentSoundReceiver,
		TComponentVisual,

		TComponentTickAnimation,
		TComponentTickDynamic,
		TComponentTickGame,

		TCount
	};
};

/**/
struct TObjectFlags
{
	enum TEnum
	{
		TStatic					= HCOMMON_INDEX_TO_FLAG( TObjectId::TStatic ),

		//valid component data
		TComponentCollision		= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentCollision ),
		TComponentDynamic		= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentDynamic ),
		TComponentGame			= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentGame ),
		TComponentForce			= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentForce ),
		TComponentLightEmitter	= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentLightEmitter ),
		TComponentLightReceiver	= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentLightReceiver ),
		TComponentSoundEmitter	= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentSoundEmitter ),
		TComponentSoundReceiver	= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentSoundReceiver ),
		TComponentVisual		= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentVisual ),

		//TTickComponentAnimation	= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentTickAnimation ),
		//TTickComponentDynamic	= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentTickDynamic ),
		//TTickComponentGame		= HCOMMON_INDEX_TO_FLAG( TObjectId::TComponentTickGame ),

		TNone					= 0x0000
	};
};

///////////////////////////////////////////////////////
// creation
/**/
VSceneImplementation::VSceneImplementation( const Hubris::HSINT in_componentFlag )
: m_componentFlag( 0 )
, m_pComponentSphereTree( HNULL )
, m_pComponentCollision( HNULL )
, m_pComponentDynamic( HNULL )
, m_pComponentGame( HNULL )
, m_pComponentForce( HNULL )
, m_pComponentLightEmitter( HNULL )
, m_pComponentLightReceiver( HNULL )
, m_pComponentSoundEmitter( HNULL )
, m_pComponentSoundReceiver( HNULL )
, m_pComponentVisual( HNULL )
, m_stringTableItemName()
, m_frameId( 0 )
, m_cameraVectorAt()
, m_cameraVectorUp()
, m_cameraVectorRight()
{
	HCOMMON_NEW(
		m_pComponentSphereTree,
		VSceneComponentSphereTree
		);

	ComponentFlagSet( in_componentFlag );

	return;
}

/**/
VSceneImplementation::VSceneImplementation()
: m_componentFlag( 0 )
, m_pComponentSphereTree( HNULL )
, m_pComponentCollision( HNULL )
, m_pComponentDynamic( HNULL )
, m_pComponentGame( HNULL )
, m_pComponentForce( HNULL )
, m_pComponentLightEmitter( HNULL )
, m_pComponentLightReceiver( HNULL )
, m_pComponentSoundEmitter( HNULL )
, m_pComponentSoundReceiver( HNULL )
, m_pComponentVisual( HNULL )
, m_stringTableItemName()
, m_frameId( 0 )
, m_cameraVectorAt()
, m_cameraVectorUp()
, m_cameraVectorRight()
{
	HCOMMON_NEW(
		m_pComponentSphereTree,
		VSceneComponentSphereTree
		);

	return;
}

/**/
VSceneImplementation::~VSceneImplementation()
{
	HCOMMON_DELETE(
		m_pComponentSphereTree,
		VSceneComponentSphereTree
		);

	ComponentRelease();

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT VSceneImplementation::ItemAdd(
	const Hubris::HSINT in_objectFlag, //which components see this object on queries, assert valid
	const Pride::PSphereR3& in_sphere,
	const Hubris::HQuaternionREAL* const in_pRotation
	)
{
	const HSINT itemId = ComponentSphereTreeGet().ItemAdd(
		in_objectFlag,
		in_sphere,
		in_pRotation
		);

	if( 0 != ( m_componentFlag & FlagComponentCollisionGet() ) )
	{
		ComponentCollisionGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentDynamicGet() ) )
	{
		ComponentDynamicGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentGameGet() ) )
	{
		ComponentGameGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentForceGet() ) )
	{
		ComponentForceGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentLightEmitterGet() ) )
	{
		ComponentLightEmitterGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentLightReceiverGet() ) )
	{
		ComponentLightReceiverGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentSoundEmitterGet() ) )
	{
		ComponentSoundEmitterGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentSoundReceiverGet() ) )
	{
		ComponentSoundReceiverGet().OnAddItem( itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentVisualGet() ) )
	{
		ComponentVisualGet().OnAddItem( itemId );
	}

	return itemId;
}

/**/
HVOID VSceneImplementation::ItemRemove(
	const Hubris::HSINT in_itemId
	)
{
	ComponentSphereTreeGet().ItemRemove( in_itemId );

	if( 0 != ( m_componentFlag & FlagComponentCollisionGet() ) )
	{
		ComponentCollisionGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentDynamicGet() ) )
	{
		ComponentDynamicGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentGameGet() ) )
	{
		ComponentGameGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentForceGet() ) )
	{
		ComponentForceGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentLightEmitterGet() ) )
	{
		ComponentLightEmitterGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentLightReceiverGet() ) )
	{
		ComponentLightReceiverGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentSoundEmitterGet() ) )
	{
		ComponentSoundEmitterGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentSoundReceiverGet() ) )
	{
		ComponentSoundReceiverGet().OnRemoveItem( in_itemId );
	}
	if( 0 != ( m_componentFlag & FlagComponentVisualGet() ) )
	{
		ComponentVisualGet().OnRemoveItem( in_itemId );
	}

	return;
}

/**/
HVOID VSceneImplementation::ItemPositionChange( 
	const Hubris::HSINT in_itemId, 
	const Pride::PSphereR3& in_sphere
	)
{
	ComponentSphereTreeGet().ItemPositionChange(
		in_itemId,
		in_sphere
		);

	return;
}

/**/
HVOID VSceneImplementation::ItemRotateChange( 
	const Hubris::HSINT in_itemId, 
	const Hubris::HQuaternionREAL& in_rotation
	)
{
	ComponentSphereTreeGet().ItemRotateChange(
		in_itemId,
		in_rotation
		);

	return;
}

/**/
HVOID VSceneImplementation::ItemDataGet(
	const Hubris::HSINT in_itemId,
	Hubris::HSINT* out_pComponentFlag,
	Pride::PSphereR3* out_pSphere,
	const VSceneItemComponentRotation** out_pRotationComponent
	)const
{
	ComponentSphereTreeGet().ItemDataGet(
		in_itemId,
		out_pComponentFlag,
		out_pSphere,
		out_pRotationComponent
		);

	return;
}

/**/
const Hubris::HSINT VSceneImplementation::ItemObjectFlagGet(
	const Hubris::HSINT in_itemId
	)const
{
	return ComponentSphereTreeGet().ItemComponentFlagGet( in_itemId );
}

/**/
const Pride::PSphereR3& VSceneImplementation::ItemSphereGet(
	const Hubris::HSINT in_itemId
	)const
{
	return ComponentSphereTreeGet().ItemSphereGet( in_itemId );
}

/**/
const Hubris::HBOOL VSceneImplementation::ItemRotationTest(
	const Hubris::HSINT in_itemId
	)const
{
	return ComponentSphereTreeGet().ItemRotationTest( in_itemId );
}

/**/
const VSceneItemComponentRotation& VSceneImplementation::ItemComponentRotationGet(
	const Hubris::HSINT in_itemId
	)const
{
	return ComponentSphereTreeGet().ItemComponentRotationGet( in_itemId );
}

/**/
Hubris::HVOID VSceneImplementation::ItemNameSet(
	const Hubris::HSINT in_itemId,
	const Hubris::HString& in_itemName
	)
{
	m_stringTableItemName.StringIndexAdd( in_itemName, in_itemId );
	return;
}

/**/
const Hubris::HSINT VSceneImplementation::ItemNameIndexGet(
	const Hubris::HString& in_itemName
	)
{
	const Hubris::HSINT itemId = m_stringTableItemName.StringFind( in_itemName );
	return itemId;
}

/**/
HVOID VSceneImplementation::ItemStructureRefreash()
{
	ComponentSphereTreeGet().BuildSphereTree();
	return;
}

/**/
HVOID VSceneImplementation::SubmitVisitorUnsortedAll(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag //item must match any of the flags to be exposed to query
	)const
{
	ComponentSphereTreeGet().SubmitVisitorUnsortedAll(
		out_arrayItemId,
		in_componentFlag
		);

	return;
}

/**/
HVOID VSceneImplementation::SubmitVisitorUnsortedSphere(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PSphereR3& in_sphere
	)const
{
	ComponentSphereTreeGet().SubmitVisitorUnsortedSphere(
		out_arrayItemId,
		in_componentFlag,
		in_sphere
		);

	return;
}

/**/
HVOID VSceneImplementation::SubmitVisitorUnsortedTriangle(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PTriangle& in_triangle
	)const
{
	ComponentSphereTreeGet().SubmitVisitorUnsortedTriangle(
		out_arrayItemId,
		in_componentFlag,
		in_triangle
		);

	return;
}

/**/
HVOID VSceneImplementation::SubmitVisitorUnsortedSegment(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PLineR3& in_segment
	)const
{
	ComponentSphereTreeGet().SubmitVisitorUnsortedSegment(
		out_arrayItemId,
		in_componentFlag,
		in_segment
		);

	return;
}

/**/
HVOID VSceneImplementation::SubmitVisitorUnsortedBounds(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PBoundsR3& in_bounds
	)const
{
	ComponentSphereTreeGet().SubmitVisitorUnsortedBounds(
		out_arrayItemId,
		in_componentFlag,
		in_bounds
		);

	return;
}

/**/
HVOID VSceneImplementation::SubmitVisitorUnsortedConvexHull(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PConvexHull& in_convexHull
	)const
{
	ComponentSphereTreeGet().SubmitVisitorUnsortedConvexHull(
		out_arrayItemId,
		in_componentFlag,
		in_convexHull
		);

	return;
}

/**/
HVOID VSceneImplementation::SubmitVisitorSortedRay(
	TFunctorVisitorSorted& in_functorVisitor,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_lineMaximumLength
	)const
{
	ComponentSphereTreeGet().SubmitVisitorSortedRay(
		in_functorVisitor,
		in_componentFlag,
		in_line,
		in_lineMaximumLength
		);

	return;
}

/**/
Hubris::HVOID VSceneImplementation::SubmitVisitorSortedHull(
	TFunctorVisitor& in_functorVisitor,
	const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
	const Hubris::HVectorR3& in_direction, //sort hint
	const Pride::PConvexHull& in_hull,
	const Pride::PSphereR3& in_sphereContainingHull
	)const
{
	ComponentSphereTreeGet().SubmitVisitorSortedHull(
		in_functorVisitor,
		in_objectFlag,
		in_direction,
		in_hull,
		in_sphereContainingHull
		);

	return;
}

/**/
Hubris::HVOID VSceneImplementation::NewFrame()
{
	m_frameId += 1;
	return;
}

/**/
Hubris::HVOID VSceneImplementation::SceneCameraSet(
	const Pride::PCamera& in_camera
	)
{
	m_cameraVectorUp = PCameraUtility::UpFromCamera( in_camera );
	m_cameraVectorRight = PCameraUtility::RightFromCamera( in_camera );
	m_cameraVectorAt = PCameraUtility::AtFromCamera( in_camera );

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID VSceneImplementation::ComponentRelease()
{
	if( HNULL != m_pComponentCollision )
	{
		HCOMMON_DELETE(
			m_pComponentCollision,
			VComponentCollision
			);
	}
	if( HNULL != m_pComponentDynamic )
	{
		HCOMMON_DELETE(
			m_pComponentDynamic,
			VComponentDynamic
			);
	}
	if( HNULL != m_pComponentGame )
	{
		HCOMMON_DELETE(
			m_pComponentGame,
			VComponentGame
			);
	}
	if( HNULL != m_pComponentForce )
	{
		HCOMMON_DELETE(
			m_pComponentForce,
			VComponentForce
			);
	}
	if( HNULL != m_pComponentLightEmitter )
	{
		HCOMMON_DELETE(
			m_pComponentLightEmitter,
			VComponentLightEmitter
			);
	}
	if( HNULL != m_pComponentLightReceiver )
	{
		HCOMMON_DELETE(
			m_pComponentLightReceiver,
			VComponentLightReceiver
			);
	}
	if( HNULL != m_pComponentSoundEmitter )
	{
		HCOMMON_DELETE(
			m_pComponentSoundEmitter,
			VComponentSoundEmitter
			);
	}
	if( HNULL != m_pComponentSoundReceiver )
	{
		HCOMMON_DELETE(
			m_pComponentSoundReceiver,
			VComponentSoundReceiver
			);
	}
	if( HNULL != m_pComponentVisual )
	{
		HCOMMON_DELETE(
			m_pComponentVisual,
			VComponentVisual
			);
	}

	return;
}

/**/
Hubris::HVOID VSceneImplementation::ComponentCreate()
{
	if( 0 != ( m_componentFlag & FlagComponentCollisionGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentCollision,
			VComponentCollision
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentDynamicGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentDynamic,
			VComponentDynamic
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentGameGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentGame,
			VComponentGame
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentForceGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentForce,
			VComponentForce
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentLightEmitterGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentLightEmitter,
			VComponentLightEmitter
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentLightReceiverGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentLightReceiver,
			VComponentLightReceiver
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentSoundEmitterGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentSoundEmitter,
			VComponentSoundEmitter
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentSoundReceiverGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentSoundReceiver,
			VComponentSoundReceiver
			);
	}
	if( 0 != ( m_componentFlag & FlagComponentVisualGet() ) )
	{
		HCOMMON_NEW(
			m_pComponentVisual,
			VComponentVisual
			);
	}

	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT VSceneImplementation::FlagComponentCollisionGet()
{
	return( TObjectFlags::TComponentCollision );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentDynamicGet()
{
	return( TObjectFlags::TComponentDynamic );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentGameGet()
{
	return( TObjectFlags::TComponentGame );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentForceGet()
{
	return( TObjectFlags::TComponentForce );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentLightEmitterGet()
{
	return( TObjectFlags::TComponentLightEmitter );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentLightReceiverGet()
{
	return( TObjectFlags::TComponentLightReceiver );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentSoundEmitterGet()
{
	return( TObjectFlags::TComponentSoundEmitter );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentSoundReceiverGet()
{
	return( TObjectFlags::TComponentSoundReceiver );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagComponentVisualGet()
{
	return( TObjectFlags::TComponentVisual );
}

/**
const Hubris::HSINT VSceneImplementation::FlagTickComponentDynamicGet()
{
	return( TObjectFlags::TTickComponentDynamic );
}

/**
const Hubris::HSINT VSceneImplementation::FlagTickComponentGameGet()
{
	return( TObjectFlags::TTickComponentGame );
}

/**/
const Hubris::HSINT VSceneImplementation::FlagStaticGet()
{
	return( TObjectFlags::TStatic );
}

///////////////////////////////////////////////////////
// public accessors
/**/
Hubris::HVOID VSceneImplementation::ComponentFlagSet( const Hubris::HSINT in_componentFlag )
{
	ComponentRelease();
	m_componentFlag = in_componentFlag;
	ComponentCreate();
	return;
}

/**/
const VSceneComponentSphereTree& VSceneImplementation::ComponentSphereTreeGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentSphereTree, "invalid member" );
	return( *m_pComponentSphereTree );
}

/**/
VSceneComponentSphereTree& VSceneImplementation::ComponentSphereTreeGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentSphereTree, "invalid member" );
	return( *m_pComponentSphereTree );
}

/**/
const VComponentCollision& VSceneImplementation::ComponentCollisionGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentCollision, "invalid member" );
	return( *m_pComponentCollision );
}

/**/
VComponentCollision& VSceneImplementation::ComponentCollisionGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentCollision, "invalid member" );
	return( *m_pComponentCollision );
}

/**/
const VComponentDynamic& VSceneImplementation::ComponentDynamicGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentDynamic, "invalid member" );
	return( *m_pComponentDynamic );
}

/**/
VComponentDynamic& VSceneImplementation::ComponentDynamicGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentDynamic, "invalid member" );
	return( *m_pComponentDynamic );
}

/**/
const VComponentGame& VSceneImplementation::ComponentGameGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentGame, "invalid member" );
	return( *m_pComponentGame );
}

/**/
VComponentGame& VSceneImplementation::ComponentGameGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentGame, "invalid member" );
	return( *m_pComponentGame );
}

/**/
const VComponentForce& VSceneImplementation::ComponentForceGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentForce, "invalid member" );
	return( *m_pComponentForce );
}

/**/
VComponentForce& VSceneImplementation::ComponentForceGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentForce, "invalid member" );
	return( *m_pComponentForce );
}

/**/
const VComponentLightEmitter& VSceneImplementation::ComponentLightEmitterGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentLightEmitter, "invalid member" );
	return( *m_pComponentLightEmitter );
}

/**/
VComponentLightEmitter& VSceneImplementation::ComponentLightEmitterGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentLightEmitter, "invalid member" );
	return( *m_pComponentLightEmitter );
}

/**/
const VComponentLightReceiver& VSceneImplementation::ComponentLightReceiverGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentLightReceiver, "invalid member" );
	return( *m_pComponentLightReceiver );
}

/**/
VComponentLightReceiver& VSceneImplementation::ComponentLightReceiverGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentLightReceiver, "invalid member" );
	return( *m_pComponentLightReceiver );
}

/**/
const VComponentSoundEmitter& VSceneImplementation::ComponentSoundEmitterGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentSoundEmitter, "invalid member" );
	return( *m_pComponentSoundEmitter );
}

/**/
VComponentSoundEmitter& VSceneImplementation::ComponentSoundEmitterGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentSoundEmitter, "invalid member" );
	return( *m_pComponentSoundEmitter );
}

/**/
const VComponentSoundReceiver& VSceneImplementation::ComponentSoundReceiverGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentSoundReceiver, "invalid member" );
	return( *m_pComponentSoundReceiver );
}

/**/
VComponentSoundReceiver& VSceneImplementation::ComponentSoundReceiverGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentSoundReceiver, "invalid member" );
	return( *m_pComponentSoundReceiver );
}

/**/
const VComponentVisual& VSceneImplementation::ComponentVisualGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentVisual, "invalid member" );
	return( *m_pComponentVisual );
}

/**/
VComponentVisual& VSceneImplementation::ComponentVisualGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentVisual, "invalid member" );
	return( *m_pComponentVisual );
}

///**/
//VAssetManager& VSceneImplementation::AssetManagerGet()
//{
//	if( HNULL == m_pAssetManager )
//	{
//		HCOMMON_NEW(
//			m_pAssetManager,
//			VAssetManager
//			);
//	}
//
//	return( *m_pAssetManager );
//}
//
///**/
//const Hubris::HSINT VSceneImplementation::RenderInterfaceIndexRequest()
//{
//	const HSINT renderIndex = m_resourceIdManagerRenderInterface.ResourceIdAcquire();
//	RenderInterfaceSet( renderIndex, HNULL );
//	return renderIndex;
//}
//
///**/
//Hubris::HVOID VSceneImplementation::RenderInterfaceIndexRelease( const Hubris::HSINT in_renderIndex )
//{
//	return m_resourceIdManagerRenderInterface.ResourceIdRelease( in_renderIndex );
//}
//
///**/
//const Hubris::HSINT VSceneImplementation::RenderInterfaceCountGet()const
//{
//	return m_arrayRenderInterface.SizeGet();
//}
//
///**/
//Sloth::SInterfaceRender* const VSceneImplementation::RenderInterfaceGet( const Hubris::HSINT in_renderIndex )
//{
//	if( ( 0 <= in_renderIndex ) &&
//		( in_renderIndex < m_arrayRenderInterface.SizeGet() ) )
//	{
//		return m_arrayRenderInterface[ in_renderIndex ];
//	}
//
//	return HNULL;
//}
//
///**/
//Hubris::HVOID VSceneImplementation::RenderInterfaceSet( const Hubris::HSINT in_renderIndex, Sloth::SInterfaceRender* const in_pRenderInterface )
//{
//	if( m_arrayRenderInterface.SizeGet() <= in_renderIndex )
//	{
//		m_arrayRenderInterface.SizeResize( in_renderIndex + 1 );
//	}
//
//	m_arrayRenderInterface[ in_renderIndex ] = in_pRenderInterface;
//
//	return;
//}
//
/**/
