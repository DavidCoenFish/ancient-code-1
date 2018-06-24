//file: Vanity/VAnimation/VAnimationReference.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationReference.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VAnimationReference::VAnimationReference( 
	const VAnimationReference& in_src 
	)
: m_animation()
{
	( *this ) = in_src;
	return;
}

/**/
VAnimationReference::VAnimationReference(
	const VAnimation& in_aniamtion
	)
: m_animation( in_aniamtion )
{
	return;
}

/**/
VAnimationReference::VAnimationReference()
: m_animation()
{
	return;
}

/**/
VAnimationReference::~VAnimationReference()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VAnimationReference& VAnimationReference::operator=( const VAnimationReference& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_animation = in_rhs.m_animation;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VAnimationReference::operator==( const VAnimationReference& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_animation == in_rhs.m_animation );
	}

	return match;
}

/**/
const Hubris::HBOOL VAnimationReference::operator!=( const VAnimationReference& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
