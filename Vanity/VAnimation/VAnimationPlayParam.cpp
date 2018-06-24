//file: Vanity/VAnimation/VAnimationPlayParam.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationPlayParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VAnimationPlayParam::VAnimationPlayParam( const VAnimationPlayParam& in_src )
: m_startTime( 0.0F )
, m_speed( 1.0F )
, m_baseWeight( 1.0F )
, m_fadeInDuration( 0.0F )
, m_fadeOutDuration( 0.0F )
{
	( *this ) = in_src;
	return;
}

/**/
VAnimationPlayParam::VAnimationPlayParam(
	const Hubris::HREAL in_startTime,
	const Hubris::HREAL in_speed,
	const Hubris::HREAL in_baseWeight,
	const Hubris::HREAL in_fadeInDuration,
	const Hubris::HREAL in_fadeOutDuration
	)
: m_startTime( in_startTime )
, m_speed( in_speed )
, m_baseWeight( in_baseWeight )
, m_fadeInDuration( in_fadeInDuration )
, m_fadeOutDuration( in_fadeOutDuration )
{
	return;
}

/**/
VAnimationPlayParam::~VAnimationPlayParam()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VAnimationPlayParam& VAnimationPlayParam::operator=( const VAnimationPlayParam& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_startTime = in_rhs.m_startTime;
		m_speed = in_rhs.m_speed;
		m_baseWeight = in_rhs.m_baseWeight;
		m_fadeInDuration = in_rhs.m_fadeInDuration;
		m_fadeOutDuration = in_rhs.m_fadeOutDuration;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VAnimationPlayParam::operator==( const VAnimationPlayParam& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_startTime == in_rhs.m_startTime );
		match &= ( m_speed == in_rhs.m_speed );
		match &= ( m_baseWeight == in_rhs.m_baseWeight );
		match &= ( m_fadeInDuration == in_rhs.m_fadeInDuration );
		match &= ( m_fadeOutDuration == in_rhs.m_fadeOutDuration );
	}

	return match;
}

/**/
const Hubris::HBOOL VAnimationPlayParam::operator!=( const VAnimationPlayParam& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/