//file: Vanity/VComponentVisual/VComponentVisualDataHierarchyMatrixCache.h
#ifndef _V_COMPONENT_VISUAL_ASSET_HIERARCHY_MATRIX_CACHE_H_
#define _V_COMPONENT_VISUAL_ASSET_HIERARCHY_MATRIX_CACHE_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Vanity
{
	class VComponentVisualAssetHierarchyBoneData;
};

///////////////////////////////////////////////////////
// class
/*
	make a cache of matrixies used for the VComponentVisualDataHierarchy
	like the bone's animation matrix relative to the root
	and bone skinning matrix (invert pose * animation relative to root)

	note, ASSUMPTION that the array of bone data is monic (can only refere to earlier bones while traversing)
*/
namespace Vanity
{
	class VComponentVisualDataHierarchyMatrixCache
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
		typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentVisualDataHierarchyMatrixCache(
			const Hubris::HSINT in_boneCount
			);
		~VComponentVisualDataHierarchyMatrixCache();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentVisualDataHierarchyMatrixCache( const VComponentVisualDataHierarchyMatrixCache& in_src );
		const VComponentVisualDataHierarchyMatrixCache& operator=( const VComponentVisualDataHierarchyMatrixCache& in_rhs );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HVOID OnNewFrame();
		const Hubris::HMatrixR4& GetBoneMatrixAnimated( 
			const Hubris::HSINT in_boneIndex,
			const TArrayMatrix& in_arrayMatrixAnimated,
			const TArrayBoneData& in_arrayBoneData
			);
		const Hubris::HMatrixR4& GetBoneMatrixSkinning( 
			const Hubris::HSINT in_boneIndex,
			const TArrayMatrix& in_arrayMatrixAnimated,
			const TArrayBoneData& in_arrayBoneData,
			const TArrayMatrix& in_arrayMatrixInvertSkinning
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TArrayMatrix& ArrayBoneMatrixAnimatedGet(
			const TArrayMatrix& in_arrayMatrixAnimated,
			const TArrayBoneData& in_arrayBoneData			
			);
		const TArrayMatrix& ArrayBoneMatrixSkinningGet(
			const TArrayMatrix& in_arrayMatrixAnimated,
			const TArrayBoneData& in_arrayBoneData,
			const TArrayMatrix& in_arrayMatrixInvertSkinning			
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		//cache data per frame
		Hubris::HSINT m_boneCount;
		Hubris::HContainerArrayBit m_arrayValidAnimated;
		Hubris::HContainerArrayBit m_arrayValidSkinning;
		TArrayMatrix m_arrayBoneMatrixAnimated;
		TArrayMatrix m_arrayBoneMatrixSkinning;

	};

	/**/
	
};

#endif // _V_COMPONENT_VISUAL_ASSET_HIERARCHY_MATRIX_CACHE_H_