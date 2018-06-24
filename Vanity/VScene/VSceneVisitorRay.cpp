//file: Vanity/VScene/VSceneVisitorRay.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneVisitorRay.h"

#include "Vanity/VScene/VSceneComponentNodeCollection.h"
#include "Vanity/VScene/VSceneNode.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"
#include "Vanity/VScene/VSceneVisitorAll.h"

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
typedef Hubris::HFunctor< Hubris::HBOOL, HTYPE_LIST_2( Hubris::HSINT, Hubris::HREAL ) >TFunctorVisitorSorted;

typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

typedef Hubris::HContainerTree< Hubris::HREAL, TArraySint >TTreeRealArraySint;

///////////////////////////////////////////////////////
// local static methods
/**/
static const Hubris::HBOOL LocalTestSphere(
	HREAL& out_sortValue,
	const PSphereR3& in_sphere,
	const PLineR3& in_line
	)
{
	//if origin of line is inside sphere,
	if( HTRUE == PSphereUtility::PointInsideInclusive( in_sphere, in_line.OriginGet() ) )
	{
		out_sortValue = HMatrixUtility::DotProduct( in_line.DirectionGet().VectorGet(), in_sphere.CenterGet() - in_line.OriginGet() ) - in_sphere.RadiusGet();
		return HTRUE;
	}

	//or if perp closest point on line is inside sphere and point after line origin 
	const HREAL distance = HMatrixUtility::DotProduct( in_line.DirectionGet().VectorGet(), in_sphere.CenterGet() - in_line.OriginGet() );
	const HVectorR3 point = in_line.OriginGet() + ( in_line.DirectionGet().VectorGet() * distance );
	if( ( 0.0F <= distance ) &&
		( HTRUE == PSphereUtility::PointInsideInclusive( in_sphere, point ) ) )
	{
		out_sortValue = distance - in_sphere.RadiusGet();
		return HTRUE;
	}

	return HFALSE;
}

/**/
static Hubris::HVOID LocalTreeRealArraySintInsert( 
	TTreeRealArraySint& in_out_treePendingNodes,
	const HREAL in_distance,
	const HSINT in_index 
	)
{
	TTreeRealArraySint::TIterator iterator = in_out_treePendingNodes.Find( in_distance );
	if( iterator != in_out_treePendingNodes.End() )
	{
		( *iterator ).Insert( in_index );
	}
	else
	{
		TArraySint arraySint;
		arraySint.Insert( in_index );
		in_out_treePendingNodes.Insert( in_distance, arraySint );
	}

	return;
}

/**/
static Hubris::HVOID LocalVisitCollectionNodes(
	TTreeRealArraySint& in_out_treePendingNodes,
	const VSceneComponentNodeCollection& in_collectionNodes,
	const TArrayNode& in_arrayNode,
	const HSINT in_componentFlag,
	const PLineR3& in_line,
	const Hubris::HREAL in_lineMaximumLength
	)
{
	if( 0 == ( in_collectionNodes.CombinedComponentFlagGet() & in_componentFlag ) )
	{
		return;
	}

	HCOMMON_FOR_EACH_CONST( index, in_collectionNodes.ArrayChildrenNodeIndexGet(), TArraySint )
	{
		const VSceneNode& node = in_arrayNode[ index ];

		if( 0 == ( node.ComponentFlagGet() & in_componentFlag ) )
		{
			continue;
		}

		const PSphereR3& sphere = node.SphereGet();
		HREAL sortValue = 0.0F;
		if( HFALSE == LocalTestSphere(
			sortValue,
			sphere,
			in_line
			) )
		{
			continue;
		}

		if( in_lineMaximumLength < sortValue )
		{
			continue;
		}

		LocalTreeRealArraySintInsert( 
			in_out_treePendingNodes,
			sortValue,
			index 
			);
	}

	return;
}

/**/
static Hubris::HVOID LocalVisitCollectionSphere(
	TTreeRealArraySint& in_out_treePendingSphere,
	const VSceneComponentSphereCollection& in_collectionSphere,
	const TArraySphere& in_arraySphere,
	const HSINT in_componentFlag,
	const PLineR3& in_line,
	const Hubris::HREAL in_lineMaximumLength
	)
{
	if( 0 == ( in_collectionSphere.CombinedComponentFlagGet() & in_componentFlag ) )
	{
		return;
	}

	//the sphere component is a collection of sphere, but not always continaed in a sphere itself...
	// so we don't have inside the sphere component a sphere to test against to bail early

	HCOMMON_FOR_EACH_CONST( index, in_collectionSphere.ArrayChildrenSphereIndexGet(), TArraySint )
	{
		const VSceneComponentSphereTreeSphere& sceneSphere = in_arraySphere[ index ];

		if( 0 == ( sceneSphere.CombinedComponentFlagGet() & in_componentFlag ) )
		{
			continue;
		}

		const PSphereR3& sphere = sceneSphere.SphereGet();
		HREAL sortValue = 0.0F;
		if( HFALSE == LocalTestSphere(
			sortValue,
			sphere,
			in_line
			) )
		{
			continue;
		}

		if( in_lineMaximumLength < sortValue )
		{
			continue;
		}

		LocalTreeRealArraySintInsert( 
			in_out_treePendingSphere,
			sortValue,
			index 
			);
	}

	return;
}

