//file: Vanity/VComponentGame/VComponentGameDataAsset.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentGame/VComponentGameDataAsset.h"

#include "Vanity/VScene/VScene_Export.h"

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
VComponentGameDataAsset::VComponentGameDataAsset(
	VSceneApplicationInterface& in_out_sceneApplicationInterface,
	const Hubris::HFileSystemPath& in_path			
	)
: m_gameObjectTypeName()
, m_data()
{
	EMementoUtility::Load(
		in_out_sceneApplicationInterface.FileSystemGet(),
		in_path,
		m_data
		);

	EMementoAssign mementoAssign( m_data );
	mementoAssign.MemberGet( "vcgda_name", m_gameObjectTypeName );

	return;
}

/**/
VComponentGameDataAsset::~VComponentGameDataAsset()
{
	return;
}
///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentGameDataAsset::CreateAsset(
	const Hubris::HFileSystemPath& in_path,
	const Hubris::HString in_gameObjectTypeName,
	const Envy::EMemento& in_data
	)
{
	HFileSystem fileSystem;

	EMemento localData( in_data );
	EMementoCollect mementoCollect( localData );
	mementoCollect.MemberAdd( "vcgda_name", in_gameObjectTypeName );

	EMementoUtility::SaveText(
		fileSystem,
		in_path,
		localData
		);

	return;
}

/**/
