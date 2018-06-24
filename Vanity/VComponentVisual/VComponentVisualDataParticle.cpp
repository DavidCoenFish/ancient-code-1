//file: Vanity/VComponentVisual/VComponentVisualDataParticle.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualDataParticle.h"

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

EMEMENTO_FACTORY_SOURCE( VComponentVisualDataParticle, VComponentVisualDataBase );

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< VComponentVisualAssetParticleData >TArrayParticleData;
typedef Hubris::HContainerArray< VComponentVisualAssetParticleTypeData >TArrayTypeData;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayDataVectorR3;
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayDataVectorR2;
typedef Hubris::HContainerArray< Pride::PColourRgba >TArrayDataColour;

///////////////////////////////////////////////////////
// static local methdods
/**/
static HVOID LocalParticDataExtract(
	HVectorR3& out_posTopLeft,
	HVectorR3& out_posTopRight,
	HVectorR3& out_posBottomLeft,
	HVectorR3& out_posBottomRight,
	HVectorR2& out_uvTopLeft,
	HVectorR2& out_uvTopRight,
	HVectorR2& out_uvBottomLeft,
	HVectorR2& out_uvBottomRight,
	PColourRgba& out_colour,
	const VComponentVisualAssetParticleData& in_data,
	const TArrayTypeData& in_arrayTypeData
	)
{
	out_posTopLeft = in_data.PositionGet() + ( ( - in_data.VectorUpGet() - in_data.VectorRightGet() ) * in_data.SizeGet() );
	out_posTopRight = in_data.PositionGet() + ( ( - in_data.VectorUpGet() + in_data.VectorRightGet() ) * in_data.SizeGet() );
	out_posBottomLeft = in_data.PositionGet() + ( ( in_data.VectorUpGet() - in_data.VectorRightGet() ) * in_data.SizeGet() );
	out_posBottomRight = in_data.PositionGet() + ( ( in_data.VectorUpGet() + in_data.VectorRightGet() ) * in_data.SizeGet() );

	const HSINT index = in_data.TypeIndexGet();
	if( ( 0 <= index ) &&
		( index < in_arrayTypeData.SizeGet() ) )
	{
		const VComponentVisualAssetParticleTypeData& typeData = in_arrayTypeData[ index ];
		out_uvTopLeft = typeData.UvTopLeftGet();
		out_uvTopRight = typeData.UvTopRightGet();
		out_uvBottomLeft = typeData.UvBottomLeftGet();
		out_uvBottomRight = typeData.UvBottomRightGet();		
	}

	out_colour = in_data.ColourGet();

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualDataParticle::VComponentVisualDataParticle()
: m_filePath()
, m_pAsset()
, m_arrayData()
, m_pRenderResource()
, m_dataIndexVertex( HCOMMON_INVALID_INDEX )
, m_dataIndexColour( HCOMMON_INVALID_INDEX )
, m_dataIndexUv( HCOMMON_INVALID_INDEX )
, m_topologyVertexIndex( HCOMMON_INVALID_INDEX )
, m_topologyIndexTriangle( HCOMMON_INVALID_INDEX )
, m_geometry()
{
	//set up geometry to be suitable for particles
	PGeometryTypeSignature typeSignature;
	TArraySint arrayDataIndex;
	m_dataIndexVertex = typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetPosition() );
	m_dataIndexColour = typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataColour(), PGeometryTypeSignature::NameGetColour() );
	m_dataIndexUv = typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR2(), PGeometryTypeSignature::NameGetUv() );
	arrayDataIndex.Insert( m_dataIndexVertex );
	arrayDataIndex.Insert( m_dataIndexColour );
	arrayDataIndex.Insert( m_dataIndexUv );

	m_topologyVertexIndex = typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), arrayDataIndex );
	m_topologyIndexTriangle = typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangle(), m_topologyVertexIndex );

	m_geometry.TypeSignatureSet( typeSignature );

	return;
}

/**/
VComponentVisualDataParticle::~VComponentVisualDataParticle()
{
	m_pRenderResource = HNULL;
	return;
}

