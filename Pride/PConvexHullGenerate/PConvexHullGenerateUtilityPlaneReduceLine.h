//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceLine.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_LINE_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_LINE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PLine/PLineSegment.h"

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

};

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward define
	/**/
	class PConvexHullGenerateUtilityPlaneReduceData;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityPlaneReduceLine
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceData >TArrayData;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityPlaneReduceLine( const PConvexHullGenerateUtilityPlaneReduceLine& in_src );
		PConvexHullGenerateUtilityPlaneReduceLine(
			PLineR3& in_line,
			const Hubris::HSINT in_planeIndexOne,
			const Hubris::HSINT in_planeIndexTwo
			);
		PConvexHullGenerateUtilityPlaneReduceLine();
		~PConvexHullGenerateUtilityPlaneReduceLine();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilityPlaneReduceLine& operator=( const PConvexHullGenerateUtilityPlaneReduceLine& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilityPlaneReduceLine& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilityPlaneReduceLine& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//trim our segement against planes, return true if 0 < length ( can be unbound )
		const Hubris::HBOOL TrimSegmentAgainstPlanes(
			const TArrayData& in_arrayData
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const PLineSegmentR3& LineSegmentGet()const{ return m_lineSegment; }
		const Hubris::HSINT PlaneIndexOneGet()const{ return m_planeIndexOne; }
		const Hubris::HSINT PlaneIndexTwoGet()const{ return m_planeIndexTwo; }

		///////////////////////////////////////////////////////
		// private members
	private:
		PLineSegmentR3 m_lineSegment;
		Hubris::HSINT m_planeIndexOne;
		Hubris::HSINT m_planeIndexTwo;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_LINE_H_