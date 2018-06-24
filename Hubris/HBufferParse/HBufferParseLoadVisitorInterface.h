//file: Hubris/HBufferParse/HBufferParseLoadVisitorInterface.h
#ifndef _H_BUFFER_PARSE_LOAD_VISITOR_INTERFACE_H_
#define _H_BUFFER_PARSE_LOAD_VISITOR_INTERFACE_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	//////////////////////////////////////////
	// forward declarations
	class HBufferParseVariant;
	class HString;

	//////////////////////////////////////////
	// class
	/*
		abstract base class
		this class is given to a HBufferParseLoad to visit each piece of data
	*/
	class HBufferParseLoadVisitorInterface
	{
		///////////////////////////////////////////////////////////
		// public interface
	public:
		//query the visitor if it want to skip to the end of the current block
		// this is done after every found method being invoked
		virtual const HBOOL SkipToEndBlock()=0;

		//tell the visitor that start of a block was found, we move into it
		virtual HVOID FoundBlockStart( const HString& in_blockName, const HSINT in_cursor )=0;
		virtual HVOID FoundBlockEnd( const HSINT in_cursor )=0;

		virtual HVOID FoundValue( const HString& in_valueName, const HBufferParseVariant& in_value, const HSINT in_cursor )=0;

		virtual HVOID FoundComment( const HString& in_comment, const HSINT in_cursor )=0;

		virtual HVOID ErrorSet( const HString& in_errorMessage, const HSINT in_cursor )=0;


	};

	/**/
};

/**/
#endif// _H_BUFFER_PARSE_LOAD_VISITOR_INTERFACE_H_