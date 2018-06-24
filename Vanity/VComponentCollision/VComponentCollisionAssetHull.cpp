//file: Vanity/VComponentCollision/VComponentCollisionAssetHull.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionAssetHull.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Envy/EMemento/EMemento_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Envy;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionAssetHull::VComponentCollisionAssetHull(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HFileSystemPath& in_path									
	)
: m_convexHull()
{
	EMemento memento;

	EMementoUtility::Load(
		in_sceneApplicationInterface.FileSystemGet(),
		in_path,
		memento
		);

	EMementoAssign mementoAssign( memento );
	mementoAssign.MemberGet( "m_convexHull", m_convexHull );

	return;
}

/**/
VComponentCollisionAssetHull::~VComponentCollisionAssetHull()
{
	return;
}

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID VComponentCollisionAssetHull::CreateAsset(
	const Hubris::HFileSystemPath& in_path,
	Pride::PConvexHull& in_convexHull
	)
{
	HFileSystem fileSystem;
	EMemento memento;

	VComponentCollisionHull hull( in_convexHull );

	EMementoCollect mementoCollect( memento );
	mementoCollect.MemberAdd( "m_convexHull", hull );

	EMementoUtility::SaveText(
		fileSystem,
		in_path,
		memento
		);

	return;
}

/**/