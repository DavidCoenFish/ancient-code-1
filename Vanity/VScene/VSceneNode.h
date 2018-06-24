//file: Vanity/VScene/VSceneNode.h
#ifndef _V_SCENE_NODE_H_
#define _V_SCENE_NODE_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Vanity
{
	class VSceneVisitorBase;
	class VSceneItemComponentRotation;
	class VSceneNode;
};
namespace Envy												
{															
	class EMementoCollect;									
	class EMementoAssign;									
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneNode& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneNode& out_data );
};

///////////////////////////////////////////////////////
// class
namespace Vanity
{
	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneNode
	{
		friend Hubris::HVOID Envy::EMementoTraitCollect< VSceneNode >( Envy::EMementoCollect& in_out_mementoCollect, const VSceneNode& in_data );\
		friend Hubris::HVOID Envy::EMementoTraitAssign< VSceneNode >( const Envy::EMementoAssign& in_out_mementoAssign, VSceneNode& out_data );\

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;
		typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( Hubris::HSINT, Hubris::HREAL ) >TFunctorVisitorSorted;

		///////////////////////////////////////////////////////
		// creation
	public:
		//copy constructor set node flag to what src is
		VSceneNode( const VSceneNode& in_src );
		//data constructor sets node flag 'InUse'
		VSceneNode(
			const Pride::PSphereR3 in_sphere,
			const Hubris::HSINT in_componentFlag,
			const Hubris::HSINT in_parentSphereIndex,
			const Hubris::HQuaternionREAL* const in_pRotation
			);
		//blank constructor DOES NOT set node flag 'InUse'
		VSceneNode();
		~VSceneNode();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VSceneNode& operator=( const VSceneNode& in_rhs );
		const Hubris::HBOOL operator==( const VSceneNode& in_rhs );
		const Hubris::HBOOL operator!=( const VSceneNode& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DataSet(
			const Pride::PSphereR3 in_sphere,
			const Hubris::HSINT in_componentFlag,
			const Hubris::HSINT in_parentSphereIndex,
			const Hubris::HQuaternionREAL* const in_pRotation
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PSphereR3& SphereGet()const{ return m_sphere; }
		Hubris::HVOID SphereSet( const Pride::PSphereR3& in_sphere ){ m_sphere = in_sphere; return; }

		const Hubris::HSINT ParentSphereIndexGet()const{ return m_parentSphereIndex; }
		Hubris::HVOID ParentSphereIndexSet( const Hubris::HSINT in_parentSphere ){ m_parentSphereIndex = in_parentSphere; return; }

		const Hubris::HSINT ComponentFlagGet()const{ return m_componentFlag; }
		Hubris::HVOID ComponentFlagSet( const Hubris::HSINT in_componentFlag ){ m_componentFlag = in_componentFlag; return; }

		Hubris::HVOID RotationSet( const Hubris::HQuaternionREAL& in_rotation );
		const Hubris::HBOOL ComponentRotationTest()const;
		const VSceneItemComponentRotation& ComponentRotationGet()const;

		const Hubris::HBOOL NodeInUseTest()const;
		Hubris::HVOID NodeNotInUseSet();

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PSphereR3 m_sphere;
		VSceneItemComponentRotation* m_pRotation;

		//Hubris::HSINT m_componentFlag;
		Hubris::HSINT m_parentSphereIndex;

		//mark as not in use by zero the component flag
		Hubris::HSINT m_componentFlag;

	};

	/**/
	
};

#endif // _V_SCENE_NODE_H_