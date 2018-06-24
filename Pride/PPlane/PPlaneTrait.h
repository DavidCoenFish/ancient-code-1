//file: Pride/PPlane/PPlaneTrait.h
#ifndef _P_CONVEX_HULL_TRAIT_H_
#define _P_CONVEX_HULL_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;

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

	//PPlaneR2
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PPlaneR2& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PPlaneR2& out_data );

	//PPlaneR3
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PPlaneR3& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PPlaneR3& out_data );

};

#endif // _P_CONVEX_HULL_TRAIT_H_