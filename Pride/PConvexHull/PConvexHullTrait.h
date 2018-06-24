//file: Pride/PConvexHull/PConvexHullTrait.h
#ifndef _P_CONVEX_HULL_TRAIT_H_
#define _P_CONVEX_HULL_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PConvexHull;
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

	//PConvexHull
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PConvexHull& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PConvexHull& out_data );

};

#endif // _P_CONVEX_HULL_TRAIT_H_