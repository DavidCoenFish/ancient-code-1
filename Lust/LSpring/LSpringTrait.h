//file: Lust/LSpring/LSpringTrait.h
#ifndef _L_SPRING_TRAIT_H_
#define _L_SPRING_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////////
// forward declarations
/**/
namespace Lust
{
	class LSpringParam;
	
};
namespace Envy
{
	class EMementoCollect;
	class EMementoAssign;
	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

};

///////////////////////////////////////////////////////////
// memento
/**/
namespace Envy
{
	//PGeometry
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Lust::LSpringParam& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Lust::LSpringParam& out_data );
};

#endif // _L_SPRING_TRAIT_H_