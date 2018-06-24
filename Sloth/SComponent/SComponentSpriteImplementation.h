//file: Sloth/SComponent/SComponentSpriteImplementation.h
#ifndef _S_COMPONENT_SPRITE_IMPLEMENTATION_H_
#define _S_COMPONENT_SPRITE_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Envy/EResourceIdManager/EResourceIdManager_Export.h >
#include "Sloth/SComponent/SComponentSpriteData.h"
#include "Sloth/SComponent/SComponentSpriteInstanceData.h"
#include "Sloth/SMaterial/SMaterialStage.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SMaterialGeometryStage;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentSpriteImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< SComponentSpriteData >TArrayData;
		typedef Hubris::HContainerArray< SComponentSpriteInstanceData >TArrayInstanceData;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerTree< Hubris::HSINT, TArraySint >TTreeSintArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentSpriteImplementation();
		~SComponentSpriteImplementation();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentSpriteImplementation( const SComponentSpriteImplementation& in_src );
		const SComponentSpriteImplementation& operator=( const SComponentSpriteImplementation& in_rhs );

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
			const Hubris::HMatrixR4& in_transform,
			const Hubris::HREAL in_alphaOverride,
			const Hubris::HBOOL in_visible
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
		// private members
	private:
		SMaterialStage m_materialStage;
		TArrayData m_arrayData;
		Envy::EResourceIdManager m_arrayInstanceDataResourceIdManager;
		TArrayInstanceData m_arrayInstanceData;
		//TTreeSintArraySint m_treeRenderList;

	};

	/**/
	
};

#endif // _S_COMPONENT_SPRITE_IMPLEMENTATION_H_