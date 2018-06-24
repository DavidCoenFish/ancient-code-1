//file: Vanity/VComponentCollision/VComponentCollisionTrait.h
#ifndef _V_COMPONENT_COLLISION_TRAIT_H_
#define _V_COMPONENT_COLLISION_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentCollision;
	class VComponentCollisionDataBound;
	class VComponentCollisionDataHull;
	class VComponentCollisionDataSphere;
	class VComponentCollisionAssetHull;
	class VComponentCollisionHull;
	class VComponentCollisionHullData;

};

HTYPE_NAME_HEADER( Vanity::VComponentCollisionDataBound );
HTYPE_NAME_HEADER( Vanity::VComponentCollisionDataHull );
HTYPE_NAME_HEADER( Vanity::VComponentCollisionDataSphere );

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

	//VComponentCollision
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollision& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollision& out_data );

	//VComponentCollisionDataBound
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionDataBound& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionDataBound& out_data );

	//VComponentCollisionDataHull
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionDataHull& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionDataHull& out_data );

	//VComponentCollisionDataSphere
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionDataSphere& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionDataSphere& out_data );

	//VComponentCollisionHull
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionHull& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionHull& out_data );

	//VComponentCollisionHullData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionHullData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionHullData& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////////
	// global functions
	/**/
	Hubris::HVOID VComponentCollisionTraitFactoryRegister();

};


#endif // _V_COMPONENT_COLLISION_TRAIT_H_