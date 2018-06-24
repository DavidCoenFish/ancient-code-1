//file: Pride/PMesh/PMeshImplementation.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PMesh/PMeshImplementation.h"

#include "Pride/PMesh/PMesh.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedefs
/**/
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

///////////////////////////////////////////////////////
// local static methods
/**
static const HSINT LocalVertexAdd( 
	TArrayVector& in_out_arrayVertex, 
	const HVectorR3& in_vector, 
	const HREAL in_tollerance 
	)
{
	const HVectorR3 tollerance( in_tollerance );
	for( HSINT index = 0; index < in_out_arrayVertex.SizeGet(); ++index )
	{
		const HVectorR3 offset = HMathUtility::Absolute( in_vector - in_out_arrayVertex[ index ] );
		if( offset <= tollerance )
		{
			return index;
		}
	}

	return HContainerUtility::PushBack( 
		in_out_arrayVertex,
		in_vector
		);
}

///////////////////////////////////////////////////////
// creation
/**/
PMeshImplementation::PMeshImplementation( const PMeshImplementation& in_src )
: m_arrayVertex()
, m_arrayNormal()
, m_arrayTriangle()
{
	( *this ) = in_src;
	return;
}

/**/
PMeshImplementation::PMeshImplementation( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex //assert SizeGet() %3 == 0
	)
: m_arrayVertex()
, m_arrayNormal()
, m_arrayTriangle()
{
	DataSet( in_arrayVertex, in_arrayTriangleVertexIndex );

	return;
}

/**/
PMeshImplementation::PMeshImplementation( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex,	//assert SizeGet() %3 == 0
	const TArrayBool& in_arrayTriangleEdgeFlags		//assert SizeGet() == in_arrayTriangleVertexIndex.SizeGet()
	)
: m_arrayVertex()
, m_arrayNormal()
, m_arrayTriangle()
{
	DataSet( in_arrayVertex, in_arrayTriangleVertexIndex, in_arrayTriangleEdgeFlags );

	return;
}

/**/
PMeshImplementation::PMeshImplementation()
: m_arrayVertex()
, m_arrayNormal()
, m_arrayTriangle()
{
	return;
}

/**/
PMeshImplementation::~PMeshImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PMeshImplementation& PMeshImplementation::operator=( const PMeshImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayVertex = in_rhs.m_arrayVertex;
		m_arrayNormal = in_rhs.m_arrayNormal;
		m_arrayTriangle = in_rhs.m_arrayTriangle;
	}

	return( *this );
}

/**/
const PMeshImplementation& PMeshImplementation::operator+=( const PMeshImplementation& in_rhs )
{
	const HSINT baseVertexIndex = ArrayVertexGet().SizeGet();
	m_arrayVertex.ArrayPointAdd( in_rhs.ArrayVertexGet() );

	for( HSINT index = 0; index < in_rhs.TriangleCountGet(); ++index )
	{
		HSINT vertexOne = HCOMMON_INVALID_INDEX;
		HSINT vertexTwo = HCOMMON_INVALID_INDEX;
		HSINT vertexThree = HCOMMON_INVALID_INDEX;

		in_rhs.TriangleIndexGet(
			index, 
			vertexOne,
			vertexTwo,
			vertexThree
			);

		PMeshTriangle triangle(
			vertexOne + baseVertexIndex,
			vertexTwo + baseVertexIndex,
			vertexThree + baseVertexIndex
			);

		HBOOL edgeVertexOneTwo = HFALSE;
		HBOOL edgeVertexTwoThree = HFALSE;
		HBOOL edgeVertexThreeOne = HFALSE;

		in_rhs.TriangleEdgeFlagGet(
			index, 
			edgeVertexOneTwo,
			edgeVertexTwoThree,
			edgeVertexThreeOne
			);

		triangle.TriangleEdgeFlagSet(
			edgeVertexOneTwo,
			edgeVertexTwoThree,
			edgeVertexThreeOne
			);

		m_arrayTriangle.Insert( triangle );
	}

	return( *this );
}

/**/
const Hubris::HBOOL PMeshImplementation::operator==( const PMeshImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayVertex == in_rhs.m_arrayVertex );
		match &= ( m_arrayNormal == in_rhs.m_arrayNormal );
		match &= ( m_arrayTriangle == in_rhs.m_arrayTriangle );
	}

	return match;
}

