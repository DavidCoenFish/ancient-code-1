//file: Envy/ETestbed/ETestbedMemento.cpp

#include "Envy/ETestbed/ETestbedMemento.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HString >TArrayString;
typedef HContainerPair< HSINT, TArrayString >TPairIntArrayString;
typedef HContainerArray< TPairIntArrayString >TArrayPairIntArrayString;


class TestClassData
{
public:
	TestClassData( const TestClassData& in_src )
	: m_data0( 0 )
	, m_data1( 0 )
	, m_data2( 0 )
	, m_data3( 0 )
	, m_data4( 0 )
	, m_data5( 0 )
	, m_data6( 0 )
	, m_data7( 0 )
	, m_data8( 0 )
	, m_data9( 0 )
	, m_data10( 0 )
	, m_arrayData0()
	, m_arrayData1()
	, m_arrayData2()
	, m_arrayData3()
	, m_arrayData4()
	, m_arrayData5()
	, m_arrayData6()
	, m_arrayData7()
	, m_arrayData8()
	, m_arrayData9()
	, m_arrayData10()
	, m_arrayData11()
	{
		( *this ) = in_src;
		return;
	}

	TestClassData()
	: m_data0( 0 )
	, m_data1( 0 )
	, m_data2( 0 )
	, m_data3( 0 )
	, m_data4( 0 )
	, m_data5( 0 )
	, m_data6( 0 )
	, m_data7( 0 )
	, m_data8( 0 )
	, m_data9( 0 )
	, m_data10( 0 )
	, m_arrayData0()
	, m_arrayData1()
	, m_arrayData2()
	, m_arrayData3()
	, m_arrayData4()
	, m_arrayData5()
	, m_arrayData6()
	, m_arrayData7()
	, m_arrayData8()
	, m_arrayData9()
	, m_arrayData10()
	, m_arrayData11()
	{
		return;
	}

	HVOID Initialise()
	{
		m_data0 = 155;
		m_data1 = -99;
		m_data2 = 65500;
		m_data3 = -30000;
		m_data4 = 66666;
		m_data5 = -66666;
		m_data6 = 10.75F;
		m_data7 = 11.5;
		m_data8 = HTRUE;
		m_data9 = 'j';
		m_data10 = "hello world";
		m_arrayData0.Insert( 5 );
		m_arrayData0.Insert( 10 );
		m_arrayData0.Insert( 15 );
		m_arrayData1.Insert( -10 );
		m_arrayData1.Insert( -20 );
		m_arrayData1.Insert( -30 );
		m_arrayData2.Insert( 550 );
		m_arrayData2.Insert( 551 );
		m_arrayData2.Insert( 552 );
		m_arrayData3.Insert( -555 );
		m_arrayData3.Insert( -556 );
		m_arrayData3.Insert( -557 );
		m_arrayData4.Insert( 123456 );
		m_arrayData4.Insert( 123457 );
		m_arrayData4.Insert( 123458 );
		m_arrayData5.Insert( -123450 );
		m_arrayData5.Insert( -123451 );
		m_arrayData5.Insert( -123452 );
		m_arrayData6.Insert( 10.3F );
		m_arrayData6.Insert( 10.4F );
		m_arrayData6.Insert( 10.5F );
		m_arrayData7.Insert( 11.4 );
		m_arrayData7.Insert( -12.3 );
		m_arrayData7.Insert( 100.7 );
		m_arrayData8.Insert( HTRUE );
		m_arrayData8.Insert( HFALSE );
		m_arrayData8.Insert( HTRUE );
		m_arrayData9.Insert( 'a' );
		m_arrayData9.Insert( 'b' );
		m_arrayData9.Insert( 'c' );
		m_arrayData10.Insert( "foo" );
		m_arrayData10.Insert( "boo" );
		m_arrayData10.Insert( "zo \no" );

		{
			TArrayString arrayString;
			arrayString.Insert( "one" );
			arrayString.Insert( "fine" );
			arrayString.Insert( "day" );
			m_arrayData11.Insert(
				TPairIntArrayString(
					108,
					arrayString
					)
				);
		}
		{
			TArrayString arrayString;
			arrayString.Insert( "in" );
			arrayString.Insert( "the" );
			m_arrayData11.Insert(
				TPairIntArrayString(
					56,
					arrayString
					)
				);
		}

		return;
	}

