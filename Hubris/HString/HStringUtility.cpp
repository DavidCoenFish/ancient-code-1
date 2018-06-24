//file: Hubris/HString/HStringUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HString/HStringUtility.h"

#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonForEach.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HContainer/HContainerLess.h"
#include "Hubris/HContainer/HContainerPair.h"
#include "Hubris/HContainer/HContainerTree.h"
#include "Hubris/HVariables/HVariablesString.h"

#include "Hubris/HTrait/HTrait_Export.h"
#include "Hubris/HMath/HMath_Export.h"

//#include <string.h>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/////////////////////////////////////////////////////////////////
// typedefs
/**/
typedef HContainerTree< HCHAR, HCHAR >TTreeCharChar;
typedef HContainerPair< HCHAR, HCHAR >TPairCharacterCharacter;
typedef HContainerArray< TPairCharacterCharacter >TArrayPairCharacterCharacter;
typedef HContainerArray< HCHAR >TArrayCharacters;
typedef HContainerArray< HString >TArrayString;
typedef HContainerPair< HCHAR, HString >TPairCharacterString;
typedef HContainerArray< TPairCharacterString >TArrayPairCharacterString;

/**/
static const HSINT s_numberStringDefaultLength = 5;

//////////////////////////////////////////////////////
// local free functions
static HVOID LocalReplace( HString& in_out_string, const TTreeCharChar& in_data )
{
	for( HSINT index = 0; index < in_out_string.SizeGet(); ++index )
	{
		const HCHAR value = in_out_string[ index ];
		const TTreeCharChar::TIterator iterator = in_data.Find( value );

		if( iterator != in_data.End() )
		{
			in_out_string[ index ] = ( *iterator );
		}
	}

	return;
}

/**/
static const TTreeCharChar& LocalTreeDigitGet()
{
	static TTreeCharChar s_digit;
	if( 0 == s_digit.SizeGet() )
	{
		for( HSINT index = 0; index < 10; ++index )
		{
			s_digit.Insert( HVariablesString::DigitGet( index ), ( HCHAR )index );
		}
	}

	return s_digit;
}

/**/
static const TTreeCharChar& LocalTreeDigitHexGet()
{
	static TTreeCharChar s_digitHex;
	if( 0 == s_digitHex.SizeGet() )
	{
		for( HSINT index = 0; index < 16; ++index )
		{
			s_digitHex.Insert( HVariablesString::HexGet( index ), ( HCHAR )index );
		}

		s_digitHex.Insert( 'a', ( HCHAR )10 );
		s_digitHex.Insert( 'b', ( HCHAR )11 );
		s_digitHex.Insert( 'c', ( HCHAR )12 );
		s_digitHex.Insert( 'd', ( HCHAR )13 );
		s_digitHex.Insert( 'e', ( HCHAR )14 );
		s_digitHex.Insert( 'f', ( HCHAR )15 );

	}

	return s_digitHex;
}

/**/
static const TTreeCharChar& LocalTreeToUpperGet()
{
	static TTreeCharChar s_upperToLower;
	if( 0 == s_upperToLower.SizeGet() )
	{
		s_upperToLower.Insert( HVariablesString::LowA(), HVariablesString::HighA() );
		s_upperToLower.Insert( HVariablesString::LowB(), HVariablesString::HighB() );
		s_upperToLower.Insert( HVariablesString::LowC(), HVariablesString::HighC() );
		s_upperToLower.Insert( HVariablesString::LowD(), HVariablesString::HighD() );
		s_upperToLower.Insert( HVariablesString::LowE(), HVariablesString::HighE() );
		s_upperToLower.Insert( HVariablesString::LowF(), HVariablesString::HighF() );
		s_upperToLower.Insert( HVariablesString::LowG(), HVariablesString::HighG() );
		s_upperToLower.Insert( HVariablesString::LowH(), HVariablesString::HighH() );
		s_upperToLower.Insert( HVariablesString::LowI(), HVariablesString::HighI() );
		s_upperToLower.Insert( HVariablesString::LowJ(), HVariablesString::HighJ() );
		s_upperToLower.Insert( HVariablesString::LowK(), HVariablesString::HighK() );
		s_upperToLower.Insert( HVariablesString::LowL(), HVariablesString::HighL() );
		s_upperToLower.Insert( HVariablesString::LowM(), HVariablesString::HighM() );
		s_upperToLower.Insert( HVariablesString::LowN(), HVariablesString::HighN() );
		s_upperToLower.Insert( HVariablesString::LowO(), HVariablesString::HighO() );
		s_upperToLower.Insert( HVariablesString::LowP(), HVariablesString::HighP() );
		s_upperToLower.Insert( HVariablesString::LowQ(), HVariablesString::HighQ() );
		s_upperToLower.Insert( HVariablesString::LowR(), HVariablesString::HighR() );
		s_upperToLower.Insert( HVariablesString::LowS(), HVariablesString::HighS() );
		s_upperToLower.Insert( HVariablesString::LowT(), HVariablesString::HighT() );
		s_upperToLower.Insert( HVariablesString::LowU(), HVariablesString::HighU() );
		s_upperToLower.Insert( HVariablesString::LowV(), HVariablesString::HighV() );
		s_upperToLower.Insert( HVariablesString::LowW(), HVariablesString::HighW() );
		s_upperToLower.Insert( HVariablesString::LowX(), HVariablesString::HighX() );
		s_upperToLower.Insert( HVariablesString::LowY(), HVariablesString::HighY() );
		s_upperToLower.Insert( HVariablesString::LowZ(), HVariablesString::HighZ() );
	}

	return s_upperToLower;
}

