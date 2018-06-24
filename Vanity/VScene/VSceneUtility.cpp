//file: Vanity/VScene/VSceneUtility.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneUtility.h"

#include "Vanity/VScene/VScene.h"
#include "Vanity/VScene/VSceneApplicationInterface.h"
#include "Vanity/VScene/VSceneImplementation.h"
#include "Vanity/VScene/VSceneItemComponentRotation.h"
#include "Vanity/VScene/VSceneComponentSphereTree.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"
#include "Vanity/VScene/VSceneUtilityHelperCollision.h"
#include "Vanity/VScene/VSceneUtilityHelperRender.h"
#include "Vanity/VScene/VSceneUtilityHelperRenderCollision.h"

#include "Vanity/VAsset/VAsset_Export.h"
#include "Vanity/VComponentCollision/VComponentCollision_Export.h"
#include "Vanity/VComponentForce/VComponentForce_Export.h"
#include "Vanity/VComponentGame/VComponentGame_Export.h"
#include "Vanity/VComponentLightReceiver/VComponentLightReceiver_Export.h"
#include "Vanity/VComponentLightEmitter/VComponentLightEmitter_Export.h"
#include "Vanity/VComponentVisual/VComponentVisual_Export.h"

#include "Sloth/Sloth_Export.h"

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
typedef Hubris::HSINT TItemId;
typedef Hubris::HContainerArray< TItemId >TArrayItemId;
typedef Hubris::HContainerArray< SLight >TArrayLight;
typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphereTreeSphere;
typedef Hubris::HContainerArray< Pride::PTriangle >TArrayTriangle;
typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;
typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( TItemId, Hubris::HREAL ) >TFunctorVisitorSorted;

///////////////////////////////////////////////////////
// static local methods
/**/
static HVOID LocalFindLights(
	VScene& in_out_scene,
	const TItemId in_lightReceiverId,
	const TArrayItemId& in_arrayStaticLights
	)
{
	const PSphereR3& receiverPos = in_out_scene.ItemSphereGet( in_lightReceiverId );
	TArrayItemId arrayLightsTouching;

	HCOMMON_FOR_EACH_CONST( lightId, in_arrayStaticLights, TArrayItemId )
	{
		if( HTRUE == PSphereUtility::SphereTouching( 
			receiverPos,
			in_out_scene.ItemSphereGet( lightId ) 
			) )
		{
			arrayLightsTouching.Insert( lightId );
		}
	}

	in_out_scene.InterfaceObjectLightReceiverGet().ArrayLightIdStaticSet(
		in_lightReceiverId,
		arrayLightsTouching
		);

	return;
}

/*
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( TItemId, Hubris::HREAL ) >TFunctorVisitorSorted;
*/

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VSceneUtility::StaticLightsUpdate( VScene& in_out_scene )
{
	//gather array of all non moving lights
	TArrayItemId arrayStaticLights;
	in_out_scene.SubmitVisitorUnsortedAll(
		arrayStaticLights,
		VScene::FlagStaticGet() | VScene::FlagComponentLightEmitterGet()
		);

	//gather array of all non moving light receivers
	TArrayItemId arrayStaticLightReceiver;
	in_out_scene.SubmitVisitorUnsortedAll(
		arrayStaticLightReceiver,
		VScene::FlagStaticGet() | VScene::FlagComponentLightReceiverGet()
		);

	HCOMMON_FOR_EACH_CONST( lightReceiverId, arrayStaticLightReceiver, TArrayItemId )
	{
		LocalFindLights(
			in_out_scene,
			lightReceiverId,
			arrayStaticLights
			);
	}

	return;
}

/**/
Hubris::HVOID VSceneUtility::DynamicLightsUpdate( 
	VScene& in_out_scene,
	const Pride::PSphereR3& in_sphere
	)
{
	in_out_scene;
	in_sphere;
	return;
}

