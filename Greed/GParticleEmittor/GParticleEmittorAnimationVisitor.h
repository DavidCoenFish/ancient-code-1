//file: Greed/GParticleEmittor/GParticleEmittorAnimationVisitor.h
#ifndef _G_PARTICLE_EMITTOR_ANIMATION_VISITOR_H_
#define _G_PARTICLE_EMITTOR_ANIMATION_VISITOR_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Greed/GComponent/GComponentAnimationVisitor.h"

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GParticleEmittor;

	///////////////////////////////////////////////////////
	// class
	/*
		data for the current state of an object
	*/
	class GParticleEmittorAnimationVisitor : public GComponentAnimationVisitor
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GParticleEmittorAnimationVisitor(
			GParticleEmittor& in_out_emittor,
			Vanity::VScene& in_out_scene
			);
		~GParticleEmittorAnimationVisitor();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GParticleEmittorAnimationVisitor( const GParticleEmittorAnimationVisitor& in_src );
		const GParticleEmittorAnimationVisitor& operator=( const GParticleEmittorAnimationVisitor& in_rhs );

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HREAL in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR2& in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR3& in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR4& in_animatedValue
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		GParticleEmittor& m_emittor;
		Vanity::VScene& m_scene;
		
	};

	/**/
	
};

#endif // _G_PARTICLE_EMITTOR_ANIMATION_VISITOR_H_