/**/
static const TTreeCharChar& LocalTreeToLowerGet()
{
	static TTreeCharChar s_lowerToUpper;
	if( 0 == s_lowerToUpper.SizeGet() )
	{
		s_lowerToUpper.Insert( HVariablesString::HighA(), HVariablesString::LowA() );
		s_lowerToUpper.Insert( HVariablesString::HighB(), HVariablesString::LowB() );
		s_lowerToUpper.Insert( HVariablesString::HighC(), HVariablesString::LowC() );
		s_lowerToUpper.Insert( HVariablesString::HighD(), HVariablesString::LowD() );
		s_lowerToUpper.Insert( HVariablesString::HighE(), HVariablesString::LowE() );
		s_lowerToUpper.Insert( HVariablesString::HighF(), HVariablesString::LowF() );
		s_lowerToUpper.Insert( HVariablesString::HighG(), HVariablesString::LowG() );
		s_lowerToUpper.Insert( HVariablesString::HighH(), HVariablesString::LowH() );
		s_lowerToUpper.Insert( HVariablesString::HighI(), HVariablesString::LowI() );
		s_lowerToUpper.Insert( HVariablesString::HighJ(), HVariablesString::LowJ() );
		s_lowerToUpper.Insert( HVariablesString::HighK(), HVariablesString::LowK() );
		s_lowerToUpper.Insert( HVariablesString::HighL(), HVariablesString::LowL() );
		s_lowerToUpper.Insert( HVariablesString::HighM(), HVariablesString::LowM() );
		s_lowerToUpper.Insert( HVariablesString::HighN(), HVariablesString::LowN() );
		s_lowerToUpper.Insert( HVariablesString::HighO(), HVariablesString::LowO() );
		s_lowerToUpper.Insert( HVariablesString::HighP(), HVariablesString::LowP() );
		s_lowerToUpper.Insert( HVariablesString::HighQ(), HVariablesString::LowQ() );
		s_lowerToUpper.Insert( HVariablesString::HighR(), HVariablesString::LowR() );
		s_lowerToUpper.Insert( HVariablesString::HighS(), HVariablesString::LowS() );
		s_lowerToUpper.Insert( HVariablesString::HighT(), HVariablesString::LowT() );
		s_lowerToUpper.Insert( HVariablesString::HighU(), HVariablesString::LowU() );
		s_lowerToUpper.Insert( HVariablesString::HighV(), HVariablesString::LowV() );
		s_lowerToUpper.Insert( HVariablesString::HighW(), HVariablesString::LowW() );
		s_lowerToUpper.Insert( HVariablesString::HighX(), HVariablesString::LowX() );
		s_lowerToUpper.Insert( HVariablesString::HighY(), HVariablesString::LowY() );
		s_lowerToUpper.Insert( HVariablesString::HighZ(), HVariablesString::LowZ() );
	}

	return s_lowerToUpper;
}

