//file: Envy/EMemento/EMementoDataStore.h
#ifndef _E_MEMENTO_DATA_STORE_H_
#define _E_MEMENTO_DATA_STORE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

//#include "Envy/EMemento/EMementoPointerData.h"
//#include "Envy/EMemento/EMementoPointerDataOwner.h"

#include "Envy/ERecursiveDataStore/ERecursiveDataStore.h"

namespace Hubris
{
	class HString;
	template< typename IN_TYPE >class HContainerArray;
}

namespace Envy
{
	/**/
	typedef HTYPE_LIST_21(
		Hubris::HU8,											
		Hubris::HS8,											
		Hubris::HU16,										
		Hubris::HS16,										
		Hubris::HU32,										
		Hubris::HS32,										
		Hubris::HR32,
		Hubris::HR64,
		Hubris::HBOOL,										
		Hubris::HCHAR,	

		Hubris::HString,

		Hubris::HContainerArray< Hubris::HBOOL >,
		Hubris::HContainerArray< Hubris::HU8 >,
		Hubris::HContainerArray< Hubris::HS8 >,
		Hubris::HContainerArray< Hubris::HU16 >,
		Hubris::HContainerArray< Hubris::HS16 >,
		Hubris::HContainerArray< Hubris::HU32 >,
		Hubris::HContainerArray< Hubris::HS32 >,
		Hubris::HContainerArray< Hubris::HR32 >,
		Hubris::HContainerArray< Hubris::HR64 >,
		Hubris::HContainerArray< Hubris::HCHAR >

		//EMementoPointerData,
		//EMementoPointerDataOwner

	) EMementoDataStoreTypeList;

	HVARIANT_DEFINITION( EMementoDataStoreVariant, EMementoDataStoreTypeList );

	typedef ERecursiveDataStore< EMementoDataStoreVariant > EMementoDataStore;

	/**/
};

/**/
#endif // _E_MEMENTO_DATA_STORE_H_