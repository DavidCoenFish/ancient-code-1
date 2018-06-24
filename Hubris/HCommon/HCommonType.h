//file: Hubris/HCommon/HCommonType.h
#ifndef _H_COMMON_TYPE_H_
#define _H_COMMON_TYPE_H_

namespace Hubris
{
	//we dont define or use VOID as it is defined in winnt and used to decide if other types are defined
	typedef void			HVOID;

	//sized types
	typedef unsigned char	HU8;
	typedef signed char		HS8;
	typedef unsigned short	HU16;
	typedef signed short	HS16;
	typedef unsigned int	HU32;
	typedef signed int		HS32;
	typedef float			HR32;
	typedef double			HR64;

	//native types
	typedef signed int		HSINT;
	typedef float			HREAL;
	typedef bool			HBOOL;
	//typedef std::string		HString; //changed to class, defined latter
	typedef char			HCHAR; //expected to match HString char type
};

#endif// _H_COMMON_TYPE_H_
