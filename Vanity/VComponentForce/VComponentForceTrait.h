//file: Vanity/VComponentForce/VComponentForceTrait.h
#ifndef _V_COMPONENT_LIGHT_EMITTER_TRAIT_H_
#define _V_COMPONENT_LIGHT_EMITTER_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentForce;
	class VComponentForceDataBound;
	class VComponentForceDataSphere;

};

HTYPE_NAME_HEADER( Vanity::VComponentForceDataBound );
HTYPE_NAME_HEADER( Vanity::VComponentForceDataSphere );

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
	// specialise memento functions
	/**/

	//VComponentForce
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentForce& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentForce& out_data );

	//VComponentForceDataBound
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentForceDataBound& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentForceDataBound& out_data );

	//VComponentForceDataSphere
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentForceDataSphere& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentForceDataSphere& out_data );

};

#endif // _V_COMPONENT_LIGHT_EMITTER_TRAIT_H_