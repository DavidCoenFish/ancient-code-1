//file: Lust/LTranslation/LTranslationComponent.cpp

#include "Lust/LustPreCompileHeader.h"
#include "Lust/LTranslation/LTranslationComponent.h"

#include "Lust/LTranslation/LTranslationComponentVelocity.h"

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
LTranslationComponent::LTranslationComponent( const LTranslationComponent& in_src )
: m_translation()
{
	( *this ) = in_src;
	return;
}

/**/
LTranslationComponent::LTranslationComponent(
	const Hubris::HVectorR3& in_translation		
	)
: m_translation( in_translation )
{
	return;
}

/**/
LTranslationComponent::LTranslationComponent()
: m_translation()
{
	return;
}

/**/
LTranslationComponent::~LTranslationComponent()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const LTranslationComponent& LTranslationComponent::operator=( const LTranslationComponent& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_translation = in_rhs.m_translation;
	}

	return( *this );
}

/**/
const Hubris::HBOOL LTranslationComponent::operator==( const LTranslationComponent& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_translation == in_rhs.m_translation );
	}

	return match;
}

/**/
const Hubris::HBOOL LTranslationComponent::operator!=( const LTranslationComponent& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID LTranslationComponent::ApplyVelocity( 
	const LTranslationComponentVelocity& in_velocity,
	const Sloth::SComponentDelta& in_delta
	)
{
	m_translation += ( in_velocity.VelocityGet() * in_delta.LastDeltaGet() );
	//TODO: apply reduction factor
	return;
}

/**/