/**/
Hubris::HVOID VSceneUtility::PrimeScene( 
	VScene& in_out_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	if( VScene::FlagComponentVisualGet() & in_out_scene.ComponentFlagGet() )
	{
		//gather all visual
		TArrayItemId arrayVisual;
		in_out_scene.SubmitVisitorUnsortedAll(
			arrayVisual,
			VScene::FlagComponentVisualGet()
			);

		//load all visual, make render resource for all visual
		VComponentVisualInterfaceObject visualInterface = in_out_scene.InterfaceObjectVisualGet();
		HCOMMON_FOR_EACH_CONST( itemId, arrayVisual, TArrayItemId )
		{
			visualInterface.Load( in_sceneApplicationInterface, itemId );
		}
	}

	if( VScene::FlagComponentCollisionGet() & in_out_scene.ComponentFlagGet() )
	{
		TArrayItemId arrayCollision;
		in_out_scene.SubmitVisitorUnsortedAll(
			arrayCollision,
			VScene::FlagComponentCollisionGet()
			);

		VComponentCollisionInterfaceObject collisionInterface = in_out_scene.InterfaceObjectCollisionGet();
		HCOMMON_FOR_EACH_CONST( itemId, arrayCollision, TArrayItemId )
		{
			collisionInterface.Load( in_sceneApplicationInterface, itemId );
		}
	}

	if( VScene::FlagComponentGameGet() & in_out_scene.ComponentFlagGet() )
	{
		TArrayItemId arrayGame;
		in_out_scene.SubmitVisitorUnsortedAll(
			arrayGame,
			VScene::FlagComponentGameGet()
			);

		VComponentGameInterfaceObject gameInterface = in_out_scene.InterfaceObjectGameGet();
		HCOMMON_FOR_EACH_CONST( itemId, arrayGame, TArrayItemId )
		{
			gameInterface.Load( in_sceneApplicationInterface, itemId );
			gameInterface.GameObjectCreate(
				in_sceneApplicationInterface,
				itemId 
				);
		}
	}

	return;
}

/**/
Hubris::HVOID VSceneUtility::PhaseAllGameObjects( 
	VScene& in_out_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	if( 0 == ( VScene::FlagComponentGameGet() & in_out_scene.ComponentFlagGet() ) )
	{
		return;
	}

	TArrayItemId arrayGame;
	in_out_scene.SubmitVisitorUnsortedAll(
		arrayGame,
		VScene::FlagComponentGameGet()
		);

	VComponentGameInterfaceObject gameInterface = in_out_scene.InterfaceObjectGameGet();
	for( HSINT index = 0; index < gameInterface.PhaseCountGet(); ++index )
	{
		HCOMMON_FOR_EACH_CONST( itemId, arrayGame, TArrayItemId )
		{
			gameInterface.Phase(
				in_out_scene,
				itemId,
				index,
				in_sceneApplicationInterface
				);
		}
	}

	return;
}

/**/
Hubris::HVOID VSceneUtility::TextureAliasUpdate( 
	Sloth::SInterfaceRender& in_out_interfaceRender,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	const HSINT maxTextureSize = in_out_interfaceRender.TextureSizeMaxGet();
	const HVectorS2 maxSize = HMatrixConstructor::HVectorS2Construct( maxTextureSize >>1, maxTextureSize >> 1 );
	in_sceneApplicationInterface.TextureAliasGet().GenerateTextureAlias( maxSize );

	in_out_interfaceRender.TextureSet( 0, in_sceneApplicationInterface.TextureAliasGet().ImageGet() );

	return;
}

/**/
Hubris::HVOID VSceneUtility::RenderScene( 
	VScene& in_out_scene,
	const Hubris::HSINT in_rendererId,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HVectorR3& in_cameraDirection,
	const Pride::PConvexHull& in_cameraFustrumHull,
	const Pride::PSphereR3& in_cameraFustrumSphere
	)
{
	if( 0 == ( VScene::FlagComponentVisualGet() & in_out_scene.ComponentFlagGet() ) )
	{
		return;
	}

	VSceneUtilityHelperRender renderSceneHelper(
		in_out_scene,
		in_rendererId,
		in_sceneApplicationInterface
		);

	TFunctorVisitor functor( renderSceneHelper, &VSceneUtilityHelperRender::VisitorSorted );

	in_out_scene.SubmitVisitorSortedHull(
		functor,
		VScene::FlagComponentVisualGet(),
		in_cameraDirection,
		in_cameraFustrumHull,
		in_cameraFustrumSphere
		);

	return;
}

