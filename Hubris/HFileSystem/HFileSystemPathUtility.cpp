//file: Hubris/HFileSystem/HFileSystemPathUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HFileSystem/HFileSystemPathUtility.h"

#include "Hubris/HFileSystem/HFileSystemPath.h"
#include "Hubris/HFileSystem/HFileSystemPathTrait.h"

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringUtility.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// local varaibles
/**/
static const HCHAR* const s_parentDir = "..";


///////////////////////////////////////////////////////////
// static public methods
/**/
const HFileSystemPath Hubris::HFileSystemPathUtility::MakeRelativePath( const HFileSystemPath& in_base, const HFileSystemPath& in_target )
{
	//deal blank base
	if( in_base == HTraitEmpty< HFileSystemPath >::EmptyGet() )
	{
		return in_target;
	}

	HFileSystemPath releativPath;
	if( ( HNULL == in_base.PathOnlyGet() ) || 
		( in_base.DriveGet() != in_target.DriveGet() ) )
	{
		return in_target;
	}


	HSINT depth = 0;
	for( HSINT index = 0; ( index < in_base.FolderCountGet() ) && ( index < in_target.FolderCountGet() ); ++index )
	{
		if( HStringUtility::ToLower( in_base.FolderGet( index ) ) == HStringUtility::ToLower( in_target.FolderGet( index ) ) )
		{
			depth = index + 1;
		}
		else
		{
			break;
		}
	}

	for( HSINT index = depth; index < in_base.FolderCountGet(); ++index )
	{
		releativPath.FolderPush( s_parentDir );
	}

	for( HSINT index = depth; index < in_target.FolderCountGet(); ++index )
	{
		releativPath.FolderPush( in_target.FolderGet( index ) );
	}

	releativPath.FileNameSet( in_target.FileNameGet() );
	releativPath.ExtentionSet( in_target.ExtentionGet() );

	return releativPath;
}

/**/
const HFileSystemPath Hubris::HFileSystemPathUtility::MakeAbsolutePath( const HFileSystemPath& in_base, const HFileSystemPath& in_relative )
{
	//deal blank base
	if( in_base == HTraitEmpty< HFileSystemPath >::EmptyGet() )
	{
		return in_relative;
	}

	HFileSystemPath absolutePath( in_base );

	HSINT depth = 0;
	for( HSINT index = 0; index < in_relative.FolderCountGet(); ++index )
	{
		if( s_parentDir == in_relative.FolderGet( index ) )
		{
			if( absolutePath.FolderCountGet() < 1 )
			{
				break;
			}

			absolutePath.FolderPop();
			depth = index + 1;
		}
		else
		{
			break;
		}
	}

	for( HSINT index = depth; index < in_relative.FolderCountGet(); ++index )
	{
		absolutePath.FolderPush( in_relative.FolderGet( index ) );
	}

	absolutePath.FileNameSet( in_relative.FileNameGet() );
	absolutePath.ExtentionSet( in_relative.ExtentionGet() );

	return absolutePath;
}

/**/
