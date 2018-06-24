//file: Sloth/SComponent/SComponentSpriteData.h
#ifndef _S_COMPONENT_SPRITE_DATA_H_
#define _S_COMPONENT_SPRITE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SMaterial/SMaterialGeometryStage.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInterfaceRender;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentSpriteData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVOID* >TArrayHandle;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentSpriteData( const SComponentSpriteData& in_src );
		SComponentSpriteData();
		~SComponentSpriteData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const SComponentSpriteData& operator=( const SComponentSpriteData& in_rhs );
		const Hubris::HBOOL operator==( const SComponentSpriteData& in_rhs )const;
		const Hubris::HBOOL operator!=( const SComponentSpriteData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID ResourceAquire( 
			SInterfaceRender& in_out_interfaceRender, 
			const Hubris::HSINT in_renderIndex 
			);

		Hubris::HVOID ResourceRelease( 
			SInterfaceRender& in_out_interfaceRender, 
			const Hubris::HSINT in_renderIndex 
			);

		//pop up render so can bail on invalid geometryId earlier
		// or expose isValid
		const Hubris::HBOOL RenderValid( 
			const Hubris::HSINT in_renderIndex 
			)const;

		Hubris::HVOID Render( 
			SInterfaceRender& in_out_interfaceRender, 
			const Hubris::HSINT in_renderIndex 
			)const;

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID* const RenderGeometryIdGet(
			const Hubris::HSINT in_renderIndex 
			)const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HVOID GeometrySet( const Pride::PGeometry& in_geometry ){ m_geometry = in_geometry; return; }

		Hubris::HVOID MaterialGeometryStageSet( const SMaterialGeometryStage& in_materialGeometryStage ){ m_materialGeometryStage = in_materialGeometryStage; return; }
		//const SMaterialGeometryStage& MaterialGeometryStageGet()const{ return m_materialGeometryStage; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PGeometry m_geometry;
		SMaterialGeometryStage m_materialGeometryStage;
		TArrayHandle m_arrayRenderResource;

	};

	/**/
	
};

#endif // _S_COMPONENT_SPRITE_DATA_H_