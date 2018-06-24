//file: Hubris/HTrait/HTraitStringOut.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HTrait/HTraitStringOut.h"

#include "Hubris/HTrait/HTraitEmpty.h"

#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringUtility.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HVariables/HVariablesString.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
typedef HContainerArray< HString >TArrayString;

//////////////////////////////////////////////////////
// local free functions
/**/
static HVOID LocalScanInt( const HString& in_data, HBOOL& out_negative, HU32& out_value )
{
	const HString data( HStringUtility::TrimWhiteSpaceStart( in_data ) );
	out_value = 0;
	out_negative = HFALSE;
	HSINT index = 0;

	//bail on empty data
	if( data.SizeGet() <= 0 )
	{
		return;
	}

	if( HVariablesString::PlusGet() == data[ 0 ] )
	{
		index += 1;
	}

	if( HVariablesString::MinusGet() == data[ 0 ] ) 
	{
		index += 1;
		out_negative = HTRUE;
	}

	//trim white space at start
	//consume minus sign
	for( ; index < data.SizeGet(); ++index )
	{
		const HCHAR character = data[ index ];
		HBOOL found = HFALSE;

		for( HSINT digitIndex = 0; digitIndex < 10; ++digitIndex )
		{
			if( HVariablesString::DigitGet( digitIndex ) == character )
			{
				out_value = (out_value * 10) + digitIndex;
				found = HTRUE;
			}
		}

		//no digit, no white space? bail
		if( HFALSE == found )
		{
			break;
		}
	}

	return;
}

/**/
static HR64 LocalScanPower( const HSINT in_exponenent )
{
	HR64 result = 1.0;

	if( in_exponenent < 0 )
	{
		for( HSINT index = 0; in_exponenent < index; --index )
		{
			result *= 0.1;
		}
	}
	else
	{
		for( HSINT index = 0; index < in_exponenent; ++index )
		{
			result *= 10.0;
		}
	}

	return result;
}

/**/
static HR64 LocalScanReal( const HString& in_data )
{
	const HString data( HStringUtility::TrimWhiteSpaceStart( in_data ) );
	HR64 value = 0.0F;
	HBOOL negative = HFALSE;
	HSINT index = 0;
	HSINT exponent = 0;

	//bail on empty data
	if( data.SizeGet() <= 0 )
	{
		return 0.0;
	}

	if( HVariablesString::PlusGet() == data[ 0 ] )
	{
		index += 1;
	}

	if( HVariablesString::MinusGet() == data[ 0 ] ) 
	{
		index += 1;
		negative = HTRUE;
	}

	HBOOL decimal = HFALSE;
	HR64 mul = 1.0;
	for( ; index < data.SizeGet(); ++index )
	{
		const HCHAR character = data[ index ];

		if( HVariablesString::DecimalGet() == character )
		{
			if( HTRUE == decimal )
			{
				break;
			}
			decimal = HTRUE;
			continue;
		}

		HBOOL found = HFALSE;
		for( HSINT digitIndex = 0; digitIndex < 10; ++digitIndex )
		{
			if( HVariablesString::DigitGet( digitIndex ) != character )
			{
				continue;
			}

			if( HTRUE == decimal )
			{
				mul *= 0.1;
				value += ( static_cast< HREAL >( digitIndex ) * mul );
			}
			else
			{
				value = ( value * 10.0 ) + ( static_cast< HREAL >( digitIndex ) );
			}

			found = HTRUE;
			break;
		}

		//no digit, no white space? bail
		if( HFALSE == found )
		{
			if( ( HVariablesString::LowE() == character ) || ( HVariablesString::HighE() == character ) )
			{
				const HString exponentString = HStringUtility::SubString( data, index + 1, data.SizeGet() - index - 1 );

				HTraitStringOut< HSINT >( exponent, exponentString );
			}

			break;
		}
	}

	//now have value and exponent, combine and return
	if( HTRUE == negative )
	{
		value = -value;
	}

	if( 0 != exponent )
	{
		value *= LocalScanPower( exponent );
	}

	return value;
}

