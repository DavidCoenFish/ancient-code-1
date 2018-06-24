//file: Sloth/SComponent/SComponentSpriteData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentSpriteData.h"

#include "Sloth/SInterface/SInterface_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// creation
/**/
SComponentSpriteData::SComponentSpriteData( const SComponentSpriteData& in_src )
: m_geometry()
, m_materialGeometryStage()
, m_arrayRenderResource()
{
	( *this ) = in_src;
	return;
}

/**/
SComponentSpriteData::SComponentSpriteData()
: m_geometry()
, m_materialGeometryStage()
, m_arrayRenderResource()
{
	return;
}

/**/
SComponentSpriteData::~SComponentSpriteData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const SComponentSpriteData& SComponentSpriteData::operator=( const SComponentSpriteData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_geometry = in_rhs.m_geometry;
		m_materialGeometryStage = in_rhs.m_materialGeometryStage;
		m_arrayRenderResource = in_rhs.m_arrayRenderResource;
	}

	return( *this );
}

/**/
const Hubris::HBOOL SComponentSpriteData::operator==( const SComponentSpriteData& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_geometry == in_rhs.m_geometry );
		match &= ( m_materialGeometryStage == in_rhs.m_materialGeometryStage );
		match &= ( m_arrayRenderResource == in_rhs.m_arrayRenderResource );
	}

	return match;
}

/**/
const Hubris::HBOOL SComponentSpriteData::operator!=( const SComponentSpriteData& in_rhs )const
{
	return( !(operator==( in_rhs ) ) ); 
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentSpriteData::ResourceAquire( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)
{
	if( m_arrayRenderResource.SizeGet() <= in_renderIndex )
	{
		m_arrayRenderResource.SizeResize( in_renderIndex + 1 );
	}

	if( m_geometry == Pride::PGeometry() )
	{
		m_arrayRenderResource[ in_renderIndex ] = HNULL;
	}
	else
	{
		TArraySint emptyArray;
		m_arrayRenderResource[ in_renderIndex ] = in_out_interfaceRender.GeometryCreate(
			m_geometry,
			emptyArray
			);
	}

	return;
}

/**/
Hubris::HVOID SComponentSpriteData::ResourceRelease( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)
{
	if( m_arrayRenderResource.SizeGet() <= in_renderIndex )
	{
		return;
	}

	Hubris::HVOID* const geometryId = m_arrayRenderResource[ in_renderIndex ];
	if( HNULL == geometryId )
	{
		return;
	}

	in_out_interfaceRender.GeometryRelease(
		geometryId
		);

	m_arrayRenderResource[ in_renderIndex ] = HNULL;

	return;
}

/**/
const Hubris::HBOOL SComponentSpriteData::RenderValid( 
	const Hubris::HSINT in_renderIndex 
	)const
{
	if( HNULL == RenderGeometryIdGet( in_renderIndex ) )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/
Hubris::HVOID SComponentSpriteData::Render( 
	SInterfaceRender& in_out_interfaceRender, 
	const Hubris::HSINT in_renderIndex 
	)const
{
	Hubris::HVOID* const geometryId = RenderGeometryIdGet( in_renderIndex );

	in_out_interfaceRender.DrawGeometry(
		geometryId,
		m_materialGeometryStage
		);

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID* const SComponentSpriteData::RenderGeometryIdGet(
	const Hubris::HSINT in_renderIndex 
	)const
{
	if( m_arrayRenderResource.SizeGet() <= in_renderIndex )
	{
		return HNULL;
	}

	Hubris::HVOID* const geometryId = m_arrayRenderResource[ in_renderIndex ];

	return geometryId;
}

/**/

