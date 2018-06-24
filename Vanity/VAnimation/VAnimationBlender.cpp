//file: Vanity/VAnimation/VAnimationBlender.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationBlender.h"

#include "Vanity/VAnimation/VAnimation.h"
#include "Vanity/VAnimation/VAnimationPlayParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HSmartPointer< VAnimationBlendData >TPointerBlendData;
typedef Hubris::HContainerArray< TPointerBlendData >TArrayPointerBlendData;

///////////////////////////////////////////////////////
// local
/**/
static const VAnimationBlendData* const LocalBlendDataGet( 
	const TArrayPointerBlendData& in_arrayPointerBlenderData, 
	const HSINT in_blendDataIndex )
{
	if( ( in_blendDataIndex < 0 ) ||
		( in_arrayPointerBlenderData.SizeGet() <= in_blendDataIndex ) )
	{
		return HNULL;
	}

	const VAnimationBlendData* const pBlendData = in_arrayPointerBlenderData[ in_blendDataIndex ].RawGet();
	return pBlendData;
}


///////////////////////////////////////////////////////
// creation
/**/
VAnimationBlender::VAnimationBlender()
: m_stringTableBlenderTargets()
, m_arrayPointerBlenderData()
, m_resourceManagerBlenderData()
, m_arrayPointerPlaying()
, m_resourceManagerAnimationPlaying()
{
	return;
}

/**/
VAnimationBlender::~VAnimationBlender()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VAnimationBlender::AnimationAdd(
	const VAnimation& in_animation
	)
{
	TArraySint arraySint;
	for( HSINT index = 0; index < in_animation.TargetNameStringTableGet().StringCountGet(); ++index )
	{
		const HString& string = in_animation.TargetNameStringTableGet().StringGet( index );
		const HSINT blenderStringIndex = m_stringTableBlenderTargets.StringAdd( string );

		for( HSINT targetIndex = arraySint.SizeGet(); targetIndex <= blenderStringIndex; ++targetIndex )
		{
			arraySint.SizeResize( targetIndex + 1 );
			arraySint[ targetIndex ] = HCOMMON_INVALID_INDEX;
		}

		arraySint[ blenderStringIndex ] = index;
	}

	const HSINT foundIndex = AnimationIndexGet( in_animation.NameGet() );
	if( HCOMMON_INVALID_INDEX != foundIndex )
	{
		return;
	}

	TPointerBlendData pointerBlendData;
	pointerBlendData.Create();

	( *pointerBlendData ).AnimationSet( &in_animation );
	( *pointerBlendData ).ArrayMapBlenderTargetArrayToAnimationTargetArrayGet() = arraySint;

	const HSINT resourceId = m_resourceManagerBlenderData.ResourceIdAcquire();
	if( m_arrayPointerBlenderData.SizeGet() <= resourceId )
	{
		m_arrayPointerBlenderData.SizeResize( resourceId + 1 );
	}

	m_arrayPointerBlenderData[ resourceId ] = pointerBlendData;

	return;
}

/**/
Hubris::HVOID VAnimationBlender::AnimationRemove(
	const VAnimation& in_animation
	)
{
	for( HSINT index = 0; index < m_arrayPointerBlenderData.SizeGet(); ++index )
	{
		TPointerBlendData& pointerBlendData = m_arrayPointerBlenderData[ index ];
		if( HNULL == pointerBlendData )
		{
			continue;
		}

		if( &in_animation != pointerBlendData->AnimationGet() )
		{
			continue;
		}

		pointerBlendData = HNULL;
		m_resourceManagerBlenderData.ResourceIdRelease( index );
	}

	return;
}

