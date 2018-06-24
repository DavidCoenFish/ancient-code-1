//file: Hubris/HFileSystem/HFileSystemPc.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HFileSystem/HFileSystemPc.h"

#include "Hubris/HFileSystem/HFileSystemTimeImplementPc.h"
#include "Hubris/HFileSystem/HFileSystemPathImplement.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HCommon/HCommon_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HVariables/HVariables_Export.h"

#include< windows.h >
#include< stdio.h >
#include< direct.h >
#include< errno.h >
#include< time.h >
#include< io.h >

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// local var
/**/
static const HSINT S_MAX_DIR_LENGTH = 1024;
static const HSINT S_COPY_SIZE = 4096;

static const HSINT S_READ_SIZE = 4096;
static const HSINT S_WRITE_SIZE = 4096;

///////////////////////////////////////////////////////////
// local static methods
/**/
static const HBOOL LocalBufferFromFile( 
	HBuffer& out_buffer, 
	FILE* const in_pFile 
	)
{
	out_buffer.SizeSet( 0 );

	if( HNULL == in_pFile )
	{
		return HFALSE;
	}

	fseek( in_pFile, 0, SEEK_END );
	const HSINT size = ftell( in_pFile );
	fseek( in_pFile, 0, SEEK_SET );

	out_buffer.SizeSet( size );

	HBOOL ok = HTRUE;

	HSINT readRemaining = size;
	HSINT trace = 0;
	while( S_READ_SIZE < readRemaining )
	{
		if( 1 != ( HSINT )fread( ( ( HU8* )out_buffer.RawGet() ) + trace, S_READ_SIZE, 1, in_pFile ) )
		{
			ok = HFALSE;
			break;
		}
		readRemaining -= S_READ_SIZE;
		trace += S_READ_SIZE;
	}

	if( HTRUE == ok )
	{
		if( 0 != readRemaining )
		{
			if( 1 != (HS32)fread( ( ( HU8* )out_buffer.RawGet() ) + trace, readRemaining, 1, in_pFile ) )
			{
				ok = HFALSE;
			}
		}
	}

	return ok;
}

/**/
static const HBOOL LocalFileFromBuffer( 
	FILE* const in_out_pFile,
	const HBuffer& in_buffer
	)
{
	if( HNULL == in_out_pFile )
	{
		return HFALSE;
	}

	HS32 writeRemaining = in_buffer.SizeGet();
	HS32 trace = 0;
	HBOOL ok = HTRUE;
	while( S_WRITE_SIZE < writeRemaining )
	{
		if( 1 != ( HSINT )fwrite( ( ( HU8* )in_buffer.RawGet() ) + trace, S_WRITE_SIZE, 1, in_out_pFile ) )
		{
			ok = HFALSE;
			break;
		}
		writeRemaining -= S_WRITE_SIZE;
		trace += S_WRITE_SIZE;
	}

	if( ok )
	{
		if( 0 != writeRemaining )
		{
			if( 1 != ( HSINT )fwrite( ( ( HU8* )in_buffer.RawGet() ) + trace, writeRemaining, 1, in_out_pFile ) )
			{
				ok = HFALSE;
			}
		}
	}

	return ok;
}

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HFileSystemPc::HFileSystemPc()
{	
	return;
}

/**/
Hubris::HFileSystemPc::~HFileSystemPc()
{	
	return;
}

///////////////////////////////////////////////////////////
// public methods
/**/
const HBOOL Hubris::HFileSystemPc::CurrentWorkingDirectorySet( const HFileSystemPathImplement& in_currentWorkingDir )
{
	HBOOL success = ( 0 == _chdir( in_currentWorkingDir.PathOnlyGet().RawGet() ) );

	return success;
}

/**/
const HFileSystemPathImplement Hubris::HFileSystemPc::CurrentWorkingDirectoryGet() const
{
	HCHAR text[ S_MAX_DIR_LENGTH ];
	const HString currentWorkingDir = _getcwd( text, S_MAX_DIR_LENGTH );

	HFileSystemPathImplement path;	
	path.PathOnlySet( currentWorkingDir + HVariablesFileSystem::FolderSpecifierGet() );

	return path;
}

/**/
const HBOOL Hubris::HFileSystemPc::FileCopy( const HFileSystemPathImplement& in_fileNameSrc, const HFileSystemPathImplement& in_fileNameDest )
{
	if( in_fileNameSrc == in_fileNameDest )
	{
		return HTRUE;
	}

	FILE* fileSrc = HNULL;
	H_FOPEN_READ( fileSrc, in_fileNameSrc.PathFileNameExtentionGet().RawGet() );
	FILE* fileDest = HNULL;
	H_FOPEN_WRITE( fileDest, in_fileNameDest.PathFileNameExtentionGet().RawGet() );

	HBuffer buffer;
	buffer.SizeSet( S_COPY_SIZE );
	HBOOL ok = HTRUE;

	if( ( HNULL != fileSrc ) && ( HNULL != fileDest ) )
	{
		HSINT amount = 0;
		do
		{
			amount = ( HSINT )fread( buffer.RawGet(), sizeof(HU8), S_COPY_SIZE, fileSrc );
			if( 0 != amount )
			{
				HSINT written = ( HSINT )fwrite( buffer.RawGet(), sizeof(HU8), amount, fileDest );
				if( written != amount )
				{
					ok = HFALSE;
					break;
					//COPY_ERROR; // out of disk space or some other disk err?
				}
			}
		} // when amount read is < BUFSZ, copy is done
		while( amount == S_COPY_SIZE );
	}
	else
	{
		ok = HFALSE;
	}

	if( HNULL != fileSrc )
	{
		fclose( fileSrc );
	}

	if( HNULL != fileDest )
	{
		fclose( fileDest );
	}

	return ok;
}

