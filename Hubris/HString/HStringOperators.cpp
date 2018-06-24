//file: Hubris/HString/HStringOperators.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HString/HStringOperators.h"

#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringUtility.h"

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HVariables/HVariablesString.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
const HBOOL Hubris::operator ==( const HString& in_lhs, const HString& in_rhs )
{
	return(0 == HStringUtility::StringCmp( in_lhs.RawGet(), in_rhs.RawGet() ) );
}

/**/
const HBOOL Hubris::operator ==( const HString& in_lhs, const HCHAR* const in_rhs )
{
	if( HNULL == in_rhs )
	{
		return(0 == HStringUtility::StringCmp( in_lhs.RawGet(), "" ) );
	}
	return(0 == HStringUtility::StringCmp( in_lhs.RawGet(), in_rhs ) );
}

/**/
const HBOOL Hubris::operator ==( const HCHAR* const in_lhs, const HString& in_rhs )
{
	if( HNULL == in_lhs )
	{
		return(0 == HStringUtility::StringCmp( "", in_rhs.RawGet() ) );
	}
	return(0 == HStringUtility::StringCmp( in_lhs, in_rhs.RawGet() ) );
}

/**/
const HBOOL Hubris::operator ==( const HString& in_lhs, const HCHAR in_rhs )
{
	HCHAR data[2];
	data[0] = in_rhs;
	data[1] = HVariablesString::EndOfStringGet();

	return(0 == HStringUtility::StringCmp( in_lhs.RawGet(), &data[0] ) );
}

/**/
const HBOOL Hubris::operator ==( const HCHAR in_lhs, const HString& in_rhs )
{
	HCHAR data[2];
	data[0] = in_lhs;
	data[1] = HVariablesString::EndOfStringGet();

	return(0 == HStringUtility::StringCmp( &data[0], in_rhs.RawGet()) );
}

/**/
const HBOOL Hubris::operator ==( const HString& in_lhs, const HSINT in_rhs )
{
	HCOMMON_ASSERT( 0 == in_rhs, "sint for HNULL only" );

	return( 0 == in_lhs.SizeGet() );
}

/**/
const HBOOL Hubris::operator ==( const HSINT in_lhs, const HString& in_rhs )
{
	HCOMMON_ASSERT( 0 == in_lhs, "sint for HNULL only" );

	return( 0 == in_rhs.SizeGet() );
}

/**/
const HBOOL Hubris::operator !=( const HString& in_lhs, const HString& in_rhs )
{
	return!( operator==( in_lhs, in_rhs ) );
}

/**/
const HBOOL Hubris::operator !=( const HString& in_lhs, const HCHAR* const in_rhs )
{
	return!( operator==( in_lhs, in_rhs ) );
}

/**/
const HBOOL Hubris::operator !=( const HCHAR* const in_lhs, const HString& in_rhs )
{
	return!( operator==( in_lhs, in_rhs ) );
}

/**/
const HBOOL Hubris::operator !=( const HString& in_lhs, const HCHAR in_rhs )
{
	return!( operator==( in_lhs, in_rhs ) );
}

/**/
const HBOOL Hubris::operator !=( const HCHAR in_lhs, const HString& in_rhs )
{
	return!( operator==( in_lhs, in_rhs ) );
}

/**/
const HBOOL Hubris::operator !=( const HString& in_lhs, const HSINT in_rhs )
{
	return!( operator==( in_lhs, in_rhs ) );
}

/**/
const HBOOL Hubris::operator !=( const HSINT in_lhs, const HString& in_rhs )
{
	return!( operator==( in_lhs, in_rhs ) );
}

/**/
const HString Hubris::operator +( const HString& in_lhs, const HString& in_rhs )
{
	HString string(in_lhs);
	string += in_rhs;

	return string;
}

/**/
const HString Hubris::operator +( const HString& in_lhs, const HCHAR* const in_rhs )
{
	HString string(in_lhs);
	string += in_rhs;

	return string;
}

/**/
const HString Hubris::operator +( const HCHAR* const in_lhs, const HString& in_rhs )
{
	HString string(in_lhs);
	string += in_rhs;

	return string;
}

/**/
const HString Hubris::operator +( const HString& in_lhs, const HCHAR in_rhs )
{
	HString string(in_lhs);
	string += in_rhs;

	return string;
}

