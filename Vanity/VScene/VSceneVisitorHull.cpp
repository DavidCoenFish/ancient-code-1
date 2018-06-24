//file: Vanity/VScene/VSceneVisitorHull.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneVisitorHull.h"

#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneComponentSphereCollection.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"
#include "Vanity/VScene/VSceneNode.h"
#include "Vanity/VScene/VSceneVisitorUtility.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HSINT >TPairSinSint;
typedef Hubris::HContainerPair< Hubris::HSINT, TPairSinSint >TPairSinPairSintSint;
typedef Hubris::HContainerArray< TPairSinPairSintSint >TArrayPairSinSint;
typedef Hubris::HContainerTree< Hubris::HREAL, TArrayPairSinSint >TTreeRealArrayPairSintSint;
typedef Hubris::HContainerArray< VSceneNode >TArrayNode;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
typedef Hubris::HContainerArray< Hubris::HSINT >TArrayItemId;
typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_1( Hubris::HSINT ) >TFunctorVisitor;

struct TFlag
{
	enum TEnum
	{
		TOutside = 0,
		TTouching, //test sphere is on boundrary of sphere
		TInsindeSphere, //test sphere is on boundary of hull, but inside sphere
		TInsideHull, //test sphere is inside hull (and sphere)

		TCount
	};
};

///////////////////////////////////////////////////////
// static local methods
/**/
static const HSINT LocalSphereTest(
	const PSphereR3& in_testSphere,
	const PConvexHull& in_hull,
	const PSphereR3& in_sphereContainingHull,
	const HSINT in_state
	)
{
	if( TFlag::TInsideHull == in_state )
	{
		return TFlag::TInsideHull;
	}

	HBOOL sphereInside;
	HBOOL sphereTouching;

	if( TFlag::TInsindeSphere == in_state )
	{
		sphereInside = HTRUE;
		sphereTouching = HTRUE;
	}
	else
	{
		PSphereUtility::SphereTouchingTest(
			sphereInside,
			sphereTouching,
			in_sphereContainingHull,
			in_testSphere
			);
	}

	if( HFALSE == sphereTouching )
	{
		return TFlag::TOutside;
	}

	HBOOL hullSphereInside;
 	HBOOL hullSphereTouching;
	PConvexHullUtility::SphereHullTest(
		hullSphereInside,
		hullSphereTouching,
		in_hull,
		in_testSphere
		);

	if( HTRUE == hullSphereInside )
	{
		return TFlag::TInsideHull;
	}

	if( HTRUE == hullSphereTouching )
	{
		if( HTRUE == sphereInside )
		{
			return TFlag::TInsindeSphere;
		}
		return TFlag::TTouching;
	}

	return TFlag::TOutside;
}

/**/
static HVOID LocalSortCollectionNodes(
	TTreeRealArrayPairSintSint& in_out_treeSortData,
	const VSceneComponentNodeCollection& in_collectionNodes,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag,
	const Hubris::HVectorR3& in_direction,
	const Pride::PConvexHull& in_hull,
	const Pride::PSphereR3& in_sphereContainingHull,
	const HSINT in_state
	)
{
	if( HFALSE == VSceneVisitorUtility::ComponentFlagTest( in_collectionNodes.CombinedComponentFlagGet(), in_componentFlag ) )
	{
		return;
	}

	HCOMMON_FOR_EACH_CONST( index, in_collectionNodes.ArrayChildrenNodeIndexGet(), TArraySint )
	{
		const VSceneNode& node = in_arrayNode[ index ];
		if( HFALSE == VSceneVisitorUtility::ComponentFlagTest( node.ComponentFlagGet(), in_componentFlag ) )
		{
			continue;
		}

		//out_arrayItemId.Insert( index );
		const HSINT state = LocalSphereTest(
			node.SphereGet(),
			in_hull,
			in_sphereContainingHull,
			in_state
			);

		if( TFlag::TOutside == state )
		{
			continue;
		}

		const HREAL sortValue = VSceneVisitorUtility::CalculateSort(
			node.SphereGet(),
			in_direction
			);

		VSceneVisitorUtility::InsertSortNode(
			in_out_treeSortData,
			sortValue,
			index,
			state
			);
	}

	return;
}

