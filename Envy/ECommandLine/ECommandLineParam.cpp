//file: Envy/ECommandLine/ECommandLineParam.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/ECommandLine/ECommandLineParam.h"

#include< Hubris/HString/HString_Export.h >

/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
// creation
/**/
ECommandLineParam::ECommandLineParam( const ECommandLineParam& in_src )
: m_arrayCommandLineKey()
, m_targetKey()
, m_helpText()
, m_minCount( 0 )
, m_followingKeyCount( 0 )
{
	( *this ) = in_src;
	return;
}

/**/
ECommandLineParam::ECommandLineParam( 
	const TArrayString& in_arrayCommandLineKey,
	const Hubris::HString& in_targetKey,
	const Hubris::HString& in_helpText,
	const Hubris::HSINT in_minCount,
	const Hubris::HSINT in_followingKeyCount
	)
: m_arrayCommandLineKey( in_arrayCommandLineKey )
, m_targetKey( in_targetKey )
, m_helpText( in_helpText )
, m_minCount( in_minCount )
, m_followingKeyCount( in_followingKeyCount )
{
	return;
}

/**/
ECommandLineParam::ECommandLineParam( 
	const Hubris::HString& in_commandLineKey,
	const Hubris::HString& in_targetKey,
	const Hubris::HString& in_helpText,
	const Hubris::HSINT in_minCount,
	const Hubris::HSINT in_followingKeyCount
	)
: m_arrayCommandLineKey()
, m_targetKey( in_targetKey )
, m_helpText( in_helpText )
, m_minCount( in_minCount )
, m_followingKeyCount( in_followingKeyCount )
{
	m_arrayCommandLineKey.Insert( in_commandLineKey );
	return;
}

/**/
ECommandLineParam::ECommandLineParam()
: m_arrayCommandLineKey()
, m_targetKey()
, m_helpText()
, m_minCount( 0 )
, m_followingKeyCount( 0 )
{
	return;
}

/**/
ECommandLineParam::~ECommandLineParam()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const ECommandLineParam& ECommandLineParam::operator=( const ECommandLineParam& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayCommandLineKey = in_rhs.m_arrayCommandLineKey;
		m_targetKey = in_rhs.m_targetKey;
		m_helpText = in_rhs.m_helpText;
		m_minCount = in_rhs.m_minCount;
		m_followingKeyCount = in_rhs.m_followingKeyCount;
	}

	return( *this );
}

/**/
Hubris::HBOOL ECommandLineParam::operator==( const ECommandLineParam& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_arrayCommandLineKey == in_rhs.m_arrayCommandLineKey );
		match &= ( m_targetKey == in_rhs.m_targetKey );
		match &= ( m_helpText == in_rhs.m_helpText );
		match &= ( m_minCount == in_rhs.m_minCount );
		match &= ( m_followingKeyCount == in_rhs.m_followingKeyCount );
	}

	return( match );
}

/**/
Hubris::HBOOL ECommandLineParam::operator!=( const ECommandLineParam& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/