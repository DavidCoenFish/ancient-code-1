//file: Hubris/HBufferParse/HBufferParseLoadText.h
#ifndef _H_BUFFER_PARSE_LOAD_TEXT_H_
#define _H_BUFFER_PARSE_LOAD_TEXT_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class HBuffer;
	class HBufferParseLoadVisitorInterface;

	///////////////////////////////////////////////////////////
	// class
	/**/
	class HBufferParseLoadText
	{
		///////////////////////////////////////////////////////////
		// creation
	public:
		HBufferParseLoadText( const HBuffer& in_srcBuffer, const HSINT in_cursorStart );
		~HBufferParseLoadText();

		///////////////////////////////////////////////////////////
		// disabled
	private:
		HBufferParseLoadText( const HBufferParseLoadText& in_src );
		const HBufferParseLoadText& operator=( const HBufferParseLoadText& in_rhs );

		//////////////////////////////////////////
		// HBufferParseLoad methods
	public:
		//  on error, we bail an dset error message in visitor
		HVOID SubmitVisitor( HBufferParseLoadVisitorInterface& out_visitor )const;

	private:
		//NO OWNERSHIP
		const HBuffer& m_buffer;
		const HSINT m_cursorStart;

	};
};

#endif// _H_BUFFER_PARSE_LOAD_TEXT_H_
