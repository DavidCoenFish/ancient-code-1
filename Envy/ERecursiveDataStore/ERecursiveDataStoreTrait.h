//file: Envy/ERecursiveDataStore/ERecursiveDataStoreTrait.h
#ifndef _E_RECURSIVE_DATA_STORE_TRAIT_H_
#define _E_RECURSIVE_DATA_STORE_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HString/HString_Export.h >
#include< Hubris/HTrait/HTrait_Export.h >
#include "Envy/ERecursiveDataStore/ERecursiveDataStore.h"

namespace Hubris
{
	/////////////////////////////////////////////////////////
	// type empty
	/**
	template< typename IN_VARIANT >										
	struct HTraitEmpty< Envy::ERecursiveDataStore< IN_VARIANT > >					
	{												
		static const Envy::ERecursiveDataStore< IN_VARIANT >& EmptyGet()
		{
			static const Envy::ERecursiveDataStore< IN_VARIANT >s_data;
			return s_data;
		}
	private:			
		~HTraitEmpty();								
	};	


	/////////////////////////////////////////////////////////
	// type name

	/**/
	template< typename IN_VARIANT >										
	struct HTraitName< Envy::ERecursiveDataStore< IN_VARIANT > >					
	{
		static HString NameGet();
	private:			
		~HTraitName();								
	};	

	/**/
	template< typename IN_VARIANT >										
	HString HTraitName< Envy::ERecursiveDataStore< IN_VARIANT > >::NameGet(){ return( HString( "ERecursiveDataStore" ) + HTraitName< IN_VARIANT::TTypeList >::NameGet() ); }

};

namespace Envy
{
	/*
		we NEED to memento recursive data store to be able to get from complicated type into EMeneto base scribable types
		to allow recursive data store to contain any type, but still be able to save it
	*/

	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	/**/
	template< typename IN_VARIANT >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const ERecursiveDataStore< IN_VARIANT >& in_dataStore )
	{
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		TArrayString arrayDataName;
		TArrayString arrayChildName;
		TArrayString arrayChildArrayName;
		in_dataStore.NameListGet( arrayDataName, arrayChildName, arrayChildArrayName );

		typedef ERecursiveDataStore< IN_VARIANT >TDataStore;

		//data
		typedef Hubris::HContainerPair< HString, IN_VARIANT >TPairStringVariant;
		typedef Hubris::HContainerArray< TPairStringVariant >TArrayPairStringVariant;
		TArrayPairStringVariant dataArray;
		HCOMMON_FOR_EACH_CONST( dataName, arrayDataName, TArrayString )
		{
			dataArray.Insert( TPairStringVariant( dataName, in_dataStore.DataVariantGet( dataName ) ) );
		}
		in_out_mementoCollect.MemberAdd( "m_data", dataArray );

		//child data store
		typedef Hubris::HContainerPair< HString, TDataStore >TPairStringDataStore;
		typedef Hubris::HContainerArray< TPairStringDataStore >TArrayPairStringDataStore;
		TArrayPairStringDataStore childArray;
		HCOMMON_FOR_EACH_CONST( childName, arrayChildName, TArrayString )
		{
			childArray.Insert( TPairStringDataStore( childName, in_dataStore.ChildGet( childName ) ) );
		}
		in_out_mementoCollect.MemberAdd( "m_childArray", childArray );
	
		//array child data store
		typedef Hubris::HContainerArray< TDataStore >TArrayDataStore;
		typedef Hubris::HContainerPair< HString, TArrayDataStore >TPairStringArrayDataStore;
		typedef Hubris::HContainerArray< TPairStringArrayDataStore >TArrayPairStringArrayDataStore;
		TArrayPairStringArrayDataStore arrayChildArray;
		HCOMMON_FOR_EACH_CONST( arrayChildName, arrayChildArrayName, TArrayString )
		{
			const HSINT arrayChildArrayCount = in_dataStore.ChildArrayCountGet( arrayChildName );
			TArrayDataStore arrayDataStore;
			arrayDataStore.SizeSet( arrayChildArrayCount );
			for( HSINT index = 0; index < arrayChildArrayCount; ++index )
			{
				arrayDataStore[ index ] = in_dataStore.ChildArrayGet( arrayChildName, index );
			}

			arrayChildArray.Insert( TPairStringArrayDataStore( arrayChildName, arrayDataStore ) );
		}
		in_out_mementoCollect.MemberAdd( "m_arrayChildArray", arrayChildArray );


		return;
	}

	/**/
	template< typename IN_VARIANT >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, ERecursiveDataStore< IN_VARIANT >& out_data )
	{
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef ERecursiveDataStore< IN_VARIANT >TDataStore;

		//data
		typedef Hubris::HContainerPair< HString, IN_VARIANT >TPairStringVariant;
		typedef Hubris::HContainerArray< TPairStringVariant >TArrayPairStringVariant;
		TArrayPairStringVariant dataArray;
		in_out_mementoAssign.MemberGet( "m_data", dataArray );
		HCOMMON_FOR_EACH_CONST( data, dataArray, TArrayPairStringVariant )
		{
			out_data.DataSet( data.m_first, data.m_second );
		}

		//child
		typedef Hubris::HContainerPair< HString, TDataStore >TPairStringDataStore;
		typedef Hubris::HContainerArray< TPairStringDataStore >TArrayPairStringDataStore;
		TArrayPairStringDataStore childArray;
		in_out_mementoAssign.MemberGet( "m_childArray", childArray );
		HCOMMON_FOR_EACH_CONST( data, childArray, TArrayPairStringDataStore )
		{
			TDataStore& dataStore = out_data.ChildAdd( data.m_first );
			dataStore = data.m_second;
		}
	
		//array child data store
		typedef Hubris::HContainerArray< TDataStore >TArrayDataStore;
		typedef Hubris::HContainerPair< HString, TArrayDataStore >TPairStringArrayDataStore;
		typedef Hubris::HContainerArray< TPairStringArrayDataStore >TArrayPairStringArrayDataStore;
		TArrayPairStringArrayDataStore arrayChildArray;
		in_out_mementoAssign.MemberGet( "m_arrayChildArray", arrayChildArray );
		HCOMMON_FOR_EACH_CONST( data, arrayChildArray, TArrayPairStringArrayDataStore )
		{
			out_data.ChildArrayEmptyAdd( data.m_first );
			for( HSINT index = 0; index < data.m_second.SizeGet(); ++index )
			{
				TDataStore& dataStore = out_data.ChildArrayAppend( data.m_first );
				dataStore = data.m_second[ index ];
			}
		}

		return;
	}


	/**/

};

#endif // _E_RECURSIVE_DATA_STORE_TRAIT_H_