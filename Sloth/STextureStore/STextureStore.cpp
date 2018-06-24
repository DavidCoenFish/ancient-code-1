//file: Sloth/STextureStore/STextureStore.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/STextureStore/STextureStore.h"

#include "Sloth/STextureStore/STextureStoreImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
STextureStore::STextureStore( const STextureStore& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, STextureStoreImplementation, in_src.ImplementationGet() );
	return;
}

/**/
STextureStore::STextureStore()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, STextureStoreImplementation );
	return;
}

/**/
STextureStore::~STextureStore()
{
	HCOMMON_DELETE( m_pImplementation, STextureStoreImplementation );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const STextureStore& STextureStore::operator=( const STextureStore& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
Hubris::HBOOL STextureStore::operator==( const STextureStore& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL STextureStore::operator!=( const STextureStore& in_rhs )const
{
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

///////////////////////////////////////////////////////
// private accessors
/**/
const STextureStoreImplementation& STextureStore::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
STextureStoreImplementation& STextureStore::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/