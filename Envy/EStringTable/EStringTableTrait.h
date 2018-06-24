//file: Envy/EStringTable/EStringTableTrait.h
#ifndef _E_STRING_TABLE_TRAIT_H_
#define _E_STRING_TABLE_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Envy												
{															
	class EMementoCollect;									
	class EMementoAssign;	
	class EStringTable;

	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const EStringTable& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, EStringTable& out_data );

};

#endif // _E_STRING_TABLE_TRAIT_H_
