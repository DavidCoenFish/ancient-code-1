//file: Hubris/HVariables/HVariablesString.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HVariables/HVariablesString.h"

#include "Hubris/HCommon/HCommonAssert.h"

//#include <string.h>

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// static local var
/**/
static const HCHAR s_variablesStringDigit[] = 
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9'
};

static const HCHAR s_variablesStringHex[] = 
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F'
};

static const HCHAR s_variablesStringHexAlt[] = 
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'a',
	'b',
	'c',
	'd',
	'e',
	'f'
};

static const HCHAR* const s_variablesStringTrue = "TRUE";
static const HCHAR* const s_variablesStringFalse = "FALSE";

/////////////////////////////////////////////////////////////////
// static public methods
/**/
const HCHAR Hubris::HVariablesString::ArrayStartGet()
{
	return( '[' );
}
const HCHAR Hubris::HVariablesString::ArrayEndGet()
{
	return( ']' );
}

const HCHAR Hubris::HVariablesString::BlockStartGet()
{
	return( '{' );
}
const HCHAR Hubris::HVariablesString::BlockEndGet()
{
	return( '}' );
}
const HCHAR Hubris::HVariablesString::EndOfStringGet()
{
	return( 0 );
}
const HCHAR Hubris::HVariablesString::CarrageReturnGet()
{
	return( '\r' );
}
const HCHAR Hubris::HVariablesString::NewLineGet()
{
	return( '\n' );
}
const HCHAR Hubris::HVariablesString::TabGet()
{
	return( '\t' );
}
const HCHAR Hubris::HVariablesString::SpaceGet()
{
	return( ' ' );
}
const HCHAR Hubris::HVariablesString::QuoteGet()
{
	return( '\"' );
}
const HCHAR Hubris::HVariablesString::CommaGet()
{
	return( ',' );
}
const HCHAR Hubris::HVariablesString::PercentageGet()
{
	return( '%' );
}
const HCHAR Hubris::HVariablesString::EqualGet()
{
	return( '=' );
}
const HCHAR Hubris::HVariablesString::PlusGet()
{
	return( '+' );
}
const HCHAR Hubris::HVariablesString::MinusGet()
{
	return( '-' );
}
const HCHAR Hubris::HVariablesString::DecimalGet()
{
	return( '.' );
}
const HCHAR Hubris::HVariablesString::ExponentGet()
{
	return( 'E' );
}
const HCHAR Hubris::HVariablesString::SemiColonGet()
{
	return( ';' );
}
const HCHAR Hubris::HVariablesString::ColonGet()
{
	return( ':' );
}
const HCHAR Hubris::HVariablesString::SlashGet()
{
	return( '/' );
}
const HCHAR Hubris::HVariablesString::BackSlashGet()
{
	return( '\\' );
}
const HCHAR Hubris::HVariablesString::NumberSign()
{
	return( '#' );
}
const HCHAR Hubris::HVariablesString::QuestionMark()
{
	return( '?' );
}

const HCHAR Hubris::HVariablesString::LowA()
{
	return( 'a' );
}
const HCHAR Hubris::HVariablesString::LowB()
{
	return( 'b' );
}
const HCHAR Hubris::HVariablesString::LowC()
{
	return( 'c' );
}
const HCHAR Hubris::HVariablesString::LowD()
{
	return( 'd' );
}
const HCHAR Hubris::HVariablesString::LowE()
{
	return( 'e' );
}
const HCHAR Hubris::HVariablesString::LowF()
{
	return( 'f' );
}
const HCHAR Hubris::HVariablesString::LowG()
{
	return( 'g' );
}
const HCHAR Hubris::HVariablesString::LowH()
{
	return( 'h' );
}
const HCHAR Hubris::HVariablesString::LowI()
{
	return( 'i' );
}
const HCHAR Hubris::HVariablesString::LowJ()
{
	return( 'j' );
}
const HCHAR Hubris::HVariablesString::LowK()
{
	return( 'k' );
}
const HCHAR Hubris::HVariablesString::LowL()
{
	return( 'l' );
}
const HCHAR Hubris::HVariablesString::LowM()
{
	return( 'm' );
}
const HCHAR Hubris::HVariablesString::LowN()
{
	return( 'n' );
}
const HCHAR Hubris::HVariablesString::LowO()
{
	return( 'o' );
}
const HCHAR Hubris::HVariablesString::LowP()
{
	return( 'p' );
}
const HCHAR Hubris::HVariablesString::LowQ()
{
	return( 'q' );
}
const HCHAR Hubris::HVariablesString::LowR()
{
	return( 'r' );
}
const HCHAR Hubris::HVariablesString::LowS()
{
	return( 's' );
}
const HCHAR Hubris::HVariablesString::LowT()
{
	return( 't' );
}
const HCHAR Hubris::HVariablesString::LowU()
{
	return( 'u' );
}
const HCHAR Hubris::HVariablesString::LowV()
{
	return( 'v' );
}
const HCHAR Hubris::HVariablesString::LowW()
{
	return( 'w' );
}
const HCHAR Hubris::HVariablesString::LowX()
{
	return( 'x' );
}
const HCHAR Hubris::HVariablesString::LowY()
{
	return( 'y' );
}
const HCHAR Hubris::HVariablesString::LowZ()
{
	return( 'z' );
}

