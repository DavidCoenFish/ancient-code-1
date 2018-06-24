//file: Envy/ETestbed/ETestbedRecursiveDataStore.cpp

#include "Envy/ETestbed/ETestbedRecursiveDataStore.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////////
// typedef
/**/
typedef HTYPE_LIST_4( HU8, HU16, HU32, HR64 ) TTypelistBasic;
HVARIANT_DEFINITION( TVariant, TTypelistBasic );
typedef ERecursiveDataStore< TVariant > TDataStore;
typedef HContainerArray< HString >TArrayString;

typedef HTYPE_LIST_3( TArrayString, HBOOL, HVectorR3 ) TTypelistComplex;
//typedef HTYPE_LIST_2( TArrayString, HBOOL ) TTypelistComplex;
HVARIANT_DEFINITION( TVariantComplex, TTypelistComplex );
typedef ERecursiveDataStore< TVariantComplex > TDataStoreComplex;

//variant
//collect values into a memento object
namespace Envy
{
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const TVariantComplex& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, TVariantComplex& out_data );
};


Hubris::HVOID Envy::EMementoTraitCollect< TVariantComplex >( EMementoCollect& in_out_mementoCollect, const TVariantComplex& in_data )
{
	EMementoTraitCollect( in_out_mementoCollect, ( const TVariantComplex::TVariantImplementation& )( in_data ) );
	return;
}
Hubris::HVOID Envy::EMementoTraitAssign< TVariantComplex >( const EMementoAssign& in_out_mementoAssign, TVariantComplex& out_data )
{
	EMementoTraitAssign( in_out_mementoAssign, ( TVariantComplex::TVariantImplementation& )( out_data ) );
	return;
}

