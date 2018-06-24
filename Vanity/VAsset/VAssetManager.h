//file: Vanity/VAsset/VAssetManager.h
#ifndef _V_ASSET_MANAGER_H_
#define _V_ASSET_MANAGER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAsset/VAsset.h"

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Hubris
{
	class HFileSystem;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAsset;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VAssetManager
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VAsset >TPointerAsset;
		typedef Hubris::HContainerTree< Hubris::HString, TPointerAsset >TTreePathPointerAsset;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAssetManager();
		~VAssetManager();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VAssetManager( const VAssetManager& in_src );
		const VAssetManager& operator=( const VAssetManager& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		template< typename IN_ASSET >
		IN_ASSET* const AssetRequest( 
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HFileSystemPath& in_path 
			)
		{
			const Hubris::HString path = in_path.PathFileNameExtentionGet();
			TTreePathPointerAsset::TIterator iterator = m_treePathPointerAsset.Find( path );
			if( iterator == m_treePathPointerAsset.End() )
			{
				IN_ASSET* pAsset = HNULL;
				HCOMMON_NEW_PARAM_2(
					pAsset,
					IN_ASSET,
					in_sceneApplicationInterface,
					in_path
					);
				m_treePathPointerAsset.Insert( path, pAsset );
				return pAsset;
			}

			IN_ASSET* const pAsset = Hubris::HTypeRunTimeInfoCast< VAsset, IN_ASSET >( ( *iterator ).RawGet() );
			
			return pAsset;
		}

		Hubris::HVOID AssetReleaseUnused();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		//const Sloth::STextureAlias& TextureAliasGet()const;
		//Sloth::STextureAlias& TextureAliasGet();

		//const Hubris::HFileSystem& FileSystemGet()const;
		//Hubris::HFileSystem& FileSystemGet();
	
		///////////////////////////////////////////////////////
		// private members
	private:
		TTreePathPointerAsset m_treePathPointerAsset;
		//Sloth::STextureAlias* m_pTextureAlias;
		//Hubris::HFileSystem* m_pFileSystem;

	};

	/**/
	
};

#endif // _V_ASSET_MANAGER_H_