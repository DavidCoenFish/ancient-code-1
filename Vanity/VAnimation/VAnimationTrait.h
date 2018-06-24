//file: Vanity/VAnimation/VAnimationTrait.h
#ifndef _V_ANIMATION_TRAIT_H_
#define _V_ANIMATION_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAnimation;
	class VAnimationStream;

	template< typename IN_TYPE >class VAnimationData;
	typedef VAnimationData< Hubris::HSINT >VAnimationDataSint;
	typedef VAnimationData< Hubris::HREAL >VAnimationDataReal;
	typedef VAnimationData< Hubris::HVectorR2 >VAnimationDataVectorR2;
	typedef VAnimationData< Hubris::HVectorR3 >VAnimationDataVectorR3;
	typedef VAnimationData< Hubris::HVectorR4 >VAnimationDataVectorR4;

};

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

	//VAnimation
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimation& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimation& out_data );

	//VAnimationStream
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationStream& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationStream& out_data );


	//VAnimationDataSint
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataSint& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataSint& out_data );
	//VAnimationDataReal
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataReal& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataReal& out_data );
	//VAnimationDataVectorR2
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataVectorR2& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataVectorR2& out_data );
	//VAnimationDataVectorR3
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataVectorR3& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataVectorR3& out_data );
	//VAnimationDataVectorR4
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataVectorR4& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataVectorR4& out_data );


};


#endif // _V_ANIMATION_TRAIT_H_