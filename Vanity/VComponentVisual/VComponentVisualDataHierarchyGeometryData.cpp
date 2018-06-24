//file: Vanity/VComponentVisual/VComponentVisualDataHierarchyGeometryData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualDataHierarchyGeometryData.h"

#include "Vanity/VComponentVisual/VComponentVisualDataHierarchyMatrixCache.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/SComponent/SComponent_Export.h >
#include< Sloth/SInterface/SInterface_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualDataHierarchyGeometryData::VComponentVisualDataHierarchyGeometryData( const VComponentVisualDataHierarchyGeometryData& in_src )
: m_typeSignature()
, m_geometryIndex( HCOMMON_INVALID_INDEX )
, m_geometryTopologyVertexIndex( HCOMMON_INVALID_INDEX )
, m_hasSkinning( HFALSE )
, m_geometrySkinningPosition()
, m_geometryDynamicIndexSkinningPosition( HCOMMON_INVALID_INDEX )
, m_geometrySkinningNormal()
, m_geometryDynamicIndexSkinningNormal( HCOMMON_INVALID_INDEX )
, m_hasBounce( HFALSE )
, m_geometryBouncePosition()
, m_geometryDynamicIndexBouncePosition( HCOMMON_INVALID_INDEX )
, m_geometryBounceVelocity()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentVisualDataHierarchyGeometryData::VComponentVisualDataHierarchyGeometryData(
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
	)
: m_typeSignature( in_typeSignature )
, m_geometryIndex( m_geometryIndex )
, m_geometryTopologyVertexIndex( m_geometryTopologyVertexIndex )
, m_hasSkinning( m_hasSkinning )
, m_geometrySkinningPosition()
, m_geometryDynamicIndexSkinningPosition( m_geometryDynamicIndexSkinningPosition )
, m_geometrySkinningNormal()
, m_geometryDynamicIndexSkinningNormal( m_geometryDynamicIndexSkinningNormal )
, m_hasBounce( m_hasBounce )
, m_geometryBouncePosition()
, m_geometryDynamicIndexBouncePosition( m_geometryDynamicIndexBouncePosition )
, m_geometryBounceVelocity()
{
	m_geometrySkinningPosition.SizeSet( m_geometrySkinningPositionArraySize );
	m_geometrySkinningNormal.SizeSet( m_geometrySkinningNormalArraySize );
	m_geometryBouncePosition.SizeSet( m_geometryBouncePositionArraySize );
	return;
}

/**/
VComponentVisualDataHierarchyGeometryData::VComponentVisualDataHierarchyGeometryData()
: m_typeSignature()
, m_geometryIndex( HCOMMON_INVALID_INDEX )
, m_geometryTopologyVertexIndex( HCOMMON_INVALID_INDEX )
, m_hasSkinning( HFALSE )
, m_geometrySkinningPosition()
, m_geometryDynamicIndexSkinningPosition( HCOMMON_INVALID_INDEX )
, m_geometrySkinningNormal()
, m_geometryDynamicIndexSkinningNormal( HCOMMON_INVALID_INDEX )
, m_hasBounce( HFALSE )
, m_geometryBouncePosition()
, m_geometryDynamicIndexBouncePosition( HCOMMON_INVALID_INDEX )
, m_geometryBounceVelocity()
{
	return;
}

