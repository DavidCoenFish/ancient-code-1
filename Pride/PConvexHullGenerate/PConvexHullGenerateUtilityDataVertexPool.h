//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataVertexPool.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_DATA_VERTEX_POOL_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_DATA_VERTEX_POOL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilityDataVertexPool
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HSINT >TTreeIntInt;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilityDataVertexPool(
			const TArrayVector& in_originalVertexPool,
			TArrayVector& in_out_newVertexPool
			);
		~PConvexHullGenerateUtilityDataVertexPool();

		///////////////////////////////////////////////////////
		// disabled
	public:
		PConvexHullGenerateUtilityDataVertexPool( const PConvexHullGenerateUtilityDataVertexPool& in_src );
		const PConvexHullGenerateUtilityDataVertexPool& operator=( const PConvexHullGenerateUtilityDataVertexPool& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT RequestVertex(
			const Hubris::HSINT in_originalVertexIndex
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		const TArrayVector& m_originalVertexPool;
		TArrayVector& m_newVertexPool;
		TTreeIntInt m_treeOriginalIndexNewIndex;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_DATA_VERTEX_POOL_H_