/**/
const HBOOL Hubris::HFileSystemPc::FileLoad( const HFileSystemPathImplement& in_fileName, HBuffer& out_buffer )
{
	out_buffer.SizeSet( 0 );

	FILE* pFile = HNULL;
	H_FOPEN_READ( pFile, in_fileName.PathFileNameExtentionGet().RawGet() );

	if( HNULL == pFile )
	{
		return HFALSE;
	}

	const HBOOL ok = LocalBufferFromFile(
		out_buffer,
		pFile
		);

	fclose( pFile );

	return ok;
}

/**/
const HBOOL Hubris::HFileSystemPc::FileSave( const HFileSystemPathImplement& in_fileName, const HBuffer& in_buffer )
{
	FILE* pFile = HNULL;
	H_FOPEN_WRITE( pFile, in_fileName.PathFileNameExtentionGet().RawGet() );

	if( HNULL == pFile )
	{
		return HFALSE;
	}

	const HBOOL ok = LocalFileFromBuffer(
		pFile,
		in_buffer
		);

	fclose( pFile );

	return ok;
}

/**/
const HBOOL Hubris::HFileSystemPc::FileTest( const HFileSystemPathImplement& in_fileName )
{
	FILE* pFile = HNULL;
	H_FOPEN_READ( pFile, in_fileName.PathFileNameExtentionGet().RawGet() );

	if( HNULL != pFile )
	{
		fclose( pFile );
		return HTRUE;
	}

	return HFALSE;
}

/**/
const HBOOL Hubris::HFileSystemPc::FileRemove( const HFileSystemPathImplement& in_fileName )
{
	const HSINT result = remove( in_fileName.PathFileNameExtentionGet().RawGet() );

	if( 0 != result )
	{
		HCOMMON_WARNING( _sys_errlist[ errno ] );
	}
	//folder made or already exsists
	return( 0 == result );
}

/**/
HVOID Hubris::HFileSystemPc::FileUniqueNameMake( HFileSystemPathImplement& out_newfileName, const HFileSystemPathImplement& in_pathfileName )
{
	out_newfileName = in_pathfileName;

	//bail if file doesn't exsist
	if( HFALSE == FileTest( in_pathfileName ) )
	{
		return;
	}

	//find the names of other files in the folder path
	TArrayString arrayFileNamesExtention;
	FolderList( in_pathfileName, HNULL, &arrayFileNamesExtention );

	//strip the file extentions
	TArrayString arrayFileNames;
	HCOMMON_FOR_EACH_CONST( fileExtention, arrayFileNamesExtention, TArrayString )
	{
		HFileSystemPathImplement localFileName( fileExtention );
		arrayFileNames.Insert( localFileName.FileNameGet() );
	}

	//be sure that the new file name is unique
	const HString newFileName = HStringUtility::NumberedStringPostMakeUnique(
		in_pathfileName.FileNameGet(),
		arrayFileNames
		);

	out_newfileName.FileNameSet( newFileName );

	return;
}

/**/
HVOID Hubris::HFileSystemPc::FileLastModifyTimeGet( const HFileSystemPathImplement& in_fileName, HFileSystemTimeImplementPc& out_fileTime )
{
	struct _finddata_t findData;
	const intptr_t hFile = _findfirst( in_fileName.PathFileNameExtentionGet().RawGet(), &findData );

	if( -1 != hFile )
	{
		out_fileTime.DataSet( findData.time_write );
	}

	return;
}

/**/
HVOID Hubris::HFileSystemPc::CurrentTimeGet( HFileSystemTimeImplementPc& out_currentTime )
{
	time_t currentTime;
	time( &currentTime );

	out_currentTime.DataSet( currentTime );

	return;
}

