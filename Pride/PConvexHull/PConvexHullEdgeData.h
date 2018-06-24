//file: Pride/PConvexHull/PConvexHullEdgeData.h
#ifndef _P_CONVEX_HULL_EDGE_DATA_H_
#define _P_CONVEX_HULL_EDGE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PLine/PLineSegment.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullEdgeData
	{
		///////////////////////////////////////////////////////
		// typedef

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullEdgeData( const PConvexHullEdgeData& in_src );
		PConvexHullEdgeData( 
			const PLineSegmentR3& m_lineSegment, 
			const Hubris::HSINT in_indexOne, 
			const Hubris::HSINT in_indexTwo 
			);
		PConvexHullEdgeData();
		~PConvexHullEdgeData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullEdgeData& operator=( const PConvexHullEdgeData& in_rhs );
		Hubris::HBOOL operator==( const PConvexHullEdgeData& in_rhs )const;
		Hubris::HBOOL operator!=( const PConvexHullEdgeData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const PLineSegmentR3& LineSegmentGet()const{ return m_lineSegment; }
		Hubris::HVOID LineSegmentSet( const PLineSegmentR3& in_lineSegment ){ m_lineSegment = in_lineSegment; return; }

		const Hubris::HSINT PlaneIndexOneGet()const{ return m_planeIndexOne; }
		Hubris::HVOID PlaneIndexOneSet( const Hubris::HSINT in_planeIndexOne ){ m_planeIndexOne = in_planeIndexOne; return; }

		const Hubris::HSINT PlaneIndexTwoGet()const{ return m_planeIndexTwo; }
		Hubris::HVOID PlaneIndexTwoSet( const Hubris::HSINT in_planeIndexTwo ){ m_planeIndexTwo = in_planeIndexTwo; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		PLineSegmentR3 m_lineSegment;
		Hubris::HSINT m_planeIndexOne;
		Hubris::HSINT m_planeIndexTwo;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_EDGE_DATA_H_