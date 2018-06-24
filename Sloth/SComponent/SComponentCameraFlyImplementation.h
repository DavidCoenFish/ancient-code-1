//file: Sloth/SComponent/SComponentCameraFlyImplementation.h
#ifndef _S_COMPONENT_CAMERA_FLY_IMPLEMENTATION_H_
#define _S_COMPONENT_CAMERA_FLY_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInput;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentCameraFlyImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentCameraFlyImplementation(
			const Pride::PCamera& in_setup
			);
		~SComponentCameraFlyImplementation();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SComponentCameraFlyImplementation( const SComponentCameraFlyImplementation& in_src );
		const SComponentCameraFlyImplementation& operator=( const SComponentCameraFlyImplementation& in_rhs );

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
		const Pride::PCamera& CameraGet()const{ return m_camera; }
		Pride::PCamera& CameraGet(){ return m_camera; }

		///////////////////////////////////////////////////////
		// private members
	private:
		//Hubris::HREAL m_latitude; //-180 ... 180 deg
		//Hubris::HREAL m_longitude; //-90 ... 90 deg

		Pride::PCamera m_camera;
		Hubris::HREAL m_translationScale;
		Hubris::HREAL m_rotationScale;

	};

	/**/
	
};

#endif // _S_COMPONENT_CAMERA_FLY_IMPLEMENTATION_H_