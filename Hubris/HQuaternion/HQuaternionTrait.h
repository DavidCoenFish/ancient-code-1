//file: Hubris/HQuaternion/HQuaternionTrait.h
#ifndef _H_QUATERNION_TRAIT_H_
#define _H_QUATERNION_TRAIT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HTrait/HTraitEmpty.h"
#include "Hubris/HTrait/HTraitName.h"

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////
	// forward definitions
	/**/
	template< typename IN_TYPE >class HQuaternion;
	typedef HQuaternion< HREAL >HQuaternionREAL;

	///////////////////////////////////////////////////////
	// HTraitEmpty
	/**/
	HTRAIT_EMPTY_HEADER( HQuaternionREAL );

	///////////////////////////////////////////////////////
	// HTraitName
	/**/
	HTYPE_NAME_HEADER( HQuaternionREAL );
};

#endif //_H_QUATERNION_TRAIT_H_