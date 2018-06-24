//file: Envy/EJana/EJanaUtility.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EJana/EJanaUtility.h"
#include "Envy/EJana/EJana.h"

#include "Envy/ETanya/ETanyaUtility.h"

#include< Hubris/HFileSystem/HFileSystem_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Envy;
using namespace Hubris;

/////////////////////////////////////////////////////////////////
// static local variables
/**/
static const HCHAR* const s_parentName = "JANA_PARENT_NAME";
static const HCHAR* const s_parentFile = "JANA_PARENT_FILE";
static const HCHAR* const s_derrivableName = "JANA_NAME";

/////////////////////////////////////////////////////////////////
// static public methods
/**/
HBOOL Envy::EJanaUtility::Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, EJana& out_document )
{
	return ETanyaUtility::Load( in_fileSystem, in_filePath, out_document );
}

/**/
HBOOL Envy::EJanaUtility::SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EJana& in_document )
{
	return ETanyaUtility::SaveText( in_fileSystem, in_filePath, in_document );
}

/**/
HBOOL Envy::EJanaUtility::SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EJana& in_document )
{
	return ETanyaUtility::SaveBinary( in_fileSystem, in_filePath, in_document );
}

/**/
void Envy::EJanaUtility::ParentSet( EJana& in_document, const HString& in_parentName, const HString& in_fileName )
{
	in_document.DataVariantSet( s_parentName, in_parentName );

	const Hubris::HFileSystemPath fileName( in_fileName );
	in_document.DataVariantSet( s_parentFile, fileName.FileNameGet() );

	return;
}

/**/
HBOOL Envy::EJanaUtility::ParentGet( const EJana& in_document, HString& out_parentName, HString& out_fileName )
{
	HBOOL found = HTRUE;

	found &= ( HTRUE == in_document.DataTest< HString >( s_parentName ) );
	found &= ( HTRUE == in_document.DataTest< HString >( s_parentFile ) );

	if( HTRUE == found )
	{
		out_parentName = in_document.DataGet< HString >( s_parentName );
		out_fileName = in_document.DataGet< HString >( s_parentFile );
	}

	return found;
}

/**/
void Envy::EJanaUtility::ParentRemove( ETanya& in_out_tanya )
{
	in_out_tanya.DataRemove( s_parentName );
	in_out_tanya.DataRemove( s_parentFile );

	return;
}

/**/
void Envy::EJanaUtility::DerrivableNameSet( EJana& in_document, const HString& in_derrivableName )
{
	in_document.DataVariantSet( s_derrivableName, in_derrivableName );

	return;
}

/**/
HBOOL Envy::EJanaUtility::DerrivableNameGet( const EJana& in_document, HString& out_derrivableName )
{
	HBOOL found = HTRUE;

	found &= ( HTRUE == in_document.DataTest< HString >( s_derrivableName ) );

	if( HTRUE == found )
	{
		out_derrivableName = in_document.DataGet< HString >( s_derrivableName );
	}

	return found;
}

/**/
void Envy::EJanaUtility::DerrivableRemove( ETanya& in_out_tanya )
{
	in_out_tanya.DataRemove( s_derrivableName );

	return;
}

/**/
