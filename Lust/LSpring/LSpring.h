//file: Lust/LSpring/LSpring.h
#ifndef _L_SPRING_H_
#define _L_SPRING_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Lust/LSpring/LSpringParam.h"

namespace Lust
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE >class LSpring;
	typedef LSpring< Hubris::HREAL >LSpringReal; //instanciated in cpp
	typedef LSpring< Hubris::HVectorR3 >LSpringR3; //instanciated in cpp

	///////////////////////////////////////////////////////
	// class
	/*
	TODO:
		Doh, should spring be in lust, yes (at least, not in Pride?)

		generic spring, based on F = kd
		where F is force, k is the spring constant, and d is distance
		spring owns a displacement and velocity

		on update, displacement has spring force and velocity applied, limited by maxDistance and dampen factor

		rather than have dampen as a constant rasied to the power of the time delta, which is multiplied with velocity to limit it
		have dampen factor multi with timedelta to lerp velocity to zero //avoiding exponent

	*/
	template< typename IN_TYPE >
	class LSpring
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		LSpring( const LSpring& in_src );
		LSpring(
			const LSpringParam& in_springParam,
			const IN_TYPE& in_displacement,
			const IN_TYPE& in_velocity
			);
		LSpring();
		~LSpring();

		///////////////////////////////////////////////////////
		// operators
	public:
		const LSpring& operator=( const LSpring& in_rhs );
		const Hubris::HBOOL operator==( const LSpring& in_rhs )const;
		const Hubris::HBOOL operator!=( const LSpring& in_rhs )const;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//return a default dampen constant
		static const Hubris::HREAL VariableDefaultDamppenGet();

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Update(
			const Hubris::HREAL in_timeDelta
			//const Hubris::HREAL in_timeExponentDamppen //a dampen constant rasied to the power of the time delta
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const LSpringParam& SpringParamGet()const{ return m_springParam; }
		LSpringParam& SpringParamGet(){ return m_springParam; }

		const IN_TYPE& DisplacementGet()const{ return m_displacement; }
		IN_TYPE& DisplacementGet(){ return m_displacement; }

		const IN_TYPE& VelocityGet()const{ return m_velocity; }
		IN_TYPE& VelocityGet(){ return m_velocity; }

		///////////////////////////////////////////////////////
		// private members
	private:
		LSpringParam m_springParam;
		IN_TYPE m_displacement;
		IN_TYPE m_velocity;

	};

	/**/
	
};

#endif // _L_SPRING_H_