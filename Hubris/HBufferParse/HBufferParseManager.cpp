//file: Hubris/HBufferParse/HBufferParseManager.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseManager.h"

#include "Hubris/HBufferParse/HBufferParseLoad.h"
#include "Hubris/HBufferParse/HBufferParseLoadBin.h"
#include "Hubris/HBufferParse/HBufferParseLoadText.h"
#include "Hubris/HBufferParse/HBufferParseSave.h"
#include "Hubris/HBufferParse/HBufferParseSaveBin.h"
#include "Hubris/HBufferParse/HBufferParseSaveText.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////
// static public methods
/**/
HBufferParseLoad Hubris::HBufferParseManager::ParseCreateLoad()
{
	return HBufferParseLoad();
}

/**/
HBufferParseSave Hubris::HBufferParseManager::ParseCreateSaveText()
{
	return HBufferParseSave( HFALSE, HTRUE );
}

/**/
HBufferParseSave Hubris::HBufferParseManager::ParseCreateSaveBin()
{
	return HBufferParseSave( HTRUE, HFALSE );
}

/**/
