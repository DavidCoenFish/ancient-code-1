//file: Vanity/VComponentForce/VComponentForceDataBound.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentForce/VComponentForceDataBound.h"

#include "Vanity/VComponentForce/VComponentForce.h"
#include "Vanity/VComponentForce/VComponentForceSampleParam.h"
#include "Vanity/VComponentForce/VComponentForceTrait.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentForceDataBound, VComponentForceDataBase );

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TFlag
{
	enum TEnum
	{
		TNone			= 0x00,
		TAccelleration	= 0x01,
		TForce			= 0x02
	};
};

///////////////////////////////////////////////////////
// static local methdods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentForceDataBound::VComponentForceDataBound()
: m_forceFlag( 0 )
, m_flag( 0 )
, m_bounds()
, m_vector()
{
	return;
}

/**/
VComponentForceDataBound::~VComponentForceDataBound()
{
	return;
}

///////////////////////////////////////////////////////
// implement VComponentForceDataBase
/**/
Hubris::HVOID VComponentForceDataBound::SampleForce(
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

	HMatrixR4 itemMatrix;
	HMatrixR4 itemInverseMatrix;
	VSceneUtility::ItemMatrixGet( itemMatrix, itemInverseMatrix, in_scene, in_itemId );

	//check that location is inside bounds
	const HVectorR3 localSpaceLocation = HMatrixUtility::VectorProduct( itemInverseMatrix, in_param.m_location );
	if( HFALSE == PBoundsUtility::PointInsideTest( m_bounds, localSpaceLocation ) )
	{
		return;
	}

	const HVectorR3 vector = HMatrixUtility::VectorProductNoTranslate( itemMatrix, m_vector ) * forceMul;

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
Hubris::HVOID VComponentForceDataBound::DataSet(
	const Hubris::HSINT in_forceFlag,
	const Hubris::HSINT in_flag,
	const Pride::PBoundsR3& in_bounds,
	const Hubris::HVectorR3& in_vector
	)
{
	m_forceFlag = in_forceFlag;
	m_flag = in_flag;
	m_bounds = in_bounds;
	m_vector = in_vector;

	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT VComponentForceDataBound::FlagGetAccelleration()
{
	return TFlag::TAccelleration;
}

/**/
const Hubris::HSINT VComponentForceDataBound::FlagGetForce()
{
	return TFlag::TForce;
}

/**/
