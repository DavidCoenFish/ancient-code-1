//file: Vanity/VScene/VSceneUtility.h
#ifndef _V_SCENE_UTILITY_H_
#define _V_SCENE_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInterfaceRender;
	class SLight;
	class SComponentDelta;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;
	class VScene;
	class VSceneApplicationInterface;
	class VComponentCollisionResultBase;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct VSceneUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< Sloth::SLight >TArrayLight;

		///////////////////////////////////////////////////////
		// disabled
	private:
		~VSceneUtility();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//update the static ligh receivers for the static light emitters 
		static Hubris::HVOID StaticLightsUpdate( VScene& in_out_scene );

		static Hubris::HVOID DynamicLightsUpdate( 
			VScene& in_out_scene,
			const Pride::PSphereR3& in_sphere
			);

		static Hubris::HVOID PrimeScene( 
			VScene& in_out_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		static Hubris::HVOID PhaseAllGameObjects( 
			VScene& in_out_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		static Hubris::HVOID TextureAliasUpdate( 
			Sloth::SInterfaceRender& in_out_interfaceRender,
			VSceneApplicationInterface& in_sceneApplicationInterface
			);

		static Hubris::HVOID RenderScene( 
			VScene& in_out_scene,
			const Hubris::HSINT in_rendererId,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HVectorR3& in_cameraDirection,
			const Pride::PConvexHull& in_cameraFustrumHull,
			const Pride::PSphereR3& in_cameraFustrumSphere
			);

		//debug render of sphere tree
		static Hubris::HVOID RenderSphereTree( 
			VScene& in_out_scene,
			const Hubris::HSINT in_rendererId,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Pride::PConvexHull& in_cameraFustrumHull
			);

		//debug render of collision
		static Hubris::HVOID RenderCollision( 
			VScene& in_out_scene,
			const Hubris::HSINT in_rendererId,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HVectorR3& in_cameraDirection,
			const Pride::PConvexHull& in_cameraFustrumHull,
			const Pride::PSphereR3& in_cameraFustrumSphere
			);

		static Hubris::HVOID ItemMatrixGet(
			Hubris::HMatrixR4& out_modelMatrix,
			const VScene& in_scene,
			const TItemId in_itemId
			);
		static Hubris::HVOID ItemMatrixGet(
			Hubris::HMatrixR4& out_modelMatrix,
			Hubris::HMatrixR4& out_invertModel,
			const VScene& in_scene,
			const TItemId in_itemId
			);

		//set the item model transform for a scene item. allow optimisation for items with no rotation
		static Hubris::HVOID RenderItemMatrixSet(
			const TItemId in_itemId,
			const VScene& in_scene,
			Sloth::SInterfaceRender& in_render
			);

		static Hubris::HVOID GatherLightsOnObject(
			VScene& in_out_scene,
			const TItemId in_itemId,
			TArrayLight& out_arrayLight,
			Pride::PColourRealRgb& out_globalAmbient
			);

		//if the scene has a force component, return the forces on a point
		static Hubris::HVOID SampleForce(
			Hubris::HVectorR3& out_force,
			VScene& in_out_scene,
			const Hubris::HSINT in_forceFlag, //what forces are we looking for
			const Hubris::HVectorR3& in_location,
			const Hubris::HREAL in_massInvert = 1.0F
			);

		//return true if there is a collision
		static const Hubris::HBOOL CollideRay(
			VComponentCollisionResultBase& in_out_collisionResult,
			VScene& in_out_scene,
			const Pride::PLineR3& in_ray,
			const Hubris::HREAL in_rayMaxLength,
			const Hubris::HREAL in_rayThickness = 0.0F
			);

	};

	/**/
	
};

#endif // _V_SCENE_H_