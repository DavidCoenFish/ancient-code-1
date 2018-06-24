//file: Hubris/HVariant/HVariantDataBase.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HVariant/HVariantDataBase.h"

#include "Hubris/HCommon/HCommonAssert.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
Hubris::HVariantDataBase::HVariantDataBase()
{
	
	return;
}

/**/
Hubris::HVariantDataBase::~HVariantDataBase()
{
	
	return;
}

/**/
HBOOL Hubris::HVariantDataBase::Cmp(const HVariantDataBase &) const 
{
	
	HCOMMON_ASSERT_ALWAYS( "base class pretend pure virtual called" );
	return false; 
}

/**/
HS32 Hubris::HVariantDataBase::TypeIndexGet() const 
{ 
	
	HCOMMON_ASSERT_ALWAYS( "base class pretend pure virtual called" );
	return HCOMMON_INVALID_INDEX; 
}

/**/