//file: Vanity/VAnimation/VAnimationPlayParam.h
#ifndef _V_ANIMATION_PLAY_PARAM_H_
#define _V_ANIMATION_PLAY_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	class VAnimationPlayParam
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationPlayParam( const VAnimationPlayParam& in_src );
		VAnimationPlayParam(
			const Hubris::HREAL in_startTime = 0.0F,
			const Hubris::HREAL in_speed = 1.0F,
			const Hubris::HREAL in_baseWeight = 1.0F,
			const Hubris::HREAL in_fadeInDuration = 0.0F,
			const Hubris::HREAL in_fadeOutDuration = 0.0F
			);
		~VAnimationPlayParam();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VAnimationPlayParam& operator=( const VAnimationPlayParam& in_rhs );
		const Hubris::HBOOL operator==( const VAnimationPlayParam& in_rhs )const;
		const Hubris::HBOOL operator!=( const VAnimationPlayParam& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HREAL StartTimeGet()const{ return m_startTime; };
		Hubris::HVOID StartTimeSet( const Hubris::HREAL in_startTime ){ m_startTime = in_startTime; return; }

		const Hubris::HREAL SpeedGet()const{ return m_speed; };
		Hubris::HVOID SpeedSet( const Hubris::HREAL in_speed ){ m_speed = in_speed; return; }

		const Hubris::HREAL BaseWeightGet()const{ return m_baseWeight; };
		Hubris::HVOID BaseWeightSet( const Hubris::HREAL in_baseWeight ){ m_baseWeight = in_baseWeight; return; }

		const Hubris::HREAL FadeInDurationGet()const{ return m_fadeInDuration; };
		Hubris::HVOID FadeInDurationSet( const Hubris::HREAL in_fadeInDuration ){ m_fadeInDuration = in_fadeInDuration; return; }

		const Hubris::HREAL FadeOutDurationGet()const{ return m_fadeOutDuration; };
		Hubris::HVOID FadeOutDurationSet( const Hubris::HREAL in_fadeOutDuration ){ m_fadeOutDuration = in_fadeOutDuration; return; }

		///////////////////////////////////////////////////////
		// private memebers
	private:
		Hubris::HREAL m_startTime;
		Hubris::HREAL m_speed;

		//max weight? total weight without fade
		Hubris::HREAL m_baseWeight;
		Hubris::HREAL m_fadeInDuration;
		Hubris::HREAL m_fadeOutDuration;

	};
};

#endif // _V_ANIMATION_PLAY_PARAM_H_