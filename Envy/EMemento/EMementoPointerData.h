//file: Envy/EMemento/EMementoPointerData.h
#ifndef _E_MEMENTO_ASSIGN_POINTER_DATA_H_
#define _E_MEMENTO_ASSIGN_POINTER_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;

	///////////////////////////////////////////////////////
	// class
	/**/
	class EMementoPointerData
	{
		//////////////////////////////////////////////
		//typedef
	private:

		//////////////////////////////////////////////
		//creation
	public:
		EMementoPointerData( const EMementoPointerData& in_src );
		EMementoPointerData( const Hubris::HSINT in_id );
		EMementoPointerData();
		~EMementoPointerData();

		//////////////////////////////////////////////
		//operator
	public:
		const EMementoPointerData& operator=( const EMementoPointerData& in_rhs );
		const Hubris::HBOOL operator==( const EMementoPointerData& in_rhs )const;
		const Hubris::HBOOL operator!=( const EMementoPointerData& in_rhs )const;

		//////////////////////////////////////////////
		//public methods
	public:
		const Hubris::HSINT IdGet()const{ return m_id; }
		Hubris::HVOID IdSet( const Hubris::HSINT in_id ){ m_id = in_id; return; }

		//////////////////////////////////////////////
		//private members
	private:
		//id is HCOMMON_INVALID on HNULL
		Hubris::HSINT m_id;

	};

	/**/
};

/**/
#endif // _E_MEMENTO_ASSIGN_POINTER_DATA_H_