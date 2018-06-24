//file: Hubris/HTestbed/HTestbedString.cpp

#include "Hubris/HTestbed/HTestbedString.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HContainer/HContainerPair.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringTrait.h"
#include "Hubris/HString/HStringUtility.h"
#include "Hubris/HVariables/HVariablesString.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
typedef HContainerPair< HCHAR, HCHAR >TPairCharacterCharacter;
typedef HContainerArray< TPairCharacterCharacter >TArrayPairCharacterCharacter;
typedef HContainerArray< HCHAR >TArrayCharacters;
typedef HContainerArray< HString >TArrayString;
typedef HContainerPair< HCHAR, HString >TPairCharacterString;
typedef HContainerArray< TPairCharacterString >TArrayPairCharacterString;

//////////////////////////////////////////////////////
// local static methods
/**/
static const HBOOL LocalTestbedString()
{
	HBOOL success = HTRUE;

	//HString( const HString& in_src );
	//HString( const HCHAR* const in_src );
	//HString( const HCHAR in_src );
	//HString( const HSINT in_src ); // for NULL construct only, assert on non null
	//HString();
	//~HString();
	{
		HString string0( 'a' );
		HString string1( "foobarish" );
		HString string2( HNULL );
		HString string3( string1 );
		HString string4;
	
		success &= ( "a" == string0 );
		success &= ( "b" != string0 );

		success &= ( "foobarish" == string1 );
		success &= ( string1 == string3 );
		success &= ( string3 == string1 );
		success &= ( "a" != string1 );

		success &= ( string2 == string4 );
		success &= ( string4 == string2 );
		success &= ( string2 != "a" );
	}

	//const HString& operator =( const HString& in_rhs );
	//const HString& operator =( const HCHAR* const in_rhs );
	//const HString& operator =( const HCHAR in_rhs );
	//const HString& operator =( const HSINT in_rhs ); // for NULL assign only, assert on non null
	{
		HString string0 = 'a';
		HString string1 = "foobarish";
		HString string2 = HNULL;
		HString string3 = string1;
		HString string4;

		success &= ( "a" == string0 );
		success &= ( "b" != string0 );

		success &= ( "foobarish" == string1 );
		success &= ( string1 == string3 );
		success &= ( string3 == string1 );
		success &= ( "a" != string1 );

		success &= ( string2 == string4 );
		success &= ( string4 == string2 );
		success &= ( string2 != "a" );
	}

	//const HCHAR operator[]( const HSINT in_index ) const;
	//HCHAR& operator[]( const HSINT in_index );
	{
		HString string0( "foobarish" );
		const HString string1( string0 );

		success &= ( string0[ 0 ] == string1[ 0 ] );
		success &= ( 'f' == string1[ 0 ] );

		success &= ( string0[ 1 ] == string1[ 1 ] );
		success &= ( 'o' == string1[ 1 ] );

		success &= ( string0[ 2 ] == string1[ 2 ] );
		success &= ( 'o' == string1[ 2 ] );

		success &= ( string0[ 3 ] == string1[ 3 ] );
		success &= ( 'b' == string1[ 3 ] );

		success &= ( string0[ 8 ] == string1[ 8 ] );
		success &= ( 'h' == string1[ 8 ] );

		string0[ 8 ] = 'a';
		success &= ( string0[ 8 ] != string1[ 8 ] );
		success &= ( 'a' == string0[ 8 ] );
		success &= ( 'h' == string1[ 8 ] );
	}

	//const HCHAR* const RawGet() const;
	{
		HString string0( "foo" );
		const HCHAR* data0 = string0.RawGet();
		success &= ( 'f' == data0[ 0 ] );
		success &= ( 'o' == data0[ 1 ] );
		success &= ( 'o' == data0[ 2 ] );
		success &= ( HVariablesString::EndOfStringGet() == data0[ 3 ] );
	}

	//HSINT SizeGet() const;
	{
		HString string0( "foo" );
		HString string1;
		success &= ( 3 == string0.SizeGet() );
		success &= ( 0 == string1.SizeGet() );
	}

	//HSINT SizeSet( const HSINT in_size );
	{
		HString string0;
		string0.SizeSet( 4 );
		success &= ( 4 == string0.SizeGet() );
	}

	//HSINT SizeResize( const HSINT in_size );
	{
		HString string0( "foo" );
		string0.SizeResize( 2 );
		success &= ( "fo" == string0 );
	}

	//HBOOL IsEmpty()const{ return( 0 == SizeGet() ); }
	{
		HString string0( "foo" );
		HString string1;
		success &= ( HFALSE == string0.IsEmpty() );
		success &= ( HTRUE == string1.IsEmpty() );

	}
	//void Clear();
	{
		HString string0( "foo" );
		success &= ( HFALSE == string0.IsEmpty() );
		string0.Clear();
		success &= ( HTRUE == string0.IsEmpty() );
	}

	//void DataSet( const HCHAR* const in_data, const HSINT in_size, const HSINT in_offset );
	{
		HString string0;
		string0.SizeSet( 4 );
		string0.DataSet( "ab", 2, 0 );
		string0.DataSet( "cd", 2, 2 );
		success &= ( "abcd" == string0 );
	}

	HTESTBED_VALIDATE_STATUS( "HString", success );

	return success;
}

