//file: Pride/PAnimation/PAnimationUtility.h
#ifndef _P_ANIMATION_UTILITY_H_
#define _P_ANIMATION_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;
	template< typename IN_FIRST, typename IN_SECOND >class HContainerPair;
	class HString;
};

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	class PAnimation;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PAnimationUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		typedef Hubris::HContainerPair< Hubris::HString, Hubris::HString >TPairStringString;
		typedef Hubris::HContainerArray< TPairStringString >TArrayPairStringString;

		///////////////////////////////////////////////////////
		// public static methods
	public:
		static Hubris::HVOID CollectKeyframe( TArrayReal& out_timeArray, const PAnimation& in_animation );

		static Hubris::HVOID RemapData( PAnimation& in_out_animation, const TArrayPairStringString& in_arrayOldNewNames );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PAnimationUtility();

	};

	/**/
};

#endif // _P_ANIMATION_UTILITY_H_