//file: Greed/GParticleEmittor/GParticleEmittorState.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GParticleEmittor/GParticleEmittorState.h"

#include "Greed/GParticleEmittor/GParticleEmittorStateDataExchange.h"
#include "Greed/GParticleEmittor/GParticleEmittor.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Greed;
using namespace Envy;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< Pride::PUnitVectorR3, Hubris::HREAL >TPairUnitVectorReal;
typedef Hubris::HContainerArray< TPairUnitVectorReal >TArrayPairUnitVectorReal;
typedef Envy::EStateMachineSimple< GParticleEmittorState, GParticleEmittorStateDataExchange >TStateMachine;

///////////////////////////////////////////////////////
// static local methods
/**/
static const HVectorR3 LocalEmittionPointGet(
	const TArrayPairUnitVectorReal& in_arrayEmittorShape,
	const Hubris::HMatrixR4 in_matrixEmittor
	)
{
	HVectorR3 position;
	HCOMMON_FOR_EACH_CONST( pair, in_arrayEmittorShape, TArrayPairUnitVectorReal )
	{
		position += ( pair.m_first.VectorGet() * ( pair.m_second * HMathRandom::RandomRangeOneValueGet() ) );
	}

	position = HMatrixUtility::VectorProduct( in_matrixEmittor, position );
	return position;
}

/**/
static const HBOOL LocalEventEmitParticle(
	GParticleEmittor& in_out_particleEmittor,
	const GParticleEmittorType& in_type,
	const HSINT in_typeIndex,
	const HREAL in_delta,
	const Hubris::HMatrixR4& in_matrixEmittor
	)
{
	//attempt to get a particle id
	const HSINT dataIndex = in_out_particleEmittor.ActiveDataGet().ResourceIdAcquire();
	if( HCOMMON_INVALID_INDEX == dataIndex )
	{
		return HFALSE;
	}

	//get emition point
	const HVectorR3 position = LocalEmittionPointGet(
		in_out_particleEmittor.EmittorShapeGet(),
		in_matrixEmittor
		);

	//get emition velocity
	HVectorR3 velocity = in_type.VelocityGet();
	const HVectorR3& velocityRand = in_type.VelocityRandGet();
	if( HVectorR3() != velocityRand )
	{
		velocity[ 0 ] += HMathRandom::RandomValuePlusMinusGet( velocityRand[ 0 ] );
		velocity[ 1 ] += HMathRandom::RandomValuePlusMinusGet( velocityRand[ 1 ] );
		velocity[ 2 ] += HMathRandom::RandomValuePlusMinusGet( velocityRand[ 2 ] );
	}
	velocity = HMatrixUtility::VectorProductNoTranslate( in_matrixEmittor, velocity );

	//make a particle
	GParticleEmittorData& particleData = in_out_particleEmittor.ArrayDataGet()[ dataIndex ];
	particleData.InitialiseParticle(
		velocity,
		position,
		in_typeIndex,
		in_delta * HMathRandom::RandomRangeOneValueGet(),
		in_type
		);

	return HTRUE;
}

///////////////////////////////////////////////////////
// creation
/**/
GParticleEmittorState::GParticleEmittorState( const GParticleEmittorState& in_src )
: m_duration( -1.0F )
, m_arrayTypeIndex()
, m_arrayNextState()
, m_currentTime( 0.0F )
, m_pAnimation( HNULL )
{
	( *this ) = in_src;
	return;
}

/**/
GParticleEmittorState::GParticleEmittorState()
: m_duration( -1.0F )
, m_arrayTypeIndex()
, m_arrayNextState()
, m_currentTime( 0.0F )
, m_pAnimation( HNULL )
{
	return;
}

/**/
GParticleEmittorState::~GParticleEmittorState()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const GParticleEmittorState& GParticleEmittorState::operator=( const GParticleEmittorState& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_duration = in_rhs.m_duration;
		m_arrayTypeIndex = in_rhs.m_arrayTypeIndex;
		m_arrayNextState = in_rhs.m_arrayNextState;
		m_currentTime = in_rhs.m_currentTime;
		m_pAnimation = HSmartPointerUtility::Copy( in_rhs.m_pAnimation );
	}
	return( *this );
}

/**/
const Hubris::HBOOL GParticleEmittorState::operator==( const GParticleEmittorState& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_duration == in_rhs.m_duration );
		match &= ( m_arrayTypeIndex == in_rhs.m_arrayTypeIndex );
		match &= ( m_arrayNextState == in_rhs.m_arrayNextState );
		match &= ( m_currentTime == in_rhs.m_currentTime );
		match &= ( HTRUE == HSmartPointerUtility::Cmp( m_pAnimation, in_rhs.m_pAnimation ) );
	}
	return match;
}

