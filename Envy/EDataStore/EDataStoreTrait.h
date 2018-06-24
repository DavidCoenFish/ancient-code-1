//file: Envy/EDataStore/EDataStoreTrait.h
#ifndef _E_DATA_STORE_TRAIT_H_
#define _E_DATA_STORE_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/EDataStore/EDataStore.h"

namespace Hubris
{
	/////////////////////////////////////////////////////////
	// type empty
	/**
	template< typename IN_VARIANT >										
	struct HTraitEmpty< Envy::EDataStore< IN_VARIANT > >					
	{												
		static const Envy::EDataStore< IN_VARIANT >& EmptyGet()
		{
			static const Envy::EDataStore< IN_VARIANT >s_data;
			return s_data;
		}
	private:			
		~HTraitEmpty();								
	};	


	/////////////////////////////////////////////////////////
	// type name

	/**/
	template< typename IN_VARIANT >										
	struct HTraitName< Envy::EDataStore< IN_VARIANT > >					
	{
		static HString NameGet();
	private:			
		~HTraitName();								
	};	

	/**/
	template< typename IN_VARIANT >										
		HString HTraitName< Envy::EDataStore< IN_VARIANT > >::NameGet(){ return( HString( "EDataStore_" ) + HTraitName< IN_VARIANT::TTypeList >::NameGet() ); }

	/////////////////////////////////////////////////////////
	// transcribe add

	/**
	template< typename IN_VARIANT > 
	void HMementoTranscribeAdd( Hubris::HMementoAdd& in_mementoAdd, const Envy::EDataStore< IN_VARIANT >& in_object, const HBOOL in_editable )
	{
		

		//in_mementoAdd.MemberAdd( "m_nameDataMap", in_object.NameDataMapGet(), in_editable );

		typedef Hubris::HContainerPair< Hubris::HString, typename IN_VARIANT::TVariantImplementation >TStringVariantPair;
		typedef Hubris::HContainerArray< TStringVariantPair >TStringVariantPairArray;
		TStringVariantPairArray dataArray;

		const HSINT count = in_object.DataCountGet();
		for( HSINT index = 0; index < count; ++index )
		{
			const Hubris::HString& name = in_object.DataNameGet( index );
			const IN_VARIANT& value = in_object.DataVariantGet( name );
			dataArray.Insert( TStringVariantPair( name, value ) );
		}

		//TODO:
		in_mementoAdd.MemberAdd( "m_nameDataMap", dataArray, in_editable );

		return;
	}

	/**/

};

#endif // _E_DATA_STORE_TRAIT_H_