///////////////////////////////////////////////////////
// implement VComponentVisualDataBase
/**/
Hubris::HVOID VComponentVisualDataParticle::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pAsset = in_sceneApplicationInterface.AssetManagerGet().AssetRequest< VComponentVisualAssetParticle >( 
		in_sceneApplicationInterface,
		m_filePath 
		);

	if( HNULL == m_pAsset )
	{
		return;
	}

	//create render resources
	TArraySint arrayDynamicDataIndex;
	arrayDynamicDataIndex.Insert( m_dataIndexVertex );
	arrayDynamicDataIndex.Insert( m_dataIndexColour );
	arrayDynamicDataIndex.Insert( m_dataIndexUv );

	//dummy up contents of the geometry, for up to max particle worth of data
	m_geometry.Clear();
	PGeometryStoreTriangle& storeTriangle = m_geometry.StoreTopologyTriangleGet( m_topologyIndexTriangle );
	const HSINT maxParticleCount = m_pAsset->MaxCountGet();

	const PGeometryTypeSignature typeSignature = m_geometry.TypeSignatureGet();
	PGeometryVertex vertex( typeSignature, m_topologyVertexIndex );
	PGeometryUtility::DefaultVertex( typeSignature, vertex );
	HSINT arrayVertexIndex[ 4 ];
	for( HSINT index = 0; index < maxParticleCount; ++index )
	{
		arrayVertexIndex[ 0 ] = PGeometryUtility::VertexAdd( typeSignature, m_geometry, vertex );
		arrayVertexIndex[ 1 ] = PGeometryUtility::VertexAdd( typeSignature, m_geometry, vertex );
		arrayVertexIndex[ 2 ] = PGeometryUtility::VertexAdd( typeSignature, m_geometry, vertex );
		arrayVertexIndex[ 3 ] = PGeometryUtility::VertexAdd( typeSignature, m_geometry, vertex );

		storeTriangle.TriangleAdd( 
			arrayVertexIndex[ 0 ],
			arrayVertexIndex[ 1 ],
			arrayVertexIndex[ 2 ]
			);

		storeTriangle.TriangleAdd( 
			arrayVertexIndex[ 1 ],
			arrayVertexIndex[ 3 ],
			arrayVertexIndex[ 2 ]
			);
	}

	// create the render resource
	VComponentVisualComponentRenderResource* pRenderResource = HNULL;
	HCOMMON_NEW_PARAM_3(
		pRenderResource,
		VComponentVisualComponentRenderResource,
		in_sceneApplicationInterface,
		m_geometry,
		arrayDynamicDataIndex
		);
	m_pRenderResource = pRenderResource;

	return;
}

/**/
Hubris::HVOID VComponentVisualDataParticle::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	m_pRenderResource = HNULL;
	m_pAsset = HNULL;
	in_sceneApplicationInterface.AssetManagerGet().AssetReleaseUnused();

	return;
}

/**/
const Hubris::HSINT VComponentVisualDataParticle::RenderLayerGet()const
{
	if( HNULL == m_pAsset )
	{
		return HCOMMON_INVALID_INDEX;
	}

	const HSINT renderLayer = m_pAsset->RenderLayerGet();
	return renderLayer;
}

/**/
Hubris::HVOID VComponentVisualDataParticle::Render( 
	const TItemId in_itemId,
	const Hubris::HSINT in_renderIndex,
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	if( ( HNULL == m_pAsset ) ||
		( HNULL == m_pRenderResource ) )
	{
		return;
	}

	SInterfaceRender* const pRender = in_sceneApplicationInterface.RenderInterfaceGet( in_renderIndex );
	if( HNULL == pRender )
	{
		return;
	}

	//do i have an alpha overide for this frame
	HREAL alphaOverride = 1.0F;
	if( AlphaOverrideFrameIdGet() == in_scene.FrameIDGet() )
	{
		alphaOverride = AlphaOverrideGet();
	}

	VSceneUtility::RenderItemMatrixSet(
		in_itemId,
		in_scene,
		*pRender
		);

	m_pRenderResource->RenderStage(
		*pRender,
		in_renderIndex,
		alphaOverride,
		m_pAsset->MaterialStageGet(),
		SMaterialGeometryStage(
			m_topologyIndexTriangle,
			m_dataIndexVertex,
			m_dataIndexColour,
			HCOMMON_INVALID_INDEX,
			m_dataIndexUv
			)
		);

	return;
}

/**
Hubris::HVOID VComponentVisualDataParticle::AnimationUpdateSubMatrix(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_boneIndex ), 
	const Hubris::HMatrixR4& HCOMMON_UNUSED_VAR( in_matrix )
	)
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentVisualDataParticle::ParticleDataLock(
	Hubris::HSINT& out_maxCount,
	TArrayParticleData*& out_pArrayParticleData
	)
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	out_maxCount = m_pAsset->MaxCountGet();
	out_pArrayParticleData = &m_arrayData;

	return;
}

/**/
Hubris::HVOID VComponentVisualDataParticle::ParticleDataUnlock()
{
	if( ( HNULL == m_pAsset ) ||
		( HNULL == m_pRenderResource ) )
	{
		return;
	}

	const HSINT size = m_arrayData.SizeGet();
	const TArrayTypeData& arrayTypeData = m_pAsset->ArrayTypeDataGet();

	PColourRgba colour;

	HSINT trace = 0;
	TArrayDataVectorR3 arrayDataPos;
	TArrayDataVectorR2 arrayDataUv;
	TArrayDataColour arrayDataColour;

	arrayDataPos.SizeSet( size * 4 );
	arrayDataUv.SizeSet( size * 4 );
	arrayDataColour.SizeSet( size * 4 );

	HCOMMON_FOR_EACH_CONST( data, m_arrayData, TArrayParticleData )
	{
		LocalParticDataExtract(
			arrayDataPos[ trace + 0 ],
			arrayDataPos[ trace + 1 ],
			arrayDataPos[ trace + 2 ],
			arrayDataPos[ trace + 3 ],
			arrayDataUv[ trace + 0 ],
			arrayDataUv[ trace + 1 ],
			arrayDataUv[ trace + 2 ],
			arrayDataUv[ trace + 3 ],
			colour,
			data,
			arrayTypeData
			);

		arrayDataColour[ trace + 0 ] = colour;
		arrayDataColour[ trace + 1 ] = colour;
		arrayDataColour[ trace + 2 ] = colour;
		arrayDataColour[ trace + 3 ] = colour;

		trace += 4;
	}

	m_pRenderResource->UpdateTopology(
		m_topologyIndexTriangle,
		0,
		size * 6
		);

	m_pRenderResource->UpdateData(
		m_dataIndexVertex,
		arrayDataPos.RawGet(),
		0,
		arrayDataPos.SizeGet() * sizeof( HVectorR3 )
		);

	m_pRenderResource->UpdateData(
		m_dataIndexUv,
		arrayDataUv.RawGet(),
		0,
		arrayDataUv.SizeGet() * sizeof( HVectorR2 )
		);

	m_pRenderResource->UpdateData(
		m_dataIndexColour,
		arrayDataColour.RawGet(),
		0,
		arrayDataColour.SizeGet() * sizeof( PColourRgba )
		);

	return;
}

