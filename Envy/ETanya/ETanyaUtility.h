//file: Envy/ETanya/ETanyaUtility.h
#ifndef _E_TANYA_UTILITY_H_
#define _E_TANYA_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/ETanya/ETanya.h"

namespace Hubris
{
	class HFileSystem;
	class HFileSystemPath;
};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// pre defines

	///////////////////////////////////////////////////////////
	// struct

	struct ETanyaUtility
	{
		/////////////////////////////////////////////////////////////////
		// typedefs

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, ETanya& out_document );
		static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const ETanya& in_document );
		static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const ETanya& in_document );

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~ETanyaUtility();

	};

	/**/
};

#endif // _E_TANYA_UTILITY_H_