//file: Pride/PConvexHull/PConvexHullEdgeUtility.h
#ifndef _P_CONVEX_HULL_EDGE_UTILITY_H_
#define _P_CONVEX_HULL_EDGE_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;

};

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PConvexHullEdgeData;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;

	///////////////////////////////////////////////////////
	// class
	/**/
	struct PConvexHullEdgeUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PPlaneR3 >TArrayPlane;
		typedef Hubris::HContainerArray< PConvexHullEdgeData >TArrayData;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID EdgeDataCreate( 
			TArrayData& out_arrayEdgeData, 
			const TArrayPlane& in_arrayPlane 
			);

		static const Hubris::HBOOL EnclosedTest( const TArrayData& in_arrayEdgeData );

		static Hubris::HVOID PlaneLoopGather( 
			TArrayVector& out_arrayVector, 
			Hubris::HBOOL& out_closed,
			const TArrayData& in_arrayEdgeData, 
			const Hubris::HSINT in_planeIndex
			);

		static Hubris::HVOID PlaneArrayIndexTouchingGet(
			TArraySint& out_arrayIndexTouching,
			const TArrayData& in_arrayEdgeData, 
			const Hubris::HSINT in_planeIndex
			);

		static Hubris::HVOID VertexGather( const TArrayData& in_arrayEdgeData, TArrayVector& out_arrayVector, const Hubris::HREAL in_threashold );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PConvexHullEdgeUtility();


	};

	/**/	
};

#endif // _P_CONVEX_HULL_EDGE_UTILITY_H_