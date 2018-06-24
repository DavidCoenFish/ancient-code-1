//file: Hubris/HTestbed/HTestbedFileSystem.cpp

#include "Hubris/HTestbed/HTestbedFileSystem.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HBuffer/HBuffer.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

#include "Hubris/HFileSystem/HFileSystem.h"
#include "Hubris/HFileSystem/HFileSystemPath.h"
#include "Hubris/HFileSystem/HFileSystemPathTrait.h"
#include "Hubris/HFileSystem/HFileSystemPathUtility.h"
#include "Hubris/HFileSystem/HFileSystemTime.h"
#include "Hubris/HFileSystem/HFileSystemTimeTrait.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HString >TArrayString;

//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedFileSystem()
{
	HBOOL success = HTRUE;

	//HBOOL CurrentWorkingDirectorySet( const HFileSystemPath& in_currentWorkingDir );
	//HFileSystemPath CurrentWorkingDirectoryGet() const;
	{
		HFileSystem fileSystem;

		fileSystem.FolderMake( "data\\" );

		const HFileSystemPath origDir = fileSystem.CurrentWorkingDirectoryGet();

		fileSystem.CurrentWorkingDirectorySet( "data\\" );

		const HFileSystemPath currentDir = fileSystem.CurrentWorkingDirectoryGet();

		success &= ( "DATA" == currentDir.FolderBack() );

		fileSystem.CurrentWorkingDirectorySet( origDir );
	}

	//HBOOL FileCopy( const HFileSystemPath& in_fileNameSrc, const HFileSystemPath& in_fileNameDest );
	//HBOOL FileLoad( const HFileSystemPath& in_fileName, HBuffer& out_buffer );
	//HBOOL FileSave( const HFileSystemPath& in_fileName, const HBuffer& in_buffer, const HBOOL in_makePath = HTRUE );
	//HBOOL FileTest( const HFileSystemPath& in_fileName );
	//HBOOL FileRemove( const HFileSystemPath& in_fileName );
	{
		HFileSystem fileSystem;

		const HREAL data[] = { 7.5F, 8.3F, 105.7F };
		HBuffer buffer( data, sizeof( data ) );

		success &= fileSystem.FileSave( "data\\file0.bin", buffer );

		success &= fileSystem.FileCopy( "data\\file0.bin", "data\\file1.bin" );

		success &= fileSystem.FileTest( "data\\file0.bin" );
		success &= fileSystem.FileTest( "data\\file1.bin" );

		HBuffer buffer2;
		success &= fileSystem.FileLoad( "data\\file1.bin", buffer2 );

		success &= ( buffer == buffer2 );

		success &= fileSystem.FileRemove( "data\\file0.bin" );
		success &= fileSystem.FileRemove( "data\\file1.bin" );

		success &= !fileSystem.FileTest( "data\\file0.bin" );
		success &= !fileSystem.FileTest( "data\\file1.bin" );
	}

	//HFileSystemTime FileLastModifyTimeGet( const HFileSystemPath& in_fileName );
	//HFileSystemTime CurrentTimeGet();
	{
		HFileSystem fileSystem;

		const HREAL data[] = { 7.5F, 8.3F, 105.7F };
		HBuffer buffer( data, sizeof( data ) );
		success &= fileSystem.FileSave( "data\\file0.bin", buffer );

		const HFileSystemTime fileTime = fileSystem.FileLastModifyTimeGet( "data\\file0.bin" );
		const HFileSystemTime currentTime = fileSystem.CurrentTimeGet();

		success &= ( fileTime <= currentTime );

		success &= fileSystem.FileRemove( "data\\file0.bin" );
	}

	//HBOOL FolderCopy( const HFileSystemPath& in_folderNameSrc, const HFileSystemPath& in_folderNameDest );
	//HBOOL FolderMake( const HFileSystemPath& in_folderName );
	//HBOOL FolderRemove( const HFileSystemPath& in_folderName );
	//HBOOL FolderList( const HFileSystemPath& in_folderName, TArrayString* const out_pFolderList = HNULL, TArrayString* const out_pFileList = HNULL );
	//HBOOL FolderTest( const HFileSystemPath& in_folderName );
	{
		HFileSystem fileSystem;

		success &= fileSystem.FolderMake( "data\\folder\\foo\\goo\\" );
		success &= fileSystem.FolderCopy( "data\\folder\\foo\\", "data\\folder\\bar\\" );
		success &= fileSystem.FolderTest( "data\\folder\\bar\\goo\\" );

		const HREAL data[] = { 7.5F, 8.3F, 105.7F };
		HBuffer buffer( data, sizeof( data ) );
		success &= fileSystem.FileSave( "data\\folder\\file0.bin", buffer );

		TArrayString folderList;
		TArrayString fileList;
		success &= fileSystem.FolderList( "data\\folder\\", &folderList, &fileList );

		success &= ( "FILE0.BIN" == fileList[ 0 ] );
		success &= ( 2 == folderList.SizeGet() );

		success &= fileSystem.FolderRemove( "data\\folder\\" );
		success &= !fileSystem.FolderTest( "data\\folder\\" );
		fileSystem.FolderRemove( "data\\" );
	}		


	HTESTBED_VALIDATE_STATUS( "HFileSystem", success );

	return success;
}	