///////////////////////////////////////////////////////
// private methods
/**
Hubris::HVOID VComponentVisualDataParticle::ParticDataToGeometry(
	const PGeometryTypeSignature& in_typeSignature
	)
{
	if( HNULL == m_pAsset )
	{
		return;
	}

	HVectorR3 posTopLeft;
	HVectorR3 posTopRight;
	HVectorR3 posBottomLeft;
	HVectorR3 posBottomRight;
	HVectorR2 uvTopLeft;
	HVectorR2 uvTopRight;
	HVectorR2 uvBottomLeft;
	HVectorR2 uvBottomRight;
	PColourRgba colour;
	const TArrayTypeData& arrayTypeData = m_pAsset->ArrayTypeDataGet();
	HSINT arrayVertexIndex[ 4 ];

	//PGeometryStoreVertexIndex& storeVertexIndex = m_geometry.StoreTopologyVertexIndexGet( m_topologyVertexIndex );
	PGeometryStoreTriangle& storeTriangle = m_geometry.StoreTopologyTriangleGet( m_topologyIndexTriangle );

	PGeometryVertex vertex0( in_typeSignature, m_topologyVertexIndex );
	PGeometryVertex vertex1( in_typeSignature, m_topologyVertexIndex );
	PGeometryVertex vertex2( in_typeSignature, m_topologyVertexIndex );
	PGeometryVertex vertex3( in_typeSignature, m_topologyVertexIndex );

	HCOMMON_FOR_EACH_CONST( data, m_arrayData, TArrayParticleData )
	{
		LocalParticDataExtract(
			posTopLeft,
			posTopRight,
			posBottomLeft,
			posBottomRight,
			uvTopLeft,
			uvTopRight,
			uvBottomLeft,
			uvBottomRight,
			colour,
			data,
			arrayTypeData
			);

		vertex0.VectorR3Set( m_dataIndexVertex, posTopLeft );
		vertex0.VectorR2Set( m_dataIndexUv, uvTopLeft );
		vertex0.ColourRgbaSet( m_dataIndexColour, colour );

		vertex1.VectorR3Set( m_dataIndexVertex, posTopRight );
		vertex1.VectorR2Set( m_dataIndexUv, uvTopRight );
		vertex1.ColourRgbaSet( m_dataIndexColour, colour );

		vertex2.VectorR3Set( m_dataIndexVertex, posBottomLeft );
		vertex2.VectorR2Set( m_dataIndexUv, uvBottomLeft );
		vertex2.ColourRgbaSet( m_dataIndexColour, colour );

		vertex3.VectorR3Set( m_dataIndexVertex, posBottomRight );
		vertex3.VectorR2Set( m_dataIndexUv, uvBottomRight );
		vertex3.ColourRgbaSet( m_dataIndexColour, colour );

		arrayVertexIndex[ 0 ] = PGeometryUtility::VertexAdd( in_typeSignature, m_geometry, vertex0 );
		arrayVertexIndex[ 1 ] = PGeometryUtility::VertexAdd( in_typeSignature, m_geometry, vertex1 );
		arrayVertexIndex[ 2 ] = PGeometryUtility::VertexAdd( in_typeSignature, m_geometry, vertex2 );
		arrayVertexIndex[ 3 ] = PGeometryUtility::VertexAdd( in_typeSignature, m_geometry, vertex3 );

		storeTriangle.TriangleAdd( 
			arrayVertexIndex[ 0 ],
			arrayVertexIndex[ 1 ],
			arrayVertexIndex[ 2 ]
			);

		storeTriangle.TriangleAdd( 
			arrayVertexIndex[ 1 ],
			arrayVertexIndex[ 3 ],
			arrayVertexIndex[ 2 ]
			);
	}

	return;
}

/**/