/**/
static HSINT LocalScanHex( const HCHAR in_data, const HSINT in_shift )
{
	for( HSINT index = 0; index < 16; ++index )
	{
		if( ( in_data == HVariablesString::HexGet( index ) ) ||
			( in_data == HVariablesString::HexAltGet( index ) ) )
		{
			return( index << ( 4 * in_shift ) );
		}
	}

	return 0;
}

//////////////////////////////////////////////////////
// public methods
/**/
HVOID Hubris::HTraitStringOut< HU8 >( HU8& out_value, const HString& in_data )
{
	HBOOL negative = false;
	HU32 value = 0;
	LocalScanInt( in_data, negative, value );

	out_value = HU8( value & 0xFF );
	return;
}		

/**/
HVOID Hubris::HTraitStringOut< HS8 >( HS8& out_value, const HString& in_data )
{
	HBOOL negative = false;
	HU32 value = 0;
	LocalScanInt( in_data, negative, value );

	out_value = HS8( value & 0x7F );
	if( HTRUE == negative )
	{
		out_value = -out_value;
	}

	return;
}		

/**/
HVOID Hubris::HTraitStringOut< HU16 >( HU16& out_value, const HString& in_data )
{
	HBOOL negative = false;
	HU32 value = 0;
	LocalScanInt( in_data, negative, value );

	out_value = HU16( value & 0xFFFF );
	return;
}		

/**/
HVOID Hubris::HTraitStringOut< HS16 >( HS16& out_value, const HString& in_data )
{
	HBOOL negative = false;
	HU32 value = 0;
	LocalScanInt( in_data, negative, value );

	out_value = HS16( value & 0x7FFF );
	if( HTRUE == negative )
	{
		out_value = -out_value;
	}

	return;
}		

/**/
HVOID Hubris::HTraitStringOut< HU32 >( HU32& out_value, const HString& in_data )
{
	HBOOL negative = false;
	LocalScanInt( in_data, negative, out_value );

	return;
}		

/**/
HVOID Hubris::HTraitStringOut< HS32 >( HS32& out_value, const HString& in_data )
{
	HBOOL negative = false;
	HU32 value = 0;
	LocalScanInt( in_data, negative, value );

	out_value = HS32( value & 0x7FFFFFFF );
	if( HTRUE == negative )
	{
		out_value = -out_value;
	}

	return;
}		

/**/
HVOID Hubris::HTraitStringOut< HR32 >( HR32& out_value, const HString& in_data )
{
	out_value = HR32( LocalScanReal( in_data ) );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HR64 >( HR64& out_value, const HString& in_data )
{
	out_value = LocalScanReal( in_data );
	return;
}

/**/
HVOID Hubris::HTraitStringOut< HCHAR >( HCHAR& out_value, const HString& in_data )
{
	HBOOL negative = false;
	HU32 value = 0;
	LocalScanInt( in_data, negative, value );

	out_value = HCHAR( value & 0xFF );

	return;
}

/*
	changed to deal with any case true or false, then to try to parse as int
*/
HVOID Hubris::HTraitStringOut< HBOOL >( HBOOL& out_value, const HString& in_data )
{
	HString localString = HStringUtility::TrimWhiteSpace( in_data );
	if( 0 == HStringUtility::StringCmpInsensitive( localString.RawGet(), HVariablesString::TrueGet() ) )
	{
		out_value = HTRUE;
	}
	else if( 0 == HStringUtility::StringCmpInsensitive( localString.RawGet(), HVariablesString::FalseGet() ) )
	{
		out_value = HFALSE;
	}
	else
	{
		HSINT value = 0;
		HTraitStringOut( value, in_data );
		out_value = ( 0 != value );
	}

	return;
}

/**/
HVOID Hubris::HTraitStringOut< HString >( HString& out_value, const HString& in_data )
{
	out_value = HStringUtility::EscapeStringReverse( in_data, HStringUtility::DefaultEscapeCharArrayGet() );
	return;
}

/**/
HVOID Hubris::HTraitStringOutHex< HU8 >( HU8& out_value, const HString& in_data )
{
	out_value = 0;
	for( HSINT index = 0; index < 2; ++index )
	{
		if( in_data.SizeGet() <= index )
		{
			break;
		}
		out_value = ( HU8 )( out_value + LocalScanHex( in_data[ index ], 1 - index ) ) ;
	}
	return;
}

/**/

