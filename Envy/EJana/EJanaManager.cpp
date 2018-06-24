//file: Envy/EJana/EJanaManager.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EJana/EJanaManager.h"
#include "Envy/EJana/EJanaManagerImplementation.h"

using namespace Envy;
using namespace Hubris;


/////////////////////////////////////////////////////////////////
// creation
Envy::EJanaManager::EJanaManager( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_basePath, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary  )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM_4( m_pImplementation, EJanaManagerImplementation, in_fileSystem, in_basePath, in_extentionText, in_extentionBinary );
	HCOMMON_ASSERT( HNULL != m_pImplementation, "new failed" );

	return;
}

/**/
Envy::EJanaManager::EJanaManager( const EJanaManager& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_ASSERT( HNULL != in_src.m_pImplementation, "invalid param" );
	HCOMMON_NEW_PARAM( m_pImplementation, EJanaManagerImplementation, ( *in_src.m_pImplementation ) );
	HCOMMON_ASSERT( HNULL != m_pImplementation, "new failed" );

	return;
}

/**/
Envy::EJanaManager::~EJanaManager()
{
	HCOMMON_DELETE( m_pImplementation, EJanaManagerImplementation );

	return;
}


/////////////////////////////////////////////////////////////////
// operators
const EJanaManager& Envy::EJanaManager::operator=( const EJanaManager& in_rhs )
{
	HCOMMON_ASSERT( HNULL != in_rhs.m_pImplementation, "invalid param" );
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );

	( *m_pImplementation ) = ( *in_rhs.m_pImplementation );

	return( *this );
}

/**/
HBOOL Envy::EJanaManager::operator==( const EJanaManager& in_rhs )const
{
	HCOMMON_ASSERT( HNULL != in_rhs.m_pImplementation, "invalid param" );
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );

	return ( *m_pImplementation ) == ( *in_rhs.m_pImplementation );
}

/**/
HBOOL Envy::EJanaManager::operator!=( const EJanaManager& in_rhs )const
{
	return( !operator ==( in_rhs ) );
}

/////////////////////////////////////////////////////////////////
// public methods
/**/
HBOOL Envy::EJanaManager::JanaToTanya( const ETanya& in_jana, ETanya& out_tanya )
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );

	return m_pImplementation->JanaToTanya( in_jana, out_tanya );
}

/**/
HBOOL Envy::EJanaManager::JanaGet( const Hubris::HString& in_fileName, ETanya& out_jana )
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );

	return m_pImplementation->JanaGet( in_fileName, out_jana );
}

/**/
HSINT Envy::EJanaManager::FileCountGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );

	return m_pImplementation->FileCountGet( );
}

/**/
const Hubris::HString& Envy::EJanaManager::FileNameGet( const HSINT in_index )const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );

	return m_pImplementation->FileNameGet( in_index );
}

/**/
