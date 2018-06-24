//file: Hubris/HMath/HMathRandom.h
#ifndef _H_MATH_RANDOM_H_
#define _H_MATH_RANDOM_H_

#include "Hubris/HCommon/HCommonType.h"

/* */
namespace Hubris
{
	struct HMathRandom
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HMathRandom();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID RandomSeedSet( const Hubris::HSINT in_seed );
		static const Hubris::HREAL RandomRangeOneValueGet(); //return a value [0 ... 1.0 } not end point inclusive
		static const Hubris::HREAL RandomValueGet( const Hubris::HREAL in_range );
		static const Hubris::HSINT RandomValueIntGet();

		//return a value from negative range up to but not including positive range [-in_range ... in_range } not end point inclusive
		static const Hubris::HREAL RandomValuePlusMinusGet( const Hubris::HREAL in_range );

	};

};

#endif // _H_MATH_RANDOM_H_