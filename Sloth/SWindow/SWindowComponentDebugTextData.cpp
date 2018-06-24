//file: Sloth/SWindow/SWindowComponentDebugTextData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowComponentDebugTextData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowComponentDebugTextData::SWindowComponentDebugTextData( const SWindowComponentDebugTextData& in_src )
: m_text()
, m_location()
, m_foregroundColour()
, m_backgroundColour()
{
	( *this ) = in_src;
	return;
}

/**/
SWindowComponentDebugTextData::SWindowComponentDebugTextData(
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_location,
	const Pride::PColourRgb& in_foregroundColour,
	const Pride::PColourRgb& in_backgroundColour			
	)
: m_text( in_text )
, m_location( in_location )
, m_foregroundColour( in_foregroundColour )
, m_backgroundColour( in_backgroundColour )
{
	return;
}

/**/
SWindowComponentDebugTextData::SWindowComponentDebugTextData()
: m_text()
, m_location()
, m_foregroundColour()
, m_backgroundColour()
{
	return;
}

/**/
SWindowComponentDebugTextData::~SWindowComponentDebugTextData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const SWindowComponentDebugTextData& SWindowComponentDebugTextData::operator=( const SWindowComponentDebugTextData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_text = in_rhs.m_text;
		m_location = in_rhs.m_location;
		m_foregroundColour = in_rhs.m_foregroundColour;
		m_backgroundColour = in_rhs.m_backgroundColour;
	}

	return( *this );
}

/**/
const Hubris::HBOOL SWindowComponentDebugTextData::operator==( const SWindowComponentDebugTextData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_text == in_rhs.m_text );
		match &= ( m_location == in_rhs.m_location );
		match &= ( m_foregroundColour == in_rhs.m_foregroundColour );
		match &= ( m_backgroundColour == in_rhs.m_backgroundColour );
	}

	return match;
}

/**/
const Hubris::HBOOL SWindowComponentDebugTextData::operator!=( const SWindowComponentDebugTextData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
