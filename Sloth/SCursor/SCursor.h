//file: Sloth/SCursor/SCursor.h
#ifndef _S_CURSOR_H_
#define _S_CURSOR_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SCursorImplementation;
	struct SCursorParam;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class SCursor
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;
		typedef Hubris::HVOID* HCURSOR;


		///////////////////////////////////////////////////////
		// creation
	public:
		//any alpha of zero is considered to cursor mask
		SCursor( 
			const SCursorParam& in_param
			);
		~SCursor();

		///////////////////////////////////////////////////////
		// public methods
	public:
		HCURSOR CursorGet();

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SCursorImplementation& ImplementationGet()const;
		SCursorImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SCursor( const SCursor& in_src );
		const SCursor& operator=( const SCursor& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		SCursorImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_CURSOR_H_