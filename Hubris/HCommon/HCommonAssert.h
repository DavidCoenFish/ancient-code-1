//file: Hubris/HCommon/HCommonAssert.h
#ifndef _H_COMMON_ASSERT_H_
#define _H_COMMON_ASSERT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

namespace Hubris
{
	/**/
	struct HCommonAssert
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HCommonAssert();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		//return true on retry
		static HBOOL Assert( const HBOOL in_condition, const HCHAR* const in_conditionString, const HSINT in_line, const HCHAR* const in_message = HNULL, const HCHAR* const in_function = HNULL );
		static HBOOL AssertCase( const HSINT in_case, const HSINT in_line, const HCHAR* const in_function = HNULL );
		static HBOOL AssertAllways( const HSINT in_line, const HCHAR* const in_message = HNULL, const HCHAR* const in_function = HNULL );
	};

	/**/
};

#define HCOMMON_ASSERT( CONDITION, HMESSAGE ) while( HFALSE == ( CONDITION ) ) { if( HFALSE == Hubris::HCommonAssert::Assert( CONDITION, HCOMMON_TOKEN( CONDITION ), __LINE__, HMESSAGE, __FUNCTION__ ) ) break; }
#define HCOMMON_ASSERT_CASE( CASE ) while( HTRUE == Hubris::HCommonAssert::AssertCase( CASE, __LINE__, __FUNCTION__ ) ) {};
#define HCOMMON_ASSERT_ALWAYS( HMESSAGE ) while( HTRUE == Hubris::HCommonAssert::AssertAllways( __LINE__, HMESSAGE, __FUNCTION__ ) ) {};

//from redtribe
/** \brief  Static assert. If expr is K_HFALSE, it gives a compile time error.
*	@param expr	The expression to evaluate. It cannot contain commas due to macro rules.
*				If it does, evaluate the expression on a line before into a const kBool.
*	@param msg	A valid C identifier with the error message, such as Error_type_must_be_integer
**/
#define HCOMMON_ASSERT_STATIC(expr, msg) \
{ HCompileTimeError< ( ( expr ) != 0 ) >STATIC_ASSERT_##msg; ( HVOID )STATIC_ASSERT_##msg; } 

template< Hubris::HSINT >struct HCompileTimeError;
template<>struct HCompileTimeError< HTRUE > {};


#endif// _H_COMMON_ASSERT_H_
