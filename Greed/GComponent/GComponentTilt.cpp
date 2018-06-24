//file: Greed/GComponent/GComponentTilt.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GComponent/GComponentTilt.h"

#include< Lust/LSpring/LSpring_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Greed;
using namespace Lust;

///////////////////////////////////////////////////////
// typedef

///////////////////////////////////////////////////////
// creation
/**/
GComponentTilt::GComponentTilt( const GComponentTilt& in_src )
: m_springParam()
, m_radius( 0.0F )
, m_oldTarget()
, m_targetSpringResult()
, m_targetSpringVelocity()
, m_rotation()
, m_dirty( HTRUE )
{
	( *this ) = in_src;
	return;
}

/**/
GComponentTilt::GComponentTilt(
	const Hubris::HVectorR3& in_target,
	const Lust::LSpringParam& in_springParam,
	const Hubris::HREAL in_radius
	)
: m_springParam( in_springParam )
, m_radius( in_radius )
, m_oldTarget()
, m_targetSpringResult()
, m_targetSpringVelocity()
, m_rotation()
, m_dirty( HTRUE )
{
	Update(
		0.0F,
		in_target,
		HTRUE
		);

	return;
}
/**/
GComponentTilt::GComponentTilt()
//debug constuction list
//: m_springParam( 100.0F, 10.0F, 10.0F )
: m_springParam( 50.0F, 7.5F, 10.0F )
, m_radius( 10.0F )
, m_oldTarget()
, m_targetSpringResult()
, m_targetSpringVelocity()
, m_rotation()
, m_dirty( HTRUE )
//: m_springParam()
//, m_radius( 0.0F )
//, m_oldTarget()
//, m_targetSpringResult()
//, m_targetSpringVelocity()
//, m_rotation()
//, m_dirty( HTRUE )
{
	return;
}

/**/
GComponentTilt::~GComponentTilt()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const GComponentTilt& GComponentTilt::operator=( const GComponentTilt& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_springParam = in_rhs.m_springParam;
		m_radius = in_rhs.m_radius;
		m_oldTarget = in_rhs.m_oldTarget;
		m_targetSpringResult = in_rhs.m_targetSpringResult;
		m_targetSpringVelocity = in_rhs.m_targetSpringVelocity;
		m_rotation = in_rhs.m_rotation;
		m_dirty = in_rhs.m_dirty;
	}
	return( *this );
}

/**/
const Hubris::HBOOL GComponentTilt::operator==( const GComponentTilt& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_springParam == in_rhs.m_springParam );
		match &= ( m_radius == in_rhs.m_radius );
		match &= ( m_oldTarget == in_rhs.m_oldTarget );
		match &= ( m_targetSpringResult == in_rhs.m_targetSpringResult );
		match &= ( m_targetSpringVelocity == in_rhs.m_targetSpringVelocity );
		match &= ( m_rotation == in_rhs.m_rotation );
		match &= ( m_dirty == in_rhs.m_dirty );
	}
	return match;
}

/**/
const Hubris::HBOOL GComponentTilt::operator!=( const GComponentTilt& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID GComponentTilt::Update(
	const Hubris::HREAL in_delta,
	const Hubris::HVectorR3& in_target,
	const Hubris::HBOOL in_reset
	)
{
	m_dirty = HTRUE;
	if( HTRUE == in_reset )
	{
		m_oldTarget = in_target;
		m_targetSpringResult = in_target;
		m_targetSpringVelocity = HTraitEmpty< HVectorR3 >::EmptyGet();
		m_rotation = HTraitEmpty< HQuaternionREAL >::EmptyGet();
		//m_oldVelocity = HTraitEmpty< HVectorR3 >::EmptyGet();
		//m_accelleration = HTraitEmpty< HVectorR3 >::EmptyGet();
	}

	//HVectorR3 displacement = m_targetSpringResult - in_target;
	//LSpringUtility::SpringVariablesTick(
	//	displacement,
	//	m_targetSpringVelocity,
	//	displacement,
	//	m_targetSpringVelocity,
	//	in_delta,
	//	m_springParam
	//	);

	//m_targetSpringResult = in_target + displacement;
	//m_oldTarget = in_target;

	// mark 2
	//if( HFALSE == HMathUtility::EpsilonZero( in_delta ) )
	//{
	//	const HREAL invertDelta = 1.0F / in_delta;
	//	const HVectorR3 velocity = ( in_target - m_oldTarget ) * invertDelta;
	//	m_accelleration = ( velocity - m_oldVelocity ) * invertDelta;
	//	m_oldVelocity = velocity;
	//	m_oldTarget = in_target;
	//}

	//HVectorR3 displacement = m_accelleration - m_targetSpringResult;
	//LSpringUtility::SpringVariablesTick(
	//	displacement,
	//	m_targetSpringVelocity,
	//	displacement,
	//	m_targetSpringVelocity,
	//	in_delta,
	//	m_springParam
	//	);
	//m_targetSpringResult = m_accelleration + displacement;

	HVectorR3 offset = in_target - m_oldTarget;
	m_oldTarget = in_target;
	LSpringUtility::SpringVariablesTick(
		m_targetSpringResult,
		m_targetSpringVelocity,
		m_targetSpringResult - offset,
		m_targetSpringVelocity,
		in_delta,
		m_springParam
		);

	////get dispacement relative to new target
	//HVectorR3 offset = in_target - m_oldTarget;
	//m_oldTarget = in_target;
	//LSpringUtility::SpringVariablesTick(
	//	m_targetSpringResult,
	//	m_targetSpringVelocity,
	//	m_targetSpringResult - offset,
	//	m_targetSpringVelocity,
	//	in_delta,
	//	m_springParam
	//	);

	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HQuaternionREAL& GComponentTilt::RotationGet()
{
	if( HTRUE == m_dirty )
	{
		m_dirty = HFALSE;

		const HVectorR3 vector0 = HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, m_radius );
		//const HVectorR3 vector1 = HMatrixConstructor::HVectorR3Construct( m_targetSpringResult[ 0 ] - m_oldTarget[ 0 ], m_targetSpringResult[ 1 ] - m_oldTarget[ 1 ], m_radius );
		const HVectorR3 vector1 = HMatrixConstructor::HVectorR3Construct( m_targetSpringResult[ 0 ], m_targetSpringResult[ 1 ], m_radius );
		m_rotation = HQuaternionUtility::BetweenVectors( vector0, vector1 );
	}

	return m_rotation;
}

/**/
