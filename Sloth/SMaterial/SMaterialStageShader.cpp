//file: Sloth/SMaterial/SMaterialStageShader.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SMaterial/SMaterialStageShader.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SMaterialStageShader::SMaterialStageShader( const SMaterialStageShader& in_src )
: m_shaderGLSLVertex()
, m_shaderGLSLFragment()
{
	( *this ) = in_src;
	return;
}

/**/
SMaterialStageShader::SMaterialStageShader()
: m_shaderGLSLVertex()
, m_shaderGLSLFragment()
{
	return;
}

/**/
SMaterialStageShader::~SMaterialStageShader()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const SMaterialStageShader& SMaterialStageShader::operator=( const SMaterialStageShader& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_shaderGLSLVertex = in_rhs.m_shaderGLSLVertex;
		m_shaderGLSLFragment = in_rhs.m_shaderGLSLFragment;
	}
	return( *this );
}

/**/
const Hubris::HBOOL SMaterialStageShader::operator==( const SMaterialStageShader& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_shaderGLSLVertex == in_rhs.m_shaderGLSLVertex );
		match &= ( m_shaderGLSLFragment == in_rhs.m_shaderGLSLFragment );
	}

	return match;
}

/**/
const Hubris::HBOOL SMaterialStageShader::operator!=( const SMaterialStageShader& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}
/**/
