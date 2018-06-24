//file: Envy/ETestbed/ETestbedDataStore.cpp

#include "Envy/ETestbed/ETestbedDataStore.h"

using namespace Hubris;
using namespace Envy;

//typedef Hubris::HVariant< HTYPE_LIST_4( HU8, HU16, HU32, HR64 ) > TVariant;
HVARIANT_DEFINITION( TVariant, HTYPE_LIST_4( HU8, HU16, HU32, HR64 ) );
typedef EDataStore< TVariant >TDataStore;

//////////////////////////////////////////////////
// local free
/**/
static const Hubris::HBOOL LocalTestbedDataStore()
{
	HBOOL success = HTRUE;

	//EDataStore( const EDataStore& in_data );
	//EDataStore();
	//~EDataStore();
	//const EDataStore& operator=( const EDataStore& in_rhs );
	//Hubris::HBOOL operator==( const EDataStore& in_rhs )const;
	//Hubris::HBOOL operator!=( const EDataStore& in_rhs )const;
	{
		TDataStore dataStore0;
		dataStore0.DataSet( "foo", ( HU16 )65500 );
		TDataStore dataStore1( dataStore0 );
		TDataStore dataStore2 = dataStore0;
		TDataStore dataStore3;

		success &= ( dataStore0 == dataStore1 );
		success &= ( dataStore1 == dataStore0 );

		success &= ( dataStore0 == dataStore2 );
		success &= ( dataStore2 == dataStore0 );

		success &= ( dataStore0 != dataStore3 );
		success &= ( dataStore3 != dataStore0 );

		success &= !( dataStore0 != dataStore2 );
		success &= !( dataStore2 != dataStore0 );

		success &= !( dataStore0 == dataStore3 );
		success &= !( dataStore3 == dataStore0 );
	}
	//template< typename IN_TYPE >void DataSet( const Hubris::HString& in_name, const IN_TYPE& in_value )
	//void DataVariantSet( const Hubris::HString& in_name, const TVariant& in_value );
	//template< typename IN_TYPE >Hubris::HBOOL DataTest( const Hubris::HString& in_name )const
	//template< typename IN_TYPE >const IN_TYPE& DataGet( const Hubris::HString& in_name )const
	//template< typename IN_TYPE >const IN_TYPE& DataDefaultGet( const Hubris::HString& in_name, const IN_TYPE& in_defaultValue )
	//const typename TVariant& DataVariantGet( const Hubris::HString& in_name )const;
	//Hubris::HBOOL DataVariantTest( const Hubris::HString& in_name )const;
	//void DataRemove( const Hubris::HString& in_name );
	{
		TDataStore dataStore0;
		dataStore0.DataSet< HU16 >( "data0", 12345 );
		dataStore0.DataVariantSet( "data1", ( HU32 )123456 );
		success &= ( HTRUE == dataStore0.DataTest< HU16 >( "data0" ) );
		success &= ( HFALSE == dataStore0.DataTest< HS16 >( "data0" ) );
		success &= ( HFALSE == dataStore0.DataTest< HU16 >( "data2" ) );
		success &= ( 12345 == dataStore0.DataGet< HU16 >( "data0" ) );
		success &= ( HTRUE == dataStore0.DataVariantTest( "data0" ) );
		success &= ( HFALSE == dataStore0.DataVariantTest( "data3" ) );
		success &= ( HTRUE == dataStore0.DataVariantGet( "data0" ).TypeTest< HU16 >() );
		dataStore0.DataRemove( "data0" );
		success &= ( HFALSE == dataStore0.DataVariantTest( "data0" ) );
	}

	//void DataClear();
	//Hubris::HSINT DataCountGet()const;
	//const Hubris::HString& DataNameGet( const Hubris::HSINT in_index )const;
	{
		TDataStore dataStore0;
		success &= ( 0 == dataStore0.DataCountGet() );
		dataStore0.DataSet( "foo", ( HU16 )65500 );

		success &= ( 1 == dataStore0.DataCountGet() );
		success &= ( "foo" == dataStore0.DataNameGet( 0 ) );
		dataStore0.DataSet( "bar", ( HU16 )1189 );

		success &= ( 2 == dataStore0.DataCountGet() );
		dataStore0.DataClear();
		success &= ( 0 == dataStore0.DataCountGet() );
	}


	ETESTBED_VALIDATE_STATUS( "EDataStore", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedDataStoreTrait()
{
	HBOOL success = HTRUE;

	{
		success &= ( "EDataStore_HTypeList_HU8_HU16_HU32_HR64" == HTraitName< TDataStore >::NameGet() );
	}

	ETESTBED_VALIDATE_STATUS( "EDataStoreTrait", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedDataStoreUtility()
{
	HBOOL success = HTRUE;

	typedef EDataStoreUtility< TDataStore >TDataStoreUtility;
	//static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );
	//static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );
	//static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, TDataStore& out_dataStore );
	{
		TDataStore dataStore0;
		dataStore0.DataSet< HU8 >( "data0", 200 );
		dataStore0.DataSet< HU16 >( "data1", 65500 );
		dataStore0.DataSet< HU32 >( "data2", 65599 );
		dataStore0.DataSet< HR64 >( "data3", 10.3 );
		dataStore0.DataSet< HU8 >( "data4", 201 );

		HFileSystem fileSystem;

		TDataStore dataStore1;
		TDataStore dataStore2;

		success &= TDataStoreUtility::SaveText( fileSystem, "data\\TDS0.txt", dataStore0 );
		success &= TDataStoreUtility::SaveBinary( fileSystem, "data\\TDS0.bin", dataStore0 );
		success &= TDataStoreUtility::Load( fileSystem, "data\\TDS0.txt", dataStore1 );
		success &= TDataStoreUtility::Load( fileSystem, "data\\TDS0.bin", dataStore2 );
	
		success &= ( dataStore0 == dataStore1 );
		success &= ( dataStore0 == dataStore2 );
	}

	//static const IN_TYPE& DataDefaultGet( IN_DATA_STORE& in_out_dataStore, const Hubris::HString& in_name, const IN_TYPE& in_defaultValue )
	{
		TDataStore dataStore0;
		success &= ( 200 == TDataStoreUtility::DataDefaultGet< HU8 >( dataStore0, "data0", 200 ) );
		success &= ( 200 == TDataStoreUtility::DataDefaultGet< HU8 >( dataStore0, "data0", 201 ) );
	}

	ETESTBED_VALIDATE_STATUS( "EDataStoreUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedDataStore()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedDataStore" );

	success &= LocalTestbedDataStore();
	success &= LocalTestbedDataStoreTrait();
	success &= LocalTestbedDataStoreUtility();

	return success;
}

/**/