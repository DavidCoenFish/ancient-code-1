//file: Envy/ETestbed/ETestbed_Import.h
#ifndef _E_TESTBED_IMPORT_E_
#define _E_TESTBED_IMPORT_E_

#include< Hubris/HBuffer/HBuffer_Export.h >
#include< Hubris/HBufferParse/HBufferParse_Export.h >
#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HFileSystem/HFileSystem_Export.h >
#include< Hubris/HFunctor/HFunctor_Export.h >
#include< Hubris/HMath/HMath_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >
#include< Hubris/HQuaternion/HQuaternion_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >
#include< Hubris/HString/HString_Export.h >
#include< Hubris/HTrait/HTrait_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

#include< Envy/ECommandLine/ECommandLine_Export.h >
#include< Envy/EDataStore/EDataStore_Export.h >
#include< Envy/EJana/EJana_Export.h >
#include< Envy/EMemento/EMemento_Export.h >
#include< Envy/ERecursiveDataStore/ERecursiveDataStore_Export.h >
#include< Envy/EResourceIdManager/EResourceIdManager_Export.h >
#include< Envy/EStateMachine/EStateMachine_Export.h >
#include< Envy/EStateMachineSimple/EStateMachineSimple_Export.h >
#include< Envy/EStringTable/EStringTable_Export.h >
#include< Envy/ETanya/ETanya_Export.h >

#include <stdio.h>

#define ETESTBED_VALIDATE_START( COMPONENT_NAME ) printf( "  %s\n", COMPONENT_NAME )
#define ETESTBED_VALIDATE_STATUS( MESSAGE, STATUS ) if( HTRUE != STATUS ) printf( "    <FAILED> %s\n", MESSAGE )

#endif // _E_TESTBED_IMPORT_E_