	~TestClassData(){ return; }
	const TestClassData& operator=( const TestClassData& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_data0 = in_rhs.m_data0;
			m_data1 = in_rhs.m_data1;
			m_data2 = in_rhs.m_data2;
			m_data3 = in_rhs.m_data3;
			m_data4 = in_rhs.m_data4;
			m_data5 = in_rhs.m_data5;
			m_data6 = in_rhs.m_data6;
			m_data7 = in_rhs.m_data7;
			m_data8 = in_rhs.m_data8;
			m_data9 = in_rhs.m_data9;
			m_data10 = in_rhs.m_data10;
			m_arrayData0 = in_rhs.m_arrayData0;
			m_arrayData1 = in_rhs.m_arrayData1;
			m_arrayData2 = in_rhs.m_arrayData2;
			m_arrayData3 = in_rhs.m_arrayData3;
			m_arrayData4 = in_rhs.m_arrayData4;
			m_arrayData5 = in_rhs.m_arrayData5;
			m_arrayData6 = in_rhs.m_arrayData6;
			m_arrayData7 = in_rhs.m_arrayData7;
			m_arrayData8 = in_rhs.m_arrayData8;
			m_arrayData9 = in_rhs.m_arrayData9;
			m_arrayData10 = in_rhs.m_arrayData10;
			m_arrayData11 = in_rhs.m_arrayData11;
		}

		return( *this );
	}

	HBOOL operator==( const TestClassData& in_rhs )const
	{
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match &= ( m_data0 == in_rhs.m_data0 );
			match &= ( m_data1 == in_rhs.m_data1 );
			match &= ( m_data2 == in_rhs.m_data2 );
			match &= ( m_data3 == in_rhs.m_data3 );
			match &= ( m_data4 == in_rhs.m_data4 );
			match &= ( m_data5 == in_rhs.m_data5 );
			match &= ( m_data6 == in_rhs.m_data6 );
			match &= ( m_data7 == in_rhs.m_data7 );
			match &= ( m_data8 == in_rhs.m_data8 );
			match &= ( m_data9 == in_rhs.m_data9 );
			match &= ( m_data10 == in_rhs.m_data10 );
			match &= ( m_arrayData0 == in_rhs.m_arrayData0 );
			match &= ( m_arrayData1 == in_rhs.m_arrayData1 );
			match &= ( m_arrayData2 == in_rhs.m_arrayData2 );
			match &= ( m_arrayData3 == in_rhs.m_arrayData3 );
			match &= ( m_arrayData4 == in_rhs.m_arrayData4 );
			match &= ( m_arrayData5 == in_rhs.m_arrayData5 );
			match &= ( m_arrayData6 == in_rhs.m_arrayData6 );
			match &= ( m_arrayData7 == in_rhs.m_arrayData7 );
			match &= ( m_arrayData8 == in_rhs.m_arrayData8 );
			match &= ( m_arrayData9 == in_rhs.m_arrayData9 );
			match &= ( m_arrayData10 == in_rhs.m_arrayData10 );
			match &= ( m_arrayData11 == in_rhs.m_arrayData11 );
		}

		return match;
	}
	HBOOL operator!=( const TestClassData& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

public:
	HU8 m_data0;
	HS8 m_data1;
	HU16 m_data2;
	HS16 m_data3;
	HU32 m_data4;
	HS32 m_data5;
	HR32 m_data6;
	HR64 m_data7;
	HBOOL m_data8;
	HCHAR m_data9;
	HString m_data10;
	HContainerArray< Hubris::HU8 > m_arrayData0;
	HContainerArray< Hubris::HS8 > m_arrayData1;
	HContainerArray< Hubris::HU16 > m_arrayData2;
	HContainerArray< Hubris::HS16 > m_arrayData3;
	HContainerArray< Hubris::HU32 > m_arrayData4;
	HContainerArray< Hubris::HS32 > m_arrayData5;
	HContainerArray< Hubris::HR32 > m_arrayData6;
	HContainerArray< Hubris::HR64 > m_arrayData7;
	HContainerArray< Hubris::HBOOL > m_arrayData8;
	HContainerArray< Hubris::HCHAR > m_arrayData9;
	HContainerArray< Hubris::HString > m_arrayData10;
	TArrayPairIntArrayString m_arrayData11;

};

