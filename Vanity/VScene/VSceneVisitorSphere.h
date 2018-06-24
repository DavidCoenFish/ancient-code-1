//file: Vanity/VScene/VSceneVisitorSphere.h
#ifndef _V_SCENE_VISITOR_SPHERE_H_
#define _V_SCENE_VISITOR_SPHERE_H_

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
	class VSceneVisitorSphere
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID VisitUnsorted(
			TArrayItemId& out_arrayItemId,
			const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
			const VSceneComponentSphereCollection& in_collectionSphere,
			const TArraySphere& in_arraySphere,
			const TArrayNode& in_arrayNode,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PSphereR3& in_testSphere
			);

		static const Hubris::HBOOL SphereSphereTest(
			const Hubris::HSINT in_componentFlag,
			const Pride::PSphereR3& in_sphere,
			const VSceneComponentSphereTreeSphere& in_sceneSphere
			);

		static const Hubris::HBOOL SphereNodeTest(
			const Hubris::HSINT in_componentFlag,
			const Pride::PSphereR3& in_sphere,
			const VSceneNode& in_sceneNode
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~VSceneVisitorSphere();

	};

	/**/
	
};

#endif // _V_SCENE_VISITOR_SPHERE_H_