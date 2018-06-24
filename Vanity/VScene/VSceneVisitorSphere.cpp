//file: Vanity/VScene/VSceneVisitorSphere.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneVisitorSphere.h"

#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneNode.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"
#include "Vanity/VScene/VSceneVisitorAll.h"
#include "Vanity/VScene/VSceneVisitorUtility.h"


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
typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID VisitNodeCollectionNode(
	TArrayItemId& out_arrayItemId,
	const VSceneComponentNodeCollection& in_collectionNodes,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PSphereR3& in_testSphere
	)
{
	if( HFALSE == VSceneVisitorUtility::ComponentFlagTest( in_collectionNodes.CombinedComponentFlagGet(), in_componentFlag ) )
	{
		return;
	}

	HCOMMON_FOR_EACH_CONST( index, in_collectionNodes.ArrayChildrenNodeIndexGet(), TArraySint )
	{
		const VSceneNode& node = in_arrayNode[ index ];

		if( HFALSE == VSceneVisitorSphere::SphereNodeTest(
			in_componentFlag,
			in_testSphere,
			node
			) )
		{
			continue;
		}

		out_arrayItemId.Insert( index );
	}

	return;
}

/**/
static Hubris::HVOID VisitCollectionSphere(
	TArrayItemId& out_arrayItemId,
	const VSceneComponentSphereCollection& in_collectionSphere,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PSphereR3& in_testSphere
	)
{
	if( HFALSE == VSceneVisitorUtility::ComponentFlagTest( in_collectionSphere.CombinedComponentFlagGet(), in_componentFlag ) )
	{
		return;
	}

	HCOMMON_FOR_EACH_CONST( index, in_collectionSphere.ArrayChildrenSphereIndexGet(), TArraySint )
	{
		const VSceneComponentSphereTreeSphere& sphere = in_arraySphere[ index ];
		if( HFALSE == VSceneVisitorUtility::ComponentFlagTest( sphere.CombinedComponentFlagGet(), in_componentFlag ) )
		{
			continue;
		}

		//if this sphere is INSIDE the test sphere, we just need to visit all the contents
		if( PSphereUtility::SphereEqualOrInside( in_testSphere, sphere.SphereGet() ) )
		{
			VSceneVisitorAll::VisitUnsortedSphere(
				out_arrayItemId,
				in_arraySphere,
				in_arrayNode,
				in_componentFlag,
				index
				);
			continue;
		}

		//if sphere is not even touching, bail
		if( HFALSE == PSphereUtility::SphereTouching( in_testSphere, sphere.SphereGet() ) )
		{
			continue;
		}

		VisitNodeCollectionNode(
			out_arrayItemId,
			sphere.NodeCollectionGet(),
			in_arrayNode,
			in_componentFlag, 
			in_testSphere
			);

		VisitCollectionSphere(
			out_arrayItemId,
			sphere.SphereCollectionGet(),
			in_arraySphere,
			in_arrayNode,
			in_componentFlag, 
			in_testSphere
			);
	}

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VSceneVisitorSphere::VisitUnsorted(
	TArrayItemId& out_arrayItemId,
	const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
	const VSceneComponentSphereCollection& in_collectionSphere,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PSphereR3& in_testSphere
	)
{
	VisitNodeCollectionNode(
		out_arrayItemId,
		in_collectionOutsideSpheresNodes,
		in_arrayNode,
		in_componentFlag, 
		in_testSphere
		);

	VisitCollectionSphere(
		out_arrayItemId,
		in_collectionSphere,
		in_arraySphere,
		in_arrayNode,
		in_componentFlag, 
		in_testSphere
		);

	return;
}

/**/
const Hubris::HBOOL VSceneVisitorSphere::SphereSphereTest(
	const Hubris::HSINT in_componentFlag,
	const Pride::PSphereR3& in_sphere,
	const VSceneComponentSphereTreeSphere& in_sceneSphere
	)
{
	if( HFALSE == VSceneVisitorUtility::ComponentFlagTest( in_componentFlag, in_sceneSphere.CombinedComponentFlagGet() ) )
	{
		return HFALSE;
	}

	const HBOOL touching = PSphereUtility::SphereTouching(
		in_sphere,
		in_sceneSphere.SphereGet()
		);

	return touching;
}

/**/
const Hubris::HBOOL VSceneVisitorSphere::SphereNodeTest(
	const Hubris::HSINT in_componentFlag,
	const Pride::PSphereR3& in_sphere,
	const VSceneNode& in_sceneNode
	)
{
	if( HFALSE == VSceneVisitorUtility::ComponentFlagTest( in_componentFlag, in_sceneNode.ComponentFlagGet() ) )
	{
		return HFALSE;
	}

	const HBOOL touching = PSphereUtility::SphereTouching(
		in_sphere,
		in_sceneNode.SphereGet()
		);

	return touching;
}
/**/
