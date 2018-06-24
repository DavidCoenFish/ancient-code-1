//file: Sloth/SComponent/SComponentCameraTargetImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentCameraTargetImplementation.h"

#include< Lust/LSpring/LSpring_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Lust;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< SComponentCameraTargetDistanceKeyData >TArrayDistanceKeyData;

///////////////////////////////////////////////////////
// local static methods
/**/
static const Hubris::HVectorR3 LocalTargetGet( const TArrayVector& in_arrayTargets )
{
	HVectorR3 result;
	HSINT count = in_arrayTargets.SizeGet();
	for( HSINT index = 0; index < count; ++index )
	{
		result += in_arrayTargets[ index ];
	}

	if( 0 < count )
	{
		result /= ( float )( count );
	}
	return result;
}

/**/
static Hubris::HVOID LocalDistanceRotationFromOffset(
	Hubris::HREAL& out_cameraDistance,
	Hubris::HREAL& out_cameraRotation,
	const Hubris::HVectorR3& in_offset
	)
{
	HVectorR3 localOffset( in_offset );
	localOffset[ 2 ] = 0.0F;
	out_cameraDistance = HMatrixUtility::Length( localOffset );
	localOffset *= ( 1.0F / out_cameraDistance );

	//0 ... 180
	out_cameraRotation = HMath::CosArc< HREAL >( localOffset[ 0 ] ) * HVariablesMath::RadToDegGet< HREAL >();
	//-180 ... 180
	out_cameraRotation = HMath::CopySign< HREAL >( out_cameraRotation, localOffset[ 1 ] );

	return;
}

/**/
static const SComponentCameraTargetDistanceKeyData LocalLerpKeyData(
	const HREAL in_distance,
	const TArrayDistanceKeyData& in_arrayDistanceKeyData
	)
{
	SComponentCameraTargetDistanceKeyData keyData;
	HSINT splineKeyIndex0 = 0;
	HSINT splineKeyIndex1 = 0;
	HSINT splineKeyIndex2 = 0;
	HSINT splineKeyIndex3 = 0;
	HREAL ratio = 0.0F;

	const HSINT count = in_arrayDistanceKeyData.SizeGet();
	if( count <= 0 )
	{
		return keyData;
	}

	for( HSINT index = 0; index < ( count - 1 ); ++index )
	{
		const SComponentCameraTargetDistanceKeyData& key0 = in_arrayDistanceKeyData[ index ];

		if( in_distance < key0.DistanceGet() )
		{
			//before key case
			break;
		}

		const SComponentCameraTargetDistanceKeyData& key1 = in_arrayDistanceKeyData[ index + 1 ];

		if( key1.DistanceGet() < in_distance )
		{
			//prep past end case 
			splineKeyIndex0 = index;
			splineKeyIndex1 = index;
			splineKeyIndex2 = index;
			splineKeyIndex3 = index;
			continue;
		}

		//key0 <= in_distanceSquared <= key1

		ratio = ( in_distance - key0.DistanceGet() ) / ( key1.DistanceGet() - key0.DistanceGet() );
		splineKeyIndex0 = HMathUtility::Clamp( index - 1, 0, count - 1 );
		splineKeyIndex1 = HMathUtility::Clamp( index    , 0, count - 1 );
		splineKeyIndex2 = HMathUtility::Clamp( index + 1, 0, count - 1 );
		splineKeyIndex3 = HMathUtility::Clamp( index + 2, 0, count - 1 );
	}

	const SComponentCameraTargetDistanceKeyData& data0 = in_arrayDistanceKeyData[ splineKeyIndex0 ];
	const SComponentCameraTargetDistanceKeyData& data1 = in_arrayDistanceKeyData[ splineKeyIndex1 ];
	const SComponentCameraTargetDistanceKeyData& data2 = in_arrayDistanceKeyData[ splineKeyIndex2 ];
	const SComponentCameraTargetDistanceKeyData& data3 = in_arrayDistanceKeyData[ splineKeyIndex3 ];
	keyData.CameraElevationSet( HMathUtility::SplineCatmullRom( ratio, data0.CameraElevationGet(), data1.CameraElevationGet(), data2.CameraElevationGet(), data3.CameraElevationGet() ) );
	//keyData.DistanceSet( HMathUtility::SplineCatmullRom( ratio, data0.DistanceGet(), data1.DistanceGet(), data2.DistanceGet(), data3.DistanceGet() ) );
	keyData.ProjectionTimeSet( HMathUtility::SplineCatmullRom( ratio, data0.ProjectionTimeGet(), data1.ProjectionTimeGet(), data2.ProjectionTimeGet(), data3.ProjectionTimeGet() ) );
	keyData.TargetElevationSet( HMathUtility::SplineCatmullRom( ratio, data0.TargetElevationGet(), data1.TargetElevationGet(), data2.TargetElevationGet(), data3.TargetElevationGet() ) );

	return keyData;
}

