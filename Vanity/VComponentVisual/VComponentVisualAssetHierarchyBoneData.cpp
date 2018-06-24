//file: Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualAssetHierarchyBoneData::VComponentVisualAssetHierarchyBoneData( const VComponentVisualAssetHierarchyBoneData& in_src )
: m_parentBoneIndex( HCOMMON_INVALID_INDEX )
, m_relativeToParentMatrix()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentVisualAssetHierarchyBoneData::VComponentVisualAssetHierarchyBoneData(
	const Hubris::HSINT in_parentBoneIndex,
	const Hubris::HMatrixR4& in_relativeToParentMatrix
	)
: m_parentBoneIndex( in_parentBoneIndex )
, m_relativeToParentMatrix( in_relativeToParentMatrix )
{
	return;
}

/**/
VComponentVisualAssetHierarchyBoneData::VComponentVisualAssetHierarchyBoneData()
: m_parentBoneIndex( HCOMMON_INVALID_INDEX )
, m_relativeToParentMatrix()
{
	return;
}

/**/
VComponentVisualAssetHierarchyBoneData::~VComponentVisualAssetHierarchyBoneData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentVisualAssetHierarchyBoneData& VComponentVisualAssetHierarchyBoneData::operator=( const VComponentVisualAssetHierarchyBoneData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_parentBoneIndex = in_rhs.m_parentBoneIndex;
		m_relativeToParentMatrix = in_rhs.m_relativeToParentMatrix;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentVisualAssetHierarchyBoneData::operator==( const VComponentVisualAssetHierarchyBoneData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_parentBoneIndex == in_rhs.m_parentBoneIndex );
		match &= ( m_relativeToParentMatrix == in_rhs.m_relativeToParentMatrix );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentVisualAssetHierarchyBoneData::operator!=( const VComponentVisualAssetHierarchyBoneData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/