template<> HVOID Envy::EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const TestClassData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_data0", in_data.m_data0 );
	in_out_mementoCollect.MemberAdd( "m_data1", in_data.m_data1 );
	in_out_mementoCollect.MemberAdd( "m_data2", in_data.m_data2 );
	in_out_mementoCollect.MemberAdd( "m_data3", in_data.m_data3 );
	in_out_mementoCollect.MemberAdd( "m_data4", in_data.m_data4 );
	in_out_mementoCollect.MemberAdd( "m_data5", in_data.m_data5 );
	in_out_mementoCollect.MemberAdd( "m_data6", in_data.m_data6 );
	in_out_mementoCollect.MemberAdd( "m_data7", in_data.m_data7 );
	in_out_mementoCollect.MemberAdd( "m_data8", in_data.m_data8 );
	in_out_mementoCollect.MemberAdd( "m_data9", in_data.m_data9 );
	in_out_mementoCollect.MemberAdd( "m_data10", in_data.m_data10 );
	in_out_mementoCollect.MemberAdd( "m_arrayData0", in_data.m_arrayData0 );
	in_out_mementoCollect.MemberAdd( "m_arrayData1", in_data.m_arrayData1 );
	in_out_mementoCollect.MemberAdd( "m_arrayData2", in_data.m_arrayData2 );
	in_out_mementoCollect.MemberAdd( "m_arrayData3", in_data.m_arrayData3 );
	in_out_mementoCollect.MemberAdd( "m_arrayData4", in_data.m_arrayData4 );
	in_out_mementoCollect.MemberAdd( "m_arrayData5", in_data.m_arrayData5 );
	in_out_mementoCollect.MemberAdd( "m_arrayData6", in_data.m_arrayData6 );
	in_out_mementoCollect.MemberAdd( "m_arrayData7", in_data.m_arrayData7 );
	in_out_mementoCollect.MemberAdd( "m_arrayData8", in_data.m_arrayData8 );
	in_out_mementoCollect.MemberAdd( "m_arrayData9", in_data.m_arrayData9 );
	in_out_mementoCollect.MemberAdd( "m_arrayData10", in_data.m_arrayData10 );
	in_out_mementoCollect.MemberAdd( "m_arrayData11", in_data.m_arrayData11 );

	return;
}

template<> HVOID Envy::EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, TestClassData& out_data )
{
	in_out_mementoAssign.MemberGet( "m_data0", out_data.m_data0 );
	in_out_mementoAssign.MemberGet( "m_data1", out_data.m_data1 );
	in_out_mementoAssign.MemberGet( "m_data2", out_data.m_data2 );
	in_out_mementoAssign.MemberGet( "m_data3", out_data.m_data3 );
	in_out_mementoAssign.MemberGet( "m_data4", out_data.m_data4 );
	in_out_mementoAssign.MemberGet( "m_data5", out_data.m_data5 );
	in_out_mementoAssign.MemberGet( "m_data6", out_data.m_data6 );
	in_out_mementoAssign.MemberGet( "m_data7", out_data.m_data7 );
	in_out_mementoAssign.MemberGet( "m_data8", out_data.m_data8 );
	in_out_mementoAssign.MemberGet( "m_data9", out_data.m_data9 );
	in_out_mementoAssign.MemberGet( "m_data10", out_data.m_data10 );
	in_out_mementoAssign.MemberGet( "m_arrayData0", out_data.m_arrayData0 );
	in_out_mementoAssign.MemberGet( "m_arrayData1", out_data.m_arrayData1 );
	in_out_mementoAssign.MemberGet( "m_arrayData2", out_data.m_arrayData2 );
	in_out_mementoAssign.MemberGet( "m_arrayData3", out_data.m_arrayData3 );
	in_out_mementoAssign.MemberGet( "m_arrayData4", out_data.m_arrayData4 );
	in_out_mementoAssign.MemberGet( "m_arrayData5", out_data.m_arrayData5 );
	in_out_mementoAssign.MemberGet( "m_arrayData6", out_data.m_arrayData6 );
	in_out_mementoAssign.MemberGet( "m_arrayData7", out_data.m_arrayData7 );
	in_out_mementoAssign.MemberGet( "m_arrayData8", out_data.m_arrayData8 );
	in_out_mementoAssign.MemberGet( "m_arrayData9", out_data.m_arrayData9 );
	in_out_mementoAssign.MemberGet( "m_arrayData10", out_data.m_arrayData10 );
	in_out_mementoAssign.MemberGet( "m_arrayData11", out_data.m_arrayData11 );

	return;
}

