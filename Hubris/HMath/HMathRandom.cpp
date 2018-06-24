//file: Hubris/HMath/HMathRandom.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMath/HMathRandom.h"

#include "Hubris/HMath/HMathRandomObject.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/////////////////////////////////////////////////////////////////
// static local methods
/**/
static HMathRandomObject& LocalRandomObjectGet()
{
	static HMathRandomObject s_randomObject;
	return s_randomObject;
}

/////////////////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID HMathRandom::RandomSeedSet( const Hubris::HSINT in_seed )
{
	LocalRandomObjectGet().RandomSeedSet( in_seed );
	return;
}

/**/
const Hubris::HREAL HMathRandom::RandomRangeOneValueGet()
{
	const HREAL value = LocalRandomObjectGet().RandomRangeOneValueGet();
	return value;
}

/**/
const Hubris::HREAL HMathRandom::RandomValueGet( const Hubris::HREAL in_range )
{
	const HREAL value = LocalRandomObjectGet().RandomValueGet( in_range );
	return value;
}

/**/
const Hubris::HSINT HMathRandom::RandomValueIntGet()
{
	const HSINT value = LocalRandomObjectGet().RandomValueIntGet();
	return value;
}

/**/
const Hubris::HREAL HMathRandom::RandomValuePlusMinusGet( const Hubris::HREAL in_range )
{
	if( 0.0F == in_range )
	{
		return 0.0F;
	}

	const HREAL value = RandomValueGet( in_range + in_range ) - in_range;
	return value;
}

/**/