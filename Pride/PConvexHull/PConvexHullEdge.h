//file: Pride/PConvexHull/PConvexHullEdge.h
#ifndef _P_CONVEX_HULL_EDGE_H_
#define _P_CONVEX_HULL_EDGE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PConvexHull/PConvexHullEdgeData.h"
#include< Hubris/HContainer/HContainer_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullEdge
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PPlaneR3 >TArrayPlane;
		typedef Hubris::HContainerArray< PConvexHullEdgeData >TArrayData;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullEdge( const PConvexHullEdge& in_src );
		PConvexHullEdge();
		~PConvexHullEdge();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullEdge& operator=( const PConvexHullEdge& in_rhs );
		Hubris::HBOOL operator==( const PConvexHullEdge& in_rhs )const;
		Hubris::HBOOL operator!=( const PConvexHullEdge& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DataSet( 
			const TArrayPlane& in_arrayPlanes
			);

		//refreash data if needed, clears dirty flag
		Hubris::HVOID Refreash( 
			const TArrayPlane& in_arrayPlanes
			);

		//assert if dirty
		const Hubris::HBOOL PlaneUseQuery( 
			const Hubris::HSINT in_planeIndex
			)const;

		//assert if dirty
		//gather a loop of verticies, if closed == false, array of vectors is segment pairs
		Hubris::HVOID PlaneLoopGather( 
			TArrayVector& out_arrayVector, 
			Hubris::HBOOL& out_closed, 
			const Hubris::HSINT in_planeIndex
			)const;

		Hubris::HVOID PlaneArrayIndexTouchingGet(
			TArraySint& out_arrayIndexTouching,
			const Hubris::HSINT in_planeIndex
			)const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		//external dirty set for when plane added or changed
		Hubris::HVOID DirtySet(){ m_dirty = HTRUE; return; }

		//assert if data is dirty
		const Hubris::HBOOL EnclosedGet()const;

		const TArrayVector& PointCloudGet()const;

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayVector m_pointCloud;
		TArrayData m_arrayData;
		//TArraySint m_arrayUsedPlaneIndex;
		//if any segments are unbound, then enclosed is false
		Hubris::HBOOL m_enclosed;
		//if data change has occured since last refreash, flag as dirty
		Hubris::HBOOL m_dirty;


	};

	/**/	
};

#endif // _P_CONVEX_HULL_EDGE_H_