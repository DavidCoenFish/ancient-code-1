//file: PConvexHullGenerate/PConvexHullGenerateUtilityDataPoint.cpp

#include "PridePreCompileHeader.h"
#include "PConvexHullGenerate/PConvexHullGenerateUtilityDataPoint.h"

#include "PConvexHullGenerate/PConvexHullGenerateUtilityDataVertexPool.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/**/
///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< PConvexHullGenerateUtilityDataPointPlane >TArrayDataPlane;

///////////////////////////////////////////////////////
// local static methods
/**/
static HSINT LocalAddPlane( 
	TArrayDataPlane& in_out_arrayPlane, 
	const HSINT in_vertexIndexOne,
	const HSINT in_vertexIndexTwo,
	const HSINT in_vertexIndexThree,
	const TArrayVector& in_pointCloud
	) 
{
	PPlaneR3 testPlane;

	if( HFALSE == PPlaneUtility::ConstructPlane(
		testPlane,
		in_pointCloud[ in_vertexIndexOne ],
		in_pointCloud[ in_vertexIndexTwo ],
		in_pointCloud[ in_vertexIndexThree ]
		) )
	{
		return HCOMMON_INVALID_INDEX;
	}

	//is this plane equivelent to a pre exsisting plane
	for( HSINT index = 0; index < in_out_arrayPlane.SizeGet(); ++index )
	{
		if( HTRUE == PPlaneUtility::EqualDelta( in_out_arrayPlane[ index ].PlaneGet(), testPlane, 0.00001F ) )
		{
			return index;
		}
	}

	//make the real plane
	PConvexHullGenerateUtilityDataPointPlane planeData;
	if( HFALSE == planeData.DataSet( 
		in_pointCloud,
		in_vertexIndexOne,
		in_vertexIndexTwo,
		in_vertexIndexThree
		) )
	{
		return HCOMMON_INVALID_INDEX;
	}

	const HSINT planeIndex = HContainerUtility< TArrayDataPlane >::PushBack( in_out_arrayPlane, planeData );
	
	return planeIndex;
}

/**/
static HBOOL LocalFlowPlanes(
	TArrayDataPlane& in_out_arrayPlane, 
	const TArrayVector& in_pointCloud,
	const HSINT in_planeIndex
	)
{
	//don't take reference to member of array in function that can change the size of array
	//PConvexHullGenerateUtilityDataPointPlane& plane	= in_out_arrayPlane[ in_planeIndex ];
	const HSINT count = in_out_arrayPlane[ in_planeIndex ].EdgeLoopTouchingCountGet();
	if( count < 3 )
	{
		return HFALSE;
	}

	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT touching = in_out_arrayPlane[ in_planeIndex ].EdgeLoopTouchingGet( index );
		if( HCOMMON_INVALID_INDEX != touching )
		{
			continue;
		}

		//assum loop clockwise
		const TArraySint& arrayEdgeIndex = in_out_arrayPlane[ in_planeIndex ].ArrayEdgeLoopVertexIndexGet();
		HSINT vertexIndexOne = arrayEdgeIndex[ index ];
		HSINT vertexIndexTwo = arrayEdgeIndex[ ( index + 1 ) % count ];
		HSINT vertexIndexOther = arrayEdgeIndex[ ( index + 2 ) % count ];

		const HVectorR3 direction = HMatrixUtilityR3::Normalise( in_pointCloud[ vertexIndexTwo ] - in_pointCloud[ vertexIndexOne ] );

		if( HTRUE == HMathUtilityEpsilonZero( direction ) )
		{
			continue;
		}

		HSINT indexNewCandidate = HCOMMON_INVALID_INDEX;
		//TODO:
		//if( HFALSE == PConvexHullGeneratePointCloudUtility::FindNextCandidate( 
		//	indexNewCandidate,
		//	vertexIndexOther,
		//	vertexIndexTwo,
		//	in_pointCloud, 
		//	PPlane( 0.0F, PUnitVector( direction ) ), 
		//	arrayEdgeIndex
		//	) )
		//{
		//	continue;
		//}

		const HSINT oldSize = in_out_arrayPlane.SizeGet();

		const HSINT planeIndex = LocalAddPlane( 
			in_out_arrayPlane, 
			vertexIndexTwo,
			vertexIndexOne,
			indexNewCandidate,
			in_pointCloud
			);

		in_out_arrayPlane[ in_planeIndex ].EdgeLoopTouchingSet( index, planeIndex );

		if( oldSize != in_out_arrayPlane.SizeGet() )
		{
			if( HFALSE == LocalFlowPlanes( 
				in_out_arrayPlane,
				in_pointCloud,
				planeIndex
				) )
			{
				continue;
			}
		}
	}

	return HTRUE;
}

