//file: Hubris/HTinyXml/HTinyXmlUtility.h
#ifndef _H_TINY_XML_UTILITY_H_
#define _H_TINY_XML_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"

///////////////////////////////////////////////////////////
// pre defines
/**/
//class TiXmlNode;
class TiXmlDocument;

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// pre defines
	/**/
	class HBuffer;
	
	///////////////////////////////////////////////////////////
	// struct
	/*
		convert between TinyXml document and buffer
		yes, it is inconvienient to us TiXmlDocument rather than TiXmlNode,
			however Document::Parse has different interface, culd swap over to Node
			if Parse interface could be satisfied for Node
	*/
	struct HTinyXmlUtility
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HTinyXmlUtility();

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		// parse buffer and put found xml nodes into children of tiny xml
		static const HBOOL TinyXmlFromBuffer( TiXmlDocument& out_tinyXml, const HBuffer& in_buffer );
		// put childrent of tiny xml node into buffer
		static const HBOOL TinyXmlToBuffer( HBuffer& out_buffer, TiXmlDocument& in_tinyXml );

	};

};

#endif // _H_TINY_XML_UTILITY_H_