//file: Hubris/HTrait/HTraitBufferIn.h
#ifndef _H_TRAIT_BUFFER_IN_H_
#define _H_TRAIT_BUFFER_IN_H_

#include "Hubris/HCommon/HCommonType.h"

/*
	HTraitBufferIn
		deal with putting data into a buffer from an arbitary type
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
	*/

	//put value on end of buffer
	template< typename IN_TYPE >HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const IN_TYPE& in_value );

	//template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HString& in_value );

	//replace location in buffer with value
	template< typename IN_TYPE >HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const IN_TYPE& in_value, const HSINT in_offset );

	//template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HString& in_value, const HSINT in_offset );

	/**/
};

/**/
#endif // _H_TRAIT_BUFFER_IN_H_