/**/
const HBOOL Hubris::HFileSystemPc::FolderCopy( const HFileSystemPathImplement& in_folderNameSrc, const HFileSystemPathImplement& in_folderNameDest )
{
	if( HFALSE == FolderMake( in_folderNameDest ) )
	{
		return HFALSE;
	}

	if( in_folderNameSrc == in_folderNameDest )
	{
		return HTRUE;
	}

	TArrayString folderList;
	TArrayString fileList;
	if( HFALSE == Hubris::HFileSystemPc::FolderList( in_folderNameSrc, &folderList, &fileList ) )
	{
		return HFALSE;
	}

	HCOMMON_FOR_EACH_CONST( file, fileList, TArrayString )
	{
		if( HFALSE == FileCopy( in_folderNameSrc + file, in_folderNameDest + file ) )
		{
			return HFALSE;
		}
	}

	HCOMMON_FOR_EACH_CONST( folder, folderList, TArrayString )
	{
		if( HFALSE == FolderCopy( in_folderNameSrc + ( folder + HVariablesFileSystem::FolderSpecifierGet() ), in_folderNameDest + ( folder + HVariablesFileSystem::FolderSpecifierGet() ) ) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
const HBOOL Hubris::HFileSystemPc::FolderMake( const HFileSystemPathImplement& in_folderName )
{
	//attempt to make each folder of given path
	HFileSystemPathImplement localCopy( in_folderName );

	if( 0 < localCopy.FolderCountGet() )
	{
		localCopy.FolderPop();
		FolderMake( localCopy );
	}

	if( -1 == _mkdir( in_folderName.PathOnlyGet().RawGet() ) )
	{
		//EEXIST 
		//  Directory was not created because dirname is the name of an existing file, directory, or device. 
		//ENOENT 
		//  Path was not found. 

		if( EEXIST == errno )
		{
			return HTRUE;
		}
		else
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

/**/
const HBOOL Hubris::HFileSystemPc::FolderRemove( const HFileSystemPathImplement& in_folderName )
{
	//recursive delete folder contents first
	TArrayString folderList;
	TArrayString fileList;
	HBOOL success = HTRUE;
	success &= Hubris::HFileSystemPc::FolderList( in_folderName, &folderList, &fileList );

	HFileSystemPathImplement localPath( in_folderName );
	HCOMMON_FOR_EACH_CONST( file, fileList, TArrayString )
	{
		localPath.FileNameExtentionOnlySet( file );
		success &= FileRemove( localPath );
	}

	HCOMMON_FOR_EACH_CONST( folder, folderList, TArrayString )
	{
		HFileSystemPathImplement localFolderPath( in_folderName );
		localFolderPath.FolderPush( folder );
		success &= FolderRemove( localFolderPath );
	}

	if( -1 == _rmdir( in_folderName.PathOnlyGet().RawGet() ) )
	{
		//ENOTEMPTY 
		//  Given path is not a directory; directory is not empty; or directory is either current working directory or root directory. 
		//ENOENT 
		//  Path is invalid. 
		//EACCESS 
		//  A program has an open handle to the directory. 
		success = HFALSE;
	}

	return success;
}

/**/
const HBOOL Hubris::HFileSystemPc::FolderList( const HFileSystemPathImplement& in_folderName, TArrayString* const out_pFolderList, TArrayString* const out_pFileList )
{
	if( HNULL != out_pFolderList )
	{
		out_pFolderList->Clear();
	}

	if( HNULL != out_pFileList )
	{
		out_pFileList->Clear();
	}

    // Get the first file
	//An attempt to open a search with a trailing backslash will always fail
    WIN32_FIND_DATA fileData;
	HANDLE hList = FindFirstFile( ( in_folderName.PathOnlyGet() + "\\*" ).RawGet(), &fileData);

    if( INVALID_HANDLE_VALUE == hList )
	{
		return HFALSE;
	}

	// Traverse through the directory structure
	HBOOL moreFiles = true;

	do
    {
		const HString name( fileData.cFileName );
        // Check the object is a directory or not
		if( fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
        {
			if( ( HNULL != out_pFolderList ) &&  ( "." != name ) && ( ".." != name ) )
			{
				out_pFolderList->Insert( name );
			}
        }
        else if( HNULL != out_pFileList )
		{
			out_pFileList->Insert( name );
		}

        if( 0 == FindNextFile( hList, &fileData ) )
        {
            if( GetLastError() == ERROR_NO_MORE_FILES )
            {
				moreFiles = HFALSE;
            }
        }
    }		
	while( HTRUE == moreFiles );

    FindClose( hList );

	return HTRUE;
}

/**/
const HBOOL Hubris::HFileSystemPc::FolderTest( const HFileSystemPathImplement& in_folderName )
{
	//want a better way of doing this, try to list folder, if it fails, assume folder not found....
	return( HTRUE == FolderList( in_folderName, HNULL, HNULL ) );
}

/**/
//GetLogicalDrives
//GetLogicalDriveStrings
Hubris::HVOID Hubris::HFileSystemPc::DriveListGet(
	TArrayString& out_arrayDriveNames
	)
{
	out_arrayDriveNames.Clear();

	HString data;
	const HSINT length = GetLogicalDriveStrings( 0, NULL );
	data.SizeSet( length );
	GetLogicalDriveStrings( length, ( LPSTR )( data.RawGet() ) );

	HString string;
	for( HSINT index = 0; index < length; ++index )
	{
		const HCHAR value = data[ index ];
		if( 0 == value )
		{
			if( HNULL != string )
			{
				out_arrayDriveNames.Insert( string );
			}

			string = HNULL;
		}
		else
		{
			string += value;
		}
	}

	return;
}

/**/