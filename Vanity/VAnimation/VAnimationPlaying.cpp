//file: Vanity/VAnimation/VAnimationPlaying.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationPlaying.h"

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
struct TFlag
{
	enum TEnum
	{
		TNone = 0x00,
		TLoop = 0x01,
		TFadeDown = 0x02,
	};
};

///////////////////////////////////////////////////////
// creation
/**/
VAnimationPlaying::VAnimationPlaying()
: m_currentTime( 0.0F )
, m_speed( 1.0F )
, m_duration( 0.0F )
, m_currentWeight( 0.0F )
, m_baseWeight( 1.0F )
, m_fadeInDuration( 0.0F )
, m_fadeInCountdown( 0.0F )
, m_fadeOutDuration( 0.0F )
, m_fadeOutCountdown( 0.0F )
, m_blendDataIndex( HCOMMON_INVALID_INDEX )
, m_arrayInterpolator()
, m_flag( TFlag::TNone )
{
	return;
}

/**/
VAnimationPlaying::~VAnimationPlaying()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VAnimationPlaying::Initialise(
	const VAnimation& in_animation,
	const VAnimationPlayParam& in_playParam,
	const Hubris::HSINT in_blendDataIndex
	)
{
	m_currentTime = in_playParam.StartTimeGet();
	m_speed = in_playParam.SpeedGet();
	m_duration = in_animation.DurationGet();
	m_currentWeight = 0.0F;
	m_baseWeight = in_playParam.BaseWeightGet();
	m_fadeInDuration = in_playParam.FadeInDurationGet();
	m_fadeInCountdown = 0.0F;
	m_fadeOutDuration = in_playParam.FadeOutDurationGet();
	m_fadeOutCountdown = 0.0F;
	m_blendDataIndex = in_blendDataIndex;
	m_arrayInterpolator.SizeSet( in_animation.ArrayStreamGet().SizeGet() );
	m_flag = TFlag::TNone;
	if( HTRUE == in_animation.LoopGet() )
	{
		m_flag |= TFlag::TLoop;
	}

	UpdateCurrentWeight();

	return;
}

/**/
Hubris::HVOID VAnimationPlaying::FadeOutSet()
{
	m_fadeOutCountdown = m_fadeOutDuration;
	m_flag |= TFlag::TFadeDown;
	return;
}

/**/
const Hubris::HBOOL VAnimationPlaying::ApplyDelta(
	const Hubris::HREAL in_delta
	)
{
	if( 0.0F != m_fadeInCountdown )
	{
		m_fadeInCountdown -= in_delta;
		if( m_fadeInCountdown < 0.0F )
		{
			m_fadeInCountdown = 0.0F;
		}
	}

	if( m_flag & TFlag::TFadeDown )
	{
		if( 0.0F != m_fadeOutCountdown )
		{
			m_fadeOutCountdown -= in_delta;
			if( m_fadeOutCountdown < 0.0F )
			{
				return HFALSE;
			}
		}
	}

	m_currentTime += ( in_delta * m_speed );

	if( m_flag & TFlag::TLoop )
	{
		while( m_duration < m_currentTime )
		{
			m_currentTime -= m_duration;
		}
		while( m_currentTime < 0.0F )
		{
			m_currentTime += m_duration;
		}
	}
	else if( m_duration <= m_currentTime )
	{
		return HFALSE;
	}

	UpdateCurrentWeight();

	return HTRUE;
}

/**/
Hubris::HVOID VAnimationPlaying::SampleValueGet(
	Hubris::HSINT& in_out_value,
	const VAnimation* const in_animation,
	const Hubris::HSINT in_animationTargetIndex
	)const
{
	if( ( HNULL == in_animation ) ||
		( HCOMMON_INVALID_INDEX == in_animationTargetIndex ) )
	{
		return;
	}

	in_animation->SampleValue( 
		m_currentTime,
		m_currentWeight,
		in_animationTargetIndex,
		in_out_value,
		m_arrayInterpolator[ in_animationTargetIndex ].CurrentIndexGet()
		);

	return;
}

/**/
Hubris::HVOID VAnimationPlaying::SampleValueGet(
	Hubris::HREAL& in_out_value,
	const VAnimation* const in_animation,
	const Hubris::HSINT in_animationTargetIndex
	)const
{
	if( ( HNULL == in_animation ) ||
		( HCOMMON_INVALID_INDEX == in_animationTargetIndex ) )
	{
		return;
	}

	in_animation->SampleValue( 
		m_currentTime,
		m_currentWeight,
		in_animationTargetIndex,
		in_out_value,
		m_arrayInterpolator[ in_animationTargetIndex ].CurrentIndexGet()
		);

	return;
}

/**/
Hubris::HVOID VAnimationPlaying::SampleValueGet(
	Hubris::HVectorR2& in_out_value,
	const VAnimation* const in_animation,
	const Hubris::HSINT in_animationTargetIndex
	)const
{
	if( ( HNULL == in_animation ) ||
		( HCOMMON_INVALID_INDEX == in_animationTargetIndex ) )
	{
		return;
	}

	in_animation->SampleValue( 
		m_currentTime,
		m_currentWeight,
		in_animationTargetIndex,
		in_out_value,
		m_arrayInterpolator[ in_animationTargetIndex ].CurrentIndexGet()
		);

	return;
}

/**/
Hubris::HVOID VAnimationPlaying::SampleValueGet(
	Hubris::HVectorR3& in_out_value,
	const VAnimation* const in_animation,
	const Hubris::HSINT in_animationTargetIndex
	)const
{
	if( ( HNULL == in_animation ) ||
		( HCOMMON_INVALID_INDEX == in_animationTargetIndex ) )
	{
		return;
	}

	in_animation->SampleValue( 
		m_currentTime,
		m_currentWeight,
		in_animationTargetIndex,
		in_out_value,
		m_arrayInterpolator[ in_animationTargetIndex ].CurrentIndexGet()
		);

	return;
}

/**/
Hubris::HVOID VAnimationPlaying::SampleValueGet(
	Hubris::HVectorR4& in_out_value,
	const VAnimation* const in_animation,
	const Hubris::HSINT in_animationTargetIndex
	)const
{
	if( ( HNULL == in_animation ) ||
		( HCOMMON_INVALID_INDEX == in_animationTargetIndex ) )
	{
		return;
	}

	in_animation->SampleValue( 
		m_currentTime,
		m_currentWeight,
		in_animationTargetIndex,
		in_out_value,
		m_arrayInterpolator[ in_animationTargetIndex ].CurrentIndexGet()
		);

	return;
}


///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VAnimationPlaying::UpdateCurrentWeight()
{
	m_currentWeight = m_baseWeight;
	if( 0.0F < m_fadeInCountdown )
	{
		m_currentWeight *= ( 1.0F - ( m_fadeInCountdown / m_fadeInDuration ) ); 
	}
	if( 0.0F < m_fadeOutCountdown )
	{
		m_currentWeight *= ( m_fadeOutCountdown / m_fadeOutDuration ); 
	}

	return;
}

/**/
