//file: Pride/PLight/PLightTrait.h
#ifndef _P_LIGHT_TRAIT_H_
#define _P_LIGHT_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PLight;
	typedef PLight< Hubris::HU8, 1 >PLightMono;
	typedef PLight< Hubris::HU8, 3 >PLightRgb;
	typedef PLight< Hubris::HU8, 4 >PLightRgba;
	typedef PLight< Hubris::HREAL, 1 >PLightRealMono;
	typedef PLight< Hubris::HREAL, 3 >PLightRealRgb;
	typedef PLight< Hubris::HREAL, 4 >PLightRealRgba;
	
};

/**/
namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	///////////////////////////////////////////////////////////
	// memento
	/**/
	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PLightRgb& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PLightRgb& out_data );


};

#endif // _P_LIGHT_TRAIT_H_