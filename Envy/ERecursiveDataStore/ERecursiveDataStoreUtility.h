//file: Envy/ERecursiveDataStore/ERecursiveDataStoreUtility.h
#ifndef _E_RECURSIVE_DATA_STORE_UTILITY_H_
#define _E_RECURSIVE_DATA_STORE_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HBufferParse/HBufferParse_Export.h >
#include "Envy/ERecursiveDataStore/ERecursiveDataStoreUtilityLoadVisitor.h"

namespace Hubris
{
	class HFileSystem;
	class HFileSystemPath;
};

namespace Envy
{
	///////////////////////////////////////////////////////
	// struct
	/*
		load and save a recursive data store for human edit
	*/
	template< typename IN_RECURSIVE_DATA_STORE >struct ERecursiveDataStoreUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef IN_RECURSIVE_DATA_STORE TDataStore;
		typedef typename TDataStore::TVariantExchange TVariantExchange;
		typedef typename TVariantExchange::TTypeList TTypeList;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		/*
			will assert on attempt to save data store of variants with non base types
			ie, can save types use by HBufferParseVariantTypeList, which should be the same as the memento base type list
			so memento complicated recursive data stores, and save them (and memento uses ERecursiveDataStoreUtility to save itself) 
		*/
		static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );
		static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );

		static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, TDataStore& out_dataStore );

		///////////////////////////////////////////////////////
		// private methods
	private:
		static Hubris::HVOID Save( Hubris::HBufferParseSave& in_out_save, const TDataStore& in_dataStore );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~ERecursiveDataStoreUtility();

		///////////////////////////////////////////////////////
		// static public members
	public:
		static const Hubris::HString s_childArray;
		static const Hubris::HString s_childArrayItem;

	};

	/**/
	template< typename IN_RECURSIVE_DATA_STORE >const Hubris::HString ERecursiveDataStoreUtility< IN_RECURSIVE_DATA_STORE >::s_childArray( "ERDSU_ARRAY" );
	template< typename IN_RECURSIVE_DATA_STORE >const Hubris::HString ERecursiveDataStoreUtility< IN_RECURSIVE_DATA_STORE >::s_childArrayItem( "ERDSU_ITEM" );

	/**/
	template< typename IN_RECURSIVE_DATA_STORE >
	Hubris::HBOOL ERecursiveDataStoreUtility< IN_RECURSIVE_DATA_STORE >::SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore )
	{
		Hubris::HBufferParseSave parseSave = Hubris::HBufferParseManager::ParseCreateSaveText();
		Save( parseSave, in_dataStore );
		return in_fileSystem.FileSave( in_path, parseSave.BufferGet() );
	}

	/**/
	template< typename IN_RECURSIVE_DATA_STORE >
	Hubris::HBOOL ERecursiveDataStoreUtility< IN_RECURSIVE_DATA_STORE >::SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore )
	{
		Hubris::HBufferParseSave parseSave = Hubris::HBufferParseManager::ParseCreateSaveBin();
		Save( parseSave, in_dataStore );
		return in_fileSystem.FileSave( in_path, parseSave.BufferGet() );
	}

	/**/
	template< typename IN_RECURSIVE_DATA_STORE >
	Hubris::HBOOL ERecursiveDataStoreUtility< IN_RECURSIVE_DATA_STORE >::Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, TDataStore& out_dataStore )
	{
		Hubris::HBufferParseLoad parseLoad = Hubris::HBufferParseManager::ParseCreateLoad();
		if( HFALSE == in_fileSystem.FileLoad( in_path, parseLoad.BufferGet() ) )
		{
			return HFALSE;
		}

		ERecursiveDataStoreUtilityLoadVisitor< IN_RECURSIVE_DATA_STORE > visitor( out_dataStore );

		parseLoad.SubmitVisitor( visitor );

		return HTRUE;
	}

	/**/
	template< typename IN_RECURSIVE_DATA_STORE >
	void ERecursiveDataStoreUtility< IN_RECURSIVE_DATA_STORE >::Save( Hubris::HBufferParseSave& in_out_save, const IN_RECURSIVE_DATA_STORE& in_dataStore )
	{
		TArrayString arrayDataName;
		TArrayString arrayChildName;
		TArrayString arrayChildArrayName;
		in_dataStore.NameListGet( arrayDataName, arrayChildName, arrayChildArrayName );

		//data, arrayDataName
		HCOMMON_FOR_EACH_CONST( dataName, arrayDataName, TArrayString )
		{
			Hubris::HBufferParseVariant value;
			Hubris::HVariantUtility::Convertor( value, in_dataStore.DataVariantGet( dataName ) );

			in_out_save.ValuePut( dataName, value );
		}

		//children, arrayChildName
		HCOMMON_FOR_EACH_CONST( childName, arrayChildName, TArrayString )
		{
			const TDataStore& child = in_dataStore.ChildGet( childName );

			in_out_save.BlockStart( childName );
			Save( in_out_save, child );
			in_out_save.BlockEnd();
		}
	    
		//childrenArray, arrayChildArrayName
		HCOMMON_FOR_EACH_CONST( childArrayName, arrayChildArrayName, TArrayString )
		{
			in_out_save.BlockStart( s_childArray );
			in_out_save.BlockStart( childArrayName );

			const Hubris::HSINT childCount = in_dataStore.ChildArrayCountGet( childArrayName );
			for( Hubris::HSINT index = 0; index < childCount; ++index )
			{
				const TDataStore& child = in_dataStore.ChildArrayGet( childArrayName, index );

				in_out_save.BlockStart( s_childArrayItem );
				Save( in_out_save, child );
				in_out_save.BlockEnd();
			}

			in_out_save.BlockEnd();
			in_out_save.BlockEnd();
		}

		return;
	}

	/**/
};

#endif // _E_RECURSIVE_DATA_STORE_UTILITY_H_