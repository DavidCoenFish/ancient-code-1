//file: Vanity/VScene/VSceneComponentNodeCollection.h
#ifndef _V_SCENE_COMPONENT_NODE_COLLECTION_H_
#define _V_SCENE_COMPONENT_NODE_COLLECTION_H_

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
	class VSceneComponentNodeCollection
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( Hubris::HSINT, Hubris::HREAL ) >TFunctorVisitorSorted;

		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneComponentNodeCollection( const VSceneComponentNodeCollection& in_src );
		VSceneComponentNodeCollection();
		~VSceneComponentNodeCollection();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VSceneComponentNodeCollection& operator=( const VSceneComponentNodeCollection& in_rhs );
		const Hubris::HBOOL operator==( const VSceneComponentNodeCollection& in_rhs );
		const Hubris::HBOOL operator!=( const VSceneComponentNodeCollection& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

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

		//return HTRUE on change
		const Hubris::HBOOL ComponentFlagUpdate( 
			const TArrayNode& in_arrayNodes
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT CombinedComponentFlagGet()const{ return m_combinedComponentFlag; }
		Hubris::HVOID CombinedComponentFlagSet( const Hubris::HSINT in_combinedComponentFlag ){ m_combinedComponentFlag = in_combinedComponentFlag; return; }

		const TArraySint& ArrayChildrenNodeIndexGet()const{ return m_arrayChildrenNodeIndex; }
		TArraySint& ArrayChildrenNodeIndexGet(){ return m_arrayChildrenNodeIndex; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArraySint m_arrayChildrenNodeIndex;
		Hubris::HSINT m_combinedComponentFlag;

	};

	/**/
	
};

#endif // _V_SCENE_COMPONENT_NODE_COLLECTION_H_