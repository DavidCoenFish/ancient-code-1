//file: Vanity/VComponentLightEmitter/VComponentLightEmitter.h
#ifndef _V_COMPONENT_LIGHT_EMITTER_H_
#define _V_COMPONENT_LIGHT_EMITTER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentLightEmitter/VComponentLightEmitterItemData.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentLightEmitter;

};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//VScene
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightEmitter& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightEmitter& out_data );
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	struct VComponentLightEmitterRenderParam;
	class VComponentLightEmitterCamera;
	class VInterfaceRenderTarget;
	class VImageHDR;
	class VComponentLightEmitterItemData;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentLightEmitter
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VComponentLightEmitter >( Envy::EMementoCollect& in_out_mementoCollect, const VComponentLightEmitter& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VComponentLightEmitter >( const Envy::EMementoAssign& in_out_mementoAssign, VComponentLightEmitter& out_data );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< VComponentLightEmitterItemData >TArrayItemData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentLightEmitter();
		~VComponentLightEmitter();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentLightEmitter( const VComponentLightEmitter& in_src );
		const VComponentLightEmitter& operator=( const VComponentLightEmitter& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const TItemId in_itemId 
			);

		Hubris::HVOID OnRemoveItem(
			const TItemId in_itemId 
			);

		Hubris::HVOID LightGet(
			const TItemId in_itemId,
			Hubris::HSINT& out_mode,
			Pride::PColourRealRgb& out_diffuse,
			Hubris::HREAL& out_falloffExponent,
			Hubris::HREAL& out_radius
			)const;

		Hubris::HVOID LightSet( 
			const TItemId in_itemId,
			const Hubris::HSINT in_mode,
			const Pride::PColourRealRgb& in_diffuse,
			const Hubris::HREAL in_falloffExponent,
			const Hubris::HREAL in_radius
			);


		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PColourRealRgb& ColourAmbientGet()const{ return m_colourAmbient; }
		Hubris::HVOID ColourAmbientSet( const Pride::PColourRealRgb& in_colourAmbient ){ m_colourAmbient = in_colourAmbient; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayItemData m_arrayItemData;
		Pride::PColourRealRgb m_colourAmbient;

	};

	/**/
	
};

#endif // _V_COMPONENT_LIGHT_EMITTER_H_