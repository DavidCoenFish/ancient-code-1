//file: Vanity/VScene/VSceneComponentSphereTreeBuild.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneComponentSphereTreeBuild.h"

#include "Vanity/VScene/VSceneNode.h"
#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneComponentSphereCollection.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HSINT >TPairSintSint;
typedef Hubris::HContainerPair< Pride::PSphereR3, TPairSintSint >TPairSpherePairSintSint;
typedef Hubris::HContainerArray< TPairSpherePairSintSint >TArrayPairSpherePairSintSint;
typedef Hubris::HContainerArray< Pride::PSphereR3 >TArrayPrideSphere;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< TArraySint >TArrayArraySint;

///////////////////////////////////////////////////////
// static local methods
/**/
static Hubris::HVOID LocalMergeSphere(
	TArrayArraySint& out_mergeList,
	const TArrayPairSpherePairSintSint& in_srcData
	)
{
	TArrayPrideSphere arrayPrideSphereMerge;
	HCOMMON_FOR_EACH_CONST( data, in_srcData, TArrayPairSpherePairSintSint )
	{
		arrayPrideSphereMerge.Insert( data.m_first );
	}

	const HSINT totalCount = arrayPrideSphereMerge.SizeGet();
	const HSINT reduceTarget = HMathUtility::Maximum( 1, totalCount >> 2 );

	//workout where sphere to merge to get to target reduceCount
	PSphereUtility::SphereListReduce(
		out_mergeList,
		arrayPrideSphereMerge,
		reduceTarget
		);

	return;
}

/**/
static Hubris::HVOID LocalReduceCount(
	const TArrayPairSpherePairSintSint& in_srcData,
	TArrayNode& in_out_arrayNode,
	TArraySphere& in_out_arraySphere,
	VSceneComponentNodeCollection& in_out_nodeOutsideTree,
	VSceneComponentSphereCollection& in_out_topSphereCollection
	)
{
	if( in_srcData.SizeGet() <= 4 )
	{
		for( HSINT index = 0; index < in_srcData.SizeGet(); ++index )
		{
			const TPairSintSint& data = in_srcData[ index ].m_second;
			if( HCOMMON_INVALID_INDEX != data.m_first )
			{
				in_out_arrayNode[ data.m_first ].ParentSphereIndexSet( HCOMMON_INVALID_INDEX );
				in_out_nodeOutsideTree.ArrayChildrenNodeIndexGet().Insert( data.m_first );
			}
			else if( HCOMMON_INVALID_INDEX != data.m_second )
			{
				in_out_arraySphere[ data.m_second ].ParentSphereIndexSet( HCOMMON_INVALID_INDEX );
				in_out_topSphereCollection.ArrayChildrenSphereIndexGet().Insert( data.m_second );
			}
		}

		return;
	}

	TArrayArraySint mergeList;
	LocalMergeSphere(
		mergeList,
		in_srcData
		);

	//perform merge
	TArrayPairSpherePairSintSint nextGeneration;
	HCOMMON_FOR_EACH_CONST( mergeArray, mergeList, TArrayArraySint )
	{
		if( 0 == mergeArray.SizeGet() )
		{
			//assert?
			continue;
		}
		if( 1 == mergeArray.SizeGet() )
		{
			//no merge, just a lone node or sphere
			nextGeneration.Insert( in_srcData[ mergeArray[ 0 ] ] );
			continue;
		}

		//calculate containg sphere
		TArrayPrideSphere arrayPrideSphereContain;
		for( HSINT index = 0; index < mergeArray.SizeGet(); ++index )
		{
			arrayPrideSphereContain.Insert( in_srcData[ mergeArray[ index ] ].m_first );
		}
		const PSphereR3 containSphere = PSphereUtility::SphereMerge( arrayPrideSphereContain );

		const HSINT sphereIndex = HContainerUtility::PushBack( in_out_arraySphere, VSceneComponentSphereTreeSphere( containSphere, HCOMMON_INVALID_INDEX ) );
		VSceneComponentSphereTreeSphere& sphere = in_out_arraySphere[ sphereIndex ];

		for( HSINT index = 0; index < mergeArray.SizeGet(); ++index )
		{
			const TPairSintSint& data = in_srcData[ mergeArray[ index ] ].m_second;
			if( HCOMMON_INVALID_INDEX != data.m_first )
			{
				in_out_arrayNode[ data.m_first ].ParentSphereIndexSet( sphereIndex );
				sphere.NodeCollectionGet().ArrayChildrenNodeIndexGet().Insert( data.m_first );
			}
			else if( HCOMMON_INVALID_INDEX != data.m_second )
			{
				in_out_arraySphere[ data.m_second ].ParentSphereIndexSet( sphereIndex );
			}
		}

		nextGeneration.Insert( TPairSpherePairSintSint( containSphere, TPairSintSint( HCOMMON_INVALID_INDEX, sphereIndex ) ) );
	}

	LocalReduceCount( 
		nextGeneration,
		in_out_arrayNode,
		in_out_arraySphere,
		in_out_nodeOutsideTree,
		in_out_topSphereCollection
		);

	return;
}

/**/
static Hubris::HVOID LocalUpdateFlag(
	TArrayNode& in_out_arrayNode,
	TArraySphere& in_out_arraySphere,
	VSceneComponentSphereCollection& in_out_topSphereCollection
	)
{
	HCOMMON_FOR_EACH_CONST( sphereIndex, in_out_topSphereCollection.ArrayChildrenSphereIndexGet(), TArraySint )
	{
		VSceneComponentSphereTreeSphere& sphere = in_out_arraySphere[ sphereIndex ];
		LocalUpdateFlag( 
			in_out_arrayNode,
			in_out_arraySphere,
			sphere.SphereCollectionGet()
			);

		sphere.NodeCollectionGet().ComponentFlagUpdate( in_out_arrayNode );
		//sphere.SphereCollectionGet().ComponentFlagUpdate( in_out_arraySphere );
	}

	in_out_topSphereCollection.ComponentFlagUpdate( in_out_arraySphere );

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VSceneComponentSphereTreeBuild::Build(
	TArrayNode& in_out_arrayNode,
	TArraySphere& in_out_arraySphere,
	VSceneComponentNodeCollection& in_out_nodeOutsideTree,
	VSceneComponentSphereCollection& in_out_sphereCollection
	)
{
	TArrayPairSpherePairSintSint arrayData;
	for( HSINT index = 0; index < in_out_arrayNode.SizeGet(); ++index )
	{
		const VSceneNode& node = in_out_arrayNode[ index ];
	
		if( HFALSE == node.NodeInUseTest() )
		{
			continue;
		}
		
		arrayData.Insert( TPairSpherePairSintSint( node.SphereGet(), TPairSintSint( index, HCOMMON_INVALID_INDEX ) ) );
	}

	LocalReduceCount( 
		arrayData,
		in_out_arrayNode,
		in_out_arraySphere,
		in_out_nodeOutsideTree,
		in_out_sphereCollection
		);

	in_out_nodeOutsideTree.ComponentFlagUpdate( in_out_arrayNode );

	LocalUpdateFlag(
		in_out_arrayNode,
		in_out_arraySphere,
		in_out_sphereCollection
		);

	return;
}

/**/