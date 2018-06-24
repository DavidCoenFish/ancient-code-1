//file: Pride/PGeometry/PGeometryStoreTriangleStrip.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryStoreTriangleStrip.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include "Pride/PGeometry/PGeometryTrait.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//EMEMENTO_FACTORY_SOURCE( PGeometryStoreTriangleStrip, PGeometryStoreInterface );

////////////////////////////////////////////////
// creation
/**/
PGeometryStoreTriangleStrip::PGeometryStoreTriangleStrip( const PGeometryStoreTriangleStrip& in_src )
: m_arrayStripLengthsBase()
, m_arrayVertexIndex()
, m_triangleCount( 0 )
, m_targetTopologyVertexIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
PGeometryStoreTriangleStrip::PGeometryStoreTriangleStrip( const Hubris::HSINT in_targetTopologyVertexIndex )
: m_arrayStripLengthsBase()
, m_arrayVertexIndex()
, m_triangleCount( 0 )
, m_targetTopologyVertexIndex( in_targetTopologyVertexIndex )
{
	return;
}

/**/
PGeometryStoreTriangleStrip::PGeometryStoreTriangleStrip()
: m_arrayStripLengthsBase()
, m_arrayVertexIndex()
, m_triangleCount( 0 )
, m_targetTopologyVertexIndex( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
PGeometryStoreTriangleStrip::~PGeometryStoreTriangleStrip()
{
	return;
}

////////////////////////////////////////////////
// operators
/**/
const PGeometryStoreTriangleStrip& PGeometryStoreTriangleStrip::operator=( const PGeometryStoreTriangleStrip& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayStripLengthsBase = in_rhs.m_arrayStripLengthsBase;
		m_arrayVertexIndex = in_rhs.m_arrayVertexIndex;
		m_triangleCount = in_rhs.m_triangleCount;
		m_targetTopologyVertexIndex = in_rhs.m_targetTopologyVertexIndex;
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryStoreTriangleStrip::operator==( const PGeometryStoreTriangleStrip& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_arrayStripLengthsBase == in_rhs.m_arrayStripLengthsBase );
		match &= ( m_arrayVertexIndex == in_rhs.m_arrayVertexIndex );
		match &= ( m_triangleCount == in_rhs.m_triangleCount );
		match &= ( m_targetTopologyVertexIndex == in_rhs.m_targetTopologyVertexIndex );
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryStoreTriangleStrip::operator!=( const PGeometryStoreTriangleStrip& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

////////////////////////////////////////////////
// implement PGeometryStoreInterface
/**/
HVOID PGeometryStoreTriangleStrip::Clear()
{
	m_arrayStripLengthsBase.Clear();
	m_arrayVertexIndex.Clear();
	m_triangleCount = 0;
	return;
}

/**/
PGeometryStoreInterface* PGeometryStoreTriangleStrip::Clone()
{
	PGeometryStoreInterface* pStore;
	HCOMMON_NEW_PARAM( pStore, PGeometryStoreTriangleStrip, *this );
	return pStore;
}

/**/
Hubris::HBOOL PGeometryStoreTriangleStrip::Cmp( const PGeometryStoreInterface* const in_pRhs )
{
	const PGeometryStoreTriangleStrip* const pRhs = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreTriangleStrip >( in_pRhs );
	if( HNULL == pRhs )
	{
		return HFALSE;
	}

	return( ( *this ) == ( *pRhs ) );
}

////////////////////////////////////////////////
// public methods
/**/
HVOID PGeometryStoreTriangleStrip::StripAdd( const Hubris::HSINT* const in_pArrayVertexIndexes, const Hubris::HSINT in_vertexIndexCount )
{
	HSINT baseVertexIndex = m_arrayVertexIndex.SizeGet();
	HContainerUtility::PushBack( m_arrayStripLengthsBase, TPairSintSint( in_vertexIndexCount, baseVertexIndex ) );

	m_arrayVertexIndex.SizeResize( baseVertexIndex + in_vertexIndexCount );
	for( HSINT index = 0; index < in_vertexIndexCount; ++index )
	{
		m_arrayVertexIndex[ baseVertexIndex + index ] = in_pArrayVertexIndexes[ index ];
	}

	m_triangleCount += ( in_vertexIndexCount - 2 );

	return;
}

/**/
Hubris::HVOID PGeometryStoreTriangleStrip::StripAdd( const TArraySint& in_arrayVertexIndex )
{
	StripAdd( in_arrayVertexIndex.RawGet(), in_arrayVertexIndex.SizeGet() );
	return;
}

////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT PGeometryStoreTriangleStrip::StripCountGet()const
{
	return m_arrayStripLengthsBase.SizeGet();
}

/**/
const Hubris::HSINT PGeometryStoreTriangleStrip::StripLengthGet( const Hubris::HSINT in_stripIndex )const
{
	return m_arrayStripLengthsBase[ in_stripIndex ].m_first;
}

/**/
const Hubris::HSINT* PGeometryStoreTriangleStrip::StripDataGet( const Hubris::HSINT in_stripIndex )const
{
	return( m_arrayVertexIndex.RawGet() + m_arrayStripLengthsBase[ in_stripIndex ].m_second );
}

/**/