/* return HCOMMON_INVALID_INDEX if input is not digit */
static const HSINT LocalIsDigit( const HCHAR in_char )
{
	const TTreeCharChar& treeDigits = LocalTreeDigitGet();
	TTreeCharChar::TIterator iterator = treeDigits.Find( in_char );
	if( iterator != treeDigits.End() )
	{
		return( HSINT )( *iterator ); 
	}

	return HCOMMON_INVALID_INDEX;
}

//////////////////////////////////////////////////////
// public methods
/**/
const HBOOL Hubris::HStringUtility::IsAlpha( const HCHAR in_character )
{
	const TTreeCharChar& alphaLow = LocalTreeToUpperGet();
	if( alphaLow.Find( in_character ) != alphaLow.End() )
	{
		return HTRUE;
	}

	const TTreeCharChar& alphaHight = LocalTreeToLowerGet();
	if( alphaHight.Find( in_character ) != alphaHight.End() )
	{
		return HTRUE;
	}

	return HFALSE;
}

/**/
const HBOOL Hubris::HStringUtility::IsDigit( const HCHAR in_character )
{
	const TTreeCharChar& treeDigits = LocalTreeDigitGet();
	if( treeDigits.Find( in_character ) != treeDigits.End() )
	{
		return HTRUE;
	}

	return HFALSE;
}

const HBOOL Hubris::HStringUtility::IsDigitHex( const HCHAR in_character )
{
	const TTreeCharChar& treeDigits = LocalTreeDigitHexGet();
	if( treeDigits.Find( in_character ) != treeDigits.End() )
	{
		return HTRUE;
	}

	return HFALSE;
}

/**/
const HBOOL Hubris::HStringUtility::IsWhiteSpace( const HCHAR in_character )
{
	return( ( HVariablesString::CarrageReturnGet() == in_character ) || 
			( HVariablesString::NewLineGet() == in_character ) ||
			( HVariablesString::SpaceGet() == in_character ) ||
			( HVariablesString::TabGet() == in_character ) );
}

/**/
const HString Hubris::HStringUtility::TrimWhiteSpace( const HString& in_string )
{
	const HString returnString = TrimWhiteSpaceStart( TrimWhiteSpaceEnd( in_string ) );
	return returnString;
}

/**/
const HString Hubris::HStringUtility::TrimWhiteSpaceStart( const HString& in_string )
{
	for( HSINT index = 0; index < in_string.SizeGet(); ++index )
	{
		if( HTRUE == HStringUtility::IsWhiteSpace( in_string[ index ] ) )
		{
			continue;
		}

		return HStringUtility::SubString( in_string, index, in_string.SizeGet() - index );
	}

	return HString();
}

/**/
const HString Hubris::HStringUtility::TrimWhiteSpaceEnd( const HString& in_string )
{
	for( HSINT index = in_string.SizeGet() - 1; 0 <= index; --index )
	{
		if( HTRUE == HStringUtility::IsWhiteSpace( in_string[ index ] ) )
		{
			continue;
		}

		return HStringUtility::SubString( in_string, 0, index + 1 );
	}

	return HString();
}

/**/
const HSINT Hubris::HStringUtility::Length( const HCHAR* const in_string )
{
	if( HNULL == in_string )
	{
		return 0;
	}

	return static_cast< HSINT >( strlen( in_string ) );
}

/**/
const HSINT Hubris::HStringUtility::StringCmp( const HCHAR* const in_lhs, const HCHAR* const in_rhs )
{
	if( ( HNULL == in_lhs ) && ( HNULL == in_rhs ) )
	{
		return 0;
	}
	else if( HNULL == in_lhs )
	{
		return 1;
	}
	else if( HNULL == in_rhs )
	{
		return -1;
	}

	//order changed so tree is sorted alphabetically
	return strcmp( in_rhs, in_lhs );
}

/**/
const HSINT Hubris::HStringUtility::StringCmpInsensitive( const HCHAR* const in_lhs, const HCHAR* const in_rhs )
{
	if( ( HNULL == in_lhs ) && ( HNULL == in_rhs ) )
	{
		return 0;
	}
	else if( HNULL == in_lhs )
	{
		return -1;
	}
	else if( HNULL == in_rhs )
	{
		return 1;
	}

	HString lhs( HStringUtility::ToLower( in_lhs ) );
	HString rhs( HStringUtility::ToLower( in_rhs ) );

	return HStringUtility::StringCmp( lhs.RawGet(), rhs.RawGet() );
}


