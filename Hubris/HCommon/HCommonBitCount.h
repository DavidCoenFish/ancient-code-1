//file: Hubris/HCommon/HCommonBitCount.h
#ifndef _H_COMMON_BIT_COUNT_H_
#define _H_COMMON_BIT_COUNT_H_

#include "Hubris/HCommon/HCommonType.h"

#define HCOMMON_BIT_COUNT( VALUE )	Hubris::HCommonBitCountGet( VALUE )

namespace Hubris
{
	const HSINT HCommonBitCountGet( const Hubris::HSINT in_value );

};

/**/																									

#endif// _H_COMMON_BIT_COUNT_H_
