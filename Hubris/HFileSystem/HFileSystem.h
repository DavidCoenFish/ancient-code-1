//file: Hubris/HFileSystem/HFileSystem.h
#ifndef _H_FILE_SYSTEM_H_
#define _H_FILE_SYSTEM_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

/*
	concret repesentation of file system
	different platform code selected at compile time
	wrappers exported for file path
	HBuffer used for data tranferal with client
*/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class HBuffer;
	class HFileSystemPath;
	class HFileSystemPc;
	class HString;
	class HFileSystemTime;
	template< typename IN_TYPE > class HContainerArray;

	///////////////////////////////////////////////////////////
	// class
	/**/
	class HFileSystem// : public HSingelton< HFileSystem >
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HContainerArray< HString > TArrayString;
		typedef HFileSystemPc TFileSystemImplement;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HFileSystem();
		~HFileSystem();

		///////////////////////////////////////////////////////////
		// disabled
	private:
		HFileSystem( const HFileSystemPc& in_src );
		const HFileSystem& operator=( const HFileSystemPc& in_rhs );

		///////////////////////////////////////////////////////////
		// public methods
	public:
		const HBOOL CurrentWorkingDirectorySet( const HFileSystemPath& in_currentWorkingDir );
		const HFileSystemPath CurrentWorkingDirectoryGet() const;
		
		const HBOOL FileCopy( const HFileSystemPath& in_fileNameSrc, const HFileSystemPath& in_fileNameDest );
		const HBOOL FileLoad( const HFileSystemPath& in_fileName, HBuffer& out_buffer );
		const HBOOL FileSave( const HFileSystemPath& in_fileName, const HBuffer& in_buffer, const HBOOL in_makePath = HTRUE );
		const HBOOL FileTest( const HFileSystemPath& in_fileName );
		const HBOOL FileRemove( const HFileSystemPath& in_fileName );
		//if file already exsists, return a file name that doesn't exsist
		const HFileSystemPath FileUniqueNameMake( const HFileSystemPath& in_pathfileName );

		//GetFileTime
		const HFileSystemTime FileLastModifyTimeGet( const HFileSystemPath& in_fileName );
		//get current time
		const HFileSystemTime CurrentTimeGet();

		const HBOOL FolderCopy( const HFileSystemPath& in_folderNameSrc, const HFileSystemPath& in_folderNameDest );
		const HBOOL FolderMake( const HFileSystemPath& in_folderName );
		//return false on an error, but function will try to keep going
		const HBOOL FolderRemove( const HFileSystemPath& in_folderName );
		const HBOOL FolderList( const HFileSystemPath& in_folderName, TArrayString* const out_pFolderList = HNULL, TArrayString* const out_pFileList = HNULL );

		const HBOOL FolderTest( const HFileSystemPath& in_folderName );

		const TArrayString DriveListGet();

		///////////////////////////////////////////////////////////
		// private accessors
	private:
		const TFileSystemImplement& ImplementGet()const;
		TFileSystemImplement& ImplementGet();

		///////////////////////////////////////////////////////////
		// private members
	private:
		TFileSystemImplement* m_pImplement;

	};
};

#endif// _H_FILE_SYSTEM_H_
