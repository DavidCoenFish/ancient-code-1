//file: Envy/ETestbed/ETestbedStringTable.cpp

#include "Envy/ETestbed/ETestbedStringTable.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Envy;
using namespace Hubris;

//////////////////////////////////////////////////
// local free functions
/**/
static const Hubris::HBOOL LocalTestbedStringTable()
{
	HBOOL success = HTRUE;

	{
		EStringTable stringTable0;
		stringTable0.StringAdd( "foo" );
		stringTable0.StringAdd( "bar" );
		const EStringTable stringTable1( stringTable0 );
		const EStringTable stringTable2 = stringTable0;
		const EStringTable stringTable3;

		success &= ( stringTable0 == stringTable1 );
		success &= ( stringTable1 == stringTable0 );

		success &= ( stringTable0 == stringTable2 );
		success &= ( stringTable2 == stringTable0 );

		success &= ( stringTable0 != stringTable3 );
		success &= ( stringTable3 != stringTable0 );
	}

	{
		const HCHAR* const string0 = "foo";
		const HCHAR* const string1 = "bar";
		const HCHAR* const string2 = "moo";

		EStringTable stringTable0;
		const HSINT index0 = stringTable0.StringAdd( string0 );
		const HSINT index1 = stringTable0.StringAdd( string1 );
		const HSINT index2 = stringTable0.StringAdd( string2 );

		success &= ( 3 == stringTable0.StringCountGet() );
		success &= ( index0 == stringTable0.StringFind( string0 ) );
		success &= ( index1 == stringTable0.StringFind( string1 ) );
		success &= ( index2 == stringTable0.StringFind( string2 ) );

		success &= ( string0 == stringTable0.StringGet( index0 ) );
		success &= ( string1 == stringTable0.StringGet( index1 ) );
		success &= ( string2 == stringTable0.StringGet( index2 ) );

		success &= ( index0 == stringTable0.StringAdd( string0 ) );
	}

	ETESTBED_VALIDATE_STATUS( "EStringTable", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedStringTable()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedStringTable" );

	success &= LocalTestbedStringTable();

	return success;
}

/**/