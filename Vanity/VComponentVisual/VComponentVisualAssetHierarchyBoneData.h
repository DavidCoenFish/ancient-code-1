//file: Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneData.h
#ifndef _V_COMPONENT_VISUAL_ASSET_HIERARCHY_BONE_DATA_H_
#define _V_COMPONENT_VISUAL_ASSET_HIERARCHY_BONE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentVisualAssetHierarchyBoneData
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualAssetHierarchyBoneData( const VComponentVisualAssetHierarchyBoneData& in_src );
		VComponentVisualAssetHierarchyBoneData(
			const Hubris::HSINT in_parentBoneIndex,
			const Hubris::HMatrixR4& in_relativeToParentMatrix
			);
		VComponentVisualAssetHierarchyBoneData();
		~VComponentVisualAssetHierarchyBoneData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentVisualAssetHierarchyBoneData& operator=( const VComponentVisualAssetHierarchyBoneData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentVisualAssetHierarchyBoneData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentVisualAssetHierarchyBoneData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT ParentBoneIndexGet()const{ return m_parentBoneIndex; }
		Hubris::HVOID ParentBoneIndexSet( const Hubris::HSINT in_parentBoneIndex ){ m_parentBoneIndex = in_parentBoneIndex; return; }

		const Hubris::HMatrixR4& RelativeToParentMatrixGet()const{ return m_relativeToParentMatrix; }
		Hubris::HMatrixR4& RelativeToParentMatrixGet(){ return m_relativeToParentMatrix; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_parentBoneIndex; //HCOMMON_INVALID for any root bones
		Hubris::HMatrixR4 m_relativeToParentMatrix;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_HIERARCHY_H_