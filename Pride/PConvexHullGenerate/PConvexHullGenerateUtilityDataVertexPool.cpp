//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataVertexPool.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityDataVertexPool.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HSINT >TTreeIntInt;

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityDataVertexPool::PConvexHullGenerateUtilityDataVertexPool(
	const TArrayVector& in_originalVertexPool,
	TArrayVector& in_out_newVertexPool
	)
: m_originalVertexPool( in_originalVertexPool )
, m_newVertexPool( in_out_newVertexPool )
, m_treeOriginalIndexNewIndex()
{
	return;
}

/**/
PConvexHullGenerateUtilityDataVertexPool::~PConvexHullGenerateUtilityDataVertexPool()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT PConvexHullGenerateUtilityDataVertexPool::RequestVertex(
	const Hubris::HSINT in_originalVertexIndex
	)
{
	HSINT newIndex = HCOMMON_INVALID_INDEX;
	TTreeIntInt::TIterator iterator = m_treeOriginalIndexNewIndex.Find( in_originalVertexIndex );
	if( iterator == m_treeOriginalIndexNewIndex.End() )
	{
		newIndex = HContainerUtility::PushBack( m_newVertexPool, m_originalVertexPool[ in_originalVertexIndex ] );
	
		m_treeOriginalIndexNewIndex.Insert( in_originalVertexIndex, newIndex );
	}
	else
	{
		newIndex = ( *iterator );
	}

	return newIndex;
}

/**/
