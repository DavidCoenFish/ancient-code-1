//file: Hubris/HTrait/HTraitBufferOut.h
#ifndef _H_TRAIT_BUFFER_OUT_H_
#define _H_TRAIT_BUFFER_OUT_H_

#include "Hubris/HCommon/HCommonType.h"

/*
	HTraitBufferOut
		deal with getting data out of a buffer into an arbitary type
*/
namespace Hubris
{
	/////////////////////////////////////////////////////////////////
	// forward definitions
	/**/
	class HBuffer;

	/////////////////////////////////////////////////////////////////
	// namespace functions
	/*
		if these are free functions, they can be extended latter? ie, there are types i don't know about yet

		return HVOID to be syemertrical with HTraitBufferInGet
	*/

	//put value on end of buffer
	template< typename IN_TYPE >HVOID HTraitBufferOutGet( IN_TYPE& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

	/**/
};

/**/
#endif // _H_TRAIT_BUFFER_OUT_H_

