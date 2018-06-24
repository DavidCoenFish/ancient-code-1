//file: PConvexHullGenerate/PConvexHullGenerateUtilityDataPointPlane.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_DATA_POINT_PLANE_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_DATA_POINT_PLANE_H_

#include "PConvexHullGenerate/PConvexHullGenerate_Import.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityDataPointPlane
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityDataPointPlane( const PConvexHullGenerateUtilityDataPointPlane& in_src );
		//don't have data constructor as data may be invalid
		PConvexHullGenerateUtilityDataPointPlane();
		~PConvexHullGenerateUtilityDataPointPlane();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilityDataPointPlane& operator=( const PConvexHullGenerateUtilityDataPointPlane& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilityDataPointPlane& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilityDataPointPlane& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL DataSet(
			const TArrayVector& in_arrayVertex,
			const Hubris::HSINT in_vertexIndexOne,
			const Hubris::HSINT in_vertexIndexTwo,
			const Hubris::HSINT in_vertexIndexThree
			);
		
		///////////////////////////////////////////////////////
		// public accessors
	public:
		const PPlaneR3& PlaneGet()const{ return m_plane; }
		const TArraySint& ArrayEdgeLoopVertexIndexGet()const{ return m_arrayEdgeLoopVertexIndex; }

		const Hubris::HSINT EdgeLoopTouchingCountGet()const;
		const Hubris::HSINT EdgeLoopTouchingGet( const Hubris::HSINT in_edgeIndex )const;
		HVOID EdgeLoopTouchingSet( const Hubris::HSINT in_edgeIndex, const Hubris::HSINT in_planeTouchingIndex );

		///////////////////////////////////////////////////////
		// private members
	private:
		PPlaneR3 m_plane;
		TArraySint m_arrayEdgeLoopVertexIndex;
		TArraySint m_arrayEdgeLoopTouching;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_DATA_POINT_PLANE_H_