/**/
const HString Hubris::HStringUtility::ToUpper( const HString& in_string )
{
	HString returnString( in_string );
	LocalReplace( returnString, LocalTreeToUpperGet() );
	return returnString;
}

/**/
const HString Hubris::HStringUtility::ToLower( const HString& in_string )
{
	HString returnString( in_string );
	LocalReplace( returnString, LocalTreeToLowerGet() );
	return returnString;
}

/**/
const HString Hubris::HStringUtility::Replace( const HString& in_string, const TArrayPairCharacterCharacter& in_arrayData )
{
	TTreeCharChar treeData;

	HCOMMON_FOR_EACH_CONST( data, in_arrayData, TArrayPairCharacterCharacter )
	{
		treeData.Insert( data.m_first, data.m_second );
	}

	HString returnString( in_string );
	LocalReplace( returnString, treeData );
	return returnString;
}

/**/
const HString Hubris::HStringUtility::Replace( const HString& in_string, const HCHAR in_search, const HCHAR in_replace )
{
	TTreeCharChar treeData;
	treeData.Insert( in_search, in_replace );

	HString returnString( in_string );
	LocalReplace( returnString, treeData );
	return returnString;
}

/**/
const HString Hubris::HStringUtility::Replace( const HString& in_string, const HString& in_search, const HString& in_replace )
{
	HSINT index = FindFirst( in_string, in_search );
	const HSINT searchTextLength = in_search.SizeGet();

	if( ( HCOMMON_INVALID_INDEX == index ) ||
		( 0 == searchTextLength ) )
	{
		return in_string;
	}

	HString remaingString( in_string );
	HString result;
	while( HCOMMON_INVALID_INDEX != index )
	{
		result += SubString( remaingString, 0, index );
		result += in_replace;
		remaingString = SubString( remaingString, index + searchTextLength, remaingString.SizeGet() - index - searchTextLength );

		index = FindFirst( remaingString, in_search );
	}

	return result;
}

/**/
const HString Hubris::HStringUtility::SubString( const HString& in_string, const HSINT in_start, const HSINT in_length )
{
	HCOMMON_ASSERT( 0 <= in_start, "invalid param" );

	HString string;
	string.SizeSet( in_length );

	string.DataSet( in_string.RawGet() + in_start, in_length, 0 );

	return string;
}

/**/
const HString Hubris::HStringUtility::Remove( const HString& in_string, const TArrayCharacters& in_characters )
{
	HString string;

	for( HSINT index = 0; index < in_string.SizeGet(); ++index )
	{
		const HCHAR value = in_string[ index ];
		HBOOL found = false;
		HCOMMON_FOR_EACH_CONST( character, in_characters, TArrayCharacters )
		{
			if( value == character )
			{
				found = true;
				break;
			}
		}

		if( HFALSE == found )
		{
			string += value;
		}
	}

	return string;
}

/**/
const HString Hubris::HStringUtility::Remove( const HString& in_string, const HCHAR in_character )
{
	TArrayCharacters characterArray;
	characterArray.Insert( in_character );

	return HStringUtility::Remove( in_string, characterArray );
}

/**/
HVOID Hubris::HStringUtility::Split( const HString& in_string, const TArrayCharacters& in_delimiters, TArrayString& out_tokens )
{
	out_tokens.SizeSet( 0 );

	HString token;
	for( HSINT trace = 0; trace < in_string.SizeGet(); ++trace )
	{
		const HCHAR value = in_string[ trace ];
		HBOOL found = HFALSE;
		HCOMMON_FOR_EACH_CONST( character, in_delimiters, TArrayCharacters )
		{
			if( value == character )
			{
				found = HTRUE;
				break;
			}
		}

		if( HTRUE == found )
		{
			if( 0 != token.SizeGet() )
			{
				out_tokens.Insert( token );
				token.SizeSet( 0 );
			}
		}
		else
		{
			token += value;
		}
	}

	if( 0 != token.SizeGet() )
	{
		out_tokens.Insert( token );
	}

	return;
}

/**/
HVOID Hubris::HStringUtility::Split( const HString& in_string, const HCHAR in_delimiter, TArrayString& out_tokens )
{
	TArrayCharacters characterArray;
	characterArray.Insert( in_delimiter );

	HStringUtility::Split( in_string, characterArray, out_tokens );

	return;
}

