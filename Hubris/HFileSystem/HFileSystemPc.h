//file: Hubris/HFileSystem/HFileSystemPc.h
#ifndef _H_FILE_SYSTEM_PC_H_
#define _H_FILE_SYSTEM_PC_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

/*
	generic resizeable data buffer, support copy, assignment, memento and factory
*/
namespace Hubris
{
	template< typename IN_TYPE > class HContainerArray;
	class HFileSystemPathImplement;
	class HFileSystemPc;
	class HString;
	class HBuffer;
	class HFileSystemTimeImplementPc;

	class HFileSystemPc
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HContainerArray< HString >TArrayString;
		typedef HFileSystemPc TFileSystemImp;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HFileSystemPc();
		~HFileSystemPc();

		///////////////////////////////////////////////////////////
		// disabled
	private:
		HFileSystemPc( const HFileSystemPc& in_src );
		const HFileSystemPc& operator=( const HFileSystemPc& in_rhs );

		///////////////////////////////////////////////////////////
		// public methods
	public:
		const HBOOL CurrentWorkingDirectorySet( const HFileSystemPathImplement& in_currentWorkingDir );
		const HFileSystemPathImplement CurrentWorkingDirectoryGet() const;
		
		const HBOOL FileCopy( const HFileSystemPathImplement& in_fileNameSrc, const HFileSystemPathImplement& in_fileNameDest );
		const HBOOL FileLoad( const HFileSystemPathImplement& in_fileName, HBuffer& out_buffer );
		const HBOOL FileSave( const HFileSystemPathImplement& in_fileName, const HBuffer& in_buffer );
		const HBOOL FileTest( const HFileSystemPathImplement& in_fileName );
		const HBOOL FileRemove( const HFileSystemPathImplement& in_fileName );
		HVOID FileUniqueNameMake( HFileSystemPathImplement& out_newfileName, const HFileSystemPathImplement& in_pathfileName );

		//GetFileTime
		HVOID FileLastModifyTimeGet( const HFileSystemPathImplement& in_fileName, HFileSystemTimeImplementPc& out_fileTime );
		//get the current time
		HVOID CurrentTimeGet( HFileSystemTimeImplementPc& out_currentTime );

		const HBOOL FolderCopy( const HFileSystemPathImplement& in_folderNameSrc, const HFileSystemPathImplement& in_folderNameDest );
		const HBOOL FolderMake( const HFileSystemPathImplement& in_folderName );
		const HBOOL FolderRemove( const HFileSystemPathImplement& in_folderName );
		const HBOOL FolderList( const HFileSystemPathImplement& in_folderName, TArrayString* const out_pFolderList = HNULL, TArrayString* const out_pFileList = HNULL );
		const HBOOL FolderTest( const HFileSystemPathImplement& in_folderName );

		Hubris::HVOID Hubris::HFileSystemPc::DriveListGet(
			TArrayString& out_arrayDriveNames
			);

	};
};

#endif// _H_FILE_SYSTEM_PC_H_
