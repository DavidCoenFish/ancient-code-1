//file: PConvexHullGenerate/PConvexHullGenerateUtilityDataPointPlane.cpp

#include "PridePreCompileHeader.h"
#include "PConvexHullGenerate/PConvexHullGenerateUtilityDataPointPlane.h"

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
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector2D;

///////////////////////////////////////////////////////
// local static methods
/**/
static HVOID LocalGatherPointsOnPlane(
	TArraySint& out_arrayIndexPointsOnPlane,
	const TArrayVector& in_arrayVertex,
	const PPlaneR3& in_plane
	)
{
	out_arrayIndexPointsOnPlane.Clear();
	for( HSINT index = 0; index < in_arrayVertex.SizeGet(); ++index )
	{
		const HREAL distance = HMathUtilityAbsolute( PPlaneUtility::DistanceFromPlaneGet( in_plane, in_arrayVertex[ index ] ) );
		if( distance < 0.00001F )
		{
			out_arrayIndexPointsOnPlane.Insert( index );
		}
	}

	return;
}

/**/
static HVOID LocalGatherProfile(
	TArraySint& out_arrayEdgeLoopVertexIndex,
	const TArraySint& in_arrayIndexPointsOnPlane,
	const TArrayVector& in_arrayVertex,
	const PPlaneR3& in_plane
	)
{
	out_arrayEdgeLoopVertexIndex.Clear();

	TArrayVector usedPoints;
	const HSINT count = in_arrayIndexPointsOnPlane.SizeGet();
	usedPoints.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		usedPoints[ index ] = in_arrayVertex[ in_arrayIndexPointsOnPlane[ index ] ]; 
	}

	TArrayVector2D arrayPoints2D;
	PPlaneUtility::ProjectOntoPlane( 
		arrayPoints2D,
		usedPoints, 
		in_plane 
		);

	TArraySint localProfileIndex;
	PConvexHullGeneratePointCloudUtility::GenerateProfile2D(
		localProfileIndex,
		arrayPoints2D
		);

	const HSINT countProfile = localProfileIndex.SizeGet();
	out_arrayEdgeLoopVertexIndex.SizeSet( countProfile );
	for( HSINT index = 0; index < countProfile; ++index )
	{
		out_arrayEdgeLoopVertexIndex[ index ] = in_arrayIndexPointsOnPlane[ localProfileIndex[ index ] ];

	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityDataPointPlane::PConvexHullGenerateUtilityDataPointPlane( const PConvexHullGenerateUtilityDataPointPlane& in_src )
: m_plane()
, m_arrayEdgeLoopVertexIndex()
, m_arrayEdgeLoopTouching()
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullGenerateUtilityDataPointPlane::PConvexHullGenerateUtilityDataPointPlane()
: m_plane()
, m_arrayEdgeLoopVertexIndex()
, m_arrayEdgeLoopTouching()
{
	return;
}

/**/
PConvexHullGenerateUtilityDataPointPlane::~PConvexHullGenerateUtilityDataPointPlane()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilityDataPointPlane& PConvexHullGenerateUtilityDataPointPlane::operator=( const PConvexHullGenerateUtilityDataPointPlane& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_plane = in_rhs.m_plane;
		m_arrayEdgeLoopVertexIndex = in_rhs.m_arrayEdgeLoopVertexIndex;
		m_arrayEdgeLoopTouching = in_rhs.m_arrayEdgeLoopTouching;
	}

	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataPointPlane::operator==( const PConvexHullGenerateUtilityDataPointPlane& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_plane == in_rhs.m_plane );
		match &= ( m_arrayEdgeLoopVertexIndex == in_rhs.m_arrayEdgeLoopVertexIndex );
		match &= ( m_arrayEdgeLoopTouching == in_rhs.m_arrayEdgeLoopTouching );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataPointPlane::operator!=( const PConvexHullGenerateUtilityDataPointPlane& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL PConvexHullGenerateUtilityDataPointPlane::DataSet(
	const TArrayVector& in_arrayVertex,
	const Hubris::HSINT in_vertexIndexOne,
	const Hubris::HSINT in_vertexIndexTwo,
	const Hubris::HSINT in_vertexIndexThree
	)
{
	( *this ) = PConvexHullGenerateUtilityDataPointPlane();

	if( HFALSE == PPlaneUtility::ConstructPlane( 
		m_plane,
		in_arrayVertex[ in_vertexIndexOne ],
		in_arrayVertex[ in_vertexIndexTwo ],
		in_arrayVertex[ in_vertexIndexThree ]
		) )
	{
		return HFALSE;
	}

	TArraySint arrayIndexPointsOnPlane;
	LocalGatherPointsOnPlane(
		arrayIndexPointsOnPlane,
		in_arrayVertex,
		m_plane
		);

	LocalGatherProfile(
		m_arrayEdgeLoopVertexIndex,
		arrayIndexPointsOnPlane,
		in_arrayVertex,
		m_plane
		);

	const HSINT count = m_arrayEdgeLoopVertexIndex.SizeGet();
	m_arrayEdgeLoopTouching.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		m_arrayEdgeLoopTouching[ index ] = HCOMMON_INVALID_INDEX;
	}

	return HTRUE;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT PConvexHullGenerateUtilityDataPointPlane::EdgeLoopTouchingCountGet()const
{
	return m_arrayEdgeLoopTouching.SizeGet();
}

/**/
const Hubris::HSINT PConvexHullGenerateUtilityDataPointPlane::EdgeLoopTouchingGet( const Hubris::HSINT in_edgeIndex )const
{
	return m_arrayEdgeLoopTouching[ in_edgeIndex ];
}

/**/
HVOID PConvexHullGenerateUtilityDataPointPlane::EdgeLoopTouchingSet(
	const Hubris::HSINT in_edgeIndex,
	const Hubris::HSINT in_touchingPlaneIndex
	)
{
	m_arrayEdgeLoopTouching[ in_edgeIndex ] = in_touchingPlaneIndex;
	return;
}

/**/
