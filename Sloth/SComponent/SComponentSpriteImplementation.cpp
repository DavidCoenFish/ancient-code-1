//file: Sloth/SComponent/SComponentSpriteImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentSpriteImplementation.h"

#include "Sloth/SInterface/SInterface_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentSpriteImplementation::SComponentSpriteImplementation()
: m_materialStage()
, m_arrayData()
, m_arrayInstanceDataResourceIdManager()
, m_arrayInstanceData()
{
	return;
}

/**/
SComponentSpriteImplementation::~SComponentSpriteImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentSpriteImplementation::MaterialStageSet( 
	const SMaterialStage& in_materialStage
	)
{
	m_materialStage = in_materialStage;
	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::SpriteAdd( 
	const Hubris::HSINT in_spriteIndex, 
	const Pride::PGeometry& in_geometry,
	const SMaterialGeometryStage& in_materialGeometryStage
	)
{
	if( m_arrayData.SizeGet() <= in_spriteIndex )
	{
		m_arrayData.SizeResize( in_spriteIndex + 1 );
	}

	SComponentSpriteData& data = m_arrayData[ in_spriteIndex ];
	data.GeometrySet( in_geometry );
	data.MaterialGeometryStageSet( in_materialGeometryStage );

	return;
}

/**/
const Hubris::HSINT SComponentSpriteImplementation::SpriteInstanceCreate(
	const Hubris::HSINT in_spriteIndex, 
	const Hubris::HMatrixR4& in_transform,
	const Hubris::HREAL in_alphaOverride,
	const Hubris::HBOOL in_visible
	)	
{
	const HSINT resourceId = m_arrayInstanceDataResourceIdManager.ResourceIdAcquire();

	if( m_arrayInstanceData.SizeGet() <= resourceId )
	{
		m_arrayInstanceData.SizeResize( resourceId + 1 );
	}

	m_arrayInstanceData[ resourceId ] = SComponentSpriteInstanceData(
		in_spriteIndex,
		in_alphaOverride,
		in_transform,
		in_visible
		);

	return resourceId;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::SpriteInstanceChangeTransform(
	const Hubris::HSINT in_spriteInstanceIndex, 
	const Hubris::HMatrixR4& in_transform
	)
{
	HCOMMON_ASSERT( ( 0 <= in_spriteInstanceIndex ) && ( in_spriteInstanceIndex < m_arrayInstanceData.SizeGet() ), "invalid param" );
	m_arrayInstanceData[ in_spriteInstanceIndex ].MatrixGet() = in_transform;

	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::SpriteInstanceChangeSpriteIndex(
	const Hubris::HSINT in_spriteInstanceIndex, 
	const Hubris::HSINT in_spriteIndex
	)
{
	HCOMMON_ASSERT( ( 0 <= in_spriteInstanceIndex ) && ( in_spriteInstanceIndex < m_arrayInstanceData.SizeGet() ), "invalid param" );
	m_arrayInstanceData[ in_spriteInstanceIndex ].SpriteIndexSet( in_spriteIndex );

	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::SpriteInstanceChangeAlphaOverride(
	const Hubris::HSINT in_spriteInstanceIndex, 
	const Hubris::HREAL in_alphaOverride
	)
{
	HCOMMON_ASSERT( ( 0 <= in_spriteInstanceIndex ) && ( in_spriteInstanceIndex < m_arrayInstanceData.SizeGet() ), "invalid param" );
	m_arrayInstanceData[ in_spriteInstanceIndex ].AlphaOverrideSet( in_alphaOverride );

	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::SpriteInstanceRemove(
	const Hubris::HSINT in_spriteInstanceIndex
	)
{
	HCOMMON_ASSERT( ( 0 <= in_spriteInstanceIndex ) && ( in_spriteInstanceIndex < m_arrayInstanceData.SizeGet() ), "invalid param" );
	m_arrayInstanceData[ in_spriteInstanceIndex ].VisibleSet( HFALSE );
	m_arrayInstanceDataResourceIdManager.ResourceIdRelease( in_spriteInstanceIndex );

	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::SpriteInstanceRemoveAll()
{
//	for( HSINT index = 0; index < m_arrayInstanceData.SizeGet(); ++index )
//	{
//		SComponentSpriteInstanceData& instanceData = m_arrayInstanceData[ index ];
	HCOMMON_FOR_EACH( instanceData, m_arrayInstanceData, TArrayInstanceData )
	{
		if( HTRUE == instanceData.VisibleGet() )
		{
			instanceData.VisibleSet( HFALSE );
		}
	}
	m_arrayInstanceDataResourceIdManager.Clear();

	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::ResourceAquire( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)
{
	HCOMMON_FOR_EACH( data, m_arrayData, TArrayData )
	{
		data.ResourceAquire( 
			in_out_interfaceRender,
			in_renderIndex
			);
	}

	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::ResourceRelease( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)
{
	HCOMMON_FOR_EACH( data, m_arrayData, TArrayData )
	{
		data.ResourceRelease( 
			in_out_interfaceRender,
			in_renderIndex
			);
	}

	return;
}

/**/
Hubris::HVOID SComponentSpriteImplementation::Render( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)const
{
	SMaterialGeometryStage materialGeometryStage;
	HCOMMON_FOR_EACH_CONST( instanceData, m_arrayInstanceData, TArrayInstanceData )
	{
		if( HFALSE == instanceData.VisibleGet() )
		{
			continue;
		}

		const HSINT spriteIndex = instanceData.SpriteIndexGet();
		if( HCOMMON_INVALID_INDEX == spriteIndex )
		{
			continue;
		}

		const SComponentSpriteData& data = m_arrayData[ spriteIndex ];
		if( HFALSE == data.RenderValid( in_renderIndex ) )
		{
			continue;
		}

		in_out_interfaceRender.ModelTransformSet( instanceData.MatrixGet() );
		in_out_interfaceRender.MaterialSet(
			m_materialStage,
			instanceData.AlphaOverrideGet()
			);

		data.Render(
			in_out_interfaceRender,
			in_renderIndex
			);
	}

	return;

}

/**/