//////////////////////////////////////////////////
// local free
/**/
static const Hubris::HBOOL LocalTestbedRecursiveDataStore()
{
	HBOOL success = HTRUE;

	//ERecursiveDataStore( const TDataStore& in_data );
	//ERecursiveDataStore();
	//~ERecursiveDataStore();
	//const TDataStore& operator=( const TDataStore& in_rhs );
	//Hubris::HBOOL operator==( const TDataStore& in_rhs )const;
	//Hubris::HBOOL operator!=( const TDataStore& in_rhs )const;
	{
		TDataStore dataStore0;
		dataStore0.DataVariantSet( "foo", ( HU8 ) 129 );
		TDataStore dataStore1( dataStore0 );
		TDataStore dataStore2 = dataStore0;
		TDataStore dataStore3;

		success &= ( dataStore0 == dataStore1 );
		success &= ( dataStore1 == dataStore0 );
		success &= ( dataStore0 == dataStore2 );
		success &= ( dataStore2 == dataStore0 );

		success &= !( dataStore0 == dataStore3 );
		success &= !( dataStore3 == dataStore0 );

		success &= ( dataStore0 != dataStore3 );
		success &= ( dataStore3 != dataStore0 );

		success &= !( dataStore0 != dataStore2 );
		success &= !( dataStore2 != dataStore0 );
	}

	//Hubris::HBOOL NameTest( const Hubris::HString& in_name )const;
	{
		TDataStore dataStore0;
		dataStore0.DataVariantSet( "foo", ( HU8 ) 129 );
		dataStore0.DataVariantSet( "bar", ( HU8 ) 110 );

		success &= ( HTRUE == dataStore0.NameTest( "foo" ) );
		success &= ( HTRUE == dataStore0.NameTest( "bar" ) );
		success &= ( HFALSE == dataStore0.NameTest( "moo" ) );
	}

	//HVOID NameListGet( TArrayString& out_arrayDataName, TArrayString& out_arrayChildName, TArrayString& out_arrayChildArrayName )const;
	//HVOID DataNameListGet( TArrayString& out_arrayName )const;
	//HVOID ChildNameListGet( TArrayString& out_arrayName )const;
	//HVOID ChildArrayNameListGet( TArrayString& out_arrayName )const;
	{
		TDataStore dataStore0;
		dataStore0.DataVariantSet( "foo", ( HU8 ) 129 );
		dataStore0.DataVariantSet( "bar", ( HU8 ) 110 );
		dataStore0.ChildAdd( "childA" );
		dataStore0.ChildAdd( "childB" );
		dataStore0.ChildAdd( "childC" );
		dataStore0.ChildArrayEmptyAdd( "childArrayA" );
		dataStore0.ChildArrayEmptyAdd( "childArrayB" );
		dataStore0.ChildArrayEmptyAdd( "childArrayC" );
		dataStore0.ChildArrayEmptyAdd( "childArrayD" );

		TArrayString arrayNameData0;
		TArrayString arrayNameData1;
		TArrayString arrayNameChild0;
		TArrayString arrayNameChild1;
		TArrayString arrayNameChildArray0;
		TArrayString arrayNameChildArray1;

		dataStore0.NameListGet( arrayNameData0, arrayNameChild0, arrayNameChildArray0 );
		dataStore0.DataNameListGet( arrayNameData1 );
		dataStore0.ChildNameListGet( arrayNameChild1 );
		dataStore0.ChildArrayNameListGet( arrayNameChildArray1 );

		success &= ( 2 == arrayNameData0.SizeGet() );
		success &= ( 2 == arrayNameData1.SizeGet() );
		success &= ( 3 == arrayNameChild0.SizeGet() );
		success &= ( 3 == arrayNameChild1.SizeGet() );
		success &= ( 4 == arrayNameChildArray0.SizeGet() );
		success &= ( 4 == arrayNameChildArray1.SizeGet() );
	}

	//TDataStore& ChildAdd( const Hubris::HString& in_childName );
	//Hubris::HBOOL ChildTest( const Hubris::HString& in_childName );
	//const TDataStore& ChildGet( const Hubris::HString& in_childName )const;
	//TDataStore& ChildGet( const Hubris::HString& in_childName );
	//HVOID ChildRemove( const Hubris::HString& in_childName );
	{
		TDataStore dataStore0;
		success &= ( HFALSE == dataStore0.ChildTest( "childA" ) );
		dataStore0.ChildAdd( "childA" );
		success &= ( HTRUE == dataStore0.ChildTest( "childA" ) );
		{
			const TDataStore& child = dataStore0.ChildGet( "childA" );
			success &= ( HFALSE == child.NameTest( "Foo" ) );
		}
		dataStore0.ChildRemove( "childA" );
		success &= ( HFALSE == dataStore0.ChildTest( "childA" ) );
	}

	//HVOID ChildArrayEmptyAdd( const Hubris::HString& in_childName );
	//TDataStore& ChildArrayAppend( const Hubris::HString& in_childName );
	//Hubris::HBOOL ChildArrayTest( const Hubris::HString& in_childName );
	//Hubris::HSINT ChildArrayCountGet( const Hubris::HString& in_childName )const;
	//const TDataStore& ChildArrayGet( const Hubris::HString& in_childName, const Hubris::HSINT in_index )const;
	//TDataStore& ChildArrayGet( const Hubris::HString& in_childName, const Hubris::HSINT in_index );
	//HVOID ChildArrayRemove( const Hubris::HString& in_childName );
	{
		TDataStore dataStore0;
		success &= ( HFALSE == dataStore0.ChildArrayTest( "childArrayA" ) );
		success &= ( HFALSE == dataStore0.ChildArrayTest( "childArrayB" ) );
		dataStore0.ChildArrayEmptyAdd( "childArrayA" );
		dataStore0.ChildArrayAppend( "childArrayB" );
		success &= ( HTRUE == dataStore0.ChildArrayTest( "childArrayA" ) );
		success &= ( HTRUE == dataStore0.ChildArrayTest( "childArrayB" ) );
		success &= ( 0 == dataStore0.ChildArrayCountGet( "childArrayA" ) );
		success &= ( 1 == dataStore0.ChildArrayCountGet( "childArrayB" ) );
		{
			const TDataStore& child = dataStore0.ChildArrayGet( "childArrayB", 0 );
			success &= ( HFALSE == child.NameTest( "Foo" ) );
		}
		dataStore0.ChildArrayRemove( "childArrayA" );
		dataStore0.ChildArrayRemove( "childArrayB" );
		success &= ( HFALSE == dataStore0.ChildArrayTest( "childArrayA" ) );
		success &= ( HFALSE == dataStore0.ChildArrayTest( "childArrayB" ) );
	}

	//Hubris::HBOOL DataVariantTest( const Hubris::HString& in_name )const;
	//const TVariantExchange DataVariantGet( const Hubris::HString& in_name )const;
	//HVOID DataVariantSet( const Hubris::HString& in_name, const TVariantExchange& in_variant );
	//HVOID DataRemove( const Hubris::HString& in_dataName );
	//Hubris::HBOOL DataTest( const Hubris::HString& in_dataName )const
	//const IN_TYPE& DataGet( const Hubris::HString& in_name )const
	{
		TDataStore dataStore0;
		success &= ( HFALSE == dataStore0.DataVariantTest( "dataA" ) );
		dataStore0.DataVariantSet( "dataA", ( HU8 )( 109 ) );
		success &= ( HTRUE == dataStore0.DataVariantTest( "dataA" ) );
		success &= ( HTRUE == dataStore0.DataTest< HU8 >( "dataA" ) );
		success &= ( HFALSE == dataStore0.DataTest< HS8 >( "dataA" ) );

		const HU8 value = dataStore0.DataGet< HU8 >( "dataA" );
		success &= ( 109 == value );

		dataStore0.DataRemove( "dataA" );
		success &= ( HFALSE == dataStore0.DataVariantTest( "dataA" ) );
	}

	ETESTBED_VALIDATE_STATUS( "RecursiveDataStore", success );

	return success;
}

