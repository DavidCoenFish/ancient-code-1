//file: Envy/EMemento/EMementoCollect.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoCollect.h"

#include "Envy/EMemento/EMemento.h"
#include "Envy/EMemento/EMementoImplementation.h"
#include "Envy/EMemento/EMementoCollectPointer.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//creation
/**/
EMementoCollect::EMementoCollect( EMemento& in_memento )
: m_currentObjectStack()
, m_pCollectPointer( HNULL )
{
	HCOMMON_NEW(
		m_pCollectPointer,
		EMementoCollectPointer
		);

	HContainerUtility::PushBack( m_currentObjectStack, &( in_memento.ImplementationGet().DataStoreGet() ) );
	return;
}

/**/
EMementoCollect::~EMementoCollect()
{
	HCOMMON_DELETE(
		m_pCollectPointer,
		EMementoCollectPointer
		);

	return;
}

//////////////////////////////////////////////
//private methods
/**/
HVOID EMementoCollect::InternalMemberAdd( const Hubris::HString& in_name, const EMementoDataStore::TVariantExchange& in_data )
{
	HContainerUtility::Back( m_currentObjectStack )->DataVariantSet( in_name, in_data );
	return;
}

/**/
Hubris::HVOID EMementoCollect::InternalPointerAdd( const Hubris::HVOID* const in_pointer, const Hubris::HString& in_factoryName )
{
	const HSINT id = CollectPointerGet().PointerAdd( in_pointer );
	InternalMemberAdd( "id", id );
	if( ( EMementoImplementation::NullPointerIdGet() != id ) &&
		( HNULL != in_factoryName ) )
	{
		InternalMemberAdd( "factory", in_factoryName );
	}

	return;
}

/**/
HVOID EMementoCollect::PushChild( const Hubris::HString& in_name )
{
	EMementoDataStore& child = HContainerUtility::Back( m_currentObjectStack )->ChildAdd( in_name );
	HContainerUtility::PushBack( m_currentObjectStack, &child );
	return;
}

/**/
HVOID EMementoCollect::PopChild()
{
	HContainerUtility::PopBack( m_currentObjectStack );
	return;
}

/**/
HVOID EMementoCollect::SeedEmptyChildArray( const Hubris::HString& in_name )
{
	HContainerUtility::Back( m_currentObjectStack )->ChildArrayEmptyAdd( in_name );
	return;
}

/**/
HVOID EMementoCollect::PushArrayChild( const Hubris::HString& in_name )
{
	EMementoDataStore& child = HContainerUtility::Back( m_currentObjectStack )->ChildArrayAppend( in_name );
	HContainerUtility::PushBack( m_currentObjectStack, &child );
	return;
}

//////////////////////////////////////////////
//private accessors
/**/
const EMementoCollectPointer& EMementoCollect::CollectPointerGet()const
{
	HCOMMON_ASSERT( HNULL != m_pCollectPointer, "invalid member" );
	return( *m_pCollectPointer );
}

/**/
EMementoCollectPointer& EMementoCollect::CollectPointerGet()
{
	HCOMMON_ASSERT( HNULL != m_pCollectPointer, "invalid member" );
	return( *m_pCollectPointer );
}

/**/
