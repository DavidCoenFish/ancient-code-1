//file: Envy/ETestbed/ETestbedTanya.cpp

#include "Envy/ETestbed/ETestbedTanya.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Envy;
using namespace Hubris;

//////////////////////////////////////////////////
// local free functions
/**/
static const Hubris::HBOOL LocalTestbedTanya()
{
	HBOOL success = HTRUE;

	{
		ETanya tanya0;
		tanya0.DataVariantSet( "foo", 123456 );
		ETanya tanya1( tanya0 );
		ETanya tanya2 = tanya0;
		ETanya tanya3;

		success &= ( tanya0 == tanya1 );
		success &= ( tanya0 == tanya2 );
		success &= ( tanya0 != tanya3 );
	}

	ETESTBED_VALIDATE_STATUS( "ETanya", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedTanyaUtility()
{
	HBOOL success = HTRUE;

	ETanya tanya0;

	{
		tanya0.DataVariantSet( "data0", HTRUE );
		tanya0.DataVariantSet( "data1", HFALSE );
		tanya0.DataVariantSet( "data2", ( HU8 )199 );
		tanya0.DataVariantSet( "data3", ( HS8 )-109 );
		tanya0.DataVariantSet( "data4", ( HU16 )65509 );
		tanya0.DataVariantSet( "data5", ( HS16 )-20509 );
		tanya0.DataVariantSet( "data6", ( HU32 )6550900 );
		tanya0.DataVariantSet( "data7", ( HS32 )-2050900 );
		tanya0.DataVariantSet( "data8", ( HR32 )9.3F );
		//tanya0.DataVariantSet( "data9", ( HR64 )10.7 );
		tanya0.DataVariantSet( "data10", ( HCHAR )'j' );
		tanya0.DataVariantSet( "data11", HString( "fubar mar\nzoo" ) );

		HContainerArray< Hubris::HBOOL > arrayData0;
		arrayData0.Insert( HTRUE );
		arrayData0.Insert( HFALSE );
		arrayData0.Insert( HTRUE );
		HContainerArray< Hubris::HU8 > arrayData1;
		arrayData1.Insert( 5 );
		arrayData1.Insert( 1 );
		arrayData1.Insert( 199 );
		HContainerArray< Hubris::HS8 > arrayData2;
		arrayData2.Insert( 50 );
		arrayData2.Insert( 10 );
		arrayData2.Insert( -109 );
		HContainerArray< Hubris::HU16 > arrayData3;
		arrayData3.Insert( 500 );
		arrayData3.Insert( 100 );
		arrayData3.Insert( 19900 );
		HContainerArray< Hubris::HS16 > arrayData4;
		arrayData4.Insert( -501 );
		arrayData4.Insert( -101 );
		arrayData4.Insert( -19901 );
		HContainerArray< Hubris::HU32 > arrayData5;
		arrayData5.Insert( 50001 );
		arrayData5.Insert( 10001 );
		arrayData5.Insert( 1990001 );
		HContainerArray< Hubris::HS32 > arrayData6;
		arrayData6.Insert( -50100 );
		arrayData6.Insert( -10100 );
		arrayData6.Insert( -1990100 );
		HContainerArray< Hubris::HR32 > arrayData7;
		arrayData7.Insert( 10.3F );
		arrayData7.Insert( 10.4F );
		arrayData7.Insert( 10.5F );
		HContainerArray< Hubris::HR64 > arrayData8;
		arrayData8.Insert( 10.8 );
		arrayData8.Insert( 10.9 );
		arrayData8.Insert( 11.0 );
		HContainerArray< Hubris::HCHAR > arrayData9;
		arrayData9.Insert( 'A' );
		arrayData9.Insert( 'B' );
		arrayData9.Insert( 'C' );
		HContainerArray< Hubris::HString > arrayData10;
		arrayData10.Insert( "one" );
		arrayData10.Insert( "fine" );
		arrayData10.Insert( "day" );
		HContainerArray< Hubris::HString > arrayData11;

		tanya0.DataVariantSet( "data12", arrayData0 );
		tanya0.DataVariantSet( "data13", arrayData1 );
		tanya0.DataVariantSet( "data14", arrayData2 );
		tanya0.DataVariantSet( "data15", arrayData3 );
		tanya0.DataVariantSet( "data16", arrayData4 );
		tanya0.DataVariantSet( "data17", arrayData5 );
		tanya0.DataVariantSet( "data18", arrayData6 );
		tanya0.DataVariantSet( "data19", arrayData7 );
		//tanya0.DataVariantSet( "data20", arrayData8 );
		tanya0.DataVariantSet( "data21", arrayData9 );
		tanya0.DataVariantSet( "data22", arrayData10 );
		tanya0.DataVariantSet( "data23", arrayData11 );
	}

	HFileSystem fileSystem;
	//static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, ETanya& out_document );
	//static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const ETanya& in_document );
	//static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const ETanya& in_document );
	{
		success &= ETanyaUtility::SaveText( fileSystem, "data\\TT.Txt", tanya0 );
		success &= ETanyaUtility::SaveBinary( fileSystem, "data\\TT.bin", tanya0 );
	}

	{
		ETanya tanya1;
		ETanya tanya2;
		ETanyaUtility::Load( fileSystem, "data\\TT.Txt", tanya1 );
		ETanyaUtility::Load( fileSystem, "data\\TT.bin", tanya2 );

		success &= ( tanya0 == tanya1 );
		success &= ( tanya0 == tanya2 );
	}

	ETESTBED_VALIDATE_STATUS( "ETanyaUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedTanya()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedTanya" );

	success &= LocalTestbedTanya();
	success &= LocalTestbedTanyaUtility();

	return success;
}

/**/