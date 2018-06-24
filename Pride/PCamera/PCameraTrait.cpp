//file: Pride/PCamera/PCameraTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PCamera/PCameraTrait.h"

#include "Pride/PCamera/PCamera.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/////////////////////////////////////////////////////////////////
// typedef
/**/

/////////////////////////////////////////////////////////////////
// empty
/**/
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( PCamera );

///////////////////////////////////////////////////////////////////
//// implementation
///**/
//HString Hubris::HTraitStringIn< Pride::PCameraRgb >( const Pride::PCameraRgb& in_data )
//{
//	HString colourString;
//
//	colourString += HTraitStringIn( in_data.RedGet() ) + HVariablesString::SpaceGet(); 
//	colourString += HTraitStringIn( in_data.GreenGet() ) + HVariablesString::SpaceGet(); 
//	colourString += HTraitStringIn( in_data.BlueGet() ); 
//
//	return colourString;
//}
//
///**/
//HString Hubris::HTraitStringIn< Pride::PCameraRgba >( const Pride::PCameraRgba& in_data )
//{
//	HString colourString;
//
//	colourString += HTraitStringIn( in_data.RedGet() ) + HVariablesString::SpaceGet(); 
//	colourString += HTraitStringIn( in_data.GreenGet() ) + HVariablesString::SpaceGet(); 
//	colourString += HTraitStringIn( in_data.BlueGet() ) + HVariablesString::SpaceGet(); 
//	colourString += HTraitStringIn( in_data.OpacityGet() );
//
//	return colourString;
//}
//
///**/
//Hubris::HVOID Hubris::HTraitStringOut< Pride::PCameraRgb >( Pride::PCameraRgb & out_value, const HString& in_data )
//{
//	out_value = Pride::PCameraRgb();
//	TArrayString arrayTokens;
//
//	HStringUtility::Split( in_data, HVariablesString::SpaceGet(), arrayTokens );
//
//	if( 0 < arrayTokens.SizeGet() )
//	{
//		HU8 value = 0;
//		HTraitStringOut< HU8 >( value, arrayTokens[ 0 ] );
//		out_value.RedSet( value );
//	}
//
//	if( 1 < arrayTokens.SizeGet() )
//	{
//		HU8 value = 0;
//		HTraitStringOut< HU8 >( value, arrayTokens[ 1 ] );
//		out_value.GreenSet( value );
//	}
//
//	if( 2 < arrayTokens.SizeGet() )
//	{
//		HU8 value = 0;
//		HTraitStringOut< HU8 >( value, arrayTokens[ 2 ] );
//		out_value.BlueSet( value );
//	}
//
//	return;
//}
//
///**/
//Hubris::HVOID Hubris::HTraitStringOut< Pride::PCameraRgba >( Pride::PCameraRgba & out_value, const HString& in_data )
//{
//	out_value = Pride::PCameraRgba();
//	TArrayString arrayTokens;
//
//	HStringUtility::Split( in_data, HVariablesString::SpaceGet(), arrayTokens );
//
//	if( 0 < arrayTokens.SizeGet() )
//	{
//		HU8 value = 0;
//		HTraitStringOut< HU8 >( value, arrayTokens[ 0 ] );
//		out_value.RedSet( value );
//	}
//
//	if( 1 < arrayTokens.SizeGet() )
//	{
//		HU8 value = 0;
//		HTraitStringOut< HU8 >( value, arrayTokens[ 1 ] );
//		out_value.GreenSet( value );
//	}
//
//	if( 2 < arrayTokens.SizeGet() )
//	{
//		HU8 value = 0;
//		HTraitStringOut< HU8 >( value, arrayTokens[ 2 ] );
//		out_value.BlueSet( value );
//	}
//
//	if( 3 < arrayTokens.SizeGet() )
//	{
//		HU8 value = 0;
//		HTraitStringOut< HU8 >( value, arrayTokens[ 3 ] );
//		out_value.OpacitySet( value );
//	}
//
//	return;
//}
//
/**/