/**/
static const HBOOL LocalTestbedStringOperators()
{
	HBOOL success = HTRUE;

	//HBOOL operator ==( const HString& in_lhs, const HString& in_rhs );
	//HBOOL operator ==( const HString& in_lhs, const HCHAR* const in_rhs );
	//HBOOL operator ==( const HCHAR* const in_lhs, const HString& in_rhs );
	//HBOOL operator ==( const HString& in_lhs, const HCHAR in_rhs );
	//HBOOL operator ==( const HCHAR in_lhs, const HString& in_rhs );
	//HBOOL operator ==( const HString& in_lhs, const HSINT in_rhs );
	//HBOOL operator ==( const HSINT in_lhs, const HString& in_rhs );
	{
		HString string0( "foo" );
		HString string1( "foo" );
		HString string2( "bar" );
		HString string3( 'a' );
		HString string4;

		success &= ( string0 == string1 );
		success &= ( string1 == string0 );
		success &= !( string0 == string2 );

		success &= ( string0 == "foo" );
		success &= ( "foo" == string0 );
		success &= !( string0 == "bar" );

		success &= ( string3 == 'a' );
		success &= ( 'a' == string3 );
		success &= !( string3 == 'b' );

		success &= ( string4 == HNULL );
		success &= ( HNULL == string4 );
	}

	//HBOOL operator !=( const HString& in_lhs, const HString& in_rhs );
	//HBOOL operator !=( const HString& in_lhs, const HCHAR* const in_rhs );
	//HBOOL operator !=( const HCHAR* const in_lhs, const HString& in_rhs );
	//HBOOL operator !=( const HString& in_lhs, const HCHAR in_rhs );
	//HBOOL operator !=( const HCHAR in_lhs, const HString& in_rhs );
	//HBOOL operator !=( const HString& in_lhs, const HSINT in_rhs );
	//HBOOL operator !=( const HSINT in_lhs, const HString& in_rhs );
	{
		HString string0( "foo" );
		HString string1( "foo" );
		HString string2( "bar" );
		HString string3( 'a' );
		HString string4;

		success &= !( string0 != string1 );
		success &= !( string1 != string0 );
		success &= ( string0 != string2 );

		success &= !( string0 != "foo" );
		success &= !( "foo" != string0 );
		success &= ( string0 != "bar" );

		success &= !( string3 != 'a' );
		success &= !( 'a' != string3 );
		success &= ( string3 != 'b' );

		success &= !( string4 != HNULL );
		success &= !( HNULL != string4 );
	}

	//HString operator +( const HString& in_lhs, const HString& in_rhs );
	//HString operator +( const HString& in_lhs, const HCHAR* const in_rhs );
	//HString operator +( const HCHAR* const in_lhs, const HString& in_rhs );
	//HString operator +( const HString& in_lhs, const HCHAR in_rhs );
	//HString operator +( const HCHAR in_lhs, const HString& in_rhs );
	//HString operator +( const HString& in_lhs, const HSINT in_rhs );
	//HString operator +( const HSINT in_lhs, const HString& in_rhs );
	{
		success &= ( "foobar" == ( HString( "foo" ) + HString( "bar" ) ) );
		success &= ( "foobar" == ( HString( "foo" ) + "bar" ) );
		success &= ( "foobar" == ( "foo" + HString( "bar" ) ) );

		success &= ( "ab" == ( HString( "a" ) + HString( "b" ) ) );
		success &= ( "ab" == ( HString( "a" ) + 'b' ) );
		success &= ( "ab" == ( 'a' + HString( "b" ) ) );

		success &= ( "foobar" == ( HString( "foobar" ) + HNULL ) );
		success &= ( "foobar" == ( HNULL + HString( "foobar" ) ) );

	}

	//HString& operator +=( HString& in_lhs, const HString& in_rhs );
	//HString& operator +=( HString& in_lhs, const HCHAR* const in_rhs );
	//HString& operator +=( HString& in_lhs, const HCHAR in_rhs );
	//HString& operator +=( HString& in_lhs, const HSINT in_rhs );
	{
		HString string0( "foo" );
		HString string1( "foo" );
		HString string2( "foo" );
		HString string3( "foo" );

		string0 += HString( "bar" );
		string1 += "bar";
		string2 += 'b';
		string3 += HNULL;

		success &= ( "foobar" == string0 );
		success &= ( "foobar" == string1 );
		success &= ( "foob" == string2 );
		success &= ( "foo" == string3 );
	}

	//HBOOL operator <( const HString& in_lhs, const HString& in_rhs );
	//HBOOL operator <( const HString& in_lhs, const HCHAR* const in_rhs );
	//HBOOL operator <( const HCHAR* const in_lhs, const HString& in_rhs );
	//HBOOL operator <( const HString& in_lhs, const HCHAR in_rhs );
	//HBOOL operator <( const HCHAR in_lhs, const HString& in_rhs );
	//HBOOL operator <( const HString& in_lhs, const HSINT in_rhs );
	//HBOOL operator <( const HSINT in_lhs, const HString& in_rhs );
	{
		HString string0( "foo" );
		HString string1( "bar" );
		HString string2( 'a' );
		HString string3( 'b' );

		success &= ( string1 < string0 );
		success &= !( string0 < string1 );

		success &= ( "bar" < string0 );
		success &= !( string0 < "bar" );

		success &= ( string1 < "foo" );
		success &= !( "foo" < string1 );

		success &= ( string2 < string3 );
		success &= !( string3 < string2 );

		success &= ( 'a' < string3 );
		success &= !( string3 < 'a' );

		success &= ( string2 < 'b' );
		success &= !( 'b' < string2 );

		success &= ( HNULL < string2 );
		success &= !( string2 < HNULL  );
	}

	HTESTBED_VALIDATE_STATUS( "HStringOperators", success );

	return success;
}

