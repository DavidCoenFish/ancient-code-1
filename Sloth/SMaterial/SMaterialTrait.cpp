//file: Sloth/SMaterial/SMaterialTrait.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SMaterial/SMaterialTrait.h"

#include "Sloth/SMaterial/SMaterial.h"
#include "Sloth/SMaterial/SMaterialStage.h"
#include "Sloth/SMaterial/SMaterialGeometryStage.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Sloth;

/*
	SMaterial
*/
Hubris::HVOID Envy::EMementoTraitCollect< Sloth::SMaterial >( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterial& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayStageMaterialGeometry", in_data.ArrayStageGeometryGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< Sloth::SMaterial >( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterial& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayStageMaterialGeometry", out_data.ArrayStageGeometryGet() );
	return;
}

/*
	SMaterialStage
*/
Hubris::HVOID Envy::EMementoTraitCollect< Sloth::SMaterialStage >( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterialStage& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_colourAmbient", in_data.m_colourAmbient );
	in_out_mementoCollect.MemberAdd( "m_colourDiffuse", in_data.m_colourDiffuse );
	in_out_mementoCollect.MemberAdd( "m_colourEmission", in_data.m_colourEmission );
	in_out_mementoCollect.MemberAdd( "m_alpha", in_data.m_alpha );
	in_out_mementoCollect.MemberAdd( "m_alphaTestReference", in_data.m_alphaTestReference );
	//in_out_mementoCollect.MemberAdd( "m_textureId", in_data.m_textureId );
	in_out_mementoCollect.MemberAdd( "m_flag", in_data.m_flag );
	in_out_mementoCollect.MemberAdd( "m_texturePath", in_data.m_texturePath );
	//do not scribe the arraytextureId, that is run time resource
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< Sloth::SMaterialStage >( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterialStage& out_data )
{
	in_out_mementoAssign.MemberGet( "m_colourAmbient", out_data.m_colourAmbient );
	in_out_mementoAssign.MemberGet( "m_colourDiffuse", out_data.m_colourDiffuse );
	in_out_mementoAssign.MemberGet( "m_colourEmission", out_data.m_colourEmission );
	in_out_mementoAssign.MemberGet( "m_alpha", out_data.m_alpha );
	in_out_mementoAssign.MemberGet( "m_alphaTestReference", out_data.m_alphaTestReference );
	//in_out_mementoAssign.MemberGet( "m_textureId", out_data.m_textureId );
	in_out_mementoAssign.MemberGet( "m_flag", out_data.m_flag );
	in_out_mementoAssign.MemberGet( "m_texturePath", out_data.m_texturePath );

	return;
}

/*
	SMaterialGeometryStage
*/
Hubris::HVOID Envy::EMementoTraitCollect< Sloth::SMaterialGeometryStage >( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterialGeometryStage& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_topologyIndex", in_data.TopologyIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_positionIndex", in_data.PositionIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_colourIndex", in_data.ColourIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_normalIndex", in_data.NormalIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_textureCoordIndex", in_data.TextureCoordIndexGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< Sloth::SMaterialGeometryStage >( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterialGeometryStage& out_data )
{
	HSINT topologyIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_topologyIndex", topologyIndex );
	out_data.TopologyIndexSet( topologyIndex );

	HSINT positionIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_positionIndex", positionIndex );
	out_data.PositionIndexSet( positionIndex );

	HSINT colourIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_colourIndex", colourIndex );
	out_data.ColourIndexSet( colourIndex );

	HSINT normalIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_normalIndex", normalIndex );
	out_data.NormalIndexSet( normalIndex );

	HSINT textureCoordIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_textureCoordIndex", textureCoordIndex );
	out_data.TextureCoordIndexSet( textureCoordIndex );

	return;
}

/**/