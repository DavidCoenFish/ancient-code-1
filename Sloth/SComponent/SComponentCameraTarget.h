//file: Sloth/SComponent/SComponentCameraTarget.h
#ifndef _S_COMPONENT_CAMERA_TARGET_H_
#define _S_COMPONENT_CAMERA_TARGET_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Pride
{
	class PCamera;
};
namespace Lust
{
	class LSpringParam;
};
namespace Sloth
{
	class SComponentCameraTargetImplementation;
	class SComponentCameraTargetDistanceKeyData;
};

///////////////////////////////////////////////////////
// class
/*
	simple camera following array of targets.

*/
namespace Sloth
{
	class SComponentCameraTarget
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< SComponentCameraTargetDistanceKeyData >TArrayDistanceKeyData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentCameraTarget(
			const Pride::PCamera& in_setup, //near, far, left, right, get used, matrix from initialTarget and initialCameraOffset
			const Hubris::HREAL in_targetSpringAheadUnitSquared, //normalisation length to work out amount for target projection, zero for ignore
			const TArrayDistanceKeyData& in_arrayDistanceKeyData,
			const Lust::LSpringParam& in_targetSpringParam,
			const Lust::LSpringParam& in_cameraSpringParam,
			const Hubris::HVectorR3& in_initialCameraOffset, //initial camera offset from targets
			const TArrayVector& in_arrayInitialTarget
			);
		~SComponentCameraTarget();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentCameraTarget( const SComponentCameraTarget& in_src );
		const SComponentCameraTarget& operator=( const SComponentCameraTarget& in_rhs );

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
		// public accessors
	public:
		const Pride::PCamera& CameraGet()const;
		Pride::PCamera& CameraGet(); //non const accessors to access camera hull, which may need to be generated

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SComponentCameraTargetImplementation& ImplementationGet()const;
		SComponentCameraTargetImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SComponentCameraTargetImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_COMPONENT_CAMERA_TARGET_H_