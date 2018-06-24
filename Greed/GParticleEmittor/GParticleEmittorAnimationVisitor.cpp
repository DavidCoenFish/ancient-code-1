//file: Greed/GParticleEmittor/GParticleEmittorAnimationVisitor.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GParticleEmittor/GParticleEmittorAnimationVisitor.h"

#include "Greed/GParticleEmittor/GParticleEmittor.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Greed;

///////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
GParticleEmittorAnimationVisitor::GParticleEmittorAnimationVisitor(
	GParticleEmittor& in_out_emittor,
	Vanity::VScene& in_out_scene	
	)
: m_emittor( in_out_emittor )
, m_scene( in_out_scene )
{
	return;
}

/**/
GParticleEmittorAnimationVisitor::~GParticleEmittorAnimationVisitor()
{
	return;
}

///////////////////////////////////////////////////////
// interface
/**/
Hubris::HVOID GParticleEmittorAnimationVisitor::ValueSet(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_animatedValue
	)
{
	m_emittor.AnimationValueSet(
		m_scene,
		in_gameObjectVarId,
		in_animatedValue
		);
	return;
}

/**/
Hubris::HVOID GParticleEmittorAnimationVisitor::ValueSet(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HREAL in_animatedValue
	)
{
	m_emittor.AnimationValueSet(
		m_scene,
		in_gameObjectVarId,
		in_animatedValue
		);
	return;
}

/**/
Hubris::HVOID GParticleEmittorAnimationVisitor::ValueSet(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR2& in_animatedValue
	)
{
	m_emittor.AnimationValueSet(
		m_scene,
		in_gameObjectVarId,
		in_animatedValue
		);
	return;
}

/**/
Hubris::HVOID GParticleEmittorAnimationVisitor::ValueSet(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR3& in_animatedValue
	)
{
	m_emittor.AnimationValueSet(
		m_scene,
		in_gameObjectVarId,
		in_animatedValue
		);
	return;
}

/**/
Hubris::HVOID GParticleEmittorAnimationVisitor::ValueSet(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR4& in_animatedValue
	)
{
	m_emittor.AnimationValueSet(
		m_scene,
		in_gameObjectVarId,
		in_animatedValue
		);
	return;
}

/**/
