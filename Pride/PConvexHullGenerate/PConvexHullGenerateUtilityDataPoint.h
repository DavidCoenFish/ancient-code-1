//file: PConvexHullGenerate/PConvexHullGenerateUtilityDataPoint.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_DATA_POINT_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_DATA_POINT_H_

#include "PConvexHullGenerate/PConvexHullGenerate_Import.h"

#include "PConvexHullGenerate/PConvexHullGenerateUtilityDataPointPlane.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PConvexHull;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityDataPoint
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilityDataPointPlane >TArrayDataPlane;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityDataPoint( const PConvexHullGenerateUtilityDataPoint& in_src );
		PConvexHullGenerateUtilityDataPoint();
		~PConvexHullGenerateUtilityDataPoint();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilityDataPoint& operator=( const PConvexHullGenerateUtilityDataPoint& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilityDataPoint& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilityDataPoint& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//create a hull from a point cloud
		const Hubris::HBOOL Create(
			const TArrayVector& in_pointCloud
			);

		//convert our plane data into hulls
		HVOID HullGet( PConvexHull& out_hull )const;

		///////////////////////////////////////////////////////
		// public accessor
	public:
		const TArrayVector& PointCloudGet()const{ return m_arrayPoints; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayDataPlane m_arrayPlane;
		TArrayVector m_arrayPoints;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_DATA_POINT_H_