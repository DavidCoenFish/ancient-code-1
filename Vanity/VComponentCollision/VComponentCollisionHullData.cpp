//file: Vanity/VComponentCollision/VComponentCollisionHullData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionHullData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionHullData::VComponentCollisionHullData( const VComponentCollisionHullData& in_src )
: m_plane()
, m_arrayIndexTouchingPlane()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentCollisionHullData::VComponentCollisionHullData()
: m_plane()
, m_arrayIndexTouchingPlane()
{
	return;
}

/**/
VComponentCollisionHullData::~VComponentCollisionHullData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VComponentCollisionHullData& VComponentCollisionHullData::operator=( const VComponentCollisionHullData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_plane = in_rhs.m_plane;
		m_arrayIndexTouchingPlane = in_rhs.m_arrayIndexTouchingPlane;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentCollisionHullData::operator==( const VComponentCollisionHullData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_plane == in_rhs.m_plane );
		match &= ( m_arrayIndexTouchingPlane == in_rhs.m_arrayIndexTouchingPlane );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentCollisionHullData::operator!=( const VComponentCollisionHullData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}
/**/
