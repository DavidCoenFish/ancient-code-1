//file: Hubris/HFileSystem/HFileSystem.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HFileSystem/HFileSystem.h"

#include "Hubris/HFileSystem/HFileSystemPath.h"
#include "Hubris/HFileSystem/HFileSystemPathImplement.h"
#include "Hubris/HFileSystem/HFileSystemPc.h"
#include "Hubris/HFileSystem/HFileSystemTime.h"
#include "Hubris/HFileSystem/HFileSystemTimeImplementPc.h"

#include "Hubris/HContainer/HContainer_Export.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HString >TArrayString;

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HFileSystem::HFileSystem() 
: m_pImplement( HNULL )
{	
	HCOMMON_NEW( m_pImplement, TFileSystemImplement );
	return;
}

/**/
Hubris::HFileSystem::~HFileSystem()
{	
	HCOMMON_DELETE( m_pImplement, TFileSystemImplement );
	return;
}

///////////////////////////////////////////////////////////
// public methods

/**/
const HBOOL Hubris::HFileSystem::CurrentWorkingDirectorySet( const HFileSystemPath& in_currentWorkingDir )
{
	return ImplementGet().CurrentWorkingDirectorySet( in_currentWorkingDir.ImplementGet() );
}

/**/
const HFileSystemPath Hubris::HFileSystem::CurrentWorkingDirectoryGet() const
{
	HFileSystemPath path;
	path.ImplementGet() = ImplementGet().CurrentWorkingDirectoryGet();

	return path;
}

/**/
const HBOOL Hubris::HFileSystem::FileCopy( const HFileSystemPath& in_fileNameSrc, const HFileSystemPath& in_fileNameDest )
{	
	return ImplementGet().FileCopy( in_fileNameSrc.ImplementGet(), in_fileNameDest.ImplementGet() );
}

/**/
const HBOOL Hubris::HFileSystem::FileLoad( const HFileSystemPath& in_fileName, HBuffer& out_buffer )
{	
	return ImplementGet().FileLoad( in_fileName.ImplementGet(), out_buffer );
}

/**/
const HBOOL Hubris::HFileSystem::FileSave( const HFileSystemPath& in_fileName, const HBuffer& in_buffer, const HBOOL in_makePath )
{	
	if( HTRUE == in_makePath )
	{
		ImplementGet().FolderMake( in_fileName.ImplementGet() );
	}
	return ImplementGet().FileSave( in_fileName.ImplementGet(), in_buffer );
}

/**/
const HBOOL Hubris::HFileSystem::FileTest( const HFileSystemPath& in_fileName )
{	
	return ImplementGet().FileTest( in_fileName.ImplementGet() );
}

/**/
const HBOOL Hubris::HFileSystem::FileRemove( const HFileSystemPath& in_fileName )
{	
	return ImplementGet().FileRemove( in_fileName.ImplementGet() );
}

/**/
const HFileSystemPath Hubris::HFileSystem::FileUniqueNameMake( const HFileSystemPath& in_pathfileName )
{
	HFileSystemPath newFileName;
	ImplementGet().FileUniqueNameMake( newFileName.ImplementGet(), in_pathfileName.ImplementGet() );
	return newFileName;
}

/**/
const HFileSystemTime Hubris::HFileSystem::FileLastModifyTimeGet( const HFileSystemPath& in_fileName )
{
	HFileSystemTime fileTime;
	ImplementGet().FileLastModifyTimeGet( in_fileName.ImplementGet(), fileTime.ImplementGet() );

	return fileTime;
}

/**/
const HFileSystemTime Hubris::HFileSystem::CurrentTimeGet()
{
	HFileSystemTime currentTime;
	ImplementGet().CurrentTimeGet( currentTime.ImplementGet() );

	return currentTime;
}

/**/
const HBOOL Hubris::HFileSystem::FolderCopy( const HFileSystemPath& in_folderNameSrc, const HFileSystemPath& in_folderNameDest )
{	
	return ImplementGet().FolderCopy( in_folderNameSrc.ImplementGet(), in_folderNameDest.ImplementGet() );
}

/**/
const HBOOL Hubris::HFileSystem::FolderMake( const HFileSystemPath& in_folderName )
{	
	return ImplementGet().FolderMake( in_folderName.ImplementGet() );
}

/**/
const HBOOL Hubris::HFileSystem::FolderRemove( const HFileSystemPath& in_folderName )
{	
	return ImplementGet().FolderRemove( in_folderName.ImplementGet() );
}

/**/
const HBOOL Hubris::HFileSystem::FolderList( const HFileSystemPath& in_folderName, TArrayString* const out_pFolderList, TArrayString* const out_pFileList )
{	
	return ImplementGet().FolderList( in_folderName.ImplementGet(), out_pFolderList, out_pFileList );
}

/**/
const HBOOL Hubris::HFileSystem::FolderTest( const HFileSystemPath& in_folderName )
{	
	return ImplementGet().FolderTest( in_folderName.ImplementGet() );
}

/**/
const TArrayString Hubris::HFileSystem::DriveListGet()
{
	TArrayString returnArray;

	ImplementGet().DriveListGet( returnArray );

	return returnArray;
}

///////////////////////////////////////////////////////////
// private accessors
/**/
const Hubris::HFileSystem::TFileSystemImplement& Hubris::HFileSystem::ImplementGet()const
{	
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return( *m_pImplement );
}

/**/
Hubris::HFileSystem::TFileSystemImplement& Hubris::HFileSystem::ImplementGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return( *m_pImplement );
}

/**/