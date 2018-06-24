//file: Sloth/SMaterial/SMaterial.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SMaterial/SMaterial.h"
#include "Sloth/SMaterial/SMaterialStage.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SMaterial::SMaterial( const SMaterial& in_src )
: m_arrayStageMaterialGeometry()
{
	( *this ) = in_src;
	return;
}

/**/
SMaterial::SMaterial(
	const TArrayPairStageMaterialGeometry& in_arrayStageMaterialGeometry
	)
: m_arrayStageMaterialGeometry( in_arrayStageMaterialGeometry )
{
	return;
}

/**/
SMaterial::SMaterial()
: m_arrayStageMaterialGeometry()
{
	return;
}

/**/
SMaterial::~SMaterial()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const SMaterial& SMaterial::operator=( const SMaterial& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayStageMaterialGeometry = in_rhs.m_arrayStageMaterialGeometry;
	}

	return( *this );
}

/**/
Hubris::HBOOL SMaterial::operator==( const SMaterial& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayStageMaterialGeometry == in_rhs.m_arrayStageMaterialGeometry );
	}

	return match;
}

/**/
Hubris::HBOOL SMaterial::operator!=( const SMaterial& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT SMaterial::StageCountGet()const
{
	const HSINT size = m_arrayStageMaterialGeometry.SizeGet();
	return size;
}

/**/
const SMaterialStage& SMaterial::StageMaterialGet( const Hubris::HSINT in_stageIndex )const
{
	return( m_arrayStageMaterialGeometry[ in_stageIndex ].m_first );
}

/**/
SMaterialStage& SMaterial::StageMaterialGet( const Hubris::HSINT in_stageIndex )
{
	return( m_arrayStageMaterialGeometry[ in_stageIndex ].m_first );
}

/**/
const SMaterialGeometryStage& SMaterial::StageGeometryGet( const Hubris::HSINT in_stageIndex )const
{
	return( m_arrayStageMaterialGeometry[ in_stageIndex ].m_second );
}

/**/
