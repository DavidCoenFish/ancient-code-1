//file: Hubris/HBufferParse/HBufferParseLoad.h
#ifndef _H_BUFFER_PARSE_LOAD_H_
#define _H_BUFFER_PARSE_LOAD_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HBuffer/HBuffer.h"

/**/
namespace Hubris
{
	//////////////////////////////////////////
	// forward declarations
	/**/
	struct HBufferParseManager;
	class HBufferParseLoadBin;
	class HBufferParseLoadText;
	class HBufferParseLoadVisitorInterface;

	///////////////////////////////////////////////////////////
	// class
	/**/
	class HBufferParseLoad
	{
		friend HBufferParseManager;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HBufferParseLoad( const HBufferParseLoad& in_src );
	private:
		HBufferParseLoad();
	public:
		~HBufferParseLoad();

		///////////////////////////////////////////////////////////
		// operator
	public:
		const HBufferParseLoad& operator=( const HBufferParseLoad& in_rhs );
		HBOOL operator==( const HBufferParseLoad& in_rhs )const;
		HBOOL operator!=( const HBufferParseLoad& in_rhs )const;

		///////////////////////////////////////////////////////////
		// public methods
	public:
		HBOOL ValidTest()const;

		//submit a visitor for a buffer, resets buffer position
		HVOID SubmitVisitor( HBufferParseLoadVisitorInterface& out_visitor )const;

		///////////////////////////////////////////////////////////
		// accessors
	public:
		HBuffer& BufferGet(){ return m_buffer; }

		///////////////////////////////////////////////////////////
		// private Members
	private:
		HBuffer m_buffer;

	};
};

#endif// _H_BUFFER_PARSE_LOAD_H_
