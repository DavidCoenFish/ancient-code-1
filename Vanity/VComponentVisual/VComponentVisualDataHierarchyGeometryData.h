//file: Vanity/VComponentVisual/VComponentVisualDataHierarchyGeometryData.h
#ifndef _V_COMPONENT_VISUAL_DATA_HIERARCHY_GEOMETRY_DATA_H_
#define _V_COMPONENT_VISUAL_DATA_HIERARCHY_GEOMETRY_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentVisual/VComponentVisualComponentRenderResource.h"

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Vanity
{
	class VComponentVisualDataHierarchyMatrixCache;
	class VComponentVisualAssetHierarchyBoneData;
	class VScene;
};
namespace Sloth
{
	class SComponentDelta;
	class SInterfaceRender;
};

///////////////////////////////////////////////////////
// class
/*  
	the instance data for visual hierarchy asset
	hold data to perform dynamic operations on data, like skinning and bounce
*/
namespace Vanity
{
	class VComponentVisualDataHierarchyGeometryData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;
		typedef Hubris::HVOID* const TObjectHandle;
		typedef Hubris::HSmartPointer< VComponentVisualComponentRenderResource >TPointerRenderResource;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualDataHierarchyGeometryData( const VComponentVisualDataHierarchyGeometryData& in_src );
		VComponentVisualDataHierarchyGeometryData(
			const Pride::PGeometryTypeSignature& in_typeSignature,
			const Hubris::HSINT m_geometryIndex,
			const Hubris::HSINT m_geometryTopologyVertexIndex,
			const Hubris::HBOOL m_hasSkinning,
			const Hubris::HSINT m_geometrySkinningPositionArraySize,
			const Hubris::HSINT m_geometryDynamicIndexSkinningPosition,
			const Hubris::HSINT m_geometrySkinningNormalArraySize,
			const Hubris::HSINT m_geometryDynamicIndexSkinningNormal,
			const Hubris::HBOOL m_hasBounce,
			const Hubris::HSINT m_geometryBouncePositionArraySize,
			const Hubris::HSINT m_geometryDynamicIndexBouncePosition
			);
		VComponentVisualDataHierarchyGeometryData();	
		~VComponentVisualDataHierarchyGeometryData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentVisualDataHierarchyGeometryData& operator=( const VComponentVisualDataHierarchyGeometryData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentVisualDataHierarchyGeometryData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentVisualDataHierarchyGeometryData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//return HFALSE if no dymanic data
		Hubris::HBOOL Initialise(
			const Pride::PGeometry& in_geometry
			);

		Hubris::HVOID Update(
			TPointerRenderResource& in_out_pRenderResource,
			const Pride::PGeometry& in_geometry,
			const Sloth::SComponentDelta& in_delta,
			VComponentVisualDataHierarchyMatrixCache& in_matrixCache,
			const TArrayMatrix& in_arrayMatrixAnimated,
			const TArrayBoneData& in_arrayBoneData,
			const TArrayMatrix& in_arrayMatrixInvertSkinning
			);

		///////////////////////////////////////////////////////
		// private methods
	private:
		//update skin for vertex, normal data with new bone positions, apply bounce
		Hubris::HVOID UpdateSkin(
			const Pride::PGeometry& in_geometry,
			const Sloth::SComponentDelta& in_delta,
			VComponentVisualDataHierarchyMatrixCache& in_matrixCache,
			const TArrayMatrix& in_arrayMatrixAnimated,
			const TArrayBoneData& in_arrayBoneData,
			const TArrayMatrix& in_arrayMatrixInvertSkinning
			);

		//update the render object data 
		Hubris::HVOID UpdateRenderData(
			TPointerRenderResource& in_out_pRenderResource
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT GeometryIndexGet()const{ return m_geometryIndex; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PGeometryTypeSignature m_typeSignature;
		//Hubris::HSINT m_frameId; //what frame we have

		Hubris::HSINT m_geometryIndex; //asset index?
		Hubris::HSINT m_geometryTopologyVertexIndex;

		Hubris::HBOOL m_hasSkinning;
		TArrayReal m_geometrySkinningPosition;
		Hubris::HSINT m_geometryDynamicIndexSkinningPosition;
		TArrayReal m_geometrySkinningNormal;
		Hubris::HSINT m_geometryDynamicIndexSkinningNormal;

		Hubris::HBOOL m_hasBounce;
		TArrayReal m_geometryBouncePosition;
		Hubris::HSINT m_geometryDynamicIndexBouncePosition;
		TArrayVector m_geometryBounceVelocity;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_DATA_HIERARCHY_GEOMETRY_DATA_H_