//file: Envy/ETanya/ETanyaUtility.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/ETanya/ETanyaUtility.h"

#include "Envy/ETanya/ETanya.h"

#include "Envy/EMemento/EMemento_Export.h"
#include "Envy/ERecursiveDataStore/ERecursiveDataStore_Export.h"

#include< Hubris/HFileSystem/HFileSystem_Export.h >

//#include< Hubris/HMatrix/HMatrix_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// typedef
/**/
//typedef ERecursiveDataStoreUtility< ETanya > TUtility;

/////////////////////////////////////////////////////////////////
// public methods
/**/
HBOOL ETanyaUtility::Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, ETanya& out_document )
{
	//return TUtility::Load( in_fileSystem, in_filePath, out_document );
	EMemento memento;
	if( HFALSE == EMementoUtility::Load( in_fileSystem, in_filePath, memento ) )
	{
		return HFALSE;
	}
	EMementoAssign mementoAssign( memento );
	mementoAssign.MemberGet( "document", out_document );

	return HTRUE;
}

/**/
HBOOL ETanyaUtility::SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const ETanya& in_document )
{
	//return TUtility::SaveText( in_fileSystem, in_filePath, in_document );
	EMemento memento;
	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "document", in_document );

	if( HFALSE == EMementoUtility::SaveText( in_fileSystem, in_filePath, memento ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
HBOOL ETanyaUtility::SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const ETanya& in_document )
{
	//return TUtility::SaveBinary( in_fileSystem, in_filePath, in_document );
	EMemento memento;
	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "document", in_document );

	if( HFALSE == EMementoUtility::SaveBinary( in_fileSystem, in_filePath, memento ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/

