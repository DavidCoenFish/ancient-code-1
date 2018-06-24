//file: Envy/EMemento/EMementoUtility.h
#ifndef _E_MEMENTO_UTILITY_H_
#define _E_MEMENTO_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	class HFileSystem;
	class HFileSystemPath;
};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// pre defines
	class EMemento;

	///////////////////////////////////////////////////////////
	// struct

	struct EMementoUtility
	{
		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, EMemento& out_memento );
		static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EMemento& in_memento );
		static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EMemento& in_memento );

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~EMementoUtility();

	};

	/**/
};

#endif // _E_MEMENTO_UTILITY_H_