//file: Envy/ECommandLine/ECommandLineUtility.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/ECommandLine/ECommandLineUtility.h"

#include "Envy/ECommandLine/ECommandLineParam.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HString/HString_Export.h >
#include< Hubris/HTrait/HTrait_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

/**/
using namespace Hubris;
using namespace Envy;

///////////////////////////////////////////////////////
// typedef
/**/
//typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

///////////////////////////////////////////////////////
// static public methods
/*
	todo, use min, followkey sint to improve help text
*/
const Hubris::HString ECommandLineUtility::HelpTextGet(
	const Hubris::HString& in_startHelpText,
	const TArrayParam& in_arrayParam
	)
{
	HString returnString( in_startHelpText + "\n\n" );
	HCOMMON_FOR_EACH_CONST( param, in_arrayParam, TArrayParam )
	{
		const TArrayString& arrayKey = param.ArrayCommandLineKeyGet();
		returnString += "{ ";
		for( HSINT index = 0; index < arrayKey.SizeGet(); ++index )
		{
			returnString += arrayKey[ index ];
			if( index != ( arrayKey.SizeGet() - 1 ) )
			{
				returnString += ", ";
			}
		}
		returnString += " } ";
	}

	returnString += "\n\n";
	HCOMMON_FOR_EACH_CONST( param, in_arrayParam, TArrayParam )
	{
		returnString += ( "  " + param.TargetKeyGet() + " " + param.HelpTextGet() );
	
		if( 0 == param.MinCountGet() )
		{
			returnString += " [optional]";
		}
		if( 0 < param.FollowingKeyCountGet() )
		{
			returnString += ( " [" + HTraitStringIn( param.FollowingKeyCountGet() ) + " following param]" );
		}

		returnString += "\n";
	}

	returnString += "\n";

	return returnString;
}

/**/
const ECommandLineUtility::TArrayString ECommandLineUtility::CommandLineToStringArray(
	const Hubris::HSINT in_argc,
	Hubris::HCHAR ** const in_argv
	)
{
	TArrayString arrayString;
	for( HSINT index = 0; index < in_argc; ++index )
	{
		HContainerUtility::PushBack( arrayString, in_argv[ index ] );
	}

	return arrayString;
}

/**/