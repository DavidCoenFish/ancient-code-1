//file: Vanity/VComponentVisual/VComponentVisualAssetHierarchyGeometryData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyGeometryData.h"

#include< Sloth/Sloth_Export.h >

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
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualAssetHierarchyGeometryData::VComponentVisualAssetHierarchyGeometryData( const VComponentVisualAssetHierarchyGeometryData& in_src )
: m_parentBoneIndex( HCOMMON_INVALID_INDEX )
, m_geometry()
, m_material()
//, m_useOffsetMatrix( HFALSE )
//, m_offsetMatrix()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentVisualAssetHierarchyGeometryData::VComponentVisualAssetHierarchyGeometryData(
	const Hubris::HSINT in_parentBoneIndex,
	const Pride::PGeometry& in_geometry,
	const Sloth::SMaterial& in_material
	)
: m_parentBoneIndex( in_parentBoneIndex )
, m_geometry( in_geometry )
, m_material( in_material )
//, m_useOffsetMatrix( HFALSE )
//, m_offsetMatrix()
{
	return;
}

/**
VComponentVisualAssetHierarchyGeometryData::VComponentVisualAssetHierarchyGeometryData(
	const Hubris::HSINT in_parentBoneIndex,
	const Hubris::HMatrixR4& in_offsetMatrix,
	const Pride::PGeometry& in_geometry,
	const Sloth::SMaterial& in_material
	)
: m_parentBoneIndex( in_parentBoneIndex )
, m_geometry( in_geometry )
, m_material( in_material )
, m_useOffsetMatrix( HTRUE )
, m_offsetMatrix( in_offsetMatrix )
{
	return;
}

/**/
VComponentVisualAssetHierarchyGeometryData::VComponentVisualAssetHierarchyGeometryData()
: m_parentBoneIndex( HCOMMON_INVALID_INDEX )
, m_geometry()
, m_material()
{
	return;
}

/**/
VComponentVisualAssetHierarchyGeometryData::~VComponentVisualAssetHierarchyGeometryData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentVisualAssetHierarchyGeometryData& VComponentVisualAssetHierarchyGeometryData::operator=( const VComponentVisualAssetHierarchyGeometryData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_parentBoneIndex = in_rhs.m_parentBoneIndex;
		m_geometry = in_rhs.m_geometry;
		m_material = in_rhs.m_material;
		//m_useOffsetMatrix = in_rhs.m_useOffsetMatrix;
		//m_offsetMatrix = in_rhs.m_offsetMatrix;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentVisualAssetHierarchyGeometryData::operator==( const VComponentVisualAssetHierarchyGeometryData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_parentBoneIndex == in_rhs.m_parentBoneIndex );
		match &= ( m_geometry == in_rhs.m_geometry );
		match &= ( m_material == in_rhs.m_material );
		//match &= ( m_useOffsetMatrix == in_rhs.m_useOffsetMatrix );
		//match &= ( m_offsetMatrix == in_rhs.m_offsetMatrix );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentVisualAssetHierarchyGeometryData::operator!=( const VComponentVisualAssetHierarchyGeometryData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentVisualAssetHierarchyGeometryData::ArrayDynamicIndexGet(
	TArraySint& in_out_arrayDynamicIndex
	)const
{
	in_out_arrayDynamicIndex.Clear();
	const PGeometryTypeSignature typeSignature = m_geometry.TypeSignatureGet();

	for( HSINT index = 0; index < typeSignature.TopologyStreamCountGet(); ++index )
	{
		const HSINT type = typeSignature.TopologyStreamTypeGet( index );
		if( PGeometryTypeSignature::TypeGetTopologyVertexIndex() != type )
		{
			continue;
		}

		HSINT positionDataStreamIndex = HCOMMON_INVALID_INDEX;
		HSINT normalDataStreamIndex = HCOMMON_INVALID_INDEX;
		PGeometryUtility::SkinningDataStreamIndexGet(
			positionDataStreamIndex,
			normalDataStreamIndex,
			typeSignature,
			index
			);
		PGeometryUtility::SpringDataStreamIndexGet(
			positionDataStreamIndex,
			typeSignature,
			index
			);

		if( HCOMMON_INVALID_INDEX != positionDataStreamIndex )
		{
			HContainerUtility::UniqueAdd( in_out_arrayDynamicIndex, positionDataStreamIndex );
		}
		if( HCOMMON_INVALID_INDEX != normalDataStreamIndex )
		{
			HContainerUtility::UniqueAdd( in_out_arrayDynamicIndex, normalDataStreamIndex );
		}
	}

	return;
}

/**/

