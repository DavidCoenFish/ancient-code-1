//file: Hubris/HVariables/HVariablesFileSystem.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HVariables/HVariablesFileSystem.h"

#include "Hubris/HVariables/HVariablesString.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
/**/

////////////////////////////////////////
// local varaibles
/**/
static const HCHAR s_extention = '.';
static const HCHAR s_drive = ':';

/////////////////////////////////////////////////
// static public methods
/**/
const HCHAR Hubris::HVariablesFileSystem::FolderSpecifierGet()
{
	return HVariablesString::BackSlashGet();
}

/**/
const HCHAR Hubris::HVariablesFileSystem::FolderAltSpecifierGet()
{
	return HVariablesString::SlashGet();
}

/**/
const HCHAR Hubris::HVariablesFileSystem::DriveSpecifierGet()
{
	return s_drive;
}

/**/
const HCHAR Hubris::HVariablesFileSystem::ExtentionSpecifierGet()
{
	return s_extention;
}

/**/