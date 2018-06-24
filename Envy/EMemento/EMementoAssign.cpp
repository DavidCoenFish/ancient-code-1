//file: Envy/EMemento/EMementoAssign.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoAssign.h"

#include "Envy/EMemento/EMemento.h"
#include "Envy/EMemento/EMementoAssignPointer.h"
#include "Envy/EMemento/EMementoImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//creation
/**/
EMementoAssign::EMementoAssign( const EMemento& in_memento )
: m_currentObjectStack()
, m_pAssignPointer( HNULL )
{
	HCOMMON_NEW(
		m_pAssignPointer,
		EMementoAssignPointer
		);

	HContainerUtility::PushBack( m_currentObjectStack, &( in_memento.ImplementationGet().DataStoreGet() ) );

	AssignPointerGet().CreationDataRefresh( in_memento.ImplementationGet().DataStoreGet() );

	return;
}

/**/
EMementoAssign::~EMementoAssign()
{
	HCOMMON_DELETE(
		m_pAssignPointer,
		EMementoAssignPointer
		);

	return;
}

//////////////////////////////////////////////
//private methods
/**/
HBOOL EMementoAssign::InternalMemberGet( const Hubris::HString& in_name, EMementoDataStore::TVariantExchange& out_data )const
{
	if( HFALSE == HContainerUtility::Back( m_currentObjectStack )->DataVariantTest( in_name ) )
	{
		return HFALSE;
	}

	out_data = HContainerUtility::Back( m_currentObjectStack )->DataVariantGet( in_name );

	return HTRUE;
}

/**/
const Hubris::HSINT EMementoAssign::InternalPointerIdGet()const
{
	EMementoDataStoreVariant idVariant = HContainerUtility::Back( m_currentObjectStack )->DataVariantGet( "id" );

	if( HFALSE == idVariant.TypeTest< HSINT >() )
	{
		return EMementoImplementation::NullPointerIdGet();
	}

	const HSINT id = idVariant.ValueGet< HSINT >();
	return id;
}

/**/
HBOOL EMementoAssign::PushChild( const Hubris::HString& in_name )const
{
	if( HFALSE == HContainerUtility::Back( m_currentObjectStack )->ChildTest( in_name ) )
	{
		return HFALSE;
	}

	const EMementoDataStore* pDataStore = &( HContainerUtility::Back( m_currentObjectStack )->ChildGet( in_name ) );
	HContainerUtility::PushBack( m_currentObjectStack, pDataStore );

	return HTRUE;
}

/**/
HVOID EMementoAssign::PopChild()const
{
	HContainerUtility::PopBack( m_currentObjectStack );
	return;
}

/**/
Hubris::HSINT EMementoAssign::ArrayChildCountGet( const Hubris::HString& in_name )const
{
	if( HFALSE == HContainerUtility::Back( m_currentObjectStack )->ChildArrayTest( in_name ) )
	{
		return HCOMMON_INVALID_INDEX;
	}

	return HContainerUtility::Back( m_currentObjectStack )->ChildArrayCountGet( in_name );
}

/**/
HVOID EMementoAssign::ArrayChildPush( const Hubris::HString& in_name, const Hubris::HSINT in_index )const
{
	const EMementoDataStore* pDataStore = &( HContainerUtility::Back( m_currentObjectStack )->ChildArrayGet( in_name, in_index ) );

	HContainerUtility::PushBack( m_currentObjectStack, pDataStore );

	return;
}

//////////////////////////////////////////////
//private accessors
/**/
EMementoAssignPointer& EMementoAssign::AssignPointerGet()const
{
	HCOMMON_ASSERT( HNULL != m_pAssignPointer, "invalid member" );
	return( *m_pAssignPointer );
}

/**
EMementoAssignPointer& EMementoAssign::AssignPointerGet()
{
	HCOMMON_ASSERT( HNULL != m_pAssignPointer, "invalid member" );
	return( *m_pAssignPointer );
}

/**/
