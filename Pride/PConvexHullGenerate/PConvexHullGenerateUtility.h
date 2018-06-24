//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtility.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_H_

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
	// predefs
	/**/
	class PConvexHull;
	class PInterfaceProgress;
	class PMesh;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PConvexHullGenerateUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< PConvexHull >TArrayHull;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector2D;

		///////////////////////////////////////////////////////
		// public static methods
	public:
		//given a mesh, generate convex hulls by flowing over adjacent triangels in the mesh
		static Hubris::HVOID GenerateHulls( 
			TArrayHull& out_arrayHull, 
			PMesh& in_mesh,
			const Hubris::HREAL in_depth = 0.0F, // = Hubris::HVariablesMath::ZeroGet< Hubris::HREAL >(),
			PInterfaceProgress* const in_pProgress = HNULL
			);

		//given a point cloud, fold a convex hull over the points
		// return false on data error
		static const Hubris::HBOOL CreateHullFromPointCloud( 
			PConvexHull& out_convexHull,
			const TArrayVector& in_pointCloud,
			PInterfaceProgress* const in_pProgress = HNULL,
			const Hubris::HREAL in_pointCloudMergePercentage = 0.01F
			);

		static const Hubris::HBOOL CreateProfileFromPointCloud2D( 
			TArraySint& out_arrayIndex,
			const TArrayVector2D& in_pointCloud,
			PInterfaceProgress* const in_pProgress = HNULL
			);

		//given a array of hulls, reduce the hull count to maxHulls
		static Hubris::HVOID ReduceHullCount( 
			TArrayHull& in_out_arrayHull, 
			const Hubris::HSINT in_maxHullCount,// = Hubris::HVariablesMath::MaximumGet< Hubris::HSINT >(),
			PInterfaceProgress* const in_pProgress = HNULL
			);

		static Hubris::HVOID ReducePlaneMerge(
			PConvexHull& in_out_hull,
			const Hubris::HREAL in_mergeDirection,
			const Hubris::HREAL in_mergeLength,
			PInterfaceProgress* const in_pProgress = HNULL
			);

		//reduce HULL down to plane count hit or not able to remove any more planes without hull being open
		static Hubris::HVOID ReducePlaneCount(
			PConvexHull& in_out_hull,
			const Hubris::HSINT in_maxPlaneCount,// = Hubris::HVariablesMath::MaximumGet< Hubris::HSINT >(),
			PInterfaceProgress* const in_pProgress = HNULL
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PConvexHullGenerateUtility();


	};

	/**/
	
};

#endif // _P_CONVEX_HULL_UTILITY_H_