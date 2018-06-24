//file: Envy/EMemento/EMementoCollectPointer.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoCollectPointer.h"
#include "Envy/EMemento/EMementoImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//creation
/**/
EMementoCollectPointer::EMementoCollectPointer()
: m_freeId( 0 )
, m_treePointerId()
//, m_treeIdOwnedPointers()
{
	return;
}

/**/
EMementoCollectPointer::~EMementoCollectPointer()
{
	return;
}

//////////////////////////////////////////////
//public methods
/**/
const Hubris::HSINT EMementoCollectPointer::PointerAdd( 
	const Hubris::HVOID* const in_pPointer
	)
{
	if( HNULL == in_pPointer )
	{
		return EMementoImplementation::NullPointerIdGet();
	}

	TTreeVoidSint::TIterator iterator = m_treePointerId.Find( in_pPointer );
	HSINT foundId = HCOMMON_INVALID_INDEX;
	if( iterator != m_treePointerId.End() )
	{
		foundId = ( *iterator );

		//TTreeSintPairDataStoreString::TIterator iteratorOwner = m_treeIdOwnedPointers.Find( foundId );
		//if( iteratorOwner != m_treeIdOwnedPointers.End() )
		//{
		//	EMementoDataStoreVariant variant = ( *iteratorOwner ).m_first->DataVariantGet( ( *iteratorOwner ).m_second );
		//	variant.ValueGet< EMementoPointerDataOwner >().ReferencedSet( HTRUE );
		//	( *iteratorOwner ).m_first->DataVariantSet( ( *iteratorOwner ).m_second, variant );
		//}
	}
	else
	{
		foundId = m_freeId;
		m_freeId += 1;

		m_treePointerId.Insert( in_pPointer, foundId );
	}

	return foundId;
}

/**
const Hubris::HSINT EMementoCollectPointer::OwnedPointerAdd( 
	Hubris::HBOOL& out_alreadyReferenced,
	const Hubris::HVOID* const in_pPointer,
	EMementoDataStore& in_dataStore, 
	const Hubris::HString& in_name
	)
{
	out_alreadyReferenced = HFALSE;
	if( HNULL == in_pPointer )
	{
		return EMementoPointerData::NullPointerIdGet();
	}

	TTreeVoidSint::TIterator iterator = m_treePointerId.Find( in_pPointer );
	HSINT foundId = HCOMMON_INVALID_INDEX;
	if( iterator != m_treePointerId.End() )
	{
		foundId = ( *iterator );

		m_treeIdOwnedPointers.Insert( foundId, TPairDataStoreString( &in_dataStore, in_name ) );

		out_alreadyReferenced = HTRUE;
		return( foundId );
	}
	else
	{
		foundId = m_freeId;
		m_freeId += 1;
		m_treePointerId.Insert( in_pPointer, foundId );
	}

	if( m_treeIdOwnedPointers.End() != m_treeIdOwnedPointers.Find( foundId ) )
	{
		HCOMMON_ASSERT_ALWAYS( "owned pointer added to mememento multiple times" );
	}

	m_treeIdOwnedPointers.Insert( foundId, TPairDataStoreString( &in_dataStore, in_name ) );

	return foundId;
}

/**/
