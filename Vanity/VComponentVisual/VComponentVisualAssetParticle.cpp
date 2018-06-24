//file: Vanity/VComponentVisual/VComponentVisualAssetParticle.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualAssetParticle.h"

#include "Vanity/VComponentVisual/VComponentVisualTrait.h"
#include "Vanity/VScene/VScene_Export.h"

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
VComponentVisualAssetParticle::VComponentVisualAssetParticle(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HFileSystemPath& in_path			
	)
: m_materialStage()
, m_arrayTypeData()
, m_maxCount( 0 )
, m_textureIndex( HCOMMON_INVALID_INDEX )
, m_renderLayer( 0 )
{
	EMemento memento;

	EMementoUtility::Load(
		in_sceneApplicationInterface.FileSystemGet(),
		in_path,
		memento
		);

	EMementoAssign mementoAssign( memento );

	mementoAssign.MemberGet( "m_materialStage", m_materialStage );
	mementoAssign.MemberGet( "m_arrayTypeData", m_arrayTypeData );
	mementoAssign.MemberGet( "m_maxCount", m_maxCount );
	mementoAssign.MemberGet( "m_renderLayer", m_renderLayer );

	PImageRgba image;
	if( HTRUE == PImageTga::TgaLoadGeneric( 
			in_sceneApplicationInterface.FileSystemGet(),
			m_materialStage.TexturePathGet(),
			image ) )
	{
		const HSINT imageId = in_sceneApplicationInterface.TextureAliasGet().TextureAdd( image );
		m_materialStage.TextureIdSet( imageId );
	}

	return;
}

/**/
VComponentVisualAssetParticle::~VComponentVisualAssetParticle()
{
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentVisualAssetParticle::CreateAsset(
	const Hubris::HFileSystemPath& in_path,
	const Sloth::SMaterialStage& in_materialStage,
	const TArrayTypeData& in_arrayTypeData,
	const Hubris::HSINT in_maxCount,
	const Hubris::HSINT in_renderLayer
	)
{
	HFileSystem fileSystem;
	EMemento memento;

	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "m_materialStage", in_materialStage );
	mementoCollect.MemberAdd( "m_arrayTypeData", in_arrayTypeData );
	mementoCollect.MemberAdd( "m_maxCount", in_maxCount );
	mementoCollect.MemberAdd( "m_renderLayer", in_renderLayer );

	EMementoUtility::SaveText(
		fileSystem,
		in_path,
		memento
		);

	return;
}

/**/
