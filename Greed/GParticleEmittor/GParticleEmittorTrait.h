//file: Greed/GParticleEmittor/GParticleEmittorTrait.h
#ifndef _G_PARTICLE_EMITTOR_TRAIT_H_
#define _G_PARTICLE_EMITTOR_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GParticleEmittor;
	class GParticleEmittorState;
	class GParticleEmittorType;

};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//GParticleEmittor
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Greed::GParticleEmittor& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Greed::GParticleEmittor& out_data );

	//GParticleEmittorState
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Greed::GParticleEmittorState& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Greed::GParticleEmittorState& out_data );

	//GParticleEmittorType
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Greed::GParticleEmittorType& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Greed::GParticleEmittorType& out_data );

};

#endif // _G_PARTICLE_EMITTOR_TRAIT_H_