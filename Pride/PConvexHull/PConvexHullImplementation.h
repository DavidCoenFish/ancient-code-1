//file: Pride/PConvexHull/PConvexHullImplementation.h
#ifndef _P_CONVEX_HULL_IMPLEMENTATION_H_
#define _P_CONVEX_HULL_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include "Pride/PPlane/PPlane_Export.h" //stl port workaround error C2139

namespace Hubris
{
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
	class PConvexHullEdge;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLineSegment;
	typedef PLineSegment< Hubris::HREAL, 2 >PLineSegmentR2;
	typedef PLineSegment< Hubris::HREAL, 3 >PLineSegmentR3;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PPlaneR3 >TArrayPlane;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< PLineSegmentR3 >TArrayLineSegment;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullImplementation( const PConvexHullImplementation& in_src );
		PConvexHullImplementation();
		~PConvexHullImplementation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullImplementation& operator=( const PConvexHullImplementation& in_rhs );
		Hubris::HBOOL operator==( const PConvexHullImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const PConvexHullImplementation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

		Hubris::HVOID DataSet(
			const TArrayPlane& in_arrayPlanes
			);

		Hubris::HVOID PlaneAdd( const PPlaneR3& in_plane );
		const Hubris::HSINT PlaneCountGet()const;

		const PPlaneR3& PlaneGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID PlaneSet( const Hubris::HSINT in_index, const PPlaneR3& in_plane );

		Hubris::HVOID PlaneRemove( const Hubris::HSINT in_index );

		Hubris::HVOID PlaneRemoveUnused();

		Hubris::HVOID PlaneLoopGather( 
			TArrayVector& out_arrayVector, 
			Hubris::HBOOL& out_closed,
			const Hubris::HSINT in_planeIndex
			);

		const TArrayVector& PointCloudGet();

		Hubris::HVOID PlaneArrayIndexTouchingGet(
			TArraySint& out_arrayIndexTouching,
			const Hubris::HSINT in_planeIndex
			);

		//no const accessor, if edge data is invalid, it regenerates
		const PConvexHullEdge& RefreashEdgeGet();

		///////////////////////////////////////////////////////
		// private methods
	private:
		const PConvexHullEdge& EdgeGet()const;
		PConvexHullEdge& EdgeGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayPlane m_arrayPlane;
		PConvexHullEdge* m_pEdge;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_IMPLEMENTATION_H_