/**/
Hubris::HVOID VSceneUtility::RenderSphereTree( 
	VScene& in_out_scene,
	const Hubris::HSINT in_rendererId,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Pride::PConvexHull& in_cameraFustrumHull
	)
{
	SInterfaceRender& interfaceRender = *( in_sceneApplicationInterface.RenderInterfaceGet( in_rendererId ) );
	//render a sphere around each node
	SMaterialStage materialNode;
	materialNode.AlphaSet( 0.2F );
	materialNode.BlendModeSourceSet( SMaterialStage::BlendModeSourceAlphaGet() );
	materialNode.BlendModeDestinationSet( SMaterialStage::BlendModeOneMinusSourceAlphaGet() );
	//materialNode.ColourDiffuseSet( PColourRealRgb( 0.5F, 0.5F, 1.0F ) );
	materialNode.ColourAmbientSet( PColourRealRgb( 0.5F, 0.5F, 1.0F ) );
	materialNode.FlagAlphaBlendSet( HTRUE );
	materialNode.FlagZWriteSet( HFALSE );
	materialNode.FlagUseLightSet( HTRUE );
	interfaceRender.MaterialSet( 
		materialNode
		);

	TArrayItemId arrayNode;
	in_out_scene.SubmitVisitorUnsortedAll(
		arrayNode,
		0
		);

	HMatrixR4 modelMatrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
	HCOMMON_FOR_EACH_CONST( nodeId, arrayNode, TArrayItemId )
	{
		const PSphereR3& sphere = in_out_scene.ItemSphereGet( nodeId );

		//bail is sphere is not on screen
		if( HFALSE == PConvexHullUtility::SphereHullTouch(
			in_cameraFustrumHull,
			sphere 
			) )
		{
			continue;
		}

		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( modelMatrix, sphere.CenterGet() );
		interfaceRender.ModelTransformSet( 
			modelMatrix
			);

		interfaceRender.DrawSphere( 
			sphere.RadiusGet()
			);
	}

	//render a sphere around each sphere tree sphere
	SMaterialStage materialSphere;
	materialSphere.AlphaSet( 0.2F );
	materialSphere.BlendModeSourceSet( SMaterialStage::BlendModeSourceAlphaGet() );
	materialSphere.BlendModeDestinationSet( SMaterialStage::BlendModeOneMinusSourceAlphaGet() );
	//materialSphere.ColourDiffuseSet( PColourRealRgb( 0.75F, 0.75F, 0.5F ) );
	materialSphere.ColourAmbientSet( PColourRealRgb( 0.75F, 0.75F, 0.5F ) );
	materialSphere.FlagAlphaBlendSet( HTRUE );
	materialSphere.FlagZWriteSet( HFALSE );
	materialSphere.FlagUseLightSet( HTRUE );
	interfaceRender.MaterialSet( 
		materialSphere
		);

	const TArraySphereTreeSphere& arraySphereTreeSpheres = in_out_scene.ImplementationGet().ComponentSphereTreeGet().m_arraySphere;
	HCOMMON_FOR_EACH_CONST( sphereTreeSphere, arraySphereTreeSpheres, TArraySphereTreeSphere )
	{
		const PSphereR3& sphere = sphereTreeSphere.SphereGet();

		//bail is sphere is not on screen
		if( HFALSE == PConvexHullUtility::SphereHullTouch(
			in_cameraFustrumHull,
			sphere 
			) )
		{
			continue;
		}

		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( modelMatrix, sphere.CenterGet() );
		interfaceRender.ModelTransformSet( 
			modelMatrix
			);

		interfaceRender.DrawSphere( 
			sphere.RadiusGet()
			);
	}

	return;
}

/**/
Hubris::HVOID VSceneUtility::RenderCollision( 
	VScene& in_out_scene,
	const Hubris::HSINT in_rendererId,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HVectorR3& in_cameraDirection,
	const Pride::PConvexHull& in_cameraFustrumHull,
	const Pride::PSphereR3& in_cameraFustrumSphere
	)
{
	if( 0 == ( VScene::FlagComponentCollisionGet() & in_out_scene.ComponentFlagGet() ) )
	{
		return;
	}

	SInterfaceRender& interfaceRender = *( in_sceneApplicationInterface.RenderInterfaceGet( in_rendererId ) );
	//make a alpha material for collision, no lighting
	SMaterialStage materialNode;
	materialNode.AlphaSet( 0.5F );
	materialNode.BlendModeSourceSet( SMaterialStage::BlendModeSourceAlphaGet() );
	materialNode.BlendModeDestinationSet( SMaterialStage::BlendModeOneMinusSourceAlphaGet() );
	materialNode.ColourDiffuseSet( PColourRealRgb( 0.5F, 1.0F, 0.5F ) );
	materialNode.ColourAmbientSet( PColourRealRgb( 0.5F, 1.0F, 0.5F ) );
	materialNode.FlagAlphaBlendSet( HTRUE );
	materialNode.FlagZWriteSet( HFALSE );
	materialNode.FlagUseLightSet( HTRUE );
	interfaceRender.MaterialSet( 
		materialNode
		);

	VSceneUtilityHelperRenderCollision renderSceneHelperCollision(
		in_out_scene,
		in_sceneApplicationInterface,
		in_rendererId
		);

	TFunctorVisitor functor( renderSceneHelperCollision, &VSceneUtilityHelperRenderCollision::VisitorSorted );

	in_out_scene.SubmitVisitorSortedHull(
		functor,
		VScene::FlagComponentCollisionGet(),
		in_cameraDirection,
		in_cameraFustrumHull,
		in_cameraFustrumSphere
		);

	return;
}

