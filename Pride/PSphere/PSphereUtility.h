//file: Pride/PSphere/PSphereUtility.h
#ifndef _P_SPHERE_UTILITY_H_
#define _P_SPHERE_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >


namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;

};


namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PUnitVector;
	typedef PUnitVector< Hubris::HREAL, 2 >PUnitVectorR2;
	typedef PUnitVector< Hubris::HREAL, 3 >PUnitVectorR3;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PSphereUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PSphereR3 >TArraySphere;
		typedef Hubris::HContainerArray< PSphereR2 >TArraySphere2D;

		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector2D;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< TArraySint >TArrayArraySint;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//translate sphere by matrix, return new sphere
		static const PSphereR3 SphereTranslate( 
			const PSphereR3& in_sphere,
			const Hubris::HMatrixR4& in_matrix
			);

		//attempt to construct a sphere from 4 point, return false on faliure (either coplanar or three are colinear)
		static const Hubris::HBOOL SphereFromPoints(
			Pride::PSphereR3& out_sphere,
			const Hubris::HVectorR3 in_pointOne,
			const Hubris::HVectorR3 in_pointTwo,
			const Hubris::HVectorR3 in_pointThree,
			const Hubris::HVectorR3 in_pointFour
			);

		static const PSphereR3 SphereMerge(
			const PSphereR3& in_lhs,
			const PSphereR3& in_rhs
			);

		static const PSphereR3 SphereMerge(
			const TArraySphere& in_arraySphere
			);

		// given a list of sphere, and target number, return the merge list
		static Hubris::HVOID SphereListReduce(
			TArrayArraySint& out_mergeList,
			const TArraySphere& in_arraySphere,
			const Hubris::HSINT in_maxCount
			);

		//return true if sphere test is inside or equal to master sphere
		static const Hubris::HBOOL SphereEqualOrInside(
			const PSphereR3& in_sphereMaster,
			const PSphereR3& in_sphereEqualInsideTest
			);

		//return true if lhs sphere touches rhs (evem just surface, two 1 unit spheres 2 units appart touch
		static const Hubris::HBOOL SphereTouching(
			const PSphereR3& in_sphereLhs,
			const PSphereR3& in_sphereRhs
			);

		static Hubris::HVOID SphereTouchingTest(
			Hubris::HBOOL& out_sphereInside,
			Hubris::HBOOL& out_sphereTouching,
			const PSphereR3& in_sphereMaster,
			const PSphereR3& in_sphereInsideTouchingTest
			);

		static const Hubris::HBOOL PointInsideInclusive( 
			const PSphereR3& in_sphere,
			const Hubris::HVectorR3& in_point
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PSphereUtility();

	};

	/**/	
};

#endif // _P_SPHERE_UTILITY_H_