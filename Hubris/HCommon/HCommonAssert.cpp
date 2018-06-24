//file: Hubris/HCommon/HCommonAssert.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HCommon/HCommonAssert.h"

#include <stdio.h>
#include <windows.h> 

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

////////////////////////////////////////////////////////////////
// local static var
/**/
static const HS32 s_maxAssertMessageLength = 4096;

//the UNICODE version of the message box function MessageBoxA from user32.dll
typedef int ( __stdcall * HMessageBox )( const HVOID * const hWnd, const HCHAR* const lpText, const HCHAR* const lpCaption, const HU32 uType );

////////////////////////////////////////////////////////////////
// local free functions
/**/
HBOOL HCommonAssertImplement( const HCHAR* const in_message = HNULL )
{
	HCOMMON_WARNING( in_message );

	HS32 messageReturn = 0;

	//call a messagebox from user32.dll
 HINSTANCE hinstLib = LoadLibrary( "user32.dll" ); 
 if( HNULL != hinstLib ) 
 { 
		HMessageBox messageBox = ( HMessageBox ) GetProcAddress( hinstLib, "MessageBoxA" ); 

		if( HNULL != messageBox )
		{
			const HCHAR* message = "<HNULL>";

			if( ( HNULL != in_message ) || ( in_message != 0 ) )
			{
				message = in_message;
			}

			messageReturn = messageBox( HNULL, message, "ASSERT: [abort] _asm( int 3), [retry/ignore] continues", MB_ICONERROR | MB_SETFOREGROUND | MB_ABORTRETRYIGNORE );
		}
	}

	//asm break point if not retry to continue
	if( IDABORT == messageReturn )
	{
		_asm { int 3 }
	}
	else if( IDRETRY == messageReturn )
	{
		return HTRUE;
	}

	return HFALSE;
}

////////////////////////////////////////////////////////////////
// namespace free functions
/**/
HBOOL Hubris::HCommonAssert::Assert( const HBOOL in_condition, const HCHAR* const in_conditionString, const HS32 in_line, const HCHAR* const in_message, const HCHAR* const in_function )
{
	if( HFALSE != in_condition )
	{
		return HFALSE;
	}

	HCHAR buf[ s_maxAssertMessageLength ];
	buf[0] = 0;

	if( HNULL != in_function )
	{
		H_SPRINT( buf, "FAILED %s line <%d> function <%s>\n", in_conditionString, in_line, in_function );
	}
	else
	{
		H_SPRINT( buf, "FAILED %s line <%d>\n", in_conditionString, in_line );
	}

	if( HNULL != in_message )
	{
		H_STRCAT( buf, in_message );
	}

	OutputDebugString( buf );

	const HBOOL result = HCommonAssertImplement( buf );

	return result;
}

/**/
HBOOL Hubris::HCommonAssert::AssertCase( const HS32 in_case, const HS32 in_line, const HCHAR* const in_function )
{
	HCHAR buf[s_maxAssertMessageLength ];
	buf[0] = 0;

	if( HNULL != in_function )
	{
		H_SPRINT( buf, "FAILED CASE %d line <%d> function <%s>\n", in_case, in_line, in_function );
	}
	else
	{
		H_SPRINT( buf, "FAILED CASE %d line <%d>\n", in_case, in_line );
	}

	const HBOOL result = HCommonAssertImplement( buf );

	return result;
}

/**/
HBOOL Hubris::HCommonAssert::AssertAllways( HS32 in_line, const HCHAR* const in_message, const HCHAR* const in_function )
{
	HCHAR buf[ s_maxAssertMessageLength ];
	buf[0] = 0;


	if( HNULL != in_function )
	{
		H_SPRINT( buf, "FAILED ALWAYS line <%d> function <%s>\n", in_line, in_function);
	}
	else
	{
		H_SPRINT( buf, "FAILED ALWAYS line <%d>\n", in_line );
	}

	if( HNULL != in_message )
	{
		H_STRCAT( buf, in_message );
	}

	const HBOOL result = HCommonAssertImplement( buf );

	return result;
}

/**/