/**/
static HVOID LocalSortCollectionSphere(
	TTreeRealArrayPairSintSint& in_out_treeSortData,
	const VSceneComponentSphereCollection& in_collectionSphere,
	const TArraySphere& in_arraySphere,
	const Hubris::HSINT in_componentFlag,
	const Hubris::HVectorR3& in_direction,
	const Pride::PConvexHull& in_hull,
	const Pride::PSphereR3& in_sphereContainingHull,
	const HSINT in_state
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

		//out_arrayItemId.Insert( index );
		const HSINT state = LocalSphereTest(
			sphere.SphereGet(),
			in_hull,
			in_sphereContainingHull,
			in_state
			);

		if( TFlag::TOutside == state )
		{
			continue;
		}

		const HREAL sortValue = VSceneVisitorUtility::CalculateSort(
			sphere.SphereGet(),
			in_direction
			);

		VSceneVisitorUtility::InsertSortSphere(
			in_out_treeSortData,
			sortValue,
			index,
			state
			);
	}

	return;
}

/**/
static HVOID LocalUnpackSortTree(
	TTreeRealArrayPairSintSint& in_out_treeSortData,
	TFunctorVisitor& in_functorVisitor,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag,
	const Hubris::HVectorR3& in_direction,
	const Pride::PConvexHull& in_hull,
	const Pride::PSphereR3& in_sphereContainingHull
	)
{
	HSINT indexNode;
	HSINT indexSphere;
	HSINT flag;
	while( HTRUE == VSceneVisitorUtility::SortPop(
		in_out_treeSortData,
		indexNode,
		indexSphere,
		flag
		) )
	{
		if( HCOMMON_INVALID_INDEX != indexNode )
		{
			if( HFALSE == in_functorVisitor( indexNode ) )
			{
				return;
			}
		}
		if( HCOMMON_INVALID_INDEX != indexSphere )
		{
			//we found a sphere insert into sort the contents of sphere
			const VSceneComponentSphereTreeSphere& sphere = in_arraySphere[ indexSphere ];

			LocalSortCollectionNodes(
				in_out_treeSortData,
				sphere.NodeCollectionGet(),
				in_arrayNode,
				in_componentFlag,
				in_direction,
				in_hull,
				in_sphereContainingHull,
				flag
				);

			LocalSortCollectionSphere(
				in_out_treeSortData,
				sphere.SphereCollectionGet(),
				in_arraySphere,
				in_componentFlag,
				in_direction,
				in_hull,
				in_sphereContainingHull,
				flag
				);
		}
	}

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VSceneVisitorHull::VisitSortedHull(
	TFunctorVisitor& in_functorVisitor,
	const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
	const VSceneComponentSphereCollection& in_collectionSphere,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag,
	const Hubris::HVectorR3& in_direction,
	const Pride::PConvexHull& in_hull,
	const Pride::PSphereR3& in_sphereContainingHull
	)
{
	TTreeRealArrayPairSintSint treeSortData;

	LocalSortCollectionNodes(
		treeSortData,
		in_collectionOutsideSpheresNodes,
		in_arrayNode,
		in_componentFlag,
		in_direction,
		in_hull,
		in_sphereContainingHull,
		TFlag::TOutside
		);

	LocalSortCollectionSphere(
		treeSortData,
		in_collectionSphere,
		in_arraySphere,
		in_componentFlag,
		in_direction,
		in_hull,
		in_sphereContainingHull,
		TFlag::TOutside
		);

	LocalUnpackSortTree(
		treeSortData,
		in_functorVisitor,
		in_arraySphere,
		in_arrayNode,
		in_componentFlag,
		in_direction,
		in_hull,
		in_sphereContainingHull
		);

	return;
}

/**/