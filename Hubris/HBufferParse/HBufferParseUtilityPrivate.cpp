//file: Hubris/HBufferParse/HBufferParseUtilityPrivate.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseUtilityPrivate.h"

#include "Hubris/HBufferParse/HBufferParseLoad.h"
#include "Hubris/HBufferParse/HBufferParseLoadBin.h"
#include "Hubris/HBufferParse/HBufferParseLoadText.h"
#include "Hubris/HBufferParse/HBufferParseSave.h"
#include "Hubris/HBufferParse/HBufferParseSaveBin.h"
#include "Hubris/HBufferParse/HBufferParseSaveText.h"

#include "Hubris/HTrait/HTraitBufferIn.h"
#include "Hubris/HTrait/HTraitBufferOut.h"
#include "Hubris/HVariables/HVariablesString.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////
// static public methods
/**/
HVOID Hubris::HBufferParseUtilityPrivate::IsTextSet( HBuffer& )
{
	//HTraitBufferInAppend( out_destBuffer, HVariablesString::HighT() );
	//HTraitBufferInAppend( out_destBuffer, HVariablesString::HighX() );
	//HTraitBufferInAppend( out_destBuffer, HVariablesString::HighT() );
	//HTraitBufferInAppend( out_destBuffer, HVariablesString::DigitGet( 0 ) );

	return;
}

/**/
HVOID Hubris::HBufferParseUtilityPrivate::IsBinSet( HBuffer& out_destBuffer )
{
	HTraitBufferInAppend( out_destBuffer, HVariablesString::HighB() );
	HTraitBufferInAppend( out_destBuffer, HVariablesString::HighI() );
	HTraitBufferInAppend( out_destBuffer, HVariablesString::HighN() );
	HTraitBufferInAppend( out_destBuffer, HVariablesString::DigitGet( 0 ) );

	return;
}

/**/
const HBOOL Hubris::HBufferParseUtilityPrivate::IsTextGet( const HBuffer&, HSINT& )
{
	//out_offset = 0;
	//HSINT offset = 0;

	//if( in_srcBuffer.SizeGet() < 4 )
	//{
	//	return HFALSE;
	//}


	//HCHAR data;
	//HTraitBufferOutGet( data, offset, in_srcBuffer );
	//if( HVariablesString::HighT() != data )
	//{
	//	return HFALSE;
	//}

	//HTraitBufferOutGet( data, offset, in_srcBuffer );
	//if( HVariablesString::HighX() != data )
	//{
	//	return HFALSE;
	//}

	//HTraitBufferOutGet( data, offset, in_srcBuffer );
	//if( HVariablesString::HighT() != data )
	//{
	//	return HFALSE;
	//}

	//HTraitBufferOutGet( data, offset, in_srcBuffer );
	//if( HVariablesString::DigitGet( 0 ) != data )
	//{
	//	return HFALSE;
	//}

	//out_offset = offset;

	return HTRUE;
}

/**/
const HBOOL Hubris::HBufferParseUtilityPrivate::IsBinGet( const HBuffer& in_srcBuffer, HSINT& out_offset )
{
	out_offset = 0;
	HSINT offset = 0;

	if( in_srcBuffer.SizeGet() < 4 )
	{
		return HFALSE;
	}

	HCHAR data;
	HTraitBufferOutGet( data, offset, in_srcBuffer );
	if( HVariablesString::HighB() != data )
	{
		return HFALSE;
	}

	HTraitBufferOutGet( data, offset, in_srcBuffer );
	if( HVariablesString::HighI() != data )
	{
		return HFALSE;
	}

	HTraitBufferOutGet( data, offset, in_srcBuffer );
	if( HVariablesString::HighN() != data )
	{
		return HFALSE;
	}

	HTraitBufferOutGet( data, offset, in_srcBuffer );
	if( HVariablesString::DigitGet( 0 ) != data )
	{
		return HFALSE;
	}

	out_offset = offset;

	return HTRUE;
}

/**/
