//file: Pride/PCamera/PCameraUtility.h
#ifndef _P_CAMERA_UTILITY_H_
#define _P_CAMERA_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PCamera;
	class PConvexHull;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PCameraUtility
	{
		///////////////////////////////////////////////////////
		// disabled
	private:
		~PCameraUtility();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static const PConvexHull FustrumFromCamera(
			const PCamera& in_camera
			);

		static const PSphereR3 SphereFromCamera(
			const PCamera& in_camera
			);

		static const Hubris::HVectorR3 AtFromCamera(
			const PCamera& in_camera
			);
		static const Hubris::HVectorR3 UpFromCamera(
			const PCamera& in_camera
			);
		static const Hubris::HVectorR3 RightFromCamera(
			const PCamera& in_camera
			);

	};

	/**/
};

#endif // _P_CAMERA_UTILITY_H_