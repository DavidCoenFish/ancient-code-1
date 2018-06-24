//file: Envy/ETestbed/ETestbedResourceIdManager.cpp

#include "Envy/ETestbed/ETestbedResourceIdManager.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Envy;
using namespace Hubris;

//////////////////////////////////////////////////
// local free functions
/**/
static const Hubris::HBOOL LocalTestbedResourceIdManager()
{
	HBOOL success = HTRUE;

	{
		EResourceIdManager resourceIdManager0;
		resourceIdManager0.ResourceIdAcquire();
		resourceIdManager0.ResourceIdAcquire();
		const EResourceIdManager resourceIdManager1( resourceIdManager0 );
		const EResourceIdManager resourceIdManager2 = resourceIdManager0;
		const EResourceIdManager resourceIdManager3;

		success &= ( resourceIdManager0 == resourceIdManager1 );
		success &= ( resourceIdManager1 == resourceIdManager0 );

		success &= ( resourceIdManager0 == resourceIdManager2 );
		success &= ( resourceIdManager2 == resourceIdManager0 );

		success &= ( resourceIdManager0 != resourceIdManager3 );
		success &= ( resourceIdManager3 != resourceIdManager0 );
	}

	//	const Hubris::HSINT ResourceIdAcquire();
	//	Hubris::HVOID ResourceIdRelease( const Hubris::HSINT in_resourceId );

	//	const Hubris::HSINT MinimumResourceValueGet()const{ return m_minimumResourceValue; }
	//	Hubris::HVOID MinimumResourceValueSet( const Hubris::HSINT in_minimumResourceValue ){ m_minimumResourceValue = in_minimumResourceValue; return; }

	{
		EResourceIdManager resourceIdManager0( 100 );

		success &= ( 100 == resourceIdManager0.MinimumResourceValueGet() );
		resourceIdManager0.MinimumResourceValueSet( 200 );
		success &= ( 200 == resourceIdManager0.MinimumResourceValueGet() );
		success &= ( 200 == resourceIdManager0.ResourceIdAcquire() );
		success &= ( 201 == resourceIdManager0.ResourceIdAcquire() );
		success &= ( 202 == resourceIdManager0.ResourceIdAcquire() );
		success &= ( 203 == resourceIdManager0.ResourceIdAcquire() );
		resourceIdManager0.ResourceIdRelease( 200 );
		success &= ( 200 == resourceIdManager0.ResourceIdAcquire() );
		resourceIdManager0.ResourceIdRelease( 200 );
		resourceIdManager0.ResourceIdRelease( 201 );
		resourceIdManager0.ResourceIdRelease( 202 );
		resourceIdManager0.ResourceIdRelease( 203 );
		resourceIdManager0.ResourceIdRelease( 204 );

		success &= ( 200 == resourceIdManager0.ResourceIdAcquire() );
		success &= ( 201 == resourceIdManager0.ResourceIdAcquire() );

		for( HSINT index = 0; index < 100; ++index )
		{
			resourceIdManager0.ResourceIdAcquire();
		}
		resourceIdManager0.ResourceIdRelease( 260 );
		success &= ( 260 == resourceIdManager0.ResourceIdAcquire() );
		success &= ( 302 == resourceIdManager0.ResourceIdAcquire() );
	}

	ETESTBED_VALIDATE_STATUS( "EResourceIdManager", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedResourceIdManager()
{
	HBOOL success = HTRUE;

	ETESTBED_VALIDATE_START( "TestbedResourceIdManager" );

	success &= LocalTestbedResourceIdManager();

	return success;
}

/**/