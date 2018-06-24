//file: Sloth/SWindow/SWindowImplementationRenderOpenGl.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowImplementationRenderOpenGl.h"

#include "Sloth/SWindow/SWindowParamOpenGl.h"

#include "Sloth/SInterface/SInterface_Export.h"
#include "Sloth/SOpenGl/SOpenGl_Export.h"

#include< windows.h >
#include< windef.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

////////////////////////////////////////////////////////////////
// local static variables
/**/

///////////////////////////////////////////////////////
// creation
/**/
SWindowImplementationRenderOpenGl::SWindowImplementationRenderOpenGl()
: SWindowImplementationRender()
, m_deviceContext( HNULL )
, m_glRenderContext( HNULL )
, m_pOpenGl( HNULL )
{
	return;
}

/**/
SWindowImplementationRenderOpenGl::~SWindowImplementationRenderOpenGl()
{
	HCOMMON_DELETE(
		m_pOpenGl,
		SOpenGl
		);

	return;
}

///////////////////////////////////////////////////////
// implement SWindowImplementationBase
/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::OnClose(
	HWND in_hWnd 
	)
{
	in_hWnd;
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::OnCreate( 
	HWND in_hWnd 
	)
{
	m_deviceContext = GetDC( ( ::HWND )in_hWnd );

	PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
	SecureZeroMemory( &pixelFormatDescriptor, sizeof( pixelFormatDescriptor ) );
	pixelFormatDescriptor.nSize = sizeof( pixelFormatDescriptor );
	pixelFormatDescriptor.nVersion = 1;
	//double buffering was resulting in extra paint calls of the surface?
	//pixelFormatDescriptor.dwFlags = PFD_SUPPORT_GDI | PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	//pixelFormatDescriptor.dwFlags = PFD_SUPPORT_GDI | PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_GENERIC_ACCELERATED;
	pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDescriptor.cColorBits = 24;
	pixelFormatDescriptor.cDepthBits = 16;
	pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;
	int iFormat = ChoosePixelFormat( 
		( ::HDC )m_deviceContext, 
		&pixelFormatDescriptor 
		);
	SetPixelFormat( 
		( ::HDC )m_deviceContext, 
		iFormat, 
		&pixelFormatDescriptor 
		);

	m_glRenderContext = wglCreateContext( ( ::HDC )m_deviceContext );

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::OnPaint( 
	HWND HCOMMON_UNUSED_VAR( in_hWnd )
	)
{
	wglMakeCurrent( ( ::HDC )m_deviceContext, ( ::HGLRC )m_glRenderContext );

	//glAccum( GL_MULT, 0.5F );
	//glAccum( GL_ACCUM, 0.5F );
	//glAccum( GL_RETURN, 1.0F );

	SwapBuffers( ( ::HDC )m_deviceContext );

	SOpenGl::ErrorCheck();
	
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::OnSize( 
	HWND HCOMMON_UNUSED_VAR( in_hWnd ),
	const Hubris::HSINT in_width,
	const Hubris::HSINT in_height
	)
{
	glViewport( 0, 0, (GLsizei)( in_width ), (GLsizei)( in_height ) );

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::OnDestroy(
	HWND in_hWnd
	)
{
	wglMakeCurrent( ( ::HDC )m_deviceContext, HNULL );
	wglDeleteContext( ( ::HGLRC )m_glRenderContext );
	m_glRenderContext = HNULL;
	ReleaseDC( ( ::HWND )in_hWnd, ( ::HDC )m_deviceContext );
	m_deviceContext = HNULL;

	return;
}

///////////////////////////////////////////////////////
// implement SInterfaceRender
/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::Clear( 
	const Hubris::HBOOL in_clearColour,
	const Hubris::HBOOL in_clearDepth,
	const Pride::PColourRealRgba& in_colour,
	const Hubris::HREAL in_depth
	)
{
	OpenGlGet().Clear(
		in_clearColour,
		in_clearDepth,
		in_colour,
		in_depth
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::CameraSet(
	const Pride::PCamera& in_camera
	)
{
	OpenGlGet().CameraSet(
		in_camera
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::ModelTransformSet(
	const Hubris::HMatrixR4& in_matrix
	)
{
	OpenGlGet().ModelTransformSet(
		in_matrix
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::ModelTransformSet(
	const Hubris::HVectorR3& in_transform
	)
{
	OpenGlGet().ModelTransformSet(
		in_transform
		);

	return;
}
/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::DrawBox(
	const Pride::PBoundsR3& in_bounds
	)
{
	OpenGlGet().DrawBox(
		in_bounds
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::DrawSphere(
	const Hubris::HREAL in_radius
	)
{
	OpenGlGet().DrawSphere(
		in_radius
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::DrawTriangle(
	const TArrayReal& in_arrayTriangle
	)
{
	OpenGlGet().DrawTriangle(
		in_arrayTriangle
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::DrawLine(
	const TArrayReal& in_arrayVector
	)
{
	OpenGlGet().DrawLine(
		in_arrayVector
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::DrawGeometry(
	const TObjectHandle in_geometryIndex,
	const SMaterialGeometryStage& in_renderStage
	)
{
	OpenGlGet().DrawGeometry(
		in_geometryIndex,
		in_renderStage
		);
	return;
}

/**/
const SWindowImplementationRenderOpenGl::TObjectHandle SWindowImplementationRenderOpenGl::GeometryCreate(
	const Pride::PGeometry& in_geometry,
	const TArraySint& in_arrayDynamicIndex 
	)
{
	TObjectHandle objectId = OpenGlGet().GeometryCreate(
		in_geometry,
		in_arrayDynamicIndex
		);
	return objectId;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::GeometryUpdateData(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_geometryDataIndex,
	const Hubris::HVOID* const in_pData,
	const Hubris::HSINT in_offset,
	const Hubris::HSINT in_size
	)
{
	OpenGlGet().GeometryUpdateData(
		in_geometryIndex,
		in_geometryDataIndex,
		in_pData,
		in_offset,
		in_size
		);
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::GeometryUpdateTopology(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_topologyIndex,
	const Hubris::HSINT in_start,
	const Hubris::HSINT in_count
	)
{
	OpenGlGet().GeometryUpdateTopology(
		in_geometryIndex,
		in_topologyIndex,
		in_start,
		in_count
		);
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::GeometryRelease(
	const TObjectHandle in_geometryIndex
	)
{
	OpenGlGet().GeometryRelease(
		in_geometryIndex
		);
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::DrawSprite(
	const Hubris::HSINT in_spriteIndex
	)
{
	OpenGlGet().DrawSprite( in_spriteIndex );
	return;
}

/**/
const Hubris::HSINT SWindowImplementationRenderOpenGl::SpriteCreate(
	const Hubris::HVectorR2& in_size,
	const Hubris::HVectorR2& in_topLeftUv,
	const Hubris::HVectorR2& in_bottomRightUv,
	const Pride::PColourRealRgba& in_colour
	)
{
	const HSINT index = OpenGlGet().SpriteCreate( 
		in_size,
		in_topLeftUv,
		in_bottomRightUv,
		in_colour
		);
	return index;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::SpriteRelease(
	const Hubris::HSINT in_spriteIndex
	)
{
	OpenGlGet().SpriteRelease( in_spriteIndex );
	return;
}

/**/
const Hubris::HBOOL SWindowImplementationRenderOpenGl::ShaderCreate(
	const Hubris::HString& in_shaderName,
	const SMaterialStageShader& in_shader
	)
{
	const HBOOL result = OpenGlGet().ShaderCreate( 
		in_shaderName,
		in_shader
		);
	return result;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::ShaderRelease(
	const Hubris::HString& in_shaderName
	)
{
	OpenGlGet().ShaderRelease( 
		in_shaderName
		);
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::ShaderReleaseAll()
{
	OpenGlGet().ShaderReleaseAll();
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::MaterialSet(
	const SMaterialStage& in_materialStage,
	const Hubris::HREAL in_alphaOverride
	)
{
	OpenGlGet().MaterialSet(
		in_materialStage,
		in_alphaOverride
		);
	return;
}

/**/
const Hubris::HSINT SWindowImplementationRenderOpenGl::LightCountMaxGet()
{
	const HSINT maxLights = OpenGlGet().LightCountMaxGet();
	return maxLights;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::LightSet(
	const TArrayLight& in_arrayLight,
	const Pride::PColourRealRgb& in_globalAmbient
	)
{
	OpenGlGet().LightSet(
		in_arrayLight,
		in_globalAmbient
		);
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::FogActiveSet(
	const Hubris::HBOOL in_active
	)
{
	OpenGlGet().FogActiveSet(
		in_active
		);
	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::FogSet(
	const Hubris::HSINT in_mode,
	const Pride::PColourRealRgba& in_colour,
	const Hubris::HREAL in_amount,
	const Hubris::HREAL in_near, //0 .. 1.0
	const Hubris::HREAL in_far //0 .. 1.0
	)
{
	OpenGlGet().FogSet(
		in_mode,
		in_colour,
		in_amount,
		in_near,
		in_far
		);

	return;
}

/**/
const Hubris::HSINT SWindowImplementationRenderOpenGl::TextureSizeMaxGet()
{
	const HSINT maxSize = OpenGlGet().TextureSizeMaxGet();
	return maxSize;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::TextureSet(
	const Hubris::HSINT in_mipMapLevel,
	const Pride::PImageRgba& in_image
	)
{
	OpenGlGet().TextureSet(
		in_mipMapLevel,
		in_image
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationRenderOpenGl::TextureTransformSet(
	const Hubris::HMatrixR4& in_transform
	)
{
	OpenGlGet().TextureTransformSet(
		in_transform
		);
	return;
}

///////////////////////////////////////////////////////
// implement SWindowImplementationRender
/**/
SInterfaceRender* const SWindowImplementationRenderOpenGl::RenderInterfaceCreate()
{
	::HWND hWnd = ( ::HWND )HWndGet();
	::HDC deviceContext = GetDC( hWnd );

	wglMakeCurrent( deviceContext, ( ::HGLRC )m_glRenderContext );

	if( HNULL == m_pOpenGl )
	{
		HCOMMON_NEW(
			m_pOpenGl,
			SOpenGl
			);
	}

	OpenGlGet().RestoreDefaults();

	SInterfaceRender* pInterface = HNULL;
	HCOMMON_NEW_PARAM(
		pInterface,
		SInterfaceRender,
		( *this )
		);

	ReleaseDC( hWnd, deviceContext );

	return( pInterface );
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SOpenGl& SWindowImplementationRenderOpenGl::OpenGlGet()const
{
	HCOMMON_ASSERT( HNULL != m_pOpenGl, "invalid member" );
	return( *m_pOpenGl );
}

/**/
SOpenGl& SWindowImplementationRenderOpenGl::OpenGlGet()
{
	HCOMMON_ASSERT( HNULL != m_pOpenGl, "invalid member" );
	return( *m_pOpenGl );
}

/**/
