//file: Vanity/VComponentVisual/VComponentVisualComponentRenderResource.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualComponentRenderResource.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualComponentRenderResource::VComponentVisualComponentRenderResource(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Pride::PGeometry& in_geometry,
	const TArraySint& in_arrayDynamicDataIndex	
	)
: m_sceneApplicationInterface( in_sceneApplicationInterface )
, m_arrayObjectHandle()
{
	const HSINT count = m_sceneApplicationInterface.RenderInterfaceCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		SInterfaceRender* const pRenderer = m_sceneApplicationInterface.RenderInterfaceGet( index );
		if( HNULL == pRenderer )
		{
			continue;
		}

		TObjectHandle handle = pRenderer->GeometryCreate( 
			in_geometry,
			in_arrayDynamicDataIndex
			);

		if( HNULL == handle )
		{
			continue;
		}

		if( m_arrayObjectHandle.SizeGet() <= index )
		{
			m_arrayObjectHandle.SizeResize( index + 1 );
		}

		m_arrayObjectHandle[ index ] = handle;
	}

	return;
}

/**/
VComponentVisualComponentRenderResource::~VComponentVisualComponentRenderResource()
{
	return;
}

///////////////////////////////////////////////////////
// public members
/**/
Hubris::HVOID VComponentVisualComponentRenderResource::UpdateTopology(
	const Hubris::HSINT in_topologyIndex,
	const Hubris::HSINT in_offset,
	const Hubris::HSINT in_count
	)
{
	const HSINT count = m_sceneApplicationInterface.RenderInterfaceCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		TObjectHandle handle = ObjectHandleGet( index );
		if( HNULL == handle )
		{
			continue;
		}

		SInterfaceRender* const pRenderer = m_sceneApplicationInterface.RenderInterfaceGet( index );
		if( HNULL == pRenderer )
		{
			continue;
		}

		pRenderer->GeometryUpdateTopology(
			handle,
			in_topologyIndex,
			in_offset,
			in_count
			);
	}
	return;
}

/**/
Hubris::HVOID VComponentVisualComponentRenderResource::UpdateData(
	const Hubris::HSINT in_dataIndex,
	const Hubris::HVOID* const in_pData,
	const Hubris::HSINT in_offset,
	const Hubris::HSINT in_size
	)
{
	const HSINT count = m_sceneApplicationInterface.RenderInterfaceCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		TObjectHandle handle = ObjectHandleGet( index );
		if( HNULL == handle )
		{
			continue;
		}

		SInterfaceRender* const pRenderer = m_sceneApplicationInterface.RenderInterfaceGet( index );
		if( HNULL == pRenderer )
		{
			continue;
		}

		pRenderer->GeometryUpdateData(
			handle,
			in_dataIndex,
			in_pData,
			in_offset,
			in_size
			);
	}

	return;
}

/**/
Hubris::HVOID VComponentVisualComponentRenderResource::Render(
	Sloth::SInterfaceRender& in_renderer,
	const Hubris::HSINT in_renderIndex,
	const Hubris::HREAL in_alphaOverride,
	const Sloth::SMaterial& in_material
	)
{
	const HSINT count = in_material.StageCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		RenderStage( 
			in_renderer,
			in_renderIndex,
			in_alphaOverride,
			in_material.StageMaterialGet( index ),
			in_material.StageGeometryGet( index )
			);
	}
	return;
}

/**/
Hubris::HVOID VComponentVisualComponentRenderResource::RenderStage(
	Sloth::SInterfaceRender& in_renderer,
	const Hubris::HSINT in_renderIndex,
	const Hubris::HREAL in_alphaOverride,
	const Sloth::SMaterialStage& in_materialStage,
	const Sloth::SMaterialGeometryStage& in_geometryStage
	)
{
	const TObjectHandle handle = ObjectHandleGet( in_renderIndex );
	if( HNULL == handle )
	{
		return;
	}

	//adjust the texture matrix
	if( HTRUE == in_materialStage.FlagUseTextureGet() )
	{
		HMatrixR4 textureMatrix;
		m_sceneApplicationInterface.TextureAliasGet().TextureMatrixGet( textureMatrix, in_materialStage.TextureIdGet() );
		in_renderer.TextureTransformSet( textureMatrix );
	}

	in_renderer.MaterialSet(
		in_materialStage,
		in_alphaOverride
		);

	in_renderer.DrawGeometry(
		handle,
		in_geometryStage
		);

	return;
}

///////////////////////////////////////////////////////
// private accessor
/**/
const VComponentVisualComponentRenderResource::TObjectHandle VComponentVisualComponentRenderResource::ObjectHandleGet( const Hubris::HSINT in_renderIndex )const
{
	if( ( in_renderIndex < 0 ) ||
		( m_arrayObjectHandle.SizeGet() <= in_renderIndex ) )
	{
		return HNULL;
	}
	const TObjectHandle handle = m_arrayObjectHandle[ in_renderIndex ];
	return handle;
}

/**/