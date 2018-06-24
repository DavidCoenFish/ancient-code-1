//file: Hubris/HTestbed/HTestbedBufferParse.cpp

#include "Hubris/HTestbed/HTestbedBufferParse.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HBuffer/HBuffer_Export.h"
#include "Hubris/HBufferParse/HBufferParse_Export.h"
#include "Hubris/HCommon/HCommon_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HFileSystem/HFileSystem_Export.h"
#include "Hubris/HMatrix/HMatrix_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HVariables/HVariables_Export.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVectorR3;
typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

//////////////////////////////////////////////////////
// local static variables
/**/
//static const HVectorR3 s_varOne = HMatrixConstructor::HVectorR3Construct( 1.05F, 2.75F, -105.7F );
static const HSINT s_varOne = 103775;
static const HCHAR* const s_varTwo = "some normal characters";
static const HCHAR* const s_varThree = "some less normal characters < > & \"";
static const HCHAR* const s_varFour = "a string with a pre escaped value &#x37;";
static const HCHAR* const s_varFourOut = "a string with a pre escaped value 7";
static const HREAL s_varFive = 7.9F;
//static const HVectorS2 s_varSix = HMatrixConstructor::HVectorS2Construct( 10, -12 );
static const HBOOL s_varSix = HFALSE;
static const HBOOL s_varEight = HTRUE;
static const HCHAR* const s_nameBlockOne = "BLOCK_ONE";
static const HCHAR* const s_nameBlockTwo = "BLOCK_TWO";
static const HCHAR* const s_nameBlockThree = "BLOCK_THREE";
static const HCHAR* const s_nameValueOne = "VALUE_ONE";
static const HCHAR* const s_nameValueTwo = "VALUE_TWO";
static const HCHAR* const s_nameValueThree = "VALUE_THREE";
static const HCHAR* const s_nameValueFour = "VALUE_FOUR";
static const HCHAR* const s_nameValueFive = "VALUE_FIVE";
static const HCHAR* const s_nameValueSix = "VALUE_SIX";
static const HCHAR* const s_nameValueSeven = HNULL;
static const HCHAR* const s_nameValueEight = "VALUE_EIGHT";

static const TArrayVectorR3& LocalArrayVectorR3Get();
static const TArrayString& LocalArrayStringGet();

//////////////////////////////////////////////////////
// local class
/**
static const TArrayString& LocalArrayStringGet()
{
	static TArrayString s_data;
	if( 0 == s_data.SizeGet() )
	{
		s_data.Insert( "abc" );
		s_data.Insert( "e f g" );
		s_data.Insert( "h, \"i, j" );
	}

	return s_data;
}

/**/
class CTestbedBufferPasresVisitor : public HBufferParseLoadVisitorInterface
{
	//////////////////////////////////////////////////////
	// creation
public:
	CTestbedBufferPasresVisitor( HBOOL& in_out_success )
	: m_success( in_out_success )
	, m_trace( 0 )
	{
		return;
	}

	~CTestbedBufferPasresVisitor()
	{
		return;
	}

	//////////////////////////////////////////////////////
	// disabled
private:
	CTestbedBufferPasresVisitor( const CTestbedBufferPasresVisitor& in_src );
	const CTestbedBufferPasresVisitor& operator=( const CTestbedBufferPasresVisitor& in_rhs );


	//////////////////////////////////////////////////////
	// private members
private:
	virtual const HBOOL SkipToEndBlock()
	{
		return HFALSE;
	}
	virtual HVOID FoundBlockStart( const HString& in_blockName, const HSINT HCOMMON_UNUSED_VAR( in_cursor ) )
	{
		switch( m_trace )
		{
		default:
			{
				m_success = HFALSE;
				break;
			}
		case 0:
			{
				m_success &= ( s_nameBlockOne == in_blockName );
				break;
			}
		case 1:
			{
				m_success &= ( s_nameBlockTwo == in_blockName );
				break;
			}
		case 3:
			{
				m_success &= ( s_nameBlockThree == in_blockName );
				break;
			}
		}
		m_trace += 1;
		return;
	}
	virtual HVOID FoundBlockEnd( const HSINT HCOMMON_UNUSED_VAR( in_cursor ) )
	{
		switch( m_trace )
		{
		default:
			{
				m_success = HFALSE;
				break;
			}
		case 2:
		case 8:
		case 13:
			{
				break;
			}
		}
		m_trace += 1;
		return;
	}
	virtual HVOID FoundValue( const HString& in_valueName, const HBufferParseVariant& in_value, const HSINT HCOMMON_UNUSED_VAR( in_cursor ) )
	{
		switch( m_trace )
		{
		default:
			{
				m_success = HFALSE;
				break;
			}
		case 4:
			{
				m_success &= ( s_nameValueOne == in_valueName );
				m_success &= ( HBufferParseVariant( s_varOne ) == in_value );
				break;
			}
		case 5:
			{
				m_success &= ( s_nameValueTwo == in_valueName );
				m_success &= ( HBufferParseVariant( HString( s_varTwo ) ) == in_value );
				break;
			}
		case 6:
			{
				m_success &= ( s_nameValueThree == in_valueName );
				m_success &= ( HBufferParseVariant( HString( s_varThree ) ) == in_value );
				break;
			}
		case 7:
			{
				m_success &= ( s_nameValueFour == in_valueName );
				m_success &= ( ( HBufferParseVariant( HString( s_varFour ) ) == in_value ) ||
					( HBufferParseVariant( HString( s_varFourOut ) ) == in_value ) );
				break;
			}
		case 9:
			{
				m_success &= ( s_nameValueFive == in_valueName );
				m_success &= ( HBufferParseVariant( s_varFive ) == in_value );
				break;
			}
		case 10:
			{
				m_success &= ( s_nameValueSix == in_valueName );
				m_success &= ( HBufferParseVariant( s_varSix ) == in_value );
				break;
			}
		case 11:
			{
				m_success &= ( s_nameValueSeven == in_valueName );
				m_success &= ( HBufferParseVariant( HTRUE ) == in_value );
				break;
			}
		case 12:
			{
				m_success &= ( s_nameValueEight == in_valueName );
				m_success &= ( HBufferParseVariant( s_varEight ) == in_value );
				break;
			}
		}
		m_trace += 1;
		return;
	}
	virtual HVOID FoundComment( const HString& in_comment, const HSINT HCOMMON_UNUSED_VAR( in_cursor ) )
	{
		m_success &= ( "comment one" == in_comment );
		m_success &= ( 4 == m_trace );
		return;
	}
	virtual HVOID ErrorSet( const HString& HCOMMON_UNUSED_VAR( in_errorMessage ), const HSINT HCOMMON_UNUSED_VAR( in_cursor ) )
	{
		m_success = HFALSE;
		return;
	}

