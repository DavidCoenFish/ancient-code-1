//file: Envy/ETanya/ETanyaVariant.h
#ifndef _E_TANYA_VARIANT_H_
#define _E_TANYA_VARIANT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

namespace Hubris
{
	class HString;
	template< typename IN_TYPE >class HContainerArray;
};

namespace Envy
{
	///////////////////////////////////////////////////
	// typedefs
	/**/
	typedef HTYPE_LIST_22( 
		Hubris::HBOOL,
		Hubris::HU8, 
		Hubris::HS8, 
		Hubris::HU16,
		Hubris::HS16,
		Hubris::HU32,
		Hubris::HS32,
		Hubris::HR32,
		Hubris::HR64,
		Hubris::HCHAR,
		Hubris::HString, 

		Hubris::HContainerArray< Hubris::HBOOL >,
		Hubris::HContainerArray< Hubris::HU8 >,
		Hubris::HContainerArray< Hubris::HS8 >,
		Hubris::HContainerArray< Hubris::HU16 >,
		Hubris::HContainerArray< Hubris::HS16 >,
		Hubris::HContainerArray< Hubris::HU32 >,
		Hubris::HContainerArray< Hubris::HS32 >,
		Hubris::HContainerArray< Hubris::HR32 >,
		Hubris::HContainerArray< Hubris::HR64 >,
		Hubris::HContainerArray< Hubris::HCHAR >,
		Hubris::HContainerArray< Hubris::HString >
	)ETanyaVariantTypeList;

	/**/
	HVARIANT_DEFINITION( ETanyaVariant, ETanyaVariantTypeList );

	/**/

	class EMementoCollect;
	class EMementoAssign;

	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const ETanyaVariant& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, ETanyaVariant& out_data );

};

/**/
#endif // _E_TANYA_VARIANT_H_