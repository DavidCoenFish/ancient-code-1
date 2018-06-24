//file: Hubris/HString/HStringOperators.h
#ifndef _H_STRING_OPERATORS_H_
#define _H_STRING_OPERATORS_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	class HString;

	const HBOOL operator ==( const HString& in_lhs, const HString& in_rhs );
	const HBOOL operator ==( const HString& in_lhs, const HCHAR* const in_rhs );
	const HBOOL operator ==( const HCHAR* const in_lhs, const HString& in_rhs );
	const HBOOL operator ==( const HString& in_lhs, const HCHAR in_rhs );
	const HBOOL operator ==( const HCHAR in_lhs, const HString& in_rhs );
	const HBOOL operator ==( const HString& in_lhs, const HSINT in_rhs );
	const HBOOL operator ==( const HSINT in_lhs, const HString& in_rhs );

	const HBOOL operator !=( const HString& in_lhs, const HString& in_rhs );
	const HBOOL operator !=( const HString& in_lhs, const HCHAR* const in_rhs );
	const HBOOL operator !=( const HCHAR* const in_lhs, const HString& in_rhs );
	const HBOOL operator !=( const HString& in_lhs, const HCHAR in_rhs );
	const HBOOL operator !=( const HCHAR in_lhs, const HString& in_rhs );
	const HBOOL operator !=( const HString& in_lhs, const HSINT in_rhs );
	const HBOOL operator !=( const HSINT in_lhs, const HString& in_rhs );

	const HString operator +( const HString& in_lhs, const HString& in_rhs );
	const HString operator +( const HString& in_lhs, const HCHAR* const in_rhs );
	const HString operator +( const HCHAR* const in_lhs, const HString& in_rhs );
	const HString operator +( const HString& in_lhs, const HCHAR in_rhs );
	const HString operator +( const HCHAR in_lhs, const HString& in_rhs );
	const HString operator +( const HString& in_lhs, const HSINT in_rhs );
	const HString operator +( const HSINT in_lhs, const HString& in_rhs );

	const HString& operator +=( HString& in_lhs, const HString& in_rhs );
	const HString& operator +=( HString& in_lhs, const HCHAR* const in_rhs );
	const HString& operator +=( HString& in_lhs, const HCHAR in_rhs );
	const HString& operator +=( HString& in_lhs, const HSINT in_rhs );

	const HBOOL operator <( const HString& in_lhs, const HString& in_rhs );
	const HBOOL operator <( const HString& in_lhs, const HCHAR* const in_rhs );
	const HBOOL operator <( const HCHAR* const in_lhs, const HString& in_rhs );
	const HBOOL operator <( const HString& in_lhs, const HCHAR in_rhs );
	const HBOOL operator <( const HCHAR in_lhs, const HString& in_rhs );
	const HBOOL operator <( const HString& in_lhs, const HSINT in_rhs );
	const HBOOL operator <( const HSINT in_lhs, const HString& in_rhs );

};

#endif // _H_STRING_OPERATORS_H_