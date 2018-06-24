//file: Envy/EJana/EJanaManagerImplementation.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EJana/EJanaManagerImplementation.h"
#include "Envy/EJana/EJanaUtility.h"

#include "Envy/ETanya/ETanya_Export.h"
#include "Envy/EDataStore/EDataStore_Export.h"

using namespace Envy;
using namespace Hubris;

/////////////////////////////////////////////////////////////////
// typedef
typedef Hubris::HContainerArray< HString >TArrayString;
typedef Hubris::HContainerPair< HFileSystemPath, EJana >TPathJanaPair;
typedef Hubris::HContainerTree< HString, TPathJanaPair >TNamePathJanaMap;

/////////////////////////////////////////////////////////////////
// local free functions
static Hubris::HVOID CollectFileNames( HFileSystem& in_fileSystem, const HFileSystemPath& in_basePath, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary, TNamePathJanaMap& out_namePathJanaMap )
{
	TArrayString fileList;
	TArrayString folderList;

	in_fileSystem.FolderList( in_basePath, &folderList, &fileList );

	//if file matches extention, add it to map
	HCOMMON_FOR_EACH_CONST( file, fileList, TArrayString )
	{
		HFileSystemPath localPath( in_basePath );
		localPath += file;
		HString extention = HStringUtility::ToLower( localPath.ExtentionGet() );
		if( ( extention == in_extentionText ) || 
			( extention == in_extentionBinary ) )
		{
			const HString& fileName = localPath.FileNameGet();
			out_namePathJanaMap.Insert( fileName, TPathJanaPair( localPath, EJana() ) );
		}
	}

	//recurse for each folder
	HCOMMON_FOR_EACH_CONST( folder, folderList, TArrayString )
	{
		HFileSystemPath localPath( in_basePath );
		localPath.FolderPush( folder );

		CollectFileNames( in_fileSystem, localPath, in_extentionText, in_extentionBinary, out_namePathJanaMap );
	}

	return;
}

static Hubris::HVOID LoadFiles( HFileSystem& in_fileSystem, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary, TNamePathJanaMap& in_out_namePathJanaMap )
{
	HCOMMON_FOR_EACH( data, in_out_namePathJanaMap, TNamePathJanaMap )
	{
		HFileSystemPath localText( data.m_first );
		HFileSystemPath localBin( data.m_first );

		localText.ExtentionSet( in_extentionText );
		localBin.ExtentionSet( in_extentionBinary );

		HBOOL loadText = HFALSE;

		if( ( HFALSE == in_fileSystem.FileTest( localBin ) ) ||
			( in_fileSystem.FileLastModifyTimeGet( localBin ) <= in_fileSystem.FileLastModifyTimeGet( localText ) ))
		{
			loadText = HTRUE;
		}

		if( HTRUE == loadText )
		{
			ETanyaUtility::Load( in_fileSystem, localText, data.m_second );
			ETanyaUtility::SaveBinary( in_fileSystem, localBin, data.m_second );
		}
		else
		{
			ETanyaUtility::Load( in_fileSystem, localBin, data.m_second );
		}
	}

	return;
}

/**/
static const ETanya* const FindJanaBlock( const EJana& in_jana, const HString& in_parentName )
{
	HString derrivedName;

	if( HTRUE == EJanaUtility::DerrivableNameGet( in_jana, derrivedName ) )
	{
		if( in_parentName == derrivedName )
		{
			return( &in_jana );
		}
	}


	//look at children
	{
		TArrayString arrayChildren;
		in_jana.ChildNameListGet( arrayChildren );
		HCOMMON_FOR_EACH_CONST( childName, arrayChildren, TArrayString )
		{
			const EJana& child = in_jana.ChildGet( childName );
			const EJana* const pJana = FindJanaBlock( child, in_parentName );

			if( HNULL != pJana )
			{
				return pJana;
			}
		}
	}

	//look at children arrays
	{
		TArrayString arrayChildrenArray;
		in_jana.ChildArrayNameListGet( arrayChildrenArray );
		HCOMMON_FOR_EACH_CONST( childName, arrayChildrenArray, TArrayString )
		{
			const HSINT count = in_jana.ChildArrayCountGet( childName );
			for( HSINT index = 0; index < count; ++index )
			{
				const EJana& child = in_jana.ChildArrayGet( childName, index );
				const EJana* const pJana = FindJanaBlock( child, in_parentName );

				if( HNULL != pJana )
				{
					return pJana;
				}
			}
		}
	}

	return HNULL;
}

static HBOOL ConvertJanaToTanya( const EJana& in_jana, ETanya& out_tanya, const TNamePathJanaMap& in_namePathJanaMap );

/**/
static HBOOL AquireBlock( const TNamePathJanaMap& in_namePathJanaMap, const HString& in_fileName, const HString& in_parentName, ETanya& out_tanya )
{
	const TNamePathJanaMap::TIterator iterator = in_namePathJanaMap.Find( in_fileName );

	if( iterator == in_namePathJanaMap.End() )
	{
		return HFALSE;
	}
	
	const EJana* const pFoundJana = FindJanaBlock( ( *iterator ).m_second, in_parentName );

	if( HNULL == pFoundJana )
	{
		return HFALSE;
	}

	//recurse
	return ConvertJanaToTanya( *pFoundJana, out_tanya, in_namePathJanaMap );
}

