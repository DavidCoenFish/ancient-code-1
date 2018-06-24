//file: Greed/GParticleEmittor/GParticleEmittorType.h
#ifndef _G_PARTICLE_EMITTOR_TYPE_H_
#define _G_PARTICLE_EMITTOR_TYPE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	class VAnimation;
};

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class GParticleEmittorType
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< Vanity::VAnimationReference >TAnimationPointer;

		///////////////////////////////////////////////////////
		// creation
	public:
		GParticleEmittorType( const GParticleEmittorType& in_src );
		GParticleEmittorType();
		~GParticleEmittorType();

		///////////////////////////////////////////////////////
		// operator
	public:
		const GParticleEmittorType& operator=( const GParticleEmittorType& in_rhs );
		const Hubris::HBOOL operator==( const GParticleEmittorType& in_rhs )const;
		const Hubris::HBOOL operator!=( const GParticleEmittorType& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID UpdateStreamIndex();

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const Hubris::HBOOL AnimationTest()const;
		//set if we have animation
		Hubris::HVOID AnimationSet( const Hubris::HBOOL in_hasAnimation );
		const Vanity::VAnimation& AnimationGet()const;
		Vanity::VAnimation& AnimationGet();

		const Hubris::HSINT UvTypeGet()const{ return m_uvType; }
		Hubris::HVOID UvTypeSet( const Hubris::HSINT in_uvType ){ m_uvType = in_uvType; return; }

		const Hubris::HREAL FlowRateGet()const{ return m_flowRate; }
		Hubris::HVOID FlowRateSet( const Hubris::HREAL in_flowRate ){ m_flowRate = in_flowRate; return; }

		const Hubris::HREAL FlowRateRandGet()const{ return m_flowRateRand; }
		Hubris::HVOID FlowRateRandSet( const Hubris::HREAL in_flowRateRand ){ m_flowRateRand = in_flowRateRand; return; }

		const Hubris::HVectorR3& VelocityGet()const{ return m_velocity; }
		Hubris::HVectorR3& VelocityGet(){ return m_velocity; }

		const Hubris::HVectorR3& VelocityRandGet()const{ return m_velocityRand; }
		Hubris::HVectorR3& VelocityRandGet(){ return m_velocityRand; }

		const Hubris::HREAL LifeSpanGet()const{ return m_lifeSpan; }
		Hubris::HVOID LifeSpanSet( const Hubris::HREAL in_lifeSpan ){ m_lifeSpan = in_lifeSpan; return; }

		const Hubris::HREAL LifeSpanRandGet()const{ return m_lifeSpanRand; }
		Hubris::HVOID LifeSpanRandSet( const Hubris::HREAL in_lifeSpanRand ){ m_lifeSpanRand = in_lifeSpanRand; return; }

		const Hubris::HREAL InvertMassGet()const{ return m_invertMass; }
		Hubris::HVOID InvertMassSet( const Hubris::HREAL in_invertMass ){ m_invertMass = in_invertMass; return; }

		const Hubris::HREAL InvertMassRandGet()const{ return m_invertMassRand; }
		Hubris::HVOID InvertMassRandSet( const Hubris::HREAL in_invertMassRand ){ m_invertMassRand = in_invertMassRand; return; }

		const Hubris::HREAL SizeGet()const{ return m_size; }
		Hubris::HVOID SizeSet( const Hubris::HREAL in_size ){ m_size = in_size; return; }

		const Hubris::HREAL SizeRandGet()const{ return m_sizeRand; }
		Hubris::HVOID SizeRandSet( const Hubris::HREAL in_sizeRand ){ m_sizeRand = in_sizeRand; return; }

		const Hubris::HSINT ForceFlagGet()const{ return m_forceFlag; }
		Hubris::HVOID ForceFlagSet( const Hubris::HSINT in_forceFlag ){ m_forceFlag = in_forceFlag; return; }

		const Hubris::HSINT ParticleFlagGet()const{ return m_particleFlag; }
		Hubris::HVOID ParticleFlagSet( const Hubris::HSINT in_particleFlag ){ m_particleFlag = in_particleFlag; return; }

		const Pride::PColourRgba& ColourGet()const{ return m_colour; }
		Pride::PColourRgba& ColourGet(){ return m_colour; }

		const Pride::PColourRgba& ColourRandGet()const{ return m_colourRand; }
		Pride::PColourRgba& ColourRandGet(){ return m_colourRand; }

		const Hubris::HSINT ColourStreamIndexGet()const{ return m_colourStreamIndex; }
		const Hubris::HSINT SizeStreamIndexGet()const{ return m_sizeStreamIndex; }

		///////////////////////////////////////////////////////
		// static public acessors
	public:
		static const Hubris::HSINT ParticleFlagCollisionBounceGet();
		static const Hubris::HSINT ParticleFlagCollisionSplatGet();
		static const Hubris::HSINT ParticleFlagBillboardGet();
		static const Hubris::HSINT ParticleFlagBillboardTreeGet();
		static const Hubris::HSINT ParticleFlagMaskCollisionGet();
		static const Hubris::HSINT ParticleFlagMaskBillboardGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		//var for particel data creation time
		Hubris::HSINT m_uvType;
		Hubris::HREAL m_flowRate;
		Hubris::HREAL m_flowRateRand;
		Hubris::HVectorR3 m_velocity;
		Hubris::HVectorR3 m_velocityRand;
		Hubris::HREAL m_lifeSpan;
		Hubris::HREAL m_lifeSpanRand;
		Hubris::HREAL m_invertMass;
		Hubris::HREAL m_invertMassRand;
		Hubris::HSINT m_forceFlag; //flag of what forces particle is subject to, gravity, wind, magnetic, magic
		Hubris::HSINT m_particleFlag; //bounce or splat on collision, billboard

		//var for particle lifetime animation
		Hubris::HREAL m_size;
		Hubris::HREAL m_sizeRand;
		Pride::PColourRgba m_colour;
		Pride::PColourRgba m_colourRand;

		//animation for partice type data
		TAnimationPointer m_pAnimation;

		//animation variables
		Hubris::HSINT m_colourStreamIndex;
		Hubris::HSINT m_sizeStreamIndex;

	};

	/**/
	
};

#endif // _G_PARTICLE_EMITTOR_TYPE_H_