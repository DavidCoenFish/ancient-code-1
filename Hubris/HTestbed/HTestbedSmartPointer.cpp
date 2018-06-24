//file: Hubris/HTestbed/HTestbedSmartPointer.cpp

#include "Hubris/HTestbed/HTestbedSmartPointer.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HSmartPointer/HSmartPointer.h"
#include "Hubris/HSmartPointer/HSmartPointerObjectBase.h"
#include "Hubris/HSmartPointer/HSmartPointerOperators.h"
#include "Hubris/HSmartPointer/HSmartPointerUtility.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// local class
/**/
class ClassTestbedSmartPointer : public HSmartPointerObjectBase< ClassTestbedSmartPointer >
{
public:
	ClassTestbedSmartPointer( const ClassTestbedSmartPointer& in_src ) 
	: m_value( HCOMMON_INVALID_INDEX )
	{
		s_constructed += 1;
		( *this ) = in_src;
		return;
	}

	ClassTestbedSmartPointer()
	: m_value( HCOMMON_INVALID_INDEX )
	{
		s_constructed += 1;
		return;
	}
	~ClassTestbedSmartPointer()
	{
		s_constructed -= 1;
		return;
	}
	static const HSINT ConstructedGet(){ return s_constructed; }

public:
	const ClassTestbedSmartPointer& operator=( const ClassTestbedSmartPointer& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_value = in_rhs.m_value;
		}
		return( *this );
	}
	HBOOL operator==( const ClassTestbedSmartPointer& in_rhs )const
	{
		HBOOL match = HTRUE;
		if( this != &in_rhs )
		{
			match &= ( m_value == in_rhs.m_value );
		}
		return match;
	}
	HBOOL operator!=( const ClassTestbedSmartPointer& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}
	
private:
	static HSINT s_constructed;

public:
	HSINT m_value;

};

HSINT ClassTestbedSmartPointer::s_constructed = 0;


//////////////////////////////////////////////////////
// static local methods
/**/
static const HBOOL LocalTestbedSmartPointer()
{
	HBOOL success = HTRUE;

	typedef HSmartPointer< ClassTestbedSmartPointer >TSmartPointer;

	TSmartPointer pointer0;

	success &= ( 0 == ClassTestbedSmartPointer::ConstructedGet() );
	success &= ( HNULL == pointer0.RawGet() );

	pointer0.Create();

	success &= ( 1 == ClassTestbedSmartPointer::ConstructedGet() );
	success &= ( 1 == pointer0->RefereceCountGet().ReferenceCountGet() );
	success &= ( HNULL != pointer0.RawGet() );

	TSmartPointer pointer1( pointer0 );
	TSmartPointer pointer2( pointer0 );

	success &= ( 1 == ClassTestbedSmartPointer::ConstructedGet() );
	success &= ( 3 == pointer0->RefereceCountGet().ReferenceCountGet() );
	success &= ( HNULL != pointer1.RawGet() );
	success &= ( HNULL != pointer2.RawGet() );

	success &= ( pointer0 == pointer1 );

	pointer1 = HNULL;
	pointer2 = HNULL;

	success &= ( pointer0 != pointer1 );
	success &= ( pointer1 == pointer2 );

	success &= ( 1 == ClassTestbedSmartPointer::ConstructedGet() );
	success &= ( 1 == pointer0->RefereceCountGet().ReferenceCountGet() );
	success &= ( HNULL == pointer1.RawGet() );
	success &= ( HNULL == pointer2.RawGet() );
	success &= ( HNULL != pointer0.RawGet() );

	pointer0.Destroy();

	success &= ( 0 == ClassTestbedSmartPointer::ConstructedGet() );
	success &= ( HNULL == pointer0.RawGet() );

	HTESTBED_VALIDATE_STATUS( "HSmartPointer", success );

	return success;
}

/**/
static const HBOOL LocalTestbedSmartPointerObjectBase()
{
	HBOOL success = HTRUE;

	HTESTBED_VALIDATE_STATUS( "HSmartPointerObjectBase", success );

	return success;
}

/**/
static const HBOOL LocalTestbedSmartPointerOperators()
{
	HBOOL success = HTRUE;

	HTESTBED_VALIDATE_STATUS( "HSmartPointerOperators", success );

	return success;
}

/**/
static const HBOOL LocalTestbedSmartPointerUtility()
{
	HBOOL success = HTRUE;

	typedef HSmartPointer< ClassTestbedSmartPointer >TSmartPointer;
	typedef HContainerArray< TSmartPointer >TArraySmartPointer;

	{
		TSmartPointer pointer0;
		pointer0.Create();
		TSmartPointer pointer1;

		pointer0->m_value = 10;

		pointer1 = HSmartPointerUtility::Copy( pointer0 );

		success &= ( HTRUE == HSmartPointerUtility::Cmp( pointer0, pointer1 ) );

		TSmartPointer pointer2;
		pointer2.Create();

		success &= ( HFALSE == HSmartPointerUtility::Cmp( pointer0, pointer2 ) );
		pointer2->m_value = 10;

		success &= ( HTRUE == HSmartPointerUtility::Cmp( pointer0, pointer2 ) );
	}


	{
		TArraySmartPointer arrayPointer;

		{
			TSmartPointer pointer0;
			pointer0.Create();
			pointer0->m_value = 5;
			arrayPointer.Insert( pointer0 );
		}
		{
			TSmartPointer pointer0;
			pointer0.Create();
			pointer0->m_value = 10;
			arrayPointer.Insert( pointer0 );
		}
		{
			TSmartPointer pointer0;
			pointer0.Create();
			pointer0->m_value = 15;
			arrayPointer.Insert( pointer0 );
		}

		TArraySmartPointer arrayPointer2 = HSmartPointerUtility::Copy( arrayPointer );

		success &= ( HTRUE == HSmartPointerUtility::Cmp( arrayPointer, arrayPointer2 ) );

		arrayPointer2[ 0 ]->m_value = 3;

		success &= ( HFALSE == HSmartPointerUtility::Cmp( arrayPointer, arrayPointer2 ) );
	}

	HTESTBED_VALIDATE_STATUS( "HSmartPointerUtility", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedSmartPointer()
{
	HTESTBED_VALIDATE_START( "TestbedSmartPointer" );
	HBOOL success = HTRUE;

	success &= LocalTestbedSmartPointer();
	success &= LocalTestbedSmartPointerObjectBase();
	success &= LocalTestbedSmartPointerOperators();
	success &= LocalTestbedSmartPointerUtility();

	return success;
}

/**/