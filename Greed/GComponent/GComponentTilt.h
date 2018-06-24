//file: Greed/GComponent/GComponentTilt.h
#ifndef _G_COMPONENT_TILT_H_
#define _G_COMPONENT_TILT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Lust/LSpring/LSpring.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		
	*/
	class GComponentTilt
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentTilt( const GComponentTilt& in_src );
		GComponentTilt(
			const Hubris::HVectorR3& in_target,
			const Lust::LSpringParam& in_springParam,
			const Hubris::HREAL in_radius = 1.0F
			);
		GComponentTilt();
		~GComponentTilt();

		///////////////////////////////////////////////////////
		// operator
	public:
		const GComponentTilt& operator=( const GComponentTilt& in_rhs );
		const Hubris::HBOOL operator==( const GComponentTilt& in_rhs )const;
		const Hubris::HBOOL operator!=( const GComponentTilt& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Update(
			const Hubris::HREAL in_delta,
			const Hubris::HVectorR3& in_target,
			const Hubris::HBOOL in_reset = HFALSE
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HQuaternionREAL& RotationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		Lust::LSpringParam m_springParam;
		Hubris::HREAL m_radius;
		Hubris::HVectorR3 m_oldTarget;
		//Hubris::HVectorR3 m_oldVelocity;
		//Hubris::HVectorR3 m_accelleration;

		Hubris::HVectorR3 m_targetSpringResult; //local space relative to in_target
		Hubris::HVectorR3 m_targetSpringVelocity;
		Hubris::HQuaternionREAL m_rotation;
		Hubris::HBOOL m_dirty; //has rotation been generated for this update

	};

	/**/
	
};

#endif // _G_COMPONENT_TILT_H_