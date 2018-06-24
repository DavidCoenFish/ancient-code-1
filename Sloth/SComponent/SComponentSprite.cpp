//file: Sloth/SComponent/SComponentSprite.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentSprite.h"

#include "Sloth/SComponent/SComponentSpriteImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentSprite::SComponentSprite()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, SComponentSpriteImplementation );
	return;
}

/**/
SComponentSprite::~SComponentSprite()
{
	HCOMMON_DELETE( m_pImplementation, SComponentSpriteImplementation );
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentSprite::MaterialStageSet( 
	const SMaterialStage& in_materialStage
	)
{
	ImplementationGet().MaterialStageSet(
		in_materialStage 
		);
	return;
}

/**/
Hubris::HVOID SComponentSprite::SpriteAdd( 
	const Hubris::HSINT in_spriteIndex, 
	const Pride::PGeometry& in_geometry,
	const SMaterialGeometryStage& in_materialGeometryStage
	)
{
	ImplementationGet().SpriteAdd(
		in_spriteIndex, 
		in_geometry,
		in_materialGeometryStage
		);
	return;
}

/**/
const Hubris::HSINT SComponentSprite::SpriteInstanceCreate(
	const Hubris::HSINT in_spriteIndex, 
	//const Hubris::HSINT in_renderSortHint, 
	const Hubris::HMatrixR4& in_transform,
	const Hubris::HREAL in_alphaOverride,
	const Hubris::HBOOL in_visible
	)
{
	const HSINT index = ImplementationGet().SpriteInstanceCreate(
		in_spriteIndex, 
		in_transform,
		in_alphaOverride,
		in_visible
		);
	return index;
}

/**/
Hubris::HVOID SComponentSprite::SpriteInstanceChangeTransform(
	const Hubris::HSINT in_spriteInstanceIndex, 
	const Hubris::HMatrixR4& in_transform
	)
{
	ImplementationGet().SpriteInstanceChangeTransform(
		in_spriteInstanceIndex, 
		in_transform 
		);
	return;
}

/**/
Hubris::HVOID SComponentSprite::SpriteInstanceChangeSpriteIndex(
	const Hubris::HSINT in_spriteInstanceIndex, 
	const Hubris::HSINT in_spriteIndex
	)
{
	ImplementationGet().SpriteInstanceChangeSpriteIndex(
		in_spriteInstanceIndex, 
		in_spriteIndex 
		);
	return;
}

/**/
//Hubris::HVOID SpriteInstanceChangeRenderSortHint(
//	const Hubris::HSINT in_spriteInstanceIndex, 
//	const Hubris::HSINT in_renderSortHint
//	)
/**/
Hubris::HVOID SComponentSprite::SpriteInstanceChangeAlphaOverride(
	const Hubris::HSINT in_spriteInstanceIndex, 
	const Hubris::HREAL in_alphaOverride
	)
{
	ImplementationGet().SpriteInstanceChangeAlphaOverride(
		in_spriteInstanceIndex, 
		in_alphaOverride 
		);
	return;
}

/**/
Hubris::HVOID SComponentSprite::SpriteInstanceRemove(
	const Hubris::HSINT in_spriteInstanceIndex
	)
{
	ImplementationGet().SpriteInstanceRemove(
		in_spriteInstanceIndex 
		);
	return;
}

/**/
Hubris::HVOID SComponentSprite::SpriteInstanceRemoveAll()
{
	ImplementationGet().SpriteInstanceRemoveAll();
	return;
}

/**/
Hubris::HVOID SComponentSprite::ResourceAquire( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)
{
	ImplementationGet().ResourceAquire(
		in_out_interfaceRender, 
		in_renderIndex 
		);
	return;
}

/**/
Hubris::HVOID SComponentSprite::ResourceRelease( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)
{
	ImplementationGet().ResourceRelease(
		in_out_interfaceRender, 
		in_renderIndex 
		);
	return;
}

/**/
Hubris::HVOID SComponentSprite::Render( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)const
{
	ImplementationGet().Render(
		in_out_interfaceRender, 
		in_renderIndex 
		);
	return;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SComponentSpriteImplementation& SComponentSprite::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
SComponentSpriteImplementation& SComponentSprite::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
