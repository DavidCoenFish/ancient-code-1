//file: Sloth/SComponent/SComponentCameraTargetDistanceKeyData.h
#ifndef _S_COMPONENT_CAMERA_TARGET_DISTANCE_KEY_DATA_H_
#define _S_COMPONENT_CAMERA_TARGET_DISTANCE_KEY_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// class
/*
	distance key data for target camera

*/
namespace Sloth
{
	class SComponentCameraTargetDistanceKeyData
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentCameraTargetDistanceKeyData( const SComponentCameraTargetDistanceKeyData& in_src );
		SComponentCameraTargetDistanceKeyData(
			const Hubris::HREAL in_distance,
			const Hubris::HREAL in_targetElevation,
			const Hubris::HREAL in_cameraElevation,
			const Hubris::HREAL in_projectionTime
			);
		SComponentCameraTargetDistanceKeyData();
		~SComponentCameraTargetDistanceKeyData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const SComponentCameraTargetDistanceKeyData& operator=( const SComponentCameraTargetDistanceKeyData& in_rhs );
		const Hubris::HBOOL operator==( const SComponentCameraTargetDistanceKeyData& in_rhs )const;
		const Hubris::HBOOL operator!=( const SComponentCameraTargetDistanceKeyData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HREAL DistanceGet()const{ return m_distance; }
		Hubris::HVOID DistanceSet( const Hubris::HREAL in_distance ){ m_distance = in_distance; return; }

		const Hubris::HREAL TargetElevationGet()const{ return m_targetElevation; }
		Hubris::HVOID TargetElevationSet( const Hubris::HREAL in_targetElevation ){ m_targetElevation = in_targetElevation; return; }

		const Hubris::HREAL CameraElevationGet()const{ return m_cameraElevation; }
		Hubris::HVOID CameraElevationSet( const Hubris::HREAL in_cameraElevation ){ m_cameraElevation = in_cameraElevation; return; }

		const Hubris::HREAL ProjectionTimeGet()const{ return m_projectionTime; }
		Hubris::HVOID ProjectionTimeSet( const Hubris::HREAL in_projectionTime ){ m_projectionTime = in_projectionTime; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HREAL m_distance;
		Hubris::HREAL m_targetElevation;
		Hubris::HREAL m_cameraElevation;
		Hubris::HREAL m_projectionTime;
	};

	/**/
	
};

#endif // _S_COMPONENT_CAMERA_TARGET_DISTANCE_KEY_DATA_H_