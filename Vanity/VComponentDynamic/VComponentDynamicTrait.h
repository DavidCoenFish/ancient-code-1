//file: Vanity/VComponentDynamic/VComponentDynamicTrait.h
#ifndef _V_COMPONENT_DYNAMIC_TRAIT_H_
#define _V_COMPONENT_DYNAMIC_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentDynamic;
	class VComponentDynamicDataStatic;
	class VComponentDynamicDataSimple;
	class VComponentDynamicComponentParam;
};

HTYPE_NAME_HEADER( Vanity::VComponentDynamicDataStatic );
HTYPE_NAME_HEADER( Vanity::VComponentDynamicDataSimple );

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

	//VComponentDynamic
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamic& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamic& out_data );

	//VComponentDynamicDataStatic
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamicDataStatic& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamicDataStatic& out_data );

	//VComponentDynamicDataSimple
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamicDataSimple& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamicDataSimple& out_data );

	//VComponentDynamicComponentParam
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamicComponentParam& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamicComponentParam& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////////
	// global functions
	/**/
	Hubris::HVOID VComponentDynamicTraitFactoryRegister();

};
#endif // _V_COMPONENT_DYNAMIC_H_