/**/
const HString Hubris::operator +( const HCHAR in_lhs, const HString& in_rhs )
{
	HCHAR data[2];
	data[0] = in_lhs;
	data[1] = HVariablesString::EndOfStringGet();

	HString string( &data[0] );
	string += in_rhs;

	return string;
}

/**/
const HString Hubris::operator +( const HString& in_lhs, const HSINT in_rhs )
{
	HCOMMON_ASSERT( 0 == in_rhs, "sint for HNULL only" );

	return in_lhs;
}

/**/
const HString Hubris::operator +( const HSINT in_lhs, const HString& in_rhs )
{
	HCOMMON_ASSERT( 0 == in_lhs, "sint for HNULL only" );

	return in_rhs;
}

/**/
const HString& Hubris::operator +=( HString& in_lhs, const HString& in_rhs )
{
	const HSINT lhsSize = in_lhs.SizeGet();
	const HSINT rhsSize = in_rhs.SizeGet();

	in_lhs.SizeResize( lhsSize + rhsSize );
	in_lhs.DataSet( in_rhs.RawGet(), rhsSize, lhsSize );

	return( in_lhs );
}

/**/
const HString& Hubris::operator +=( HString& in_lhs, const HCHAR* const in_rhs )
{
	const HSINT lhsSize = in_lhs.SizeGet();
	const HSINT rhsSize = HStringUtility::Length( in_rhs );

	in_lhs.SizeResize( lhsSize + rhsSize );
	in_lhs.DataSet( in_rhs, rhsSize, lhsSize );

	return in_lhs;
}

/**/
const HString& Hubris::operator +=( HString& in_lhs, const HCHAR in_rhs )
{
	HCHAR data[2];
	data[0] = in_rhs;
	data[1] = HVariablesString::EndOfStringGet();

	const HSINT lhsSize = in_lhs.SizeGet();

	in_lhs.SizeResize( lhsSize + 1 );
	in_lhs.DataSet( &data[0], 1, lhsSize );

	return in_lhs;
}

/**/
const HString& Hubris::operator +=( HString& in_lhs, const HSINT in_rhs )
{
	HCOMMON_ASSERT( 0 == in_rhs, "sint for HNULL only" );

	return in_lhs;
}

/**/
const HBOOL Hubris::operator <( const HString& in_lhs, const HString& in_rhs )
{
	return(0 < HStringUtility::StringCmp( in_lhs.RawGet(), in_rhs.RawGet() ) );
}

/**/
const HBOOL Hubris::operator <( const HString& in_lhs, const HCHAR* const in_rhs )
{
	return(0 < HStringUtility::StringCmp( in_lhs.RawGet(), in_rhs ) );
}

/**/
const HBOOL Hubris::operator <( const HCHAR* const in_lhs, const HString& in_rhs )
{
	return(0 < HStringUtility::StringCmp( in_lhs, in_rhs.RawGet() ) );
}

/**/
const HBOOL Hubris::operator <( const HString& in_lhs, const HCHAR in_rhs )
{
	HCHAR data[2];
	data[0] = in_rhs;
	data[1] = HVariablesString::EndOfStringGet();
	return(0 < HStringUtility::StringCmp( in_lhs.RawGet(), &data[0] ) );
}

/**/
const HBOOL Hubris::operator <( const HCHAR in_lhs, const HString& in_rhs )
{
	HCHAR data[2];
	data[0] = in_lhs;
	data[1] = HVariablesString::EndOfStringGet();

	return(0 < HStringUtility::StringCmp( &data[0], in_rhs.RawGet() ) );
}

/**/
const HBOOL Hubris::operator <( const HString& in_lhs, const HSINT in_rhs )
{
	HCOMMON_ASSERT( 0 == in_rhs, "sint for HNULL only" );

	return(0 < HStringUtility::StringCmp( in_lhs.RawGet(), HNULL ) );
}

/**/
const HBOOL Hubris::operator <( const HSINT in_lhs, const HString& in_rhs )
{
	HCOMMON_ASSERT( 0 == in_lhs, "sint for HNULL only" );

	return(0 < HStringUtility::StringCmp( HNULL, in_rhs.RawGet() ) );
}

/**/
