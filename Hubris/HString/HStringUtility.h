//file: Hubris/HString/HStringUtility.h
#ifndef _H_STRING_UTILITY_H_
#define _H_STRING_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// pre defines
	/**/
	class HString;
	template< typename IN_TYPE > class HContainerArray;
	template< typename IN_KEY, typename IN_DATA, typename IN_SORT > class HContainerTree;
	template< typename IN_FIRST, typename IN_SECOND > class HContainerPair;
	
	///////////////////////////////////////////////////////////
	// struct
	/**/
	struct HStringUtility
	{
		/////////////////////////////////////////////////////////////////
		// typedefs
	private:
		typedef HContainerPair< HCHAR, HCHAR >TPairCharacterCharacter;
		typedef HContainerArray< TPairCharacterCharacter >TArrayPairCharacterCharacter;
		typedef HContainerArray< HCHAR >TArrayCharacters;
		typedef HContainerArray< HString >TArrayString;
		typedef HContainerPair< HCHAR, HString >TPairCharacterString;
		typedef HContainerArray< TPairCharacterString >TArrayPairCharacterString;

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HStringUtility();

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		static const HBOOL IsAlpha( const HCHAR in_character );
		static const HBOOL IsDigit( const HCHAR in_character );
		static const HBOOL IsDigitHex( const HCHAR in_character );

		//return true if char is white space
		static const HBOOL IsWhiteSpace( const HCHAR in_character );
		//return a new string without whitespace at the start
		static const HString TrimWhiteSpaceStart( const HString& in_string );
		static const HString TrimWhiteSpaceEnd( const HString& in_string );
		static const HString TrimWhiteSpace( const HString& in_string );

		static const HSINT Length( const HCHAR* const in_string );
		static const HSINT StringCmp( const HCHAR* const in_lhs, const HCHAR* const in_rhs );
		//compare string (insensitive to case)
		static const HSINT StringCmpInsensitive( const HCHAR* const in_lhs, const HCHAR* const in_rhs );

		static const HString ToUpper( const HString& in_string );
		static const HString ToLower( const HString& in_string );

		//in_data[].m_first is search, m_second is replace
		static const HString Replace( const HString& in_string, const TArrayPairCharacterCharacter& in_data );
		static const HString Replace( const HString& in_string, const HCHAR in_search, const HCHAR in_replace );
		static const HString Replace( const HString& in_string, const HString& in_search, const HString& in_replace );

		static const HString SubString( const HString& in_string, const HSINT in_start, const HSINT in_length );

		//remove given delimiters from string
		static const HString Remove( const HString& in_string, const TArrayCharacters& in_characters );
		static const HString Remove( const HString& in_string, const HCHAR in_character );

		//spit a string into tokens whenever any delimiter is hit
		static HVOID Split( const HString& in_string, const TArrayCharacters& in_delimiters, TArrayString& out_tokens );
		static HVOID Split( const HString& in_string, const HCHAR in_delimiter, TArrayString& out_tokens );
		static HVOID Split( const HString& in_string, const HString& in_delimiterString, TArrayString& out_tokens );

		//find the first instance in string, else HCOMMON_INVALID_INDEX
		static const HSINT FindFirst( const HString& in_string, const HString& in_needle );
		static const HSINT FindFirst( const HString& in_string, const TArrayCharacters& in_characters );
		static const HSINT FindFirst( const HString& in_string, const HCHAR in_character );
		//find the last instance  in string, else HCOMMON_INVALID_INDEX
		static const HSINT FindLast( const HString& in_string, const HString& in_needle );
		static const HSINT FindLast( const HString& in_string, const TArrayCharacters& in_characters );
		static const HSINT FindLast( const HString& in_string, const HCHAR in_character );

		//pad the left of a string with character to get to length, return string if longer than length
		static const HString PadLeft( const HString& in_string, const HSINT in_length, const HCHAR in_character );

		//escape revers char helper, return true if we reversed an escape sequence
		static const HBOOL FindLongestMatchEscape( const HString& in_string, const HSINT in_index, HString& in_out_outputString, HSINT& out_length, const TArrayPairCharacterString& in_escapeMap );

		//prepend any character in string in the subject list with the escape char. the escape char automatically added to the subjects
		static const HString EscapeString( const HString& in_string, const TArrayPairCharacterString& in_escapeMap );
		//reverse the effects of a escape string operation
		static const HString EscapeStringReverse( const HString& in_string, const TArrayPairCharacterString& in_escapeMap );

		//get a default escape string map, escapes escape char, double quotes, tab and return/ eol
		static const TArrayPairCharacterString& DefaultEscapeCharArrayGet();

		//split a string into string and number from the input strings end (post)
		static HVOID NumberedStringPostSplit( 
			HString& out_baseString, 
			HSINT& out_number,
			const HString& in_numberedString
			);

		//put the number on the end
		static const HString NumberedStringPostMerge( 
			const HString& in_baseString, 
			const HSINT in_number
			);

		//given a name, get the postpended number and increment
		static const HString NumberedStringPostIncrement( 
			const HString& in_numberedString
			);

		//given a name, make it unique agains all other names in the array
		static const HString NumberedStringPostMakeUnique(
			const HString& in_numberedString,
			const TArrayString& in_arrayOtherString
			);

	};

};

#endif // _H_STRING_UTILITY_H_