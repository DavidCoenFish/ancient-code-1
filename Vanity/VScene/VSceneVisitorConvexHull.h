//file: Vanity/VScene/VSceneVisitorConvexHull.h
#ifndef _V_SCENE_VISITOR_CONVEX_HULL_H_
#define _V_SCENE_VISITOR_CONVEX_HULL_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneComponentNodeCollection;
	class VSceneSphere;
	class VSceneNode;
	class VSceneConvexHull;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneVisitorConvexHull
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VSceneSphere >TArraySphere;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID VisitUnsorted(
			TArrayItemId& out_arrayItemId,
			const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
			const TArraySphere& in_arraySphere,
			const TArrayNode& in_arrayNode,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PConvexHull& in_convexHull
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~VSceneVisitorConvexHull();

	};

	/**/
	
};

#endif // _V_SCENE_VISITOR_CONVEX_HULL_H_