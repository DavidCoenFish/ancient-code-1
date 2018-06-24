//file: Sloth/SLight/SLight.h
#ifndef _S_LIGHT_H_
#define _S_LIGHT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >
#include< Pride/PColour/PColour_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class SLight
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SLight( const SLight& in_src );
		SLight(
			const Hubris::HSINT in_mode,
			const Pride::PColourRealRgb& in_diffuse,
			const Hubris::HVectorR3& in_position,
			//const Hubris::HVectorR3& in_direction, we don't construct with direction as it is optional
			const Hubris::HREAL in_radius,
			const Hubris::HREAL in_falloffExponent = 1.0F
			);
		SLight();
		~SLight();

		///////////////////////////////////////////////////////
		// operators
	public:
		const SLight& operator=( const SLight& in_rhs );
		const Hubris::HBOOL operator==( const SLight& in_rhs )const;
		const Hubris::HBOOL operator!=( const SLight& in_rhs )const;

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT ModePointGet();
		static const Hubris::HSINT ModeDirectGet();
		static const Hubris::HSINT ModeSpotGet();

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL DirectionValidTest()const;

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
		Hubris::HVOID RadiusSet( const Hubris::HREAL in_radius){ m_radius = in_radius; return; }

		//const Hubris::HREAL SpotAngleGet()const{ return m_spotAngle; }
		//Hubris::HVOID SpotAngleSet( const Hubris::HREAL in_spotAngle ){ m_spotAngle = in_spotAngle; return; }

		const Hubris::HVectorR3& PositionGet()const{ return m_position; }
		Hubris::HVOID PositionSet( const Hubris::HVectorR3 in_position ){ m_position = in_position; return; }

		const Hubris::HVectorR3& DirectionGet()const{ return m_direction; }
		Hubris::HVOID DirectionSet( const Hubris::HVectorR3 in_direction ){ m_direction = in_direction; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_mode;
		Pride::PColourRealRgb m_diffuse;
		Hubris::HREAL m_falloffExponent;
		Hubris::HREAL m_radius;
		Hubris::HVectorR3 m_position;
		Hubris::HVectorR3 m_direction;

	};

	/**/
	
};

#endif // _S_LIGHT_H_