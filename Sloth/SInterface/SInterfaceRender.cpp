//file: Sloth/SInterface/SInterfaceRender.cpp
#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SInterface/SInterfaceRender.h"

#include "Sloth/SWindow/SWindowImplementationRenderOpenGl.h"
#include "Sloth/SWindow/SWindowImplementationRenderDirectX.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

////////////////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
SInterfaceRender::SInterfaceRender(
	SWindowImplementationRenderDirectX& in_renderDirectX//,
	//const Hubris::HSINT in_renderId
	)
: m_pRenderDirectX( HNULL )
, m_pRenderOpenGl( HNULL )
//, m_renderId( in_renderId )
{
	m_pRenderDirectX = &in_renderDirectX;
	return;
}

/**/
SInterfaceRender::SInterfaceRender(
	SWindowImplementationRenderOpenGl& in_renderOpenGl//,
	//const Hubris::HSINT in_renderId
	)
: m_pRenderDirectX( HNULL )
, m_pRenderOpenGl( HNULL )
//, m_renderId( in_renderId )
{
	m_pRenderOpenGl = &in_renderOpenGl;
	return;
}

/**/
Hubris::HVOID SInterfaceRender::DeleteThis()
{
	HCOMMON_DELETE_THIS( 
		this,
		SInterfaceRender
		);

	return;
}

/**/
SInterfaceRender::~SInterfaceRender()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SInterfaceRender::Clear( 
	const Hubris::HBOOL in_clearColour,
	const Hubris::HBOOL in_clearDepth,
	const Pride::PColourRealRgba& in_colour,
	const Hubris::HREAL in_depth
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->Clear( 
			in_clearColour,
			in_clearDepth,
			in_colour,
			in_depth
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::CameraSet(
	const Pride::PCamera& in_camera
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->CameraSet( in_camera );
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::ModelTransformSet(
	const Hubris::HMatrixR4& in_matrix
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->ModelTransformSet( 
			in_matrix
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::ModelTransformSet(
	const Hubris::HVectorR3& in_transform
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->ModelTransformSet( 
			in_transform
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::DrawBox(
	const Pride::PBoundsR3& in_bounds
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->DrawBox( 
			in_bounds
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::DrawSphere(
	const Hubris::HREAL in_radius
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->DrawSphere( 
			in_radius
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::DrawTriangle(
	const TArrayReal& in_arrayTriangle
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->DrawTriangle( 
			in_arrayTriangle
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::DrawLine(
	const TArrayReal& in_arrayVector
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->DrawLine( 
			in_arrayVector
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::DrawGeometry(
	const TObjectHandle in_geometryIndex,
	const SMaterialGeometryStage& in_renderStage
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->DrawGeometry( 
			in_geometryIndex,
			in_renderStage
			);
	}

	return;
}

/**/
const SInterfaceRender::TObjectHandle SInterfaceRender::GeometryCreate(
	const Pride::PGeometry& in_geometry,
	const TArraySint& in_arrayDynamicIndex
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		const TObjectHandle id = m_pRenderOpenGl->GeometryCreate( 
			in_geometry,
			in_arrayDynamicIndex
			);
		return id;
	}

	return HNULL;
}

/**/
Hubris::HVOID SInterfaceRender::GeometryUpdateData(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_geometryDataIndex,
	const Hubris::HVOID* const in_pData,
	const Hubris::HSINT in_offset,
	const Hubris::HSINT in_size
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->GeometryUpdateData( 
			in_geometryIndex,
			in_geometryDataIndex,
			in_pData,
			in_offset,
			in_size
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::GeometryUpdateTopology(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_topologyIndex,
	const Hubris::HSINT in_start,
	const Hubris::HSINT in_count
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->GeometryUpdateTopology( 
			in_geometryIndex,
			in_topologyIndex,
			in_start,
			in_count
			);
	}

	return;
}

/*
Hubris::HVOID SInterfaceRender::GeometryUpdate(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_index,
	const Hubris::HVOID* const in_pData,
	const Hubris::HSINT in_size
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->GeometryUpdate( 
			in_geometryIndex,
			in_index,
			in_pData,
			in_size
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::GeometryRelease(
	const TObjectHandle in_geometryIndex
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->GeometryRelease( 
			in_geometryIndex
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::DrawSprite(
	const Hubris::HSINT in_spriteIndex
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->DrawSprite( 
			in_spriteIndex
			);
	}

	return;
}

/**/
const Hubris::HSINT SInterfaceRender::SpriteCreate(
	const Hubris::HVectorR2& in_size,
	const Hubris::HVectorR2& in_topLeftUv,
	const Hubris::HVectorR2& in_bottomRightUv,
	const Pride::PColourRealRgba& in_colour
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		const HSINT index = m_pRenderOpenGl->SpriteCreate( 
			in_size,
			in_topLeftUv,
			in_bottomRightUv,
			in_colour
			);

		return index;
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
Hubris::HVOID SInterfaceRender::SpriteRelease(
	const Hubris::HSINT in_spriteIndex
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->SpriteRelease( 
			in_spriteIndex
			);
	}

	return;
}

/**/
const Hubris::HBOOL SInterfaceRender::ShaderCreate(
	const Hubris::HString& in_shaderName,
	const SMaterialStageShader& in_shader
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		const HBOOL result = m_pRenderOpenGl->ShaderCreate(
			in_shaderName,
			in_shader
			);
		return result;
	}

	return HFALSE;
}

/**/
Hubris::HVOID SInterfaceRender::ShaderRelease(
	const Hubris::HString& in_shaderName
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->ShaderRelease(
			in_shaderName
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::ShaderReleaseAll()
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->ShaderReleaseAll();
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::MaterialSet(
	const SMaterialStage& in_materialStage,
	const Hubris::HREAL in_alphaOverride
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->MaterialSet(
			in_materialStage,
			in_alphaOverride
			);
	}

	return;
}

/**/
const Hubris::HSINT SInterfaceRender::LightCountMaxGet()
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		return m_pRenderOpenGl->LightCountMaxGet();
	}

	return 0;
}

/**/
Hubris::HVOID SInterfaceRender::LightSet(
	const TArrayLight& in_arrayLight,
	const Pride::PColourRealRgb& in_globalAmbient
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->LightSet( 
			in_arrayLight,
			in_globalAmbient
			);
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::FogActiveSet(
	const Hubris::HBOOL in_active
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->FogActiveSet( in_active );
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::FogSet(
	const Hubris::HSINT in_mode,
	const Pride::PColourRealRgba& in_colour,
	const Hubris::HREAL in_amount,
	const Hubris::HREAL in_near,
	const Hubris::HREAL in_far
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->FogSet( 
			in_mode,
			in_colour,
			in_amount,
			in_near,
			in_far
			);
	}

	return;
}

/**/
const Hubris::HSINT SInterfaceRender::TextureSizeMaxGet()
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		return m_pRenderOpenGl->TextureSizeMaxGet();
	}

	return 0;
}

/**/
Hubris::HVOID SInterfaceRender::TextureSet(
	const Hubris::HSINT in_mipMapLevel,
	const Pride::PImageRgba& in_image
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->TextureSet( in_mipMapLevel, in_image );
	}

	return;
}

/**/
Hubris::HVOID SInterfaceRender::TextureTransformSet(
	const Hubris::HMatrixR4& in_transform
	)
{
	if( HNULL != m_pRenderDirectX )
	{
		HCOMMON_ASSERT_ALWAYS( "TODO" );
	}
	else
	{
		m_pRenderOpenGl->TextureTransformSet( 
			in_transform 
			);
	}

	return;
}

/**/
