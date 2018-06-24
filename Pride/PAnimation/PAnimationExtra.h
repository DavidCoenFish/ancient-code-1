//file: Pride/PAnimation/PAnimationExtra.h
#ifndef _P_ANIMATION_EXTRA_H_
#define _P_ANIMATION_EXTRA_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PAnimation/PAnimation.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs

	///////////////////////////////////////////////////////
	// class
	/*
		hold some extra information to go with an animation
	*/
	class PAnimationExtra
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		PAnimationExtra( const PAnimationExtra& in_src );
		PAnimationExtra(
			const Hubris::HString& in_name,
			const Hubris::HSINT& in_flag,
			const PAnimation& in_animation
			);
		PAnimationExtra();
		~PAnimationExtra();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PAnimationExtra& operator=( const PAnimationExtra& in_rhs );
		const Hubris::HBOOL operator==( const PAnimationExtra& in_rhs )const;
		const Hubris::HBOOL operator!=( const PAnimationExtra& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HString& NameGet()const{ return m_name; }
		Hubris::HString& NameGet(){ return m_name; }

		const Hubris::HSINT FlagGet()const{ return m_flag; }
		Hubris::HVOID FlagSet( const Hubris::HSINT in_flag ){ m_flag = in_flag; return; }

		const PAnimation& AnimationGet()const{ return m_animation; }
		PAnimation& AnimationGet(){ return m_animation; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HString m_name;
		Hubris::HSINT m_flag;
		PAnimation m_animation;

	};

	/**/	
};

#endif // _P_ANIMATION_EXTRA_H_