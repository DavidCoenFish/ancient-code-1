//file: Sloth/SMaterial/SMaterialGeometryStage.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SMaterial/SMaterialGeometryStage.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SMaterialGeometryStage::SMaterialGeometryStage( const SMaterialGeometryStage& in_src )
: m_topologyIndex( HCOMMON_INVALID_INDEX )
, m_positionIndex( HCOMMON_INVALID_INDEX )
, m_colourIndex( HCOMMON_INVALID_INDEX )
, m_normalIndex( HCOMMON_INVALID_INDEX )
, m_textureCoordIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
SMaterialGeometryStage::SMaterialGeometryStage(
	const Hubris::HSINT in_topologyIndex,
	const Hubris::HSINT in_positionIndex,
	const Hubris::HSINT in_colourIndex,
	const Hubris::HSINT in_normalIndex,
	const Hubris::HSINT in_textureCoordIndex
	)
: m_topologyIndex( in_topologyIndex )
, m_positionIndex( in_positionIndex )
, m_colourIndex( in_colourIndex )
, m_normalIndex( in_normalIndex )
, m_textureCoordIndex( in_textureCoordIndex )
{
	return;
}

/**/
SMaterialGeometryStage::~SMaterialGeometryStage()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const SMaterialGeometryStage& SMaterialGeometryStage::operator=( const SMaterialGeometryStage& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_topologyIndex = in_rhs.m_topologyIndex;
		m_positionIndex = in_rhs.m_positionIndex;
		m_colourIndex = in_rhs.m_colourIndex;
		m_normalIndex = in_rhs.m_normalIndex;
		m_textureCoordIndex = in_rhs.m_textureCoordIndex;
	}

	return( *this );
}

/**/
Hubris::HBOOL SMaterialGeometryStage::operator==( const SMaterialGeometryStage& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_topologyIndex == in_rhs.m_topologyIndex );
		match &= ( m_positionIndex == in_rhs.m_positionIndex );
		match &= ( m_colourIndex == in_rhs.m_colourIndex );
		match &= ( m_normalIndex == in_rhs.m_normalIndex );
		match &= ( m_textureCoordIndex == in_rhs.m_textureCoordIndex );
	}

	return match;
}

/**/
Hubris::HBOOL SMaterialGeometryStage::operator!=( const SMaterialGeometryStage& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
