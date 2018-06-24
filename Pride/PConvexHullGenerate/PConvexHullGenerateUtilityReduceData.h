//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduceData.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_REDUCE_DATA_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_REDUCE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >
#include "Pride/PConvexHull/PConvexHull.h"

#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward define
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityReduceData : public Hubris::HSmartPointerObjectBase< PConvexHullGenerateUtilityReduceData >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HSmartPointer< PConvexHullGenerateUtilityReduceData >TDataPointer;
		typedef Hubris::HContainerArray< TDataPointer >TArrayData;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityReduceData( const PConvexHullGenerateUtilityReduceData& in_src );
		PConvexHullGenerateUtilityReduceData(
			const PConvexHull in_convexHull
			);
		PConvexHullGenerateUtilityReduceData();
		~PConvexHullGenerateUtilityReduceData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilityReduceData& operator=( const PConvexHullGenerateUtilityReduceData& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilityReduceData& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilityReduceData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID HullSet( 
			const PConvexHull& in_convexHull
			);

		Hubris::HVOID CalculateValues(
			const Hubris::HSINT in_ourIndex,
			const TArrayData& in_dataArray
			);

		Hubris::HVOID DataAppend(
			const Hubris::HSINT in_ourIndex,
			const PConvexHullGenerateUtilityReduceData& in_data
			);

		Hubris::HVOID RemoveDataIndex( const Hubris::HSINT in_removedIndex, const Hubris::HSINT in_ourIndex );
		Hubris::HVOID BestValueGet( 
			Hubris::HSINT& in_out_bestDataIndexOne, 
			Hubris::HSINT& in_out_bestDataIndexTwo, 
			Hubris::HREAL& in_out_bestValue, 
			const Hubris::HSINT in_ourIndex 
			)const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const PConvexHull& HullGet()const{ return m_convexHull; }
		PConvexHull& HullGet(){ return m_convexHull; }

		//const Hubris::HVectorR3& LocationGet()const{ return m_location; }
		//const Hubris::HREAL RadiusGet()const{ return m_radius; }

		///////////////////////////////////////////////////////
		// private members
	private:
		PConvexHull m_convexHull;
		Hubris::HVectorR3 m_location;
		Hubris::HREAL m_radius;

		TArrayReal m_arrayValue;
		Hubris::HSINT m_externalDataArrayIndexBest;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_REDUCE_DATA_H_