//file: Hubris/HMath/HMathVolume.h
#ifndef _H_MATH_VOLUME_H_
#define _H_MATH_VOLUME_H_

#include "Hubris/HCommon/HCommonType.h"

/* 
	helper unit to collect volume calculations
*/
namespace Hubris
{
	///////////////////////////////////////////////////////////////////
	// predefines
	template< typename IN_TYPE > class HContainerArray;
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;

	/**/
	/**/
	struct HMathVolume
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HMatrix< HREAL, 3, 1 >HVectorR3;
		typedef HContainerArray< HVectorR3 >TArrayVectorR3;

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HMathVolume();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		//return the volume of a sphere
		template< typename IN_TYPE >static const IN_TYPE VolumeSphere( const IN_TYPE& in_radius );

		// return the volume of intersection of two spheres
		template< typename IN_TYPE >static const IN_TYPE VolumeSphereIntersection( const IN_TYPE& in_radiusOne, const IN_TYPE& in_radiusTwo, const IN_TYPE& in_distance );

		//return the volume of a closed mesh, array size must be % 3
		static const HREAL VolumeClosedMesh( const TArrayVectorR3& in_arrayTriangleTriplets );

	};

	//template<>static const HREAL HMathVolume::VolumeSphere( const HREAL& in_radius );
	//template<>static const HREAL HMathVolume::VolumeSphereIntersection( const HREAL& in_radiusOne, const HREAL& in_radiusTwo, const HREAL& in_distance );

	/**/
};

#endif // _H_MATH_VOLUME_H_