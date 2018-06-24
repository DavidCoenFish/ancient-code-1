//file: Envy/EMemento/EMementoImplementation.h
#ifndef _E_MEMENTO_IMPLEMENTATION_H_
#define _E_MEMENTO_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/EMemento/EMementoDataStore.h"

namespace Envy
{
	//////////////////////////////////////////////
	//class
	/*
		represent a pointer by a SINT 
	*/
	class EMementoImplementation
	{
		//////////////////////////////////////////////
		//typedef
	public:
		typedef EMementoDataStore::TVariantExchange TVariantExchange;

		//////////////////////////////////////////////
		//creation
	public:
		EMementoImplementation( const EMementoImplementation& in_src );
		EMementoImplementation();
		~EMementoImplementation();

		//////////////////////////////////////////////
		//operators
	public:
		const EMementoImplementation& operator=( const EMementoImplementation& in_rhs );
		Hubris::HBOOL operator==( const EMementoImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const EMementoImplementation& in_rhs )const;

		//////////////////////////////////////////////
		//public accessors
	public:
		const EMementoDataStore& DataStoreGet()const{ return m_dataStore; }
		EMementoDataStore& DataStoreGet(){ return m_dataStore; }

		//////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT NullPointerIdGet();

		//////////////////////////////////////////////
		//private members
	private:
		EMementoDataStore m_dataStore;

	};

	/**/
};

/**/
#endif // _E_MEMENTO_IMPLEMENTATION_H_