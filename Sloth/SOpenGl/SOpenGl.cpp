//file: Sloth/SOpenGl/SOpenGl.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGl.h"

#include "Sloth/SOpenGl/SOpenGlBox.h"
#include "Sloth/SOpenGl/SOpenGlGeometry.h"
#include "Sloth/SOpenGl/SOpenGlInfo.h"
#include "Sloth/SOpenGl/SOpenGlSphere.h"
#include "Sloth/SOpenGl/SOpenGlSprite.h"
#include "Sloth/SOpenGl/SOpenGlShaderManager.h"

#include "Sloth/SLight/SLight_Export.h"
#include "Sloth/SMaterial/SMaterial_Export.h"

#include< windows.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
struct TDisplayList
{
	enum TEnum
	{
		TBox = 1,
		TSphere,
		TCharacterStart
	};
};

typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

///////////////////////////////////////////////////////
// local static methods
/**/
static const HSINT LocalAlphaBlendModeGet( const HSINT in_mode )
{
	if( in_mode == SMaterialStage::BlendModeDestinationAlphaGet() )
	{
		return GL_DST_ALPHA;
	}
	else if( in_mode == SMaterialStage::BlendModeDestinationColourGet () )
	{
		return GL_DST_COLOR;
	}
	else if( in_mode == SMaterialStage::BlendModeOneGet () )
	{
		return GL_ONE;
	}
	else if( in_mode == SMaterialStage::BlendModeOneMinusDestinationAlphaGet() )
	{
		return GL_ONE_MINUS_DST_ALPHA;
	}
	else if( in_mode == SMaterialStage::BlendModeOneMinusDestinationColourGet() )
	{
		return GL_ONE_MINUS_DST_COLOR;
	}
	else if( in_mode == SMaterialStage::BlendModeOneMinusSourceAlphaGet() )
	{
		return GL_ONE_MINUS_SRC_ALPHA;
	}
	else if( in_mode == SMaterialStage::BlendModeOneMinusSourceColourGet() )
	{
		return GL_ONE_MINUS_SRC_COLOR;
	}
	else if( in_mode == SMaterialStage::BlendModeSourceAlphaGet() )
	{
		return GL_SRC_ALPHA;
	}
	else if( in_mode == SMaterialStage::BlendModeSourceAlphaSaturateGet() )
	{
		return GL_SRC_ALPHA_SATURATE;
	}
	else if( in_mode == SMaterialStage::BlendModeSourceColourGet() )
	{
		return GL_SRC_COLOR;
	}
	else if( in_mode == SMaterialStage::BlendModeZeroGet() )
	{
		return GL_ZERO;
	}

	return GL_ZERO;
}

/**/
static const HSINT LocalAlphaTestModeGet( const HSINT in_mode ) 
{
	if( in_mode == SMaterialStage::AlphaTestModeAlwaysGet() )
	{
		return GL_ALWAYS;
	}
	else if( in_mode == SMaterialStage::AlphaTestModeEqualGet() )
	{
		return GL_EQUAL;
	}
	else if( in_mode == SMaterialStage::AlphaTestModeGreaterEqualGet() )
	{
		return GL_GEQUAL;
	}
	else if( in_mode == SMaterialStage::AlphaTestModeGreaterGet() )
	{
		return GL_GREATER;
	}
	else if( in_mode == SMaterialStage::AlphaTestModeLessEqualGet() )
	{
		return GL_LEQUAL;
	}
	else if( in_mode == SMaterialStage::AlphaTestModeLessGet() )
	{
		return GL_LESS;
	}
	else if( in_mode == SMaterialStage::AlphaTestModeNeverGet() )
	{
		return GL_NEVER;
	}
	else if( in_mode == SMaterialStage::AlphaTestModeNotEqualGet() )
	{
		return GL_NOTEQUAL;
	}

	return GL_ALWAYS;

}

/**/
static HVOID LocalEnableProperty(
	const GLenum in_enum,
	const HBOOL in_active
	)
{
	if( HTRUE == in_active )
	{
		glEnable( in_enum );
	}
	else
	{
		glDisable( in_enum );
	}

	return;
}

/**/
static HVOID LocalLightParam4Set(
	const GLenum in_lightId,
	const GLenum in_lightType,
	const PColourRealRgb& in_colour
	)
{
	const GLfloat arrayValue[ 4 ] = { 
		in_colour.RedGet(),
		in_colour.GreenGet(),
		in_colour.BlueGet(),
		1.0F
	};

	glLightfv( in_lightId, in_lightType, arrayValue );

	return;
}

/**/
static HVOID LocalLightParam4Set(
	const GLenum in_lightId,
	const GLenum in_lightType,
	const HVectorR3& in_vector,
	const GLfloat in_value
	)
{
	const GLfloat arrayValue[ 4 ] = { 
		in_vector[ 0 ],
		in_vector[ 1 ],
		in_vector[ 2 ],
		in_value
	};

	glLightfv( in_lightId, in_lightType, arrayValue );

	return;
}

