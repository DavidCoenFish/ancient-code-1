//file: Envy/ECommandLine/ECommandLine.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/ECommandLine/ECommandLine.h"

#include "Envy/ECommandLine/ECommandLineParam.h"

#include< Hubris/HString/HString_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

///////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
typedef Hubris::HContainerArray< ECommandLineParam >TArrayParam;
typedef Hubris::HContainerTree< Hubris::HString, TArrayString >TTreeStingArrayString;

///////////////////////////////////////////////////////
// static local methods
/**/
static const HBOOL LocalMatchCommandLine(
	const HString& in_commandLine,
	const TArrayString& in_arrayString,
	const HBOOL in_caseInsensitive
	)
{
	HCOMMON_FOR_EACH_CONST( string, in_arrayString, TArrayString )
	{
		if( HTRUE == in_caseInsensitive )
		{
			if( 0 == HStringUtility::StringCmpInsensitive( string.RawGet(), in_commandLine.RawGet() ) )
			{
				return HTRUE;
			}
		}
		else
		{
			if( string == in_commandLine )
			{
				return HTRUE;
			}
		}
	}
	return HFALSE;
}

/**/
static HVOID LocalParaceCommandLine(
	TTreeStingArrayString& out_treeData,
	HSINT& in_out_index,
	const HString& in_commandLine,
	const TArrayParam& in_arrayParam,
	const TArrayString& in_arrayCommandLine,
	const HBOOL in_caseInsensitive
	)
{
	HBOOL match = HFALSE;
	HSINT followingKeyCount = 0;
	HString key;
	HCOMMON_FOR_EACH_CONST( param, in_arrayParam, TArrayParam )
	{
		if( HTRUE == LocalMatchCommandLine(
			in_commandLine,
			param.ArrayCommandLineKeyGet(),
			in_caseInsensitive
			) )
		{
			match = HTRUE;
			key = param.TargetKeyGet();
			followingKeyCount = param.FollowingKeyCountGet();
			break;
		}
	}

	if( HFALSE == match )
	{
		return;
	}
	
	TArrayString arrayString;
	for( HSINT index = 0; index < followingKeyCount; ++index )
	{
		if( in_arrayCommandLine.SizeGet() <= in_out_index + 1 )
		{
			break;
		}
		in_out_index += 1;
		arrayString.Insert( in_arrayCommandLine[ in_out_index ] );
	}

	TTreeStingArrayString::TIterator iterator = out_treeData.Find( key );
	if( iterator == out_treeData.End() )
	{
		//append create key
		out_treeData.Insert( key, arrayString );
	}
	else
	{
		//append exsisting string
		HCOMMON_FOR_EACH_CONST( string, arrayString, TArrayString )
		{
			( *iterator ).Insert( string );
		}
	}

	return;
}

/**/
static const HBOOL LocalDataCheck( 
	const TTreeStingArrayString& in_treeData,
	const TArrayParam& in_arrayParam
	)
{
	if( 0 == in_treeData.SizeGet() )
	{
		//must have at least one key to be valid?
		return HFALSE;
	}

	HBOOL valid = HTRUE;
	HCOMMON_FOR_EACH_CONST( param, in_arrayParam, TArrayParam )
	{
		if( param.MinCountGet() <= 0 )
		{
			continue;
		}
		//if more than min of 0, then key must be found to be valid
		valid &= ( in_treeData.Find( param.TargetKeyGet() ) != in_treeData.End() );
	}

	return valid;
}

///////////////////////////////////////////////////////
// creation
/**/
ECommandLine::ECommandLine( 
	const Hubris::HBOOL in_keyCaseInsensitive,
	const TArrayParam& in_arrayParam,
	const TArrayString& in_arrayCommandLine
	)
: m_valid( HFALSE )
, m_treeData()
{
	for( HSINT index = 0; index < in_arrayCommandLine.SizeGet(); ++index )
	{
		const HString& commandLine = in_arrayCommandLine[ index ];

		LocalParaceCommandLine(
			m_treeData,
			index,
			commandLine,
			in_arrayParam,
			in_arrayCommandLine,
			in_keyCaseInsensitive
			);
	}

	m_valid = LocalDataCheck( 
		m_treeData,
		in_arrayParam
		);

	return;
}

/**/
ECommandLine::~ECommandLine()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL ECommandLine::KeyTest( const Hubris::HString& in_key )const
{
	const TTreeStingArrayString::TIterator iterator = m_treeData.Find( in_key );
	const HBOOL found = ( iterator != m_treeData.End() );
	return found;
}

/**/
const TArrayString& ECommandLine::KeyGet( const Hubris::HString& in_key )const
{
	const TTreeStingArrayString::TIterator iterator = m_treeData.Find( in_key );
	HCOMMON_ASSERT( iterator != m_treeData.End(), "invalid data access, use KeyTest()" );
	return( *iterator );
}

/**/