/**/
const Hubris::HSINT VAnimationBlender::AnimationIndexGet(
	const Hubris::HString& in_animationName
	)const
{
	for( HSINT index = 0; index < m_arrayPointerBlenderData.SizeGet(); ++index )
	{
		const TPointerBlendData& pointerBlendData = m_arrayPointerBlenderData[ index ];
		if( HNULL == pointerBlendData )
		{
			continue;
		}

		const VAnimation* const pAnimation = pointerBlendData->AnimationGet();
		if( HNULL == pAnimation )
		{
			continue;
		}
		if( in_animationName == pAnimation->NameGet() )
		{
			return index;
		}
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const Hubris::HSINT VAnimationBlender::TargetNameIndexGet(
	const Hubris::HString& in_tagetName
	)const
{
	const HSINT index = m_stringTableBlenderTargets.StringFind( in_tagetName );
	return index;
}

/**/
Hubris::HVOID VAnimationBlender::TimeDeltaApply(
	const Hubris::HREAL in_timeDelta
	)
{
	//HCOMMON_FOR_EACH( pPlaying, m_arrayPointerPlaying, TArrayPointerPlaying )
	HSINT lastInUseIndex = 0;
	for( HSINT index = 0; index < m_arrayPointerPlaying.SizeGet(); ++index )
	{
		TPointerPlaying& pointerPlaying = m_arrayPointerPlaying[ index ];
		if( HNULL == pointerPlaying )
		{
			continue;
		}

		if( HFALSE == pointerPlaying->ApplyDelta( in_timeDelta ) )
		{
			pointerPlaying = HNULL;
			m_resourceManagerAnimationPlaying.ResourceIdRelease( index );
		}
		else
		{
			lastInUseIndex = index;
		}
	}

	if( ( lastInUseIndex + 1 ) < m_arrayPointerPlaying.SizeGet() )
	{
		m_arrayPointerPlaying.SizeResize( lastInUseIndex + 1 );
	}

	return;
}

/**/
const Hubris::HSINT VAnimationBlender::PlayAnimation(
	const Hubris::HSINT in_blendDataIndex, // animation name?
	const VAnimationPlayParam& in_playParam
	)
{
	const VAnimationBlendData* const pBlendData = LocalBlendDataGet( m_arrayPointerBlenderData, in_blendDataIndex );
	if( HNULL == pBlendData )
	{
		return HCOMMON_INVALID_INDEX;
	}
	const VAnimation* const pAnimation = pBlendData->AnimationGet();
	if( HNULL == pAnimation )
	{
		return HCOMMON_INVALID_INDEX;
	}
	const HSINT animationId = m_resourceManagerAnimationPlaying.ResourceIdAcquire();
	if( m_arrayPointerPlaying.SizeGet() <= animationId )
	{
		m_arrayPointerPlaying.SizeResize( animationId + 1 );
	}

	TPointerPlaying& pointerPlaying = m_arrayPointerPlaying[ animationId ];
	pointerPlaying = HNULL;
	pointerPlaying.Create();

	pointerPlaying->Initialise(
		*pAnimation,
		in_playParam,
		in_blendDataIndex
		);

	return animationId;
}

/**/
Hubris::HVOID VAnimationBlender::PlayingAnimationStop(
	const Hubris::HSINT in_playingAnimationIndex
	)
{
	m_resourceManagerAnimationPlaying.ResourceIdRelease( in_playingAnimationIndex );
	HCOMMON_ASSERT( ( 0 <= in_playingAnimationIndex ) && ( in_playingAnimationIndex < m_arrayPointerPlaying.SizeGet() ), "invalid param" );
	m_arrayPointerPlaying[ in_playingAnimationIndex ] = HNULL;
	return;
}

/**/
Hubris::HVOID VAnimationBlender::PlayingAnimationStartFadeOut(
	const Hubris::HSINT in_playingAnimationIndex
	)
{
	HCOMMON_ASSERT( ( 0 <= in_playingAnimationIndex ) && ( in_playingAnimationIndex < m_arrayPointerPlaying.SizeGet() ), "invalid param" );
	TPointerPlaying& pointerPlaying = m_arrayPointerPlaying[ in_playingAnimationIndex ];
	if( HNULL == pointerPlaying )
	{
		return;
	}

	pointerPlaying->FadeOutSet();

	return;
}

/**/
Hubris::HVOID VAnimationBlender::PlayingAnimationSpeedSet(
	const Hubris::HSINT in_playingAnimationIndex,
	const Hubris::HREAL in_speed
	)
{
	HCOMMON_ASSERT( ( 0 <= in_playingAnimationIndex ) && ( in_playingAnimationIndex < m_arrayPointerPlaying.SizeGet() ), "invalid param" );
	TPointerPlaying& pointerPlaying = m_arrayPointerPlaying[ in_playingAnimationIndex ];
	if( HNULL == pointerPlaying )
	{
		return;
	}

	pointerPlaying->SpeedSet( in_speed );

	return;
}

/**/
Hubris::HVOID VAnimationBlender::PlayingAnimationTimeSet(
	const Hubris::HSINT in_playingAnimationIndex,
	const Hubris::HREAL in_time
	)
{
	HCOMMON_ASSERT( ( 0 <= in_playingAnimationIndex ) && ( in_playingAnimationIndex < m_arrayPointerPlaying.SizeGet() ), "invalid param" );
	TPointerPlaying& pointerPlaying = m_arrayPointerPlaying[ in_playingAnimationIndex ];
	if( HNULL == pointerPlaying )
	{
		return;
	}

	pointerPlaying->CurrentTimeSet( in_time );

	return;
}

/**/
Hubris::HVOID VAnimationBlender::SampleValueGet(
	Hubris::HSINT& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	HCOMMON_FOR_EACH_CONST( pPlayingAnimation, m_arrayPointerPlaying, TArrayPointerPlaying )
	{
		if( HNULL == pPlayingAnimation )
		{
			continue;
		}

		const HSINT blenderDataIndex = pPlayingAnimation->BlendDataIndexGet();
		const VAnimationBlendData* const pBlendData = LocalBlendDataGet( m_arrayPointerBlenderData, blenderDataIndex );
		if( HNULL == pBlendData )
		{
			continue;
		}

		const HSINT streamIndex = pBlendData->StreamIndexGet( in_blenderTargetIndex );
		const VAnimation* const pAnimation = pBlendData->AnimationGet();

		pPlayingAnimation->SampleValueGet(
			in_out_value,
			pAnimation,
			streamIndex
			);
	}

	return;
}

/**/
Hubris::HVOID VAnimationBlender::SampleValueGet(
	Hubris::HREAL& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	HCOMMON_FOR_EACH_CONST( pPlayingAnimation, m_arrayPointerPlaying, TArrayPointerPlaying )
	{
		if( HNULL == pPlayingAnimation )
		{
			continue;
		}

		const HSINT blenderDataIndex = pPlayingAnimation->BlendDataIndexGet();
		const VAnimationBlendData* const pBlendData = LocalBlendDataGet( m_arrayPointerBlenderData, blenderDataIndex );
		if( HNULL == pBlendData )
		{
			continue;
		}

		const HSINT streamIndex = pBlendData->StreamIndexGet( in_blenderTargetIndex );
		const VAnimation* const pAnimation = pBlendData->AnimationGet();

		pPlayingAnimation->SampleValueGet(
			in_out_value,
			pAnimation,
			streamIndex
			);
	}

	return;
}

/**/
Hubris::HVOID VAnimationBlender::SampleValueGet(
	Hubris::HVectorR2& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	HCOMMON_FOR_EACH_CONST( pPlayingAnimation, m_arrayPointerPlaying, TArrayPointerPlaying )
	{
		if( HNULL == pPlayingAnimation )
		{
			continue;
		}

		const HSINT blenderDataIndex = pPlayingAnimation->BlendDataIndexGet();
		const VAnimationBlendData* const pBlendData = LocalBlendDataGet( m_arrayPointerBlenderData, blenderDataIndex );
		if( HNULL == pBlendData )
		{
			continue;
		}

		const HSINT streamIndex = pBlendData->StreamIndexGet( in_blenderTargetIndex );
		const VAnimation* const pAnimation = pBlendData->AnimationGet();

		pPlayingAnimation->SampleValueGet(
			in_out_value,
			pAnimation,
			streamIndex
			);
	}

	return;
}

/**/
Hubris::HVOID VAnimationBlender::SampleValueGet(
	Hubris::HVectorR3& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	HCOMMON_FOR_EACH_CONST( pPlayingAnimation, m_arrayPointerPlaying, TArrayPointerPlaying )
	{
		if( HNULL == pPlayingAnimation )
		{
			continue;
		}

		const HSINT blenderDataIndex = pPlayingAnimation->BlendDataIndexGet();
		const VAnimationBlendData* const pBlendData = LocalBlendDataGet( m_arrayPointerBlenderData, blenderDataIndex );
		if( HNULL == pBlendData )
		{
			continue;
		}

		const HSINT streamIndex = pBlendData->StreamIndexGet( in_blenderTargetIndex );
		const VAnimation* const pAnimation = pBlendData->AnimationGet();

		pPlayingAnimation->SampleValueGet(
			in_out_value,
			pAnimation,
			streamIndex
			);
	}

	return;
}

/**/
Hubris::HVOID VAnimationBlender::SampleValueGet(
	Hubris::HVectorR4& in_out_value,
	const Hubris::HSINT in_blenderTargetIndex
	)const
{
	HCOMMON_FOR_EACH_CONST( pPlayingAnimation, m_arrayPointerPlaying, TArrayPointerPlaying )
	{
		if( HNULL == pPlayingAnimation )
		{
			continue;
		}

		const HSINT blenderDataIndex = pPlayingAnimation->BlendDataIndexGet();
		const VAnimationBlendData* const pBlendData = LocalBlendDataGet( m_arrayPointerBlenderData, blenderDataIndex );
		if( HNULL == pBlendData )
		{
			continue;
		}

		const HSINT streamIndex = pBlendData->StreamIndexGet( in_blenderTargetIndex );
		const VAnimation* const pAnimation = pBlendData->AnimationGet();

		pPlayingAnimation->SampleValueGet(
			in_out_value,
			pAnimation,
			streamIndex
			);
	}

	return;
}

/**/