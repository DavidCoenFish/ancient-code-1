//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduce.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceData.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceLine.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward define
	/**/
	class PConvexHullGenerateUtilityPlaneReduceData;
	class PConvexHullGenerateUtilityPlaneReduceLine;
	class PConvexHull;

	///////////////////////////////////////////////////////
	// class
	/*
		collect data for each hull, and merge them together untill under specified min	
	*/
	class PConvexHullGenerateUtilityPlaneReduce
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceData >TArrayData;
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceLine >TArrayLine;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityPlaneReduce(
			const PConvexHull& in_hull,
			const Hubris::HSINT in_maxPlaneCount
			);
		~PConvexHullGenerateUtilityPlaneReduce();

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID GatherHull(
			PConvexHull& out_hull
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		PConvexHullGenerateUtilityPlaneReduce( const PConvexHullGenerateUtilityPlaneReduce& in_rhs );
		const PConvexHullGenerateUtilityPlaneReduce& operator=( const PConvexHullGenerateUtilityPlaneReduce& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayData m_arrayData;
		TArrayLine m_arrayLines;

	};

	/**/
	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_H_