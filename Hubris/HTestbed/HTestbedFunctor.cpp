//file: Hubris/HTestbed/HTestbedFunctor.cpp

#include "Hubris/HTestbed/HTestbedFunctor.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HFunctor/HFunctor.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// typedef
/**/

//////////////////////////////////////////////////////
// local free functions
/**/
static HBOOL LocalFunctorTest( HSINT in_index )
{
	return( 5 == in_index );
}

class TFoo
{
public:
	HBOOL bar( HSINT in_index )
	{ 
		return( 7 == in_index );
	}
};
/**/
static const HBOOL LocalTestbedFunctor()
{
	HBOOL success = HTRUE;

	{
		typedef HFunctor< HBOOL, HTYPE_LIST_1( HSINT ) >TFunctor;

		TFunctor functor0( LocalFunctorTest );
		TFoo foo;
		TFunctor functor1( foo, &TFoo::bar );


		success = ( HTRUE == functor0( 5 ) );
		success = ( HFALSE == functor0( 6 ) );
		success = ( HTRUE == functor1( 7 ) );
		success = ( HFALSE == functor1( 8 ) );
	}


	HTESTBED_VALIDATE_STATUS( "HFunctor", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions

/**/
const HBOOL TestbedFunctor()
{
	HTESTBED_VALIDATE_START( "TestbedFunctor" );
	HBOOL success = HTRUE;

	success &= LocalTestbedFunctor();

	return success;
}

/**/