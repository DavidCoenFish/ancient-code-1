//file: Hubris/HType/HTypeIndex.h
#ifndef _H_TYPE_INDEX_H_
#define _H_TYPE_INDEX_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	/////////////////////////////////////////////////
	// free function
	/**/
	HS32 HTypeIndexUniqueGet();

	/////////////////////////////////////////////////
	// class
	//  make a template to provide a unique id for a type in a translation unit

	template< typename IN_TYPE >struct HTypeIndex
	{
	public:
		static HSINT UniqueTypeIndexGet();

	private:
		////////////////////////////////////////////////
		// disabled

		~HTypeIndex();

	private:
		static HSINT s_typeIndex;

	};

	/////////////////////////////////////////////////
	// template implementation

	/**/
	template< typename IN_TYPE > 
	HSINT HTypeIndex< IN_TYPE >::s_typeIndex = -1;

	/**/
	template< typename IN_TYPE > 
	HSINT HTypeIndex< IN_TYPE >::UniqueTypeIndexGet()
	{
		if( -1 == s_typeIndex )
		{
			s_typeIndex = HTypeIndexUniqueGet();
		}

		return s_typeIndex;
	}

	/**/
};

#endif // _H_TYPE_INDEX_H_