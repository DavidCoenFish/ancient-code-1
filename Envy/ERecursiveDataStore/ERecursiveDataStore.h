//file: Envy/ERecursiveDataStore/ERecursiveDataStore.h
#ifndef _E_RECURSIVE_DATA_STORE_H_
#define _E_RECURSIVE_DATA_STORE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HString/HString_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// class
	/*
		hold a value in a variant to a name. ( tree map )

		typelist is appended with ERecursiveDataStore pointer and pointer array types

		treat smart pointers as being objects, any useage (assginment/ cmp) requires pointer dereference
		policy. 
			always keep ownership of smart pointer memory, ie no one outside a ERecursiveDataStore object gets to look at smart pointer

		ideally, would like not to expose variant in the interface, but it is quite intrinsic to the class definition
	*/
	template< typename IN_VARIANT >class ERecursiveDataStore : public Hubris::HSmartPointerObjectBase< ERecursiveDataStore< typename IN_VARIANT > >
	{
		///////////////////////////////////////////////////////
		// typedef
	public:
		typedef IN_VARIANT TVariantExchange;
		typedef Hubris::HSmartPointer< ERecursiveDataStore< typename IN_VARIANT > >TRecursiveDataStorePointer;

	private:
		typedef typename TVariantExchange::TTypeList TTypleList;
		typedef ERecursiveDataStore< typename IN_VARIANT >TDataStore;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HContainerArray< TRecursiveDataStorePointer >TArrayPointer;
		typedef HTYPE_LIST_APPEND( TArrayPointer, HTYPE_LIST_APPEND( TRecursiveDataStorePointer, TTypleList ) ) TTypeListComplete;

		HVARIANT_DEFINITION( TRecursiveDataStoreVariant, TTypeListComplete );

		typedef Hubris::HContainerTree< Hubris::HString, TRecursiveDataStoreVariant >TMapNameData;

		///////////////////////////////////////////////////////
		// creation
	public:
		ERecursiveDataStore( const TDataStore& in_data );
		ERecursiveDataStore();
		~ERecursiveDataStore();

		///////////////////////////////////////////////////////
		// operators
	public:
		const TDataStore& operator=( const TDataStore& in_rhs );
		const Hubris::HBOOL operator==( const TDataStore& in_rhs )const;
		const Hubris::HBOOL operator!=( const TDataStore& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

		//is a given name in use? true if in use
		const Hubris::HBOOL NameTest( const Hubris::HString& in_name )const;

		Hubris::HVOID NameListGet( TArrayString& out_arrayDataName, TArrayString& out_arrayChildName, TArrayString& out_arrayChildArrayName )const;
		Hubris::HVOID DataNameListGet( TArrayString& out_arrayName )const;
		Hubris::HVOID ChildNameListGet( TArrayString& out_arrayName )const;
		Hubris::HVOID ChildArrayNameListGet( TArrayString& out_arrayName )const;

		TDataStore& ChildAdd( const Hubris::HString& in_childName );
		const Hubris::HBOOL ChildTest( const Hubris::HString& in_childName )const;
		const TDataStore& ChildGet( const Hubris::HString& in_childName )const;
		TDataStore& ChildGet( const Hubris::HString& in_childName );
		Hubris::HVOID ChildRemove( const Hubris::HString& in_childName );

		//add an empty child array
		Hubris::HVOID ChildArrayEmptyAdd( const Hubris::HString& in_childName );
		TDataStore& ChildArrayAppend( const Hubris::HString& in_childName );
		const Hubris::HBOOL ChildArrayTest( const Hubris::HString& in_childName )const;
		const Hubris::HSINT ChildArrayCountGet( const Hubris::HString& in_childName )const;
		Hubris::HVOID ChildArrayCountSet( const Hubris::HString& in_childName, const Hubris::HSINT in_size );
		const TDataStore& ChildArrayGet( const Hubris::HString& in_childName, const Hubris::HSINT in_index )const;
		TDataStore& ChildArrayGet( const Hubris::HString& in_childName, const Hubris::HSINT in_index );
		Hubris::HVOID ChildArrayRemove( const Hubris::HString& in_childName );

		const Hubris::HBOOL DataVariantTest( const Hubris::HString& in_name )const;
		const TVariantExchange DataVariantGet( const Hubris::HString& in_name )const;
		Hubris::HVOID DataVariantSet( const Hubris::HString& in_name, const TVariantExchange& in_variant );
		Hubris::HVOID DataRemove( const Hubris::HString& in_dataName );

		template< typename IN_TYPE >
		const Hubris::HBOOL DataTest( const Hubris::HString& in_dataName )const
		{
			const TMapNameData::TIterator iter = m_mapNameData.Find( in_dataName );
			if( iter == m_mapNameData.End() )
			{
				return HFALSE;
			}

			return( ( *iter ).TypeTest< IN_TYPE >() );
		}

		//return by value, conversion required upstream, so nothing to take reference of
		template< typename IN_TYPE >
		const IN_TYPE DataGet( const Hubris::HString& in_name )const
		{
			return DataVariantGet( in_name ).ValueGet< IN_TYPE >();
		}

		template< typename IN_TYPE >
		Hubris::HVOID DataSet( const Hubris::HString& in_name, const IN_TYPE& in_value )
		{
			DataVariantSet( in_name, TVariantExchange( in_value ) );
		}

		///////////////////////////////////////////////////////
		// private members
	private:
		TMapNameData m_mapNameData;

	};

	///////////////////////////////////////////////////////
	// creation
	/**/
	template< typename IN_VARIANT >
	ERecursiveDataStore< IN_VARIANT >::ERecursiveDataStore( const ERecursiveDataStore& in_data )
	: m_mapNameData()
	{
		( *this ) = in_data;
		return;
	}

	/**/
	template< typename IN_VARIANT >
	ERecursiveDataStore< IN_VARIANT >::ERecursiveDataStore()
	: m_mapNameData()
	{
		return;
	}

	/**/
	template< typename IN_VARIANT >
	ERecursiveDataStore< IN_VARIANT >::~ERecursiveDataStore()
	{
		return;
	}

	///////////////////////////////////////////////////////
	// operators
	/**/
	template< typename IN_VARIANT >
	const ERecursiveDataStore< IN_VARIANT >& ERecursiveDataStore< IN_VARIANT >::operator=( const ERecursiveDataStore& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			//using smart pointers, requires dereference of assigned smart pointer objects. 
			//policy. we keep ownership of our own memory
			m_mapNameData.Clear();
			for( const TMapNameData::TIterator iter = in_rhs.m_mapNameData.Begin(); iter != in_rhs.m_mapNameData.End(); ++iter )
			{
				const TRecursiveDataStoreVariant& variant = iter.DataGet();

				if( HTRUE == variant.TypeTest< TRecursiveDataStorePointer >() )
				{
					m_mapNameData.Insert( iter.KeyGet(), TRecursiveDataStoreVariant( HSmartPointerUtility::Copy( variant.ValueGet< TRecursiveDataStorePointer >() ) ) );
				}
				else if( HTRUE == variant.TypeTest< TArrayPointer >() )
				{
					m_mapNameData.Insert( iter.KeyGet(), TRecursiveDataStoreVariant( HSmartPointerUtility::Copy( variant.ValueGet< TArrayPointer >() ) ) );
				}
				else
				{
					m_mapNameData.Insert( iter.KeyGet(), variant );
				}
			}
		}

		return( *this );
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HBOOL ERecursiveDataStore< IN_VARIANT >::operator==( const ERecursiveDataStore& in_rhs )const
	{		
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			//using smart pointers, requires dereference of CMP smart pointer objects. 
			//policy. we keep ownership of our own memory
			match &= ( m_mapNameData.SizeGet() == in_rhs.m_mapNameData.SizeGet() );
			if( HFALSE == match )
			{
				return HFALSE;
			}

			for( const TMapNameData::TIterator lhsIter = m_mapNameData.Begin(), rhsIter = in_rhs.m_mapNameData.Begin(); lhsIter != m_mapNameData.End(), rhsIter != in_rhs.m_mapNameData.End(); ++lhsIter, ++rhsIter )
			{
				if( lhsIter.KeyGet() != rhsIter.KeyGet() )
				{
					return HFALSE;
				}

				const TRecursiveDataStoreVariant& lhsVariant = lhsIter.DataGet();
				const TRecursiveDataStoreVariant& rhsVariant = rhsIter.DataGet();
				
				if( lhsVariant.TypeIndexGet() != rhsVariant.TypeIndexGet() )
				{
					return HFALSE;
				}

				if( HTRUE == lhsVariant.TypeTest< TRecursiveDataStorePointer >() )
				{
					match &= HSmartPointerUtility::Cmp( lhsVariant.ValueGet< TRecursiveDataStorePointer >(), rhsVariant.ValueGet< TRecursiveDataStorePointer >() );
				}
				else if( HTRUE == lhsVariant.TypeTest< TArrayPointer >() )
				{
					match &= HSmartPointerUtility::Cmp( lhsVariant.ValueGet< TArrayPointer >(), rhsVariant.ValueGet< TArrayPointer >() );
				}
				else
				{
					match &= ( lhsVariant == rhsVariant );
				}

				if( HFALSE == match )
				{
					return HFALSE;
				}
			}
		}

		return match;
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HBOOL ERecursiveDataStore< IN_VARIANT >::operator!=( const ERecursiveDataStore& in_rhs )const
	{	
		return( !( operator==( in_rhs ) ) );
	}

	///////////////////////////////////////////////////////
	// public methods
	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::Clear()
	{
		m_mapNameData.Clear();
		return;
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HBOOL ERecursiveDataStore< IN_VARIANT >::NameTest( const Hubris::HString& in_name )const
	{
		return( m_mapNameData.Find( in_name ) != m_mapNameData.End() );
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::NameListGet( TArrayString& out_arrayDataName, TArrayString& out_arrayChildName, TArrayString& out_arrayChildArrayName )const
	{
		for( const TMapNameData::TIterator iter = m_mapNameData.Begin(); iter != m_mapNameData.End(); ++iter )
		{
			const TRecursiveDataStoreVariant& data = ( *iter );
			//if( data.TypeIndexGet() == Hubris::HTypeListUtilIndexOf< IN_VARIANT, TRecursiveDataStorePointer >::index )
			if( HTRUE == data.TypeTest< TRecursiveDataStorePointer >() )
			{
				out_arrayChildName.Insert( iter.KeyGet() );
			}
			//else if( data.TypeIndexGet() == Hubris::HTypeListUtilIndexOf< IN_VARIANT, TArrayPointer >::index )
			else if( HTRUE == data.TypeTest< TArrayPointer >() )
			{
				out_arrayChildArrayName.Insert( iter.KeyGet() );
			}
			else
			{
				out_arrayDataName.Insert( iter.KeyGet() );
			}
		}

		return;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::DataNameListGet( TArrayString& out_arrayName )const
	{
		TArrayString dummyOne;
		TArrayString dummyTwo;
		NameListGet( out_arrayName, dummyOne, dummyTwo );
		return;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::ChildNameListGet( TArrayString& out_arrayName )const
	{
		TArrayString dummyOne;
		TArrayString dummyTwo;
		NameListGet( dummyOne, out_arrayName, dummyTwo );
		return;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::ChildArrayNameListGet( TArrayString& out_arrayName )const
	{
		TArrayString dummyOne;
		TArrayString dummyTwo;
		NameListGet( dummyOne, dummyTwo, out_arrayName );
		return;
	}

	/**/
	template< typename IN_VARIANT >
	typename ERecursiveDataStore< IN_VARIANT >::TDataStore& ERecursiveDataStore< IN_VARIANT >::ChildAdd( const Hubris::HString& in_childName )
	{
		HCOMMON_ASSERT( HFALSE == NameTest( in_childName ), "name already in use" );
		TRecursiveDataStorePointer pData;
		pData.Create();
		m_mapNameData.Insert( in_childName, TRecursiveDataStoreVariant( pData ) );
		return( *pData );
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HBOOL ERecursiveDataStore< IN_VARIANT >::ChildTest( const Hubris::HString& in_childName )const
	{
		const TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter != m_mapNameData.End() )
		{
			if( HTRUE == ( *iter ).TypeTest< TRecursiveDataStorePointer >() )
			{
				return HTRUE;
			}
		}
		return HFALSE;
	}

	/**/
	template< typename IN_VARIANT >
	typename const ERecursiveDataStore< IN_VARIANT >::TDataStore& ERecursiveDataStore< IN_VARIANT >::ChildGet( const Hubris::HString& in_childName )const
	{
		const TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter == m_mapNameData.End() )
		{
			HCOMMON_ASSERT_ALWAYS( "child member not found" );
		}

		HCOMMON_ASSERT( HTRUE == ( *iter ).TypeTest< TRecursiveDataStorePointer >(), "incorrect data type" );

		return( *( ( *iter ).ValueGet< TRecursiveDataStorePointer >() ) );
	}

	/**/
	template< typename IN_VARIANT >
	typename ERecursiveDataStore< IN_VARIANT >::TDataStore& ERecursiveDataStore< IN_VARIANT >::ChildGet( const Hubris::HString& in_childName )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter == m_mapNameData.End() )
		{
			HCOMMON_ASSERT_ALWAYS( "child member not found" );
		}

		HCOMMON_ASSERT( HTRUE == ( *iter ).TypeTest< TRecursiveDataStorePointer >(), "incorrect data type" );

		return( *( ( *iter ).ValueGet< TRecursiveDataStorePointer >() ) );
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::ChildRemove( const Hubris::HString& in_childName )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter != m_mapNameData.End() )
		{
			m_mapNameData.Remove( iter );
		}

		return;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::ChildArrayEmptyAdd( const Hubris::HString& in_childName )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter == m_mapNameData.End() )
		{
			TArrayPointer arrayPointer;
			m_mapNameData.Insert( in_childName, TRecursiveDataStoreVariant( arrayPointer ) );
		}

		return;
	}

	/**/
	template< typename IN_VARIANT >
	typename ERecursiveDataStore< IN_VARIANT >::TDataStore& ERecursiveDataStore< IN_VARIANT >::ChildArrayAppend( const Hubris::HString& in_childName )
	{
		TRecursiveDataStorePointer pData;
		pData.Create();
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );

		if( iter == m_mapNameData.End() )
		{
			TArrayPointer arrayPointer;
			arrayPointer.Insert( pData );
			m_mapNameData.Insert( in_childName, TRecursiveDataStoreVariant( arrayPointer ) );
		}
		else
		{
			HCOMMON_ASSERT( HTRUE == ( *iter ).TypeTest< TArrayPointer >(), "incorrect data type" );
			( *iter ).ValueGet< TArrayPointer >().Insert( pData );
		}

		return( *pData );
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HBOOL ERecursiveDataStore< IN_VARIANT >::ChildArrayTest( const Hubris::HString& in_childName )const
	{
		const TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter != m_mapNameData.End() )
		{
			if( HTRUE == ( *iter ).TypeTest< TArrayPointer >() )
			{
				return HTRUE;
			}
		}
		return HFALSE;
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HSINT ERecursiveDataStore< IN_VARIANT >::ChildArrayCountGet( const Hubris::HString& in_childName )const
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter == m_mapNameData.End() )
		{
			HCOMMON_ASSERT_ALWAYS( "child array not found" );
		}
		HCOMMON_ASSERT( HTRUE == ( *iter ).TypeTest< TArrayPointer >(), "incorrect data type" );
		return ( *iter ).ValueGet< TArrayPointer >().SizeGet();
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::ChildArrayCountSet( const Hubris::HString& in_childName, const Hubris::HSINT in_size )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter == m_mapNameData.End() )
		{
			HCOMMON_ASSERT_ALWAYS( "child array not found" );
		}
		HCOMMON_ASSERT( HTRUE == ( *iter ).TypeTest< TArrayPointer >(), "incorrect data type" );
		TArrayPointer& arrayPointer = ( *iter ).ValueGet< TArrayPointer >();
		if( arrayPointer.SizeGet() != in_size )
		{
			arrayPointer.SizeResize( in_size );
			//make sure the child array is populated
			HCOMMON_FOR_EACH( pPointer, arrayPointer, TArrayPointer )
			{
				if( HNULL != pPointer )
				{
					continue;
				}

				pPointer.Create();
			}
		}

		return;
	}

	/**/
	template< typename IN_VARIANT >
	typename const ERecursiveDataStore< IN_VARIANT >::TDataStore& ERecursiveDataStore< IN_VARIANT >::ChildArrayGet( const Hubris::HString& in_childName, const Hubris::HSINT in_index )const
	{
		const TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter == m_mapNameData.End() )
		{
			HCOMMON_ASSERT_ALWAYS( "child array not found" );
		}
		HCOMMON_ASSERT( HTRUE == ( *iter ).TypeTest< TArrayPointer >(), "incorrect data type" );
		return( *( ( *iter ).ValueGet< TArrayPointer >()[ in_index ] ));
	}

	/**/
	template< typename IN_VARIANT >
	typename ERecursiveDataStore< IN_VARIANT >::TDataStore& ERecursiveDataStore< IN_VARIANT >::ChildArrayGet( const Hubris::HString& in_childName, const Hubris::HSINT in_index )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter == m_mapNameData.End() )
		{
			HCOMMON_ASSERT_ALWAYS( "child array not found" );
		}
		HCOMMON_ASSERT( HTRUE == ( *iter ).TypeTest< TArrayPointer >(), "incorrect data type" );
		return( *( ( *iter ).ValueGet< TArrayPointer >()[ in_index ] ));
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::ChildArrayRemove( const Hubris::HString& in_childName )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_childName );
		if( iter != m_mapNameData.End() )
		{
			m_mapNameData.Remove( iter );
		}

		return;
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HBOOL ERecursiveDataStore< IN_VARIANT >::DataVariantTest( const Hubris::HString& in_dataName )const
	{
		const TMapNameData::TIterator iter = m_mapNameData.Find( in_dataName );
		if( iter != m_mapNameData.End() )
		{
			if( ( HFALSE == ( *iter ).TypeTest< TRecursiveDataStorePointer >() ) &&
				( HFALSE == ( *iter ).TypeTest< TArrayPointer >() ) )
			{
				return HTRUE;
			}
		}
		return HFALSE;
	}

	/**/
	template< typename IN_VARIANT >
	typename const ERecursiveDataStore< IN_VARIANT >::TVariantExchange ERecursiveDataStore< IN_VARIANT >::DataVariantGet( const Hubris::HString& in_dataName )const
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_dataName );
		if( iter == m_mapNameData.End() )
		{
			HCOMMON_ASSERT_ALWAYS( "data not found in data store" );
		}
		TVariantExchange data;
		Hubris::HVariantUtility::Convertor< TVariantExchange, TRecursiveDataStoreVariant >( data, ( *iter ) );

		return data;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::DataVariantSet( const Hubris::HString& in_dataName, const TVariantExchange& in_variant )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_dataName );
		if( iter == m_mapNameData.End() )
		{
			TRecursiveDataStoreVariant data;
			Hubris::HVariantUtility::Convertor< TRecursiveDataStoreVariant, TVariantExchange >( data, in_variant );
			m_mapNameData.Insert( in_dataName, data );
		}
		else
		{
			TRecursiveDataStoreVariant data;
			Hubris::HVariantUtility::Convertor< TRecursiveDataStoreVariant, TVariantExchange >( data, in_variant );

			( *iter ) = data;
		}

		return;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HVOID ERecursiveDataStore< IN_VARIANT >::DataRemove( const Hubris::HString& in_dataName )
	{
		TMapNameData::TIterator iter = m_mapNameData.Find( in_dataName );
		if( iter != m_mapNameData.End() )
		{
			m_mapNameData.Remove( iter );
		}

		return;
	}

	/**/
	
};

#endif // _E_RECURSIVE_DATA_STORE_H_