/**/
HVOID Hubris::HStringUtility::Split( const HString& in_string, const HString& in_delimiter, TArrayString& out_tokens )
{
	TArrayCharacters characterArray;
	for( HSINT index = 0; index < in_delimiter.SizeGet(); ++index )
	{
		characterArray.Insert( in_delimiter[ index ] );
	}

	HStringUtility::Split( in_string, characterArray, out_tokens );

	return;
}

/**/
const HSINT Hubris::HStringUtility::FindFirst( const HString& in_string, const HString& in_needle )
{
	for( HSINT index = 0; index <= in_string.SizeGet() - in_needle.SizeGet(); ++index )
	{
		HBOOL match = HTRUE;
		for( HSINT needleIndex = 0; needleIndex < in_needle.SizeGet(); ++needleIndex )
		{
			if( in_string[ index + needleIndex ] != in_needle[ needleIndex ] )
			{
				match = HFALSE;
				break;
			}
		}

		if( HTRUE == match )
		{
			return index;
		}
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const HSINT Hubris::HStringUtility::FindFirst( const HString& in_string, const TArrayCharacters& in_characters )
{
	for( HSINT index = 0; index < in_string.SizeGet(); ++index )
	{
		const HCHAR value = in_string[ index ];

		HCOMMON_FOR_EACH_CONST( character, in_characters, TArrayCharacters )
		{
			if( character == value )
			{
				return index;
			}
		}
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const HSINT Hubris::HStringUtility::FindFirst( const HString& in_string, const HCHAR in_character )
{
	TArrayCharacters characterArray;
	characterArray.Insert( in_character );

	return HStringUtility::FindFirst( in_string, characterArray );
}

/**/
const HSINT Hubris::HStringUtility::FindLast( const HString& in_string, const HString& in_needle )
{
	for( HSINT index = in_string.SizeGet() - in_needle.SizeGet(); 0 <= index; --index )
	{
		HBOOL match = HTRUE;
		for( HSINT needleIndex = 0; needleIndex < in_needle.SizeGet(); ++needleIndex )
		{
			if( in_string[ index + needleIndex ] != in_needle[ needleIndex ] )
			{
				match = HFALSE;
				break;
			}
		}

		if( HTRUE == match )
		{
			return index;
		}
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const HSINT Hubris::HStringUtility::FindLast( const HString& in_string, const TArrayCharacters& in_characters )
{
	for( HSINT index = in_string.SizeGet() - 1; 0 <= index; --index )
	{
		const HCHAR value = in_string[ index ];

		HCOMMON_FOR_EACH_CONST( character, in_characters, TArrayCharacters )
		{
			if( character == value )
			{
				return index;
			}
		}
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const HSINT Hubris::HStringUtility::FindLast( const HString& in_string, const HCHAR in_character )
{
	TArrayCharacters characterArray;
	characterArray.Insert( in_character );

	return HStringUtility::FindLast( in_string, characterArray );
}

/**/
const HString Hubris::HStringUtility::PadLeft( const HString& in_string, const HSINT in_length, const HCHAR in_character )
{
	HString returnString;
	for( HSINT index = in_string.SizeGet(); index < in_length; ++index )
	{
		returnString += in_character;
	}
	returnString += in_string;

	return returnString;
}

/**/
const HString Hubris::HStringUtility::EscapeString( const HString& in_string, const TArrayPairCharacterString& in_escapeMap )
{
	HString returnString;

	for( HSINT index = 0; index < in_string.SizeGet(); ++index )
	{
		const HCHAR character = in_string[ index ];
		HBOOL characterAdd = HTRUE;

		HCOMMON_FOR_EACH_CONST( data, in_escapeMap, TArrayPairCharacterString )
		{
			if( character == data.m_first )
			{
				returnString += data.m_second;
				characterAdd = false;
				break;
			}
		}

		if( HTRUE == characterAdd )
		{
			returnString += character;
		}
	}

	return returnString;
}

/**/
const HString Hubris::HStringUtility::EscapeStringReverse( const HString& in_string, const TArrayPairCharacterString& in_escapeMap )
{
	HString returnString;

	const HSINT count = in_string.SizeGet();
	for( HSINT index = 0; index < count; ++index )
	{
		const HCHAR character = in_string[ index ];

		HSINT length = 0;
		if( HTRUE == FindLongestMatchEscape( in_string, index, returnString, length, in_escapeMap ) )
		{
			index += ( length - 1 );
		}
		else
		{
			returnString += character;
		}
	}

	return returnString;
}

/**/
const HBOOL Hubris::HStringUtility::FindLongestMatchEscape( const HString& in_string, const HSINT in_index, HString& in_out_outputString, HSINT& out_length, const TArrayPairCharacterString& in_escapeMap )
{	
	HBOOL found = HFALSE;
	HString foundString;

	HCOMMON_FOR_EACH_CONST( data, in_escapeMap, TArrayPairCharacterString )
	{
		const HSINT length = data.m_second.SizeGet();
		const HString subString = HStringUtility::SubString( in_string, in_index, length );

		if( subString == data.m_second )
		{
			if( out_length < length )
			{
				found = HTRUE;
				out_length = length;
				foundString = data.m_first;
			}
		}
	}

	if( HTRUE == found )
	{
		in_out_outputString += foundString;
	}

	return found;
}

/**/
const TArrayPairCharacterString& Hubris::HStringUtility::DefaultEscapeCharArrayGet()
{
	static TArrayPairCharacterString s_charStringMap;

	if( 0 == s_charStringMap.SizeGet() )
	{
		s_charStringMap.Insert( TPairCharacterString( '\\', "\\\\" ) );
		s_charStringMap.Insert( TPairCharacterString( '\"', "\\\"" ) );
		s_charStringMap.Insert( TPairCharacterString( '\r', "\\r" ) );
		s_charStringMap.Insert( TPairCharacterString( '\n', "\\n" ) );
		s_charStringMap.Insert( TPairCharacterString( '\t', "\\t" ) );
	}

	return s_charStringMap;
}

/**/
HVOID Hubris::HStringUtility::NumberedStringPostSplit( 
	HString& out_baseString, 
	HSINT& out_number,
	const HString& in_numberedString
	)
{
	HString localString( in_numberedString );
	HSINT number = 0;
	HSINT multiply = 1;
	while( 0 < localString.SizeGet() )
	{
		const HSINT result = LocalIsDigit( localString[ localString.SizeGet() - 1 ] );
		if( HCOMMON_INVALID_INDEX == result )
		{
			break;
		}

		number += ( result * multiply );
		multiply *= 10;
		localString.SizeResize( localString.SizeGet() - 1 );
	}

	out_baseString = localString;
	out_number = number;

	return;
}

/**/
const HString Hubris::HStringUtility::NumberedStringPostMerge( 
	const HString& in_baseString, 
	const HSINT in_number
	)
{
	const HString string = in_baseString + PadLeft( HTraitStringIn( in_number ), s_numberStringDefaultLength, HVariablesString::DigitGet( 0 ) );
	return string;
}

/**/
const HString Hubris::HStringUtility::NumberedStringPostIncrement( 
	const HString& in_numberedString
	)
{
	HString baseString;
	HSINT number = 0;

	NumberedStringPostSplit( baseString, number, in_numberedString );

	const HString string = NumberedStringPostMerge( baseString, number + 1 );

	return string;
}

/**/
const HString Hubris::HStringUtility::NumberedStringPostMakeUnique(
	const HString& in_numberedString,
	const TArrayString& in_arrayOtherString
	)
{
	HBOOL duplicateFound = HFALSE;
	HString baseName;
	HSINT baseNumber = 0;
	NumberedStringPostSplit( baseName, baseNumber, in_numberedString );
	HSINT maxNumber = baseNumber;

	HCOMMON_FOR_EACH_CONST( string, in_arrayOtherString, TArrayString )
	{
		HString testBaseName;
		HSINT testBaseNumber = 0;
		NumberedStringPostSplit( testBaseName, testBaseNumber, string );

		if( testBaseName != baseName )
		{
			continue;
		}

		//do we actually have a duplicate
		if( in_numberedString == string )
		{
			duplicateFound = HTRUE;
		}

		maxNumber = HMathUtility::Maximum( maxNumber, testBaseNumber + 1 );
	}

	if( HTRUE == duplicateFound )
	{
		Hubris::HString name = NumberedStringPostMerge( baseName, maxNumber );
		return name;
	}

	return in_numberedString;
}

/**/