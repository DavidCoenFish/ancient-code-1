//file: Envy/ERecursiveDataStore/ERecursiveDataStoreUtilityLoadVisitorData.h
#ifndef _E_RECURSIVE_DATA_STORE_UTILITY_LOAD_VISITOR_DATA_H_
#define _E_RECURSIVE_DATA_STORE_UTILITY_LOAD_VISITOR_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Envy
{
	template< typename IN_DATA_STORE >class ERecursiveDataStoreUtilityLoadVisitorData
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef IN_DATA_STORE TDataStore;

		///////////////////////////////////////////////////////////
		// creation
	public:
		ERecursiveDataStoreUtilityLoadVisitorData( const ERecursiveDataStoreUtilityLoadVisitorData& in_src );
		ERecursiveDataStoreUtilityLoadVisitorData( IN_DATA_STORE& in_dataStore );
		ERecursiveDataStoreUtilityLoadVisitorData();
		~ERecursiveDataStoreUtilityLoadVisitorData();

		///////////////////////////////////////////////////////////
		// operator
	public:
		const ERecursiveDataStoreUtilityLoadVisitorData& operator=( const ERecursiveDataStoreUtilityLoadVisitorData& in_rhs );
		Hubris::HBOOL operator==( const ERecursiveDataStoreUtilityLoadVisitorData& in_rhs )const;
		Hubris::HBOOL operator!=( const ERecursiveDataStoreUtilityLoadVisitorData& in_rhs )const;

		///////////////////////////////////////////////////////////
		// public methods
	public:
		const TDataStore& DataStoreGet()const{ return( *m_pDataStore ); }
		TDataStore& DataStoreGet(){ return( *m_pDataStore ); }

		const Hubris::HBOOL InsideChildArrayGet()const{ return m_insideChildArray; }
		Hubris::HVOID InsideChildArraySet(){ m_insideChildArray = HTRUE; return; }

		const Hubris::HString& ArrayNameGet()const{ return m_arrayName; }
		Hubris::HVOID ArrayNameSet( const Hubris::HString& in_arrayName ){ m_arrayName = in_arrayName; return; }

		//Hubris::HVOID DataStoreSet( const TDataStore& in_dataStore ){ m_pDataStore = &in_dataStore; return; }

		///////////////////////////////////////////////////////////
		// private members
	private:
		TDataStore* m_pDataStore;
		Hubris::HBOOL m_insideChildArray;
		Hubris::HString m_arrayName;

	};

	/**/
	template< typename IN_DATA_STORE >
	ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >::ERecursiveDataStoreUtilityLoadVisitorData( const ERecursiveDataStoreUtilityLoadVisitorData& in_src )
	: m_pDataStore( HNULL )
	, m_insideChildArray( HFALSE )
	, m_arrayName()
	{
		( *this ) = in_src;
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >::ERecursiveDataStoreUtilityLoadVisitorData( IN_DATA_STORE& in_dataStore )
	: m_pDataStore( &in_dataStore )
	, m_insideChildArray( HFALSE )
	, m_arrayName()
	{
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >::ERecursiveDataStoreUtilityLoadVisitorData()
	: m_pDataStore( HNULL )
	, m_insideChildArray( HFALSE )
	, m_arrayName()
	{
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >::~ERecursiveDataStoreUtilityLoadVisitorData()
	{
		return;
	}

	///////////////////////////////////////////////////////////
	// operator
	/**/
	template< typename IN_DATA_STORE >
	const ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >& ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >::operator=( const ERecursiveDataStoreUtilityLoadVisitorData& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_pDataStore = in_rhs.m_pDataStore;
			m_insideChildArray = in_rhs.m_insideChildArray;
			m_arrayName = in_rhs.m_arrayName;
		}

		return( *this );
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HBOOL ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >::operator==( const ERecursiveDataStoreUtilityLoadVisitorData& in_rhs )const
	{
		Hubris::HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match &= ( m_pDataStore == in_rhs.m_pDataStore );
			match &= ( m_insideChildArray == in_rhs.m_insideChildArray );
			match &= ( m_arrayName == in_rhs.m_arrayName );
		}

		return match;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HBOOL ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >::operator!=( const ERecursiveDataStoreUtilityLoadVisitorData& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	/**/
};

#endif // _E_RECURSIVE_DATA_STORE_UTILITY_LOAD_VISITOR_DATA_H_