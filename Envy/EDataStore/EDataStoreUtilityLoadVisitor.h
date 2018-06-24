//file: Envy/EDataStore/EDataStoreUtilityLoadVisitor.h
#ifndef _E_DATA_STORE_UTILITY_LOAD_VISITOR_H_
#define _E_DATA_STORE_UTILITY_LOAD_VISITOR_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HBufferParse/HBufferParse_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// struct
	/*
		load and save a data store for human edit
	*/
	template< typename IN_DATA_STORE >class EDataStoreUtilityLoadVisitor : public Hubris::HBufferParseLoadVisitorInterface
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef IN_DATA_STORE TDataStore;

		///////////////////////////////////////////////////////////
		// creation
	public:
		EDataStoreUtilityLoadVisitor( TDataStore& in_dataStore );
		~EDataStoreUtilityLoadVisitor();

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
		// disabled
	private:
		EDataStoreUtilityLoadVisitor( const EDataStoreUtilityLoadVisitor& in_src );
		const EDataStoreUtilityLoadVisitor& operator=( const EDataStoreUtilityLoadVisitor& in_rhs );

		///////////////////////////////////////////////////////////
		// private members
	private:
		TDataStore& m_dataStore;

		Hubris::HBOOL m_error;
	};

	///////////////////////////////////////////////////////////
	// creation
	/**/
	template< typename IN_DATA_STORE >
	EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::EDataStoreUtilityLoadVisitor( TDataStore& in_dataStore )
	: m_dataStore( in_dataStore )
	, m_error( HFALSE )
	{
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::~EDataStoreUtilityLoadVisitor()
	{
		return;
	}

	///////////////////////////////////////////////////////////
	// implement HInterfaceBufferParseLoadVisitor
	/**/
	template< typename IN_DATA_STORE >
	const Hubris::HBOOL EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::SkipToEndBlock()
	{ 
		return( HTRUE == m_error ); 
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundBlockStart( const Hubris::HString&, const Hubris::HSINT )
	{
		m_error = HTRUE;
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundBlockEnd( const Hubris::HSINT )
	{
		m_error = HTRUE;
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundValue( const Hubris::HString& in_valueName, const Hubris::HBufferParseVariant& in_value, const Hubris::HSINT )
	{
		IN_DATA_STORE::TVariant dataStoreVariant;
		Hubris::HVariantUtility::Convertor( dataStoreVariant, in_value );

		m_dataStore.DataSet( in_valueName, dataStoreVariant );

		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::FoundComment( const Hubris::HString&, const Hubris::HSINT )
	{
		return;
	}

	/**/
	template< typename IN_DATA_STORE >
	Hubris::HVOID EDataStoreUtilityLoadVisitor< IN_DATA_STORE >::ErrorSet( const Hubris::HString&, const Hubris::HSINT )
	{
		m_error = true;
		return;
	}

	/**/
};

#endif // _E_DATA_STORE_UTILITY_LOAD_VISITOR_H_
