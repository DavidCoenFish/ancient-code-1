//file: Hubris/HType/HTypeNone.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HType/HTypeNone.h"

#include "Hubris/HCommon/HCommonDefine.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////
// creation
/**/
HTypeNone::HTypeNone( const HTypeNone& )
{
	return;
}

/**/
HTypeNone::HTypeNone()
{
	return;
}

/**/
HTypeNone::~HTypeNone()
{
	return;
}

///////////////////////////////////
// operators
/**/
const HTypeNone& HTypeNone::operator=( const HTypeNone& )
{
	return( *this );
}

/**/
HBOOL HTypeNone::operator==( const HTypeNone& )const
{
	return HTRUE;
}

/**/
HBOOL HTypeNone::operator!=( const HTypeNone& )const
{
	return HFALSE;
}

/**/
