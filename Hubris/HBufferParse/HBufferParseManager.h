//file: Hubris/HBufferParse/HBufferParseManager.h
#ifndef _H_BUFFER_PARSE_MANAGER_H_
#define _H_BUFFER_PARSE_MANAGER_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

namespace Hubris
{
	//////////////////////////////////////////
	// forward declarations
	/**/
	class HBufferParseLoad;
	class HBufferParseSave;
	class HBuffer;

	//////////////////////////////////////////
	// struct
	/*
		create load or save buffer parse objects
	*/
	struct HBufferParseManager
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HBufferParseManager();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		//return a load interface for parser
		static HBufferParseLoad ParseCreateLoad();

		// return a save interface
		static HBufferParseSave ParseCreateSaveText();
		static HBufferParseSave ParseCreateSaveBin();

	};
	
	/**/
};

#endif// _H_BUFFER_PARSE_MANAGER_H_
