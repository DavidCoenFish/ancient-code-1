//file: Pride/PMesh/PMeshTriangle.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PMesh/PMeshTriangle.h"

#include "Pride/PTriangle/PTriangle_Export.h"
#include "Pride/PUnitVector/PUnitVector_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedefs
/**/
struct TCalculatedData
{
	enum TEnum
	{
		TNormal		= 0x01,
		TEdgeOne	= 0x02,
		TEdgeTwo	= 0x04,
		TEdgeThree	= 0x08,

		TNormalCalculationFailed = 0x10,
		TEdgeVertexOneTwo		= 0x20,
		TEdgeVertexTwoThree		= 0x40,
		TEdgeVertexThreeOne		= 0x80,

		TNone		= 0x00,
	};
};

static const TCalculatedData::TEnum s_arrayEdgeFlag[ 3 ] = {
	TCalculatedData::TEdgeOne,
	TCalculatedData::TEdgeTwo,
	TCalculatedData::TEdgeThree
};

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalClearValues( HSINT* const in_pVertexIndex, HSINT* const in_pTouchingTriangleIndex )
{
	for( HSINT index = 0; index < 3; ++index )
	{
		in_pVertexIndex[ index ] = HCOMMON_INVALID_INDEX;
		in_pTouchingTriangleIndex[ index ] = HCOMMON_INVALID_INDEX;
	}

	return;
}

/**/
static const HBOOL LocalFlagTest( const HSINT in_flag, TCalculatedData::TEnum in_value )
{
	return( 0 != ( in_flag & in_value ) );
}

/**/
static Hubris::HVOID LocalFlagSet( HSINT& in_out_flag, TCalculatedData::TEnum in_value, const HBOOL in_active )
{
	if( HTRUE == in_active )
	{
		in_out_flag |= HSINT( in_value );
	}
	else
	{
		in_out_flag &= ( ~( HSINT( in_value ) ) );
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
PMeshTriangle::PMeshTriangle( const PMeshTriangle& in_src )
: m_flag( 0 )
, m_normalIndex( HCOMMON_INVALID_INDEX )
{
	LocalClearValues( m_vertexIndex, m_touchingTriangleIndex );
	( *this ) = in_src;
	return;
}

/**/
PMeshTriangle::PMeshTriangle(
	const Hubris::HSINT in_vertexIndexOne,
	const Hubris::HSINT in_vertexIndexTwo,
	const Hubris::HSINT in_vertexIndexThree
	)
: m_flag( 0 )
, m_normalIndex( HCOMMON_INVALID_INDEX )
{
	LocalClearValues( m_vertexIndex, m_touchingTriangleIndex );
	VertexIndexSet(
		in_vertexIndexOne,
		in_vertexIndexTwo,
		in_vertexIndexThree
		);
	return;
}

/**/
PMeshTriangle::PMeshTriangle()
: m_flag( 0 )
, m_normalIndex( HCOMMON_INVALID_INDEX )
{
	LocalClearValues( m_vertexIndex, m_touchingTriangleIndex );
	return;
}

/**/
PMeshTriangle::~PMeshTriangle()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PMeshTriangle& PMeshTriangle::operator=( const PMeshTriangle& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		for( HSINT index = 0; index < 3; ++index )
		{
			for( HSINT index = 0; index < 3; ++index )
			{
				m_vertexIndex[ index ] = in_rhs.m_vertexIndex[ index ];
				m_touchingTriangleIndex[ index ] = in_rhs.m_touchingTriangleIndex[ index ];
			}
			m_flag = in_rhs.m_flag;
			m_normalIndex = in_rhs.m_normalIndex;
		}
	}

	return( *this );
}

/**/
Hubris::HBOOL PMeshTriangle::operator==( const PMeshTriangle& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		for( HSINT index = 0; index < 3; ++index )
		{
			match &= ( m_vertexIndex[ index ] == in_rhs.m_vertexIndex[ index ] );
			match &= ( m_touchingTriangleIndex[ index ] == in_rhs.m_touchingTriangleIndex[ index ] );
		}
		match &= ( m_flag == in_rhs.m_flag );
		match &= ( m_normalIndex == in_rhs.m_normalIndex );
	}

	return match;
}