/**
Hubris::HVOID VSceneUtility::RenderHull( 
	VScene& in_out_scene,
	const Hubris::HSINT in_rendererId,
	Pride::PConvexHull& in_out_convexHull
	)
{
	TArrayTriangle arrayTriangle;
	PConvexHullUtility::ConvertToTriangles(
		arrayTriangle,
		in_out_convexHull
		);

	in_out_scene.RenderInterfaceGet( in_rendererId )->DrawTriangle( 
		arrayTriangle
		);

	return;
}

/**/
Hubris::HVOID VSceneUtility::ItemMatrixGet(
	Hubris::HMatrixR4& out_modelMatrix,
	const VScene& in_out_scene,
	const TItemId in_itemId
	)
{
	out_modelMatrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
	const PSphereR3& pos = in_out_scene.ItemSphereGet( in_itemId );

	if( HTRUE == in_out_scene.ItemRotationTest( in_itemId ) )
	{
		const HMatrixR3& rotationMatrix = in_out_scene.ItemComponentRotationGet( in_itemId ).RotationMatrixGet();

		HMatrixUtility::MinorMatrixSet< HMatrixR4, HMatrixR3 >( out_modelMatrix, rotationMatrix, 3, 3 );
		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_modelMatrix, pos.CenterGet() );
		//out_modelMatrixInvert = HMatrixUtility::Inverse( out_modelMatrix );
	}
	else
	{
		//out_modelMatrixInvert = out_modelMatrix;
		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_modelMatrix, pos.CenterGet() );
		//HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_modelMatrixInvert, -( pos.CenterGet() ) );
	}

	return;
}

/**/
Hubris::HVOID VSceneUtility::ItemMatrixGet(
	Hubris::HMatrixR4& out_modelMatrix,
	Hubris::HMatrixR4& out_modelMatrixInvert,
	const VScene& in_out_scene,
	const TItemId in_itemId
	)
{
	out_modelMatrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
	const PSphereR3& pos = in_out_scene.ItemSphereGet( in_itemId );

	if( HTRUE == in_out_scene.ItemRotationTest( in_itemId ) )
	{
		const VSceneItemComponentRotation& rotationComponent = in_out_scene.ItemComponentRotationGet( in_itemId );
		HMatrixUtility::MinorMatrixSet< HMatrixR4, HMatrixR3 >( out_modelMatrix, rotationComponent.RotationMatrixGet(), 3, 3 );
		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_modelMatrix, pos.CenterGet() );

		HMatrixUtility::MinorMatrixSet< HMatrixR4, HMatrixR3 >( out_modelMatrix, rotationComponent.RotationMatrixInvertedGet(), 3, 3 );
		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_modelMatrix, -( pos.CenterGet() ) );

		//out_modelMatrixInvert = HMatrixUtility::Inverse( out_modelMatrix );
	}
	else
	{
		out_modelMatrixInvert = out_modelMatrix;
		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_modelMatrix, pos.CenterGet() );
		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_modelMatrixInvert, -( pos.CenterGet() ) );
	}

	return;
}

/**/
Hubris::HVOID VSceneUtility::RenderItemMatrixSet(
	const TItemId in_itemId,
	const VScene& in_scene,
	Sloth::SInterfaceRender& in_render
	)
{
	const PSphereR3& pos = in_scene.ItemSphereGet( in_itemId );

	if( HTRUE == in_scene.ItemRotationTest( in_itemId ) )
	{
		//todo: speed this up? change remder omterface to raw arrays of floats?
		const HMatrixR3& rotationMatrix = in_scene.ItemComponentRotationGet( in_itemId ).RotationMatrixGet();
		HMatrixR4 modelMatrix;
		HMatrixUtility::MinorMatrixSet< HMatrixR4, HMatrixR3 >( modelMatrix, rotationMatrix, 3, 3 );
		HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( modelMatrix, pos.CenterGet() );
		modelMatrix[ 15 ] = 1.0F;

		in_render.ModelTransformSet( modelMatrix );
	}
	else
	{
		in_render.ModelTransformSet( pos.CenterGet() );
	}

	return;
}