const HCHAR Hubris::HVariablesString::HighA()
{
	return( 'A' );
}
const HCHAR Hubris::HVariablesString::HighB()
{
	return( 'B' );
}
const HCHAR Hubris::HVariablesString::HighC()
{
	return( 'C' );
}
const HCHAR Hubris::HVariablesString::HighD()
{
	return( 'D' );
}
const HCHAR Hubris::HVariablesString::HighE()
{
	return( 'E' );
}
const HCHAR Hubris::HVariablesString::HighF()
{
	return( 'F' );
}
const HCHAR Hubris::HVariablesString::HighG()
{
	return( 'G' );
}
const HCHAR Hubris::HVariablesString::HighH()
{
	return( 'H' );
}
const HCHAR Hubris::HVariablesString::HighI()
{
	return( 'I' );
}
const HCHAR Hubris::HVariablesString::HighJ()
{
	return( 'J' );
}
const HCHAR Hubris::HVariablesString::HighK()
{
	return( 'K' );
}
const HCHAR Hubris::HVariablesString::HighL()
{
	return( 'L' );
}
const HCHAR Hubris::HVariablesString::HighM()
{
	return( 'M' );
}
const HCHAR Hubris::HVariablesString::HighN()
{
	return( 'N' );
}
const HCHAR Hubris::HVariablesString::HighO()
{
	return( 'O' );
}
const HCHAR Hubris::HVariablesString::HighP()
{
	return( 'P' );
}
const HCHAR Hubris::HVariablesString::HighQ()
{
	return( 'Q' );
}
const HCHAR Hubris::HVariablesString::HighR()
{
	return( 'R' );
}
const HCHAR Hubris::HVariablesString::HighS()
{
	return( 'S' );
}
const HCHAR Hubris::HVariablesString::HighT()
{
	return( 'T' );
}
const HCHAR Hubris::HVariablesString::HighU()
{
	return( 'U' );
}
const HCHAR Hubris::HVariablesString::HighV()
{
	return( 'V' );
}
const HCHAR Hubris::HVariablesString::HighW()
{
	return( 'W' );
}
const HCHAR Hubris::HVariablesString::HighX()
{
	return( 'X' );
}
const HCHAR Hubris::HVariablesString::HighY()
{
	return( 'Y' );
}
const HCHAR Hubris::HVariablesString::HighZ()
{
	return( 'Z' );
}

const HCHAR Hubris::HVariablesString::DigitGet( const HSINT in_index )
{
	HCOMMON_ASSERT( ( 0 <= in_index ) && ( in_index < HCOMMON_ARRAY_SIZE( s_variablesStringDigit ) ), "invalid param" );
	return s_variablesStringDigit[ in_index ];
}
const HCHAR Hubris::HVariablesString::HexGet( const HSINT in_index )
{
	HCOMMON_ASSERT( ( 0 <= in_index ) && ( in_index < HCOMMON_ARRAY_SIZE( s_variablesStringHex ) ), "invalid param" );
	return s_variablesStringHex[ in_index ];
}
const HCHAR Hubris::HVariablesString::HexAltGet( const HSINT in_index )
{
	HCOMMON_ASSERT( ( 0 <= in_index ) && ( in_index < HCOMMON_ARRAY_SIZE( s_variablesStringHexAlt ) ), "invalid param" );
	return s_variablesStringHexAlt[ in_index ];
}

const HCHAR* const Hubris::HVariablesString::TrueGet()
{
	return s_variablesStringTrue;
}
const HCHAR* const Hubris::HVariablesString::FalseGet()
{
	return s_variablesStringFalse;
}

/**/