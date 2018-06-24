//file: Envy/EMemento/EMementoUtility.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoUtility.h"

#include "Envy/EMemento/EMemento.h"
#include "Envy/EMemento/EMementoDataStore.h"
#include "Envy/EMemento/EMementoImplementation.h"

#include "Envy/ERecursiveDataStore/ERecursiveDataStoreUtility.h"

#include< Hubris/HFileSystem/HFileSystem_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Envy;
using namespace Hubris;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef ERecursiveDataStoreUtility< EMementoDataStore > TUtility;

/////////////////////////////////////////////////////////////////
// public methods
/**/
HBOOL EMementoUtility::Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, EMemento& out_memento )
{
	return TUtility::Load( in_fileSystem, in_filePath, out_memento.ImplementationGet().DataStoreGet() );
}

/**/
HBOOL EMementoUtility::SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EMemento& in_memento )
{
	return TUtility::SaveText( in_fileSystem, in_filePath, in_memento.ImplementationGet().DataStoreGet() );
}

/**/
HBOOL EMementoUtility::SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EMemento& in_memento )
{
	return TUtility::SaveBinary( in_fileSystem, in_filePath, in_memento.ImplementationGet().DataStoreGet() );
}

/**/

