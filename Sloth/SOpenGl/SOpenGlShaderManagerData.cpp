//file: Sloth/SOpenGl/SOpenGlShaderManagerData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlShaderManagerData.h"

#include "Sloth/SOpenGl/SOpenGl.h"
#include "Sloth/SMaterial/SMaterial_Export.h"

#include< windows.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// local static variables
/*

	GLuint vertexShader = in_openGl.GlCreateShaderObjectARB( GL_VERTEX_SHADER );

	const HCHAR* pVertexShader = ( HCHAR* )vertexShaderBuffer.RawGet();
	in_openGl.GlShaderSourceARB( vertexShader, 1, &pVertexShader, NULL );
	in_openGl.GlCompileShaderARB( vertexShader );

	// create and link the ppl shader program
	GLuint pplProgram = in_openGl.GlCreateProgramObjectARB();
	//in_openGl.GlAttachObjectARB( pplProgram, fragmentShader );
	in_openGl.GlAttachObjectARB( pplProgram, vertexShader );
	in_openGl.GlLinkProgramARB( pplProgram );

	HString logShader = in_openGl.GlGetInfoLogARB( vertexShader );
	HString logProgram = in_openGl.GlGetInfoLogARB( pplProgram );

	if( HNULL != logShader )
	{
		HCOMMON_ASSERT_ALWAYS( logShader.RawGet() );
	}
	if( HNULL != logProgram )
	{
		HCOMMON_ASSERT_ALWAYS( logProgram.RawGet() );

*/

///////////////////////////////////////////////////////
// creation
/**/
SOpenGlShaderManagerData::SOpenGlShaderManagerData(
	SOpenGl& in_out_openGl,
	const SMaterialStageShader& in_shader
	)
: m_openGl( in_out_openGl )
, m_shaderIdVertex( 0 )
, m_shaderIdFragment( 0 )
, m_programId( 0 )
, m_valid( HTRUE )
{
	m_programId = m_openGl.GlCreateProgramObjectARB();

	if( HNULL != in_shader.ShaderGLSLVertexGet() )
	{
		m_shaderIdVertex = m_openGl.GlCreateShaderObjectARB( GL_VERTEX_SHADER );
		const HCHAR* pVertexShader = ( HCHAR* )in_shader.ShaderGLSLVertexGet().RawGet();
		m_openGl.GlShaderSourceARB( m_shaderIdVertex, 1, &pVertexShader, NULL );
		m_openGl.GlCompileShaderARB( m_shaderIdVertex );
		m_openGl.GlAttachObjectARB( m_programId, m_shaderIdVertex );

		HString logShader = m_openGl.GlGetInfoLogARB( m_shaderIdVertex );
		if( HNULL != logShader )
		{
			HCOMMON_ASSERT_ALWAYS( logShader.RawGet() );
			m_valid = HFALSE;
		}
	}

	if( HNULL != in_shader.ShaderGLSLFragmentGet() )
	{
		m_shaderIdFragment = m_openGl.GlCreateShaderObjectARB( GL_FRAGMENT_SHADER );
		const HCHAR* pFragmentShader = ( HCHAR* )in_shader.ShaderGLSLFragmentGet().RawGet();
		m_openGl.GlShaderSourceARB( m_shaderIdFragment, 1, &pFragmentShader, NULL );
		m_openGl.GlCompileShaderARB( m_shaderIdFragment );
		m_openGl.GlAttachObjectARB( m_programId, m_shaderIdFragment );

		//TODO: GetShaderiv for state rather than log
		HString logShader = m_openGl.GlGetInfoLogARB( m_shaderIdFragment );
		if( HNULL != logShader )
		{
			HCOMMON_ASSERT_ALWAYS( logShader.RawGet() );
			m_valid = HFALSE;
		}
	}

	m_openGl.GlLinkProgramARB( m_programId );
	HString logProgram = m_openGl.GlGetInfoLogARB( m_programId );
	if( HNULL != logProgram )
	{
		HCOMMON_ASSERT_ALWAYS( logProgram.RawGet() );
		m_valid = HFALSE;
	}

	return;
}
/**/
SOpenGlShaderManagerData::~SOpenGlShaderManagerData()
{
	if( 0 != m_shaderIdVertex )
	{
		m_openGl.GlDeleteShaderARB( m_shaderIdVertex );
		m_shaderIdVertex = 0;
	}
	if( 0 != m_shaderIdFragment )
	{
		m_openGl.GlDeleteShaderARB( m_shaderIdFragment );
		m_shaderIdFragment = 0;
	}
	if( 0 != m_programId )
	{
		m_openGl.GlDeleteProgramARB( m_programId );
		m_programId = 0;
	}

	return;
}

/**/
