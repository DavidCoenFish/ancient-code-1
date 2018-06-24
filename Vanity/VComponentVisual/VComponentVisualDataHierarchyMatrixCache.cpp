//file: Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneSkinData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualDataHierarchyMatrixCache.h"

#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualDataHierarchyMatrixCache::VComponentVisualDataHierarchyMatrixCache(
	const HSINT in_boneCount
	)
: m_boneCount( in_boneCount )
, m_arrayValidAnimated()
, m_arrayValidSkinning()
, m_arrayBoneMatrixAnimated()
, m_arrayBoneMatrixSkinning()
{
	m_arrayValidAnimated.SizeSet( m_boneCount );
	m_arrayValidSkinning.SizeSet( m_boneCount );
	m_arrayBoneMatrixAnimated.SizeSet( m_boneCount );
	m_arrayBoneMatrixSkinning.SizeSet( m_boneCount );

	return;
}

/**/
VComponentVisualDataHierarchyMatrixCache::~VComponentVisualDataHierarchyMatrixCache()
{
	return;
}

///////////////////////////////////////////////////////
// public methods/**/
Hubris::HVOID VComponentVisualDataHierarchyMatrixCache::OnNewFrame()
{
	for( HSINT index = 0; index < m_boneCount; ++index )
	{
		m_arrayValidAnimated[ index ] = HFALSE;
		m_arrayValidSkinning[ index ] = HFALSE;
	}
	return;
}

/**/
const Hubris::HMatrixR4& VComponentVisualDataHierarchyMatrixCache::GetBoneMatrixAnimated( 
	const Hubris::HSINT in_boneIndex,
	const TArrayMatrix& in_arrayMatrixAnimated,
	const TArrayBoneData& in_arrayBoneData
	)
{
	if( HFALSE == m_arrayValidAnimated[ in_boneIndex ] )
	{
		m_arrayValidAnimated[ in_boneIndex ] = HTRUE;

		const VComponentVisualAssetHierarchyBoneData& boneData = in_arrayBoneData[ in_boneIndex ];
		const HSINT parentIndex = boneData.ParentBoneIndexGet();
		HMatrixR4& targetMatrix = m_arrayBoneMatrixAnimated[ in_boneIndex ];
		if( HCOMMON_INVALID_INDEX != parentIndex )
		{
			targetMatrix = GetBoneMatrixAnimated( 
				parentIndex,   
				in_arrayMatrixAnimated,
				in_arrayBoneData );

			targetMatrix *= boneData.RelativeToParentMatrixGet();
			targetMatrix *= in_arrayMatrixAnimated[ in_boneIndex ];
		}
		else
		{
			targetMatrix = boneData.RelativeToParentMatrixGet() * in_arrayMatrixAnimated[ in_boneIndex ];
		}
	}

	return m_arrayBoneMatrixAnimated[ in_boneIndex ];
}

/**/
const Hubris::HMatrixR4& VComponentVisualDataHierarchyMatrixCache::GetBoneMatrixSkinning( 
	const Hubris::HSINT in_boneIndex,
	const TArrayMatrix& in_arrayMatrixAnimated,
	const TArrayBoneData& in_arrayBoneData,
	const TArrayMatrix& in_arrayMatrixInvertSkinning
	)
{
	if( HFALSE == m_arrayValidSkinning[ in_boneIndex ] )
	{
		m_arrayValidSkinning[ in_boneIndex ] = HTRUE;
		m_arrayBoneMatrixSkinning[ in_boneIndex ] = in_arrayMatrixInvertSkinning[ in_boneIndex ] * GetBoneMatrixAnimated( in_boneIndex, in_arrayMatrixAnimated, in_arrayBoneData );
	}

	return m_arrayBoneMatrixAnimated[ in_boneIndex ];
}

///////////////////////////////////////////////////////
// public accessors
/**/
const TArrayMatrix& VComponentVisualDataHierarchyMatrixCache::ArrayBoneMatrixAnimatedGet(
	const TArrayMatrix& in_arrayMatrixAnimated,
	const TArrayBoneData& in_arrayBoneData			
	)
{
	for( HSINT index = 0; index < m_boneCount; ++index )
	{
		GetBoneMatrixAnimated(
			index,
			in_arrayMatrixAnimated,
			in_arrayBoneData
			);
	}

	return m_arrayBoneMatrixAnimated;
}

/**/
const TArrayMatrix& VComponentVisualDataHierarchyMatrixCache::ArrayBoneMatrixSkinningGet(
	const TArrayMatrix& in_arrayMatrixAnimated,
	const TArrayBoneData& in_arrayBoneData,
	const TArrayMatrix& in_arrayMatrixInvertSkinning			
	)
{
	for( HSINT index = 0; index < m_boneCount; ++index )
	{
		GetBoneMatrixSkinning(
			index,
			in_arrayMatrixAnimated,
			in_arrayBoneData,
			in_arrayMatrixInvertSkinning
			);
	}

	return m_arrayBoneMatrixAnimated;
}
/**/