//file: Vanity/VComponentVisual/VComponentVisualAssetParticleData.h
#ifndef _V_COMPONENT_VISUAL_ASSET_PARTICLE_DATA_H_
#define _V_COMPONENT_VISUAL_ASSET_PARTICLE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentVisualAssetParticleData
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualAssetParticleData( const VComponentVisualAssetParticleData& in_src );
		VComponentVisualAssetParticleData(
			const Hubris::HVectorR3& in_position,
			const Hubris::HVectorR3& in_vectorUp,
			const Hubris::HVectorR3& in_vectorRight,
			const Hubris::HREAL in_size,
			const Pride::PColourRgba& in_colour,
			const Hubris::HSINT in_typeIndex
			);
		VComponentVisualAssetParticleData();
		~VComponentVisualAssetParticleData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentVisualAssetParticleData& operator=( const VComponentVisualAssetParticleData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentVisualAssetParticleData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentVisualAssetParticleData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& PositionGet()const{ return m_position; }
		Hubris::HVOID PositionSet( const Hubris::HVectorR3& in_position ){ m_position = in_position; return; }

		const Hubris::HVectorR3& VectorUpGet()const{ return m_vectorUp; }
		Hubris::HVOID VectorUpSet( const Hubris::HVectorR3& in_vectorUp ){ m_vectorUp = in_vectorUp; return; }

		const Hubris::HVectorR3& VectorRightGet()const{ return m_vectorRight; }
		Hubris::HVOID VectorRightSet( const Hubris::HVectorR3& in_vectorRight ){ m_vectorRight = in_vectorRight; return; }

		const Hubris::HREAL SizeGet()const{ return m_size; }
		Hubris::HVOID SizeSet( const Hubris::HREAL in_size ){ m_size = in_size; return; }

		const Pride::PColourRgba& ColourGet()const{ return m_colour; }
		Hubris::HVOID ColourSet( const Pride::PColourRgba& in_colour ){ m_colour = in_colour; return; }

		const Hubris::HSINT TypeIndexGet()const{ return m_typeIndex; }
		Hubris::HVOID TypeIndexSet( const Hubris::HSINT in_typeIndex ){ m_typeIndex = in_typeIndex; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		//in object space, not world
		Hubris::HVectorR3 m_position;
		Hubris::HVectorR3 m_vectorUp;//y
		Hubris::HVectorR3 m_vectorRight;//x
		Hubris::HREAL m_size;
		Pride::PColourRgba m_colour;
		Hubris::HSINT m_typeIndex;

		Hubris::HSINT m_pad;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_PARTICLE_DATA_H_