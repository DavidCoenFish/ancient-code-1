//file: Vanity/VAsset/VAssetManager.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAsset/VAssetManager.h"

#include "Sloth/Sloth_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef

///////////////////////////////////////////////////////
// creation
/**/
VAssetManager::VAssetManager()
: m_treePathPointerAsset()
{
	return;
}

/**/
VAssetManager::~VAssetManager()
{
	AssetReleaseUnused();

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VAssetManager::AssetReleaseUnused()
{
	//TTreePathPointerAsset localTreePathPointerAsset( m_treePathPointerAsset );
	//m_treePathPointerAsset.Clear();

	for( TTreePathPointerAsset::TIterator iterator = m_treePathPointerAsset.Begin(); iterator != m_treePathPointerAsset.End(); ++iterator )
	{
		if( ( HNULL == ( *iterator ) ) ||
			( ( *iterator )->RefereceCountGet().ReferenceCountGet() <= 1 ) )
		{
			iterator = m_treePathPointerAsset.Remove( iterator );

		}
	}

	return;
}

/**/
