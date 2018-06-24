//file: Sloth/SWindow/SWindowImplementationRenderOpenGl.h
#ifndef _S_WINDOW_IMPLEMENTATION_RENDER_OPEN_GL_H_
#define _S_WINDOW_IMPLEMENTATION_RENDER_OPEN_GL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowImplementationRender.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SMaterialStage;
	class SWindowComponentImage;
	class SWindowImageInterface;
	class SWindowComponentPaintDx;
	struct SWindowParamOpenGl;
	class SLight;
	class SOpenGl;
	class SMaterialGeometryStage;
	class SMaterialStageShader;

	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SWindowImplementationRenderOpenGl : public SWindowImplementationRender
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< SLight >TArrayLight;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HVOID* const TObjectHandle;
		typedef Hubris::HVOID* HGLRC;
		//typedef Hubris::HContainerArray< Pride::PTriangle >TArrayTriangle;
		//typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;
		typedef Hubris::HVOID* HWND;
		typedef Hubris::HVOID* HDC;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowImplementationRenderOpenGl();
		virtual ~SWindowImplementationRenderOpenGl();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowImplementationRenderOpenGl( const SWindowImplementationRenderOpenGl& in_src );
		const SWindowImplementationRenderOpenGl& operator=( const SWindowImplementationRenderOpenGl& in_rhs );

		///////////////////////////////////////////////////////
		// implement SWindowImplementationBase
	private:
		virtual Hubris::HVOID OnClose(
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnCreate( 
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnPaint( 
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnSize( 
			HWND in_hWnd,
			const Hubris::HSINT in_width,
			const Hubris::HSINT in_height
			);
		virtual Hubris::HVOID OnDestroy(
			HWND in_hWnd 			
			);

		///////////////////////////////////////////////////////
		// implement SInterfaceRender
	public:
		Hubris::HVOID Clear( 
			const Hubris::HBOOL in_clearColour,
			const Hubris::HBOOL in_clearDepth,
			const Pride::PColourRealRgba& in_colour,
			const Hubris::HREAL in_depth
			);

		Hubris::HVOID CameraSet(
			const Pride::PCamera& in_camera
			);

		Hubris::HVOID ModelTransformSet(
			const Hubris::HMatrixR4& in_matrix
			);
		Hubris::HVOID ModelTransformSet(
			const Hubris::HVectorR3& in_transform
			);

		Hubris::HVOID DrawBox(
			const Pride::PBoundsR3& in_bounds
			);
		Hubris::HVOID DrawSphere(
			const Hubris::HREAL in_radius
			);
		Hubris::HVOID DrawTriangle(
			const TArrayReal& in_arrayTriangle
			);
		Hubris::HVOID DrawLine(
			const TArrayReal& in_arraySegment
			);
		Hubris::HVOID DrawGeometry(
			const TObjectHandle in_geometryIndex,
			const SMaterialGeometryStage& in_renderStage
			);
		const TObjectHandle GeometryCreate(
			const Pride::PGeometry& in_geometry,
			const TArraySint& in_arrayDynamicIndex 
			);
		Hubris::HVOID GeometryUpdateData(
			const TObjectHandle in_geometryIndex,
			const Hubris::HSINT in_geometryDataIndex,
			const Hubris::HVOID* const in_pData,
			const Hubris::HSINT in_offset,
			const Hubris::HSINT in_size
			);
		Hubris::HVOID GeometryUpdateTopology(
			const TObjectHandle in_geometryIndex,
			const Hubris::HSINT in_topologyIndex,
			const Hubris::HSINT in_start,
			const Hubris::HSINT in_count
			);
		Hubris::HVOID GeometryRelease(
			const TObjectHandle in_geometryIndex
			);

		Hubris::HVOID DrawSprite(
			const Hubris::HSINT in_spriteIndex
			);
		const Hubris::HSINT SpriteCreate(
			const Hubris::HVectorR2& in_size,
			const Hubris::HVectorR2& in_topLeftUv,
			const Hubris::HVectorR2& in_bottomRightUv,
			const Pride::PColourRealRgba& in_colour
			);
		Hubris::HVOID SpriteRelease(
			const Hubris::HSINT in_spriteIndex
			);

		const Hubris::HBOOL ShaderCreate(
			const Hubris::HString& in_shaderName,
			const SMaterialStageShader& in_shader
			);
		Hubris::HVOID ShaderRelease(
			const Hubris::HString& in_shaderName
			);
		Hubris::HVOID ShaderReleaseAll();

		Hubris::HVOID MaterialSet(
			const SMaterialStage& in_materialStage,
			const Hubris::HREAL in_alphaOverride
			);

		const Hubris::HSINT LightCountMaxGet();
		Hubris::HVOID LightSet(
			const TArrayLight& in_arrayLight,
			const Pride::PColourRealRgb& in_globalAmbient
			);

		Hubris::HVOID FogActiveSet(
			const Hubris::HBOOL in_active
			);

		Hubris::HVOID FogSet(
			const Hubris::HSINT in_mode,
			const Pride::PColourRealRgba& in_colour,
			const Hubris::HREAL in_amount,
			const Hubris::HREAL in_near,
			const Hubris::HREAL in_far
			);

		const Hubris::HSINT TextureSizeMaxGet();
		Hubris::HVOID TextureSet(
			const Hubris::HSINT in_mipMapLevel,
			const Pride::PImageRgba& in_image
			);
		Hubris::HVOID TextureTransformSet(
			const Hubris::HMatrixR4& in_transform
			);
		///////////////////////////////////////////////////////
		// implement SWindowImplementationRender
	public:
		virtual SInterfaceRender* const RenderInterfaceCreate();

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SOpenGl& OpenGlGet()const;
		SOpenGl& OpenGlGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		HDC m_deviceContext;
		HGLRC m_glRenderContext;
		SOpenGl* m_pOpenGl;

	};

	/**/
	
};

#endif // _S_WINDOW_IMPLEMENTATION_RENDER_OPEN_GL_H_