/**/
static const HBOOL LocalTestbedFileSystemPath()
{
	HBOOL success = HTRUE;

	//HFileSystemPath( const HFileSystemPath& in_src );
	//HFileSystemPath( const HString& in_src );
	//HFileSystemPath();
	//~HFileSystemPath();
	//const HFileSystemPath& operator=( const HFileSystemPath& in_rhs );
	//HBOOL operator==( const HFileSystemPath& in_rhs ) const;
	//HBOOL operator!=( const HFileSystemPath& in_rhs ) const;
	//HBOOL operator<( const HFileSystemPath& in_rhs ) const;
	//HFileSystemPath operator+( const HFileSystemPath& in_rhs ) const;
	//HFileSystemPath& operator+=( const HFileSystemPath& in_rhs );
	{
		HFileSystemPath path0( "c:\\temp\\foo\\bar\\file0.bin" );
		HFileSystemPath path1( path0 );
		HFileSystemPath path2 = path1;
		HFileSystemPath path3( "zoo\\moo\\goo.txt" );
		HFileSystemPath path4( "c:\\temp\\foo\\bar\\zoo\\moo\\goo.txt" );
		HFileSystemPath path5;

		success &= ( path0 == path1 );
		success &= ( path1 == path0 );

		success &= ( path0 == path2 );
		success &= ( path2 == path0 );

		path0 += path3;

		success &= ( path0 == path4 );
		success &= ( path4 == path0 );

		success &= ( ( path1 + path3 ) == path4 );
		success &= ( path4 == ( path1 + path3 ) );

		success &= ( path0 != path5 );
		success &= ( path5 != path0 );

		success &= ( path0 < path3 );
		success &= !( path3 < path0 );
	}

	//const HString PathFileNameExtentionGet()const;
	//HVOID PathFileNameExtentionSet( const HString& in_pathFileNameExtention );
	//const HString PathOnlyGet()const;
	//const HString PathOnlySet( const HString& in_path );
	//const HString FileNameExtentionOnlyGet()const;
	//HVOID FileNameExtentionOnlySet( const HString& in_fileNameExtention );
	{
		HFileSystemPath path;
		path.PathFileNameExtentionSet( "c:\\temp\\foo\\bar\\file0.bin" );

		success &= ( "C:\\TEMP\\FOO\\BAR\\FILE0.BIN" == path.PathFileNameExtentionGet() );

		path.PathOnlySet( "w:\\moo\\goo\\boo\\" );

		success &= ( "W:\\MOO\\GOO\\BOO\\FILE0.BIN" == path.PathFileNameExtentionGet() );
		success &= ( "W:\\MOO\\GOO\\BOO\\" == path.PathOnlyGet() );

		path.FileNameExtentionOnlySet( "loo.txt" );

		success &= ( "W:\\MOO\\GOO\\BOO\\LOO.TXT" == path.PathFileNameExtentionGet() );
		success &= ( "LOO.TXT" == path.FileNameExtentionOnlyGet() );
	}

	//const HString DriveGet()const;
	//const HString DriveSet( const HString& in_data );
	//HSINT FolderCountGet()const;
	//const HString FolderGet( const HSINT in_index )const;
	//HVOID FolderSet( const HSINT in_index, const HString& in_folder );
	//const HString FolderAdd( const HString& in_data );
	//const HString FolderBack()const;
	//HVOID FolderPush( const HString& in_folder );
	//HVOID FolderPop();
	//const HString FileNameGet()const;
	//const HString FileNameSet( const HString& in_data );
	//const HString ExtentionGet()const;
	//HVOID ExtentionSet( const HString& in_extention );
	{
		HFileSystemPath path;

		path.DriveSet( "w:" );
		success &= ( "W:" == path.DriveGet() );

		success &= ( 0 == path.FolderCountGet() );
		path.FolderPush( "Moo" );
		path.FolderPush( "Goo" );
		path.FolderPush( "Boo" );
		path.FolderPop();
		success &= ( 2 == path.FolderCountGet() );
		success &= ( "MOO" == path.FolderGet( 0 ) );
		success &= ( "GOO" == path.FolderGet( 1 ) );

		path.FolderSet( 1, "Zoo" );

		success &= ( "ZOO" == path.FolderGet( 1 ) );
		success &= ( "ZOO" == path.FolderBack() );

		path.FolderAdd( "Loo\\koo\\foo\\" );
		success &= ( 3 == path.FolderCountGet() );

		path.FileNameSet( "HOO." );
		success &= ( "HOO" == path.FileNameGet() );

		path.ExtentionSet( "BIN" );
		success &= ( "BIN" == path.ExtentionGet() );

		success &= ( "W:\\MOO\\ZOO\\LOO\\HOO.BIN" == path.PathFileNameExtentionGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HFileSystemPath", success );

	return success;
}	

/**/
static const HBOOL LocalTestbedFileSystemPathTrait()
{
	HBOOL success = HTRUE;

	//HTraitEmpty
	{
		const HFileSystemPath path( "c:\\whatever.txt" );

		success &= ( HFileSystemPath() == HTraitEmpty< HFileSystemPath >::EmptyGet() );
		success &= ( path != HTraitEmpty< HFileSystemPath >::EmptyGet() );
	}

	//HTraitName
	{
		success &= ( HString( "HFileSystemPath" ) == HTraitName< HFileSystemPath >::NameGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HFileSystemPathTrait", success );

	return success;
}	

/**/
static const HBOOL LocalTestbedFileSystemPathUtility()
{
	HBOOL success = HTRUE;

	//struct HFileSystemPathUtility
	//static const HFileSystemPath MakeRelativePath( const HFileSystemPath& in_base, const HFileSystemPath& in_target );
	//static const HFileSystemPath MakeAbsolutePath( const HFileSystemPath& in_base, const HFileSystemPath& in_relative );
	{
		const HFileSystemPath pathR0 = HFileSystemPathUtility::MakeRelativePath( "c:\\temp\\one\\", "c:\\temp\\one\\two\\three\\foo.zip" );
		const HFileSystemPath pathR1 = HFileSystemPathUtility::MakeRelativePath( "c:\\temp\\one\\", "c:\\other\\zoo.zip" );

		const HFileSystemPath pathA0 = HFileSystemPathUtility::MakeAbsolutePath( "c:\\temp\\one\\", pathR0 );
		const HFileSystemPath pathA1 = HFileSystemPathUtility::MakeAbsolutePath( "c:\\temp\\one\\", pathR1 );

		success &= ( "TWO\\THREE\\FOO.ZIP" == pathR0.PathFileNameExtentionGet() );
		success &= ( "..\\..\\OTHER\\ZOO.ZIP" == pathR1.PathFileNameExtentionGet() );

		success &= ( "C:\\TEMP\\ONE\\TWO\\THREE\\FOO.ZIP" == pathA0.PathFileNameExtentionGet() );
		success &= ( "C:\\OTHER\\ZOO.ZIP" == pathA1.PathFileNameExtentionGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HFileSystemPathUtility", success );

	return success;
}	

/**/
static const HBOOL LocalTestbedFileSystemTime()
{
	HBOOL success = HTRUE;

	//HFileSystemTime( const HFileSystemTime& in_rhs );
	//HFileSystemTime();
	//~HFileSystemTime();
	//const HFileSystemTime& operator=( const HFileSystemTime& in_rhs );
	//HBOOL operator==( const HFileSystemTime& in_rhs ) const;
	//HBOOL operator!=( const HFileSystemTime& in_rhs ) const;
	{
		HFileSystem fileSystem;
		const HFileSystemTime time0 = fileSystem.CurrentTimeGet();
		const HFileSystemTime time1( time0 );
		const HFileSystemTime time2 = time1;
		const HFileSystemTime time3;

		success &= ( time0 == time1 );
		success &= ( time1 == time0 );

		success &= ( time0 == time2 );
		success &= ( time2 == time0 );

		success &= ( time0 != time3 );
		success &= ( time3 != time0 );

		success &= !( time0 != time2 );
		success &= !( time2 != time0 );

		success &= !( time0 == time3 );
		success &= !( time3 == time0 );
	}

	//HBOOL operator<( const HFileSystemTime& in_rhs )const;
	//HBOOL operator<=( const HFileSystemTime& in_rhs )const;
	//HBOOL operator>( const HFileSystemTime& in_rhs )const;
	//HBOOL operator>=( const HFileSystemTime& in_rhs )const;
	{
		HFileSystem fileSystem;
		const HFileSystemTime time0 = fileSystem.CurrentTimeGet();
		const HFileSystemTime time1;

		success &= ( time1 < time0 ); 
		success &= !( time0 < time1 ); 
		success &= !( time0 < time0 ); 
		success &= !( time1 < time1 ); 
		
		success &= ( time1 <= time0 ); 
		success &= !( time0 <= time1 ); 
		success &= ( time0 <= time0 ); 
		success &= ( time1 <= time1 ); 

		success &= !( time1 > time0 ); 
		success &= ( time0 > time1 ); 
		success &= !( time0 > time0 ); 
		success &= !( time1 > time1 ); 

		success &= !( time1 >= time0 ); 
		success &= ( time0 >= time1 ); 
		success &= ( time0 >= time0 ); 
		success &= ( time1 >= time1 ); 
	}


	//HString StringISO8601Get()const;
	//HVOID StringISO8601Set( const HString& in_string );
	{
		HFileSystem fileSystem;
		const HFileSystemTime time0 = fileSystem.CurrentTimeGet();
		const HString string0 = time0.StringISO8601Get();
		const HString string1 = "abcdfoo";
		const HString string2 = "2008-05-04T14:46:25Z";
		const HString string3 = HFileSystemTime().StringISO8601Get();

		HFileSystemTime time1;
		HFileSystemTime time2;
		HFileSystemTime time3;
		HFileSystemTime time4;

		time1.StringISO8601Set( string0 );
		time2.StringISO8601Set( string1 );
		time3.StringISO8601Set( string2 );
		time4.StringISO8601Set( string3 );

		//success &= ( time0 == time1 ); 
		success &= ( time2 != time3 ); 
		success &= ( time2 == HFileSystemTime() );
	}

	HTESTBED_VALIDATE_STATUS( "HFileSystemTime", success );

	return success;
}	

/**/
static const HBOOL LocalTestbedFileSystemTimeTrait()
{
	HBOOL success = HTRUE;

	//HTraitEmpty
	{
		HFileSystem fileSystem;
		const HFileSystemTime fileSystemTime = fileSystem.CurrentTimeGet();

		success &= ( HFileSystemTime() == HTraitEmpty< HFileSystemTime >::EmptyGet() );
		success &= ( fileSystemTime != HTraitEmpty< HFileSystemTime >::EmptyGet() );
	}

	//HTraitName
	{
		success &= ( HString( "HFileSystemTime" ) == HTraitName< HFileSystemTime >::NameGet() );
	}


	HTESTBED_VALIDATE_STATUS( "HFileSystemTimeTrait", success );

	return success;
}	

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedFileSystem()
{
	HTESTBED_VALIDATE_START( "TestbedFileSystem" );
	HBOOL success = HTRUE;

	success &= LocalTestbedFileSystem();
	success &= LocalTestbedFileSystemPath();
	success &= LocalTestbedFileSystemPathTrait();
	success &= LocalTestbedFileSystemPathUtility();
	success &= LocalTestbedFileSystemTime();
	success &= LocalTestbedFileSystemTimeTrait();

	return success;
}

/**/