//file: Vanity/VComponentVisual/VComponentVisualTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualTrait.h"

#include "Vanity/VComponentVisual/VComponentVisual.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneData.h"
//#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyBoneSkinData.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetHierarchyGeometryData.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetSimple.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticleTypeData.h"
#include "Vanity/VComponentVisual/VComponentVisualDataHierarchy.h"
#include "Vanity/VComponentVisual/VComponentVisualDataParticle.h"
#include "Vanity/VComponentVisual/VComponentVisualDataSimple.h"

#include< Envy/EMemento/EMemento_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Envy;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VComponentVisualDataBase* >TArrayBase;
typedef Hubris::HSmartPointer< VComponentVisualDataBase >TPointerData;
typedef Hubris::HContainerArray< TPointerData >TArrayPointerData;

/**/
HTYPE_NAME_IMPLEMENTATION( VComponentVisualDataParticle );
HTYPE_NAME_IMPLEMENTATION( VComponentVisualDataSimple );
HTYPE_NAME_IMPLEMENTATION( VComponentVisualDataHierarchy );

/**/
HVOID Envy::EMementoTraitCollect< VComponentVisual >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisual& in_data )
{
	TArrayBase arrayData;
	const HSINT count = in_data.m_arrayPointerData.SizeGet();
	arrayData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		arrayData[ index ] = ( VComponentVisualDataBase* )( in_data.m_arrayPointerData[ index ].RawGet() );
	}

	in_out_mementoCollect.OwnedPointerAdd( "itemData", arrayData );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentVisual >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisual& out_data )
{
	TArrayBase arrayData;
	in_out_mementoAssign.OwnedPointerGet( "itemData", arrayData );

	const HSINT count = arrayData.SizeGet();
	out_data.m_arrayPointerData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		out_data.m_arrayPointerData[ index ] = arrayData[ index ];
	}

	return;
}

/*
	VComponentVisualDataHierarchy
*/
Hubris::HVOID Envy::EMementoTraitCollect< VComponentVisualDataHierarchy >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualDataHierarchy& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_path", in_data.FilePathGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< VComponentVisualDataHierarchy >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualDataHierarchy& out_data )
{
	in_out_mementoAssign.MemberGet( "m_path", out_data.FilePathGet() );
	return;
}

/*
	VComponentVisualDataSimple
*/
HVOID Envy::EMementoTraitCollect< VComponentVisualDataSimple >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualDataSimple& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_path", in_data.FilePathGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentVisualDataSimple >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualDataSimple& out_data )
{
	HFileSystemPath fileSystemPath;
	in_out_mementoAssign.MemberGet( "m_path", fileSystemPath );
	out_data.FilePathSet( fileSystemPath );

	return;
}

/*
	VComponentVisualDataParticle
*/
HVOID Envy::EMementoTraitCollect< VComponentVisualDataParticle >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualDataParticle& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_path", in_data.FilePathGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentVisualDataParticle >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualDataParticle& out_data )
{
	HFileSystemPath fileSystemPath;
	in_out_mementoAssign.MemberGet( "m_path", fileSystemPath );
	out_data.FilePathSet( fileSystemPath );

	return;
}

/*
	VComponentVisualAssetParticleTypeData
*/
HVOID Envy::EMementoTraitCollect< VComponentVisualAssetParticleTypeData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetParticleTypeData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_uvTopLeft", in_data.UvTopLeftGet() );
	in_out_mementoCollect.MemberAdd( "m_uvTopRight", in_data.UvTopRightGet() );
	in_out_mementoCollect.MemberAdd( "m_uvBottomLeft", in_data.UvBottomLeftGet() );
	in_out_mementoCollect.MemberAdd( "m_uvBottomRight", in_data.UvBottomRightGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentVisualAssetParticleTypeData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetParticleTypeData& out_data )
{
	in_out_mementoAssign.MemberGet( "m_uvTopLeft", out_data.UvTopLeftGet() );
	in_out_mementoAssign.MemberGet( "m_uvTopRight", out_data.UvTopRightGet() );
	in_out_mementoAssign.MemberGet( "m_uvBottomLeft", out_data.UvBottomLeftGet() );
	in_out_mementoAssign.MemberGet( "m_uvBottomRight", out_data.UvBottomRightGet() );

	return;
}