	//////////////////////////////////////////////////////
	// private members
private:
	HSINT m_trace;
	HBOOL& m_success;

};

//////////////////////////////////////////////////////
// local static methods
/**
static const TArrayVectorR3& LocalArrayVectorR3Get()
{
	static TArrayVectorR3 s_data;
	if( 0 == s_data.SizeGet() )
	{
		s_data.Insert( HMatrixConstructor::HVectorR3Construct( 1.05F, 2.75F, 10.7F ) );
		s_data.Insert( HMatrixConstructor::HVectorR3Construct( 2.05F, -7.0F, -11.3F ) );
		s_data.Insert( HMatrixConstructor::HVectorR3Construct( 3.05F, 1.3258F, 4.2F ) );
	}

	return s_data;
}

/**/
static HVOID LocalSaveData(
	HBufferParseSave& in_out_parseSave
	)
{
	in_out_parseSave.BlockStart( s_nameBlockOne ); //0
	in_out_parseSave.BlockStart( s_nameBlockTwo ); //1
	in_out_parseSave.BlockEnd(); //2
	in_out_parseSave.BlockStart( s_nameBlockThree ); //3
	in_out_parseSave.CommentPut( "comment one" ); //3a
	in_out_parseSave.ValuePut( s_nameValueOne, s_varOne ); //4
	in_out_parseSave.ValuePut( s_nameValueTwo, HString( s_varTwo ) ); //5
	in_out_parseSave.ValuePut( s_nameValueThree, HString( s_varThree ) ); //6
	in_out_parseSave.ValuePut( s_nameValueFour, HString( s_varFour ) ); //7
	in_out_parseSave.BlockEnd(); //8
	//in_out_parseSave.ValuePut( s_nameValueFive, LocalArrayVectorR3Get() ); //9
	in_out_parseSave.ValuePut( s_nameValueFive, s_varFive ); //9
	in_out_parseSave.ValuePut( s_nameValueSix, s_varSix ); //10
	in_out_parseSave.ValuePut( s_nameValueSeven, HTRUE ); //11
	in_out_parseSave.ValuePut( s_nameValueEight, s_varEight ); //12
	in_out_parseSave.BlockEnd(); //13

	return;
}

/**/
static const HBOOL LocalTestbedBufferParseSaveText()
{
	HBOOL success = HTRUE;

	HBufferParseSave parseSaveText = HBufferParseManager::ParseCreateSaveText();
	
	LocalSaveData( parseSaveText );

	HFileSystem fileSystem;
	fileSystem.FileSave( "data\\parse_text.xml", parseSaveText.BufferGet() );

	HTESTBED_VALIDATE_STATUS( "HBufferParseSaveText", success );
	return success;
}

/**/
static const HBOOL LocalTestbedBufferParseSaveBin()
{
	HBOOL success = HTRUE;

	HBufferParseSave parseSaveBin = HBufferParseManager::ParseCreateSaveBin();
	
	LocalSaveData( parseSaveBin );

	HFileSystem fileSystem;
	fileSystem.FileSave( "data\\parse_text.bin", parseSaveBin.BufferGet() );

	HTESTBED_VALIDATE_STATUS( "HBufferParseSaveBin", success );
	return success;
}

/**/
static const HBOOL LocalTestbedBufferParseLoadText()
{
	HBOOL success = HTRUE;

	HFileSystem fileSystem;
	HBufferParseLoad parseLoadText = HBufferParseManager::ParseCreateLoad();
	fileSystem.FileLoad( "data\\parse_text.xml", parseLoadText.BufferGet() );

	CTestbedBufferPasresVisitor visitor( success );
	parseLoadText.SubmitVisitor( visitor );

	HTESTBED_VALIDATE_STATUS( "HBufferParseLoadText", success );

	return success;
}

/**/
static const HBOOL LocalTestbedBufferParseLoadBin()
{
	HBOOL success = HTRUE;

	HFileSystem fileSystem;
	HBufferParseLoad parseLoadText = HBufferParseManager::ParseCreateLoad();
	fileSystem.FileLoad( "data\\parse_text.bin", parseLoadText.BufferGet() );

	CTestbedBufferPasresVisitor visitor( success );
	parseLoadText.SubmitVisitor( visitor );

	HTESTBED_VALIDATE_STATUS( "HBufferParseLoadBin", success );
	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedBufferParse()
{
	HTESTBED_VALIDATE_START( "TestbedBufferParse" );
	HBOOL success = HTRUE;

	success &= LocalTestbedBufferParseSaveText();
	success &= LocalTestbedBufferParseSaveBin();
	success &= LocalTestbedBufferParseLoadText();
	success &= LocalTestbedBufferParseLoadBin();

	return success;
}

/**/