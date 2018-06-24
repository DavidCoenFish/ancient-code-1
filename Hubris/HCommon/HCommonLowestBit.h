//file: Hubris/HCommon/HCommonLowestBit.h
#ifndef _H_COMMON_LOWEST_BIT_H_
#define _H_COMMON_LOWEST_BIT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

//TODO: consider, would this be better as function?, with a loop? having 17 conditionals my be code blotish, but is unrolled
// return HCOMMON_INVALID_INDEX ifno lowest bit 
#define HCOMMON_LOWEST_BIT32( VALUE )	( HSINT )																				\
	( 0xFFFFFFFF & VALUE ) ?																									\
	( 																															\
		( 0xFFFF & VALUE ) ?																									\
		( 																														\
			( 0xFF & VALUE ) ?																									\
			( 																													\
				( 0xF & VALUE ) ?																								\
				( 																												\
					( 0x3 & VALUE ) ? ( ( 0x1 & VALUE ) ? 0 : 1 ) :	( ( 0x4 & VALUE ) ? 2 : 3 )									\
				)																												\
					:																											\
				( 																												\
					( 0x30 & VALUE ) ? ( ( 0x10 & VALUE ) ? 4 : 5 ) :	( ( 0x40 & VALUE ) ? 6 : 7 )							\
				)																												\
			)																													\
				:																												\
			( 																													\
				( 0xF00 & VALUE ) ?																								\
				( 																												\
					( 0x300 & VALUE ) ? ( ( 0x100 & VALUE ) ? 8 : 9 ) :	( ( 0x400 & VALUE ) ? 10 : 11 )							\
				)																												\
					:																											\
				( 																												\
					( 0x3000 & VALUE ) ? ( ( 0x1000 & VALUE ) ? 12 : 13 ) :	( ( 0x4000 & VALUE ) ? 14 : 15 )					\
				)																												\
			)																													\
		)																														\
			:																													\
		( 																														\
			( 0xFF0000 & VALUE ) ?																								\
			( 																													\
				( 0xF0000 & VALUE ) ?																							\
				( 																												\
					( 0x30000 & VALUE ) ? ( ( 0x10000 & VALUE ) ? 16 : 17 ) :	( ( 0x40000 & VALUE ) ? 18 : 19 )				\
				)																												\
					:																											\
				( 																												\
					( 0x300000 & VALUE ) ? ( ( 0x100000 & VALUE ) ? 20 : 21 ) :	( ( 0x400000 & VALUE ) ? 22 : 23 )				\
				)																												\
			)																													\
				:																												\
			( 																													\
				( 0xF000000 & VALUE ) ?																							\
				( 																												\
					( 0x3000000 & VALUE ) ? ( ( 0x1000000 & VALUE ) ? 24 : 25 ) :	( ( 0x4000000 & VALUE ) ? 26 : 27 )			\
				)																												\
					:																											\
				( 																												\
					( 0x30000000 & VALUE ) ? ( ( 0x10000000 & VALUE ) ? 28 : 29 ) :	( ( 0x40000000 & VALUE ) ? 30 : 31 )		\
				)																												\
			)																													\
		)																														\
	)																															\
		:																														\
	( 																															\
		HCOMMON_INVALID_INDEX																									\
	)																															\


/**/																									

#endif// _H_COMMON_LOWEST_BIT_H_
