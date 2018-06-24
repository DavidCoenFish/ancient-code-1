//file: Vanity/VAnimation/VAnimationReference.h
#ifndef _V_ANIMATION_REFERENCE_H_
#define _V_ANIMATION_REFERENCE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >
#include "Vanity/VAnimation/VAnimation.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		smart point suitable class holding an animation
	*/
	class VAnimationReference : public Hubris::HSmartPointerObjectBase< VAnimationReference >
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationReference( const VAnimationReference& in_src );
		VAnimationReference(
			const VAnimation& in_aniamtion
			);
		VAnimationReference();
		~VAnimationReference();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VAnimationReference& operator=( const VAnimationReference& in_rhs );
		const Hubris::HBOOL operator==( const VAnimationReference& in_rhs )const;
		const Hubris::HBOOL operator!=( const VAnimationReference& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const VAnimation& AnimationGet()const{ return m_animation; }
		VAnimation& AnimationGet(){ return m_animation; }

		///////////////////////////////////////////////////////
		// private members
	private:
		VAnimation m_animation;

	};

	/**/
	
};

#endif // _V_ANIMATION_REFERENCE_H_