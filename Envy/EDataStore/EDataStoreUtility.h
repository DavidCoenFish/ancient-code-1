//file: Envy/EDataStore/EDataStoreUtility.h
#ifndef _E_DATA_STORE_UTILITY_H_
#define _E_DATA_STORE_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/EDataStore/EDataStoreUtilityLoadVisitor.h"

namespace Envy
{
	///////////////////////////////////////////////////////
	// struct
	/*
		load and save a data store for human edit
	*/
	template< typename IN_DATA_STORE >struct EDataStoreUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef IN_DATA_STORE TDataStore;
		typedef typename IN_DATA_STORE::TVariant TVariant;
		typedef typename IN_DATA_STORE::TVariant::TTypeList TTypeList;

		///////////////////////////////////////////////////////
		// public static methods
	public:
		static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );
		static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore );

		static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, TDataStore& out_dataStore );

		// given a default value, get a value, if not found set and return default value and insert into data store
		template< typename IN_TYPE >
		static const IN_TYPE& DataDefaultGet( IN_DATA_STORE& in_out_dataStore, const Hubris::HString& in_name, const IN_TYPE& in_defaultValue )
		{
			if( HFALSE == in_out_dataStore.DataTest< IN_TYPE >( in_name ) )
			{
				in_out_dataStore.DataSet< IN_TYPE >( in_name, in_defaultValue );
			}

			return in_out_dataStore.DataGet< IN_TYPE >( in_name );
		}

		///////////////////////////////////////////////////////
		// private methods
	private:
		static Hubris::HVOID Save( Hubris::HBufferParseSave& in_out_save, const TDataStore& in_dataStore );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~EDataStoreUtility();

		///////////////////////////////////////////////////////
		// private members
	private:
		//static const Hubris::HString s_value;
	};

	/**/
	//template< typename IN_DATA_STORE >const Hubris::HString EDataStoreUtility< IN_DATA_STORE >::s_value( "VALUE" );

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HBOOL EDataStoreUtility< IN_DATA_STORE >::SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore )
	{
		Hubris::HBufferParseSave parseSave = Hubris::HBufferParseManager::ParseCreateSaveText();
		Save( parseSave, in_dataStore );
		return in_fileSystem.FileSave( in_path, parseSave.BufferGet() );
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HBOOL EDataStoreUtility< IN_DATA_STORE >::SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const TDataStore& in_dataStore )
	{
		Hubris::HBufferParseSave parseSave = Hubris::HBufferParseManager::ParseCreateSaveBin();
		Save( parseSave, in_dataStore );
		return in_fileSystem.FileSave( in_path, parseSave.BufferGet() );
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HBOOL EDataStoreUtility< IN_DATA_STORE >::Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, TDataStore& out_dataStore )
	{
		Hubris::HBufferParseLoad parseLoad = Hubris::HBufferParseManager::ParseCreateLoad();
		if( HFALSE == in_fileSystem.FileLoad( in_path, parseLoad.BufferGet() ) )
		{
			return HFALSE;
		}

		EDataStoreUtilityLoadVisitor< IN_DATA_STORE > visitor( out_dataStore );

		parseLoad.SubmitVisitor( visitor );

		return HTRUE;
	}

	/**/
	template< typename IN_DATA_STORE >
	void EDataStoreUtility< IN_DATA_STORE >::Save( Hubris::HBufferParseSave& in_out_save, const IN_DATA_STORE& in_dataStore )
	{
		for( HSINT index = 0; index < in_dataStore.DataCountGet(); ++index )
		{
			const Hubris::HString name = in_dataStore.DataNameGet( index );

			Hubris::HBufferParseVariant value;
			Hubris::HVariantUtility::Convertor( value, in_dataStore.DataVariantGet( name ) );

			in_out_save.ValuePut( name, value );
		}

		return;
	}

	/**/
};

#endif // _E_DATA_STORE_UTILITY_H_