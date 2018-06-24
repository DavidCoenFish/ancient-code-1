//file: Sloth/SOpenGl/SOpenGl.h
#ifndef _S_OPEN_GL_H_
#define _S_OPEN_GL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Pride/PColour/PColour_Export.h >
#include< Pride/PBounds/PBounds_Export.h >
#include< Pride/PGeometry/PGeometry_Export.h >
#include< Pride/PSphere/PSphere_Export.h >
#include< Pride/PTriangle/PTriangle_Export.h >
#include "Sloth/SMaterial/SMaterialStage.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SOpenGlInfo;
	class SOpenGlShaderManager;
	class SLight;
	class SMaterialGeometryStage;
	class SMaterialStage;
	class SMaterialStageShader;

	///////////////////////////////////////////////////////
	// class
	/*
		change to class and hold the ARB function pointers for vertex buffer objects here?
		or at least opengl data
	*/
	class SOpenGl
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< SLight >TArrayLight;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HVOID* const TObjectHandle;
		typedef Hubris::HContainerArray< Pride::PTriangle >TArrayTriangle;

		///////////////////////////////////////////////////////
		// creation
	public:
		SOpenGl();
		~SOpenGl();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SOpenGl( const SOpenGl& in_src );
		const SOpenGl& operator=( const SOpenGl& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID ErrorCheck();

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID RestoreDefaults();

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
		Hubris::HVOID SOpenGl::ModelTransformSet(
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
			const TArrayReal& in_arrayVector
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
		Hubris::HVOID LightingActiveSet(
			const Hubris::HBOOL in_active
			);
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

		Hubris::HVOID DepthTestActiveSet(
			const Hubris::HBOOL in_active
			);

		const Hubris::HSINT TextureSizeMaxGet();
		Hubris::HVOID TextureActiveSet(
			const Hubris::HBOOL in_active
			);
		Hubris::HVOID TextureSet(
			const Hubris::HSINT in_mipMapLevel,
			const Pride::PImageRgba& in_image
			);
		Hubris::HVOID TextureTransformSet(
			const Hubris::HMatrixR4& in_transform
			);

		/*
			these could be static, but would prefer the function pointers to be private members, even if they are not yet
			since they are assigned on class creation
		*/
		Hubris::HVOID GlBindBufferARB( const Hubris::HSINT in_target, const Hubris::HSINT in_bufferId );
		Hubris::HVOID GlDeleteBuffersARB( const Hubris::HSINT in_size, const Hubris::HSINT* in_pBufferId );
		Hubris::HVOID GlGenBuffersARB( const Hubris::HSINT in_target, Hubris::HSINT* const out_pBufferId );
		const Hubris::HBOOL GlIsBufferARB( const Hubris::HSINT in_bufferId );
		Hubris::HVOID GlBufferDataARB( const Hubris::HSINT in_target, const Hubris::HSINT in_size, const Hubris::HVOID* const in_pData, const Hubris::HSINT in_usage );
		Hubris::HVOID GlBufferSubDataARB( const Hubris::HSINT in_target, const Hubris::HSINT in_offset, const Hubris::HSINT in_size, const Hubris::HVOID* const in_pData );
		Hubris::HVOID GlGetBufferParameterivARB( const Hubris::HSINT in_target, const Hubris::HSINT in_pname, Hubris::HSINT* out_pParams );
		Hubris::HVOID GlMapBufferARB( const Hubris::HSINT in_target,  const Hubris::HSINT in_access);
		Hubris::HVOID GlUnmapBufferARB( const Hubris::HSINT in_target );

		//Hubris::HVOID GlDrawRangeElements( const Hubris::HSINT in_mode, const Hubris::HSINT in_start, const Hubris::HSINT in_end, const Hubris::HSINT in_size, const Hubris::HSINT in_type, const Hubris::HVOID* const in_pData );

		const Hubris::HU32 GlCreateShaderObjectARB( const Hubris::HSINT in_target );
		Hubris::HVOID GlShaderSourceARB( const Hubris::HU32 in_handle, const Hubris::HSINT in_count, const Hubris::HCHAR** in_arrayString, const Hubris::HSINT* length );
		Hubris::HVOID GlCompileShaderARB( const Hubris::HU32 in_handle );
		const Hubris::HU32 GlCreateProgramObjectARB();
		Hubris::HVOID GlAttachObjectARB( const Hubris::HU32 in_program, const Hubris::HU32 in_shader );
		Hubris::HVOID GlLinkProgramARB( const Hubris::HU32 in_program );
		Hubris::HVOID GlUseProgramObjectARB( const Hubris::HU32 in_program );
		Hubris::HVOID GlDeleteShaderARB( const Hubris::HU32 in_handle );
		Hubris::HVOID GlDeleteProgramARB( const Hubris::HU32 in_program );

		const Hubris::HString GlGetInfoLogARB( const Hubris::HU32 in_handle );
		Hubris::HVOID GlGetObjectParameterivARB( const Hubris::HU32 in_handle, const Hubris::HSINT in_pname, Hubris::HSINT& out_value );

		const Hubris::HSINT GlGetUniformLocationARB( const Hubris::HU32 in_programHandle, const Hubris::HString& in_name );
		Hubris::HVOID GlUniform1iARB( const Hubris::HSINT in_location, const Hubris::HSINT in_value );

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID MaterialSet(
			const SMaterialStage& in_materialStage,
			const Hubris::HREAL in_alphaOverride,
			const Hubris::HBOOL in_forceChange
			);

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SOpenGlInfo& OpenGlInfoGet()const;
		SOpenGlInfo& OpenGlInfoGet();

		const SOpenGlShaderManager& OpenGlShaderManagerGet()const;
		SOpenGlShaderManager& OpenGlShaderManagerGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SOpenGlInfo* m_pInfo;
		SOpenGlShaderManager* m_pShaderManager;
		Hubris::HSINT m_textureId;

		//preserve the state of the current material stage
		SMaterialStage m_currentMaterialState;

		//function pointers to extention methods
		Hubris::HVOID* m_pglGenBuffersARB;
		Hubris::HVOID* m_pglIsBufferARB;
		Hubris::HVOID* m_pglBindBufferARB;
		Hubris::HVOID* m_pglBufferDataARB;
		Hubris::HVOID* m_pglBufferSubDataARB;
		Hubris::HVOID* m_pglDeleteBuffersARB;
		Hubris::HVOID* m_pglGetBufferParameterivARB;
		Hubris::HVOID* m_pglMapBufferARB;
		Hubris::HVOID* m_pglUnmapBufferARB;

		Hubris::HVOID* m_pglDrawRangeElements;

		Hubris::HVOID* m_pglCreateShaderObjectARB;
		Hubris::HVOID* m_pglShaderSourceARB;
		Hubris::HVOID* m_pglCompileShaderARB;
		Hubris::HVOID* m_pglCreateProgramObjectARB;
		Hubris::HVOID* m_pglAttachObjectARB;
		Hubris::HVOID* m_pglLinkProgramARB;
		Hubris::HVOID* m_pglUseProgramObjectARB;
		Hubris::HVOID* m_pglGetInfoLogARB;
		Hubris::HVOID* m_pglGetObjectParameterivARB;
		Hubris::HVOID* m_pglDeleteShader;
		Hubris::HVOID* m_pglDeleteProgram;

		Hubris::HVOID* m_pglGetUniformLocationARB;
		Hubris::HVOID* m_pglUniform1iARB;
		Hubris::HVOID* m_pglUniformfvARB;

	};

	/**/
	
};

#endif // _S_OPEN_GL_H_