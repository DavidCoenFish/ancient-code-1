//file: Hubris/HCommon/HCommonForEach.h
#ifndef _H_COMMON_FOR_EACH_H_
#define _H_COMMON_FOR_EACH_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

namespace Hubris
{
	//from redtribe (tom - ryan)
#define _FOREACH(IN_VAR, IN_VAR_TYPE, IN_ITER_TYPE, IN_ITER_START, IN_ITER_END) \
	if( Hubris::HBOOL _forEachCont = HTRUE )	\
		for( ; HTRUE == _forEachCont; _forEachCont = HFALSE ) \
			for( IN_ITER_TYPE _forEachIter = IN_ITER_START; IN_ITER_END != _forEachIter; ++_forEachIter ) \
				if( HFALSE == _forEachCont ) \
					break; \
				else if( HFALSE == ( _forEachCont = HFALSE ) ) \
					for (IN_VAR_TYPE& IN_VAR = ( *_forEachIter ); HFALSE == _forEachCont; _forEachCont = HTRUE )

#define HCOMMON_FOR_EACH(IN_VAR, IN_CONTAINER, IN_CONTAINER_TYPE) _FOREACH(IN_VAR, IN_CONTAINER_TYPE::TType, IN_CONTAINER_TYPE::TIterator, IN_CONTAINER.Begin(), IN_CONTAINER.End())
#define HCOMMON_FOR_EACH_CONST(IN_VAR, IN_CONTAINER, IN_CONTAINER_TYPE) _FOREACH(IN_VAR, const IN_CONTAINER_TYPE::TType, IN_CONTAINER_TYPE::TIterator, IN_CONTAINER.Begin(), IN_CONTAINER.End())

#define HCOMMON_FOR_EACH_RANGE(IN_VAR, IN_CONTAINER_TYPE, IN_ITER_START, IN_ITER_END) _FOREACH(IN_VAR, IN_CONTAINER_TYPE::TType, IN_CONTAINER_TYPE::TIterator, IN_ITER_START, IN_ITER_END)
#define HCOMMON_FOR_EACH_RANGE_CONST(IN_VAR, IN_CONTAINER_TYPE, IN_ITER_START, IN_ITER_END) _FOREACH(IN_VAR, const IN_CONTAINER_TYPE::TType, IN_CONTAINER_TYPE::TIterator, IN_ITER_START, IN_ITER_END)


//#define _FOREACH(IN_VAR, IN_VAR_TYPE, IN_ITER_TYPE, IN_ITER_START, IN_ITER_END) \
//	if(HBOOL _forEachCont = HTRUE)	\
//		for (; HTRUE == _forEachCont; _forEachCont = HFALSE) \
//			for (IN_ITER_TYPE _forEachIter = IN_ITER_START; IN_ITER_END != _forEachIter; ++_forEachIter) \
//					if(HFALSE == _forEachCont) \
//						break; \
//					else if(HFALSE == (_forEachCont = HFALSE)) \
//						for (IN_VAR_TYPE & IN_VAR = (*_forEachIter); HFALSE == _forEachCont; _forEachCont = HTRUE)
//
//#define HCOMMON_FOR_EACH(IN_VAR, IN_CONTAINER, IN_CONTAINER_TYPE) _FOREACH(IN_VAR, IN_CONTAINER_TYPE::value_type, IN_CONTAINER_TYPE::iterator, IN_CONTAINER.begin(), IN_CONTAINER.end())
//#define HCOMMON_FOR_EACH_CONST(IN_VAR, IN_CONTAINER, IN_CONTAINER_TYPE) _FOREACH(IN_VAR, const IN_CONTAINER_TYPE::value_type, IN_CONTAINER_TYPE::const_iterator, IN_CONTAINER.begin(), IN_CONTAINER.end())
//
//#define HCOMMON_FOR_EACH_RANGE(IN_VAR, IN_CONTAINER_TYPE, IN_ITER_START, IN_ITER_END) _FOREACH(IN_VAR, IN_CONTAINER_TYPE::value_type, IN_CONTAINER_TYPE::iterator, IN_ITER_START, IN_ITER_END)
//#define HCOMMON_FOR_EACH_RANGE_CONST(IN_VAR, IN_CONTAINER_TYPE, IN_ITER_START, IN_ITER_END) _FOREACH(IN_VAR, const IN_CONTAINER_TYPE::value_type, IN_CONTAINER_TYPE::const_iterator, IN_ITER_START, IN_ITER_END)

};

#endif// _H_COMMON_FOR_EACH_H_
