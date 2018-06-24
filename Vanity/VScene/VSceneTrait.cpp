//file: Vanity/VScene/VSceneTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneTrait.h"

#include "Vanity/VScene/VScene.h"
#include "Vanity/VScene/VSceneImplementation.h"
#include "Vanity/VScene/VSceneComponentSphereTree.h"
#include "Vanity/VScene/VSceneItemComponentRotation.h"
#include "Vanity/VScene/VSceneComponentSphereCollection.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Envy;
using namespace Vanity;

HTYPE_NAME_IMPLEMENTATION( VSceneItemComponentRotation );

///////////////////////////////////////////////////////////
// specialise memento
/**/
HVOID Envy::EMementoTraitCollect< VScene >( EMementoCollect& in_out_mementoCollect, const Vanity::VScene& in_data )
{
	const HSINT componentFlag = in_data.ImplementationGet().ComponentFlagGet();
	in_out_mementoCollect.MemberAdd( "flag", componentFlag );

	in_out_mementoCollect.MemberAdd( "ComponentSphereTree", in_data.ImplementationGet().ComponentSphereTreeGet() );

	if( 0 != ( componentFlag & VScene::FlagComponentCollisionGet() ) )
	{
		in_out_mementoCollect.MemberAdd( "ComponentCollision", in_data.ImplementationGet().ComponentCollisionGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentDynamicGet() ) )
	{
		in_out_mementoCollect.MemberAdd( "ComponentDynamic", in_data.ImplementationGet().ComponentDynamicGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentGameGet() ) )
	{
		in_out_mementoCollect.MemberAdd( "ComponentGame", in_data.ImplementationGet().ComponentGameGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentForceGet() ) )
	{
		in_out_mementoCollect.MemberAdd( "ComponentForce", in_data.ImplementationGet().ComponentForceGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentLightEmitterGet() ) )
	{
		in_out_mementoCollect.MemberAdd( "ComponentLightEmitter", in_data.ImplementationGet().ComponentLightEmitterGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentLightReceiverGet() ) )
	{
		in_out_mementoCollect.MemberAdd( "ComponentLightReceiver", in_data.ImplementationGet().ComponentLightReceiverGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentSoundEmitterGet() ) )
	{
	}
	if( 0 != ( componentFlag & VScene::FlagComponentSoundReceiverGet() ) )
	{
	}
	if( 0 != ( componentFlag & VScene::FlagComponentVisualGet() ) )
	{
		in_out_mementoCollect.MemberAdd( "ComponentVisual", in_data.ImplementationGet().ComponentVisualGet() );
	}

	in_out_mementoCollect.MemberAdd( "m_stringTableItemName", in_data.ImplementationGet().StringTableItemNameGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VScene >( const EMementoAssign& in_out_mementoAssign, Vanity::VScene& out_data )
{
	HSINT componentFlag = 0;// in_data.ImplementationGet().ComponentFlagGet();
	in_out_mementoAssign.MemberGet( "flag", componentFlag );
	out_data.ImplementationGet().ComponentFlagSet( componentFlag );

	in_out_mementoAssign.MemberGet( "ComponentSphereTree", out_data.ImplementationGet().ComponentSphereTreeGet() );

	if( 0 != ( componentFlag & VScene::FlagComponentCollisionGet() ) )
	{
		in_out_mementoAssign.MemberGet( "ComponentCollision", out_data.ImplementationGet().ComponentCollisionGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentDynamicGet() ) )
	{
		in_out_mementoAssign.MemberGet( "ComponentDynamic", out_data.ImplementationGet().ComponentDynamicGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentGameGet() ) )
	{
		in_out_mementoAssign.MemberGet( "ComponentGame", out_data.ImplementationGet().ComponentGameGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentForceGet() ) )
	{
		in_out_mementoAssign.MemberGet( "ComponentForce", out_data.ImplementationGet().ComponentForceGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentLightEmitterGet() ) )
	{
		in_out_mementoAssign.MemberGet( "ComponentLightEmitter", out_data.ImplementationGet().ComponentLightEmitterGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentLightReceiverGet() ) )
	{
		in_out_mementoAssign.MemberGet( "ComponentLightReceiver", out_data.ImplementationGet().ComponentLightReceiverGet() );
	}
	if( 0 != ( componentFlag & VScene::FlagComponentSoundEmitterGet() ) )
	{
	}
	if( 0 != ( componentFlag & VScene::FlagComponentSoundReceiverGet() ) )
	{
	}
	if( 0 != ( componentFlag & VScene::FlagComponentVisualGet() ) )
	{
		in_out_mementoAssign.MemberGet( "ComponentVisual", out_data.ImplementationGet().ComponentVisualGet() );
	}
	
	in_out_mementoAssign.MemberGet( "m_stringTableItemName", out_data.ImplementationGet().StringTableItemNameGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitCollect< VSceneComponentSphereTree >( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentSphereTree& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_lowestUnusedNodeIndex", in_data.m_lowestUnusedNodeIndex );
	in_out_mementoCollect.MemberAdd( "m_arrayNode", in_data.m_arrayNode );
	in_out_mementoCollect.MemberAdd( "m_arraySphere", in_data.m_arraySphere );
	in_out_mementoCollect.MemberAdd( "m_nodeOutsideTree", in_data.m_nodeOutsideTree );
	in_out_mementoCollect.MemberAdd( "m_sphereCollection", in_data.m_sphereCollection );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VSceneComponentSphereTree >( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentSphereTree& out_data )
{
	in_out_mementoAssign.MemberGet( "m_lowestUnusedNodeIndex", out_data.m_lowestUnusedNodeIndex );
	in_out_mementoAssign.MemberGet( "m_arrayNode", out_data.m_arrayNode );
	in_out_mementoAssign.MemberGet( "m_arraySphere", out_data.m_arraySphere );
	in_out_mementoAssign.MemberGet( "m_nodeOutsideTree", out_data.m_nodeOutsideTree );
	in_out_mementoAssign.MemberGet( "m_sphereCollection", out_data.m_sphereCollection );

	return;
}

/**/
HVOID Envy::EMementoTraitCollect< VSceneComponentNodeCollection >( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentNodeCollection& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayChildrenNodeIndex", in_data.ArrayChildrenNodeIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_combinedComponentFlag", in_data.CombinedComponentFlagGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VSceneComponentNodeCollection >( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentNodeCollection& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayChildrenNodeIndex", out_data.ArrayChildrenNodeIndexGet() );
	HSINT flag = 0;
	in_out_mementoAssign.MemberGet( "m_combinedComponentFlag", flag );
	out_data.CombinedComponentFlagSet( flag );
	return;
}

/**/
HVOID Envy::EMementoTraitCollect< VSceneComponentSphereCollection >( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentSphereCollection& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayChildrenSphereIndex", in_data.ArrayChildrenSphereIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_combinedComponentFlag", in_data.CombinedComponentFlagGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VSceneComponentSphereCollection >( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentSphereCollection& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayChildrenSphereIndex", out_data.ArrayChildrenSphereIndexGet() );
	HSINT flag = 0;
	in_out_mementoAssign.MemberGet( "m_combinedComponentFlag", flag );
	out_data.CombinedComponentFlagSet( flag );
	return;
}
/**/
HVOID Envy::EMementoTraitCollect< VSceneNode >( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneNode& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_sphere", in_data.SphereGet() );

	//const VSceneItemComponentRotation* pRotation = HNULL;
	//if( HTRUE == in_data.ComponentRotationTest() )
	//{
	//	pRotation = &in_data.ComponentRotationGet();
	//}
	//in_out_mementoCollect.OwnedPointerAdd( "m_pRotation", pRotation );
	in_out_mementoCollect.OwnedPointerAdd( "m_pRotation", in_data.m_pRotation );

	in_out_mementoCollect.MemberAdd( "m_parentSphereIndex", in_data.ParentSphereIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_componentFlag", in_data.ComponentFlagGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VSceneNode >( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneNode& out_data )
{
	PSphereR3 sphere;
	in_out_mementoAssign.MemberGet( "m_sphere", sphere );
	out_data.SphereSet( sphere );

	in_out_mementoAssign.OwnedPointerGet( "m_pRotation", out_data.m_pRotation );

	//VSceneItemComponentRotation* pRotation = HNULL;
	//if( HNULL != pRotation )
	//{
	//	out_data.RotationSet( pRotation->RotationGet() );
	//	HCOMMON_DELETE( pRotation, VSceneItemComponentRotation );
	//}

	HSINT parentSphereIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_parentSphereIndex", parentSphereIndex );
	out_data.ParentSphereIndexSet( parentSphereIndex );

	HSINT componentFlag = 0;
	in_out_mementoAssign.MemberGet( "m_componentFlag", componentFlag );
	out_data.ComponentFlagSet( componentFlag );

	return;
}

/**/
HVOID Envy::EMementoTraitCollect< VSceneComponentSphereTreeSphere >( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentSphereTreeSphere& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_sphere", in_data.SphereGet() );
	in_out_mementoCollect.MemberAdd( "m_sphereCollection", in_data.SphereCollectionGet() );
	in_out_mementoCollect.MemberAdd( "m_nodeCollection", in_data.NodeCollectionGet() );
	in_out_mementoCollect.MemberAdd( "m_parentSphereIndex", in_data.ParentSphereIndexGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VSceneComponentSphereTreeSphere >( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentSphereTreeSphere& out_data )
{
	in_out_mementoAssign.MemberGet( "m_sphere", out_data.SphereGet() );
	in_out_mementoAssign.MemberGet( "m_sphereCollection", out_data.SphereCollectionGet() );
	in_out_mementoAssign.MemberGet( "m_nodeCollection", out_data.NodeCollectionGet() );
	HSINT parentSphereIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_parentSphereIndex", parentSphereIndex );
	out_data.ParentSphereIndexSet( parentSphereIndex );

	return;
}

/**/

/**/
HVOID Envy::EMementoTraitCollect< VSceneItemComponentRotation >( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneItemComponentRotation& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_rotation", in_data.RotationGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VSceneItemComponentRotation >( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneItemComponentRotation& out_data )
{
	HQuaternionREAL rotation;
	in_out_mementoAssign.MemberGet( "m_rotation", rotation );
	out_data.RotationSet( rotation );
	return;
}

///////////////////////////////////////////////////////////
// global functions
/**/
Hubris::HVOID Vanity::VComponentSceneTraitFactoryRegister()
{
	EMEMENTO_FACTORY_REGISTER( VSceneItemComponentRotation, VSceneItemComponentRotation );
	return;
}

/**/