//file: Hubris/HBufferParse/HBufferParseUtilityPrivate.h
#ifndef _H_BUFFER_PARSE_UTILITY_PRIVATE_H_
#define _H_BUFFER_PARSE_UTILITY_PRIVATE_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	//////////////////////////////////////////
	// forward declarations
	/**/
	class HBuffer;

	/**/
	struct HBufferParseUtilityPrivate
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HBufferParseUtilityPrivate();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:	
		static const HBOOL IsBinGet( const HBuffer& in_srcBuffer, HSINT& out_offset );
		static const HBOOL IsTextGet( const HBuffer& in_srcBuffer, HSINT& out_offset );
		static HVOID IsTextSet( HBuffer& out_destBuffer );
		static HVOID IsBinSet( HBuffer& out_destBuffer );

	};

	/**/
};

#endif// _H_BUFFER_PARSE_UTILITY_PRIVATE_H_