/**/
static HVOID LocalCollectUsedPoints(
	TArrayVector& out_newPointCloud,
	const TArrayDataPlane& in_arrayPlane, 
	const TArrayVector& in_oldPointCloud
	)
{
	PConvexHullGenerateUtilityDataVertexPool vertexPool( in_oldPointCloud, out_newPointCloud );
	HCOMMON_FOR_EACH_CONST( plane, in_arrayPlane, TArrayDataPlane )
	{
		const TArraySint& arrayVertexIndex = plane.ArrayEdgeLoopVertexIndexGet();
		for( HSINT index = 0; index < arrayVertexIndex.SizeGet(); ++index )
		{
			vertexPool.RequestVertex( arrayVertexIndex[ index ] );
		}
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityDataPoint::PConvexHullGenerateUtilityDataPoint( const PConvexHullGenerateUtilityDataPoint& in_src )
: m_arrayPlane()
, m_arrayPoints()
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullGenerateUtilityDataPoint::PConvexHullGenerateUtilityDataPoint()
: m_arrayPlane()
, m_arrayPoints()
{
	return;
}

/**/
PConvexHullGenerateUtilityDataPoint::~PConvexHullGenerateUtilityDataPoint()
{
	return;
}

/**/

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilityDataPoint& PConvexHullGenerateUtilityDataPoint::operator=( const PConvexHullGenerateUtilityDataPoint& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayPlane = in_rhs.m_arrayPlane;
		m_arrayPoints = in_rhs.m_arrayPoints;
	}

	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataPoint::operator==( const PConvexHullGenerateUtilityDataPoint& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this == ( &in_rhs ) )
	{
		match &= ( m_arrayPlane == in_rhs.m_arrayPlane );
		match &= ( m_arrayPoints == in_rhs.m_arrayPoints );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataPoint::operator!=( const PConvexHullGenerateUtilityDataPoint& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataPoint::Create(
	const TArrayVector& in_pointCloud
	)
{
	( *this ) = PConvexHullGenerateUtilityDataPoint();

	HSINT vertexIndex[ 3 ];
	if( HFALSE == PConvexHullGeneratePointCloudUtility::SeedPointsSelect(
		vertexIndex[ 0 ],
		vertexIndex[ 1 ],
		vertexIndex[ 2 ],
		in_pointCloud
		) )
	{
		return HFALSE;
	}

	const HSINT planeIndex = LocalAddPlane( 
		m_arrayPlane, 
		vertexIndex[ 0 ],
		vertexIndex[ 1 ],
		vertexIndex[ 2 ],
		in_pointCloud
		);

	if( HCOMMON_INVALID_INDEX == planeIndex )
	{
		return HFALSE;
	}

	LocalFlowPlanes(
		m_arrayPlane, 
		in_pointCloud,
		planeIndex
		);

	LocalCollectUsedPoints(
		m_arrayPoints,
		m_arrayPlane, 
		in_pointCloud
		);

	return HTRUE;
}

/**/
HVOID PConvexHullGenerateUtilityDataPoint::HullGet( PConvexHull& out_hull )const
{
	HCOMMON_FOR_EACH_CONST( plane, m_arrayPlane, TArrayDataPlane )
	{
		out_hull.PlaneAdd( plane.PlaneGet() );
	}

	return;
}

/**/