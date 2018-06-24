//file: Pride/PAnimation/PAnimationExtra.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PAnimation/PAnimationExtra.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PAnimationExtra::PAnimationExtra( const PAnimationExtra& in_src )
: m_name()
, m_flag( 0 )
, m_animation()
{
	( *this ) = in_src;
	return;
}

/**/
PAnimationExtra::PAnimationExtra(
	const Hubris::HString& in_name,
	const Hubris::HSINT& in_flag,
	const PAnimation& in_animation
	)
: m_name( in_name )
, m_flag( in_flag )
, m_animation( in_animation )
{
	return;
}

/**/
PAnimationExtra::PAnimationExtra()
: m_name()
, m_flag( 0 )
, m_animation()
{
	return;
}

/**/
PAnimationExtra::~PAnimationExtra()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PAnimationExtra& PAnimationExtra::operator=( const PAnimationExtra& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_name = in_rhs.m_name;
		m_flag = in_rhs.m_flag;
		m_animation = in_rhs.m_animation;
	}

	return( *this );
}

/**/
const Hubris::HBOOL PAnimationExtra::operator==( const PAnimationExtra& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_name == in_rhs.m_name );
		match &= ( m_flag == in_rhs.m_flag );
		match &= ( m_animation == in_rhs.m_animation );
	}

	return match;
}

/**/
const Hubris::HBOOL PAnimationExtra::operator!=( const PAnimationExtra& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
