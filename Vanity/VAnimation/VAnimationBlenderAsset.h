//file: Vanity/VAnimation/VAnimationBlenderAsset.h
#ifndef _V_ANIMATION_BLENDER_ASSET_H_
#define _V_ANIMATION_BLENDER_ASSET_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAnimation/VAnimationAsset.h"
#include "Vanity/VAnimation/VAnimationBlender.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAnimationPlayParam;

	///////////////////////////////////////////////////////
	// class
	/*
		use VAnimationBlender as component and reference VAnimationAsset
	*/
	class VAnimationBlenderAsset
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VAnimationAsset >TAssetPointer;
		typedef Hubris::HContainerArray< TAssetPointer >TArrayAssetPointer;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationBlenderAsset();
		~VAnimationBlenderAsset();

		///////////////////////////////////////////////////////
		// operators
	private:
		VAnimationBlenderAsset( const VAnimationBlenderAsset& in_src );
		const VAnimationBlenderAsset& operator=( const VAnimationBlenderAsset& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		//WARNING, sharing of ownership of smart pointer asset, we keep a reference
		Hubris::HVOID AnimationAssetAdd(
			const TAssetPointer& in_animationAsset
			);
		//release reference to animation asset
		Hubris::HVOID AnimationAssetRemove(
			const TAssetPointer& in_animationAsset
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
		//trigger an aniamtion to start fade out
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
		// private members
	private:
		VAnimationBlender m_animationBlender;
		TArrayAssetPointer m_arrayAssetPointer;

	};
}

#endif // _V_ANIMATION_BLENDER_ASSET_H_