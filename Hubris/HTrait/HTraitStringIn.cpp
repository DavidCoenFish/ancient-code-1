//file: Hubris/HTrait/HTraitStringIn.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HTrait/HTraitStringIn.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringUtility.h"
#include "Hubris/HVariables/HVariablesString.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local free functions
/**/
static HString LocalPrintInt( const HBOOL in_negative, const HU32 in_data, const HU32 in_highest )
{
	//special case zero
	if( 0 == in_data )
	{
		return HVariablesString::DigitGet( 0 );
	}

	HString string;
	if( HTRUE == in_negative )
	{
		string = HVariablesString::MinusGet();
	}

	HBOOL printing = HFALSE;
	HU32 highest( in_highest );
	HU32 localData( in_data );
	while( 0 != highest )
	{
		const HSINT digit = localData / highest;
		if( ( 0 != digit ) && ( HFALSE == printing ) )
		{
			printing = HTRUE;
		}

		if( HTRUE == printing )
		{
			string += HVariablesString::DigitGet( digit );
			localData -= ( digit * highest );
		}

		highest /= 10;
	}

	return string;
}

/**/
static HSINT LocalPrintLog( const HR64 in_value )
{ 
	HSINT exponent = 0;
	HR64 testValue = 1.0;

	if( in_value < 1.0 )
	{
		while( in_value <= testValue) 
		{
			testValue *= 0.1; 
			exponent -= 1;
		}
	}
	else
	{
		while( testValue <= in_value ) 
		{
			testValue *= 10.0; 
			exponent += 1;
		}

		exponent -= 1;
	}

	return exponent;
}

/**/
static HR64 LocalPrintPower( const HSINT in_exponenent )
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
static HString LocalPrintRealFraction( const HR64 in_data, const HSINT in_presision )
{
	HString string;
	HR64 localData( in_data );

	for( HSINT index = 0; index < in_presision; ++index )
	{
		localData *= 10.0;
		const HU32 number = HU32( localData ) % 10;
		localData -= HR64( number );

		string += HVariablesString::DigitGet( number );
	}

	//trim zeros
	HSINT last = in_presision;
	for( HSINT index = in_presision - 1; 0 < index; --index )
	{
		if( HVariablesString::DigitGet( 0 ) == string[ index ] )
		{
			last = index;
		}
		else
		{
			break;
		}
	}

	if( last != in_presision )
	{
		string.SizeResize( last );
	}

	return string;
}

/**/
static HString LocalPrintReal( const HR64 in_data, const HSINT in_presision )
{
	
	HString string;
	if( 0.0 == in_data )
	{
		string = HVariablesString::DigitGet( 0 );
		string += HVariablesString::DecimalGet();
		string += HVariablesString::DigitGet( 0 );
		return string;
	}
	HSINT exponential = 0;
	HR64 localValue( in_data );
	if( localValue < 0.0 )
	{
		string = HVariablesString::MinusGet();
		localValue = -localValue;
	}

	exponential = LocalPrintLog( localValue );
	HSINT presisionAdjust( exponential );

	//round up
	localValue += ( 0.5 / LocalPrintPower( in_presision - exponential ) );

	//only go into exponential if too far away from 0
	if( ( -in_presision < exponential ) && ( exponential < in_presision ) )
	{
		exponential = 0;
	}
	else
	{
		localValue /= LocalPrintPower( exponential );
		presisionAdjust = 0;
	}


	const HU32 number = HU32( localValue );
	localValue -= HR64( number );
	string += HTraitStringIn< HU32 >( number );
	string += HVariablesString::DecimalGet();

	string += LocalPrintRealFraction( localValue, in_presision - presisionAdjust );

	if( 0 != exponential )
	{
		string += HVariablesString::HighE();
		HBOOL negativeExponential = HFALSE;
		if( exponential < 0 )
		{
			negativeExponential = HTRUE;
			exponential = -exponential;
		}

		string += LocalPrintInt( negativeExponential, HU32( exponential ), 10000 );
	}

	return string;
}

/**/
static HCHAR LocalPrintHex( const HSINT in_data, const HSINT in_shift )
{
	return HVariablesString::HexGet( ( in_data >> ( 4 * in_shift ) ) & 0x0F );
}

//////////////////////////////////////////////////////
// public methods

//255
//100
/**/
HString Hubris::HTraitStringIn< HU8 >( const HU8& in_data )
{
	return LocalPrintInt( HFALSE, HU32( in_data ), 100 );
}		

/**/
HString Hubris::HTraitStringIn< HS8 >( const HS8& in_data )
{
	HBOOL negative = HFALSE;
	HS32 local( in_data );
	if( in_data < 0 )
	{
		local = -local;
		negative = HTRUE;
	}

	return LocalPrintInt( negative, HU32( local ), 100 );
}		

//65535
//10000
/**/
HString Hubris::HTraitStringIn< HU16 >( const HU16& in_data )
{
	return LocalPrintInt( HFALSE, HU32( in_data ), 10000 );
}		

/**/
HString Hubris::HTraitStringIn< HS16 >( const HS16& in_data )
{
	HBOOL negative = HFALSE;
	HS32 local( in_data );
	if( in_data < 0 )
	{
		local = -local;
		negative = HTRUE;
	}

	return LocalPrintInt( negative, HU32( local ), 10000 );
}		

//4294967295
//1000000000
/**/
HString Hubris::HTraitStringIn< HU32 >( const HU32& in_data )
{
	return LocalPrintInt( HFALSE, in_data, 1000000000 );
}		

/**/
HString Hubris::HTraitStringIn< HS32 >( const HS32& in_data )
{
	HBOOL negative = HFALSE;
	HS32 local( in_data );
	if( in_data < 0 )
	{
		local = -local;
		negative = HTRUE;
	}

	return LocalPrintInt( negative, HU32( local ), 1000000000 );
}	

/**/
HString Hubris::HTraitStringIn< HR32 >( const HR32& in_data )
{
	return LocalPrintReal( in_data, 7 );
}

/**/
HString Hubris::HTraitStringIn< HR64 >( const HR64& in_data )
{
	return LocalPrintReal( in_data, 16 );
}

/**/
HString Hubris::HTraitStringIn< HCHAR >( const HCHAR& in_data )
{
	return LocalPrintInt( HFALSE, HU32( in_data & 0xFF ), 100 );
}

/**/
HString Hubris::HTraitStringIn< HBOOL >( const HBOOL& in_data )
{
	if( HTRUE == in_data )
	{
		return HVariablesString::TrueGet();
	}

	return HVariablesString::FalseGet();
}

/**/
HString Hubris::HTraitStringIn< HString >( const HString& in_data )
{
	const HString string = HStringUtility::EscapeString( in_data, HStringUtility::DefaultEscapeCharArrayGet() );

	return string;
}

/**/
HString Hubris::HTraitStringInHex< HU8 >( const HU8& in_data )
{
	HString returnString;
	returnString += LocalPrintHex( in_data, 1 );
	returnString += LocalPrintHex( in_data, 0 );
	return returnString;
}

/**/