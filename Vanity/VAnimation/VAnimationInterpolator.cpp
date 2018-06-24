//file: Vanity/VAnimation/VAnimationInterpolator.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationInterpolator.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VAnimationInterpolator::VAnimationInterpolator( const VAnimationInterpolator& in_src )
: m_currentIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
VAnimationInterpolator::VAnimationInterpolator()
: m_currentIndex( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
VAnimationInterpolator::~VAnimationInterpolator()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VAnimationInterpolator& VAnimationInterpolator::operator=( const VAnimationInterpolator& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_currentIndex = in_rhs.m_currentIndex;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VAnimationInterpolator::operator==( const VAnimationInterpolator& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_currentIndex == in_rhs.m_currentIndex );
	}
	return match;
}

/**/
const Hubris::HBOOL VAnimationInterpolator::operator!=( const VAnimationInterpolator& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
