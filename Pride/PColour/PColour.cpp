//file: Pride/PColour/PColour.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PColour/PColour.h"

#include "Pride/PColour/PColourOperator.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// typedef
/*
	optimisation dependance. raw layout to match win32 bitmap colour specification.
	incase of change, need to modify PImage/PImageBitmap.h
*/
struct TChannel
{
	enum TEnum
	{
		TBlue= 0,
		TGreen,
		TRed,
		TOpacity,
		TCount
	};
};


////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PColour< HU8, 4 >;
template class Pride::PColour< HU8, 3 >;
template class Pride::PColour< HU8, 1 >;

template class Pride::PColour< HREAL, 4 >;
template class Pride::PColour< HREAL, 3 >;
template class Pride::PColour< HREAL, 1 >;

///////////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::PColour( const PColour& in_src )
: m_data()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::PColour( const TVector& in_data )
: m_data( in_data )
{
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::PColour( const IN_TYPE in_red, const IN_TYPE in_green, const IN_TYPE in_blue, const IN_TYPE in_opacity )
: m_data()
{
	RedSet( in_red );
	GreenSet( in_green );
	BlueSet( in_blue );
	OpacitySet( in_opacity );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::PColour( 
			const IN_TYPE in_red,
			const IN_TYPE in_green,
			const IN_TYPE in_blue
			)
: m_data()
{
	RedSet( in_red );
	GreenSet( in_green );
	BlueSet( in_blue );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::PColour( const IN_TYPE in_mono )
: m_data()
{
	MonoSet( in_mono );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::~PColour()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
const PColour< IN_TYPE, IN_CHANNEL_COUNT >& Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::operator=( const PColour& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
const HBOOL Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::operator==( const PColour& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_data == in_rhs.m_data );
	}

	return match;
}

/**
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
const HBOOL Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::operator!=( const PColour& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
///////////////////////////////////////////////////////
// public methods

//return the value in the first channel, set the value to the same in all channels
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
IN_TYPE Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::MonoGet()const
{
	return m_data[ 0 ];
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::MonoSet( const IN_TYPE in_mono )
{
	m_data = in_mono;
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
IN_TYPE Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::RedGet()const
{
	return m_data[ TChannel::TRed ];
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::RedSet( const IN_TYPE in_red )
{
	m_data[ TChannel::TRed ] = in_red;
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
IN_TYPE Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::GreenGet()const
{
	return m_data[ TChannel::TGreen ];
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::GreenSet( const IN_TYPE in_green )
{
	m_data[ TChannel::TGreen ] = in_green;
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
IN_TYPE Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::BlueGet()const
{
	return m_data[ TChannel::TBlue ];
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::BlueSet( const IN_TYPE in_blue )
{
	m_data[ TChannel::TBlue ] = in_blue;
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
IN_TYPE Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::OpacityGet()const
{
	return m_data[ TChannel::TOpacity ];
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PColour< IN_TYPE, IN_CHANNEL_COUNT >::OpacitySet( const IN_TYPE in_opacity )
{
	m_data[ TChannel::TOpacity ] = in_opacity;
	return;
}

/**/