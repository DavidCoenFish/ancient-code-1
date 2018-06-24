//file: Sloth/SCursor/SCursorImplementation.h
#ifndef _S_CURSOR_IMPLEMENTATION_H_
#define _S_CURSOR_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SCursorComponentImage;
	class SCursorImageInterface;
	struct SCursorParam;

	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SCursorImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HCURSOR;

		///////////////////////////////////////////////////////
		// creation
	public:
		SCursorImplementation( 
			const SCursorParam& in_param
			);
		~SCursorImplementation();

		///////////////////////////////////////////////////////
		// public methods
	public:
		HCURSOR CursorGet();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SCursorImplementation( const SCursorImplementation& in_src );
		const SCursorImplementation& operator=( const SCursorImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		HCURSOR m_cursor;

	};

	/**/
	
};

#endif // _S_CURSOR_IMPLEMENTATION_H_