/**/
static HVOID LocalMaterialParam4Set(
	const GLenum in_face,
	const GLenum in_name,
	const PColourRealRgb& in_colour,
	const HREAL in_alpha = 1.0F
	)
{
	const GLfloat arrayValue[ 4 ] = { 
		in_colour.RedGet(),
		in_colour.GreenGet(),
		in_colour.BlueGet(),
		in_alpha
	};

	glMaterialfv( in_face, in_name, arrayValue );

	return;
}
/**/
static HVOID LocalLightSet( 
	const SLight& in_light,
	const GLenum in_lightId
	//const Hubris::HMatrixR4& in_invertModelView
	)
{
	glLightf( in_lightId, GL_CONSTANT_ATTENUATION, 	in_light.FalloffExponentGet() );
	glLightf( in_lightId, GL_QUADRATIC_ATTENUATION, in_light.RadiusGet() );

	const HSINT mode = in_light.ModeGet();
	HREAL flagDirection = 0.0F;
	if( HTRUE == in_light.DirectionValidTest() )
	{
		flagDirection = 1.0F;
	}

	LocalLightParam4Set(
		in_lightId,
		GL_AMBIENT,
		in_light.PositionGet(),
		flagDirection
		);

	LocalLightParam4Set(
		in_lightId,
		GL_DIFFUSE,
		in_light.DiffuseGet()
		);

	if( HTRUE == in_light.DirectionValidTest() )
	{
		HREAL flagSpot = 0.0F;
		if( mode == SLight::ModeSpotGet() )
		{
			flagSpot = 1.0F;
		}

		LocalLightParam4Set(
			in_lightId,
			GL_SPECULAR,
			in_light.DirectionGet(),
			flagSpot
			);
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SOpenGl::SOpenGl()
: m_pInfo( HNULL )
, m_pShaderManager( HNULL )
, m_textureId( 0 )
, m_currentMaterialState()

, m_pglGenBuffersARB( HNULL )
, m_pglIsBufferARB( HNULL )
, m_pglBindBufferARB( HNULL )
, m_pglBufferDataARB( HNULL )
, m_pglBufferSubDataARB( HNULL )
, m_pglDeleteBuffersARB( HNULL )
, m_pglGetBufferParameterivARB( HNULL )
, m_pglMapBufferARB( HNULL )
, m_pglUnmapBufferARB( HNULL )

, m_pglDrawRangeElements( HNULL )

, m_pglCreateShaderObjectARB( HNULL )
, m_pglShaderSourceARB( HNULL )
, m_pglCompileShaderARB( HNULL )
, m_pglCreateProgramObjectARB( HNULL )
, m_pglAttachObjectARB( HNULL )
, m_pglLinkProgramARB( HNULL )
, m_pglUseProgramObjectARB( HNULL )
, m_pglGetInfoLogARB( HNULL )
, m_pglGetObjectParameterivARB( HNULL )
, m_pglDeleteShader( HNULL )
, m_pglDeleteProgram( HNULL )

, m_pglGetUniformLocationARB( HNULL )
, m_pglUniform1iARB( HNULL )
, m_pglUniformfvARB( HNULL )
{
	HCOMMON_NEW(
		m_pInfo,
		SOpenGlInfo
		);

	HCOMMON_NEW(
		m_pShaderManager,
		SOpenGlShaderManager
		);

	if( HTRUE == OpenGlInfoGet().ExtentionTest( "GL_ARB_vertex_buffer_object" ) )
	{
        m_pglGenBuffersARB = wglGetProcAddress( "glGenBuffersARB" );
		m_pglIsBufferARB = wglGetProcAddress( "glIsBufferARB" );
        m_pglBindBufferARB = wglGetProcAddress( "glBindBufferARB" );
        m_pglBufferDataARB = wglGetProcAddress( "glBufferDataARB" );
        m_pglBufferSubDataARB = wglGetProcAddress( "glBufferSubDataARB" );
        m_pglDeleteBuffersARB = wglGetProcAddress( "glDeleteBuffersARB" );
        m_pglGetBufferParameterivARB = wglGetProcAddress( "glGetBufferParameterivARB" );
        m_pglMapBufferARB = wglGetProcAddress( "glMapBufferARB" );
        m_pglUnmapBufferARB = wglGetProcAddress( "glUnmapBufferARB" );
    }

	//s_pglDrawRangeElements = ( PFNGLDRAWRANGEELEMENTSEXTPROC )wglGetProcAddress( "glDrawRangeElements" );

	m_pglCreateShaderObjectARB = wglGetProcAddress( "glCreateShaderObjectARB" );
	m_pglShaderSourceARB = wglGetProcAddress( "glShaderSourceARB" );
	m_pglCompileShaderARB = wglGetProcAddress( "glCompileShaderARB" );
	m_pglCreateProgramObjectARB = wglGetProcAddress( "glCreateProgramObjectARB" );
	m_pglAttachObjectARB = wglGetProcAddress( "glAttachObjectARB" );
	m_pglLinkProgramARB = wglGetProcAddress( "glLinkProgramARB" );
	m_pglUseProgramObjectARB = wglGetProcAddress( "glUseProgramObjectARB" );
	m_pglDeleteShader = wglGetProcAddress( "glDeleteShader" );
	m_pglDeleteProgram = wglGetProcAddress( "glDeletePrograms" );

	m_pglGetInfoLogARB = wglGetProcAddress( "glGetInfoLogARB" );
	m_pglGetObjectParameterivARB = wglGetProcAddress( "glGetObjectParameterivARB" );

	m_pglGetUniformLocationARB = wglGetProcAddress( "glGetUniformLocationARB" );
	m_pglUniform1iARB = wglGetProcAddress( "glUniform1iARB" );
	m_pglUniformfvARB = wglGetProcAddress( "glGetUniformfvARB" );

	return;
}

/**/
SOpenGl::~SOpenGl()
{
	HCOMMON_DELETE(
		m_pShaderManager,
		SOpenGlShaderManager
		);

	HCOMMON_DELETE(
		m_pInfo,
		SOpenGlInfo
		);

	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID SOpenGl::ErrorCheck()
{
//GL_INVALID_ENUM      0x0500
//GL_INVALID_VALUE     0x0501
//GL_INVALID_OPERATION 0x0502
//GL_STACK_OVERFLOW    0x0503
//GL_STACK_UNDERFLOW   0x0504
//GL_OUT_OF_MEMORY     0x0505
	GLenum error = GL_NO_ERROR;
	do
	{
		error = glGetError();
		if( error != GL_NO_ERROR )
		{
			HCOMMON_ASSERT_ALWAYS( "open gl error" );
			break;
		}
	}
	while( error != GL_NO_ERROR );

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SOpenGl::RestoreDefaults()
{
    glPixelStorei( GL_UNPACK_ALIGNMENT, 4 );      // 4-byte pixel alignment
	glFrontFace( GL_CCW ); //GL_CW
	glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, 1 );

	//LocalEnableProperty( GL_COLOR_MATERIAL, HTRUE );
	//GL_COLOR_MATERIAL_FACE

	//MaterialSet( SMaterialStage(), 1.0F );
	MaterialSet(
		SMaterialStage(),
		1.0F,
		HTRUE
		);

	return;
}

/**/
Hubris::HVOID SOpenGl::Clear( 
	const Hubris::HBOOL in_clearColour,
	const Hubris::HBOOL in_clearDepth,
	const Pride::PColourRealRgba& in_colour,
	const Hubris::HREAL in_depth
	)
{
	GLbitfield clearFlag = 0;
	if( HTRUE == in_clearColour )
	{
		glClearColor( 
			in_colour.RedGet(),
			in_colour.GreenGet(),
			in_colour.BlueGet(),
			in_colour.OpacityGet()
			);

		clearFlag |= GL_COLOR_BUFFER_BIT;
	}

	if( HTRUE == in_clearDepth )
	{
		glClearDepth(
			in_depth
			);

		clearFlag |= GL_DEPTH_BUFFER_BIT;
	}

	if( 0 != clearFlag )
	{
		glClear( clearFlag );
	}

	return;
}

/**/
Hubris::HVOID SOpenGl::CameraSet(
	const Pride::PCamera& in_camera
	)
{
	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();

	if( PCamera::TypePerspectiveGet() == in_camera.TypeGet() )
	{
		glFrustum(
			in_camera.LeftGet(),//-5
			in_camera.RightGet(),//5
			in_camera.TopGet(), //-5
			in_camera.BottomGet(),//5
			in_camera.NearGet(),
			in_camera.FarGet()
			);
	}
	else if( PCamera::TypeOrthogonalGet() == in_camera.TypeGet() )
	{
		glOrtho(
			in_camera.LeftGet(),//-5
			in_camera.RightGet(),//5
			in_camera.TopGet(), //-5
			in_camera.BottomGet(),//5
			in_camera.NearGet(),
			in_camera.FarGet()
			);
	}

	glMultMatrixf( HMatrixUtility::Inverse( in_camera.TransformGet() ).DataGet() );

	return;
}

/**/
Hubris::HVOID SOpenGl::ModelTransformSet(
	const Hubris::HMatrixR4& in_matrix
	)
{
	glMatrixMode( GL_MODELVIEW );
	glLoadMatrixf( in_matrix.DataGet() );

	return;
}

/**/
Hubris::HVOID SOpenGl::ModelTransformSet(
	const Hubris::HVectorR3& in_transform
	)
{
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef( 
		in_transform[ 0 ], 
		in_transform[ 1 ], 
		in_transform[ 2 ]
		);
	return;
}

/**/
Hubris::HVOID SOpenGl::DrawBox(
	const Pride::PBoundsR3& in_bounds
	)
{
	SOpenGlBox::DrawBox(
		in_bounds
		);

	return;
}

/**/
Hubris::HVOID SOpenGl::DrawSphere(
	const Hubris::HREAL in_radius
	)
{
	SOpenGlSphere::DrawSphere(
		in_radius,
		TDisplayList::TSphere
		);

	return;
}

/**/
Hubris::HVOID SOpenGl::DrawTriangle(
	const TArrayReal& in_arrayTriangle
	)
{
	if( in_arrayTriangle.SizeGet() <= 0 )
	{
		return;
	}

	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );
	glEnableClientState( GL_VERTEX_ARRAY );

	glVertexPointer( 3, GL_FLOAT, 0, in_arrayTriangle.RawGet() );

	glDrawArrays(
		GL_TRIANGLES,
		0,
		in_arrayTriangle.SizeGet() / 3
		);
	

	glPopClientAttrib();

	return;
}

/**/
Hubris::HVOID SOpenGl::DrawLine(
	const TArrayReal& in_arrayVector
	)
{
	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );
	glEnableClientState( GL_VERTEX_ARRAY );

	glVertexPointer( 3, GL_FLOAT, 0, in_arrayVector.RawGet() );

	glDrawArrays(
		GL_LINES,
		0,
		in_arrayVector.SizeGet() / 3 
		);

	glPopClientAttrib();

	return;
}

/**/
Hubris::HVOID SOpenGl::DrawGeometry(
	const TObjectHandle in_geometryIndex,
	const SMaterialGeometryStage& in_renderStage
	)
{
	SOpenGlGeometry::DrawGeometry(
		in_geometryIndex,
		*this,
		in_renderStage
		);
	return;
}

/**/
const SOpenGl::TObjectHandle SOpenGl::GeometryCreate(
	const Pride::PGeometry& in_geometry,
	const TArraySint& in_arrayDynamicIndex 
	)
{
	TObjectHandle handle = SOpenGlGeometry::GeometryCreate(
		in_geometry,
		in_arrayDynamicIndex,
		*this 
		);
	return handle;
}

/**/
Hubris::HVOID SOpenGl::GeometryUpdateData(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_geometryDataIndex,
	const Hubris::HVOID* const in_pData,
	const Hubris::HSINT in_offset,
	const Hubris::HSINT in_size
	)
{
	SOpenGlGeometry::GeometryUpdateData(
		in_geometryIndex,
		in_geometryDataIndex,
		in_pData,
		in_offset,
		in_size,
		*this 
		);
	return;
}

/**/
Hubris::HVOID SOpenGl::GeometryUpdateTopology(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_topologyIndex,
	const Hubris::HSINT in_start,
	const Hubris::HSINT in_count
	)
{
	SOpenGlGeometry::GeometryUpdateTopology(
		in_geometryIndex,
		in_topologyIndex,
		in_start,
		in_count,
		*this 
		);
	return;
}

/**/
Hubris::HVOID SOpenGl::GeometryRelease(
	const TObjectHandle in_geometryIndex
	)
{
	SOpenGlGeometry::GeometryRelease(
		in_geometryIndex,
		*this 
		);
	return;
}

/**/
Hubris::HVOID SOpenGl::DrawSprite(
	const Hubris::HSINT in_spriteIndex
	)
{
	SOpenGlSprite::DrawSprite(
		in_spriteIndex
		);
	return;
}

/**/
const Hubris::HSINT SOpenGl::SpriteCreate(
	const Hubris::HVectorR2& in_size,
	const Hubris::HVectorR2& in_topLeftUv,
	const Hubris::HVectorR2& in_bottomRightUv,
	const Pride::PColourRealRgba& in_colour
	)
{
	const HSINT index = SOpenGlSprite::SpriteCreate(
		in_size,
		in_topLeftUv,
		in_bottomRightUv,
		in_colour
		);
	return index;
}

/**/
Hubris::HVOID SOpenGl::SpriteRelease(
	const Hubris::HSINT in_spriteIndex
	)
{
	SOpenGlSprite::SpriteRelease(
		in_spriteIndex
		);
	return;
}

/**/
const Hubris::HBOOL SOpenGl::ShaderCreate(
	const Hubris::HString& in_shaderName,
	const SMaterialStageShader& in_shader
	)
{
	const HBOOL result = OpenGlShaderManagerGet().ShaderCreate( 
		*this,
		in_shaderName,
		in_shader
		);
	return result;
}

/**/
Hubris::HVOID SOpenGl::ShaderRelease(
	const Hubris::HString& in_shaderName
	)
{
	OpenGlShaderManagerGet().ShaderRelease( 
		*this,
		in_shaderName 
		);
	return;
}

/**/
Hubris::HVOID SOpenGl::ShaderReleaseAll()
{
	OpenGlShaderManagerGet().ShaderReleaseAll(
		*this		
		);
	return;
}

/**/
Hubris::HVOID SOpenGl::MaterialSet(
	const SMaterialStage& in_materialStage,
	const Hubris::HREAL in_alphaOverride
	)
{
	MaterialSet(
		in_materialStage,
		in_alphaOverride,
		HFALSE
		);

	return;
}

/**/
const Hubris::HSINT SOpenGl::LightCountMaxGet()
{
	const HSINT maxLights = OpenGlInfoGet().MaxLightsGet();
	return maxLights;
}

/**/
Hubris::HVOID SOpenGl::LightingActiveSet(
	const Hubris::HBOOL in_active
	)
{
	LocalEnableProperty( GL_LIGHTING, in_active );
	return;
}

/**/
Hubris::HVOID SOpenGl::LightSet(
	const TArrayLight& in_arrayLight,
	const Pride::PColourRealRgb& in_globalAmbient
	)
{
	const GLfloat arrayAmbient[ 4 ] = {
		in_globalAmbient.RedGet(),
		in_globalAmbient.GreenGet(),
		in_globalAmbient.BlueGet(),
		1.0F
	};
	glLightModelfv(
		GL_LIGHT_MODEL_AMBIENT,
		arrayAmbient
		);

	const HSINT maxLight = LightCountMaxGet();
	const HSINT countLight = in_arrayLight.SizeGet();
	HSINT trace = 0;
	for( HSINT index = 0; index < maxLight; ++index )
	{
		const GLenum lightId = GL_LIGHT0 + index;
		//is this needed to change lights?
		glDisable( lightId );

		if( trace < countLight )
		{
			LocalLightSet( 
				in_arrayLight[ trace ],
				lightId
				);
			trace += 1;

			glEnable( lightId );
		}
	}

	//g_activeLightCount
	//GlUniform1iARB( GlGetUniformLocationARB( m_shaderVertexLight, "g_activeLightCount" ), countLight );

	return;
}

/**/
Hubris::HVOID SOpenGl::FogActiveSet(
	const Hubris::HBOOL in_active
	)
{
	LocalEnableProperty( GL_FOG, in_active );
	return;
}

/**/
Hubris::HVOID SOpenGl::FogSet(
	const Hubris::HSINT in_mode,
	const Pride::PColourRealRgba& in_colour,
	const Hubris::HREAL in_amount,
	const Hubris::HREAL in_near,
	const Hubris::HREAL in_far
	)
{
	glFogi( 
		GL_FOG_MODE,
		in_mode
		);

	GLfloat colour[ 4 ];
	colour[ 0 ] = in_colour.RedGet();
	colour[ 1 ] = in_colour.GreenGet();
	colour[ 2 ] = in_colour.BlueGet();
	colour[ 3 ] = in_colour.OpacityGet();
	glFogfv(
		GL_FOG_COLOR,
		colour
		);

	glFogf(
		GL_FOG_DENSITY,
		in_amount
		);

	glFogf(
		GL_FOG_START,
		in_near
		);

	glFogf(
		GL_FOG_END,
		in_far
		);

	return;
}

/**/
Hubris::HVOID SOpenGl::DepthTestActiveSet(
	const Hubris::HBOOL in_active
	)
{
	LocalEnableProperty( GL_DEPTH_TEST, in_active );
	glDepthFunc( GL_LEQUAL );
	return;
}

/**/
const Hubris::HSINT SOpenGl::TextureSizeMaxGet()
{
	const HSINT textureSize = OpenGlInfoGet().MaxTextureSizeGet();
	return textureSize;
}

/**/
Hubris::HVOID SOpenGl::TextureActiveSet(
	const Hubris::HBOOL in_active
	)
{
	LocalEnableProperty( GL_TEXTURE_2D, in_active );
	return;
}

/**/
Hubris::HVOID SOpenGl::TextureSet(
	const Hubris::HSINT in_mipMapLevel,
	const Pride::PImageRgba& in_image
	)
{
	if( 0 == m_textureId )
	{
		glGenTextures( 1, ( GLuint* )&m_textureId );
	}

	const HVectorS2 size = in_image.SizeGet();

	glBindTexture( GL_TEXTURE_2D, m_textureId );
	glTexImage2D(
		GL_TEXTURE_2D,
		in_mipMapLevel,
		GL_RGBA, //GL_LUMINANCE_ALPHA, damn, internal format changes application of texture
		size[ 0 ],
		size[ 1 ],
		0,
		GL_BGRA_EXT,
		GL_UNSIGNED_BYTE,
		in_image.RawGet()
		);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );	// Linear Filtering
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );	// Linear Filtering

	return;
}

