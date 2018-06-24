//file: Sloth/SComponent/SComponentCameraFly.h
#ifndef _S_COMPONENT_CAMERA_FLY_H_
#define _S_COMPONENT_CAMERA_FLY_H_

#include< Hubris/HCommon/HCommon_Export.h >
namespace Pride
{
	class PCamera;
};

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SComponentCameraFlyImplementation;
	class SInput;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentCameraFly
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentCameraFly(
			const Pride::PCamera& in_setup
			);
		~SComponentCameraFly();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentCameraFly( const SComponentCameraFly& in_src );
		const SComponentCameraFly& operator=( const SComponentCameraFly& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Update(
			const Hubris::HREAL in_delta,
			const SInput& in_input
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PCamera& CameraGet()const;
		Pride::PCamera& CameraGet(); //non const accessors to access camera hull, which may need to be generated

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SComponentCameraFlyImplementation& ImplementationGet()const;
		SComponentCameraFlyImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SComponentCameraFlyImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_COMPONENT_CAMERA_FLY_H_