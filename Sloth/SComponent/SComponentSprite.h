//file: Sloth/SComponent/SComponentSprite.h
#ifndef _S_COMPONENT_SPRITE_H_
#define _S_COMPONENT_SPRITE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	class PGeometry;
};

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SMaterialStage;
	class SInterfaceRender;
	class SComponentSpriteImplementation;
	class SMaterialGeometryStage;

	///////////////////////////////////////////////////////
	// class
	/*
		doh, sprite manager could have been better name 
	*/
	class SComponentSprite
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentSprite();
		~SComponentSprite();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentSprite( const SComponentSprite& in_src );
		const SComponentSprite& operator=( const SComponentSprite& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID MaterialStageSet( 
			const SMaterialStage& in_materialStage
			);

		Hubris::HVOID SpriteAdd( 
			const Hubris::HSINT in_spriteIndex, 
			const Pride::PGeometry& in_geometry,
			const SMaterialGeometryStage& in_materialGeometryStage
			);

		const Hubris::HSINT SpriteInstanceCreate(
			const Hubris::HSINT in_spriteIndex, 
			//const Hubris::HSINT in_renderSortHint, 
			const Hubris::HMatrixR4& in_transform,
			const Hubris::HREAL in_alphaOverride = 1.0F,
			const Hubris::HBOOL in_visible = HTRUE
			);

		Hubris::HVOID SpriteInstanceChangeTransform(
			const Hubris::HSINT in_spriteInstanceIndex, 
			const Hubris::HMatrixR4& in_transform
			);

		Hubris::HVOID SpriteInstanceChangeSpriteIndex(
			const Hubris::HSINT in_spriteInstanceIndex, 
			const Hubris::HSINT in_spriteIndex
			);

		//Hubris::HVOID SpriteInstanceChangeRenderSortHint(
		//	const Hubris::HSINT in_spriteInstanceIndex, 
		//	const Hubris::HSINT in_renderSortHint
		//	);

		Hubris::HVOID SpriteInstanceChangeAlphaOverride(
			const Hubris::HSINT in_spriteInstanceIndex, 
			const Hubris::HREAL in_alphaOverride
			);

		Hubris::HVOID SpriteInstanceRemove(
			const Hubris::HSINT in_spriteInstanceIndex
			);

		Hubris::HVOID SpriteInstanceRemoveAll();

		Hubris::HVOID ResourceAquire( 
			SInterfaceRender& in_out_interfaceRender, 
			const Hubris::HSINT in_renderIndex 
			);

		Hubris::HVOID ResourceRelease( 
			SInterfaceRender& in_out_interfaceRender, 
			const Hubris::HSINT in_renderIndex 
			);

		Hubris::HVOID Render( 
			SInterfaceRender& in_out_interfaceRender, 
			const Hubris::HSINT in_renderIndex 
			)const;

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SComponentSpriteImplementation& ImplementationGet()const;
		SComponentSpriteImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SComponentSpriteImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_COMPONENT_SPRITE_H_