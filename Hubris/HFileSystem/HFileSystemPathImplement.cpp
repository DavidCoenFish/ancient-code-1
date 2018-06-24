//file: Hubris/HFileSystem/HFileSystemPathImplement.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HFileSystem/HFileSystemPathImplement.h"

#include "Hubris/HCommon/HCommonForEach.h"
#include "Hubris/HContainer/HContainerUtility.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringUtility.h"
#include "Hubris/HVariables/HVariablesFileSystem.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

////////////////////////////////////////
// creation
/**/
HFileSystemPathImplement::HFileSystemPathImplement( const HFileSystemPathImplement& in_src )
: m_drive()
, m_arrayFolders()
, m_fileName()
, m_fileExtention()
{
	( *this ) = in_src;
	return;
}

/**/
HFileSystemPathImplement::HFileSystemPathImplement( const HString& in_pathFileNameExtention )
: m_drive()
, m_arrayFolders()
, m_fileName()
, m_fileExtention()
{
	PathFileNameExtentionSet( in_pathFileNameExtention );
	return;
}

/**/
HFileSystemPathImplement::HFileSystemPathImplement()
: m_drive()
, m_arrayFolders()
, m_fileName()
, m_fileExtention()
{
	return;
}

/**/
HFileSystemPathImplement::~HFileSystemPathImplement()
{
	return;
}

////////////////////////////////////////
// operators
/**/
const HFileSystemPathImplement& HFileSystemPathImplement::operator=( const HFileSystemPathImplement& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_drive = in_rhs.m_drive;
		m_arrayFolders = in_rhs.m_arrayFolders;
		m_fileName = in_rhs.m_fileName;
		m_fileExtention = in_rhs.m_fileExtention;
	}

	return( *this );
}

/**/
HBOOL HFileSystemPathImplement::operator==( const HFileSystemPathImplement& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_drive == in_rhs.m_drive );
		match &= ( m_arrayFolders == in_rhs.m_arrayFolders );
		match &= ( m_fileName == in_rhs.m_fileName );
		match &= ( m_fileExtention == in_rhs.m_fileExtention );
	}

	return match;
}

/**/
HBOOL HFileSystemPathImplement::operator!=( const HFileSystemPathImplement& in_rhs )const
{
	return( !operator==( in_rhs ) );
}

HBOOL HFileSystemPathImplement::operator<( const HFileSystemPathImplement& in_rhs )const
{
	HBOOL lessThan = HFALSE;

	if( this != &in_rhs )
	{
		lessThan = PathFileNameExtentionGet() < in_rhs.PathFileNameExtentionGet();
		//lessThan |= ( m_drive < in_rhs.m_drive );
		//lessThan |= ( m_arrayFolders < in_rhs.m_arrayFolders );
		//lessThan |= ( m_fileName < in_rhs.m_fileName );
		//lessThan |= ( m_fileExtention < in_rhs.m_fileExtention );
	}

	return lessThan;
}

/**/
const HFileSystemPathImplement HFileSystemPathImplement::operator+( const HFileSystemPathImplement& in_rhs )const
{
	HFileSystemPathImplement returnPath( *this );
	returnPath += in_rhs;
	return returnPath;
}

/**/
const HFileSystemPathImplement& HFileSystemPathImplement::operator+=( const HFileSystemPathImplement& in_rhs )
{
	HCOMMON_FOR_EACH_CONST( folderName, in_rhs.m_arrayFolders, TArrayString )
	{
		FolderPush( folderName );
	}

	FileNameSet( in_rhs.FileNameGet() );
	ExtentionSet( in_rhs.ExtentionGet() );

	return( *this );
}

////////////////////////////////////////
// public methods
/**/
const HString HFileSystemPathImplement::PathFileNameExtentionGet()const
{
	return( PathOnlyGet() + FileNameExtentionOnlyGet() );
}

/**/
HVOID HFileSystemPathImplement::PathFileNameExtentionSet( const HString& in_pathFileNameExtention)
{
	HString data( in_pathFileNameExtention );

	data = PathOnlySet( data );
	FileNameExtentionOnlySet( data );

	return;
}

/**/
const HString HFileSystemPathImplement::PathOnlyGet()const
{
	HString returnString;
	if( 0 < m_drive.SizeGet() )
	{
		returnString = DriveGet() + HVariablesFileSystem::FolderSpecifierGet();
	}

	HCOMMON_FOR_EACH_CONST( folderName, m_arrayFolders, TArrayString )
	{
		returnString += ( folderName + HVariablesFileSystem::FolderSpecifierGet() );
	}

	return returnString;
}

/**/
const HString HFileSystemPathImplement::PathOnlySet( const HString& in_data )
{
	HString returnData( in_data );
	HString oldData;

	returnData = DriveSet( returnData );

	m_arrayFolders.Clear();
	do
	{
		oldData = returnData;
		returnData = FolderAdd( returnData );
	}
	while( oldData != returnData );

	return returnData;
}

