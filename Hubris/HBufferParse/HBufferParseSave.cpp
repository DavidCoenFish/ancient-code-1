//file: Hubris/HBufferParse/HBufferParseSave.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseSave.h"

#include "Hubris/HBufferParse/HBufferParseSaveBin.h"
#include "Hubris/HBufferParse/HBufferParseSaveText.h"
#include "Hubris/HBufferParse/HBufferParseVariant.h"

#include "Hubris/HBuffer/HBufferTrait.h"
#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HSmartPointer/HSmartPointerOperators.h"
#include "Hubris/HTrait/HTraitEmpty.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// creation
/**/
Hubris::HBufferParseSave::HBufferParseSave( const HBOOL in_createBin, const HBOOL in_createText )
: m_pSaveBin( HNULL )
, m_pSaveText( HNULL )
{
	HCOMMON_ASSERT( in_createBin != in_createText, "invalid param" );

	if( HTRUE == in_createBin )
	{
		m_pSaveBin.Create();
	}
	else if( HTRUE == in_createText )
	{
		m_pSaveText.Create();
	}

	return;
}

/**/
Hubris::HBufferParseSave::HBufferParseSave( const HBufferParseSave& in_src ) :
	m_pSaveBin( HNULL ),
	m_pSaveText( HNULL )
{
	( *this ) = in_src;
	return;
}

/**/
Hubris::HBufferParseSave::~HBufferParseSave()
{
	return;
}

///////////////////////////////////////////////////////////
// operator
/**/
const HBufferParseSave& Hubris::HBufferParseSave::operator=( const HBufferParseSave& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		if( HNULL != in_rhs.m_pSaveBin )
		{
			m_pSaveBin.Create();
			( *m_pSaveBin ) = ( *( in_rhs.m_pSaveBin ) );
		}

		if( HNULL != in_rhs.m_pSaveText )
		{
			m_pSaveText.Create();
			( *m_pSaveText ) = ( *( in_rhs.m_pSaveText ) );
		}
	}

	return( *this );
}

/**/
HBOOL Hubris::HBufferParseSave::operator==( const HBufferParseSave& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		if( ( HNULL != m_pSaveBin ) && ( HNULL != in_rhs.m_pSaveBin ) )
		{
			match &= ( ( *m_pSaveBin ) == ( *( in_rhs.m_pSaveBin ) ) );
		}
		else
		{
			match &= ( m_pSaveBin == in_rhs.m_pSaveBin );
		}

		if( ( HNULL != m_pSaveText ) && ( HNULL != in_rhs.m_pSaveText ) )
		{
			match &= ( ( *m_pSaveText ) == ( *( in_rhs.m_pSaveText ) ) );
		}
		else
		{
			match &= ( m_pSaveText == in_rhs.m_pSaveText );
		}
	}

	return match;
}

/**/
HBOOL Hubris::HBufferParseSave::operator!=( const HBufferParseSave& in_rhs )const
{
	return!( operator==( in_rhs ) );
}

///////////////////////////////////////////////////////////
// public methods
/**/
HVOID Hubris::HBufferParseSave::BlockStart( 
	const HString& in_name //name must not have spaces, can be HNULL
	)
{
	if( HNULL != m_pSaveBin )
	{
		m_pSaveBin->BlockStart(
			in_name 
			);
	}
	else if( HNULL != m_pSaveText )
	{
		m_pSaveText->BlockStart(
			in_name
			);
	}
	else
	{
		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
	}

	return;
}

/**/
HVOID Hubris::HBufferParseSave::BlockEnd()
{
	if( HNULL != m_pSaveBin )
	{
		m_pSaveBin->BlockEnd();
	}
	else if( HNULL != m_pSaveText )
	{
		m_pSaveText->BlockEnd();
	}
	else
	{
		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
	}

	return;
}

/**/
HVOID Hubris::HBufferParseSave::ValuePut( 
	const HString& in_name,
	const HBufferParseVariant& in_value 
	)
{
	if( HNULL != m_pSaveBin )
	{
		m_pSaveBin->ValuePut(
			in_name,
			in_value
			);
	}
	else if( HNULL != m_pSaveText )
	{
		m_pSaveText->ValuePut(
			in_name,
			in_value
			);
	}
	else
	{
		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
	}

	return;
}

/**/
HVOID Hubris::HBufferParseSave::CommentPut( 
	const HString& in_comment 
	)
{
	if( HNULL != m_pSaveBin )
	{
		m_pSaveBin->CommentPut(
			in_comment 
			);
	}
	else if( HNULL != m_pSaveText )
	{
		m_pSaveText->CommentPut(
			in_comment
			);
	}
	else
	{
		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
	}

	return;
}

//HVOID Hubris::HBufferParseSave::BlockStart()
//{
//	if( HNULL != m_pSaveBin )
//	{
//		m_pSaveBin->BlockStart();
//	}
//	else if( HNULL != m_pSaveText )
//	{
//		m_pSaveText->BlockStart();
//	}
//	else
//	{
//		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
//	}
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSave::BlockEnd()
//{
//	if( HNULL != m_pSaveBin )
//	{
//		m_pSaveBin->BlockEnd();
//	}
//	else if( HNULL != m_pSaveText )
//	{
//		m_pSaveText->BlockEnd();
//	}
//	else
//	{
//		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
//	}
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSave::TokenPut( const HString& in_token )
//{
//	if( HNULL != m_pSaveBin )
//	{
//		m_pSaveBin->TokenPut( in_token );
//	}
//	else if( HNULL != m_pSaveText )
//	{
//		m_pSaveText->TokenPut( in_token );
//	}
//	else
//	{
//		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
//	}
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSave::ValuePut( const HBufferParseVariant& in_value )
//{
//	if( HNULL != m_pSaveBin )
//	{
//		m_pSaveBin->ValuePut( in_value );
//	}
//	else if( HNULL != m_pSaveText )
//	{
//		m_pSaveText->ValuePut( in_value );
//	}
//	else
//	{
//		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
//	}
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSave::CommentPut( const HString& in_comment )
//{
//	if( HNULL != m_pSaveBin )
//	{
//		m_pSaveBin->CommentPut( in_comment );
//	}
//	else if( HNULL != m_pSaveText )
//	{
//		m_pSaveText->CommentPut( in_comment );
//	}
//	else
//	{
//		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
//	}
//
//	return;
//}
//
///**/
//HVOID Hubris::HBufferParseSave::EndOfLinePut()
//{
//	if( HNULL != m_pSaveBin )
//	{
//		m_pSaveBin->EndOfLinePut();
//	}
//	else if( HNULL != m_pSaveText )
//	{
//		m_pSaveText->EndOfLinePut();
//	}
//	else
//	{
//		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
//	}
//
//	return;
//}

///////////////////////////////////////////////////////////
// accessors
/**/
const HBuffer& Hubris::HBufferParseSave::BufferGet()const
{
	if( HNULL != m_pSaveBin )
	{
		return m_pSaveBin->BufferGet();
	}
	else if( HNULL != m_pSaveText )
	{
		return m_pSaveText->BufferGet();
	}
	else
	{
		HCOMMON_ASSERT_ALWAYS( "invalid parse save invoked" );
	}

	return HTraitEmpty< HBuffer >::EmptyGet();
}

/**/