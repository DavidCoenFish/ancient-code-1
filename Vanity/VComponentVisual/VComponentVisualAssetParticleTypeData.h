//file: Vanity/VComponentVisual/VComponentVisualAssetParticleTypeData.h
#ifndef _V_COMPONENT_VISUAL_ASSET_PARTICLE_TYPE_DATA_H_
#define _V_COMPONENT_VISUAL_ASSET_PARTICLE_TYPE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;

	///////////////////////////////////////////////////////
	// class
	/*
		TODO: remove this class and replace by HContainerArrayStatic< HVectorR2, 4 >
	*/
	class VComponentVisualAssetParticleTypeData
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualAssetParticleTypeData( const VComponentVisualAssetParticleTypeData& in_src );
		VComponentVisualAssetParticleTypeData(
			const Hubris::HVectorR2& in_uvTopLeft,
			const Hubris::HVectorR2& in_uvTopRight,
			const Hubris::HVectorR2& in_uvBottomLeft,
			const Hubris::HVectorR2& in_uvBottomRight
			);
		VComponentVisualAssetParticleTypeData();
		~VComponentVisualAssetParticleTypeData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentVisualAssetParticleTypeData& operator=( const VComponentVisualAssetParticleTypeData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentVisualAssetParticleTypeData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentVisualAssetParticleTypeData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR2& UvTopLeftGet()const{ return m_uvTopLeft; }
		Hubris::HVectorR2& UvTopLeftGet(){ return m_uvTopLeft; }

		const Hubris::HVectorR2& UvTopRightGet()const{ return m_uvTopRight; }
		Hubris::HVectorR2& UvTopRightGet(){ return m_uvTopRight; }

		const Hubris::HVectorR2& UvBottomLeftGet()const{ return m_uvBottomLeft; }
		Hubris::HVectorR2& UvBottomLeftGet(){ return m_uvBottomLeft; }

		const Hubris::HVectorR2& UvBottomRightGet()const{ return m_uvBottomRight; }
		Hubris::HVectorR2& UvBottomRightGet(){ return m_uvBottomRight; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorR2 m_uvTopLeft;
		Hubris::HVectorR2 m_uvTopRight;
		Hubris::HVectorR2 m_uvBottomLeft;
		Hubris::HVectorR2 m_uvBottomRight;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_PARTICLE_TYPE_DATA_H_