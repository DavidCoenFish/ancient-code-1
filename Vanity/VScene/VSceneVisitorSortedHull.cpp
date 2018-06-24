//file: Vanity/VScene/VSceneVisitorSortedHull.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneVisitorSortedHull.h"

#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneComponentSphereCollection.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"
#include "Vanity/VScene/VSceneNode.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// local static methods
/**/
///////////////////////////////////////////////////////
// static public methods
/**/
HVOID VSceneVisitorSortedHull::VisitUnsorted(
	TArrayItemId& out_arrayItemId,
	const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
	const VSceneComponentSphereCollection& in_collectionSphere,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag //item must match any of the flags to be exposed to query
	)
{
	out_arrayItemId.Clear();

	VisitUnsortedNodeCollection(
		out_arrayItemId,
		in_collectionOutsideSpheresNodes,
		in_arrayNode,
		in_componentFlag
		);

	if( in_componentFlag == ( in_collectionSphere.CombinedComponentFlagGet() & in_componentFlag ) )
	{
		HCOMMON_FOR_EACH_CONST( sphereIndex, in_collectionSphere.ArrayChildrenSphereIndexGet(), TArraySint )
		{
			VisitUnsortedSphere(
				out_arrayItemId,
				in_arraySphere,
				in_arrayNode,
				in_componentFlag,
				sphereIndex
				);
		}
	}

	return;
}

/**/
HVOID VSceneVisitorSortedHull::VisitUnsortedNodeCollection(
	TArrayItemId& out_arrayItemId,
	const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
	const TArrayNode& in_arrayNode,
	const HSINT in_componentFlag
	)
{
	if( in_componentFlag != ( in_collectionOutsideSpheresNodes.CombinedComponentFlagGet() & in_componentFlag ) )
	{
		return;
	}

	HCOMMON_FOR_EACH_CONST( index, in_collectionOutsideSpheresNodes.ArrayChildrenNodeIndexGet(), TArraySint )
	{
		const VSceneNode& node = in_arrayNode[ index ];
		if( in_componentFlag != ( node.ComponentFlagGet() & in_componentFlag ) )
		{
			continue;
		}

		out_arrayItemId.Insert( index );
	}

	return;
}

/**/
HVOID VSceneVisitorSortedHull::VisitUnsortedSphere(
	TArrayItemId& out_arrayItemId,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const HSINT in_componentFlag,
	const HSINT in_sphereIndex
	)
{
	const VSceneComponentSphereTreeSphere& sphere = in_arraySphere[ in_sphereIndex ];
	if( in_componentFlag != ( sphere.CombinedComponentFlagGet() & in_componentFlag ) )
	{
		return;
	}

	VisitUnsortedNodeCollection(
		out_arrayItemId,
		sphere.NodeCollectionGet(),
		in_arrayNode,
		in_componentFlag
		);


	if( in_componentFlag == ( sphere.SphereCollectionGet().CombinedComponentFlagGet() & in_componentFlag ) )
	{
		HCOMMON_FOR_EACH_CONST( sphereIndex, sphere.SphereCollectionGet().ArrayChildrenSphereIndexGet(), TArraySint )
		{
			VisitUnsortedSphere(
				out_arrayItemId,
				in_arraySphere,
				in_arrayNode,
				in_componentFlag,
				sphereIndex
				);
		}
	}

	return;
}

/**/