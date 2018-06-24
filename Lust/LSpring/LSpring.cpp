//file: Lust/LSpring/LSpring.cpp

#include "Lust/LustPreCompileHeader.h"
#include "Lust/LSpring/LSpring.h"

#include "Lust/LSpring/LSpringUtility.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Lust;

////////////////////////////////////////////////////
// static local varaibles
/**/
static const Hubris::HREAL s_variableDefaultDamppen = 0.95F;

////////////////////////////////////////////////////
// template definitions
/**/
template class Lust::LSpring< Hubris::HREAL >;
template class Lust::LSpring< Hubris::HVectorR3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE >
Lust::LSpring< IN_TYPE >::LSpring( const LSpring& in_src )
: m_springParam()
, m_displacement()
, m_velocity()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE >
Lust::LSpring< IN_TYPE >::LSpring(
	const LSpringParam& in_springParam,
	const IN_TYPE& in_displacement,
	const IN_TYPE& in_velocity
	)
: m_springParam( in_springParam )
, m_displacement( in_displacement )
, m_velocity( in_velocity )
{
	return;
}

/**/
template< typename IN_TYPE >
Lust::LSpring< IN_TYPE >::LSpring()
: m_springParam()
, m_displacement()
, m_velocity()
{
	return;
}

/**/
template< typename IN_TYPE >
Lust::LSpring< IN_TYPE >::~LSpring()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE >
const LSpring< IN_TYPE >& Lust::LSpring< IN_TYPE >::operator=( const LSpring& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_springParam = in_rhs.m_springParam;
		m_displacement = in_rhs.m_displacement;
		m_velocity = in_rhs.m_velocity;
	}
	return( *this );
}

/**/
template< typename IN_TYPE >
const Hubris::HBOOL Lust::LSpring< IN_TYPE >::operator==( const LSpring& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_springParam == in_rhs.m_springParam );
		match &= ( m_displacement == in_rhs.m_displacement );
		match &= ( m_velocity == in_rhs.m_velocity );
	}
	return match;
}

/**/
template< typename IN_TYPE >
const Hubris::HBOOL Lust::LSpring< IN_TYPE >::operator!=( const LSpring& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// static public methods
/**/
template< typename IN_TYPE >
const Hubris::HREAL Lust::LSpring< IN_TYPE >::VariableDefaultDamppenGet()
{
	return s_variableDefaultDamppen;
}

///////////////////////////////////////////////////////
// public methods
/**/
template< typename IN_TYPE >
Hubris::HVOID Lust::LSpring< IN_TYPE >::Update(
	const Hubris::HREAL in_timeDelta
	)
{
	const IN_TYPE localDisplacement( m_displacement );
	const IN_TYPE localVelocity( m_velocity );
	LSpringUtility::SpringVariablesTick(
		m_displacement,
		m_velocity,
		localDisplacement,
		localVelocity,
		in_timeDelta,
		m_springParam
		);

	return;
}

/**/