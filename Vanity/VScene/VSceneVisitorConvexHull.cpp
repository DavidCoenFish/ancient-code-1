//file: Vanity/VScene/VSceneVisitorConvexHull.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneVisitorConvexHull.h"

#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneNode.h"
#include "Vanity/VScene/VSceneSphere.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VSceneSphere >TArraySphere;
typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// local static methods
/**/
///////////////////////////////////////////////////////
// static public methods
/**/

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID Vanity::VSceneVisitorConvexHull::VisitUnsorted(
	TArrayItemId& out_arrayItemId,
	const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PConvexHull& in_convexHull
	)
{
	HCOMMON_ASSERT_ALWAYS( "TODO" );

	out_arrayItemId;
	in_collectionOutsideSpheresNodes;
	in_arraySphere;
	in_arrayNode;
	in_componentFlag;
	in_convexHull;

	return;
}

/**/