/**/
const HString HFileSystemPathImplement::FileNameExtentionOnlyGet()const
{
	if( 0 < m_fileExtention.SizeGet() )
	{
		return m_fileName + HVariablesFileSystem::ExtentionSpecifierGet() + m_fileExtention;
	}

	return m_fileName;
}

/**/
HVOID HFileSystemPathImplement::FileNameExtentionOnlySet( const HString& in_fileNameExtention )
{
	HString data( in_fileNameExtention );

	data = FileNameSet( data );
	ExtentionSet( data );

	return;
}

////////////////////////////////////////
// public accessors
/**/
const HString HFileSystemPathImplement::DriveGet()const
{
	if( HNULL != m_drive )
	{
		return m_drive + HVariablesFileSystem::DriveSpecifierGet();
	}

	return HNULL;
}

/**/
const HString HFileSystemPathImplement::DriveSet( const HString& in_data )
{
	m_drive.Clear();
	HString returnData( in_data );
	
	const HSINT driveIndex = HStringUtility::FindFirst( returnData,  HVariablesFileSystem::DriveSpecifierGet() );
	if( HCOMMON_INVALID_INDEX != driveIndex )
	{
		HSINT driveStartIndex = 0;
		for( ; driveStartIndex < driveIndex; ++driveStartIndex )
		{
			const HCHAR value = in_data[ driveStartIndex ];
			if( ( HVariablesFileSystem::FolderSpecifierGet() != value ) && 
				( HVariablesFileSystem::FolderAltSpecifierGet() != value ) )
			{
				break;
			}
		}

		m_drive = HStringUtility::ToUpper( HStringUtility::SubString( returnData, driveStartIndex, driveIndex - driveStartIndex ) );
		returnData = HStringUtility::SubString( returnData, driveIndex + 1, returnData.SizeGet() - ( driveIndex + 1 ) );
	}

	return returnData;
}

/**/
HSINT HFileSystemPathImplement::FolderCountGet()const
{
	return m_arrayFolders.SizeGet();
}

/**/
const HString HFileSystemPathImplement::FolderGet( const HSINT in_index )const
{
	return m_arrayFolders[ in_index ];
}

/**/
HVOID HFileSystemPathImplement::FolderSet( const HSINT in_index, const HString& in_folder )
{
	m_arrayFolders[ in_index ] = HStringUtility::ToUpper( in_folder );
	return;
}

/**/
const HString HFileSystemPathImplement::FolderAdd( const HString& in_data )
{
	HString returnData( in_data );
	TArrayHCHAR folderDelimiters;
	folderDelimiters.Insert( HVariablesFileSystem::FolderSpecifierGet() );
	folderDelimiters.Insert( HVariablesFileSystem::FolderAltSpecifierGet() );

	const HSINT folderIndex = HStringUtility::FindFirst( returnData, folderDelimiters );
	if( HCOMMON_INVALID_INDEX == folderIndex )
	{
		return returnData;
	}

	const HString folderName = HStringUtility::SubString( returnData, 0, folderIndex );
	returnData = HStringUtility::SubString( returnData, folderIndex + 1, returnData.SizeGet() - ( folderIndex + 1 ) );

	FolderPush( folderName );

	return returnData;
}

/**/
const HString HFileSystemPathImplement::FolderBack()const
{
	return HContainerUtility::Back( m_arrayFolders );
}

/**/
HVOID HFileSystemPathImplement::FolderPush( const HString& in_folder )
{
	if( in_folder.SizeGet() <= 0 )
	{
		return;
	}

	HContainerUtility::PushBack( m_arrayFolders, HStringUtility::ToUpper( in_folder ) );
}

/**/
HVOID HFileSystemPathImplement::FolderPop()
{
	HContainerUtility::PopBack( m_arrayFolders );
	return;
}

/**/
const HString HFileSystemPathImplement::FileNameGet()const
{
	return m_fileName;
}

/**/
const HString HFileSystemPathImplement::FileNameSet( const HString& in_fileName )
{
	HString returnData( in_fileName );

	const HSINT index = HStringUtility::FindFirst( returnData, HVariablesFileSystem::ExtentionSpecifierGet() );

	if( HCOMMON_INVALID_INDEX != index )
	{
		m_fileName = HStringUtility::ToUpper( HStringUtility::SubString( returnData, 0, index ) );
		returnData = HStringUtility::SubString( returnData, index + 1, returnData.SizeGet() - ( index + 1 ) );
	}
	else
	{
		m_fileName = HStringUtility::ToUpper( returnData );
		returnData.Clear();
	}

	return returnData;
}

/**/
const HString HFileSystemPathImplement::ExtentionGet()const
{
	return m_fileExtention;
}

/**/
HVOID HFileSystemPathImplement::ExtentionSet( const HString& in_extention )
{
	m_fileExtention = HStringUtility::ToUpper( in_extention );
	return;
}

/**/