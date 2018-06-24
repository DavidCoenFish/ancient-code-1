//file: Vanity/VAnimation/VAnimationPlaying.h
#ifndef _V_ANIMATION_PLAYING_H_
#define _V_ANIMATION_PLAYING_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAnimation/VAnimationInterpolator.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAnimation;
	class VAnimationBlendData;
	class VAnimationPlayParam;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VAnimationPlaying : public Hubris::HSmartPointerObjectBase< VAnimationPlaying >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VAnimationInterpolator >TArrayInterpolator;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationPlaying();
		~VAnimationPlaying();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VAnimationPlaying( const VAnimationPlaying& in_src );
		const VAnimationPlaying& operator=( const VAnimationPlaying& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Initialise(
			const VAnimation& in_animation,
			const VAnimationPlayParam& in_playParam,
			const Hubris::HSINT in_blendDataIndex
			);

		//activate fade out
		Hubris::HVOID FadeOutSet();
		//return false if animation has finished (faded out or reached end of non loop
		const Hubris::HBOOL ApplyDelta(
			const Hubris::HREAL in_delta
			);

		Hubris::HVOID SampleValueGet(
			Hubris::HSINT& in_out_value,
			const VAnimation* const in_animation,
			const Hubris::HSINT in_animationTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HREAL& in_out_value,
			const VAnimation* const in_animation,
			const Hubris::HSINT in_animationTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HVectorR2& in_out_value,
			const VAnimation* const in_animation,
			const Hubris::HSINT in_animationTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HVectorR3& in_out_value,
			const VAnimation* const in_animation,
			const Hubris::HSINT in_animationTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HVectorR4& in_out_value,
			const VAnimation* const in_animation,
			const Hubris::HSINT in_animationTargetIndex
			)const;

		///////////////////////////////////////////////////////
		// public methods
	private:
		Hubris::HVOID UpdateCurrentWeight();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT BlendDataIndexGet()const{ return m_blendDataIndex; };
		Hubris::HVOID BlendDataIndexSet( const Hubris::HSINT in_blendDataIndex ){ m_blendDataIndex = in_blendDataIndex; return; }

		const Hubris::HREAL CurrentTimeGet()const{ return m_currentTime; };
		Hubris::HVOID CurrentTimeSet( const Hubris::HREAL in_currentTime ){ m_currentTime = in_currentTime; return; }

		const Hubris::HREAL SpeedGet()const{ return m_speed; };
		Hubris::HVOID SpeedSet( const Hubris::HREAL in_speed ){ m_speed = in_speed; return; }

		const Hubris::HREAL FadeOutDurationGet()const{ return m_fadeOutDuration; };
		Hubris::HVOID FadeOutDurationSet( const Hubris::HREAL in_fadeOutDuration ){ m_fadeOutDuration = in_fadeOutDuration; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HREAL m_currentTime;
		Hubris::HREAL m_speed; //mul delta current time on update, can be zero, no effect on fade
		Hubris::HREAL m_currentWeight; //current weight of the animation (base weight modified by fade in and out

		Hubris::HREAL m_duration;

		Hubris::HREAL m_baseWeight;
		Hubris::HREAL m_fadeInDuration;
		Hubris::HREAL m_fadeInCountdown;
		Hubris::HREAL m_fadeOutDuration;
		Hubris::HREAL m_fadeOutCountdown;

		Hubris::HSINT m_blendDataIndex;

		//index maps to animation target index
		mutable TArrayInterpolator m_arrayInterpolator;

		Hubris::HSINT m_flag;

	};

	/**/
	
};

#endif // _V_ANIMATION_PLAYING_H_