/*
	VComponentVisualAssetHierarchyBoneData
*/
Hubris::HVOID Envy::EMementoTraitCollect< VComponentVisualAssetHierarchyBoneData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetHierarchyBoneData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_parentBoneIndex", in_data.ParentBoneIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_matrix", in_data.RelativeToParentMatrixGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< VComponentVisualAssetHierarchyBoneData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetHierarchyBoneData& out_data )
{
	HSINT parentBoneIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_parentBoneIndex", parentBoneIndex );
	out_data.ParentBoneIndexSet( parentBoneIndex );

	in_out_mementoAssign.MemberGet( "m_matrix", out_data.RelativeToParentMatrixGet() );

	return;
}

/*
	VComponentVisualAssetHierarchyBoneSkinData
*
Hubris::HVOID Envy::EMementoTraitCollect< VComponentVisualAssetHierarchyBoneSkinData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetHierarchyBoneSkinData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_boneIndex", in_data.BoneIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_boneSkinMatrix", in_data.InvertBoneSkinMatrixGet() );

	return;
}

/**
Hubris::HVOID Envy::EMementoTraitAssign< VComponentVisualAssetHierarchyBoneSkinData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetHierarchyBoneSkinData& out_data )
{
	HSINT boneIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_boneIndex", boneIndex );
	out_data.BoneIndexSet( boneIndex );

	in_out_mementoAssign.MemberGet( "m_boneSkinMatrix", out_data.InvertBoneSkinMatrixGet() );

	return;
}

/*
	VComponentVisualAssetHierarchyGeometryData
*/
Hubris::HVOID Envy::EMementoTraitCollect< VComponentVisualAssetHierarchyGeometryData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetHierarchyGeometryData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_parentBoneIndex", in_data.ParentBoneIndexGet() );
	in_out_mementoCollect.MemberAdd( "m_geometry", in_data.GeometryGet() );
	in_out_mementoCollect.MemberAdd( "m_material", in_data.MaterialGet() );

	//const HBOOL useOffset = in_data.UseOffsetMatrixGet();
	//in_out_mementoCollect.MemberAdd( "m_useOffset", useOffset );
	//if( HTRUE == useOffset )
	//{
	//	in_out_mementoCollect.MemberAdd( "m_offsetMatrix", in_data.OffsetMatrixGet() );
	//}

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< VComponentVisualAssetHierarchyGeometryData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetHierarchyGeometryData& out_data )
{
	HSINT parentBoneIndex = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_parentBoneIndex", parentBoneIndex );
	out_data.ParentBoneIndexSet( parentBoneIndex );

	in_out_mementoAssign.MemberGet( "m_geometry", out_data.GeometryGet() );
	in_out_mementoAssign.MemberGet( "m_material", out_data.MaterialGet() );

	//HBOOL useOffset = HFALSE;
	//in_out_mementoAssign.MemberGet( "m_useOffset", useOffset );
	//out_data.UseOffsetMatrixSet( useOffset );
	//if( HTRUE == useOffset )
	//{
	//	in_out_mementoAssign.MemberGet( "m_offsetMatrix", out_data.OffsetMatrixGet() );
	//}

	return;
}

///////////////////////////////////////////////////////////
// global functions
/**/
Hubris::HVOID Vanity::VComponentVisualTraitFactoryRegister()
{
	EMEMENTO_FACTORY_REGISTER( VComponentVisualDataHierarchy, VComponentVisualDataBase );
	EMEMENTO_FACTORY_REGISTER( VComponentVisualDataParticle, VComponentVisualDataBase );
	EMEMENTO_FACTORY_REGISTER( VComponentVisualDataSimple, VComponentVisualDataBase );
	return;
}

/**/