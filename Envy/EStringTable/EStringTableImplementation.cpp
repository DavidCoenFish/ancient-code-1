//file: Envy/EStringTable/EStringTableImplementation.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStringTable/EStringTableImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// creation
/**/
EStringTableImplementation::EStringTableImplementation( const EStringTableImplementation& in_src )
: m_arrayString()
, m_treeStringIndex()
{
	( *this ) = in_src;
	return;
}
/**/
EStringTableImplementation::EStringTableImplementation()
: m_arrayString()
, m_treeStringIndex()
{
	return;
}

/**/
EStringTableImplementation::~EStringTableImplementation()
{
	return;
}

/////////////////////////////////////////////////////////////////
// operators
/**/
const EStringTableImplementation& EStringTableImplementation::operator=( const EStringTableImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayString = in_rhs.m_arrayString;
		m_treeStringIndex = in_rhs.m_treeStringIndex;
	}

	return( *this );
}

/**/
const Hubris::HBOOL EStringTableImplementation::operator==( const EStringTableImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayString == in_rhs.m_arrayString );
		match &= ( m_treeStringIndex == in_rhs.m_treeStringIndex );
	}

	return match;
}

/**/
const Hubris::HBOOL EStringTableImplementation::operator!=( const EStringTableImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT EStringTableImplementation::StringAdd( const Hubris::HString& in_string )
{
	HSINT foundIndex = StringFind( in_string );
	if( HCOMMON_INVALID_INDEX != foundIndex )
	{
		return foundIndex;
	}

	foundIndex = HContainerUtility::PushBack( m_arrayString, in_string );
	m_treeStringIndex.Insert( in_string, foundIndex );

	return foundIndex;
}

/**/
Hubris::HVOID EStringTableImplementation::StringIndexAdd( const Hubris::HString& in_string, const Hubris::HSINT in_index )
{
	if( m_arrayString.SizeGet() <= in_index )
	{
		m_arrayString.SizeResize( in_index + 1 );
	}

	HString& string = m_arrayString[ in_index ];
	if( HNULL != string )
	{
		TTreeStringSint::TIterator iterator = m_treeStringIndex.Find( string );
		if( iterator != m_treeStringIndex.End() )
		{
			m_treeStringIndex.Remove( iterator );
		}
	}

	string = in_string;
	m_treeStringIndex.Insert( string, in_index );

	return;
}

/**/
const Hubris::HSINT EStringTableImplementation::StringFind( const Hubris::HString& in_string )const
{
	const TTreeStringSint::TIterator iterator = m_treeStringIndex.Find( in_string );
	if( iterator != m_treeStringIndex.End() )
	{
		return( *iterator );
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const Hubris::HString& EStringTableImplementation::StringGet( const Hubris::HSINT in_index )const
{
	HCOMMON_ASSERT( ( 0 <= in_index ) && ( in_index < m_arrayString.SizeGet() ), "out of bounds param" );
	return m_arrayString[ in_index ];
}

/**/
const Hubris::HSINT EStringTableImplementation::StringCountGet()const
{
	return m_arrayString.SizeGet();
}

/**/
