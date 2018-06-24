//file: Envy/ETestbed/ETestbedCommandLine.cpp

#include "Envy/ETestbed/ETestbedCommandLine.h"

using namespace Envy;
using namespace Hubris;

///////////////////////////////////////////////////////
// typedef
typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
typedef Hubris::HContainerArray< ECommandLineParam >TArrayParam;

//////////////////////////////////////////////////
// local free functions
//ECommandLineParam
/**/
static const Hubris::HBOOL LocalCommandLineParam()
{
	HBOOL success = HTRUE;

	{
		const ECommandLineParam param0( "key0", "target_key0", "help for key 0", 0, 1 );
		const ECommandLineParam param1( param0 );
		const ECommandLineParam param2 = param0;
		const ECommandLineParam param3;

		success &= ( param0 == param1 );
		success &= ( param1 == param0 );

		success &= ( param0 == param2 );
		success &= ( param2 == param0 );

		success &= !( param0 != param2 );
		success &= !( param2 != param0 );

		success &= !( param0 == param3 );
		success &= !( param3 == param0 );

		success &= ( param0 != param3 );
		success &= ( param3 != param0 );

		TArrayString arrayKey;
		arrayKey.Insert( "key0" );
		success &= ( arrayKey == param0.ArrayCommandLineKeyGet() );
		success &= ( "help for key 0" == param0.HelpTextGet() );
		success &= ( "target_key0" == param0.TargetKeyGet() );
		success &= ( 0 == param0.MinCountGet() );
		success &= ( 1 == param0.FollowingKeyCountGet() );
	}

	ETESTBED_VALIDATE_STATUS( "CommandLine", success );

	return success; 
}

/**/
static const Hubris::HBOOL LocalCommandLine()
{
	HBOOL success = HTRUE;

	TArrayParam arrayParam;
	arrayParam.Insert( ECommandLineParam( "key0", "key0_0param", "help for key 0", 0, 0 ) );
	arrayParam.Insert( ECommandLineParam( "key1", "key1_1param", "help for key 1", 1, 1 ) );
	arrayParam.Insert( ECommandLineParam( "key2", "key2_1param_optional", "help for key 2", 0, 1 ) );
	TArrayString arrayCommandLine;
	arrayCommandLine.Insert( "some_command_name.exe" );
	arrayCommandLine.Insert( "key0" );
	arrayCommandLine.Insert( "key1" );
	arrayCommandLine.Insert( "key1_data" );

	ECommandLine commandLine( 
		HTRUE,
		arrayParam,
		arrayCommandLine
		);

	success &= ( HTRUE == commandLine.ValidGet() );
	success &= ( HTRUE == commandLine.KeyTest( "key0_0param" ) );
	success &= ( HTRUE == commandLine.KeyTest( "key1_1param" ) );
	success &= ( HFALSE == commandLine.KeyTest( "key2_1param_optional" ) );

	if( HTRUE == success )
	{
		success &= ( 0 == commandLine.KeyGet( "key0_0param" ).SizeGet() );
		success &= ( 1 == commandLine.KeyGet( "key1_1param" ).SizeGet() );
	}

	const HString helpText = ECommandLineUtility::HelpTextGet( arrayParam );

	printf( "%s\n", helpText.RawGet() );

	ETESTBED_VALIDATE_STATUS( "CommandLine", success );

	return success; 
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedCommandLine()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedCommandLine" );

	success &= LocalCommandLineParam();
	success &= LocalCommandLine();

	return success;
}

/**/