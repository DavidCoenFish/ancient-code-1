//file: Envy/ETestbed/ETestbedJana.cpp

#include "Envy/ETestbed/ETestbedJana.h"

using namespace Envy;
using namespace Hubris;

//////////////////////////////////////////////////
// local variables
static const HCHAR* const s_extentionText = "jna";
static const HCHAR* const s_extentionBinary = "jnb";
static const HCHAR* const s_documentOneText = "janaDocumentOne.jna";
static const HCHAR* const s_documentTwoText = "janaDocumentTwo.jna";

//////////////////////////////////////////////////
// local free functions
/**/
static const Hubris::HBOOL LocalTestbedJana()
{
	HBOOL success = HTRUE;

	{
		EJana jana0;
		jana0.DataVariantSet( "foo", 123456 );
		EJana jana1( jana0 );
		EJana jana2 = jana0;
		EJana jana3;

		success &= ( jana0 == jana1 );
		success &= ( jana0 == jana2 );
		success &= ( jana0 != jana3 );
	}

	ETESTBED_VALIDATE_STATUS( "EJana", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedJanaManager()
{
	HBOOL success = HTRUE;

	HFileSystem fileSystem;

	//create some data
	{
		EJana jana0;
		jana0.DataVariantSet( "foo", HString( "base" ) );
		jana0.DataVariantSet( "bar", HU32( 123456 ) );
		EJana& child = jana0.ChildAdd( "baseChild" );
		child.DataVariantSet( "childData", HString( "baseChild" ) );

		EJanaUtility::DerrivableNameSet( jana0, "fubar" );

		EJanaUtility::SaveText( fileSystem, "data\\ETJ0.jna", jana0 );
	}

	{
		EJana jana0;
		jana0.DataVariantSet( "bar", HU32( 5 ) );
		EJanaUtility::ParentSet( jana0, "fubar", "ETJ0" );
		EJanaUtility::SaveText( fileSystem, "data\\ETJ1.jna", jana0 );
	}

	ETanya result0;
	{
		result0.DataVariantSet( "foo", HString( "base" ) );
		result0.DataVariantSet( "bar", HU32( 5 ) );
		ETanya& child = result0.ChildAdd( "baseChild" );
		child.DataVariantSet( "childData", HString( "baseChild" ) );
	}

	//EJanaManager( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_basePath, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary  );
	//EJanaManager( const EJanaManager& in_src );
	//~EJanaManager();
	//const EJanaManager& operator=( const EJanaManager& in_rhs );
	//Hubris::HBOOL operator==( const EJanaManager& in_rhs )const;
	//Hubris::HBOOL operator!=( const EJanaManager& in_rhs )const;
	{
		EJanaManager manager0( fileSystem, "data\\", s_extentionText, s_extentionBinary );
		EJanaManager manager1( manager0 );
		EJanaManager manager2 = manager0;
		EJanaManager manager3( fileSystem, "fake", s_extentionText, s_extentionBinary );

		success &= ( manager0 == manager1 );
		success &= ( manager1 == manager0 );

		success &= ( manager0 == manager2 );
		success &= ( manager2 == manager0 );

		success &= ( manager0 != manager3 );
		success &= ( manager3 != manager0 );

		success &= !( manager0 != manager2 );
		success &= !( manager2 != manager0 );

		success &= !( manager0 == manager3 );
		success &= !( manager3 == manager0 );
	}

	//Hubris::HBOOL JanaToTanya( const EJana& in_jana, ETanya& out_tanya );
	//Hubris::HBOOL JanaGet( const Hubris::HString& in_fileName, EJana& out_jana );
	{
		EJanaManager manager0( fileSystem, "data\\", s_extentionText, s_extentionBinary );
		EJana jana0;
		manager0.JanaGet( "ETJ1.jna", jana0 );

		ETanya tanya0;
		manager0.JanaToTanya( jana0, tanya0 ); 

		success &= ( result0 == tanya0 );
	}

	//Hubris::HSINT FileCountGet()const;
	//const Hubris::HString& FileNameGet( const Hubris::HSINT in_index )const;
	{
		EJanaManager manager0( fileSystem, "data\\", s_extentionText, s_extentionBinary );
		success &= ( 2 == manager0.FileCountGet() );
		success &= ( ( "ETJ0" == manager0.FileNameGet( 0 ) ) || ( "ETJ1" == manager0.FileNameGet( 0 ) ) );
		success &= ( ( "ETJ0" == manager0.FileNameGet( 1 ) ) || ( "ETJ1" == manager0.FileNameGet( 1 ) ) );
	}

	ETESTBED_VALIDATE_STATUS( "EJanaManager", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedJanaUtility()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_STATUS( "EJanaUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedJana()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedJana" );

	success &= LocalTestbedJana();
	success &= LocalTestbedJanaManager();
	success &= LocalTestbedJanaUtility();

	return success;
}

/**/