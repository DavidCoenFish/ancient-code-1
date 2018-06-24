//file: Vanity/VScene/VSceneComponentSphereTree.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneComponentSphereTree.h"

#include "Vanity/VScene/VSceneComponentSphereTreeBuild.h"
#include "Vanity/VScene/VSceneVisitorAll.h"
#include "Vanity/VScene/VSceneVisitorHull.h"
#include "Vanity/VScene/VSceneVisitorRay.h"
#include "Vanity/VScene/VSceneVisitorSphere.h"

//#include "Vanity/VScene/VSceneVisitorBounds.h"
//#include "Vanity/VScene/VSceneVisitorSegment.h"
//#include "Vanity/VScene/VSceneVisitorTriangle.h"

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
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< TArraySint >TArrayArraySint;
typedef Hubris::HContainerArray< PSphereR3 >TArrayPrideSphere;

///////////////////////////////////////////////////////
// local methods
/**/
static Hubris::HVOID LocalUpdateSphereComponenet(
	TArraySphere& in_out_arraySphere,
	const HSINT in_sphereIndex,
	VSceneComponentSphereCollection in_out_sphereCollectionTop
	)
{
	if( HCOMMON_INVALID_INDEX == in_sphereIndex )
	{
		in_out_sphereCollectionTop.ComponentFlagUpdate( in_out_arraySphere );
		return;
	}

	VSceneComponentSphereTreeSphere& sphere = in_out_arraySphere[ in_sphereIndex ];

	const HBOOL change = sphere.SphereCollectionGet().ComponentFlagUpdate( in_out_arraySphere );

	if( HTRUE == change )
	{
		LocalUpdateSphereComponenet(
			in_out_arraySphere,
			sphere.ParentSphereIndexGet(),
			in_out_sphereCollectionTop
			);
	}

	return;
}

/**/
static Hubris::HVOID LocalNodeRemoveFromTree(
	const HSINT in_nodeIndex,
	VSceneComponentNodeCollection& in_out_nodeCollectionOutsideSpheres,
	TArraySphere& in_out_arraySphere,
	const TArrayNode& in_arrayNode,
	VSceneComponentSphereCollection in_out_sphereCollectionTop
	)
{
	const HSINT nodeParentSphereIndex = in_arrayNode[ in_nodeIndex ].ParentSphereIndexGet();

	if( HCOMMON_INVALID_INDEX == nodeParentSphereIndex )
	{
		in_out_nodeCollectionOutsideSpheres.NodeRemove( in_arrayNode, in_nodeIndex );
	}
	else
	{
		VSceneComponentSphereTreeSphere& sphere = in_out_arraySphere[ nodeParentSphereIndex ];

		const HBOOL change = sphere.NodeRemove( in_arrayNode, in_nodeIndex );
		if( HTRUE == change )
		{
			LocalUpdateSphereComponenet(
				in_out_arraySphere,
				sphere.ParentSphereIndexGet(),
				in_out_sphereCollectionTop
				);
		}
	}

	return;
}

