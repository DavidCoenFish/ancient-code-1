//file: Vanity/VComponentVisual/VComponentVisualDataSimple.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualDataSimple.h"

#include "Vanity/VComponentVisual/VComponentVisualTrait.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentVisualDataSimple, VComponentVisualDataBase );

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualDataSimple::VComponentVisualDataSimple()
: m_filePath()
, m_pAsset()
{
	return;
}

/**/
VComponentVisualDataSimple::~VComponentVisualDataSimple()
{
	return;
}

///////////////////////////////////////////////////////
// implement VComponentVisualDataBase
/**/
Hubris::HVOID VComponentVisualDataSimple::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pAsset = in_sceneApplicationInterface.AssetManagerGet().AssetRequest< VComponentVisualAssetSimple >( 
		in_sceneApplicationInterface,
		m_filePath
		);

	return;
}

/**/
Hubris::HVOID VComponentVisualDataSimple::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pAsset = HNULL;
	in_sceneApplicationInterface.AssetManagerGet().AssetReleaseUnused();

	return;
}

/**
Hubris::HVOID VComponentVisualDataSimple::RenderDataAcquire(
	Sloth::SInterfaceRender& in_out_interfaceRender
	)
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	const HSINT renderIndex = in_out_interfaceRender.RenderIdGet();
	if( HNULL != m_pAsset->ObjectHandleGet( renderIndex ) )
	{
		return;
	}

	TObjectHandle handle = in_out_interfaceRender.GeometryCreate( m_pAsset->GeometryGet(), TArraySint() );
	m_pAsset->ObjectHandleSet( renderIndex, handle );

	return;
}

/**
Hubris::HVOID VComponentVisualDataSimple::RenderDataRelease(
	Sloth::SInterfaceRender& in_out_interfaceRender
	)
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	const HSINT renderIndex = in_out_interfaceRender.RenderIdGet();
	TObjectHandle objectHandle = m_pAsset->ObjectHandleGet( renderIndex );
	in_out_interfaceRender.GeometryRelease( objectHandle );

	m_pAsset->ObjectHandleSet( renderIndex, HNULL );

	return;
}


/**/
const Hubris::HSINT VComponentVisualDataSimple::RenderLayerGet()const
{
	if( HNULL == m_pAsset )
	{
		return HCOMMON_INVALID_INDEX;
	}

	const HSINT renderLayer = m_pAsset->RenderLayerGet();
	return renderLayer;
}

/**/
Hubris::HVOID VComponentVisualDataSimple::Render( 
	const TItemId in_itemId,
	const Hubris::HSINT in_renderIndex,
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	SInterfaceRender* const pRender = in_sceneApplicationInterface.RenderInterfaceGet( in_renderIndex );
	if( HNULL == pRender )
	{
		return;
	}

	VSceneUtility::RenderItemMatrixSet(
		in_itemId,
		in_scene,
		*pRender
		);

	//do i have an alpha overide for this frame
	HREAL alphaOverride = 1.0F;
	if( AlphaOverrideFrameIdGet() == in_scene.FrameIDGet() )
	{
		alphaOverride = AlphaOverrideGet();
	}

	m_pAsset->Render(
		*pRender,
		in_sceneApplicationInterface,
		in_renderIndex,
		alphaOverride
		);

	return;
}

/**
Hubris::HVOID VComponentVisualDataSimple::AnimationUpdateSubMatrix(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_boneIndex ), 
	const Hubris::HMatrixR4& HCOMMON_UNUSED_VAR( in_matrix )
	)
{
	return;
}

/**/
