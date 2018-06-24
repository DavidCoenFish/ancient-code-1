//file: Pride/PColour/PColourTrait.h
#ifndef _P_COLOUR_TRAIT_H_
#define _P_COLOUR_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PColour/PColour.h"

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class HString;
	template< typename IN_TYPE >HString HTraitStringIn( const IN_TYPE& in_data );
	template< typename IN_TYPE >IN_TYPE HTraitStringOut( const HString& in_data );

	template< typename IN_TYPE >HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const IN_TYPE& in_value );
	template< typename IN_TYPE >HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const IN_TYPE& in_value, const HSINT in_offset );
	template< typename IN_TYPE >HVOID HTraitBufferOutGet( IN_TYPE& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

	///////////////////////////////////////////////////////////
	// empty
	HTRAIT_EMPTY_HEADER( Pride::PColourMono );
	HTRAIT_EMPTY_HEADER( Pride::PColourRgb );
	HTRAIT_EMPTY_HEADER( Pride::PColourRgba );

	///////////////////////////////////////////////////////////
	// declarations
	template HString HTraitStringIn( const Pride::PColourRgb& in_data );
	template HString HTraitStringIn( const Pride::PColourRgba& in_data );

	//	template< typename IN_TYPE >HVOID HTraitStringOut( IN_TYPE& out_value, const HString& in_string );
	template HVOID HTraitStringOut( Pride::PColourRgb & out_value, const HString& in_data );
	template HVOID HTraitStringOut( Pride::PColourRgba & out_value, const HString& in_data );


	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const Pride::PColourRgba& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const Pride::PColourRealRgba& in_value );

	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const Pride::PColourRgba& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const Pride::PColourRealRgba& in_value, const HSINT in_offset );

	template HVOID HTraitBufferOutGet( Pride::PColourRgba& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( Pride::PColourRealRgba& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

};

/**/
namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	///////////////////////////////////////////////////////////
	// memento
	/**/
	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PColourRgb& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PColourRgb& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PColourRgba& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PColourRgba& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PColourRealRgb& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PColourRealRgb& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PColourRealRgba& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PColourRealRgba& out_data );

};

/**/
#endif // _P_COLOUR_TRAIT_H_