/**/
Hubris::HVOID SOpenGl::TextureTransformSet(
	const Hubris::HMatrixR4& in_transform
	)
{
	glMatrixMode( GL_TEXTURE );
	//const HMatrixR4 localMatrix = HMatrixUtility::Transpose( in_transform );
	glLoadMatrixf( in_transform.DataGet() );

	return;
}

/**/
Hubris::HVOID SOpenGl::GlBindBufferARB( const Hubris::HSINT in_target, const Hubris::HSINT in_bufferId )
{
	if( HNULL != m_pglBindBufferARB )
	{
		( ( PFNGLBINDBUFFERARBPROC )m_pglBindBufferARB )( in_target, in_bufferId );
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlDeleteBuffersARB( const Hubris::HSINT in_size, const Hubris::HSINT* in_pBufferId )
{
	if( HNULL != m_pglDeleteBuffersARB )
	{
		( ( PFNGLDELETEBUFFERSARBPROC )m_pglDeleteBuffersARB )( in_size, ( const GLuint* )in_pBufferId );
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlGenBuffersARB( const Hubris::HSINT in_target, Hubris::HSINT* const out_pBufferId )
{
	if( HNULL != m_pglGenBuffersARB )
	{
		( ( PFNGLGENBUFFERSARBPROC )m_pglGenBuffersARB )( in_target, ( GLuint* )out_pBufferId );
	}
	return;
}

/**/
const Hubris::HBOOL SOpenGl::GlIsBufferARB( const Hubris::HSINT in_bufferId )
{
	if( HNULL != m_pglIsBufferARB )
	{
		const HBOOL result = ( 0 != ( ( PFNGLISBUFFERARBPROC ) m_pglIsBufferARB )( in_bufferId ) );
		return result;
	}
	return HTRUE;
}

/**/
Hubris::HVOID SOpenGl::GlBufferDataARB( const Hubris::HSINT in_target, const Hubris::HSINT in_size, const Hubris::HVOID* const in_pData, const Hubris::HSINT in_usage )
{
	if( HNULL != m_pglBufferDataARB )
	{
		( ( PFNGLBUFFERDATAARBPROC ) m_pglBufferDataARB )( 
			in_target,
			in_size, 
			in_pData,
			in_usage
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlBufferSubDataARB( const Hubris::HSINT in_target, const Hubris::HSINT in_offset, const Hubris::HSINT in_size, const Hubris::HVOID* const in_pData )
{
	if( HNULL != m_pglBufferSubDataARB )
	{
		( ( PFNGLBUFFERSUBDATAARBPROC )m_pglBufferSubDataARB )( 
			in_target,
			in_offset, 
			in_size,
			in_pData
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlGetBufferParameterivARB( const Hubris::HSINT in_target, const Hubris::HSINT in_pname, Hubris::HSINT* out_pParams )
{
	if( HNULL != m_pglGetBufferParameterivARB )
	{
		( ( PFNGLGETBUFFERPARAMETERIVARBPROC )m_pglGetBufferParameterivARB )( 
			in_target,
			in_pname,
			out_pParams
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlMapBufferARB( const Hubris::HSINT in_target, const Hubris::HSINT in_access )
{
	if( HNULL != m_pglMapBufferARB )
	{
		( ( PFNGLMAPBUFFERARBPROC )m_pglMapBufferARB )( 
			in_target,
			in_access
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlUnmapBufferARB( const Hubris::HSINT in_target )
{
	if( HNULL != m_pglUnmapBufferARB )
	{
		( ( PFNGLUNMAPBUFFERARBPROC )m_pglUnmapBufferARB )( 
			in_target
			);
	}
	return;
}

/**/
const Hubris::HU32 SOpenGl::GlCreateShaderObjectARB( const Hubris::HSINT in_target )
{
	if( HNULL != m_pglCreateShaderObjectARB )
	{
		const HU32 handle = ( ( PFNGLCREATESHADEROBJECTARBPROC )m_pglCreateShaderObjectARB )( 
			in_target
			);
		return handle;
	}
	return 0;
}

/**/
Hubris::HVOID SOpenGl::GlShaderSourceARB( const Hubris::HU32 in_handle, const Hubris::HSINT in_count, const Hubris::HCHAR** in_arrayString, const Hubris::HSINT* length )
{
	if( HNULL != m_pglShaderSourceARB )
	{
		( ( PFNGLSHADERSOURCEARBPROC )m_pglShaderSourceARB )( 
			in_handle,
			in_count,
			in_arrayString,
			length
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlCompileShaderARB( const Hubris::HU32 in_handle )
{
	if( HNULL != m_pglCompileShaderARB )
	{
		( ( PFNGLCOMPILESHADERARBPROC )m_pglCompileShaderARB )( 
			in_handle
			);
	}
	return;
}

/**/
const Hubris::HU32 SOpenGl::GlCreateProgramObjectARB()
{
	if( HNULL != m_pglCreateProgramObjectARB )
	{
		const HU32 handle = ( ( PFNGLCREATEPROGRAMOBJECTARBPROC )m_pglCreateProgramObjectARB )();
		return handle;
	}
	return 0;
}

/**/
Hubris::HVOID SOpenGl::GlAttachObjectARB( const Hubris::HU32 in_program, const Hubris::HU32 in_shader )
{
	if( HNULL != m_pglAttachObjectARB )
	{
		( ( PFNGLATTACHOBJECTARBPROC )m_pglAttachObjectARB )( 
			in_program,
			in_shader
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlLinkProgramARB( const Hubris::HU32 in_program )
{
	if( HNULL != m_pglLinkProgramARB )
	{
		( ( PFNGLLINKPROGRAMARBPROC )m_pglLinkProgramARB )( 
			in_program
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlUseProgramObjectARB( const Hubris::HU32 in_program )
{
	if( HNULL != m_pglUseProgramObjectARB )
	{
		( ( PFNGLUSEPROGRAMOBJECTARBPROC )m_pglUseProgramObjectARB )( 
			in_program
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlDeleteShaderARB( const Hubris::HU32 in_handle )
{
	if( HNULL != m_pglDeleteShader )
	{
		( ( PFNGLDELETESHADERPROC )m_pglDeleteShader )( 
			in_handle
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGl::GlDeleteProgramARB( const Hubris::HU32 in_program )
{
	if( HNULL != m_pglDeleteProgram )
	{
		( ( PFNGLDELETEPROGRAMPROC )m_pglDeleteProgram )(
			in_program
			);
	}
	return;
}

/**/
const Hubris::HString SOpenGl::GlGetInfoLogARB( const Hubris::HU32 in_handle )
{
	if( HNULL != m_pglGetInfoLogARB )
	{
		HSINT length = 0;
		GlGetObjectParameterivARB( in_handle, GL_OBJECT_INFO_LOG_LENGTH_ARB, length );
		HString returnString;
		returnString.SizeSet( length );

		( ( PFNGLGETINFOLOGARBPROC )m_pglGetInfoLogARB )( 
			in_handle,
			length,
			0,
			( GLcharARB * )returnString.RawGet()
			);

		return returnString;
	}

	return HNULL;
}

/**/
Hubris::HVOID SOpenGl::GlGetObjectParameterivARB( const Hubris::HU32 in_handle, const Hubris::HSINT in_pname, Hubris::HSINT& out_value )
{
	if( HNULL != m_pglGetObjectParameterivARB )
	{
		( ( PFNGLGETOBJECTPARAMETERIVARBPROC )m_pglGetObjectParameterivARB )(
			in_handle,
			in_pname,
			&out_value
			);
	}

	return;
}

/**/
const Hubris::HSINT SOpenGl::GlGetUniformLocationARB( const Hubris::HU32 in_programHandle, const Hubris::HString& in_name )
{
	if( HNULL != m_pglGetUniformLocationARB )
	{
		const HSINT location = ( ( PFNGLGETUNIFORMLOCATIONARBPROC )m_pglGetUniformLocationARB )(
			in_programHandle,
			in_name.RawGet()
			);
		return location;
	}

	return 0;
}

/**/
Hubris::HVOID SOpenGl::GlUniform1iARB( const Hubris::HSINT in_location, const Hubris::HSINT in_value )
{
	if( HNULL != m_pglUniform1iARB )
	{
		( ( PFNGLUNIFORM1IARBPROC )m_pglUniform1iARB )(
			in_location,
			in_value
			);
	}

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID SOpenGl::MaterialSet(
	const SMaterialStage& in_materialStage,
	const HREAL in_alphaOverride,
	const HBOOL in_forceChange
	)
{
	SMaterialStage localMaterialStage( in_materialStage );
	//if there is an alpha overide, fonce alpha blending to on, combie with material alpha
	if( in_alphaOverride < 1.0F )
	{
		localMaterialStage.AlphaSet( in_alphaOverride * in_materialStage.AlphaGet() );
		localMaterialStage.FlagAlphaBlendSet( HTRUE );
	}

	//alpha blend
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagAlphaBlendGet() != localMaterialStage.FlagAlphaBlendGet() ) )
	{
		if( HTRUE == localMaterialStage.FlagAlphaBlendGet() )
		{
			LocalEnableProperty( GL_BLEND, HTRUE );
			glBlendFunc( 
				LocalAlphaBlendModeGet( localMaterialStage.BlendModeSourceGet() ), 
				LocalAlphaBlendModeGet( localMaterialStage.BlendModeDestinationGet() )
				);
		}
		else
		{
			LocalEnableProperty( GL_BLEND, HFALSE );
		}
	}

	//alpha test
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagAlphaTestGet() != localMaterialStage.FlagAlphaTestGet() ) )
	{
		if( HTRUE == localMaterialStage.FlagAlphaTestGet() )
		{
			LocalEnableProperty( GL_ALPHA_TEST, HTRUE );
			glAlphaFunc( 
				LocalAlphaTestModeGet( localMaterialStage.AlphaTestModeGet() ), 
				localMaterialStage.AlphaTestReferenceGet()
				);
		}
		else
		{
			LocalEnableProperty( GL_ALPHA_TEST, HFALSE );
		}
	}


	//generate sphere uv
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagGenerateSphereUVGet() != localMaterialStage.FlagGenerateSphereUVGet() ) )
	{
		LocalEnableProperty( GL_TEXTURE_GEN_S, localMaterialStage.FlagGenerateSphereUVGet() );
		LocalEnableProperty( GL_TEXTURE_GEN_T, localMaterialStage.FlagGenerateSphereUVGet() );
	}

	//smooth
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagSmoothGet() != localMaterialStage.FlagSmoothGet() ) )
	{
		if( HTRUE == localMaterialStage.FlagSmoothGet() )
		{
			glShadeModel( GL_SMOOTH );
		}
		else
		{
			glShadeModel( GL_FLAT );
		}
	}

	//two sided
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagTwoSidedGet() != localMaterialStage.FlagTwoSidedGet() ) )
	{
		if( HTRUE == localMaterialStage.FlagTwoSidedGet() )
		{
			LocalEnableProperty( GL_CULL_FACE, HFALSE );
		}
		else
		{
			LocalEnableProperty( GL_CULL_FACE, HTRUE );
		}
	}

	//lighting
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagUseLightGet() != localMaterialStage.FlagUseLightGet() ) )
	{
		LocalEnableProperty( GL_LIGHTING, localMaterialStage.FlagUseLightGet() );
	}

	//GL_COLOR_MATERIAL
	//if( ( HTRUE == in_forceChange ) ||
	//	( m_currentMaterialState.FlagUseColorMaterialGet() != localMaterialStage.FlagUseColorMaterialGet() ) )
	//{
	//	LocalEnableProperty( GL_COLOR_MATERIAL, localMaterialStage.FlagUseColorMaterialGet() );
	//}

	//texture
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagUseTextureGet() != localMaterialStage.FlagUseTextureGet() ) )
	{
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
		LocalEnableProperty( GL_TEXTURE_2D, localMaterialStage.FlagUseTextureGet() );
	}

	//z read
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagZReadGet() != localMaterialStage.FlagZReadGet() ) )
	{
		LocalEnableProperty( GL_DEPTH_TEST, localMaterialStage.FlagZReadGet() );
	}

	//z write
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.FlagZWriteGet() != localMaterialStage.FlagZWriteGet() ) )
	{
		if( HTRUE == localMaterialStage.FlagZWriteGet() )
		{
			glDepthMask( 1 );
		}
		else
		{
			glDepthMask( 0 );
		}
	}

	//ambient
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.ColourAmbientGet() != localMaterialStage.ColourAmbientGet() ) )
	{
		LocalMaterialParam4Set( GL_FRONT_AND_BACK, GL_AMBIENT, localMaterialStage.ColourAmbientGet() );
	}
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.ColourDiffuseGet() != localMaterialStage.ColourDiffuseGet() ) ||
		( m_currentMaterialState.AlphaGet() != localMaterialStage.AlphaGet() ) )
	{
		LocalMaterialParam4Set( GL_FRONT_AND_BACK, GL_DIFFUSE, localMaterialStage.ColourDiffuseGet(), localMaterialStage.AlphaGet() );
	}
	//if( ( HTRUE == in_forceChange ) ||
	//	( m_currentMaterialState.ColourSpecularGet() != localMaterialStage.ColourSpecularGet() ) )
	//{
	//	LocalMaterialParam4Set( GL_FRONT_AND_BACK, GL_SPECULAR, localMaterialStage.ColourSpecularGet() );
	//}
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.ColourEmissionGet() != localMaterialStage.ColourEmissionGet() ) )
	{
		LocalMaterialParam4Set( GL_FRONT_AND_BACK, GL_EMISSION, localMaterialStage.ColourEmissionGet() );
	}
	if( ( HTRUE == in_forceChange ) ||
		( m_currentMaterialState.ShininessGet() != localMaterialStage.ShininessGet() ) )
	{
		glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, localMaterialStage.ShininessGet() );
	}

	OpenGlShaderManagerGet().ShaderSet(
		*this,
		localMaterialStage.ShaderNameGet(),
		localMaterialStage.ShaderDataGet()
		);

	//we need to set the colour, as caling drawElement with a vbo could leave it in an undifined state...
	const GLfloat defaultColour[] = { 1.0F, 1.0F, 1.0F, 1.0F };
	glColor4fv( defaultColour );
	//LocalEnableProperty( GL_COLOR_MATERIAL, HFALSE );

	m_currentMaterialState = localMaterialStage;

	return;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SOpenGlInfo& SOpenGl::OpenGlInfoGet()const
{
	HCOMMON_ASSERT( HNULL != m_pInfo, "invalid member" );
	return( *m_pInfo );
}

/**/
SOpenGlInfo& SOpenGl::OpenGlInfoGet()
{
	HCOMMON_ASSERT( HNULL != m_pInfo, "invalid member" );
	return( *m_pInfo );
}

/**/
const SOpenGlShaderManager& SOpenGl::OpenGlShaderManagerGet()const
{
	HCOMMON_ASSERT( HNULL != m_pShaderManager, "invalid member" );
	return( *m_pShaderManager );
}

/**/
SOpenGlShaderManager& SOpenGl::OpenGlShaderManagerGet()
{
	HCOMMON_ASSERT( HNULL != m_pShaderManager, "invalid member" );
	return( *m_pShaderManager );
}

/**/