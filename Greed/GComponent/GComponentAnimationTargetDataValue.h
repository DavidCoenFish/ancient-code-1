//file: Greed/GComponent/GComponentAnimationTargetDataValue.h
#ifndef _G_COMPONENT_ANIMATION_TARGET_DATA_VALUE_H_
#define _G_COMPONENT_ANIMATION_TARGET_DATA_VALUE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Vanity/VAnimation/VAnimation_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations

	///////////////////////////////////////////////////////
	// class
	/* 
		hold default value for animation

		TODO: also hold last value? or things not animating be cheap to update...
		 many things may be in manual update of animation...?
	*/
	template< typename IN_TYPE >
	class GComponentAnimationTargetDataValue
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentAnimationTargetDataValue(
			const IN_TYPE& in_value
			);
		~GComponentAnimationTargetDataValue();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GComponentAnimationTargetDataValue( const GComponentAnimationTargetDataValue& in_src );
		const GComponentAnimationTargetDataValue& operator=( const GComponentAnimationTargetDataValue& in_rhs );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const IN_TYPE& ValueGet()const{ return m_value; }

		///////////////////////////////////////////////////////
		// private members
	private:
		const IN_TYPE m_value;
	};

	/**/
	
};

#endif // _G_COMPONENT_ANIMATION_TARGET_DATA_VALUE_H_