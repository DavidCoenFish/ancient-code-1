//file: Envy/EStringTable/EStringTable.h
#ifndef _E_STRING_TABLE_H_
#define _E_STRING_TABLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
//#include "Envy/EMemento/EMementoTrait.h"

/////////////////////////////////////////////////////////////////
// forward declarations
/**/
namespace Hubris
{
	class HString;
};
namespace Envy
{
	class EStringTable;
	class EStringTableImplementation;
};
//EMEMENTO_TRAIT_HEADER( Envy::EStringTable );
namespace Envy												
{															
	class EMementoCollect;									
	class EMementoAssign;									
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const EStringTable& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, EStringTable& out_data );
};

/////////////////////////////////////////////////////////////////
// class
/*
	HNULL string may not behave well, add string as index can cause multiple null strings in array 
	Multiple identical strings may not behave well either
*/
namespace Envy
{
	class EStringTable
	{
		//EMEMENTO_TRAIT_FRIEND( EStringTable );
		friend Hubris::HVOID Envy::EMementoTraitCollect< EStringTable >( Envy::EMementoCollect& in_out_mementoCollect, const EStringTable& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< EStringTable >( const Envy::EMementoAssign& in_out_mementoAssign, EStringTable& out_data );

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStringTable( const EStringTable& in_src );
		EStringTable();
		~EStringTable();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EStringTable& operator=( const EStringTable& in_rhs );
		const Hubris::HBOOL operator==( const EStringTable& in_rhs )const;
		const Hubris::HBOOL operator!=( const EStringTable& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT StringAdd( const Hubris::HString& in_string );

		//allow adding string at an index, will replace string at index
		Hubris::HVOID StringIndexAdd( const Hubris::HString& in_string, const Hubris::HSINT in_index );

		//return HCOMMON_INVALID_INDEX is string not found
		const Hubris::HSINT StringFind( const Hubris::HString& in_string )const;

		const Hubris::HString& StringGet( const Hubris::HSINT in_index )const;
		const Hubris::HSINT StringCountGet()const;

		/////////////////////////////////////////////////////////////////
		// private accessors
	private:
		const EStringTableImplementation& ImplementationGet()const;
		EStringTableImplementation& ImplementationGet();

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		EStringTableImplementation* m_pImplementation;

	};

	/**/
};

#endif // _E_STRING_TABLE_H_
