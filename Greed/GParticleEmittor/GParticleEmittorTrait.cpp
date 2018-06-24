//file: Greed/GParticleEmittor/GParticleEmittorTrait.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GParticleEmittor/GParticleEmittorTrait.h"

#include "Greed/GParticleEmittor/GParticleEmittor.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Greed;
using namespace Vanity;

///////////////////////////////////////////////////////
// global template overrides
/*
	GParticleEmittor
*/
Hubris::HVOID Envy::EMementoTraitCollect< GParticleEmittor >( EMementoCollect& in_out_mementoCollect, const Greed::GParticleEmittor& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_stateMachine", in_data.StateMachineGet() );
 	in_out_mementoCollect.MemberAdd( "m_arrayPendingStateName", in_data.ArrayPendingStateNameGet() );
	in_out_mementoCollect.MemberAdd( "m_emittorShape", in_data.EmittorShapeGet() );
	in_out_mementoCollect.MemberAdd( "m_arrayType", in_data.ArrayTypeGet() );
	in_out_mementoCollect.MemberAdd( "m_maximumParticleCount", in_data.MaximumParticleCountGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< GParticleEmittor >( const EMementoAssign& in_out_mementoAssign, Greed::GParticleEmittor& out_data )
{
	in_out_mementoAssign.MemberGet( "m_stateMachine", out_data.StateMachineGet() );
 	in_out_mementoAssign.MemberGet( "m_arrayPendingStateName", out_data.ArrayPendingStateNameGet() );
	in_out_mementoAssign.MemberGet( "m_emittorShape", out_data.EmittorShapeGet() );
	in_out_mementoAssign.MemberGet( "m_arrayType", out_data.ArrayTypeGet() );

	HSINT maximumParticleCount = 0;
	in_out_mementoAssign.MemberGet( "m_maximumParticleCount", maximumParticleCount ); 
	out_data.MaximumParticleCountSet( maximumParticleCount );

	return;
}

/*
	GParticleEmittorState
*/
Hubris::HVOID Envy::EMementoTraitCollect< GParticleEmittorState >( EMementoCollect& in_out_mementoCollect, const Greed::GParticleEmittorState& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_duration", in_data.DurationGet() );
	in_out_mementoCollect.MemberAdd( "m_arrayTypeIndex", in_data.ArrayTypeIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_arrayNextState", in_data.ArrayNextStateGet() );

	if( HTRUE == in_data.AnimationTest() )
	{
		in_out_mementoCollect.MemberAdd( "m_animation", in_data.AnimationGet() );
	}

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< GParticleEmittorState >( const EMementoAssign& in_out_mementoAssign, Greed::GParticleEmittorState& out_data )
{
	HREAL duration = -1.0F;
	in_out_mementoAssign.MemberGet( "m_duration", duration );
	out_data.DurationSet( duration );

	in_out_mementoAssign.MemberGet( "m_arrayTypeIndex", out_data.ArrayTypeIndexGet() );
	in_out_mementoAssign.MemberGet( "m_arrayNextState", out_data.ArrayNextStateGet() );

	VAnimation animation;
	in_out_mementoAssign.MemberGet( "m_animation", animation );
	if( animation != VAnimation() )
	{
		out_data.AnimationSet( HTRUE );
		out_data.AnimationGet() = animation;
	}	
	else
	{
		out_data.AnimationSet( HFALSE );
	}

	return;
}

/*
	GParticleEmittorType
*/
Hubris::HVOID Envy::EMementoTraitCollect< GParticleEmittorType >( EMementoCollect& in_out_mementoCollect, const Greed::GParticleEmittorType& in_data )
{	
	in_out_mementoCollect.MemberAdd( "m_uvType", in_data.UvTypeGet() );
	in_out_mementoCollect.MemberAdd( "m_flowRate", in_data.FlowRateGet() );
	in_out_mementoCollect.MemberAdd( "m_flowRateRand", in_data.FlowRateRandGet() );

	in_out_mementoCollect.MemberAdd( "m_velocity", in_data.VelocityGet() );
	in_out_mementoCollect.MemberAdd( "m_velocityRand", in_data.VelocityRandGet() );

	in_out_mementoCollect.MemberAdd( "m_lifeSpan", in_data.LifeSpanGet() );
	in_out_mementoCollect.MemberAdd( "m_lifeSpanRand", in_data.LifeSpanRandGet() );
	in_out_mementoCollect.MemberAdd( "m_invertMass", in_data.InvertMassGet() );
	in_out_mementoCollect.MemberAdd( "m_invertMassRand", in_data.InvertMassRandGet() );
	in_out_mementoCollect.MemberAdd( "m_size", in_data.SizeGet() );
	in_out_mementoCollect.MemberAdd( "m_sizeRand", in_data.SizeRandGet() );

	in_out_mementoCollect.MemberAdd( "m_forceFlag", in_data.ForceFlagGet() );
	in_out_mementoCollect.MemberAdd( "m_particleFlag", in_data.ParticleFlagGet() );

	in_out_mementoCollect.MemberAdd( "m_colour", in_data.ColourGet() );
	in_out_mementoCollect.MemberAdd( "m_colourRand", in_data.ColourRandGet() );

	if( HTRUE == in_data.AnimationTest() )
	{
		in_out_mementoCollect.MemberAdd( "m_animation", in_data.AnimationGet() );
	}

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< GParticleEmittorType >( const EMementoAssign& in_out_mementoAssign, Greed::GParticleEmittorType& out_data )
{
	Hubris::HSINT uvType = 0;
	in_out_mementoAssign.MemberGet( "m_uvType", uvType );
	out_data.UvTypeSet( uvType );

	Hubris::HREAL flowRate = 0.0F;
	in_out_mementoAssign.MemberGet( "m_flowRate", flowRate );
	out_data.FlowRateSet( flowRate );

	Hubris::HREAL flowRateRand = 0.0F;
	in_out_mementoAssign.MemberGet( "m_flowRateRand", flowRateRand );
	out_data.FlowRateRandSet( flowRateRand );

	in_out_mementoAssign.MemberGet( "m_velocity", out_data.VelocityGet() );
	in_out_mementoAssign.MemberGet( "m_velocityRand", out_data.VelocityRandGet() );

	Hubris::HREAL lifeSpan = 0.0F;
	in_out_mementoAssign.MemberGet( "m_lifeSpan", lifeSpan );
	out_data.LifeSpanSet( lifeSpan );

	Hubris::HREAL lifeSpanRand = 0.0F;
	in_out_mementoAssign.MemberGet( "m_lifeSpanRand", lifeSpanRand );
	out_data.LifeSpanRandSet( lifeSpanRand );

	Hubris::HREAL invertMass = 0.0F;
	in_out_mementoAssign.MemberGet( "m_invertMass", invertMass );
	out_data.InvertMassSet( invertMass );

	Hubris::HREAL invertMassRand = 0.0F;
	in_out_mementoAssign.MemberGet( "m_invertMassRand", invertMassRand );
	out_data.InvertMassRandSet( invertMassRand );

	Hubris::HSINT forceFlag = 0;
	in_out_mementoAssign.MemberGet( "m_forceFlag", forceFlag );
	out_data.ForceFlagSet( forceFlag );

	Hubris::HSINT particleFlag = 0;
	in_out_mementoAssign.MemberGet( "m_particleFlag", particleFlag );
	out_data.ParticleFlagSet( particleFlag );

	Hubris::HREAL size = 0.0F;
	in_out_mementoAssign.MemberGet( "m_size", size );
	out_data.SizeSet( size );

	Hubris::HREAL sizeRand = 0.0F;
	in_out_mementoAssign.MemberGet( "m_sizeRand", sizeRand );
	out_data.SizeRandSet( sizeRand );

	in_out_mementoAssign.MemberGet( "m_colour", out_data.ColourGet() );
	in_out_mementoAssign.MemberGet( "m_colourRand", out_data.ColourRandGet() );

	VAnimation animation;
	in_out_mementoAssign.MemberGet( "m_animation", animation );
	if( animation != VAnimation() )
	{
		out_data.AnimationSet( HTRUE );
		out_data.AnimationGet() = animation;
	}
	else
	{
		out_data.AnimationSet( HFALSE );
	}

	out_data.UpdateStreamIndex();

	return;
}

/**/
