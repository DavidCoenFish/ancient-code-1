//file: Greed/GParticleEmittor/GParticleEmittorData.h
#ifndef _G_PARTICLE_EMITTOR_DATA_H_
#define _G_PARTICLE_EMITTOR_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Lust/LTranslation/LTranslation_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GParticleEmittorType;

	///////////////////////////////////////////////////////
	// class
	/*
		data for the current state of a particle
	*/
	class GParticleEmittorData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		GParticleEmittorData( const GParticleEmittorData& in_src );
		GParticleEmittorData();
		~GParticleEmittorData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const GParticleEmittorData& operator=( const GParticleEmittorData& in_rhs );
		const Hubris::HBOOL operator==( const GParticleEmittorData& in_rhs )const;
		const Hubris::HBOOL operator!=( const GParticleEmittorData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public acessors
	public:
		Hubris::HVOID InitialiseParticle(
			const Hubris::HVectorR3& in_velocity,
			const Hubris::HVectorR3& in_position,
			const Hubris::HSINT in_particleType,
			const Hubris::HREAL in_particleAge,
			const GParticleEmittorType& in_typeData
			);

		//return true if still active
		const Hubris::HBOOL Tick(
			const Sloth::SComponentDelta& in_delta
			);

		//const Hubris::HBOOL ActiveGet()const;
		Hubris::HVOID DeactiveSet();

		Hubris::HVOID UpdatePosition(
			Vanity::VScene& in_out_scene,
			const Sloth::SComponentDelta& in_delta,
			const GParticleEmittorType& in_particleType,
			const Hubris::HVectorR3& in_cameraVectorUp,
			const Hubris::HVectorR3& in_cameraVectorRight
			);

		Hubris::HVOID WriteOutValues(
			Vanity::VComponentVisualAssetParticleData& out_data,
			const GParticleEmittorType& in_typeData,
			const Hubris::HMatrixR4& in_modelMatrixInvert
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT ParticleTypeGet()const{ return m_particleType; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Lust::LTranslationComponentVelocity m_translationComponentVelocity;
		Lust::LTranslationComponent m_translationComponent;
		Hubris::HREAL m_massInvert;
		Hubris::HREAL m_size;
		Pride::PColourRgba m_colour;
		Hubris::HREAL m_particleLifespan;
		Hubris::HREAL m_particleAge; //current time
		Hubris::HSINT m_particleType;

		//local data
		Hubris::HSINT m_flag;
		Hubris::HVectorR3 m_up;
		Hubris::HVectorR3 m_right;

		//animation variables
		Hubris::HSINT m_colourIndexHint;
		Hubris::HSINT m_sizeIndexHint;

	};

	/**/
	
};

#endif // _G_PARTICLE_EMITTOR_DATA_H_