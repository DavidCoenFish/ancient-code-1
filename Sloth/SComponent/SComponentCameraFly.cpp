//file: Sloth/SComponent/SComponentCameraFly.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentCameraFly.h"

#include "Sloth/SComponent/SComponentCameraFlyImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentCameraFly::SComponentCameraFly( 
	const Pride::PCamera& in_setup
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM(
		m_pImplementation,
		SComponentCameraFlyImplementation,
		in_setup
		);
	return;
}

/**/
SComponentCameraFly::~SComponentCameraFly()
{
	HCOMMON_DELETE(
		m_pImplementation,
		SComponentCameraFlyImplementation
		);
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentCameraFly::Update(
	const Hubris::HREAL in_delta,
	const SInput& in_input
	)
{
	ImplementationGet().Update(
		in_delta,
		in_input
		);
	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Pride::PCamera& SComponentCameraFly::CameraGet()const
{
	return( ImplementationGet().CameraGet() );
}

/**/
Pride::PCamera& SComponentCameraFly::CameraGet()
{
	return( ImplementationGet().CameraGet() );
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SComponentCameraFlyImplementation& SComponentCameraFly::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
SComponentCameraFlyImplementation& SComponentCameraFly::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
