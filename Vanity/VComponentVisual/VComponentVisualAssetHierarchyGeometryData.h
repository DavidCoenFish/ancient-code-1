//file: Vanity/VComponentVisual/VComponentVisualAssetHierarchyGeometryData.h
#ifndef _V_COMPONENT_VISUAL_ASSET_HIERARCHY_GEOMETRY_DATA_H_
#define _V_COMPONENT_VISUAL_ASSET_HIERARCHY_GEOMETRY_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

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
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentVisualAssetHierarchyGeometryData
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
		VComponentVisualAssetHierarchyGeometryData( const VComponentVisualAssetHierarchyGeometryData& in_src );
		VComponentVisualAssetHierarchyGeometryData(
			const Hubris::HSINT in_parentBoneIndex,
			const Pride::PGeometry& in_geometry,
			const Sloth::SMaterial& in_material
			);
		//VComponentVisualAssetHierarchyGeometryData(
		//	const Hubris::HSINT in_parentBoneIndex,
		//	const Hubris::HMatrixR4& in_offsetMatrix,
		//	const Pride::PGeometry& in_geometry,
		//	const Sloth::SMaterial& in_material
		//	);
		VComponentVisualAssetHierarchyGeometryData();
		~VComponentVisualAssetHierarchyGeometryData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentVisualAssetHierarchyGeometryData& operator=( const VComponentVisualAssetHierarchyGeometryData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentVisualAssetHierarchyGeometryData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentVisualAssetHierarchyGeometryData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID ArrayDynamicIndexGet(
			TArraySint& in_out_arrayDynamicIndex
			)const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT ParentBoneIndexGet()const{ return m_parentBoneIndex; }
		Hubris::HVOID ParentBoneIndexSet( const Hubris::HSINT in_parentBoneIndex ){ m_parentBoneIndex = in_parentBoneIndex; return; }

		const Pride::PGeometry& GeometryGet()const{ return m_geometry; }
		Pride::PGeometry& GeometryGet(){ return m_geometry; }

		const Sloth::SMaterial& MaterialGet()const{ return m_material; }
		Sloth::SMaterial& MaterialGet(){ return m_material; }

		//const Hubris::HBOOL UseOffsetMatrixGet()const{ return m_useOffsetMatrix; }
		//Hubris::HVOID UseOffsetMatrixSet( const Hubris::HBOOL in_useOffsetMatrix ){ m_useOffsetMatrix = in_useOffsetMatrix; return; }

		//const Hubris::HMatrixR4& OffsetMatrixGet()const{ return m_offsetMatrix; }
		//Hubris::HMatrixR4& OffsetMatrixGet(){ return m_offsetMatrix; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_parentBoneIndex;
		Pride::PGeometry m_geometry;
		Sloth::SMaterial m_material;
		//normally burn in the offset into the geometry, however this could be problamatic for skins, 
		//Hubris::HBOOL m_useOffsetMatrix;
		//Hubris::HMatrixR4 m_offsetMatrix;
	
	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_HIERARCHY_GEOMETRY_DATA_H_