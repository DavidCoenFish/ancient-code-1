//file: Pride/PConvexHull/PConvexHull.h
#ifndef _P_CONVEX_HULL_H_
#define _P_CONVEX_HULL_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;

};

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	class PConvexHullImplementation;
	struct PConvexHullUtility;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;

	///////////////////////////////////////////////////////
	// class
	/*
		this class is for manageing the data of a convex hull
		see PConvexHullUtility for extracting information derived from the convex hull information
	*/
	class PConvexHull
	{
		friend PConvexHullUtility;

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Pride::PPlaneR3 >TArrayPlane;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHull( const PConvexHull& in_src );
		PConvexHull();
		~PConvexHull();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHull& operator=( const PConvexHull& in_rhs );
		Hubris::HBOOL operator==( const PConvexHull& in_rhs )const;
		Hubris::HBOOL operator!=( const PConvexHull& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

		//construct a hull given the array of planes and the array of points
		// we keep the points that are on the 'surface' of the planes, ie, not outside any plane
		Hubris::HVOID DataSet(
			const TArrayPlane& in_arrayPlanes
			);

		Hubris::HVOID PlaneAdd( const PPlaneR3& in_plane );
		const Hubris::HSINT PlaneCountGet()const;

		const PPlaneR3& PlaneGet( const Hubris::HSINT in_index )const;
		//plane set can dirty data, so don't jsut have non const PlaneGet
		Hubris::HVOID PlaneSet( const Hubris::HSINT in_index, const PPlaneR3& in_plane );

		Hubris::HVOID PlaneRemove( const Hubris::HSINT in_index );

		Hubris::HVOID PlaneRemoveUnused();

		const TArrayVector& PointCloudGet();

		//gather the array of touching plane index for the indexed plane
		Hubris::HVOID PlaneArrayIndexTouchingGet(
			TArraySint& out_arrayIndexTouching,
			const Hubris::HSINT in_planeIndex
			);

		//regenerate internal data if needed of if cached line segements now needed (speeds up plane removal)
		//HVOID RefreashInternalData( const Hubris::HBOOL in_cacheLineSegements = HFALSE );

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const PConvexHullImplementation& ImplementationGet()const;
		PConvexHullImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		PConvexHullImplementation* m_pImplementation;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_H_