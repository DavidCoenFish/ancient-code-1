//file: Hubris/HBufferParse/HBufferParseLoad.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseLoad.h"

#include "Hubris/HBufferParse/HBufferParseUtilityPrivate.h"
#include "Hubris/HBufferParse/HBufferParseLoadBin.h"
#include "Hubris/HBufferParse/HBufferParseLoadText.h"
#include "Hubris/HBufferParse/HBufferParseLoadVisitorInterface.h"

#include "Hubris/HBuffer/HBufferOperators.h"
#include "Hubris/HSmartPointer/HSmartPointer.h"
#include "Hubris/HString/HString.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// typedef
typedef HSmartPointer< HBufferParseLoadBin >TLoadBinPointer;
typedef HSmartPointer< HBufferParseLoadText >TLoadTextPointer;


///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HBufferParseLoad::HBufferParseLoad( const HBufferParseLoad& in_src )
: m_buffer()
{
	( *this ) = in_src;
}

/**/
Hubris::HBufferParseLoad::HBufferParseLoad()
: m_buffer()
{
	return;
}

/**/
Hubris::HBufferParseLoad::~HBufferParseLoad()
{
	return;
}

///////////////////////////////////////////////////////////
// operator
/**/
const HBufferParseLoad& Hubris::HBufferParseLoad::operator=( const HBufferParseLoad& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_buffer = in_rhs.m_buffer;
	}

	return( *this );
}

/**/
HBOOL Hubris::HBufferParseLoad::operator==( const HBufferParseLoad& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_buffer == in_rhs.m_buffer );
	}

	return match;
}

/**/
HBOOL Hubris::HBufferParseLoad::operator!=( const HBufferParseLoad& in_rhs )const
{
	return!( operator==( in_rhs ) );
}

///////////////////////////////////////////////////////////
// public methods
HBOOL Hubris::HBufferParseLoad::ValidTest()const
{
	HSINT offset = 0;
	if( HTRUE == HBufferParseUtilityPrivate::IsBinGet( m_buffer, offset ) )
	{
		return HTRUE;
	}
	else if( HTRUE == HBufferParseUtilityPrivate::IsTextGet( m_buffer, offset ) )
	{
		return HTRUE;
	}

	return HFALSE;
}

/**/
HVOID Hubris::HBufferParseLoad::SubmitVisitor( HBufferParseLoadVisitorInterface& out_visitor)const
{
	HSINT offset = 0;
	if( HTRUE == HBufferParseUtilityPrivate::IsBinGet( m_buffer, offset ) )
	{
		HBufferParseLoadBin loadBin( m_buffer, offset );
		loadBin.SubmitVisitor( out_visitor );
	}
	else if( HTRUE == HBufferParseUtilityPrivate::IsTextGet( m_buffer, offset ) )
	{
		HBufferParseLoadText loadText( m_buffer, offset );
		loadText.SubmitVisitor( out_visitor );
	}
	else
	{
		out_visitor.ErrorSet( "buffer not of recognised type", HCOMMON_INVALID_INDEX );
	}

	return;
}

/**/