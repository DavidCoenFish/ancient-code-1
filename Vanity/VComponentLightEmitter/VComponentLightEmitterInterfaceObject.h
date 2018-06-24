//file: Vanity/VComponentLightEmitter/VComponentLightEmitterInterfaceObject.h
#ifndef _V_COMPONENT_LIGHT_EMITTER_INTERFACE_OBJECT_H_
#define _V_COMPONENT_LIGHT_EMITTER_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >


namespace Pride
{
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PLight;
	typedef PLight< Hubris::HU8, 3 >PLightRgb;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VComponentLightEmitter;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentLightEmitterInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentLightEmitterInterfaceObject(
			VComponentLightEmitter& in_componentLight,
			VScene& in_scene
			);
		~VComponentLightEmitterInterfaceObject();

		///////////////////////////////////////////////////////
		// public methods
	public:
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

		const Pride::PColourRealRgb& ColourAmbientGet()const;
		Hubris::HVOID ColourAmbientSet( const Pride::PColourRealRgb& in_colourAmbient );

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentLightEmitterInterfaceObject( const VComponentLightEmitterInterfaceObject& in_src );
		const VComponentLightEmitterInterfaceObject& operator=( const VComponentLightEmitterInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentLightEmitter& m_componentLight;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_LIGHT_EMITTER_INTERFACE_OBJECT_H_