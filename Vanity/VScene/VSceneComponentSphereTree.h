//file: Vanity/VScene/VSceneComponentSphereTree.h
#ifndef _V_SCENE_COMPONENT_SPHERE_TREE_H_
#define _V_SCENE_COMPONENT_SPHERE_TREE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneComponentSphereCollection.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"
#include "Vanity/VScene/VSceneNode.h"

#include "Vanity/VScene/VSceneUtility.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneComponentSphereTree;

};

EMEMENTO_TRAIT_HEADER( Vanity::VSceneComponentSphereTree );

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneApplicationInterface;
	class VSceneVisitorBase;
	class VSceneNodeBase;
	class VSceneNode;
	class VSceneSegment;
	class VSceneConvexHull;
	class VSceneTriangle;
	class VSceneItemComponentRotation;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VSceneComponentSphereTree
	{
		EMEMENTO_TRAIT_FRIEND( VSceneComponentSphereTree );

		//draw sphere tree
		friend static Hubris::HVOID VSceneUtility::RenderSphereTree( VScene& in_out_scene, const Hubris::HSINT in_rendererId, VSceneApplicationInterface& in_sceneApplicationInterface, const Pride::PConvexHull& in_cameraFustrumHull );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( Hubris::HSINT, Hubris::HREAL ) >TFunctorVisitorSorted;

		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneComponentSphereTree();
		~VSceneComponentSphereTree();

		///////////////////////////////////////////////////////
		// public methods
	public:
		//adds an item, return the index of the item in the scene
		const Hubris::HSINT ItemAdd(
			const Hubris::HSINT in_componentFlag, //which components see this object on queries, assert valid
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
		const Hubris::HSINT ItemComponentFlagGet(
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

		Hubris::HVOID BuildSphereTree();

		Hubris::HVOID SubmitVisitorUnsortedAll(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_componentFlag //item must match any of the flags to be exposed to query
			)const;
		Hubris::HVOID SubmitVisitorUnsortedSphere(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PSphereR3& in_sphere
			)const;
		Hubris::HVOID SubmitVisitorUnsortedTriangle(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PTriangle& in_triangle
			)const;
		Hubris::HVOID SubmitVisitorUnsortedSegment(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PLineR3& in_segment
			)const;
		Hubris::HVOID SubmitVisitorUnsortedBounds(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PBoundsR3& in_bounds
			)const;
		Hubris::HVOID SubmitVisitorUnsortedConvexHull(
			TArrayItemId& out_arrayItemId,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PConvexHull& in_convexHull
			)const;

		//return nodes along ray in order
		Hubris::HVOID SubmitVisitorSortedRay(
			TFunctorVisitorSorted& in_functorVisitor,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
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

		///////////////////////////////////////////////////////
		// private methods
	private:
		const Hubris::HSINT NodeAdd( 
			const Hubris::HSINT in_componentFlag, //which components see this object on queries, assert valid
			const Pride::PSphereR3& in_sphere,
			const Hubris::HQuaternionREAL* const in_pRotation = HNULL,
			const Hubris::HSINT in_sphereParentIndex = HCOMMON_INVALID_INDEX
			);
		Hubris::HVOID NodeRemove( const Hubris::HSINT in_index );

		///////////////////////////////////////////////////////
		// disabled
	public:
		VSceneComponentSphereTree( const VSceneComponentSphereTree& in_src );
		const VSceneComponentSphereTree& operator=( const VSceneComponentSphereTree& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_lowestUnusedNodeIndex;
		TArrayNode m_arrayNode;
		TArraySphere m_arraySphere;

		//the nodes that are outside spheres
		VSceneComponentNodeCollection m_nodeOutsideTree;

		//the top children spheres of tree
		VSceneComponentSphereCollection m_sphereCollection;

	};

	/**/
	
};

#endif // _V_SCENE_COMPONENT_SPHERE_TREE_H_