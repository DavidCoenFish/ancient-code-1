//file: Sloth/SOpenGl/SOpenGlInfo.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlInfo.h"

#include< windows.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

///////////////////////////////////////////////////////
// creation
/**/
SOpenGlInfo::SOpenGlInfo()
: m_vendor()
, m_renderer()
, m_version()
, m_treeExtensions()
, m_arrayExtentions()
, m_redBits( 0 )
, m_greenBits( 0 )
, m_blueBits( 0 )
, m_alphaBits( 0 )
, m_depthBits( 0 )
, m_stencilBits( 0 )
, m_maxTextureSize( 0 )
, m_maxLights( 0 )
, m_maxAttribStacks( 0 )
, m_maxModelViewStacks( 0 )
, m_maxProjectionStacks( 0 )
, m_maxClipPlanes( 0 )
, m_maxTextureStacks( 0 )
, m_maxMultipassTexureUnit( 0 )
{
	m_vendor = ( const HCHAR* const )glGetString( GL_VENDOR );
	m_renderer = ( const HCHAR* const )glGetString( GL_RENDERER );
	m_version = ( const HCHAR* const )glGetString( GL_VERSION );

    const HString stringExtentions( ( const HCHAR* const )glGetString( GL_EXTENSIONS ) );
	HStringUtility::Split( stringExtentions, ' ', m_arrayExtentions );
	HCOMMON_FOR_EACH( extention, m_arrayExtentions, TArrayString )
	{
		m_treeExtensions.Insert( extention, 0 );
	}

    // get number of color bits
    glGetIntegerv( GL_RED_BITS, &m_redBits );
    glGetIntegerv( GL_GREEN_BITS, &m_greenBits );
    glGetIntegerv( GL_BLUE_BITS, &m_blueBits );
    glGetIntegerv( GL_ALPHA_BITS, &m_alphaBits );

    // get depth bits
    glGetIntegerv(GL_DEPTH_BITS, &m_depthBits );

    // get stecil bits
    glGetIntegerv(GL_STENCIL_BITS, &m_stencilBits );

    // get max number of lights allowed
    glGetIntegerv(GL_MAX_LIGHTS, &m_maxLights );

    // get max texture resolution
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &m_maxTextureSize );

    // get max number of clipping planes
    glGetIntegerv(GL_MAX_CLIP_PLANES, &m_maxClipPlanes );

    // get max modelview and projection matrix stacks
    glGetIntegerv( GL_MAX_MODELVIEW_STACK_DEPTH, &m_maxModelViewStacks );
    glGetIntegerv( GL_MAX_PROJECTION_STACK_DEPTH, &m_maxProjectionStacks );
    glGetIntegerv( GL_MAX_ATTRIB_STACK_DEPTH, &m_maxAttribStacks );

    // get max texture stacks
    glGetIntegerv( GL_MAX_TEXTURE_STACK_DEPTH, &m_maxTextureStacks );

	glGetIntegerv( GL_MAX_TEXTURE_UNITS_ARB, &m_maxMultipassTexureUnit );

	return;
}

/**/
SOpenGlInfo::~SOpenGlInfo()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL SOpenGlInfo::ExtentionTest( const Hubris::HString& in_extention )
{
	TTreeStringInt::TIterator iterator = m_treeExtensions.Find( in_extention );
	if( iterator == m_treeExtensions.End() )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**/