/**/
const Hubris::HBOOL PMeshImplementation::operator!=( const PMeshImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PMeshImplementation::DataSet( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex //assert SizeGet() %3 == 0
	)
{
	m_arrayNormal.Clear();
	m_arrayVertex.ArrayPointsSet( in_arrayVertex );

	HCOMMON_ASSERT( 0 == ( in_arrayTriangleVertexIndex.SizeGet() % 3 ), "invalid param" );
	HSINT triangleCount = in_arrayTriangleVertexIndex.SizeGet() / 3;
	m_arrayTriangle.SizeSet( triangleCount );
	for( HSINT index = 0; index < triangleCount; ++index )
	{
		const HSINT baseIndex = index * 3;
		const HSINT vertexIndexOne = in_arrayTriangleVertexIndex[ baseIndex + 0 ];
		const HSINT vertexIndexTwo = in_arrayTriangleVertexIndex[ baseIndex + 1 ];
		const HSINT vertexIndexThree = in_arrayTriangleVertexIndex[ baseIndex + 2 ];

		HCOMMON_ASSERT( ( 0 <= vertexIndexOne ) && ( vertexIndexOne < in_arrayTriangleVertexIndex.SizeGet() ), "invalid data" );
		HCOMMON_ASSERT( ( 0 <= vertexIndexTwo ) && ( vertexIndexTwo < in_arrayTriangleVertexIndex.SizeGet() ), "invalid data" );
		HCOMMON_ASSERT( ( 0 <= vertexIndexThree ) && ( vertexIndexThree < in_arrayTriangleVertexIndex.SizeGet() ), "invalid data" );

		m_arrayTriangle[ index ].VertexIndexSet(
			vertexIndexOne,
			vertexIndexTwo,
			vertexIndexThree
		);
	}

	return;
}

/**/
HVOID PMeshImplementation::DataSet( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex,	//assert SizeGet() %3 == 0
	const TArrayBool& in_arrayTriangleEdgeFlags		//assert SizeGet() == in_arrayTriangleVertexIndex.SizeGet()
	)
{
	HCOMMON_ASSERT( in_arrayTriangleVertexIndex.SizeGet() == in_arrayTriangleEdgeFlags.SizeGet(), "invalid param" );
	DataSet( in_arrayVertex, in_arrayTriangleVertexIndex );

	HSINT triangleCount = in_arrayTriangleVertexIndex.SizeGet() / 3;
	for( HSINT index = 0; index < triangleCount; ++index )
	{
		const HSINT baseIndex = index * 3;
		const HBOOL edgeOneTwo = in_arrayTriangleEdgeFlags[ baseIndex + 0 ];
		const HBOOL edgeTwoThree = in_arrayTriangleEdgeFlags[ baseIndex + 1 ];
		const HBOOL edgeThreeOne = in_arrayTriangleEdgeFlags[ baseIndex + 2 ];

		m_arrayTriangle[ index ].TriangleEdgeFlagSet(
			edgeOneTwo,
			edgeTwoThree,
			edgeThreeOne
		);
	}

	return;
}

/**/
const Hubris::HSINT PMeshImplementation::TriangleAdd(
	const Hubris::HVectorR3& in_vertexOne,
	const Hubris::HVectorR3& in_vertexTwo,
	const Hubris::HVectorR3& in_vertexThree,
	const Hubris::HVectorR3& in_threashold
	)
{
	const HSINT vertexIndexOne = m_arrayVertex.PointMerge( in_vertexOne, in_threashold );
	const HSINT vertexIndexTwo = m_arrayVertex.PointMerge( in_vertexTwo, in_threashold );
	const HSINT vertexIndexThree = m_arrayVertex.PointMerge( in_vertexThree, in_threashold );

	if( ( vertexIndexOne == vertexIndexTwo ) ||
		( vertexIndexTwo == vertexIndexThree ) ||
		( vertexIndexThree == vertexIndexOne ) )
	{
		return HCOMMON_INVALID_INDEX;
	}

	return HContainerUtility::PushBack(
		m_arrayTriangle,
		PMeshTriangle(
			vertexIndexOne,
			vertexIndexTwo,
			vertexIndexThree
			)
		);
}

/**/
const PMeshImplementation::TArrayVector& PMeshImplementation::ArrayVertexGet()const
{ 
	return m_arrayVertex.ArrayPointsGet();
}

/**/
const Hubris::HSINT PMeshImplementation::TriangleCountGet()const
{
	return m_arrayTriangle.SizeGet();
}

/**/
HVOID PMeshImplementation::TriangleIndexGet(
	const Hubris::HSINT in_triangleIndex,
	Hubris::HSINT& out_vertexIndexOne,
	Hubris::HSINT& out_vertexIndexTwo,
	Hubris::HSINT& out_vertexIndexThree
	)const
{
	m_arrayTriangle[ in_triangleIndex ].VertexIndexGet(
		out_vertexIndexOne,
		out_vertexIndexTwo,
		out_vertexIndexThree
		);
	return;
}

/**/
HVOID PMeshImplementation::TriangleVertexGet(
	const Hubris::HSINT in_triangleIndex,
	Hubris::HVectorR3& out_vertexOne,
	Hubris::HVectorR3& out_vertexTwo,
	Hubris::HVectorR3& out_vertexThree
	)const
{
	HSINT vertexIndexOne;
	HSINT vertexIndexTwo;
	HSINT vertexIndexThree;
	TriangleIndexGet( 
		in_triangleIndex,
		vertexIndexOne,
		vertexIndexTwo,
		vertexIndexThree
		);
	out_vertexOne = m_arrayVertex.ArrayPointsGet()[ vertexIndexOne ];
	out_vertexTwo = m_arrayVertex.ArrayPointsGet()[ vertexIndexTwo ];
	out_vertexThree = m_arrayVertex.ArrayPointsGet()[ vertexIndexThree ];

	return;
}

/**/
HVOID PMeshImplementation::TriangleEdgeFlagGet(
	const Hubris::HSINT in_triangleIndex,
	Hubris::HBOOL& out_edgeVertexOneTwo,
	Hubris::HBOOL& out_edgeVertexTwoThree,
	Hubris::HBOOL& out_edgeVertexThreeOne
	)const
{
	m_arrayTriangle[ in_triangleIndex ].TriangleEdgeFlagGet(
		out_edgeVertexOneTwo,
		out_edgeVertexTwoThree,
		out_edgeVertexThreeOne
		);

	return;
}

/**/
HVOID PMeshImplementation::TriangleEdgeFlagSet(
	const Hubris::HSINT in_triangleIndex,
	const Hubris::HBOOL& in_edgeVertexOneTwo,
	const Hubris::HBOOL& in_edgeVertexTwoThree,
	const Hubris::HBOOL& in_edgeVertexThreeOne
	)
{
	m_arrayTriangle[ in_triangleIndex ].TriangleEdgeFlagSet(
		in_edgeVertexOneTwo,
		in_edgeVertexTwoThree,
		in_edgeVertexThreeOne
		);

	return;
}

/**/
const Hubris::HSINT PMeshImplementation::TriangleEdgeTouchesGet(
	const Hubris::HSINT in_triangleIndex,
	const Hubris::HSINT in_edgeIndex
	)
{
	return PMeshTriangle::EdgeTouchesTriangleIndexGet( 
		in_triangleIndex,
		in_edgeIndex,
		m_arrayTriangle
		);
}

/**/
const Hubris::HBOOL PMeshImplementation::TriangleNormalValidGet(
	const Hubris::HSINT in_triangleIndex
	)
{
	return m_arrayTriangle[ in_triangleIndex ].NormalValidGet(
		m_arrayVertex.ArrayPointsGet(),
		m_arrayNormal 
		);
}

/**/
const Hubris::HVectorR3& PMeshImplementation::TriangleNormalGet(
	const Hubris::HSINT in_triangleIndex
	)
{
	const HSINT normalIndex = m_arrayTriangle[ in_triangleIndex ].NormalIndexGet( 
		m_arrayVertex.ArrayPointsGet(),
		m_arrayNormal 
		);

	return m_arrayNormal[ normalIndex ];
}

/**/