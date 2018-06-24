//file: Vanity/VComponentVisual/VComponentVisualAsset.h
#ifndef _V_COMPONENT_VISUAL_ASSET_H_
#define _V_COMPONENT_VISUAL_ASSET_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VAsset/VAsset_Export.h"
#include< Sloth/SMaterial/SMaterial_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentVisualAsset : public VAsset
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentVisualAsset, VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* TObjectHandle;
		typedef Hubris::HContainerArray< TObjectHandle >TArrayObjectHandle;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualAsset(
			VAssetManager& in_out_assetManager,
			const Hubris::HFileSystemPath& in_path			
			);
		virtual ~VComponentVisualAsset();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualAsset( const VAsset& in_src );
		const VComponentVisualAsset& operator=( const VAsset& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID CreateAsset(
			const Hubris::HFileSystemPath& in_path,
			const Pride::PGeometry& in_geometry,
			const Sloth::SMaterial& in_material
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PGeometry& GeometryGet()const{ return m_geometry; }
		Pride::PGeometry& GeometryGet(){ return m_geometry; }

		const Sloth::SMaterial& MaterialGet()const{ return m_material; }
		Sloth::SMaterial& MaterialGet(){ return m_material; }

		const TObjectHandle ObjectHandleGet( const Hubris::HSINT in_renderIndex );
		Hubris::HVOID ObjectHandleSet( const Hubris::HSINT in_renderIndex, const TObjectHandle in_objectHandle );

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PGeometry m_geometry;
		Sloth::SMaterial m_material;
		TArrayObjectHandle m_arrayRenderHandle;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_H_