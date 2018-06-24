//file: Pride/PColour/PColourTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PColour/PColourTrait.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >
#include< Hubris/HString/HString_Export.h >

#include< Envy/EMemento/EMemento_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HString >TArrayString;

/////////////////////////////////////////////////////////////////
// empty
/**/
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( PColourMono );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( PColourRgb );
HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( PColourRgba );

/////////////////////////////////////////////////////////////////
// implementation
/**/
HString Hubris::HTraitStringIn< Pride::PColourRgb >( const Pride::PColourRgb& in_data )
{
	HString colourString;

	colourString += HTraitStringIn( in_data.RedGet() ) + HVariablesString::SpaceGet(); 
	colourString += HTraitStringIn( in_data.GreenGet() ) + HVariablesString::SpaceGet(); 
	colourString += HTraitStringIn( in_data.BlueGet() ); 

	return colourString;
}

/**/
HString Hubris::HTraitStringIn< Pride::PColourRgba >( const Pride::PColourRgba& in_data )
{
	HString colourString;

	colourString += HTraitStringIn( in_data.RedGet() ) + HVariablesString::SpaceGet(); 
	colourString += HTraitStringIn( in_data.GreenGet() ) + HVariablesString::SpaceGet(); 
	colourString += HTraitStringIn( in_data.BlueGet() ) + HVariablesString::SpaceGet(); 
	colourString += HTraitStringIn( in_data.OpacityGet() );

	return colourString;
}

/**/
Hubris::HVOID Hubris::HTraitStringOut< Pride::PColourRgb >( Pride::PColourRgb & out_value, const HString& in_data )
{
	out_value = Pride::PColourRgb();
	TArrayString arrayTokens;

	HStringUtility::Split( in_data, HVariablesString::SpaceGet(), arrayTokens );

	if( 0 < arrayTokens.SizeGet() )
	{
		HU8 value = 0;
		HTraitStringOut< HU8 >( value, arrayTokens[ 0 ] );
		out_value.RedSet( value );
	}

	if( 1 < arrayTokens.SizeGet() )
	{
		HU8 value = 0;
		HTraitStringOut< HU8 >( value, arrayTokens[ 1 ] );
		out_value.GreenSet( value );
	}

	if( 2 < arrayTokens.SizeGet() )
	{
		HU8 value = 0;
		HTraitStringOut< HU8 >( value, arrayTokens[ 2 ] );
		out_value.BlueSet( value );
	}

	return;
}

/**/
Hubris::HVOID Hubris::HTraitStringOut< Pride::PColourRgba >( Pride::PColourRgba & out_value, const HString& in_data )
{
	out_value = Pride::PColourRgba();
	TArrayString arrayTokens;

	HStringUtility::Split( in_data, HVariablesString::SpaceGet(), arrayTokens );

	if( 0 < arrayTokens.SizeGet() )
	{
		HU8 value = 0;
		HTraitStringOut< HU8 >( value, arrayTokens[ 0 ] );
		out_value.RedSet( value );
	}

	if( 1 < arrayTokens.SizeGet() )
	{
		HU8 value = 0;
		HTraitStringOut< HU8 >( value, arrayTokens[ 1 ] );
		out_value.GreenSet( value );
	}

	if( 2 < arrayTokens.SizeGet() )
	{
		HU8 value = 0;
		HTraitStringOut< HU8 >( value, arrayTokens[ 2 ] );
		out_value.BlueSet( value );
	}

	if( 3 < arrayTokens.SizeGet() )
	{
		HU8 value = 0;
		HTraitStringOut< HU8 >( value, arrayTokens[ 3 ] );
		out_value.OpacitySet( value );
	}

	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< Pride::PColourRgba >( HBuffer& in_out_buffer, const Pride::PColourRgba& in_value )
{
	HTraitBufferInAppend< Pride::PColourRgba::TVector >( in_out_buffer, in_value.DataGet() );
	return;
}

/**/
HVOID Hubris::HTraitBufferInAppend< Pride::PColourRealRgba >( HBuffer& in_out_buffer, const Pride::PColourRealRgba& in_value )
{
	HTraitBufferInAppend< Pride::PColourRealRgba::TVector >( in_out_buffer, in_value.DataGet() );
	return;
}

/**/
HSINT Hubris::HTraitBufferInReplace< Pride::PColourRgba >( HBuffer& in_out_buffer, const Pride::PColourRgba& in_value, const HSINT in_offset )
{
	return HTraitBufferInReplace< Pride::PColourRgba::TVector >( in_out_buffer, in_value.DataGet(), in_offset );
}

/**/
HSINT Hubris::HTraitBufferInReplace< Pride::PColourRealRgba >( HBuffer& in_out_buffer, const Pride::PColourRealRgba& in_value, const HSINT in_offset )
{
	return HTraitBufferInReplace< Pride::PColourRealRgba::TVector >( in_out_buffer, in_value.DataGet(), in_offset );
}

/**/
HVOID Hubris::HTraitBufferOutGet< Pride::PColourRgba >( Pride::PColourRgba& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	Pride::PColourRgba::TVector data;
	HTraitBufferOutGet< Pride::PColourRgba::TVector >( data, in_out_offset, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
HVOID Hubris::HTraitBufferOutGet< Pride::PColourRealRgba >( Pride::PColourRealRgba& out_value, HSINT& in_out_offset, const HBuffer& in_buffer )
{
	Pride::PColourRealRgba::TVector data;
	HTraitBufferOutGet< Pride::PColourRealRgba::TVector >( data, in_out_offset, in_buffer );
	out_value.DataSet( data );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< Pride::PColourRgb >( EMementoCollect& in_out_mementoCollect, const Pride::PColourRgb& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_data", in_data.DataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< Pride::PColourRgb >( const EMementoAssign& in_out_mementoAssign, Pride::PColourRgb& out_data )
{
	Pride::PColourRgb::TVector data;
	in_out_mementoAssign.MemberGet( "m_data", data );
	out_data.DataSet( data );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< Pride::PColourRgba >( EMementoCollect& in_out_mementoCollect, const Pride::PColourRgba& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_data", in_data.DataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< Pride::PColourRgba >( const EMementoAssign& in_out_mementoAssign, Pride::PColourRgba& out_data )
{
	Pride::PColourRgba::TVector data;
	in_out_mementoAssign.MemberGet( "m_data", data );
	out_data.DataSet( data );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< Pride::PColourRealRgb >( EMementoCollect& in_out_mementoCollect, const Pride::PColourRealRgb& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_data", in_data.DataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< Pride::PColourRealRgb >( const EMementoAssign& in_out_mementoAssign, Pride::PColourRealRgb& out_data )
{
	Pride::PColourRealRgb::TVector data;
	in_out_mementoAssign.MemberGet( "m_data", data );
	out_data.DataSet( data );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< Pride::PColourRealRgba >( EMementoCollect& in_out_mementoCollect, const Pride::PColourRealRgba& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_data", in_data.DataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< Pride::PColourRealRgba >( const EMementoAssign& in_out_mementoAssign, Pride::PColourRealRgba& out_data )
{
	Pride::PColourRealRgba::TVector data;
	in_out_mementoAssign.MemberGet( "m_data", data );
	out_data.DataSet( data );
	return;
}

/**/
