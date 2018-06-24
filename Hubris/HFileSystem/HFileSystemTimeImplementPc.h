//file: Hubris/HFileSystem/HFileSystemTimeImplementPc.h
#ifndef _H_FILE_SYSTEM_TIME_IMPLEMENT_H_
#define _H_FILE_SYSTEM_TIME_IMPLEMENT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

/*
	file path as object
*/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class HString;

	///////////////////////////////////////////////////////////
	// class
	/*
		store a time_t on presumption of use under windows, 

		from help://MS.VSCC.2003/MS.MSDNQTR.2003FEB.1033/vclib/html/_crt_time.htm
		A call to time or _time64 can fail, however, if the date passed to the function is: 
		Before midnight, January 1, 1970. 
		After 19:14:07, January 18, 2038, UTC (using time and time_t). 
		After 23:59:59, December 31, 3000, UTC (using _time64 and __time64_t).

		time_t of -1 is not a valid time.
		treat uninitialised time as zero sec from 1970 or as invalid data.
		treat error or uninitialised time as zer sec from 1970
		*/
	class HFileSystemTimeImplementPc
	{
		///////////////////////////////////////////////////////////
		// creation
	public:
		HFileSystemTimeImplementPc( const HFileSystemTimeImplementPc& in_src );
		HFileSystemTimeImplementPc( const time_t in_time = 0 );
		~HFileSystemTimeImplementPc();

		///////////////////////////////////////////////////////////
		// operators

		const HFileSystemTimeImplementPc& operator=( const HFileSystemTimeImplementPc& in_rhs );
		HBOOL operator==( const HFileSystemTimeImplementPc& in_rhs ) const;
		HBOOL operator!=( const HFileSystemTimeImplementPc& in_rhs ) const;

		HBOOL operator<( const HFileSystemTimeImplementPc& in_rhs )const;
		HBOOL operator<=( const HFileSystemTimeImplementPc& in_rhs )const;
		HBOOL operator>( const HFileSystemTimeImplementPc& in_rhs )const;
		HBOOL operator>=( const HFileSystemTimeImplementPc& in_rhs )const;

		///////////////////////////////////////////////////////////
		// public methods
	public:
		HVOID StringISO8601Get( HString& out_string )const;
		HVOID StringISO8601Set( const HString& in_string );

		const HSINT SeedGet()const;

		///////////////////////////////////////////////////////////
		// public accessors
	public:
		HVOID DataSet( const time_t in_time ){ m_time = in_time; return; }
		const time_t DataGet(){ return m_time; }

		///////////////////////////////////////////////////////////
		// private members
	private:
		time_t m_time;

	};
};

#endif// _H_FILE_SYSTEM_TIME_IMPLEMENT_H_