/**/
static const Hubris::HBOOL  LocalTestbedRecursiveDataStoreTrait()
{
	HBOOL success = HTRUE;

	const HString name = HTraitName< TDataStore >::NameGet();
	success &= ( "ERecursiveDataStoreHTypeList_HU8_HU16_HU32_HR64" == name );

	TDataStoreComplex dataStoreComplex;
	TDataStoreComplex dataStoreComplex2;
	{
		TVariantComplex variantComplex( HBOOL( HTRUE ) );
		dataStoreComplex.DataSet( "data0", TVariantComplex( HTRUE ) ); 
		TArrayString arrayString;
		arrayString.Insert( "one" );
		arrayString.Insert( "two" );
		arrayString.Insert( "three" );
		dataStoreComplex.DataSet( "data1", TVariantComplex( arrayString ) ); 
		dataStoreComplex.DataSet( "data2", TVariantComplex( HMatrixConstructor::HVectorR3Construct( 10.4F, 11.7F, -6.0F ) ) ); 
		TDataStoreComplex& dataStoreComplex1 = dataStoreComplex.ChildAdd( "child0" );
		dataStoreComplex1.DataSet( "data3", TVariantComplex( HFALSE ) ); 

		EMemento memento;
		EMementoCollect mementoCollect( memento );
		mementoCollect.MemberAdd( "dataStore", dataStoreComplex );
		HFileSystem fileSystem;
		EMementoUtility::SaveText( fileSystem, "data\\ETRDS_Complex.txt", memento );

		EMemento memento2;
		EMementoUtility::Load( fileSystem, "data\\ETRDS_Complex.txt", memento2 );
		EMementoAssign mementoAssign( memento2 );
		mementoAssign.MemberGet( "dataStore", dataStoreComplex2 );

		success = ( dataStoreComplex == dataStoreComplex2 );
	}

	return success;
}

/**/
static const Hubris::HBOOL  LocalTestbedRecursiveDataStoreUtility()
{
	HBOOL success = HTRUE;

	typedef ERecursiveDataStoreUtility< TDataStore >TRecursiveDataStoreUtility;

	TDataStore dataStore0;
	dataStore0.DataVariantSet( "dataA", ( HU8 )( 109 ) );
	{
		TDataStore& child = dataStore0.ChildAdd( "childA" );
		child.DataVariantSet( "dataB", ( HU16 )( 599 ) );
		child.ChildArrayEmptyAdd( "childArrayD" );
	}
	{
		TDataStore& child = dataStore0.ChildAdd( "childB" );
		child.DataVariantSet( "dataC", ( HU32 )( 65599 ) );
		child.DataVariantSet( "dataD", ( HR64 )( 99.99 ) );
		child.ChildArrayAppend( "childArrayE" );
	}
	{
		TDataStore& child = dataStore0.ChildArrayAppend( "childArrayA" );
		child.DataVariantSet( "dataE", ( HU8 )( 199 ) );
		child.DataVariantSet( "dataF", ( HU8 )( 200 ) );
	}
	{
		TDataStore& child = dataStore0.ChildArrayAppend( "childArrayA" );
		child.DataVariantSet( "dataG", ( HU8 )( 199 ) );
		child.DataVariantSet( "dataH", ( HU8 )( 200 ) );
	}
	{
		TDataStore& child = dataStore0.ChildArrayAppend( "childArrayA" );
		child.DataVariantSet( "dataI", ( HU8 )( 199 ) );
		child.DataVariantSet( "dataJ", ( HU8 )( 200 ) );
	}
	{
		dataStore0.ChildArrayEmptyAdd( "childArrayC" );
	}

	//static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );
	{
		HFileSystem fileSystem;
		success &= TRecursiveDataStoreUtility::SaveText( fileSystem, "data\\RDSU0.txt", dataStore0 );
	}

	//static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );
	{
		HFileSystem fileSystem;
		success &= TRecursiveDataStoreUtility::SaveBinary( fileSystem, "data\\RDSU0.bin", dataStore0 );
	}

	//static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, TDataStore& out_dataStore );
	{
		HFileSystem fileSystem;
		TDataStore dataStore1;
		success &= TRecursiveDataStoreUtility::Load( fileSystem, "data\\RDSU0.txt", dataStore1 );
		success &= TRecursiveDataStoreUtility::SaveText( fileSystem, "data\\RDSU1.txt", dataStore1 );

		TDataStore dataStore2;
		success &= TRecursiveDataStoreUtility::Load( fileSystem, "data\\RDSU0.bin", dataStore2 );

		success &= ( dataStore0 == dataStore1 );
		success &= ( dataStore0 == dataStore2 );
	}

	ETESTBED_VALIDATE_STATUS( "RecursiveDataStoreUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedRecursiveDataStore()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedRecursiveDataStore" );

	success &= LocalTestbedRecursiveDataStore();
	success &= LocalTestbedRecursiveDataStoreTrait();
	success &= LocalTestbedRecursiveDataStoreUtility();

	return success;
}

/**/