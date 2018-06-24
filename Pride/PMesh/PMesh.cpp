//file: Pride/PMesh/PMesh.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PMesh/PMesh.h"

#include "Pride/PMesh/PMeshImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PMesh::PMesh( const PMesh& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PMeshImplementation, in_src.ImplementationGet() );
	return;
}

/**/
PMesh::PMesh( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex //assert SizeGet() %3 == 0
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM_2( m_pImplementation, PMeshImplementation, in_arrayVertex, in_arrayTriangleVertexIndex );
	return;
}

/**/
PMesh::PMesh( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex, //assert SizeGet() %3 == 0
	const TArrayBool& in_arrayTriangleEdgeFlags //assert SizeGet() == in_arrayTriangleVertexIndex.SizeGet()
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM_3( m_pImplementation, PMeshImplementation, in_arrayVertex, in_arrayTriangleVertexIndex, in_arrayTriangleEdgeFlags );
	return;
}

PMesh::PMesh()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, PMeshImplementation );
	return;
}

/**/
PMesh::~PMesh()
{
	HCOMMON_DELETE( m_pImplementation, PMeshImplementation );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PMesh& PMesh::operator=( const PMesh& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		ImplementationGet() = in_rhs.ImplementationGet();
	}
	return( *this );
}

/**/
const PMesh& PMesh::operator+=( const PMesh& in_rhs )
{
	ImplementationGet() += in_rhs.ImplementationGet();
	return( *this );
}

/**/
const Hubris::HBOOL PMesh::operator==( const PMesh& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match = ( ImplementationGet() == in_rhs.ImplementationGet() );
	}

	return match;
}

/**/
const Hubris::HBOOL PMesh::operator!=( const PMesh& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PMesh::DataSet( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex //assert SizeGet() %3 == 0
	)
{
	ImplementationGet().DataSet( in_arrayVertex, in_arrayTriangleVertexIndex );
	return;
}

/**/
HVOID PMesh::DataSet( 
	const TArrayVector& in_arrayVertex,  
	const TArraySint& in_arrayTriangleVertexIndex,	//assert SizeGet() %3 == 0
	const TArrayBool& in_arrayTriangleEdgeFlags		//assert SizeGet() == in_arrayTriangleVertexIndex.SizeGet()
	)
{
	ImplementationGet().DataSet( in_arrayVertex, in_arrayTriangleVertexIndex, in_arrayTriangleEdgeFlags );
	return;
}

/**/
const Hubris::HSINT PMesh::TriangleAdd(
	const Hubris::HVectorR3& in_vertexOne,
	const Hubris::HVectorR3& in_vertexTwo,
	const Hubris::HVectorR3& in_vertexThree,
	const Hubris::HVectorR3& in_threashold
	)
{
	return ImplementationGet().TriangleAdd(
		in_vertexOne,
		in_vertexTwo,
		in_vertexThree,
		in_threashold
		);
}

/**/
const PMesh::TArrayVector& PMesh::ArrayVertexGet()const
{
	return ImplementationGet().ArrayVertexGet();
}

/**/
const Hubris::HSINT PMesh::TriangleCountGet()const
{
	return ImplementationGet().TriangleCountGet();
}

/**/
HVOID PMesh::TriangleIndexGet(
	const Hubris::HSINT in_triangleIndex,
	Hubris::HSINT& out_vertexIndexOne,
	Hubris::HSINT& out_vertexIndexTwo,
	Hubris::HSINT& out_vertexIndexThree
	)const
{
	ImplementationGet().TriangleIndexGet(
		in_triangleIndex,
		out_vertexIndexOne,
		out_vertexIndexTwo,
		out_vertexIndexThree
		);
	return;
}

/**/
HVOID PMesh::TriangleVertexGet(
	const Hubris::HSINT in_triangleIndex,
	Hubris::HVectorR3& out_vertexOne,
	Hubris::HVectorR3& out_vertexTwo,
	Hubris::HVectorR3& out_vertexThree
	)const
{
	ImplementationGet().TriangleVertexGet(
		in_triangleIndex,
		out_vertexOne,
		out_vertexTwo,
		out_vertexThree
		);
	return;
}

/**/
HVOID PMesh::TriangleEdgeFlagGet(
	const Hubris::HSINT in_triangleIndex,
	Hubris::HBOOL& out_edgeVertexOneTwo,
	Hubris::HBOOL& out_edgeVertexTwoThree,
	Hubris::HBOOL& out_edgeVertexThreeOne
	)const
{
	ImplementationGet().TriangleEdgeFlagGet(
		in_triangleIndex,
		out_edgeVertexOneTwo,
		out_edgeVertexTwoThree,
		out_edgeVertexThreeOne
		);
	return;
}

/**/
HVOID PMesh::TriangleEdgeFlagSet(
	const Hubris::HSINT in_triangleIndex,
	const Hubris::HBOOL& in_edgeVertexOneTwo,
	const Hubris::HBOOL& in_edgeVertexTwoThree,
	const Hubris::HBOOL& in_edgeVertexThreeOne
	)
{
	ImplementationGet().TriangleEdgeFlagSet(
		in_triangleIndex,
		in_edgeVertexOneTwo,
		in_edgeVertexTwoThree,
		in_edgeVertexThreeOne
		);
	return;
}

/**/
const Hubris::HSINT PMesh::TriangleEdgeTouchesGet(
	const Hubris::HSINT in_triangleIndex,
	const Hubris::HSINT in_edgeIndex
	)
{
	return ImplementationGet().TriangleEdgeTouchesGet(
		in_triangleIndex,
		in_edgeIndex
		);
}

/**/
const Hubris::HBOOL PMesh::TriangleNormalValidGet(
	const Hubris::HSINT in_triangleIndex	
	)
{
	return ImplementationGet().TriangleNormalValidGet(
		in_triangleIndex
		);
}

/**/
const Hubris::HVectorR3& PMesh::TriangleNormalGet(
	const Hubris::HSINT in_triangleIndex
	)
{
	return ImplementationGet().TriangleNormalGet( 
		in_triangleIndex
		);
}

///////////////////////////////////////////////////////
// private methods
/**/
const PMeshImplementation& PMesh::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
PMeshImplementation& PMesh::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
