//file: Envy/ERecursiveDataStore/ERecursiveDataStoreUtilityLoadVisitor.h
#ifndef E_RECURSIVE_DATA_STORE_UTILITY_LOAD_VISITOR_H_
#define E_RECURSIVE_DATA_STORE_UTILITY_LOAD_VISITOR_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HBufferParse/HBufferParse_Export.h >

#include "Envy/ERecursiveDataStore/ERecursiveDataStoreUtilityLoadVisitorData.h"

namespace Envy
{
	template< typename IN_DATA_STORE >class ERecursiveDataStoreUtilityLoadVisitor : public Hubris::HBufferParseLoadVisitorInterface
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef IN_DATA_STORE TDataStore;
		typedef typename TDataStore::TVariantExchange TVariantExchange;
		typedef ERecursiveDataStoreUtilityLoadVisitorData< IN_DATA_STORE >TData;
		typedef Hubris::HContainerArray< TData >TStackData;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		///////////////////////////////////////////////////////////
		// creation
	public:
		ERecursiveDataStoreUtilityLoadVisitor( 
			TDataStore& in_dataStore
			);
		~ERecursiveDataStoreUtilityLoadVisitor();

		///////////////////////////////////////////////////////////
		// implement HBufferParseLoadVisitorInterface
	public:
		virtual const Hubris::HBOOL SkipToEndBlock();
		virtual Hubris::HVOID FoundBlockStart( const Hubris::HString& in_blockName, const Hubris::HSINT in_cursor );
		virtual Hubris::HVOID FoundBlockEnd( const Hubris::HSINT in_cursor );
		virtual Hubris::HVOID FoundValue( const Hubris::HString& in_blockName, const Hubris::HBufferParseVariant& in_value, const Hubris::HSINT in_cursor );
		virtual Hubris::HVOID FoundComment( const Hubris::HString& in_comment, const Hubris::HSINT in_cursor );
		virtual Hubris::HVOID ErrorSet( const Hubris::HString& in_errorMessage, const Hubris::HSINT in_cursor );

		///////////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HBOOL ErrorGet()const{ return m_error; }
		Hubris::HString ErrorMessageGet()const{ return m_errorMessage; }
		Hubris::HSINT ErrorTraceGet()const{ return m_foundTrace; }

		///////////////////////////////////////////////////////////
		// private methods
	private:
		const TData& CurrentDataGet()const;
		TData& CurrentDataGet();

		///////////////////////////////////////////////////////////
		// disabled
	private:
		ERecursiveDataStoreUtilityLoadVisitor( const ERecursiveDataStoreUtilityLoadVisitor& in_src );
		const ERecursiveDataStoreUtilityLoadVisitor& operator=( const ERecursiveDataStoreUtilityLoadVisitor& in_rhs );

		///////////////////////////////////////////////////////////
		// private members
	private:
		TDataStore& m_dataStore;
		TStackData m_stackData;

		Hubris::HString m_errorMessage;
		Hubris::HSINT m_foundTrace;
		Hubris::HBOOL m_error;
	};

	/**/
	///////////////////////////////////////////////////////////
	// creation
	/**/
	template< typename IN_DATA_STORE >
	ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::ERecursiveDataStoreUtilityLoadVisitor( 
		TDataStore& in_dataStore
		)
	: m_dataStore( in_dataStore )
	, m_stackData()
	, m_errorMessage( HFALSE )
	, m_foundTrace( HCOMMON_INVALID_INDEX )
	, m_error( HFALSE )
	{
		Hubris::HContainerUtility::PushBack( m_stackData, TData( in_dataStore ) );

		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::~ERecursiveDataStoreUtilityLoadVisitor()
	{
		return;
	}

	///////////////////////////////////////////////////////////
	// implement HBufferParseLoadVisitorInterface
	/**/
	template< typename IN_DATA_STORE >
	const Hubris::HBOOL ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::SkipToEndBlock()
	{
		return m_error;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundBlockStart( const Hubris::HString& in_blockName, const Hubris::HSINT HCOMMON_UNUSED_VAR( in_cursor )  )
	{
		TData& currentData = CurrentDataGet();
		if( ERecursiveDataStoreUtility< IN_DATA_STORE >::s_childArray == in_blockName )
		{
			//pad the data stack with a duplicate entry of the data store but with 'inside array' turned on
			TData localData( currentData.DataStoreGet() );
			localData.InsideChildArraySet();
			Hubris::HContainerUtility::PushBack( m_stackData, localData );			
		}
		else if( HTRUE == currentData.InsideChildArrayGet() )
		{
			currentData.DataStoreGet().ChildArrayEmptyAdd( in_blockName );
			TData localData( currentData.DataStoreGet() );
			localData.ArrayNameSet( in_blockName );
			Hubris::HContainerUtility::PushBack( m_stackData, localData );
		}
		else if( ERecursiveDataStoreUtility< IN_DATA_STORE >::s_childArrayItem == in_blockName )
		{
			TDataStore& dataStore = currentData.DataStoreGet().ChildArrayAppend( currentData.ArrayNameGet() );
			Hubris::HContainerUtility::PushBack( m_stackData, TData( dataStore ) );
		}
		else
		{
			TDataStore& dataStore = currentData.DataStoreGet().ChildAdd( in_blockName );
			Hubris::HContainerUtility::PushBack( m_stackData, TData( dataStore ) );			
		}

		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundBlockEnd( const Hubris::HSINT HCOMMON_UNUSED_VAR( in_cursor )  )
	{
		Hubris::HContainerUtility::PopBack( m_stackData );
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundValue( const Hubris::HString& in_valueName, const Hubris::HBufferParseVariant& in_value, const Hubris::HSINT HCOMMON_UNUSED_VAR( in_cursor ) )
	{
		IN_DATA_STORE::TVariantExchange dataStoreVariant;
		Hubris::HVariantUtility::Convertor( dataStoreVariant, in_value );

		CurrentDataGet().DataStoreGet().DataSet( in_valueName, dataStoreVariant );		

		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundComment( const Hubris::HString& HCOMMON_UNUSED_VAR( in_comment ), const Hubris::HSINT HCOMMON_UNUSED_VAR( in_cursor ) )
	{
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::ErrorSet( const Hubris::HString& in_errorMessage, const Hubris::HSINT in_cursor )
	{
		m_error = HTRUE;
		m_errorMessage = in_errorMessage;
		m_foundTrace = in_cursor;
	}

	///////////////////////////////////////////////////////////
	// private methods
	/**/
	template< typename IN_DATA_STORE >
	typename const ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::TData& ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::CurrentDataGet()const
	{
		return Hubris::HContainerUtility::BackConst( m_stackData );
	}

	/**/
	template< typename IN_DATA_STORE >
	typename ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::TData& ERecursiveDataStoreUtilityLoadVisitor< IN_DATA_STORE >::CurrentDataGet()
	{
		return Hubris::HContainerUtility::Back( m_stackData );
	}

	/**/

};

#endif // E_RECURSIVE_DATA_STORE_UTILITY_LOAD_VISITOR_H_