/**/
static const HBOOL LocalTestbedStringTrait()
{
	HBOOL success = HTRUE;

	//name
	{
		success &= ( HString( "HString" ) == HTraitName< HString >::NameGet() );
	}

	//empty
	{
		success &= ( HString() == HTraitEmpty< HString >::EmptyGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HStringTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedStringUtility()
{
	HBOOL success = HTRUE;

	//HStringUtility
	//static HBOOL IsWhiteSpace( const HCHAR in_character );
	{
		success &= ( HStringUtility::IsWhiteSpace( ' ' ) );
		success &= ( HStringUtility::IsWhiteSpace( '\t' ) );
		success &= ( HStringUtility::IsWhiteSpace( '\r' ) );
		success &= ( HStringUtility::IsWhiteSpace( '\n' ) );
	}

	//static HString TrimWhiteSpace( const HString& in_string );
	{
		HString string0 = HStringUtility::TrimWhiteSpace( " \t\nf bar" );
		success &= ( "f bar" == string0 );
	}

	//static HSINT Length( const HCHAR* const in_string );
	{
		success &= ( 4 == HStringUtility::Length( "foob" ) );
	}

	//static HSINT StringCmp( const HCHAR* const in_lhs, const HCHAR* const in_rhs );
	{
		success &= ( 0 == HStringUtility::StringCmp( "foob", "foob" ) );
		success &= !( 0 == HStringUtility::StringCmp( "foob", "foo" ) );
	}

	//static HSINT StringCmpInsensitive( const HCHAR* const in_lhs, const HCHAR* const in_rhs );
	{
		success &= ( 0 == HStringUtility::StringCmpInsensitive( "foob", "foob" ) );
		success &= ( 0 == HStringUtility::StringCmpInsensitive( "FoOb", "fOoB" ) );
		success &= !( 0 == HStringUtility::StringCmpInsensitive( "foOb", "fOo" ) );
	}
	//static HString ToUpper( const HString& in_string );
	{
		success &= ( "FOOB" == HStringUtility::ToUpper( "foob" ) );
		success &= ( "FOOB" == HStringUtility::ToUpper( "FoOb" ) );
		success &= ( "FOOB" == HStringUtility::ToUpper( "FOOB" ) );
	}

	//static HString ToLower( const HString& in_string );
	{
		success &= ( "foob" == HStringUtility::ToLower( "foob" ) );
		success &= ( "foob" == HStringUtility::ToLower( "FoOb" ) );
		success &= ( "foob" == HStringUtility::ToLower( "FOOB" ) );
	}

	//static HString Replace( const HString& in_string, const TArrayPairCharacterCharacter& in_data );
	{
		TArrayPairCharacterCharacter data;
		data.Insert( TPairCharacterCharacter( 'a', '_' ) );
		data.Insert( TPairCharacterCharacter( 'A', '-' ) );

		success &= ( "_S-_" == HStringUtility::Replace( "aSAa", data ) );
	}

	//static HString Replace( const HString& in_string, const HCHAR in_search, const HCHAR in_replace );
	{
		success &= ( "_SA_" == HStringUtility::Replace( "aSAa", 'a', '_' ) );
	}

	//static const HString Replace( const HString& in_string, const HString& in_search, const HString& in_replace );
	{
		success &= ( "HARRO world HARRO" == HStringUtility::Replace( "hello world hello", "hello", "HARRO" ) );
		success &= ( "HARRO world HARRO" == HStringUtility::Replace( HString( "hello world hello" ), HString( "hello" ), HString( "HARRO" ) ) );
	}

	//static HString SubString( const HString& in_string, const HSINT in_start, const HSINT in_length );
	{
		success &= ( "bcd" == HStringUtility::SubString( "abcdefghijk", 1, 3 ) );
	}

	//static HString Remove( const HString& in_string, const TArrayCharacters& in_characters );
	{
		TArrayCharacters data;
		data.Insert( 'a' );
		data.Insert( 'A' );
		success &= ( "SS" == HStringUtility::Remove( "aSAaS", data ) );
	}
	//static HString Remove( const HString& in_string, const HCHAR in_character );
	{
		success &= ( "SA" == HStringUtility::Remove( "aSAa", 'a' ) );
	}
	//static void Split( const HString& in_string, const TArrayCharacters& in_delimiters, TArrayString& out_tokens );
	{
		TArrayCharacters data;
		data.Insert( '.' );
		data.Insert( ' ' );
		TArrayString outArray;
		HStringUtility::Split( "ab.cd . ef gh ", data, outArray );
		success &= ( 4 == outArray.SizeGet() );
		success &= ( "ab" == outArray[ 0 ] );
		success &= ( "cd" == outArray[ 1 ] );
		success &= ( "ef" == outArray[ 2 ] );
		success &= ( "gh" == outArray[ 3 ] );

		HStringUtility::Split( "ab.cd . ef gh", data, outArray );
		success &= ( 4 == outArray.SizeGet() );
		success &= ( "ab" == outArray[ 0 ] );
		success &= ( "cd" == outArray[ 1 ] );
		success &= ( "ef" == outArray[ 2 ] );
		success &= ( "gh" == outArray[ 3 ] );
	}

	//static void Split( const HString& in_string, const HCHAR in_delimiter, TArrayString& out_tokens );
	{
		TArrayString outArray;
		HStringUtility::Split( "ab cd   ef gh", ' ', outArray );
		success &= ( 4 == outArray.SizeGet() );
		success &= ( "ab" == outArray[ 0 ] );
		success &= ( "cd" == outArray[ 1 ] );
		success &= ( "ef" == outArray[ 2 ] );
		success &= ( "gh" == outArray[ 3 ] );
	}

	//static HSINT FindFirst( const HString& in_string, const HString& in_needle );
	{
		success &= ( 4 == HStringUtility::FindFirst( "abcdabcdeabcabcde", "abcde" ) );
	}

	//static HSINT FindFirst( const HString& in_string, const TArrayCharacters& in_characters );
	{
		TArrayCharacters data;
		data.Insert( 'd' );
		data.Insert( 'e' );

		success &= ( 3 == HStringUtility::FindFirst( "abcdabcdeabcabcde", data ) );
	}

	//static HSINT FindFirst( const HString& in_string, const HCHAR in_character );
	{
		success &= ( 8 == HStringUtility::FindFirst( "abcdabcdeabcabcde", 'e' ) );
	}

	//static HSINT FindLast( const HString& in_string, const HString& in_needle );
	{
		success &= ( 12 == HStringUtility::FindLast( "abcdabcdeabcabcde", "abcde" ) );
	}
	//static HSINT FindLast( const HString& in_string, const TArrayCharacters& in_characters );
	{
		TArrayCharacters data;
		data.Insert( 'd' );
		data.Insert( 'e' );

		success &= ( 16 == HStringUtility::FindLast( "abcdabcdeabcabcde", data ) );
	}

	//static HSINT FindLast( const HString& in_string, const HCHAR in_character );
	{
		success &= ( 15 == HStringUtility::FindLast( "abcdabcdeabcabcde", 'd' ) );
	}

	//static HString PadLeft( const HString& in_string, const HSINT in_length, const HCHAR in_character );
	{
		success &= ( " abc" == HStringUtility::PadLeft( "abc", 4, ' ' ) );
	}

	//static HString EscapeString( const HString& in_string, const TArrayPairCharacterString& in_escapeMap );
	//static HString EscapeStringReverse( const HString& in_string, const TArrayPairCharacterString& in_escapeMap );
	//static const TArrayPairCharacterString& DefaultEscapeCharArrayGet();
	{
		const HString string0( "abc def\nghi lmp\n" );
		const HString string1 = HStringUtility::EscapeString( string0, HStringUtility::DefaultEscapeCharArrayGet() );
		const HString string2 = HStringUtility::EscapeStringReverse( string1, HStringUtility::DefaultEscapeCharArrayGet() );

		success &= ( string0 != string1 );
		success &= ( string0 == string2 );
	}

	HTESTBED_VALIDATE_STATUS( "HStringUtility", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedString()
{
	HTESTBED_VALIDATE_START( "TestbedString" );
	HBOOL success = HTRUE;

	success &= LocalTestbedString();
	success &= LocalTestbedStringOperators();
	success &= LocalTestbedStringTrait();
	success &= LocalTestbedStringUtility();

	return success;
}

/**/