//file: Vanity/VComponentForce/VComponentForceDataSphere.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentForce/VComponentForceDataSphere.h"

#include "Vanity/VComponentForce/VComponentForceSampleParam.h"
#include "Vanity/VComponentForce/VComponentForceTrait.h"
#include "Vanity/VComponentForce/VComponentForce.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentForceDataSphere, VComponentForceDataBase );

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TFlag
{
	enum TEnum
	{
		TNone					= 0x00,
		TAccelleration			= 0x01,
		TForce					= 0x02,
		TPoint					= 0x04,
		TDirection				= 0x08,
		TFalloffLinear			= 0x10,
		TFalloffSquarDistance	= 0x20
	};
};

///////////////////////////////////////////////////////
// creation
/**/
VComponentForceDataSphere::VComponentForceDataSphere()
: m_forceFlag( 0 )
, m_flag( 0 )
, m_vector()
{
	return;
}

/**/
VComponentForceDataSphere::~VComponentForceDataSphere()
{
	return;
}

///////////////////////////////////////////////////////
// implement VComponentForceDataBase
/**/
Hubris::HVOID VComponentForceDataSphere::SampleForce(
	Hubris::HVectorR3& in_out_forceSum,
	//Pride::PAxisAngle* const in_out_pRotation,
	const VComponentForceSampleParam& in_param,
	VScene& in_scene,
	const TItemId in_itemId
	)const
{
	const HSINT localForceFlag = ( m_forceFlag & in_param.m_forceFlag );
	if( 0 == localForceFlag )
	{
		return;
	}

	//if you had a force that effected physical overlapping Magnetic force, you get both, so internally we multiply as well
	HREAL forceMul = HREAL( HCommonBitCountGet( localForceFlag ) );

	//get force vector
	HVectorR3 vector;

	Hubris::HREAL originToPointDistanceSquared = 0.0F;
	HBOOL originToPointDistanceSquaredValid = HFALSE;
	Hubris::HREAL originToPointDistance = 0.0F;
	HBOOL originToPointDistanceValid = HFALSE;
	Hubris::HVectorR3 normal;
	HBOOL normalValid = HFALSE;

	if( m_flag & TFlag::TPoint )
	{
		PSphereR3 itemSphere;
		in_scene.ItemDataGet( in_itemId, HNULL, &itemSphere );
		const HVectorR3 offset = in_param.m_location - itemSphere.CenterGet();
		originToPointDistanceSquared = HMatrixUtility::LengthSquared( offset );
		originToPointDistanceSquaredValid = HTRUE;
		originToPointDistance = HMath::SquareRoot( originToPointDistanceSquared );
		originToPointDistanceValid = HTRUE;
		normal = ( offset / originToPointDistance );
		normalValid = HTRUE;
		vector = normal;
	}
	else if( m_flag & TFlag::TDirection )
	{
		HMatrixR4 itemMatrix;
		VSceneUtility::ItemMatrixGet( itemMatrix, in_scene, in_itemId );
		vector = HMatrixUtility::VectorProductNoTranslate( itemMatrix, m_vector );
	}

	//apply falloff
	HREAL falloff = 1.0F;
	if( m_flag & TFlag::TFalloffLinear )
	{
		PSphereR3 itemSphere;
		in_scene.ItemDataGet( in_itemId, HNULL, &itemSphere );

		if( HFALSE == originToPointDistanceValid )
		{
			const HVectorR3 offset = in_param.m_location - itemSphere.CenterGet();
			originToPointDistance = HMatrixUtility::Length( offset );
			originToPointDistanceValid = HTRUE;
		}

		falloff = ( originToPointDistance / itemSphere.RadiusGet() );
	}
	else if( m_flag & TFlag::TFalloffSquarDistance )
	{
		PSphereR3 itemSphere;
		in_scene.ItemDataGet( in_itemId, HNULL, &itemSphere );

		if( HFALSE == originToPointDistanceSquaredValid )
		{
			const HVectorR3 offset = in_param.m_location - itemSphere.CenterGet();
			originToPointDistanceSquared = HMatrixUtility::LengthSquared( offset );
			originToPointDistanceSquaredValid = HTRUE;
		}

		falloff = ( originToPointDistanceSquared / ( itemSphere.RadiusGet() * itemSphere.RadiusGet() ) );
	}

	vector = ( vector * ( forceMul * falloff ) );

	//apply force
	if( m_flag & TFlag::TAccelleration )
	{
		VComponentForce::SampleForceApplyAccelleration(
			in_out_forceSum,
			vector,
			in_param
			);
	}
	else if( m_flag & TFlag::TForce )
	{
		VComponentForce::SampleForceApplyForce(
			in_out_forceSum,
			vector,
			in_param
			);
	}

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentForceDataSphere::DataSet(
	const Hubris::HSINT in_forceFlag,
	const Hubris::HSINT in_flag,
	const Hubris::HVectorR3& in_vector,
	const Hubris::HREAL in_magnitude
	)
{
	m_forceFlag = in_forceFlag;
	m_flag = in_flag;
	if( m_flag & TFlag::TPoint )
	{
		m_vector[ 0 ] = in_magnitude;
	}
	else if( m_flag & TFlag::TDirection )
	{
		m_vector = in_vector;
	}

	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT VComponentForceDataSphere::FlagGetAccelleration()
{
	return TFlag::TAccelleration;
}

/**/
const Hubris::HSINT VComponentForceDataSphere::FlagGetForce()
{
	return TFlag::TForce;
}

/**/
const Hubris::HSINT VComponentForceDataSphere::FlagGetPoint()
{
	return TFlag::TPoint;
}

/**/
const Hubris::HSINT VComponentForceDataSphere::FlagGetDirection()
{
	return TFlag::TDirection;
}

/**/
const Hubris::HSINT VComponentForceDataSphere::FlagGetFalloffLinear()
{
	return TFlag::TFalloffLinear;
}

/**/
const Hubris::HSINT VComponentForceDataSphere::FlagGetFalloffSquarDistance()
{
	return TFlag::TFalloffSquarDistance;
}

/**/
