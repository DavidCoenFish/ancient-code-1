//file: Sloth/SApplication/SApplication.h
#ifndef _S_APPLICATION_H_
#define _S_APPLICATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SApplication
	{
		///////////////////////////////////////////////////////
		// friends
		friend int WinMain(HVOID* in_hInstance, Hubris::HVOID*, char* far, int);

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		///////////////////////////////////////////////////////
		// creation
	private:
		SApplication( const Hubris::HString in_commandLine );
		~SApplication();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SApplication( const SApplication& in_src );
		const SApplication& operator=( const SApplication& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		//SWindow* const WindowRequest();
		//HVOID WindowRelease( SWindow*& in_out_pWindow );

		//SConsole* const ConsoleRequest();
		//HVOID ConsoleRelease( SConsole*& in_out_pConsole );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		///////////////////////////////////////////////////////
		// private members
	private:


	};

	/**/
	
};

#endif // _S_APPLICATION_H_