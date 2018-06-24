//file: Pride/PIntersection/PIntersectionUtility.h
#ifndef _P_INTERSECTION_UTILITY_H_
#define _P_INTERSECTION_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;

};

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward define
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLine;
	typedef PLine< Hubris::HREAL, 2 >PLineR2;
	typedef PLine< Hubris::HREAL, 3 >PLineR3;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;
	typedef PBounds< Hubris::HREAL, 1 >PBoundsR1;
	typedef PBounds< Hubris::HREAL, 2 >PBoundsR2;
	typedef PBounds< Hubris::HREAL, 3 >PBoundsR3;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;

	class PConvexHull;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PIntersectionUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

		///////////////////////////////////////////////////////
		// public static methods
	public:
		//return true is there is an intersection with line (no line bounds check)
		// rem. with the intersection points, can get the normal by offset intesection to certer div by radius....
		static const Hubris::HBOOL LineSphereIntersect( 
			const PSphereR3& in_sphere,
			const PLineR3& in_line,
			Hubris::HREAL* const out_pRatioOnLineNear = HNULL, 
			Hubris::HREAL* const out_pRatioOnLineFar = HNULL
			);

		//return true is there is a point intersect (planes and line not perpendicular or coincident) find point of intersection of plane and line
		static const Hubris::HBOOL PlaneLineIntersect( 
			Hubris::HREAL& out_ratioOnLine, 
			const PPlaneR2& in_plane,
			const PLineR2& in_line
			);
		static const Hubris::HBOOL PlaneLineIntersect( 
			Hubris::HREAL& out_ratioOnLine, 
			const PPlaneR3& in_plane,
			const PLineR3& in_line
			);

		//return true is there is a line intersect (planes not parrale or coincident) find line of intersection of two planes
		static const Hubris::HBOOL PlanePlaneIntersect( 
			PLineR3& out_line, 
			const PPlaneR3& in_planeOne,
			const PPlaneR3& in_planeTwo
			);

		//return true if there is a point of intersection of three planes
		static const Hubris::HBOOL PlanePlanePlaneIntersect( 
			Hubris::HVectorR3& out_point, 
			const PPlaneR3& in_planeOne,
			const PPlaneR3& in_planeTwo,
			const PPlaneR3& in_planeThree
			);

		//return true if any point is inside hull
		static const Hubris::HBOOL ArrayPointInsideHull(
			PConvexHull& in_out_hull,
			const TArrayVector& in_arrayVector,
			const Hubris::HREAL in_delta = 0.0F //add to hull thickness, give small neg if you dont want points on surface returning as inside
			);

		static const Hubris::HBOOL PointInsideHull(
			PConvexHull& in_out_hull,
			const Hubris::HVectorR3& in_vector,
			const Hubris::HREAL in_delta = 0.0F
			);

		//static const Hubris::HBOOL PointInsideBounds(
		//	const PBoundsR3& in_bounds,
		//	const Hubris::HVectorR3& in_vector
		//	);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PIntersectionUtility();

	};

	/**/
	
};

#endif // _P_INTERSECTION_UTILITY_H_