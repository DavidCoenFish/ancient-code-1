//file: Envy/EMemento/EMementoAssignPointer.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoAssignPointer.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//typedef
/**/
typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HString >TTreeSintString;
typedef Hubris::HContainerTree< Hubris::HSINT, Hubris::HVOID* >TTreeSintPointer;
typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

//////////////////////////////////////////////
//static local methods
/*
<factory TYPE="HString">TestClassPointer</factory>
<id TYPE="HS32">0</id>
*/
static Hubris::HVOID LocalRecurseDataStorePownedDataGet( 
	TTreeSintString& in_out_treeIdFactoryName,
	const EMementoDataStore& in_mementoData
	)
{
	const EMementoDataStoreVariant dataId = in_mementoData.DataVariantGet( "id" );

	if( HFALSE == dataId.TypeTest< HSINT >() )
	{
		return;
	}

	// NULL pointers have no factory
	const HSINT id = dataId.ValueGet< HSINT >();
	if( id == EMementoImplementation::NullPointerIdGet() )
	{
		return;
	}

	const EMementoDataStoreVariant dataFactory = in_mementoData.DataVariantGet( "factory" );
	if( HFALSE == dataFactory.TypeTest< HString >() )
	{
		return;
	}

	in_out_treeIdFactoryName.Insert( id, dataFactory.ValueGet< HString >() );

	return;
}

/**/
static Hubris::HVOID LocalRecurseDataStore( 
	TTreeSintString& in_out_treeIdFactoryName,
	const EMementoDataStore& in_mementoData
	)
{
	TArrayString arrayDataName;
	TArrayString arrayChildName;
	TArrayString arrayChildArrayName;

	in_mementoData.NameListGet( arrayDataName, arrayChildName, arrayChildArrayName );

	HCOMMON_FOR_EACH( childName, arrayChildName, TArrayString )
	{
		if( "_POWNED" == childName )
		{
			LocalRecurseDataStorePownedDataGet(
				in_out_treeIdFactoryName,
				in_mementoData.ChildGet( childName )
				);
		}
		else
		{
			LocalRecurseDataStore(
				in_out_treeIdFactoryName,
				in_mementoData.ChildGet( childName )
				);
		}
	}

	HCOMMON_FOR_EACH( childArrayName, arrayChildArrayName, TArrayString )
	{
		const HSINT count = in_mementoData.ChildArrayCountGet( childArrayName );
		for( HSINT index = 0; index < count; ++index )
		{
			LocalRecurseDataStore(
				in_out_treeIdFactoryName,
				in_mementoData.ChildArrayGet( childArrayName, index )
				);
		}
	}

	return;
}

//////////////////////////////////////////////
//creation
/**/
EMementoAssignPointer::EMementoAssignPointer()
: m_treeIdFactoryName()
, m_treeIdObject()
{
	return;
}

/**/
EMementoAssignPointer::~EMementoAssignPointer()
{
	return;
}

//////////////////////////////////////////////
//public methods
/**/
Hubris::HVOID EMementoAssignPointer::CreationDataRefresh( const EMementoDataStore& in_mementoData )
{
	m_treeIdFactoryName.Clear();
	LocalRecurseDataStore( 
		m_treeIdFactoryName,
		in_mementoData
		);

	return;
}

/**/
Hubris::HVOID EMementoAssignPointer::CreatedClear()
{
	m_treeIdObject.Clear();
	return;
}

/**/