/**/
const Hubris::HBOOL GParticleEmittorState::operator!=( const GParticleEmittorState& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// implement EStateMachineSimple contract
/**/
HVOID GParticleEmittorState::SubmitEvent(
	GParticleEmittorStateDataExchange& in_out_dataExchange,
	TStateMachine& HCOMMON_UNUSED_VAR( in_out_stateMachine ),
	const HString& HCOMMON_UNUSED_VAR( in_stateName ),
	const HString& in_eventName
	)
{
	in_out_dataExchange;
	if( in_eventName == HString( Envy::EStateMachineSimpleEventNameGetActivate() ) )
	{
		m_currentTime = 0.0F;
	}
	else if( in_eventName == GParticleEmittor::StateSubmitEventNameGetEmit() )
	{
		OnEventEmit(
			in_out_dataExchange
			);
	}
	else if( in_eventName == EStateMachineSimpleEventNameGetActivate() )
	{
	}
	else if( in_eventName == EStateMachineSimpleEventNameGetDeactivate() )
	{
	}

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID GParticleEmittorState::OnEventTick(
	GParticleEmittorStateDataExchange& in_out_dataExchange
	)
{
	if( m_duration < 0.0F )
	{
		return;
	}

	const HREAL delta = in_out_dataExchange.DeltaGet().LastDeltaGet();
	if( ( HTRUE == HMathUtility::EpsilonZero( delta ) ) ||
		( delta < 0.0F ) )
	{
		return;
	}

	m_currentTime += delta;
	if( m_currentTime < m_duration )
	{
		return;
	}

	//deactivate state
	TStateMachine& stateMachine = in_out_dataExchange.ParticleEmittorGet().StateMachineGet();
	const HString stateName = stateMachine.StateNameGet( this );
	stateMachine.StateActiveSet( stateName, HFALSE, in_out_dataExchange );

	//activate next states
	HCOMMON_FOR_EACH_CONST( nextState, m_arrayNextState, TArrayString )
	{
		stateMachine.StateActiveSet( nextState, HTRUE, in_out_dataExchange );
	}

	return;
}

/**/
Hubris::HVOID GParticleEmittorState::OnEventEmit(
	GParticleEmittorStateDataExchange& in_out_dataExchange
	)
{
	const HREAL delta = in_out_dataExchange.DeltaGet().LastDeltaGet();
	if( ( HTRUE == HMathUtility::EpsilonZero( delta ) ) ||
		( delta < 0.0F ) )
	{
		return;
	}

	GParticleEmittor& particleEmittor = in_out_dataExchange.ParticleEmittorGet();
	const HMatrixR4& matrixEmittor = in_out_dataExchange.MatrixEmittorGet();

	HCOMMON_FOR_EACH_CONST( typeIndex, m_arrayTypeIndex, TArraySint )
	{
		const GParticleEmittorType& type = particleEmittor.ArrayTypeGet()[ typeIndex ];

		//test if we emmit
		HREAL flow = ( type.FlowRateGet() + HMathRandom::RandomValuePlusMinusGet( type.FlowRateRandGet() ) ) * delta;

		while( 1.0F < flow )
		{
			if( HFALSE == LocalEventEmitParticle(
				particleEmittor,
				type,
				typeIndex,
				delta,
				matrixEmittor
				) )
			{
				//bail if emit fails
				return;
			}

			flow -= 1.0F;
		}

		if( HMathRandom::RandomRangeOneValueGet() <= flow )
		{
			LocalEventEmitParticle(
				particleEmittor,
				type,
				typeIndex,
				delta,
				matrixEmittor
				);
		}
	}

	return;
}

///////////////////////////////////////////////////////
// public acessors
/**/
const Hubris::HBOOL GParticleEmittorState::AnimationTest()const
{
	return( HNULL != m_pAnimation );
}

/**/
Hubris::HVOID GParticleEmittorState::AnimationSet( const Hubris::HBOOL in_hasAnimation )
{
	if( HTRUE == in_hasAnimation )
	{
		if( HNULL == m_pAnimation )
		{
			m_pAnimation.Create();
		}
	}
	else
	{
		if( HNULL != m_pAnimation )
		{
			m_pAnimation = HNULL;
		}
	}

	return;
}

/**/
const Vanity::VAnimation& GParticleEmittorState::AnimationGet()const
{
	return( m_pAnimation->AnimationGet() );
}

/**/
Vanity::VAnimation& GParticleEmittorState::AnimationGet()
{
	return( m_pAnimation->AnimationGet() );
}

/**/

