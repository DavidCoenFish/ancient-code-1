//file: Envy/EDataStore/EDataStore.h
#ifndef _E_DATA_STORE_H_
#define _E_DATA_STORE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// class
	/*
		hold a value in a variant to a name. ( tree map )
		can only have one value per name

		policy.
			assert if data not found on get, or if data access is of wrong type ( so provide test functions )

		ideally, would like not to expose variant in the interface, but it is quite intrinsic to the class definition
	*/
	template< typename IN_VARIANT >class EDataStore
	{
		///////////////////////////////////////////////////////
		// typedef
	public:
		typedef IN_VARIANT TVariant;

	private:
		typedef Hubris::HContainerTree< Hubris::HString, typename TVariant >TNameDataMap;

		///////////////////////////////////////////////////////
		// creation
	public:
		EDataStore( const EDataStore& in_data );
		EDataStore();
		~EDataStore();

		///////////////////////////////////////////////////////
		// operators
	public:
		const EDataStore& operator=( const EDataStore& in_rhs );
		Hubris::HBOOL operator==( const EDataStore& in_rhs )const;
		Hubris::HBOOL operator!=( const EDataStore& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		/**/
		template< typename IN_TYPE >void DataSet( const Hubris::HString& in_name, const IN_TYPE& in_value )
		{
			DataVariantSet( in_name, TVariant( in_value ) );

			return;
		}

		/**/
		void DataVariantSet( const Hubris::HString& in_name, const TVariant& in_value );

		/**/
		template< typename IN_TYPE >Hubris::HBOOL DataTest( const Hubris::HString& in_name )const
		{
			TNameDataMap::TIterator iterator = m_nameDataMap.Find( in_name );
			if( iterator != m_nameDataMap.End() )
			{
				return( *iterator ).TypeTest< IN_TYPE >();
			}

			return HFALSE;
		}

		/**/

		template< typename IN_TYPE >const IN_TYPE& DataGet( const Hubris::HString& in_name )const
		{
			const IN_VARIANT& value = DataVariantGet( in_name );
			HCOMMON_ASSERT( HTRUE == value.TypeTest< IN_TYPE >(), "invalid type access" )

			return value.ValueGet< IN_TYPE >();
		}

		/**/
		const typename TVariant& DataVariantGet( const Hubris::HString& in_name )const;
		//test if any type of data exsists for given name
		Hubris::HBOOL DataVariantTest( const Hubris::HString& in_name )const;

		void DataRemove( const Hubris::HString& in_name );
		void DataClear();
			
		Hubris::HSINT DataCountGet()const;
		const Hubris::HString& DataNameGet( const Hubris::HSINT in_index )const;

		///////////////////////////////////////////////////////
		// private members
	private:
		TNameDataMap m_nameDataMap;

	};

	///////////////////////////////////////////////////////
	// creation

	/**/
	template< typename IN_VARIANT >
	EDataStore< IN_VARIANT >::EDataStore( const EDataStore& in_data ) :
		m_nameDataMap()
	{
		( *this ) = in_data;
		return;
	}

	/**/
	template< typename IN_VARIANT >
	EDataStore< IN_VARIANT >::EDataStore() :
		m_nameDataMap()
	{
		return;
	}

	/**/
	template< typename IN_VARIANT >
	EDataStore< IN_VARIANT >::~EDataStore()
	{
		return;
	}

	///////////////////////////////////////////////////////
	// operators
	/**/
	template< typename IN_VARIANT >
	const EDataStore< IN_VARIANT >& EDataStore< IN_VARIANT >::operator=( const EDataStore& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_nameDataMap = in_rhs.m_nameDataMap;
		}

		return( *this );
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HBOOL EDataStore< IN_VARIANT >::operator==( const EDataStore& in_rhs )const
	{
		HBOOL match = true;
		if( this != &in_rhs )
		{
			match &= ( m_nameDataMap == in_rhs.m_nameDataMap );
		}

		return match;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HBOOL EDataStore< IN_VARIANT >::operator!=( const EDataStore& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	///////////////////////////////////////////////////////
	// public methods
	/**/
	template< typename IN_VARIANT >
	void EDataStore< IN_VARIANT >::DataVariantSet( const Hubris::HString& in_name, const TVariant& in_value )
	{
		m_nameDataMap.Insert( in_name, in_value );

		return;
	}

	/**/
	template< typename IN_VARIANT >
	const typename IN_VARIANT& EDataStore< IN_VARIANT >::DataVariantGet( const Hubris::HString& in_name )const
	{
		TNameDataMap::TIterator iterator = m_nameDataMap.Find( in_name );
		HCOMMON_ASSERT( iterator != m_nameDataMap.End(), "map entry not found" );

		return( *iterator );
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HBOOL EDataStore< IN_VARIANT >::DataVariantTest( const Hubris::HString& in_name )const
	{
		TNameDataMap::TIterator iterator = m_nameDataMap.Find( in_name );
		if( iterator != m_nameDataMap.End() )
		{
			return HTRUE;;
		}

		return HFALSE;
	}

	/**/
	template< typename IN_VARIANT >
	void EDataStore< IN_VARIANT >::DataRemove( const Hubris::HString& in_name )
	{
		TNameDataMap::TIterator iterator = m_nameDataMap.Find( in_name );
		if( iterator != m_nameDataMap.End() )
		{
			m_nameDataMap.Remove( iterator );
		}

		return;
	}

	/**/
	template< typename IN_VARIANT >
	void EDataStore< IN_VARIANT >::DataClear()
	{
		m_nameDataMap.Clear();

		return;
	}

	/**/
	template< typename IN_VARIANT >
	Hubris::HSINT EDataStore< IN_VARIANT >::DataCountGet()const
	{
		return m_nameDataMap.SizeGet();
	}

	/**/
	template< typename IN_VARIANT >
	const Hubris::HString& EDataStore< IN_VARIANT >::DataNameGet( const Hubris::HSINT in_index )const
	{
		return m_nameDataMap.KeyGet( in_index );
	}

	/**/
	
};

#endif // _E_DATA_STORE_H_
