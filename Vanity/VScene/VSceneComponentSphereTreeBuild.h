//file: Vanity/VScene/VSceneComponentSphereTreeBuild.h
#ifndef _V_SCENE_COMPONENT_SPHERE_TREE_BUILD_H_
#define _V_SCENE_COMPONENT_SPHERE_TREE_BUILD_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneNode;
	class VSceneComponentSphereTreeSphere;
	class VSceneComponentNodeCollection;
	class VSceneComponentSphereCollection;


	///////////////////////////////////////////////////////
	// struct
	/*
	*/
	struct VSceneComponentSphereTreeBuild
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID Build(
			TArrayNode& in_out_arrayNode,
			TArraySphere& in_out_arraySphere,
			VSceneComponentNodeCollection& in_out_nodeOutsideTree,
			VSceneComponentSphereCollection& in_out_sphereCollection
			);

		///////////////////////////////////////////////////////
		// disabled
	public:
		~VSceneComponentSphereTreeBuild();

	};

	/**/
	
};

#endif // _V_SCENE_COMPONENT_SPHERE_TREE_BUILD_H_