/**/
Hubris::HBOOL PMeshTriangle::operator!=( const PMeshTriangle& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public accessors
/**/
HVOID PMeshTriangle::VertexIndexSet(
	const Hubris::HSINT in_vertexIndexOne,
	const Hubris::HSINT in_vertexIndexTwo,
	const Hubris::HSINT in_vertexIndexThree
	)
{
	m_vertexIndex[ 0 ] = in_vertexIndexOne;
	m_vertexIndex[ 1 ] = in_vertexIndexTwo;
	m_vertexIndex[ 2 ] = in_vertexIndexThree;

	return;
}

/**/
HVOID PMeshTriangle::VertexIndexGet(
	Hubris::HSINT& out_vertexIndexOne,
	Hubris::HSINT& out_vertexIndexTwo,
	Hubris::HSINT& out_vertexIndexThree
	)const
{
	out_vertexIndexOne = m_vertexIndex[ 0 ];
	out_vertexIndexTwo = m_vertexIndex[ 1 ];
	out_vertexIndexThree = m_vertexIndex[ 2 ];

	return;
}

/**/
HVOID PMeshTriangle::TriangleEdgeFlagGet(
	Hubris::HBOOL& out_edgeVertexOneTwo,
	Hubris::HBOOL& out_edgeVertexTwoThree,
	Hubris::HBOOL& out_edgeVertexThreeOne
	)const
{
	out_edgeVertexOneTwo = LocalFlagTest( m_flag, TCalculatedData::TEdgeVertexOneTwo );
	out_edgeVertexTwoThree = LocalFlagTest( m_flag, TCalculatedData::TEdgeVertexTwoThree );
	out_edgeVertexThreeOne = LocalFlagTest( m_flag, TCalculatedData::TEdgeVertexThreeOne );
	return;
}

/**/
HVOID PMeshTriangle::TriangleEdgeFlagSet(
	const Hubris::HBOOL& in_edgeVertexOneTwo,
	const Hubris::HBOOL& in_edgeVertexTwoThree,
	const Hubris::HBOOL& in_edgeVertexThreeOne
	)
{
	LocalFlagSet( m_flag, TCalculatedData::TEdgeVertexOneTwo, in_edgeVertexOneTwo );
	LocalFlagSet( m_flag, TCalculatedData::TEdgeVertexTwoThree, in_edgeVertexTwoThree );
	LocalFlagSet( m_flag, TCalculatedData::TEdgeVertexThreeOne, in_edgeVertexThreeOne );
	return;
}

/**/
const Hubris::HSINT PMeshTriangle::NormalIndexGet( 
	const TArrayVector& in_arrayVertex,
	TArrayVector& in_out_arrayNormal
	)
{
	if( HTRUE == LocalFlagTest( m_flag, TCalculatedData::TNormal ) )
	{
		return m_normalIndex;
	}

	PTriangle triangle( 
		in_arrayVertex[ m_vertexIndex[ 0 ] ],
		in_arrayVertex[ m_vertexIndex[ 1 ] ],
		in_arrayVertex[ m_vertexIndex[ 2 ] ]
	);

	PUnitVectorR3 normal;
	if( HFALSE == PTriangleUtility::TriangleNormalGet( normal, triangle ) )
	{
		LocalFlagSet( m_flag, TCalculatedData::TNormalCalculationFailed, HTRUE );
	}

	m_normalIndex = HContainerUtility::UniqueAdd( in_out_arrayNormal, normal.VectorGet() );

	LocalFlagSet( m_flag, TCalculatedData::TNormal, HTRUE );

	return m_normalIndex;
}

/**/
const Hubris::HBOOL PMeshTriangle::NormalValidGet(
	const TArrayVector& in_arrayVertex,
	TArrayVector& in_out_arrayNormal
	)
{
	NormalIndexGet( in_arrayVertex, in_out_arrayNormal );
	return LocalFlagTest( m_flag, TCalculatedData::TNormalCalculationFailed );
}

/**/
const Hubris::HSINT PMeshTriangle::EdgeTouchesTriangleIndexGet( 
	const Hubris::HSINT in_triangleIndex,
	const Hubris::HSINT in_edgeIndex,
	TArrayTriangle& in_out_arrayTriangle
	)
{
	PMeshTriangle& triangle = in_out_arrayTriangle[ in_triangleIndex ];

	HCOMMON_ASSERT( ( 0 <= in_edgeIndex ) && ( in_edgeIndex < 3 ), "invalid param" );

	const TCalculatedData::TEnum edgeFlag = s_arrayEdgeFlag[ in_edgeIndex ]; 
	if( HTRUE == LocalFlagTest( triangle.m_flag, edgeFlag ) )
	{
		return triangle.m_touchingTriangleIndex[ in_edgeIndex ];
	}

	triangle.m_touchingTriangleIndex[ in_edgeIndex ] = HCOMMON_INVALID_INDEX;
	const HSINT SampleVertexIndexOne = triangle.m_vertexIndex[ in_edgeIndex ];
	const HSINT SampleVertexIndexTwo = triangle.m_vertexIndex[ ( in_edgeIndex + 1 ) % 3 ];
	for( HSINT triangleIndex = 0; triangleIndex < in_out_arrayTriangle.SizeGet(); ++triangleIndex )
	{
		if( triangleIndex == in_triangleIndex )
		{
			continue;
		}

		PMeshTriangle& testTriangle = in_out_arrayTriangle[ triangleIndex ];

		for( HSINT index = 0; index < 3; ++index )
		{
			const TCalculatedData::TEnum testEdgeFlag = s_arrayEdgeFlag[ index ];
			if( ( SampleVertexIndexTwo != testTriangle.m_vertexIndex[ index ] ) || 
				( SampleVertexIndexOne != testTriangle.m_vertexIndex[ ( index + 1 ) % 3 ] ||
				( HTRUE == LocalFlagTest( testTriangle.m_flag, testEdgeFlag ) ) ) ) 
			{
				continue;
			}

			//found edge touching
			triangle.m_touchingTriangleIndex[ in_edgeIndex ] = triangleIndex;
			LocalFlagSet( triangle.m_flag, edgeFlag, HTRUE );

			testTriangle.m_touchingTriangleIndex[ index ] = in_triangleIndex;
			LocalFlagSet( testTriangle.m_flag, testEdgeFlag, HTRUE );

			return triangle.m_touchingTriangleIndex[ in_edgeIndex ];
		}
	}

	//did not find edge touching
	return triangle.m_touchingTriangleIndex[ in_edgeIndex ];
}

/**/