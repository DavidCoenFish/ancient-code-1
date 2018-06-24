//file: Pride/PImage/PImage.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PImage/PImage.h"

#include "Pride/PColour/PColour_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PImage< HU8, 1 >;
template class Pride::PImage< HU8, 3 >;
template class Pride::PImage< HU8, 4 >;

template class Pride::PImage< HREAL, 1 >;
template class Pride::PImage< HREAL, 3 >;
template class Pride::PImage< HREAL, 4 >;

////////////////////////////////////////////////////
// typedef
/**/
struct TAxis
{
	enum TEnum
	{
		TWidth = 0,
		THeight,
		TCount
	};
};

///////////////////////////////////////////////////////////
// local free function
/*
	would be quicker without the wrap, infact, don't allow set or get on out of range pixel, ASSERT
*/
static HSINT LocalIndexGet( const HVectorS2& in_index, const HVectorS2& in_size )
{
	const HSINT index = ( ( in_index[ TAxis::THeight ] * in_size[ TAxis::TWidth ] ) + in_index[ TAxis::TWidth ] );

	return index;
}

///////////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::PImage( const PImage& in_src )
: m_size()
, m_data()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::PImage( const Hubris::HVectorS2& in_size )
: m_size()
, m_data()
{
	SizeSet( in_size );
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::~PImage()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
const PImage< IN_TYPE, IN_CHANNEL_COUNT >& Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::operator=( const PImage& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_size = in_rhs.m_size;
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
HBOOL Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::operator==( const PImage& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_size == in_rhs.m_size );
		match &= ( m_data == in_rhs.m_data );
	}

	return match;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
HBOOL Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::operator!=( const PImage& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
HBOOL Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::IndexValid( const Hubris::HVectorS2& in_index )const
{
	HBOOL valid = HTRUE;

	valid &= ( 0 <= in_index[ TAxis::TWidth ] );
	valid &= ( in_index[ TAxis::TWidth ] < m_size[ TAxis::TWidth ] );

	valid &= ( 0 <= in_index[ TAxis::THeight ] );
	valid &= ( in_index[ TAxis::THeight ] < m_size[ TAxis::THeight ] );

	return valid;
}

///////////////////////////////////////////////////////
// static public methods
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
const Hubris::HVectorS2 Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::IndexCreate( const Hubris::HSINT in_width, const Hubris::HSINT in_height )
{
	HVectorS2 returnValue;
	returnValue[ TAxis::TWidth ] = in_width;
	returnValue[ TAxis::THeight ] = in_height;
	return returnValue;
}

///////////////////////////////////////////////////////
// public accessors
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
typename const Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::TColour Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::ColourGet( const Hubris::HVectorS2& in_index )const
{
	HCOMMON_ASSERT( HTRUE == IndexValid( in_index ), "invalid param" ); 
	TColour returnColour;
	TVector colourData;
	const HSINT dataIndex = ( LocalIndexGet( in_index, m_size ) * IN_CHANNEL_COUNT );
	for( HSINT index = 0; index < IN_CHANNEL_COUNT; ++index )
	{
		colourData[ index ] = m_data[ dataIndex + index ];
	}

	returnColour.DataSet( colourData );
	return returnColour;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::ColourSet( const Hubris::HVectorS2& in_index, const TColour& in_colour )
{
	HCOMMON_ASSERT( HTRUE == IndexValid( in_index ), "invalid param" ); 
	const TVector colourData = in_colour.DataGet();
	const HSINT dataIndex = ( LocalIndexGet( in_index, m_size ) * IN_CHANNEL_COUNT );
	for( HSINT index = 0; index < IN_CHANNEL_COUNT; ++index )
	{
		m_data[ dataIndex + index ] = colourData[ index ];
	}

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::SizeSet( const Hubris::HVectorS2& in_size )
{
	HCOMMON_ASSERT( 0 <= in_size[ TAxis::TWidth ], "invalid param" ); 
	HCOMMON_ASSERT( 0 <= in_size[ TAxis::THeight ], "invalid param" ); 

	m_size = in_size;
	
	m_data.SizeSet( in_size[ TAxis::TWidth ] * in_size[ TAxis::THeight ] * IN_CHANNEL_COUNT );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
const void* const Pride::PImage< IN_TYPE, IN_CHANNEL_COUNT >::RawGet()const
{
	return m_data.RawGet();
}

/**/
