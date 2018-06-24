//file: Vanity/VAnimation/VAnimationAsset.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationAsset.h"

#include "Vanity/VAsset/VAsset_Export.h"
#include "Vanity/VScene/VScene_Export.h"

//#include< Envy/Envy_Export.h >
/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// creation
/**/
VAnimationAsset::VAnimationAsset(
	VSceneApplicationInterface& in_out_sceneApplicationInterface,
	const Hubris::HFileSystemPath& in_path					
	)
{
	EMemento memento;

	EMementoUtility::Load(
		in_out_sceneApplicationInterface.FileSystemGet(),
		in_path,
		memento
		);

	EMementoAssign mementoAssign( memento );
	mementoAssign.MemberGet( "m_arrayAnimation", m_arrayAnimation );

	return;
}

/**/
VAnimationAsset::~VAnimationAsset()
{
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VAnimationAsset::CreateAsset(
	const Hubris::HFileSystemPath& in_path,
	const TArrayAnimation& in_arrayAnimation
	)
{
	HFileSystem fileSystem;
	EMemento memento;

	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "m_arrayAnimation", in_arrayAnimation );

	EMementoUtility::SaveText(
		fileSystem,
		in_path,
		memento
		);

	return;
}

/**/
