//file: Vanity/VAnimation/VAnimationInterpolator.h
#ifndef _V_ANIMATION_KEY_H_
#define _V_ANIMATION_KEY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// class
	/**/
	class VAnimationInterpolator
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationInterpolator( const VAnimationInterpolator& in_src );
		VAnimationInterpolator();
		~VAnimationInterpolator();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VAnimationInterpolator& operator=( const VAnimationInterpolator& in_rhs );
		const Hubris::HBOOL operator==( const VAnimationInterpolator& in_rhs )const;
		const Hubris::HBOOL operator!=( const VAnimationInterpolator& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT CurrentIndexGet()const{ return m_currentIndex; }
		Hubris::HSINT& CurrentIndexGet(){ return m_currentIndex; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_currentIndex;

	};

	/**/
	
};
#endif // _V_ANIMATION_KEY_H_