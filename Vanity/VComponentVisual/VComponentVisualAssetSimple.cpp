//file: Vanity/VComponentVisual/VComponentVisualAssetSimple.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetSimple.h"

#include "Vanity/VComponentVisual/VComponentVisualComponentRenderResource.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualAssetSimple::VComponentVisualAssetSimple(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HFileSystemPath& in_path			
	)
: m_geometry()
, m_material()
, m_renderLayer( 0 )
, m_pRenderResource()
{
	EMemento memento;

	EMementoUtility::Load(
		in_sceneApplicationInterface.FileSystemGet(),
		in_path,
		memento
		);

	EMementoAssign mementoAssign( memento );
	mementoAssign.MemberGet( "m_geometry", m_geometry );
	mementoAssign.MemberGet( "m_material", m_material );
	mementoAssign.MemberGet( "m_renderLayer", m_renderLayer );

	const HSINT count = m_material.StageCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		if( HFALSE == m_material.StageMaterialGet( index ).FlagUseTextureGet() )
		{
			continue;
		}

		PImageRgba image;
		if( HTRUE == PImageTga::TgaLoadGeneric( 
				in_sceneApplicationInterface.FileSystemGet(),
				m_material.StageMaterialGet( index ).TexturePathGet(),
				image ) )
		{
			const HSINT imageId = in_sceneApplicationInterface.TextureAliasGet().TextureAdd( image );
			m_material.StageMaterialGet( index ).TextureIdSet( imageId );
		}
	}

	// create the render resource
	VComponentVisualComponentRenderResource* pRenderResource = HNULL;
	HCOMMON_NEW_PARAM_3(
		pRenderResource,
		VComponentVisualComponentRenderResource,
		in_sceneApplicationInterface,
		m_geometry,
		TArraySint()
		);
	m_pRenderResource = pRenderResource;

	return;
}

/**/
VComponentVisualAssetSimple::~VComponentVisualAssetSimple()
{
	m_pRenderResource = HNULL;
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentVisualAssetSimple::CreateAsset(
	const Hubris::HFileSystemPath& in_path,
	const Pride::PGeometry& in_geometry,
	const Sloth::SMaterial& in_material,
	const Hubris::HSINT in_renderLayer
	)
{
	HFileSystem fileSystem;
	EMemento memento;

	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "m_geometry", in_geometry );
	mementoCollect.MemberAdd( "m_material", in_material );
	mementoCollect.MemberAdd( "m_renderLayer", in_renderLayer );

	EMementoUtility::SaveText(
		fileSystem,
		in_path,
		memento
		);

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentVisualAssetSimple::Render(
	Sloth::SInterfaceRender& in_renderer,
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface ),
	const Hubris::HSINT in_renderIndex,
	const Hubris::HREAL in_alphaOverride
	)
{
	if( HNULL == m_pRenderResource )
	{
		return;
	}

	m_pRenderResource->Render(
		in_renderer,
		in_renderIndex,
		in_alphaOverride,
		m_material
		);
	return;
}

///////////////////////////////////////////////////////
// public accessors
/**
const VComponentVisualAssetSimple::TObjectHandle VComponentVisualAssetSimple::ObjectHandleGet( const Hubris::HSINT in_renderIndex )
{
	if( ( 0 <= in_renderIndex ) &&
		( in_renderIndex < m_arrayRenderHandle.SizeGet() ) )
	{
		return m_arrayRenderHandle[ in_renderIndex ];
	}
	return HNULL;
}

/**
Hubris::HVOID VComponentVisualAssetSimple::ObjectHandleSet( const Hubris::HSINT in_renderIndex, const TObjectHandle in_objectHandle )
{
	if( in_renderIndex < 0 )
	{
		return;
	}

	if( m_arrayRenderHandle.SizeGet() <= in_renderIndex )
	{
		m_arrayRenderHandle.SizeResize( in_renderIndex + 1 );
	}

	m_arrayRenderHandle[ in_renderIndex ] = in_objectHandle;

	return;
}

/**/