/**/
class TestClass
{
public:
	TestClass()
	: m_real( 0 )
	, m_short( 0 )
	, m_string()
	, m_data()
	, m_arrayData()
	, m_treeData()
	{
		return;
	}

	HVOID Initialise()
	{
		m_real = 0.5F;
		m_short = -512;
		m_string = "now is the time for all good men to come to the aid of the party";
		m_data.Initialise();
		m_arrayData.Insert( m_data );
		m_treeData.Insert( "Initialise", m_data );
		m_treeData.Insert( "Default", TestClassData() );
		return;
	}

	~TestClass(){ return; }
	HBOOL operator==( const TestClass& in_rhs )const
	{
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match &= ( m_real == in_rhs.m_real );
			match &= ( m_short == in_rhs.m_short );
			match &= ( m_string == in_rhs.m_string );
			match &= ( m_data == in_rhs.m_data );
			match &= ( m_arrayData == in_rhs.m_arrayData );
			match &= ( m_treeData == in_rhs.m_treeData );
		}

		return match;
	}
	HBOOL operator!=( const TestClass& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}
public:
	HREAL m_real;
	HS16 m_short;
	HString m_string;
	TestClassData m_data;
	HContainerArray< TestClassData > m_arrayData;
	HContainerTree< HString, TestClassData > m_treeData;
};

/**/
//template< typename IN_TYPE > HVOID Envy::EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );

template<> HVOID Envy::EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const TestClass& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_real", in_data.m_real );
	in_out_mementoCollect.MemberAdd( "m_short", in_data.m_short );
	in_out_mementoCollect.MemberAdd( "m_string", in_data.m_string );
	in_out_mementoCollect.MemberAdd( "m_data", in_data.m_data );
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.m_arrayData );
	in_out_mementoCollect.MemberAdd( "m_treeData", in_data.m_treeData );

	return;
}

template<> HVOID Envy::EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, TestClass& out_data )
{
	in_out_mementoAssign.MemberGet( "m_real", out_data.m_real );
	in_out_mementoAssign.MemberGet( "m_short", out_data.m_short );
	in_out_mementoAssign.MemberGet( "m_string", out_data.m_string );
	in_out_mementoAssign.MemberGet( "m_data", out_data.m_data );
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.m_arrayData );
	in_out_mementoAssign.MemberGet( "m_treeData", out_data.m_treeData );
	return;
}

class TestClassPointer
{
	EMEMENTO_FACTORY_HEADER( TestClassPointer )
public:
	TestClassPointer() : m_value( 3 ){ return; }
	~TestClassPointer(){ return; }
public:
	Hubris::HSINT m_value;
};

HTYPE_NAME_HEADER( TestClassPointer );
HTYPE_NAME_IMPLEMENTATION( TestClassPointer );
EMEMENTO_FACTORY_SOURCE( TestClassPointer, TestClassPointer );

class TestClassPointerDerived : public TestClassPointer
{
	EMEMENTO_FACTORY_HEADER( TestClassPointer )
public:
	TestClassPointerDerived() : TestClassPointer(), m_other( 5 ){ return; }
	~TestClassPointerDerived(){ return; }
public:
	Hubris::HSINT m_other;
};

HTYPE_NAME_HEADER( TestClassPointerDerived );
HTYPE_NAME_IMPLEMENTATION( TestClassPointerDerived );
EMEMENTO_FACTORY_SOURCE( TestClassPointerDerived, TestClassPointer );

