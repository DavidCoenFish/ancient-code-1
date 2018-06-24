//file: Vanity/VAnimation/VAnimationBlender.h
#ifndef _V_ANIMATION_BLENDER_H_
#define _V_ANIMATION_BLENDER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAnimation/VAnimationBlendData.h"
#include "Vanity/VAnimation/VAnimationPlaying.h"

#include< Envy/EResourceIdManager/EResourceIdManager_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAnimation;
	class VAnimationPlayParam;

	///////////////////////////////////////////////////////
	// class
	/*
		wanted to be able to run the animation system without awareness of animation asset
		however SOMETHING above this want to keep ownership of the animation
	*/
	class VAnimationBlender
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VAnimationBlendData >TPointerBlendData;
		typedef Hubris::HContainerArray< TPointerBlendData >TArrayPointerBlendData;

		typedef Hubris::HSmartPointer< VAnimationPlaying >TPointerPlaying;
		typedef Hubris::HContainerArray< TPointerPlaying >TArrayPointerPlaying;

		typedef Hubris::HContainerArray< VAnimation >TArrayAnimation;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationBlender();
		~VAnimationBlender();

		///////////////////////////////////////////////////////
		// operators
	private:
		VAnimationBlender( const VAnimationBlender& in_src );
		const VAnimationBlender& operator=( const VAnimationBlender& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		//WARNING, going to take reference of animation without taking ownership
		// expect external management of asset for now
		Hubris::HVOID AnimationAdd(
			const VAnimation& in_animation
			);
		Hubris::HVOID AnimationRemove(
			const VAnimation& in_animation
			);

		const Hubris::HSINT AnimationIndexGet(
			const Hubris::HString& in_animationName
			)const;
		const Hubris::HSINT TargetNameIndexGet(
			const Hubris::HString& in_tagetName
			)const;

		Hubris::HVOID TimeDeltaApply(
			const Hubris::HREAL in_timeDelta
			);

		const Hubris::HSINT PlayAnimation(
			const Hubris::HSINT in_animationId, // animation name?
			const VAnimationPlayParam& in_playParam
			);

		Hubris::HVOID PlayingAnimationStop(
			const Hubris::HSINT in_playingAnimationIndex
			);
		Hubris::HVOID PlayingAnimationStartFadeOut(
			const Hubris::HSINT in_playingAnimationIndex
			);
		Hubris::HVOID PlayingAnimationSpeedSet(
			const Hubris::HSINT in_playingAnimationIndex,
			const Hubris::HREAL in_speed
			);
		Hubris::HVOID PlayingAnimationTimeSet(
			const Hubris::HSINT in_playingAnimationIndex,
			const Hubris::HREAL in_time
			);

		Hubris::HVOID SampleValueGet(
			Hubris::HSINT& in_out_value,
			const Hubris::HSINT in_blenderTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HREAL& in_out_value,
			const Hubris::HSINT in_blenderTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HVectorR2& in_out_value,
			const Hubris::HSINT in_blenderTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HVectorR3& in_out_value,
			const Hubris::HSINT in_blenderTargetIndex
			)const;
		Hubris::HVOID SampleValueGet(
			Hubris::HVectorR4& in_out_value,
			const Hubris::HSINT in_blenderTargetIndex
			)const;

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HCHAR* const AnimationNamegGetDefault();

		///////////////////////////////////////////////////////
		// private members
	private:
		//table of string to index for all the targets of any added animation
		Envy::EStringTable m_stringTableBlenderTargets;
		//index of blend data in array matches animationIndex
		// reference to animation, index map of blended target index to animation target index
		// NULL animation on removal of animation from blender
		TArrayPointerBlendData m_arrayPointerBlenderData; 
		Envy::EResourceIdManager m_resourceManagerBlenderData;

		//index of playing animation matches playAnimationIndex, smart pointered with resource manager to locate free 'index'
		TArrayPointerPlaying m_arrayPointerPlaying;
		Envy::EResourceIdManager m_resourceManagerAnimationPlaying;

	};
}

#endif // _V_ANIMATION_BLENDER_H_