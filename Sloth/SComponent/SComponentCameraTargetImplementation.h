//file: Sloth/SComponent/SComponentCameraTargetImplementation.h
#ifndef _S_COMPONENT_CAMERA_TARGET_IMPLEMENTATION_H_
#define _S_COMPONENT_CAMERA_TARGET_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SComponent/SComponentCameraTargetDistanceKeyData.h"

#include< Lust/LSpring/LSpringParam.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInput;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentCameraTargetImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< SComponentCameraTargetDistanceKeyData >TArrayDistanceKeyData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentCameraTargetImplementation(
			const Pride::PCamera& in_setup,
			const Hubris::HREAL in_targetSpringAheadUnitSquared, //normalisation length to work out amount for target projection, zero for ignore
			const TArrayDistanceKeyData& in_arrayDistanceKeyData,
			const Lust::LSpringParam& in_targetSpringParam,
			const Lust::LSpringParam& in_cameraSpringParam,
			const Hubris::HVectorR3& in_initialCameraOffset, //initial camera offset from targets
			const TArrayVector& in_arrayInitialTarget,
			const Hubris::HREAL in_cameraScaleDistance = 5000.0F,
			const Hubris::HREAL in_cameraScaleRotation = 10000.0F
			);
		~SComponentCameraTargetImplementation();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SComponentCameraTargetImplementation( const SComponentCameraTargetImplementation& in_src );
		const SComponentCameraTargetImplementation& operator=( const SComponentCameraTargetImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Update(
			const Hubris::HREAL in_delta,
			const TArrayVector& in_arrayTargets,
			const Hubris::HVectorR3& in_cameraInput, //rotate camera left/ right, zoom camera in/ out
			const Hubris::HBOOL in_reset //erase history of movement, restore initial state of camera
			);

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID UpdateCamera();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PCamera& CameraGet()const{ return m_camera; }
		Pride::PCamera& CameraGet(){ return m_camera; }

		///////////////////////////////////////////////////////
		// private members
	private:
		//camera param
		Hubris::HREAL m_targetSpringAheadUnitSquared;
		TArrayDistanceKeyData m_arrayDistanceKeyData;
		Lust::LSpringParam m_targetSpringParam;
		Lust::LSpringParam m_cameraSpringParam;
		Hubris::HVectorR3 m_initialCameraOffset;
		Hubris::HREAL m_cameraScaleDistance;
		Hubris::HREAL m_cameraScaleRotation;
		Hubris::HREAL m_cameraMinDistance;
		Hubris::HREAL m_cameraMaxDistance;

		//working camera state
		//Hubris::HREAL m_targetVelocity;
		//Lust::LSpringParam m_targetProjectionParam;
		Hubris::HVectorR3 m_targetOld;
		//Hubris::HREAL m_oldDelta;
		Hubris::HVectorR3 m_targetProjectionSpringResult;
		Hubris::HVectorR3 m_targetProjectionSpringVelocity;
		Hubris::HVectorR3 m_cameraPosition;
		Hubris::HVectorR3 m_cameraPositionSpringResult;
		Hubris::HVectorR3 m_cameraPositionSpringVelocity;

		Hubris::HREAL m_cameraRotation;
		Hubris::HREAL m_cameraDistance;

		//end result
		Pride::PCamera m_camera;

	};

	/**/
	
};

#endif // _S_COMPONENT_CAMERA_TARGET_IMPLEMENTATION_H_