template<> HVOID Envy::EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const TestClassPointer& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_value", in_data.m_value );
	return;
}

template<> HVOID Envy::EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, TestClassPointer& out_data )
{
	in_out_mementoAssign.MemberGet( "m_value", out_data.m_value );
	return;
}

template<> HVOID Envy::EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const TestClassPointerDerived& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_value", in_data.m_value );
	in_out_mementoCollect.MemberAdd( "m_other", in_data.m_other );
	return;
}

template<> HVOID Envy::EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, TestClassPointerDerived& out_data )
{
	in_out_mementoAssign.MemberGet( "m_value", out_data.m_value );
	in_out_mementoAssign.MemberGet( "m_other", out_data.m_other );
	return;
}

//////////////////////////////////////////////////
// local free
/**/
static const Hubris::HBOOL LocalTestbedMemento()
{
	HBOOL success = HTRUE;

	//EMemento( const EMemento& in_src );
	//EMemento();
	//~EMemento();
	//const EMemento& operator=( const EMemento& in_rhs );
	//Hubris::HBOOL operator==( const EMemento& in_rhs )const;
	//Hubris::HBOOL operator!=( const EMemento& in_rhs )const;
	{
		EMemento memento0;

		{
			EMementoCollect mementoCollect( memento0 );
			mementoCollect.MemberAdd( "foo", 123456 );
			mementoCollect.MemberAdd( "bar", 10.3 );
		}

		EMemento memento1( memento0 );
		EMemento memento2 = memento0;
		EMemento memento3;

		success &= ( memento0 == memento1 );
		success &= ( memento1 == memento0 );

		success &= ( memento0 == memento2 );
		success &= ( memento2 == memento0 );

		success &= ( memento0 != memento3 );
		success &= ( memento3 != memento0 );

		success &= !( memento0 != memento2 );
		success &= !( memento2 != memento0 );

		success &= !( memento0 == memento3 );
		success &= !( memento3 == memento0 );
	}

	ETESTBED_VALIDATE_STATUS( "Memento", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedMementoAssignCollect()
{
	HBOOL success = HTRUE;

	TestClass testClass0;
	testClass0.Initialise();

	EMemento memento;

	{
		EMementoCollect mementoCollect( memento );
		mementoCollect.MemberAdd( "testClass", testClass0 );
	}

	TestClass testClass1;

	{
		EMementoAssign mementoAssign( memento );
		mementoAssign.MemberGet( "testClass", testClass1 );
	}

	success &= ( testClass0 == testClass1 );
	success &= ( testClass0 != TestClass() );
	success &= ( TestClass() == TestClass() );

	ETESTBED_VALIDATE_STATUS( "Memento", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedMementoTrait()
{
	HBOOL success = HTRUE;

	//HFileSystemPath
	{
		HFileSystemPath path0;
		path0.PathFileNameExtentionSet( "w:\\test\\the\\path.txt" );
		EMemento memento;
		{
			EMementoCollect mementoCollect( memento );
			mementoCollect.MemberAdd( "path", path0 );
		}

		HFileSystemPath path1;
		{
			EMementoAssign mementoAssign( memento );
			mementoAssign.MemberGet( "path", path1 );
		}

		success &= ( path0 == path1 );
		success &= ( path0 != HFileSystemPath() );
	}

	ETESTBED_VALIDATE_STATUS( "Memento", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedMementoUtility()
{
	HBOOL success = HTRUE;

	HFileSystem fileSystem;

	TestClass testClass0;
	testClass0.Initialise();

	//EMementoUtility
	//Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EMemento& in_memento );
	//Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EMemento& in_memento );
	{
		EMemento memento0;
		EMementoCollect mementoCollect( memento0 );
		mementoCollect.MemberAdd( "testClass", testClass0 );

		success &= EMementoUtility::SaveBinary( fileSystem, "data\\TM.bin", memento0 );
		success &= EMementoUtility::SaveText( fileSystem, "data\\TM.txt", memento0 );
	}

	TestClass testClass1;
	TestClass testClass2;

	//Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, EMemento& out_memento );
	{
		EMemento memento0;
		success &= EMementoUtility::Load( fileSystem, "data\\TM.bin", memento0 );

		EMementoAssign mementoAssign( memento0 );
		mementoAssign.MemberGet( "testClass", testClass1 );
	}
	{
		EMemento memento0;
		success &= EMementoUtility::Load( fileSystem, "data\\TM.txt", memento0 );

		EMementoAssign mementoAssign( memento0 );
		mementoAssign.MemberGet( "testClass", testClass2 );
	}

	success &= ( testClass0 == testClass1 );
	success &= ( testClass0 == testClass2 );
	success &= ( testClass0 != TestClass() );
	success &= ( TestClass() == TestClass() );

	ETESTBED_VALIDATE_STATUS( "Memento", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalTestbedMementoPointers()
{
	HBOOL success = HTRUE;

	EMEMENTO_FACTORY_REGISTER( TestClassPointer, TestClassPointer ); 
	EMEMENTO_FACTORY_REGISTER( TestClassPointerDerived, TestClassPointer ); 

	{
		TestClassPointer classPointer0;
		TestClassPointerDerived classPointer1;
		classPointer1.m_other = 20;
		classPointer1.m_value = 21;
		EMemento memento0;
		EMementoCollect mementoCollect( memento0 );

		TestClassPointer* const pClass0 = &classPointer0;
		TestClassPointer* const pClassDerrived0 = &classPointer1;
		TestClassPointer* const pClassNULL = HNULL;
		mementoCollect.PointerAdd( "pClass0", pClass0 );
		mementoCollect.OwnedPointerAdd( "pClass1", pClass0 );
		mementoCollect.OwnedPointerAdd( "pClassDerrived0", pClassDerrived0 );
		mementoCollect.PointerAdd( "pClassDerrived1", pClassDerrived0 );
		mementoCollect.OwnedPointerAdd( "pClassNULL0", pClassNULL );
		mementoCollect.PointerAdd( "pClassNULL1", pClassNULL );

		HFileSystem fileSystem;
		EMementoUtility::SaveText( fileSystem, "data\\empointer.txt",  memento0 );
	}

	{
		EMemento memento0;
		HFileSystem fileSystem;
		EMementoUtility::Load( fileSystem, "data\\empointer.txt",  memento0 );

		EMementoAssign mementoAssign( memento0 );

		TestClassPointer* pClass0 = HNULL;
		TestClassPointer* pClass1 = HNULL;
		TestClassPointer* pClassDerrived0 = HNULL;
		TestClassPointer* pClassDerrived1 = HNULL;
		TestClassPointer* pClassNULL0 = HNULL;
		TestClassPointer* pClassNULL1 = HNULL;

		mementoAssign.PointerGet( "pClass0", pClass0 );
		mementoAssign.OwnedPointerGet( "pClass1", pClass1 );
		mementoAssign.OwnedPointerGet( "pClassDerrived0", pClassDerrived0 );
		mementoAssign.PointerGet( "pClassDerrived1", pClassDerrived1 );
		mementoAssign.OwnedPointerGet( "pClassNULL0", pClassNULL0 );
		mementoAssign.PointerGet( "pClassNULL1", pClassNULL1 );

		success &= ( HNULL != pClass0 );
		success &= ( pClass1 == pClass0 );
		success &= ( HNULL != pClassDerrived0 );
		success &= ( pClassDerrived1 == pClassDerrived0 );
		if( HNULL != pClassDerrived0 )
		{
			success &= ( 20 == ( ( TestClassPointerDerived* )pClassDerrived0 )->m_other );
			success &= ( 21 == pClassDerrived0->m_value );
		}
		success &= ( HNULL == pClassNULL0 );
		success &= ( HNULL == pClassNULL1 );

	}

	ETESTBED_VALIDATE_STATUS( "MementoPointer", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedMemento()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedMemento" );

	success &= LocalTestbedMemento();
	success &= LocalTestbedMementoAssignCollect();
	success &= LocalTestbedMementoTrait();
	success &= LocalTestbedMementoUtility();
	success &= LocalTestbedMementoPointers();

	return success;
}

/**/