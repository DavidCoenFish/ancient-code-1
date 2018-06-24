//file: Vanity/VComponentForce/VComponentForce.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentForce/VComponentForce.h"

#include "Vanity/VComponentForce/VComponentForceDataBound.h"
#include "Vanity/VComponentForce/VComponentForceDataSphere.h"
#include "Vanity/VComponentForce/VComponentForceSampleParam.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TForceFlag
{
	enum TEnum
	{
		TForceNone		= 0x00,
		TForceGravity	= 0x01,
		TForcePhysical	= 0x02,
		TForceMagnetic	= 0x04,
		TForceAir		= 0x08,
		TForceCamera	= 0x10,
		TForceBoyancy	= 0x20
	};
};

///////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentForce::VComponentForce()
: m_arrayPointerData()
{
	return;
}

/**/
VComponentForce::~VComponentForce()
{
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentForce::SampleForceApplyAccelleration(
	Hubris::HVectorR3& in_out_forceSum,
	const Hubris::HVectorR3& in_accelleration,
	const VComponentForceSampleParam& in_param
	)
{
	// F = M x A
	if( HTRUE == HMathUtility::EpsilonZeroNot( in_param.m_massInvert ) )
	{
		in_out_forceSum += ( in_accelleration / in_param.m_massInvert );
	}

	return;
}

/**/
Hubris::HVOID VComponentForce::SampleForceApplyForce(
	Hubris::HVectorR3& in_out_forceSum,
	const Hubris::HVectorR3& in_force,
	const VComponentForceSampleParam& HCOMMON_UNUSED_VAR( in_param )
	)
{
	in_out_forceSum += in_force;
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentForce::OnAddItem(
	const Hubris::HSINT in_itemIndex
	)
{
	if( m_arrayPointerData.SizeGet() <= in_itemIndex )
	{
		m_arrayPointerData.SizeResize( in_itemIndex + 1 );
	}

	return;
}

/**/
HVOID VComponentForce::OnRemoveItem(
	const Hubris::HSINT in_itemIndex
	)
{
	if( in_itemIndex < m_arrayPointerData.SizeGet() )
	{
		m_arrayPointerData[ in_itemIndex ] = HNULL;
	}

	return;
}

/**/
Hubris::HVOID VComponentForce::ForceBoundCreate(
	const TItemId in_itemId,
	const Hubris::HSINT in_forceFlag,
	const Hubris::HSINT in_boundFlag,
	const Pride::PBoundsR3& in_bounds,
	const Hubris::HVectorR3& in_vector
	)
{
	VComponentForceDataBound* pBound = HNULL;
	HCOMMON_NEW(
		pBound,
		VComponentForceDataBound
		);

	if( HNULL != pBound )
	{
		pBound->DataSet(
			in_forceFlag,
			in_boundFlag,
			in_bounds,
			in_vector
			);
	}

	m_arrayPointerData[ in_itemId ] = pBound;

	return;
}

/**/
Hubris::HVOID VComponentForce::ForceSphereCreate(
	const TItemId in_itemId,
	const Hubris::HSINT in_forceFlag,
	const Hubris::HSINT in_sphereFlag,
	const Hubris::HVectorR3& in_vector,
	const Hubris::HREAL in_magnitude
	)
{
	VComponentForceDataSphere* pSphere = HNULL;
	HCOMMON_NEW(
		pSphere,
		VComponentForceDataSphere
		);

	if( HNULL != pSphere )
	{
		pSphere->DataSet(
			in_forceFlag,
			in_sphereFlag,
			in_vector,
			in_magnitude
			);
	}

	m_arrayPointerData[ in_itemId ] = pSphere;

	return;
}

/**/
Hubris::HVOID VComponentForce::SampleForce(
	Hubris::HVectorR3& in_out_forceSum,
	//Pride::PAxisAngle* const in_out_pRotation,
	const VComponentForceSampleParam& in_param,
	VScene& in_scene,
	const TItemId in_itemId
	)const
{
	const TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->SampleForce(
		in_out_forceSum,
		in_param,
		in_scene,
		in_itemId
		);

	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT VComponentForce::FlagGetForceGravity()
{
	return TForceFlag::TForceGravity;
}

/**/
const Hubris::HSINT VComponentForce::FlagGetForcePhysical()
{
	return TForceFlag::TForcePhysical;
}

/**/
const Hubris::HSINT VComponentForce::FlagGetForceMagnetic()
{
	return TForceFlag::TForceMagnetic;
}

/**/
const Hubris::HSINT VComponentForce::FlagGetForceAir()
{
	return TForceFlag::TForceAir;
}

/**/
const Hubris::HSINT VComponentForce::FlagGetForceCamera()
{
	return TForceFlag::TForceCamera;
}

/**/
const Hubris::HSINT VComponentForce::FlagGetForceBoyancy()
{
	return TForceFlag::TForceBoyancy;
}

/**/
const Hubris::HSINT VComponentForce::FlagGetBoundAccelleration()
{
	return VComponentForceDataBound::FlagGetAccelleration();
}

/**/
const Hubris::HSINT VComponentForce::FlagGetBoundForce()
{
	return VComponentForceDataBound::FlagGetForce();
}

/**/
const Hubris::HSINT VComponentForce::FlagGetSphereAccelleration()
{
	return VComponentForceDataSphere::FlagGetAccelleration();
}

/**/
const Hubris::HSINT VComponentForce::FlagGetSphereForce()
{
	return VComponentForceDataSphere::FlagGetForce();
}

/**/
const Hubris::HSINT VComponentForce::FlagGetSpherePoint()
{
	return VComponentForceDataSphere::FlagGetPoint();
}

/**/
const Hubris::HSINT VComponentForce::FlagGetSphereDirection()
{
	return VComponentForceDataSphere::FlagGetDirection();
}

/**/
const Hubris::HSINT VComponentForce::FlagGetSphereFalloffLinear()
{
	return VComponentForceDataSphere::FlagGetFalloffLinear();
}

/**/
const Hubris::HSINT VComponentForce::FlagGetSphereFalloffSquarDistance()
{
	return VComponentForceDataSphere::FlagGetFalloffSquarDistance();
}

/**/