/**/
static HBOOL ConvertJanaToTanya( const EJana& in_jana, ETanya& out_tanya, const TNamePathJanaMap& in_namePathJanaMap )
{
	HBOOL success = HTRUE;

	//if we inherit, get the values now
	{
		HString parentName;
		HString fileName;
		if( HTRUE == EJanaUtility::ParentGet( in_jana, parentName, fileName ) )
		{
			success &= AquireBlock( in_namePathJanaMap, fileName, parentName, out_tanya );
		}
	}

	TArrayString arrayDataNames;
	TArrayString arrayChildNames;
	TArrayString arrayChildArrayNames;
	in_jana.NameListGet( arrayDataNames, arrayChildNames, arrayChildArrayNames );

	//add data from current block
	HCOMMON_FOR_EACH_CONST( name, arrayDataNames, TArrayString )
	{
		out_tanya.DataVariantSet( name, in_jana.DataVariantGet( name ) );
	}

	//add children
	HCOMMON_FOR_EACH_CONST( name, arrayChildNames, TArrayString )
	{
		const EJana& janaChild = in_jana.ChildGet( name );
		ETanya& tanyaChild = out_tanya.ChildAdd( name );

		success &= ConvertJanaToTanya( janaChild, tanyaChild, in_namePathJanaMap );
	}

	//add children arrays
	HCOMMON_FOR_EACH_CONST( name, arrayChildArrayNames, TArrayString )
	{
		const HSINT count = in_jana.ChildArrayCountGet( name );
		for( HSINT index = 0; index < count; ++index )
		{
			const EJana& janaChild = in_jana.ChildArrayGet( name, index );
			ETanya& tanyaChild = out_tanya.ChildArrayAppend( name );

			success &= ConvertJanaToTanya( janaChild, tanyaChild, in_namePathJanaMap );
		}
	}

	EJanaUtility::ParentRemove( out_tanya );
	EJanaUtility::DerrivableRemove( out_tanya );

	return success;
}

/////////////////////////////////////////////////////////////////
// creation
Envy::EJanaManagerImplementation::EJanaManagerImplementation( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_basePath, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary  ) 
: m_namePathJanaMap()
{
	HString lowerText( HStringUtility::ToLower( in_extentionText ) );
	HString lowerBinary( HStringUtility::ToLower( in_extentionBinary ) );

	//collect file names
	CollectFileNames( in_fileSystem, in_basePath, lowerText, lowerBinary, m_namePathJanaMap );

	//load each file
	LoadFiles( in_fileSystem, lowerText, lowerBinary, m_namePathJanaMap );

	return;
}

/**/
Envy::EJanaManagerImplementation::EJanaManagerImplementation( const EJanaManagerImplementation& in_src )
: m_namePathJanaMap()
{
	( *this ) = in_src;

	return;
}

/**/
Envy::EJanaManagerImplementation::~EJanaManagerImplementation()
{
	m_namePathJanaMap.Clear();

	return;
}

/////////////////////////////////////////////////////////////////
// operators
/**/
const EJanaManagerImplementation& Envy::EJanaManagerImplementation::operator=( const EJanaManagerImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_namePathJanaMap = in_rhs.m_namePathJanaMap;
	}

	return( *this );
}

/**/
HBOOL Envy::EJanaManagerImplementation::operator==( const EJanaManagerImplementation& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != & in_rhs )
	{
		match &= ( m_namePathJanaMap == in_rhs.m_namePathJanaMap );
	}

	return match;
}

/**/
HBOOL Envy::EJanaManagerImplementation::operator!=( const EJanaManagerImplementation& in_rhs )const
{
	return( !operator==( in_rhs ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
HBOOL Envy::EJanaManagerImplementation::JanaToTanya( const EJana& in_jana, ETanya& out_tanya )
{
	//visit each block, if it inherits, find it in the map, recurses
	return ConvertJanaToTanya( in_jana, out_tanya, m_namePathJanaMap );
}

/**/
HBOOL Envy::EJanaManagerImplementation::JanaGet( const Hubris::HString& in_fileName, EJana& out_jana )
{
	HFileSystemPath path( in_fileName );
	TNamePathJanaMap::TIterator iterator = m_namePathJanaMap.Find( path.FileNameGet() );

	if( iterator != m_namePathJanaMap.End() )
	{
		out_jana = ( *iterator ).m_second;
	}

	return HFALSE;
}

/**/
HSINT Envy::EJanaManagerImplementation::FileCountGet()const
{
	return m_namePathJanaMap.SizeGet();
}

/**/
const Hubris::HString& Envy::EJanaManagerImplementation::FileNameGet( const HSINT in_index )const
{
	return m_namePathJanaMap.KeyGet( in_index );
}

/**/