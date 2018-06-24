//file: Envy/ETanya/ETanya.h
#ifndef _E_TANYA_H_
#define _E_TANYA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/ETanya/ETanyaVariant.h"
#include "Envy/ERecursiveDataStore/ERecursiveDataStore.h"

namespace Envy
{
	///////////////////////////////////////////////////////
	// class
	/*
		a xml like document,
		see ETanyaUtility for Load/ Save
	*/

	typedef ERecursiveDataStore< ETanyaVariant >ETanya;

	/**/
};

#endif // _E_TANYA_H_