/**/
Hubris::HVOID VSceneUtility::GatherLightsOnObject(
	VScene& in_out_scene,
	const TItemId in_itemId,
	TArrayLight& out_arrayLight,
	Pride::PColourRealRgb& out_globalAmbient
	)
{
	out_arrayLight.Clear();
	out_globalAmbient = PColourRealRgb();

	if( 0 == ( VScene::FlagComponentLightReceiverGet() & in_out_scene.ItemObjectFlagGet( in_itemId ) ) )
	{
		return;
	}

	TArrayItemId arrayLightId;
	in_out_scene.InterfaceObjectLightReceiverGet().ArrayLightIdGather(
		in_itemId,
		arrayLightId
		);

	VComponentLightEmitterInterfaceObject interfaceLightEmitter = in_out_scene.InterfaceObjectLightEmitterGet();
	HSINT mode;
	PColourRealRgb diffuse;
	HREAL falloffExponent;
	HREAL radius;

	const HSINT count = arrayLightId.SizeGet();
	out_arrayLight.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		TItemId lightId = arrayLightId[ index ];
		interfaceLightEmitter.LightGet( 
			lightId,
			mode,
			diffuse,
			falloffExponent,
			radius
			);

		SLight& light = out_arrayLight[ index ];
		const PSphereR3& sphere = in_out_scene.ItemSphereGet( lightId );

		light.ModeSet( mode );
		light.DiffuseSet( diffuse );
		light.FalloffExponentSet( falloffExponent );
		light.RadiusSet( radius );
		light.PositionSet( sphere.CenterGet() );

		if( ( SLight::ModeDirectGet() == mode ) ||
			( SLight::ModeSpotGet() == mode ) )
		{
			HVectorR3 vector = HMatrixConstructor::HVectorR3AxisZ();
			if( HTRUE == in_out_scene.ItemRotationTest( lightId ) )
			{
				vector = in_out_scene.ItemComponentRotationGet( lightId ).RotateVector( vector );
			}

			light.DirectionSet( vector );
		}
	}

	out_globalAmbient = interfaceLightEmitter.ColourAmbientGet();

	return;
}

/**/
Hubris::HVOID VSceneUtility::SampleForce(
	Hubris::HVectorR3& out_force,
	VScene& in_out_scene,
	const Hubris::HSINT in_forceFlag, //what forces are we looking for
	const Hubris::HVectorR3& in_location,
	const Hubris::HREAL in_massInvert
	)
{
	out_force = HVectorR3();

	if( 0 == ( VScene::FlagComponentVisualGet() & in_out_scene.ComponentFlagGet() ) )
	{
		return;
	}

	const VComponentForceInterfaceObject& interfaceObject = in_out_scene.InterfaceObjectForceGet();
	const VComponentForceSampleParam forceParam(
		in_forceFlag,
		in_location,
		in_massInvert
		);

	if( in_forceFlag & VComponentForce::FlagGetForceGravity() )
	{
		VComponentForce::SampleForceApplyAccelleration( 
			out_force,
			interfaceObject.GravitationalAccellerationGet(),
			forceParam
			);
	}

	TArrayItemId arrayForce;
	PSphereR3 sampleSphere;
	sampleSphere.CenterSet( in_location );

	in_out_scene.SubmitVisitorUnsortedSphere(
		arrayForce,
		VScene::FlagComponentVisualGet(),
		sampleSphere
		);

	HCOMMON_FOR_EACH_CONST( forceId, arrayForce, TArrayItemId )
	{
		interfaceObject.SampleForce(
			out_force,
			forceParam,
			in_out_scene,
			forceId
			);
	}

	return;
}

/**/
const Hubris::HBOOL VSceneUtility::CollideRay(
	VComponentCollisionResultBase& in_out_collisionResult,
	VScene& in_out_scene,
	const Pride::PLineR3& in_ray,
	const Hubris::HREAL in_rayMaxLength,
	const Hubris::HREAL in_rayThickness
	)
{
	if( 0 == ( VScene::FlagComponentCollisionGet() & in_out_scene.ComponentFlagGet() ) )
	{
		return HFALSE;
	}

	VSceneUtilityHelperCollision collisionSceneHelper(
		in_out_scene,
		in_out_collisionResult,
		in_ray,
		in_rayMaxLength,
		in_rayThickness
		);

	TFunctorVisitorSorted functor( collisionSceneHelper, &VSceneUtilityHelperCollision::VisitorSorted );

	in_out_scene.SubmitVisitorSortedRay(
		functor,
		VScene::FlagComponentCollisionGet(),
		in_ray,
		in_rayMaxLength
		);

	const HBOOL result = in_out_collisionResult.ValidGet();
	return result;
}


/**/
