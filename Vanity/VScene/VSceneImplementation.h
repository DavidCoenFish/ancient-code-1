//file: Vanity/VScene/VSceneImplementation.h
#ifndef _V_SCENE_IMPLEMENTATION_H_
#define _V_SCENE_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// forward declaration
	/**/
	class EStringTable;
};

namespace Sloth
{
	class SInterfaceRender;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declaration
	/**/
	class VAssetManager;
	class VComponentCollision;
	class VComponentDynamic;
	class VComponentGame;
	class VComponentForce;
	class VComponentLightEmitter;
	class VComponentLightReceiver;
	class VComponentSoundEmitter;
	class VComponentSoundReceiver;
	class VComponentVisual;
	class VSceneComponentSphereTree;
	class VSceneConvexHull;
	class VSceneItemComponentRotation;
	class VSceneNode;
	class VSceneNodeBase;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
		typedef Hubris::HContainerArray< Sloth::SInterfaceRender* >TArrayInterfaceRender;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( Hubris::HSINT, Hubris::HREAL ) >TFunctorVisitorSorted;
		typedef Hubris::HContainerPair< Hubris::HVectorR3, Hubris::HVectorR3 >TPairVectorVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneImplementation( const Hubris::HSINT in_componentFlag );
		VSceneImplementation();
		~VSceneImplementation();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VSceneImplementation( const VSceneImplementation& in_src );
		const VSceneImplementation& operator=( const VSceneImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		//adds an item, return the index of the item in the scene
		const Hubris::HSINT ItemAdd(
			const Hubris::HSINT in_objectFlag, //which components see this object on queries, assert valid
			const Pride::PSphereR3& in_sphere,
			const Hubris::HQuaternionREAL* const in_pRotation = HNULL
			);
		Hubris::HVOID ItemRemove(
			const Hubris::HSINT in_itemId
			);
		Hubris::HVOID ItemPositionChange( 
			const Hubris::HSINT in_itemId, 
			const Pride::PSphereR3& in_sphere
			);
		Hubris::HVOID ItemRotateChange( 
			const Hubris::HSINT in_itemId, 
			const Hubris::HQuaternionREAL& in_rotation
			);

		Hubris::HVOID ItemDataGet(
			const Hubris::HSINT in_itemId,
			Hubris::HSINT* out_pComponentFlag = HNULL,
			Pride::PSphereR3* out_pSphere = HNULL,
			const VSceneItemComponentRotation** out_pRotationComponent = HNULL
			)const;
		const Hubris::HSINT ItemObjectFlagGet(
			const Hubris::HSINT in_itemId
			)const;
		const Pride::PSphereR3& ItemSphereGet(
			const Hubris::HSINT in_itemId
			)const;
		//return true if item has rotation
		const Hubris::HBOOL ItemRotationTest(
			const Hubris::HSINT in_itemId
			)const;

		//get the rotation component, could be NULL
		const VSceneItemComponentRotation& ItemComponentRotationGet(
			const Hubris::HSINT in_itemId
			)const;

		//register a name for an item
		Hubris::HVOID ItemNameSet(
			const Hubris::HSINT in_itemId,
			const Hubris::HString& in_itemName
			);

		//find item id for name, HCOMMON_INVALID_INDEX if not found
		const Hubris::HSINT ItemNameIndexGet(
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
		// private methods
	private:
		Hubris::HVOID ComponentRelease();
		Hubris::HVOID ComponentCreate();

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

		static const Hubris::HSINT FlagTickComponentDynamicGet();
		static const Hubris::HSINT FlagTickComponentGameGet();

		static const Hubris::HSINT FlagStaticGet(); //object doesn't move or get removed after world load, ie, a static light in the scene, static geometry, collision

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT ComponentFlagGet()const{ return m_componentFlag; }
		Hubris::HVOID ComponentFlagSet( const Hubris::HSINT in_componentFlag );

		const VSceneComponentSphereTree& ComponentSphereTreeGet()const;
		VSceneComponentSphereTree& ComponentSphereTreeGet();

		//assert if scene was not create with component
		const VComponentCollision& ComponentCollisionGet()const;
		VComponentCollision& ComponentCollisionGet();

		const VComponentDynamic& ComponentDynamicGet()const;
		VComponentDynamic& ComponentDynamicGet();

		const VComponentGame& ComponentGameGet()const;
		VComponentGame& ComponentGameGet();

		const VComponentForce& ComponentForceGet()const;
		VComponentForce& ComponentForceGet();

		const VComponentLightEmitter& ComponentLightEmitterGet()const;
		VComponentLightEmitter& ComponentLightEmitterGet();

		const VComponentLightReceiver& ComponentLightReceiverGet()const;
		VComponentLightReceiver& ComponentLightReceiverGet();

		const VComponentSoundEmitter& ComponentSoundEmitterGet()const;
		VComponentSoundEmitter& ComponentSoundEmitterGet();

		const VComponentSoundReceiver& ComponentSoundReceiverGet()const;
		VComponentSoundReceiver& ComponentSoundReceiverGet();

		const VComponentVisual& ComponentVisualGet()const;
		VComponentVisual& ComponentVisualGet();

		const Envy::EStringTable& StringTableItemNameGet()const{ return m_stringTableItemName; }
		Envy::EStringTable& StringTableItemNameGet(){ return m_stringTableItemName; }

		const Hubris::HSINT FrameIDGet()const{ return m_frameId; }
		const Hubris::HVectorR3& CameraVectorAtGet()const{ return m_cameraVectorAt; }
		const Hubris::HVectorR3& CameraVectorUpGet()const{ return m_cameraVectorUp; }
		const Hubris::HVectorR3& CameraVectorRightGet()const{ return m_cameraVectorRight; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_componentFlag;

		VSceneComponentSphereTree* m_pComponentSphereTree;

		VComponentCollision* m_pComponentCollision;
		VComponentDynamic* m_pComponentDynamic;
		VComponentGame* m_pComponentGame;
		VComponentForce* m_pComponentForce;
		VComponentLightEmitter* m_pComponentLightEmitter;
		VComponentLightReceiver* m_pComponentLightReceiver;
		VComponentSoundEmitter* m_pComponentSoundEmitter;
		VComponentSoundReceiver* m_pComponentSoundReceiver;
		VComponentVisual* m_pComponentVisual;

		//table of named items, maps to itemId
		Envy::EStringTable m_stringTableItemName;

		//transiant properties of the scene, frameId, scene camera
		Hubris::HSINT m_frameId;
		Hubris::HVectorR3 m_cameraVectorAt;
		Hubris::HVectorR3 m_cameraVectorUp;
		Hubris::HVectorR3 m_cameraVectorRight;


	};

	/**/
	
};

#endif // _V_SCENE_H_