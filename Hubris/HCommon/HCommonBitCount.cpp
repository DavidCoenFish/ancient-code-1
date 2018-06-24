//file: Hubris/HCommon/HCommonBitCount.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HCommon/HCommonBitCount.h"

using namespace Hubris;

/**/
const HSINT Hubris::HCommonBitCountGet( const Hubris::HSINT in_value )
{
	if( 0 == in_value )
	{
		return 0;
	}
	HSINT returnValue = 0;
	for( HSINT index = 0; index < 32; ++index )
	{
		if( in_value & ( 1 << index ) )
		{
			returnValue += 1;
		}
	}

	return returnValue;
}

/**/
