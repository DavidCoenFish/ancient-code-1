//file: Pride/PSphere/PSphereTrait.h
#ifndef _P_SPHERE_TRAIT_H_
#define _P_SPHERE_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;
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

	//PSphereR2
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PSphereR2& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PSphereR2& out_data );

	//PSphereR3
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PSphereR3& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PSphereR3& out_data );

};

#endif // _P_SPHERE_TRAIT_H_