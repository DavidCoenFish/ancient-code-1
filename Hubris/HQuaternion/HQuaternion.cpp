//file: Hubris/HQuaternion/HQuaternion.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HQuaternion/HQuaternion.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HMatrix/HMatrixOperator.h"

////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

////////////////////////////////////////////////////
// typedef
/**/
struct TChannel
{
	enum TEnum
	{
		TW = 0,
		TX,
		TY,
		TZ,
		TCount
	};
};


////////////////////////////////////////////////////
// template definitions
/**/
template class Hubris::HQuaternion< HREAL >;

///////////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE >
Hubris::HQuaternion< IN_TYPE >::HQuaternion( const HQuaternion& in_src )
: m_data()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE >
Hubris::HQuaternion< IN_TYPE >::HQuaternion( 
	const IN_TYPE in_w,  
	const IN_TYPE in_x, 
	const IN_TYPE in_y, 
	const IN_TYPE in_z 
	)
: m_data()
{
	WSet( in_w );
	XSet( in_x );
	YSet( in_y );
	ZSet( in_z );

	return;
}

/**/
template< typename IN_TYPE >
Hubris::HQuaternion< IN_TYPE >::~HQuaternion()
{
	return;
}

//////////////////////////////////////////
// operators, for other operators, see HQuaternionOperators
/**/
template< typename IN_TYPE >
const HQuaternion< IN_TYPE >& Hubris::HQuaternion< IN_TYPE >::operator=( const HQuaternion& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**/
template< typename IN_TYPE >
HBOOL Hubris::HQuaternion< IN_TYPE >::operator==( const HQuaternion& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_data == in_rhs.m_data );
	}

	return match;
}

/**/
template< typename IN_TYPE >
HBOOL Hubris::HQuaternion< IN_TYPE >::operator!=( const HQuaternion& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

//////////////////////////////////////////
// public accessors
/**/
template< typename IN_TYPE >
HVOID Hubris::HQuaternion< IN_TYPE >::WSet( const IN_TYPE in_w )
{
	m_data[ TChannel::TW ] = in_w;
	return;
}

/**/
template< typename IN_TYPE >
const IN_TYPE Hubris::HQuaternion< IN_TYPE >::WGet()const
{
	return m_data[ TChannel::TW ];
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HQuaternion< IN_TYPE >::XSet( const IN_TYPE in_x )
{
	m_data[ TChannel::TX ] = in_x;
	return;
}

/**/
template< typename IN_TYPE >
const IN_TYPE Hubris::HQuaternion< IN_TYPE >::XGet()const
{
	return m_data[ TChannel::TX ];
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HQuaternion< IN_TYPE >::YSet( const IN_TYPE in_y )
{
	m_data[ TChannel::TY ] = in_y;
	return;
}

/**/
template< typename IN_TYPE >
const IN_TYPE Hubris::HQuaternion< IN_TYPE >::YGet()const
{
	return m_data[ TChannel::TY ];
}

/**/
template< typename IN_TYPE >
HVOID Hubris::HQuaternion< IN_TYPE >::ZSet( const IN_TYPE in_z )
{
	m_data[ TChannel::TZ ] = in_z;
	return;
}

/**/
template< typename IN_TYPE >
const IN_TYPE Hubris::HQuaternion< IN_TYPE >::ZGet()const
{
	return m_data[ TChannel::TZ ];
}

/**/
