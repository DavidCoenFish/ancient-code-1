//file: Vanity/VScene/VSceneVisitorSortedHull.h
#ifndef _V_SCENE_VISITOR_SORTED_HULL_H_
#define _V_SCENE_VISITOR_SORTED_HULL_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneComponentNodeCollection;
	class VSceneComponentSphereCollection;
	class VSceneComponentSphereTreeSphere;
	class VSceneNode;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneVisitorSortedHull
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID VisitSortedHull(
			TFunctorVisitorSorted& in_functorVisitor,
			const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
			const VSceneComponentSphereCollection& in_collectionSphere,
			const TArraySphere& in_arraySphere,
			const TArrayNode& in_arrayNode,
			const Hubris::HSINT in_componentFlag,
			const Hubris::HVectorR3& in_direction,
			const Pride::PConvexHull& in_hull,
			const Pride::PSphere& in_sphereContainingHull
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~VSceneVisitorSortedHull();

	};

	/**/
	
};

#endif // _V_SCENE_VISITOR_SORTED_HULL_H_