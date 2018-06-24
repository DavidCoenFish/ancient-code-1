//file: Sloth/SComponent/SComponentCameraFlyImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentCameraFlyImplementation.h"

#include "Sloth/SInput/SInput_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

///////////////////////////////////////////////////////
// static local methods
/**/
static HVOID LocalUpdatePosition(
	HVectorR3& in_out_translation,
	const PUnitVectorR3& in_unitVectorAt,
	const PUnitVectorR3& in_unitVectorRight,
	const HREAL in_delta,
	const SInput& in_input 
	)
{
	HREAL deltaRight = HVariablesMath::ZeroGet< HREAL >();
	HREAL deltaForward = HVariablesMath::ZeroGet< HREAL >();
	if( SInput::ButtonStateDownGet() & in_input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardRightGet() ) )
	{
		deltaRight += in_delta;
	}
	if( SInput::ButtonStateDownGet() & in_input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardLeftGet() ) )
	{
		deltaRight -= in_delta;
	}

	if( SInput::ButtonStateDownGet() & in_input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardUpGet() ) )
	{
		deltaForward += in_delta;
	}
	if( SInput::ButtonStateDownGet() & in_input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardDownGet() ) )
	{
		deltaForward -= in_delta;
	}

	if( ( 0.0F == deltaRight ) &&
		( 0.0F == deltaForward ) )
	{
		return;
	}

	in_unitVectorAt;
	in_unitVectorRight;
	//in_out_translation += ( ( deltaForward * in_unitVectorRight.VectorGet() ) );// + ( deltaForward * in_unitVectorAt.VectorGet() ) );
	in_out_translation += ( 10.0F * ( ( ( deltaRight * in_unitVectorRight.VectorGet() ) + ( deltaForward * in_unitVectorAt.VectorGet() ) ) ) );

	return;
}

/**/
static HVOID LocalUpdateDirection(
	HREAL& in_out_latitude,
	HREAL& in_out_longitude,
	const HREAL in_delta,
	const SInput& in_input 
	)
{
	if( SInput::ButtonStateDownGet() & in_input.ButtonStateGet( SInput::DeviceIndexMouseGet(), SInput::InputIndexMouseLeftGet() ) )
	{
		in_out_latitude -= ( 10000.0F * in_delta * in_input.InputDeltaGet( SInput::DeviceIndexMouseGet(), SInput::InputIndexMouseHorizontalGet() ) );
		in_out_longitude -= ( 10000.0F * in_delta * in_input.InputDeltaGet( SInput::DeviceIndexMouseGet(), SInput::InputIndexMouseVerticalGet() ) );
	}

	return;
}

/**/
static HVOID LocalSetCameraTransform(
	HMatrixR4& out_newMatrix,
	const HVectorR3& in_translation,
	const HREAL in_latitude,
	const HREAL in_longitude
	)
{
	HREAL localLatitude( in_latitude );
	while( localLatitude < -180.0F )
	{
		localLatitude += 360.0F;
	}
	while( 180.0F < localLatitude )
	{
		localLatitude -= 360.0F;
	}
	HREAL localLongitude( in_longitude );

	PUnitVectorR3 unitVectorAt;
	PUnitVectorR3 unitVectorUp;
	PUnitVectorUtility::UnitVectorFromPolar(
		unitVectorAt,
		localLatitude, //-180 ... 180 deg
		localLongitude//-90 ... 90 deg
		);
	HREAL upLongitude = localLongitude + 90.0F;
	HREAL upLatitude = localLatitude;
	if( 90.0F < upLongitude )
	{
		upLongitude = 180.0F - upLongitude;
		upLatitude += 180.0F;
	}
	PUnitVectorUtility::UnitVectorFromPolar(
		unitVectorUp,
		upLatitude,
		upLongitude
		);

	out_newMatrix = HMatrixConstructor::HMatrixR4ConstructAtUp( 
		unitVectorAt.VectorGet(), 
		unitVectorUp.VectorGet(),
		-HMatrixConstructor::HVectorR3AxisZ(),
		HMatrixConstructor::HVectorR3AxisY()
		);

	HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( out_newMatrix, in_translation );

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SComponentCameraFlyImplementation::SComponentCameraFlyImplementation(
	const Pride::PCamera& in_setup
	)
: m_camera( in_setup )
, m_translationScale( HVariablesMath::UnitGet< HREAL >() )
, m_rotationScale( HVariablesMath::UnitGet< HREAL >() )
{
	return;
}

/**/
SComponentCameraFlyImplementation::~SComponentCameraFlyImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentCameraFlyImplementation::Update(
	const Hubris::HREAL in_delta,
	const SInput& in_input
	)
{
	HVectorR3 translation = HMatrixUtility::TranslateGet< HMatrixR4, HVectorR3 >( m_camera.TransformGet() );
	const PUnitVectorR3 unitVectorAt( HMatrixUtility::VectorProductNoTranslate( 
		m_camera.TransformGet(),
		-HMatrixConstructor::HVectorR3AxisZ()
		) );

	const PUnitVectorR3 unitVectorRight( HMatrixUtility::VectorProductNoTranslate( 
		m_camera.TransformGet(),
		HMatrixConstructor::HVectorR3AxisX()
		) );

	const PUnitVectorR3 unitVectorForward( HMatrixUtility::VectorProductNoTranslate( 
		m_camera.TransformGet(),
		HMatrixConstructor::HVectorR3AxisY()
		) );

	HREAL latitude = HVariablesMath::ZeroGet< HREAL >();
	HREAL longitude = HVariablesMath::ZeroGet< HREAL >();

	PUnitVectorUtility::PolarFromUnitVector(
		latitude,
		longitude,
		unitVectorAt
		);

	LocalUpdatePosition(
		translation,
		unitVectorAt,
		unitVectorRight,
		in_delta * m_translationScale,
		in_input 
		);

	LocalUpdateDirection(
		latitude,
		longitude,
		in_delta * m_rotationScale,
		in_input
		);

	HMatrixR4 newMatrix;
	LocalSetCameraTransform(
		newMatrix,
		translation,
		latitude,
		longitude
		);

	m_camera.TransformSet( newMatrix );

	return;
}

/**/
