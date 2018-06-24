//file: Vanity/VScene/VScene.h
#ifndef _V_SCENE_H_
#define _V_SCENE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VScene/VSceneUtility.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;

};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//VScene
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VScene& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VScene& out_data );
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneApplicationInterface;
	class VSceneImplementation;
	class VSceneTriangle;
	class VSceneSegment;
	class VSceneConvexHull;
	class VSceneItemComponentRotation;

	class VComponentCollisionInterfaceObject;
	class VComponentDynamicInterfaceObject;
	class VComponentGameInterfaceObject;
	class VComponentForceInterfaceObject;
	class VComponentLightEmitterInterfaceObject;
	class VComponentLightReceiverInterfaceObject;
	class VComponentSoundEmitterInterfaceObject;
	class VComponentSoundReceiverInterfaceObject;
	class VComponentVisualInterfaceObject;

	///////////////////////////////////////////////////////
	// class
	/*
		a scene owns components, and a sphere tree (or something)
		insert items, and gather results from items
		public interface of components via a interface object for each component

		TODO: was wrong the put render interface ownership under scene, register render id is ok...

		POLICY: simplify, resource acusition on load of item, 
			rather than have load pass and render resource aquire on items
			if you want streaming, need to redesign anyrate.
			 means entire level must fit in memory
			
	*/
	class VScene
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VScene >( Envy::EMementoCollect& in_out_mementoCollect, const VScene& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VScene >( const Envy::EMementoAssign& in_out_mementoAssign, VScene& out_data );
		//draw sphere tree
		friend static Hubris::HVOID VSceneUtility::RenderSphereTree( VScene& in_out_scene, const Hubris::HSINT in_rendererId, VSceneApplicationInterface& in_sceneApplicationInterface, const Pride::PConvexHull& in_cameraFustrumHull );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< TItemId >TArrayItemId;
		//visitor functor, return HFALSE to stop
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( TItemId, Hubris::HREAL ) >TFunctorVisitorSorted;

		///////////////////////////////////////////////////////
		// creation
	public:
		//component flag is made of the componets to be created for the scene
		VScene( const Hubris::HSINT in_objectFlag );
		VScene();
		~VScene();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VScene( const VScene& in_src );
		const VScene& operator=( const VScene& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		//adds an item, return the index of the item in the scene
		const TItemId ItemAdd(
			const Hubris::HSINT in_objectFlag, //valid component data, filter query
			const Pride::PSphereR3& in_sphere,
			const Hubris::HQuaternionREAL* const in_pRotation = HNULL //an item can have no rotation
			);
		Hubris::HVOID ItemRemove(
			const TItemId in_itemId
			);
		Hubris::HVOID ItemPositionChange( 
			const TItemId in_itemId, 
			const Pride::PSphereR3& in_sphere
			);
		Hubris::HVOID ItemRotateChange( 
			const TItemId in_itemId, 
			const Hubris::HQuaternionREAL& in_rotation
			);

		Hubris::HVOID ItemDataGet(
			const TItemId in_itemId,
			Hubris::HSINT* out_pObjectFlag = HNULL,
			Pride::PSphereR3* out_pSphere = HNULL,
			const VSceneItemComponentRotation** out_pRotationComponent = HNULL
			)const;
		const Hubris::HSINT ItemObjectFlagGet(
			const TItemId in_itemId
			)const;
		const Pride::PSphereR3& ItemSphereGet(
			const TItemId in_itemId
			)const;

		//return true if item has rotation
		const Hubris::HBOOL ItemRotationTest(
			const TItemId in_itemId
			)const;
		//get the rotation component, could be NULL so ItemRotationTest()
		const VSceneItemComponentRotation& ItemComponentRotationGet(
			const TItemId in_itemId
			)const;

		//register a name for an item
		Hubris::HVOID ItemNameSet(
			const TItemId in_itemId,
			const Hubris::HString& in_itemName
			);
		//find item id for name, HCOMMON_INVALID_INDEX if not found
		const TItemId ItemNameIndexGet(
			const Hubris::HString& in_itemName
			);

		//after insert a lot of items, refreash the internal data, ie. update sphere tree. could be slow
		Hubris::HVOID ItemStructureRefreash();

		/*
			undecided if functor or array is better for collecting visitors.
			functor allows bail (good for sort) but suspect it will be slower (bad coherency)
		*/
		Hubris::HVOID SubmitVisitorUnsortedAll(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_objectFlag //item must match any of the flags to be exposed to query
			)const;
		Hubris::HVOID SubmitVisitorUnsortedSphere(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
			const Pride::PSphereR3& in_sphere
			)const;
		Hubris::HVOID SubmitVisitorUnsortedTriangle(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
			const Pride::PTriangle& in_triangle
			)const;
		Hubris::HVOID SubmitVisitorUnsortedSegment(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
			const Pride::PLineR3& in_segment
			)const;
		Hubris::HVOID SubmitVisitorUnsortedBounds(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
			const Pride::PBoundsR3& in_bounds
			)const;
		Hubris::HVOID SubmitVisitorUnsortedConvexHull(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
			const Pride::PConvexHull& in_convexHull
			)const;

		//return nodes along ray in order
		Hubris::HVOID SubmitVisitorSortedRay(
			TFunctorVisitorSorted& in_functorVisitor,
			const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
			const Pride::PLineR3& in_line,
			const Hubris::HREAL in_lineMaximumLength
			)const;

		Hubris::HVOID SubmitVisitorSortedHull(
			TFunctorVisitor& in_functorVisitor,
			const Hubris::HSINT in_objectFlag, //item must match any of the flags to be exposed to query
			const Hubris::HVectorR3& in_direction, //sort hint
			const Pride::PConvexHull& in_hull,
			const Pride::PSphereR3& in_sphereContainingHull
			)const;

		Hubris::HVOID NewFrame();
		//update the scene with some camera data, used for particle billboard
		Hubris::HVOID SceneCameraSet(
			const Pride::PCamera& in_camera
			);

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT FlagComponentCollisionGet();
		static const Hubris::HSINT FlagComponentDynamicGet();
		static const Hubris::HSINT FlagComponentGameGet();
		static const Hubris::HSINT FlagComponentForceGet();
		static const Hubris::HSINT FlagComponentLightEmitterGet();
		static const Hubris::HSINT FlagComponentLightReceiverGet();
		static const Hubris::HSINT FlagComponentSoundEmitterGet();
		static const Hubris::HSINT FlagComponentSoundReceiverGet();
		static const Hubris::HSINT FlagComponentVisualGet();

		//static const Hubris::HSINT FlagTickComponentDynamicGet();
		//static const Hubris::HSINT FlagTickComponentGameGet();

		static const Hubris::HSINT FlagStaticGet(); //object doesn't move or get removed after world load, ie, a static light in the scene, static geometry, static collision

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT ComponentFlagGet()const;
		Hubris::HVOID ComponentFlagSet( const Hubris::HSINT in_componentFlag );

		//access component function via component interface objects
		//assert if scene was not create with component
		VComponentCollisionInterfaceObject InterfaceObjectCollisionGet();
		VComponentDynamicInterfaceObject InterfaceObjectDynamicGet();
		VComponentGameInterfaceObject InterfaceObjectGameGet();
		VComponentForceInterfaceObject InterfaceObjectForceGet();
		VComponentLightEmitterInterfaceObject InterfaceObjectLightEmitterGet();
		VComponentLightReceiverInterfaceObject InterfaceObjectLightReceiverGet();
		VComponentSoundEmitterInterfaceObject InterfaceObjectSoundEmitterGet();
		VComponentSoundReceiverInterfaceObject InterfaceObjectSoundReceiverGet();
		VComponentVisualInterfaceObject InterfaceObjectVisualGet();

		const Hubris::HSINT FrameIDGet()const;
		//access the camera settings for the scene, ie, for billboard particles of camera relative player input
		const Hubris::HVectorR3& CameraVectorAtGet()const;
		const Hubris::HVectorR3& CameraVectorUpGet()const;
		const Hubris::HVectorR3& CameraVectorRightGet()const;

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const VSceneImplementation& ImplementationGet()const;
		VSceneImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		VSceneImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _V_SCENE_H_