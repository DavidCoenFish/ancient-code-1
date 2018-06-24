//file: Hubris/HBuffer/HBufferOperators.h
#ifndef _H_BUFFER_OPERATORS_H_
#define _H_BUFFER_OPERATORS_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class HBuffer;

	////////////////////////////////////////////////////////
	// global free methods
	/**/
	const HBuffer operator +( const HBuffer& in_lhs, const HBuffer& in_rhs );
	const HBuffer& operator +=( HBuffer& in_lhs, const HBuffer& in_rhs );

	const HBOOL operator <( const HBuffer& in_lhs, const HBuffer& in_rhs );

};

/**/
#endif // _H_BUFFER_OPERATORS_H_

