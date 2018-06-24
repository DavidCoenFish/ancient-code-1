//file: Vanity/VScene/VSceneVisitorRay.h
#ifndef _V_SCENE_VISITOR_RAY_H_
#define _V_SCENE_VISITOR_RAY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneComponentSphereCollection;
	class VSceneComponentSphereTreeSphere;
	class VSceneComponentNodeCollection;
	class VSceneNode;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneVisitorRay
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( Hubris::HSINT, Hubris::HREAL ) >TFunctorVisitorSorted;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID VisitSorted(
			TFunctorVisitorSorted& in_functorVisitor,
			const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
			const VSceneComponentSphereCollection& in_collectionSphere,
			const TArraySphere& in_arraySphere,
			const TArrayNode& in_arrayNode,
			const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
			const Pride::PLineR3& in_line,
			const Hubris::HREAL in_lineMaximumLength
			);
		///////////////////////////////////////////////////////
		// disabled
	private:
		~VSceneVisitorRay();

	};

	/**/
	
};

#endif // _V_SCENE_VISITOR_RAY_H_