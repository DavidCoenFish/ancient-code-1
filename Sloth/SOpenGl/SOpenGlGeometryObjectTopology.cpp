//file: Sloth/SOpenGl/SOpenGlGeometryObjectTopology.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlGeometryObjectTopology.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SOpenGlGeometryObjectTopology::SOpenGlGeometryObjectTopology( const SOpenGlGeometryObjectTopology& in_src )
: m_drawMode( HCOMMON_INVALID_INDEX )
, m_drawElementType( HCOMMON_INVALID_INDEX )
, m_drawStartIndex( HCOMMON_INVALID_INDEX )
, m_drawCount( HCOMMON_INVALID_INDEX )
, m_vertexBufferObjectIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
SOpenGlGeometryObjectTopology::SOpenGlGeometryObjectTopology(
	const Hubris::HSINT in_drawMode,
	const Hubris::HSINT in_drawElementType,
	const Hubris::HSINT in_drawCount,
	const Hubris::HSINT in_drawStartIndex,
	const Hubris::HSINT in_vertexBufferObjectIndex
	)
: m_drawMode( in_drawMode )
, m_drawElementType( in_drawElementType )
, m_drawStartIndex( in_drawStartIndex )
, m_drawCount( in_drawCount )
, m_vertexBufferObjectIndex( in_vertexBufferObjectIndex )
{
	return;
}

/**/
SOpenGlGeometryObjectTopology::SOpenGlGeometryObjectTopology()
: m_drawMode( HCOMMON_INVALID_INDEX )
, m_drawElementType( HCOMMON_INVALID_INDEX )
, m_drawStartIndex( HCOMMON_INVALID_INDEX )
, m_drawCount( HCOMMON_INVALID_INDEX )
, m_vertexBufferObjectIndex( m_vertexBufferObjectIndex )
{
	return;
}

/**/
SOpenGlGeometryObjectTopology::~SOpenGlGeometryObjectTopology()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const SOpenGlGeometryObjectTopology& SOpenGlGeometryObjectTopology::operator=( const SOpenGlGeometryObjectTopology& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_drawMode = in_rhs.m_drawMode;
		m_drawElementType = in_rhs.m_drawElementType;
		m_drawStartIndex = in_rhs.m_drawStartIndex;
		m_drawCount = in_rhs.m_drawCount;
		m_vertexBufferObjectIndex = in_rhs.m_vertexBufferObjectIndex;
	}

	return( *this );
}

/**/
const Hubris::HBOOL SOpenGlGeometryObjectTopology::operator==( const SOpenGlGeometryObjectTopology& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_drawMode == in_rhs.m_drawMode );
		match &= ( m_drawElementType == in_rhs.m_drawElementType );
		match &= ( m_drawStartIndex == in_rhs.m_drawStartIndex );
		match &= ( m_drawCount == in_rhs.m_drawCount );
		match &= ( m_vertexBufferObjectIndex == in_rhs.m_vertexBufferObjectIndex );
	}

	return( match );
}

/**/
const Hubris::HBOOL SOpenGlGeometryObjectTopology::operator!=( const SOpenGlGeometryObjectTopology& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
