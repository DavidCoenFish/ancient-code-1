//file: Sloth/SInterface/SInterfaceRender.h
#ifndef _S_INTERFACE_RENDER_H_
#define _S_INTERFACE_RENDER_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;
	typedef PBounds< Hubris::HREAL, 1 >PBoundsR1; //instanciated in cpp
	typedef PBounds< Hubris::HREAL, 2 >PBoundsR2; //instanciated in cpp
	typedef PBounds< Hubris::HREAL, 3 >PBoundsR3; //instanciated in cpp

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2; //instanciated in cpp
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3; //instanciated in cpp

	class PGeometry;
	class PCamera;
	class PTriangle;

};

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SWindowImplementationRenderDirectX;
	class SWindowImplementationRenderOpenGl;
	class SMaterialGeometryStage;
	class SMaterialStage;
	class SMaterialStageShader;
	class SLight;

	///////////////////////////////////////////////////////
	// class
	/*
	don't want virtuals in render interface, so this is a wrapper, behaving like a interface
	*/
	class SInterfaceRender
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< SLight >TArrayLight;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		//typedef Hubris::HContainerArray< Pride::PTriangle >TArrayTriangle;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HVOID* const TObjectHandle;

		///////////////////////////////////////////////////////
		// creation
	public:
		SInterfaceRender(
			SWindowImplementationRenderDirectX& in_renderDirectX
			);
		SInterfaceRender(
			SWindowImplementationRenderOpenGl& in_renderOpenGl
			);
		Hubris::HVOID DeleteThis();
	private:
		~SInterfaceRender();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SInterfaceRender( const SInterfaceRender& in_src );
		const SInterfaceRender& operator=( const SInterfaceRender& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
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
			const TArrayReal& in_arrayTriangle //get a triangle for each three vectors (vector is 3 floats)
			);
		Hubris::HVOID DrawLine(
			const TArrayReal& in_arraySegment //get a segment for each two vectors (vector is 3 floats)
			);

		Hubris::HVOID DrawGeometry(
			const TObjectHandle in_geometryIndex,
			const SMaterialGeometryStage& in_renderStage
			);
		const TObjectHandle GeometryCreate(
			const Pride::PGeometry& in_geometry,
			const TArraySint& in_arrayDynamicIndex //empty for static geometry
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

		//material is used to set render state, use light, colour, ztest
		Hubris::HVOID MaterialSet(
			const SMaterialStage& in_materialStage,
			const Hubris::HREAL in_alphaOverride = 1.0F
			);
		Hubris::HVOID MaterialShaderRelease();

		const Hubris::HSINT TextureSizeMaxGet();
		Hubris::HVOID TextureSet(
			const Hubris::HSINT in_mipMapLevel,
			const Pride::PImageRgba& in_image
			);
		Hubris::HVOID TextureTransformSet(
			const Hubris::HMatrixR4& in_transform
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

		///////////////////////////////////////////////////////
		// public accessors
	public:
		//const Hubris::HSINT RenderIdGet()const{ return m_renderId; }
		//Hubris::HVOID RenderIdSet( const Hubris::HSINT in_renderId ){ m_renderId = in_renderId; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		SWindowImplementationRenderDirectX* m_pRenderDirectX;
		SWindowImplementationRenderOpenGl* m_pRenderOpenGl;
		//const Hubris::HSINT m_renderId;

	};

	/**/
	
};

#endif // _S_INTERFACE_RENDER_H_