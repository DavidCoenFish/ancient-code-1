//file: Vanity/VAnimation/VAnimation.h
#ifndef _V_ANIMATION_H_
#define _V_ANIMATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAnimation/VAnimationData.h"
#include "Vanity/VAnimation/VAnimationStream.h"
#include< Envy/EStringTable/EStringTable_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VAnimation;

	///////////////////////////////////////////////////////
	// class
	/*
		animation is named, with duration and flag. 
		it has a stream for each target for the animation set
		each stream has a type, which can be none, and each stream has time and value keys, and a flag

		moved to target string table down into the animation to allow for more flexablity (was up in asset)

		WARNING: for a looped animation, the last value in the data MUST match the first, else for risk of
		 a frame pop on time ==> last time (which current time should not reach anyrate, with time between zero and duration
	*/
	class VAnimation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VAnimationStream >TArrayStream;
		typedef Hubris::HREAL TTime;
		typedef Hubris::HContainerPair< TTime, Hubris::HSINT >TPairTimeSint;
		typedef Hubris::HContainerArray< TPairTimeSint >TArrayPairTimeSint;
		typedef Hubris::HContainerPair< TTime, Hubris::HREAL >TPairTimeReal;
		typedef Hubris::HContainerArray< TPairTimeReal >TArrayPairTimeReal;
		typedef Hubris::HContainerPair< TTime, Hubris::HVectorR2 >TPairTimeVectorR2;
		typedef Hubris::HContainerArray< TPairTimeVectorR2 >TArrayPairTimeVectorR2;
		typedef Hubris::HContainerPair< TTime, Hubris::HVectorR3 >TPairTimeVectorR3;
		typedef Hubris::HContainerArray< TPairTimeVectorR3 >TArrayPairTimeVectorR3;
		typedef Hubris::HContainerPair< TTime, Hubris::HVectorR4 >TPairTimeVectorR4;
		typedef Hubris::HContainerArray< TPairTimeVectorR4 >TArrayPairTimeVectorR4;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimation( const VAnimation& in_src );
		VAnimation();
		~VAnimation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VAnimation& operator=( const VAnimation& in_rhs );
		const Hubris::HBOOL operator==( const VAnimation& in_rhs )const;
		const Hubris::HBOOL operator!=( const VAnimation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID SampleValue(
			const Hubris::HREAL in_currentTime,
			const Hubris::HREAL in_animationWeight,
			const Hubris::HSINT in_streamIndex,
			Hubris::HSINT& in_out_value,
			Hubris::HSINT& in_out_indexHint
			)const;
		Hubris::HVOID SampleValue(
			const Hubris::HREAL in_currentTime,
			const Hubris::HREAL in_animationWeight,
			const Hubris::HSINT in_streamIndex,
			Hubris::HREAL& in_out_value,
			Hubris::HSINT& in_out_indexHint
			)const;
		Hubris::HVOID SampleValue(
			const Hubris::HREAL in_currentTime,
			const Hubris::HREAL in_animationWeight,
			const Hubris::HSINT in_streamIndex,
			Hubris::HVectorR2& in_out_value,
			Hubris::HSINT& in_out_indexHint
			)const;
		Hubris::HVOID SampleValue(
			const Hubris::HREAL in_currentTime,
			const Hubris::HREAL in_animationWeight,
			const Hubris::HSINT in_streamIndex,
			Hubris::HVectorR3& in_out_value,
			Hubris::HSINT& in_out_indexHint
			)const;
		Hubris::HVOID SampleValue(
			const Hubris::HREAL in_currentTime,
			const Hubris::HREAL in_animationWeight,
			const Hubris::HSINT in_streamIndex,
			Hubris::HVectorR4& in_out_value,
			Hubris::HSINT& in_out_indexHint
			)const;

		Hubris::HVOID DataSet(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_dataFlag, //VAnimationData flag, interploator type
			const TArrayPairTimeSint& in_arrayData
			);
		Hubris::HVOID DataSet(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_dataFlag,
			const TArrayPairTimeReal& in_arrayData
			);
		Hubris::HVOID DataSet(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_dataFlag,
			const TArrayPairTimeVectorR2& in_arrayData
			);
		Hubris::HVOID DataSet(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_dataFlag,
			const TArrayPairTimeVectorR3& in_arrayData
			);
		Hubris::HVOID DataSet(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_dataFlag,
			const TArrayPairTimeVectorR4& in_arrayData
			);

		const Hubris::HSINT StreamIndexGet(
			const Hubris::HString& in_targetName
			)const;

		///////////////////////////////////////////////////////
		// private methods
	private:
		VAnimationStream& StreamCreateGet(
			const Hubris::HString& in_targetName
			);

		Hubris::HVOID DurationUpdate(
			const TTime in_time
			);

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT FlagDataInterpolatorStepGet();
		static const Hubris::HSINT FlagDataInterpolatorLerpGet();
		static const Hubris::HSINT FlagDataInterpolatorSpineCamultRomGet();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HString& NameGet()const{ return m_name; }
		Hubris::HString& NameGet(){ return m_name; }

		const Hubris::HREAL DurationGet()const{ return m_duration; }
		Hubris::HREAL& DurationGet(){ return m_duration; }

		const Hubris::HSINT FlagGet()const{ return m_flag; }
		Hubris::HVOID FlagSet( const Hubris::HSINT in_flag ){ m_flag = in_flag; return; }

		//packed into flag
		const Hubris::HBOOL LoopGet()const;
		Hubris::HVOID LoopSet( const Hubris::HBOOL in_loop );

		const TArrayStream& ArrayStreamGet()const{ return m_arrayStream; }
		TArrayStream& ArrayStreamGet(){ return m_arrayStream; }

		const Hubris::HSINT TypeDataGet( const Hubris::HSINT in_streamIndex )const;
		Hubris::HVOID TypeDataSet( const Hubris::HSINT in_streamIndex, const Hubris::HSINT in_typeData );

		const Envy::EStringTable& TargetNameStringTableGet()const{ return m_targetNameStringTable; }
		Envy::EStringTable& TargetNameStringTableGet(){ return m_targetNameStringTable; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HString m_name;
		Hubris::HREAL m_duration;
		Hubris::HSINT m_flag;
		TArrayStream m_arrayStream;
		Envy::EStringTable m_targetNameStringTable;

	};

	/**/
	
};

#endif // _V_ANIMATION_H_