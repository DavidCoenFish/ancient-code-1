//file: Vanity/VScene/VSceneVisitorUtility.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneVisitorUtility.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HSINT >TPairSinSint;
typedef Hubris::HContainerPair< Hubris::HSINT, TPairSinSint >TPairSinPairSintSint;
typedef Hubris::HContainerArray< TPairSinPairSintSint >TArrayPairSinSint;
typedef Hubris::HContainerTree< Hubris::HREAL, TArrayPairSinSint >TTreeRealArrayPairSintSint;


////////////////////////////////////////////////////////////
// static local methods
/**/
static HVOID LocalInsertSort(
	TTreeRealArrayPairSintSint& in_out_tree,
	const Hubris::HREAL in_sortValue,
	const TPairSinSint& in_data,
	const Hubris::HSINT in_flag
	)
{
	TPairSinPairSintSint localData( in_flag, in_data );
	TTreeRealArrayPairSintSint::TIterator iterator = in_out_tree.Find( in_sortValue );
	if( iterator != in_out_tree.End() )
	{
		( *iterator ).Insert( localData );
	}
	else
	{
		TArrayPairSinSint arrayIndex;
		arrayIndex.Insert( localData );
		in_out_tree.Insert( in_sortValue, arrayIndex );
	}

	return;
}	

////////////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HREAL VSceneVisitorUtility::CalculateSort( 
	const Pride::PSphereR3& in_sphere,
	const Hubris::HVectorR3& in_vector
	)
{
	const HREAL returnValue = in_sphere.RadiusGet() - HMatrixUtility::DotProduct( in_vector, in_sphere.CenterGet() );
	return returnValue;
}

/**/
Hubris::HVOID VSceneVisitorUtility::InsertSortNode(
	TTreeRealArrayPairSintSint& in_out_tree,
	const Hubris::HREAL in_sortValue,
	const Hubris::HSINT in_nodeIndex,
	const Hubris::HSINT in_flag
	)
{
	LocalInsertSort(
		in_out_tree,
		in_sortValue,
		TPairSinSint( in_nodeIndex, HCOMMON_INVALID_INDEX ),
		in_flag
		);

	return;
}

/**/
Hubris::HVOID VSceneVisitorUtility::InsertSortSphere(
	TTreeRealArrayPairSintSint& in_out_tree,
	const Hubris::HREAL in_sortValue,
	const Hubris::HSINT in_sphereIndex,
	const Hubris::HSINT in_flag
	)
{
	LocalInsertSort(
		in_out_tree,
		in_sortValue,
		TPairSinSint( HCOMMON_INVALID_INDEX, in_sphereIndex ),
		in_flag
		);

	return;
}

/**/
const Hubris::HBOOL VSceneVisitorUtility::SortPop(
	TTreeRealArrayPairSintSint& in_out_tree,
	Hubris::HSINT& out_indexNode,
	Hubris::HSINT& out_indexSphere,
	Hubris::HSINT& out_flag
	)
{
	if( in_out_tree.SizeGet() <= 0 )
	{
		return HFALSE;
	}

	TTreeRealArrayPairSintSint::TIterator iterator = in_out_tree.Begin();
	{
		const TPairSinPairSintSint& data = HContainerUtility::Back( *iterator );
		out_indexNode = data.m_second.m_first;
		out_indexSphere = data.m_second.m_second;
		out_flag = data.m_first;
	}
	HContainerUtility::PopBack( *iterator );
	if( ( *iterator ).SizeGet() <= 0 )
	{
		in_out_tree.Remove( iterator );
	}

	return HTRUE;
}

/**/
const Hubris::HBOOL VSceneVisitorUtility::ComponentFlagTest(
	const Hubris::HSINT in_componentFlag,
	const Hubris::HSINT in_subjectFlag
	)
{
	const HBOOL result = ( in_subjectFlag == ( in_componentFlag & in_subjectFlag ) );
	return result;
}

/**/
