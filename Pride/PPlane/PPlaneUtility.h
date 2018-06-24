//file: Pride/PPlane/PPlaneUtility.h
#ifndef _P_PLANE_UTILITY_H_
#define _P_PLANE_UTILITY_H_

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
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PPlaneUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector2D;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//return true if we could constuct plane, points not coincident or colinear
		static const Hubris::HBOOL ConstructPlane( 
			PPlaneR2& out_plane, 
			const Hubris::HVectorR2& in_pointOne,
			const Hubris::HVectorR2& in_pointTwo
			);
		static const Hubris::HBOOL ConstructPlane( 
			PPlaneR3& out_plane, 
			const Hubris::HVectorR3& in_pointOne,
			const Hubris::HVectorR3& in_pointTwo,
			const Hubris::HVectorR3& in_pointThree
			);

		static const PPlaneR3 TranslatePlane( 
			const PPlaneR3& in_plane, 
			const Hubris::HMatrixR4& in_transform
			);

		//point plane in opposite direction, but sill over same point
		static const PPlaneR2 PlaneFlip( const PPlaneR2& in_plane );
		static const PPlaneR3 PlaneFlip( const PPlaneR3& in_plane );

		static const Hubris::HREAL DistanceFromPlaneGet( const PPlaneR2& in_plane, const Hubris::HVectorR2& in_point );
		static const Hubris::HREAL DistanceFromPlaneGet( const PPlaneR3& in_plane, const Hubris::HVectorR3& in_point );

		static const Hubris::HBOOL DirectionParallelToPlaneTest( 
			const PPlaneR2& in_plane, 
			const PUnitVectorR2& in_direction, 
			const Hubris::HREAL in_delta = 0.000001F // = Hubris::HVariablesMath::EpsilonGet< Hubris::HREAL >()
			);
		static const Hubris::HBOOL DirectionParallelToPlaneTest( 
			const PPlaneR3& in_plane, 
			const PUnitVectorR3& in_direction, 
			const Hubris::HREAL in_delta = 0.000001F // = Hubris::HVariablesMath::EpsilonGet< Hubris::HREAL >()
			);

		//return true if two planes are within delta of each other
		static const Hubris::HBOOL EqualDelta( 
			const PPlaneR2& in_planeLhs, 
			const PPlaneR2& in_planeRhs, 
			const Hubris::HREAL in_deltaDirection,
			const Hubris::HREAL in_deltaDistance
			);
		static const Hubris::HBOOL EqualDelta( 
			const PPlaneR3& in_planeLhs, 
			const PPlaneR3& in_planeRhs, 
			const Hubris::HREAL in_deltaDirection,
			const Hubris::HREAL in_deltaDistance
			);
		
		//given a plane, project the given points onto the surface, output array of 2d points
		static Hubris::HVOID ProjectOntoPlane( 
			TArrayVector2D& out_arrayPoints2D,
			const TArrayVector& in_pointCloud, 
			const PPlaneR3& in_plane 
			);

		//inside or touching (distance - radius <= 0) sphere and plane
		static const Hubris::HBOOL SphereTouchPlane( 
			const PPlaneR3& in_plane,
			const PSphereR3& in_sphere
			);

		//inside or touching (distance + radius <= 0) sphere is inside inclusive of plane
		static const Hubris::HBOOL SphereInsidePlane( 
			const PPlaneR3& in_plane,
			const PSphereR3& in_sphere
			);

		//inclusive
		static const Hubris::HBOOL PointInsidePlane(
			const PPlaneR3& in_plane,
			const Hubris::HVectorR3& in_point
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PPlaneUtility();

	};

	/**/	
};

#endif // _P_PLANE_UTILITY_H_