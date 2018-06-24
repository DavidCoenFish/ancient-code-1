//file: Vanity/VComponentVisual/VComponentVisualComponentRenderResource.h
#ifndef _V_COMPONENT_VISUAL_COMPONENT_RENDER_RESOURCE_H_
#define _V_COMPONENT_VISUAL_COMPONENT_RENDER_RESOURCE_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Sloth
{
	class SInterfaceRender;
	class SLight;
	class SMaterial;
	class SMaterialStage;
	class SMaterialGeometryStage;
};
namespace Vanity
{
	class VAssetManager;
	class VSceneApplicationInterface;
	class VScene;
};


///////////////////////////////////////////////////////
// class
/*
	a smart pointer to hold the render resources for a static or dynamic geometry
*/
namespace Vanity
{

	class VComponentVisualComponentRenderResource : public Hubris::HSmartPointerObjectBase< VComponentVisualComponentRenderResource >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* TObjectHandle;
		typedef Hubris::HContainerArray< TObjectHandle >TArrayObjectHandle;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualComponentRenderResource(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Pride::PGeometry& in_geometry,
			const TArraySint& in_arrayDynamicDataIndex
			);
		~VComponentVisualComponentRenderResource();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualComponentRenderResource( const VComponentVisualComponentRenderResource& in_src );
		const VComponentVisualComponentRenderResource& operator=( const VComponentVisualComponentRenderResource& in_rhs );

		///////////////////////////////////////////////////////
		// public members
	public:
		Hubris::HVOID UpdateTopology(
			const Hubris::HSINT in_topologyIndex,
			const Hubris::HSINT in_offset,
			const Hubris::HSINT in_count
			);

		Hubris::HVOID UpdateData(
			const Hubris::HSINT in_dataIndex,
			const Hubris::HVOID* const in_pData,
			const Hubris::HSINT in_offset,
			const Hubris::HSINT in_size
			);

		Hubris::HVOID Render(
			Sloth::SInterfaceRender& in_renderer,
			const Hubris::HSINT in_renderIndex,
			const Hubris::HREAL in_alphaOverride,
			const Sloth::SMaterial& in_material
			);

		Hubris::HVOID RenderStage(
			Sloth::SInterfaceRender& in_renderer,
			const Hubris::HSINT in_renderIndex,
			const Hubris::HREAL in_alphaOverride,
			const Sloth::SMaterialStage& in_materialStage,
			const Sloth::SMaterialGeometryStage& in_geometryStage
			);

		///////////////////////////////////////////////////////
		// private accessor
	private:
		const TObjectHandle ObjectHandleGet( const Hubris::HSINT in_renderIndex )const;

		///////////////////////////////////////////////////////
		// private members
	private:
		VSceneApplicationInterface& m_sceneApplicationInterface;
		TArrayObjectHandle m_arrayObjectHandle;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ITEM_DATA_BASE_H_