//file: Envy/EResourceIdManager/EResourceIdManager.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EResourceIdManager/EResourceIdManager.h"

#include "Envy/EResourceIdManager/EResourceIdManagerImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

///////////////////////////////////////////////////////
// creation
/**/
EResourceIdManager::EResourceIdManager( const EResourceIdManager& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, EResourceIdManagerImplementation, in_src.ImplementationGet() );
	return;
}

/**/
EResourceIdManager::EResourceIdManager( const Hubris::HSINT in_minimumResourceValue )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, EResourceIdManagerImplementation, in_minimumResourceValue );
	return;
}

/**/
EResourceIdManager::~EResourceIdManager()
{
	HCOMMON_DELETE( m_pImplementation, EResourceIdManagerImplementation );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const EResourceIdManager& EResourceIdManager::operator=( const EResourceIdManager& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		ImplementationGet() = in_rhs.ImplementationGet();
	}

	return( *this );
}

/**/
const Hubris::HBOOL EResourceIdManager::operator==( const EResourceIdManager& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( ImplementationGet() == in_rhs.ImplementationGet() );
	}

	return match;
}

/**/
const Hubris::HBOOL EResourceIdManager::operator!=( const EResourceIdManager& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID EResourceIdManager::Clear()
{
	ImplementationGet().Clear();
	return;
}

/**/
const Hubris::HSINT EResourceIdManager::ResourceIdAcquire()
{
	const HSINT resourceId = ImplementationGet().ResourceIdAcquire();
	return resourceId;
}

/**/
const Hubris::HBOOL EResourceIdManager::ResourceIdValid( const Hubris::HSINT in_resourceId )const
{
	const HBOOL valid = ImplementationGet().ResourceIdValid( in_resourceId );
	return valid;
}

/**/
Hubris::HVOID EResourceIdManager::ResourceIdRelease( const Hubris::HSINT in_resourceId )
{
	ImplementationGet().ResourceIdRelease( in_resourceId );
	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT EResourceIdManager::MinimumResourceValueGet()const
{
	const HSINT minimumResourceValue = ImplementationGet().MinimumResourceValueGet();
	return minimumResourceValue;
}

/**/
Hubris::HVOID EResourceIdManager::MinimumResourceValueSet( const Hubris::HSINT in_minimumResourceValue )
{
	ImplementationGet().MinimumResourceValueSet( in_minimumResourceValue );
	return;
}

/**/
const Hubris::HSINT EResourceIdManager::MaximumResourceValueGet()const
{
	const HSINT maximumResourceValue = ImplementationGet().MaximumResourceValueGet();
	return maximumResourceValue;
}

/**/
Hubris::HVOID EResourceIdManager::MaximumResourceValueSet( const Hubris::HSINT in_maximumResourceValue )
{
	ImplementationGet().MaximumResourceValueSet( in_maximumResourceValue );
	return;
}

/**/
const Hubris::HSINT EResourceIdManager::ResourceIdCountGet()const
{
	const HSINT count = ImplementationGet().ResourceIdCountGet();
	return count;
}

/////////////////////////////////////////////////////////////////
// private accessors
/**/
const EResourceIdManagerImplementation& EResourceIdManager::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
EResourceIdManagerImplementation& EResourceIdManager::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/

