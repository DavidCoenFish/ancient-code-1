//file: Envy/EMemento/EMementoCollectPointer.h
#ifndef _E_MEMENTO_COLLECT_POINTER_H_
#define _E_MEMENTO_COLLECT_POINTER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HType_Export.h >

#include "Envy/EMemento/EMementoDataStore.h"

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;

	///////////////////////////////////////////////////////
	// class
	/**/
	class EMementoCollectPointer
	{
		//////////////////////////////////////////////
		//typedef
	private:
		typedef Hubris::HContainerTree< const Hubris::HVOID*, Hubris::HSINT >TTreeVoidSint;
		//typedef Hubris::HContainerPair< EMementoDataStore*, Hubris::HString >TPairDataStoreString;
		//typedef Hubris::HContainerTree< Hubris::HSINT, TPairDataStoreString >TTreeSintPairDataStoreString;

		//////////////////////////////////////////////
		//creation
	public:
		EMementoCollectPointer();
		~EMementoCollectPointer();

		//////////////////////////////////////////////
		//disabled
	private:
		EMementoCollectPointer( const EMementoCollectPointer& in_src );
		const EMementoCollectPointer& operator=( const EMementoCollectPointer& in_rhs );

		//////////////////////////////////////////////
		//public methods
	public:
		const Hubris::HSINT PointerAdd( 
			const Hubris::HVOID* const in_pPointer
			);

		//const Hubris::HSINT OwnedPointerAdd( 
			//Hubris::HBOOL& out_alreadyReferenced,
			//const Hubris::HVOID* const in_pPointer,
			//EMementoDataStore& in_dataStore, //could pass a EMementoPointerDataOwner reference and trust it not to move...
			//const Hubris::HString& in_name
			//);

		//////////////////////////////////////////////
		//private members
	private:
		Hubris::HSINT m_freeId;
		TTreeVoidSint m_treePointerId;
		//keep track of owned pointers, want to let them know if they are referenced
		//TTreeSintPairDataStoreString m_treeIdOwnedPointers;

		/**/
	};

	/**/
};

/**/
#endif // _E_MEMENTO_COLLECT_H_