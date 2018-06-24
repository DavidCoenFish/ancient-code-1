//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceData.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_DATA_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PPlane/PPlane.h"
#include< Hubris/HContainer/HContainer_Export.h >
namespace Pride
{
	///////////////////////////////////////////////////////
	// forward define
	/**/
	class PConvexHullGenerateUtilityPlaneReduceLine;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityPlaneReduceData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceData >TArrayData;
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceLine >TArrayLine;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityPlaneReduceData( const PConvexHullGenerateUtilityPlaneReduceData& in_src );
		PConvexHullGenerateUtilityPlaneReduceData(
			const PPlaneR3& in_plane
			);
		PConvexHullGenerateUtilityPlaneReduceData();
		~PConvexHullGenerateUtilityPlaneReduceData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilityPlaneReduceData& operator=( const PConvexHullGenerateUtilityPlaneReduceData& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilityPlaneReduceData& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilityPlaneReduceData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HREAL CalculateRemovedVolume( 
			const TArrayLine& in_arrayLine,
			const TArrayData& in_arrayData,
			const Hubris::HSINT in_ourIndex 
			)const;

		Hubris::HVOID ArrayLineIndexClear();
		Hubris::HVOID ArrayLineIndexAdd( const Hubris::HSINT in_lineIndex );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HBOOL PlaneInUseGet()const{ return m_planeInUse; };
		Hubris::HVOID PlaneInUseSet( const Hubris::HBOOL in_planeInUse ){ m_planeInUse = in_planeInUse; return; };

		const PPlaneR3& PlaneGet()const{ return m_plane; }
		Hubris::HVOID PlaneSet( const PPlaneR3& in_plane ){ m_plane = in_plane; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		PPlaneR3 m_plane;
		Hubris::HBOOL m_planeInUse;
		TArraySint m_arrayLineIndex;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_PLANE_REDUCE_DATA_H_