/**/
static const HVectorR3 LocalProjectTarget(
	const HVectorR3& in_target,
	const HVectorR3& in_targetOld,
	const HREAL in_delta,
	const HREAL in_projectionTime
	)
{
	//get velocity from targetOld to target over delta, 
	//project target by projectionTime
	//const HREAL length = HMatrixUtility::Length( offset );
	//const HVectorR3 projectTarget = in_target + ( offset / length ) * ( length / in_delta ) * in_projectionTime 

	//const HVectorR3 offset = in_target - in_targetOld;
	//const HVectorR3 projectTarget = in_target + ( offset * ( in_projectionTime / in_delta ) );

	if( HTRUE == HMathUtility::EpsilonEqual( in_target, in_targetOld ) )
	{
		return in_target;
	}

	//const HREAL targetVelocity = ( HMatrixUtility::Length( target - m_targetOld ) / in_delta );

	const HVectorR3 offset = in_target - in_targetOld;
	const HREAL length = HMatrixUtility::Length( offset );
	const HREAL velocity = length / in_delta; //this is the delta of the wrong frame, need to preserve
	const HVectorR3 direction = offset * ( 1.0F / length );

	const HVectorR3 projectTarget = in_target + ( direction * ( velocity * in_projectionTime ) );

	return projectTarget;
}

/**/
static Hubris::HVOID LocalApplyInput( 
	Hubris::HREAL& in_out_cameraDistance,
	Hubris::HREAL& in_out_cameraRotation,
	const Hubris::HVectorR3& in_cameraInput,
	const Hubris::HREAL in_delta,
	const Hubris::HREAL in_rotationScale,
	const Hubris::HREAL in_distanceScale,
	const Hubris::HREAL in_minDistance,
	const Hubris::HREAL in_maxDistance
	)
{
	in_out_cameraDistance += ( ( in_cameraInput[ 1 ] ) * ( in_delta * in_distanceScale ) );
	in_out_cameraDistance = HMathUtility::Clamp( in_out_cameraDistance, in_minDistance, in_maxDistance );

	in_out_cameraRotation += ( ( in_cameraInput[ 0 ] ) * ( in_delta * in_rotationScale ) );
	while( in_out_cameraRotation < -180.0F )
	{
		in_out_cameraRotation += 360.0F;
	}
	while( 180.0F < in_out_cameraRotation )
	{
		in_out_cameraRotation -= 360.0F;
	}

	return;
}

/**/
static const HVectorR3 LocalNewCameraPositionGet(
	const Hubris::HVectorR3& in_projectedTarget,
	const Hubris::HREAL in_cameraRotation,
	const Hubris::HREAL in_cameraDistance
	)
{
	HVectorR3 offset;
	offset[ 0 ] = ( HMath::Cos< HREAL >( in_cameraRotation * HVariablesMath::DegToRadGet< HREAL >() ) ) * in_cameraDistance;
	offset[ 1 ] = ( HMath::Sin< HREAL >( in_cameraRotation * HVariablesMath::DegToRadGet< HREAL >() ) ) * in_cameraDistance;

	offset[ 1 ] = HMath::CopySign< HREAL >( offset[ 1 ], in_cameraRotation );

	const HVectorR3 resultVector( in_projectedTarget + offset );
	return resultVector;
}

