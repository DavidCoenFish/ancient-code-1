//file: Hubris/HFileSystem/HFileSystemTime.h
#ifndef _H_FILE_SYSTEM_TIME_H_
#define _H_FILE_SYSTEM_TIME_H_

#include "Hubris/HCommon/HCommonType.h"

/*
	file path as object, wrapper to avoid component having dependance
*/
namespace Hubris
{

	///////////////////////////////////////////////////////////
	// predefine
	class HFileSystemTimeImplementPc;
	class HFileSystem;
	class HString;

	///////////////////////////////////////////////////////////
	// class
	class HFileSystemTime
	{
		friend HFileSystem; //access to implementation

		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HFileSystemTimeImplementPc TImplementation;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HFileSystemTime( const HFileSystemTime& in_rhs );
		HFileSystemTime();
		~HFileSystemTime();

		///////////////////////////////////////////////////////////
		// operators
	public:
		const HFileSystemTime& operator=( const HFileSystemTime& in_rhs );
		HBOOL operator==( const HFileSystemTime& in_rhs ) const;
		HBOOL operator!=( const HFileSystemTime& in_rhs ) const;

		HBOOL operator<( const HFileSystemTime& in_rhs )const;
		HBOOL operator<=( const HFileSystemTime& in_rhs )const;
		HBOOL operator>( const HFileSystemTime& in_rhs )const;
		HBOOL operator>=( const HFileSystemTime& in_rhs )const;

		///////////////////////////////////////////////////////////
		// public methods
	public:
		const HString StringISO8601Get()const;
		HVOID StringISO8601Set( const HString& in_string );

		const HSINT SeedGet()const;

		///////////////////////////////////////////////////////////
		// private accessors
	private:
		const TImplementation& ImplementGet()const;
		TImplementation& ImplementGet();

	private:
		///////////////////////////////////////////////////////////
		// private members

		TImplementation* m_pImplement;

	};

	/**/
};

#endif// _H_FILE_SYSTEM_TIME_H_