/**/
static Hubris::HVOID LocalBreakDownSphere(
	TTreeRealArraySint& out_treePendingNodes,
	TTreeRealArraySint& out_treePendingSpheres,
	const VSceneComponentSphereTreeSphere& in_treeSphere,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_lineMaximumLength
	)
{
	LocalVisitCollectionNodes(
		out_treePendingNodes,
		in_treeSphere.NodeCollectionGet(),
		in_arrayNode,
		in_componentFlag,
		in_line,
		in_lineMaximumLength
		);

	LocalVisitCollectionSphere(
		out_treePendingSpheres,
		in_treeSphere.SphereCollectionGet(),
		in_arraySphere,
		in_componentFlag,
		in_line,
		in_lineMaximumLength
		);

	return;
}

/**/
static const Hubris::HBOOL LocalPendingGet( 
	Hubris::HREAL& out_nextNodeDistance,
	Hubris::HREAL& out_nextSphereDistance,
	const TTreeRealArraySint& in_treePendingNodes,
	const TTreeRealArraySint& in_treePendingSpheres
	) 
{
	out_nextNodeDistance = HVariablesMath::MaximumGet< HREAL >();
	out_nextSphereDistance = HVariablesMath::MaximumGet< HREAL >();
	HBOOL valid = HFALSE;

	if( 0 < in_treePendingNodes.SizeGet() )
	{
		out_nextNodeDistance = ( in_treePendingNodes.Begin().KeyGet() );
		valid = HTRUE;
	}

	if( 0 < in_treePendingSpheres.SizeGet() )
	{
		out_nextSphereDistance = ( in_treePendingSpheres.Begin().KeyGet() );
		valid = HTRUE;
	}

	return valid;
}

/**/
static const Hubris::HSINT LocalPendingPop( 
	TTreeRealArraySint& in_out_treePendingNodes
	)
{
	TTreeRealArraySint::TIterator iterator = in_out_treePendingNodes.Begin();
	const HSINT returnID = HContainerUtility::Back( *iterator );
	HContainerUtility::PopBack( *iterator );
	if( 0 == ( *iterator ).SizeGet() )
	{
		in_out_treePendingNodes.Remove( iterator );
	}

	return returnID;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VSceneVisitorRay::VisitSorted(
	TFunctorVisitorSorted& in_functorVisitor,
	const VSceneComponentNodeCollection& in_collectionOutsideSpheresNodes,
	const VSceneComponentSphereCollection& in_collectionSphere,
	const TArraySphere& in_arraySphere,
	const TArrayNode& in_arrayNode,
	const Hubris::HSINT in_componentFlag, //item must match any of the flags to be exposed to query
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_lineMaximumLength
	)
{
	TTreeRealArraySint treePendingNodes;
	TTreeRealArraySint treePendingSpheres;

	LocalVisitCollectionNodes(
		treePendingNodes,
		in_collectionOutsideSpheresNodes,
		in_arrayNode,
		in_componentFlag,
		in_line,
		in_lineMaximumLength
		);

	LocalVisitCollectionSphere(
		treePendingSpheres,
		in_collectionSphere,
		in_arraySphere,
		in_componentFlag,
		in_line,
		in_lineMaximumLength
		);

	HREAL nextNodeDistance = 0.0F;
	HREAL nextSphereDistance = 0.0F;

	while( HTRUE == LocalPendingGet( 
		nextNodeDistance,
		nextSphereDistance,
		treePendingNodes,
		treePendingSpheres
		) )
	{
		if( nextNodeDistance < nextSphereDistance )
		{
			const HSINT itemIndex = LocalPendingPop( treePendingNodes );

			if( HFALSE == in_functorVisitor( 
				itemIndex,
				nextNodeDistance
				) )
			{
				return;
			}
		}
		else
		{
			const HSINT sphereIndex = LocalPendingPop( treePendingSpheres );
			LocalBreakDownSphere(
				treePendingNodes,
				treePendingSpheres,
				in_arraySphere[ sphereIndex ],
				in_arraySphere,
				in_arrayNode,
				in_componentFlag, //item must match any of the flags to be exposed to query
				in_line,
				in_lineMaximumLength
				);
		}
	}

	return;
}

/**/
