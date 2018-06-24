//file: Hubris/HBuffer/HBufferUtility.h
#ifndef _H_BUFFER_UTILITY_H_
#define _H_BUFFER_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	/////////////////////////////////////////////////////////////////
	// forward defines
	/**/
	class HBuffer;
	class HString;

	/////////////////////////////////////////////////////////////////
	// struct
	/**/
	struct HBufferUtility
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HBufferUtility();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		//put the data buffer into a string, string adds EOS
		static HVOID StringFromBuffer( HString& out_string, const HBuffer& in_buffer );
		//put data of string into buffer without EOS
		static HVOID BufferFromString( HBuffer& out_buffer, const HString& in_string );

		static HVOID DataAppend( HBuffer& in_buffer, const HVOID* const in_data, const HSINT in_size );
		static HVOID DataSet( HBuffer& in_buffer, const HVOID* const in_data, const HSINT in_offset, const HSINT in_size );
		static HVOID DataGet( const HBuffer& in_buffer, HVOID* const out_data, const HSINT in_offset, const HSINT in_size );

		//pad the size of data in buffer to a certain boundary using given pad value, assert if boundary is zero
		static HVOID DataPad( HBuffer& in_out_buffer, const HSINT in_byteBoundary, const HU8 in_padValue = 0 );

		static HVOID TextAppend( 
			HBuffer& in_out_buffer, 
			const HString& in_text
			);

	};

	/**/
};

/**/
#endif // _H_BUFFER_UTILITY_H_