/**/
static Hubris::HVOID LocalNodeInsertIntoTree(
	const HSINT in_nodeIndex,
	VSceneComponentNodeCollection& in_out_nodeCollectionOutsideSpheres,
	TArraySphere& in_out_arraySphere,
	const TArrayNode& in_arrayNode,
	VSceneComponentSphereCollection in_out_sphereCollectionTop
	)
{
	const HSINT nodeParentSphereIndex = in_arrayNode[ in_nodeIndex ].ParentSphereIndexGet();

	if( HCOMMON_INVALID_INDEX == nodeParentSphereIndex )
	{
		in_out_nodeCollectionOutsideSpheres.NodeAdd( in_arrayNode, in_nodeIndex );
	}
	else
	{
		VSceneComponentSphereTreeSphere& sphere = in_out_arraySphere[ nodeParentSphereIndex ];
		const HBOOL change = sphere.NodeAdd( in_arrayNode, in_nodeIndex );
		if( HTRUE == change )
		{
			LocalUpdateSphereComponenet(
				in_out_arraySphere,
				sphere.ParentSphereIndexGet(),
				in_out_sphereCollectionTop
				);
		}
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
VSceneComponentSphereTree::VSceneComponentSphereTree()
: m_lowestUnusedNodeIndex( 0 )
, m_arrayNode()
, m_arraySphere()
, m_nodeOutsideTree()
, m_sphereCollection()
{
	return;
}

/**/
VSceneComponentSphereTree::~VSceneComponentSphereTree()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT VSceneComponentSphereTree::ItemAdd(
	const Hubris::HSINT in_componentFlag, //which components see this object on queries, assert valid
	const Pride::PSphereR3& in_sphere,
	const Hubris::HQuaternionREAL* const in_pRotation
	)
{
	HREAL smallestRadius = HVariablesMath::MaximumGet< HREAL >();
	const HSINT sphereParentIndex = m_sphereCollection.ParentSphereFind(
		m_arraySphere, 
		in_sphere,
		smallestRadius
		);

	const HSINT nodeIndex = NodeAdd( 
		in_componentFlag,
		in_sphere,
		in_pRotation,
		sphereParentIndex
		);

	return nodeIndex;
}

/**/
HVOID VSceneComponentSphereTree::ItemRemove(
	const Hubris::HSINT in_itemId
	)
{
	NodeRemove( in_itemId );
	return;
}

/**/
HVOID VSceneComponentSphereTree::ItemPositionChange( 
	const Hubris::HSINT in_itemId, 
	const Pride::PSphereR3& in_sphere
	)
{
	VSceneNode& node = m_arrayNode[ in_itemId ];

	const HSINT oldParentSphereIndex = node.ParentSphereIndexGet();
	HSINT newSphereIndex = oldParentSphereIndex;
	//are we still inside the originial sphere, or attempt to find new sphere
	if( HCOMMON_INVALID_INDEX != oldParentSphereIndex )
	{
		if( HFALSE == PSphereUtility::SphereEqualOrInside(
			m_arraySphere[ oldParentSphereIndex ].SphereGet(),
			in_sphere ) )
		{
			HREAL smallestRadius = HVariablesMath::MaximumGet< HREAL >();
			newSphereIndex = m_sphereCollection.ParentSphereFind(
				m_arraySphere, 
				in_sphere,
				smallestRadius
				);
		}
	}
	
	node.SphereSet( in_sphere );
	if( newSphereIndex == oldParentSphereIndex )
	{
		return;
	}

	LocalNodeRemoveFromTree(
		in_itemId,
		m_nodeOutsideTree,
		m_arraySphere,
		m_arrayNode,
		m_sphereCollection
		);

	node.ParentSphereIndexSet( newSphereIndex );

	LocalNodeInsertIntoTree(
		in_itemId,
		m_nodeOutsideTree,
		m_arraySphere,
		m_arrayNode,
		m_sphereCollection
		);

	return;
}
/**/
HVOID VSceneComponentSphereTree::ItemRotateChange( 
	const Hubris::HSINT in_itemId, 
	const Hubris::HQuaternionREAL& in_rotation
	)
{
	VSceneNode& node = m_arrayNode[ in_itemId ];
	node.RotationSet( in_rotation );
	return;
}

/**/
HVOID VSceneComponentSphereTree::ItemDataGet(
	const Hubris::HSINT in_itemId,
	Hubris::HSINT* out_pComponentFlag,
	Pride::PSphereR3* out_pSphere,
	const VSceneItemComponentRotation** out_pRotationComponent
	)const
{
	const VSceneNode& node = m_arrayNode[ in_itemId ];

	if( HNULL != out_pComponentFlag )
	{
		( *out_pComponentFlag ) = node.ComponentFlagGet();
	}
	if( HNULL != out_pSphere )
	{
		( *out_pSphere ) = node.SphereGet();
	}
	if( ( HNULL != out_pRotationComponent ) && 
		( HTRUE == node.ComponentRotationTest() ) )
	{
		( *out_pRotationComponent ) = &( node.ComponentRotationGet() );
	}

	return;
}

/**/
const Hubris::HSINT VSceneComponentSphereTree::ItemComponentFlagGet(
	const Hubris::HSINT in_itemId
	)const
{
	const VSceneNode& node = m_arrayNode[ in_itemId ];
	return node.ComponentFlagGet();
}

/**/
const Pride::PSphereR3& VSceneComponentSphereTree::ItemSphereGet(
	const Hubris::HSINT in_itemId
	)const
{
	const VSceneNode& node = m_arrayNode[ in_itemId ];
	return node.SphereGet();
}

/**/
const Hubris::HBOOL VSceneComponentSphereTree::ItemRotationTest(
	const Hubris::HSINT in_itemId
	)const
{
	const VSceneNode& node = m_arrayNode[ in_itemId ];
	return node.ComponentRotationTest();
}

/**/
const VSceneItemComponentRotation& VSceneComponentSphereTree::ItemComponentRotationGet(
	const Hubris::HSINT in_itemId
	)const
{
	const VSceneNode& node = m_arrayNode[ in_itemId ];
	return node.ComponentRotationGet();
}

/**/
HVOID VSceneComponentSphereTree::BuildSphereTree()
{
	m_nodeOutsideTree.Clear();
	m_sphereCollection.Clear();
	m_arraySphere.Clear();

	VSceneComponentSphereTreeBuild::Build(
		m_arrayNode,
		m_arraySphere,
		m_nodeOutsideTree,
		m_sphereCollection
		);

	return;
}

/**/
HVOID VSceneComponentSphereTree::SubmitVisitorUnsortedAll(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag //item must match any of the flags to be exposed to query
	)const
{
	VSceneVisitorAll::VisitUnsorted(
		out_arrayItemId,
		m_nodeOutsideTree,
		m_sphereCollection,
		m_arraySphere,
		m_arrayNode,
		in_componentFlag
		);

	return;
}

/**/
HVOID VSceneComponentSphereTree::SubmitVisitorUnsortedSphere(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PSphereR3& in_sphere
	)const
{
	out_arrayItemId;
	in_componentFlag;
	in_sphere;

	//VSceneVisitorSphere::VisitUnsorted(
	//	out_arrayItemId,
	//	m_nodeOutsideTree,
	//	m_arraySphere,
	//	m_arrayNode,
	//	in_componentFlag,
	//	in_sphere
	//	);

	return;
}

/**/
HVOID VSceneComponentSphereTree::SubmitVisitorUnsortedTriangle(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PTriangle& in_triangle
	)const
{
	out_arrayItemId;
	in_componentFlag;
	in_triangle;

	//VSceneVisitorTriangle::VisitUnsorted(
	//	out_arrayItemId,
	//	m_nodeOutsideTree,
	//	m_arraySphere,
	//	m_arrayNode,
	//	in_componentFlag,
	//	in_triangle
	//	);

	return;
}

/**/
HVOID VSceneComponentSphereTree::SubmitVisitorUnsortedSegment(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PLineR3& in_segment
	)const
{
	out_arrayItemId;
	in_componentFlag;
	in_segment;

	//VSceneVisitorSegment::VisitUnsorted(
	//	out_arrayItemId,
	//	m_nodeOutsideTree,
	//	m_arraySphere,
	//	m_arrayNode,
	//	in_componentFlag,
	//	in_segment
	//	);

	return;
}

/**/
HVOID VSceneComponentSphereTree::SubmitVisitorUnsortedBounds(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PBoundsR3& in_bounds
	)const
{
	out_arrayItemId;
	in_componentFlag;
	in_bounds;

	//VSceneVisitorBounds::VisitUnsorted(
	//	out_arrayItemId,
	//	m_nodeOutsideTree,
	//	m_arraySphere,
	//	m_arrayNode,
	//	in_componentFlag,
	//	in_bounds
	//	);

	return;
}

/**/
HVOID VSceneComponentSphereTree::SubmitVisitorUnsortedConvexHull(
	TArrayItemId& out_arrayItemId,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PConvexHull& in_convexHull
	)const
{
	out_arrayItemId;
	in_componentFlag;
	in_convexHull;

	//VSceneVisitorConvexHull::VisitUnsorted(
	//	out_arrayItemId,
	//	m_nodeOutsideTree,
	//	m_arraySphere,
	//	m_arrayNode,
	//	in_componentFlag,
	//	in_convexHull
	//	);

	return;
}

/**/
HVOID VSceneComponentSphereTree::SubmitVisitorSortedRay(
	TFunctorVisitorSorted& in_functorVisitor,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_lineMaximumLength
	)const
{
	VSceneVisitorRay::VisitSorted(
		in_functorVisitor,
		m_nodeOutsideTree,
		m_sphereCollection,
		m_arraySphere,
		m_arrayNode,
		in_componentFlag,
		in_line,
		in_lineMaximumLength
		);

	return;
}

/**/
Hubris::HVOID VSceneComponentSphereTree::SubmitVisitorSortedHull(
	TFunctorVisitor& in_functorVisitor,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Hubris::HVectorR3& in_direction, //sort hint
	const Pride::PConvexHull& in_hull,
	const Pride::PSphereR3& in_sphereContainingHull
	)const
{
	VSceneVisitorHull::VisitSortedHull(
		in_functorVisitor,
		m_nodeOutsideTree,
		m_sphereCollection,
		m_arraySphere,
		m_arrayNode,
		in_componentFlag,
		in_direction,
		in_hull,
		in_sphereContainingHull
		);

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
const Hubris::HSINT VSceneComponentSphereTree::NodeAdd( 
	const Hubris::HSINT in_componentFlag, //which components see this object on queries, assert valid
	const Pride::PSphereR3& in_sphere,
	const Hubris::HQuaternionREAL* const in_pRotation,
	const Hubris::HSINT in_sphereParentIndex
	)
{
	HSINT newIndex = HCOMMON_INVALID_INDEX;

	//for( ; in_out_lowestUnusedNodeIndex < in_out_arrayNode.SizeGet(); ++in_out_lowestUnusedNodeIndex )
	for( HSINT index = m_lowestUnusedNodeIndex; index < m_arrayNode.SizeGet(); ++index )
	{
		if( HFALSE == m_arrayNode[ index ].NodeInUseTest() )
		{
			newIndex = index;
			m_lowestUnusedNodeIndex = index + 1;
			break;
		}
	}

	if( HCOMMON_INVALID_INDEX == newIndex )
	{
		const HSINT index = m_arrayNode.SizeGet();

		newIndex = HContainerUtility::PushBack(
			m_arrayNode,
			VSceneNode(
				in_sphere,
				in_componentFlag,
				in_sphereParentIndex,
				in_pRotation
				) );

		HCOMMON_ASSERT( index == newIndex, "contract violation" );
	}
	else
	{
		m_arrayNode[ newIndex ] = VSceneNode(
			in_sphere,
			in_componentFlag,
			in_sphereParentIndex,
			in_pRotation
			);
	}

	LocalNodeInsertIntoTree(
		newIndex,
		m_nodeOutsideTree,
		m_arraySphere,
		m_arrayNode,
		m_sphereCollection
		);

	return newIndex; 
}

/**/
HVOID VSceneComponentSphereTree::NodeRemove( const Hubris::HSINT in_index )
{
	LocalNodeRemoveFromTree(
		in_index,
		m_nodeOutsideTree,
		m_arraySphere,
		m_arrayNode,
		m_sphereCollection
		);

	VSceneNode& node = m_arrayNode[ in_index ];
	node.NodeNotInUseSet();

	if( in_index < m_lowestUnusedNodeIndex )
	{
		m_lowestUnusedNodeIndex = in_index;
	}

	return;
}

/**/
