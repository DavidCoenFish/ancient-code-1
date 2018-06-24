//file: Pride/PridePreCompileHeader.h
#ifndef _PRIDE_PRE_COMPILE_HEADER_H_
#define _PRIDE_PRE_COMPILE_HEADER_H_

/*
	have reached break even?
	without hubris exports in the pch, takes 55 seconds to build 
	with hubris exports in pch, it takes 32 seconds to build
*/

#include< Hubris/Hubris_Export.h >

/*
	without pride exports in the pch, takes 32 seconds to build 
	with pride exports in pch, it takes 30 seconds to build
*/


#endif //_PRIDE_PRE_COMPILE_HEADER_H_