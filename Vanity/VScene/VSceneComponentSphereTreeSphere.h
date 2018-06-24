//file: Vanity/VScene/VSceneComponentSphereTreeSphere.h
#ifndef _V_SCENE_COMPONENT_SPHERE_TREE_SPHERE_H_
#define _V_SCENE_COMPONENT_SPHERE_TREE_SPHERE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneComponentSphereCollection.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneNode;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneComponentSphereTreeSphere
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneComponentSphereTreeSphere( const VSceneComponentSphereTreeSphere& in_src );
		VSceneComponentSphereTreeSphere(
			const Pride::PSphereR3& in_sphere,
			const Hubris::HSINT in_parentSphereIndex
			);
		VSceneComponentSphereTreeSphere();
		~VSceneComponentSphereTreeSphere();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VSceneComponentSphereTreeSphere& operator=( const VSceneComponentSphereTreeSphere& in_rhs );
		const Hubris::HBOOL operator==( const VSceneComponentSphereTreeSphere& in_rhs );
		const Hubris::HBOOL operator!=( const VSceneComponentSphereTreeSphere& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID SphereAdd( 
			const Hubris::HSINT in_sphereIndex
			);

		//return HTRUE on change of component flag
		const Hubris::HBOOL NodeAdd( 			
			const TArrayNode& in_arrayNodes,
			const Hubris::HSINT in_nodeIndex 
			);
		//return HTRUE on change of component flag
		const Hubris::HBOOL NodeRemove( 
			const TArrayNode& in_arrayNodes,
			const Hubris::HSINT in_nodeIndex 
			);

		const Hubris::HSINT CombinedComponentFlagGet()const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PSphereR3& SphereGet()const{ return m_sphere; }
		Pride::PSphereR3& SphereGet(){ return m_sphere; }

		const Hubris::HSINT ParentSphereIndexGet()const{ return m_parentSphereIndex; }
		Hubris::HVOID ParentSphereIndexSet( const Hubris::HSINT in_parentSphereIndex ){ m_parentSphereIndex = in_parentSphereIndex; return; }

		const VSceneComponentNodeCollection& NodeCollectionGet()const{ return m_nodeCollection; }
		VSceneComponentNodeCollection& NodeCollectionGet(){ return m_nodeCollection; }

		const VSceneComponentSphereCollection& SphereCollectionGet()const{ return m_sphereCollection; }
		VSceneComponentSphereCollection& SphereCollectionGet(){ return m_sphereCollection; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PSphereR3 m_sphere;

		Hubris::HSINT m_parentSphereIndex;

		VSceneComponentNodeCollection m_nodeCollection;
		VSceneComponentSphereCollection m_sphereCollection;
	};

	/**/
	
};

#endif // _V_SCENE_COMPONENT_SPHERE_TREE_SPHERE_H_