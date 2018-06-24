//file: Vanity/VComponentGame/VComponentGameVariant.h
#ifndef _V_COMPONENT_GAME_VARIANT_H_
#define _V_COMPONENT_GAME_VARIANT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

namespace Hubris
{
	class HString;
	template< typename IN_TYPE >class HContainerArray;
};

namespace Vanity
{
	///////////////////////////////////////////////////
	// typedefs
	/**/
	typedef HTYPE_LIST_18( 
		Hubris::HBOOL,
		Hubris::HS8, 
		Hubris::HS32,
		Hubris::HR32,
		Hubris::HString, 
		Hubris::HVectorR2, 
		Hubris::HVectorR3, 
		Hubris::HVectorR4, 
		Hubris::HMatrixR4, 

		Hubris::HContainerArray< Hubris::HBOOL >,
		Hubris::HContainerArray< Hubris::HS8 >,
		Hubris::HContainerArray< Hubris::HS32 >,
		Hubris::HContainerArray< Hubris::HR32 >,
		Hubris::HContainerArray< Hubris::HString >,
		Hubris::HContainerArray< Hubris::HVectorR2 >,
		Hubris::HContainerArray< Hubris::HVectorR3 >,
		Hubris::HContainerArray< Hubris::HVectorR4 >,
		Hubris::HContainerArray< Hubris::HMatrixR4 >
	)VComponentGameVariantTypeList;

	/**/
	HVARIANT_DEFINITION( VComponentGameVariant, VComponentGameVariantTypeList );

};

/**/
namespace Envy
{
	class EMementoCollect;
	class EMementoAssign;

	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentGameVariant& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentGameVariant& out_data );

};

#endif // _V_COMPONENT_GAME_VARIANT_H_