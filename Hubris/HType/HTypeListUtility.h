//file: Hubris/HType/HTypeListUtility.h
#ifndef _H_TYPE_LIST_UTIL_H_
#define _H_TYPE_LIST_UTIL_H_


#include "Hubris/HType/HTypeNone.h"

namespace Hubris
{
	//concept taken from loki
	template<class IN_CLASS_A, class IN_CLASS_B> class HTypeList;

	//==================================================================
	// classes match
	//==================================================================
	//result == true if the given classes match
	template<class IN_CLASS_A, class IN_CLASS_B> 
	struct HTypeListUtilMatch
	{
		enum TEnum 
		{
			result = false
		};
	};

	template<class IN_CLASS_A> 
	struct HTypeListUtilMatch<IN_CLASS_A, IN_CLASS_A>
	{
		enum TEnum 
		{
			result = true
		};
	};

	//==================================================================
	// typelist contains type
	//==================================================================
	//result == true if the given class is in the typelist
	template<class IN_TYPE_LIST, class IN_CLASS> struct HTypeListUtilContains;

	template<class IN_CLASS> 
	struct HTypeListUtilContains<HTypeNone, IN_CLASS>
	{
		enum TEnum
		{
			result = HFALSE
		};
	};

	template<class IN_CLASS, class IN_TYPE_LIST_TAIL> 
	struct HTypeListUtilContains<HTypeList<IN_CLASS, IN_TYPE_LIST_TAIL>, IN_CLASS>
	{
		enum TEnum
		{
			result = HTRUE
		};
	};

	template<class IN_TYPE_LIST_HEAD, class IN_TYPE_LIST_TAIL, class IN_CLASS> 
	struct HTypeListUtilContains<HTypeList<IN_TYPE_LIST_HEAD, IN_TYPE_LIST_TAIL>, IN_CLASS>
	{
		enum TEnum
		{
			result = HTypeListUtilContains<IN_TYPE_LIST_TAIL, IN_CLASS>::result
		};
	};

	//==================================================================
	// find index of type in typelist, HCOMMON_INVALID_INDEX if not found
	//==================================================================
	template<class IN_TYPE_LIST, class IN_CLASS> struct HTypeListUtilIndexOf;

	template< class IN_CLASS > 
	struct HTypeListUtilIndexOf< HTypeNone, IN_CLASS >
	{
		enum TEnum
		{
			index = HCOMMON_INVALID_INDEX
		};
	};

	template< class IN_CLASS, class IN_TYPE_LIST_TAIL > 
	struct HTypeListUtilIndexOf< HTypeList< IN_CLASS, IN_TYPE_LIST_TAIL >, IN_CLASS >
	{
		enum TEnum
		{
			index = 0
		};
	};

	template< class IN_TYPE_LIST_HEAD, class IN_TYPE_LIST_TAIL, class IN_CLASS > 
	struct HTypeListUtilIndexOf< HTypeList< IN_TYPE_LIST_HEAD, IN_TYPE_LIST_TAIL >, IN_CLASS >
	{
	private:
		enum
		{
			temp = HTypeListUtilIndexOf< IN_TYPE_LIST_TAIL, IN_CLASS >::index
		};
	public:
		enum TEnum
		{
			index = ( ( temp == HCOMMON_INVALID_INDEX ) ? HCOMMON_INVALID_INDEX : 1 + temp )
		};
	};

	//==================================================================
	// get TYPE at index, Type is HTypeNone on index out of range
	//==================================================================
	template<class IN_TYPE_LIST, const HS32 IN_INDEX> struct HTypeListUtilIndexType;

	template<HS32 IN_INDEX> 
	struct HTypeListUtilIndexType<HTypeNone, IN_INDEX>
	{
		typedef HTypeNone Type;
	};

	template<class IN_TYPE_HEAD, class IN_TYPE_TAIL> 
	struct HTypeListUtilIndexType<HTypeList<IN_TYPE_HEAD, IN_TYPE_TAIL>, 0>
	{
		typedef IN_TYPE_HEAD Type;
	};

	template<class IN_TYPE_HEAD, class IN_TYPE_TAIL, const HS32 IN_INDEX> 
	struct HTypeListUtilIndexType<HTypeList<IN_TYPE_HEAD, IN_TYPE_TAIL>, IN_INDEX>
	{
		typedef typename HTypeListUtilIndexType<IN_TYPE_TAIL, IN_INDEX - 1>::Type Type;
	};

	//==================================================================
	// get Count of types in typelist
	//==================================================================
	template<class IN_TYPE_LIST> struct HTypeListUtilCount;

	template<> 
	struct HTypeListUtilCount< HTypeNone >
	{
		enum TEnum
		{
			count = 0
		};
	};

	template<> 
	struct HTypeListUtilCount< HTypeList< HTypeNone, HTypeNone > >
	{
		enum TEnum
		{
			count = 0
		};
	};

	template< class IN_TYPE_HEAD, class IN_TYPE_TAIL > 
	struct HTypeListUtilCount<HTypeList< IN_TYPE_HEAD, IN_TYPE_TAIL > >
	{
		enum TEnum
		{
			count = HTypeListUtilCount<IN_TYPE_TAIL>::count + 1
		};
	};

};

#endif // _H_TYPE_LIST_UTIL_H_