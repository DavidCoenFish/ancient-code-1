//file: Vanity/VScene/VSceneTrait.h
#ifndef _V_SCENE_TRAIT_H_
#define _V_SCENE_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VSceneComponentSphereTree;
	class VSceneComponentNodeCollection;
	class VSceneComponentSphereCollection;
	class VSceneNode;
	class VSceneComponentSphereTreeSphere;
	class VSceneItemComponentRotation;

};

HTYPE_NAME_HEADER( Vanity::VSceneItemComponentRotation );

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//VScene
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VScene& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VScene& out_data );

	//VSceneComponentSphereTree
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentSphereTree& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentSphereTree& out_data );

	//VSceneComponentNodeCollection
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentNodeCollection& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentNodeCollection& out_data );

	//VSceneComponentSphereCollection
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentSphereCollection& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentSphereCollection& out_data );

	//VSceneNode
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneNode& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneNode& out_data );

	//VSceneComponentSphereTreeSphere
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneComponentSphereTreeSphere& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneComponentSphereTreeSphere& out_data );

	//VSceneItemComponentRotation
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VSceneItemComponentRotation& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VSceneItemComponentRotation& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////////
	// global functions
	/**/
	Hubris::HVOID VComponentSceneTraitFactoryRegister();

};

#endif //_V_SCENE_TRAIT_H_