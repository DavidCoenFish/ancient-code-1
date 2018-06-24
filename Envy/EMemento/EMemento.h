//file: Envy/EMemento/EMemento.h
#ifndef _E_MEMENTO_H_
#define _E_MEMENTO_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMementoImplementation;
	class EMementoAssign;
	class EMementoCollect;
	struct EMementoUtility;

	///////////////////////////////////////////////////////
	// class
	/*
		we are just a data holder, see EMementoCollect ect for functionality implementation
	*/
	class EMemento
	{
		friend EMementoAssign;
		friend EMementoCollect;
		friend EMementoUtility;

		//////////////////////////////////////////////
		//creation
	public:
		EMemento( const EMemento& in_src );
		EMemento();
		~EMemento();

		//////////////////////////////////////////////
		//operators
	public:
		const EMemento& operator=( const EMemento& in_rhs );
		Hubris::HBOOL operator==( const EMemento& in_rhs )const;
		Hubris::HBOOL operator!=( const EMemento& in_rhs )const;

		//////////////////////////////////////////////
		//private accessors
	private:
		const EMementoImplementation& ImplementationGet()const;
		EMementoImplementation& ImplementationGet();

		//////////////////////////////////////////////
		//private members
	private:
		EMementoImplementation* m_pImplementation;

	};

	/**/
};

#endif // _E_MEMENTO_H_