//file: Envy/EMemento/EMementoAssignPointer.h
#ifndef _E_MEMENTO_ASSIGN_POINTER_H_
#define _E_MEMENTO_ASSIGN_POINTER_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Envy/EMemento/EMementoDataStore.h"
#include "Envy/EMemento/EMementoFactory.h"
#include "Envy/EMemento/EMementoImplementation.h"

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;

	///////////////////////////////////////////////////////
	// class
	/**/
	class EMementoAssignPointer
	{
		//////////////////////////////////////////////
		//typedef
	private:
		typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HString >TTreeSintString;
		typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HVOID* >TTreeSintPointer;

		//////////////////////////////////////////////
		//creation
	public:
		EMementoAssignPointer();
		~EMementoAssignPointer();

		//////////////////////////////////////////////
		//disabled
	private:
		EMementoAssignPointer( const EMementoAssignPointer& in_src );
		const EMementoAssignPointer& operator=( const EMementoAssignPointer& in_rhs );

		//////////////////////////////////////////////
		//public methods
	public:
		Hubris::HVOID CreationDataRefresh( const EMementoDataStore& in_mementoData ); //scan through memento to gather class name to owner
		Hubris::HVOID CreatedClear();//clear record of created objects for owned poiners, so if queried, create new objects. assum ownership has been taken, ie, leak

		template< typename IN_TYPE >
		IN_TYPE* const PointerGet( const Hubris::HSINT in_id );

		//////////////////////////////////////////////
		//private members
	private:
		TTreeSintString m_treeIdFactoryName;
		TTreeSintPointer m_treeIdObject;

	};

	template< typename IN_TYPE >
	IN_TYPE* const EMementoAssignPointer::PointerGet( const Hubris::HSINT in_id )
	{
		if( in_id == EMementoImplementation::NullPointerIdGet() )
		{
			return HNULL;
		}

		TTreeSintPointer::TIterator iteratorPointer = m_treeIdObject.Find( in_id );
		if( iteratorPointer != m_treeIdObject.End() )
		{
			return( ( IN_TYPE* const )( *iteratorPointer ) );
		}


		TTreeSintString::TIterator iteratorFactory = m_treeIdFactoryName.Find( in_id );
		if( iteratorFactory == m_treeIdFactoryName.End() )
		{
			return HNULL;
		}

		IN_TYPE* const pData = EMementoFactory< IN_TYPE >::CreateObject( ( *iteratorFactory ) );
		m_treeIdObject.Insert( in_id, pData );

		return pData;
	}


	/**/
};

/**/
#endif // _E_MEMENTO_ASSIGN_POINTER_H_