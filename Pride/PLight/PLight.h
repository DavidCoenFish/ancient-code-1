//file: Pride/PLight/PLight.h
#ifndef _P_LIGHT_H_
#define _P_LIGHT_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PColour/PColour_Export.h"

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PLight;
	//see cpp for instanciation
	typedef PLight< Hubris::HU8, 1 >PLightMono;
	typedef PLight< Hubris::HU8, 3 >PLightRgb;
	typedef PLight< Hubris::HU8, 4 >PLightRgba;
	typedef PLight< Hubris::HREAL, 1 >PLightRealMono;
	typedef PLight< Hubris::HREAL, 3 >PLightRealRgb;
	typedef PLight< Hubris::HREAL, 4 >PLightRealRgba;

	///////////////////////////////////////////////////////
	// class
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PLight
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef PColour< IN_TYPE, IN_CHANNEL_COUNT > TColour;

		///////////////////////////////////////////////////////
		// creation
	public:
		PLight( const PLight& in_src );
		PLight(
			const Hubris::HBOOL in_active,
			const Hubris::HSINT in_type,
			const Hubris::HREAL in_strength,
			const Hubris::HREAL in_radius,
			const TColour& in_ambient,
			const TColour& in_diffuse,
			const TColour& in_specular,
			const Hubris::HREAL in_exponent,
			const Hubris::HREAL in_spotAngle,
			const Hubris::HREAL in_spotExponent,
			const Hubris::HSINT in_shadowFlag,
			const Hubris::HSINT in_shadowQuality
			);
		PLight();
		~PLight();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PLight& operator=( const PLight& in_rhs );
		const Hubris::HBOOL operator==( const PLight& in_rhs )const;
		const Hubris::HBOOL operator!=( const PLight& in_rhs )const;

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT TypeAmbientGet();
		static const Hubris::HSINT TypePointGet();
		static const Hubris::HSINT TypeDirectGet();
		static const Hubris::HSINT TypeSpotGet();

		static const Hubris::HSINT ShadowFlagNoneGet();
		static const Hubris::HSINT ShadowFlagMapGet();

		static const Hubris::HSINT ShadowQualityLowGet();
		static const Hubris::HSINT ShadowQualityMediumGet();
		static const Hubris::HSINT ShadowQualityHighGet();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HBOOL ActiveGet()const{ return m_active; }
		Hubris::HVOID ActiveSet( const Hubris::HBOOL in_active ){ m_active = in_active; return; }

		const Hubris::HSINT TypeGet()const{ return m_type; }
		Hubris::HVOID TypeSet( const Hubris::HSINT in_type ){ m_type = in_type; return; }

		const Hubris::HREAL StrengthGet()const{ return m_strength; }
		Hubris::HVOID StrengthSet( const Hubris::HREAL in_strength ){ m_strength = in_strength; return; }

		const Hubris::HREAL RadiusGet()const{ return m_radius; }
		Hubris::HVOID RadiusSet( const Hubris::HREAL in_radius ){ m_radius = in_radius; return; }

		const TColour& AmbientGet()const{ return m_ambient; }
		Hubris::HVOID AmbientSet( const TColour& in_ambient ){ m_ambient = in_ambient; return; }

		const TColour& DiffuseGet()const{ return m_diffuse; }
		Hubris::HVOID DiffuseSet( const TColour& in_diffuse ){ m_diffuse = in_diffuse; return; }

		const TColour& SpecularGet()const{ return m_specular; }
		Hubris::HVOID SpecularSet( const TColour& in_specular ){ m_specular = in_specular; return; }

		const Hubris::HREAL ExponentGet()const{ return m_exponent; }
		Hubris::HVOID ExponentSet( const Hubris::HREAL in_exponent ){ m_exponent = in_exponent; return; }

		const Hubris::HREAL SpotAngleGet()const{ return m_spotAngle; }
		Hubris::HVOID SpotAngleSet( const Hubris::HREAL in_spotAngle ){ m_spotAngle = in_spotAngle; return; }

		const Hubris::HREAL SpotExponentGet()const{ return m_spotExponent; }
		Hubris::HVOID SpotExponentSet( const Hubris::HREAL in_spotExponent ){ m_spotExponent = in_spotExponent; return; }

		const Hubris::HSINT ShadowFlagGet()const{ return m_shadowFlag; }
		Hubris::HVOID ShadowFlagSet( const Hubris::HSINT in_shadowFlag ){ m_shadowFlag = in_shadowFlag; return; }

		const Hubris::HSINT ShadowQualityGet()const{ return m_shadowQuality; }
		Hubris::HVOID ShadowQualitySet( const Hubris::HSINT in_shadowQuality ){ m_shadowQuality = in_shadowQuality; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HBOOL m_active;
		Hubris::HSINT m_type;
		Hubris::HREAL m_strength;
		Hubris::HREAL m_radius;
		TColour m_ambient;
		TColour m_diffuse;
		TColour m_specular;
		Hubris::HREAL m_exponent;
		Hubris::HREAL m_spotAngle;
		Hubris::HREAL m_spotExponent;
		Hubris::HSINT m_shadowFlag;
		Hubris::HSINT m_shadowQuality;

	};

	/**/
	
};

#endif // _P_LIGHT_H_