//file: Vanity/VAnimation/VAnimationBlendData.h
#ifndef _V_ANIMATION_BLEND_DATA_H_
#define _V_ANIMATION_BLEND_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAnimation;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VAnimationBlendData : public Hubris::HSmartPointerObjectBase< VAnimationBlendData >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationBlendData();
		~VAnimationBlendData();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VAnimationBlendData( const VAnimationBlendData& in_src );
		const VAnimationBlendData& operator=( const VAnimationBlendData& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID AnimationSet( const VAnimation* in_pAnimation ){ m_pAnimation = in_pAnimation; return; }
		const VAnimation* const AnimationGet()const{ return m_pAnimation; }

		const TArraySint& ArrayMapBlenderTargetArrayToAnimationTargetArrayGet()const{ return m_arrayMapBlenderTargetArrayToAnimationTargetArray; }
		TArraySint& ArrayMapBlenderTargetArrayToAnimationTargetArrayGet(){ return m_arrayMapBlenderTargetArrayToAnimationTargetArray; }

		const Hubris::HSINT StreamIndexGet( const Hubris::HSINT in_blenderTargetIndex )const;
		Hubris::HVOID StreamIndexSet( 
			const Hubris::HSINT in_blenderTargetIndex,
			const Hubris::HSINT in_streamIndex
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		//WARNING, no ownership, can be null if animation is removed
		const VAnimation* m_pAnimation;
		//index in array is the blender targer, value is the animation stream index, can be invalid index
		// size of array can be smaller than blender target array (animation added at a latter time)
		TArraySint m_arrayMapBlenderTargetArrayToAnimationTargetArray;

	};

	/**/
	
};

#endif // _V_ANIMATION_BLEND_DATA_H_