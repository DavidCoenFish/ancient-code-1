//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduce.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_REDUCE_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_REDUCE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward define
	/**/
	class PConvexHullGenerateUtilityReduceData;
	class PInterfaceProgress;
	class PConvexHull;

	///////////////////////////////////////////////////////
	// class
	/*
		collect data for each hull, and merge them together untill under specified min	
	*/
	class PConvexHullGenerateUtilityReduce
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PConvexHull >TArrayConvexHull;
		typedef Hubris::HSmartPointer< PConvexHullGenerateUtilityReduceData >TDataPointer;
		typedef Hubris::HContainerArray< TDataPointer >TArrayData;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityReduce(
			TArrayConvexHull& in_arrayConvexHull,
			const Hubris::HSINT in_maxCount,
			PInterfaceProgress* const in_pProgress = HNULL
			);
		~PConvexHullGenerateUtilityReduce();

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID GatherHulls(
			TArrayConvexHull& out_arrayConvexHull
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		PConvexHullGenerateUtilityReduce( const PConvexHullGenerateUtilityReduce& in_rhs );
		const PConvexHullGenerateUtilityReduce& operator=( const PConvexHullGenerateUtilityReduce& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayData m_arrayData;

	};

	/**/
	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_REDUCE_H_