//file: Pride/PConvexHull/PConvexHullUtility.h
#ifndef _P_CONVEX_HULL_UTILITY_H_
#define _P_CONVEX_HULL_UTILITY_H_

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
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;
	typedef PBounds< Hubris::HREAL, 3 >PBoundsR3;
	class PConvexHull;
	class PTriangle;
	class PMesh;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PConvexHullUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PTriangle >TArrayTriangle;
		typedef Hubris::HContainerArray< TArrayTriangle >TArrayArrayTriangle;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< PConvexHull >TArrayHull;

	public:
		struct TTriangleData{
			Hubris::HSINT m_planeIndex;
			Hubris::HBOOL m_messy;

			TTriangleData()
			: m_planeIndex( HCOMMON_INVALID_INDEX )
			, m_messy( HFALSE )
			{
				return;
			}
		};
		typedef Hubris::HContainerArray< TTriangleData >TArrayTriangleData;

		///////////////////////////////////////////////////////
		// public static methods
	public:
		//remove unused planes
		static Hubris::HVOID HullClean( PConvexHull& in_out_convexHull );

		//return true if hull is enclosed, ie, no open regions and has volume
		static const Hubris::HBOOL EnclosedTest( PConvexHull& in_out_convexHull );

		//get the bounds of an enclosed hull, assert on non valid hull
		static const PBoundsR3 BoundsGet( PConvexHull& in_out_convexHull );

		static Hubris::HVOID ConvertToMesh(
			PMesh& out_mesh,
			Hubris::HBOOL& out_open,
			Hubris::HBOOL& out_messy, //triangle normals not matching plane, or open edges
			TArrayTriangleData& out_triangleData,
			TArraySint& out_arrayUnusedPlaneIndex,
			PConvexHull& in_out_convexHull,
			const Hubris::HREAL in_pointMergeThreasholdPercentage = 0.001F
			);

		static Hubris::HVOID ConvertToTriangles(
			TArrayTriangle& out_arrayTriangles,
			PConvexHull& in_out_convexHull
			);

		static Hubris::HVOID ConvertToTriangles(
			TArrayReal& out_arrayTriangles,
			PConvexHull& in_out_convexHull
			);

		//volume of the bounding box get, zero if hull not valid
		static const Hubris::HREAL VolumeApproxGet( PConvexHull& in_out_convexHull );
		//volume of the mesh get, zero if hull not valid
		static const Hubris::HREAL VolumeGet( PConvexHull& in_out_convexHull );

		static Hubris::HVOID ScaleHull( PConvexHull& in_out_convexHull, const Hubris::HREAL in_scale );
		static Hubris::HVOID TranslateHull( PConvexHull& in_out_convexHull, const Hubris::HMatrixR4& in_transform );

		static const Hubris::HBOOL SphereHullTouch(
			const PConvexHull& in_hull,
			const PSphereR3& in_sphere
			);

		//return true if sphere is inside inclusive of hull
		static const Hubris::HBOOL SphereHullInside(
			const PConvexHull& in_hull,
			const PSphereR3& in_sphereTest
			);

		//TODO: hull inside? ouch
		//do sphere and hull inclusive make contact, is sphere fully inside hull
		static Hubris::HVOID SphereHullTest(
			Hubris::HBOOL& out_sphereInside,
			Hubris::HBOOL& out_touching,
			const PConvexHull& in_hull,
			const PSphereR3& in_sphereTest
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PConvexHullUtility();


	};

	/**/
	
};

#endif // _P_CONVEX_HULL_UTILITY_H_