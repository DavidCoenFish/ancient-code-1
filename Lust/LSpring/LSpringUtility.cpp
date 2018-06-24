//file: Lust/LSpring/LSpringUtility.cpp

#include "Lust/LustPreCompileHeader.h"
#include "Lust/LSpring/LSpringUtility.h"

#include "Lust/LSpring/LSpringParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Lust;

///////////////////////////////////////////////////////
// local static methods
/**/
static const Hubris::HREAL LocalDampenGet(
	const Hubris::HREAL in_delta,
	const Hubris::HREAL in_dampen
	)
{
	const HREAL result = HMathUtility::Clamp( in_dampen * in_delta, 0.0F, 1.0F );
	return result;
	//return in_dampen;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID LSpringUtility::SpringVariablesTick(
	Hubris::HREAL& out_displacement,
	Hubris::HREAL& out_velocity,
	const Hubris::HREAL in_displacement,
	const Hubris::HREAL in_velocity,
	const Hubris::HREAL in_timeDelta,
	const LSpringParam& in_springParam
	)
{
	const HREAL localDisplacement( in_displacement ); //allow for &out_displacement == &in_displacement
	const HREAL tempVelocity = in_velocity - ( in_timeDelta * in_springParam.SpringConstantGet() * in_displacement );
	HREAL newDisplacement = in_displacement + ( in_timeDelta * tempVelocity );

	//dampen the spring occilation
	const HREAL dampen = LocalDampenGet( in_springParam.SpringDamppenConstantGet(), in_timeDelta );
	if( HTRUE == HMathUtility::EpsilonZeroNot( dampen ) )
	{
		newDisplacement = HMathUtility::Lerp( newDisplacement, 0.0F, dampen );
	}

	//clamp the output displacement
	const HREAL springMaximumDisplacement = in_springParam.SpringMaximumDistanceGet();
	out_displacement = HMathUtility::Clamp( newDisplacement, -springMaximumDisplacement, springMaximumDisplacement );

	//adjust velocity for effect of clamp (not just accel on old velocity, tempVelocity)
	if( HTRUE == HMathUtility::EpsilonZeroNot( in_timeDelta ) )
	{
		out_velocity = ( out_displacement - localDisplacement ) / in_timeDelta;
	}

	//dampen velocity
	if( HTRUE == HMathUtility::EpsilonZeroNot( dampen ) )
	{
		out_velocity = HMathUtility::Lerp( out_velocity, 0.0F, dampen );
	}

	return;
}

/**/
Hubris::HVOID LSpringUtility::SpringVariablesTick(
	Hubris::HVectorR3& out_displacement,
	Hubris::HVectorR3& out_velocity,
	const Hubris::HVectorR3& in_displacement,
	const Hubris::HVectorR3& in_velocity,
	const Hubris::HREAL in_timeDelta,
	const LSpringParam& in_springParam
	)
{
	const HVectorR3 localDisplacement( in_displacement ); //allow for &out_displacement == &in_displacement
	const HVectorR3 tempVelocity = in_velocity - ( in_timeDelta * in_springParam.SpringConstantGet() * in_displacement );
	HVectorR3 newDisplacement = in_displacement + ( in_timeDelta * tempVelocity );

	//dampen the spring occilation
	//const HREAL dampen = in_springParam.SpringDamppenConstantGet();
	//newDisplacement *= dampen; 
	const HREAL dampen = LocalDampenGet( in_springParam.SpringDamppenConstantGet(), in_timeDelta );
	//if( HTRUE == HMathUtility::EpsilonZeroNot( dampen ) )
	//{
	//	newDisplacement = HMathUtility::Lerp( newDisplacement, HVectorR3( 0.0F ), dampen );
	//}

	//clamp the output displacement
	const HREAL springMaximumDisplacement = in_springParam.SpringMaximumDistanceGet();
	out_displacement = HMathUtility::Clamp( newDisplacement, HVectorR3( -springMaximumDisplacement ), HVectorR3( springMaximumDisplacement ) );

	//adjust velocity for effect of clamp (not just accel on old velocity, tempVelocity)
	if( HTRUE == HMathUtility::EpsilonZeroNot( in_timeDelta ) )
	{
		out_velocity = ( out_displacement - localDisplacement ) / in_timeDelta;
	}

	//dampen velocity
	if( HTRUE == HMathUtility::EpsilonZeroNot( dampen ) )
	{
		out_velocity = HMathUtility::Lerp( out_velocity, HVectorR3( 0.0F ), dampen );
	}
	//out_velocity *= dampen;

	return;
}

/**/