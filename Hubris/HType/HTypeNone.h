//file: Hubris/HType/HTypeNone.h
#ifndef _H_TYPE_NONE_H_
#define _H_TYPE_NONE_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	//an empty class to help typelist
	class HTypeNone
	{
		///////////////////////////////////
		// creation
	public:
		HTypeNone( const HTypeNone& in_src );
		HTypeNone();
		~HTypeNone();

		///////////////////////////////////
		// operators
	public:
		const HTypeNone& operator=( const HTypeNone& in_rhs );
		HBOOL operator==( const HTypeNone& in_rhs )const;
		HBOOL operator!=( const HTypeNone& in_rhs )const;

	};

	/**/
};

#endif // _H_TYPE_NONE_H_