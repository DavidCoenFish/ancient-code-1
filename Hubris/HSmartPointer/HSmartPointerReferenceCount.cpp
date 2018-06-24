//file: Hubris/HSmartPointer/HSmartPointerReferenceCount.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HSmartPointer/HSmartPointerReferenceCount.h"

#include "Hubris/HCommon/HCommonAssert.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
Hubris::HSmartPointerReferenceCount::HSmartPointerReferenceCount() :
	m_referenceCount( 0 )
{
	return;
}

/**/
Hubris::HSmartPointerReferenceCount::~HSmartPointerReferenceCount()
{
	HCOMMON_ASSERT( 0 == m_referenceCount, "non zero reference count object being deleted" );
	return;
}

/**/
HVOID Hubris::HSmartPointerReferenceCount::Increment() const
{
	m_referenceCount += 1;

	return;
}

/**/
HVOID Hubris::HSmartPointerReferenceCount::Decrement() const
{
	m_referenceCount -= 1;

	return;
}

/**/
HBOOL Hubris::HSmartPointerReferenceCount::ZeroReferenceTest() const
{
	return( 0 == m_referenceCount );
}

/**/