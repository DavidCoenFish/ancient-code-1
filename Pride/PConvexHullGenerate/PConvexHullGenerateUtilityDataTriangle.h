//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataTriangle.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_DATA_TRIANGLE_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_DATA_TRIANGLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PMesh;
	class PConvexHull;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityDataTriangle
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HBOOL >TArrayBool;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Pride::PPlaneR3 >TArrayPlane;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityDataTriangle( const PConvexHullGenerateUtilityDataTriangle& in_src );
		PConvexHullGenerateUtilityDataTriangle();
		~PConvexHullGenerateUtilityDataTriangle();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilityDataTriangle& operator=( const PConvexHullGenerateUtilityDataTriangle& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilityDataTriangle& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilityDataTriangle& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//create a hull by flowing along triangles in mesh
		const Hubris::HBOOL Create(
			TArrayBool& in_out_arrayFaceUsage,
			PMesh& in_mesh,
			const Hubris::HREAL in_depth,
			const Hubris::HSINT in_seedIndex
			);

		///////////////////////////////////////////////////////
		// public accessor
	public:
		const TArrayVector& PointCloudGet()const{ return m_arrayPoints; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayVector m_arrayPoints;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_DATA_TRIANGLE_H_