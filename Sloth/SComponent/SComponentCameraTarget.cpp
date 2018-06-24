//file: Sloth/SComponent/SComponentCameraTarget.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentCameraTarget.h"

#include "Sloth/SComponent/SComponentCameraTargetImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentCameraTarget::SComponentCameraTarget(
	const Pride::PCamera& in_setup,
	const Hubris::HREAL in_targetSpringAheadUnitSquared, //normalisation length to work out amount for target projection, zero for ignore
	const TArrayDistanceKeyData& in_arrayDistanceKeyData,
	const Lust::LSpringParam& in_targetSpringParam,
	const Lust::LSpringParam& in_cameraSpringParam,
	const Hubris::HVectorR3& in_initialCameraOffset, //initial camera offset from targets
	const TArrayVector& in_arrayInitialTarget
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM_7(
		m_pImplementation,
		SComponentCameraTargetImplementation,
		in_setup,
		in_targetSpringAheadUnitSquared,
		in_arrayDistanceKeyData,
		in_targetSpringParam,
		in_cameraSpringParam,
		in_initialCameraOffset,
		in_arrayInitialTarget
		);

	return;
}

/**/
SComponentCameraTarget::~SComponentCameraTarget()
{
	HCOMMON_DELETE(
		m_pImplementation,
		SComponentCameraTargetImplementation
		);

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentCameraTarget::Update(
	const Hubris::HREAL in_delta,
	const TArrayVector& in_arrayTargets,
	const Hubris::HVectorR3& in_cameraInput, //rotate camera left/ right, zoom camera in/ out
	const Hubris::HBOOL in_reset //erase history of movement, restore initial state of camera
	)
{
	ImplementationGet().Update(
		in_delta,
		in_arrayTargets,
		in_cameraInput,
		in_reset
		);

	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Pride::PCamera& SComponentCameraTarget::CameraGet()const
{
	return ImplementationGet().CameraGet();
}

/**/
Pride::PCamera& SComponentCameraTarget::CameraGet()
{
	return ImplementationGet().CameraGet();
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SComponentCameraTargetImplementation& SComponentCameraTarget::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
SComponentCameraTargetImplementation& SComponentCameraTarget::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
