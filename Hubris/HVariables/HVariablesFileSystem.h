//file: Hubris/HVariables/HVariablesFileSystem.h
#ifndef _H_VARIABLES_FILE_SYSTEM_H_
#define _H_VARIABLES_FILE_SYSTEM_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	struct HVariablesFileSystem
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HVariablesFileSystem();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		static const HCHAR FolderSpecifierGet();
		static const HCHAR FolderAltSpecifierGet();
		static const HCHAR DriveSpecifierGet();
		static const HCHAR ExtentionSpecifierGet();

	};
};

#endif // _H_VARIABLES_FILE_SYSTEM_H_