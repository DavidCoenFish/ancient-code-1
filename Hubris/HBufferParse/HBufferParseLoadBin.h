//file: Hubris/HBufferParse/HBufferParseLoadBin.h
#ifndef _H_BUFFER_PARSE_LOAD_BIN_H_
#define _H_BUFFER_PARSE_LOAD_BIN_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations

	class HBuffer;
	class HBufferParseLoadVisitorInterface;

	///////////////////////////////////////////////////////////
	// class

	class HBufferParseLoadBin
	{
		///////////////////////////////////////////////////////////
		// creation
	public:
		HBufferParseLoadBin( const HBuffer& in_srcBuffer, const HSINT in_cursorStart );
		~HBufferParseLoadBin();

		//////////////////////////////////////////
		// public methods
	public:
		HVOID SubmitVisitor( HBufferParseLoadVisitorInterface& out_visitor )const;

		///////////////////////////////////////////////////////////
		// disabled
	private:
		HBufferParseLoadBin( const HBufferParseLoadBin& in_src );
		const HBufferParseLoadBin& operator=( const HBufferParseLoadBin& in_rhs );

		///////////////////////////////////////////////////////////
		// private members
	private:
		//NO OWNERSHIP
		const HBuffer& m_buffer;
		const HSINT m_cursorStart;

	};
};

#endif// _H_BUFFER_PARSE_LOAD_BIN_H_
