//file: Vanity/VAnimation/VAnimationBlenderAsset.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationBlenderAsset.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

typedef Hubris::HContainerArray< VAnimation >TArrayAnimation;

///////////////////////////////////////////////////////
// creation
/**/
VAnimationBlenderAsset::VAnimationBlenderAsset()
: m_animationBlender()
, m_arrayAssetPointer()
{
	return;
}

/**/
VAnimationBlenderAsset::~VAnimationBlenderAsset()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VAnimationBlenderAsset::AnimationAssetAdd(
	const TAssetPointer& in_animationAsset
	)
{
	if( HNULL == in_animationAsset )
	{
		return;
	}

	m_arrayAssetPointer.Insert(  in_animationAsset );
	HCOMMON_FOR_EACH_CONST( animation, in_animationAsset->ArrayAnimationGet(), TArrayAnimation )
	{
		m_animationBlender.AnimationAdd(
			animation
			);
	}

	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::AnimationAssetRemove(
	const TAssetPointer& in_animationAsset
	)
{
	if( HNULL == in_animationAsset )
	{
		return;
	}

	for( TArrayAssetPointer::TIterator iterator = m_arrayAssetPointer.Begin(); iterator != m_arrayAssetPointer.End(); ++iterator )
	{
		if( HNULL == ( *iterator ) )
		{
			if( ( *iterator ) != in_animationAsset )
			{
				continue;
			}

			HCOMMON_FOR_EACH_CONST( animation, in_animationAsset->ArrayAnimationGet(), TArrayAnimation )
			{
				m_animationBlender.AnimationRemove(
					animation
					);
			}
		}

		iterator = m_arrayAssetPointer.Remove( iterator );
	}

	return;
}
/**/
const Hubris::HSINT VAnimationBlenderAsset::AnimationIndexGet(
	const Hubris::HString& in_animationName
	)const
{
	const HSINT index = m_animationBlender.AnimationIndexGet( 
		in_animationName
		);
	return index;
}

/**/
const Hubris::HSINT VAnimationBlenderAsset::TargetNameIndexGet(
	const Hubris::HString& in_tagetName
	)const
{
	const HSINT index = m_animationBlender.TargetNameIndexGet( 
		in_tagetName
		);
	return index;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::TimeDeltaApply(
	const Hubris::HREAL in_timeDelta
	)
{
	m_animationBlender.TimeDeltaApply( 
		in_timeDelta
		);
	return;
}

/**/
const Hubris::HSINT VAnimationBlenderAsset::PlayAnimation(
	const Hubris::HSINT in_animationId, // animation name?
	const VAnimationPlayParam& in_playParam
	)
{
	const HSINT index = m_animationBlender.PlayAnimation( 
		in_animationId,
		in_playParam
		);
	return index;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::PlayingAnimationStop(
	const Hubris::HSINT in_playingAnimationIndex
	)
{
	m_animationBlender.PlayingAnimationStop( 
		in_playingAnimationIndex
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::PlayingAnimationStartFadeOut(
	const Hubris::HSINT in_playingAnimationIndex
	)
{
	m_animationBlender.PlayingAnimationStartFadeOut( 
		in_playingAnimationIndex
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::PlayingAnimationSpeedSet(
	const Hubris::HSINT in_playingAnimationIndex,
	const Hubris::HREAL in_speed
	)
{
	m_animationBlender.PlayingAnimationSpeedSet( 
		in_playingAnimationIndex,
		in_speed
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::PlayingAnimationTimeSet(
	const Hubris::HSINT in_playingAnimationIndex,
	const Hubris::HREAL in_time
	)
{
	m_animationBlender.PlayingAnimationTimeSet( 
		in_playingAnimationIndex,
		in_time
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::SampleValueGet(
	Hubris::HSINT& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	m_animationBlender.SampleValueGet( 
		in_out_value,
		in_blenderTargetIndex
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::SampleValueGet(
	Hubris::HREAL& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	m_animationBlender.SampleValueGet( 
		in_out_value,
		in_blenderTargetIndex
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::SampleValueGet(
	Hubris::HVectorR2& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	m_animationBlender.SampleValueGet( 
		in_out_value,
		in_blenderTargetIndex
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::SampleValueGet(
	Hubris::HVectorR3& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	m_animationBlender.SampleValueGet( 
		in_out_value,
		in_blenderTargetIndex
		);
	return;
}

/**/
Hubris::HVOID VAnimationBlenderAsset::SampleValueGet(
	Hubris::HVectorR4& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	m_animationBlender.SampleValueGet( 
		in_out_value,
		in_blenderTargetIndex
		);
	return;
}

/**/