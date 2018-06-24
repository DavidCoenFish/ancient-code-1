//file: Vanity/VAnimation/VAnimationData.h
#ifndef _V_ANIMATION_DATA_H_
#define _V_ANIMATION_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// predefs
	/* instanciated in cpp */
	template< typename IN_TYPE >class VAnimationData;
	typedef VAnimationData< Hubris::HSINT >VAnimationDataSint;
	typedef VAnimationData< Hubris::HREAL >VAnimationDataReal;
	typedef VAnimationData< Hubris::HVectorR2 >VAnimationDataVectorR2;
	typedef VAnimationData< Hubris::HVectorR3 >VAnimationDataVectorR3;
	typedef VAnimationData< Hubris::HVectorR4 >VAnimationDataVectorR4;

	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	template< typename IN_TYPE >
	class VAnimationData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HREAL TTime;
		typedef Hubris::HContainerPair< TTime, IN_TYPE >TPairTimeValue;
		typedef Hubris::HContainerArray< TPairTimeValue >TArrayPairTimeValue;
		typedef Hubris::HContainerArray< TTime >TArrayTime;
		typedef Hubris::HContainerArray< IN_TYPE >TArrayValue;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationData( const VAnimationData& in_src );
		VAnimationData();
		~VAnimationData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VAnimationData& operator=( const VAnimationData& in_rhs );
		const Hubris::HBOOL operator==( const VAnimationData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VAnimationData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		/*
			expect current time to be within 0 ... animation duration, loop
			 flag is for spline continunity
			expect to be told if we loop//, for the current time
			calculate the animation value, 
			use index hint as starting point to find animation keys around current time
		*/
		Hubris::HVOID SampleValue(
			const Hubris::HREAL in_currentTime,
			const Hubris::HBOOL in_loopAnimation,
			const Hubris::HREAL in_animationWeight,
			IN_TYPE& in_out_value,
			Hubris::HSINT& in_out_indexHint
			)const;

		Hubris::HVOID StreamDataSet(
			const Hubris::HSINT in_flag,
			const TArrayPairTimeValue& in_arrayData
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT TypeInterpolatorGet()const{ return m_flag; }
		Hubris::HVOID TypeInterpolatorSet( const Hubris::HSINT in_typeInterpolator ){ m_flag = in_typeInterpolator; return; }

		const TArrayTime& ArrayTimeGet()const{ return m_arrayTime; }
		TArrayTime& ArrayTimeGet(){ return m_arrayTime; }

		const TArrayValue& ArrayValueGet()const{ return m_arrayValue; }
		TArrayValue& ArrayValueGet(){ return m_arrayValue; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_flag; //interpolation type
		TArrayTime m_arrayTime;
		TArrayValue m_arrayValue;

	};

	/**/
	
};

#endif // _V_ANIMATION_DATA_H_