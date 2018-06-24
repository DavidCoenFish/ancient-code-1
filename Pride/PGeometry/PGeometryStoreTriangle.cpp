//file: Pride/PGeometry/PGeometryStoreTriangle.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryStoreTriangle.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include "Pride/PGeometry/PGeometryTrait.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//EMEMENTO_FACTORY_SOURCE( PGeometryStoreTriangle, PGeometryStoreInterface );

////////////////////////////////////////////////
// creation
/**/
PGeometryStoreTriangle::PGeometryStoreTriangle( const PGeometryStoreTriangle& in_src )
: m_arrayVertexIndex()
, m_targetTopologyVertexIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
PGeometryStoreTriangle::PGeometryStoreTriangle( const Hubris::HSINT in_targetTopologyVertexIndex )
: m_arrayVertexIndex()
, m_targetTopologyVertexIndex( in_targetTopologyVertexIndex )
{
	return;
}

/**/
PGeometryStoreTriangle::PGeometryStoreTriangle()
: m_arrayVertexIndex()
, m_targetTopologyVertexIndex( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
PGeometryStoreTriangle::~PGeometryStoreTriangle()
{
	return;
}

////////////////////////////////////////////////
// operators
/**/
const PGeometryStoreTriangle& PGeometryStoreTriangle::operator=( const PGeometryStoreTriangle& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayVertexIndex = in_rhs.m_arrayVertexIndex;
		m_targetTopologyVertexIndex = in_rhs.m_targetTopologyVertexIndex;
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryStoreTriangle::operator==( const PGeometryStoreTriangle& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_arrayVertexIndex == in_rhs.m_arrayVertexIndex );
		match &= ( m_targetTopologyVertexIndex == in_rhs.m_targetTopologyVertexIndex );
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryStoreTriangle::operator!=( const PGeometryStoreTriangle& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

////////////////////////////////////////////////
// implement PGeometryStoreInterface
/**/
HVOID PGeometryStoreTriangle::Clear()
{
	m_arrayVertexIndex.Clear();
	//clear data, not target channel index
	return;
}

/**/
PGeometryStoreInterface* PGeometryStoreTriangle::Clone()
{
	PGeometryStoreTriangle* pStore = HNULL;
	HCOMMON_NEW_PARAM( pStore, PGeometryStoreTriangle, *this );
	return pStore;
}

/**/
Hubris::HBOOL PGeometryStoreTriangle::Cmp( const PGeometryStoreInterface* const in_pRhs )
{
	const PGeometryStoreTriangle* const pRhs = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreTriangle >( in_pRhs );
	if( HNULL == pRhs )
	{
		return HFALSE;
	}

	return( ( *this ) == ( *pRhs ) );
}

////////////////////////////////////////////////
// public methods
/**/
HVOID PGeometryStoreTriangle::TriangleAdd( const Hubris::HSINT in_vertexIndexOne, const Hubris::HSINT in_vertexIndexTwo, const Hubris::HSINT in_vertexIndexThree )
{
	HContainerUtility::PushBack( m_arrayVertexIndex, in_vertexIndexOne );
	HContainerUtility::PushBack( m_arrayVertexIndex, in_vertexIndexTwo );
	HContainerUtility::PushBack( m_arrayVertexIndex, in_vertexIndexThree );

	return;
}

////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT PGeometryStoreTriangle::TriangleCountGet()const
{
	return( m_arrayVertexIndex.SizeGet() / 3 );
}

/**/
HVOID PGeometryStoreTriangle::TriangleGet( const Hubris::HSINT in_triangleIndex, Hubris::HSINT& out_vertexIndexOne, Hubris::HSINT& out_vertexIndexTwo, Hubris::HSINT& out_vertexIndexThree )const
{
	const HSINT baseIndex = in_triangleIndex * 3;
	out_vertexIndexOne = m_arrayVertexIndex[ baseIndex + 0 ];
	out_vertexIndexTwo = m_arrayVertexIndex[ baseIndex + 1 ];
	out_vertexIndexThree = m_arrayVertexIndex[ baseIndex + 2 ];
	return;
}

/**/
