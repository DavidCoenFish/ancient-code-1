//file: Lust/LTranslation/LTranslationComponentVelocity.cpp

#include "Lust/LustPreCompileHeader.h"
#include "Lust/LTranslation/LTranslationComponentVelocity.h"

#include "Lust/LTranslation/LTranslationComponentForceSum.h"

#include< Sloth/SComponent/SComponentDelta.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Lust;

///////////////////////////////////////////////////////
// typedef

///////////////////////////////////////////////////////
// creation
/**/
LTranslationComponentVelocity::LTranslationComponentVelocity( const LTranslationComponentVelocity& in_src )
: m_velocity()
{
	( *this ) = in_src;
	return;
}

/**/
LTranslationComponentVelocity::LTranslationComponentVelocity()
: m_velocity()
{
	return;
}

/**/
LTranslationComponentVelocity::~LTranslationComponentVelocity()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const LTranslationComponentVelocity& LTranslationComponentVelocity::operator=( const LTranslationComponentVelocity& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_velocity = in_rhs.m_velocity;
	}

	return( *this );
}

/**/
const Hubris::HBOOL LTranslationComponentVelocity::operator==( const LTranslationComponentVelocity& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_velocity == in_rhs.m_velocity );
	}

	return match;
}

/**/
const Hubris::HBOOL LTranslationComponentVelocity::operator!=( const LTranslationComponentVelocity& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}


///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID LTranslationComponentVelocity::ApplyForceSum( 
	const LTranslationComponentForceSum& in_forceSum,
	const Sloth::SComponentDelta& in_delta,
	const Hubris::HREAL in_massInvert
	)
{
	m_velocity += ( in_forceSum.ForceSumGet() * in_massInvert * in_delta.LastDeltaGet() );
	//TODO: apply reduction factor
	return;
}

/**/
