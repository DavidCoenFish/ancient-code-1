//file: Greed/GParticleEmittor/GParticleEmittorStateDataExchange.h
#ifndef _G_PARTICLE_EMITTOR_STATE_DATA_EXCHANGE_H_
#define _G_PARTICLE_EMITTOR_STATE_DATA_EXCHANGE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	class SComponentDelta;
};

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GParticleEmittor;

	///////////////////////////////////////////////////////
	// class
	/**/
	class GParticleEmittorStateDataExchange 
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GParticleEmittorStateDataExchange(
			GParticleEmittor& in_out_particleEmittor,
			const Sloth::SComponentDelta& in_delta,
			const Hubris::HMatrixR4& in_matrixEmittor
			);
		~GParticleEmittorStateDataExchange();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GParticleEmittorStateDataExchange( const GParticleEmittorStateDataExchange& in_src );
		const GParticleEmittorStateDataExchange& operator=( const GParticleEmittorStateDataExchange& in_rhs );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const GParticleEmittor& ParticleEmittorGet()const{ return m_particleEmittor; }
		GParticleEmittor& ParticleEmittorGet(){ return m_particleEmittor; }

		const Sloth::SComponentDelta& DeltaGet()const{ return m_delta; }
		const Hubris::HMatrixR4& MatrixEmittorGet()const{ return m_matrixEmittor; }

		///////////////////////////////////////////////////////
		// members
	private:
		GParticleEmittor& m_particleEmittor;
		const Sloth::SComponentDelta& m_delta;
		const Hubris::HMatrixR4& m_matrixEmittor;

	};

	/**/
	
};

#endif // _G_PARTICLE_EMITTOR_STATE_DATA_EXCHANGE_H_