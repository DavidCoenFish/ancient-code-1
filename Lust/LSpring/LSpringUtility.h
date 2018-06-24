//file: Lust/LSpring/LSpringUtility.h
#ifndef _L_SPRING_UTILITY_H_
#define _L_SPRING_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Lust
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class LSpringParam;

	///////////////////////////////////////////////////////
	// struct
	/*
		utility for performing spring
		in_displacement if the offset from spring target (ie, these functions assume that the target is at 0.0 )
		in_velocity is the current velocity of the spring

	*/
	struct LSpringUtility
	{
		///////////////////////////////////////////////////////
		// disabled
	private:
		~LSpringUtility();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID SpringVariablesTick(
			Hubris::HREAL& out_displacement,
			Hubris::HREAL& out_velocity,
			const Hubris::HREAL in_displacement, //distance from spring zero
			const Hubris::HREAL in_velocity,
			const Hubris::HREAL in_timeDelta,
			const LSpringParam& in_springParam
			);

		static Hubris::HVOID SpringVariablesTick(
			Hubris::HVectorR3& out_displacement,
			Hubris::HVectorR3& out_velocity,
			const Hubris::HVectorR3& in_displacement,
			const Hubris::HVectorR3& in_velocity,
			const Hubris::HREAL in_timeDelta,
			const LSpringParam& in_springParam
			);

	};

	/**/
	
};

#endif // _L_SPRING_UTILITY_H__