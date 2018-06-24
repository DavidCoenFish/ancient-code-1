//file: Vanity/VComponentVisual/VComponentVisualAsset.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAsset.h"

#include< Sloth/Sloth_Export.h >

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
VComponentVisualAsset::VComponentVisualAsset(
	VAssetManager& in_out_assetManager,
	const Hubris::HFileSystemPath& in_path			
	)
: m_geometry()
, m_material()
, m_arrayRenderHandle()
{
	EMemento memento;

	EMementoUtility::Load(
		in_out_assetManager.FileSystemGet(),
		in_path,
		memento
		);

	EMementoAssign mementoAssign( memento );
	mementoAssign.MemberGet( "m_geometry", m_geometry );
	mementoAssign.MemberGet( "m_material", m_material );

	const HSINT count = m_material.StageCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		PImageRgba image;
		if( HTRUE == PImageTga::TgaLoadGeneric( 
				in_out_assetManager.FileSystemGet(),
				m_material.StageMaterialGet( index ).TexturePathGet(),
				image ) )
		{
			const HSINT imageId = in_out_assetManager.TextureAliasGet().TextureAdd( image );
			m_material.StageMaterialGet( index ).TextureIdSet( imageId );
		}
	}

	return;
}

/**/
VComponentVisualAsset::~VComponentVisualAsset()
{
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentVisualAsset::CreateAsset(
	const Hubris::HFileSystemPath& in_path,
	const Pride::PGeometry& in_geometry,
	const Sloth::SMaterial& in_material
	)
{
	HFileSystem fileSystem;
	EMemento memento;

	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "m_geometry", in_geometry );
	mementoCollect.MemberAdd( "m_material", in_material );

	EMementoUtility::SaveText(
		fileSystem,
		in_path,
		memento
		);

	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const VComponentVisualAsset::TObjectHandle VComponentVisualAsset::ObjectHandleGet( const Hubris::HSINT in_renderIndex )
{
	if( ( 0 <= in_renderIndex ) &&
		( in_renderIndex < m_arrayRenderHandle.SizeGet() ) )
	{
		return m_arrayRenderHandle[ in_renderIndex ];
	}
	return HNULL;
}

/**/
Hubris::HVOID VComponentVisualAsset::ObjectHandleSet( const Hubris::HSINT in_renderIndex, const TObjectHandle in_objectHandle )
{
	if( in_renderIndex < 0 )
	{
		return;
	}

	if( m_arrayRenderHandle.SizeGet() <= in_renderIndex )
	{
		m_arrayRenderHandle.SizeResize( in_renderIndex + 1 );
	}

	m_arrayRenderHandle[ in_renderIndex ] = in_objectHandle;

	return;
}

/**/
