//file: Hubris/HFileSystem/HFileSystemPathUtility.h
#ifndef _H_FILE_SYSTEM_PATH_UTILITY_H_
#define _H_FILE_SYSTEM_PATH_UTILITY_H_

/*
	file path as object, wrapper to avoid component having dependance
*/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// predefine
	/**/
	class HFileSystemPath;

	struct HFileSystemPathUtility
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HFileSystemPathUtility();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:	
		static const HFileSystemPath MakeRelativePath( const HFileSystemPath& in_base, const HFileSystemPath& in_target );
		static const HFileSystemPath MakeAbsolutePath( const HFileSystemPath& in_base, const HFileSystemPath& in_relative );

	};

};

#endif// _H_FILE_SYSTEM_PATH_UTILITY_H_