/**/
static Hubris::HVOID LocalApplySpring(
	const Hubris::HVectorR3& in_target,
	Hubris::HVectorR3& in_out_springPosition,
	Hubris::HVectorR3& in_out_springVelocity,
	Lust::LSpringParam& in_springParam,
	const Hubris::HREAL in_delta
	)
{
	HVectorR3 displacement( in_out_springPosition - in_target );
	LSpringUtility::SpringVariablesTick(
		displacement,
		in_out_springVelocity,
		displacement,
		in_out_springVelocity,
		in_delta,
		in_springParam
		);

	in_out_springPosition = in_target + displacement;

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SComponentCameraTargetImplementation::SComponentCameraTargetImplementation(
	const Pride::PCamera& in_setup,
	const Hubris::HREAL in_targetSpringAheadUnitSquared, //normalisation length to work out amount for target projection, zero for ignore
	const TArrayDistanceKeyData& in_arrayDistanceKeyData,
	const Lust::LSpringParam& in_targetSpringParam,
	const Lust::LSpringParam& in_cameraSpringParam,
	const Hubris::HVectorR3& in_initialCameraOffset, //initial camera offset from targets
	const TArrayVector& in_arrayInitialTarget,
	const Hubris::HREAL in_cameraScaleDistance,
	const Hubris::HREAL in_cameraScaleRotation
	)
: m_targetSpringAheadUnitSquared( in_targetSpringAheadUnitSquared )
, m_arrayDistanceKeyData( in_arrayDistanceKeyData )
, m_targetSpringParam( in_targetSpringParam )
, m_cameraSpringParam( in_cameraSpringParam )
, m_initialCameraOffset( in_initialCameraOffset )
, m_cameraScaleDistance( in_cameraScaleDistance )
, m_cameraScaleRotation( in_cameraScaleRotation )
, m_cameraMinDistance( 0.0F )
, m_cameraMaxDistance( 0.0F )
//, m_oldDelta( 0.0F )
, m_targetOld()
, m_targetProjectionSpringResult()
, m_targetProjectionSpringVelocity()
, m_cameraPosition()
, m_cameraPositionSpringResult()
, m_cameraPositionSpringVelocity()
, m_cameraRotation( 0.0F )
, m_cameraDistance( 0.0F )
, m_camera( in_setup )
{
	Update(
		0.0F,
		in_arrayInitialTarget,
		HVectorR3(),
		HTRUE
		);

	if( 0 < m_arrayDistanceKeyData.SizeGet() )
	{
		m_cameraMinDistance = m_arrayDistanceKeyData[ 0 ].DistanceGet();
		m_cameraMaxDistance = m_arrayDistanceKeyData[ m_arrayDistanceKeyData.SizeGet() - 1 ].DistanceGet();
	}

	return;
}

/**/
SComponentCameraTargetImplementation::~SComponentCameraTargetImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentCameraTargetImplementation::Update(
	const Hubris::HREAL in_delta,
	const TArrayVector& in_arrayTargets,
	const Hubris::HVectorR3& in_cameraInput, //rotate camera left/ right, zoom camera in/ out
	const Hubris::HBOOL in_reset //erase history of movement, restore initial state of camera
	)
{
	HVectorR3 target = LocalTargetGet( in_arrayTargets );
	if( HTRUE == in_reset )
	{
		m_targetOld = target;
		//m_oldDelta = in_delta;
		m_targetProjectionSpringResult = target;
		m_targetProjectionSpringVelocity = HTraitEmpty< HVectorR3 >::EmptyGet();
		m_cameraPosition = target + m_initialCameraOffset;
		m_cameraPositionSpringResult = m_cameraPosition;
		m_cameraPositionSpringVelocity = HTraitEmpty< HVectorR3 >::EmptyGet();
		LocalDistanceRotationFromOffset(
			m_cameraDistance,
			m_cameraRotation,
			m_initialCameraOffset
			);
	}

	if( HTRUE == HMathUtility::EpsilonZero( in_delta ) )
	{
		UpdateCamera();
		return;
	}

	//const HREAL targetVelocity = ( HMatrixUtility::Length( target - m_targetOld ) / in_delta );

	const HREAL oldCameraDistance( m_cameraDistance );
	SComponentCameraTargetDistanceKeyData lerpKeyData = LocalLerpKeyData(
		m_cameraDistance,
		m_arrayDistanceKeyData
		);

	const HVectorR3 projectedTarget = LocalProjectTarget(
		target,
		m_targetOld,
		in_delta,
		lerpKeyData.ProjectionTimeGet()
		);
	m_targetOld = target;

	//const HVectorR3 projectedTarget = target;

	//update rotation and distance with input
	LocalApplyInput( 
		m_cameraDistance,
		m_cameraRotation,
		in_cameraInput,
		in_delta,
		m_cameraScaleRotation,
		m_cameraScaleDistance,
		m_cameraMinDistance,
		m_cameraMaxDistance
		);

	//if camera distance changes on input, recalculate lerp data
	if( oldCameraDistance != m_cameraDistance )
	{
		lerpKeyData = LocalLerpKeyData(
		m_cameraDistance,
		m_arrayDistanceKeyData
		);
	}

	const HVectorR3 newCameraPosition = LocalNewCameraPositionGet(
		projectedTarget,
		m_cameraRotation,
		m_cameraDistance
		);

	//apply spring
	//LSpringUtility::SpringVariablesTick(
	LocalApplySpring(
		projectedTarget + HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, lerpKeyData.TargetElevationGet() ),
		m_targetProjectionSpringResult,
		m_targetProjectionSpringVelocity,
		m_targetSpringParam,
		in_delta
		);

	LocalApplySpring(
		newCameraPosition + HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, lerpKeyData.CameraElevationGet() ),
		m_cameraPositionSpringResult,
		m_cameraPositionSpringVelocity,
		m_targetSpringParam,
		in_delta
		);

	UpdateCamera();

	//keep old target to aid projection
	//m_targetOld = target;
	//const HREAL length = HMatrixUtility::Length( projectedTarget - 
	//m_targetVelocity

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID SComponentCameraTargetImplementation::UpdateCamera()
{
	//create a appropriate up vector for camera
	const HVectorR3 at = HMatrixUtility::Normalise( m_targetProjectionSpringResult - m_cameraPositionSpringResult );

	const HVectorR3 cross = HMatrixUtility::CrossProduct( at, HMatrixConstructor::HVectorR3AxisZ() );
	const HVectorR3 up = HMatrixUtility::Normalise( HMatrixUtility::CrossProduct( cross, at ) );


	//create a new matrix for the camera bassed on members, m_targetProjectionSpringResult, m_cameraPositionSpringResult
	HMatrixR4 newMatrix = HMatrixConstructor::HMatrixR4ConstructAtUp( 
		at,
		up,
		-HMatrixConstructor::HVectorR3AxisZ(),
		HMatrixConstructor::HVectorR3AxisY()
		);

	HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( newMatrix, m_cameraPositionSpringResult );

	m_camera.TransformSet( newMatrix );

	return;
}

/**/