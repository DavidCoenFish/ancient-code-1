//file: Vanity/VComponentVisual/VComponentVisualAssetSimple.h
#ifndef _V_COMPONENT_VISUAL_ASSET_SIMPLE_H_
#define _V_COMPONENT_VISUAL_ASSET_SIMPLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAsset/VAsset.h"

#include< Sloth/SMaterial/SMaterial_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Sloth
{
	class SInterfaceRender;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;
	class VSceneApplicationInterface;
	class VComponentVisualComponentRenderResource;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentVisualAssetSimple : public VAsset
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentVisualAssetSimple, VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* TObjectHandle;
		typedef Hubris::HContainerArray< TObjectHandle >TArrayObjectHandle;
		typedef Hubris::HSmartPointer< VComponentVisualComponentRenderResource >TPointerRenderResource;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualAssetSimple(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HFileSystemPath& in_path			
			);
		virtual ~VComponentVisualAssetSimple();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualAssetSimple( const VAsset& in_src );
		const VComponentVisualAssetSimple& operator=( const VAsset& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID CreateAsset(
			const Hubris::HFileSystemPath& in_path,
			const Pride::PGeometry& in_geometry,
			const Sloth::SMaterial& in_material,
			const Hubris::HSINT in_renderLayer
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Render(
			Sloth::SInterfaceRender& in_renderer,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HSINT in_renderIndex,
			const Hubris::HREAL in_alphaOverride
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PGeometry& GeometryGet()const{ return m_geometry; }
		Pride::PGeometry& GeometryGet(){ return m_geometry; }

		const Sloth::SMaterial& MaterialGet()const{ return m_material; }
		Sloth::SMaterial& MaterialGet(){ return m_material; }

		const Hubris::HSINT RenderLayerGet()const{ return m_renderLayer; }
		Hubris::HVOID RenderLayerGet( const Hubris::HSINT in_renderLayer ){ m_renderLayer = in_renderLayer; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PGeometry m_geometry;
		Sloth::SMaterial m_material;
		Hubris::HSINT m_renderLayer;

		TPointerRenderResource m_pRenderResource;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_SIMPLE_H_