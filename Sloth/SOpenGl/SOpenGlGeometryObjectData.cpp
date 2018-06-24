//file: Sloth/SOpenGl/SOpenGlGeometryObjectData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlGeometryObjectData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SOpenGlGeometryObjectData::SOpenGlGeometryObjectData( const SOpenGlGeometryObjectData& in_src )
: m_drawSize( HCOMMON_INVALID_INDEX )
, m_drawType( HCOMMON_INVALID_INDEX )
, m_vertexBufferObjectIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
SOpenGlGeometryObjectData::SOpenGlGeometryObjectData(
	const Hubris::HSINT in_drawSize,
	const Hubris::HSINT in_drawType,
	const Hubris::HSINT in_vertexBufferObjectIndex
	)
: m_drawSize( in_drawSize )
, m_drawType( in_drawType )
, m_vertexBufferObjectIndex( in_vertexBufferObjectIndex )
{
	return;
}

/**/
SOpenGlGeometryObjectData::SOpenGlGeometryObjectData()
: m_drawSize( HCOMMON_INVALID_INDEX )
, m_drawType( HCOMMON_INVALID_INDEX )
, m_vertexBufferObjectIndex( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
SOpenGlGeometryObjectData::~SOpenGlGeometryObjectData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const SOpenGlGeometryObjectData& SOpenGlGeometryObjectData::operator=( const SOpenGlGeometryObjectData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_drawSize = in_rhs.m_drawSize;
		m_drawType = in_rhs.m_drawType;
		m_vertexBufferObjectIndex = in_rhs.m_vertexBufferObjectIndex;
	}
	return( *this );
}

/**/
const Hubris::HBOOL SOpenGlGeometryObjectData::operator==( const SOpenGlGeometryObjectData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_drawSize == in_rhs.m_drawSize );
		match &= ( m_drawType == in_rhs.m_drawType );
		match &= ( m_vertexBufferObjectIndex == in_rhs.m_vertexBufferObjectIndex );
	}

	return( match );
}

/**/
const Hubris::HBOOL SOpenGlGeometryObjectData::operator!=( const SOpenGlGeometryObjectData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
