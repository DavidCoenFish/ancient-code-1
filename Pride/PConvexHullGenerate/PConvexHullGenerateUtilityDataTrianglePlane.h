//file: PConvexHullGenerate/PConvexHullGenerateUtilityDataTrianglePlane.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_DATA_TRIANGLE_PLANE_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_DATA_TRIANGLE_PLANE_H_

#include "PConvexHullGenerate/PConvexHullGenerate_Import.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PMesh;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityDataTrianglePlane
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilityDataTrianglePlane >TArrayPlane;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityDataTrianglePlane( const PConvexHullGenerateUtilityDataTrianglePlane& in_src );
		//don't have data constructor as data may be invalid
		PConvexHullGenerateUtilityDataTrianglePlane();
		~PConvexHullGenerateUtilityDataTrianglePlane();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilityDataTrianglePlane& operator=( const PConvexHullGenerateUtilityDataTrianglePlane& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilityDataTrianglePlane& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilityDataTrianglePlane& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		HVOID DataSet(
			const Hubris::HSINT in_triangleIndex,
			const Hubris::HVectorR3& in_vectorOne,
			const Hubris::HVectorR3& in_vectorTwo,
			const Hubris::HVectorR3& in_vectorThree
			);

		HVOID TrianlgeAdd(
			const Hubris::HSINT in_triangleIndex
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TArraySint& ArrayTriangleIndexGet()const{ return m_arrayTranglesIndex; }
		const PPlaneR3& PlaneGet()const{ return m_plane; }

		///////////////////////////////////////////////////////
		// private members
	private:
		PPlaneR3 m_plane;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_DATA_TRIANGLE_PLANE_H_