//file: Envy/EJana/EJana.h
#ifndef _E_JANA_H_
#define _E_JANA_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Envy/ETanya/ETanya.h"

namespace Envy
{
	/*
		ETanya is a theoretical class, it actually is a ETanya with a few more variables to assist making it derivable
		like DeriveName, ParentName, ParentFile

		any ETanya Document can be set as avaliable for derivation, or to inherit from a file::class

		a manager is set up with the base path, and can be requested to refresh all jana documents, or to load a jana document
		which yeilds a tanya document, which can be flaterned to a normal tanya document, inheretance information removed
	*/

	typedef ETanya EJana;

	/**/
};

#endif // _E_JANA_H_