//file: Vanity/VComponentLightEmitter/VComponentLightEmitterItemData.h
#ifndef _V_COMPONENT_LIGHT_EMITTER_ITEM_DATA_H_
#define _V_COMPONENT_LIGHT_EMITTER_ITEM_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Pride/PLight/PLight_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentLightEmitterItemData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentLightEmitterItemData( const VComponentLightEmitterItemData& in_src );
		VComponentLightEmitterItemData();
		~VComponentLightEmitterItemData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VComponentLightEmitterItemData& operator=( const VComponentLightEmitterItemData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentLightEmitterItemData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentLightEmitterItemData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT ModeGet()const{ return m_mode; }
		Hubris::HVOID ModeSet( const Hubris::HSINT in_mode ){ m_mode = in_mode; return; }

		const Pride::PColourRealRgb& DiffuseGet()const{ return m_diffuse; }
		Hubris::HVOID DiffuseSet( const Pride::PColourRealRgb& in_diffuse ){ m_diffuse = in_diffuse; return; }

		const Hubris::HREAL FalloffExponentGet()const{ return m_falloffExponent; }
		Hubris::HVOID FalloffExponentSet( const Hubris::HREAL in_falloffExponent ){ m_falloffExponent = in_falloffExponent; return; }

		const Hubris::HREAL RadiusGet()const{ return m_radius; }
		Hubris::HVOID RadiusSet( const Hubris::HREAL in_radius ){ m_radius = in_radius; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_mode;
		Pride::PColourRealRgb m_diffuse;
		Hubris::HREAL m_falloffExponent;
		Hubris::HREAL m_radius;

	};

	/**/
	
};

#endif // _V_COMPONENT_LIGHT_EMITTER_H_