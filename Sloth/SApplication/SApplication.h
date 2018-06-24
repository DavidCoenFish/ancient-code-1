//file: Sloth/SApplication/SApplication.h
#ifndef _S_APPLICATION_H_
#define _S_APPLICATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// predefine
	/**/
	class SConsole;
	class SCursor;
	class SIcon;
	class SInput;
	class SMenu;
	class SWindowImage;
	class SWindowRender;
	struct SCursorParam;
	struct SIconParam;
	struct SWindowParam;
	struct SWindowParamDirectX;
	struct SWindowParamOpenGl;

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
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;
		typedef Hubris::HCHAR* LPSTR;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		///////////////////////////////////////////////////////
		// friends
		friend int __stdcall WinMain(
			HINSTANCE in_hInstance,
			HINSTANCE in_hPrevInstance,
			LPSTR in_lpCmdLine,
			int in_nCmdShow
		);
		friend int main( 
			int in_argc, 
			char** in_argv
			//char** in_envp
			);

		///////////////////////////////////////////////////////
		// creation
	private:
	public:
		SApplication( 
			HINSTANCE in_hInstance,
			const Hubris::HString& in_commandLine,
			int in_nCmdShow			
			);
		~SApplication();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SApplication( const SApplication& in_src );
		const SApplication& operator=( const SApplication& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		SMenu* const MenuRequest();
		Hubris::HVOID MenuRelease( SMenu*& in_out_pMenu );

		SCursor* const CursorRequest( const SCursorParam& in_cursorParam );
		Hubris::HVOID CursorRelease( SCursor*& in_out_pCursor );

		SIcon* const IconRequest( const SIconParam& in_iconParam );
		Hubris::HVOID IconRelease( SIcon*& in_out_pIcon );

		SWindowImage* const WindowImageRequest( const SWindowParam& in_windowParam );
		Hubris::HVOID WindowImageRelease( SWindowImage*& in_out_pWindowImage );

		SWindowRender* const WindowRenderRequest( const SWindowParamDirectX& in_windowParamDirectX );
		SWindowRender* const WindowRenderRequest( const SWindowParamOpenGl& in_windowParamOpenGl );
		Hubris::HVOID WindowRenderRelease( SWindowRender*& in_out_pWindowRender );

		SConsole* const ConsoleRequest();
		Hubris::HVOID ConsoleRelease( SConsole*& in_out_pConsole );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HString& CommandLineGet()const{ return m_commandLine; }

		const Hubris::HBOOL CommandShowGetHide()const;
		const Hubris::HBOOL CommandShowGetMaximize()const;
		const Hubris::HBOOL CommandShowGetMinimize()const;
		const Hubris::HBOOL CommandShowGetRestore()const;
		const Hubris::HBOOL CommandShowGetShow()const;
		const Hubris::HBOOL CommandShowGetShowMaximized()const;
		const Hubris::HBOOL CommandShowGetShowMinimized()const;
		const Hubris::HBOOL CommandShowGetShowMinNoActive()const;
		const Hubris::HBOOL CommandShowGetShowNA()const;
		const Hubris::HBOOL CommandShowGetShowNoActivate()const;
		const Hubris::HBOOL CommandShowGetShowNormal()const;

		///////////////////////////////////////////////////////
		// private members
	private:
		HINSTANCE m_hinstance;
		const Hubris::HString m_commandLine;
		const Hubris::HSINT m_commandShow;

	};

	/**/
	
};

#endif // _S_APPLICATION_H_