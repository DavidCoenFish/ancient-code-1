//file: Sloth/SMaterial/SMaterialGeometryStage.h
#ifndef _S_MATERIAL_GEOMETRY_STAGE_H_
#define _S_MATERIAL_GEOMETRY_STAGE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// class
	/**/
	class SMaterialGeometryStage
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SMaterialGeometryStage( const SMaterialGeometryStage& in_src );
		SMaterialGeometryStage(
			const Hubris::HSINT in_topologyIndex = HCOMMON_INVALID_INDEX,
			const Hubris::HSINT in_positionIndex = HCOMMON_INVALID_INDEX,
			const Hubris::HSINT in_colourIndex = HCOMMON_INVALID_INDEX,
			const Hubris::HSINT in_normalIndex = HCOMMON_INVALID_INDEX,
			const Hubris::HSINT in_textureCoordIndex = HCOMMON_INVALID_INDEX
			);
		~SMaterialGeometryStage();

		///////////////////////////////////////////////////////
		// operators
	public:
		const SMaterialGeometryStage& operator=( const SMaterialGeometryStage& in_rhs );
		Hubris::HBOOL operator==( const SMaterialGeometryStage& in_rhs )const;
		Hubris::HBOOL operator!=( const SMaterialGeometryStage& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT TopologyIndexGet()const{ return m_topologyIndex; }
		Hubris::HVOID TopologyIndexSet( const Hubris::HSINT in_topologyIndex ){ m_topologyIndex = in_topologyIndex; return; }

		const Hubris::HSINT PositionIndexGet()const{ return m_positionIndex; }
		Hubris::HVOID PositionIndexSet( const Hubris::HSINT in_positionIndex ){ m_positionIndex = in_positionIndex; return; }

		const Hubris::HSINT ColourIndexGet()const{ return m_colourIndex; }
		Hubris::HVOID ColourIndexSet( const Hubris::HSINT in_colourIndex ){ m_colourIndex = in_colourIndex; return; }

		const Hubris::HSINT NormalIndexGet()const{ return m_normalIndex; }
		Hubris::HVOID NormalIndexSet( const Hubris::HSINT in_normalIndex ){ m_normalIndex = in_normalIndex; return; }

		const Hubris::HSINT TextureCoordIndexGet()const{ return m_textureCoordIndex; }
		Hubris::HVOID TextureCoordIndexSet( const Hubris::HSINT in_textureCoordIndex ){ m_textureCoordIndex = in_textureCoordIndex; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_topologyIndex;
		Hubris::HSINT m_positionIndex;
		Hubris::HSINT m_colourIndex;
		Hubris::HSINT m_normalIndex;
		Hubris::HSINT m_textureCoordIndex;

	};

	/**/
	
};

#endif // _S_MATERIAL_GEOMETRY_STAGE_H_