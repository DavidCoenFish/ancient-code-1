//file: Pride/PMesh/PMeshUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PMesh/PMeshUtility.h"

#include "Pride/PMesh/PMesh.h"

#include "Pride/PBounds/PBounds_Export.h"
#include "Pride/PPointCloud/PPointCloud_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

///////////////////////////////////////////////////////
// local static methods

///////////////////////////////////////////////////////
// public static methods
/**
HVOID PMeshUtility::VertexIndexFromTriangleIndexArray( 
	TArraySint& out_arrayVertexIndex, 
	const PMesh& in_mesh, 
	const TArraySint& in_arrayTriangleIndex 
	)
{
	out_arrayVertexIndex.Clear();
	TArraySint arrayIndex;

	HCOMMON_FOR_EACH_CONST( triangleIndex, in_arrayTriangleIndex, TArraySint )
	{
		HSINT vertexIndexOne;
		HSINT vertexIndexTwo;
		HSINT vertexIndexThree;

		in_mesh.TriangleIndexGet( triangleIndex, vertexIndexOne, vertexIndexTwo, vertexIndexThree );

		arrayIndex.Insert( vertexIndexOne );
		arrayIndex.Insert( vertexIndexTwo );
		arrayIndex.Insert( vertexIndexThree );
	}

	HContainerAlgorithm::MergeSort< TArraySint >( arrayIndex );

	HSINT oldValue = HCOMMON_INVALID_INDEX;
	HCOMMON_FOR_EACH_CONST( triangleIndex, arrayIndex, TArraySint )
	{
		if( oldValue == triangleIndex )
		{
			continue;
		}
		oldValue = triangleIndex;
		out_arrayVertexIndex.Insert( triangleIndex );
	}

	return;
}

/**/
HVOID PMeshUtility::TiangleVertexIndexArrayGet( 
	TArraySint& out_arrayTriangleVertexIndex,
	const PMesh& in_mesh
	)
{
	out_arrayTriangleVertexIndex.Clear();
	HSINT vertexIndexOne = HCOMMON_INVALID_INDEX;
	HSINT vertexIndexTwo = HCOMMON_INVALID_INDEX;
	HSINT vertexIndexThree = HCOMMON_INVALID_INDEX;
	for( HSINT index = 0; index < in_mesh.TriangleCountGet(); ++index )
	{
		in_mesh.TriangleIndexGet( index, vertexIndexOne, vertexIndexTwo, vertexIndexThree );
		out_arrayTriangleVertexIndex.Insert( vertexIndexOne );
		out_arrayTriangleVertexIndex.Insert( vertexIndexTwo );
		out_arrayTriangleVertexIndex.Insert( vertexIndexThree );
	}
	return;
}

/**/
HVOID PMeshUtility::MeshTransform( 
	PMesh& in_out_mesh,
	const HMatrixR4& in_transform
	)
{
	TArraySint arrayTriangleVertexIndex;
	TiangleVertexIndexArrayGet(
		arrayTriangleVertexIndex,
		in_out_mesh
		);

	TArrayVector arrayVectors = in_out_mesh.ArrayVertexGet();

	HCOMMON_FOR_EACH( point, arrayVectors, TArrayVector )
	{
		point = HMatrixUtility::VectorProduct( in_transform, point );
	}

	in_out_mesh = PMesh( arrayVectors, arrayTriangleVertexIndex );

	return;
}

/**/
HVOID PMeshUtility::TrianglePointCloudGet( 
	TArrayVector& out_pointCloud,
	const TArraySint& in_arrayTriangleVertexIndex,
	const PMesh& in_mesh
	)
{
	TArraySint arrayIndex;
	HCOMMON_FOR_EACH_CONST( triangleIndex, in_arrayTriangleVertexIndex, TArraySint )
	{
		HSINT indexOne = HCOMMON_INVALID_INDEX;
		HSINT indexTwo = HCOMMON_INVALID_INDEX; 
		HSINT indexThree = HCOMMON_INVALID_INDEX;

		in_mesh.TriangleIndexGet( 
			triangleIndex,
			indexOne,
			indexTwo, 
			indexThree
			);

		HContainerUtility::UniqueAdd( arrayIndex, indexOne );
		HContainerUtility::UniqueAdd( arrayIndex, indexTwo );
		HContainerUtility::UniqueAdd( arrayIndex, indexThree );
	}

	const TArrayVector& meshPointCloud = in_mesh.ArrayVertexGet();
	HCOMMON_FOR_EACH_CONST( triangleIndex, arrayIndex, TArraySint )
	{
		out_pointCloud.Insert( meshPointCloud[ triangleIndex ] );
	}

	return;
}

/**/
const PBoundsR3 PMeshUtility::BoundsGet(
	const PMesh& in_mesh
	)
{
	TArrayVector arrayVector = in_mesh.ArrayVertexGet();
	PBoundsR3 bounds;
	HCOMMON_FOR_EACH_CONST( point, arrayVector, TArrayVector )
	{
		bounds.InsertPoint( point );
	}

	return bounds;
}

/**/
HVOID PMeshUtility::MeshMerge( 
	PMesh& in_out_mesh,
	const Hubris::HREAL in_threashold //multiply with bounds to get the threashold vector for each axis
	)
{
	const PBoundsR3 bounds = BoundsGet( in_out_mesh );
	if( HFALSE == bounds.ValidGet() )
	{
		return;
	}

	const HVectorR3 pointThreashold = ( bounds.VectorMaximumGet() - bounds.VectorMinimumGet() ) * in_threashold;
	PMesh oldMesh( in_out_mesh );
	TArrayVector arrayVector = in_out_mesh.ArrayVertexGet();
	TArraySint arrayVertexIndex;
	arrayVertexIndex.SizeSet( arrayVector.SizeGet() );
	PPointCloudR3 pointCloud;

	for( HSINT index = 0; index < arrayVector.SizeGet(); ++index )
	{
		arrayVertexIndex[ index ] = pointCloud.PointMerge( arrayVector[ index ] );
	}

	TArraySint arrayTriangleVertexIndex;
	for( HSINT index = 0; index < in_out_mesh.TriangleCountGet(); ++index )
	{
		HSINT vertexOne = HCOMMON_INVALID_INDEX;
		HSINT vertexTwo = HCOMMON_INVALID_INDEX;
		HSINT vertexThree = HCOMMON_INVALID_INDEX;
		in_out_mesh.TriangleIndexGet( index, vertexOne, vertexTwo, vertexThree );

		const HSINT remappedOne = arrayVertexIndex[ vertexOne ];
		const HSINT remappedTwo = arrayVertexIndex[ vertexTwo ];
		const HSINT remappedThree = arrayVertexIndex[ vertexThree ];

		if( ( remappedOne == remappedTwo ) ||
			( remappedTwo == remappedThree ) ||
			( remappedThree == remappedOne ) )
		{
			continue;
		}

		HContainerUtility::PushBack( arrayTriangleVertexIndex, remappedOne );
		HContainerUtility::PushBack( arrayTriangleVertexIndex, remappedTwo );
		HContainerUtility::PushBack( arrayTriangleVertexIndex, remappedThree );
	}

	in_out_mesh = PMesh(
		pointCloud.ArrayPointsGet(),
		arrayTriangleVertexIndex
		);

	return;
}

/**/