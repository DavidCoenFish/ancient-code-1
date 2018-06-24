//file: Vanity/VScene/VSceneVisitorAll.h
#ifndef _V_SCENE_VISITOR_ALL_H_
#define _V_SCENE_VISITOR_ALL_H_

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
	class VSceneVisitorAll
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
			const Hubris::HSINT in_componentFlag //item must match any of the flags to be exposed to query
			);

		static Hubris::HVOID VisitUnsortedNodeCollection(
			TArrayItemId& out_arrayItemId,
			const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
			const TArrayNode& in_arrayNode,
			const Hubris::HSINT in_componentFlag
			);

		static Hubris::HVOID VisitUnsortedSphere(
			TArrayItemId& out_arrayItemId,
			const TArraySphere& in_arraySphere,
			const TArrayNode& in_arrayNode,
			const Hubris::HSINT in_componentFlag,
			const Hubris::HSINT in_sphereIndex
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~VSceneVisitorAll();

	};

	/**/
	
};

#endif // _V_SCENE_VISITOR_ALL_H_