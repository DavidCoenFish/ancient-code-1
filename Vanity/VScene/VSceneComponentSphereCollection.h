//file: Vanity/VScene/VSceneComponentSphereCollection.h
#ifndef _V_SCENE_COMPONENT_SPHERE_COLLECTION_H_
#define _V_SCENE_COMPONENT_SPHERE_COLLECTION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneComponentSphereTreeSphere;
	class VSceneNode;
	class VSceneFan;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VSceneComponentSphereCollection
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( Hubris::HSINT, Hubris::HREAL ) >TFunctorVisitorSorted;

		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneComponentSphereCollection( const VSceneComponentSphereCollection& in_src );
		VSceneComponentSphereCollection();
		~VSceneComponentSphereCollection();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VSceneComponentSphereCollection& operator=( const VSceneComponentSphereCollection& in_rhs );
		const Hubris::HBOOL operator==( const VSceneComponentSphereCollection& in_rhs );
		const Hubris::HBOOL operator!=( const VSceneComponentSphereCollection& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

		Hubris::HVOID SphereAdd( const Hubris::HSINT in_sphereIndex );
		Hubris::HVOID SphereRemove( const Hubris::HSINT in_sphereIndex );

		const Hubris::HSINT ParentSphereFind(
			const TArraySphere& in_arraySphere,
			const Pride::PSphereR3& in_sphereTest,
			Hubris::HREAL& in_out_bestRadius
			)const;

		//return HTRUE on change of component flag, for upward propergation of change
		const Hubris::HBOOL ComponentFlagUpdate( 
			const TArraySphere& in_arraySphere
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT CombinedComponentFlagGet()const{ return m_combinedComponentFlag; }
		Hubris::HVOID CombinedComponentFlagSet( const Hubris::HSINT in_combinedComponentFlag ){ m_combinedComponentFlag = in_combinedComponentFlag; return; }

		const TArraySint& ArrayChildrenSphereIndexGet()const{ return m_arrayChildrenSphereIndex; }
		TArraySint& ArrayChildrenSphereIndexGet(){ return m_arrayChildrenSphereIndex; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArraySint m_arrayChildrenSphereIndex;
		//the combined flag of all the child spheres
		Hubris::HSINT m_combinedComponentFlag;

	};

	/**/
	
};

#endif // _V_SCENE_COMPONENT_SPHERE_COLLECTION_H_