/**/
VComponentVisualDataHierarchyGeometryData::~VComponentVisualDataHierarchyGeometryData()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentVisualDataHierarchyGeometryData& VComponentVisualDataHierarchyGeometryData::operator=( const VComponentVisualDataHierarchyGeometryData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_typeSignature = in_rhs.m_typeSignature;
		m_geometryIndex = in_rhs.m_geometryIndex;
		m_geometryTopologyVertexIndex = in_rhs.m_geometryTopologyVertexIndex;
		m_hasSkinning = in_rhs.m_hasSkinning;
		m_geometrySkinningPosition = in_rhs.m_geometrySkinningPosition;
		m_geometryDynamicIndexSkinningPosition = in_rhs.m_geometryDynamicIndexSkinningPosition;
		m_geometrySkinningNormal = in_rhs.m_geometrySkinningNormal;
		m_geometryDynamicIndexSkinningNormal = in_rhs.m_geometryDynamicIndexSkinningNormal;
		m_hasBounce = in_rhs.m_hasBounce;
		m_geometryBouncePosition = in_rhs.m_geometryBouncePosition;
		m_geometryDynamicIndexBouncePosition = in_rhs.m_geometryDynamicIndexBouncePosition;
		m_geometryBounceVelocity = in_rhs.m_geometryBounceVelocity;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentVisualDataHierarchyGeometryData::operator==( const VComponentVisualDataHierarchyGeometryData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_typeSignature == in_rhs.m_typeSignature );
		match &= ( m_geometryIndex == in_rhs.m_geometryIndex );
		match &= ( m_geometryTopologyVertexIndex == in_rhs.m_geometryTopologyVertexIndex );
		match &= ( m_hasSkinning == in_rhs.m_hasSkinning );
		match &= ( m_geometrySkinningPosition == in_rhs.m_geometrySkinningPosition );
		match &= ( m_geometryDynamicIndexSkinningPosition == in_rhs.m_geometryDynamicIndexSkinningPosition );
		match &= ( m_geometrySkinningNormal == in_rhs.m_geometrySkinningNormal );
		match &= ( m_geometryDynamicIndexSkinningNormal == in_rhs.m_geometryDynamicIndexSkinningNormal );
		match &= ( m_hasBounce == in_rhs.m_hasBounce );
		match &= ( m_geometryBouncePosition == in_rhs.m_geometryBouncePosition );
		match &= ( m_geometryDynamicIndexBouncePosition == in_rhs.m_geometryDynamicIndexBouncePosition );
		match &= ( m_geometryBounceVelocity == in_rhs.m_geometryBounceVelocity );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentVisualDataHierarchyGeometryData::operator!=( const VComponentVisualDataHierarchyGeometryData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentVisualDataHierarchyGeometryData::Update(
	TPointerRenderResource& in_out_pRenderResource,
	const Pride::PGeometry& in_geometry,
	const Sloth::SComponentDelta& in_delta,
	VComponentVisualDataHierarchyMatrixCache& in_matrixCache,
	const TArrayMatrix& in_arrayMatrixAnimated,
	const TArrayBoneData& in_arrayBoneData,
	const TArrayMatrix& in_arrayMatrixInvertSkinning
	)
{
	UpdateSkin(
		in_geometry,
		in_delta,
		in_matrixCache,
		in_arrayMatrixAnimated,
		in_arrayBoneData,
		in_arrayMatrixInvertSkinning
		);

	UpdateRenderData(
		in_out_pRenderResource
		);

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID VComponentVisualDataHierarchyGeometryData::UpdateSkin(
	const Pride::PGeometry& in_geometry,
	const Sloth::SComponentDelta& in_delta,
	VComponentVisualDataHierarchyMatrixCache& in_matrixCache,
	const TArrayMatrix& in_arrayMatrixAnimated,
	const TArrayBoneData& in_arrayBoneData,
	const TArrayMatrix& in_arrayMatrixInvertSkinning
	)
{
	if( HTRUE == m_hasSkinning )
	{
		PGeometryUtility::PerformSkinning( 
			m_geometrySkinningPosition,
			m_geometrySkinningNormal,
			m_typeSignature, 
			in_geometry,
			m_geometryTopologyVertexIndex,
			in_matrixCache.ArrayBoneMatrixSkinningGet( in_arrayMatrixAnimated, in_arrayBoneData, in_arrayMatrixInvertSkinning )			
			);
	}

	if( HTRUE == m_hasBounce )
	{
		PGeometryUtility::PerformSpring( 
			m_geometryBouncePosition,
			m_geometryBounceVelocity,
			m_geometrySkinningPosition,
			m_typeSignature, 
			in_geometry,
			m_geometryTopologyVertexIndex,
			in_delta.LastDeltaGet()
			);
	}

	return;
}

/**/
Hubris::HVOID VComponentVisualDataHierarchyGeometryData::UpdateRenderData(
	TPointerRenderResource& in_out_pRenderResource
	)
{
	if( HNULL == in_out_pRenderResource )
	{
		return;
	}

	if( HTRUE == m_hasBounce )
	{
		in_out_pRenderResource->UpdateData(
			m_geometryDynamicIndexBouncePosition,
			m_geometryBouncePosition.RawGet(),
			0,
			sizeof( HREAL ) * m_geometryBouncePosition.SizeGet()
			);
	}
	else
	{
		in_out_pRenderResource->UpdateData(
			m_geometryDynamicIndexSkinningPosition,
			m_geometrySkinningPosition.RawGet(),
			0,
			sizeof( HREAL ) * m_geometrySkinningPosition.SizeGet()
			);
	}

	if( 0 != m_geometrySkinningNormal.SizeGet() )
	{
		in_out_pRenderResource->UpdateData(
			m_geometryDynamicIndexSkinningNormal,
			m_geometrySkinningNormal.RawGet(),
			0,
			sizeof( HREAL ) * m_geometrySkinningNormal.SizeGet()
			);
	}

	return;
}

/**/
